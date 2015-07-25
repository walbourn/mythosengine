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
// elrmain.cpp
//
// Main library module with pointer-to-functions for math helper routines
// and enable/disable code for AMD 3DNow instruction versions.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "euler.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern "C" int mythos_detect_mmx();
extern "C" int mythos_detect_amd3d();

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// FPU versions
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

//ÄÄÄ 2D operations
extern "C" void elr_fpu_transform2d(const ElrPoint2D *v,
                                    const ElrMatrix2D *m, ElrPoint2DW *d,
                                    int hn);

extern "C" void elr_fpu_transform2dw(const ElrPoint2DW *v,
                                     const ElrMatrix2D *m, ElrPoint2DW *d,
                                     int hn);

extern "C" void elr_fpu_transformv2d(const ElrVector2D *v,
                                     const ElrMatrix2D *m, ElrVector2DW *d,
                                     int hn);

extern "C" void elr_fpu_transformv2dw(const ElrVector2DW *v,
                                      const ElrMatrix2D *m, ElrVector2DW *d,
                                      int hn);

extern "C" void elr_fpu_normalize2d(ElrVector2D *v);

extern "C" void elr_fpu_hnormalize2d(ElrVector2DW *v);

extern "C" void elr_fpu_concatmatrix2d(const ElrMatrix2D *s,
                                       const ElrMatrix2D *m, ElrMatrix2D *d,
                                       int hn);

extern "C" void elr_fpu_adjointmatrix2d(const ElrMatrix2D *m, ElrMatrix2D *d,
                                        int hn);

extern "C" int elr_fpu_inversematrix2d(const ElrMatrix2D *m, ElrMatrix2D *d,
                                       int hn);

//ÄÄÄ 3D operations
extern "C" void elr_fpu_transform3d(const ElrPoint3D *v,
                                    const ElrMatrix3D *m, ElrPoint3DW *d,
                                    int hn);

extern "C" void elr_fpu_transform3dw(const ElrPoint3DW *v,
                                     const ElrMatrix3D *m, ElrPoint3DW *d,
                                     int hn);

extern "C" void elr_fpu_transformv3d(const ElrVector3D *v,
                                     const ElrMatrix3D *m, ElrVector3DW *d,
                                     int hn);

extern "C" void elr_fpu_transformv3dw(const ElrVector3DW *v,
                                      const ElrMatrix3D *m, ElrVector3DW *d,
                                      int hn);

extern "C" ElrVector3D *elr_fpu_cross3d(const ElrVector3D *v1,
                                        const ElrVector3D *v2, ElrVector3D *d);

extern "C" void elr_fpu_normalize3d(ElrVector3D *v);

extern "C" void elr_fpu_hnormalize3d(ElrVector3DW *v);

extern "C" void elr_fpu_concatmatrix3d(const ElrMatrix3D *s,
                                      const ElrMatrix3D *m, ElrMatrix3D *d,
                                      int hn);

extern "C" void elr_fpu_adjointmatrix3d(const ElrMatrix3D *m, ElrMatrix3D *d,
                                        int hn);

extern "C" int elr_fpu_inversematrix3d(const ElrMatrix3D *m, ElrMatrix3D *d,
                                       int hn);

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// AMD-3D versions
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

//ÄÄÄ 2D operations

//ÄÄÄ 3D operations

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

#ifdef __WATCOMC__
#pragma off(unreferenced);
#endif

//ÄÄ Identification string for the library.
static char id[] =
"Euler -  A component of the MythOS collection\n"
"Copyright (C) 1998 by Charybdis Enterprises, Inc. All Rights Reserved.\n"
"MythOS is a trademark of Charybdis Enterprises, Inc.\n";

//ÄÄ 2D operations
void (*elr_transform2d)(const ElrPoint2D *v,
                        const ElrMatrix2D *m,
                        ElrPoint2DW *d, int hn) = elr_fpu_transform2d;

void (*elr_transform2dw)(const ElrPoint2DW *v,
                         const ElrMatrix2D *m,
                         ElrPoint2DW *d, int hn) = elr_fpu_transform2dw;

void (*elr_transformv2d)(const ElrVector2D *v,
                         const ElrMatrix2D *m,
                         ElrVector2DW *d, int hn) = elr_fpu_transformv2d;

void (*elr_transformv2dw)(const ElrVector2DW *v,
                          const ElrMatrix2D *m,
                          ElrVector2DW *d, int hn) = elr_fpu_transformv2dw;

void (*elr_normalize2d)(ElrVector2D *v) = elr_fpu_normalize2d;

void (*elr_hnormalize2d)(ElrVector2DW *v) = elr_fpu_hnormalize2d;

void (*elr_concatmatrix2d)(const ElrMatrix2D *s,
                           const ElrMatrix2D *m,
                           ElrMatrix2D *d, int hn) = elr_fpu_concatmatrix2d;

void (*elr_adjointmatrix2d)(const ElrMatrix2D *m,
                            ElrMatrix2D *d, int hn) = elr_fpu_adjointmatrix2d;

int (*elr_inversematrix2d)(const ElrMatrix2D *m,
                           ElrMatrix2D *d, int hn) = elr_fpu_inversematrix2d;

//ÄÄ 3D operations
void (*elr_transform3d)(const ElrPoint3D *v,
                        const ElrMatrix3D *m,
                        ElrPoint3DW *d, int hn) = elr_fpu_transform3d;

void (*elr_transform3dw)(const ElrPoint3DW *v,
                         const ElrMatrix3D *m,
                         ElrPoint3DW *d, int hn) = elr_fpu_transform3dw;

void (*elr_transformv3d)(const ElrVector3D *v,
                         const ElrMatrix3D *m,
                         ElrVector3DW *d, int hn) = elr_fpu_transformv3d;

void (*elr_transformv3dw)(const ElrVector3DW *v,
                          const ElrMatrix3D *m,
                          ElrVector3DW *d, int hn) = elr_fpu_transformv3dw;

ElrVector3D *(*elr_cross3d)(const ElrVector3D *v1,
                            const ElrVector3D *v2,
                            ElrVector3D *d) = elr_fpu_cross3d;

void (*elr_normalize3d)(ElrVector3D *v) = elr_fpu_normalize3d;

void (*elr_hnormalize3d)(ElrVector3DW *v) = elr_fpu_hnormalize3d;

void (*elr_concatmatrix3d)(const ElrMatrix3D *s,
                           const ElrMatrix3D *m,
                           ElrMatrix3D *d, int hn) = elr_fpu_concatmatrix3d;

void (*elr_adjointmatrix3d)(const ElrMatrix3D *m,
                            ElrMatrix3D *d, int hn) = elr_fpu_adjointmatrix3d;

int (*elr_inversematrix3d)(const ElrMatrix3D *m,
                           ElrMatrix3D *d, int hn) = elr_fpu_inversematrix3d;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_enable_amd3d
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int elr_enable_amd3d()
{
    if (!mythos_detect_amd3d())
        return 1;

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// elr_disable_amd3d
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void elr_disable_amd3d()
{
}

//°±² End of module - elrmain.cpp ²±°
