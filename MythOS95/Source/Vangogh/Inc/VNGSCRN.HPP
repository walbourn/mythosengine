//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                        http://www.mythos-engine.org/
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Tim Little
//
// vngscrn.hpp
//
// The screen manager classes.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __VNGSCRN_HPP
#define __VNGSCRN_HPP  1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "ivory.hpp"

#ifdef _OPENGL
#include "gl/gl.h"
#endif

#include <ddraw.h>
#include <d3d.h>

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Base screen manager
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class VngoScreenManager
{
protected:
    dword       type_info;
    dword       lflags;
    VNGError    init_state;
    BOOL        frame_is_open;
    RECT        damage_rect;

public:
    long        startx;
    long        starty;
    long        width;
    long        height;
    long        bit_depth;
    char        hwName[12];
    VngoPal     *pal;
    dword       sins;

    enum { SCREENTYPE_DDRAW     = 1,
           SCREENTYPE_DIB       = 2,
           SCREENTYPE_D3D       = 3,
           SCREENTYPE_3DFX      = 4,
           SCREENTYPE_CLEAR3D   = 5,
           SCREENTYPE_MSI       = 6,
           SCREENTYPE_OPENGL    = 7,
           SCREENTYPE_HYBRID    = 8};

    virtual ~VngoScreenManager() {};

    void set_startxy(int sx,int sy) { startx = sx; starty = sy;}
    dword get_flags() {return lflags;}
    dword get_type () {return (type_info);}
    VNGError get_initstate() { return (init_state);}

    virtual VNGError init()=0;
    virtual VNGError reinit(Flx16 brightness=0)=0;
    virtual VNGError set_mode(int width, int height, int bpp, VngoPal *pal, dword flags = 0)=0;
    virtual VNGError check_mode(int width, int height, int bpp, dword _flags, VngoPixelInfo *pinfo)=0;
    virtual VNGError set_palette(VngoPal *p,Flx16 brightness=0)=0;
    virtual VNGError term()=0;
    virtual VNGError flip()
    {
        damage_rect.left = width;
        damage_rect.right = 0;
        damage_rect.top = height;
        damage_rect.bottom = 0;
        return VNGO_NO_ERROR;
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
    virtual void open_frame() {};
    virtual void close_frame() {};
    virtual VNGError dump_textures()=0;

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Windows DIB screen manager
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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


    VngoDIB();
    VngoDIB(HWND hwndclient);

    virtual ~VngoDIB();

    virtual VNGError init();
    virtual VNGError reinit(Flx16 brightness=0);
    virtual VNGError set_mode(int width, int height, int bpp, VngoPal *pal, dword flags = 0);
    virtual VNGError check_mode(int width, int height, int bpp, dword _flags, VngoPixelInfo *pinfo);
    virtual VNGError set_palette(VngoPal *p,Flx16 brightness=0);
    virtual VNGError term();
    virtual VNGError flip();
    virtual VNGError dump_textures();
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// DirectDraw screen manager
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class VngoDirectDraw : public VngoScreenManager
{
public:
    HRESULT                 err;
    LPDIRECTDRAW            dd;
    LPDIRECTDRAWSURFACE     FrontBuffer;
    LPDIRECTDRAWSURFACE     BackBuffer;
    LPDIRECTDRAWSURFACE     Primary;
    LPDIRECTDRAWSURFACE     ZBuffer;
    VngoSurfaceManager      *SurfaceManager;
    LPDIRECTDRAWPALETTE     Palette;
    DDSURFACEDESC           ddsd;
    HFONT                   AppFont;
    HWND                    hWndClient;

    VngoDirectDraw();
    VngoDirectDraw(HWND hwndclient);
    virtual ~VngoDirectDraw();

    virtual VNGError init();
    virtual VNGError reinit(Flx16 brightness=0);
    virtual VNGError set_mode(int width, int height, int bpp, VngoPal *pal, dword flags = 0);
    virtual VNGError check_mode(int width, int height, int bpp, dword _flags, VngoPixelInfo *pinfo);
    virtual VNGError flip();
    virtual VNGError set_palette(VngoPal *p,Flx16 brightness=0);
    virtual VNGError term();
    virtual VNGError dump_textures();

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Windows DIB with DirectDraw blit screen manager
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class VngoHybrid : public VngoScreenManager
{
public:
    HRESULT                 err;
    LPDIRECTDRAW            dd;
    LPDIRECTDRAWSURFACE     FrontBuffer;
    LPDIRECTDRAWSURFACE     BackBuffer;
    LPDIRECTDRAWSURFACE     Primary;
    LPDIRECTDRAWPALETTE     Palette;
    DDSURFACEDESC           ddsd;
    HWND                    hWndClient;
    BYTE                    *gmap;
    int                     pitch;

    VngoHybrid();
    VngoHybrid(HWND hwndclient);
    virtual ~VngoHybrid();

    virtual VNGError init();
    virtual VNGError reinit(Flx16 brightness=0);
    virtual VNGError set_mode(int width, int height, int bpp, VngoPal *pal, dword flags = 0);
    virtual VNGError check_mode(int width, int height, int bpp, dword _flags, VngoPixelInfo *pinfo);
    virtual VNGError flip();
    virtual VNGError set_palette(VngoPal *p,Flx16 brightness=0);
    virtual VNGError term();
    virtual VNGError dump_textures();

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Direct3D screen manager
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class VngoDirect3D : public VngoScreenManager
{
public:
    HRESULT                 err;
    LPDIRECTDRAW            dd;
    LPDIRECTDRAWSURFACE     FrontBuffer;
    LPDIRECTDRAWSURFACE     BackBuffer;
    LPDIRECTDRAWSURFACE     Primary;
    LPDIRECTDRAWSURFACE     ZBuffer;
    VngoSurfaceManager      *SurfaceManager;
    DDSURFACEDESC           ddsd;
    HFONT                   AppFont;
    HWND                    hWndClient;
    IDirect3D2              *d3d;
    IDirect3DDevice2        *d3dDevice;
    IDirect3DViewport2      *d3dViewport;
    char                    *target;
    GUID                    targetID;

    VngoDirect3D();
    VngoDirect3D(HWND hwndclient,char *targetname=NULL);
    virtual ~VngoDirect3D();

    virtual VNGError init();
    virtual VNGError init(char *targetNam);
    virtual VNGError reinit(Flx16 brightness=0);
    virtual VNGError set_mode(int width, int height, int bpp, VngoPal *pal, dword flags = 0);
    virtual VNGError check_mode(int width, int height, int bpp, dword _flags, VngoPixelInfo *pinfo);
    virtual VNGError flip();
    virtual VNGError set_palette(VngoPal *p,Flx16 brightness=0);
    virtual VNGError term();

    virtual void open_frame();
    virtual void close_frame();
    virtual VNGError dump_textures();

    void set_draw_state(dword state, D3DTEXTUREHANDLE handle=0);
};


#define VNGO_D3DSFLAGS_GOURAUD          0x1
#define VNGO_D3DSFLAGS_DITHER           0x2
#define VNGO_D3DSFLAGS_PERSPECTIVE      0x4
#define VNGO_D3DSFLAGS_TBLEND_MOD       0x8
#define VNGO_D3DSFLAGS_CKEY_ENABLE      0x10
#define VNGO_D3DSFLAGS_ALPHA            0x20
#define VNGO_D3DSFLAGS_FILTER           0x40

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Cirrus Clear3D screen manager
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#ifdef _OPENGL
class VngoOpenGL : public VngoScreenManager
{
    LPDIRECTDRAW            dd;
    HWND                    hWndClient;
    HDC                     hDC;
    HGLRC                   hGLRC;
    PIXELFORMATDESCRIPTOR   pixDesc;
    int                     pixIndex;
    float                   xscale;
    float                   yscale;

public:
    VngoOpenGL();
    VngoOpenGL(HWND hwndclient);
    virtual ~VngoOpenGL();
    virtual VNGError init();
    virtual VNGError reinit(Flx16 brightness);
    virtual VNGError set_mode(int _width, int _height, int bpp, VngoPal *pal, dword flags = 0);
    virtual VNGError check_mode(int width, int height, int bpp, dword _flags, VngoPixelInfo *pinfo);
    virtual VNGError flip();
    virtual VNGError set_palette(VngoPal *p, Flx16 brightness);
    virtual VNGError term();
};
#endif // _OPENGL

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - vngscrn.hpp ²±°

