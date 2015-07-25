//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. | 
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  | 
//                                                           |_|_|_._._.|
// Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.   |.-.-.-.-..|
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
};

class VngoRectList;
           
class VngoRectList
{ 
public:            
    VngoRect        rect;
    VngoRectList    *next;

    VngoRectList() {next = NULL;}
    VngoRectList (VngoRect nrect)
    {
        rect.x = nrect.x;
        rect.y = nrect.y;
        rect.dx = nrect.dx;
        rect.dy = nrect.dy;
        next = NULL;
    }
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// vngo_point is a 2D draw point, it contains all of the needed information ³
// needed to draw into the view port for most drawing types.                ³
// This structure is intentionaly 32 BYTES long.                            ³
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

    VngoPoint () { shade = VNGO_SHADE_FLAT;}
};



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoTriangle structure holds all of the information that needs to be used³
//  to draw a triangle.  All of the parameters fit in this behemoth.        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class VngoTriangle
{
public:
    VngoPoint   *long_top;
    VngoPoint   *long_bottom;
    VngoPoint   *short_top;
    VngoPoint   *short_bottom;

    // Horizontal line info.
    long        z_step;
    long        shade_step;
    long        u_step1;
    long        u_step2;
    long        v_step1;
    long        v_step2;

    // Texture information
    long        u_upshift;      // how far to shift to cause automatic tiling.
    long        u_downshift;    // how far to shift to get to non-fixed point.
    long        v_upshift;      // how far to shift to cause automatic tiling.  
    long        v_downshift;    // how far to shift to get to non-fixed point.
    long        widthshift;     // shift up by this to multiply width.

    // Long edge info.
    long        long_x;
    long        long_x_step;
    long        long_z;
    long        long_z_step;
    long        long_s;
    long        long_s_step;
    long        long_u;
    long        long_u_step1;
    long        long_u_step2;
    long        long_v;
    long        long_v_step1;
    long        long_v_step2;
    long        long_w;
    long        long_w_step;

    // Short1 edge info.
    long        short_x;
    long        short_x_step;
    long        short_u;
    long        short_u_step1;
    long        short_u_step2;
    long        short_v;
    long        short_v_step1;
    long        short_v_step2;
    long        short_w;
    long        short_w_step;

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// vngo_vbuffer is a view port structure which contains all of the info     ³
// needed to draw into the view port.                                       ³
// This structure is intentionaly 40 BYTES long.                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

struct VngoVbuffer
{
    long    width;      // width of actual buffer.
    long    height;     // height of the actual buffer.
    long    left;       // left edge of buffer's clipping window.
    long    top;        // top edge of buffer's clipping window.
    byte    *scrn_ptr;  // view buffer pointer.
    VngoPal *pal;       // pointer to the palette for this Vbuffer.
    dword   *ytable;    // pointer to the table of pre-calculated y offsets.
    dword   *invert;    // table of 1/max(xres,yres) values to save divides.
    dword   *zbuff_ptr; // pointer to the ZBuffer if it exist.
    dword   na;
};



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// the lower 24bits of this are the RGB triple in x:8:8:8 format.           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
struct VngoRGBColor
{
    byte    r;
    byte    g;
    byte    b;
    byte    flags;
};


struct VngoTexture
{
    short   width;
    short   height;
    byte    *tex;
    dword   flags;
};

#endif          // __VNGSTRCT_HPP

//°±² End of module - vngstrct.hpp ²±°

