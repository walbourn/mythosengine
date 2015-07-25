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
//ùùùùùùùùùùùCopyrightù(c)ù1994-1997ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùAllùRightsùReserved.ùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùù Microsoft Windows '95 Version ùùùùùùùùùùùùùùùùùùùùùùù
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
// esfrrot.cpp
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
// EschFrameRef - rotate                                                    ³
//                                                                          ³
// Appends a rotation about an arbitrary axis to frame of reference.        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::rotate(const EschVector *v, const float degrees, dword update)
{
//ÄÄÄ Compute rotation values

    float s = esch_sin(degrees);
    float c = esch_cos(degrees);
    float t = 1.0f - c;

    // r0 = ti^2 + c
    float r0 = t*v->i*v->i + c;

    // r1 = tij + sk
    float r1 = t*v->i*v->j + s*v->k;

    // r2 = tik - sj
    float r2 = t*v->i*v->k - s*v->j;

    // r3 = tij - sk
    float r3 = t*v->i*v->j - s*v->k;

    // r4 = tj^2 + c
    float r4 = t*v->j*v->j + c;

    // r5 = tjk + si
    float r5 = t*v->j*v->k + s*v->i;

    // r6 = tik + sj
    float r6 = t*v->i*v->k + s*v->j;

    // r7 = tjk - si
    float r7 = t*v->j*v->k - s*v->i;

    // r8 = tk^2 + c
    float r8 = t*v->k*v->k + c;

    // Normalize rotation constants

    EschVector u(r0,r3,r6);
    u.normalize();
    r0 = u.i;
    r3 = u.j;
    r6 = u.k;

    u.i = r1;
    u.j = r4;
    u.k = r7;
    u.normalize();
    r1 = u.i;
    r4 = u.j;
    r7 = u.k;

    u.i = r2;
    u.j = r5;
    u.k = r8;
    u.normalize();
    r2 = u.i;
    r5 = u.j;
    r8 = u.k;

//ÄÄÄ Append transform
    // [A B C 0]   [1  0  0  0]   [r0 r1 r2 0]   [1 0 0 0]
    // [D E F 0] * [0  1  0  0] * [r3 r4 r5 0] * [0 1 0 0]
    // [G H I 0]   [0  0  1  0]   [r6 r7 r8 0]   [0 0 1 0]
    // [J K L 1]   [-J -K -L 1]   [0  0  0  1]   [J K L 1]
    //
    //     [Ar0+Br3+Cr6 Ar1+Br4+Cr7 Ar2+Br5+Cr8 0]
    //   = [Dr0+Er3+Fr6 Dr1+Er4+Fr7 Dr2+Er5+Fr8 0]
    //     [Gr0+Hr3+Ir6 Gr1+Hr4+Ir7 Gr2+Hr5+Ir8 0]
    //     [J           K           L           1]

    EschMatrix  m = orient;

    // Ar0+Br3+Cr6
    orient.mtx[ESCH_MTX_A] = m.mtx[ESCH_MTX_A]*r0
                             + m.mtx[ESCH_MTX_B]*r3
                             + m.mtx[ESCH_MTX_C]*r6;

    // Dr0+Er3+Fr6
    orient.mtx[ESCH_MTX_D] = m.mtx[ESCH_MTX_D]*r0
                             + m.mtx[ESCH_MTX_E]*r3
                             + m.mtx[ESCH_MTX_F]*r6;

    // Gr0+Hr3+Ir6
    orient.mtx[ESCH_MTX_G] = m.mtx[ESCH_MTX_G]*r0
                             + m.mtx[ESCH_MTX_H]*r3
                             + m.mtx[ESCH_MTX_I]*r6;

    // Ar1+Br4+Cr7
    orient.mtx[ESCH_MTX_B] = m.mtx[ESCH_MTX_A]*r1
                             + m.mtx[ESCH_MTX_B]*r4
                             + m.mtx[ESCH_MTX_C]*r7;

    // Dr1+Er4+Fr7
    orient.mtx[ESCH_MTX_E] = m.mtx[ESCH_MTX_D]*r1
                             + m.mtx[ESCH_MTX_E]*r4
                             + m.mtx[ESCH_MTX_F]*r7;

    // Gr1+Hr4+Ir7
    orient.mtx[ESCH_MTX_H] = m.mtx[ESCH_MTX_G]*r1
                             + m.mtx[ESCH_MTX_H]*r4
                             + m.mtx[ESCH_MTX_I]*r7;

    // Ar2+Br5+Cr8
    orient.mtx[ESCH_MTX_C] = m.mtx[ESCH_MTX_A]*r2
                             + m.mtx[ESCH_MTX_B]*r5
                             + m.mtx[ESCH_MTX_C]*r8;

    // Dr2+Er5+Fr8
    orient.mtx[ESCH_MTX_F] = m.mtx[ESCH_MTX_D]*r2
                             + m.mtx[ESCH_MTX_E]*r5
                             + m.mtx[ESCH_MTX_F]*r8;

    // Gr2+Hr5+Ir8
    orient.mtx[ESCH_MTX_I] = m.mtx[ESCH_MTX_G]*r2
                             + m.mtx[ESCH_MTX_H]*r5
                             + m.mtx[ESCH_MTX_I]*r8;

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
        // [1  0  0  0]   [r0 r3 r6 0]   [1 0 0 0]   [A B C 0]
        // [0  1  0  0] * [r1 r4 r7 0] * [0 1 0 0] * [D E F 0]
        // [0  0  1  0]   [r2 r5 r8 0]   [0 0 1 0]   [G H I 0]
        // [-j -k -l 1]   [0  0  0  1]   [j k l 1]   [J K L 1]
        //
        //   [Ar0+Dr3+Gr6  Br0+Er3+Hr6  Cr0+Fr3+Ir6  0]
        // = [Ar1+Dr4+Gr7  Br1+Er4+Hr7  Cr1+Fr4+Ir7  0]
        //   [Ar2+Dr5+Gr8  Br2+Er5+Hr8  Cr2+Fr5+Ir8  0]
        //   [AX+DY+GZ+J   BX+EY+HZ+K   CX+FY+IZ+L   1]
        //
        //  X = j-jr0-kr1-lr2 
        //  Y = k-jr3-kr4-lr5
        //  Z = l-jr6-kr7-lr8

        float x = m.mtx[ESCH_MTX_J]
                  - m.mtx[ESCH_MTX_J]*r0
                  - m.mtx[ESCH_MTX_K]*r1
                  - m.mtx[ESCH_MTX_L]*r2;

        float y = m.mtx[ESCH_MTX_K]
                  - m.mtx[ESCH_MTX_J]*r3
                  - m.mtx[ESCH_MTX_K]*r4
                  - m.mtx[ESCH_MTX_L]*r5;

        float z = m.mtx[ESCH_MTX_L]
                  - m.mtx[ESCH_MTX_J]*r6
                  - m.mtx[ESCH_MTX_K]*r7
                  - m.mtx[ESCH_MTX_L]*r8;

        m = iorient;

        // Ar0+Dr3+Gr6
        iorient.mtx[ESCH_MTX_A] = m.mtx[ESCH_MTX_A]*r0
                                  + m.mtx[ESCH_MTX_D]*r3
                                  + m.mtx[ESCH_MTX_G]*r6;

        // Br0+Er3+Hr6
        iorient.mtx[ESCH_MTX_B] = m.mtx[ESCH_MTX_B]*r0
                                  + m.mtx[ESCH_MTX_E]*r3
                                  + m.mtx[ESCH_MTX_H]*r6;

        // Cr0+Fr3+Ir6
        iorient.mtx[ESCH_MTX_C] = m.mtx[ESCH_MTX_C]*r0
                                  + m.mtx[ESCH_MTX_F]*r3
                                  + m.mtx[ESCH_MTX_I]*r6;

        // Ar1+Dr4+Gr7
        iorient.mtx[ESCH_MTX_D] = m.mtx[ESCH_MTX_A]*r1
                                  + m.mtx[ESCH_MTX_D]*r4
                                  + m.mtx[ESCH_MTX_G]*r7;
        
        // Br1+Er4+Hr7
        iorient.mtx[ESCH_MTX_E] = m.mtx[ESCH_MTX_B]*r1
                                  + m.mtx[ESCH_MTX_E]*r4
                                  + m.mtx[ESCH_MTX_H]*r7;
        
        // Cr1+Fr4+Ir7
        iorient.mtx[ESCH_MTX_F] = m.mtx[ESCH_MTX_C]*r1
                                  + m.mtx[ESCH_MTX_F]*r4
                                  + m.mtx[ESCH_MTX_I]*r7;

        // Ar2+Dr5+Gr8
        iorient.mtx[ESCH_MTX_G] = m.mtx[ESCH_MTX_A]*r2
                                  + m.mtx[ESCH_MTX_D]*r5
                                  + m.mtx[ESCH_MTX_G]*r8;

        // Br2+Er5+Hr8
        iorient.mtx[ESCH_MTX_H] = m.mtx[ESCH_MTX_B]*r2
                                  + m.mtx[ESCH_MTX_E]*r5
                                  + m.mtx[ESCH_MTX_H]*r8;

        // Cr2+Fr5+Ir8
        iorient.mtx[ESCH_MTX_I] = m.mtx[ESCH_MTX_C]*r2
                                  + m.mtx[ESCH_MTX_F]*r5
                                  + m.mtx[ESCH_MTX_I]*r8;

        // AX+DY+GZ+J
        iorient.mtx[ESCH_MTX_J] = m.mtx[ESCH_MTX_A]*x
                                  + m.mtx[ESCH_MTX_D]*y
                                  + m.mtx[ESCH_MTX_G]*z
                                  + m.mtx[ESCH_MTX_J];

        // BX+EY+HZ+K
        iorient.mtx[ESCH_MTX_K] = m.mtx[ESCH_MTX_B]*x
                                  + m.mtx[ESCH_MTX_E]*y
                                  + m.mtx[ESCH_MTX_H]*z
                                  + m.mtx[ESCH_MTX_K];

        // CX+FY+IZ+L
        iorient.mtx[ESCH_MTX_L] = m.mtx[ESCH_MTX_C]*x
                                  + m.mtx[ESCH_MTX_F]*y
                                  + m.mtx[ESCH_MTX_I]*z
                                  + m.mtx[ESCH_MTX_L];
#else
        orient.inverse(&iorient);
#endif
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - pitch                                                     ³
//                                                                          ³
// Appends a rotation about the frame's current I axis.                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::pitch(const float degrees, dword update)
{
    EschVector   axis(orient.mtx[ESCH_MTX_A],
                      orient.mtx[ESCH_MTX_B],
                      orient.mtx[ESCH_MTX_C]);

    axis.normalize();

    rotate(&axis,degrees,update);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - roll                                                      ³
//                                                                          ³
// Appends a rotation about the frame's current K axis.                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::roll(const float degrees, dword update)
{
    rotate(&dir,degrees,update);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - yaw                                                       ³
//                                                                          ³
// Appends a rotation about the frame's current J axis.                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::yaw(const float degrees, dword update)
{
    EschVector   axis(orient.mtx[ESCH_MTX_D],
                      orient.mtx[ESCH_MTX_E],
                      orient.mtx[ESCH_MTX_F]);

    axis.normalize();

    rotate(&axis,degrees,update);
}

//°±² End of module - esfrrot.cpp ²±°

