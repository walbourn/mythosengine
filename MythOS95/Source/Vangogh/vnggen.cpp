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
// vnggen.cpp
//
//อออออออออออออออออออออออออออออ Revision History ออออออออออออออออออออออออออออ
//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//
//                                Includes
//                                
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

#include <assert.h>
#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"

//ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ
//
//                                 Data
//
//ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ

inline void SWAP (int &a, int &b) 
{
#if 0
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;    
#else   // This is safer if a & b are references to the same variable.
    int t;
    t = a;
    a = b;
    b = t;
#endif
}

inline void COPYPOINT (VngoPoint *p1,VngoPoint *p2)
{
    p1->x = p2->x;
    p1->y = p2->y;
    p1->z = p2->z;
    p1->shade = p2->shade;
    p1->clr = p2->clr;
}     

//ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ
//
//                                 Code
//
//ฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ

void vngo_line (VngoVport *vp, VngoPoint *p1,VngoPoint *p2,VngoColor24bit *rgb_val)
{
// This is a straight forward Bresenham line algorithm with symetry.
    int dx = (p1->x < p2->x) ? (p2->x - p1->x) : (p1->x - p2->x);
    int dy = (p1->y < p2->y) ? (p2->y - p1->y) : (p1->y - p2->y);
    VngoPoint    pt1;
    VngoPoint    pt2;

    if (dx >= dy)
    {
        if (p1->x <= p2->x)
        {
            COPYPOINT(&pt1,p1);
            COPYPOINT(&pt2,p2);
        }
        else
        {
            COPYPOINT(&pt2, p1);
            COPYPOINT(&pt1, p2);
        }
    }
    else
    {
        if (p1->y <= p2->y)
        {
            COPYPOINT(&pt1, p1);
            COPYPOINT(&pt2, p2);
        }                  
        else               
        {                  
            COPYPOINT(&pt1, p2);
            COPYPOINT(&pt2, p1);
        }                  
    }

    int x1 = pt1.x;
    int x2 = pt2.x;
    int y1 = pt1.y;
    int y2 = pt2.y;
    int color = p1->clr;
    int shade = p1->shade;

    if (rgb_val)
    {
        color = vp->vbuff.pal->get_index(*rgb_val);
        shade = vp->vbuff.pal->shd_pal->mid_point - 1; 
    }

    pt1.clr = color;
    pt2.clr = color;
    pt1.shade = shade;
    pt2.shade = shade;

    int d,x,y,x3,y3,ydir=1,xdir=1;
    int i;
    Flx16 tz=0;
    Flx16 zstep=0;



    if(dy==0 || dx==0)
    {
        if(dy==0 && dx)
        {
            if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            {
                tz.flx = pt2.z - pt1.z;
                zstep = tz / Flx16 (x2 - x1);
            }
            // The horizontal line.
            pt1.y = y1;
            for (i=x1; i < x2; i++)
            {
                pt1.x = i;
                pt1.z += zstep.flx;
                vp->pixel(&pt1);
            }
        }
        else if (dy)
        {
            if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            {
                tz.flx = pt2.z - pt1.z;
                zstep = tz / Flx16 (y2 - y1);
            }
            // The vertical line.
            pt1.x = x1;
            for (i = y1; i < y2; i++)
            {   
                pt1.y = i;
                pt1.z += zstep.flx;
                vp->pixel(&pt1);
            }
        }
    }
    else
    {
        if(dx >= dy)
        {
            if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            {
                tz.flx = pt2.z - pt1.z;
                zstep = tz / Flx16 (x2 - x1);
            }
            if(y2<y1)
            {
                ydir=-1;
            }
            x=x1;
            y=y1;
            y3=y2;
            x3=x2;
            d=(dy<<1)-dx;
            while(x<x3)
            {
                if(d >= 0)
                {
                    x++;
                    x3--;
                    y3-=ydir;
                    y+=ydir;
                    d+=((dy-dx)<<1);
                }
                else
                {
                    x++;
                    x3--;
                    d+=(dy<<1);
                }
                pt1.x = x;
                pt1.y = y;
                pt1.z += zstep.flx;
                pt2.x = x3;
                pt2.y = y3;
                pt2.z -= zstep.flx;
                vp->pixel(&pt1);
                vp->pixel(&pt2);
            }
        }
        else
        {
            if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            {
                tz.flx = pt2.z - pt1.z;
                zstep = tz / Flx16 (y2 - y1);
            }
            if(x2<x1)
            {
                xdir=-1;
            }
            x=x1;
            y=y1;
            x3=x2;
            y3=y2;
            d=(dx<<1)-dy;

            while(y<y3)
            {
                if(d >= 0)
                {
                    y++;
                    y3--;
                    x+=xdir;
                    x3-=xdir;
                    d+=((dx-dy)<<1);
                }
                else
                {
                    y++;
                    y3--;
                    d+=(dx<<1);     
                }
                pt1.x = x;
                pt1.y = y;
                pt1.z += zstep.flx;
                pt2.x = x3;
                pt2.y = y3;
                pt2.z -= zstep.flx;
                vp->pixel(&pt1);
                vp->pixel(&pt2);
            }
        }
    }
    COPYPOINT(&pt1,p1);
    COPYPOINT(&pt2,p2);
    pt1.clr = color;
    pt2.clr = color;
    pt1.shade = shade;
    pt2.shade = shade;
    vp->pixel(&pt1);
    vp->pixel(&pt2);
}




void vngo_gline (VngoVport *vp, VngoPoint *p1,VngoPoint *p2,VngoColor24bit *rgb_val)
{
// This is a straight forward Bresenham line algorithm with symetry.
    int dx = (p1->x < p2->x) ? (p2->x - p1->x) : (p1->x - p2->x);
    int dy = (p1->y < p2->y) ? (p2->y - p1->y) : (p1->y - p2->y);
    VngoPoint    pt1;
    VngoPoint    pt2;

    if (dx >= dy)
    {
        if (p1->x <= p2->x)
        {
            COPYPOINT(&pt1, p1);
            COPYPOINT(&pt2, p2);
        }                  
        else               
        {                  
            COPYPOINT(&pt2, p1);
            COPYPOINT(&pt1, p2);
        }                  
    }                      
    else                   
    {                      
        if (p1->y <= p2->y)
        {                  
            COPYPOINT(&pt1, p1);
            COPYPOINT(&pt2, p2);
        }                  
        else               
        {                  
            COPYPOINT(&pt1, p2);
            COPYPOINT(&pt2, p1);
        }
    }

    int x1 = pt1.x;
    int x2 = pt2.x;
    int y1 = pt1.y;
    int y2 = pt2.y;
    int color = p1->clr;

    if (rgb_val)
        color = vp->vbuff.pal->get_index(*rgb_val);

    int d,x,y,x3,y3,ydir=1,xdir=1;
    int i;
    Flx16 tz;
    Flx16 zstep;
    Flx16 s1;
    Flx16 s2;
    Flx16 ts;
    Flx16 sstep;


    if(dy==0 || dx==0)
    {
        if(dy==0 && dx)
        {
            Flx16 tdx = x2 - x1;
            if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            {
                tz.flx = pt2.z - pt1.z;
                zstep = tz / tdx;
            }
            s1 = pt1.shade;
            s2 = pt2.shade;
            ts = s2 - s1;
            sstep = ts / tdx;
            // The horizontal line.
            pt1.y = y1;
            for (i=x1; i < x2; i++)
            {

                pt1.x = i;
                pt1.z += zstep.flx;
                s1 += sstep;
                pt1.shade = s1;
                vp->pixel(&pt1);
            }
        }
        else if (dy)
        {
            Flx16 tdy = y2 - y1;
            if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            {
                tz.flx = pt2.z - pt1.z;
                zstep = tz / tdy;
            }
            s1 = pt1.shade;
            s2 = pt2.shade;
            ts = s2-s1;
            sstep = ts / tdy;
            // The vertical line.

            pt1.x = x1;
            for (i = y1; i < y2; i++)
            {   
                pt1.y = i;
                pt1.z += zstep.flx;
                s1 += sstep;
                pt1.shade = s1;
                vp->pixel(&pt1);
            }
        }
    }
    else
    {
        if(dx >= dy)
        {
            Flx16 tdx = x2 - x1;
            if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            {
                tz.flx = pt2.z - pt1.z;
                zstep = tz / tdx;
            }
            s1 = pt1.shade;
            s2 = pt2.shade;
            ts = s2 - s1;
            sstep = ts / tdx;
            if(y2<y1)
            {
                ydir=-1;
            }
            x=x1;
            y=y1;
            y3=y2;
            x3=x2;
            d=(dy<<1)-dx;
            while(x<x3)
            {
                if(d >= 0)
                {
                    x++;
                    x3--;
                    y3-=ydir;
                    y+=ydir;
                    d+=((dy-dx)<<1);
                }
                else
                {
                    x++;
                    x3--;
                    d+=(dy<<1);
                }
                pt1.x = x;
                pt1.y = y;
                pt1.z += zstep.flx;
                s1 += sstep;
                pt1.shade = s1;

                pt2.x = x3;
                pt2.y = y3;
                pt2.z -= zstep.flx;
                s2 -= sstep;
                pt2.shade = s2;
                vp->pixel(&pt1);
                vp->pixel(&pt2);
            }
        }
        else
        {
            Flx16 tdy = y2 - y1;
            if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            {
                tz.flx = pt2.z - pt1.z;
                zstep = tz / tdy;
            }
            s1 = pt1.shade;
            s2 = pt2.shade;
            ts = s2-s1;
            sstep = ts / tdy;
            if(x2<x1)
            {
                xdir=-1;
            }
            x=x1;
            y=y1;
            x3=x2;
            y3=y2;
            d=(dx<<1)-dy;

            while(y<y3)
            {
                if(d >= 0)
                {
                    y++;
                    y3--;
                    x+=xdir;
                    x3-=xdir;
                    d+=((dx-dy)<<1);
                }
                else
                {
                    y++;
                    y3--;
                    d+=(dx<<1);     
                }
                pt1.x = x;
                pt1.y = y;
                pt1.z += zstep.flx;
                s1 += sstep;
                pt1.shade = s1;
                pt2.x = x3;
                pt2.y = y3;
                pt2.z -= zstep.flx;
                s2 -= sstep;
                pt2.shade = s2;

                vp->pixel(&pt1);
                vp->pixel(&pt2);
            }
        }
    }
    COPYPOINT(&pt1,p1);
    COPYPOINT(&pt2,p2);
    pt1.clr = color;
    pt2.clr = color;
    vp->pixel(&pt1);
    vp->pixel(&pt2);
}

//ฐฑฒ End of module - vnggen.cpp ฒฑฐ




