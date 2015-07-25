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

//ÄÄÄ 'ECA1' (floating-point)
struct EschFileCamera
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    float   x;
    float   y;
    float   z;
    float   diri;
    float   dirj;
    float   dirk;
    float   topi;
    float   topj;
    float   topk;
    float   fov;
    char    na[4];
};


//ÄÄÄ 'ECAM' (16.16 fixed-point)
struct EschFileCameraV1
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    long    x;
    long    y;
    long    z;
    long    diri;
    long    dirj;
    long    dirk;
    long    topi;
    long    topj;
    long    topk;
    long    fov;
    char    na[4];
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Lights                                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Ambient light source
//ÄÄÄ 'EAMB'
struct EschFileLightAmbi
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    dword   color;
    char    na[8];
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Vector light source
//ÄÄÄ 'EVE1' (floating-point)
struct EschFileLightVect
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    float   i;
    float   j;
    float   k;
    dword   color;
    char    na[12];
};

//ÄÄÄ 'EVEC' (fixed-point)
struct EschFileLightVectV1
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    long    i;
    long    j;
    long    k;
    dword   color;
    char    na[12];
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Fast/normal point light source
//ÄÄÄ 'EFP1' (floating-point)
//ÄÄÄ 'EPN1' (floating-point)
struct EschFileLightPoint
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    float   x;
    float   y;
    float   z;
    dword   color;
    char    na[12];
};

//ÄÄÄ 'EFPT' (fixed-point)
//ÄÄÄ 'EPNT' (fixed-point)
struct EschFileLightPointV1
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    long    x;
    long    y;
    long    z;
    dword   color;
    char    na[12];
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Fast/normal attenuated point light source
//ÄÄÄ 'EFA1' (floating-point)
//ÄÄÄ 'EAT1' (floating-point)
struct EschFileLightAtten
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    float   x;
    float   y;
    float   z;
    dword   color;
    float   inner;
    float   outer;
    char    na[4];
};

//ÄÄÄ 'EFAT' (fixed-point)
//ÄÄÄ 'EATN' (fixed-point)
struct EschFileLightAttenV1
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    long    x;
    long    y;
    long    z;
    dword   color;
    long    inner;
    long    outer;
    char    na[4];
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Fast/normal spot light source
//ÄÄÄ 'EFS1' (floating-point)
//ÄÄÄ 'ESP1' (floating-point)
struct EschFileLightSpot
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    float   x;
    float   y;
    float   z;
    float   i;
    float   j;
    float   k;
    dword   color;
    float   inner;
    float   outer;
    float   hotspot;
    float   falloff;
};

//ÄÄÄ 'EFSP' (fixed-point)
//ÄÄÄ 'ESPT' (fixed-point)
struct EschFileLightSpotV1
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    long    x;
    long    y;
    long    z;
    long    i;
    long    j;
    long    k;
    dword   color;
    long    inner;
    long    outer;
    long    hotspot;
    long    falloff;
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// FORM 'EMSH' - Mesh data IFF form.                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Header
//ÄÄÄ 'HDR '
struct EschFileMeshHDR
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    ulong   nverts;
    ulong   nfaces;
    ulong   nmtls;
    char    na[32];
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Matrix
//ÄÄÄ 'MTR1' (floating-point)
// Contains a single EschMatrix structure.

//ÄÄÄ 'MTRX' (fixed-point)
struct EschMatrixV1
{
    long    mtx[3*4];
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Extents
//ÄÄÄ 'EXN1' (floating-point)
struct EschFileMeshEXNT
{
    float   cenx;
    float   ceny;
    float   cenz;
    float   extent_radius;
    float   minx;
    float   miny;
    float   minz;
    float   maxx;
    float   maxy;
    float   maxz;
    char    na[8];
};

//ÄÄÄ 'EXNT' (fixed-point)
struct EschFileMeshEXNTV1
{
    long    cenx;
    long    ceny;
    long    cenz;
    long    extent_radius;
    long    minx;
    long    miny;
    long    minz;
    long    maxx;
    long    maxy;
    long    maxz;
    char    na[8];
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Hierarchy
//ÄÄÄ 'HIER'
struct EschFileMeshHIER
{
    char    parent[ESCH_MAX_NAME];
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Vertex
//ÄÄÄ 'VER1' (floating-point)
// Consists of an array of EschVertex structures

//ÄÄÄ 'VERT' (fixed-point)
struct EschVertexV1
{
    long        x;
    long        y;
    long        z;
    dword       na;
    struct
    {
        long    i;
        long    j;
        long    k;
        dword   na;
    }       normal;
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Face
//ÄÄÄ 'FAC2' (floating-point w/ alpha)
// Consists of an array of EschFace structures

//ÄÄÄ 'FAC1' (floating-point)
#define ESCH_FACEV2_SILLUM_MASK 0xf00000
#define ESCH_FACEV2_ALPHA_MASK 0xf000000
struct EschFaceV2
{
    dword           flags;
    word            a;
    word            b;
    word            c;
    word            txt;
    float           u[3];
    float           v[3];
    dword           color;
    struct
    {
        float       i;
        float       j;
        float       k;
        dword       na;
    }       normal;
};

//ÄÄÄ 'FACE' (fixed-point)
#define ESCH_FACEV1_SILLUM_MASK 0xf00000
#define ESCH_FACEV1_ALPHA_MASK 0xf000000
struct EschFaceV1
{
    dword           flags;
    word            a;
    word            b;
    word            c;
    word            txt;
    long            u[3];
    long            v[3];
    dword           color;
    struct
    {
        long        i;
        long        j;
        long        k;
        dword       na;
    }       normal;
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Material description
//ÄÄÄ 'MTL '
struct EschFileMeshMTL
{
    char    name[ESCH_MAX_NAME];
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// FORM 'EMTL', 'EMT1' - Material Data Form.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Material Header
//ÄÄÄ 'HDR '
struct EschFileMtlMHDR
{
    char    name[ESCH_MAX_NAME];
    ushort  xsize;
    ushort  ysize;
    ushort  nframes;        // Always 1 for EMTL
    byte    type;
    byte    compress;
    dword   flags;
    char    na[4];
    char    pname[16];
};

#define ESCH_MTL_TYPE_8BIT          1
#define ESCH_MTL_TYPE_8BIT_TRANSP   2
#define ESCH_MTL_TYPE_24BIT         3
#define ESCH_MTL_TYPE_32BIT         4

#define ESCH_MTL_COMPRESS_NONE      0
#define ESCH_MTL_COMPRESS_RLE       1

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Material Body
//ÄÄÄ 'BODY'
// Raw data for the bitmap (use type in header to decode)


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// FORM 'KEYF' - Keyframing data IFF form.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Header
//ÄÄÄ 'HDR '
struct EschFileKeyframeHeader
{
    char    m_type[M_TYPE_LEN];
    ulong   flags;
    long   key_depth;
    char    chain[M_TYPE_LEN];
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Keyframes
//ÄÄÄ 'KEY1' (floating-point)
struct EschFileKeyframe
{
    ulong   k_type;
    int     frame_num;
    float   rotation[3];
};

//ÄÄÄ 'KEY ' (fixed-point)
struct EschFileKeyframeV1
{
    ulong   k_type;
    int     frame_num;
    long    rotation[3];
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// FORM 'ETOK' - Escher Keyframe Token data IFF form.                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Header
//ÄÄÄ 'HDR '
struct EschFileTokenHeader
{
    ulong   ver;
    ulong   count;
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Tokens
//ÄÄÄ 'KTOK'
struct EschFileToken
{
    char    name[ESCH_MAX_NAME];
    ulong   type;
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// FORM 'ESEN' - Scene data IFF form.                                       ³
//               This form will contain all FORMs within the scene and      ³
//               heirachy information for connecting the objects.           ³
//               The various loaders will search for named objects within   ³
//               a ESEN form for their data.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Header
//ÄÄÄ 'HDR '
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

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Header
//ÄÄÄ 'HDR1' (floating-point)
struct EschFileTerrHDR
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    ushort  width;                      // Width of the height field
    ushort  depth;                      // Depth of the height field
    ushort  surfratio;                  // Height:Surface points ratio
    byte    compression;                // Compression flag for data (0=none)
    byte    ntxts;                      // Number of textures
    float   wscale;                     // World space per unit in width (obs)
    float   dscale;                     // World space per unit in depth (obs)
    float   hscale;                     // World space per unit in height
    float   scale;                      // World space per unit in width & depth
    float   origin_x;                   // Origin location
    float   origin_y;
    float   origin_z;
    char    na[56];
    char    palname[16];                // Van Gogh palette used to color
                                        // terrain data
};

//ÄÄÄ 'HDR ' (fixed-point)
struct EschFileTerrHDRV1
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    ushort  width;                      // Width of the height field
    ushort  depth;                      // Depth of the height field
    ushort  surfratio;                  // Height:Surface points ratio
    byte    compression;                // Compression flag for data (0=none)
    byte    ntxts;                      // Number of textures
    long    wscale;                     // World space per unit in width (obs)
    long    dscale;                     // World space per unit in depth (obs)
    long    hscale;                     // World space per unit in height
    long    scale;                      // World space per unit in width & depth
    long    origin_x;                   // Origin location
    long    origin_y;
    long    origin_z;
    char    na[56];
    char    palname[16];                // Van Gogh palette used to color
                                        // terrain data
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Height data
//ÄÄÄ 'HGTS'
// 2D array of bytes width*height in size, one row at a time.

//ÄÄÄ 256 entry array of height index to elevation mappings
//ÄÄÄ 'HTB1' (floating-point)
//ÄÄÄ 'HTBL' (fixed-point)

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Surface data
//ÄÄÄ 'SURF'
// 2D array of dwords (width*height)/(surfratio*2) in size, one row at a time.

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Material description
//ÄÄÄ 'MTL '
struct EschFileTerrMTL
{
    char    name[ESCH_MAX_NAME];
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Normals data
//ÄÄÄ 'NRM2' (floating-point)
// 2D array of EschVectors (width*height)/(surfratio*2) in size, one row at a time.

//ÄÄÄ 'NRM1' (compressed fixed-point)
// 2D array of ushorts 4*(width*height)/(surfratio*2) in size, one row at a time
// where each 4 ushort set lower 16-bits of a 16.16 number for i,j,k and
// the 1 and sign bits encoded into the 4th ushort.

//ÄÄÄ 'NRML' (fixed-point)
// 2D array of EschVectorV1s (width*height)/(surfratio*2) in size, one row at a time.
struct EschVectorV1
{
    long        i;
    long        j;
    long        k;
    dword       na;
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Texture color data
//ÄÄÄ 'COLR'
// Byte array for texture colors.

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Height color bands
//ÄÄÄ 'HCLR'
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

