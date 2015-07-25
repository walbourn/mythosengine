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
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
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
// zpgt8.cpp
//
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

STATIC void find_quadratic(long &dx, double &q0, double &q2,
                    double &w0, double &w2,long *d1,long *d2,long upscale);

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
//  void vngo_zgtriangle8_persp (VngoVbuffer *vp,VngoPoint2 *pts,
//                               VngoTexture3D *tex)
//      This routine draws a Gouraud shaded perspected texture mapped
//      triangle, making the assumption that it has already been clipped.
//      It draws with respect for the Z-buffer.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

extern "C" void vngo_ztgtriangle8_persp (VngoVbuffer *vb,VngoPoint2 *pts,
                                         VngoTexture3D *tex)
{
    int high_pt_idx = 0;
    int has_flat_top=0;
    int low_pt_idx = 2;
    int mid_pt_idx = 1;

    calc_order(high_pt_idx,mid_pt_idx,low_pt_idx,pts);

    VngoPoint2 *high_pt = &pts[high_pt_idx];
    VngoPoint2 *mid_pt = &pts[mid_pt_idx];
    VngoPoint2 *low_pt = &pts[low_pt_idx];

    double wscale = 1. / double (1 << 30);
    double whigh_pt = double(high_pt->w) * wscale;
    double wmid_pt = double(mid_pt->w) * wscale;
    double wlow_pt = double(low_pt->w) * wscale;

    double uhigh_pt = double (high_pt->u) * whigh_pt;
    double umid_pt = double (mid_pt->u) * wmid_pt;
    double ulow_pt = double (low_pt->u) * wlow_pt;

    double vhigh_pt = double (high_pt->v) * whigh_pt;
    double vmid_pt = double (mid_pt->v) * wmid_pt;
    double vlow_pt = double (low_pt->v) * wlow_pt;

    long    dy1 = ((low_pt->y + 0x80000) >> 20) - ((high_pt->y) >> 20);
    long    dy2 = ((mid_pt->y + 0x80000) >> 20) - ((high_pt->y) >> 20);

    if (dy1 == 0)
    {   // the triangle is completely flat if this is true.
        // So we need to do a horizontal line here.....tl
        return;
    }

    double  u1 = uhigh_pt;
    double  u2;
    double  v1 = vhigh_pt;
    double  v2;
    double  w1 = whigh_pt;
    double  w2;
    double  vstep1;
    double  vstep2;
    double  ustep1;
    double  ustep2;
    double  wstep1;
    double  wstep2;

    long    edge1 = high_pt->x;
    long    edge2;
    long    z1 = long(ulong(high_pt->z) >> 1);
    long    z2;
    long    s1 = high_pt->shade;
    long    s2;
    long    xstep1 = (low_pt->x - high_pt->x) / dy1;
    long    xstep2;
    long    ustep_dx1;
    long    vstep_dx1;
    long    ustep_dx2;
    long    vstep_dx2;
    long    ustep;
    long    vstep;
    long    uup = tex->u_upshift;
    long    vup = tex->v_upshift;
    long    zstep1;
    long    zstep2;
    long    zstep;
    long    sstep1;
    long    sstep2;
    long    sstep;
    int     edge1_on_left;
    int     line_count;

    double idy1 = 1. / double(dy1);
    zstep1 = long((ulong(low_pt->z) >> 1) - (ulong(high_pt->z) >> 1)) / dy1;
    sstep1 = (low_pt->shade - high_pt->shade) / dy1;

    ustep1 = (ulow_pt - uhigh_pt) * idy1;
    vstep1 = (vlow_pt - vhigh_pt) * idy1;
    wstep1 = (wlow_pt - whigh_pt) * idy1;

    double idy2 = 1. / double(dy2);
    ustep2 = (umid_pt - uhigh_pt) * idy2;
    vstep2 = (vmid_pt - vhigh_pt) * idy2;
    wstep2 = (wmid_pt - whigh_pt) * idy2;


    if (dy2 == 0)
    {   // the triangle has a flat top in this case.
        u2 = umid_pt;
        edge2 = mid_pt->x;

        s2 = mid_pt->shade;
        w2 = wmid_pt;
        z2 = long(ulong(mid_pt->z) >> 1);
        v2 = vmid_pt;

        wstep2 = (wlow_pt - wmid_pt) / double(dy1);

        xstep2 = (low_pt->x - mid_pt->x) / dy1;
        dy2 = dy1;
        has_flat_top = 1;
        line_count = dy2;


        if (mid_pt->x > high_pt->x)
        {
            edge1_on_left = 1;
            long    dx = ((edge2 + 0x80000) >> 20) - (edge1 >> 20);
            if (dx)
            {
                sstep = (s2 - s1) / dx;
                zstep = (z2 - z1) / dx;

                // Need to calc a quadratic here.
                find_quadratic(dx,u1,u2,w1,w2,&ustep_dx1,&ustep_dx2,uup);
                find_quadratic(dx,v1,v2,w1,w2,&vstep_dx1,&vstep_dx2,vup);

            }
            else
            {
                sstep = 0;
                zstep = 0;

                ustep_dx1 = ustep_dx2 = 0;
                vstep_dx1 = vstep_dx2 = 0;
            }
        }
        else
        {
            edge1_on_left = 0;
            sstep2 = (low_pt->shade - mid_pt->shade) / dy1;
            zstep2 = long((ulong(low_pt->z) >> 1) - (ulong(mid_pt->z) >> 1)) / dy1;


            double idy1 = 1. / double(dy1);
            ustep2 = (ulow_pt - umid_pt) * idy1;
            vstep2 = (vlow_pt - vmid_pt) * idy1;
            vstep2 = (vlow_pt - vmid_pt) * idy1;

            long    dx = ((edge1 + 0x80000) >> 20) - (edge2 >> 20);
            if (dx)
            {
                sstep = (s1 - s2) / dx;
                zstep = (z1 - z2) / dx;

                // Need to calc a quadratic here.
                find_quadratic(dx,u2,u1,w2,w1,&ustep_dx1,&ustep_dx2,uup);
                find_quadratic(dx,v2,v1,w2,w1,&vstep_dx1,&vstep_dx2,vup);

            }
            else
            {
                sstep = 0;
                zstep = 0;

                ustep_dx1 = ustep_dx2 = 0;
                vstep_dx1 = vstep_dx2 = 0;
            }
        }
    }
    else
    {
        u2 = u1;
        v2 = v1;
        s2 = s1;
        z2 = z1;
        w2 = w1;
        edge2 = edge1;

        xstep2 = (mid_pt->x - high_pt->x) / dy2;
//        sstep1 = (low_pt->shade - high_pt->shade) / dy1;

//        double idy1 = 1. / double(dy1);
//        ustep1 = (ulow_pt - uhigh_pt) * idy1;
//        vstep1 = (vlow_pt - vhigh_pt) * idy1;
//        wstep1 = (wlow_pt - whigh_pt) * idy1;

//        zstep1 = long((ulong(low_pt->z) >> 1) - (ulong(high_pt->z) >> 1)) / dy1;

        line_count = dy2;

        if (xstep2 > xstep1)
        {
            edge1_on_left = 1;
            long dx = ((mid_pt->x + 0x80000) >> 20) - (((xstep1 * dy2) + edge1) >> 20);
            long news = (sstep1 * dy2) + s1;
            long newz = (zstep1 * dy2) + z1;

            double newu = (ustep1 * double(dy2)) + u1;
            double newv = (vstep1 * double(dy2)) + v1;
            double neww = (wstep1 * double(dy2)) + w1;

            if (dx)
            {
                sstep = (mid_pt->shade - news) / dx;
                zstep = (long(ulong(mid_pt->z) >> 1) - newz) / dx;

                // Again with the scary quadratic.
                find_quadratic(dx,newu,umid_pt,neww,wmid_pt,&ustep_dx1,&ustep_dx2,uup);
                find_quadratic(dx,newv,vmid_pt,neww,wmid_pt,&vstep_dx1,&vstep_dx2,vup);
            }
            else
            {
                sstep = 0;
                zstep = 0;


                ustep_dx1 = ustep_dx2 = 0;
                vstep_dx1 = vstep_dx2 = 0;
            }
        }
        else
        {
            double idy2 = 1. / double(dy2);
            edge1_on_left = 0;
            sstep2 = (mid_pt->shade - high_pt->shade) / dy2;

            ustep2 = (umid_pt - uhigh_pt) * idy2;
            vstep2 = (vmid_pt - vhigh_pt) * idy2;
            wstep2 = (wmid_pt - whigh_pt) * idy2;

            zstep2 = (long(ulong(mid_pt->z) >> 1) - (long(ulong(high_pt->z) >> 1))) / dy2;

            long dx = (((xstep1 * dy2) + edge1 + 0x80000) >> 20) - (mid_pt->x >> 20);

            long news = (sstep1 * dy2) + s1;
            long newz = (zstep1 * dy2) + z1;

            double newu = (ustep1 * double(dy2)) + u1;
            double newv = (vstep1 * double(dy2)) + v1;
            double neww = (wstep1 * double(dy2)) + w1;


            if (dx > 0)
            {
                sstep = (news - mid_pt->shade) / dx;
                zstep = (newz - long(ulong(mid_pt->z) >> 1)) / dx;

                // Scary quadratic.
                find_quadratic(dx,umid_pt,newu,wmid_pt,neww,&ustep_dx1,&ustep_dx2,uup);
                find_quadratic(dx,vmid_pt,newv,wmid_pt,neww,&vstep_dx1,&vstep_dx2,vup);

            }
            else
            {
                sstep = 0;
                zstep = 0;

                ustep_dx1 = ustep_dx2 = 0;
                vstep_dx1 = vstep_dx2 = 0;
            }
        }
    }

    long            dx;

    VngoShadePal8   *tp = (VngoShadePal8 *)vb->pal->shd_pal;
    VngoColorShade8 *tc = &(*tp)[0];
    byte            *stble = &tc->shl[0];
    long            toffset = (high_pt->y) >> 20;
    byte            *scrnptr = vb->scrn_ptr + vb->ytable[toffset];
    word            *zptr = vb->zbuff_ptr + (vb->ztable[toffset] >> 1);
    long            pitch = vb->pitch;
    long            zpitch = vb->zpitch >> 1;
    long            curu;
    long            curv;
    long            curz;
    long            curs;
    byte            clr;
    byte            *tptr = tex->vtxt->tex;
    long            udown = tex->u_downshift;
    long            vdown = tex->v_downshift - tex->widthshift;
    long            mask = ~((1 << tex->widthshift) -1);
    long            dither = (1 << 22);
    long            ditherbit = (1 << 22);


    // check this.
//    ustep_dx1 = ustep_dx1 << uup;
//    vstep_dx1 = vstep_dx1 << vup;
//    ustep_dx2 = ustep_dx2 << uup;
//    vstep_dx2 = vstep_dx2 << vup;

    line_count++;

    while (has_flat_top < 2)
    {
        if (edge1_on_left)
        {   // edge 1 is on the left;
            while (line_count)
            {
                double  wunscale = 1. / w1;
                long    t = edge1 >> 20;
                byte    *tscrn = scrnptr + t;
                word    *tzptr = zptr + t;

                dx =((edge2 + 0x80000) >> 20) - t;
                curu = long(u1 * wunscale) << uup;
                curv = long(v1 * wunscale) << vup;
                ustep = ustep_dx1;
                vstep = vstep_dx1;
                curs = s1;
                curz = z1;
                for (int i=0;i <= dx;i++)
                {
                    word tz = word(curz >> 15);
                    if (tz < *tzptr)
                    {
                        *tzptr = tz;
                        clr = tptr[(((dword)curv >> vdown) & mask) + ((dword)curu >> udown)];
                        if (clr != VNGO_TRANSPARENT_COLOR)
                        {
                            int ts = ((curs + dither) >> 23);
                            if (ts > 31)
                                ts = 31;
                            else if (ts < 0)
                                ts = 0;

                            clr = stble[(clr << 5) + ts];
                            *tscrn = clr;
                            dither ^= ditherbit;
                        }
                    }
                    tscrn++;
                    tzptr++;
                    curu += ustep;
                    curv += vstep;
                    ustep += ustep_dx2;
                    vstep += vstep_dx2;
                    curz += zstep;
                    curs += sstep;
                }
                u1 += ustep1;
                v1 += vstep1;
                w1 += wstep1;
                edge1 += xstep1;
                edge2 += xstep2;
                z1 += zstep1;
                s1 += sstep1;
                line_count--;
                scrnptr += pitch;
                zptr += zpitch;
            }
        }
        else
        {   // edge 2 is on the left;
            while (line_count)
            {
                long t = edge2 >> 20;
                byte *tscrn = scrnptr + t;
                word *tzptr = zptr + t;

                dx = ((edge1 + 0x80000) >> 20)- t;

                double wunscale = 1. / w2;
                curu = long(u2 * wunscale) << uup;
                curv = long(v2 * wunscale) << vup;
                ustep = ustep_dx1;
                vstep = vstep_dx1;
                curz = z2;
                curs = s2;
                for (int i=0;i <= dx;i++)
                {
                    word tz = word(curz >> 15);
                    if (tz < *tzptr)
                    {
                        *tzptr = tz;
                        clr = tptr[(((dword)curv >> vdown) & mask) + ((dword)curu >> udown)];
                        if (clr != VNGO_TRANSPARENT_COLOR)
                        {
                            int ts = ((curs + dither) >> 23);
                            if (ts > 31)
                                ts = 31;
                            else if (ts < 0)
                                ts = 0;

                            clr = stble[(clr << 5) + ts];
                            *tscrn = clr;
                            dither ^= ditherbit;
                        }
                    }
                    tscrn++;
                    tzptr++;
                    curz += zstep;
                    curs += sstep;
                    curu += ustep;
                    curv += vstep;
                    ustep += ustep_dx2;
                    vstep += vstep_dx2;
                }

                edge1 += xstep1;
                edge2 += xstep2;
                u2 += ustep2;
                v2 += vstep2;
                w2 += wstep2;
                z2 += zstep2;
                s2 += sstep2;
                line_count--;
                scrnptr += pitch;
                zptr += zpitch;
            }
        }
        if (!has_flat_top)
        {
            dy2 = ((low_pt->y) >> 20) - ((mid_pt->y + 0x80000)>> 20);

            if (dy2 > 0)
            {
                xstep2 = (low_pt->x - mid_pt->x) / dy2;
                if (!edge1_on_left)
                {
                    sstep2 = (low_pt->shade - mid_pt->shade)  / dy2;
                    s2 = mid_pt->shade;
                    s2 += sstep2;
                    zstep2 = long((ulong(low_pt->z) >> 1) - (ulong(mid_pt->z) >> 1)) / dy2;
                    z2 = long(ulong(mid_pt->z) >> 1);
                    z2 += zstep2;

                    ustep2 = (ulow_pt - umid_pt) / double(dy2);
                    vstep2 = (vlow_pt - vmid_pt) / double(dy2);
                    u2 = umid_pt;
                    u2 += ustep2;
                    v2 = vmid_pt;
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


STATIC void find_quadratic(long &dx, double &q0, double &q2,
                    double &w0, double &w2,long *d1,long *d2,long upscale)
{
    double pdx = 1. / double(dx);
    double pq1 = (q0 + q2) / (w0 + w2);
    double pq0 = q0 / w0;
    double pq2 = q2 / w2;
    double a1 = (-3*pq0 + 4*pq1 - pq2) * pdx;
    double a2 = 2*(pq0 - 2*pq1 + pq2) * pdx * pdx;

    *d1 = long((a1+a2) * double(1 << upscale));
    *d2 = long((2*a2) * double(1 << upscale));
}

//°±² End of module - zlgttri.cpp ²±°
