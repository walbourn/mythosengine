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
// zgtri8.cpp
//
//     The 8bpp specific Gouraud shaded triangle draw code for VanGogh.
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
extern "C" void vngo_zgtriangle8 (VngoVbuffer *vb,VngoPoint2 *pts,dword color);

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

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  void vngo_gtriangle8(VngoVbuffer *vb,VngoPoint2 *pts,dword color)
//      This routine draws a Gouraud shaded triangle, making the assumption
//      that it has already been clipped.  It draws with respect for the
//      Z-buffer.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

extern "C" void vngo_azgtriangle8 (VngoVbuffer *vb,VngoPoint2 *pts,
                                   dword color,long alpha)
{
    if (alpha < 25) // it is transparent enough to be invisible.
        return;
    if (alpha > 225) // it is opaque enough to be solid.
    {
        vngo_zgtriangle8(vb,pts,color);
        return;
    }

    int alpha_set=1;
    if (alpha > 170)
        alpha_set=2;
    else if (alpha < 86)
        alpha_set=0;

    int high_pt_idx = 0;
    int has_flat_top=0;
    int low_pt_idx = 2;
    int mid_pt_idx = 1;

    calc_order(high_pt_idx,mid_pt_idx,low_pt_idx,pts);

    VngoPoint2 *high_pt = &pts[high_pt_idx];
    VngoPoint2 *mid_pt = &pts[mid_pt_idx];
    VngoPoint2 *low_pt = &pts[low_pt_idx];

    long    dy1 = ((low_pt->y + 0x8000) >> 16) - ((high_pt->y) >> 16);
    long    dy2 = ((mid_pt->y + 0x8000) >> 16) - ((high_pt->y) >> 16);

    if (dy1 == 0)
    {   // the triangle is completely flat if this is true.
        // So we need to do a horizontal line here.....tl
        return;    
    }

    long    edge1 = high_pt->x;
    long    edge2;
    long    s1 = high_pt->shade;
    long    s2;
    long    z1 = long(ulong(high_pt->z) >> 1);
    long    z2;
    long    xstep1 = (low_pt->x - high_pt->x) / dy1;
    long    xstep2;
    long    sstep1;
    long    sstep2;
    long    sstep;
    long    zstep1;
    long    zstep2;
    long    zstep;
    int     edge1_on_left;
    int     line_count;

    if (dy2 == 0)
    {   // the triangle has a flat top in this case.
        edge2 = mid_pt->x;
        s2 = mid_pt->shade;
        z2 = long(ulong(mid_pt->z) >> 1);
        xstep2 = (low_pt->x - mid_pt->x) / dy1;
        dy2 = dy1;
        has_flat_top = 1;
        line_count = dy2;


        if (mid_pt->x > high_pt->x)
        {
            zstep1 = long((ulong(low_pt->z) >> 1) - (ulong(high_pt->z) >> 1)) / dy1;
            sstep1 = (low_pt->shade - high_pt->shade) / dy1;
            edge1_on_left = 1;
            long    dx = ((edge2 + 0x8000) >> 16) - (edge1 >> 16);
            if (dx)
            {
                sstep = (s2 - s1) / dx;
                zstep = (z2 - z1) / dx;
            }
            else
            {
                sstep = 0;
                zstep = 0;
            }
        }
        else
        {
            edge1_on_left = 0;
            sstep2 = (low_pt->shade - mid_pt->shade) / dy1;
            zstep2 = long((ulong(low_pt->z) >> 1) - (ulong(mid_pt->z) >> 1)) / dy1;

            long    dx = ((edge1 + 0x8000) >> 16) - (edge2 >> 16); 
            if (dx)
            {
                sstep = (s1 - s2) / dx;
                zstep = (z1 - z2) / dx;
            }
            else
            {
                sstep = 0;
                zstep = 0;
            }
        }
    }
    else
    {
        s2 = s1;
        z2 = z1;
        edge2 = edge1;

        xstep2 = (mid_pt->x - high_pt->x) / dy2;
        sstep1 = (low_pt->shade - high_pt->shade) / dy1;
        zstep1 = long((ulong(low_pt->z) >> 1) - (ulong(high_pt->z) >> 1)) / dy1;

        line_count = dy2;

        if (xstep2 > xstep1)
        {
            edge1_on_left = 1;
            long dx = ((mid_pt->x + 0x8000) >> 16) - (((xstep1 * dy2) + edge1) >> 16);
            long news = (sstep1 * dy2) + s1;
            long newz = (zstep1 * dy2) + z1;

            if (dx)
            {
                sstep = (mid_pt->shade - news) / dx;
                zstep = (long(ulong(mid_pt->z) >> 1) - newz) / dx;
            }
            else
            {
                sstep = 0;
                zstep = 0;
            }
        }
        else
        {
            edge1_on_left = 0;
            sstep2 = (mid_pt->shade - high_pt->shade) / dy2;
            zstep2 = (long(ulong(mid_pt->z) >> 1) - (long(ulong(high_pt->z) >> 1))) / dy2;

            long dx = (((xstep1 * dy2) + edge1 + 0x8000) >> 16)  - (mid_pt->x >> 16);
            long news = (sstep1 * dy2) + s1;
            long newz = (zstep1 * dy2) + z1;

            if (dx > 0)
            {
                sstep = (news - mid_pt->shade) / dx;
                zstep = (newz - long(ulong(mid_pt->z) >> 1)) / dx;
            }
            else
            {
                sstep = 0;
                zstep = 0;
            }
        }
    }

    int             dx;

    VngoShadePal8   *tp = (VngoShadePal8 *)vb->pal->shd_pal;
    VngoColorShade8 *tc = &(*tp)[color];
    byte            *stble = &tc->shl[0];
    long            toffset = (high_pt->y) >> 16;
    byte            *scrnptr = vb->scrn_ptr + vb->ytable[toffset];
    word            *zptr = vb->zbuff_ptr + (vb->ztable[toffset] >> 1);
    long            pitch = vb->pitch;
    long            zpitch = vb->zpitch >> 1;
    long            curs;
    long            curz;
    long            dither;
    long            alpha_mask = 0;
    long            ty = high_pt->y >> 16;

    if (alpha_set == 2)
        alpha_mask = 1;


    line_count++;

    while (has_flat_top < 2)
    {
        if (alpha_set)
        {
            if (edge1_on_left)
            {   // edge 1 is on the left;
                while (line_count)
                {
                    long    t = edge1 >> 16;
                    byte    *tscrn = scrnptr + t;
                    word    *tzptr = zptr + t;

                    dx = ((edge2 + 0x8000)>> 16) - t;
                    curs = s1;
                    curz = z1;
                    dither = (ty ^ t) & 1;

                    for (int i=0;i <= dx;i++)
                    {
                        if (dither || (ty & alpha_mask))
                        {
                            word tz = word(curz >> 15);
                            if (tz < *tzptr)
                            {
                                *tzptr = tz;
                                int ts = curs >> 19;
                                if (ts > 31)
                                    ts = 31;
                                else if (ts < 0)
                                    ts = 0;
                                *tscrn = stble[ts];
                            }
                        }
                        tscrn++;
                        tzptr++;
                        curs += sstep;
                        curz += zstep;
                        dither ^= 1;
                    }            
                    ty++;
                    edge1 += xstep1;
                    edge2 += xstep2;
                    s1 += sstep1;
                    z1 += zstep1;
                    line_count--;
                    scrnptr += pitch;
                    zptr += zpitch;
                }
            }
            else
            {   // edge 2 is on the left; 
                while (line_count)
                {
                    long t = edge2 >> 16;
                    byte *tscrn = scrnptr + t;
                    word *tzptr = zptr + t;

                    dx = ((edge1 + 0x8000) >> 16)- t;

                    dither = (ty ^ t) & 1;
                    curs = s2;
                    curz = z2;
                    for (int i=0;i <= dx;i++)
                    {
                        if (dither || (ty & alpha_mask))
                        {
                            word tz = word(curz >> 15);
                            if (tz < *tzptr)
                            {
                                *tzptr = tz;
                                int ts = curs >> 19;
                                if (ts > 31)
                                    ts = 31;
                                else if (ts < 0)
                                    ts = 0;
                                *tscrn = stble[ts];
                            }
                        }
                        tscrn++;
                        tzptr++;
                        curz += zstep;
                        curs += sstep;
                        dither ^= 1;
                    }            
                    ty++;
                    edge1 += xstep1;
                    edge2 += xstep2;
                    s2 += sstep2;
                    z2 += zstep2;
                    line_count--;
                    scrnptr += pitch;
                    zptr += zpitch;
                }
            }
        }
        else
        {
            if (edge1_on_left)
            {   // edge 1 is on the left;
                if (!(ty & 1))
                {
                    edge1 += xstep1;
                    edge2 += xstep2;
                    s1 += sstep1;
                    z1 += zstep1;
                    scrnptr += pitch;
                    zptr += zpitch;
                    ty++;
                    line_count--;
                }
                long txstep1 = xstep1 << 1;
                long txstep2 = xstep2 << 1;
                long tsstep1 = sstep1 << 1;
                long tzstep1 = zstep1 << 1;
                long tpitch = pitch << 1;
                long tzpitch = zpitch << 1;

                while (line_count > 0)
                {
                    long    t = edge1 >> 16;
                    byte    *tscrn = scrnptr + t;
                    word    *tzptr = zptr + t;

                    dx = ((edge2 + 0x8000)>> 16) - t;
                    curs = s1;
                    curz = z1;
                    dither = (ty ^ t) & 1;

                    for (int i=0;i <= dx;i++)
                    {
                        if (dither)
                        {
                            word tz = word(curz >> 15);
                            if (tz < *tzptr)
                            {
                                *tzptr = tz;
                                int ts = curs >> 19;
                                if (ts > 31)
                                    ts = 31;
                                else if (ts < 0)
                                    ts = 0;
                                *tscrn = stble[ts];
                            }
                        }
                        tscrn++;
                        tzptr++;
                        curs += sstep;
                        curz += zstep;
                        dither ^= 1;
                    }            
                    ty+=2;
                    edge1 += txstep1;
                    edge2 += txstep2;
                    s1 += tsstep1;
                    z1 += tzstep1;
                    line_count-=2;
                    scrnptr += tpitch;
                    zptr += tzpitch;
                }
            }
            else
            {   // edge 2 is on the left; 
                if (!(ty & 1))
                {
                    edge1 += xstep1;
                    edge2 += xstep2;
                    s1 += sstep1;
                    z1 += zstep1;
                    scrnptr += pitch;
                    zptr += zpitch;
                    ty++;
                    line_count--;
                }
                long txstep1 = xstep1 << 1;
                long txstep2 = xstep2 << 1;
                long tsstep2 = sstep2 << 1;
                long tzstep2 = zstep2 << 1;
                long tpitch = pitch << 1;
                long tzpitch = zpitch << 1;

                while (line_count > 0)
                {
                    long t = edge2 >> 16;
                    byte *tscrn = scrnptr + t;
                    word *tzptr = zptr + t;

                    dx = ((edge1 + 0x8000) >> 16)- t;

                    dither = (ty ^ t) & 1;
                    curs = s2;
                    curz = z2;
                    for (int i=0;i <= dx;i++)
                    {
                        if (dither)
                        {
                            word tz = word(curz >> 15);
                            if (tz < *tzptr)
                            {
                                *tzptr = tz;
                                int ts = curs >> 19;
                                if (ts > 31)
                                    ts = 31;
                                else if (ts < 0)
                                    ts = 0;
                                *tscrn = stble[ts];
                            }
                        }
                        tscrn++;
                        tzptr++;
                        curz += zstep;
                        curs += sstep;
                        dither ^= 1;
                    }            
                    ty+=2;
                    edge1 += txstep1;
                    edge2 += txstep2;
                    s2 += tsstep2;
                    z2 += tzstep2;
                    line_count-=2;
                    scrnptr += tpitch;
                    zptr += tzpitch;
                }
            }
        }
        if (!has_flat_top)
        {
            dy2 = ((low_pt->y + 0x8000) >> 16) - ((mid_pt->y + 0x8000) >> 16);

            if (dy2 > 0)
            {
                xstep2 = (low_pt->x - mid_pt->x) / dy2;
                if (!edge1_on_left)
                {
                    zstep2 = long((ulong(low_pt->z) >> 1) - (ulong(mid_pt->z) >> 1)) / dy2;
                    z2 = long(ulong(mid_pt->z) >> 1);
                    z2 += zstep2;
                    sstep2 = (low_pt->shade - mid_pt->shade)  / dy2;
                    s2 = mid_pt->shade;
                    s2 += sstep2;
                }
                edge2 = mid_pt->x + xstep2;
                line_count = dy2;
                has_flat_top++;
            }
            else
            {
                return;
            }
        }
        else
        {
            return;
        }
    } 
    return;
}

//°±² End of module - zgtri8.cpp ²±°

