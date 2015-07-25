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
// vngttri8.cpp
//
//     The 8bpp specific linear texture mapping routines for polygons in
//     the VanGogh Draw library.
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
//  This section of code contains all of the code for solid shaded          ³
//  Texture mapped polygons.                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  void vngo_dthline8(long y, VngoTriangle *tri,                           ³
//                    VngoVport *vp, VngoTexture *tex);                     ³
//                                                                          ³    
//      This routine draws a linear texture mapped horizontal line.         ³    
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_dthline8(long y, VngoTriangle *tri, VngoVport *vp, VngoTexture *tex)
{
    VngoPoint   pt;
    long        x1,x2,step,t;
    long        width_shift=0;
    long        ustep,vstep,ucur,vcur;

    ucur = tri->long_u << (tri->u_upshift);
    ustep = tri->u_step1 << (tri->u_upshift);

    vcur = tri->long_v << (tri->v_upshift);
    vstep = tri->v_step1 << (tri->v_upshift);

    width_shift = tri->widthshift;


    x1 = (tri->long_x + 0x80000) >> 20;
    x2 = (tri->short_x + 0x80000) >> 20;

    pt.x = x1;
    pt.y = y;
    pt.shade = tri->long_top->shade;

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
    
    for (int i=0 ; i <= t; i++)
    {
        long    ut,vt;
        ut = (dword)ucur >> (tri->u_downshift);
        vt = (dword)vcur >> (tri->v_downshift);

        
        pt.clr = tex->tex[(vt << width_shift) + ut];

        vp->pixel(&pt);
        pt.x += step;
        ucur += ustep;
        vcur += vstep;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  void vngo_dthline8(long y, VngoTriangle *tri,                           ³
//                    VngoVport *vp, VngoTexture *tex);                     ³
//      This routine draws a linear texture mapped horizontal line.         ³    
//      It draws with respect to the Z-Buffer.                              ³    
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_dzthline8(long y, VngoTriangle *tri, VngoVport *vp, VngoTexture *tex)
{
    VngoPoint   pt;
    long        x1,x2,step,t;
    long        width_shift=0;
    long        ustep,vstep,ucur,vcur;

    ucur = tri->long_u << (tri->u_upshift);
    ustep = tri->u_step1 << (tri->u_upshift);

    vcur = tri->long_v << (tri->v_upshift);
    vstep = tri->v_step1 << (tri->v_upshift);

    width_shift = tri->widthshift;


    x1 = tri->long_x >> 20;
    x2 = tri->short_x >> 20;

    pt.shade = tri->long_top->shade;
    pt.z = tri->long_z;

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
    VngoColorShade8 *tc;
    dword           poffset = vp->vbuff.ytable[y] + x1;
    dword           z = tri->long_z;
    long            ts = pt.shade >> 3;
    long            tcolor;
    for (int i=0;i <= t; i++)
    {
        if ((z >> 16) <= zptr[poffset])
        {
            long    ut,vt;
            ut = (dword)ucur >> (tri->u_downshift);
            vt = (dword)vcur >> (tri->v_downshift);
            tcolor = tex->tex[(vt << width_shift) + ut];
            if (tcolor != VNGO_TRANSPARENT_COLOR)
            {
                tc = &(*tp)[tcolor];

                sptr[poffset] = tc->shl[ts];
                zptr[poffset] = (word)(z >> 16);
            }
        }
        poffset += step;
        z += tri->z_step;
        ucur += ustep;
        vcur += vstep;
    }
}




//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_ttriangle8 (VngoVport *vp,VngoPoint *pts, VngoTexture *tex)
{
    VngoTriangle    tri;
    dword           stepped=0;
    long            dy;

    // fill in some pertinent info about the triangle.
    triangle_setup(pts,&tri);


    if (tex->width == 128)
    {
        tri.widthshift = 7;
        tri.u_upshift = 9;
    }
    else if (tex->width == 64)
    {
        tri.widthshift = 6;
        tri.u_upshift = 10;
    }
    else if (tex->width == 256)
    {
        tri.widthshift = 8;
        tri.u_upshift = 8;
    }
    else if (tex->width == 32)
    {
        tri.widthshift = 5;
        tri.u_upshift = 11;
    }
    else if (tex->width == 16)
    {
        tri.widthshift = 4;
        tri.u_upshift = 12;
    }
    tri.u_downshift = 32 - tri.widthshift;

    if (tex->height == 128)
    {
        tri.v_upshift = 9;
        tri.v_downshift = 25;
    }
    else if (tex->height == 64)
    {
        tri.v_upshift = 10;
        tri.v_downshift = 26;
    }
    else if (tex->height == 256)
    {
        tri.v_upshift = 8;
        tri.v_downshift = 24;
    }
    else if (tex->height == 32)
    {
        tri.v_upshift = 11;
        tri.v_downshift = 27;
    }
    else if (tex->height == 16)
    {
        tri.v_upshift = 12;
        tri.v_downshift = 28;
    }


    dy = tri.long_bottom->y - tri.long_top->y + 1;
    if (dy)
    {
        tri.long_x_step = vngo_calc_xstep(tri.long_top->x,
                                          tri.long_bottom->x,dy);
        tri.long_u_step1 = vngo_calc_uvstep(tri.long_top->u,
                                            tri.long_bottom->u, dy);
        tri.long_v_step1 = vngo_calc_uvstep(tri.long_top->v,
                                            tri.long_bottom->v, dy); 
 
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
    tri.long_u = tri.long_top->u;
    tri.long_v = tri.long_top->v;



    if (!stepped)
    {
        // calc the z step for the h-line.
        long    t2,ut,vt;

        ut = tri.long_u_step1;
        ut *= dy;
        ut += tri.long_u;
        ut = tri.short_bottom->u - ut;

        vt = tri.long_v_step1;
        vt *= dy;
        vt += tri.long_v;
        vt = tri.short_bottom->v - vt;


        t2 = tri.long_x_step * dy;
        t2 += tri.long_x;
        t2 = (tri.short_bottom->x << 20) - t2;

        // t2 now has delta X for the hline.
        if (t2 < 0)
            t2 = -t2;

        t2 = t2 >> 20;
        t2++;

        // calculate the 16.16 u/v steps for the horizontal lines.
        tri.u_step1 = ut / t2;
        tri.v_step1 = vt / t2;
    }
    else
    {
        long    t3,ut,vt;
        t3 = tri.short_x - tri.long_x;
        ut = tri.short_top->u - tri.long_u;
        vt = tri.short_top->v - tri.long_v;

        if (t3 < 0)
            t3 = -t3;

        t3 = t3 >> 20;
        t3++;

        // calculate the 16.16 u/v steps for the horizontal lines.
        tri.u_step1 = ut / t3;
        tri.v_step1 = vt / t3;

    }

    while (--dy)
    {
        vngo_dthline8(y,&tri,vp,tex);
        y++;
        tri.long_x += tri.long_x_step;
        tri.short_x += tri.short_x_step;
        tri.long_u += tri.long_u_step1;
        tri.long_v += tri.long_v_step1;
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
            vngo_dthline8(y,&tri,vp,tex);
            y++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;
            tri.long_u += tri.long_u_step1;
            tri.long_v += tri.long_v_step1;
        }
    }
    return;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_zttriangle8 (VngoVport *vp,VngoPoint *pts, VngoTexture *tex)
{
    VngoTriangle    tri;
    dword           stepped=0;
    long            dy;

    // fill in some pertinent info about the triangle.
    triangle_setup(pts,&tri);


    if (tex->width == 128)
    {
        tri.widthshift = 7;
        tri.u_upshift = 9;
    }
    else if (tex->width == 64)
    {
        tri.widthshift = 6;
        tri.u_upshift = 10;
    }
    else if (tex->width == 256)
    {
        tri.widthshift = 8;
        tri.u_upshift = 8;
    }
    else if (tex->width == 32)
    {
        tri.widthshift = 5;
        tri.u_upshift = 11;
    }
    else if (tex->width == 16)
    {
        tri.widthshift = 4;
        tri.u_upshift = 12;
    }
    tri.u_downshift = 32 - tri.widthshift;

    if (tex->height == 128)
    {
        tri.v_upshift = 9;
        tri.v_downshift = 25;
    }
    else if (tex->height == 64)
    {
        tri.v_upshift = 10;
        tri.v_downshift = 26;
    }
    else if (tex->height == 256)
    {
        tri.v_upshift = 8;
        tri.v_downshift = 24;
    }
    else if (tex->height == 32)
    {
        tri.v_upshift = 11;
        tri.v_downshift = 27;
    }
    else if (tex->height == 16)
    {
        tri.v_upshift = 12;
        tri.v_downshift = 28;
    }


    dy = tri.long_bottom->y - tri.long_top->y + 1;
    if (dy)
    {
        tri.long_x_step = vngo_calc_xstep(tri.long_top->x,
                                          tri.long_bottom->x,dy);
        tri.long_z_step = vngo_calc_zstep(tri.long_top->z, 
                                          tri.long_bottom->z,dy);
        tri.long_u_step1 = vngo_calc_uvstep(tri.long_top->u,
                                            tri.long_bottom->u, dy);
        tri.long_v_step1 = vngo_calc_uvstep(tri.long_top->v,
                                            tri.long_bottom->v, dy); 
 
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
    tri.long_u = tri.long_top->u;
    tri.long_v = tri.long_top->v;



    if (!stepped)
    {
        // calc the z step for the h-line.
        long    t1,t2,ut,vt;
        t2 = tri.long_z_step;
        t2 *= dy;
        // the amount z gets changed over dy.
        t2 += tri.long_z;
        // t2 now has Z at the long edge ofsett dy lines from start.
        t1 = tri.short_bottom->z - t2;
        // t1 should now have the delta Z for the hline.

        ut = tri.long_u_step1;
        ut *= dy;
        ut += tri.long_u;
        ut = tri.short_bottom->u - ut;

        vt = tri.long_v_step1;
        vt *= dy;
        vt += tri.long_v;
        vt = tri.short_bottom->v - vt;


        t2 = tri.long_x_step * dy;
        t2 += tri.long_x + 0x80000;
        t2 = (tri.short_bottom->x << 20) - t2;

        // t2 now has delta X for the hline.
        if (t2 < 0)
            t2 = -t2;

        t2 = t2 >> 20;
        t2++;

        // calculate the 16.16 z_step for the horizontal lines.
        tri.z_step = t1 / t2;

        // calculate the 16.16 u/v steps for the horizontal lines.
        tri.u_step1 = ut / t2;
        tri.v_step1 = vt / t2;
    }
    else
    {
        long    t1,t3,ut,vt;
        t1 = tri.short_top->z - tri.long_z;
        t3 = tri.short_x - tri.long_x;
        ut = tri.short_top->u - tri.long_u;
        vt = tri.short_top->v - tri.long_v;

        if (t3 < 0)
            t3 = -t3;

        t3 = t3 >> 20;
        t3++;

        // calculate the 16.16 z_step for the horizontal lines.
        tri.z_step = t1 / t3;

        // calculate the 16.16 u/v steps for the horizontal lines.
        tri.u_step1 = ut / t3;
        tri.v_step1 = vt / t3;

    }

    while (dy--)
    {
        vngo_dzthline8(y,&tri,vp,tex);
        y++;
        tri.long_x += tri.long_x_step;
        tri.short_x += tri.short_x_step;
        tri.long_z += tri.long_z_step;
        tri.long_u += tri.long_u_step1;
        tri.long_v += tri.long_v_step1;
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
            vngo_dzthline8(y,&tri,vp,tex);
            y++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;
            tri.long_z += tri.long_z_step;
            tri.long_u += tri.long_u_step1;
            tri.long_v += tri.long_v_step1;
        }
    }
    return;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  vngo_tpoly(VngoVbuffer *vb, int count, VngoPoint *pts,                  ³
//              VngoTexture *tex);                                          ³
//      Draws an N sided convex polygon, by breaking it down into triangles ³
//      if it is not already a triangle.  This will also degenerate lines   ³
//      and pixels appropriately.  It draws with flat shading.              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void vngo_tpoly8 (VngoVport *vp,int count,VngoPoint *pts, VngoTexture *tex)
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
                    vngo_zttriangle8 (vp,tpts,tex);
                else
                    vngo_ttriangle8 (vp,tpts,tex);
            }
        }
#if 0
        if (count == 1)
        {
            vp->pixel(pts);
        }
        else
        {
            vp->line(&pts[0],&pts[1]);
        }
#endif
    }
    else
    {
        if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            vngo_zttriangle8 (vp,pts,tex);
        else
            vngo_ttriangle8 (vp,pts,tex);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  This section of code contains all of the code for Gouraud shaded        ³
//  Texture mapped polygons.                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_dtghline8(long y, VngoTriangle *tri, VngoVport *vp, VngoTexture *tex)
{
    VngoPoint   pt;
    long        shade;
    long        x1,x2,step,t,dither;
    long        width_shift=0;
    long        ucur,vcur,ustep,vstep;

    ucur = tri->long_u << (tri->u_upshift);
    ustep = tri->u_step1 << (tri->u_upshift);

    vcur = tri->long_v << (tri->v_upshift);
    vstep = tri->v_step1 << (tri->v_upshift);

    width_shift = tri->widthshift;




    x1 = (tri->long_x + 0x80000) >> 20;
    x2 = (tri->short_x + 0x80000) >> 20;
    dither = ((x1 ^ y) & 0x1) << 2;

    pt.x = x1;
    pt.y = y;
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
    for (int i=0 ; i <= t; i++)
    {
        long    ut,vt;
        ut = (dword)ucur >> (tri->u_downshift);
        vt = (dword)vcur >> (tri->v_downshift);

        pt.clr = tex->tex[(vt << width_shift) + ut];

        pt.shade = (shade >> 20);

        if (pt.shade < 0)
            pt.shade = 0;
        else if (pt.shade > (255 - 8))
            pt.shade = 255 - 8;

        pt.shade += dither;
        vp->pixel(&pt);
        dither ^= 0x4;
        pt.x += step;
        shade += tri->shade_step;
        ucur += ustep;
        vcur += vstep;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_dztghline8(long y, VngoTriangle *tri, VngoVport *vp, VngoTexture *tex)
{
    VngoPoint   pt;
    long        shade;
    long        x1,x2,step,t,dither;
    long        width_shift=0;
    long        ucur,vcur,ustep,vstep;

    ucur = tri->long_u << (tri->u_upshift);
    ustep = tri->u_step1 << (tri->u_upshift);

    vcur = tri->long_v << (tri->v_upshift);
    vstep = tri->v_step1 << (tri->v_upshift);

    width_shift = tri->widthshift;




    x1 = (tri->long_x + 0x80000) >> 20;
    x2 = (tri->short_x + 0x80000) >> 20;

    dither = ((x1 ^ y) & 0x1) << 2;

    shade = tri->long_s;
    pt.z = tri->long_z;
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
    VngoColorShade8 *tc;
    dword           poffset = vp->vbuff.ytable[y] + x1;
    dword           z = tri->long_z;
    long            ts;
    long            tcolor;

    for (int i=0;i <= t; i++)
    {
        if ((z >> 16) <= zptr[poffset])
        {
            long    ut,vt;
            ut = (dword)ucur >> (tri->u_downshift);
            vt = (dword)vcur >> (tri->v_downshift);
            tcolor = tex->tex[(vt << width_shift) + ut];
            if (tcolor != VNGO_TRANSPARENT_COLOR)
            {
                tc = &(*tp)[tcolor];
                ts = (shade >> 20) + dither;
                if (ts < 0) 
                    ts = 0;
                else if (ts > 255)
                    ts = 255;

                sptr[poffset] = tc->shl[ts >> 3];
                zptr[poffset] = (word)(z >> 16);
            }
        }
        dither ^=0x4;
        poffset += step;
        z += tri->z_step;
        shade += tri->shade_step;
        ucur += ustep;
        vcur += vstep;
    }
}




//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_tgtriangle8 (VngoVport *vp,VngoPoint *pts, VngoTexture *tex)
{
    VngoTriangle    tri;
    dword           stepped=0;
    long            dy;

    // fill in some pertinent info about the triangle.
    triangle_setup(pts,&tri);


    if (tex->width == 128)
    {
        tri.widthshift = 7;
        tri.u_upshift = 9;
    }
    else if (tex->width == 64)
    {
        tri.widthshift = 6;
        tri.u_upshift = 10;
    }
    else if (tex->width == 256)
    {
        tri.widthshift = 8;
        tri.u_upshift = 8;
    }
    else if (tex->width == 32)
    {
        tri.widthshift = 5;
        tri.u_upshift = 11;
    }
    else if (tex->width == 16)
    {
        tri.widthshift = 4;
        tri.u_upshift = 12;
    }
    tri.u_downshift = 32 - tri.widthshift;

    if (tex->height == 128)
    {
        tri.v_upshift = 9;
        tri.v_downshift = 25;
    }
    else if (tex->height == 64)
    {
        tri.v_upshift = 10;
        tri.v_downshift = 26;
    }
    else if (tex->height == 256)
    {
        tri.v_upshift = 8;
        tri.v_downshift = 24;
    }
    else if (tex->height == 32)
    {
        tri.v_upshift = 11;
        tri.v_downshift = 27;
    }
    else if (tex->height == 16)
    {
        tri.v_upshift = 12;
        tri.v_downshift = 28;
    }


    dy = tri.long_bottom->y - tri.long_top->y + 1;
    if (dy)
    {
        tri.long_x_step = vngo_calc_xstep(tri.long_top->x,
                                          tri.long_bottom->x,dy);
        tri.long_s_step = vngo_calc_sstep(tri.long_top->shade, 
                                          tri.long_bottom->shade, dy);
        tri.long_u_step1 = vngo_calc_uvstep(tri.long_top->u,
                                            tri.long_bottom->u, dy);
        tri.long_v_step1 = vngo_calc_uvstep(tri.long_top->v,
                                            tri.long_bottom->v, dy); 
 
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
    tri.long_u = tri.long_top->u;
    tri.long_v = tri.long_top->v;



    if (!stepped)
    {
        // calc the z step for the h-line.
        long    t2,t3,ut,vt;

        t3 = tri.long_s_step;
        t3 *= dy;
        t3 += tri.long_s;
        t3 = (tri.short_bottom->shade << 20) - t3;

        ut = tri.long_u_step1;
        ut *= dy;
        ut += tri.long_u;
        ut = tri.short_bottom->u - ut;

        vt = tri.long_v_step1;
        vt *= dy;
        vt += tri.long_v;
        vt = tri.short_bottom->v - vt;


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

        // calculate the 16.16 u/v steps for the horizontal lines.
        tri.u_step1 = ut / t2;
        tri.v_step1 = vt / t2;
    }
    else
    {
        long    t2,t3,ut,vt;
        t2 = (tri.short_top->shade << 20) - tri.long_s;
        t3 = tri.short_x - tri.long_x;
        ut = tri.short_top->u - tri.long_u;
        vt = tri.short_top->v - tri.long_v;

        if (t3 < 0)
            t3 = -t3;

        t3 = t3 >> 20;
        t3++;

        // calculate the 12.20 shade_step for the horizontal lines.
        tri.shade_step = t2 / t3;

        // calculate the 16.16 u/v steps for the horizontal lines.
        tri.u_step1 = ut / t3;
        tri.v_step1 = vt / t3;

    }

    while (--dy)
    {
        vngo_dtghline8(y,&tri,vp,tex);
        y++;
        tri.long_x += tri.long_x_step;
        tri.short_x += tri.short_x_step;
        tri.long_s += tri.long_s_step;
        tri.long_u += tri.long_u_step1;
        tri.long_v += tri.long_v_step1;
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
            vngo_dtghline8(y,&tri,vp,tex);
            y++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;
            tri.long_s += tri.long_s_step;
            tri.long_u += tri.long_u_step1;
            tri.long_v += tri.long_v_step1;
        }
    }
    return;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_ztgtriangle8 (VngoVport *vp,VngoPoint *pts, VngoTexture *tex)
{
    VngoTriangle    tri;
    dword           stepped=0;
    long            dy;

    // fill in some pertinent info about the triangle.
    triangle_setup(pts,&tri);


    if (tex->width == 128)
    {
        tri.widthshift = 7;
        tri.u_upshift = 9;
    }
    else if (tex->width == 64)
    {
        tri.widthshift = 6;
        tri.u_upshift = 10;
    }
    else if (tex->width == 256)
    {
        tri.widthshift = 8;
        tri.u_upshift = 8;
    }
    else if (tex->width == 32)
    {
        tri.widthshift = 5;
        tri.u_upshift = 11;
    }
    else if (tex->width == 16)
    {
        tri.widthshift = 4;
        tri.u_upshift = 12;
    }
    tri.u_downshift = 32 - tri.widthshift;

    if (tex->height == 128)
    {
        tri.v_upshift = 9;
        tri.v_downshift = 25;
    }
    else if (tex->height == 64)
    {
        tri.v_upshift = 10;
        tri.v_downshift = 26;
    }
    else if (tex->height == 256)
    {
        tri.v_upshift = 8;
        tri.v_downshift = 24;
    }
    else if (tex->height == 32)
    {
        tri.v_upshift = 11;
        tri.v_downshift = 27;
    }
    else if (tex->height == 16)
    {
        tri.v_upshift = 12;
        tri.v_downshift = 28;
    }


    dy = tri.long_bottom->y - tri.long_top->y + 1;
    if (dy)
    {
        tri.long_x_step = vngo_calc_xstep(tri.long_top->x,
                                          tri.long_bottom->x,dy);
        tri.long_z_step = vngo_calc_zstep(tri.long_top->z, 
                                          tri.long_bottom->z,dy);
        tri.long_s_step = vngo_calc_sstep(tri.long_top->shade, 
                                          tri.long_bottom->shade, dy);
        tri.long_u_step1 = vngo_calc_uvstep(tri.long_top->u,
                                            tri.long_bottom->u, dy);
        tri.long_v_step1 = vngo_calc_uvstep(tri.long_top->v,
                                            tri.long_bottom->v, dy); 
 
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
    tri.long_u = tri.long_top->u;
    tri.long_v = tri.long_top->v;



    if (!stepped)
    {
        // calc the z step for the h-line.
        long    t1,t2,t3,ut,vt;
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

        ut = tri.long_u_step1;
        ut *= dy;
        ut += tri.long_u;
        ut = tri.short_bottom->u - ut;

        vt = tri.long_v_step1;
        vt *= dy;
        vt += tri.long_v;
        vt = tri.short_bottom->v - vt;


        t2 = tri.long_x_step * dy;
        t2 += tri.long_x + 0x80000;
        t2 = (tri.short_bottom->x << 20) - t2;

        // t2 now has delta X for the hline.
        if (t2 < 0)
            t2 = -t2;

        t2 = t2 >> 20;
        t2++;

        // calculate the 16.16 z_step for the horizontal lines.
        tri.z_step = t1 / t2;
        // calculate the 12.20 shade_step for the horizontal lines.
        tri.shade_step = t3 / t2;

        // calculate the 16.16 u/v steps for the horizontal lines.
        tri.u_step1 = ut / t2;
        tri.v_step1 = vt / t2;
    }
    else
    {
        long    t1,t2,t3,ut,vt;
        t1 = tri.short_top->z - tri.long_z;
        t2 = (tri.short_top->shade << 20) - tri.long_s;
        t3 = tri.short_x - tri.long_x;
        ut = tri.short_top->u - tri.long_u;
        vt = tri.short_top->v - tri.long_v;

        if (t3 < 0)
            t3 = -t3;

        t3 = t3 >> 20;
        t3++;

        // calculate the 16.16 z_step for the horizontal lines.
        tri.z_step = t1 / t3;
        // calculate the 12.20 shade_step for the horizontal lines.
        tri.shade_step = t2 / t3;

        // calculate the 16.16 u/v steps for the horizontal lines.
        tri.u_step1 = ut / t3;
        tri.v_step1 = vt / t3;

    }

    while (dy--)
    {
        vngo_dztghline8(y,&tri,vp,tex);
        y++;
        tri.long_x += tri.long_x_step;
        tri.short_x += tri.short_x_step;
        tri.long_z += tri.long_z_step;
        tri.long_s += tri.long_s_step;
        tri.long_u += tri.long_u_step1;
        tri.long_v += tri.long_v_step1;
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
            vngo_dztghline8(y,&tri,vp,tex);
            y++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;
            tri.long_z += tri.long_z_step;
            tri.long_s += tri.long_s_step;
            tri.long_u += tri.long_u_step1;
            tri.long_v += tri.long_v_step1;
        }
    }
    return;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  vngo_tgpoly(VngoVbuffer *vb, int count, VngoPoint *pts,                 ³
//              VngoTexture *tex);                                          ³
//      Draws an N sided convex polygon, by breaking it down into triangles ³
//      if it is not already a triangle.  This will also degenerate lines   ³
//      and pixels appropriately.  It draws with Gouraud shading.           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void vngo_tgpoly8 (VngoVport *vp,int count,VngoPoint *pts, VngoTexture *tex)
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
                    vngo_ztgtriangle8 (vp,tpts,tex);
                else
                    vngo_tgtriangle8 (vp,tpts,tex);
            }
        }
#if 0
        if (count == 1)
        {
            vp->pixel(pts);
        }
        else
        {
            vp->line(&pts[0],&pts[1]);
        }
#endif
    }
    else
    {
        if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            vngo_ztgtriangle8 (vp,pts,tex);
        else
            vngo_tgtriangle8 (vp,pts,tex);
    }
}







//°±² End of module - vngttri.cpp ²±°
