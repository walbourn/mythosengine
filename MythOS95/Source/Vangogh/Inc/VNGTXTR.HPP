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
// Created by Tim Little
//
// vngtxtr.hpp
//
// Contains the texture classes definitions
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __VNGTXTR_HPP
#define __VNGTXTR_HPP 1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <string.h>
#include <ddraw.h>
#include <d3d.h>

#include "vngpal.hpp"

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
// Texture manager base class
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class VngoTexture3D;
class VngoScreenManager;
class VngoVport;

class VngoCacheHndl
{
public:
    dword           flags;
    VngoTexture3D   *tex;
    VngoCacheHndl   *next;
    VngoCacheHndl   *prev;

    ~VngoCacheHndl();
};

class VngoTextureManager
{
public:
    VngoScreenManager   *screen;
    VngoCacheHndl       *ready_head;
    VngoCacheHndl       *ready_tail;
    VngoCacheHndl       *out_head;
    VngoCacheHndl       *out_tail;

    VngoTextureManager ()
    {
        screen = NULL;
        ready_head = NULL;
        ready_tail = NULL;
        out_head = NULL;
        out_tail = NULL;
    }

    ~VngoTextureManager();
    VNGError ready(VngoCacheHndl *hndl);
    VNGError add(VngoCacheHndl *ntex,int ready=1);
    VNGError remove(VngoCacheHndl *ntex);


};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Texture classes
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
struct VngoTexture
{
    short           width;
    short           height;
    void            *tex;
    dword           flags;
    VngoTexture3D   *vtex3d;
    VngoPal         *pal_ptr;

    VngoTexture() :
        tex(0),
        flags(VNGO_TEXTURE_8BIT),
        vtex3d(0),
        pal_ptr(0)
    {}

    VngoTexture(dword _flags) :
        tex(0),
        flags(_flags),
        vtex3d(0),
        pal_ptr(0)
    {}

    VngoTexture (short _width, short _height,
                 void *_tex, dword _flags = VNGO_TEXTURE_8BIT,
                 VngoPal *_pal =0) :
        width(_width),
        height(_height),
        tex(_tex),
        flags(_flags),
        vtex3d(0),
        pal_ptr(_pal)
    {}

    ~VngoTexture() { release(); }

    void release();
    void make_dirty();
    VNGError create(short w, short h, int bits = 8, int trans = 1);
    VNGError convert(XFBitmap *bm, VngoPal *pal);

};

struct VngoCTexture : public VngoTexture
{
    dword   *ytable;

    VngoCTexture() {ytable=NULL;};
    VngoCTexture(VngoTexture *_tex);

    ~VngoCTexture() { release(); }

    VNGError init(VngoTexture *_tex);
    void release();
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// 3D texture classes
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class VngoTexture3D
{
protected:
    VngoTextureType dev_type;
    VNGError        err_status;

    VngoTexture3D ()
    {
        next = NULL;
        chandle = NULL;
        ref = NULL;
        palette = NULL;
        flags = 0;
    }
    VngoTexture3D (VngoTexture *_tex,VngoPal *_pal = NULL) { }
    VngoTexture3D (const VngoTexture3D &t);
    VngoTexture3D &operator= (const VngoTexture3D &t);

public:
    VngoCacheHndl   *chandle;
    VngoTexture     *ref;
    VngoTexture3D   *next;
    VngoPal         *palette;
    dword           flags;

    VngoTextureType get_type() {return (dev_type);}
    VNGError get_err_status() {return err_status;}

    virtual ~VngoTexture3D() {};
    virtual VNGError init(VngoTexture *_src,VngoPal *_pal=NULL) {return VNGO_NO_ERROR;}
    virtual VNGError reinit(VngoTexture *_src,VngoPal *_pal=NULL) {return VNGO_NO_ERROR;}
    virtual VNGError ready_texture() {return VNGO_NO_ERROR;}
    virtual void release() {};
};

class VngoMemTexture3D : public VngoTexture3D
{
    dword       iflags;
public:
    VngoTexture *vtxt;
    long        widthshift;
    long        heightshift;
    long        u_upshift;
    long        v_upshift;
    long        u_downshift;
    long        v_downshift;

    VngoMemTexture3D ();
    VngoMemTexture3D (VngoTexture *_src,VngoPal *_pal=NULL);
    virtual ~VngoMemTexture3D();
    virtual VNGError init(VngoTexture *_src,VngoPal *_pal=NULL);
    virtual VNGError reinit(VngoTexture *_src,VngoPal *_pal=NULL);
    virtual VNGError ready_texture() {return VNGO_NO_ERROR;};
    virtual void release();
};

class VngoD3DTexture3D : public VngoTexture3D
{
    dword       iflags;
    VNGError    load_texture();
public:
    IDirectDrawSurface  *MemorySurface;
    IDirectDrawSurface  *DeviceSurface;
    IDirectDrawPalette  *pal;
    D3DTEXTUREHANDLE    handle;

    VngoD3DTexture3D ()
    {
        dev_type = VNGO_D3D_TEX;
        MemorySurface = NULL;
        DeviceSurface = NULL;
        pal           = NULL;
        handle        = NULL;
        iflags        = NULL;
    }

    VngoD3DTexture3D (VngoTexture *_src,VngoPal *_pal=NULL);
    virtual ~VngoD3DTexture3D();
    virtual VNGError init(VngoTexture *_src,VngoPal *_pal=NULL);
    virtual VNGError reinit(VngoTexture *_src,VngoPal *_pal=NULL);
    virtual VNGError ready_texture();
    virtual void release();
private:
    VNGError restore();
};

#ifdef _OEMS
#ifdef _CLEAR_3D
class VngoCL3DTexture3D : public VngoTexture3D
{
    dword       iflags;
public:
    IDirectDrawSurface  *DeviceSurface;
    IDirectDrawPalette  *pal;

    VngoCL3DTexture3D ()
    {
        dev_type = VNGO_CLEAR3D_TEX;
        DeviceSurface = NULL;
        pal           = NULL;
    }

    VngoCL3DTexture3D (VngoTexture *_src,VngoPal *_pal=NULL);
    virtual ~VngoCL3DTexture3D();
    virtual VNGError init(VngoTexture *_src,VngoPal *_pal=NULL);
    virtual VNGError reinit(VngoTexture *_src,VngoPal *_pal=NULL);
    virtual VNGError ready_texture();
    virtual void release();
private:
    VNGError restore();
};
#endif          // _CLEAR_3D
#endif          // _OEMS


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ZMap class
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class VngoZMap
{
    dword       flags;
public:
    int         color;          // This is the color that all Zeros in
                                // the map should be drawn.
    dword       depth;          // This is the depth that should be
                                // assigned to all Zeros in the map.
    char        name[16];
    VngoTexture zmap;

    // This is the "persistant" format header.
    struct HDR
    {
        dword           ver;
        dword           size;
        short           width;
        short           height;
        int             color;
        dword           depth;
        char            name[16];
    };

    VngoZMap()
    {
        flags = 0;
        zmap.flags = VNGO_TEXTURE_MONO | VNGO_TEXTURE_ZMAP;
        strncpy (name,"Default",16);
    };

    ~VngoZMap()
    {
        if (zmap.tex && (flags & VNGO_MYMEM_ZMAP))
            delete [] zmap.tex;
    }

    void set_name(const char *n)
    {
        strncpy (name,n,16);
    }


    virtual int load(const char *fn);
    virtual int load(XFParseIFF *iffp);
    virtual int save(const char *fn);
    virtual int save(XFParseIFF *iffp);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// System class
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class VngoSystem
{
public:
    VngoVport           *cur_vport;
    VngoTextureManager  *DIBTx;     // Assumed to be a VngoDIB
    VngoTextureManager  *DDTx;      // Assumed to be a VngoDirectDraw
    VngoTextureManager  *D3DTx;     // Assumed to be a VngoDirect3D
    VngoTextureManager  *OGLTx;     // Assumed to be a VngoOpenGL
    VngoTextureManager  *CL3DTx;    // Assumed to be a VngoClear3D
    VngoTextureManager  *GlideTx;   // Assumed to be a Vngo3Dfx
    VngoTextureManager  *MSITx;     // Assumed to be a VngoMSI

    VngoSystem()
    {
        cur_vport = NULL;
        DIBTx = NULL;
        DDTx = NULL;
        D3DTx = NULL;
        OGLTx = NULL;
        CL3DTx = NULL;
        GlideTx = NULL;
        MSITx = NULL;
    }
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif          // __VNGTXTR_HPP

//°±² End of header - vngtxtr.hpp ²±°
