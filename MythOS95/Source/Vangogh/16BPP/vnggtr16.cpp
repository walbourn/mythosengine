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


STATIC void vngo_dghline8(long y, VngoTriangle *tri)
{
    long        shade;
    long        x1,x2,step,t,dither;

    x1 = (tri->long_x + 0x80000) >> 20;
    x2 = (tri->short_x + 0x80000) >> 20;

    if (tri->x_dir)
    {
        step = -1;
        t = x1-x2;
    }
    else
    {
        step = 1;
        t = x2-x1;
    }

    dither = ((x1 ^ y) & 0x1) << 22;
    shade = tri->long_s;

    byte            *stable_ptr = tri->stable_ptr;
    byte            *sptr = tri->hline_bptr + x1;
    word            *zptr = tri->hline_zptr + x1;
    long            ts;
    long            sstep = tri->shade_step;

    for (int i=0;i <= t; i++)
    {
        ts = (shade + dither) >> 23;
        if (ts < 0)  
            ts = 0;
        else if (ts > 32)
            ts = 32;

        *sptr = stable_ptr[ts];
        dither ^=0x400000;
        sptr += step;
        shade += sstep;
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
STATIC void vngo_dzghline8(long y, VngoTriangle *tri)
{
    long        shade;
    long        x1,x2,step,t,dither;

    x1 = (tri->long_x + 0x80000) >> 20;
    x2 = (tri->short_x + 0x80000) >> 20;

    if (tri->x_dir)
    {
        step = -1;
        t = x1-x2;
    }
    else
    {
        step = 1;
        t = x2-x1;
    }

    dither = ((x1 ^ y) & 0x1) << 22;
    shade = tri->long_s;

    byte            *stable_ptr = tri->stable_ptr;
    byte            *sptr = tri->hline_bptr + x1;
    word            *zptr = tri->hline_zptr + x1;
    dword           z = tri->long_z;
    long            ts;
    word            tz;
    dword           zstep = tri->z_step;
    dword           sstep = tri->shade_step;

    for (int i=0;i <= t; i++)
    {
        tz = (word) (z >> 16);
        if (tz < *zptr)
        {
            *zptr = tz;
            ts = (shade + dither) >> 23;

            if (ts < 0)  
                ts = 0;
            else if (ts > 32)
                ts = 32;

            *sptr = stable_ptr[ts];
        }
        dither ^=0x400000;
        sptr  += step;
        zptr  += step;
        shade += sstep;
        z     += zstep;
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
    int             pdrawn=0;

    // Decide if we need to subdivide the polygon.
    {
        int t = ((pts[0].x + 0x80000) >> 20) - 
                ((pts[1].x + 0x80000) >> 20);
        int t1= ((pts[1].x + 0x80000) >> 20) - 
                ((pts[2].x + 0x80000) >> 20);
        int t2= ((pts[2].x + 0x80000) >> 20) - 
                ((pts[0].x + 0x80000) >> 20);
        int maxx,edge_num;

        if (t < 0)
            t = -t;
        if (t1 < 0)
            t1 = -t1;
        if (t2 < 0)
            t2 = -t2;

        if (t > t1)
            if (t > t2)
            {
                maxx = t;
                edge_num = 0;
            }
            else 
            {
                maxx = t2;
                edge_num = 2;
            }
        else if (t1 > t2)
        {
            maxx = t1;
            edge_num = 1;
        }
        else
        {
            maxx = t2;
            edge_num = 2;
        }

        int ty = ((pts[0].y + 0x80000) >> 20) - 
                 ((pts[1].y + 0x80000) >> 20);
        int ty1= ((pts[1].y + 0x80000) >> 20) - 
                 ((pts[2].y + 0x80000) >> 20);
        int ty2= ((pts[2].y + 0x80000) >> 20) - 
                 ((pts[0].y + 0x80000) >> 20);
        int maxy,yedge_num;

        if (ty < 0)
            ty = -ty;
        if (ty1 < 0)
            ty1 = -ty1;
        if (ty2 < 0)
            ty2 = -ty2;

        if (ty > ty1)
            if (ty > ty2)
            {
                maxy = ty;
                yedge_num = 0;
            }
            else 
            {
                maxy = ty2;
                yedge_num = 2;
            }
        else if (ty1 > ty2)
        {
            maxy = ty1;
            yedge_num = 1;
        }
        else
        {
            maxy = ty2;
            yedge_num = 2;
        }

        if (maxy > maxx)
        {
            edge_num = yedge_num;
            maxx = maxy;
        }
        if (maxx >= vp->persp_pixcount)
        {
            VngoPoint  npoint;
            VngoPoint  npts[3];
            // we need to subdivide and call this again.
            if (edge_num == 0)
            {
                vngo_midpt(&pts[0],&pts[1],&npoint);
                npts[0] = pts[0];
                npts[1] = npoint;
                npts[2] = pts[2];
                vngo_gtriangle8 (vp, npts,color);
                npts[0] = npoint;
                npts[1] = pts[1]; 
                npts[2] = pts[2];
                vngo_gtriangle8 (vp, npts,color);
                pdrawn = 1;
            }
            else if (edge_num == 1)
            {
                vngo_midpt(&pts[1],&pts[2],&npoint);
                npts[0] = pts[0];
                npts[1] = pts[1];
                npts[2] = npoint;
                vngo_gtriangle8 (vp, npts,color);
                npts[0] = pts[0];
                npts[1] = npoint;
                npts[2] = pts[2]; 
                vngo_gtriangle8 (vp, npts,color);
                pdrawn = 1;
            }
            else
            {
                vngo_midpt(&pts[2],&pts[0],&npoint);
                npts[0] = pts[0];
                npts[1] = pts[1];
                npts[2] = npoint;
                vngo_gtriangle8 (vp, npts,color);
                npts[0] = npoint;
                npts[1] = pts[1];
                npts[2] = pts[2]; 
                vngo_gtriangle8 (vp, npts,color);
                pdrawn = 1;
            }
        }

    }
    if (pdrawn)
        return;

    // fill in some pertinent info about the triangle.
    triangle_setup(pts,&tri);

    tri.x_dir = 0;
    VngoShadePal8   *tp = (VngoShadePal8 *)vp->vbuff.pal->shd_pal;
    VngoColorShade8 *tc = &(*tp)[tri.long_top->clr];
    tri.stable_ptr = &(tc->shl[0]);

    tri.hline_bptr = (byte *)((dword)vp->vbuff.scrn_ptr + vp->vbuff.ytable[(tri.long_top->y + 0x80000) >> 20]);

    dy = ((tri.long_bottom->y + 0x80000) >> 20) - 
         ((tri.long_top->y + 0x80000) >> 20);
    if (dy)
    {
        tri.long_x_step = vngo_calc_xstep(tri.long_top->x,
                                          tri.long_bottom->x,dy);
        tri.long_s_step = vngo_calc_xstep(tri.long_top->shade, 
                                          tri.long_bottom->shade, dy);
    }

    else
    {
        // if the long edge is horizontal, then there is nothing to draw!
        int left=0;
        int right = 0;
        if (pts[1].x > pts[0].x)
        {
            if (pts[1].x > pts[2].x)
            {
                right = 1;
                if (pts[2].x < pts[0].x)
                    left = 2;
            }
            else
            {
                right = 2;
            }
        }
        else if (pts[2].x > pts[0].x)
        {
            left = 1;
            right = 2;
        }
        else if (pts[1].x > pts[2].x)
        {
            left = 2;
        }
        else
        {
            left =1;
        }
        int t = ((pts[right].x + 0x80000) >> 20) - 
                ((pts[left].x + 0x80000) >> 20);
        if (t)
        {
            tri.long_x = pts[left].x;
            tri.long_z = pts[left].z;
            tri.long_s = pts[left].shade;

            tri.short_x = pts[right].x;


            tri.shade_step = (tri.long_s - pts[right].shade)/t;

            vngo_dghline8(pts[0].y,&tri);
        }
        else
        {
            VngoPoint   t;
            t.x = pts->x >> 20;
            t.y = pts->y >> 20;
            t.clr = pts->clr;
            t.shade = pts->shade >> 20;
            t.z = pts->z;
            vp->pixel(&t);
        }
        return;
    }

    dy = ((tri.short_bottom->y + 0x80000) >> 20) - 
         ((tri.short_top->y + 0x80000) >> 20); 
    if (dy)
    {
        tri.short_x_step = vngo_calc_xstep(tri.short_top->x,
                                           tri.short_bottom->x, dy);
    }

    if (tri.short_top != tri.long_top)
    {
        // if the top of the short and long are not the same then the
        // triangle has a flat top!
        stepped = 1;
    }


    long    y = tri.long_top->y >> 20;

    //
    // Setup all of the starting edge values to be interpolated.
    //

    tri.long_x = tri.long_top->x;
    tri.short_x = tri.short_top->x;
    tri.long_s = tri.long_top->shade;



    if (!stepped)
    {
        // calc the z step for the h-line.
        long    t2,t3;

        t3 = tri.long_s_step;
        t3 *= dy;
        t3 += tri.long_s;
        t3 = (tri.short_bottom->shade) - t3;


        t2 = tri.long_x_step * dy;
        t2 += tri.long_x;
        t2 = (t2 + 0x80000) >> 20;
        t2 = ((tri.short_bottom->x + 0x8000) >> 20) - t2;

        if (t2 < 0)
        {
            t2 = -t2;
            tri.x_dir = -1;
        }

        if (t2)
        {
            // calculate the 12.20 shade_step for the horizontal lines.
            tri.shade_step = t3 / t2;
        }
        else
        {
            tri.shade_step = 0;
        }
    }
    else
    {
        long    t2,t3;
        t2 = (tri.short_top->shade) - tri.long_s;
        t3 = ((tri.short_x + 0x80000) >> 20) - 
             ((tri.long_x + 0x80000) >> 20);

        if (t3 < 0)
        {
            t3 = -t3;
            tri.x_dir = -1;
        }

        if (t3)
        {
            // calculate the 12.20 shade_step for the horizontal lines.
            tri.shade_step = t2 / t3;
        }
        else
        {
            tri.shade_step = 0;
        }
    }

    dy++;
    while (dy--)
    {
        vngo_dghline8(y,&tri);
        y++;
        tri.long_x += tri.long_x_step;
        tri.short_x += tri.short_x_step;
        tri.long_s += tri.long_s_step;
        tri.hline_bptr += vp->vbuff.pitch;
    }

    if(!stepped)
    {
        stepped = 1;
        dy = ((tri.long_bottom->y + 0x80000) >> 20) - 
             ((tri.short_bottom->y + 0x80000) >> 20);
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
        tri.short_x = tri.short_bottom->x;
        tri.short_x += tri.short_x_step;

        while (--dy)
        {
            vngo_dghline8(y,&tri);
            y++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;
            tri.long_s += tri.long_s_step;
            tri.hline_bptr += vp->vbuff.pitch;
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
    int             pdrawn=0;

    // Decide if we need to subdivide the polygon.
    {
        int t = ((pts[0].x + 0x80000) >> 20) - 
                ((pts[1].x + 0x80000) >> 20);
        int t1= ((pts[1].x + 0x80000) >> 20) - 
                ((pts[2].x + 0x80000) >> 20);
        int t2= ((pts[2].x + 0x80000) >> 20) - 
                ((pts[0].x + 0x80000) >> 20);
        int maxx,edge_num;

        if (t < 0)
            t = -t;
        if (t1 < 0)
            t1 = -t1;
        if (t2 < 0)
            t2 = -t2;

        if (t > t1)
            if (t > t2)
            {
                maxx = t;
                edge_num = 0;
            }
            else 
            {
                maxx = t2;
                edge_num = 2;
            }
        else if (t1 > t2)
        {
            maxx = t1;
            edge_num = 1;
        }
        else
        {
            maxx = t2;
            edge_num = 2;
        }

        int ty = ((pts[0].y + 0x80000) >> 20) - 
                 ((pts[1].y + 0x80000) >> 20);
        int ty1= ((pts[1].y + 0x80000) >> 20) - 
                 ((pts[2].y + 0x80000) >> 20);
        int ty2= ((pts[2].y + 0x80000) >> 20) - 
                 ((pts[0].y + 0x80000) >> 20);
        int maxy,yedge_num;

        if (ty < 0)
            ty = -ty;
        if (ty1 < 0)
            ty1 = -ty1;
        if (ty2 < 0)
            ty2 = -ty2;

        if (ty > ty1)
            if (ty > ty2)
            {
                maxy = ty;
                yedge_num = 0;
            }
            else 
            {
                maxy = ty2;
                yedge_num = 2;
            }
        else if (ty1 > ty2)
        {
            maxy = ty1;
            yedge_num = 1;
        }
        else
        {
            maxy = ty2;
            yedge_num = 2;
        }

        if (maxy > maxx)
        {
            edge_num = yedge_num;
            maxx = maxy;
        }
        if (maxx >= vp->persp_pixcount)
        {
            VngoPoint  npoint;
            VngoPoint  npts[3];
            // we need to subdivide and call this again.
            if (edge_num == 0)
            {
                vngo_midpt(&pts[0],&pts[1],&npoint);
                npts[0] = pts[0];
                npts[1] = npoint;
                npts[2] = pts[2];
                vngo_zgtriangle8 (vp, npts,color);
                npts[0] = npoint;
                npts[1] = pts[1]; 
                npts[2] = pts[2];
                vngo_zgtriangle8 (vp, npts,color);
                pdrawn = 1;
            }
            else if (edge_num == 1)
            {
                vngo_midpt(&pts[1],&pts[2],&npoint);
                npts[0] = pts[0];
                npts[1] = pts[1];
                npts[2] = npoint;
                vngo_zgtriangle8 (vp, npts,color);
                npts[0] = pts[0];
                npts[1] = npoint;
                npts[2] = pts[2]; 
                vngo_zgtriangle8 (vp, npts,color);
                pdrawn = 1;
            }
            else
            {
                vngo_midpt(&pts[2],&pts[0],&npoint);
                npts[0] = pts[0];
                npts[1] = pts[1];
                npts[2] = npoint;
                vngo_zgtriangle8 (vp, npts,color);
                npts[0] = npoint;
                npts[1] = pts[1];
                npts[2] = pts[2]; 
                vngo_zgtriangle8 (vp, npts,color);
                pdrawn = 1;
            }
        }

    }
    if (pdrawn)
        return;

    // fill in some pertinent info about the triangle.
    triangle_setup(pts,&tri);

    tri.x_dir = 0;
    VngoShadePal8   *tp = (VngoShadePal8 *)vp->vbuff.pal->shd_pal;
    VngoColorShade8 *tc = &(*tp)[tri.long_top->clr];
    tri.stable_ptr = &(tc->shl[0]);

    tri.hline_bptr = (byte *)((dword)vp->vbuff.scrn_ptr + vp->vbuff.ytable[(tri.long_top->y + 0x80000) >> 20]);
    tri.hline_zptr = (word *)((dword)vp->vbuff.zbuff_ptr + vp->vbuff.ztable[(tri.long_top->y + 0x80000) >> 20]);

    dy = ((tri.long_bottom->y + 0x80000) >> 20) - 
         ((tri.long_top->y + 0x80000) >> 20);
    if (dy)
    {
        tri.long_x_step = vngo_calc_xstep(tri.long_top->x,
                                          tri.long_bottom->x,dy);
        tri.long_z_step = vngo_calc_zstep(tri.long_top->z, 
                                          tri.long_bottom->z,dy);
        tri.long_s_step = vngo_calc_xstep(tri.long_top->shade, 
                                          tri.long_bottom->shade, dy);
    }

    else
    {
        // if the long edge is horizontal, then there is nothing to draw!
        int left=0;
        int right = 0;
        if (pts[1].x > pts[0].x)
        {
            if (pts[1].x > pts[2].x)
            {
                right = 1;
                if (pts[2].x < pts[0].x)
                    left = 2;
            }
            else
            {
                right = 2;
            }
        }
        else if (pts[2].x > pts[0].x)
        {
            left = 1;
            right = 2;
        }
        else if (pts[1].x > pts[2].x)
        {
            left = 2;
        }
        else
        {
            left =1;
        }
        int t = ((pts[right].x + 0x80000) >> 20) - 
                ((pts[left].x + 0x80000) >> 20);
        if (t)
        {
            tri.long_x = pts[left].x;
            tri.long_z = pts[left].z;
            tri.long_s = pts[left].shade;

            tri.short_x = pts[right].x;


            tri.z_step = vngo_calc_zstep(tri.long_z,pts[right].z,t);
            tri.shade_step = (tri.long_s - (pts[right].shade))/t;

            vngo_dzghline8(pts[0].y,&tri);
        }
        else
        {
            VngoPoint t;
            t.x = pts->x >> 20;
            t.y = pts->y >> 20;
            t.z = pts->z;
            t.clr = pts->clr;
            t.shade = pts->shade >> 20;
            vp->pixel(&t);
        }
        return;
    }

    dy = ((tri.short_bottom->y + 0x80000) >> 20) - 
         ((tri.short_top->y + 0x80000) >> 20); 
    if (dy)
    {
        tri.short_x_step = vngo_calc_xstep(tri.short_top->x,
                                           tri.short_bottom->x, dy);
    }

    if (tri.short_top != tri.long_top)
    {
        // if the top of the short and long are not the same then the
        // triangle has a flat top!
        stepped = 1;
    }


    long    y = tri.long_top->y >> 20;

    //
    // Setup all of the starting edge values to be interpolated.
    //

    tri.long_x = tri.long_top->x;
    tri.long_z = tri.long_top->z;
    tri.short_x = tri.short_top->x;
    tri.long_s = tri.long_top->shade;



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
        t3 = (tri.short_bottom->shade) - t3;


        t2 = tri.long_x_step * dy;
        t2 += tri.long_x;
        t2 = (t2 + 0x80000) >> 20;
        t2 = ((tri.short_bottom->x + 0x80000) >> 20) - t2;

        if (t2 < 0)
        {
            t2 = -t2;
            tri.x_dir = -1;
        }

        if (t2)
        {
            // calculate the 16.16 z_step for the horizontal lines.
            tri.z_step = t1 / t2;
            // calculate the 12.20 shade_step for the horizontal lines.
            tri.shade_step = t3 / t2;
        }
        else
        {
            tri.z_step = 0;
            tri.shade_step = 0;
        }
    }
    else
    {
        long    t1,t2,t3;
        t1 = tri.short_top->z - tri.long_z;
        t2 = (tri.short_top->shade) - tri.long_s;
        t3 = ((tri.short_x + 0x80000) >> 20) - 
             ((tri.long_x + 0x80000) >> 20);

        if (t3 < 0)
        {
            t3 = -t3;
            tri.x_dir = -1;
        }


        if (t3)
        {
            // calculate the 16.16 z_step for the horizontal lines.
            tri.z_step = t1 / t3;
            // calculate the 12.20 shade_step for the horizontal lines.
            tri.shade_step = t2 / t3;
        }
        else
        {
            tri.z_step = 0;
            tri.shade_step = 0;
        }
    }

    dy++;
    while (dy--)
    {
        vngo_dzghline8(y,&tri);
        y++;
        tri.long_x += tri.long_x_step;
        tri.short_x += tri.short_x_step;
        tri.long_z += tri.long_z_step;
        tri.long_s += tri.long_s_step;
        tri.hline_bptr += vp->vbuff.pitch;
        tri.hline_zptr = (word *)((dword)tri.hline_zptr + vp->vbuff.zpitch);
    }

    if(!stepped)
    {
        stepped = 1;
        dy = ((tri.long_bottom->y + 0x80000) >> 20) - 
             ((tri.short_bottom->y + 0x80000) >> 20);
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
        tri.short_x = tri.short_bottom->x;
        tri.short_x += tri.short_x_step;

        while (--dy)
        {
            vngo_dzghline8(y,&tri);
            y++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;
            tri.long_z += tri.long_z_step;
            tri.long_s += tri.long_s_step;
            tri.hline_bptr += vp->vbuff.pitch;
            tri.hline_zptr = (word *)((dword)tri.hline_zptr + vp->vbuff.zpitch);
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
