//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
//
// tri8.cpp
//
//     The Flat/Solid colored triangle code for the VanGogh Draw library.
//
//����������������������������� Revision History ����������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������
//#include <assert.h>
#include <string.h>

#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������


//���������������������������������������������������������������������������
//
//                               Structures
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                               Routines
//
//���������������������������������������������������������������������������

extern "C" void scan_zgouraud_edge(VngoPoint2 *edge,VngoPoint2 *p1, VngoPoint2 *p2);
extern "C" void draw_zghlines(VngoTriangle *tri);

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

long DitherMatrix[4][4] = 
{  
    0 << 15,  8 << 15,  2 << 15, 10 << 15,
   12 << 15,  4 << 15, 14 << 15,  6 << 15,
    3 << 15, 11 << 15,  1 << 15,  9 << 15,
   15 << 15,  7 << 15, 13 << 15,  5 << 15
};

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//��������������������������������������������������������������������������
//  void vngo_triangle8(VngoVbuffer *vb,VngoPoint2 *pts,dword color)
//      This routine draws a flat shaded triangle, making the assumption
//      that it has already been clipped.
//��������������������������������������������������������������������������

extern "C" void vngo_zgtriangle8 (VngoVbuffer *vb,VngoPoint2 *pts,dword color)
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

    long    dy1 = ((low_pt->y + 0x8000) >> 16) - ((high_pt->y + 0x8000) >> 16);
    long    dy2 = ((mid_pt->y + 0x8000) >> 16) - ((high_pt->y + 0x8000) >> 16);

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

    tri.start_y = (high_pt->y + 0x8000) >> 16;
    tri.color = pts[0].clr;
    tri.sptr  = vb->scrn_ptr + vb->ytable[tri.start_y];
    tri.zptr  = (word*)(long(vb->zbuff_ptr) + vb->ztable[tri.start_y]);

    scan_zgouraud_edge(edge1,high_pt,low_pt);

    scan_zgouraud_edge(edge2,high_pt,mid_pt);

    scan_zgouraud_edge(&edge2[dy2],mid_pt,low_pt);

    tri.vbuff = vb;
    tri.pitch = vb->pitch;
    tri.zpitch = vb->zpitch;
    tri.height = dy1;

    long mid_dx = ((edge2[mid_y].x + 0x8000) >> 16) - ((edge1[mid_y].x + 0x8000) >> 16);

    if (mid_dx >= 0)
    {
        tri.left_edge = edge1;
        tri.right_edge = edge2;
        if (mid_dx)
        {
            tri.zstep_dx1 = (long(edge2[mid_y].z) - long(edge1[mid_y].z)) / mid_dx;
            tri.sstep_dx1 = (long(edge2[mid_y].shade) - long(edge1[mid_y].shade)) / mid_dx;
        }
        else
        {
            tri.zstep_dx1 = 0;
            tri.sstep_dx1 = 0;
        }
    }
    else
    {
        tri.left_edge = edge2;
        tri.right_edge = edge1;

        tri.zstep_dx1 = (long(edge1[mid_y].z) - long(edge2[mid_y].z)) / -mid_dx;
        tri.sstep_dx1 = (long(edge1[mid_y].shade) - long(edge2[mid_y].shade)) / -mid_dx;
    }
    draw_zghlines(&tri);
}

extern "C" void scan_zgouraud_edge(VngoPoint2 *edge,VngoPoint2 *p1, VngoPoint2 *p2)
{
    Flx16 xstep;
    Flx16 zstep;
    Flx16 sstep;
    Flx16 dy = Flx16(p2->y - p1->y ,0);
    long  count = ((p2->y + 0x8000) >> 16) - ((p1->y + 0x8000) >> 16);
    if (count)
    {
        Flx16 dz = Flx16(long(ulong(p2->z) >> 1),0) - Flx16(long(ulong(p1->z) >> 1),0);
        Flx16 dx = Flx16(p2->x - p1->x,0);
        Flx16 ds = Flx16(p2->shade,0) - Flx16(p1->shade,0);
        if (dy.flx < 0x10000)
        {
            xstep = dx;
            zstep = dz;
            sstep = ds;
        }
        else
        {
            xstep = dx / dy;
            zstep = dz / dy;
            sstep = ds / dy;
        }
        Flx16 wx = Flx16(p1->x,0);
        Flx16 wz = Flx16(long(ulong(p1->z) >> 1), 0);
        Flx16 ws = Flx16(p1->shade,0);

        count++;
        while (count--)
        {
            edge->x = wx.flx;
            edge->z = wz.flx;
            edge->shade = ws.flx;
            edge++;
            wx += xstep;
            wz += zstep;
            ws += sstep;
        }
    }
}



extern "C" void draw_zghlines(VngoTriangle *tri)
{
    VngoShadePal8   *tp = (VngoShadePal8 *)tri->vbuff->pal->shd_pal;
    VngoColorShade8 *tc = &(*tp)[tri->color];
    byte            *stable = &tc->shl[0];

    long            count = tri->height;
    long            pitch = tri->pitch;
    long            zpitch = tri->zpitch >> 1;
    long            zstep_dx1 = tri->zstep_dx1;
    long            sstep_dx1 = tri->sstep_dx1;
    byte            *scrn = (byte*)tri->sptr;
    word            *zbuff = (word*)tri->zptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;

    long start_y = tri->start_y;
    for (long y=0;y <= count;y++)
    {
        long tz = edge1->z;
        long ts = edge1->shade;
        long tx = (edge1->x + 0x8000) >> 16;
        byte *ptr = scrn + tx;
        word *zptr = zbuff + tx;
        int dx = ((edge2->x + 0x8000) >> 16);
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

        for (int x = tx;x <= dx; x++)
        {
            word wz = word(tz >> 15);
            if (wz < *zptr)
            {
                *zptr = wz;

                int ws = (ts + dmatrix[x&3]) >> 19;
                if (ws > 31)
                    ws = 31;
                else if (ws < 0)
                    ws =0;

                *ptr = stable[ws];
            }
            ptr++;
            zptr++;
            tz += zstep_dx1;
            ts += sstep_dx1;
        }
        scrn += pitch;
        zbuff += zpitch;
        edge1++;
        edge2++;
    }
}

//��� End of module - ztri8.cpp ���