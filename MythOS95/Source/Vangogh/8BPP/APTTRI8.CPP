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
// azpttri8.cpp
//
//     The flat shaded linearly texture mapped triangle code
//     for the VanGogh Draw library.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
#include <assert.h>
#include <string.h>

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

extern "C" void scan_psolid_edge(VngoPoint2 *edge,VngoPointF2 *p1, VngoPointF2 *p2);
extern "C" void draw_aphlines(VngoTriangle *tri,long alpha);
extern "C" void vngo_ttriangle8_persp (VngoVbuffer *vb,VngoPoint2 *pts,
                                       VngoTexture3D *tex);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern long AlphaMatrix[4][4];

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±


inline void find_quadratic(long dx, float pq0, float q0, float q2,
                           float w0, float w2,long *d1,long *d2,
                           long upscale)
{
    if (dx)
    {
        float pdx = 1.f / float(dx);
        float pq1 = (q0 + q2) / (w0 + w2);
    //    float pq0 = q0 / w0;
        float pq2 = q2 / w2;
        float a1 = (-3*pq0 + 4*pq1 - pq2) * pdx;
        float a2 = 2*(pq0 - 2*pq1 + pq2) * pdx * pdx;

        *d1 = long((a1+a2) * float(1 << upscale));
        *d2 = long((2*a2) * float(1 << upscale));
    }
    else
    {
        *d1 = *d2 = 0;
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  void vngo_triangle8(VngoVbuffer *vb,VngoPoint2 *pts,dword color)
//      This routine draws a flat shaded triangle, making the assumption
//      that it has already been clipped.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

extern "C" void vngo_attriangle8_persp (VngoVbuffer *vb,VngoPoint2 *pts,
                                        VngoTexture3D *tex,long alpha)
{
    long            mid_y;
    VngoTriangle    tri;
    int             high_pt_idx = 0;
    int             low_pt_idx = 2;
    int             mid_pt_idx = 1;
    VngoPoint2      *edge1 = vb->edge1;
    VngoPoint2      *edge2 = vb->edge2;

    if (alpha < 15)
        return;
    else if (alpha >= (15 << 4))
        vngo_ttriangle8_persp(vb,pts,tex);

    calc_order(high_pt_idx,mid_pt_idx,low_pt_idx,pts);

    float       flxconv = 1.f / 65536.f;
    VngoPointF2  high_pt;
    high_pt.x = pts[high_pt_idx].x;
    high_pt.y = pts[high_pt_idx].y;
    high_pt.w = float(pts[high_pt_idx].w) / float(1 << 30);
    high_pt.u = (float(pts[high_pt_idx].u) * flxconv) * high_pt.w;
    high_pt.v = (float(pts[high_pt_idx].v) * flxconv) * high_pt.w;

    VngoPointF2  mid_pt;
    mid_pt.x = pts[mid_pt_idx].x;
    mid_pt.y = pts[mid_pt_idx].y;
    mid_pt.w = float(pts[mid_pt_idx].w) / float(1 << 30);
    mid_pt.u = (float(pts[mid_pt_idx].u) * flxconv) * mid_pt.w;
    mid_pt.v = (float(pts[mid_pt_idx].v) * flxconv) * mid_pt.w;

    VngoPointF2  low_pt;
    low_pt.x = pts[low_pt_idx].x;
    low_pt.y = pts[low_pt_idx].y;
    low_pt.w = float(pts[low_pt_idx].w) / float(1 << 30);
    low_pt.u = (float(pts[low_pt_idx].u) * flxconv) * low_pt.w;
    low_pt.v = (float(pts[low_pt_idx].v) * flxconv) * low_pt.w;

    long    dy1 = ((low_pt.y + 0x8000) >> 16) - ((high_pt.y + 0x8000) >> 16);
    long    dy2 = ((mid_pt.y + 0x8000) >> 16) - ((high_pt.y + 0x8000) >> 16);

    if (dy1 == 0)
    {   // the triangle is completely flat if this is true.
        return;
    }

    tri.start_y = (high_pt.y + 0x8000) >> 16;
    tri.color = pts[0].clr;
    tri.sptr  = vb->scrn_ptr + vb->ytable[tri.start_y];

    scan_psolid_edge(edge1,&high_pt,&low_pt);

    scan_psolid_edge(edge2,&high_pt,&mid_pt);

    scan_psolid_edge(&edge2[dy2],&mid_pt,&low_pt);

    tri.vbuff = vb;
    tri.pitch = vb->pitch;
    tri.height = dy1;

    assert(tex->get_type() == VNGO_MEM_TEX);
    tri.tex = (VngoMemTexture3D*)tex;
    tri.shade = pts[0].shade;

    if (dy1 > dy2)
    {
        mid_y = dy2;
    }
    else
    {
        mid_y = dy2 - 1;
    }
    long mid_dx = ((edge2[mid_y].x + 0x8000) >> 16)
                  - ((edge1[mid_y].x + 0x8000) >> 16);


    mid_dx = ((edge2[mid_y].x + 0x8000) >> 16)
             - ((edge1[mid_y].x + 0x8000) >> 16);


    if (mid_dx >= 0)
    {
        tri.left_edge = edge1;
        tri.right_edge = edge2;
    }
    else
    {
        tri.left_edge = edge2;
        tri.right_edge = edge1;

    }

    draw_aphlines(&tri,alpha);
}


extern "C" void draw_aphlines(VngoTriangle *tri,long alpha)
{
    VngoShadePal8   *tp = (VngoShadePal8 *)tri->vbuff->pal->shd_pal;
    VngoColorShade8 *tc = &(*tp)[0];
    byte            *stable = &tc->shl[tri->shade >> 19];

    long            count = tri->height;
    long            pitch = tri->pitch;

    long            ustep_dx1 = tri->ustep_dx1;
    long            ustep_dx2 = tri->ustep_dx2;
    long            vstep_dx1 = tri->vstep_dx1;
    long            vstep_dx2 = tri->vstep_dx2;

    byte            *scrn = (byte*)tri->sptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            uup = tri->tex->u_upshift;
    long            vup = tri->tex->v_upshift;
    long            udown = tri->tex->u_downshift;
    long            vdown = tri->tex->v_downshift - tri->tex->widthshift;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    long            mask = ~((1 << tri->tex->widthshift) - 1);
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long tu = edge1->u << uup;
        long tv = edge1->v << vup;

        long tx = (edge1->x + 0x8000) >> 16;
        byte *ptr = scrn + tx;
        int dx = ((edge2->x + 0x8000) >> 16);
        int ldx = dx - tx;
        long *amatrix = &AlphaMatrix[(start_y + y) & 3][0];

        if (ldx > 0)
        {
            vngo_calc_quadratic2(edge1->w,edge2->w,edge1->u,edge2->u,ldx,
                                &ustep_dx1,&ustep_dx2,uup);
            vngo_calc_quadratic2(edge1->w,edge2->w,edge1->v,edge2->v,ldx,
                                &vstep_dx1,&vstep_dx2,vup);
        }
        else
        {
            ustep_dx1=0;
            ustep_dx2=0;
            vstep_dx1=0;
            vstep_dx2=0;
        }

        for (int x = tx;x <= dx; x++)
        {
            if ((amatrix[x & 3] + alpha) >= 255)
            {
                clr = tptr[(((dword)tv >> vdown) & mask)
                            + ((dword)tu >> udown)];

                if (clr != VNGO_TRANSPARENT_COLOR)
                {
                    *ptr = stable[(clr << 5)];
                }
            }
            ptr++;
            tu += ustep_dx1;
            tv += vstep_dx1;
            ustep_dx1 += ustep_dx2;
            vstep_dx1 += vstep_dx2;
        }
        scrn += pitch;
        edge1++;
        edge2++;
    }
}

//°±² End of module - zlttri8.cpp ²±°
