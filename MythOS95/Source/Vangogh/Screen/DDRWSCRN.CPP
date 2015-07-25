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

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <windows.h>
#include <ddraw.h>
#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"
#include "vngscrn.hpp"

VngoDirectDraw::VngoDirectDraw(HWND hwndclient):
    dd(0),
    FrontBuffer(NULL),
    BackBuffer(NULL),
    SurfaceManager(NULL),
    Palette(NULL),
    hWndClient(hwndclient)
{
    strcpy(hwName,"Direct Draw");
    pal = NULL;
    init_state = init();
}

VngoDirectDraw::~VngoDirectDraw()
{
    term();
}


BOOL VngoDirectDraw::init()
{
    strcpy(hwName,"DDraw");
    err = DirectDrawCreate(NULL, &dd, NULL);

    if (err != DD_OK)
        return FALSE;

    type_info = SCREENTYPE_DDRAW;
    return TRUE;
}


void VngoDirectDraw::reinit(Flx16 brightness)
{
    if (!pal)
        return;

    set_palette(pal,brightness);
}

BOOL VngoDirectDraw::check_mode(int _width, int _height, int bpp)
{
    assert (dd != 0);

    return (FALSE);
}



BOOL VngoDirectDraw::set_mode(int _width, int _height, int bpp, VngoPal *_pal,dword flags)
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

    ZBuffer = NULL;

    if (flags & VNGO_ALLOC_ZBUFFER)
    {
        ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

        ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_VIDEOMEMORY;
        if (lflags & VNGO_3DDEVICE)
            ddsd.ddsCaps.dwCaps |= DDSCAPS_3DDEVICE;

        ddsd.dwHeight = height;
        if (bpp == 8)
            ddsd.dwWidth = width * 2;
        else if (bpp == 16)
            ddsd.dwWidth = width;
        err = dd->CreateSurface (&ddsd, &ZBuffer, NULL);

        if (err != DD_OK)
            return FALSE;
    }


    SurfaceManager = new VngoSurfaceManager(FrontBuffer,ZBuffer);

    if (SurfaceManager == NULL)
    {
        return FALSE;
    }
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

void VngoDirectDraw::flip()
{

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

void VngoDirectDraw::set_palette(VngoPal *p,Flx16 brightness)
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



void VngoDirectDraw::term()
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
