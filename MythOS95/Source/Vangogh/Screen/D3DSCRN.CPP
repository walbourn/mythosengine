//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  |
//                                                           |_|_|_._._.|
// Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
//              All rights reserved.                        %\__________/%
//                                                           %          %
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
//           *** Charybdis Enterprises, Inc. Company Confidential ***
//
//  This file and all associated files are the company proprietary property
//        of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
//
// CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
// TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
// IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
// AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
// INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
// DDraw.cpp
//
//  This file contains the member functions for the class that describes
//  the current game state.  This class also "runs" the game, but must
//  be driven by an outside program.
//
//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
#define D3D_OVERLOADS

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <windows.h>
#include <ddraw.h>
#include "debug.h"
#include "portable.h"

#ifndef     _D3D
#define     _D3D
#define     TEMP_D3D
#endif

#include "vangogh.hpp"
#include "vngscrn.hpp"

#ifdef      TEMP_D3D
#undef      _D3D
#undef      _TEMP_D3D
#endif


extern VngoSystem   VgSystem;

BOOL CALLBACK FindDeviceCallback(GUID *lpGUID,LPSTR szName,LPSTR szDevice,LPVOID lParam);

VngoDirect3D::VngoDirect3D(HWND hwndclient):
    dd(0),
    FrontBuffer(NULL),
    BackBuffer(NULL),
    ZBuffer(NULL),
    SurfaceManager(NULL),
    Palette(NULL),
    d3d(NULL),
    d3dDevice(NULL),
    d3dViewport(NULL),
    hWndClient(hwndclient)
{
    frame_is_open = FALSE;
    pal = NULL;
    init_state = init();
}

VngoDirect3D::~VngoDirect3D()
{
    term();
}


BOOL VngoDirect3D::init()
{
//    GetProfileString(szAppName, "Device", "", DeviceName,sizeof(DeviceName));

    target = "3Dfx Interactive DirectX II Driver (dd3dfx)";

//    DirectDrawEnumerate(FindDeviceCallback,(LPVOID)this);

    if (dd==NULL)
        err = DirectDrawCreate(NULL, &dd, NULL);

    if (err != DD_OK)
        return FALSE;

    err = dd->QueryInterface(IID_IDirect3D2, (void**)&d3d);

    if (err != DD_OK)
        return FALSE;

    VgSystem.D3DTx = new VngoTextureManager;
    VgSystem.D3DTx->screen = this;

    type_info = SCREENTYPE_D3D;
    return TRUE;
}


void VngoDirect3D::reinit(Flx16 brightness)
{
    if (!pal)
        return;

    set_palette(pal,brightness);
}

BOOL VngoDirect3D::check_mode(int _width, int _height, int bpp)
{
    assert (dd != 0);

    return (FALSE);
}



BOOL VngoDirect3D::set_mode(int _width, int _height, int bpp, VngoPal *_pal,dword flags)
{
    width = _width;
    height = _height;
    lflags = flags;
    startx = 0;
    starty = 0;
    bit_depth = bpp;

    if (err != DD_OK)
        return FALSE;

    if (lflags & VNGO_SET_RESOLUTION)
    {
        err = dd->SetCooperativeLevel(hWndClient,
            DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN | DDSCL_ALLOWMODEX);
        if (err == DD_OK)
            err = dd->SetDisplayMode(width, height, bpp);
    }
    else
    {
        err = dd->SetCooperativeLevel(hWndClient,DDSCL_NORMAL);
    }

    if (err != DD_OK)
        return FALSE;

    // Get rid of any previous surfaces.
    if (BackBuffer)
    {
        BackBuffer->Release();
        BackBuffer = NULL;
    }
    if (FrontBuffer)
    {
        FrontBuffer->Release();
        FrontBuffer = NULL;
    }
    if (ZBuffer)
    {
        ZBuffer->Release();
        ZBuffer = NULL;
    }

    if (Palette)
    {
        Palette->Release();
        Palette = NULL;
    }

    // Creat surfaces.
    ZeroMemory (&ddsd, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    if (lflags & VNGO_TRUE_FLIP)
    {
        ddsd.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
        ddsd.dwBackBufferCount = 1;
        ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE |
                              DDSCAPS_FLIP |
                              DDSCAPS_COMPLEX |
                              DDSCAPS_VIDEOMEMORY;
    }
    else
    {
        ddsd.dwFlags = DDSD_CAPS;
        ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE
                              | DDSCAPS_VIDEOMEMORY;
    }
    if (lflags & VNGO_3DDEVICE)
    {
        ddsd.ddsCaps.dwCaps |= DDSCAPS_3DDEVICE;
    }

    // try to get a double buffered video memory surface.
    err = dd->CreateSurface(&ddsd, &Primary, NULL);

    if (err != DD_OK)
    {
        // settle for a main memory surface.
        ddsd.ddsCaps.dwCaps &= ~DDSCAPS_VIDEOMEMORY;
        err = dd->CreateSurface(&ddsd, &Primary, NULL);
        if (err != DD_OK)
            return FALSE;
        lflags &= ~VNGO_FORCE_SYSTEMMEMORY;
    }



    // get a pointer to the back buffer.
    if (lflags & VNGO_TRUE_FLIP)
    {
        DDSCAPS caps;
        caps.dwCaps = DDSCAPS_BACKBUFFER;
        err = Primary->GetAttachedSurface(&caps, &BackBuffer);

        if (err != DD_OK)
            return FALSE;

        if (lflags & VNGO_FORCE_SYSTEMMEMORY)
        {
            ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
            ddsd.ddsCaps.dwCaps = DDSCAPS_SYSTEMMEMORY;
            ddsd.dwHeight = height;
            ddsd.dwWidth = width;
            err = dd->CreateSurface (&ddsd, &FrontBuffer, NULL);

            if (err != DD_OK)
                return FALSE;
        }
        else
            FrontBuffer = BackBuffer;
    }
    else
    {
        ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

        if (lflags & VNGO_FORCE_SYSTEMMEMORY)
            ddsd.ddsCaps.dwCaps = DDSCAPS_SYSTEMMEMORY;
        else
        {
            ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_VIDEOMEMORY;
            if (lflags & VNGO_3DDEVICE)
                ddsd.ddsCaps.dwCaps |= DDSCAPS_3DDEVICE;
        }



        ddsd.dwHeight = height;
        ddsd.dwWidth = width;
        err = dd->CreateSurface (&ddsd, &BackBuffer, NULL);

        FrontBuffer = BackBuffer;

        if (err != DD_OK)
            return FALSE;
    }

    if (flags & VNGO_ALLOC_ZBUFFER)
    {
        memset( &ddsd, 0, sizeof(ddsd) );
        ddsd.dwSize = sizeof(ddsd);
        ddsd.dwFlags           = DDSD_WIDTH
                               | DDSD_HEIGHT
                               | DDSD_CAPS
                               | DDSD_ZBUFFERBITDEPTH;
        ddsd.dwWidth           = _width;
        ddsd.dwHeight          = _height;
        ddsd.ddsCaps.dwCaps    = DDSCAPS_ZBUFFER;
        ddsd.dwZBufferBitDepth = 16;
        err = dd->CreateSurface( &ddsd, &ZBuffer, NULL );

        err = BackBuffer->AddAttachedSurface( ZBuffer );
    }

    SurfaceManager = new VngoSurfaceManager(FrontBuffer,ZBuffer);

    if (SurfaceManager == NULL)
    {
        return FALSE;
    }

    //
    // Now initialize all of the D3D stuff.
    //
    if (flags & VNGO_3DDEVICE)
    {
        err = d3d->CreateDevice(IID_IDirect3DHALDevice,BackBuffer,&d3dDevice);
        if (err == DD_OK)
            strcpy(hwName,"D3D HAL");

    }
    if ((err != DD_OK) || !(flags & VNGO_3DDEVICE))
    {
        err = d3d->CreateDevice(IID_IDirect3DRGBDevice,BackBuffer,&d3dDevice);
        if (err != DD_OK)
        {
            err = d3d->CreateDevice(IID_IDirect3DRampDevice,BackBuffer,&d3dDevice);
        }
        else
        {
            strcpy(hwName,"D3D RGB");
        }
        if (err == DD_OK)
        {
            strcpy(hwName,"D3D Ramp");
        }
    }
    if (err != DD_OK)
        return FALSE;

    err = d3d->CreateViewport(&d3dViewport,NULL);
    if (err != DD_OK)
        return FALSE;
    err = d3dDevice->AddViewport (d3dViewport);
    if (err != DD_OK)
        return FALSE;

    D3DVIEWPORT2 viewData;
    memset(&viewData,0,sizeof(D3DVIEWPORT2));
    viewData.dwSize = sizeof(D3DVIEWPORT2);
    viewData.dwX = 0;
    viewData.dwY = 0;
    viewData.dwWidth = _width;
    viewData.dwHeight = _height;
    viewData.dvClipX = -1.f;
    viewData.dvClipWidth = 2.0f;
    viewData.dvClipHeight = (D3DVALUE)(double(_height) * 2.0 / double(_width));
    viewData.dvClipY = viewData.dvClipHeight / 2.0f;
    viewData.dvMinZ = 0.0f;
    viewData.dvMaxZ = 1.0f;

    err = d3dViewport->SetViewport2(&viewData);
    if (err != DD_OK)
        return FALSE;

    err = d3dDevice->SetCurrentViewport(d3dViewport);

    if (err != DD_OK)
        return FALSE;

    if (flags & VNGO_ALLOC_ZBUFFER)
    {
        d3dDevice->SetRenderState(D3DRENDERSTATE_ZENABLE,TRUE);
        d3dDevice->SetRenderState(D3DRENDERSTATE_ZWRITEENABLE,TRUE);
        d3dDevice->SetRenderState(D3DRENDERSTATE_ZFUNC,D3DCMP_LESS);
    }
    else
    {
        d3dDevice->SetRenderState(D3DRENDERSTATE_ZENABLE,FALSE);
        d3dDevice->SetRenderState(D3DRENDERSTATE_ZWRITEENABLE,FALSE);
    }
    d3dDevice->SetRenderState(D3DRENDERSTATE_SHADEMODE, D3DSHADE_GOURAUD);
    d3dDevice->SetRenderState(D3DRENDERSTATE_DITHERENABLE,TRUE);
    d3dDevice->SetRenderState(D3DRENDERSTATE_CULLMODE, D3DCULL_NONE);
    d3dDevice->SetRenderState(D3DRENDERSTATE_TEXTUREHANDLE,NULL);


    // Create a palette if we are in a paletized display mode.

    if (bpp == 8)
    {
        pal=_pal;
        PALETTEENTRY        ape[256];
        HDC hdc = GetDC(NULL);
        if (GetDeviceCaps(hdc, RASTERCAPS) & RC_PALETTE)
        {
            // get the current windows colors.
            GetSystemPaletteEntries(hdc, 0, 256, ape);

            if (pal)
            {
                // make the palette we want.
                for (int i=0; i < 256; i++)
                {
                    ape[i].peRed   = ((VngoPal8 *)pal)->get_RGB(i).r;
                    ape[i].peGreen = ((VngoPal8 *)pal)->get_RGB(i).g;
                    ape[i].peBlue  = ((VngoPal8 *)pal)->get_RGB(i).b;
                }
            }
            err = dd->CreatePalette(DDPCAPS_8BIT | DDPCAPS_ALLOW256,
                                    ape, &Palette, NULL);

            if (err == DD_OK)
            {
                err = Palette->SetEntries(0,0,256,ape);
                if (err == DD_OK)
                {
                    Primary->SetPalette(Palette);
                    FrontBuffer->SetPalette(Palette);
                    BackBuffer->SetPalette(Palette);
                }
            }

        }
        ReleaseDC (NULL, hdc);
    }

    return TRUE;
}

void VngoDirect3D::flip()
{
    if (frame_is_open)
        close_frame();

    if (FrontBuffer->IsLost() == DDERR_SURFACELOST)
        FrontBuffer->Restore();

    if (BackBuffer->IsLost() == DDERR_SURFACELOST)
        BackBuffer->Restore();

    if (Primary->IsLost() == DDERR_SURFACELOST)
        Primary->Restore();


    if (lflags & VNGO_TRUE_FLIP)
    {
        if (lflags & VNGO_FORCE_SYSTEMMEMORY)
        {
            RECT rcRect;
            rcRect.left = 0;
            rcRect.top = 0;
            rcRect.right = width;
            rcRect.bottom = height;

            while (1)
            {
                HRESULT ddrval = BackBuffer->Blt(&rcRect,
                                                 FrontBuffer,
                                                 &rcRect,
                                                 0, NULL);
                if (ddrval == DD_OK)
                {
                    break;
                }
                if (ddrval != DDERR_WASSTILLDRAWING)
                {
                    return;
                }
            }
        }
        Primary->Flip(NULL,DDFLIP_WAIT);
    }
    else
    {
#if 1
        RECT rcRect;
        rcRect.left = 0;
        rcRect.top = 0;
        rcRect.right = width;
        rcRect.bottom = height;
#endif
        RECT srcRect;
        srcRect.left = startx + damage_rect.left;
        srcRect.top = starty + damage_rect.top;
        srcRect.right = startx + damage_rect.right;
        srcRect.bottom = starty + damage_rect.bottom;

        while (1)
        {
            HRESULT ddrval = Primary->Blt(&rcRect,
                                          BackBuffer,
//                                          &damage_rect,
                                          &rcRect,
                                          0, NULL);
            if (ddrval == DD_OK)
            {
                break;
            }
            if (ddrval != DDERR_WASSTILLDRAWING)
            {
                return;
            }
        }
    }
        VngoScreenManager::flip();
}

void VngoDirect3D::set_palette(VngoPal *p,Flx16 brightness)
{
    if (!Palette)
        return;

    pal = p;

    PALETTEENTRY        ape[256];

    // make the palette we want.
    for (int i=0; i < 256; i++)
    {
        VngoColorHLS hls;
        VngoColor24bit rgb;

        hls = ((VngoPal8*)p)->hw_pal.p[i];
        hls.l += brightness;
        if(hls.l < 0)
            hls.l = 0;
        else if (hls.l > Flx16(1))
            hls.l = Flx16(1);

        rgb = hls;

        ape[i].peRed   = rgb.r;
        ape[i].peGreen = rgb.g;
        ape[i].peBlue  = rgb.b;
    }

    Palette->SetEntries(0,0,256,ape);

}

void VngoDirect3D::open_frame()
{
    if (!frame_is_open)
    {
        d3dDevice->BeginScene();
    }
    frame_is_open = TRUE;
}

void VngoDirect3D::close_frame()
{
    if (frame_is_open)
    {
        d3dDevice->EndScene();
    }
    frame_is_open = FALSE;
}

void VngoDirect3D::term()
{

    if (SurfaceManager)
    {
        delete SurfaceManager;
        SurfaceManager = NULL;
    }

    if (FrontBuffer)
    {
        if (BackBuffer && (FrontBuffer != BackBuffer))
        {
            FrontBuffer->Release();
            FrontBuffer = NULL;
        }
    }

    if (BackBuffer)
    {
        BackBuffer->Release();
        BackBuffer = NULL;
    }

    if (ZBuffer)
    {
        ZBuffer->Release();
        ZBuffer = NULL;
    }

    if (VgSystem.D3DTx)
    {
        delete VgSystem.D3DTx;
        VgSystem.D3DTx = NULL;
    }

    if (d3dDevice)
    {
        d3dDevice->Release();
        d3dDevice = NULL;
    }

    if (d3dViewport)
    {
        d3dViewport->Release();
        d3dViewport = NULL;
    }

    if (d3d)
    {
        d3d->Release();
        d3d=NULL;
    }

    if (Primary)
    {
        Primary->Release();
        Primary = NULL;
    }


    if (Palette)
    {
        Palette->Release();
        Palette = NULL;
    }

    if (dd)
    {
        dd->SetCooperativeLevel(hWndClient,DDSCL_NORMAL);
        dd->Release();
        dd = NULL;
    }
}

BOOL CALLBACK FindDeviceCallback(GUID *lpGUID,LPSTR szName,LPSTR szDevice,LPVOID lParam)
{
    char ach[128];
    VngoDirect3D    *screen = (VngoDirect3D *)lParam;

    wsprintf(ach,"%s (%s)",szName, szDevice);

    if (lstrcmpi(screen->target, szDevice) == 0 || lstrcmpi(screen->target,ach) == 0)
    {
        DirectDrawCreate(lpGUID,&screen->dd,NULL);
        return DDENUMRET_CANCEL;
    }
    return DDENUMRET_OK;
}




