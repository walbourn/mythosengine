//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                        http://www.mythos-engine.org/
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Tim Little
//
// grtri8.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

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

extern "C" void scan_gradient_edge(VngoPoint2 *edge,VngoPoint2 *p1, VngoPoint2 *p2);
extern "C" void draw_grhlines16(VngoTriangle *tri);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern long RedDitherMatrix[4][4];
extern long GreenDitherMatrix[4][4];
extern long BlueDitherMatrix[4][4];

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

extern "C" void vngo_grtriangle16 (VngoVbuffer *vb,VngoPoint2 *pts,dword color)
{
    long            mid_y;
    int             high_pt_idx = 0;
    int             low_pt_idx = 2;
    int             mid_pt_idx = 1;
    VngoTriangle    tri;
    VngoPoint2      *edge1 = vb->edge1;
    VngoPoint2      *edge2 = vb->edge2;

    calc_order(high_pt_idx,mid_pt_idx,low_pt_idx,pts);

    VngoPoint2 *high_pt = &pts[high_pt_idx];
    VngoPoint2 *mid_pt = &pts[mid_pt_idx];
    VngoPoint2 *low_pt = &pts[low_pt_idx];

    long    dy1 = ((low_pt->y) >> 16) - ((high_pt->y) >> 16);
    long    dy2 = ((mid_pt->y) >> 16) - ((high_pt->y) >> 16);

    if (dy1 == 0)
    {   // the triangle is completely flat if this is true.
        return;
    }

    if (dy1 > dy2)
    {
        mid_y = dy2;
    }
    else
    {
        mid_y = dy2 - 1;
    }

    tri.start_y = (high_pt->y) >> 16;
    tri.color = pts[0].clr;
    tri.sptr  = (word*)(dword(vb->scrn_ptr) + vb->ytable[(high_pt->y) >> 16]);

    scan_gradient_edge(edge1,high_pt,low_pt);

    scan_gradient_edge(edge2,high_pt,mid_pt);

    scan_gradient_edge(&edge2[dy2],mid_pt,low_pt);

    tri.vbuff = vb;
    tri.pitch = vb->pitch;
    tri.height = dy1;

    long mid_dx = ((edge2[mid_y].x + 0x8000) >> 16) - ((edge1[mid_y].x + 0x8000) >> 16);

    if (mid_dx >= 0)
    {
        tri.left_edge = edge1;
        tri.right_edge = edge2;
        if (mid_dx)
        {
            tri.sstep_dx1 = (long(edge2[mid_y].shade) - long(edge1[mid_y].shade)) / mid_dx;
            tri.ustep_dx1 = (long(edge2[mid_y].u) - long(edge1[mid_y].u)) / mid_dx;
            tri.vstep_dx1 = (long(edge2[mid_y].v) - long(edge1[mid_y].v)) / mid_dx;
        }
        else
        {
            tri.sstep_dx1 = 0;
            tri.ustep_dx1 = 0;
            tri.vstep_dx1 = 0;
        }
    }
    else
    {
        tri.left_edge = edge2;
        tri.right_edge = edge1;

        tri.sstep_dx1 = (long(edge1[mid_y].shade) - long(edge2[mid_y].shade)) / -mid_dx;
        tri.ustep_dx1 = (long(edge1[mid_y].u) - long(edge2[mid_y].u)) / -mid_dx;
        tri.vstep_dx1 = (long(edge1[mid_y].v) - long(edge2[mid_y].v)) / -mid_dx;
    }
    draw_grhlines16(&tri);
}


extern "C" void draw_grhlines16 (VngoTriangle *tri)
{
    VngoVbuffer     *vb = tri->vbuff;

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;
    long            zstep_dx1 = tri->zstep_dx1;
    long            Rstep_dx1 = tri->sstep_dx1;
    long            Gstep_dx1 = tri->ustep_dx1;
    long            Bstep_dx1 = tri->vstep_dx1;

    word            *scrn = (word*)tri->sptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;

    long start_y = tri->start_y;
    if (vb->pal->flags & VNGO_15BIT)
    {
        for (long y=0;y < count;y++)
        {
            long tR = edge1->shade;
            long tG = edge1->u;
            long tB = edge1->v;
            long tx = ((edge1->x + 0xffff) >> 16);
            word *ptr = scrn + tx;
            int dx = ((edge2->x + 0xffff) >> 16);

            long *dmatrixR = &RedDitherMatrix[(start_y+y)&3][0];
            long *dmatrixG = &GreenDitherMatrix[(start_y+y)&3][0];
            long *dmatrixB = &BlueDitherMatrix[(start_y+y)&3][0];

            for (int x = tx;x < dx; x++)
            {
                int ltx = x & 3;
                word val = 0;
                int tval = tB + dmatrixB[ltx];
                if (tval > 0xff0000)
                    val = word(0x1f << 10);
                else if (tval >= 0)
                    val = word(tval >> 9) & (0x1f << 10);

                tval = tG + dmatrixG[ltx];
                if (tval > 0xff0000)
                    val |= word(0x1f << 5);
                else if (tval >= 0)
                    val |= word(tval >> 14) & (0x1f << 5);


                tval = tR + dmatrixR[ltx];
                if (tval > 0xff0000)
                    val |= word(0x1f);
                else if (tval >= 0)
                    val |= word((tval >> 19) & 0x1f);

                *ptr = val;
                ptr++;
                tR += Rstep_dx1;
                tG += Gstep_dx1;
                tB += Bstep_dx1;
            }
            scrn += pitch;
            edge1++;
            edge2++;
        }
    }
    else
    {
        for (long y=0;y < count;y++)
        {
            long tR = edge1->shade;
            long tG = edge1->u;
            long tB = edge1->v;
            long tx = ((edge1->x + 0xffff) >> 16);
            word *ptr = scrn + tx;
            int dx = ((edge2->x + 0xffff) >> 16);

            long *dmatrixR = &RedDitherMatrix[(start_y+y)&3][0];
            long *dmatrixG = &GreenDitherMatrix[(start_y+y)&3][0];
            long *dmatrixB = &BlueDitherMatrix[(start_y+y)&3][0];

            for (int x = tx;x < dx; x++)
            {
                int ltx = x & 3;
                word val = 0;
                int tval = tB + dmatrixB[ltx];
                if (tval > 0xff0000)
                    val = word(0x1f << 11);
                else if (tval >= 0)
                    val = word(tval >> 8) & (0x1f << 11);

                tval = tG + dmatrixG[ltx];
                if (tval > 0xff0000)
                    val |= word(0x3f << 5);
                else if (tval >= 0)
                    val |= word(tval >> 13) & (0x3f << 5);


                tval = tR + dmatrixR[ltx];
                if (tval > 0xff0000)
                    val |= word(0x1f);
                else if (tval >= 0)
                    val |= word((tval >> 19) & 0x1f);

                *ptr = val;
                ptr++;
                tR += Rstep_dx1;
                tG += Gstep_dx1;
                tB += Bstep_dx1;
            }
            scrn += pitch;
            edge1++;
            edge2++;
        }
    }
}

//°±² End of module - ztri8.cpp ²±°
