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
// vngtri.cpp
//
//     The C++ palette classes for the VanGogh Draw library.
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
//  This section of code contains all of the code for Flat shaded           ³
//  perspectively correct Texture mapped polygons.                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_dthline_persp(long y, VngoTriangle *tri, VngoVport *vp, VngoTexture *tex)
{
    VngoPoint   pt;
    long        x1,x2,step,t;
    long        width_shift;
    long        ustep,ustep2,vstep,vstep2;

    pt.u = tri->long_u << tri->u_upshift;
    ustep = tri->u_step1 << tri->u_upshift;
    ustep2 = tri->u_step2 << tri->u_upshift;

    pt.v = tri->long_v << tri->v_upshift; 
    vstep = tri->v_step1 << tri->v_upshift;
    vstep2 = tri->v_step2 << tri->v_upshift;

    width_shift = tri->widthshift;

    x1 = tri->long_x >> 20;
    x2 = tri->short_x >> 20;

    pt.x = x1;
    pt.y = y;
    pt.shade = tri->long_s >> 20;

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
        ut = (dword)pt.u >> (tri->u_downshift);
        vt = (dword)pt.v >> (tri->v_downshift);

        pt.clr = tex->tex[(vt << width_shift) + ut];

        if (pt.clr != VNGO_TRANSPARENT_COLOR)
        {
            vp->pixel(&pt);
        }
        pt.x += step;
        pt.u += ustep;
        pt.v += vstep;
        ustep +=ustep2;
        vstep +=vstep2;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_dzthline_persp(long y, VngoTriangle *tri, VngoVport *vp, VngoTexture *tex)
{
    VngoPoint   pt;
    long        x1,x2,step,t;
    long        width_shift;
    long        ustep,ustep2,vstep,vstep2;

    pt.u = tri->long_u << tri->u_upshift;
    ustep = tri->u_step1 << tri->u_upshift;
    ustep2 = tri->u_step2 << tri->u_upshift;

    pt.v = tri->long_v << tri->v_upshift; 
    vstep = tri->v_step1 << tri->v_upshift;
    vstep2 = tri->v_step2 << tri->v_upshift;

    width_shift = tri->widthshift;

    x1 = tri->long_x >> 20;
    x2 = tri->short_x >> 20;

    pt.x = x1;
    pt.y = y;
    pt.shade = tri->long_s >> 20;
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

    for (int i=0 ; i <= t; i++)
    {
        long    ut,vt;
        ut = (dword)pt.u >> (tri->u_downshift);
        vt = (dword)pt.v >> (tri->v_downshift);

        pt.clr = tex->tex[(vt << width_shift) + ut];

        if (pt.clr != VNGO_TRANSPARENT_COLOR)
        {
            vp->pixel(&pt);
        }
        pt.x += step;
        pt.z += tri->z_step;
        pt.u += ustep;
        pt.v += vstep;
        ustep +=ustep2;
        vstep +=vstep2;
    }
}




//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_ttriangle_persp (VngoVport *vp,VngoPoint *pts, VngoTexture *tex)
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
        tri.long_w_step = vngo_calc_wstep(tri.long_top->w,
                                          tri.long_bottom->w, dy);

        vngo_calc_quadratic(tri.long_top->w,
                            tri.long_bottom->w,
                            tri.long_top->u,
                            tri.long_bottom->u,
                            dy,
                            &tri.long_u_step1,
                            &tri.long_u_step2);

        vngo_calc_quadratic(tri.long_top->w,
                            tri.long_bottom->w,
                            tri.long_top->v,
                            tri.long_bottom->v,
                            dy,
                            &tri.long_v_step1,
                            &tri.long_v_step2);

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

        tri.short_w_step = vngo_calc_wstep(tri.short_top->w,
                                          tri.short_bottom->w, dy);

        vngo_calc_quadratic(tri.short_top->w,
                            tri.short_bottom->w,
                            tri.short_top->u,
                            tri.short_bottom->u,
                            dy,
                            &tri.short_u_step1,
                            &tri.short_u_step2);

        vngo_calc_quadratic(tri.short_top->w,
                            tri.short_bottom->w,
                            tri.short_top->v,
                            tri.short_bottom->v,
                            dy,
                            &tri.short_v_step1,
                            &tri.short_v_step2);

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
    tri.long_w = tri.long_top->w;
    tri.short_u = tri.short_top->u;
    tri.short_v = tri.short_top->v;
    tri.short_w = tri.short_top->w;



    long q=0;
    while (--dy)
    {
        long    t;
        t = (tri.short_x >> 20) - (tri.long_x >> 20);
        if (t < 0)
            t = -t;
        t++;

        if (((q & 0) == 0) || (t < 8))
        {
            vngo_calc_quadratic(tri.long_w,
                                tri.short_w,
                                tri.long_u,
                                tri.short_u,
                                t,
                                &tri.u_step1,
                                &tri.u_step2);

            vngo_calc_quadratic(tri.long_w,
                                tri.short_w,
                                tri.long_v,
                                tri.short_v,
                                t,
                                &tri.v_step1,
                                &tri.v_step2);
        }

        vngo_dthline_persp(y,&tri,vp,tex);
        y++;
        q++;
        tri.long_x += tri.long_x_step;
        tri.long_u += tri.long_u_step1;
        tri.long_u_step1 += tri.long_u_step2;
        tri.long_v += tri.long_v_step1;
        tri.long_v_step1 += tri.long_v_step2;
        tri.long_w += tri.long_w_step;

        tri.short_x += tri.short_x_step;
        tri.short_u += tri.short_u_step1;
        tri.short_u_step1 += tri.short_u_step2;
        tri.short_v += tri.short_v_step1;
        tri.short_v_step1 += tri.short_v_step2;
        tri.short_w += tri.short_w_step;

    }

    if(!stepped)
    {
        stepped = 1;
        dy = tri.long_bottom->y - tri.short_bottom->y + 1;
        if (dy)
        {
            tri.short_x_step = vngo_calc_xstep(tri.short_bottom->x,
                                               tri.long_bottom->x, dy);

            tri.short_w_step = vngo_calc_wstep(tri.short_bottom->w,
                                            tri.long_bottom->w, dy);

            vngo_calc_quadratic(tri.short_bottom->w,
                                tri.long_bottom->w,
                                tri.short_bottom->u,
                                tri.long_bottom->u,
                                dy,
                                &tri.short_u_step1,
                                &tri.short_u_step2);

            vngo_calc_quadratic(tri.short_bottom->w,
                                tri.long_bottom->w,
                                tri.short_bottom->v,
                                tri.long_bottom->v,
                                dy,
                                &tri.short_v_step1,
                                &tri.short_v_step2);

        }
        else
        {
            // if the second short leg is also zero, then the long leg should 
            // have already failed above.
            return;
        }
        tri.short_x = tri.short_bottom->x << 20;
        tri.short_u = tri.short_bottom->u;
        tri.short_v = tri.short_bottom->v;
        tri.short_w = tri.short_bottom->w;


        while (--dy)
        {
            long    t;
            t = (tri.short_x >> 20) - (tri.long_x >> 20);
            if (t < 0)
                t = -t;
            t++;

            if (((q & 0) == 0) || (t < 8))
            {
                vngo_calc_quadratic(tri.long_w,
                                    tri.short_w,
                                    tri.long_u,
                                    tri.short_u,
                                    t,
                                    &tri.u_step1,
                                    &tri.u_step2);

                vngo_calc_quadratic(tri.long_w,
                                    tri.short_w,
                                    tri.long_v,
                                    tri.short_v,
                                    t,
                                    &tri.v_step1,
                                    &tri.v_step2);
            }

            vngo_dthline_persp(y,&tri,vp,tex);
            y++;
            q++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;

            tri.long_u += tri.long_u_step1;
            tri.long_u_step1 += tri.long_u_step2;
            tri.long_v += tri.long_v_step1;
            tri.long_v_step1 += tri.long_v_step2;
            tri.long_w += tri.long_w_step;

            tri.short_u += tri.short_u_step1;
            tri.short_u_step1 += tri.short_u_step2;
            tri.short_v += tri.short_v_step1;
            tri.short_v_step1 += tri.short_v_step2;
            tri.short_w += tri.short_w_step;

        }
    }
    return;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_zttriangle_persp (VngoVport *vp,VngoPoint *pts, VngoTexture *tex)
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

        tri.long_w_step = vngo_calc_wstep(tri.long_top->w,
                                          tri.long_bottom->w, dy);

        vngo_calc_quadratic(tri.long_top->w,
                            tri.long_bottom->w,
                            tri.long_top->u,
                            tri.long_bottom->u,
                            dy,
                            &tri.long_u_step1,
                            &tri.long_u_step2);

        vngo_calc_quadratic(tri.long_top->w,
                            tri.long_bottom->w,
                            tri.long_top->v,
                            tri.long_bottom->v,
                            dy,
                            &tri.long_v_step1,
                            &tri.long_v_step2);

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

        tri.short_w_step = vngo_calc_wstep(tri.short_top->w,
                                          tri.short_bottom->w, dy);

        vngo_calc_quadratic(tri.short_top->w,
                            tri.short_bottom->w,
                            tri.short_top->u,
                            tri.short_bottom->u,
                            dy,
                            &tri.short_u_step1,
                            &tri.short_u_step2);

        vngo_calc_quadratic(tri.short_top->w,
                            tri.short_bottom->w,
                            tri.short_top->v,
                            tri.short_bottom->v,
                            dy,
                            &tri.short_v_step1,
                            &tri.short_v_step2);

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
    tri.long_w = tri.long_top->w;
    tri.short_u = tri.short_top->u;
    tri.short_v = tri.short_top->v;
    tri.short_w = tri.short_top->w;




    if (!stepped)
    {
        // calc the z step for the h-line.
        long    t1,t2;
        t2 = tri.long_z_step;
        t2 *= dy;
        // the amount z gets changed over dy.
        t2 += tri.long_z;
        // t2 now has Z at the long edge ofsett dy lines from start.
        t1 = tri.short_bottom->z - t2;
        // t1 should now have the delta Z for the hline.

        t2 = tri.long_x_step * dy;
        t2 += tri.long_x;
        t2 = (tri.short_bottom->x << 20) - t2;

        // t2 now has delta X for the hline.
        if (t2 < 0)
            t2 = -t2;

        t2 = t2 >> 20;
        t2++;

        // calculate the 16.16 z_step for the horizontal lines.
        tri.z_step = t1 / t2;

    }
    else
    {
        long    t1,t3;
        t1 = tri.short_top->z - tri.long_z;
        t3 = tri.short_x - tri.long_x;

        if (t3 < 0)
            t3 = -t3;

        t3 = t3 >> 20;
        t3++;

        // calculate the 16.16 z_step for the horizontal lines.
        tri.z_step = t1 / t3;
    }

    long q=0;
    while (--dy)
    {
        long    t;
        t = (tri.short_x >> 20) - (tri.long_x >> 20);
        if (t < 0)
            t = -t;
        t++;

        if (((q & 0) == 0) || (t < 8))
        {
            vngo_calc_quadratic(tri.long_w,
                                tri.short_w,
                                tri.long_u,
                                tri.short_u,
                                t,
                                &tri.u_step1,
                                &tri.u_step2);

            vngo_calc_quadratic(tri.long_w,
                                tri.short_w,
                                tri.long_v,
                                tri.short_v,
                                t,
                                &tri.v_step1,
                                &tri.v_step2);
        }

        vngo_dzthline_persp(y,&tri,vp,tex);
        y++;
        q++;
        tri.long_x += tri.long_x_step;
        tri.long_z += tri.long_z_step;
        tri.long_u += tri.long_u_step1;
        tri.long_u_step1 += tri.long_u_step2;
        tri.long_v += tri.long_v_step1;
        tri.long_v_step1 += tri.long_v_step2;
        tri.long_w += tri.long_w_step;

        tri.short_x += tri.short_x_step;
        tri.short_u += tri.short_u_step1;
        tri.short_u_step1 += tri.short_u_step2;
        tri.short_v += tri.short_v_step1;
        tri.short_v_step1 += tri.short_v_step2;
        tri.short_w += tri.short_w_step;

    }

    if(!stepped)
    {
        stepped = 1;
        dy = tri.long_bottom->y - tri.short_bottom->y + 1;
        if (dy)
        {
            tri.short_x_step = vngo_calc_xstep(tri.short_bottom->x,
                                               tri.long_bottom->x, dy);

            tri.short_w_step = vngo_calc_wstep(tri.short_bottom->w,
                                            tri.long_bottom->w, dy);

            vngo_calc_quadratic(tri.short_bottom->w,
                                tri.long_bottom->w,
                                tri.short_bottom->u,
                                tri.long_bottom->u,
                                dy,
                                &tri.short_u_step1,
                                &tri.short_u_step2);

            vngo_calc_quadratic(tri.short_bottom->w,
                                tri.long_bottom->w,
                                tri.short_bottom->v,
                                tri.long_bottom->v,
                                dy,
                                &tri.short_v_step1,
                                &tri.short_v_step2);

        }
        else
        {
            // if the second short leg is also zero, then the long leg should 
            // have already failed above.
            return;
        }
        tri.short_x = tri.short_bottom->x << 20;
        tri.short_u = tri.short_bottom->u;
        tri.short_v = tri.short_bottom->v;
        tri.short_w = tri.short_bottom->w;


        while (--dy)
        {
            long    t;
            t = (tri.short_x >> 20) - (tri.long_x >> 20);
            if (t < 0)
                t = -t;
            t++;

            if (((q & 0) == 0) || (t < 8))
            {
                vngo_calc_quadratic(tri.long_w,
                                    tri.short_w,
                                    tri.long_u,
                                    tri.short_u,
                                    t,
                                    &tri.u_step1,
                                    &tri.u_step2);

                vngo_calc_quadratic(tri.long_w,
                                    tri.short_w,
                                    tri.long_v,
                                    tri.short_v,
                                    t,
                                    &tri.v_step1,
                                    &tri.v_step2);
            }

            vngo_dzthline_persp(y,&tri,vp,tex);
            y++;
            q++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;
            tri.long_z += tri.long_z_step;

            tri.long_u += tri.long_u_step1;
            tri.long_u_step1 += tri.long_u_step2;
            tri.long_v += tri.long_v_step1;
            tri.long_v_step1 += tri.long_v_step2;
            tri.long_w += tri.long_w_step;

            tri.short_u += tri.short_u_step1;
            tri.short_u_step1 += tri.short_u_step2;
            tri.short_v += tri.short_v_step1;
            tri.short_v_step1 += tri.short_v_step2;
            tri.short_w += tri.short_w_step;

        }
    }
    return;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  vngo_tpoly_persp (VngoVbuffer *vb, int count, VngoPoint *pts,           ³
//              VngoTexture *tex);                                          ³
//      Draws an N sided convex polygon, by breaking it down into triangles ³
//      if it is not already a triangle.  This will also degenerate lines   ³
//      and pixels appropriately.  It draws with Gouraud shading.           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void vngo_tpoly_persp (VngoVport *vp,int count,VngoPoint *pts, VngoTexture *tex)
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
                    vngo_zttriangle_persp (vp,tpts,tex);
                else
                    vngo_ttriangle_persp (vp,tpts,tex);
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
            vngo_zttriangle_persp (vp,pts,tex);
        else
            vngo_ttriangle_persp (vp,pts,tex);
    }
}





//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  This section of code contains all of the code for Gouraud shaded        ³
//  perspectively correct Texture mapped polygons.                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_dtghline_persp(long y, VngoTriangle *tri, VngoVport *vp, VngoTexture *tex)
{
    VngoPoint   pt;
    long        shade;
    long        x1,x2,step,t,dither;
    long        width_shift=0;
    long        ustep,ustep2,vstep,vstep2;

    pt.u = tri->long_u << tri->u_upshift;
    ustep = tri->u_step1 << tri->u_upshift;
    ustep2 = tri->u_step2 << tri->u_upshift;

    pt.v = tri->long_v << tri->v_upshift; 
    vstep = tri->v_step1 << tri->v_upshift;
    vstep2 = tri->v_step2 << tri->v_upshift;

    width_shift = tri->widthshift;



    x1 = tri->long_x >> 20;
    x2 = tri->short_x >> 20;
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
        ut = (dword)pt.u >> (tri->u_downshift);
        vt = (dword)pt.v >> (tri->v_downshift);

        pt.clr = tex->tex[(vt << width_shift) + ut];

        if (pt.clr != VNGO_TRANSPARENT_COLOR)
        {
            pt.shade = (shade >> 20);
            if (pt.shade < 0)
            {
                pt.shade = 0;
            }
            else if (pt.shade > (255 - 8))
            {
                pt.shade = 255- 8;
            }

            pt.shade += dither;
            vp->pixel(&pt);
        }
        dither ^= 0x4;
        pt.x += step;
        shade += tri->shade_step;
        pt.u += ustep;
        pt.v += vstep;
        ustep +=ustep2;
        vstep +=vstep2;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_dztghline_persp(long y, VngoTriangle *tri, VngoVport *vp, VngoTexture *tex)
{
    VngoPoint   pt;
    long        shade;
    long        x1,x2,step,t,dither;
    long        width_shift=0;
    long        ustep,ustep2,vstep,vstep2;

    pt.u = tri->long_u << tri->u_upshift;
    ustep = tri->u_step1 << tri->u_upshift;
    ustep2 = tri->u_step2 << tri->u_upshift;

    pt.v = tri->long_v << tri->v_upshift; 
    vstep = tri->v_step1 << tri->v_upshift;
    vstep2 = tri->v_step2 << tri->v_upshift;

    width_shift = tri->widthshift;



    x1 = tri->long_x >> 20;
    x2 = tri->short_x >> 20;
    dither = ((x1 ^ y) & 0x1) << 2;

    pt.x = x1;
    pt.y = y;
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

    for (int i=0 ; i <= t; i++)
    {
        long    ut,vt;
        ut = (dword)pt.u >> (tri->u_downshift);
        vt = (dword)pt.v >> (tri->v_downshift);

        pt.clr = tex->tex[(vt << width_shift) + ut];

        if (pt.clr != VNGO_TRANSPARENT_COLOR)
        {
            pt.shade = (shade >> 20);
            if (pt.shade < 0)
            {
                pt.shade = 0;
            }
            else if (pt.shade > (255 - 8))
            {
                pt.shade = 255- 8;
            }

            pt.shade += dither;
            vp->pixel(&pt);
        }
        dither ^= 0x4;
        pt.x += step;
        pt.z += tri->z_step;
        shade += tri->shade_step;
        pt.u += ustep;
        pt.v += vstep;
        ustep +=ustep2;
        vstep +=vstep2;
    }
}




//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_tgtriangle_persp (VngoVport *vp,VngoPoint *pts, VngoTexture *tex)
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

        tri.long_w_step = vngo_calc_wstep(tri.long_top->w,
                                          tri.long_bottom->w, dy);

        vngo_calc_quadratic(tri.long_top->w,
                            tri.long_bottom->w,
                            tri.long_top->u,
                            tri.long_bottom->u,
                            dy,
                            &tri.long_u_step1,
                            &tri.long_u_step2);

        vngo_calc_quadratic(tri.long_top->w,
                            tri.long_bottom->w,
                            tri.long_top->v,
                            tri.long_bottom->v,
                            dy,
                            &tri.long_v_step1,
                            &tri.long_v_step2);

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

        tri.short_w_step = vngo_calc_wstep(tri.short_top->w,
                                          tri.short_bottom->w, dy);

        vngo_calc_quadratic(tri.short_top->w,
                            tri.short_bottom->w,
                            tri.short_top->u,
                            tri.short_bottom->u,
                            dy,
                            &tri.short_u_step1,
                            &tri.short_u_step2);

        vngo_calc_quadratic(tri.short_top->w,
                            tri.short_bottom->w,
                            tri.short_top->v,
                            tri.short_bottom->v,
                            dy,
                            &tri.short_v_step1,
                            &tri.short_v_step2);

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
    tri.long_w = tri.long_top->w;
    tri.short_u = tri.short_top->u;
    tri.short_v = tri.short_top->v;
    tri.short_w = tri.short_top->w;




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

    long q=0;
    while (--dy)
    {
        long    t;
        t = (tri.short_x >> 20) - (tri.long_x >> 20);
        if (t < 0)
            t = -t;
        t++;

        if (((q & 0) == 0) || (t < 8))
        {
            vngo_calc_quadratic(tri.long_w,
                                tri.short_w,
                                tri.long_u,
                                tri.short_u,
                                t,
                                &tri.u_step1,
                                &tri.u_step2);

            vngo_calc_quadratic(tri.long_w,
                                tri.short_w,
                                tri.long_v,
                                tri.short_v,
                                t,
                                &tri.v_step1,
                                &tri.v_step2);
        }

        vngo_dtghline_persp(y,&tri,vp,tex);
        y++;
        q++;
        tri.long_x += tri.long_x_step;
        tri.long_s += tri.long_s_step;
        tri.long_u += tri.long_u_step1;
        tri.long_u_step1 += tri.long_u_step2;
        tri.long_v += tri.long_v_step1;
        tri.long_v_step1 += tri.long_v_step2;
        tri.long_w += tri.long_w_step;

        tri.short_x += tri.short_x_step;
        tri.short_u += tri.short_u_step1;
        tri.short_u_step1 += tri.short_u_step2;
        tri.short_v += tri.short_v_step1;
        tri.short_v_step1 += tri.short_v_step2;
        tri.short_w += tri.short_w_step;

    }

    if(!stepped)
    {
        stepped = 1;
        dy = tri.long_bottom->y - tri.short_bottom->y + 1;
        if (dy)
        {
            tri.short_x_step = vngo_calc_xstep(tri.short_bottom->x,
                                               tri.long_bottom->x, dy);

            tri.short_w_step = vngo_calc_wstep(tri.short_bottom->w,
                                            tri.long_bottom->w, dy);

            vngo_calc_quadratic(tri.short_bottom->w,
                                tri.long_bottom->w,
                                tri.short_bottom->u,
                                tri.long_bottom->u,
                                dy,
                                &tri.short_u_step1,
                                &tri.short_u_step2);

            vngo_calc_quadratic(tri.short_bottom->w,
                                tri.long_bottom->w,
                                tri.short_bottom->v,
                                tri.long_bottom->v,
                                dy,
                                &tri.short_v_step1,
                                &tri.short_v_step2);

        }
        else
        {
            // if the second short leg is also zero, then the long leg should 
            // have already failed above.
            return;
        }
        tri.short_x = tri.short_bottom->x << 20;
        tri.short_u = tri.short_bottom->u;
        tri.short_v = tri.short_bottom->v;
        tri.short_w = tri.short_bottom->w;


        while (--dy)
        {
            long    t;
            t = (tri.short_x >> 20) - (tri.long_x >> 20);
            if (t < 0)
                t = -t;
            t++;

            if (((q & 0) == 0) || (t < 8))
            {
                vngo_calc_quadratic(tri.long_w,
                                    tri.short_w,
                                    tri.long_u,
                                    tri.short_u,
                                    t,
                                    &tri.u_step1,
                                    &tri.u_step2);

                vngo_calc_quadratic(tri.long_w,
                                    tri.short_w,
                                    tri.long_v,
                                    tri.short_v,
                                    t,
                                    &tri.v_step1,
                                    &tri.v_step2);
            }

            vngo_dtghline_persp(y,&tri,vp,tex);
            y++;
            q++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;
            tri.long_s += tri.long_s_step;

            tri.long_u += tri.long_u_step1;
            tri.long_u_step1 += tri.long_u_step2;
            tri.long_v += tri.long_v_step1;
            tri.long_v_step1 += tri.long_v_step2;
            tri.long_w += tri.long_w_step;

            tri.short_u += tri.short_u_step1;
            tri.short_u_step1 += tri.short_u_step2;
            tri.short_v += tri.short_v_step1;
            tri.short_v_step1 += tri.short_v_step2;
            tri.short_w += tri.short_w_step;

        }
    }
    return;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_ztgtriangle_persp (VngoVport *vp,VngoPoint *pts, VngoTexture *tex)
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

        tri.long_w_step = vngo_calc_wstep(tri.long_top->w,
                                          tri.long_bottom->w, dy);

        vngo_calc_quadratic(tri.long_top->w,
                            tri.long_bottom->w,
                            tri.long_top->u,
                            tri.long_bottom->u,
                            dy,
                            &tri.long_u_step1,
                            &tri.long_u_step2);

        vngo_calc_quadratic(tri.long_top->w,
                            tri.long_bottom->w,
                            tri.long_top->v,
                            tri.long_bottom->v,
                            dy,
                            &tri.long_v_step1,
                            &tri.long_v_step2);

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

        tri.short_w_step = vngo_calc_wstep(tri.short_top->w,
                                          tri.short_bottom->w, dy);

        vngo_calc_quadratic(tri.short_top->w,
                            tri.short_bottom->w,
                            tri.short_top->u,
                            tri.short_bottom->u,
                            dy,
                            &tri.short_u_step1,
                            &tri.short_u_step2);

        vngo_calc_quadratic(tri.short_top->w,
                            tri.short_bottom->w,
                            tri.short_top->v,
                            tri.short_bottom->v,
                            dy,
                            &tri.short_v_step1,
                            &tri.short_v_step2);

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
    tri.long_w = tri.long_top->w;
    tri.short_u = tri.short_top->u;
    tri.short_v = tri.short_top->v;
    tri.short_w = tri.short_top->w;




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

        t2 = tri.long_x_step * dy;
        t2 += tri.long_x;
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

    long q=0;
    while (--dy)
    {
        long    t;
        t = (tri.short_x >> 20) - (tri.long_x >> 20);
        if (t < 0)
            t = -t;
        t++;

        if (((q & 0) == 0) || (t < 8))
        {
            vngo_calc_quadratic(tri.long_w,
                                tri.short_w,
                                tri.long_u,
                                tri.short_u,
                                t,
                                &tri.u_step1,
                                &tri.u_step2);

            vngo_calc_quadratic(tri.long_w,
                                tri.short_w,
                                tri.long_v,
                                tri.short_v,
                                t,
                                &tri.v_step1,
                                &tri.v_step2);
        }

        vngo_dztghline_persp(y,&tri,vp,tex);
        y++;
        q++;
        tri.long_x += tri.long_x_step;
        tri.long_z += tri.long_z_step;
        tri.long_s += tri.long_s_step;
        tri.long_u += tri.long_u_step1;
        tri.long_u_step1 += tri.long_u_step2;
        tri.long_v += tri.long_v_step1;
        tri.long_v_step1 += tri.long_v_step2;
        tri.long_w += tri.long_w_step;

        tri.short_x += tri.short_x_step;
        tri.short_u += tri.short_u_step1;
        tri.short_u_step1 += tri.short_u_step2;
        tri.short_v += tri.short_v_step1;
        tri.short_v_step1 += tri.short_v_step2;
        tri.short_w += tri.short_w_step;

    }

    if(!stepped)
    {
        stepped = 1;
        dy = tri.long_bottom->y - tri.short_bottom->y + 1;
        if (dy)
        {
            tri.short_x_step = vngo_calc_xstep(tri.short_bottom->x,
                                               tri.long_bottom->x, dy);

            tri.short_w_step = vngo_calc_wstep(tri.short_bottom->w,
                                            tri.long_bottom->w, dy);

            vngo_calc_quadratic(tri.short_bottom->w,
                                tri.long_bottom->w,
                                tri.short_bottom->u,
                                tri.long_bottom->u,
                                dy,
                                &tri.short_u_step1,
                                &tri.short_u_step2);

            vngo_calc_quadratic(tri.short_bottom->w,
                                tri.long_bottom->w,
                                tri.short_bottom->v,
                                tri.long_bottom->v,
                                dy,
                                &tri.short_v_step1,
                                &tri.short_v_step2);

        }
        else
        {
            // if the second short leg is also zero, then the long leg should 
            // have already failed above.
            return;
        }
        tri.short_x = tri.short_bottom->x << 20;
        tri.short_u = tri.short_bottom->u;
        tri.short_v = tri.short_bottom->v;
        tri.short_w = tri.short_bottom->w;


        while (--dy)
        {
            long    t;
            t = (tri.short_x >> 20) - (tri.long_x >> 20);
            if (t < 0)
                t = -t;
            t++;

            if (((q & 0) == 0) || (t < 8))
            {
                vngo_calc_quadratic(tri.long_w,
                                    tri.short_w,
                                    tri.long_u,
                                    tri.short_u,
                                    t,
                                    &tri.u_step1,
                                    &tri.u_step2);

                vngo_calc_quadratic(tri.long_w,
                                    tri.short_w,
                                    tri.long_v,
                                    tri.short_v,
                                    t,
                                    &tri.v_step1,
                                    &tri.v_step2);
            }

            vngo_dztghline_persp(y,&tri,vp,tex);
            y++;
            q++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;
            tri.long_z += tri.long_z_step;
            tri.long_s += tri.long_s_step;

            tri.long_u += tri.long_u_step1;
            tri.long_u_step1 += tri.long_u_step2;
            tri.long_v += tri.long_v_step1;
            tri.long_v_step1 += tri.long_v_step2;
            tri.long_w += tri.long_w_step;

            tri.short_u += tri.short_u_step1;
            tri.short_u_step1 += tri.short_u_step2;
            tri.short_v += tri.short_v_step1;
            tri.short_v_step1 += tri.short_v_step2;
            tri.short_w += tri.short_w_step;

        }
    }
    return;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  vngo_tgpoly_persp (VngoVbuffer *vb, int count, VngoPoint *pts,          ³
//              VngoTexture *tex);                                          ³
//      Draws an N sided convex polygon, by breaking it down into triangles ³
//      if it is not already a triangle.  This will also degenerate lines   ³
//      and pixels appropriately.  It draws with Gouraud shading.           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void vngo_tgpoly_persp (VngoVport *vp,int count,VngoPoint *pts, VngoTexture *tex)
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
                    vngo_ztgtriangle_persp (vp,tpts,tex);
                else
                    vngo_tgtriangle_persp (vp,tpts,tex);
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
            vngo_ztgtriangle_persp (vp,pts,tex);
        else
            vngo_tgtriangle_persp (vp,pts,tex);
    }
}




//°±² End of module - vngtri.cpp ²±°
