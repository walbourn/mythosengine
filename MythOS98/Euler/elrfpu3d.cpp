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
// elrfpu3d.cpp
//
// Contains the C-callable math helper routines for 3D data types implemented
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
// elr_fpu_transform3d
//
// Transforms a 3D point by a 3D matrix with an implicit w value of 1 in
// the point.  If 'hn' is set, then the matrix is assumed to have [0 0 0 1] in
// the last column.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void elr_fpu_transform3d(const ElrPoint3D *p,
                                    const ElrMatrix3D *m, ElrPoint3DW *d,
                                    int hn)
{
    assertMyth("elr_fpu_transform3d() needs valid input",
               p != 0 && m != 0 && d != 0);

//ÄÄÄ Check for common case of hnormalized matrix
    if (hn
        || (m->mtx[ELR_MTX3D_D] == 0.0f
            && m->mtx[ELR_MTX3D_H] == 0.0f
            && m->mtx[ELR_MTX3D_L] == 0.0f
            && m->mtx[ELR_MTX3D_P] == 1.0f))
    {
        //              [A B C 0]   [ Ax+Ey+Iz+M ]
        // [x y z 1] *  [E F G 0] = [ Bx+Fy+Jz+N ]
        //              [I J K 0]   [ Cx+Gy+Kz+O ]
        //              [M N O 1]   [      1     ]

        d->x = m->mtx[ELR_MTX3D_A]*p->x
               + m->mtx[ELR_MTX3D_E]*p->y
               + m->mtx[ELR_MTX3D_I]*p->z
               + m->mtx[ELR_MTX3D_M];

        d->y = m->mtx[ELR_MTX3D_B]*p->x
               + m->mtx[ELR_MTX3D_F]*p->y
               + m->mtx[ELR_MTX3D_J]*p->z
               + m->mtx[ELR_MTX3D_N];

        d->z = m->mtx[ELR_MTX3D_C]*p->x
               + m->mtx[ELR_MTX3D_G]*p->y
               + m->mtx[ELR_MTX3D_K]*p->z
               + m->mtx[ELR_MTX3D_O];

        d->w = 1.0f;
    }
//ÄÄÄ General case
    else
    {
        //              [A B C D]   [ Ax+Ey+Iz+M ]
        // [x y z 1] *  [E F G H] = [ Bx+Fy+Jz+N ]
        //              [I J K L]   [ Cx+Gy+Kz+O ]
        //              [M N O P]   [ Dx+Hy+Lz+P ]

        d->x = m->mtx[ELR_MTX3D_A]*p->x
               + m->mtx[ELR_MTX3D_E]*p->y
               + m->mtx[ELR_MTX3D_I]*p->z
               + m->mtx[ELR_MTX3D_M];

        d->y = m->mtx[ELR_MTX3D_B]*p->x
               + m->mtx[ELR_MTX3D_F]*p->y
               + m->mtx[ELR_MTX3D_J]*p->z
               + m->mtx[ELR_MTX3D_N];

        d->z = m->mtx[ELR_MTX3D_C]*p->x
               + m->mtx[ELR_MTX3D_G]*p->y
               + m->mtx[ELR_MTX3D_K]*p->z
               + m->mtx[ELR_MTX3D_O];

        d->w = m->mtx[ELR_MTX3D_D]*p->x
               + m->mtx[ELR_MTX3D_H]*p->y
               + m->mtx[ELR_MTX3D_L]*p->z
               + m->mtx[ELR_MTX3D_P];
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_transform3dw
//
// Transforms a 3D point by a 3D matrix.  If 'hn' is set, then the matrix is
// assumed to have [0 0 0 1] in the last column.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void elr_fpu_transform3dw(const ElrPoint3DW *p,
                                     const ElrMatrix3D *m, ElrPoint3DW *d,
                                     int hn)
{
    assertMyth("elr_fpu_transform3dw() needs valid input",
               p != 0 && m != 0 && d != 0);

    float nx, ny, nz, nw;

//ÄÄÄ Check for common case of hnormalized matrix
    if (hn
        || (m->mtx[ELR_MTX3D_D] == 0.0f
            && m->mtx[ELR_MTX3D_H] == 0.0f
            && m->mtx[ELR_MTX3D_L] == 0.0f
            && m->mtx[ELR_MTX3D_P] == 1.0f))
    {
        //              [A B C 0]   [ Ax+Ey+Iz+Mw ]
        // [x y z w] *  [E F G 0] = [ Bx+Fy+Jz+Nw ]
        //              [I J K 0]   [ Cx+Gy+Kz+Ow ]
        //              [M N O 1]   [      w      ]

        nx = m->mtx[ELR_MTX3D_A]*p->x
             + m->mtx[ELR_MTX3D_E]*p->y
             + m->mtx[ELR_MTX3D_I]*p->z
             + m->mtx[ELR_MTX3D_M]*p->w;

        ny = m->mtx[ELR_MTX3D_B]*p->x
             + m->mtx[ELR_MTX3D_F]*p->y
             + m->mtx[ELR_MTX3D_J]*p->z
             + m->mtx[ELR_MTX3D_N]*p->w;

        nz = m->mtx[ELR_MTX3D_C]*p->x
             + m->mtx[ELR_MTX3D_G]*p->y
             + m->mtx[ELR_MTX3D_K]*p->z
             + m->mtx[ELR_MTX3D_O]*p->w;

        nw = p->w;
    }
//ÄÄÄ General case
    else
    {
        //              [A B C D]   [ Ax+Ey+Iz+Mw ]
        // [x y z w] *  [E F G H] = [ Bx+Fy+Jz+Nw ]
        //              [I J K L]   [ Cx+Gy+Kz+Ow ]
        //              [M N O P]   [ Dx+Hy+Lz+Pw ]

        nx = m->mtx[ELR_MTX3D_A]*p->x
             + m->mtx[ELR_MTX3D_E]*p->y
             + m->mtx[ELR_MTX3D_I]*p->z
             + m->mtx[ELR_MTX3D_M]*p->w;

        ny = m->mtx[ELR_MTX3D_B]*p->x
             + m->mtx[ELR_MTX3D_F]*p->y
             + m->mtx[ELR_MTX3D_J]*p->z
             + m->mtx[ELR_MTX3D_N]*p->w;

        nz = m->mtx[ELR_MTX3D_C]*p->x
             + m->mtx[ELR_MTX3D_G]*p->y
             + m->mtx[ELR_MTX3D_K]*p->z
             + m->mtx[ELR_MTX3D_O]*p->w;

        nw = m->mtx[ELR_MTX3D_D]*p->x
             + m->mtx[ELR_MTX3D_H]*p->y
             + m->mtx[ELR_MTX3D_L]*p->z
             + m->mtx[ELR_MTX3D_P]*p->w;
    }

    d->x = nx;
    d->y = ny;
    d->z = nz;
    d->w = nw;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_transformv3d
//
// Transforms a 3D vector by a 3D matrix with an implicit w value of 1 in
// the vector.  If 'hn' is set, then the matrix is assumed to have [0 0 0 1]
// in the last column.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void elr_fpu_transformv3d(const ElrVector3D *v,
                                     const ElrMatrix3D *m, ElrVector3DW *d,
                                     int hn)
{
    assertMyth("elr_fpu_transformv3d() needs valid input",
               v != 0 && m != 0 && d != 0);

//ÄÄÄ Check for common case of hnormalized matrix
    if (hn
        || (m->mtx[ELR_MTX3D_D] == 0.0f
            && m->mtx[ELR_MTX3D_H] == 0.0f
            && m->mtx[ELR_MTX3D_L] == 0.0f
            && m->mtx[ELR_MTX3D_P] == 1.0f))
    {
        //              [A B C 0]   [ Ai+Ej+Ik ]
        // [i j k 1] *  [E F G 0] = [ Bi+Fj+Jk ]
        //              [I J K 0]   [ Ci+Gj+Kk ]
        //              [x x x 1]   [     1    ]

        d->i = m->mtx[ELR_MTX3D_A]*v->i
               + m->mtx[ELR_MTX3D_E]*v->j
               + m->mtx[ELR_MTX3D_I]*v->k;

        d->j = m->mtx[ELR_MTX3D_B]*v->i
               + m->mtx[ELR_MTX3D_F]*v->j
               + m->mtx[ELR_MTX3D_J]*v->k;

        d->k = m->mtx[ELR_MTX3D_C]*v->i
               + m->mtx[ELR_MTX3D_G]*v->j
               + m->mtx[ELR_MTX3D_K]*v->k;

        d->w = 1.0f;
    }
//ÄÄÄ General case
    else
    {
        //              [A B C D]   [  Ax+Ey+Iz  ]
        // [x y z 1] *  [E F G H] = [  Bx+Fy+Jz  ]
        //              [I J K L]   [  Cx+Gy+Kz  ]
        //              [x x x P]   [ Dx+Hy+Lz+P ]

        d->i = m->mtx[ELR_MTX3D_A]*v->i
               + m->mtx[ELR_MTX3D_E]*v->j
               + m->mtx[ELR_MTX3D_I]*v->k;

        d->j = m->mtx[ELR_MTX3D_B]*v->i
               + m->mtx[ELR_MTX3D_F]*v->j
               + m->mtx[ELR_MTX3D_J]*v->k;

        d->k = m->mtx[ELR_MTX3D_C]*v->i
               + m->mtx[ELR_MTX3D_G]*v->j
               + m->mtx[ELR_MTX3D_K]*v->k;

        d->w = m->mtx[ELR_MTX3D_D]*v->i
               + m->mtx[ELR_MTX3D_H]*v->j
               + m->mtx[ELR_MTX3D_L]*v->k
               + m->mtx[ELR_MTX3D_P];
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_transformv3dw
//
// Transforms a 3D vector by a 3D matrix.    If 'hn' is set, then the matrix
// is assumed to have [0 0 0 1] in the last column.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void elr_fpu_transformv3dw(const ElrVector3DW *v,
                                      const ElrMatrix3D *m, ElrVector3DW *d,
                                      int hn)
{
    assertMyth("elr_fpu_transformv3dw() needs valid input",
               v != 0 && m != 0 && d != 0);

    float ni, nj, nk, nw;

//ÄÄÄ Check for common case of hnormalized matrix
    if (hn
        || (m->mtx[ELR_MTX3D_D] == 0.0f
            && m->mtx[ELR_MTX3D_H] == 0.0f
            && m->mtx[ELR_MTX3D_L] == 0.0f
            && m->mtx[ELR_MTX3D_P] == 1.0f))
    {
        //              [A B C 0]   [ Ai+Ej+Ik ]
        // [i j k w] *  [E F G 0] = [ Bi+Fj+Jk ]
        //              [I J K 0]   [ Ci+Gj+Kk ]
        //              [x x x 1]   [    w     ]

        ni = m->mtx[ELR_MTX3D_A]*v->i
             + m->mtx[ELR_MTX3D_E]*v->j
             + m->mtx[ELR_MTX3D_I]*v->k;

        nj = m->mtx[ELR_MTX3D_B]*v->i
             + m->mtx[ELR_MTX3D_F]*v->j
             + m->mtx[ELR_MTX3D_J]*v->k;

        nk = m->mtx[ELR_MTX3D_C]*v->i
             + m->mtx[ELR_MTX3D_G]*v->j
             + m->mtx[ELR_MTX3D_K]*v->k;

        nw = v->w;
    }
//ÄÄÄ General case
    else
    {
        //              [A B C D]   [   Ai+Ej+Ik  ]
        // [i j k w] *  [E F G H] = [   Bi+Fj+Jk  ]
        //              [I J K L]   [   Ci+Gj+Kk  ]
        //              [x x x P]   [ Di+Hj+Lk+Pw ]

        ni = m->mtx[ELR_MTX3D_A]*v->i
             + m->mtx[ELR_MTX3D_E]*v->j
             + m->mtx[ELR_MTX3D_I]*v->k;

        nj = m->mtx[ELR_MTX3D_B]*v->i
             + m->mtx[ELR_MTX3D_F]*v->j
             + m->mtx[ELR_MTX3D_J]*v->k;

        nk = m->mtx[ELR_MTX3D_C]*v->i
             + m->mtx[ELR_MTX3D_G]*v->j
             + m->mtx[ELR_MTX3D_K]*v->k;

        nw = m->mtx[ELR_MTX3D_D]*v->i
             + m->mtx[ELR_MTX3D_H]*v->j
             + m->mtx[ELR_MTX3D_L]*v->k
             + m->mtx[ELR_MTX3D_P]*v->w;
    }

    d->i = ni;
    d->j = nj;
    d->k = nk;
    d->w = nw;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_cross3d
//
// Computes the cross product of two 3D vectors.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" ElrVector3D *elr_fpu_cross3d(const ElrVector3D *v1,
                                        const ElrVector3D *v2, ElrVector3D *d)
{
    assertMyth("elr_fpu_cross3d() needs valid input",
               v1 != 0 && v2 != 0 && d != 0);

//
// (i', j', k') = v1 CROSS v2
//
//       i' = (v1.j * v2.k) - (v1.k * v2.j)
//       j' = (v1.k * v2.i) - (v1.i * v2.k)
//       k' = (v1.i * v2.j) - (v1.j * v2.i)
//

    float newi = (v1->j*v2->k) - (v1->k*v2->j);
    float newj = (v1->k*v2->i) - (v1->i*v2->k);
    float newk = (v1->i*v2->j) - (v1->j*v2->i);

    d->i = newi;
    d->j = newj;
    d->k = newk;

    return d;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_normalize3d
//
// Normalizes a 3D vector (there is a lower-bound on the valid size, so this
// will be a no-op in the case of an extremely short vector which might fail
// to result in an valid representation).
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void elr_fpu_normalize3d(ElrVector3D *v)
{
    assertMyth("elr_fpu_normalize3d() needs valid input", v != 0);

    float mag = elr_sqrt(v->i*v->i + v->j*v->j + v->k*v->k);

    if (mag >= 0.0001f)
    {
        v->i /= mag;
        v->j /= mag;
        v->k /= mag;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_hnormalize3d
//
// Normalizes/projects a vector in homogeneous space onto the w=1 hyperplane.
// (there is a lower-bound on the size of w since smaller values might
// result in invalid representation).
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void elr_fpu_hnormalize3d(ElrVector3DW *v)
{
    assertMyth("elr_fpu_hnormalize3d() needs valid input", v != 0);

    if (v->w == 1.0f)
        return;

    if (v->w > 0.0001f || v->w < -0.0001f)
    {
        v->i /= v->w;
        v->j /= v->w;
        v->k /= v->w;
        v->w = 1.0f;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_contactmatrix3d
//
// Concacts/multiplies two 3D matricies.  If 'hn' is set, then both matricies
// are assumed to have [0 0 0 1] in the last column.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void elr_fpu_concatmatrix3d(const ElrMatrix3D *s,
                                       const ElrMatrix3D *m, ElrMatrix3D *d,
                                       int hn)
{
    assertMyth("elr_fpu_concatmatrix3d() needs valid input",
               s != 0 && m != 0 && d != 0);

    ElrMatrix3D mtx;

    if (s == d)
    {
        mtx = *s;
        s = &mtx;
    }

//ÄÄÄ Check for common case of two hnormalized matricies
    if (hn
        || (s->mtx[ELR_MTX3D_D] == 0.0f && s->mtx[ELR_MTX3D_H] == 0.0f
            && s->mtx[ELR_MTX3D_L] == 0.0f && s->mtx[ELR_MTX3D_P] == 1.0f
            && m->mtx[ELR_MTX3D_D] == 0.0f && m->mtx[ELR_MTX3D_H] == 0.0f
            && m->mtx[ELR_MTX3D_L] == 0.0f && m->mtx[ELR_MTX3D_P] == 1.0f))
    {
        // [A B C 0]   [a b c 0]   [ Aa+Be+Ci   Ab+Bf+Cj   Ac+Bg+Ck  0]
        // [E F G 0] * [e f g 0] = [ Ea+Fe+Gi   Eb+Ff+Gj   Ec+Fg+Gk  0]
        // [I J K 0]   [i j k 0]   [ Ia+Je+Ki   Ib+Jf+Kj   Ic+Jg+Kk  0]
        // [M N O 1]   [m n o 1]   [Ma+Ne+Oi+m Mb+Nf+Oj+n Mc+Ng+Ok+o 1]

        // A' = Aa+Be+Ci
        d->mtx[ELR_MTX3D_A] = s->mtx[ELR_MTX3D_A]*m->mtx[ELR_MTX3D_A]
                              + s->mtx[ELR_MTX3D_B]*m->mtx[ELR_MTX3D_E]
                              + s->mtx[ELR_MTX3D_C]*m->mtx[ELR_MTX3D_I];

        // E' = Ea+Fe+Gi
        d->mtx[ELR_MTX3D_E] = s->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_A]
                              + s->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_E]
                              + s->mtx[ELR_MTX3D_G]*m->mtx[ELR_MTX3D_I];

        // I' = Ia+Je+Ki
        d->mtx[ELR_MTX3D_I] = s->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_A]
                              + s->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_E]
                              + s->mtx[ELR_MTX3D_K]*m->mtx[ELR_MTX3D_I];

        // M' = Ma+Ne+Oi+m
        d->mtx[ELR_MTX3D_M] = s->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_A]
                              + s->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_E]
                              + s->mtx[ELR_MTX3D_O]*m->mtx[ELR_MTX3D_I]
                              + m->mtx[ELR_MTX3D_M];

        // B' = Ab+Bf+Cj
        d->mtx[ELR_MTX3D_B] = s->mtx[ELR_MTX3D_A]*m->mtx[ELR_MTX3D_B]
                              + s->mtx[ELR_MTX3D_B]*m->mtx[ELR_MTX3D_F]
                              + s->mtx[ELR_MTX3D_C]*m->mtx[ELR_MTX3D_J];

        // F' = Eb+Ff+Gj
        d->mtx[ELR_MTX3D_F] = s->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_B]
                              + s->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_F]
                              + s->mtx[ELR_MTX3D_G]*m->mtx[ELR_MTX3D_J];

        // J' = Ib+Jf+Kj
        d->mtx[ELR_MTX3D_J] = s->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_B]
                              + s->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_F]
                              + s->mtx[ELR_MTX3D_K]*m->mtx[ELR_MTX3D_J];

        // N' = Mb+Nf+Oj+n
        d->mtx[ELR_MTX3D_N] = s->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_B]
                              + s->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_F]
                              + s->mtx[ELR_MTX3D_O]*m->mtx[ELR_MTX3D_J]
                              + m->mtx[ELR_MTX3D_N];

        // C' = Ac+Bg+Ck
        d->mtx[ELR_MTX3D_C] = s->mtx[ELR_MTX3D_A]*m->mtx[ELR_MTX3D_C]
                              + s->mtx[ELR_MTX3D_B]*m->mtx[ELR_MTX3D_G]
                              + s->mtx[ELR_MTX3D_C]*m->mtx[ELR_MTX3D_K];

        // G' = Ec+Fg+Gk
        d->mtx[ELR_MTX3D_G] = s->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_C]
                              + s->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_G]
                              + s->mtx[ELR_MTX3D_G]*m->mtx[ELR_MTX3D_K];

        // K' = Ic+Jg+Kk
        d->mtx[ELR_MTX3D_K] = s->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_C]
                              + s->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_G]
                              + s->mtx[ELR_MTX3D_K]*m->mtx[ELR_MTX3D_K];

        // O' = Mc+Ng+Ok+o
        d->mtx[ELR_MTX3D_O] = s->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_C]
                              + s->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_G];
                              + s->mtx[ELR_MTX3D_O]*m->mtx[ELR_MTX3D_K];
                              + m->mtx[ELR_MTX3D_O];

        // D' = 0
        d->mtx[ELR_MTX3D_D] = 0.0f;

        // H' = 0
        d->mtx[ELR_MTX3D_H] = 0.0f;

        // L' = 0
        d->mtx[ELR_MTX3D_L] = 0.0f;

        // P' = 1
        d->mtx[ELR_MTX3D_P] = 1.0f;
    }
//ÄÄÄ General case
    else
    {
        //[A B C D] [a b c d] [Aa+Be+Ci+Dm Ab+Bf+Cj+Dn Ac+Bg+Ck+Do Ad+Bh+Cl+Dp]
        //[E F G H]*[e f g h]=[Ea+Fe+Gi+Hm Eb+Ff+Gj+Hn Ec+Fg+Gk+Ho Ed+Fh+Gl+Hp]
        //[I J K L] [i j k l] [Ia+Je+Ki+Lm Ib+Jf+Kj+Ln Ic+Jg+Kk+Lo Id+Jh+Kl+Lp]
        //[M N O P] [m n o p] [Ma+Ne+Oi+Pm Mb+Nf+Oj+Pn Mc+Ng+Ok+Po Md+Nh+Ol+Pp]

        // A' = Aa+Be+Ci+Dm
        d->mtx[ELR_MTX3D_A] = s->mtx[ELR_MTX3D_A]*m->mtx[ELR_MTX3D_A]
                              + s->mtx[ELR_MTX3D_B]*m->mtx[ELR_MTX3D_E]
                              + s->mtx[ELR_MTX3D_C]*m->mtx[ELR_MTX3D_I]
                              + s->mtx[ELR_MTX3D_D]*m->mtx[ELR_MTX3D_M];

        // E' = Ea+Fe+Gi+Hm
        d->mtx[ELR_MTX3D_E] = s->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_A]
                              + s->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_E]
                              + s->mtx[ELR_MTX3D_G]*m->mtx[ELR_MTX3D_I]
                              + s->mtx[ELR_MTX3D_H]*m->mtx[ELR_MTX3D_M];

        // I' = Ia+Je+Ki+Lm
        d->mtx[ELR_MTX3D_I] = s->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_A]
                              + s->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_E]
                              + s->mtx[ELR_MTX3D_K]*m->mtx[ELR_MTX3D_I]
                              + s->mtx[ELR_MTX3D_L]*m->mtx[ELR_MTX3D_M];

        // M' = Ma+Ne+Oi+Pm
        d->mtx[ELR_MTX3D_M] = s->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_A]
                              + s->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_E]
                              + s->mtx[ELR_MTX3D_O]*m->mtx[ELR_MTX3D_I]
                              + s->mtx[ELR_MTX3D_P]*m->mtx[ELR_MTX3D_M];

        // B' = Ab+Bf+Cj+Dn
        d->mtx[ELR_MTX3D_B] = s->mtx[ELR_MTX3D_A]*m->mtx[ELR_MTX3D_B]
                              + s->mtx[ELR_MTX3D_B]*m->mtx[ELR_MTX3D_F]
                              + s->mtx[ELR_MTX3D_C]*m->mtx[ELR_MTX3D_J]
                              + s->mtx[ELR_MTX3D_D]*m->mtx[ELR_MTX3D_N];

        // F' = Eb+Ff+Gj+Hn
        d->mtx[ELR_MTX3D_F] = s->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_B]
                              + s->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_F]
                              + s->mtx[ELR_MTX3D_G]*m->mtx[ELR_MTX3D_J]
                              + s->mtx[ELR_MTX3D_H]*m->mtx[ELR_MTX3D_N];

        // J' = Ib+Jf+Kj+Ln
        d->mtx[ELR_MTX3D_J] = s->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_B]
                              + s->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_F]
                              + s->mtx[ELR_MTX3D_K]*m->mtx[ELR_MTX3D_J]
                              + s->mtx[ELR_MTX3D_L]*m->mtx[ELR_MTX3D_N];

        // N' = Mb+Nf+Oj+Pn
        d->mtx[ELR_MTX3D_N] = s->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_B]
                              + s->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_F]
                              + s->mtx[ELR_MTX3D_O]*m->mtx[ELR_MTX3D_J]
                              + s->mtx[ELR_MTX3D_P]*m->mtx[ELR_MTX3D_N];

        // C' = Ac+Bg+Ck+Do
        d->mtx[ELR_MTX3D_C] = s->mtx[ELR_MTX3D_A]*m->mtx[ELR_MTX3D_C]
                              + s->mtx[ELR_MTX3D_B]*m->mtx[ELR_MTX3D_G]
                              + s->mtx[ELR_MTX3D_C]*m->mtx[ELR_MTX3D_K]
                              + s->mtx[ELR_MTX3D_D]*m->mtx[ELR_MTX3D_O];

        // G' = Ec+Fg+Gk+Ho
        d->mtx[ELR_MTX3D_G] = s->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_C]
                              + s->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_G]
                              + s->mtx[ELR_MTX3D_G]*m->mtx[ELR_MTX3D_K]
                              + s->mtx[ELR_MTX3D_H]*m->mtx[ELR_MTX3D_O];

        // K' = Ic+Jg+Kk+Lo
        d->mtx[ELR_MTX3D_K] = s->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_C]
                              + s->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_G]
                              + s->mtx[ELR_MTX3D_K]*m->mtx[ELR_MTX3D_K]
                              + s->mtx[ELR_MTX3D_L]*m->mtx[ELR_MTX3D_O];

        // O' = Mc+Ng+Ok+Po
        d->mtx[ELR_MTX3D_O] = s->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_C]
                              + s->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_G];
                              + s->mtx[ELR_MTX3D_O]*m->mtx[ELR_MTX3D_K];
                              + s->mtx[ELR_MTX3D_P]*m->mtx[ELR_MTX3D_O];

        // D' = Ad+Bh+Cl+Dp
        d->mtx[ELR_MTX3D_D] = s->mtx[ELR_MTX3D_A]*m->mtx[ELR_MTX3D_D]
                              + s->mtx[ELR_MTX3D_B]*m->mtx[ELR_MTX3D_H]
                              + s->mtx[ELR_MTX3D_C]*m->mtx[ELR_MTX3D_L]
                              + s->mtx[ELR_MTX3D_D]*m->mtx[ELR_MTX3D_P];

        // H' = Ed+Fh+Gl+Hp
        d->mtx[ELR_MTX3D_H] = s->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_D]
                              + s->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_H]
                              + s->mtx[ELR_MTX3D_G]*m->mtx[ELR_MTX3D_L]
                              + s->mtx[ELR_MTX3D_H]*m->mtx[ELR_MTX3D_P];

        // L' = Id+Jh+Kl+Lp
        d->mtx[ELR_MTX3D_L] = s->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_D]
                              + s->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_H]
                              + s->mtx[ELR_MTX3D_K]*m->mtx[ELR_MTX3D_L]
                              + s->mtx[ELR_MTX3D_L]*m->mtx[ELR_MTX3D_P];

        // P' = Md+Nh+Ol+Pp
        d->mtx[ELR_MTX3D_P] = s->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_D]
                              + s->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_H]
                              + s->mtx[ELR_MTX3D_O]*m->mtx[ELR_MTX3D_L]
                              + s->mtx[ELR_MTX3D_P]*m->mtx[ELR_MTX3D_P];
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_adjointmatrix3d
//
// Computes the adjoint of a 3D matrix.  If 'hn' is set, then the matrix is
// assumed to have [0 0 0 1] in the last column.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" void elr_fpu_adjointmatrix3d(const ElrMatrix3D *m, ElrMatrix3D *d,
                                        int hn)
{
    assertMyth("elr_fpu_adjointmatrix3d() needs valid input",
               m != 0 && d != 0);

    ElrMatrix3D mtx;

    if (m == d)
    {
        mtx = *m;
        m = &mtx;
    }

//ÄÄÄ Check for common case of hnormalized matrix
    if (hn
        || (m->mtx[ELR_MTX3D_D] == 0.0f && m->mtx[ELR_MTX3D_H] == 0.0f
            && m->mtx[ELR_MTX3D_L] == 0.0f && m->mtx[ELR_MTX3D_P] == 1.0f))
    {
        // [A B C 0]*   [ |F G 0|  -|B C 0|   |B C 0|  -|B C 0| ]
        // [E F G 0]  = [ |J K 0|   |J K 0|   |F G 0|   |F G 0| ]
        // [I J K 0]    [ |N O 1|   |N O 1|   |N O 1|   |J K 0| ]
        // [M N O 1]    [                                       ]
        //              [-|E G 0|   |A C 0|  -|A C 0|   |A C 0| ]
        //              [ |I K 0|   |I K 0|   |E G 0|   |E G 0| ]
        //              [ |M O 1|   |M O 1|   |M O 1|   |I K 0| ]
        //              [                                       ]
        //              [ |E F 0|  -|A B 0|   |A B 0|  -|A B 0| ]
        //              [ |I J 0|   |I J 0|   |E F 0|   |E F 0| ]
        //              [ |M N 1|   |M N 1|   |M N 1|   |I J 0| ]
        //              [                                       ]
        //              [-|E F G|   |A B C|  -|A B C|   |A B C| ]
        //              [ |I J K|   |I J K|   |E F G|   |E F G| ]
        //              [ |M N O|   |M N O|   |M N O|   |I J K| ]

        //      |F G 0|
        // A' = |J K 0| = F|K 0| - G|J 0| = FK - GJ
        //      |N O 1|    |O 1|    |N 1|

        d->mtx[ELR_MTX3D_A] = m->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_K]
                              - m->mtx[ELR_MTX3D_G]*m->mtx[ELR_MTX3D_J];

        //      -|E G 0|
        // E' =  |I K 0| = - E|K 0| + G|I 0| = GI - EK
        //       |M O 1|      |O 1|    |M 1|

        d->mtx[ELR_MTX3D_E] = m->mtx[ELR_MTX3D_G]*m->mtx[ELR_MTX3D_I]
                              - m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_K];

        //      |E F 0|
        // I' = |I J 0| = E|J 0| - F|I 0| = EJ - FI
        //      |M N 1|    |N 1|    |M 1|

        d->mtx[ELR_MTX3D_I] = m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_J]
                              - m->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_I];

        //      -|E F G|
        // M' =  |I J K| = -E|J K| + F|I K| - G|I J| = F(IN-MK)-E(JO-NK)-G(IN-MJ)
        //       |M N O|     |N O|    |M N|    |M N|

        d->mtx[ELR_MTX3D_M] = m->mtx[ELR_MTX3D_F]
                                *( m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_N]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_K] )
                              - m->mtx[ELR_MTX3D_E]
                                *( m->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_O]
                                   - m->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_K] )
                              - m->mtx[ELR_MTX3D_G]
                                *( m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_N]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_J] );

        //      -|B C 0|
        // B' =  |J K 0| = -B|K 0| + C|J 0| = CJ - BK
        //       |N O 1|     |O 1|    |N 1|

        d->mtx[ELR_MTX3D_B] = m->mtx[ELR_MTX3D_C]*m->mtx[ELR_MTX3D_J]
                              - m->mtx[ELR_MTX3D_B]*m->mtx[ELR_MTX3D_K];

        //      |A C 0|
        // F' = |I K 0| = A|K 0| - C|I 0| = AK - CI
        //      |M O 1|    |O 1|    |M 1|

        d->mtx[ELR_MTX3D_F] = m->mtx[ELR_MTX3D_A]*m->mtx[ELR_MTX3D_K]
                              - m->mtx[ELR_MTX3D_C]*m->mtx[ELR_MTX3D_I];

        //      -|A B 0|
        // J' =  |I J 0| = -A|J 0| + B|I 0| = BI-AJ
        //       |M N 1|     |N 1|    |M 1|

        d->mtx[ELR_MTX3D_J] = m->mtx[ELR_MTX3D_B]*m->mtx[ELR_MTX3D_I]
                              - m->mtx[ELR_MTX3D_A]*m->mtx[ELR_MTX3D_J];

        //      |A B C|
        // N' = |I J K| = A|J K| - B|I K| + C|I J| = A(JO-NK)-B(IO-MK)+C(IN-MJ)
        //      |M N O|    |N O|    |M O|    |M N|

        d->mtx[ELR_MTX3D_N] = m->mtx[ELR_MTX3D_A]
                                *( m->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_O]
                                   - m->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_K] )
                              - m->mtx[ELR_MTX3D_B]
                                *( m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_O]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_K] )
                              + m->mtx[ELR_MTX3D_C]
                                *( m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_N]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_J] );

        //      |B C 0|
        // C' = |F G 0| = B|G 0| - C|F 0| = BG - CF
        //      |N O 1|    |O 1|    |N 1|

        d->mtx[ELR_MTX3D_C] = m->mtx[ELR_MTX3D_B]*m->mtx[ELR_MTX3D_G]
                              - m->mtx[ELR_MTX3D_C]*m->mtx[ELR_MTX3D_F];

        //      -|A C 0|
        // G' =  |E G 0| = -A|G 0| + C|E 0| = CE-AG
        //       |M O 1|     |O 1|    |M 1|

        d->mtx[ELR_MTX3D_G] = m->mtx[ELR_MTX3D_C]*m->mtx[ELR_MTX3D_E]
                              - m->mtx[ELR_MTX3D_A]*m->mtx[ELR_MTX3D_G];

        //      |A B 0|
        // K' = |E F 0| = A|F 0| - B|E 0| = AF - BE
        //      |M N 1|    |N 1|    |M 1|

        d->mtx[ELR_MTX3D_K] = m->mtx[ELR_MTX3D_A]*m->mtx[ELR_MTX3D_F]
                              - m->mtx[ELR_MTX3D_B]*m->mtx[ELR_MTX3D_E];

        //      -|A B C|
        // O' =  |E F G| = -A|F G| + B|E G| - C|E F| = B(EO-MG)-A(FO-NG)-C(EN-MF)
        //       |M N O|     |N O|    |M O|    |M N|

        d->mtx[ELR_MTX3D_O] = m->mtx[ELR_MTX3D_B]
                                *( m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_O]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_G] )
                              - m->mtx[ELR_MTX3D_A]
                                *( m->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_O]
                                   - m->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_G] )
                              - m->mtx[ELR_MTX3D_C]
                                *( m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_N]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_F] );

        //      -|B C 0|
        // D' =  |F G 0| = -B|G 0| + C|F 0| = 0
        //       |J K 0|     |K 0|    |J 0|

        d->mtx[ELR_MTX3D_D] = 0.0f;

        //       |A C 0|
        // H' =  |E G 0| = A|G 0| - C|E 0| = 0
        //       |I K 0|    |K 0|    |I 0|

        d->mtx[ELR_MTX3D_H] = 0.0f;

        //      -|A B 0|
        // L' =  |E F 0| = -A|F 0| + B|E 0| = 0
        //       |I J 0|     |J 0|    |I 0|

        d->mtx[ELR_MTX3D_L] = 0.0f;

        //       |A B C|
        // P' =  |E F G| = A|F G| - B|E G| + C|E F| = A(FK-JG)-B(EK-IG)+C(EJ-IF)
        //       |I J K|    |J K|    |I K|    |I J|

        d->mtx[ELR_MTX3D_P] = m->mtx[ELR_MTX3D_A]
                                *( m->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_K]
                                   - m->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_G] )
                              - m->mtx[ELR_MTX3D_B]
                                *( m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_K]
                                   - m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_G] )
                              + m->mtx[ELR_MTX3D_C]
                                *( m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_J]
                                   - m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_F] );
    }
//ÄÄÄ General case
    else
    {
        // [A B C D]*   [ |F G H|  -|B C D|   |B C D|  -|B C D| ]
        // [E F G H]  = [ |J K L|   |J K L|   |F G H|   |F G H| ]
        // [I J K L]    [ |N O P|   |N O P|   |N O P|   |J K L| ]
        // [M N O P]    [                                       ]
        //              [-|E G H|   |A C D|  -|A C D|   |A C D| ]
        //              [ |I K L|   |I K L|   |E G H|   |E G H| ]
        //              [ |M O P|   |M O P|   |M O P|   |I K L| ]
        //              [                                       ]
        //              [ |E F H|  -|A B D|   |A B D|  -|A B D| ]
        //              [ |I J L|   |I J L|   |E F H|   |E F H| ]
        //              [ |M N P|   |M N P|   |M N P|   |I J L| ]
        //              [                                       ]
        //              [-|E F G|   |A B C|  -|A B C|   |A B C| ]
        //              [ |I J K|   |I J K|   |E F G|   |E F G| ]
        //              [ |M N O|   |M N O|   |M N O|   |I J K| ]

        //      |F G H|
        // A' = |J K L| = F|K L| - G|J L| + H|J K| = F(KP-OL)-G(JP-NL)+H(JO-NK)
        //      |N O P|    |O P|    |N P|    |N O|

        d->mtx[ELR_MTX3D_A] = m->mtx[ELR_MTX3D_F]
                                *( m->mtx[ELR_MTX3D_K]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_O]*m->mtx[ELR_MTX3D_L] )
                              - m->mtx[ELR_MTX3D_G]
                                *( m->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_L] )
                              + m->mtx[ELR_MTX3D_H]
                                *( m->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_O]
                                   - m->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_K] );

        //      -|E G H|
        // E' =  |I K L| = -E|K L| + G|I L| - H|I K| = G(IP-ML)-E(KP-OL)-H(IO-MK)
        //       |M O P|     |O P|    |M P|    |M O|

        d->mtx[ELR_MTX3D_E] = m->mtx[ELR_MTX3D_G]
                                *( m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_L] )
                              - m->mtx[ELR_MTX3D_E]
                                *( m->mtx[ELR_MTX3D_K]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_O]*m->mtx[ELR_MTX3D_L] )
                              - m->mtx[ELR_MTX3D_H]
                                *( m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_O]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_K] );

        //      |E F H|
        // I' = |I J L| = E|J L| - F|I L| + H|I J| = E(JP-NL)-F(IP-ML)+H(IN-MJ)
        //      |M N P|    |N P|    |M P|    |M N|

        d->mtx[ELR_MTX3D_I] = m->mtx[ELR_MTX3D_E]
                                *( m->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_L] )
                              - m->mtx[ELR_MTX3D_F]
                                *( m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_L] )
                              + m->mtx[ELR_MTX3D_H]
                                *( m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_N]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_J] );

        //      -|E F G|
        // M' =  |I J K| = -E|J K| + F|I K| - G|I J| = F(IN-MK)-E(JO-NK)-G(IN-MJ)
        //       |M N O|     |N O|    |M N|    |M N|

        d->mtx[ELR_MTX3D_M] = m->mtx[ELR_MTX3D_F]
                                *( m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_N]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_K] )
                              - m->mtx[ELR_MTX3D_E]
                                *( m->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_O]
                                   - m->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_K] )
                              - m->mtx[ELR_MTX3D_G]
                                *( m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_N]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_J] );

        //      -|B C D|
        // B' =  |J K L| = -B|K L| + C|J L| - D|J K| = C(JP-NL)-B(KP-OL)-D(JO-NK)
        //       |N O P|     |O P|    |N P|    |N O|

        d->mtx[ELR_MTX3D_B] = m->mtx[ELR_MTX3D_C]
                                *( m->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_L] )
                              - m->mtx[ELR_MTX3D_B]
                                *( m->mtx[ELR_MTX3D_K]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_O]*m->mtx[ELR_MTX3D_L] )
                              - m->mtx[ELR_MTX3D_D]
                                *( m->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_O]
                                   - m->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_K] );

        //      |A C D|
        // F' = |I K L| = A|K L| - C|I L| + D|I K|= A(KP-OL)-C(IP-ML)+D(IO-MK)
        //      |M O P|    |O P|    |M P|    |M O|

        d->mtx[ELR_MTX3D_F] = m->mtx[ELR_MTX3D_A]
                                *( m->mtx[ELR_MTX3D_K]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_O]*m->mtx[ELR_MTX3D_L] )
                              - m->mtx[ELR_MTX3D_C]
                                *( m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_L] )
                              + m->mtx[ELR_MTX3D_D]
                                *( m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_O]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_K] );

        //      -|A B D|
        // J' =  |I J L| = -A|J L| + B|I L| - D|I J| = B(IP-ML)-A(JP-NL)-D(IN-MJ)
        //       |M N P|     |N P|    |M P|    |M N|

        d->mtx[ELR_MTX3D_J] = m->mtx[ELR_MTX3D_B]
                                *( m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_L] )
                              - m->mtx[ELR_MTX3D_A]
                                *( m->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_L] )
                              - m->mtx[ELR_MTX3D_D]
                                *( m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_N]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_J] );

        //      |A B C|
        // N' = |I J K| = A|J K| - B|I K| + C|I J| = A(JO-NK)-B(IO-MK)+C(IN-MJ)
        //      |M N O|    |N O|    |M O|    |M N|

        d->mtx[ELR_MTX3D_N] = m->mtx[ELR_MTX3D_A]
                                *( m->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_O]
                                   - m->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_K] )
                              - m->mtx[ELR_MTX3D_B]
                                *( m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_O]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_K] )
                              + m->mtx[ELR_MTX3D_C]
                                *( m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_N]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_J] );

        //      |B C D|
        // C' = |F G H| = B|G H| - C|F H| + D|F G| = B(GP-OH)-C(FP-NH)+D(FO-NG)
        //      |N O P|    |O P|    |N P|    |N O|

        d->mtx[ELR_MTX3D_C] = m->mtx[ELR_MTX3D_B]
                                *( m->mtx[ELR_MTX3D_G]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_O]*m->mtx[ELR_MTX3D_H] )
                              - m->mtx[ELR_MTX3D_C]
                                *( m->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_H] )
                              + m->mtx[ELR_MTX3D_D]
                                *( m->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_O]
                                   - m->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_G] );

        //      -|A C D|
        // G' =  |E G H| = -A|G H| + C|E H| - D|E G| = C(EP-MH)-A(GP-OH)-D(EO-MG)
        //       |M O P|     |O P|    |M P|    |M O|

        d->mtx[ELR_MTX3D_G] = m->mtx[ELR_MTX3D_C]
                                *( m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_H] )
                              - m->mtx[ELR_MTX3D_A]
                                *( m->mtx[ELR_MTX3D_G]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_O]*m->mtx[ELR_MTX3D_H] )
                              - m->mtx[ELR_MTX3D_D]
                                *( m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_O]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_G] );

        //      |A B D|
        // K' = |E F H| = A|F H| - B|E H| + D|E F| =A(FP-NH)-B(EP-MH)+D(EN-MF)
        //      |M N P|    |N P|    |M P|    |M N|

        d->mtx[ELR_MTX3D_K] = m->mtx[ELR_MTX3D_A]
                                *( m->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_H] )
                              - m->mtx[ELR_MTX3D_B]
                                *( m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_P]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_H] )
                              + m->mtx[ELR_MTX3D_D]
                                *( m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_N]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_F] );

        //      -|A B C|
        // O' =  |E F G| = -A|F G| + B|E G| - C|E F| = B(EO-MG)-A(FO-NG)-C(EN-MF)
        //       |M N O|     |N O|    |M O|    |M N|

        d->mtx[ELR_MTX3D_O] = m->mtx[ELR_MTX3D_B]
                                *( m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_O]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_G] )
                              - m->mtx[ELR_MTX3D_A]
                                *( m->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_O]
                                   - m->mtx[ELR_MTX3D_N]*m->mtx[ELR_MTX3D_G] )
                              - m->mtx[ELR_MTX3D_C]
                                *( m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_N]
                                   - m->mtx[ELR_MTX3D_M]*m->mtx[ELR_MTX3D_F] );

        //      -|B C D|
        // D' =  |F G H| = -B|G H| + C|F H| - D|F G| = C(FL-JH)-B(GL-KH)-D(FK-JG)
        //       |J K L|     |K L|    |J L|    |J K|

        d->mtx[ELR_MTX3D_D] = m->mtx[ELR_MTX3D_C]
                                *( m->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_L]
                                   - m->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_H] )
                              - m->mtx[ELR_MTX3D_B]
                                *( m->mtx[ELR_MTX3D_G]*m->mtx[ELR_MTX3D_L]
                                   - m->mtx[ELR_MTX3D_K]*m->mtx[ELR_MTX3D_H] )
                              - m->mtx[ELR_MTX3D_D]
                                *( m->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_K]
                                   - m->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_G] );

        //       |A C D|
        // H' =  |E G H| = A|G H| - C|E H| + D|E G| = A(GL-KH)-C(EL-IH)+D(EK-IG)
        //       |I K L|    |K L|    |I L|    |I K|

        d->mtx[ELR_MTX3D_H] = m->mtx[ELR_MTX3D_A]
                                *( m->mtx[ELR_MTX3D_G]*m->mtx[ELR_MTX3D_L]
                                   - m->mtx[ELR_MTX3D_K]*m->mtx[ELR_MTX3D_H] )
                              - m->mtx[ELR_MTX3D_C]
                                *( m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_L]
                                   - m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_H] )
                              + m->mtx[ELR_MTX3D_D]
                                *( m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_K]
                                   - m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_G] );

        //      -|A B D|
        // L' =  |E F H| = -A|F H| + B|E H| - D|E F| = B(EL-IH)-A(FL-JH)-D(EJ-IF)
        //       |I J L|     |J L|    |I L|    |I J|

        d->mtx[ELR_MTX3D_L] = m->mtx[ELR_MTX3D_B]
                                *( m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_L]
                                   - m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_H] )
                              - m->mtx[ELR_MTX3D_A]
                                *( m->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_L]
                                   - m->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_H] )
                              - m->mtx[ELR_MTX3D_D]
                                *( m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_J]
                                   - m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_F] );

        //       |A B C|
        // P' =  |E F G| = A|F G| - B|E G| + C|E F| = A(FK-JG)-B(EK-IG)+C(EJ-IF)
        //       |I J K|    |J K|    |I K|    |I J|

        d->mtx[ELR_MTX3D_P] = m->mtx[ELR_MTX3D_A]
                                *( m->mtx[ELR_MTX3D_F]*m->mtx[ELR_MTX3D_K]
                                   - m->mtx[ELR_MTX3D_J]*m->mtx[ELR_MTX3D_G] )
                              - m->mtx[ELR_MTX3D_B]
                                *( m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_K]
                                   - m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_G] )
                              + m->mtx[ELR_MTX3D_C]
                                *( m->mtx[ELR_MTX3D_E]*m->mtx[ELR_MTX3D_J]
                                   - m->mtx[ELR_MTX3D_I]*m->mtx[ELR_MTX3D_F] );
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_fpu_inversematrix3d
//
// Computes the inverse of a 3D matrix.  Returns 1 if the inverse does not
// exist, 0 otherwise.  If 'hn' is set, then the matrix is assumed to have
// [0 0 0 1] in the last column.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
extern "C" int elr_fpu_inversematrix3d(const ElrMatrix3D *m, ElrMatrix3D *d,
                                       int hn)
{
    assertMyth("elr_fpu_inversematrix3d() needs valid input",
               m != 0 && d != 0);

//ÄÄÄ Compute determinent
    float det = m->det();

    if (det < 0.0001f && det > -0.0001f)
        return 1;

//ÄÄÄ Compute adjoint
    elr_fpu_adjointmatrix3d(m,d,hn);

//ÄÄÄ Divide by determinent.
    *d /= det;

    return 0;
}

//°±² End of module - elrfpu3d.cpp ²±°
