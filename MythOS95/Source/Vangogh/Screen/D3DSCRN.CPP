//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//        Microsoft Windows 95/98/NT Version                 | / \   .  |
//                                                           |_|_|_._._.|
//                                                           |.-.-.-.-..|
//                                                          %\__________/%
//                                                           %          %
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
//                        http://www.mythos-engine.org/
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
// Created by Tim Little
//
// d3dscrn.cpp
//
// Direct3D
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

// #define RENDER_FRONT

extern VngoSystem   *VgSystem;

BOOL CALLBACK FindDeviceCallback(GUID *lpGUID,LPSTR szName,LPSTR szDevice,LPVOID lParam);



VngoDirect3D::VngoDirect3D():
    dd(0),
    Primary(NULL),
    FrontBuffer(NULL),
    BackBuffer(NULL),
    ZBuffer(NULL),
    SurfaceManager(NULL),
    d3d(NULL),
    d3dDevice(NULL),
    d3dViewport(NULL),
    target(NULL),
    hWndClient(0)
{
    sins = 0;
    frame_is_open = FALSE;
    pal = NULL;
    init_state = VNGO_NOSCREEN_ERROR;
}



VngoDirect3D::VngoDirect3D(HWND hwndclient,char *targetname):
    dd(0),
    Primary(NULL),
    FrontBuffer(NULL),
    BackBuffer(NULL),
    ZBuffer(NULL),
    SurfaceManager(NULL),
    d3d(NULL),
    d3dDevice(NULL),
    d3dViewport(NULL),
    target(NULL),
    hWndClient(hwndclient)
{
    sins = 0;
    frame_is_open = FALSE;
    pal = NULL;
    init_state = init(targetname);
}

VngoDirect3D::~VngoDirect3D()
{
//    if ((lflags & VNGO_SET_RESOLUTION) && dd != NULL)
//        dd->RestoreDisplayMode();

    term();
}

VNGError VngoDirect3D::init()
{
    return init(NULL);
}

VNGError VngoDirect3D::init(char *targetName)
{
    target = targetName;

    if (target != NULL)
    {
        if (DirectDrawEnumerate(FindDeviceCallback,(LPVOID)this)==DD_OK)
        {
            if (dd==NULL)
                err = DirectDrawCreate(&targetID, &dd, NULL);
            if (err != DD_OK)
            {
                if (dd != NULL)
                {
                    dd->Release();
                    dd = NULL;
                }
                err = DirectDrawCreate(NULL, &dd, NULL);
            }
        }
        else
        {
            if (dd==NULL)
                err = DirectDrawCreate(NULL, &dd, NULL);
        }
    }
    else
    {
        if (dd==NULL)
            err = DirectDrawCreate(NULL, &dd, NULL);
    }


    if (err != DD_OK)
        return VNGO_INTERNAL_ERROR;

    err = dd->QueryInterface(IID_IDirect3D2, (void**)&d3d);

    if (err != DD_OK)
        return VNGO_INTERNAL_ERROR;


    VgSystem->D3DTx = new VngoTextureManager;
    if (VgSystem->D3DTx)
    {
        VgSystem->D3DTx->screen = this;
    }
    else
    {
        term();
        return VNGO_INTERNAL_ERROR;
    }

    type_info = SCREENTYPE_D3D;
    return VNGO_NO_ERROR;
}


VNGError VngoDirect3D::reinit(Flx16 brightness)
{
    if (!pal)
        return VNGO_NOT_SUPPORTED;

    return set_palette(pal,brightness);
}

VNGError VngoDirect3D::check_mode(int _width, int _height, int bpp, dword _flags, VngoPixelInfo *pinfo)
{
    assert (dd != 0);

    if (_flags & VNGO_SET_RESOLUTION)
    {
    }

    return (VNGO_NOT_SUPPORTED);
}



VNGError VngoDirect3D::set_mode(int _width, int _height, int bpp, VngoPal *_pal,dword flags)
{
    width = _width;
    height = _height;
    lflags = flags;
    startx = 0;
    starty = 0;
    bit_depth = bpp;

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
    {
        term();
        return VNGO_INTERNAL_ERROR;
    }

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
        {
            term();
            return VNGO_INTERNAL_ERROR;
        }
        lflags &= ~VNGO_FORCE_SYSTEMMEMORY;
    }



    // get a pointer to the back buffer.
    if (lflags & VNGO_TRUE_FLIP)
    {
        DDSCAPS caps;
        caps.dwCaps = DDSCAPS_BACKBUFFER;
        err = Primary->GetAttachedSurface(&caps, &BackBuffer);

        if (err != DD_OK)
        {
            term();
            return VNGO_INTERNAL_ERROR;
        }

        if (lflags & VNGO_FORCE_SYSTEMMEMORY)
        {
            ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
            ddsd.ddsCaps.dwCaps = DDSCAPS_SYSTEMMEMORY;
            ddsd.dwHeight = height;
            ddsd.dwWidth = width;
            err = dd->CreateSurface (&ddsd, &FrontBuffer, NULL);

            if (err != DD_OK)
            {
                term();
                return VNGO_INTERNAL_ERROR;
            }
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
        {
            term();
            return VNGO_INTERNAL_ERROR;
        }
    }
    DDSURFACEDESC   tdesc;
    memset(&tdesc,0,sizeof(tdesc));
    tdesc.dwSize = sizeof(tdesc);
    int safty=0;
    int locked = 0;
    while (!locked && safty < 10000)
    {
        safty++;
        HRESULT terr;
        terr = BackBuffer->Lock(NULL,&tdesc,DDLOCK_SURFACEMEMORYPTR | DDLOCK_WAIT,NULL);
        if (terr == DD_OK)
        {
            locked = 1;
        }
        if (terr == DDERR_SURFACELOST)
        {
            terr = BackBuffer->Restore();
            if (terr != DD_OK)
                locked = 0; // an error occured while
                            // restoring the surface, so it cannot be locked.
        }
    }
    if (locked)
        BackBuffer->Unlock(NULL);
    else
    {
        term();
        return VNGO_INTERNAL_ERROR;
    }


    if (tdesc.ddpfPixelFormat.dwRBitMask == 0xf800)   // Is it 16bpp?
    {
        if (!(_pal->flags & VNGO_16BIT))
        {
            term();
            return VNGO_NEEDS_PAL16;
        }
    }
    else if (tdesc.ddpfPixelFormat.dwRBitMask == 0x7c00) // Is it 15bpp?
    {
        if (!(_pal->flags & VNGO_15BIT))
        {
            term();
            return VNGO_NEEDS_PAL15;
        }
    }
    else
    {
        term();
        return VNGO_WRONG_BITDEPTH;
    }

#ifdef RENDER_FRONT
    FrontBuffer = BackBuffer;
    BackBuffer = Primary;
#endif
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

        if (err != DD_OK)
        {
            term();
            return VNGO_INTERNAL_ERROR;
        }

        err = BackBuffer->AddAttachedSurface( ZBuffer );

        if (err != DD_OK)
        {
            term();
            return VNGO_INTERNAL_ERROR;
        }
    }

    SurfaceManager = new VngoSurfaceManager(BackBuffer,ZBuffer);

    if (SurfaceManager == NULL)
    {
        term();
        return VNGO_MEMALLOC_ERROR;
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
    else
    {
        term();
        return VNGO_NOT_SUPPORTED;
    }

    if (err != DD_OK)
    {
        term();
        return VNGO_INTERNAL_ERROR;
    }


    DDCAPS          ddhaldesc,ddheldesc;

    ZeroMemory(&ddhaldesc,sizeof(ddhaldesc));
    ddhaldesc.dwSize = sizeof(ddhaldesc);

    ZeroMemory(&ddheldesc,sizeof(ddheldesc));
    ddheldesc.dwSize = sizeof(ddheldesc);


    err = dd->GetCaps(&ddhaldesc,&ddheldesc);
    if (err != DD_OK)
    {
        sins = err;
        term();
        return VNGO_INTERNAL_ERROR;
    }

    if (!(ddhaldesc.dwCaps & DDCAPS_3D))
    {
        sins |= VNGO_NOT_3DDEVICE;
        term();
        return VNGO_INTERNAL_ERROR;
    }

    if (!(ddhaldesc.dwCaps & DDCAPS_BLT))
    {
        sins |= VNGO_NO_HWBLIT;
        if (!(ddheldesc.dwCaps & DDCAPS_BLT))
        {
            sins |= VNGO_NO_BLIT;
        }
    }
    if (ddhaldesc.dwCaps2 & DDCAPS2_NO2DDURING3DSCENE)
    {
        sins |= VNGO_NO_3D_2D_INTERLEAVE;
//        term();
//        return VNGO_INTERNAL_ERROR;
    }


    D3DDEVICEDESC   thaldesc,theldesc;

    ZeroMemory(&thaldesc,sizeof(thaldesc));
    thaldesc.dwSize = sizeof(thaldesc);

    ZeroMemory(&theldesc,sizeof(theldesc));
    theldesc.dwSize = sizeof(theldesc);

    err = d3dDevice->GetCaps(&thaldesc,&theldesc);

    if (err != DD_OK)
    {
        sins = err;
        term();
        return VNGO_INTERNAL_ERROR;
    }
    else
    {
        //
        // Lets fill in the sins info here :)
        //
        if (thaldesc.dwFlags & D3DDD_COLORMODEL)
        {
            if(!(thaldesc.dcmColorModel & D3DCOLOR_RGB))
            {
                sins |= VNGO_INVALID_COLORMODEL;
                term();
                return VNGO_NOT_SUPPORTED;
            }
        }
        if (thaldesc.dwFlags & D3DDD_DEVCAPS)
        {
            if (!(thaldesc.dwDevCaps & D3DDEVCAPS_FLOATTLVERTEX))
            {
                sins |= VNGO_INVALID_VERTEX_FORMAT;
                term();
                return VNGO_NOT_SUPPORTED;
            }
        }
        if (thaldesc.dwFlags & D3DDD_DEVICERENDERBITDEPTH)
        {
            if (!(thaldesc.dwDeviceRenderBitDepth & DDBD_16))
            {
                sins |= VNGO_INVALID_RENDERDEPTH;
                term();
                return VNGO_NOT_SUPPORTED;
            }
        }
        if (thaldesc.dwFlags & D3DDD_DEVICEZBUFFERBITDEPTH)
        {
            if (!(thaldesc.dwDeviceZBufferBitDepth & DDBD_16))
                sins |= VNGO_NO_ZBUFFER;
        }
        if (thaldesc.dwFlags & D3DDD_LINECAPS)
        {
            // We don't currently care about the line caps to much....
        }
        if (thaldesc.dwFlags & D3DDD_TRICAPS)
        {
            if (!(thaldesc.dpcTriCaps.dwMiscCaps & D3DPMISCCAPS_CULLNONE))
                sins |= VNGO_NO_CULLING_CONTROL;
            if (!(thaldesc.dpcTriCaps.dwRasterCaps & D3DPRASTERCAPS_DITHER))
                sins |= VNGO_NO_DITHER;
            if (!(thaldesc.dpcTriCaps.dwRasterCaps & D3DPRASTERCAPS_FOGVERTEX))
                sins |= VNGO_NO_VERTEX_FOG;
            if (!(thaldesc.dpcTriCaps.dwRasterCaps & D3DPRASTERCAPS_FOGTABLE))
                sins |= VNGO_NO_TABLE_FOG;
            if (!(thaldesc.dpcTriCaps.dwRasterCaps & D3DPRASTERCAPS_STIPPLE) &&
                !(thaldesc.dpcTriCaps.dwShadeCaps & D3DPSHADECAPS_ALPHAFLATSTIPPLED) &&
                !(thaldesc.dpcTriCaps.dwShadeCaps & D3DPSHADECAPS_ALPHAGOURAUDSTIPPLED))
                sins |= VNGO_NO_STIPPLE_ALPHA;
            if (!((thaldesc.dpcTriCaps.dwSrcBlendCaps & D3DPBLENDCAPS_BOTHSRCALPHA)
                && (thaldesc.dpcTriCaps.dwDestBlendCaps & D3DPBLENDCAPS_BOTHSRCALPHA)))
                sins |= VNGO_NO_ALPHA;
            if (!(thaldesc.dpcTriCaps.dwShadeCaps & D3DPSHADECAPS_SPECULARGOURAUDRGB))
                sins |= VNGO_NO_SPECULAR;
            if (!(thaldesc.dpcTriCaps.dwShadeCaps & (D3DPSHADECAPS_FOGFLAT | D3DPSHADECAPS_FOGGOURAUD)))
                sins |= VNGO_NO_FOG;
            if (!(thaldesc.dpcTriCaps.dwTextureCaps & D3DPTEXTURECAPS_PERSPECTIVE))
                sins |= VNGO_NO_PERSPECTIVE;
            if (thaldesc.dpcTriCaps.dwTextureCaps & D3DPTEXTURECAPS_SQUAREONLY)
                sins |= VNGO_INVALID_TEXTURE_SIZES;
            if (!(thaldesc.dpcTriCaps.dwTextureCaps & D3DPTEXTURECAPS_TRANSPARENCY))
                sins |= VNGO_NO_CHROMAKEY_TEXTURES;
            if (!(thaldesc.dpcTriCaps.dwTextureFilterCaps & D3DPTFILTERCAPS_LINEAR))
                sins |= VNGO_NO_FILTERS;
            if (!(thaldesc.dpcTriCaps.dwTextureBlendCaps & D3DPTBLENDCAPS_MODULATE))
                sins |= VNGO_NO_TEXTURE_MODULATION;
            if (!(thaldesc.dpcTriCaps.dwTextureAddressCaps & D3DPTADDRESSCAPS_WRAP))
                sins |= VNGO_NO_TEXTURE_TILE;
        }
        // Just added so old drivers don't support this check.
        // So we need to make sure there are values filed in before we use it.
        if (thaldesc.dwMinTextureWidth
            && thaldesc.dwMinTextureHeight)
        {
            if (thaldesc.dwMinTextureWidth > 16
                || thaldesc.dwMinTextureHeight > 16)
            {
                sins |= VNGO_INVALID_TEXTURE_SIZES;
            }
        }
        // Just added so old drivers don't support this check.
        // So we need to make sure there are values filed in before we use it.
        if (thaldesc.dwMaxTextureWidth
            && thaldesc.dwMaxTextureHeight)
        {
            if (thaldesc.dwMaxTextureWidth < 256
                || thaldesc.dwMaxTextureHeight < 256)
            {
                sins |= VNGO_INVALID_TEXTURE_SIZES;
            }
        }
    }

    err = d3d->CreateViewport(&d3dViewport,NULL);
    if (err != DD_OK)
    {
        term();
        return VNGO_INTERNAL_ERROR;
    }

    err = d3dDevice->AddViewport (d3dViewport);
    if (err != DD_OK)
    {
        term();
        return VNGO_INTERNAL_ERROR;
    }

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
    {
        term();
        return VNGO_INTERNAL_ERROR;
    }

    err = d3dDevice->SetCurrentViewport(d3dViewport);

    if (err != DD_OK)
    {
        term();
        return VNGO_INTERNAL_ERROR;
    }

    if (flags & VNGO_ALLOC_ZBUFFER)
    {
        d3dDevice->SetRenderState(D3DRENDERSTATE_ZENABLE,TRUE);
        d3dDevice->SetRenderState(D3DRENDERSTATE_ZWRITEENABLE,TRUE);
        d3dDevice->SetRenderState(D3DRENDERSTATE_ZFUNC,D3DCMP_LESSEQUAL);
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
    d3dDevice->SetRenderState(D3DRENDERSTATE_LASTPIXEL,FALSE);

    return VNGO_NO_ERROR;
}

VNGError VngoDirect3D::flip()
{
    if (frame_is_open)
        close_frame();

#ifndef RENDER_FRONT
//#if 0   // rendering to primary for Bruce.
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
                    return VNGO_INTERNAL_ERROR;
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
                return VNGO_INTERNAL_ERROR;
            }
        }
    }
#endif   // rendering to primary for Bruce.
    return VngoScreenManager::flip();
}

VNGError VngoDirect3D::set_palette(VngoPal *p,Flx16 brightness)
{
    pal = p;

    return VNGO_NO_ERROR;
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

VNGError VngoDirect3D::term()
{

    close_frame();


    if ((lflags & VNGO_SET_RESOLUTION) && dd != NULL)
        dd->RestoreDisplayMode();

    if (d3dViewport)
    {
        d3dViewport->Release();
        d3dViewport = NULL;
    }

    if (d3dDevice)
    {
        d3dDevice->Release();
        d3dDevice = NULL;
    }

    if (SurfaceManager)
    {
        delete SurfaceManager;
        SurfaceManager = NULL;
    }

    if (ZBuffer)
    {
        ZBuffer->Release();
        ZBuffer = NULL;
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
        if (BackBuffer == Primary)
            Primary = NULL;

        BackBuffer->Release();
        BackBuffer = NULL;
    }

    if (Primary)
    {
        Primary->Release();
        Primary = NULL;
    }

    if (VgSystem->D3DTx)
    {
        delete VgSystem->D3DTx;
        VgSystem->D3DTx = NULL;
    }

    if (d3d)
    {
        d3d->Release();
        d3d=NULL;
    }

    if (dd)
    {

        // Restore the normal cooperative level.

        dd->SetCooperativeLevel(hWndClient,DDSCL_NORMAL);

        dd->Release();
        dd = NULL;
    }
    return VNGO_NO_ERROR;
}

BOOL CALLBACK FindDeviceCallback(GUID *lpGUID,LPSTR szName,LPSTR szDevice,LPVOID lParam)
{
    char ach[128];
    VngoDirect3D    *screen = (VngoDirect3D *)lParam;

    wsprintf(ach,"%s (%s)",szName, szDevice);
    _strlwr(ach);

    if (strstr(ach,screen->target) != 0)
    {
        if (lpGUID)
        {
            screen->targetID = *lpGUID;
            return DDENUMRET_CANCEL;
        }
    }
    return DDENUMRET_OK;
}

BOOL CALLBACK EnumModesCallback(LPDDSURFACEDESC lpsdesc ,LPVOID lParam)
{
    return DDENUMRET_OK;
}



VNGError VngoDirect3D::dump_textures()
{
    return VNGO_NO_ERROR;
}

void VngoDirect3D::set_draw_state(dword state, D3DTEXTUREHANDLE handle)
{
    static dword            last_state=-1;
    static D3DTEXTUREHANDLE last_handle=0;

    if (last_handle != handle)
    {
        d3dDevice->SetRenderState(D3DRENDERSTATE_TEXTUREHANDLE,handle);
        last_handle = handle;
    }
    if (last_state != state)
    {
        bool always_set=FALSE;
        if (last_state == -1)
        {
            last_state = 0;
            always_set=TRUE;
        }
        if (((last_state & VNGO_D3DSFLAGS_ALPHA) != (state & VNGO_D3DSFLAGS_ALPHA)) || always_set)
        {
            if (state & VNGO_D3DSFLAGS_ALPHA)
            {
                d3dDevice->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, TRUE);
                d3dDevice->SetRenderState(D3DRENDERSTATE_DESTBLEND, D3DBLEND_BOTHSRCALPHA);
                d3dDevice->SetRenderState(D3DRENDERSTATE_SRCBLEND, D3DBLEND_BOTHSRCALPHA);
                last_state |= VNGO_D3DSFLAGS_ALPHA;
            }
            else
            {
                d3dDevice->SetRenderState(D3DRENDERSTATE_ALPHABLENDENABLE, FALSE);
                last_state &= ~VNGO_D3DSFLAGS_ALPHA;
            }

        }
        if (((last_state & VNGO_D3DSFLAGS_GOURAUD) != (state & VNGO_D3DSFLAGS_GOURAUD)) || always_set)
        {
            if (state & VNGO_D3DSFLAGS_GOURAUD)
            {
                last_state |= VNGO_D3DSFLAGS_GOURAUD;
                d3dDevice->SetRenderState(D3DRENDERSTATE_SHADEMODE, D3DSHADE_GOURAUD);
            }
            else
            {
                last_state &= ~VNGO_D3DSFLAGS_GOURAUD;
                d3dDevice->SetRenderState(D3DRENDERSTATE_SHADEMODE, D3DSHADE_FLAT);
            }
        }
        if (((last_state & VNGO_D3DSFLAGS_DITHER) != (state & VNGO_D3DSFLAGS_DITHER)) || always_set)
        {
            if (state & VNGO_D3DSFLAGS_DITHER)
            {
                last_state |= VNGO_D3DSFLAGS_DITHER;
                d3dDevice->SetRenderState(D3DRENDERSTATE_DITHERENABLE,TRUE);
            }
            else
            {
                last_state &= ~VNGO_D3DSFLAGS_DITHER;
                d3dDevice->SetRenderState(D3DRENDERSTATE_DITHERENABLE,TRUE);
            }
        }
        if (((last_state & VNGO_D3DSFLAGS_FILTER) != (state & VNGO_D3DSFLAGS_FILTER)) || always_set)
        {
            if (state & VNGO_D3DSFLAGS_FILTER)
            {
                last_state |= VNGO_D3DSFLAGS_FILTER;
                d3dDevice->SetRenderState(D3DRENDERSTATE_TEXTUREMAG, D3DFILTER_LINEAR);
                d3dDevice->SetRenderState(D3DRENDERSTATE_TEXTUREMIN, D3DFILTER_LINEAR);
            }
            else
            {
                last_state &= ~VNGO_D3DSFLAGS_FILTER;
                d3dDevice->SetRenderState(D3DRENDERSTATE_TEXTUREMAG, D3DFILTER_NEAREST);
                d3dDevice->SetRenderState(D3DRENDERSTATE_TEXTUREMIN, D3DFILTER_NEAREST);
            }
        }

        if (((last_state & VNGO_D3DSFLAGS_PERSPECTIVE) != (state & VNGO_D3DSFLAGS_PERSPECTIVE)) || always_set)
        {
            if (state & VNGO_D3DSFLAGS_PERSPECTIVE)
            {
                last_state |= VNGO_D3DSFLAGS_PERSPECTIVE;
                d3dDevice->SetRenderState(D3DRENDERSTATE_TEXTUREPERSPECTIVE, TRUE);
            }
            else
            {
                last_state &= ~VNGO_D3DSFLAGS_PERSPECTIVE;
                d3dDevice->SetRenderState(D3DRENDERSTATE_TEXTUREPERSPECTIVE, FALSE);
            }
        }
        if (((last_state & VNGO_D3DSFLAGS_TBLEND_MOD) != (state & VNGO_D3DSFLAGS_TBLEND_MOD)) || always_set)
        {
            if (state & VNGO_D3DSFLAGS_TBLEND_MOD)
            {
                last_state |= VNGO_D3DSFLAGS_TBLEND_MOD;
                d3dDevice->SetRenderState(D3DRENDERSTATE_TEXTUREMAPBLEND,D3DTBLEND_MODULATE);
            }
            else
            {
                last_state &= ~VNGO_D3DSFLAGS_TBLEND_MOD;
                d3dDevice->SetRenderState(D3DRENDERSTATE_TEXTUREMAPBLEND,D3DTBLEND_DECAL);
            }
        }
        if (((last_state & VNGO_D3DSFLAGS_CKEY_ENABLE) != (state & VNGO_D3DSFLAGS_CKEY_ENABLE)) || always_set)
        {
            if (state & VNGO_D3DSFLAGS_CKEY_ENABLE)
            {
                last_state |= VNGO_D3DSFLAGS_CKEY_ENABLE;
                d3dDevice->SetRenderState(D3DRENDERSTATE_COLORKEYENABLE,TRUE);
            }
            else
            {
                last_state &= ~VNGO_D3DSFLAGS_CKEY_ENABLE;
                d3dDevice->SetRenderState(D3DRENDERSTATE_COLORKEYENABLE,FALSE);
            }
        }
    }
}

