//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùù°°°°°°°°°°ù°°°°°°°°ùùù°°°°°°°°ùù°°°ùùùù°°°ù°°°°°°°°°°ù°°°°°°°°°ùù
//ùùùùùùùùù°±°ùùùùùùù°±°ùùùù°±°ù°±°ùùùù°±°ù°±°ùùùù°±°ù°±°ùùùùùùùù°±°ùùùù°±°ùù
//ùùùùùùùù±°±ùùùùùùù±°±ùùùùùùùù±°±ùùùùùùùù±°±ùùùù±°±ù±°±ùùùùùùùù±°±ùùùù±°±ùùù
//ùùùùùùù±²±±°±±²ùù±²±±°±±²±±ù±²±ùùùùùùùù±²±±°±±²±±ù±²±±°±±²ùùù±²±±°±±²°ùùùùù
//ùùùùùù±²±ùùùùùùùùùùùùùù±²±ù±²±ùùùùùùùù±²±ùùùù±²±ù±²±ùùùùùùùù±²±ùùùù±²±ùùùùù
//ùùùùù²±²ùùùùùùù²±²ùùùù²±²ù²±²ùùùù²±²ù²±²ùùùù²±²ù²±²ùùùùùùùù²±²ùùùù²±²ùùùùùù
//ùùùù²²²²²²²²²²ù²²²²²²²²ùùù²²²²²²²²ùù²²²ùùùù²²²ù²²²²²²²²²²ù²²²ùùùù²²²ùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùù Microsoft Windows 95/NT Version ùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùCopyrightù(c)ù1994-1998ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùAllùRightsùReserved.ùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
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
// Created by Tim Little & Chuck Walbourn
//
// esmath.cpp
//
// Contains the various arithmetic operations for the EschPoint and
// EschVector classes in the 'math' header.
//
//      esch_rotatex
//      esch_rotatey
//      esch_rotatez
//      esch_transform
//      esch_transform_notran
//
// These routines assume that the EschPoint and EschVector classes are
// identical to the assembly routine with x/i, y/j, z/k as the first
// three dwords, represented as single-precision floats math.
// 
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// esch_rotatex                                                             ³
//                                                                          ³
// This function rotates the passed in vector/point about the X-axis        ³
// by the number of degrees passed in deg.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void esch_rotatex(const void *s, const float deg, void *d)
{
//
//  (i', j', k') = rotate-about-x (i, j, k)
//
//      i' = i
//      j' = j * c + k * s
//      k' = k * c - j * s
//

    float sn = esch_sin(deg);
    float cn = esch_cos(deg);

    float newj = ((const EschVector*)s)->j*cn + ((const EschVector*)s)->k*sn;
    float newk = ((const EschVector*)s)->k*cn - ((const EschVector*)s)->j*sn;

    ((EschVector*)d)->i = ((const EschVector*)s)->i;
    ((EschVector*)d)->j = newj;
    ((EschVector*)d)->k = newk;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// esch_rotatey                                                             ³
//                                                                          ³
// This function rotates the passed in vector/point about the Y-axis        ³
// by the number of degrees passed in deg.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void esch_rotatey(const void *s, const float deg, void *d)
{
//
//  (i', j', k') = rotate-about-y (i, j, k)
//
//       i' = i * c - k * s
//       j' = j
//       k' = i * s + k * c
//

    float sn = esch_sin(deg);
    float cn = esch_cos(deg);

    float newi = ((const EschVector*)s)->i*cn - ((const EschVector*)s)->k*sn;
    float newk = ((const EschVector*)s)->i*sn + ((const EschVector*)s)->k*cn;

    ((EschVector*)d)->i = newi;
    ((EschVector*)d)->j = ((const EschVector*)s)->j;
    ((EschVector*)d)->k = newk;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// esch_rotatez                                                             ³
//                                                                          ³
// This function rotates the passed in vector/point about the Z-axis        ³
// by the number of degrees passed in deg.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void esch_rotatez(const void *s,const float deg, void *d)
{
//
//  (i', j', k') = rotate-about-x (i, j, k)
//
//       i' = i * c + j * s
//       j' = j * c - i * s 
//       k' = k
//

    float sn = esch_sin(deg);
    float cn = esch_cos(deg);

    float newi = ((const EschVector*)s)->i*cn + ((const EschVector*)s)->j*sn;
    float newj = ((const EschVector*)s)->j*cn - ((const EschVector*)s)->i*sn;

    ((EschVector*)d)->i = newi;
    ((EschVector*)d)->j = newj;
    ((EschVector*)d)->k = ((const EschVector*)s)->k;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// esch_transform                                                           ³
//                                                                          ³
// This transforms the vector/point by the matrix 'm'.                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void esch_transform(const void *s, const EschMatrix *m, void *d)
{
//
//             [A B C 0]   [ Ai+Dj+Gk+J ]
// [i j k 1] * [D E F 0] = [ Bi+Ej+Hk+K ]
//             [G H I 0]   [ Ci+Fj+Ik+L ]
//             [J K L 1]   [      1     ]
//

    float newi = m->mtx[ESCH_MTX_A]*((const EschVector*)s)->i
                 + m->mtx[ESCH_MTX_D]*((const EschVector*)s)->j
                 + m->mtx[ESCH_MTX_G]*((const EschVector*)s)->k
                 + m->mtx[ESCH_MTX_J];

    float newj = m->mtx[ESCH_MTX_B]*((const EschVector*)s)->i
                 + m->mtx[ESCH_MTX_E]*((const EschVector*)s)->j
                 + m->mtx[ESCH_MTX_H]*((const EschVector*)s)->k
                 + m->mtx[ESCH_MTX_K];

    float newk = m->mtx[ESCH_MTX_C]*((const EschVector*)s)->i
                 + m->mtx[ESCH_MTX_F]*((const EschVector*)s)->j
                 + m->mtx[ESCH_MTX_I]*((const EschVector*)s)->k
                 + m->mtx[ESCH_MTX_L];

    ((EschVector*)d)->i = newi;
    ((EschVector*)d)->j = newj;
    ((EschVector*)d)->k = newk;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// esch_transform_notran                                                    ³
//                                                                          ³
// This transforms the vector/point by the matrix 'm' ignoring translation. ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void esch_transform_notran(const void *s,const EschMatrix *m,
                                      void *d)
{
//
//             [A B C 0]   [ Ai+Dj+Gk ]
// [i j k 1] * [D E F 0] = [ Bi+Ej+Hk ]
//             [G H I 0]   [ Ci+Fj+Ik ]
//             [J K L 1]   [    1     ]
//

    float newi = m->mtx[ESCH_MTX_A]*((const EschVector*)s)->i
                 + m->mtx[ESCH_MTX_D]*((const EschVector*)s)->j
                 + m->mtx[ESCH_MTX_G]*((const EschVector*)s)->k;

    float newj = m->mtx[ESCH_MTX_B]*((const EschVector*)s)->i
                 + m->mtx[ESCH_MTX_E]*((const EschVector*)s)->j
                 + m->mtx[ESCH_MTX_H]*((const EschVector*)s)->k;

    float newk = m->mtx[ESCH_MTX_C]*((const EschVector*)s)->i
                 + m->mtx[ESCH_MTX_F]*((const EschVector*)s)->j
                 + m->mtx[ESCH_MTX_I]*((const EschVector*)s)->k;

    ((EschVector*)d)->i = newi;
    ((EschVector*)d)->j = newj;
    ((EschVector*)d)->k = newk;
}

//°±² End of module - esmath.cpp ²±°

