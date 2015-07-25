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
//ששששששששששCopyrightש(c)ש1994,ש1995שbyשCharybdisשEnterprises,שInc.שששששששששש
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
// esfile.hpp
//
//      Contains the file structures for the Escher 3D library.
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

#ifndef __ESFILE_HPP
#define __ESFILE_HPP    1

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

#include <portable.h>
#include <felix.hpp>

#include "esdefs.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// CHUNK 'ECAM' - Camera data IFF block.                                    ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ

struct EschFileCamera
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    Flx16   x;
    Flx16   y;
    Flx16   z;
    Flx16   diri;
    Flx16   dirj;
    Flx16   dirk;
    Flx16   topi;
    Flx16   topj;
    Flx16   topk;
    Flx16   fov;
    char    na[4];
};

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// CHUNK 'EAMB' - Ambient light data IFF block                              ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ

struct EschFileLightAmbi
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    dword   color;
    char    na[8];
};

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// CHUNK 'EPNT' - Point light data IFF block                                ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ

struct EschFileLightPoint
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    Flx16   x;
    Flx16   y;
    Flx16   z;
    dword   color;
    char    na[12];
};

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// CHUNK 'EVEC' - Vector light data IFF block                               ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ

struct EschFileLightVect
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    Flx16   i;
    Flx16   j;
    Flx16   k;
    dword   color;
    char    na[12];
};

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// FORM 'EMSH' - Mesh data IFF form.                                        ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ

//ִִִ 'HDR ' - Header
struct EschFileMeshHDR 
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    ulong   nverts;
    ulong   nfaces;
    ulong   nmtls;
    char    na[32];
};

//ִִִ 'MTRX' - Matrix
// Contains a single EschMatrix structure.

//ִִִ 'EXNT' - Extents
struct EschFileMeshEXNT
{
    Flx16   cenx;
    Flx16   ceny;
    Flx16   cenz;
    Flx16   extent_radius;
    Flx16   minx;
    Flx16   miny;
    Flx16   minz;
    Flx16   maxx;
    Flx16   maxy;
    Flx16   maxz;
    char    na[8];
};

//ִִִ 'HIER' - Hierarchy
struct EschFileMeshHIER
{
    char    parent[ESCH_MAX_NAME];
};

//ִִִ 'VERT' - Vertex
// Consists of an array of EschVertex structures

//ִִִ 'FACE' - Face
// Consists of an array of EschFace structures

//ִִִ 'MTL ' - Material description
struct EschFileMeshMTL
{
    char    name[ESCH_MAX_NAME];
};

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// FORM 'EMTL' - Material Data Form.                                        ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ

//ִִִ 'HDR ' - Material Header
struct EschFileMtlMHDR
{
    char    name[ESCH_MAX_NAME];
    ushort  xsize;
    ushort  ysize;
    ushort  nframes;
    word    type;
    char    na[8];
    char    pname[16];
};

//ִִִ 'BODY' - Material Body
// Raw data for the bitmap (use type in header to decode)

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// FORM 'ESEN' - Scene data IFF form.                                       ³
//               This form will contain all FORMs within the scene and      ³
//               heirachy information for connecting the objects.           ³
//               The various loaders will search for named objects within   ³
//               a ESEN form for their data.                                ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ

//ִִִ 'HDR ' - Header
struct EschFileSceneHDR
{
    char    name[ESCH_MAX_NAME];
    ulong   ncameras;
    ulong   nobjects;
    ulong   nmaterials;
    ulong   nvectorlights;
    ulong   npointlights;
    char    na[28];
};

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// FORM 'ETER' - Terrain Data Form.                                         ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ

//ִִִ 'HDR ' - Header
struct EschFileTerrHDR
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    ushort  width;                      // Width of the height field
    ushort  depth;                      // Depth of the height field
    ushort  surfratio;                  // Height:Surface points ratio
    byte    compression;                // Compression flag for data (0=none)
    byte    ntxts;                      // Number of textures
    Flx16   wscale;                     // World space per unit in width
    Flx16   dscale;                     // World space per unit in depth
    Flx16   hscale;                     // World space per unit in height
    char    na[72];
    char    palname[16];                // Van Gogh palette used to color
                                        // terrain data
};

//ִִִ 'HGTS' - Height data
// 2D array of bytes width*height in size, one row at a time.

//ִִִ 'SURF' - Surface data
// 2D array of dwords (width*height)/(surfratio*2) in size, one row at a time.

//ִִִ 'NRML' - Normals data
// 2D array of EschVectors (width*height)/(surfratio*2) in size, one row at a time.

//ִִִ 'COLR' - Texture color data 
// Byte array for texture colors.


#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - esfile.hpp ²±°

