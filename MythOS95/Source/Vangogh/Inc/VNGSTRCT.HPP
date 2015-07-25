//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм
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
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
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
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
// vngstrct.hpp
//
// Contains the general structure definitions
//
//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм

#ifndef __VNGSTRCT_HPP
#define __VNGSTRCT_HPP 1

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                Includes
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

#include <string.h>
#include "vngpal.hpp"
#include "vngtxtr.hpp"

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                Classes
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

struct VngoVbuffer;
class VngoTexture3D;
class VngoMemTexture3D;

//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoPoint is a 2D draw point, it contains all of the needed information  Ё
// needed to draw into the view port for most drawing types.                Ё
// This structure is intentionaly 48 BYTES long.                            Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
class VngoPoint
{
public:
#if 1
    float   wx;
    float   wy;
    float   wz;
#else
    long    wx;
    long    wy;
    long    wz;
#endif
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


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoPoint2 is an internal version of VngoPoint                           Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
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


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoPointF is a 2D draw point, it contains all of the needed information Ё
// needed to draw into the view port for most drawing types.                Ё
// This structure is intentionaly 32 BYTES long.                            Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
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


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoPointF2 is an internal version of VngoPointF                         Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
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


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoTriangle is an internal structure                                    Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
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


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoRect is a 2D filled rectangle, which has its uper left hand corner   Ё
// defined by the point (x,y), it's width in dx, and it's height in dy.     Ё
// This structure is intentionaly 16 BYTES long.                            Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
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


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// VngoVbuffer is a view port structure which contains all of the info      Ё
// needed to draw into the view port.                                       Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
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

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif          // __VNGSTRCT_HPP

//╟╠╡ End of module - vngstrct.hpp ╡╠╟

