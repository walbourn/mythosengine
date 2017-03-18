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
// tahlgen.cpp
//
//     The alpha blended non-texturemapped horizontal scan line code.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"
#include <math.h>

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

extern long DitherMatrix[4][4];

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


extern "C" void vngo_taghlines16 (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[tri->color];
    word             *stable = &tc->shl[0];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;

    long            sstep_dx1 = tri->sstep_dx1;

    word            *scrn = (word*)tri->sptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    word            work;
    word            swork;
    word            dwork;
    byte            *salpha = &VgSystem->alpha_table[(tri->alpha) << 5];
    byte            *dalpha = &VgSystem->alpha_table[( 255 - tri->alpha) << 5];

    if (tri->vbuff->pal->flags & VNGO_15BIT)
    {
        for (long y=0;y <= count;y++)
        {
            long ts = edge1->shade;

            long tx = edge1->x;
            word *ptr = scrn + tx;
            int dx = edge2->x;
            long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

            for (int x = tx;x < dx; x++)
            {
                long  matval = dmatrix[x&3];
                int ws = (ts + matval) >> 19;

                if (ws > 31)
                    ws = 31;
                else if (ws < 0)
                    ws = 0;

                swork = stable[ws];
                dwork = *ptr;

                work = salpha[(swork >> 10)] << 10;
                work += salpha[(swork >> 5) & 0x1f] << 5;
                work += salpha[swork & 0x1f];

                work += dalpha[(dwork >> 10)] << 10;
                work += dalpha[(dwork >> 5) & 0x1f] << 5;
                work += dalpha[dwork & 0x1f];

                *ptr = work;

                ptr++;
                ts += sstep_dx1;
            }
            scrn += pitch;
            edge1++;
            edge2++;
        }
    }
    else
    {
        for (long y=0;y <= count;y++)
        {
            long ts = edge1->shade;

            long tx = edge1->x;
            word *ptr = scrn + tx;
            int dx = edge2->x;
            long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

            for (int x = tx;x < dx; x++)
            {
                long  matval = dmatrix[x&3];
                int ws = (ts + matval) >> 19;

                if (ws > 31)
                    ws = 31;
                else if (ws < 0)
                    ws = 0;

                swork = stable[ws];
                dwork = *ptr;

                work = salpha[(swork >> 11)] << 11;
                work += salpha[(swork >> 6) & 0x1f] << 6;
                work += salpha[swork & 0x1f];

                work += dalpha[(dwork >> 11)] << 11;
                work += dalpha[(dwork >> 6) & 0x1f] << 6;
                work += dalpha[dwork & 0x1f];

                *ptr = work;

                ptr++;
                ts += sstep_dx1;
            }
            scrn += pitch;
            edge1++;
            edge2++;
        }
    }
}

extern "C" void vngo_tahlines16 (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[tri->color];
    word             clr = tc->shl[tri->left_edge->shade >> 19];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;

    word            *scrn = (word*)tri->sptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    word            work;
    word            dwork;
    byte            *salpha = &VgSystem->alpha_table[(tri->alpha) << 5];
    byte            *dalpha = &VgSystem->alpha_table[( 255 - tri->alpha) << 5];

    if (tri->vbuff->pal->flags & VNGO_15BIT)
    {
        for (long y=0;y <= count;y++)
        {
            long tx = edge1->x;
            word *ptr = scrn + tx;
            int dx = edge2->x;

            for (int x = tx;x < dx; x++)
            {
                dwork = *ptr;

                work = salpha[(clr >> 10)] << 10;
                work += salpha[(clr >> 5) & 0x1f] << 5;
                work += salpha[clr & 0x1f];

                work += dalpha[(dwork >> 10)] << 10;
                work += dalpha[(dwork >> 5) & 0x1f] << 5;
                work += dalpha[dwork & 0x1f];

                *ptr = work;
                ptr++;
            }
            scrn += pitch;
            edge1++;
            edge2++;
        }
    }
    else
    {
        for (long y=0;y <= count;y++)
        {
            long tx = edge1->x;
            word *ptr = scrn + tx;
            int dx = edge2->x;

            for (int x = tx;x < dx; x++)
            {
                dwork = *ptr;

                work = salpha[(clr >> 11)] << 11;
                work += salpha[(clr >> 6) & 0x1f] << 6;
                work += salpha[clr & 0x1f];

                work += dalpha[(dwork >> 11)] << 11;
                work += dalpha[(dwork >> 6) & 0x1f] << 6;
                work += dalpha[dwork & 0x1f];

                *ptr = work;
                ptr++;
            }
            scrn += pitch;
            edge1++;
            edge2++;
        }
    }
}




// Zbuffered stuff.

extern "C" void vngo_tazghlines16 (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[tri->color];
    word             *stable = &tc->shl[0];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;
    long            zpitch = tri->zpitch >> 1;

    long            zstep_dx1 = tri->zstep_dx1;
    long            sstep_dx1 = tri->sstep_dx1;

    word            *scrn = (word*)tri->sptr;
    word            *zbuff = (word*)tri->zptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    word            work;
    word            swork;
    word            dwork;
    byte            *salpha = &VgSystem->alpha_table[(tri->alpha) << 5];
    byte            *dalpha = &VgSystem->alpha_table[( 255 - tri->alpha) << 5];

    if (tri->vbuff->pal->flags & VNGO_15BIT)
    {
        for (long y=0;y <= count;y++)
        {
            long tz = edge1->z;
            long ts = edge1->shade;

            long tx = edge1->x;
            word *ptr = scrn + tx;
            word *zptr = zbuff + tx;
            int  dx = edge2->x;
            long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

            for (int x = tx;x < dx; x++)
            {
                word wz = word(tz >> 15);
                if (wz < *zptr)
                {
                    *zptr = wz;
                    int ws = (ts + dmatrix[x&3]) >> 19;

                    if (ws > 31)
                        ws = 31;
                    else if (ws < 0)
                        ws = 0;

                    swork = stable[ws];
                    dwork = *ptr;

                    work = salpha[(swork >> 10)] << 10;
                    work += salpha[(swork >> 5) & 0x1f] << 5;
                    work += salpha[swork & 0x1f];

                    work += dalpha[(dwork >> 10)] << 10;
                    work += dalpha[(dwork >> 5) & 0x1f] << 5;
                    work += dalpha[dwork & 0x1f];

                    *ptr = work;
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
    else
    {
        for (long y=0;y <= count;y++)
        {
            long tz = edge1->z;
            long ts = edge1->shade;

            long tx = edge1->x;
            word *ptr = scrn + tx;
            word *zptr = zbuff + tx;
            int  dx = edge2->x;
            long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

            for (int x = tx;x < dx; x++)
            {
                word wz = word(tz >> 15);
                if (wz < *zptr)
                {
                    *zptr = wz;
                    int ws = (ts + dmatrix[x&3]) >> 19;

                    if (ws > 31)
                        ws = 31;
                    else if (ws < 0)
                        ws = 0;

                    swork = stable[ws];
                    dwork = *ptr;

                    work = salpha[(swork >> 11)] << 11;
                    work += salpha[(swork >> 6) & 0x1f] << 6;
                    work += salpha[swork & 0x1f];

                    work += dalpha[(dwork >> 11)] << 11;
                    work += dalpha[(dwork >> 6) & 0x1f] << 6;
                    work += dalpha[dwork & 0x1f];

                    *ptr = work;
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
}





extern "C" void vngo_tazhlines16 (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[tri->color];
    word             clr = tc->shl[tri->left_edge->shade >> 19];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;
    long            zpitch = tri->zpitch >> 1;
    long            zstep_dx1 = tri->zstep_dx1;

    word            *scrn = (word*)tri->sptr;
    word            *zbuff = (word*)tri->zptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    word            work;
    word            dwork;
    byte            *salpha = &VgSystem->alpha_table[(tri->alpha) << 5];
    byte            *dalpha = &VgSystem->alpha_table[( 255 - tri->alpha) << 5];

    if (tri->vbuff->pal->flags & VNGO_15BIT)
    {
        for (long y=0;y <= count;y++)
        {
            long tx = edge1->x;
            long tz = edge1->z;
            word *ptr = scrn + tx;
            word *zptr = zbuff + tx;
            int dx = edge2->x;

            for (int x = tx;x < dx; x++)
            {
                word wz = word(tz >> 15);
                if (wz < *zptr)
                {
                    *zptr = wz;

                    dwork = *ptr;

                    work = salpha[(clr >> 10)] << 10;
                    work += salpha[(clr >> 5) & 0x1f] << 5;
                    work += salpha[clr & 0x1f];

                    work += dalpha[(dwork >> 10)] << 10;
                    work += dalpha[(dwork >> 5) & 0x1f] << 5;
                    work += dalpha[dwork & 0x1f];

                    *ptr = work;
                }

                ptr++;
                zptr++;
                tz += zstep_dx1;
            }
            scrn += pitch;
            zbuff += zpitch;
            edge1++;
            edge2++;
        }
    }
    else
    {
        for (long y=0;y <= count;y++)
        {
            long tx = edge1->x;
            long tz = edge1->z;
            word *ptr = scrn + tx;
            word *zptr = zbuff + tx;
            int dx = edge2->x;

            for (int x = tx;x < dx; x++)
            {
                word wz = word(tz >> 15);
                if (wz < *zptr)
                {
                    *zptr = wz;

                    dwork = *ptr;

                    work = salpha[(clr >> 11)] << 11;
                    work += salpha[(clr >> 6) & 0x1f] << 6;
                    work += salpha[clr & 0x1f];

                    work += dalpha[(dwork >> 11)] << 11;
                    work += dalpha[(dwork >> 6) & 0x1f] << 6;
                    work += dalpha[dwork & 0x1f];

                    *ptr = work;
                }

                ptr++;
                zptr++;
                tz += zstep_dx1;
            }
            scrn += pitch;
            zbuff += zpitch;
            edge1++;
            edge2++;
        }
    }
}

