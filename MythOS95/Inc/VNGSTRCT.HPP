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
// vngstrct.hpp
//
//      This is the definition of the vngo_vbuffer.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __VNGSTRCT_HPP
#define __VNGSTRCT_HPP 1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
#include <string.h>
#include "vngpal.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Macros
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

struct VngoVbuffer;
class VngoTextureInfo;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// vngo_point is a 2D draw point, it contains all of the needed information ³
// needed to draw into the view port for most drawing types.                ³
// This structure is intentionaly 48 BYTES long.                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

class VngoPoint
{
public:
    long    wx;
    long    wy;
    long    wz;
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



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPoint2 is a 2D draw point, it contains all of the needed information ³
// needed to draw into the view port for most drawing types.                ³
// This structure is intentionaly 32 BYTES long.                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

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

    VngoPoint2 () {}
    VngoPoint2 (int _x, int _y, dword _clr) {x = _x; y = _y; clr = _clr;}
    VngoPoint2 (int _x, int _y, int _z, dword _clr,int _shade)
    {
        x = _x;
        y = _y;
        z = _z;
        clr = _clr;
        shade = _shade;
    }
    VngoPoint2 (VngoPoint pt)
    {   // This doen't copy the U and V coord info, since it needs to know
        // the size of the VngoTexture to scale them.
        x       = pt.x << 20;
        y       = pt.y << 20;
        z       = pt.z;
        clr     = pt.clr;
        shade   = pt.shade;
        w       = pt.w;
    }

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoPointF is a 2D draw point, it contains all of the needed information ³
// needed to draw into the view port for most drawing types.                ³
// This structure is intentionaly 32 BYTES long.  Uses floating point (u,v) ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

class VngoPointF
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

struct VngoTriangle
{
    // Info pointers.
    void            *sptr;
    void            *zptr;
    VngoVbuffer     *vbuff;
    VngoPoint2      *left_edge;
    VngoPoint2      *right_edge;

    VngoTextureInfo *tex;

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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// vngo_rect is a 2D filled rectangle, which has its uper left hand corner  ³
// defined by the point (x,y), it's width in dx, and it's height in dy.     ³
// This structure is intentionaly 16 BYTES long.                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
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

    int point_in(int _x,int _y)
    {
        if (_x >= x && _x < x + dx)
            if (_y >= y && _y < y + dy)
                return 1;
        return 0;
    }

    int point_in(VngoPoint &pt) {return point_in(pt.x,pt.y);}
};




//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// vngo_vbuffer is a view port structure which contains all of the info     ³
// needed to draw into the view port.                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

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



struct VngoTexture
{
    short   width;
    short   height;
    byte    *tex;
    dword   flags;

    VngoTexture() {flags = VNGO_TEXTURE_8BIT;}
    VngoTexture(dword _flags) {flags = _flags;}
    VngoTexture (short _width, short _height, byte *_tex, dword _flags = VNGO_TEXTURE_8BIT)
    {
        width   = _width;
        height  = _height;
        tex     = _tex;
        flags   = _flags;
    }
};

class VngoTextureInfo
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
};

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

#endif          // __VNGSTRCT_HPP

//°±² End of module - vngstrct.hpp ²±°

