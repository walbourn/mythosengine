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
// esfile.hpp
//
//      Contains the file structures for the Escher 3D library.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

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

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Cameras                                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄ 'ECAM' - Camera data
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Lights                                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄ 'EAMB' - Ambient light source
struct EschFileLightAmbi
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    dword   color;
    char    na[8];
};

//ÄÄÄ 'EVEC' - Vector light source
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

//ÄÄÄ 'EFPT' - Fast point light source
//ÄÄÄ 'EPNT' - Point light source
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

//ÄÄÄ 'EFAT' - Fast Attenuated point light source
//ÄÄÄ 'EATN' - Attenuated point light source
struct EschFileLightAtten
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    Flx16   x;
    Flx16   y;
    Flx16   z;
    dword   color;
    Flx16   inner;
    Flx16   outer;
    char    na[4];
};

//ÄÄÄ 'EFSP' - Spot light source
//ÄÄÄ 'ESPT' - Spot light source
struct EschFileLightSpot
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    Flx16   x;
    Flx16   y;
    Flx16   z;
    Flx16   i;
    Flx16   j;
    Flx16   k;
    dword   color;
    Flx16   inner;
    Flx16   outer;
    Flx16   hotspot;
    Flx16   falloff;
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// FORM 'EMSH' - Mesh data IFF form.                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄ 'HDR ' - Header
struct EschFileMeshHDR 
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    ulong   nverts;
    ulong   nfaces;
    ulong   nmtls;
    char    na[32];
};

//ÄÄÄ 'MTRX' - Matrix
// Contains a single EschMatrix structure.

//ÄÄÄ 'EXNT' - Extents
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

//ÄÄÄ 'HIER' - Hierarchy
struct EschFileMeshHIER
{
    char    parent[ESCH_MAX_NAME];
};

//ÄÄÄ 'VERT' - Vertex
// Consists of an array of EschVertex structures

//ÄÄÄ 'FACE' - Face
// Consists of an array of EschFace structures

//ÄÄÄ 'MTL ' - Material description
struct EschFileMeshMTL
{
    char    name[ESCH_MAX_NAME];
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// FORM 'EMTL' - Material Data Form.                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄ 'HDR ' - Material Header
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

//ÄÄÄ 'BODY' - Material Body
// Raw data for the bitmap (use type in header to decode)


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// FORM 'ESEN' - Scene data IFF form.                                       ³
//               This form will contain all FORMs within the scene and      ³
//               heirachy information for connecting the objects.           ³
//               The various loaders will search for named objects within   ³
//               a ESEN form for their data.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄ 'HDR ' - Header
struct EschFileSceneHDR
{
    char    name[ESCH_MAX_NAME];
    ulong   ncameras;
    ulong   nobjects;
    ulong   nmaterials;
    ulong   nvectorlights;
    ulong   npointlights;
    ushort  nfpointlights;
    ushort  nattenlights; 
    ushort  nfattenlights; 
    ushort  nspotlights; 
    ushort  nfspotlights; 
    char    na[18];
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// FORM 'ETER' - Terrain Data Form.                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄ 'HDR ' - Header
struct EschFileTerrHDR
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    ushort  width;                      // Width of the height field
    ushort  depth;                      // Depth of the height field
    ushort  surfratio;                  // Height:Surface points ratio
    byte    compression;                // Compression flag for data (0=none)
    byte    ntxts;                      // Number of textures
    Flx16   wscale;                     // World space per unit in width (obs)
    Flx16   dscale;                     // World space per unit in depth (obs)
    Flx16   hscale;                     // World space per unit in height
    Flx16   scale;                      // World space per unit in width & depth
    Flx16   origin_x;                   // Origin location
    Flx16   origin_y;
    Flx16   origin_z;
    char    na[56];
    char    palname[16];                // Van Gogh palette used to color
                                        // terrain data
};

//ÄÄÄ 'HGTS' - Height data
// 2D array of bytes width*height in size, one row at a time.

//ÄÄÄ 'SURF' - Surface data
// 2D array of dwords (width*height)/(surfratio*2) in size, one row at a time.

//ÄÄÄ 'NRML' - Normals data
// 2D array of EschVectors (width*height)/(surfratio*2) in size, one row at a time.

//ÄÄÄ 'COLR' - Texture color data 
// Byte array for texture colors.

//ÄÄÄ 'HCLR' - Height color bands
struct EschFileTerrHCLR
{
    ushort  blue;
    ushort  lblue;
    ushort  white;
    ushort  green;
    ushort  lgreen;
    ushort  yellow;
    ushort  lorange;
    ushort  orange;
    ushort  lbrown;
    ushort  brown;
    ushort  red;
    char    na[10];
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - esfile.hpp ²±°

