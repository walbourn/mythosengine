//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
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
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// Created by Tim Little
//
// vngstrct.hpp
//
// Contains the general structure definitions
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __VNGSTRCT_HPP
#define __VNGSTRCT_HPP 1

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <string.h>
#include "vngpal.hpp"
#include "vngtxtr.hpp"

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

struct VngoVbuffer;
class VngoTexture3D;
class VngoMemTexture3D;
class VngoSystem;

extern VngoSystem *VgSystem;
#ifndef __ESCH_EXPORT
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// System class
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class VngoSystem
{
public:
    float               gamma_correct;
    byte                gtable[256];
    byte                alpha_table[256*32];
    VngoVport           *cur_vport;
    VngoTextureManager  *DIBTx;     // Assumed to be a VngoDIB
    VngoTextureManager  *DDTx;      // Assumed to be a VngoDirectDraw
    VngoTextureManager  *D3DTx;     // Assumed to be a VngoDirect3D
    VngoTextureManager  *OGLTx;     // Assumed to be a VngoOpenGL

    VngoSystem()
    {
        VgSystem = this;
        set_gamma(1.f);
        init_alpha();
        cur_vport = NULL;
        DIBTx = NULL;
        DDTx = NULL;
        D3DTx = NULL;
        OGLTx = NULL;
    }
    void set_gamma (float gamma);
    void init_alpha ();
};

#endif

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPoint is a 2D draw point, it contains all of the needed information  �
// needed to draw into the view port for most drawing types.                �
// This structure is intentionaly 48 BYTES long.                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class VngoPoint
{
public:
    float   wx;
    float   wy;
    float   wz;
    long    x;
    long    y;
    long    z;
    dword   clr;
    long    shade;
    long    u;
    long    v;
    long    w;
    dword   pflags;

    VngoPoint () {}
    VngoPoint (int _x, int _y, dword _clr) {x = _x; y = _y; clr = _clr;}
    VngoPoint (int _x, int _y, int _z, dword _clr,int _shade)
    {
        x = _x;
        y = _y;
        z = _z;
        clr = _clr;
        shade = _shade;
    }

};

#if 1
class VngoPointF3
{
public:
    float   wx;
    float   wy;
    float   wz;

    float   x;
    float   y;
    float   z;
    dword   clr;
    long    shade;
    float   u;
    float   v;
    float   w;
    dword   pflags;
};
#endif


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPoint2 is an internal version of VngoPoint                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class VngoPoint2
{
public:
    long    x;
    long    y;
    dword   z;
    dword   clr;
    long    shade;
    long    u;
    long    v;
    long    w;

};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPointF is a 2D draw point, it contains all of the needed information �
// needed to draw into the view port for most drawing types.                �
// This structure is intentionaly 44 BYTES long.                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class VngoPointF
{
public:
    float   x;
    float   y;
    float   z;
    dword   clr;
    float   shade;
    float   u;
    float   v;
    float   w;
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoPointF2 is an internal version of VngoPointF                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class VngoPointF2
{
public:
    long    x;
    long    y;
    dword   z;
    dword   clr;
    long    shade;
    float   u;
    float   v;
    float   w;
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoTriangle is an internal structure                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
struct VngoTriangle
{
    // Info pointers.
    void            *sptr;
    void            *zptr;
    VngoVbuffer     *vbuff;
    VngoPoint2      *left_edge;
    VngoPoint2      *right_edge;

    VngoMemTexture3D *tex;

    // Raw info.
    long            start_y;
    long            height;
    long            color;
    long            shade;
    long            alpha;
    long            pitch;
    long            zpitch;

    // Perspective interpolants.
    long            wstep;

    // Shading interpolants.
    long            sstep_dx1;
    long            sstep_dx2;
    long            sstep_edge;
    long            sstep_edge_start;

    // Z interpolants.
    long            zstep_dx1;
    long            zstep_dx2;
    long            zstep_edge;
    long            zstep_edge_start;

    // Texture U innterpolants.
    long            ustep_dx1;
    long            ustep_dx2;
    long            ustep_edge;
    long            ustep_edge_start;

    // Texture V innterpolants.
    long            vstep_dx1;
    long            vstep_dx2;
    long            vstep_edge;
    long            vstep_edge_start;
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoRect is a 2D filled rectangle, which has its uper left hand corner   �
// defined by the point (x,y), it's width in dx, and it's height in dy.     �
// This structure is intentionaly 16 BYTES long.                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
struct VngoRect
{

    long    x;
    long    y;
    long    dx;
    long    dy;

    VngoRect () {}
    VngoRect (long _x, long _y, long _dx, long _dy)
    {
        x = _x;
        y = _y;
        dx = _dx;
        dy = _dy;
    }

    VNGError clip_to(VngoRect &crect);
    VNGError clip_to(VngoPoint *p1,VngoPoint *p2,dword flags);
    VNGError clip_to(VngoPointF *p1,VngoPointF *p2,dword flags);

    int point_in(int _x,int _y)
    {
        if (_x >= x && _x < x + dx)
            if (_y >= y && _y < y + dy)
                return 1;
        return 0;
    }

    int point_in(VngoPoint &pt) {return point_in(pt.x,pt.y);}
    int point_in(VngoPointF &pt) {return point_in(int(pt.x),int(pt.y));}
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// VngoVbuffer is a view port structure which contains all of the info      �
// needed to draw into the view port.                                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
struct VngoVbuffer
{
    long        width;      // width of actual buffer.
    long        height;     // height of the actual buffer.
    VngoPal     *pal;       // pointer to the palette for this Vbuffer.

    byte        *scrn_ptr;  // view buffer pointer.
    dword       pitch;      // Number of bytes to add to advance 1 scan line in the Frame Buffer.
    dword       *ytable;    // pointer to the table of pre-calculated y offsets.

    word        *zbuff_ptr; // pointer to the ZBuffer if it exist.
    dword       zpitch;     // Number of bytes to add to advance 1 scan line in the Z-Buffer.
    dword       *ztable;    // Offsets in bytes to each line in the Z-Buffer.

    VngoPoint2  *edge1;     // Edge arrays for the scan converters to use.
    VngoPoint2  *edge2;     // Edge arrays for the scan converters to use.
};

struct VngoPixelInfo
{
    long        bits_per_pixel;
    dword       rmask;
    dword       gmask;
    dword       bmask;
};

class VngoHazeInfo
{
public:
    VngoColor24bit  target_color;
    float           start_depth;    // Range 0 - 0.9999f things beyond, not hazed.
    float           mid_depth;      // so you can have a pheudo curve to the haze.

    VngoHazeInfo()
    {
        target_color.r = 255;       // Default to white.
        target_color.g = 255;
        target_color.b = 255;
        start_depth = 0.6f;         // a fair default.
        mid_depth = 0.85f;          // a fair default.
    }
};

class VngoHazeInfoVVP16
{
public:
    byte    *rtable;
    byte    *gtable;
    byte    *btable;
    dword   start_depth;

    VngoHazeInfoVVP16(){rtable=NULL;gtable=NULL;btable=NULL;}
    ~VngoHazeInfoVVP16();

    void setup(VngoHazeInfo *info);
    void release();
};

class VngoHazeInfoVVP8
{
public:
    byte    *htable;
    dword   start_depth;

    VngoHazeInfoVVP8(){htable=NULL;}
    ~VngoHazeInfoVVP8();

    void setup(VngoHazeInfo *info,VngoPal *pal);
    void release();
};

class VngoHazeInfoD3D
{
public:
    byte            fog_lut[256];
    VngoColor24bit  target_color;

    void setup(VngoHazeInfo *info);
    int get_fog(float z){return (int(fog_lut[int(z*255.f)]));}
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif          // __VNGSTRCT_HPP

//葦� End of module - vngstrct.hpp 憶�

