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
//ùùùùùùùùùùùùùùùùù Microsoft Windows 95/98/NT Version ùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùCopyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbournùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
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
// Created by Tim Little & Chuck Walbourn
//
// esfref.cpp
//
// Contains the EschFrameRef utility functions.  The EschFrameRef class
// is used to provide conversions of one frame-of-reference to another
// via transformation, as well as the inverse operation.  Various affine
// transformations may be put into frames-of-reference.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define INCREMENTAL_INVERSE

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - set_position                                              ³
//                                                                          ³
// Sets the position of the frame-of-reference in world coordinates.        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::set_position(const EschPoint *pt, dword update)
{
    orient.mtx[ESCH_MTX_J] = pt->x;
    orient.mtx[ESCH_MTX_K] = pt->y;
    orient.mtx[ESCH_MTX_L] = pt->z;

//ÄÄÄ Update inverse transform
    if (update & ESCH_UPD_INVERSE)
    {
        orient.inverse(&iorient);
    }
}

void EschFrameRef::set_position(const float ix, const float iy, const float iz,
                                dword update)

{
    orient.mtx[ESCH_MTX_J] = ix;
    orient.mtx[ESCH_MTX_K] = iy;
    orient.mtx[ESCH_MTX_L] = iz;

//ÄÄÄ Update inverse transform
    if (update & ESCH_UPD_INVERSE)
    {
        orient.inverse(&iorient);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - set_top                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::set_top(const EschVector *v, dword update)
{
    EschVector top(v->i, v->j, v->k);
    top.normalize();

//ÄÄÄ Create right vector
    EschVector right = top CROSS dir;

//ÄÄÄ Fill in matrix for ortho rotation

    //ÄÄÄ Transform
    orient.mtx[ESCH_MTX_A] = right.i;
    orient.mtx[ESCH_MTX_B] = right.j;
    orient.mtx[ESCH_MTX_C] = right.k;

    orient.mtx[ESCH_MTX_D] = top.i;
    orient.mtx[ESCH_MTX_E] = top.j;
    orient.mtx[ESCH_MTX_F] = top.k;

    if (update & ESCH_UPD_ORTHO)
        orthogonalize_top(update);
    else if (update & ESCH_UPD_INVERSE)
        compute_inverse();
}

void EschFrameRef::set_top(float ii, float ij, float ik, dword update)
{
    EschVector v(ii,ij,ik);
    v.normalize();

//ÄÄÄ Create right vector
    EschVector right = v CROSS dir;

//ÄÄÄ Fill in matrix for ortho rotation

    //ÄÄÄ Transform
    orient.mtx[ESCH_MTX_A] = right.i;
    orient.mtx[ESCH_MTX_B] = right.j;
    orient.mtx[ESCH_MTX_C] = right.k;

    orient.mtx[ESCH_MTX_D] = v.i;
    orient.mtx[ESCH_MTX_E] = v.j;
    orient.mtx[ESCH_MTX_F] = v.k;

    if (update & ESCH_UPD_ORTHO)
        orthogonalize_top(update);
    else if (update & ESCH_UPD_INVERSE)
        compute_inverse();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - set_direction                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::set_direction(const EschVector *v, dword update)
{
    dir = *v;
    dir.normalize();

    EschVector  top(orient.mtx[ESCH_MTX_D],
                    orient.mtx[ESCH_MTX_E],
                    orient.mtx[ESCH_MTX_F]);

//ÄÄÄ Create right vector
    EschVector right = top CROSS dir;

//ÄÄÄ Fill in matrix for ortho rotation

    //ÄÄÄ Transform
    orient.mtx[ESCH_MTX_A] = right.i;
    orient.mtx[ESCH_MTX_B] = right.j;
    orient.mtx[ESCH_MTX_C] = right.k;

    orient.mtx[ESCH_MTX_G] = dir.i;
    orient.mtx[ESCH_MTX_H] = dir.j;
    orient.mtx[ESCH_MTX_I] = dir.k;

    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_INVERSE)
        compute_inverse();
}

void EschFrameRef::set_direction(float ii, float ij, float ik, dword update)
{
    dir.i = ii;
    dir.j = ij;
    dir.k = ik;
    dir.normalize();

    EschVector  top(orient.mtx[ESCH_MTX_D],
                    orient.mtx[ESCH_MTX_E],
                    orient.mtx[ESCH_MTX_F]);

//ÄÄÄ Create right vector
    EschVector right = top CROSS dir;

//ÄÄÄ Fill in matrix for ortho rotation

    //ÄÄÄ Transform
    orient.mtx[ESCH_MTX_A] = right.i;
    orient.mtx[ESCH_MTX_B] = right.j;
    orient.mtx[ESCH_MTX_C] = right.k;

    orient.mtx[ESCH_MTX_G] = dir.i;
    orient.mtx[ESCH_MTX_H] = dir.j;
    orient.mtx[ESCH_MTX_I] = dir.k;

    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_INVERSE)
        compute_inverse();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - rotatex                                                   ³
//                                                                          ³
// Appends a rotation about X to the frame of reference.                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::rotatex(const float degrees, dword update)
{
    float   m[3];

    float s=esch_sin(degrees);
    float c=esch_cos(degrees);

//ÄÄÄ Append transform

    // [A B C 0]   [1  0  0  0]   [1 0  0 0]   [1 0 0 0]   [A Bc-Cs Bs+Cc 0]
    // [D E F 0] * [0  1  0  0] * [0 c  s 0] * [0 1 0 0] = [D Ec-Fs Es+Fc 0]
    // [G H I 0]   [0  0  1  0]   [0 -s c 0]   [0 0 1 0]   [G Hc-Is Hs+Ic 0]
    // [J K L 1]   [-J -K -L 1]   [0 0  0 1]   [J K L 1]   [J K     L     1]

    m[0] = orient.mtx[ESCH_MTX_B]*c - orient.mtx[ESCH_MTX_C]*s;
    m[1] = orient.mtx[ESCH_MTX_E]*c - orient.mtx[ESCH_MTX_F]*s;
    m[2] = orient.mtx[ESCH_MTX_H]*c - orient.mtx[ESCH_MTX_I]*s;

    orient.mtx[ESCH_MTX_C] = orient.mtx[ESCH_MTX_B]*s
                             + orient.mtx[ESCH_MTX_C]*c;
    orient.mtx[ESCH_MTX_F] = orient.mtx[ESCH_MTX_E]*s
                             + orient.mtx[ESCH_MTX_F]*c;
    orient.mtx[ESCH_MTX_I] = orient.mtx[ESCH_MTX_H]*s
                             + orient.mtx[ESCH_MTX_I]*c;

    orient.mtx[ESCH_MTX_B] = m[0];
    orient.mtx[ESCH_MTX_E] = m[1];
    orient.mtx[ESCH_MTX_H] = m[2];

    dir.i = orient.mtx[ESCH_MTX_G];
    dir.j = orient.mtx[ESCH_MTX_H];
    dir.k = orient.mtx[ESCH_MTX_I];
    dir.normalize();

//ÄÄÄ Orthogonalize
    if ((++ortho_count > ESCH_MAX_ORTHOCOUNT) && (update & ESCH_UPD_ORTHO))
        orthogonalize(update);

//ÄÄÄ Update inverse transform
    else if (update & ESCH_UPD_INVERSE)
    {
#ifdef INCREMENTAL_INVERSE
        float n[3];

        // [1  0  0  0]   [1 0  0  0]   [1 0 0 0]   [A B C 0]
        // [0  1  0  0] * [0 c  -s 0] * [0 1 0 0] * [D E F 0]
        // [0  0  1  0]   [0 s  c  0]   [0 0 1 0]   [G H I 0]
        // [-j -k -l 1]   [0 0  0  1]   [j k l 1]   [J K L 1]
        //
        //   [A           B           C           0]
        // = [Dc-Gs       Ec-Hs       Fc-Is       0]
        //   [Ds+Gc       Es+Hc       Fs+Ic       0]
        //   [D(-kc-ls+k) E(-kc-ls+k) F(-kc-ls+k) 1]
        //    +G(ks-lc+l) +H(ks-lc+l) +I(ks-lc+l)
        //    +J          +K          +L

        float t1 = orient.mtx[ESCH_MTX_K]
                   - orient.mtx[ESCH_MTX_K]*c - orient.mtx[ESCH_MTX_L]*s;

        float t2 = orient.mtx[ESCH_MTX_L]
                   + orient.mtx[ESCH_MTX_K]*s - orient.mtx[ESCH_MTX_L]*c;

        m[0] = iorient.mtx[ESCH_MTX_D]*c - iorient.mtx[ESCH_MTX_G]*s;
        n[0] = iorient.mtx[ESCH_MTX_D]*s + iorient.mtx[ESCH_MTX_G]*c;

        m[1] = iorient.mtx[ESCH_MTX_E]*c - iorient.mtx[ESCH_MTX_H]*s;
        n[1] = iorient.mtx[ESCH_MTX_E]*s + iorient.mtx[ESCH_MTX_H]*c;

        m[2] = iorient.mtx[ESCH_MTX_F]*c - iorient.mtx[ESCH_MTX_I]*s;
        n[2] = iorient.mtx[ESCH_MTX_F]*s + iorient.mtx[ESCH_MTX_I]*c;

        iorient.mtx[ESCH_MTX_J] += iorient.mtx[ESCH_MTX_D]*t1
                                   + iorient.mtx[ESCH_MTX_G]*t2;
        iorient.mtx[ESCH_MTX_K] += iorient.mtx[ESCH_MTX_E]*t1
                                   + iorient.mtx[ESCH_MTX_H]*t2;
        iorient.mtx[ESCH_MTX_L] += iorient.mtx[ESCH_MTX_F]*t1
                                   + iorient.mtx[ESCH_MTX_I]*t2;

        iorient.mtx[ESCH_MTX_D] = m[0];
        iorient.mtx[ESCH_MTX_E] = m[1];
        iorient.mtx[ESCH_MTX_F] = m[2];

        iorient.mtx[ESCH_MTX_G] = n[0];
        iorient.mtx[ESCH_MTX_H] = n[1];
        iorient.mtx[ESCH_MTX_I] = n[2];
#else
        orient.inverse(&iorient);
#endif
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - rotatey                                                   ³
//                                                                          ³
// Appends a rotation about Y to the frame of reference.                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::rotatey(const float degrees, dword update)
{
    float   m[3];

    float s=esch_sin(degrees);
    float c=esch_cos(degrees);

//ÄÄÄ Append transform

    // [A B C 0]   [1  0  0  0]   [c 0 -s 0]   [1 0 0 0]   [Ac+Cs B Cc-As 0]
    // [D E F 0] * [0  1  0  0] * [0 1 0  0] * [0 1 0 0] = [Dc+Fs E Fc-Ds 0]
    // [G H I 0]   [0  0  1  0]   [s 0 c  0]   [0 0 1 0]   [Gc+Is H Ic-Gs 0]
    // [J K L 1]   [-J -K -L 1]   [0 0 0  1]   [J K L 1]   [J     K L     1]

    m[0] = orient.mtx[ESCH_MTX_A]*c + orient.mtx[ESCH_MTX_C]*s;
    m[1] = orient.mtx[ESCH_MTX_D]*c + orient.mtx[ESCH_MTX_F]*s;
    m[2] = orient.mtx[ESCH_MTX_G]*c + orient.mtx[ESCH_MTX_I]*s;

    orient.mtx[ESCH_MTX_C] = orient.mtx[ESCH_MTX_C]*c
                             - orient.mtx[ESCH_MTX_A]*s;
    orient.mtx[ESCH_MTX_F] = orient.mtx[ESCH_MTX_F]*c
                             - orient.mtx[ESCH_MTX_D]*s;
    orient.mtx[ESCH_MTX_I]= orient.mtx[ESCH_MTX_I]*c
                            - orient.mtx[ESCH_MTX_G]*s;

    orient.mtx[ESCH_MTX_A] = m[0];
    orient.mtx[ESCH_MTX_D] = m[1];
    orient.mtx[ESCH_MTX_G] = m[2];

    dir.i = orient.mtx[ESCH_MTX_G];
    dir.j = orient.mtx[ESCH_MTX_H];
    dir.k = orient.mtx[ESCH_MTX_I];
    dir.normalize();

//ÄÄÄ Orthogonalize
    if ((++ortho_count > ESCH_MAX_ORTHOCOUNT) && (update & ESCH_UPD_ORTHO))
        orthogonalize(update);

//ÄÄÄ Update inverse transform
    else if (update & ESCH_UPD_INVERSE)
    {
#ifdef INCREMENTAL_INVERSE
        float n[3];

        // [1  0  0  0]   [c  0 s 0]   [1 0 0 0]   [A B C 0]
        // [0  1  0  0] * [0  1 0 0] * [0 1 0 0] * [D E F 0]
        // [0  0  1  0]   [-s 0 c 0]   [0 0 1 0]   [G H I 0]
        // [-j -k -l 1]   [0  0 0 1]   [j k l 1]   [J K L 1]
        //
        //   [Ac+Gs        Bc+Hs        Cc+Is       0]
        // = [D            E            F           0]
        //   [Gc-As        Hc-Bs        Ic-Cs       0]
        //   [A(j-jc+ls)   B(j-jc+ls)   C(j-jc+ls)  1]
        //    +G(l-js-lc)  +H(l-js-lc)  +I(l-js-lc)
        //    +J           +K           +L

        float t1 = orient.mtx[ESCH_MTX_J]
                   - orient.mtx[ESCH_MTX_J]*c + orient.mtx[ESCH_MTX_L]*s;

        float t2 = orient.mtx[ESCH_MTX_L]
                   - orient.mtx[ESCH_MTX_J]*s - orient.mtx[ESCH_MTX_L]*c;

        m[0] = iorient.mtx[ESCH_MTX_A]*c + iorient.mtx[ESCH_MTX_G]*s;
        n[0] = iorient.mtx[ESCH_MTX_G]*c - iorient.mtx[ESCH_MTX_A]*s;

        m[1] = iorient.mtx[ESCH_MTX_B]*c + iorient.mtx[ESCH_MTX_H]*s;
        n[1] = iorient.mtx[ESCH_MTX_H]*c - iorient.mtx[ESCH_MTX_B]*s;

        m[2] = iorient.mtx[ESCH_MTX_C]*c + iorient.mtx[ESCH_MTX_I]*s;
        n[2] = iorient.mtx[ESCH_MTX_I]*c - iorient.mtx[ESCH_MTX_C]*s;

        iorient.mtx[ESCH_MTX_J] += iorient.mtx[ESCH_MTX_A]*t1
                                   + iorient.mtx[ESCH_MTX_G]*t2;
        iorient.mtx[ESCH_MTX_K] += iorient.mtx[ESCH_MTX_B]*t1
                                   + iorient.mtx[ESCH_MTX_H]*t2;
        iorient.mtx[ESCH_MTX_L] += iorient.mtx[ESCH_MTX_C]*t1
                                   + iorient.mtx[ESCH_MTX_I]*t2;

        iorient.mtx[ESCH_MTX_A] = m[0];
        iorient.mtx[ESCH_MTX_B] = m[1];
        iorient.mtx[ESCH_MTX_C] = m[2];

        iorient.mtx[ESCH_MTX_G] = n[0];
        iorient.mtx[ESCH_MTX_H] = n[1];
        iorient.mtx[ESCH_MTX_I] = n[2];
#else
        orient.inverse(&iorient);
#endif
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - rotatez                                                   ³
//                                                                          ³
// Appends a rotation about Z to the frame of reference.                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::rotatez(const float degrees, dword update)
{
    float   m[3];

    float s=esch_sin(degrees);
    float c=esch_cos(degrees);

//ÄÄÄ Append transform

    // [A B C 0]   [1  0  0  0]   [c  s 0 0]   [1 0 0 0]   [Ac-Bs As+Bc C 0]
    // [D E F 0] * [0  1  0  0] * [-s c 0 0] * [0 1 0 0] = [Dc-Es Ds+Ec F 0]
    // [G H I 0]   [0  0  1  0]   [0  0 1 0]   [0 0 1 0]   [Gc-Hs Gs+Hc I 0]
    // [J K L 1]   [-J -K -L 1]   [0  0 0 1]   [J K L 1]   [J     K     L 1]

    m[0] = orient.mtx[ESCH_MTX_A]*c - orient.mtx[ESCH_MTX_B]*s;
    m[1] = orient.mtx[ESCH_MTX_D]*c - orient.mtx[ESCH_MTX_E]*s;
    m[2] = orient.mtx[ESCH_MTX_G]*c - orient.mtx[ESCH_MTX_H]*s;

    orient.mtx[ESCH_MTX_B]= orient.mtx[ESCH_MTX_A]*s
                            + orient.mtx[ESCH_MTX_B]*c;
    orient.mtx[ESCH_MTX_E]= orient.mtx[ESCH_MTX_D]*s
                            + orient.mtx[ESCH_MTX_E]*c;
    orient.mtx[ESCH_MTX_H]= orient.mtx[ESCH_MTX_G]*s
                            + orient.mtx[ESCH_MTX_H]*c;

    orient.mtx[ESCH_MTX_A] = m[0];
    orient.mtx[ESCH_MTX_D] = m[1];
    orient.mtx[ESCH_MTX_G] = m[2];

    dir.i = orient.mtx[ESCH_MTX_G];
    dir.j = orient.mtx[ESCH_MTX_H];
    dir.k = orient.mtx[ESCH_MTX_I];
    dir.normalize();

//ÄÄÄ Orthogonalize
    if ((++ortho_count > ESCH_MAX_ORTHOCOUNT) && (update & ESCH_UPD_ORTHO))
        orthogonalize(update);

//ÄÄÄ Update inverse transform
    else if (update & ESCH_UPD_INVERSE)
    {
#ifdef INCREMENTAL_INVERSE
        float n[3];

        // [1  0  0  0]   [c -s 0 0]   [1 0 0 0]   [A B C 0]
        // [0  1  0  0] * [s c  0 0] * [0 1 0 0] * [D E F 0]
        // [0  0  1  0]   [0 0  1 0]   [0 0 1 0]   [G H I 0]
        // [-j -k -l 1]   [0 0  0 1]   [j k l 1]   [J K L 1]
        //
        //   [Ac-Ds       Bc-Es       Cc-Fs       0]
        // = [As+Dc       Bs+Es       Cs+Fs       0]
        //   [G           H           I           0]
        //   [A(j-jc-ks)  B(j-jc-ks)  C(j-jc-ks)  1]
        //    +D(k+js-kc) +E(k+js-kc) +F(k+js-kc)
        //    +J          +K          +L

        float t1 = orient.mtx[ESCH_MTX_J]
                   - orient.mtx[ESCH_MTX_J]*c - orient.mtx[ESCH_MTX_K]*s;

        float t2 = orient.mtx[ESCH_MTX_K]
                   + orient.mtx[ESCH_MTX_J]*s - orient.mtx[ESCH_MTX_K]*c;

        m[0] = iorient.mtx[ESCH_MTX_A]*c - iorient.mtx[ESCH_MTX_D]*s;
        n[0] = iorient.mtx[ESCH_MTX_A]*s + iorient.mtx[ESCH_MTX_D]*c;

        m[1] = iorient.mtx[ESCH_MTX_B]*c - iorient.mtx[ESCH_MTX_E]*s;
        n[1] = iorient.mtx[ESCH_MTX_B]*s + iorient.mtx[ESCH_MTX_E]*c;

        m[2] = iorient.mtx[ESCH_MTX_C]*c - iorient.mtx[ESCH_MTX_F]*s;
        n[2] = iorient.mtx[ESCH_MTX_C]*s + iorient.mtx[ESCH_MTX_F]*c;

        iorient.mtx[ESCH_MTX_J] += iorient.mtx[ESCH_MTX_A]*t1
                                   + iorient.mtx[ESCH_MTX_D]*t2;

        iorient.mtx[ESCH_MTX_K] += iorient.mtx[ESCH_MTX_B]*t1
                                   + iorient.mtx[ESCH_MTX_E]*t2;

        iorient.mtx[ESCH_MTX_L] += iorient.mtx[ESCH_MTX_C]*t1
                                   + iorient.mtx[ESCH_MTX_F]*t2;

        iorient.mtx[ESCH_MTX_A] = m[0];
        iorient.mtx[ESCH_MTX_B] = m[1];
        iorient.mtx[ESCH_MTX_C] = m[2];

        iorient.mtx[ESCH_MTX_D] = n[0];
        iorient.mtx[ESCH_MTX_E] = n[1];
        iorient.mtx[ESCH_MTX_F] = n[2];
#else
        orient.inverse(&iorient);
#endif
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - translate                                                 ³
//                                                                          ³
// Appends a translation to the frame of reference.                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::translate(const EschVector *v, dword update)
{
//ÄÄÄ Append transform
    // [A B C 0]   [1 0 0 0]   [A   B   C   0]
    // [D E F 0] * [0 1 0 0] = [D   E   F   0]
    // [G H I 0]   [0 0 1 0]   [G   H   I   0]
    // [J K L 1]   [x y z 1]   [J+x K+y L+z 1]

    orient.mtx[ESCH_MTX_J] = orient.mtx[ESCH_MTX_J] + v->i;
    orient.mtx[ESCH_MTX_K] = orient.mtx[ESCH_MTX_K] + v->j;
    orient.mtx[ESCH_MTX_L] = orient.mtx[ESCH_MTX_L] + v->k;

//ÄÄÄ Update inverse transform
    if (update & ESCH_UPD_INVERSE)
    {
#ifdef INCREMENTAL_INVERSE
        // [ 1  0  0 0]   [A B C 0]   [A           B           C           0]
        // [ 0  1  0 0] * [D E F 0] = [D           E           F           0]
        // [ 0  0  1 0]   [G H I 0]   [G           H           I           0]
        // [-x -y -z 1]   [J K L 1]   [-xA-Dy-Gz+J -xB-yE-zH+K -xC-yF-zI+L 1]

        iorient.mtx[ESCH_MTX_J] = iorient.mtx[ESCH_MTX_J]
                                  - iorient.mtx[ESCH_MTX_A]*v->i
                                  - iorient.mtx[ESCH_MTX_D]*v->j
                                  - iorient.mtx[ESCH_MTX_G]*v->k;

        iorient.mtx[ESCH_MTX_K] = iorient.mtx[ESCH_MTX_K]
                                  - iorient.mtx[ESCH_MTX_B]*v->i
                                  - iorient.mtx[ESCH_MTX_E]*v->j
                                  - iorient.mtx[ESCH_MTX_H]*v->k;

        iorient.mtx[ESCH_MTX_L] = iorient.mtx[ESCH_MTX_L]
                                  - iorient.mtx[ESCH_MTX_C]*v->i
                                  - iorient.mtx[ESCH_MTX_F]*v->j
                                  - iorient.mtx[ESCH_MTX_I]*v->k;
#else
        orient.inverse(&iorient);
#endif
    }
}

void EschFrameRef::translate(const float idx, const float idy, const float idz,
                             dword update)
{
//ÄÄÄ Append transform
    // [A B C 0]   [1 0 0 0]   [A   B   C   0]
    // [D E F 0] * [0 1 0 0] = [D   E   F   0]
    // [G H I 0]   [0 0 1 0]   [G   H   I   0]
    // [J K L 1]   [x y z 1]   [J+x K+y L+z 1]

    orient.mtx[ESCH_MTX_J] = orient.mtx[ESCH_MTX_J] + idx;
    orient.mtx[ESCH_MTX_K] = orient.mtx[ESCH_MTX_K] + idy;
    orient.mtx[ESCH_MTX_L] = orient.mtx[ESCH_MTX_L] + idz;

//ÄÄÄ Update inverse transform
    if (update & ESCH_UPD_INVERSE)
    {
#ifdef INCREMENTAL_INVERSE
        // [ 1  0  0 0]   [A B C 0]   [A           B           C           0]
        // [ 0  1  0 0] * [D E F 0] = [D           E           F           0]
        // [ 0  0  1 0]   [G H I 0]   [G           H           I           0]
        // [-x -y -z 1]   [J K L 1]   [-xA-Dy-Gz+J -xB-yE-zH+K -xC-yF-zI+L 1]

        iorient.mtx[ESCH_MTX_J] = iorient.mtx[ESCH_MTX_J]
                                  - iorient.mtx[ESCH_MTX_A]*idx
                                  - iorient.mtx[ESCH_MTX_D]*idy
                                  - iorient.mtx[ESCH_MTX_G]*idz;

        iorient.mtx[ESCH_MTX_K] = iorient.mtx[ESCH_MTX_K]
                                  - iorient.mtx[ESCH_MTX_B]*idx
                                  - iorient.mtx[ESCH_MTX_E]*idy
                                  - iorient.mtx[ESCH_MTX_H]*idz;

        iorient.mtx[ESCH_MTX_L] = iorient.mtx[ESCH_MTX_L]
                                  - iorient.mtx[ESCH_MTX_C]*idx
                                  - iorient.mtx[ESCH_MTX_F]*idy
                                  - iorient.mtx[ESCH_MTX_I]*idz;
#else
        orient.inverse(&iorient);
#endif
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - move                                                      ³
//                                                                          ³
// Appends a translation to the frame of reference along it's current       ³
// I, J, and K axises.                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::move(const EschVector *v, dword update)
{
    EschVector t;
    v->transform(&orient,&t);

    translate(t.i, t.j, t.k, update);
}

void EschFrameRef::move(const float idx, const float idy, const float idz,
                        dword update)
{
    EschVector   t(idx,idy,idz);

    t.transform(&orient);

    translate(t.i, t.j, t.k, update);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - scale                                                     ³
//                                                                          ³
// Appends a 3D scale factor to the frame of reference.                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::scale(const float is, dword update)
{
    assertMyth("EschFrameRef::scale must be positive", is > 0);

    scalef = scalef * is;

//ÄÄÄ Append transform
    // [A B C 0]   [1  0  0  0]   [s 0 0 0]   [1 0 0 0]   [As Bs Cs 0]
    // [D E F 0] * [0  1  0  0] * [0 s 0 0] * [0 1 0 0] = [Ds Es Fs 0]
    // [G H I 0]   [0  0  1  0]   [0 0 s 0]   [0 0 1 0]   [Gs Hs Is 0]
    // [J K L 1]   [-J -K -L 1]   [0 0 0 1]   [J K L 1]   [J  K  L  1]

    orient.mtx[ESCH_MTX_A] *= is;
    orient.mtx[ESCH_MTX_B] *= is;
    orient.mtx[ESCH_MTX_C] *= is;
    orient.mtx[ESCH_MTX_D] *= is;
    orient.mtx[ESCH_MTX_E] *= is;
    orient.mtx[ESCH_MTX_F] *= is;
    orient.mtx[ESCH_MTX_G] *= is;
    orient.mtx[ESCH_MTX_H] *= is;
    orient.mtx[ESCH_MTX_I] *= is;

//ÄÄÄ Update inverse transform
    if (update & ESCH_UPD_INVERSE)
    {
#ifdef INCREMENTAL_INVERSE
        float sp = 1.0f / is;

        // [1  0  0  0]   [s' 0  0  0]   [1 0 0 0]   [A B C 0]
        // [0  1  0  0] * [0  s' 0  0] * [0 1 0 0] * [D E F 0]
        // [0  0  1  0]   [0  0  s' 0]   [0 0 1 0]   [G H I 0]
        // [-j -k -l 1]   [0  0  0  1]   [j k l 1]   [J K L 1]
        //
        //   [As'       Bs'       Cs'       0]
        // = [Ds'       Es'       Fs'       0]
        //   [G's       Hs'       Is'       0]
        //   [A(j-js')  B(j-js')  C(j-js')  1]
        //    +D(k-ks') +E(k-ks') F(k-ks')
        //    +G(l-ls') +H(l-ls') I(l-ls')
        //    +J        +K        +L

        float t1 = orient.mtx[ESCH_MTX_J] - orient.mtx[ESCH_MTX_J]*sp;
        float t2 = orient.mtx[ESCH_MTX_K] - orient.mtx[ESCH_MTX_K]*sp;
        float t3 = orient.mtx[ESCH_MTX_L] - orient.mtx[ESCH_MTX_L]*sp;

        iorient.mtx[ESCH_MTX_J] += iorient.mtx[ESCH_MTX_A]*t1
                                   + iorient.mtx[ESCH_MTX_D]*t2
                                   + iorient.mtx[ESCH_MTX_G]*t3;

        iorient.mtx[ESCH_MTX_K] += iorient.mtx[ESCH_MTX_B]*t1
                                   + iorient.mtx[ESCH_MTX_E]*t2
                                   + iorient.mtx[ESCH_MTX_H]*t3;

        iorient.mtx[ESCH_MTX_L] += iorient.mtx[ESCH_MTX_C]*t1
                                   + iorient.mtx[ESCH_MTX_F]*t2
                                   + iorient.mtx[ESCH_MTX_I]*t3;

        iorient.mtx[ESCH_MTX_A] *= sp;
        iorient.mtx[ESCH_MTX_B] *= sp;
        iorient.mtx[ESCH_MTX_C] *= sp;
        iorient.mtx[ESCH_MTX_D] *= sp;
        iorient.mtx[ESCH_MTX_E] *= sp;
        iorient.mtx[ESCH_MTX_F] *= sp;
        iorient.mtx[ESCH_MTX_G] *= sp;
        iorient.mtx[ESCH_MTX_H] *= sp;
        iorient.mtx[ESCH_MTX_I] *= sp;
#else
        orient.inverse(&iorient);
#endif
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - orthogonalize                                             ³
//                                                                          ³
// Ensures that the matrix is an orthonormal basis, ensuring that no        ³
// undesired scaling or shearing occurrs due to accumulated error in updates³
// from rotations, using the direction vector as the first basis.           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::orthogonalize(dword update)
{
    ortho_count = 0;

//ÄÄÄ Get vectors to form into orthonormal basis
    // dir is already a normalized copy of mtx[G,H,I], so use dir as v1
    float mag;
    EschVector right(orient.mtx[ESCH_MTX_A],
                     orient.mtx[ESCH_MTX_B],
                     orient.mtx[ESCH_MTX_C]);

    EschVector top(orient.mtx[ESCH_MTX_D],
                   orient.mtx[ESCH_MTX_E],
                   orient.mtx[ESCH_MTX_F]);

//ÄÄÄ Compute orthonormal basis using Gram-Schmidt process
    top = top - dir*(top DOT dir);
    mag = top.magnitude();
    if (mag > 0)
    {
        top /= mag;

        right = right - dir*(right DOT dir) - top*(right DOT top);
        mag = right.magnitude();
        if (mag > 0)
        {
            right /= mag;
        }
        else
        {
            right = top CROSS dir;
        }
    }
    else
    {
        right = right - dir*(right DOT dir);
        mag = right.magnitude();

        assertMyth("EschFrameRef::orthogonalize input is invalid",
                   mag > 0);

        right /= mag;

        top = dir CROSS right;
    }

//ÄÄÄ Put new vectors into matrix
    orient.mtx[ESCH_MTX_A] = right.i * scalef;
    orient.mtx[ESCH_MTX_B] = right.j * scalef;
    orient.mtx[ESCH_MTX_C] = right.k * scalef;

    orient.mtx[ESCH_MTX_D] = top.i * scalef;
    orient.mtx[ESCH_MTX_E] = top.j * scalef;
    orient.mtx[ESCH_MTX_F] = top.k * scalef;

    orient.mtx[ESCH_MTX_G] = dir.i * scalef;
    orient.mtx[ESCH_MTX_H] = dir.j * scalef;
    orient.mtx[ESCH_MTX_I] = dir.k * scalef;

//ÄÄÄ Update inverse transform
    if (update & ESCH_UPD_INVERSE)
        orient.inverse(&iorient);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - orthogonalize_top                                         ³
//                                                                          ³
// Ensures that the matrix is an orthonormal basis, ensuring that no        ³
// undesired scaling or shearing occurrs due to accumulated error in updates³
// from rotations, using the 'top' vector as the first basis.               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::orthogonalize_top(dword update)
{
    ortho_count = 0;

//ÄÄÄ Get vectors to form into orthonormal basis
    // dir is already a normalized copy of mtx[G,H,I], so use dir as v1

    float mag;
    EschVector right(orient.mtx[ESCH_MTX_A],
                     orient.mtx[ESCH_MTX_B],
                     orient.mtx[ESCH_MTX_C]);

    EschVector top(orient.mtx[ESCH_MTX_D],
                   orient.mtx[ESCH_MTX_E],
                   orient.mtx[ESCH_MTX_F]);

//ÄÄÄ Compute orthonormal basis using Gram-Schmidt process
    mag = top.magnitude();
    assertMyth("EschFrameRef::orthogonalize_top input is invalid",
                mag > 0);
    top /= mag;

    dir = dir - top*(dir DOT top);
    mag = dir.magnitude();
    if (mag > 0)
    {
        dir /= mag;

        right = right - dir*(right DOT dir) - top*(right DOT top);
        mag = right.magnitude();
        if (mag > 0)
        {
            right /= mag;
        }
        else
        {
            right = top CROSS dir;
        }
    }
    else
    {
        right = right - top*(right DOT top);
        mag = right.magnitude();

        assertMyth("EschFrameRef::orthogonalize_top input is invalid",
                   mag > 0);

        right /= mag;

        dir = right CROSS top;
    }

//ÄÄÄ Put new vectors into matrix
    orient.mtx[ESCH_MTX_A] = right.i * scalef;
    orient.mtx[ESCH_MTX_B] = right.j * scalef;
    orient.mtx[ESCH_MTX_C] = right.k * scalef;

    orient.mtx[ESCH_MTX_D] = top.i * scalef;
    orient.mtx[ESCH_MTX_E] = top.j * scalef;
    orient.mtx[ESCH_MTX_F] = top.k * scalef;

    orient.mtx[ESCH_MTX_G] = dir.i * scalef;
    orient.mtx[ESCH_MTX_H] = dir.j * scalef;
    orient.mtx[ESCH_MTX_I] = dir.k * scalef;

//ÄÄÄ Update inverse transform
    if (update & ESCH_UPD_INVERSE)
        orient.inverse(&iorient);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - orthogonalize_right                                       ³
//                                                                          ³
// Ensures that the matrix is an orthonormal basis, ensuring that no        ³
// undesired scaling or shearing occurrs due to accumulated error in updates³
// from rotations, using the 'right' vector as the first basis.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::orthogonalize_right(dword update)
{
    ortho_count = 0;

//ÄÄÄ Get vectors to form into orthonormal basis
    // dir is already a normalized copy of mtx[G,H,I], so use dir as v1

    float mag;
    EschVector right(orient.mtx[ESCH_MTX_A],
                     orient.mtx[ESCH_MTX_B],
                     orient.mtx[ESCH_MTX_C]);

    EschVector top(orient.mtx[ESCH_MTX_D],
                   orient.mtx[ESCH_MTX_E],
                   orient.mtx[ESCH_MTX_F]);

//ÄÄÄ Compute orthonormal basis using Gram-Schmidt process
    mag = right.magnitude();
    assertMyth("EschFrameRef::orthogonalize_right input is invalid",
                mag > 0);
    right /= mag;

    dir = dir - right*(dir DOT right);
    mag = dir.magnitude();
    if (mag > 0)
    {
        dir /= mag;

        top = top - dir*(top DOT dir) - right*(top DOT right);
        mag = top.magnitude();
        if (mag > 0)
        {
            top /= mag;
        }
        else
        {
            top = dir CROSS right;
        }
    }
    else
    {
        top = top - right*(top DOT right);
        mag = top.magnitude();

        assertMyth("EschFrameRef::orthogonalize_right input is invalid",
                   mag > 0);

        top /= mag;

        dir = right CROSS top;
    }

//ÄÄÄ Put new vectors into matrix
    orient.mtx[ESCH_MTX_A] = right.i * scalef;
    orient.mtx[ESCH_MTX_B] = right.j * scalef;
    orient.mtx[ESCH_MTX_C] = right.k * scalef;

    orient.mtx[ESCH_MTX_D] = top.i * scalef;
    orient.mtx[ESCH_MTX_E] = top.j * scalef;
    orient.mtx[ESCH_MTX_F] = top.k * scalef;

    orient.mtx[ESCH_MTX_G] = dir.i * scalef;
    orient.mtx[ESCH_MTX_H] = dir.j * scalef;
    orient.mtx[ESCH_MTX_I] = dir.k * scalef;

//ÄÄÄ Update inverse transform
    if (update & ESCH_UPD_INVERSE)
        orient.inverse(&iorient);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - concat                                                    ³
//                                                                          ³
// Appends another frame of reference to the current frame of reference.    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::concat(const EschFrameRef *m)
{
    orient.concat(&m->orient);
    dir.i = orient.mtx[ESCH_MTX_G];
    dir.j = orient.mtx[ESCH_MTX_H];
    dir.k = orient.mtx[ESCH_MTX_I];
    dir.normalize();
    scalef *= m->scalef;
    ortho_count=0;

    m->iorient.concat(&iorient,&iorient);
}

void EschFrameRef::concat(const EschFrameRef *m, EschFrameRef *result) const
{
    orient.concat(&m->orient,&result->orient);
    result->dir.i = result->orient.mtx[ESCH_MTX_G];
    result->dir.j = result->orient.mtx[ESCH_MTX_H];
    result->dir.k = result->orient.mtx[ESCH_MTX_I];
    result->dir.normalize();
    result->scalef = scalef * m->scalef;
    result->ortho_count=0;

    m->iorient.concat(&iorient,&result->iorient);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - reset                                                     ³
//                                                                          ³
// Resets the frame-of-reference to the identity.                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::reset()
{
    ortho_count=0;
    orient.reset();
    iorient.reset();
    dir.i=0;
    dir.j=0;
    dir.k=1;
    scalef=1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - compute_inverse                                           ³
//                                                                          ³
// Computes the inverse orientation and direction vectors.                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::compute_inverse()
{
    orient.inverse(&iorient);
}

//°±² End of module - esfref.cpp ²±°

