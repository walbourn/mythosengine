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

STATIC void vngo_dthline8(long y, VngoTriangle *tri, VngoVbuffer *vp, VngoTexture *tex)
{
    long        x1,x2,step,t;
    long        width_shift;
    long        ucur,vcur,ustep,vstep;

    ucur = tri->long_u << (tri->u_upshift);
    ustep = tri->u_step1 << (tri->u_upshift);

    vcur = tri->long_v << (tri->v_upshift);
    vstep = tri->v_step1 << (tri->v_upshift);

    width_shift = tri->widthshift;

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

    byte            *sptr = tri->hline_bptr + x1;
    long            tcolor;
    byte            *tptr = tex->tex;
    long            udown = tri->u_downshift;
    long            vdown = tri->v_downshift - width_shift;
    long            mask = ~((1 << width_shift) - 1);
    byte            *stble = tri->stable_ptr;

    for (int i=0;i <= t; i++)
    {
        tcolor = tptr[(((dword)vcur >> vdown) & mask) + ((dword)ucur >> udown)];
        if (tcolor != VNGO_TRANSPARENT_COLOR)
        {
            *sptr = stble[(tcolor << 5)];
        }
        sptr += step;
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

STATIC void vngo_dzthline8(long y, VngoTriangle *tri, VngoVbuffer *vp, VngoTexture *tex)
{
    long        x1,x2,step,t;
    long        width_shift=0;
    long        ucur,vcur,ustep,vstep;

    ucur = tri->long_u << (tri->u_upshift);
    ustep = tri->u_step1 << (tri->u_upshift);

    vcur = tri->long_v << (tri->v_upshift);
    vstep = tri->v_step1 << (tri->v_upshift);

    width_shift = tri->widthshift;

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

    byte            *sptr = tri->hline_bptr + x1;
    word            *zptr = tri->hline_zptr + x1;
    dword           z = tri->long_z;
    long            tcolor;
    long            udown = tri->u_downshift;
    long            vdown = tri->v_downshift - width_shift;
    long            mask = ~((1 << width_shift) - 1);
    long            zstep = tri->z_step;
    byte            *tptr = tex->tex;
    byte            *stble = tri->stable_ptr;
    word            tz;

    for (int i=0;i <= t; i++)
    {
        tz = (word) (z >> 16);
        if (tz < *zptr)
        {
            tcolor = tptr[(((dword)vcur >> vdown) & mask) + ((dword)ucur >> udown)];
            if (tcolor != VNGO_TRANSPARENT_COLOR)
            {
                *zptr = tz;
                *sptr = stble[(tcolor << 5)];
            }
        }
        sptr += step;
        zptr += step;
        ucur += ustep;
        vcur += vstep;
        z += zstep;
    }
}




//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

void vngo_ttriangle8 (VngoVport *vp,VngoPoint *pts, VngoTextureInfo *ttex)
{
    VngoTriangle    tri;
    dword           stepped=0;
    long            dy;
    VngoTexture     *tex = ttex->vtxt;
    long            pdrawn = 0;

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
                vngo_ttriangle8 (vp, npts, ttex);
                npts[0] = npoint;
                npts[1] = pts[1]; 
                vngo_ttriangle8 (vp, npts, ttex);
                pdrawn = 1;
            }
            else if (edge_num == 1)
            {
                vngo_midpt(&pts[1],&pts[2],&npoint);
                npts[0] = pts[0];
                npts[1] = pts[1];
                npts[2] = npoint;
                vngo_ttriangle8 (vp, npts, ttex);
                npts[1] = npoint;
                npts[2] = pts[2]; 
                vngo_ttriangle8 (vp, npts, ttex);
                pdrawn = 1;
            }
            else
            {
                vngo_midpt(&pts[2],&pts[0],&npoint);
                npts[0] = pts[0];
                npts[1] = pts[1];
                npts[2] = npoint;
                vngo_ttriangle8 (vp, npts, ttex);
                npts[0] = npoint;
                npts[2] = pts[2]; 
                vngo_ttriangle8 (vp, npts, ttex);
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
    VngoColorShade8 *tc = &(*tp)[0];
    tri.stable_ptr = &(tc->shl[tri.long_top->shade >> 3]);

    tri.hline_bptr = (byte *)((dword)vp->vbuff.scrn_ptr + vp->vbuff.ytable[(tri.long_top->y + 0x80000) >> 20]);

    tri.widthshift = ttex->widthshift;
    tri.u_upshift = ttex->u_upshift;
    tri.v_upshift = ttex->v_upshift;
    tri.u_downshift = ttex->u_downshift;
    tri.v_downshift = ttex->v_downshift;


    dy = ((tri.long_bottom->y + 0x80000) >> 20) - 
         ((tri.long_top->y + 0x80000) >> 20);
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
            tri.long_u = pts[left].u;
            tri.long_v = pts[left].v;

            tri.short_x = pts[right].x;


            tri.u_step1 = vngo_calc_uvstep(tri.long_u,pts[right].u,t);
            tri.v_step1 = vngo_calc_uvstep(tri.long_v,pts[right].v,t);


            vngo_dthline8(pts[0].y,&tri,&vp->vbuff,tex);
        }
        else
        {
            VngoPoint t;
            t.x = pts->x >> 20;
            t.y = pts->y >> 20;
            t.z = pts->z;
            t.clr = pts->clr;
            t.shade = pts->shade;
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


    long   y = tri.long_top->y >> 20;

    //
    // Setup all of the starting edge values to be interpolated.
    //

    tri.long_x = tri.long_top->x;
    tri.short_x = tri.short_top->x;
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
        t2 += tri.long_x + 0x80000;
        t2 = t2 >> 20;
        t2 = ((tri.short_bottom->x + 0x80000) >> 20) - t2;

        // t2 now has delta X for the hline.
        if (t2 < 0)
        {
            t2 = -t2;
            tri.x_dir = -1;
        }


        if (t2)
        {
            // calculate the 16.16 u/v steps for the horizontal lines.
            tri.u_step1 = ut / t2;
            tri.v_step1 = vt / t2;
        }
        else
        {
            tri.u_step1 = 0;
            tri.v_step1 = 0;
        }
    }
    else
    {
        long    t3,ut,vt;
        t3 = ((tri.short_x + 0x80000) >> 20) - 
             ((tri.long_x + 0x80000) >> 20);
        ut = tri.short_top->u - tri.long_u;
        vt = tri.short_top->v - tri.long_v;

        if (t3 < 0)
        {
            t3 = -t3;
            tri.x_dir = -1;
        }

        if (t3)
        {
            // calculate the 16.16 u/v steps for the horizontal lines.
            tri.u_step1 = ut / t3;
            tri.v_step1 = vt / t3;
        }
        else
        {
            tri.u_step1 = 0;
            tri.v_step1 = 0;
        }
    }

    dy++;
    while (dy--)
    {
        vngo_dthline8(y,&tri,&vp->vbuff,tex);
        y++;
        tri.long_x += tri.long_x_step;
        tri.short_x += tri.short_x_step;
        tri.long_u += tri.long_u_step1;
        tri.long_v += tri.long_v_step1;
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
            vngo_dthline8(y,&tri,&vp->vbuff,tex);
            y++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;
            tri.long_u += tri.long_u_step1;
            tri.long_v += tri.long_v_step1;
            tri.hline_bptr += vp->vbuff.pitch;
        }
    }
    return;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

void vngo_zttriangle8 (VngoVport *vp,VngoPoint *pts, VngoTextureInfo *ttex)
{
    VngoTriangle    tri;
    dword           stepped=0;
    long            dy;
    VngoTexture     *tex = ttex->vtxt;
    long            pdrawn = 0;

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
                vngo_zttriangle8 (vp, npts, ttex);
                npts[0] = npoint;
                npts[1] = pts[1]; 
                vngo_zttriangle8 (vp, npts, ttex);
                pdrawn = 1;
            }
            else if (edge_num == 1)
            {
                vngo_midpt(&pts[1],&pts[2],&npoint);
                npts[0] = pts[0];
                npts[1] = pts[1];
                npts[2] = npoint;
                vngo_zttriangle8 (vp, npts, ttex);
                npts[1] = npoint;
                npts[2] = pts[2]; 
                vngo_zttriangle8 (vp, npts, ttex);
                pdrawn = 1;
            }
            else
            {
                vngo_midpt(&pts[2],&pts[0],&npoint);
                npts[0] = pts[0];
                npts[1] = pts[1];
                npts[2] = npoint;
                vngo_zttriangle8 (vp, npts, ttex);
                npts[0] = npoint;
                npts[2] = pts[2]; 
                vngo_zttriangle8 (vp, npts, ttex);
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
    VngoColorShade8 *tc = &(*tp)[0];
    tri.stable_ptr = &(tc->shl[tri.long_top->shade >> 3]);

    tri.hline_bptr = (byte *)((dword)vp->vbuff.scrn_ptr + vp->vbuff.ytable[(tri.long_top->y + 0x80000) >> 20]);
    tri.hline_zptr = (word *)((dword)vp->vbuff.zbuff_ptr + vp->vbuff.ztable[(tri.long_top->y + 0x80000) >> 20]);

    tri.widthshift = ttex->widthshift;
    tri.u_upshift = ttex->u_upshift;
    tri.u_downshift = ttex->u_downshift;
    tri.v_upshift = ttex->v_upshift;
    tri.v_downshift = ttex->v_downshift;


    dy = ((tri.long_bottom->y + 0x80000) >> 20) - 
         ((tri.long_top->y + 0x80000) >> 20);
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
            tri.long_u = pts[left].u;
            tri.long_v = pts[left].v;

            tri.short_x = pts[right].x;


            tri.z_step = vngo_calc_zstep(tri.long_z,pts[right].z,t);
            tri.u_step1 = vngo_calc_uvstep(tri.long_u,pts[right].u,t);
            tri.v_step1 = vngo_calc_uvstep(tri.long_v,pts[right].v,t);


            vngo_dzthline8(pts[0].y,&tri,&vp->vbuff,tex);
        }
        else
        {
            VngoPoint t;
            t.x = pts->x >> 20;
            t.y = pts->y >> 20;
            t.z = pts->z;
            t.clr = pts->clr;
            t.shade = pts->shade;
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
        t2 = t2 >> 20;
        t2 = ((tri.short_bottom->x + 0x80000) >> 20) - t2;

        // t2 now has delta X for the hline.
        if (t2 < 0)
        {
            t2 = -t2;
            tri.x_dir = -1;
        }

        if (t2)
        {
            // calculate the 16.16 z_step for the horizontal lines.
            tri.z_step = t1 / t2;

            // calculate the 16.16 u/v steps for the horizontal lines.
            tri.u_step1 = ut / t2;
            tri.v_step1 = vt / t2;
        }
        else
        {
            tri.z_step = 0;
            tri.u_step1 = 0;
            tri.v_step1 = 0;
        }
    }
    else
    {
        long    t1,t3,ut,vt;
        t1 = tri.short_top->z - tri.long_z;
        t3 = ((tri.short_x + 0x80000) >> 20) - 
             ((tri.long_x + 0x80000) >> 20);
        ut = tri.short_top->u - tri.long_u;
        vt = tri.short_top->v - tri.long_v;

        if (t3 < 0)
        {
            t3 = -t3;
            tri.x_dir = -1;
        }

        if (t3)
        {
            // calculate the 16.16 z_step for the horizontal lines.
            tri.z_step = t1 / t3;

            // calculate the 16.16 u/v steps for the horizontal lines.
            tri.u_step1 = ut / t3;
            tri.v_step1 = vt / t3;
        }
        else
        {
            tri.z_step = 0;
            tri.u_step1 = 0;
            tri.v_step1 = 0;
        }
    }

    dy++;
    while (dy--)
    {
        vngo_dzthline8(y,&tri,&vp->vbuff,tex);
        y++;
        tri.long_x += tri.long_x_step;
        tri.short_x += tri.short_x_step;
        tri.long_z += tri.long_z_step;
        tri.long_u += tri.long_u_step1;
        tri.long_v += tri.long_v_step1;
        tri.hline_bptr += vp->vbuff.pitch;
        tri.hline_zptr = (word *)((dword) tri.hline_zptr + vp->vbuff.zpitch);
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
            vngo_dzthline8(y,&tri,&vp->vbuff,tex);
            y++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;
            tri.long_z += tri.long_z_step;
            tri.long_u += tri.long_u_step1;
            tri.long_v += tri.long_v_step1;
            tri.hline_bptr += vp->vbuff.pitch;
            tri.hline_zptr = (word *)((dword) tri.hline_zptr + vp->vbuff.zpitch);
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
void vngo_tpoly8 (VngoVport *vp,int count,VngoPoint *pts, VngoTextureInfo *tex)
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
        if (count == 1)
        {
            VngoPoint t;
            t.x = pts->x >> 20;
            t.y = pts->y >> 20;
            t.z = pts->z;
            t.clr = pts->clr;
            t.shade = pts->shade;
            vp->pixel(&t);
        }
#if 0
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

STATIC void vngo_dtghline8(long y, VngoTriangle *tri, VngoVbuffer *vp, VngoTexture *tex)
{
    long        shade;
    long        x1,x2,step,t,dither;
    long        width_shift=0;
    long        ucur,vcur,ustep,vstep;


    ucur = tri->long_u << (tri->u_upshift);
    ustep = tri->u_step1 << (tri->u_upshift);

    vcur = tri->long_v << (tri->v_upshift);
    vstep = tri->v_step1 << (tri->v_upshift);

    width_shift = tri->widthshift;

    shade = tri->long_s;

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

    byte            *sptr = tri->hline_bptr + x1;
    long            ts;
    long            tcolor;
    long            udown = tri->u_downshift;
    long            vdown = tri->v_downshift - width_shift;
    long            mask = ~((1 << width_shift) - 1);
    byte            *tptr = tex->tex;
    byte            *stble = tri->stable_ptr;
    long            sstep = tri->shade_step;

    for (int i=0;i <= t; i++)
    {
        tcolor = tptr[(((dword)vcur >> vdown) & mask) + ((dword)ucur >> udown)];
        if (tcolor != VNGO_TRANSPARENT_COLOR)
        {
            ts = (shade + dither) >> 23;
            if (ts < 0) 
                ts = 0;
            else if (ts > 32)
                ts = 32;

            *sptr = stble[(tcolor << 5) + ts];
        }
        dither ^=0x400000;
        sptr += step;
        shade += sstep;
        ucur += ustep;
        vcur += vstep;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

STATIC void vngo_dztghline8(long y, VngoTriangle *tri, VngoVbuffer *vp, VngoTexture *tex)
{
    long        shade;
    long        x1,x2,step,t,dither;
    long        width_shift=0;
    long        ucur,vcur,ustep,vstep;

    ucur = tri->long_u << (tri->u_upshift);
    ustep = tri->u_step1 << (tri->u_upshift);

    vcur = tri->long_v << (tri->v_upshift);
    vstep = tri->v_step1 << (tri->v_upshift);

    width_shift = tri->widthshift;

    shade = tri->long_s;

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

    byte            *sptr = tri->hline_bptr + x1;
    word            *zptr = tri->hline_zptr + x1;
    dword           z = tri->long_z;
    long            ts;
    long            tcolor;
    long			zstep = tri->z_step;
    long			sstep = tri->shade_step;
    long			udown = tri->u_downshift;
    long			vdown = tri->v_downshift - width_shift;
    long            mask = ~((1 << width_shift) - 1);
    byte            *tptr = tex->tex;
    byte            *stble = tri->stable_ptr;
    word            tz;

    for (int i=0;i <= t; i++)
    {                   
        tz = (word)(z >> 16);
        if (tz < *zptr)
        {
            tcolor = tptr[(((dword)vcur >> vdown) & mask) + ((dword)ucur >> udown)];
            if (tcolor != VNGO_TRANSPARENT_COLOR)
            {
                *zptr = tz;
                ts = (shade + dither) >> 23;
                if (ts < 0) 
                    ts = 0;
                else if (ts > 32)
                    ts = 32;

                *sptr = stble[(tcolor << 5) + ts];
            }
        }
        dither ^=( 1 << 22); // 0x400000;
        sptr += step;
        zptr += step;
        shade += sstep;
        ucur += ustep;
        vcur += vstep;
        z += zstep;
    }
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

void vngo_tgtriangle8 (VngoVport *vp,VngoPoint *pts, VngoTextureInfo *ttex)
{
    VngoTriangle    tri;
    dword           stepped=0;
    long            dy;
    VngoTexture     *tex = ttex->vtxt;
    long            pdrawn = 0;

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
                vngo_tgtriangle8 (vp, npts, ttex);
                npts[0] = npoint;
                npts[1] = pts[1]; 
                vngo_tgtriangle8 (vp, npts, ttex);
                pdrawn = 1;
            }
            else if (edge_num == 1)
            {
                vngo_midpt(&pts[1],&pts[2],&npoint);
                npts[0] = pts[0];
                npts[1] = pts[1];
                npts[2] = npoint;
                vngo_tgtriangle8 (vp, npts, ttex);
                npts[1] = npoint;
                npts[2] = pts[2]; 
                vngo_tgtriangle8 (vp, npts, ttex);
                pdrawn = 1;
            }
            else
            {
                vngo_midpt(&pts[2],&pts[0],&npoint);
                npts[0] = pts[0];
                npts[1] = pts[1];
                npts[2] = npoint;
                vngo_tgtriangle8 (vp, npts, ttex);
                npts[0] = npoint;
                npts[2] = pts[2]; 
                vngo_tgtriangle8 (vp, npts, ttex);
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
    VngoColorShade8 *tc = &(*tp)[0];
    tri.stable_ptr = &(tc->shl[0]);

    tri.hline_bptr = (byte *)((dword)vp->vbuff.scrn_ptr + vp->vbuff.ytable[(tri.long_top->y + 0x80000) >> 20]);

    tri.widthshift = ttex->widthshift;
    tri.u_upshift = ttex->u_upshift;
    tri.u_downshift = ttex->u_downshift;
    tri.v_upshift = ttex->v_upshift;
    tri.v_downshift = ttex->v_downshift;


    dy = ((tri.long_bottom->y + 0x80000) >> 20) - 
         ((tri.long_top->y + 0x80000) >> 20);
    if (dy)
    {
        tri.long_x_step = vngo_calc_xstep(tri.long_top->x,
                                          tri.long_bottom->x,dy);
        tri.long_s_step = vngo_calc_xstep(tri.long_top->shade, 
                                          tri.long_bottom->shade, dy);
        tri.long_u_step1 = vngo_calc_uvstep(tri.long_top->u,
                                            tri.long_bottom->u, dy);
        tri.long_v_step1 = vngo_calc_uvstep(tri.long_top->v,
                                            tri.long_bottom->v, dy); 

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
            tri.long_s = pts[left].shade;
            tri.long_u = pts[left].u;
            tri.long_v = pts[left].v;

            tri.short_x = pts[right].x;


            tri.u_step1 = vngo_calc_uvstep(tri.long_u,pts[right].u,t);
            tri.v_step1 = vngo_calc_uvstep(tri.long_v,pts[right].v,t);

            tri.shade_step = (tri.long_s - (pts[right].shade))/t;

            vngo_dztghline8(pts[0].y,&tri,&vp->vbuff,tex);
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
    tri.short_x = tri.short_top->x;
    tri.long_s = tri.long_top->shade;
    tri.long_u = tri.long_top->u;
    tri.long_v = tri.long_top->v;



    if (!stepped)
    {
        // calc the z step for the h-line.
        long    t2,t3,ut,vt;

        t3 = tri.long_s_step;
        t3 *= dy;
        t3 += tri.long_s;
        t3 = (tri.short_bottom->shade) - t3;

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
        t2 = t2 >> 20;
        t2 = ((tri.short_bottom->x + 0x80000) >> 20) - t2;

        // t2 now has delta X for the hline.
        if (t2 < 0)
        {
            t2 = -t2;
            tri.x_dir = -1;
        }

        if (t2)
        {
            // calculate the 12.20 shade_step for the horizontal lines.
            tri.shade_step = t3 / t2;

            // calculate the 16.16 u/v steps for the horizontal lines.
            tri.u_step1 = ut / t2;
            tri.v_step1 = vt / t2;
        }
        else
        {
            tri.shade_step = 0;
            tri.u_step1 = 0;
            tri.v_step1 = 0;
        }
    }
    else
    {
        long    t2,t3,ut,vt;
        t2 = (tri.short_top->shade) - tri.long_s;
        t3 = ((tri.short_x + 0x80000) >> 20) - 
             ((tri.long_x + 0x80000) >> 20);
        ut = tri.short_top->u - tri.long_u;
        vt = tri.short_top->v - tri.long_v;

        if (t3 < 0)
        {
            t3 = -t3;
            tri.x_dir = -1;
        }

        if (t3)
        {
            // calculate the 12.20 shade_step for the horizontal lines.
            tri.shade_step = t2 / t3;

            // calculate the 16.16 u/v steps for the horizontal lines.
            tri.u_step1 = ut / t3;
            tri.v_step1 = vt / t3;
        }
        else
        {
            tri.shade_step = 0;
            tri.u_step1 = 0;
            tri.v_step1 = 0;
        }
    }

    dy++;
    while (dy--)
    {
        vngo_dtghline8(y,&tri,&vp->vbuff,tex);
        y++;
        tri.long_x += tri.long_x_step;
        tri.short_x += tri.short_x_step;
        tri.long_s += tri.long_s_step;
        tri.long_u += tri.long_u_step1;
        tri.long_v += tri.long_v_step1;
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
            vngo_dtghline8(y,&tri,&vp->vbuff,tex);
            y++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;
            tri.long_s += tri.long_s_step;
            tri.long_u += tri.long_u_step1;
            tri.long_v += tri.long_v_step1;
            tri.hline_bptr += vp->vbuff.pitch;
        }
    }
    return;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

void vngo_ztgtriangle8 (VngoVport *vp,VngoPoint *pts, VngoTextureInfo *ttex)
{
    VngoTriangle    tri;
    dword           stepped=0;
    long            dy;

    long            pdrawn = 0;
    VngoTexture     *tex = ttex->vtxt;

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
                vngo_ztgtriangle8 (vp, npts, ttex);
                npts[0] = npoint;
                npts[1] = pts[1]; 
                vngo_ztgtriangle8 (vp, npts, ttex);
                pdrawn = 1;
            }
            else if (edge_num == 1)
            {
                vngo_midpt(&pts[1],&pts[2],&npoint);
                npts[0] = pts[0];
                npts[1] = pts[1];
                npts[2] = npoint;
                vngo_ztgtriangle8 (vp, npts, ttex);
                npts[1] = npoint;
                npts[2] = pts[2]; 
                vngo_ztgtriangle8 (vp, npts, ttex);
                pdrawn = 1;
            }
            else
            {
                vngo_midpt(&pts[2],&pts[0],&npoint);
                npts[0] = pts[0];
                npts[1] = pts[1];
                npts[2] = npoint;
                vngo_ztgtriangle8 (vp, npts, ttex);
                npts[0] = npoint;
                npts[2] = pts[2]; 
                vngo_ztgtriangle8 (vp, npts, ttex);
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
    VngoColorShade8 *tc = &(*tp)[0];
    tri.stable_ptr = &(tc->shl[0]);

    tri.hline_bptr = (byte *)((dword)vp->vbuff.scrn_ptr + vp->vbuff.ytable[(tri.long_top->y + 0x80000) >> 20]);
    tri.hline_zptr = (word *)((dword)vp->vbuff.zbuff_ptr + vp->vbuff.ztable[(tri.long_top->y + 0x80000) >> 20]);

    tri.widthshift = ttex->widthshift;
    tri.u_upshift = ttex->u_upshift;
    tri.v_upshift = ttex->v_upshift;
    tri.u_downshift = ttex->u_downshift;
    tri.v_downshift = ttex->v_downshift;


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
        tri.long_u_step1 = vngo_calc_uvstep(tri.long_top->u,
                                            tri.long_bottom->u, dy);
        tri.long_v_step1 = vngo_calc_uvstep(tri.long_top->v,
                                            tri.long_bottom->v, dy); 

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
            tri.long_u = pts[left].u;
            tri.long_v = pts[left].v;

            tri.short_x = pts[right].x;


            tri.z_step = vngo_calc_zstep(tri.long_z,pts[right].z,t);
            tri.u_step1 = vngo_calc_uvstep(tri.long_u,pts[right].u,t);
            tri.v_step1 = vngo_calc_uvstep(tri.long_v,pts[right].v,t);

            tri.shade_step = (tri.long_s - (pts[right].shade))/t;

            vngo_dztghline8(pts[0].y,&tri,&vp->vbuff,tex);
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
        t3 = (tri.short_bottom->shade) - t3;

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
        t2 = t2 >> 20;
        t2 = ((tri.short_bottom->x + 0x80000) >> 20) - t2;

        // t2 now has delta X for the hline.
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

            // calculate the 16.16 u/v steps for the horizontal lines.
            tri.u_step1 = ut / t2;
            tri.v_step1 = vt / t2;
        }
        else
        {
            tri.z_step = 0;
            tri.shade_step = 0;
            tri.u_step1 = 0;
            tri.v_step1 = 0;
        }
    }
    else
    {
        long    t1,t2,t3,ut,vt;
        t1 = tri.short_top->z - tri.long_z;
        t2 = (tri.short_top->shade) - tri.long_s;
        t3 = ((tri.short_x + 0x80000) >> 20) - 
             ((tri.long_x + 0x80000) >> 20);
        ut = tri.short_top->u - tri.long_u;
        vt = tri.short_top->v - tri.long_v;

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

            // calculate the 16.16 u/v steps for the horizontal lines.
            tri.u_step1 = ut / t3;
            tri.v_step1 = vt / t3;
        }
        else
        {
            tri.z_step = 0;
            tri.shade_step = 0;
            tri.u_step1 = 0;
            tri.v_step1 = 0;
        }
    }

    dy++;
    while (dy--)
    {
        vngo_dztghline8(y,&tri,&vp->vbuff,tex);
        y++;
        tri.long_x += tri.long_x_step;
        tri.short_x += tri.short_x_step;
        tri.long_z += tri.long_z_step;
        tri.long_s += tri.long_s_step;
        tri.long_u += tri.long_u_step1;
        tri.long_v += tri.long_v_step1;
        tri.hline_bptr += vp->vbuff.pitch;
        tri.hline_zptr = (word *)((dword) tri.hline_zptr + vp->vbuff.zpitch);
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
            vngo_dztghline8(y,&tri,&vp->vbuff,tex);
            y++;
            tri.long_x += tri.long_x_step;
            tri.short_x += tri.short_x_step;
            tri.long_z += tri.long_z_step;
            tri.long_s += tri.long_s_step;
            tri.long_u += tri.long_u_step1;
            tri.long_v += tri.long_v_step1;
            tri.hline_bptr += vp->vbuff.pitch;
            tri.hline_zptr = (word *)((dword) tri.hline_zptr + vp->vbuff.zpitch);
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
void vngo_tgpoly8 (VngoVport *vp,int count,VngoPoint *pts, VngoTextureInfo *tex)
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
