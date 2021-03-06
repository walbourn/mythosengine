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
// vngcircl.cpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <assert.h>
#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

STATIC void plot8(VngoVport *vp, long px, long py, long ox,
                  long oy, dword color);

STATIC void clip_plot8(VngoVport *vp, long px, long py, long ox,
                  long oy, dword color);

STATIC void plot8(VngoVport *vp, long px, long py, VngoPoint *center);

STATIC void clip_plot8(VngoVport *vp, long px, long py, VngoPoint *center);

STATIC void wide_plot8(VngoVport *vp, VngoRect *trect, long ox,
                       long oy, dword color);

STATIC void clip_wide_plot8(VngoVport *vp, VngoRect *trect, long ox,
                       long oy, dword color);





STATIC void plot8(VngoVport *vp, long px, long py, long ox,
                  long oy, VngoColor24bit *color);

STATIC void clip_plot8(VngoVport *vp, long px, long py, long ox,
                  long oy, VngoColor24bit *color);


//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

void vngo_circle(VngoVport *vp, VngoPoint *center, long r)
{
    int     x,y,e;

    y = r;
    x = 0;
    e = -y;
    while (x <= y)
    {
        plot8(vp,x,y,center);
        e +=(x<<1)+1;
        if (e > 0)
        {
            --y;
            e -= (y << 1);
        }
        ++x;
    }
}

STATIC void plot8(VngoVport *vp,long px,long py,VngoPoint *center)
{
    VngoPoint   p1=*center;
    p1.x = center->x+px;
    p1.y = center->y+py;
    vp->pixel(&p1);
    p1.y = center->y-py;
    vp->pixel(&p1);
    p1.x = center->x-px;
    vp->pixel(&p1);
    p1.y = center->y+py;
    vp->pixel(&p1);

    p1.x = center->x+py;
    p1.y = center->y+px;
    vp->pixel(&p1);
    p1.y = center->y-px;
    vp->pixel(&p1);
    p1.x = center->x-py;
    vp->pixel(&p1);
    p1.y = center->y+px;
    vp->pixel(&p1);
}



void vngo_clip_circle(VngoVport *vp, VngoPoint *center, long r)
{
    int     x,y,e;

    y = r;
    x = 0;
    e = -y;
    while (x <= y)
    {
        clip_plot8(vp,x,y,center);
        e +=(x<<1)+1;
        if (e > 0)
        {
            --y;
            e -= (y << 1);
        }
        ++x;
    }
}

STATIC void clip_plot8(VngoVport *vp,long px,long py,VngoPoint *center)
{
    VngoPoint   p1=*center;
    p1.x = center->x+px;
    p1.y = center->y+py;
    vp->clip_pixel(&p1);
    p1.y = center->y-py;
    vp->clip_pixel(&p1);
    p1.x = center->x-px;
    vp->clip_pixel(&p1);
    p1.y = center->y+py;
    vp->clip_pixel(&p1);

    p1.x = center->x+py;
    p1.y = center->y+px;
    vp->clip_pixel(&p1);
    p1.y = center->y-px;
    vp->clip_pixel(&p1);
    p1.x = center->x-py;
    vp->clip_pixel(&p1);
    p1.y = center->y+px;
    vp->clip_pixel(&p1);
}


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

void vngo_circle(VngoVport *vp,long xoffset, long yoffset,long r,VngoColor24bit *color)
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
    p1.shade = vp->vbuff.pal->shd_pal->mid_point;
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

STATIC void plot8(VngoVport *vp,long px,long py,long ox,long oy,VngoColor24bit *color)
{
    VngoPoint   p1;
    p1.x = ox+px;
    p1.y = oy+py;
    vp->pixel(&p1,color);
    p1.y = oy-py;
    vp->pixel(&p1,color);
    p1.x = ox-px;
    vp->pixel(&p1,color);
    p1.y = oy+py;
    vp->pixel(&p1,color);

    p1.x = ox+py;
    p1.y = oy+px;
    vp->pixel(&p1,color);
    p1.y = oy-px;
    vp->pixel(&p1,color);
    p1.x = ox-py;
    vp->pixel(&p1,color);
    p1.y = oy+px;
    vp->pixel(&p1,color);
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


void vngo_clip_circle(VngoVport *vp,long xoffset, long yoffset,long r,VngoColor24bit *color)
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
    p1.shade = vp->vbuff.pal->shd_pal->mid_point;
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



STATIC void clip_plot8(VngoVport *vp,long px,long py,long ox,long oy,VngoColor24bit *color)
{
    VngoPoint   p1;
    p1.x = ox+px;
    p1.y = oy+py;
    vp->clip_pixel(&p1,color);
    p1.y = oy-py;
    vp->clip_pixel(&p1,color);
    p1.x = ox-px;
    vp->clip_pixel(&p1,color);
    p1.y = oy+py;
    vp->clip_pixel(&p1,color);

    p1.x = ox+py;
    p1.y = oy+px;
    vp->clip_pixel(&p1,color);
    p1.y = oy-px;
    vp->clip_pixel(&p1,color);
    p1.x = ox-py;
    vp->clip_pixel(&p1,color);
    p1.y = oy+px;
    vp->clip_pixel(&p1,color);
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


//葦� End of module - vngcircl.cpp 憶�

