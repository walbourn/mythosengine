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
//ùùùùùùùùùùùCopyrightù(c)ù1994-1996ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
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

    if (update & ESCH_UPD_INVERSE)
        compute_inverse();
}

void EschFrameRef::set_position(const Flx16 ix, const Flx16 iy, const Flx16 iz,
                                dword update)

{ 
    orient.mtx[ESCH_MTX_J] = ix;
    orient.mtx[ESCH_MTX_K] = iy;
    orient.mtx[ESCH_MTX_L] = iz; 

    if (update & ESCH_UPD_INVERSE)
        compute_inverse();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - rotatex                                                   ³
//                                                                          ³
// Appends a rotation about X to the frame of reference.                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::rotatex(const Flx16 degrees, dword update)
{
    Flx16   s,c;
    Flx16   m[3];

    s=degrees.sin();
    c=degrees.cos();

//ÄÄÄ Append transform

    // [A B C 0]   [1  0  0  0]   [1 0  0 0]   [1 0 0 0]   [A Bc-Cs Bs+Cc 0]
    // [D E F 0] * [0  1  0  0] * [0 c  s 0] * [0 1 0 0] = [D Ec-Fs Es+Fc 0]
    // [G H I 0]   [0  0  1  0]   [0 -s c 0]   [0 0 1 0]   [G Hc-Is Hs+Ic 0]
    // [J K L 1]   [-J -K -L 1]   [0 0  0 1]   [J K L 1]   [J K     L     1]

    m[0].flx = flx_16mul16(orient.mtx[ESCH_MTX_B],c).flx
               - flx_16mul16(orient.mtx[ESCH_MTX_C],s).flx;
    m[1].flx = flx_16mul16(orient.mtx[ESCH_MTX_E],c).flx
               - flx_16mul16(orient.mtx[ESCH_MTX_F],s).flx;
    m[2].flx = flx_16mul16(orient.mtx[ESCH_MTX_H],c).flx
               - flx_16mul16(orient.mtx[ESCH_MTX_I],s).flx;
    
    orient.mtx[ESCH_MTX_C].flx = flx_16mul16(orient.mtx[ESCH_MTX_B],s).flx
                                 + flx_16mul16(orient.mtx[ESCH_MTX_C],c).flx;
    orient.mtx[ESCH_MTX_F].flx = flx_16mul16(orient.mtx[ESCH_MTX_E],s).flx
                                 + flx_16mul16(orient.mtx[ESCH_MTX_F],c).flx;
    orient.mtx[ESCH_MTX_I].flx = flx_16mul16(orient.mtx[ESCH_MTX_H],s).flx
                                 + flx_16mul16(orient.mtx[ESCH_MTX_I],c).flx;
    
    orient.mtx[ESCH_MTX_B] = m[0];
    orient.mtx[ESCH_MTX_E] = m[1];
    orient.mtx[ESCH_MTX_H] = m[2];
    
    dir.i = orient.mtx[ESCH_MTX_G];
    dir.j = orient.mtx[ESCH_MTX_H];
    dir.k = orient.mtx[ESCH_MTX_I];
    dir.normalize();

//ÄÄÄ Orthogonalize
    if ((++ortho_count > ESCH_MAX_ORTHOCOUNT) && (update & ESCH_UPD_ORTHO))
    {
        orthogonalize(update);
        ortho_count=0;
    }
    else if (update & ESCH_UPD_INVERSE)
        orient.inverse(&iorient);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - rotatey                                                   ³
//                                                                          ³
// Appends a rotation about Y to the frame of reference.                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::rotatey(const Flx16 degrees, dword update)
{
    Flx16   s,c;
    Flx16   m[3];

    s=degrees.sin();
    c=degrees.cos();

//ÄÄÄ Append transform

    // [A B C 0]   [1  0  0  0]   [c 0 -s 0]   [1 0 0 0]   [Ac+Cs B Cc-As 0]
    // [D E F 0] * [0  1  0  0] * [0 1 0  0] * [0 1 0 0] = [Dc+Fs E Fc-Ds 0]
    // [G H I 0]   [0  0  1  0]   [s 0 c  0]   [0 0 1 0]   [Gc+Is H Ic-Gs 0]
    // [J K L 1]   [-J -K -L 1]   [0 0 0  1]   [J K L 1]   [J     K L     1]

    m[0].flx = flx_16mul16(orient.mtx[ESCH_MTX_A],c).flx
               + flx_16mul16(orient.mtx[ESCH_MTX_C],s).flx;
    m[1].flx = flx_16mul16(orient.mtx[ESCH_MTX_D],c).flx
               + flx_16mul16(orient.mtx[ESCH_MTX_F],s).flx;
    m[2].flx = flx_16mul16(orient.mtx[ESCH_MTX_G],c).flx
               + flx_16mul16(orient.mtx[ESCH_MTX_I],s).flx;
    
    orient.mtx[ESCH_MTX_C].flx  = flx_16mul16(orient.mtx[ESCH_MTX_C],c).flx
                                  - flx_16mul16(orient.mtx[ESCH_MTX_A],s).flx;
    orient.mtx[ESCH_MTX_F].flx  = flx_16mul16(orient.mtx[ESCH_MTX_F],c).flx
                                  - flx_16mul16(orient.mtx[ESCH_MTX_D],s).flx;
    orient.mtx[ESCH_MTX_I].flx = flx_16mul16(orient.mtx[ESCH_MTX_I],c).flx
                                 - flx_16mul16(orient.mtx[ESCH_MTX_G],s).flx;
    
    orient.mtx[ESCH_MTX_A] = m[0];
    orient.mtx[ESCH_MTX_D] = m[1];
    orient.mtx[ESCH_MTX_G] = m[2];
    
    dir.i = orient.mtx[ESCH_MTX_G];
    dir.j = orient.mtx[ESCH_MTX_H];
    dir.k = orient.mtx[ESCH_MTX_I];
    dir.normalize();

//ÄÄÄ Orthogonalize
    if ((++ortho_count > ESCH_MAX_ORTHOCOUNT) && (update & ESCH_UPD_ORTHO))
    {
        orthogonalize(update);
        ortho_count=0;
    }
    else if (update & ESCH_UPD_INVERSE)
        orient.inverse(&iorient);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFrameRef - rotatez                                                   ³
//                                                                          ³
// Appends a rotation about Z to the frame of reference.                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFrameRef::rotatez(const Flx16 degrees, dword update)
{
    Flx16   s,c;
    Flx16   a,b;
    Flx16   m[3];
    Flx16   n[3];

    s=degrees.sin();
    c=degrees.cos();

//ÄÄÄ Append transform

    // [A B C 0]   [1  0  0  0]   [c  s 0 0]   [1 0 0 0]   [Ac-Bs As+Bc C 0]
    // [D E F 0] * [0  1  0  0] * [-s c 0 0] * [0 1 0 0] = [Dc-Es Ds+Ec F 0]
    // [G H I 0]   [0  0  1  0]   [0  0 1 0]   [0 0 1 0]   [Gc-Hs Gs+Hc I 0]
    // [J K L 1]   [-J -K -L 1]   [0  0 0 1]   [J K L 1]   [J     K     L 1]

    m[0].flx = flx_16mul16(orient.mtx[ESCH_MTX_A],c).flx
               - flx_16mul16(orient.mtx[ESCH_MTX_B],s).flx;
    m[1].flx = flx_16mul16(orient.mtx[ESCH_MTX_D],c).flx
               - flx_16mul16(orient.mtx[ESCH_MTX_E],s).flx;
    m[2].flx = flx_16mul16(orient.mtx[ESCH_MTX_G],c).flx
               - flx_16mul16(orient.mtx[ESCH_MTX_H],s).flx;
    
    orient.mtx[ESCH_MTX_B].flx = flx_16mul16(orient.mtx[ESCH_MTX_A],s).flx
                                 + flx_16mul16(orient.mtx[ESCH_MTX_B],c).flx;
    orient.mtx[ESCH_MTX_E].flx = flx_16mul16(orient.mtx[ESCH_MTX_D],s).flx
                                 + flx_16mul16(orient.mtx[ESCH_MTX_E],c).flx;
    orient.mtx[ESCH_MTX_H].flx = flx_16mul16(orient.mtx[ESCH_MTX_G],s).flx
                                 + flx_16mul16(orient.mtx[ESCH_MTX_H],c).flx;
    
    orient.mtx[ESCH_MTX_A] = m[0];
    orient.mtx[ESCH_MTX_D] = m[1];
    orient.mtx[ESCH_MTX_G] = m[2];
    
    dir.i = orient.mtx[ESCH_MTX_G];
    dir.j = orient.mtx[ESCH_MTX_H];
    dir.k = orient.mtx[ESCH_MTX_I];
    dir.normalize();

//ÄÄÄ Orthogonalize
    if ((++ortho_count > ESCH_MAX_ORTHOCOUNT) && (update & ESCH_UPD_ORTHO))
    {
        orthogonalize(update);
        ortho_count=0;
    }
    else if (update & ESCH_UPD_INVERSE)
        orient.inverse(&iorient);
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

    orient.mtx[ESCH_MTX_J].flx  = orient.mtx[ESCH_MTX_J].flx + v->i.flx;
    orient.mtx[ESCH_MTX_K].flx  = orient.mtx[ESCH_MTX_K].flx + v->j.flx;
    orient.mtx[ESCH_MTX_L].flx = orient.mtx[ESCH_MTX_L].flx + v->k.flx;

//ÄÄÄ Update inverse transform
    if (update & ESCH_UPD_INVERSE)
        orient.inverse(&iorient);
}

void EschFrameRef::translate(const Flx16 idx, const Flx16 idy, const Flx16 idz,
                             dword update)
{
//ÄÄÄ Append transform
    // [A B C 0]   [1 0 0 0]   [A   B   C   0]
    // [D E F 0] * [0 1 0 0] = [D   E   F   0]
    // [G H I 0]   [0 0 1 0]   [G   H   I   0]
    // [J K L 1]   [x y z 1]   [J+x K+y L+z 1]

    orient.mtx[ESCH_MTX_J].flx  = orient.mtx[ESCH_MTX_J].flx + idx.flx;
    orient.mtx[ESCH_MTX_K].flx  = orient.mtx[ESCH_MTX_K].flx + idy.flx;
    orient.mtx[ESCH_MTX_L].flx = orient.mtx[ESCH_MTX_L].flx + idz.flx;

//ÄÄÄ Update inverse transform
    if (update & ESCH_UPD_INVERSE)
        orient.inverse(&iorient);
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

void EschFrameRef::move(const Flx16 idx, const Flx16 idy, const Flx16 idz,
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
void EschFrameRef::scale(const Flx16 is, dword update)
{
    Flx16   a,b,c;
    Flx16   n[3];

    scalef = scalef * is;

//ÄÄÄ Append transform
    // [A B C 0]   [1  0  0  0]   [s  0 0 0]   [1 0 0 0]   [As Bs Cs 0]
    // [D E F 0] * [0  1  0  0] * [0  s 0 0] * [0 1 0 0] = [Ds Es Fs 0]
    // [G H I 0]   [0  0  1  0]   [0  0 s 0]   [0 0 1 0]   [Gs Hs Is 0]
    // [J K L 1]   [-J -K -L 1]   [0  0 0 1]   [J K L 1]   [J  K  L  1]

    orient.mtx[ESCH_MTX_A].flx = flx_16mul16(orient.mtx[ESCH_MTX_A],is).flx;
    orient.mtx[ESCH_MTX_D].flx = flx_16mul16(orient.mtx[ESCH_MTX_D],is).flx;
    orient.mtx[ESCH_MTX_G].flx = flx_16mul16(orient.mtx[ESCH_MTX_G],is).flx;
              
    orient.mtx[ESCH_MTX_B].flx = flx_16mul16(orient.mtx[ESCH_MTX_B],is).flx;
    orient.mtx[ESCH_MTX_E].flx = flx_16mul16(orient.mtx[ESCH_MTX_E],is).flx;
    orient.mtx[ESCH_MTX_H].flx = flx_16mul16(orient.mtx[ESCH_MTX_H],is).flx;

    orient.mtx[ESCH_MTX_C].flx  = flx_16mul16(orient.mtx[ESCH_MTX_C],is).flx;
    orient.mtx[ESCH_MTX_F].flx  = flx_16mul16(orient.mtx[ESCH_MTX_F],is).flx;
    orient.mtx[ESCH_MTX_I].flx = flx_16mul16(orient.mtx[ESCH_MTX_I],is).flx;

//ÄÄÄ Update inverse transform
    if (update & ESCH_UPD_INVERSE)
        orient.inverse(&iorient);
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
//ÄÄÄ Get vectors to form into orthonormal basis
    // dir is already a normalized copy of mtx[G,H,I], so use dir as v1

    EschVector right(orient.mtx[ESCH_MTX_A],
                     orient.mtx[ESCH_MTX_B],
                     orient.mtx[ESCH_MTX_C]);

    EschVector top(orient.mtx[ESCH_MTX_D],
                   orient.mtx[ESCH_MTX_E],
                   orient.mtx[ESCH_MTX_F]);

//ÄÄÄ Compute orthonormal basis using Gram-Schmidt process
    top = top - dir*(top DOT dir);
    top.normalize();

    right = right - dir*(right DOT dir) - top*(right DOT top);
    right.normalize();

//ÄÄÄ Put new vectors into matrix
    orient.mtx[ESCH_MTX_A].flx = flx_16mul16(right.i,scalef).flx;
    orient.mtx[ESCH_MTX_B].flx = flx_16mul16(right.j,scalef).flx;
    orient.mtx[ESCH_MTX_C].flx = flx_16mul16(right.k,scalef).flx;

    orient.mtx[ESCH_MTX_D].flx = flx_16mul16(top.i,scalef).flx;
    orient.mtx[ESCH_MTX_E].flx = flx_16mul16(top.j,scalef).flx;
    orient.mtx[ESCH_MTX_F].flx = flx_16mul16(top.k,scalef).flx;

    orient.mtx[ESCH_MTX_G].flx = flx_16mul16(dir.i,scalef).flx;
    orient.mtx[ESCH_MTX_H].flx = flx_16mul16(dir.j,scalef).flx;
    orient.mtx[ESCH_MTX_I].flx = flx_16mul16(dir.k,scalef).flx;

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
//ÄÄÄ Get vectors to form into orthonormal basis
    // dir is already a normalized copy of mtx[G,H,I], so use dir as v1

    EschVector right(orient.mtx[ESCH_MTX_A],
                     orient.mtx[ESCH_MTX_B],
                     orient.mtx[ESCH_MTX_C]);

    EschVector top(orient.mtx[ESCH_MTX_D],
                   orient.mtx[ESCH_MTX_E],
                   orient.mtx[ESCH_MTX_F]);

//ÄÄÄ Compute orthonormal basis using Gram-Schmidt process
    top.normalize();

    dir = dir - top*(dir DOT top);
    dir.normalize();

    right = right - dir*(right DOT dir) - top*(right DOT top);
    right.normalize();

//ÄÄÄ Put new vectors into matrix
    orient.mtx[ESCH_MTX_A].flx = flx_16mul16(right.i,scalef).flx;
    orient.mtx[ESCH_MTX_B].flx = flx_16mul16(right.j,scalef).flx;
    orient.mtx[ESCH_MTX_C].flx = flx_16mul16(right.k,scalef).flx;

    orient.mtx[ESCH_MTX_D].flx = flx_16mul16(top.i,scalef).flx;
    orient.mtx[ESCH_MTX_E].flx = flx_16mul16(top.j,scalef).flx;
    orient.mtx[ESCH_MTX_F].flx = flx_16mul16(top.k,scalef).flx;

    orient.mtx[ESCH_MTX_G].flx = flx_16mul16(dir.i,scalef).flx;
    orient.mtx[ESCH_MTX_H].flx = flx_16mul16(dir.j,scalef).flx;
    orient.mtx[ESCH_MTX_I].flx = flx_16mul16(dir.k,scalef).flx;

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
//ÄÄÄ Get vectors to form into orthonormal basis
    // dir is already a normalized copy of mtx[G,H,I], so use dir as v1

    EschVector right(orient.mtx[ESCH_MTX_A],
                     orient.mtx[ESCH_MTX_B],
                     orient.mtx[ESCH_MTX_C]);

    EschVector top(orient.mtx[ESCH_MTX_D],
                   orient.mtx[ESCH_MTX_E],
                   orient.mtx[ESCH_MTX_F]);

//ÄÄÄ Compute orthonormal basis using Gram-Schmidt process
    right.normalize();

    dir = dir - right*(dir DOT right);
    dir.normalize();

    top = top - dir*(top DOT dir) - right*(top DOT right);
    top.normalize();

//ÄÄÄ Put new vectors into matrix
    orient.mtx[ESCH_MTX_A].flx = flx_16mul16(right.i,scalef).flx;
    orient.mtx[ESCH_MTX_B].flx = flx_16mul16(right.j,scalef).flx;
    orient.mtx[ESCH_MTX_C].flx = flx_16mul16(right.k,scalef).flx;

    orient.mtx[ESCH_MTX_D].flx = flx_16mul16(top.i,scalef).flx;
    orient.mtx[ESCH_MTX_E].flx = flx_16mul16(top.j,scalef).flx;
    orient.mtx[ESCH_MTX_F].flx = flx_16mul16(top.k,scalef).flx;

    orient.mtx[ESCH_MTX_G].flx = flx_16mul16(dir.i,scalef).flx;
    orient.mtx[ESCH_MTX_H].flx = flx_16mul16(dir.j,scalef).flx;
    orient.mtx[ESCH_MTX_I].flx = flx_16mul16(dir.k,scalef).flx;

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

