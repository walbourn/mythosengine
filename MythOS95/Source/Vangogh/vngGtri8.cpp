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
// vngtri8.cpp
//
//     The 8bpp specific polygon scan conversion code for VanGogh.
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  This section of code contains all of the code for Gouraud shaded        ³
//  polygons.                                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  void vngo_dghline8 (long y, VngoTriangle *tri, VngoVport *vp);          ³
//      This routine draws a Gouraud shaded horizontal line getting the     ³
//      color, shade and end point X coordinate information from the        ³
//      VngoTriangle structure, and the Y coordinate information from the   ³
//      y parameter that was passed in.                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_dghline8(long y, VngoTriangle *tri, VngoVport *vp)
{
    VngoPoint   pt;
    long        shade;
    long        x1,x2,step,t,dither;

    x1 = (tri->long_x + 0x100000) >> 20;
    x2 = (tri->short_x + 0x100000) >> 20;
    dither = ((x1 ^ y) & 0x1) << 2;
    shade = tri->long_s;

    if (x1 > x2)
    {
        step = -1;
        t = x1-x2;
    }
    else
    {
        step = 1;
        t = x2-x1;
    }

    byte            *sptr = vp->vbuff.scrn_ptr;;
    word            *zptr = (word *)vp->vbuff.zbuff_ptr;
    VngoShadePal8   *tp = (VngoShadePal8 *)vp->vbuff.pal->shd_pal;
    VngoColorShade8 *tc = &(*tp)[tri->long_top->clr];
    byte            color = tc->shl[tri->long_top->shade >> 3];
    dword           poffset = vp->vbuff.ytable[y] + x1;
    long            ts;

    for (int i=0;i <= t; i++)
    {
        ts = (shade >> 20) + dither;
        if (ts < 0) 
           ts = 0;
        else if (ts > 255)
           ts = 255;

        sptr[poffset] = tc->shl[ts >> 3];
        dither ^=0x4;
        poffset += step;
        shade += tri->shade_step;
    }
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  void vngo_dzghline8 (long y, VngoTriangle *tri, VngoVport *vp);         ³
//      This routine draws a Gouraud shaded horizontal line getting the     ³
//      color, shade and end point X coordinate information from the        ³
//      VngoTriangle structure, and the Y coordinate information from the   ³
//      y parameter that was passed in.  It draws with respect to the       ³
//      Z-buffer.                                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void vngo_dzghline8(long y, VngoTriangle *tri, VngoVport *vp)
{
    VngoPoint   pt;
    long        shade;
    long        x1,x2,step,t,dither;

    x1 = (tri->long_x + 0x80000) >> 20;
    x2 = (tri->short_x + 0x80000) >> 20;
    dither = ((x1 ^ y) & 0x1) << 2;
    shade = tri->long_s;

    if (x1 > x2)
    {
        step = -1;
        t = x1-x2;
    }
    else
    {
        step = 1;
        t = x2-x1;
    }

    byte            *sptr = vp->vbuff.scrn_ptr;;
    word            *zptr = (word *)vp->vbuff.zbuff_ptr;
    VngoShadePal8   *tp = (VngoShadePal8 *)vp->vbuff.pal->shd_pal;
    VngoColorShade8 *tc = &(*tp)[tri->long_top->clr];
    byte            color = tc->shl[tri->long_top->shade >> 3];
    dword           poffset = vp->vbuff.ytable[y] + x1;
    dword           z = tri->long_z;
    long            ts;

    for (int i=0;i <= t; i++)
    {
        if ((z >> 16) <= zptr[poffset])
        {
            ts = (shade >> 20) + dither;
#if 1
            if (ts < 0)  
                ts = 0;
            else if (ts > 255)
                ts = 255;
#endif
            sptr[poffset] = tc->shl[ts >> 3];
            zptr[poffset] = (word)(z >> 16);
        }
        dither ^=0x4;
        poffset += step;
        z += tri->z_step;
        shade += tri->shade_step;
    }
}




//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  void vngo_gtriangle8(VngoVport *vp,VngoPoint *pts,dword color)          ³
//      This routine draws a Gouraud shaded triangle, making the assumption ³
//      that it has already been clipped.                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_gtriangle8 (VngoVport *vp,VngoPoint *pts,dword color)
{
    VngoTriangle    tri;
    dword           stepped=0;
    long            dy;

    // fill in some pertinent info about the triangle.
    triangle_setup(pts,&tri);

    dy = tri.long_bottom->y - tri.long_top->y + 1;
    if (dy)
    {
        tri.long_x_step = vngo_calc_xstep(tri.long_top->x,
                                          tri.long_bottom->x,dy);
        tri.long_s_step = vngo_calc_sstep(tri.long_top->shade, 
                                          tri.long_bottom->shade, dy);
    }
    else
    {
        // if the long edge is horizontal, then there is nothing to draw!
        return;
    }

    dy = tri.short_bottom->y - tri.short_top->y + 1; 
    if (dy)
    {
        tri.short_x_step = vngo_calc_xstep(tri.short_top->x,
                                           tri.short_bottom->x, dy);
    }
    else
    {
        // if it has a flat top, it should have already been dealt with,
        // therefore if the short leg is horizontal, then the polygon is 
        // completely flat, and there is nothing to draw.
        return;
    }

    if (tri.short_top != tri.long_top)
    {
        // if the top of the short and long are not the same then the
        // triangle has a flat top!
        stepped = 1;
    }


    long            y = tri.long_top->y;

    //
    // Setup all of the starting edge values to be interpolated.
    //

    tri.long_x = tri.long_top->x << 20;
    tri.short_x = tri.short_top->x << 20;
    tri.long_s = tri.long_top->shade << 20;



    if (!stepped)
    {
        // calc the z step for the h-line.
        long    t2,t3;

        t3 = tri.long_s_step;
        t3 *= dy;
        t3 += tri.long_s;
        t3 = (tri.short_bottom->shade << 20) - t3;


        t2 = tri.long_x_step * dy;
        t2 += tri.long_x;
        t2 = (tri.short_bottom->x << 20) - t2;

        // t2 now has delta X for the hline.
        if (t2 < 0)
            t2 = -t2;

        t2 = t2 >> 20;
        t2++;

        // calculate the 12.20 shade_step for the horizontal lines.
        tri.shade_step = t3 / t2;
    }
    else
    {
        long    t2,t3;
        t2 = (tri.short_top->shade << 20) - tri.long_s;
        t3 = tri.short_x - tri.long_x;

        if (t3 < 0)
            t3 = -t3;

        t3 = t3 >> 20;
        t3++;

        // calculate the 12.20 shade_step for the horizontal lines.
        tri.shade_step = t2 / t3;
    }

    while (--dy)
    {
        vngo_dghline8(y,&tri,vp);
        y++;
        tri.long_x += tri.long_x_step;
        tri.short_x += tri.short_x_step;
        tri.long_s += tri.long_s_step;
    }

    if(!stepped)
    {
        stepped = 1;
        dy = tri.long_bottom->y - tri.short_bottom->y + 1;
        if (dy)
        {
            tri.short_x_step = vngo_calc_xstep(tri.short_bottom->x,
                                               tri.long_bottom->x, dy);
        }
        else
        {
            // if the second short leg is also zero, then the long leg should 
            // have already failed above.
            return;
        }
        tri.short_x = tri.short_bottom->x << 20;

        while (--dy)
        {
            vngo_dghline8(y,&tri,vp);
            y++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;
            tri.long_s += tri.long_s_step;
        }
    }
    return;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  void vngo_gtriangle8(VngoVport *vp,VngoPoint *pts,dword color)          ³
//      This routine draws a Gouraud shaded triangle, making the assumption ³
//      that it has already been clipped.  It draws with respect for the    ³
//      Z-buffer.                                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_zgtriangle8 (VngoVport *vp,VngoPoint *pts,dword color)
{
    VngoTriangle    tri;
    dword           stepped=0;
    long            dy;

    // fill in some pertinent info about the triangle.
    triangle_setup(pts,&tri);

    dy = tri.long_bottom->y - tri.long_top->y + 1;
    if (dy)
    {
        tri.long_x_step = vngo_calc_xstep(tri.long_top->x,
                                          tri.long_bottom->x,dy);
        tri.long_z_step = vngo_calc_zstep(tri.long_top->z, 
                                          tri.long_bottom->z,dy);
        tri.long_s_step = vngo_calc_sstep(tri.long_top->shade, 
                                          tri.long_bottom->shade, dy);
    }
    else
    {
        // if the long edge is horizontal, then there is nothing to draw!
        return;
    }

    dy = tri.short_bottom->y - tri.short_top->y + 1; 
    if (dy)
    {
        tri.short_x_step = vngo_calc_xstep(tri.short_top->x,
                                           tri.short_bottom->x, dy);
    }
    else
    {
        // if it has a flat top, it should have already been dealt with,
        // therefore if the short leg is horizontal, then the polygon is 
        // completely flat, and there is nothing to draw.
        return;
    }

    if (tri.short_top != tri.long_top)
    {
        // if the top of the short and long are not the same then the
        // triangle has a flat top!
        stepped = 1;
    }


    long            y = tri.long_top->y;

    //
    // Setup all of the starting edge values to be interpolated.
    //

    tri.long_x = tri.long_top->x << 20;
    tri.long_z = tri.long_top->z;
    tri.short_x = tri.short_top->x << 20;
    tri.long_s = tri.long_top->shade << 20;



    if (!stepped)
    {
        // calc the z step for the h-line.
        long    t1,t2,t3;
        t2 = tri.long_z_step;
        t2 *= dy;
        // the amount z gets changed over dy.
        t2 += tri.long_z;
        // t2 now has Z at the long edge ofsett dy lines from start.
        t1 = tri.short_bottom->z - t2;
        // t1 should now have the delta Z for the hline.

        t3 = tri.long_s_step;
        t3 *= dy;
        t3 += tri.long_s;
        t3 = (tri.short_bottom->shade << 20) - t3;


        t2 = tri.long_x_step * (dy - 1);
        t2 += tri.long_x + 0x80000;
        t2 = t2 >> 20;
        t2 = tri.short_bottom->x - t2;

        // t2 now has delta X for the hline.
        if (t2 < 0)
            t2 = -t2;
        t2++;

        // calculate the 16.16 z_step for the horizontal lines.
        tri.z_step = t1 / t2;
        // calculate the 12.20 shade_step for the horizontal lines.
        tri.shade_step = t3 / t2;
    }
    else
    {
        long    t1,t2,t3;
        t1 = tri.short_top->z - tri.long_z;
        t2 = (tri.short_top->shade << 20) - tri.long_s;
        t3 = tri.short_x - tri.long_x;

        if (t3 < 0)
            t3 = -t3;

        t3 = t3 >> 20;
        t3++;

        // calculate the 16.16 z_step for the horizontal lines.
        tri.z_step = t1 / t3;
        // calculate the 12.20 shade_step for the horizontal lines.
        tri.shade_step = t2 / t3;
    }

    while (dy--)
    {
        vngo_dzghline8(y,&tri,vp);
        y++;
        tri.long_x += tri.long_x_step;
        tri.short_x += tri.short_x_step;
        tri.long_z += tri.long_z_step;
        tri.long_s += tri.long_s_step;
    }

    if(!stepped)
    {
        stepped = 1;
        dy = tri.long_bottom->y - tri.short_bottom->y + 1;
        if (dy)
        {
            tri.short_x_step = vngo_calc_xstep(tri.short_bottom->x,
                                               tri.long_bottom->x, dy);
        }
        else
        {
            // if the second short leg is also zero, then the long leg should 
            // have already failed above.
            return;
        }
        tri.short_x = tri.short_bottom->x << 20;
        tri.short_x += tri.short_x_step;

        while (--dy)
        {
            vngo_dzghline8(y,&tri,vp);
            y++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;
            tri.long_z += tri.long_z_step;
            tri.long_s += tri.long_s_step;
        }
    }
    return;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  vngo_gpoly(VngoVbuffer *vb, int count, VngoPoint *pts);                 ³
//      Draws an N sided convex polygon, by breaking it down into triangles ³
//      if it is not already a triangle.  It draws with Gouraud shading.    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void vngo_gpoly8 (VngoVport *vp,int count,VngoPoint *pts)
{
    if (count != 3)
    {
        if (count > 3)
        {
            // if there are more than three vertices, break it into a series
            // of triangles.
            for (int i=1;i < count-1;i++)
            {
                VngoPoint tpts[3];
                tpts[0] = pts[0];
                tpts[1] = pts[i];
                tpts[2] = pts[i+1];
                if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
                    vngo_zgtriangle8 (vp,tpts,pts[0].clr);
                else
                    vngo_gtriangle8 (vp,tpts,pts[0].clr);
            }
        }
    }
    else
    {
        if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            vngo_zgtriangle8 (vp,pts,pts[0].clr);
        else
            vngo_gtriangle8 (vp,pts,pts[0].clr);
    }
}

//°±² End of module - vngtri8.cpp ²±°
