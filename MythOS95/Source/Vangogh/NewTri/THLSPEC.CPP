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
// thlspec.cpp
//
//     The UxV texture mapping horizontal scan line code.
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
#include "thlspec.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define U_UP                    (16-WIDTH_SHIFT)
#define V_UP                    (16-HEIGHT_SHIFT)
#define U_DITHER                (U_UP - 3)
#define V_DITHER                (V_UP - 3)
#define UDOWN                   (32 - WIDTH_SHIFT)
#define VDOWN                   ((32-HEIGHT_SHIFT) - WIDTH_SHIFT)
#define MASK                    (~(( 1 << WIDTH_SHIFT) - 1))

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


// Gouraud shaded texturemappers.


extern "C" void LGH16_NTRANS_FILTERED (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[0];
    word             *stable = &tc->shl[0];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;

    long            sstep_dx1 = tri->sstep_dx1;
    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;

    word            *scrn = (word*)tri->sptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long ts = edge1->shade;
        long tu = edge1->u << U_UP;
        long tv = edge1->v << V_UP;

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

            clr = tptr[(((dword)(tv + (matval << V_DITHER)) >> VDOWN) & MASK)
                      + ((dword)(tu + (matval << U_DITHER)) >> UDOWN)];

            *ptr = stable[(clr << 5) + ws];

            ptr++;
            ts += sstep_dx1;
            tu += ustep_dx1;
            tv += vstep_dx1;
        }
        scrn += pitch;
        edge1++;
        edge2++;
    }
}

extern "C" void LGH16_NTRANS (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[0];
    word             *stable = &tc->shl[0];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;

    long            sstep_dx1 = tri->sstep_dx1;
    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;

    word            *scrn = (word*)tri->sptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long ts = edge1->shade;
        long tu = edge1->u << U_UP;
        long tv = edge1->v << V_UP;

        long tx = edge1->x;
        word *ptr = scrn + tx;
        int dx = edge2->x;
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

        for (int x = tx;x < dx; x++)
        {
            int ws = (ts + dmatrix[x&3]) >> 19;
            clr = tptr[(((dword)(tv) >> VDOWN) & MASK)
                      + ((dword)(tu) >> UDOWN)];

            if (ws > 31)
                ws = 31;
            else if (ws < 0)
                ws = 0;

            *ptr = stable[(clr << 5) + ws];

            ptr++;
            ts += sstep_dx1;
            tu += ustep_dx1;
            tv += vstep_dx1;
        }
        scrn += pitch;
        edge1++;
        edge2++;
    }
}




extern "C" void LGH16_TRANS_FILTERED (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[0];
    word             *stable = &tc->shl[0];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;

    long            sstep_dx1 = tri->sstep_dx1;
    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;

    word            *scrn = (word*)tri->sptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long ts = edge1->shade;
        long tu = edge1->u << U_UP;
        long tv = edge1->v << V_UP;

        long tx = edge1->x;
        word *ptr = scrn + tx;
        int dx = edge2->x;
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

        for (int x = tx;x < dx; x++)
        {
            long  matval = dmatrix[x&3];
            int ws = (ts + matval) >> 19;
            clr = tptr[(((dword)(tv + (matval << V_DITHER)) >> VDOWN) & MASK)
                      + ((dword)(tu + (matval << U_DITHER)) >> UDOWN)];

            if (clr != 255)
            {
                if (ws > 31)
                    ws = 31;
                else if (ws < 0)
                    ws = 0;
                *ptr = stable[(clr << 5) + ws];
            }

            ptr++;
            ts += sstep_dx1;
            tu += ustep_dx1;
            tv += vstep_dx1;
        }
        scrn += pitch;
        edge1++;
        edge2++;
    }
}

extern "C" void LGH16_TRANS (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[0];
    word             *stable = &tc->shl[0];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;

    long            sstep_dx1 = tri->sstep_dx1;
    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;

    word            *scrn = (word*)tri->sptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long ts = edge1->shade;
        long tu = edge1->u << U_UP;
        long tv = edge1->v << V_UP;

        long tx = edge1->x;
        word *ptr = scrn + tx;
        int dx = edge2->x;
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

        for (int x = tx;x < dx; x++)
        {
            int ws = (ts + dmatrix[x&3]) >> 19;
            clr = tptr[(((dword)(tv) >> VDOWN) & MASK)
                      + ((dword)(tu) >> UDOWN)];

            if (clr != 255)
            {
                if (ws > 31)
                    ws = 31;
                else if (ws < 0)
                    ws = 0;

                *ptr = stable[(clr << 5) + ws];
            }

            ptr++;
            ts += sstep_dx1;
            tu += ustep_dx1;
            tv += vstep_dx1;
        }
        scrn += pitch;
        edge1++;
        edge2++;
    }
}



// Flat shaded texture mappers.

extern "C" void LH16_NTRANS_FILTERED (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[0];
    word             *stable = &tc->shl[tri->left_edge->shade >> 19];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;

    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;

    word            *scrn = (word*)tri->sptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long tu = edge1->u << U_UP;
        long tv = edge1->v << V_UP;

        long tx = edge1->x;
        word *ptr = scrn + tx;
        int dx = edge2->x;
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

        for (int x = tx;x < dx; x++)
        {
            long  matval = dmatrix[x&3];

            clr = tptr[(((dword)(tv + (matval << V_DITHER)) >> VDOWN) & MASK)
                      + ((dword)(tu + (matval << V_DITHER)) >> UDOWN)];

            *ptr = stable[clr << 5];
            ptr++;
            tu += ustep_dx1;
            tv += vstep_dx1;
        }
        scrn += pitch;
        edge1++;
        edge2++;
    }
}



extern "C" void LH16_NTRANS (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[0];
    word             *stable = &tc->shl[tri->left_edge->shade >> 19];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;

    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;

    word            *scrn = (word*)tri->sptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long tu = edge1->u << U_UP;
        long tv = edge1->v << V_UP;

        long tx = edge1->x;
        word *ptr = scrn + tx;
        int dx = edge2->x;

        for (int x = tx;x < dx; x++)
        {

            clr = tptr[(((dword)(tv) >> VDOWN) & MASK)
                      + ((dword)(tu) >> UDOWN)];

            *ptr = stable[clr << 5];
            ptr++;
            tu += ustep_dx1;
            tv += vstep_dx1;
        }
        scrn += pitch;
        edge1++;
        edge2++;
    }
}

extern "C" void LH16_TRANS_FILTERED (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[0];
    word             *stable = &tc->shl[tri->left_edge->shade >> 19];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;

    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;

    word            *scrn = (word*)tri->sptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long tu = edge1->u << U_UP;
        long tv = edge1->v << V_UP;

        long tx = edge1->x;
        word *ptr = scrn + tx;
        int dx = edge2->x;
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

        for (int x = tx;x < dx; x++)
        {
            long  matval = dmatrix[x&3];

            clr = tptr[(((dword)(tv + (matval << V_DITHER)) >> VDOWN) & MASK)
                      + ((dword)(tu + (matval << U_DITHER)) >> UDOWN)];

            if (clr != 255)
            {
                *ptr = stable[clr << 5];
            }
            ptr++;
            tu += ustep_dx1;
            tv += vstep_dx1;
        }
        scrn += pitch;
        edge1++;
        edge2++;
    }
}



extern "C" void LH16_TRANS (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[0];
    word             *stable = &tc->shl[tri->left_edge->shade >> 19];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;

    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;

    word            *scrn = (word*)tri->sptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long tu = edge1->u << U_UP;
        long tv = edge1->v << V_UP;

        long tx = edge1->x;
        word *ptr = scrn + tx;
        int dx = edge2->x;

        for (int x = tx;x < dx; x++)
        {

            clr = tptr[(((dword)(tv) >> VDOWN) & MASK)
                      + ((dword)(tu) >> UDOWN)];

            if (clr != 255)
            {
                *ptr = stable[clr << 5];
            }
            ptr++;
            tu += ustep_dx1;
            tv += vstep_dx1;
        }
        scrn += pitch;
        edge1++;
        edge2++;
    }
}

// Zbuffered stuff.


extern "C" void LZGH16_NTRANS_FILTERED (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[0];
    word             *stable = &tc->shl[0];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;
    long            zpitch = tri->zpitch >> 1;

    long            zstep_dx1 = tri->zstep_dx1;
    long            sstep_dx1 = tri->sstep_dx1;
    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;

    word            *scrn = (word*)tri->sptr;
    word            *zbuff = (word*)tri->zptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long tz = edge1->z;
        long ts = edge1->shade;
        long tu = edge1->u << U_UP;
        long tv = edge1->v << V_UP;

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
                long  matval = dmatrix[x&3];
                int ws = (ts + matval) >> 19;

                if (ws > 31)
                    ws = 31;
                else if (ws < 0)
                    ws = 0;

                clr = tptr[(((dword)(tv + (matval << V_DITHER)) >> VDOWN) & MASK)
                          + ((dword)(tu + (matval << U_DITHER)) >> UDOWN)];

                *ptr = stable[(clr << 5) + ws];
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


extern "C" void LZGH16_NTRANS (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[0];
    word             *stable = &tc->shl[0];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;
    long            zpitch = tri->zpitch >> 1;

    long            zstep_dx1 = tri->zstep_dx1;
    long            sstep_dx1 = tri->sstep_dx1;
    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;

    word            *scrn = (word*)tri->sptr;
    word            *zbuff = (word*)tri->zptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long tz = edge1->z;
        long ts = edge1->shade;
        long tu = edge1->u << U_UP;
        long tv = edge1->v << V_UP;

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

                clr = tptr[(((dword)(tv) >> VDOWN) & MASK)
                          + ((dword)(tu) >> UDOWN)];

                *ptr = stable[(clr << 5) + ws];
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




extern "C" void LZGH16_TRANS_FILTERED (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[0];
    word             *stable = &tc->shl[0];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;
    long            zpitch = tri->zpitch >> 1;

    long            zstep_dx1 = tri->zstep_dx1;
    long            sstep_dx1 = tri->sstep_dx1;
    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;

    word            *scrn = (word*)tri->sptr;
    word            *zbuff = (word*)tri->zptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long tz = edge1->z;
        long ts = edge1->shade;
        long tu = edge1->u << U_UP;
        long tv = edge1->v << V_UP;

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
                long  matval = dmatrix[x&3];
                int ws = (ts + matval) >> 19;

                clr = tptr[(((dword)(tv + (matval << V_DITHER)) >> VDOWN) & MASK)
                          + ((dword)(tu + (matval << U_DITHER)) >> UDOWN)];

                if (clr != 255)
                {
                    if (ws > 31)
                        ws = 31;
                    else if (ws < 0)
                        ws = 0;
                    *ptr = stable[(clr << 5) + ws];
                    *zptr = wz;
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


extern "C" void LZGH16_TRANS (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[0];
    word             *stable = &tc->shl[0];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;
    long            zpitch = tri->zpitch >> 1;

    long            zstep_dx1 = tri->zstep_dx1;
    long            sstep_dx1 = tri->sstep_dx1;
    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;

    word            *scrn = (word*)tri->sptr;
    word            *zbuff = (word*)tri->zptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long tz = edge1->z;
        long ts = edge1->shade;
        long tu = edge1->u << U_UP;
        long tv = edge1->v << V_UP;

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
                int ws = (ts + dmatrix[x&3]) >> 19;

                clr = tptr[(((dword)(tv) >> VDOWN) & MASK)
                          + ((dword)(tu) >> UDOWN)];

                if (clr != 255)
                {
                    if (ws > 31)
                        ws = 31;
                    else if (ws < 0)
                        ws = 0;
                    *ptr = stable[(clr << 5) + ws];
                    *zptr = wz;
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




// Flat shaded

extern "C" void LZH16_NTRANS_FILTERED (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[0];
    word             *stable = &tc->shl[tri->left_edge->shade >> 19];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;
    long            zpitch = tri->zpitch >> 1;

    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;
    long            zstep_dx1 = tri->zstep_dx1;

    word            *scrn = (word*)tri->sptr;
    word            *zbuff = (word*)tri->zptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long tu = edge1->u << U_UP;
        long tv = edge1->v << V_UP;
        long tz = edge1->z;

        long tx = edge1->x;
        word *ptr = scrn + tx;
        word *zptr = zbuff + tx;
        int dx = edge2->x;
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

        for (int x = tx;x < dx; x++)
        {
            word wz = word(tz >> 15);
            if (wz < *zptr)
            {
                *zptr = wz;

                long  matval = dmatrix[x&3];
                clr = tptr[(((dword)(tv + (matval << V_DITHER)) >> VDOWN) & MASK)
                          + ((dword)(tu + (matval << U_DITHER)) >> UDOWN)];

                *ptr = stable[clr << 5];
            }

            ptr++;
            zptr++;
            tz += zstep_dx1;
            tu += ustep_dx1;
            tv += vstep_dx1;
        }
        scrn += pitch;
        zbuff += zpitch;
        edge1++;
        edge2++;
    }
}


extern "C" void LZH16_NTRANS (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[0];
    word             *stable = &tc->shl[tri->left_edge->shade >> 19];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;
    long            zpitch = tri->zpitch >> 1;

    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;
    long            zstep_dx1 = tri->zstep_dx1;

    word            *scrn = (word*)tri->sptr;
    word            *zbuff = (word*)tri->zptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long tu = edge1->u << U_UP;
        long tv = edge1->v << V_UP;
        long tz = edge1->z;

        long tx = edge1->x;
        word *ptr = scrn + tx;
        word *zptr = zbuff + tx;
        int dx = edge2->x;

        for (int x = tx;x < dx; x++)
        {
            word wz = word(tz >> 15);
            if (wz < *zptr)
            {
                *zptr = wz;

                clr = tptr[(((dword)(tv) >> VDOWN) & MASK)
                          + ((dword)(tu) >> UDOWN)];

                *ptr = stable[clr << 5];
            }

            ptr++;
            zptr++;
            tz += zstep_dx1;
            tu += ustep_dx1;
            tv += vstep_dx1;
        }
        scrn += pitch;
        zbuff += zpitch;
        edge1++;
        edge2++;
    }
}


extern "C" void LZH16_TRANS_FILTERED (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[0];
    word             *stable = &tc->shl[tri->left_edge->shade >> 19];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;
    long            zpitch = tri->zpitch >> 1;

    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;
    long            zstep_dx1 = tri->zstep_dx1;

    word            *scrn = (word*)tri->sptr;
    word            *zbuff = (word*)tri->zptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long tu = edge1->u << U_UP;
        long tv = edge1->v << V_UP;
        long tz = edge1->z;

        long tx = edge1->x;
        word *ptr = scrn + tx;
        word *zptr = zbuff + tx;
        int dx = edge2->x;
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

        for (int x = tx;x < dx; x++)
        {
            word wz = word(tz >> 15);
            if (wz < *zptr)
            {
                long  matval = dmatrix[x&3];
                clr = tptr[(((dword)(tv + (matval << V_DITHER)) >> VDOWN) & MASK)
                          + ((dword)(tu + (matval << U_DITHER)) >> UDOWN)];

                if (clr != 255)
                {
                    *ptr = stable[clr << 5];
                    *zptr = wz;
                }
            }

            ptr++;
            zptr++;
            tz += zstep_dx1;
            tu += ustep_dx1;
            tv += vstep_dx1;
        }
        scrn += pitch;
        zbuff += zpitch;
        edge1++;
        edge2++;
    }
}

extern "C" void LZH16_TRANS (VngoTriangle *tri)
{
    VngoShadePal16   *tp = (VngoShadePal16 *)tri->vbuff->pal->shd_pal;
    VngoColorShade16 *tc = &(*tp)[0];
    word             *stable = &tc->shl[tri->left_edge->shade >> 19];

    long            count = tri->height;
    long            pitch = tri->pitch >> 1;
    long            zpitch = tri->zpitch >> 1;

    long            ustep_dx1 = tri->ustep_dx1;
    long            vstep_dx1 = tri->vstep_dx1;
    long            zstep_dx1 = tri->zstep_dx1;

    word            *scrn = (word*)tri->sptr;
    word            *zbuff = (word*)tri->zptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long tu = edge1->u << U_UP;
        long tv = edge1->v << V_UP;
        long tz = edge1->z;

        long tx = edge1->x;
        word *ptr = scrn + tx;
        word *zptr = zbuff + tx;
        int dx = edge2->x;

        for (int x = tx;x < dx; x++)
        {
            word wz = word(tz >> 15);
            if (wz < *zptr)
            {

                clr = tptr[(((dword)(tv) >> VDOWN) & MASK)
                          + ((dword)(tu) >> UDOWN)];

                if (clr != 255)
                {
                    *ptr = stable[clr << 5];
                    *zptr = wz;
                }
            }

            ptr++;
            zptr++;
            tz += zstep_dx1;
            tu += ustep_dx1;
            tv += vstep_dx1;
        }
        scrn += pitch;
        zbuff += zpitch;
        edge1++;
        edge2++;
    }
}



extern "C" void LGH16_FILTERED (VngoTriangle *tri)
{
    if (tri->tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT)
        LGH16_TRANS_FILTERED(tri);
    else
        LGH16_NTRANS_FILTERED(tri);
}

extern "C" void LGH16 (VngoTriangle *tri)
{
    if (tri->tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT)
        LGH16_TRANS(tri);
    else
        LGH16_NTRANS(tri);
}

extern "C" void LZGH16_FILTERED (VngoTriangle *tri)
{
    if (tri->tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT)
        LZGH16_TRANS_FILTERED(tri);
    else
        LZGH16_NTRANS_FILTERED(tri);
}

extern "C" void LZGH16 (VngoTriangle *tri)
{
    if (tri->tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT)
        LZGH16_TRANS(tri);
    else
        LZGH16_NTRANS(tri);
}

extern "C" void LH16_FILTERED (VngoTriangle *tri)
{
    if (tri->tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT)
        LH16_TRANS_FILTERED(tri);
    else
        LH16_NTRANS_FILTERED(tri);
}

extern "C" void LH16 (VngoTriangle *tri)
{
    if (tri->tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT)
        LH16_TRANS(tri);
    else
        LH16_NTRANS(tri);
}

extern "C" void LZH16_FILTERED (VngoTriangle *tri)
{
    if (tri->tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT)
        LZH16_TRANS_FILTERED(tri);
    else
        LZH16_NTRANS_FILTERED(tri);
}

extern "C" void LZH16 (VngoTriangle *tri)
{
    if (tri->tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT)
        LZH16_TRANS(tri);
    else
        LZH16_NTRANS(tri);
}


