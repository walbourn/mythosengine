//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. | 
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  | 
//                                                           |_|_|_._._.|
// Copyright (c) 1994-1996 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
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
// vngvp8.cpp
//
//     The C pluss pluss 8bpp view port classes.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <assert.h>
#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

STATIC void plot8(VngoVport *vp, long px, long py, long ox,
                  long oy, dword color);

STATIC void wide_plot8(VngoVport *vp, VngoRect *trect, long ox,
                       long oy, dword color);

STATIC void clip_plot8(VngoVport *vp, long px, long py, long ox,
                  long oy, dword color);

STATIC void clip_wide_plot8(VngoVport *vp, VngoRect *trect, long ox,
                       long oy, dword color);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±


void vngo_circle(VngoVport *vp,long xoffset, long yoffset,long r,dword color)
{
    int     x,y,e;

    y = r;
    x = 0;
    e = -y;
    while (x <= y)
    {
        plot8(vp,x,y,xoffset,yoffset,color);
        e +=(x<<1)+1;
        if (e > 0)
        {
            --y;
            e -= (y << 1);
        }
        ++x;
    }
}


STATIC void plot8(VngoVport *vp,long px,long py,long ox,long oy,dword color)
{
    VngoPoint   p1;
    p1.shade = vp->vbuff.pal->shd_pal->mid_point -1;
    p1.clr = color;
    p1.x = ox+px;
    p1.y = oy+py;
    vp->pixel(&p1);
    p1.y = oy-py;
    vp->pixel(&p1);
    p1.x = ox-px;
    vp->pixel(&p1);
    p1.y = oy+py;
    vp->pixel(&p1);

    p1.x = ox+py;
    p1.y = oy+px;
    vp->pixel(&p1);
    p1.y = oy-px;
    vp->pixel(&p1);
    p1.x = ox-py;
    vp->pixel(&p1);
    p1.y = oy+px;
    vp->pixel(&p1);
}


void vngo_circle(VngoVport *vp,long xoffset, long yoffset,
                 long r, dword color,int width)
{
    int         x,y,e, wmod = width >> 1;
    VngoRect    trect;

    trect.dx = trect.dy = width;


    y = r;
    x = 0;
    e = -y;
    while (x <= y)
    {
        trect.x = x - wmod;
        trect.y = y - wmod;
        wide_plot8(vp,&trect,xoffset,yoffset,color);
        e +=(x<<1)+1;
        if (e > 0)
        {
            --y;
            e -= (y << 1);
        }
        ++x;
    }
}


STATIC void wide_plot8(VngoVport *vp, VngoRect *trect,
                       long ox, long oy, dword color)
{
    VngoRect    tr = *trect;
    tr.x = ox+trect->x;
    tr.y = oy+trect->y;
    vp->frect(&tr,color);
    tr.y = oy-trect->y;
    vp->frect(&tr,color);
    tr.x = ox-trect->x;
    vp->frect(&tr,color);
    tr.y = oy+trect->y;
    vp->frect(&tr,color);

    tr.x = ox+trect->y;
    tr.y = oy+trect->x;
    vp->frect(&tr,color);
    tr.y = oy-trect->x;
    vp->frect(&tr,color);
    tr.x = ox-trect->y;
    vp->frect(&tr,color);
    tr.y = oy+trect->x;
    vp->frect(&tr,color);
}


void vngo_clip_circle(VngoVport *vp,long xoffset, long yoffset,long r,dword color)
{
    int     x,y,e;

    y = r;
    x = 0;
    e = -y;
    while (x <= y)
    {
        clip_plot8(vp,x,y,xoffset,yoffset,color);
        e +=(x<<1)+1;
        if (e > 0)
        {
            --y;
            e -= (y << 1);
        }
        ++x;
    }
}


STATIC void clip_plot8(VngoVport *vp,long px,long py,long ox,long oy,dword color)
{
    VngoPoint   p1;
    p1.shade = vp->vbuff.pal->shd_pal->mid_point -1;
    p1.clr = color;
    p1.x = ox+px;
    p1.y = oy+py;
    vp->clip_pixel(&p1);
    p1.y = oy-py;
    vp->clip_pixel(&p1);
    p1.x = ox-px;
    vp->clip_pixel(&p1);
    p1.y = oy+py;
    vp->clip_pixel(&p1);

    p1.x = ox+py;
    p1.y = oy+px;
    vp->clip_pixel(&p1);
    p1.y = oy-px;
    vp->clip_pixel(&p1);
    p1.x = ox-py;
    vp->clip_pixel(&p1);
    p1.y = oy+px;
    vp->clip_pixel(&p1);
}


void vngo_clip_circle(VngoVport *vp,long xoffset, long yoffset,
                 long r, dword color,int width)
{
    int         x,y,e, wmod = width >> 1;
    VngoRect    trect;

    trect.dx = trect.dy = width;


    y = r;
    x = 0;
    e = -y;
    while (x <= y)
    {
        trect.x = x - wmod;
        trect.y = y - wmod;
        clip_wide_plot8(vp,&trect,xoffset,yoffset,color);
        e +=(x<<1)+1;
        if (e > 0)
        {
            --y;
            e -= (y << 1);
        }
        ++x;
    }
}


STATIC void clip_wide_plot8(VngoVport *vp, VngoRect *trect,
                       long ox, long oy, dword color)
{
    VngoRect    tr = *trect;
    tr.x = ox+trect->x;
    tr.y = oy+trect->y;
    vp->clip_frect(&tr,color);
    tr.y = oy-trect->y;
    vp->clip_frect(&tr,color);
    tr.x = ox-trect->x;
    vp->clip_frect(&tr,color);
    tr.y = oy+trect->y;
    vp->clip_frect(&tr,color);

    tr.x = ox+trect->y;
    tr.y = oy+trect->x;
    vp->clip_frect(&tr,color);
    tr.y = oy-trect->x;
    vp->clip_frect(&tr,color);
    tr.x = ox-trect->y;
    vp->clip_frect(&tr,color);
    tr.y = oy+trect->x;
    vp->clip_frect(&tr,color);
}

//°±² End of module - vngcircl.cpp ²±°

