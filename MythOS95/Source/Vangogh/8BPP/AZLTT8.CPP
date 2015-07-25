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
// zlttri8.cpp
//
//     The 8bpp specific flat shaded linear texture mapped triangle code for
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

extern "C" void vngo_zttriangle8 (VngoVbuffer *vb,VngoPoint2 *pts,
                                  VngoTextureInfo *tex);

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
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  void vngo_zttriangle8(VngoVbuffer *vb,VngoPoint2 *pts,
//                       VngoTextureInfo *tex);
//      This routine draws a linearly texture mapped flat shaded triangle,
//      making the assumption that it has already been clipped.  It draws
//      with respect for the Z-buffer.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

extern "C" void vngo_azttriangle8 (VngoVbuffer *vb,VngoPoint2 *pts,
                                  VngoTextureInfo *tex, long alpha)
{
    if (alpha < 25) // it is transparent enough to be invisible.
        return;
    if (alpha > 225) // it is opaque enough to be solid.
    {
        vngo_zttriangle8(vb,pts,tex);
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
    long    u1 = high_pt->u;
    long    u2;
    long    v1 = high_pt->v;
    long    v2;
    long    z1 = long(ulong(high_pt->z) >> 1);
    long    z2;
    long    xstep1 = (low_pt->x - high_pt->x) / dy1;
    long    xstep2;
    long    ustep1;
    long    ustep2;
    long    ustep;
    long    vstep1;
    long    vstep2;
    long    vstep;
    long    zstep1;
    long    zstep2;
    long    zstep;
    int     edge1_on_left;
    int     line_count;

    if (dy2 == 0)
    {   // the triangle has a flat top in this case.
        edge2 = mid_pt->x;
        u2 = mid_pt->u;
        v2 = mid_pt->v;
        z2 = long(ulong(mid_pt->z) >> 1);
        xstep2 = (low_pt->x - mid_pt->x) / dy1;
        dy2 = dy1;
        has_flat_top = 1;
        line_count = dy2;


        if (mid_pt->x > high_pt->x)
        {
            zstep1 = long((ulong(low_pt->z) >> 1) - (ulong(high_pt->z) >> 1)) / dy1;
            ustep1 = (low_pt->u - high_pt->u) / dy1;
            vstep1 = (low_pt->v - high_pt->v) / dy1;
            edge1_on_left = 1;
            long    dx = ((edge2 + 0x8000) >> 16) - (edge1 >> 16);
            if (dx)
            {
                ustep = (u2 - u1) / dx;
                vstep = (v2 - v1) / dx;
                zstep = (z2 - z1) / dx;
            }
            else
            {
                ustep = 0;
                vstep = 0;
                zstep = 0;
            }
        }
        else
        {
            edge1_on_left = 0;
            ustep2 = (low_pt->u - mid_pt->u) / dy1;
            vstep2 = (low_pt->v - mid_pt->v) / dy1;
            zstep2 = long((ulong(low_pt->z) >> 1) - (ulong(mid_pt->z) >> 1)) / dy1;

            long    dx = ((edge1 + 0x8000) >> 16) - (edge2 >> 16);
            if (dx)
            {
                ustep = (u1 - u2) / dx;
                vstep = (v1 - v2) / dx;
                zstep = (z1 - z2) / dx;
            }
            else
            {
                ustep = 0;
                vstep = 0;
                zstep = 0;
            }
        }
    }
    else
    {
        u2 = u1;
        v2 = v1;
        z2 = z1;
        edge2 = edge1;

        xstep2 = (mid_pt->x - high_pt->x) / dy2;
        ustep1 = (low_pt->u - high_pt->u) / dy1;
        vstep1 = (low_pt->v - high_pt->v) / dy1;
        zstep1 = long((ulong(low_pt->z) >> 1) - (ulong(high_pt->z) >> 1)) / dy1;

        line_count = dy2;

        if (xstep2 > xstep1)
        {
            edge1_on_left = 1;
            long dx = ((mid_pt->x + 0x8000) >> 16) - (((xstep1 * dy2) + edge1) >> 16);
            long newu = (ustep1 * dy2) + u1;
            long newv = (vstep1 * dy2) + v1;
            long newz = (zstep1 * dy2) + z1;

            if (dx)
            {
                ustep = (mid_pt->u - newu) / dx;
                vstep = (mid_pt->v - newv) / dx;
                zstep = (long(ulong(mid_pt->z) >> 1) - newz) / dx;
            }
            else
            {
                ustep = 0;
                vstep = 0;
                zstep = 0;
            }
        }
        else
        {
            edge1_on_left = 0;
            ustep2 = (mid_pt->u - high_pt->u) / dy2;
            vstep2 = (mid_pt->v - high_pt->v) / dy2;
            zstep2 = (long(ulong(mid_pt->z) >> 1) - (long(ulong(high_pt->z) >> 1))) / dy2;

            long dx = (((xstep1 * dy2) + edge1 + 0x8000) >> 16)  - (mid_pt->x >> 16);
            long newu = (ustep1 * dy2) + u1;
            long newv = (vstep1 * dy2) + v1;
            long newz = (zstep1 * dy2) + z1;

            if (dx > 0)
            {
                ustep = (newu - mid_pt->u) / dx;
                vstep = (newv - mid_pt->v) / dx;
                zstep = (newz - long(ulong(mid_pt->z) >> 1)) / dx;
            }
            else
            {
                ustep = 0;
                vstep = 0;
                zstep = 0;
            }
        }
    }

    int             dx;

    VngoShadePal8   *tp = (VngoShadePal8 *)vb->pal->shd_pal;
    VngoColorShade8 *tc = &(*tp)[0];
    byte            *stble = &tc->shl[pts[0].shade >> 19];
    long            toffset = (high_pt->y) >> 16;
    byte            *scrnptr = vb->scrn_ptr + vb->ytable[toffset];
    word            *zptr = vb->zbuff_ptr + (vb->ztable[toffset] >> 1);
    long            pitch = vb->pitch;
    long            zpitch = vb->zpitch >> 1;
    long            curu;
    long            curv;
    long            curz;
    byte            clr;
    byte            *tptr = tex->vtxt->tex;
    long            udown = tex->u_downshift;
    long            vdown = tex->v_downshift - tex->widthshift;
    long            uup = tex->u_upshift;
    long            vup = tex->v_upshift;
    long            mask = ~((1 << tex->widthshift) -1);
    int             dither;
    long            ty=high_pt->y >> 16;
    long            alpha_mask = 0;

    if (alpha_set == 2)
        alpha_mask = 1;


    ustep = ustep << uup;
    vstep = vstep << vup;

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

                    dither = (t ^ ty) & 1;
                    dx = ((edge2 + 0x8000) >> 16) - t;
                    curu = u1 << uup;
                    curv = v1 << vup;
                    curz = z1;
                    for (int i=0;i <= dx;i++)
                    {
                        if (dither || (ty & alpha_mask))
                        {
                            word tz = word(curz >> 15);
                            if (tz < *tzptr)
                            {
                                clr = tptr[(((dword)curv >> vdown) & mask) + ((dword)curu >> udown)];
                                if (clr != VNGO_TRANSPARENT_COLOR)
                                {
                                    *tzptr = tz;
                                    clr = stble[clr << 5];
                                    *tscrn = clr;
                                }
                            }
                        }
                        dither ^= 1;
                        tscrn++;
                        tzptr++;
                        curu += ustep;
                        curv += vstep;
                        curz += zstep;
                    }
                    ty++;
                    edge1 += xstep1;
                    edge2 += xstep2;
                    u1 += ustep1;
                    v1 += vstep1;
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
                    curu = u2 << uup;
                    curv = v2 << vup;
                    curz = z2;
                    for (int i=0;i <= dx;i++)
                    {
                        if (dither || (ty & alpha_mask))
                        {
                            word tz = word(curz >> 15);
                            if (tz < *tzptr)
                            {
                                clr = tptr[(((dword)curv >> vdown) & mask) + ((dword)curu >> udown)];
                                if (clr != VNGO_TRANSPARENT_COLOR)
                                {
                                    *tzptr = tz;
                                    clr = stble[clr << 5];
                                    *tscrn = clr;
                                }
                            }
                        }
                        dither ^= 1;
                        tscrn++;
                        tzptr++;
                        curz += zstep;
                        curu += ustep;
                        curv += vstep;
                    }
                    ty++;
                    edge1 += xstep1;
                    edge2 += xstep2;
                    u2 += ustep2;
                    v2 += vstep2;
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
                    ty++;
                    line_count --;
                    edge1 += xstep1;
                    edge2 += xstep2;
                    scrnptr += pitch;
                    zptr += zpitch;
                    u1 += ustep1;
                    v1 += vstep1;
                    z1 += zstep1;
                }
                long    tustep1 = ustep1 << 1;
                long    tvstep1 = vstep1 << 1;
                long    tzstep1 = zstep1 << 1;
                long    txstep1 = xstep1 << 1;
                long    txstep2 = xstep2 << 1;
                long    tzpitch = zpitch << 1;
                long    tpitch  = pitch << 1;

                while (line_count > 0)
                {
                    long    t = edge1 >> 16;
                    byte    *tscrn = scrnptr + t;
                    word    *tzptr = zptr + t;

                    dither = (t ^ ty) & 1;
                    dx = ((edge2 + 0x8000) >> 16) - t;
                    curu = u1 << uup;
                    curv = v1 << vup;
                    curz = z1;
                    for (int i=0;i <= dx;i++)
                    {
                        if (dither)
                        {
                            word tz = word(curz >> 15);
                            if (tz < *tzptr)
                            {
                                clr = tptr[(((dword)curv >> vdown) & mask) + ((dword)curu >> udown)];
                                if (clr != VNGO_TRANSPARENT_COLOR)
                                {
                                    *tzptr = tz;
                                    clr = stble[clr << 5];
                                    *tscrn = clr;
                                }
                            }
                        }
                        dither ^= 1;
                        tscrn++;
                        tzptr++;
                        curu += ustep;
                        curv += vstep;
                        curz += zstep;
                    }
                    ty+=2;
                    edge1 += txstep1;
                    edge2 += txstep2;
                    u1 += tustep1;
                    v1 += tvstep1;
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
                    ty++;
                    line_count --;
                    edge1 += xstep1;
                    edge2 += xstep2;
                    scrnptr += pitch;
                    zptr += zpitch;
                    u2 += ustep2;
                    v2 += vstep2;
                    z2 += zstep2;
                }
                long    tustep2 = ustep2 << 1;
                long    tvstep2 = vstep2 << 1;
                long    tzstep2 = zstep2 << 1;
                long    txstep1 = xstep1 << 1;
                long    txstep2 = xstep2 << 1;
                long    tzpitch = zpitch << 1;
                long    tpitch  = pitch << 1;

                while (line_count > 0)
                {
                    long t = edge2 >> 16;
                    byte *tscrn = scrnptr + t;
                    word *tzptr = zptr + t;

                    dx = ((edge1 + 0x8000) >> 16)- t;

                    dither = (ty ^ t) & 1;
                    curu = u2 << uup;
                    curv = v2 << vup;
                    curz = z2;
                    for (int i=0;i <= dx;i++)
                    {
                        if (dither)
                        {
                            word tz = word(curz >> 15);
                            if (tz < *tzptr)
                            {
                                clr = tptr[(((dword)curv >> vdown) & mask) + ((dword)curu >> udown)];
                                if (clr != VNGO_TRANSPARENT_COLOR)
                                {
                                    *tzptr = tz;
                                    clr = stble[clr << 5];
                                    *tscrn = clr;
                                }
                            }
                        }
                        dither ^= 1;
                        tscrn++;
                        tzptr++;
                        curz += zstep;
                        curu += ustep;
                        curv += vstep;
                    }
                    ty+=2;
                    edge1 += txstep1;
                    edge2 += txstep2;
                    u2 += tustep2;
                    v2 += tvstep2;
                    z2 += tzstep2;
                    line_count-=2;
                    scrnptr += tpitch;
                    zptr += tzpitch;
                }
            }
        }
        if (!has_flat_top)
        {
            dy2 = ((low_pt->y + 0x8000) >> 16) - ((mid_pt->y + 0x8000)>> 16);

            if (dy2 > 0)
            {
                xstep2 = (low_pt->x - mid_pt->x) / dy2;
                if (!edge1_on_left)
                {
                    zstep2 = long((ulong(low_pt->z) >> 1) - (ulong(mid_pt->z) >> 1)) / dy2;
                    z2 = long(ulong(mid_pt->z) >> 1);
                    z2 += zstep2;
                    ustep2 = (low_pt->u - mid_pt->u)  / dy2;
                    u2 = mid_pt->u;
                    u2 += ustep2;
                    vstep2 = (low_pt->v - mid_pt->v)  / dy2;
                    v2 = mid_pt->v;
                    v2 += vstep2;
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

//°±² End of module - zlttri8.cpp ²±°
