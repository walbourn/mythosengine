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
// DIBscrn.cpp
//
// Windows DIB/WinG
//
//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

#include <assert.h>
#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"
#include "vngscrn.hpp"

const int COLORS = 256;


VngoDIB::VngoDIB():
    dd(0),
    bmi(0),
    hdc(0),
    gmap(0),
    hpal(0),
    hWndClient(NULL)
{
    sins = 0;
    lflags = 0;
    frame_is_open=FALSE;
    strcpy(hwName,"DIB Draw");
    pal = NULL;
    init_state = VNGO_NOSCREEN_ERROR;
}


VngoDIB::VngoDIB(HWND hwndclient):
    dd(0),
    bmi(0),
    hdc(0),
    gmap(0),
    hpal(0),
    hWndClient(hwndclient)
{
    sins = 0;
    lflags = 0;
    frame_is_open=FALSE;
    strcpy(hwName,"DIB Draw");
    pal = NULL;
    init_state = init();
}

VngoDIB::~VngoDIB()
{
    if ((lflags & VNGO_SET_RESOLUTION) && dd != NULL)
        dd->RestoreDisplayMode();
    term();
}


VNGError VngoDIB::init()
{
    hdc = GetDC (hWndClient);

    err = DirectDrawCreate(NULL, &dd, NULL);

    if (err != DD_OK)
    {
        term();
        return VNGO_INTERNAL_ERROR;
    }

    type_info = SCREENTYPE_DIB;
    return VNGO_NO_ERROR;
}

VNGError VngoDIB::reinit(Flx16 brightness)
{
    if (!pal)
        return VNGO_NOT_SUPPORTED;

    return set_palette(pal,brightness);
}


VNGError VngoDIB::check_mode(int _width, int _height, int bpp, dword _flags, VngoPixelInfo *pinfo)
{
    assert (dd != 0);

    return (VNGO_NOT_SUPPORTED);
}

VNGError VngoDIB::set_mode(int _width, int _height, int bpp, VngoPal *_pal, dword flags)
{
    startx = 0;
    starty = 0;
    width = _width;
    height = _height;

    pal = _pal;

    if (bpp == 15 || bpp == 16)
    {
        if (!(pal->flags & VNGO_15BIT))
        {
            return VNGO_NEEDS_PAL15;
        }
        bit_depth = 15;
    }
    else if (bpp == 8)
        bit_depth = 8;
    else
    {
        term();
        return VNGO_NOT_SUPPORTED;
    }

    if (bpp == 8)
    {
        bmi = (LPBITMAPINFO)ivory_alloc (sizeof (BITMAPINFOHEADER) + COLORS*sizeof(WORD));
        if (bmi)
        {
            memset (bmi, 0, sizeof (*bmi));
            bmi->bmiHeader.biSize        = sizeof (BITMAPINFOHEADER);
            bmi->bmiHeader.biPlanes      = 1;
            bmi->bmiHeader.biBitCount    = bpp;
            bmi->bmiHeader.biCompression = BI_RGB;
            bmi->bmiHeader.biClrUsed     = COLORS;
            bmi->bmiHeader.biClrImportant= COLORS;
        }
        else
        {
            term();
            return VNGO_MEMALLOC_ERROR;
        }
    }
    else
    {
        bmi = (LPBITMAPINFO)ivory_alloc (sizeof (BITMAPINFOHEADER) + COLORS*sizeof(word));
        if (bmi)
        {
            memset (bmi, 0, sizeof (*bmi));
            bmi->bmiHeader.biSize         = sizeof (BITMAPINFOHEADER);
            bmi->bmiHeader.biPlanes       = 1;
            bmi->bmiHeader.biBitCount     = bpp;
            bmi->bmiHeader.biCompression  = 0;
            bmi->bmiHeader.biClrUsed      = 0;
            bmi->bmiHeader.biClrImportant = 0;
        }
        else
        {
            term();
            return VNGO_MEMALLOC_ERROR;
        }
    }


    assert (dd != 0);
    if (flags & VNGO_SET_RESOLUTION)
    {
        err = dd->SetCooperativeLevel(hWndClient,
            DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN | DDSCL_ALLOWMODEX);

        if (err == DD_OK)
            err = dd->SetDisplayMode(width, height, bpp);
        lflags |= VNGO_SET_RESOLUTION;
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

    gmap = new BYTE [width * height * (bpp / 8)];
    if (!gmap)
    {
        term();
        return VNGO_MEMALLOC_ERROR;
    }

    bmi->bmiHeader.biWidth = width;
    bmi->bmiHeader.biHeight = -height;
    if (pal && bpp == 8)
    {
        VngoPal *t=pal;
        LOGPALETTE *lpal = (LOGPALETTE *)ivory_alloc(sizeof(LOGPALETTE)+256*sizeof(PALETTEENTRY));
        lpal->palVersion = 0x300;
        lpal->palNumEntries = 256;
        for (int i=0; i < COLORS; i++)
        {
            ((WORD *)bmi->bmiColors)[i] = i;
            lpal->palPalEntry[i].peRed  = t->hw_pal.p[i].r;
            lpal->palPalEntry[i].peGreen= t->hw_pal.p[i].g;
            lpal->palPalEntry[i].peBlue = t->hw_pal.p[i].b;
            lpal->palPalEntry[i].peFlags= PC_NOCOLLAPSE;
        }
        // Force our palette into Windows
        // This should be a global; free it with DeleteObject (hpal);

        hpal = CreatePalette (lpal);
        if (hpal)
        {
            SelectPalette (hdc, hpal, FALSE);
            RealizePalette (hdc);
        }
        ivory_free ((void **)&lpal);
    }

    sins |= VNGO_NO_FILTERS | VNGO_NO_FOG | VNGO_NOT_3DDEVICE;
    invalidate();
    return VNGO_NO_ERROR;
}


VNGError VngoDIB::flip()
{
#if 1
    SetDIBitsToDevice (hdc,
                       damage_rect.left,
                       damage_rect.top,
                       damage_rect.right - damage_rect.left,
                       damage_rect.bottom - damage_rect.top,
                       damage_rect.left,
                       height - damage_rect.bottom,
                       0,height,
                       gmap, bmi, (bit_depth == 8) ? DIB_PAL_COLORS : DIB_RGB_COLORS);
#else
    SetDIBitsToDevice (hdc, 0,0,width,height,
                       0, 0, 0, height,
                       gmap, bmi, DIB_PAL_COLORS);

#endif
    return VngoScreenManager::flip();
}


VNGError VngoDIB::set_palette(VngoPal *p,Flx16 brightness)
{

    if (bit_depth == 8)
    {
        pal = p;
        VngoPal8 *t=(VngoPal8 *)p;
        LOGPALETTE *lpal = (LOGPALETTE *)ivory_alloc(sizeof(LOGPALETTE)+256*sizeof(PALETTEENTRY));
        lpal->palVersion = 0x300;
        lpal->palNumEntries = 256;
        for (int i=0; i < COLORS; i++)
        {
            VngoColorHLS hls;
            VngoColor24bit rgb;

            hls = t->hw_pal.p[i];
            hls.l += brightness;
            if(hls.l < 0)
                hls.l = 0;
            else if (hls.l > Flx16(1))
                hls.l = Flx16(1);

            rgb = hls;

            ((WORD *)bmi->bmiColors)[i] = i;
            lpal->palPalEntry[i].peRed  = rgb.r;
            lpal->palPalEntry[i].peGreen= rgb.g;
            lpal->palPalEntry[i].peBlue = rgb.b;

            lpal->palPalEntry[i].peFlags= PC_NOCOLLAPSE;
        }

        for (i = 0; i < 256; i++)
            LPWORD (bmi->bmiColors)[i]  = i;


        // Force our palette into Windows
        // This should be a global; free it with DeleteObject (hpal);

        if (hpal)
            DeleteObject(hpal);

        hpal = CreatePalette (lpal);

        if (hpal)
        {
            SelectPalette (hdc, hpal, FALSE);
            RealizePalette (hdc);
        }
        ivory_free ((void **)&lpal);
    }
    else
        pal = p;

    return VNGO_NO_ERROR;
}


VNGError VngoDIB::term()
{
    if (hpal)
        DeleteObject(hpal);

    if (dd)
    {
        err = dd->SetCooperativeLevel(hWndClient,DDSCL_NORMAL);
        dd->Release();
        dd = NULL;
    }

    if (bmi != NULL)
    {
        ivory_free((void **)&bmi);
    }

    if (gmap != NULL)
    {
        delete [] gmap;
    }

    ReleaseDC (NULL, hdc);

    return VNGO_NO_ERROR;
}

VNGError VngoDIB::dump_textures()
{
    return VNGO_NO_ERROR;
}

