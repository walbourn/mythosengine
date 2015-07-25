//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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

#ifdef _OEMS

#ifdef _3DFX
    extern "C" {
    #include <glide.h>
    }
#endif // _3DFX

#ifdef _MSI
    #include <msi95.h>
#endif // _MSI

#ifdef _CLEAR_3D
    #include <wll3d.h>
#endif // _CLEAR_3D
#endif // _OEMS

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
    dword   type_info;
    dword   lflags;
    BOOL    init_state;
    BOOL    frame_is_open;
    RECT    damage_rect;

public:
    long    startx;
    long    starty;
    long    width;
    long    height;
    long    bit_depth;
    char    hwName[12];
    VngoPal *pal;

    enum { SCREENTYPE_DDRAW     = 1,
           SCREENTYPE_DIB       = 2,
           SCREENTYPE_D3D       = 3,
           SCREENTYPE_3DFX      = 4,
           SCREENTYPE_CLEAR3D   = 5,
           SCREENTYPE_MSI       = 6,
           SCREENTYPE_HYBRID    = 7};

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
    virtual void open_frame() {};
    virtual void close_frame() {};

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


    VngoDIB() {};
    VngoDIB(HWND hwndclient);

    virtual ~VngoDIB();

    virtual BOOL init();
    virtual void reinit(Flx16 brightness=0);
    virtual BOOL set_mode(int width, int height, int bpp, VngoPal *pal, dword flags = 0);
    virtual BOOL check_mode(int width, int height, int bpp);
    virtual void set_palette(VngoPal *p,Flx16 brightness=0);
    virtual void term();
    virtual void flip();
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

    virtual BOOL init();
    virtual void reinit(Flx16 brightness=0);
    virtual BOOL set_mode(int width, int height, int bpp, VngoPal *pal, dword flags = 0);
    virtual BOOL check_mode(int width, int height, int bpp);
    virtual void flip();
    virtual void set_palette(VngoPal *p,Flx16 brightness=0);
    virtual void term();

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Direct3D screen manager
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#ifdef _D3D
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
    LPDIRECTDRAWPALETTE     Palette;
    DDSURFACEDESC           ddsd;
    HFONT                   AppFont;
    HWND                    hWndClient;
    IDirect3D2              *d3d;
    IDirect3DDevice2        *d3dDevice;
    IDirect3DViewport2      *d3dViewport;
    char                    *target;

    VngoDirect3D() {};
    VngoDirect3D(HWND hwndclient);
    virtual ~VngoDirect3D();

    virtual BOOL init();
    virtual void reinit(Flx16 brightness=0);
    virtual BOOL set_mode(int width, int height, int bpp, VngoPal *pal, dword flags = 0);
    virtual BOOL check_mode(int width, int height, int bpp);
    virtual void flip();
    virtual void set_palette(VngoPal *p,Flx16 brightness=0);
    virtual void term();
    virtual void open_frame();
    virtual void close_frame();

};
#endif


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Cirrus Clear3D screen manager
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#ifdef _OEMS
#ifdef _CLEAR_3D

#define CLEAR3D_MAX_BATCH_COPROCESSOR 25
#define CLEAR3D_MAX_BATCH_PROCESSOR 1000

class VngoClear3D : public VngoScreenManager
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

    int                     BatchCount;
    ClrContext              *pContext;
    LL_Batch                *pBatchRef;
    LL_Batch                *pBatch;
    IvoryArena              *VertPool;

    VngoClear3D(HWND hwndclient);
    virtual ~VngoClear3D();
    virtual BOOL init();
    virtual void reinit(Flx16 brightness);
    virtual BOOL check_mode(int _width, int _height, int _bpp);
    virtual BOOL set_mode(int _width, int _height, int _bpp, VngoPal *_pal,dword flags);
    virtual void flip();
    virtual void set_palette(VngoPal *p,Flx16 brightness);
    virtual void open_frame();
    virtual void close_frame();
    virtual void flush();
    virtual void run_dl();
    virtual void wait_busy();
    virtual void term();

    LL_Batch *get_batch(int num_batches=1);
};
#endif _CLEAR_3D


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// 3D/fx Glide screen manager
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#ifdef _3DFX
class Vngo3Dfx : public VngoScreenManager
{
    GrHwConfiguration       hwconfig;
    GrScreenResolution_t    screenRes;

public:
    Vngo3Dfx();
    virtual ~Vngo3Dfx();

    virtual BOOL init();
    virtual void reinit(Flx16 brightness=0){return;};
    virtual BOOL set_mode(int width, int height, int bpp, VngoPal *pal, dword flags = 0);
    virtual BOOL check_mode(int width, int height, int bpp) {return FALSE;}
    virtual void flip();
    virtual void set_palette(VngoPal *p,Flx16 brightness=0){return;};
    virtual void term();
};
#endif // _3DFX


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Matrox Simple Interface screen manager
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#ifdef _MSI
class VngoMSI : public VngoScreenManager
{
    WNDPROC lpWinProc;
public:
    T_msiParameters     msiParms;
    T_msiInfo           *pInfo;
    QueryInfoStruct     BoardInfo;

    VngoMSI();
    VngoMSI(WNDPROC lpWindowProc);
    virtual ~VngoMSI();

    virtual BOOL init();
    virtual BOOL init(WNDPROC lpWindowProc=NULL);
    virtual void reinit(Flx16 brightness=0){return;};
    virtual BOOL set_mode(int width, int height, int bpp, VngoPal *pal, dword flags = 0);
    virtual BOOL check_mode(int width, int height, int bpp) {return FALSE;}
    virtual void flip();
    virtual void set_palette(VngoPal *p,Flx16 brightness=0){return;};
    virtual void term();

    virtual void open_frame()
    {
        if (!frame_is_open)
        {
            if (msiStartFrame(FALSE,0.f,0.f,0.f,FALSE,1.f))
            {
                frame_is_open = TRUE;
            }
        }
    }
    virtual void close_frame() { close_frame(0,0,1);}

    int close_frame(BOOL dump,long frame,BOOL wait)
    {
        if (frame_is_open)
        {
            if (msiEndFrame(dump,frame,wait))
            {
                frame_is_open=FALSE;
                return TRUE;
            }
            else
                return FALSE;
        }
        else
            return TRUE;
    }
};
#endif // _MSI
#endif // _OEMS

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - vngscrn.hpp ²±°

