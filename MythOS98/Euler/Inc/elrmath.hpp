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
// INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PbROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Chuck Walbourn
//
// elrmath.hpp
//
// Core math routines for the Euler library including the overloadable
// C-interface routines for AMD-3D/MMX enhancements.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __ELRMATH_HPP
#define __ELRMATH_HPP   1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <math.h>
#include <string.h>

#include <assert.h>
#include <portable.h>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define ELR_DEG2RAD 0.017453292f
#define ELR_RAD2DEG 57.29577951f

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                 Inlines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄ Trig functions
inline float elr_sin(float dg) { return float(sin(dg * ELR_DEG2RAD)); }
inline float elr_cos(float dg) { return float(cos(dg * ELR_DEG2RAD)); }
inline float elr_tan(float dg) { return float(tan(dg * ELR_DEG2RAD)); }

inline float elr_asin(float n) { return (float(asin(n)) * ELR_RAD2DEG); }
inline float elr_acos(float n) { return (float(acos(n)) * ELR_RAD2DEG); }
inline float elr_atan(float n) { return (float(atan(n)) * ELR_RAD2DEG); }

//ÄÄ Misc functions
inline float elr_sqrt(float n) { return float(sqrt(n)); }

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern "C" int elr_enable_amd3d();
extern "C" void elr_disable_amd3d();

//ÄÄ 2D operations
class ElrPoint2D;
class ElrPoint2DW;
class ElrVector2D;
class ElrVector2DW;
class ElrMatrix2D;

extern "C" void (*elr_transform2d)(const ElrPoint2D *v,
                                   const ElrMatrix2D *m, ElrPoint2DW *d,
                                   int hn=0);

extern "C" void (*elr_transform2dw)(const ElrPoint2DW *v,
                                    const ElrMatrix2D *m, ElrPoint2DW *d,
                                    int hn=0);

extern "C" void (*elr_transformv2d)(const ElrVector2D *v,
                                    const ElrMatrix2D *m, ElrVector2DW *d,
                                    int hn=0);

extern "C" void (*elr_transformv2dw)(const ElrVector2DW *v,
                                     const ElrMatrix2D *m, ElrVector2DW *d,
                                     int hn=0);

extern "C" void (*elr_normalize2d)(ElrVector2D *v);

extern "C" void (*elr_hnormalize2d)(ElrVector2DW *v);

extern "C" void (*elr_concatmatrix2d)(const ElrMatrix2D *s,
                                      const ElrMatrix2D *m, ElrMatrix2D *d,
                                      int hn=0);

extern "C" void (*elr_adjointmatrix2d)(const ElrMatrix2D *m, ElrMatrix2D *d,
                                       int hn=0);

extern "C" int (*elr_inversematrix2d)(const ElrMatrix2D *m, ElrMatrix2D *d,
                                      int hn=0);

//ÄÄ 3D operations
class ElrPoint3D;
class ElrPoint3DW;
class ElrVector3D;
class ElrVector3DW;
class ElrMatrix3D;

extern "C" void (*elr_transform3d)(const ElrPoint3D *v,
                                   const ElrMatrix3D *m, ElrPoint3DW *d,
                                   int hn=0);

extern "C" void (*elr_transform3dw)(const ElrPoint3DW *v,
                                    const ElrMatrix3D *m, ElrPoint3DW *d,
                                    int hn=0);

extern "C" void (*elr_transformv3d)(const ElrVector3D *v,
                                    const ElrMatrix3D *m, ElrVector3DW *d,
                                    int hn=0);

extern "C" void (*elr_transformv3dw)(const ElrVector3DW *v,
                                     const ElrMatrix3D *m, ElrVector3DW *d,
                                     int hn=0);

extern "C" ElrVector3D *(*elr_cross3d)(const ElrVector3D *v1,
                                       const ElrVector3D *v2, ElrVector3D *d);

extern "C" void (*elr_normalize3d)(ElrVector3D *v);

extern "C" void (*elr_hnormalize3d)(ElrVector3DW *v);

extern "C" void (*elr_concatmatrix3d)(const ElrMatrix3D *s,
                                      const ElrMatrix3D *m, ElrMatrix3D *d,
                                      int hn=0);

extern "C" void (*elr_adjointmatrix3d)(const ElrMatrix3D *m, ElrMatrix3D *d,
                                       int hn=0);

extern "C" int (*elr_inversematrix3d)(const ElrMatrix3D *m, ElrMatrix3D *d,
                                      int hn=0);

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - elrmath.hpp ²±°
