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
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
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
// DDrwscrn.cpp
//
// DirectDraw
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

VngoDirectDraw::VngoDirectDraw():
    dd(0),
    FrontBuffer(NULL),
    BackBuffer(NULL),
    Primary(NULL),
    SurfaceManager(NULL),
    ZBuffer(NULL),
    Palette(NULL),
    hWndClient(0)
{
    sins = 0;
    lflags = 0;
    frame_is_open = FALSE;
    strcpy(hwName,"Direct Draw");
    pal = NULL;
    init_state = VNGO_NOSCREEN_ERROR;
}


VngoDirectDraw::VngoDirectDraw(HWND hwndclient):
    dd(0),
    FrontBuffer(NULL),
    BackBuffer(NULL),
    Primary(NULL),
    SurfaceManager(NULL),
    ZBuffer(NULL),
    Palette(NULL),
    hWndClient(hwndclient)
{
    lflags = 0;
    frame_is_open = FALSE;
    sins = 0;
    strcpy(hwName,"Direct Draw");
    pal = NULL;
    init_state = init();
}

VngoDirectDraw::~VngoDirectDraw()
{
    if ((lflags & VNGO_SET_RESOLUTION) && dd != NULL)
        dd->RestoreDisplayMode();

    term();
}


VNGError VngoDirectDraw::init()
{
    strcpy(hwName,"DDraw");
    err = DirectDrawCreate(NULL, &dd, NULL);

    if (err != DD_OK)
    {
        term();
        return VNGO_INTERNAL_ERROR;
    }

    type_info = SCREENTYPE_DDRAW;
    return VNGO_NO_ERROR;
}


VNGError VngoDirectDraw::reinit(Flx16 brightness)
{
    if (!pal)
        return VNGO_NOT_SUPPORTED;

    return set_palette(pal,brightness);
}

VNGError VngoDirectDraw::check_mode(int _width, int _height, int bpp,dword _flags, VngoPixelInfo *pinfo)
{
    assert (dd != 0);

    return (VNGO_NOT_SUPPORTED);
}



VNGError VngoDirectDraw::set_mode(int _width, int _height, int bpp, VngoPal *_pal,dword flags)
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

    ZBuffer = NULL;
#if 0
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
        {
            term();
            return VNGO_INTERNAL_ERROR;
        }
    }
#endif

    SurfaceManager = new VngoSurfaceManager(FrontBuffer,ZBuffer);

    if (SurfaceManager == NULL)
    {
        term();
        return VNGO_MEMALLOC_ERROR;
    }
    // Create a palette if we are in a paletized display mode.

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
        return VNGO_INTERNAL_ERROR;

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
    sins |= VNGO_NO_FILTERS | VNGO_NO_FOG | VNGO_NOT_3DDEVICE;

    return VNGO_NO_ERROR;
}

VNGError VngoDirectDraw::flip()
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
    return VngoScreenManager::flip();
}

VNGError VngoDirectDraw::set_palette(VngoPal *p,Flx16 brightness)
{
    if (!Palette)
        return VNGO_NOT_SUPPORTED;

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

    return VNGO_NO_ERROR;
}



VNGError VngoDirectDraw::term()
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
    return VNGO_NO_ERROR;
}

VNGError VngoDirectDraw::dump_textures()
{
    return VNGO_NO_ERROR;
}

