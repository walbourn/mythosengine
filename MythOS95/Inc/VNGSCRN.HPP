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
// vngscrn.hpp
//
//     The screen manager classes.
//
//อออออออออออออออออออออออออออออ Revision History ออออออออออออออออออออออออออออ
//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

#ifndef __VNGSCRN_HPP
#define __VNGSCRN_HPP  1

#if 0
extern "C" {
#include <glide.h>
}
#endif

//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//
//                                Classes
//
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

// Direct Draw management class.
class VngoScreenManager
{
protected:
    dword   type_info;
    dword   lflags;
    BOOL    init_state;
    RECT    damage_rect;

public:
    long    startx;
    long    starty;
    long    width;
    long    height;
    VngoPal *pal;

    enum { SCREENTYPE_DDRAW = 1,
           SCREENTYPE_DIB = 2,
           SCREENTYPE_D3D = 3,
           SCREENTYPE_3DFX = 4,
           SCREENTYPE_LAGUNA = 5};

    virtual ~VngoScreenManager() {};

    void set_startxy(int sx,int sy) { startx = sx; starty = sy;}

    dword get_type () {return (type_info);}
    BOOL get_initstate() { return (init_state);}

    virtual BOOL init()=0;
    virtual void reinit(Flx16 brightness=0)=0;
    virtual BOOL set_mode(int width, int height, int bpp, VngoPal *pal, dword flags = 0)=0;
    virtual BOOL check_mode(int width, int height, int bpp)=0;
    virtual void set_palette(VngoPal *p,Flx16 brightness=0)=0;
    virtual void term()=0;
    virtual void flip()
    {
        damage_rect.left = width;
        damage_rect.right = 0;
        damage_rect.top = height;
        damage_rect.bottom = 0;
    }
    virtual void invalidate(const VngoRect &rect)
    {
        if (damage_rect.left > rect.x)
            damage_rect.left = rect.x;
        if (damage_rect.right < rect.x + rect.dx)
            damage_rect.right = rect.x + rect.dx;
        if (damage_rect.top > rect.y)
            damage_rect.top = rect.y;
        if (damage_rect.bottom < rect.y + rect.dy)
            damage_rect.bottom = rect.y + rect.dy;
    }
    virtual void invalidate()
    {
        damage_rect.top = 0;
        damage_rect.bottom = height;
        damage_rect.left = 0;
        damage_rect.right = width;
    }

};

class VngoDIB : public VngoScreenManager
{
public:
    HRESULT             err;
    LPDIRECTDRAW        dd;
    BITMAPINFO          *bmi;
    HDC                 hdc;
    BYTE                *gmap;
    HPALETTE            hpal;
    HWND                hWndClient;

    VngoDIB() {};
    VngoDIB(HWND hwndclient);
    virtual ~VngoDIB();

    virtual void flip() {VngoScreenManager::flip();}

};

class VngoDIB8 : public VngoDIB
{
public:
    VngoDIB8() {};
    VngoDIB8(HWND hwndclient);

    virtual ~VngoDIB8();

    virtual BOOL init();
    virtual void reinit(Flx16 brightness=0);
    virtual BOOL set_mode(int width, int height, int bpp, VngoPal *pal, dword flags = 0);
    virtual BOOL check_mode(int width, int height, int bpp);
    virtual void set_palette(VngoPal *p,Flx16 brightness=0);
    virtual void term();
    virtual void flip();

};


class VngoDirectDraw : public VngoScreenManager
{
public:
    HRESULT                 err;
    LPDIRECTDRAW            dd;
    LPDIRECTDRAWSURFACE     FrontBuffer;
    LPDIRECTDRAWSURFACE     BackBuffer;
    LPDIRECTDRAWSURFACE     Primary;
    VngoSurfaceManager      *SurfaceManager;
    LPDIRECTDRAWPALETTE     Palette;
    DDSURFACEDESC           ddsd;
    HFONT                   AppFont;
    HWND                    hWndClient;

    VngoDirectDraw() {};
    VngoDirectDraw(HWND hwndclient);
    virtual ~VngoDirectDraw();

    virtual BOOL init();
    virtual void reinit(Flx16 brightness=0);
    virtual BOOL set_mode(int width, int height, int bpp, VngoPal *pal, dword flags = 0);
    virtual BOOL check_mode(int width, int height, int bpp);
    virtual void flip();
    virtual void set_palette(VngoPal *p,Flx16 brightness=0);
    virtual void term();

};

#if 0
class Vngo3Dfx : public VngoScreenManager
{
    GrHwConfiguration       hwconfig;
    GrScreenResolution_t    screenRes;

public:
    Vngo3Dfx();
    virtual ~Vngo3Dfx();

    virtual BOOL Init();
    virtual void reinit(Flx16 brightness=0);
    virtual BOOL SetMode(int width, int height, int bpp, VngoPal *pal, dword flags = 0);
    virtual void Flip();
    virtual void set_palette(VngoPal *p,Flx16 brightness=0);
    virtual void Term();
};
#endif

class VngoD3D : public VngoScreenManager
{
public:
    VngoD3D();
    virtual ~VngoD3D();

    virtual BOOL Init();
    virtual void reinit(Flx16 brightness=0);
    virtual BOOL SetMode(int width, int height, int bpp, VngoPal *pal, dword flags = 0);
    virtual void Flip();
    virtual void set_palette(VngoPal *p,Flx16 brightness=0);
    virtual void Term();

};

#endif
//ฐฑฒ End of header - vngscrn.hpp ฒฑฐ

