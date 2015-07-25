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
// screen.hpp
//
// Contains the definitions for the Screen interface.  Here is where
// the DirectDraw and DIB engine calls will be localized
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __SCREEN_HPP
#define __SCREEN_HPP    1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreen
//
// This class is the basic screen management class.  Since games typically
// have a single 'screen', this manages a single window.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class GFScreen
{
public:
    enum cursor_type {
        CURS_STD    =0,
        CURS_WAIT   =1,
        CURS_MAX
    };

protected:
    cursor_type curs_current;
    HCURSOR     curs[CURS_MAX];

public:
    VngoVVport8 *gvport;
    VngoPal8    *pal;

    int         height;
    int         width;

    GFScreen ();
    virtual ~GFScreen ();

    virtual int init (int w, int h);
    virtual int load_palette (const char *, int freeold=1);
    virtual int set_palette (VngoPal8 *p) = 0;
    virtual void flip () = 0;
    virtual void reinit() = 0;
    virtual VngoVport *create_subviewport(VngoRect &screen_rect, dword flags) = 0;

    virtual long lock ();
    virtual int  unlock ();
    virtual void clear ();

    virtual void invalidate (const VngoRect &);
    void invalidate ()
    {
        VngoRect rect;
        rect.x=rect.y=0;
        rect.dx=width;
        rect.dy=height;
        invalidate(rect);
    }

    void cursor_set(cursor_type c)
    {
        curs_current=c;
        SetCursor(curs[curs_current]);
    }
    void cursor_off()  { SetCursor(NULL); }
    void cursor_on()  { SetCursor(curs[curs_current]); }
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDD
//
//  This is a DirectDraw implementation of the GFScreen class.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class GFScreenDD: public GFScreen
{
public:
    LPDIRECTDRAW        lpDD;
    LPDIRECTDRAWSURFACE lpDDSPrimary;
    LPDIRECTDRAWSURFACE lpDDSBackBuffer;
    VngoSurfaceManager  *SurfaceManager;
    LPDIRECTDRAWPALETTE lpDDPal;
    DDSURFACEDESC       ddsd;

public:
    GFScreenDD ();
    ~GFScreenDD ();

    int init (int w, int h);
    int set_palette (VngoPal8 *p);
    VngoVport *create_subviewport(VngoRect &screen_rect, dword flags);

    void flip ();
    void reinit ();
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GFScreenDIB
//
//  This is a DIB/GDI implementation of the GFScreen class.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class GFScreenDIB: public GFScreen
{
public:
    LPDIRECTDRAW    lpDD;
    HDC             hdc;
    LPBITMAPINFO    bmi;
    HPALETTE        hpal;

    BYTE            *bits;

    RECT            damage_rect;

    BOOL            allow_mode_switch;

public:
    GFScreenDIB (BOOL allowswitch);
    ~GFScreenDIB ();

    int init (int w, int h);
    int set_palette (VngoPal8 *p);
    VngoVport *create_subviewport(VngoRect &screen_rect, dword flags);

    void flip ();
    void reinit ();
    void clear ();

    void invalidate (const VngoRect &);
};

#endif

//°±² End of header - screen.hpp ²±°
