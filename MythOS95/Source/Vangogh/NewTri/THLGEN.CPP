//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
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
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// Created by Tim Little
//
// thline128.cpp
//
//     The 128x128 texture mapping horizontal scan line code.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"
#include <math.h>

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�


//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

extern long DitherMatrix[4][4];

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�


// Gouraud shaded texturemappers.


extern "C" void vngo_lghlines16_ntrans_filtered (VngoTriangle *tri)
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
        long ts = edge1->shade;
        long tu = edge1->u << uup;
        long tv = edge1->v << vup;

        long tx = edge1->x;
        word *ptr = scrn + tx;
        int dx = edge2->x;
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

        for (int x = tx;x < dx; x++)
        {
            long  matval = dmatrix[x&3];
            int ws = (ts + matval) >> 19;
            long matvalv = matval << (vup - 3);
            matval = matval << (uup - 3);
            clr = tptr[(((dword)(tv + matvalv) >> vdown) & mask)
                      + ((dword)(tu + matval) >> udown)];

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

extern "C" void vngo_lghlines16_ntrans (VngoTriangle *tri)
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
        long ts = edge1->shade;
        long tu = edge1->u << uup;
        long tv = edge1->v << vup;

        long tx = edge1->x;
        word *ptr = scrn + tx;
        int dx = edge2->x;
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

        for (int x = tx;x < dx; x++)
        {
            int ws = (ts + dmatrix[x&3]) >> 19;
            clr = tptr[(((dword)(tv) >> vdown) & mask)
                      + ((dword)(tu) >> udown)];

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




extern "C" void vngo_lghlines16_trans_filtered (VngoTriangle *tri)
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
        long ts = edge1->shade;
        long tu = edge1->u << uup;
        long tv = edge1->v << vup;

        long tx = edge1->x;
        word *ptr = scrn + tx;
        int dx = edge2->x;
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

        for (int x = tx;x < dx; x++)
        {
            long  matval = dmatrix[x&3];
            int ws = (ts + matval) >> 19;

            long matvalv = matval << (vup - 3);
            matval = matval << (uup - 3);
            clr = tptr[(((dword)(tv + matvalv) >> vdown) & mask)
                      + ((dword)(tu + matval) >> udown)];

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

extern "C" void vngo_lghlines16_trans (VngoTriangle *tri)
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
        long ts = edge1->shade;
        long tu = edge1->u << uup;
        long tv = edge1->v << vup;

        long tx = edge1->x;
        word *ptr = scrn + tx;
        int dx = edge2->x;
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

        for (int x = tx;x < dx; x++)
        {
            int ws = (ts + dmatrix[x&3]) >> 19;
            clr = tptr[(((dword)(tv) >> vdown) & mask)
                      + ((dword)(tu) >> udown)];

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

extern "C" void vngo_lhlines16_ntrans_filtered (VngoTriangle *tri)
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

        long tx = edge1->x;
        word *ptr = scrn + tx;
        int dx = edge2->x;
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

        for (int x = tx;x < dx; x++)
        {
            long  matval = dmatrix[x&3];
            long  matvalv = matval << (vup-3);
            matval = matval << (uup-3);

            clr = tptr[(((dword)(tv + matvalv) >> vdown) & mask)
                      + ((dword)(tu + matval) >> udown)];

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



extern "C" void vngo_lhlines16_ntrans (VngoTriangle *tri)
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

        long tx = edge1->x;
        word *ptr = scrn + tx;
        int dx = edge2->x;

        for (int x = tx;x < dx; x++)
        {

            clr = tptr[(((dword)(tv) >> vdown) & mask)
                      + ((dword)(tu) >> udown)];

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

extern "C" void vngo_lhlines16_trans_filtered (VngoTriangle *tri)
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

        long tx = edge1->x;
        word *ptr = scrn + tx;
        int dx = edge2->x;
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];

        for (int x = tx;x < dx; x++)
        {
            long  matval = dmatrix[x&3];
            long  matvalv = matval << (vup-3);
            matval = matval << (uup-3);

            clr = tptr[(((dword)(tv + matvalv) >> vdown) & mask)
                      + ((dword)(tu + matval) >> udown)];

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



extern "C" void vngo_lhlines16_trans (VngoTriangle *tri)
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

        long tx = edge1->x;
        word *ptr = scrn + tx;
        int dx = edge2->x;

        for (int x = tx;x < dx; x++)
        {

            clr = tptr[(((dword)(tv) >> vdown) & mask)
                      + ((dword)(tu) >> udown)];

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


extern "C" void vngo_lzghlines16_ntrans_filtered (VngoTriangle *tri)
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
                long matvalv = matval << (vup-3);
                matval = matval << (uup-3);
                clr = tptr[(((dword)(tv + matvalv) >> vdown) & mask)
                          + ((dword)(tu + matval) >> udown)];

                if (ws > 31)
                    ws = 31;
                else if (ws < 0)
                    ws = 0;

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


extern "C" void vngo_lzghlines16_ntrans (VngoTriangle *tri)
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

                clr = tptr[(((dword)(tv) >> vdown) & mask)
                          + ((dword)(tu) >> udown)];

                if (ws > 31)
                    ws = 31;
                else if (ws < 0)
                    ws = 0;

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




extern "C" void vngo_lzghlines16_trans_filtered (VngoTriangle *tri)
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
                long matvalv = matval << (vup-3);
                matval = matval << (uup-3);
                clr = tptr[(((dword)(tv + matvalv) >> vdown) & mask)
                          + ((dword)(tu + matval) >> udown)];

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


extern "C" void vngo_lzghlines16_trans (VngoTriangle *tri)
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

                clr = tptr[(((dword)(tv) >> vdown) & mask)
                          + ((dword)(tu) >> udown)];

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

extern "C" void vngo_lzhlines16_ntrans_filtered (VngoTriangle *tri)
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
                long  matvalv = matval << (vup-3);
                matval = matval << (uup-3);

                clr = tptr[(((dword)(tv + matvalv) >> vdown) & mask)
                          + ((dword)(tu + matval) >> udown)];

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


extern "C" void vngo_lzhlines16_ntrans (VngoTriangle *tri)
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

                clr = tptr[(((dword)(tv) >> vdown) & mask)
                          + ((dword)(tu) >> udown)];

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


extern "C" void vngo_lzhlines16_trans_filtered (VngoTriangle *tri)
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
                long  matvalv = matval << (vup-3);
                matval = matval << (uup-3);
                clr = tptr[(((dword)(tv + matvalv) >> vdown) & mask)
                          + ((dword)(tu + matval) >> udown)];

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

extern "C" void vngo_lzhlines16_trans (VngoTriangle *tri)
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

                clr = tptr[(((dword)(tv) >> vdown) & mask)
                          + ((dword)(tu) >> udown)];

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



extern "C" void vngo_lghlines16_filtered(VngoTriangle *tri)
{
    if (tri->tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT)
        vngo_lghlines16_trans_filtered(tri);
    else
        vngo_lghlines16_ntrans_filtered(tri);
}

extern "C" void vngo_lghlines16(VngoTriangle *tri)
{
    if (tri->tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT)
        vngo_lghlines16_trans(tri);
    else
        vngo_lghlines16_ntrans(tri);
}

extern "C" void vngo_lzghlines16_filtered(VngoTriangle *tri)
{
    if (tri->tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT)
        vngo_lzghlines16_trans_filtered(tri);
    else
        vngo_lzghlines16_ntrans_filtered(tri);
}

extern "C" void vngo_lzghlines16(VngoTriangle *tri)
{
    if (tri->tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT)
        vngo_lzghlines16_trans(tri);
    else
        vngo_lzghlines16_ntrans(tri);
}

extern "C" void vngo_lhlines16_filtered(VngoTriangle *tri)
{
    if (tri->tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT)
        vngo_lhlines16_trans_filtered(tri);
    else
        vngo_lhlines16_ntrans_filtered(tri);
}

extern "C" void vngo_lhlines16(VngoTriangle *tri)
{
    if (tri->tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT)
        vngo_lhlines16_trans(tri);
    else
        vngo_lhlines16_ntrans(tri);
}

extern "C" void vngo_lzhlines16_filtered(VngoTriangle *tri)
{
    if (tri->tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT)
        vngo_lzhlines16_trans_filtered(tri);
    else
        vngo_lzhlines16_ntrans_filtered(tri);
}

extern "C" void vngo_lzhlines16(VngoTriangle *tri)
{
    if (tri->tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT)
        vngo_lzhlines16_trans(tri);
    else
        vngo_lzhlines16_ntrans(tri);
}


