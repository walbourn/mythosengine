//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//שששששששששש°°°°°°°°°°ש°°°°°°°°ששש°°°°°°°°שש°°°שששש°°°ש°°°°°°°°°°ש°°°°°°°°°שש
//ששששששששש°±°ששששששש°±°שששש°±°ש°±°שששש°±°ש°±°שששש°±°ש°±°שששששששש°±°שששש°±°שש
//שששששששש±°±ששששששש±°±שששששששש±°±שששששששש±°±שששש±°±ש±°±שששששששש±°±שששש±°±ששש
//ששששששש±²±±°±±²שש±²±±°±±²±±ש±²±שששששששש±²±±°±±²±±ש±²±±°±±²ששש±²±±°±±²°ששששש
//שששששש±²±שששששששששששששש±²±ש±²±שששששששש±²±שששש±²±ש±²±שששששששש±²±שששש±²±ששששש
//ששששש²±²ששששששש²±²שששש²±²ש²±²שששש²±²ש²±²שששש²±²ש²±²שששששששש²±²שששש²±²שששששש
//שששש²²²²²²²²²²ש²²²²²²²²ששש²²²²²²²²שש²²²שששש²²²ש²²²²²²²²²²ש²²²שששש²²²ששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//שששששששששששCopyrightש(c)ש1994-1996שbyשCharybdisשEnterprises,שInc.שששששששששש
//ששששששששששששששששששששששששששAllשRightsשReserved.ששששששששששששששששששששששששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//ששששששששששששששששששששש Microsoft Windows '95 Version ששששששששששששששששששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
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
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
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
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

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

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// EschFrameRef - rotate                                                    ³
//                                                                          ³
// Appends a rotation about an arbitrary axis to frame of reference.        ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
void EschFrameRef::rotate(const EschVector *v, const Flx16 degrees, dword update)
{
    Flx16       s,c,t;
    Flx16       j,k,l;
    Flx16       r0, r1, r2;
    Flx16       r3, r4, r5;
    Flx16       r6, r7, r8;
    EschVector  u;

//ִִִ Compute rotation values

    s=degrees.sin();
    c=degrees.cos();
    t.flx = (1<<16) - c.flx;

    // r0 = ti^2 + c
    r0.flx = flx_16mul16(t,flx_16mul16(v->i,v->i)).flx + c.flx;

    // r1 = tij + sk
    r1.flx = flx_16mul16(t,flx_16mul16(v->i,v->j)).flx
             + flx_16mul16(s,v->k).flx;

    // r2 = tik - sj
    r2.flx = flx_16mul16(t,flx_16mul16(v->i,v->k)).flx
             - flx_16mul16(s,v->j).flx;

    // r3 = tij - sk
    r3.flx = flx_16mul16(t,flx_16mul16(v->i,v->j)).flx
             - flx_16mul16(s,v->k).flx;

    // r4 = tj^2 + c
    r4.flx = flx_16mul16(t,flx_16mul16(v->j,v->j)).flx + c.flx;

    // r5 = tjk + si
    r5.flx = flx_16mul16(t,flx_16mul16(v->j,v->k)).flx
             + flx_16mul16(s,v->i).flx;

    // r6 = tik + sj
    r6.flx = flx_16mul16(t,flx_16mul16(v->i,v->k)).flx
             + flx_16mul16(s,v->j).flx;

    // r7 = tjk - si
    r7.flx = flx_16mul16(t,flx_16mul16(v->j,v->k)).flx
             - flx_16mul16(s,v->i).flx;

    // r8 = tk^2 + c
    r8.flx = flx_16mul16(t,flx_16mul16(v->k,v->k)).flx + c.flx;

    // Normalize rotation constants

    u.i = r0;
    u.j = r3;
    u.k = r6;
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

//ִִִ Append transform
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
    orient.mtx[ESCH_MTX_A].flx = flx_16mul16(m.mtx[ESCH_MTX_A],r0).flx
                        + flx_16mul16(m.mtx[ESCH_MTX_B],r3).flx
                        + flx_16mul16(m.mtx[ESCH_MTX_C],r6).flx;

    // Dr0+Er3+Fr6
    orient.mtx[ESCH_MTX_D].flx = flx_16mul16(m.mtx[ESCH_MTX_D],r0).flx
                        + flx_16mul16(m.mtx[ESCH_MTX_E],r3).flx
                        + flx_16mul16(m.mtx[ESCH_MTX_F],r6).flx;

    // Gr0+Hr3+Ir6
    orient.mtx[ESCH_MTX_G].flx = flx_16mul16(m.mtx[ESCH_MTX_G],r0).flx
                        + flx_16mul16(m.mtx[ESCH_MTX_H],r3).flx
                        + flx_16mul16(m.mtx[ESCH_MTX_I],r6).flx;

    // Ar1+Br4+Cr7
    orient.mtx[ESCH_MTX_B].flx = flx_16mul16(m.mtx[ESCH_MTX_A],r1).flx
                        + flx_16mul16(m.mtx[ESCH_MTX_B],r4).flx
                        + flx_16mul16(m.mtx[ESCH_MTX_C],r7).flx;

    // Dr1+Er4+Fr7
    orient.mtx[ESCH_MTX_E].flx = flx_16mul16(m.mtx[ESCH_MTX_D],r1).flx
                        + flx_16mul16(m.mtx[ESCH_MTX_E],r4).flx
                        + flx_16mul16(m.mtx[ESCH_MTX_F],r7).flx;

    // Gr1+Hr4+Ir7
    orient.mtx[ESCH_MTX_H].flx = flx_16mul16(m.mtx[ESCH_MTX_G],r1).flx
                        + flx_16mul16(m.mtx[ESCH_MTX_H],r4).flx
                        + flx_16mul16(m.mtx[ESCH_MTX_I],r7).flx;

    // Ar2+Br5+Cr8
    orient.mtx[ESCH_MTX_C].flx = flx_16mul16(m.mtx[ESCH_MTX_A],r2).flx
                        + flx_16mul16(m.mtx[ESCH_MTX_B],r5).flx
                        + flx_16mul16(m.mtx[ESCH_MTX_C],r8).flx;

    // Dr2+Er5+Fr8
    orient.mtx[ESCH_MTX_F].flx = flx_16mul16(m.mtx[ESCH_MTX_D],r2).flx
                        + flx_16mul16(m.mtx[ESCH_MTX_E],r5).flx
                        + flx_16mul16(m.mtx[ESCH_MTX_F],r8).flx;

    // Gr2+Hr5+Ir8
    orient.mtx[ESCH_MTX_I].flx = flx_16mul16(m.mtx[ESCH_MTX_G],r2).flx
                         + flx_16mul16(m.mtx[ESCH_MTX_H],r5).flx
                         + flx_16mul16(m.mtx[ESCH_MTX_I],r8).flx;

    dir.i = orient.mtx[ESCH_MTX_G];
    dir.j = orient.mtx[ESCH_MTX_H];
    dir.k = orient.mtx[ESCH_MTX_I];
    dir.normalize();

//ִִִ Orthogonalize
    if ((++ortho_count > ESCH_MAX_ORTHOCOUNT) && (update & ESCH_UPD_ORTHO))
    {
        orthogonalize(update);
        ortho_count=0;
    }
    else if (update & ESCH_UPD_INVERSE)
        orient.inverse(&iorient);
}


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// EschFrameRef - pitch                                                     ³
//                                                                          ³
// Appends a rotation about the frame's current I axis.                     ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
void EschFrameRef::pitch(const Flx16 degrees, dword update)
{
    EschVector   axis(orient.mtx[ESCH_MTX_A],
                      orient.mtx[ESCH_MTX_B],
                      orient.mtx[ESCH_MTX_C]);

    axis.normalize();

    rotate(&axis,degrees,update);
}


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// EschFrameRef - roll                                                      ³
//                                                                          ³
// Appends a rotation about the frame's current K axis.                     ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
void EschFrameRef::roll(const Flx16 degrees, dword update)
{
    rotate(&dir,degrees,update);
}


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// EschFrameRef - yaw                                                       ³
//                                                                          ³
// Appends a rotation about the frame's current J axis.                     ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
void EschFrameRef::yaw(const Flx16 degrees, dword update)
{
    EschVector   axis(orient.mtx[ESCH_MTX_D],
                      orient.mtx[ESCH_MTX_E],
                      orient.mtx[ESCH_MTX_F]);

    axis.normalize();

    rotate(&axis,degrees,update);
}

//°±² End of module - esfrrot.cpp ²±°

