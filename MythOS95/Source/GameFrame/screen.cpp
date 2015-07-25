//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                        _/_/_/           _/_/_/_/
//                      _/                _/
//                     _/  _/_/          _/_/_/
//                    _/    _/  A M E   _/      R A M  E
//                     _/_/_/          _/
//
// A Framework for Microsoft Windows '95 Entertainment Software Using MythOS
//
//          Copyright (c) 1995 - 1997 by Charybdis Enterprises, Inc.
//                           All Rights Reserved
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// screen.cpp
//
// This module contains some basic support code for the screen management,
// including any DIB and DirectDraw initialization needed.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define WIN32_LEAN_AND_MEAN
#include <global.hpp>

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° GFScreen Class °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreen - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
GFScreen::GFScreen() :
    gvport(0),
    pal(0),
    curs_current (CURS_STD)
{
    for(int i=0; i < CURS_MAX; i++)
        curs[i]=NULL;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreen - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
GFScreen::~GFScreen()
{
    if (pal)
    {
        delete pal;
        pal=0;
    }
    if (gvport)
    {
        delete gvport;
        gvport=0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreen - init
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int GFScreen::init(int w, int h)
{
    width = w;
    height = h;

    curs[CURS_STD]      =LoadCursor(NULL,IDC_ARROW);
    curs[CURS_WAIT]     =LoadCursor(NULL,IDC_WAIT);

    for(int i=0; i < CURS_MAX; i++)
    {
        if (!curs[i])
            return 1;
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreen - load_palette
//
// Loads a VanGogh palette file and then calls set_palette for the
// loaded font.  Any old palette is orphaned if freeold is clear (set
// by default).
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int GFScreen::load_palette(const char *lpszFile, int freeold)
{
    assertMyth("GFScreen:load_palette needs gvport", gvport != 0);

    // Clean up any old palette information that is still around.
    if (freeold && pal)
        delete pal;

    // Initialize the Vangogh palette
    pal = new VngoPal8;
    if (pal == 0)
        return 1;

    if (pal->init (0, (char *)lpszFile) != 0)
        return 1;

    return set_palette(pal);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreen - lock
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
long GFScreen::lock()
{
    assertMyth("GFScreen::lock needs gvport",gvport != 0);

    return gvport->lock();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreen - unlock
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int GFScreen::unlock()
{
    assertMyth("GFScreen::unlock needs gvport",gvport != 0);

    return gvport->unlock();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreen - clear
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GFScreen::clear()
{
    assertMyth("GFScreen::clear needs gvport and palette",
               gvport != 0 && pal != 0);

    gvport->reset(pal->get_index (VngoColor24bit (0,0,0)));
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreen - invalidate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GFScreen::invalidate(const VngoRect &rct)
{
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°° GFScreenDD Class °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDD - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
GFScreenDD::GFScreenDD() :
    GFScreen(),
    lpDDSPrimary(0),
    lpDDPal(0),
    lpDD(0),
    SurfaceManager(0)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDD - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
GFScreenDD::~GFScreenDD()
{
    if (SurfaceManager != NULL)
    {
        delete SurfaceManager;
        SurfaceManager = NULL;
    }

    if (lpDDSPrimary != NULL)
    {
        lpDDSPrimary->Release();
        lpDDSPrimary = NULL;
    }
    if (lpDDPal != NULL)
    {
        lpDDPal->Release();
        lpDDPal = NULL;
    }

    if (lpDD != NULL)
    {
        lpDD->Release();
        lpDD = NULL;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDD - init
//
// Performs the initialization of the memory buffer and sets up a palette
// instance.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int GFScreenDD::init(int w, int h)
{
    if (GFScreen::init(w,h))
        return 1;

    HRESULT ddrval;

    // Attach to direct draw
    ddrval = DirectDrawCreate (NULL, &lpDD, NULL);
    if (ddrval != DD_OK)
        return 1;

    ddrval = lpDD->SetCooperativeLevel (hWndClient,
                                        DDSCL_FULLSCREEN
                                        | DDSCL_EXCLUSIVE
                                        | DDSCL_ALLOWMODEX);
    if (ddrval != DD_OK)
        return 1;

    ddrval = lpDD->SetDisplayMode (w, h, 8);
    if (ddrval != DD_OK)
        return 1;

    // Create the primary surface
    ddsd.dwSize = sizeof (ddsd);
    ddsd.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
    ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE |
                          DDSCAPS_FLIP |
                          DDSCAPS_COMPLEX |
                          DDSCAPS_VIDEOMEMORY;

    ddsd.dwBackBufferCount = 1;
    ddrval = lpDD->CreateSurface (&ddsd, &lpDDSPrimary, NULL);

    if (ddrval != DD_OK)
    {
        ddsd.ddsCaps.dwCaps &= ~DDSCAPS_VIDEOMEMORY;
        ddrval = lpDD->CreateSurface( &ddsd, &lpDDSPrimary, NULL);
    }

    if (ddrval != DD_OK)
        return 1;

    // Get the backbuffer.
    DDSCAPS caps;
    caps.dwCaps = DDSCAPS_BACKBUFFER;
    ddrval = lpDDSPrimary->GetAttachedSurface(&caps,&lpDDSBackBuffer);

    if (ddrval != DD_OK)
        return 1;

    SurfaceManager = new VngoSurfaceManager(lpDDSBackBuffer);

    // Now, create a standard palette
    pal = new VngoPal8;
    if (pal == 0)
        return 2;
    pal->init (0);

    // Create and set the DD palette
    PALETTEENTRY palEntry[256];
    for (int i = 1; i < 256; i++)
    {
        palEntry[i].peRed  = pal->hw_pal.p[i].r;
        palEntry[i].peGreen= pal->hw_pal.p[i].g;
        palEntry[i].peBlue = pal->hw_pal.p[i].b;
        palEntry[i].peFlags= 0;
    }

    ddrval = lpDD->CreatePalette (DDPCAPS_8BIT, palEntry, &lpDDPal, NULL);
    if (ddrval != DD_OK)
        return 1;

    ddrval = lpDDSPrimary->SetPalette (lpDDPal);
    if (ddrval != DD_OK)
        return 1;

    gvport = new VngoVportDD8 (SurfaceManager, NULL, pal, 0);
    if (!gvport || gvport->get_init_state())
        return 1;

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDD - set_palette
//
// Sets up Windows with the 'hardware' palette for the VanGogh data.
// Screen then assumes ownership of pointer.  Old palette is orphaned.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int GFScreenDD::set_palette(VngoPal8 *p)
{
    if (!p)
        return 1;

    assertMyth("GFScreenDD::set_palette needs gvport", gvport != 0);

    clear();
    flip();

    pal = p;
    gvport->vbuff.pal = pal;

    // Load the colors for DD
    PALETTEENTRY palEntry[256];
    for (int i = 1; i < 256; i++)
    {
        palEntry[i].peRed  = pal->hw_pal.p[i].r;
        palEntry[i].peGreen= pal->hw_pal.p[i].g;
        palEntry[i].peBlue = pal->hw_pal.p[i].b;
        palEntry[i].peFlags= 0;
    }

    // Now, recreate the DD palette
    if (lpDDPal)
        lpDDPal->Release();

    if (lpDD->CreatePalette (DDPCAPS_8BIT, palEntry, &lpDDPal, NULL) != DD_OK)
        return 1;

    if (lpDDSPrimary->SetPalette (lpDDPal) != DD_OK)
        return 1;

    clear();
    flip();

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDD - flip
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GFScreenDD::flip()
{
#if 0
    HRESULT ddrval;
    for (;;)
    {
        if ((ddrval = lpDDSPrimary->Flip (NULL, 0)) == DD_OK)
            break;

        if (ddrval == DDERR_SURFACELOST)
        {
            ddrval = lpDDSPrimary->Restore();
            if (ddrval != DD_OK)
                break;
        }
        if (ddrval != DDERR_WASSTILLDRAWING)
            break;
    }
#else
    if (lpDDSPrimary->IsLost() == DDERR_SURFACELOST)
        lpDDSPrimary->Restore();

    lpDDSPrimary->Blt(NULL,lpDDSBackBuffer, NULL,
                      DDBLT_ASYNC | DDBLT_WAIT, NULL);
#endif

}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDD - reinit
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GFScreenDD::reinit()
{
    if (!pal)
        return;

    // Load the colors for DD
    PALETTEENTRY palEntry[256];
    for (int i = 1; i < 256; i++)
    {
        palEntry[i].peRed  = pal->hw_pal.p[i].r;
        palEntry[i].peGreen= pal->hw_pal.p[i].g;
        palEntry[i].peBlue = pal->hw_pal.p[i].b;
        palEntry[i].peFlags= 0;
    }

    // Now, recreate the DD palette
    if (lpDDPal)
        lpDDPal->Release();

    if (lpDD->CreatePalette (DDPCAPS_8BIT, palEntry, &lpDDPal, NULL) == DD_OK)
        lpDDSPrimary->SetPalette (lpDDPal);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDD - create_subviewport
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VngoVport *GFScreenDD::create_subviewport(VngoRect &srect, dword flags)
{

    VngoVport *ret_val = new VngoVportDD8(SurfaceManager, NULL,srect,
                                          gvport->vbuff.pal, flags);
    return (ret_val);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°° GFScreenDIB Class °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#ifdef DEBUG
#define NOCHANGEMODE
#endif

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDIB - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
GFScreenDIB::GFScreenDIB(BOOL allowswitch) :
    GFScreen(),
    lpDD(0),
    hdc (GetDC (hWndClient)),
    bmi (0),
    hpal (0),
    bits (0),
    allow_mode_switch(allowswitch)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDIB - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
GFScreenDIB::~GFScreenDIB()
{
    if (hpal)
    {
        DeleteObject (hpal);
        hpal=0;
    }
    if (bmi)
        ivory_free ((void **)&bmi);
    if (bits)
    {
        delete [] bits;
        bits=0;
    }

#ifndef NOCHANGEMODE
    if (lpDD != NULL)
    {
        lpDD->Release();
        lpDD = NULL;
    }
#endif
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDIB - init
//
// Performs the initialization of the memory buffer and sets up a palette
// instance.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int GFScreenDIB::init(int w, int h)
{
    if (GFScreen::init(w,h))
        return 1;

#ifndef NOCHANGEMODE
    if (allow_mode_switch)
    {
        // Attach to direct draw
        HRESULT ddrval = DirectDrawCreate (NULL, &lpDD, NULL);
        if (ddrval == DD_OK)
        {
            ddrval = lpDD->SetCooperativeLevel (hWndClient,
                                                DDSCL_EXCLUSIVE
                                                | DDSCL_FULLSCREEN
                                                | DDSCL_ALLOWMODEX);
            if (ddrval != DD_OK)
                return 1;

            ddrval = lpDD->SetDisplayMode (w, h, 8);
            if (ddrval != DD_OK)
                return 1;
        }
    }
#endif

    // Specify the DIB parameters.
    bmi  = (LPBITMAPINFO)ivory_zalloc (sizeof (BITMAPINFOHEADER)
                                       + 256*sizeof (WORD));
    if (bmi == 0)
        return 3;

    bmi->bmiHeader.biSize        = sizeof (BITMAPINFOHEADER);
    bmi->bmiHeader.biWidth       = w;
    bmi->bmiHeader.biHeight      = -h;
    bmi->bmiHeader.biPlanes      = 1;
    bmi->bmiHeader.biBitCount    = 8;
    bmi->bmiHeader.biCompression = BI_RGB;
    bmi->bmiHeader.biClrUsed     = 256;
    bmi->bmiHeader.biClrImportant= 256;

    // Each entry maps onto the same entry in the logical palette
    for (int i = 0; i < 256; i++)
        LPWORD (bmi->bmiColors)[i]  = i;

    // Now, create a standard palette
    pal = new VngoPal8;
    if (pal == 0)
    {
        ivory_free ((void **)&bmi);
        return 2;
    }

    pal->init (0);

    bits   = new BYTE [width * height];
    gvport = new VngoVportDB8 (width, height, bits, NULL, pal, 0);

    if (bits == 0 || gvport == 0 || gvport->get_init_state())
        return 3;

    clear();

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDIB - set_palette
//
// Sets up Windows with the 'hardware' palette for the VanGogh data.
// Screen assumes ownership of the palette and old palette is orphaned.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int GFScreenDIB::set_palette(VngoPal8 *p)
{
    int res = 1;

    if (!p)
        return res;

    assertMyth("GFScreenDIB::set_palette needs gvport", gvport != 0);

    clear();
    flip();

    pal=p;
    gvport->vbuff.pal = pal;

    LOGPALETTE *lpal = (LOGPALETTE *)ivory_alloc (sizeof (LOGPALETTE) + 256 * sizeof (PALETTEENTRY));
    if (lpal != 0)
    {
        res = 1;

        lpal->palVersion = 0x300;
        lpal->palNumEntries = 256;
        for (int i = 0; i < 256; i++)
        {
            lpal->palPalEntry[i].peRed  = pal->hw_pal.p[i].r;
            lpal->palPalEntry[i].peGreen= pal->hw_pal.p[i].g;
            lpal->palPalEntry[i].peBlue = pal->hw_pal.p[i].b;
            lpal->palPalEntry[i].peFlags= PC_NOCOLLAPSE;
        }

        if (hpal)
            DeleteObject (hpal);

        // Create a palette and make it our own
        hpal = CreatePalette (lpal);
        if (hpal != 0)
        {
            res = 0;

            // Get this palette into the DC
            SelectPalette (hdc, hpal, FALSE);

            // Now, get this palette mapped into the system palette
            RealizePalette (hdc);
        }

        ivory_free ((void **)&lpal);
    }

    clear();
    flip();

    return res;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDIB - flip
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GFScreenDIB::flip()
{
    if (damage_rect.left < damage_rect.right &&
        damage_rect.top < damage_rect.bottom)
    {
#if 0
        SetDIBitsToDevice (hdc,
                           damage_rect.left, damage_rect.top,

//                           width, height,
                           damage_rect.right - damage_rect.left,
                           damage_rect.bottom - damage_rect.top,

                           damage_rect.left, damage_rect.bottom,
                           0, height,
                           bits, bmi, DIB_PAL_COLORS);
#else
        SetDIBitsToDevice (hdc,
                           damage_rect.left, damage_rect.top,   // dest coord

                           // src width, heigth
//                           width, height,
                           damage_rect.right - damage_rect.left,
                           damage_rect.bottom - damage_rect.top,

                           // src lower left coord
                           damage_rect.left, height - damage_rect.bottom,

                           // scanline start, stop
                           0, height,

                           // bits, DIB struct, flags
                           bits, bmi, DIB_PAL_COLORS);
#endif

        damage_rect.left = width;
        damage_rect.top  = height;
        damage_rect.bottom = 0;
        damage_rect.right  = 0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDIB - reinit
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GFScreenDIB::reinit()
{
    if (!pal)
        return;

    LOGPALETTE *lpal = (LOGPALETTE *)ivory_alloc (sizeof (LOGPALETTE) + 256 * sizeof (PALETTEENTRY));
    if (lpal != 0)
    {
        lpal->palVersion = 0x300;
        lpal->palNumEntries = 256;
        for (int i = 0; i < 256; i++)
        {
            lpal->palPalEntry[i].peRed  = pal->hw_pal.p[i].r;
            lpal->palPalEntry[i].peGreen= pal->hw_pal.p[i].g;
            lpal->palPalEntry[i].peBlue = pal->hw_pal.p[i].b;
            lpal->palPalEntry[i].peFlags= PC_NOCOLLAPSE;
        }

        if (hpal)
            DeleteObject (hpal);

        // Create a palette and make it our own
        hpal = CreatePalette (lpal);
        if (hpal != 0)
        {
            // Get this palette into the DC
            SelectPalette (hdc, hpal, FALSE);

            // Now, get this palette mapped into the system palette
            RealizePalette (hdc);
        }

        ivory_free ((void **)&lpal);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDIB - create_subviewport
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VngoVport *GFScreenDIB::create_subviewport(VngoRect &srect, dword flags)
{
    VngoVport *ret_val;
    int waslocked = lock();
    ret_val = new VngoVportDB8 (srect.dx, srect.dy,
                      gvport->vbuff.scrn_ptr + srect.x + gvport->vbuff.ytable[srect.y],
                      NULL, Screen->pal, flags, gvport->vbuff.pitch);

    if (!waslocked)
        unlock();
    return (ret_val);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDIB - clear
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GFScreenDIB::clear()
{
    GFScreen::clear();

    damage_rect.top  = 0;
    damage_rect.left = 0;
    damage_rect.bottom = height;
    damage_rect.right  = width;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDIB - invalidate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GFScreenDIB::invalidate(const VngoRect &rect)
{
    const int x2 = rect.x + rect.dx;
    const int y2 = rect.y + rect.dy;

    if (rect.x < damage_rect.left)
        damage_rect.left = rect.x;

    if (x2 > damage_rect.right)
        damage_rect.right = x2;

    if (rect.y < damage_rect.top)
        damage_rect.top = rect.y;

    if (y2 > damage_rect.bottom)
        damage_rect.bottom = y2;
}

//°±² eof - screen.cpp ²±°
