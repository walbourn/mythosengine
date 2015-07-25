//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  |
//                                                           |_|_|_._._.|
// Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
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
// azlgttr8.cpp
//
//     The Gouraud shaded linearly texture mapped triangle code
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

extern "C" void scan_zlgouraud_edge(VngoPoint2 *edge,VngoPoint2 *p1, VngoPoint2 *p2);
extern "C" void draw_azlghlines(VngoTriangle *tri,long alpha);
extern "C" void vngo_ztgtriangle8 (VngoVbuffer *vb,VngoPoint2 *pts,
                                   VngoTexture3D *tex);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern long AlphaMatrix[4][4];
extern long DitherMatrix[4][4];

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  void vngo_triangle8(VngoVbuffer *vb,VngoPoint2 *pts,dword color)
//      This routine draws a flat shaded triangle, making the assumption
//      that it has already been clipped.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

extern "C" void vngo_aztgtriangle8 (VngoVbuffer *vb,VngoPoint2 *pts,
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
        vngo_ztgtriangle8(vb,pts,tex);

    calc_order(high_pt_idx,mid_pt_idx,low_pt_idx,pts);

    VngoPoint2 *high_pt = &pts[high_pt_idx];
    VngoPoint2 *mid_pt = &pts[mid_pt_idx];
    VngoPoint2 *low_pt = &pts[low_pt_idx];

    long    dy1 = ((low_pt->y + 0x8000) >> 16) - ((high_pt->y + 0x8000) >> 16);
    long    dy2 = ((mid_pt->y + 0x8000) >> 16) - ((high_pt->y + 0x8000) >> 16);

    if (dy1 == 0)
    {   // the triangle is completely flat if this is true.
        return;
    }

    tri.start_y = (high_pt->y + 0x8000) >> 16;
    tri.color = pts[0].clr;
    tri.sptr  = vb->scrn_ptr + vb->ytable[tri.start_y];
    tri.zptr  = (word*)(long(vb->zbuff_ptr) + vb->ztable[tri.start_y]);

    scan_zlgouraud_edge(edge1,high_pt,low_pt);

    scan_zlgouraud_edge(edge2,high_pt,mid_pt);

    scan_zlgouraud_edge(&edge2[dy2],mid_pt,low_pt);

    tri.vbuff = vb;
    tri.pitch = vb->pitch;
    tri.zpitch = vb->zpitch;
    tri.height = dy1;

    assert (tex->get_type() == VNGO_MEM_TEX);
    tri.tex = (VngoMemTexture3D*)tex;

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
        if (mid_dx)
        {
            tri.zstep_dx1 = (long(edge2[mid_y].z) - long(edge1[mid_y].z)) / mid_dx;
            tri.sstep_dx1 = (long(edge2[mid_y].shade) - long(edge1[mid_y].shade)) / mid_dx;
            tri.ustep_dx1 = ((edge2[mid_y].u - edge1[mid_y].u) / mid_dx) << tri.tex->u_upshift;
            tri.vstep_dx1 = ((edge2[mid_y].v - edge1[mid_y].v) / mid_dx) << tri.tex->v_upshift;
        }
        else
        {
            tri.zstep_dx1 = 0;
            tri.sstep_dx1 = 0;
            tri.ustep_dx1 = 0;
            tri.vstep_dx1 = 0;
        }
    }
    else
    {
        tri.left_edge = edge2;
        tri.right_edge = edge1;

        tri.zstep_dx1 = (long(edge1[mid_y].z) - long(edge2[mid_y].z)) / -mid_dx;
        tri.sstep_dx1 = (long(edge1[mid_y].shade) - long(edge2[mid_y].shade)) / -mid_dx;
        tri.ustep_dx1 = ((edge1[mid_y].u - edge2[mid_y].u) / -mid_dx) << tri.tex->u_upshift;
        tri.vstep_dx1 = ((edge1[mid_y].v - edge2[mid_y].v) / -mid_dx) << tri.tex->v_upshift;
    }
    draw_azlghlines(&tri,alpha);
}




extern "C" void draw_azlghlines(VngoTriangle *tri,long alpha)
{
    VngoShadePal8   *tp = (VngoShadePal8 *)tri->vbuff->pal->shd_pal;
    VngoColorShade8 *tc = &(*tp)[0];
    byte            *stable = &tc->shl[0];

    long            count = tri->height;
    long            pitch = tri->pitch;
    long            zpitch = tri->zpitch >> 1;

    long            zstep_dx1 = tri->zstep_dx1;
    long            sstep_dx1 = tri->sstep_dx1;
    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;

    byte            *scrn = (byte*)tri->sptr;
    word            *zbuff = (word*)tri->zptr;
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
        long tz = edge1->z;
        long ts = edge1->shade;
        long tu = edge1->u << uup;
        long tv = edge1->v << vup;
        long matx;

        long tx = (edge1->x + 0x8000) >> 16;
        byte *ptr = scrn + tx;
        word *zptr = zbuff + tx;
        int dx = ((edge2->x + 0x8000) >> 16);
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];
        long *amatrix = &AlphaMatrix[(start_y+y)&3][0];

        for (int x = tx;x <= dx; x++)
        {
            matx = x & 3;
            if ((amatrix[matx] + alpha) >= 255)
            {
                word wz = word(tz >> 15);
                if (wz < *zptr)
                {
                    clr = tptr[(((dword)tv >> vdown) & mask)
                               + ((dword)tu >> udown)];

                    if (clr != VNGO_TRANSPARENT_COLOR)
                    {
                        *zptr = wz;

                        int ws = (ts + dmatrix[matx]) >> 19;
                        if (ws > 31)
                            ws = 31;
                        else if (ws < 0)
                            ws =0;

                        *ptr = stable[(clr << 5) + ws];
                    }
                }
            }
            ptr++;
            zptr++;
            tz += zstep_dx1;
            ts += sstep_dx1;
            tu += ustep_dx1;
            tv += vstep_dx1;
        }
        scrn += pitch;
        zbuff += zpitch;
        edge1++;
        edge2++;
    }
}

//°±² End of module - zlgtri8.cpp ²±°
