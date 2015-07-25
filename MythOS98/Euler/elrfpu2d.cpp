//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
// _________________________________________________________________________
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// |       1       2       3       4       5       6       7       8       9
// |                                                                       |
// |              E U L E R:   Math and Computation Library                |
// |_______________________________________________________________________|
//
//                      Microsoft Windows 95/NT Version
//
//               Copyright (c) 1998 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
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
// Created by Chuck Walbourn
//
// elrfpu2d.cpp
//
// Contains the C-callable math helper routines for 2D data types implemented
// using standard FPU instructions.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "euler.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_transform2d
//
// Transforms a 2D point by a 2D matrix with an implicit w value of 1 in
// the point.  If 'hn' is set, then the matrix is assumed to have [0 0 1] in
// the last column.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void elr_fpu_transform2d(const ElrPoint2D *p,
                                    const ElrMatrix2D *m, ElrPoint2DW *d,
                                    int hn)
{
    assertMyth("elr_fpu_transform2d() needs valid input",
               p != 0 && m != 0 && d != 0);

//ÄÄÄ Check for common case of hnormalized matrix
    if (hn
        || (m->mtx[ELR_MTX2D_C] == 0.0f
            && m->mtx[ELR_MTX2D_H] == 0.0f
            && m->mtx[ELR_MTX2D_I] == 1.0f))
    {
        //           [A B 0]   [ Ax+Dy+G ]
        // [x y 1] * [D E 0] = [ Bx+Ey+H ]
        //           [G H 1]   [    1    ]

        d->x = m->mtx[ELR_MTX2D_A]*p->x
               + m->mtx[ELR_MTX2D_D]*p->y
               + m->mtx[ELR_MTX2D_G];

        d->y = m->mtx[ELR_MTX2D_B]*p->x
               + m->mtx[ELR_MTX2D_E]*p->y
               + m->mtx[ELR_MTX2D_H];

        d->w = 1.0f;
    }
//ÄÄÄ General case
    else
    {
        //           [A B C]   [ Ax+Dy+G ]
        // [x y 1] * [D E F] = [ Bx+Ey+H ]
        //           [G H I]   [ Cx+Fy+I ]

        d->x = m->mtx[ELR_MTX2D_A]*p->x
               + m->mtx[ELR_MTX2D_D]*p->y
               + m->mtx[ELR_MTX2D_G];

        d->y = m->mtx[ELR_MTX2D_B]*p->x
               + m->mtx[ELR_MTX2D_E]*p->y
               + m->mtx[ELR_MTX2D_H];

        d->w = m->mtx[ELR_MTX2D_C]*p->x
               + m->mtx[ELR_MTX2D_F]*p->y
               + m->mtx[ELR_MTX2D_I];
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_transform2dw
//
// Transforms a 2D point by a 2D matrix.  If 'hn' is set, then the matrix is
// assumed to have [0 0 1] in the last column.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void elr_fpu_transform2dw(const ElrPoint2DW *p,
                                     const ElrMatrix2D *m, ElrPoint2DW *d,
                                     int hn)
{
    assertMyth("elr_fpu_transform2dw() needs valid input",
                p != 0 && m != 0 && d != 0);

    float nx, ny, nw;

//ÄÄÄ Check for common case of hnormalized matrix
    if (hn
        || (m->mtx[ELR_MTX2D_C] == 0.0f
            && m->mtx[ELR_MTX2D_H] == 0.0f
            && m->mtx[ELR_MTX2D_I] == 1.0f))
    {
        //           [A B 0]   [ Ax+Dy+Gw ]
        // [x y w] * [D E 0] = [ Bx+Ey+Hw ]
        //           [G H 1]   [    w     ]

        nx = m->mtx[ELR_MTX2D_A]*p->x
             + m->mtx[ELR_MTX2D_D]*p->y
             + m->mtx[ELR_MTX2D_G]*p->w;

        ny = m->mtx[ELR_MTX2D_B]*p->x
             + m->mtx[ELR_MTX2D_E]*p->y
             + m->mtx[ELR_MTX2D_H]*p->w;

        nw = p->w;
    }
//ÄÄÄ General case
    else
    {
        //           [A B C]   [ Ax+Dy+Gw ]
        // [x y w] * [D E F] = [ Bx+Ey+Hw ]
        //           [G H I]   [ Cx+Fy+Iw ]

        nx = m->mtx[ELR_MTX2D_A]*p->x
             + m->mtx[ELR_MTX2D_D]*p->y
             + m->mtx[ELR_MTX2D_G]*p->w;

        ny = m->mtx[ELR_MTX2D_B]*p->x
             + m->mtx[ELR_MTX2D_E]*p->y
             + m->mtx[ELR_MTX2D_H]*p->w;

        nw = m->mtx[ELR_MTX2D_C]*p->x
             + m->mtx[ELR_MTX2D_F]*p->y
             + m->mtx[ELR_MTX2D_I]*p->w;
    }

    d->x = nx;
    d->y = ny;
    d->w = nw;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_transformv2d
//
// Transforms a 2D vector by a 2D matrix with an implicit w value of 1 in
// the vector.  If 'hn' is set, then the matrix is assumed to have [0 0 1] in
// the last column.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void elr_fpu_transformv2d(const ElrVector2D *v,
                                     const ElrMatrix2D *m, ElrVector2DW *d,
                                     int hn)
{
    assertMyth("elr_fpu_transformv2d() needs valid input",
               v != 0 && m != 0 && d != 0);

//ÄÄÄ Check for common case of hnormalized matrix
    if (hn
        || (m->mtx[ELR_MTX2D_C] == 0.0f
            && m->mtx[ELR_MTX2D_H] == 0.0f
            && m->mtx[ELR_MTX2D_I] == 1.0f))
    {
        //           [A B 0]   [ Ai+Dj ]
        // [i j 1] * [D E 0] = [ Bi+Ej ]
        //           [x x 1]   [   1   ]

        d->i = m->mtx[ELR_MTX2D_A]*v->i
               + m->mtx[ELR_MTX2D_D]*v->j;

        d->j = m->mtx[ELR_MTX2D_B]*v->i
               + m->mtx[ELR_MTX2D_E]*v->j;

        d->w = 1.0f;
    }
//ÄÄÄ General case
    else
    {
        //           [A B C]   [  Ai+Dj  ]
        // [i j 1] * [D E F] = [  Bi+Ej  ]
        //           [x x I]   [ Ci+Fj+I ]

        d->i = m->mtx[ELR_MTX2D_A]*v->i
               + m->mtx[ELR_MTX2D_D]*v->j;

        d->j = m->mtx[ELR_MTX2D_B]*v->i
               + m->mtx[ELR_MTX2D_E]*v->j;

        d->w = m->mtx[ELR_MTX2D_C]*v->i
               + m->mtx[ELR_MTX2D_F]*v->j
               + m->mtx[ELR_MTX2D_I];
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_transformv2dw
//
// Transforms a 2D vector by a 2D matrix.  If 'hn' is set, then the matrix is
// assumed to have [0 0 1] in the last column.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void elr_fpu_transformv2dw(const ElrVector2DW *v,
                                      const ElrMatrix2D *m, ElrVector2DW *d,
                                      int hn)
{
    assertMyth("elr_fpu_transformv2dw() needs valid input",
                v != 0 && m != 0 && d != 0);

    float ni, nj, nw;

//ÄÄÄ Check for common case of hnormalized matrix
    if (hn
        || (m->mtx[ELR_MTX2D_C] == 0.0f
            && m->mtx[ELR_MTX2D_H] == 0.0f
            && m->mtx[ELR_MTX2D_I] == 1.0f))
    {
        //           [A B 0]   [ Ai+Dj ]
        // [i j w] * [D E 0] = [ Bi+Ej ]
        //           [x x 1]   [   w   ]

        ni = m->mtx[ELR_MTX2D_A]*v->i
             + m->mtx[ELR_MTX2D_D]*v->j;

        nj = m->mtx[ELR_MTX2D_B]*v->i
             + m->mtx[ELR_MTX2D_E]*v->j;

        nw = v->w;
    }
//ÄÄÄ General case
    else
    {
        //           [A B C]   [   Ai+Dj  ]
        // [i j w] * [D E F] = [   Bi+Ej  ]
        //           [x x I]   [ Ci+Fj+Iw ]

        ni = m->mtx[ELR_MTX2D_A]*v->i
             + m->mtx[ELR_MTX2D_D]*v->j;

        nj = m->mtx[ELR_MTX2D_B]*v->i
             + m->mtx[ELR_MTX2D_E]*v->j;

        nw = m->mtx[ELR_MTX2D_C]*v->i
             + m->mtx[ELR_MTX2D_F]*v->j
             + m->mtx[ELR_MTX2D_I]*v->w;
    }

    d->i = ni;
    d->j = nj;
    d->w = nw;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_normalize2d
//
// Normalizes a 2D vector (there is a lower-bound on the valid size, so this
// will be a no-op in the case of an extremely short vector which might fail
// to result in an valid representation).
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void elr_fpu_normalize2d(ElrVector2D *v)
{
    assertMyth("elr_fpu_normalize2d() needs valid input", v != 0);

    float mag = elr_sqrt(v->i*v->i + v->j*v->j);

    if (mag >= 0.0001f)
    {
        v->i /= mag;
        v->j /= mag;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_hnormalize2d
//
// Normalizes/projects a vector in homogeneous space onto the w=1 plane
// (there is a lower-bound on the size of w since smaller values might
// result in invalid representation).
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void elr_fpu_hnormalize2d(ElrVector2DW *v)
{
    assertMyth("elr_fpu_hnormalize2d() needs valid input", v != 0);

    if (v->w == 1.0f)
        return;

    if (v->w > 0.0001f || v->w < -0.0001f)
    {
        v->i /= v->w;
        v->j /= v->w;
        v->w = 1.0f;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_contactmatrix2d
//
// Concacts/multiplies two 2D matricies.  If 'hn' is set, then both matricies
// are assumed to have [0 0 0 1] in the last column.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void elr_fpu_concatmatrix2d(const ElrMatrix2D *s,
                                       const ElrMatrix2D *m, ElrMatrix2D *d,
                                       int hn)
{
    assertMyth("elr_fpu_concatmatrix2d() needs valid input",
               s != 0 && m != 0 && d != 0);

    ElrMatrix2D mtx;

    if (s == d)
    {
        mtx = *s;
        s = &mtx;
    }

//ÄÄÄ Check for common case of two hnormalized matricies
    if (hn
        || (s->mtx[ELR_MTX2D_C] == 0.0f && s->mtx[ELR_MTX2D_F] == 0.0f
            && s->mtx[ELR_MTX2D_I] == 1.0f
            && m->mtx[ELR_MTX2D_C] == 0.0f && m->mtx[ELR_MTX2D_F] == 0.0f
            && m->mtx[ELR_MTX2D_I] == 1.0f))
    {
        // [A B 0]   [a b 0]   [Aa+Bd   Ab+Be   0]
        // [D E 0] * [d e 0] = [Da+Ed   Db+Ee   0]
        // [G H 1]   [g h 1]   [Ga+Hd+g Gb+He+h 1]

        // A' = Aa+Bd
        d->mtx[ELR_MTX2D_A] = s->mtx[ELR_MTX2D_A] * m->mtx[ELR_MTX2D_A]
                              + s->mtx[ELR_MTX2D_B] * m->mtx[ELR_MTX2D_D];

        // D' = Da+Ed
        d->mtx[ELR_MTX2D_D] = s->mtx[ELR_MTX2D_A] * m->mtx[ELR_MTX2D_A]
                              + s->mtx[ELR_MTX2D_B] * m->mtx[ELR_MTX2D_D];

        // G' = Ga+Hd+g
        d->mtx[ELR_MTX2D_G] = s->mtx[ELR_MTX2D_G] * m->mtx[ELR_MTX2D_A]
                              + s->mtx[ELR_MTX2D_H] * m->mtx[ELR_MTX2D_D]
                              + m->mtx[ELR_MTX2D_G];

        // B' = Ab+Be
        d->mtx[ELR_MTX2D_B] = s->mtx[ELR_MTX2D_A] * m->mtx[ELR_MTX2D_B]
                              + s->mtx[ELR_MTX2D_B] * m->mtx[ELR_MTX2D_E];

        // E' = Db+Ee
        d->mtx[ELR_MTX2D_E] = s->mtx[ELR_MTX2D_D] * m->mtx[ELR_MTX2D_B]
                              + s->mtx[ELR_MTX2D_E] * m->mtx[ELR_MTX2D_E];

        // H' = Gb+He+h
        d->mtx[ELR_MTX2D_H] = s->mtx[ELR_MTX2D_G] * m->mtx[ELR_MTX2D_B]
                              + s->mtx[ELR_MTX2D_H] * m->mtx[ELR_MTX2D_E]
                              + m->mtx[ELR_MTX2D_H];

        // [C' F' I'] = [0 0 1]
        d->mtx[ELR_MTX2D_C] =
        d->mtx[ELR_MTX2D_F] = 0.0f;
        d->mtx[ELR_MTX2D_I] = 1.0f;
    }
//ÄÄÄ General case
    else
    {
        // [A B C]   [a b c]   [Aa+Bd+Cg Ab+Be+Ch Ac+Bf+Ci]
        // [D E F] * [d e f] = [Da+Ed+Fg Db+Ee+Fh Dc+Ef+Fi]
        // [G H I]   [g h i]   [Ga+Hd+Ig Gb+He+Ih Gc+Hf+Ii]

        // A' = Aa+Bd+Cg
        d->mtx[ELR_MTX2D_A] = s->mtx[ELR_MTX2D_A] * m->mtx[ELR_MTX2D_A]
                              + s->mtx[ELR_MTX2D_B] * m->mtx[ELR_MTX2D_D]
                              + s->mtx[ELR_MTX2D_C] * m->mtx[ELR_MTX2D_G];

        // D' = Da+Ed+Fg
        d->mtx[ELR_MTX2D_D] = s->mtx[ELR_MTX2D_D] * m->mtx[ELR_MTX2D_A]
                              + s->mtx[ELR_MTX2D_E] * m->mtx[ELR_MTX2D_D]
                              + s->mtx[ELR_MTX2D_F] * m->mtx[ELR_MTX2D_G];

        // G' = Ga+Hd+Ig
        d->mtx[ELR_MTX2D_G] = s->mtx[ELR_MTX2D_G] * m->mtx[ELR_MTX2D_A]
                              + s->mtx[ELR_MTX2D_H] * m->mtx[ELR_MTX2D_D]
                              + s->mtx[ELR_MTX2D_I] * m->mtx[ELR_MTX2D_G];

        // B' = Ab+Be+Ch
        d->mtx[ELR_MTX2D_B] = s->mtx[ELR_MTX2D_A] * m->mtx[ELR_MTX2D_B]
                              + s->mtx[ELR_MTX2D_B] * m->mtx[ELR_MTX2D_E]
                              + s->mtx[ELR_MTX2D_C] * m->mtx[ELR_MTX2D_H];

        // E' = Db+Ee+Fh
        d->mtx[ELR_MTX2D_E] = s->mtx[ELR_MTX2D_D] * m->mtx[ELR_MTX2D_B]
                              + s->mtx[ELR_MTX2D_E] * m->mtx[ELR_MTX2D_E]
                              + s->mtx[ELR_MTX2D_F] * m->mtx[ELR_MTX2D_H];

        // H' = Gb+He+Ih
        d->mtx[ELR_MTX2D_H] = s->mtx[ELR_MTX2D_G] * m->mtx[ELR_MTX2D_B]
                              + s->mtx[ELR_MTX2D_H] * m->mtx[ELR_MTX2D_E]
                              + s->mtx[ELR_MTX2D_I] * m->mtx[ELR_MTX2D_H];

        // C' = Ac+Bf+Ci
        d->mtx[ELR_MTX2D_C] = s->mtx[ELR_MTX2D_A] * m->mtx[ELR_MTX2D_C]
                              + s->mtx[ELR_MTX2D_B] * m->mtx[ELR_MTX2D_F]
                              + s->mtx[ELR_MTX2D_C] * m->mtx[ELR_MTX2D_I];

        // F' = Dc+Ef+Fi
        d->mtx[ELR_MTX2D_F] = s->mtx[ELR_MTX2D_D] * m->mtx[ELR_MTX2D_C]
                              + s->mtx[ELR_MTX2D_E] * m->mtx[ELR_MTX2D_F]
                              + s->mtx[ELR_MTX2D_F] * m->mtx[ELR_MTX2D_I];

        // I' = Gc+Hf+Ii
        d->mtx[ELR_MTX2D_I] = s->mtx[ELR_MTX2D_G] * m->mtx[ELR_MTX2D_C]
                              + s->mtx[ELR_MTX2D_H] * m->mtx[ELR_MTX2D_F]
                              + s->mtx[ELR_MTX2D_I] * m->mtx[ELR_MTX2D_I];
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_adjointmatrix2d
//
// Computes the adjoint of a 2D matrix.  If 'hn' is set, then the matrix is
// assumed to have [0 0 1] in the last column.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void elr_fpu_adjointmatrix2d(const ElrMatrix2D *m, ElrMatrix2D *d,
                                        int hn)
{
    assertMyth("elr_fpu_adjointmatrix2d() needs valid input",
               m != 0 && d != 0);

    ElrMatrix2D mtx;

    if (m == d)
    {
        mtx = *m;
        m = &mtx;
    }

//ÄÄÄ Check for common case of hnormalized matrix
    if (hn
        || (m->mtx[ELR_MTX2D_C] == 0.0f && m->mtx[ELR_MTX2D_F] == 0.0f
            && m->mtx[ELR_MTX2D_I] == 1.0f))
    {
        // [A B 0]*   [ |E 0| -|B 0|  |B 0| ]
        // [D E 0]  = [ |H 1|  |H 1|  |E F| ]
        // [G H 1]    [                     ]
        //            [-|D F|  |A 0| -|A 0| ]
        //            [ |G 1|  |G 1|  |D F| ]
        //            [                     ]
        //            [ |D E| -|A B|  |A B| ]
        //            [ |G H|  |G H|  |D E| ]

        // A' = |E 0|  = E1 - H0 = E
        //      |H 1|

        d->mtx[ELR_MTX2D_A] = m->mtx[ELR_MTX2D_E];

        // D' = -|D 0| = -(D1 - G0) = G0 - D1 = -D
        //       |G 1|

        d->mtx[ELR_MTX2D_D] = -m->mtx[ELR_MTX2D_D];

        // G' = |D E| = DH - GE
        //      |G H|

        d->mtx[ELR_MTX2D_G] = m->mtx[ELR_MTX2D_D]*m->mtx[ELR_MTX2D_H]
                              - m->mtx[ELR_MTX2D_G]*m->mtx[ELR_MTX2D_E];

        // B' = -|B 0| = -(B1 - H0) = H0 - B1 = -B
        //       |H 1|

        d->mtx[ELR_MTX2D_B] = -m->mtx[ELR_MTX2D_B];

        // E' = |A 0| = A1 - G0 = A
        //      |G 1|

        d->mtx[ELR_MTX2D_E] = m->mtx[ELR_MTX2D_A];

        // H' = -|A B| = -(AH - GB) = GB - AH
        //       |G H|

        d->mtx[ELR_MTX2D_H] = m->mtx[ELR_MTX2D_G]*m->mtx[ELR_MTX2D_B]
                              - m->mtx[ELR_MTX2D_A]*m->mtx[ELR_MTX2D_H];

        // C' = |B 0| = B0 - E0 = 0
        //      |E 0|

        d->mtx[ELR_MTX2D_C] = 0;

        // F' = -|A 0| = -(A0 - D0) = D0 - A0 = 0
        //       |D 0|

        d->mtx[ELR_MTX2D_F] = 0;

        // I' = |A B| = AE - DB
        //      |D E|

        d->mtx[ELR_MTX2D_I] = m->mtx[ELR_MTX2D_D]*m->mtx[ELR_MTX2D_C]
                              - m->mtx[ELR_MTX2D_A]*m->mtx[ELR_MTX2D_F];
    }
//ÄÄÄ General case
    else
    {
        // [A B C]*   [ |E F| -|B C|  |B C| ]
        // [D E F]  = [ |H I|  |H I|  |E F| ]
        // [G H I]    [                     ]
        //            [-|D F|  |A C| -|A C| ]
        //            [ |G I|  |G I|  |D F| ]
        //            [                     ]
        //            [ |D E| -|A B|  |A B| ]
        //            [ |G H|  |G H|  |D E| ]

        // A' = |E F|  = EI - HF
        //      |H I|

        d->mtx[ELR_MTX2D_A] = m->mtx[ELR_MTX2D_E]*m->mtx[ELR_MTX2D_I]
                              - m->mtx[ELR_MTX2D_H]*m->mtx[ELR_MTX2D_F];

        // D' = -|D F| = -(DI - GF) = GF - DI
        //       |G I|

        d->mtx[ELR_MTX2D_D] = m->mtx[ELR_MTX2D_G]*m->mtx[ELR_MTX2D_F]
                              - m->mtx[ELR_MTX2D_D]*m->mtx[ELR_MTX2D_I];

        // G' = |D E| = DH - GE
        //      |G H|

        d->mtx[ELR_MTX2D_G] = m->mtx[ELR_MTX2D_D]*m->mtx[ELR_MTX2D_H]
                              - m->mtx[ELR_MTX2D_G]*m->mtx[ELR_MTX2D_E];

        // B' = -|B C| = -(BI - HC) = HC - BI
        //       |H I|

        d->mtx[ELR_MTX2D_B] = m->mtx[ELR_MTX2D_H]*m->mtx[ELR_MTX2D_C]
                              - m->mtx[ELR_MTX2D_B]*m->mtx[ELR_MTX2D_I];

        // E' = |A C| = AI - GC
        //      |G I|

        d->mtx[ELR_MTX2D_E] = m->mtx[ELR_MTX2D_A]*m->mtx[ELR_MTX2D_I]
                              - m->mtx[ELR_MTX2D_G]*m->mtx[ELR_MTX2D_C];

        // H' = -|A B| = -(AH - GB) = GB - AH
        //       |G H|

        d->mtx[ELR_MTX2D_H] = m->mtx[ELR_MTX2D_G]*m->mtx[ELR_MTX2D_B]
                              - m->mtx[ELR_MTX2D_A]*m->mtx[ELR_MTX2D_H];

        // C' = |B C| = BF - EC
        //      |E F|

        d->mtx[ELR_MTX2D_C] = m->mtx[ELR_MTX2D_B]*m->mtx[ELR_MTX2D_F]
                              - m->mtx[ELR_MTX2D_E]*m->mtx[ELR_MTX2D_C];

        // F' = -|A C| = -(AF - DC) = DC - AF
        //       |D F|

        d->mtx[ELR_MTX2D_F] = m->mtx[ELR_MTX2D_D]*m->mtx[ELR_MTX2D_C]
                              - m->mtx[ELR_MTX2D_A]*m->mtx[ELR_MTX2D_F];

        // I' = |A B| = AE - DB
        //      |D E|

        d->mtx[ELR_MTX2D_I] = m->mtx[ELR_MTX2D_A]*m->mtx[ELR_MTX2D_E]
                              - m->mtx[ELR_MTX2D_D]*m->mtx[ELR_MTX2D_B];
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_inversematrix2d
//
// Computes the inverse of a 2D matrix.  Returns 1 if the inverse does not
// exist, 0 otherwise.  If 'hn' is set, then the matrix is assumed to have
// [0 0 1] in the last column.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" int elr_fpu_inversematrix2d(const ElrMatrix2D *m, ElrMatrix2D *d,
                                       int hn)
{
    assertMyth("elr_fpu_inversematrix2d() needs valid input",
               m != 0 && d != 0);

//ÄÄÄ Compute determinent
    float det = m->det();

    if (det < 0.0001f && det > -0.0001f)
        return 1;

//ÄÄÄ Compute adjoint
    elr_fpu_adjointmatrix2d(m,d,hn);

//ÄÄÄ Divide by determinent.
    *d /= det;

    return 0;
}

//°±² End of module - elrfpu2d.cpp ²±°
