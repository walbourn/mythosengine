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
// esdefs.h
//
// Contains the global constants and defines for the Escher 3D library. 
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __ESDEFS_H
#define __ESDEFS_H    1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Error values                                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
typedef enum _esch_error_codes
{
    //ÄÄÄ General error codes
    ESCH_ERR_NONE                   =0,     // No Error
    ESCH_ERR_INVALIDPARMS           =1,     // Invalid parameters
    ESCH_ERR_NOMEMORY               =2,     // Not enough memory
    ESCH_ERR_LOCKFAILED             =3,     // Lock of handle memory failed
    ESCH_ERR_REFERENCED             =4,     // Object referenced, can't
                                            // release data.

    //ÄÄÄ File error codes
    ESCH_ERR_FILEERROR              =10,    // Error with file i/o
    ESCH_ERR_NOTFOUND               =11,    // Not found
    ESCH_ERR_INVALIDDATA            =12,    // Invalid data
    ESCH_ERR_INVALIDVDATA           =13,    // Invalid Vertex data
    ESCH_ERR_INVALIDFDATA           =14,    // Invalid Face data
    ESCH_ERR_MISSINGITEMS           =15,    // Items missing from form
    ESCH_ERR_NOTSUPPORTED           =16,    // Operation not supported
    ESCH_ERR_MISSINGDATA            =17,    // Needed data missing
    ESCH_ERR_INVALIDHIER            =18,    // Hierarchy invalid data
    ESCH_ERR_INVALIDHGTDATA         =19,    // Invalid height data
    ESCH_ERR_INVALIDSRFDATA         =20,    // Invalid surface data

    //ÄÄÄ Drawable picking/collide error codes
    ESCH_ERR_NEEDILIST              =30,    // No input list
    ESCH_ERR_NEEDARENA              =31,    // Arena missing
    ESCH_ERR_NEEDCAMERA             =32,    // Need camera data

    //ÄÄÄ Shade-table generation error codes
    ESCH_ERR_NEEDVPORT              =40,    // Camera needs viewport
} esch_error_codes;


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Clip draw face flags                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_CDF_CLIP           0x1
#define ESCH_CDF_BFCULL         0x2
#define ESCH_CDF_INFINITEZ      0x4
#define ESCH_CDF_MUSTTXT        0x8

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Update flags                                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_UPD_INVERSE            0x1     // Update inverse (FrameRef)
#define ESCH_UPD_ORTHO              0x2     // Check Orthonormalize (FrameRef)

#define ESCH_UPD_WORLD              0x10    // Update world frameref (Geometry)
#define ESCH_UPD_EXTENTS            0x20    // Update extents (Geometry)

#define ESCH_UPD_EYE                0x10    // Update eye frameref (Camera)
#define ESCH_UPD_SCALAR             0x20    // Update scalar/zfactor (Camera)

#define ESCH_UPD_ALL                0xff


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Render control flags                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_REND_PRE               0x1     // Perform pre-render
#define ESCH_REND_DRAW              0x2     // Perform render draw
#define ESCH_REND_POST              0x4     // Perform post processing

#define ESCH_REND_ALL               0xff


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTexture                                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_TXT_LOCKED             0x1     // Texture ptr valid
#define ESCH_TXT_SKIPANIMATE        0x2     // Skip texture for animate()
#define ESCH_TXT_OWNSDATA           0x10000 // Texture should free data on destruct

#define ESCH_TXT_APP0               0x1000000   // Application defined bits
#define ESCH_TXT_APP1               0x2000000
#define ESCH_TXT_APP2               0x4000000
#define ESCH_TXT_APP3               0x8000000
#define ESCH_TXT_APP4               0x10000000
#define ESCH_TXT_APP5               0x20000000
#define ESCH_TXT_APP6               0x40000000
#define ESCH_TXT_APP7               0x80000000


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera                                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_CAM_SHADE_WIRE         0x1     // Render with wireframe
#define ESCH_CAM_SHADE_SOLID        0x2     // Render with solid colors
#define ESCH_CAM_SHADE_FLAT         0x4     // Render with flat shading
#define ESCH_CAM_SHADE_SMOOTH       0x8     // Render with smoothed shading
#define ESCH_CAM_SHADE_SPECULAR     0x80    // Render with specular highlight

#define ESCH_CAM_BACKCULL           0x100   // Backface culling
#define ESCH_CAM_TEXTURED           0x200   // If set, textures on faces drawn
#define ESCH_CAM_PERSPECTIVE        0x400   // Draw with perspective routines

#define ESCH_CAM_SHOW_ALL_LINES     0x1000  // Don't use visibility flags for 
                                            // wireframe mode

#define ESCH_CAM_VPWASLOCKED        0x2000  // pre_rend() sets/clears this for post_rend()

#define ESCH_CAM_NOCLEAR            0x4000  // Don't clear viewport on render

#define ESCH_CAM_MODELSPACE         0x8000  // Perform lighting in model-space
                                            // instead of world-space.

#define ESCH_CAM_HAZE               0x10000 // Hazing effect active (Ex)
#define ESCH_CAM_IGNORE_BMAP        0x20000 // Ignore's background bitmap if defined (Ex)

#define ESCH_CAM_OWNSBITMAP         0x100000// Owns background bitmap (Ex)
#define ESCH_CAM_OWNSHAZE           0x200000// Owns haze palette (Ex)

#define ESCH_CAM_APP0               0x1000000   // Application defined bits
#define ESCH_CAM_APP1               0x2000000
#define ESCH_CAM_APP2               0x4000000
#define ESCH_CAM_APP3               0x8000000
#define ESCH_CAM_APP4               0x10000000
#define ESCH_CAM_APP5               0x20000000
#define ESCH_CAM_APP6               0x40000000
#define ESCH_CAM_APP7               0x80000000


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschLight                                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄ Flags
#define ESCH_LGT_OFF                0x1     // Light is off
#define ESCH_LGT_ATTEN              0x10    // Light attenuates over a range

#define ESCH_LGT_APP0               0x1000000   // Application defined bits
#define ESCH_LGT_APP1               0x2000000
#define ESCH_LGT_APP2               0x4000000
#define ESCH_LGT_APP3               0x8000000
#define ESCH_LGT_APP4               0x10000000
#define ESCH_LGT_APP5               0x20000000
#define ESCH_LGT_APP6               0x40000000
#define ESCH_LGT_APP7               0x80000000

//ÄÄÄ Types
#ifdef __cplusplus
const word ESCH_LGTT_AMBIENT        =0x0000;
const word ESCH_LGTT_VECTOR         =0x0100;
const word ESCH_LGTT_FPOINT         =0x0200;
const word ESCH_LGTT_FATTEN         =0x0210;
const word ESCH_LGTT_FSPOT          =0x0211;
const word ESCH_LGTT_POINT          =0x0300;
const word ESCH_LGTT_ATTEN          =0x0310;
const word ESCH_LGTT_SPOT           =0x0311;
#else
#define  ESCH_LGTT_AMBIENT          0x0000
#define  ESCH_LGTT_VECTOR           0x0100
#define  ESCH_LGTT_FPOINT           0x0200
#define  ESCH_LGTT_FATTEN           0x0210
#define  ESCH_LGTT_FSPOT            0x0211
#define  ESCH_LGTT_POINT            0x0300
#define  ESCH_LGTT_ATTEN            0x0310
#define  ESCH_LGTT_SPOT             0x0311
#endif

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCollision                                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_CLSN_NOSETUP           0x1     // Assume structure setup already
#define ESCH_CLSN_NOWALK            0x2     // Only use first item in input list
#define ESCH_CLSN_TESTSELF          0x4     // Test first item in input list
#define ESCH_CLSN_ILIST             0x8     // Use input list instead of context
#define ESCH_CLSN_ARENA             0x10    // Use arean instead of systems
#define ESCH_CLSN_MAXCOUNT          0x20    // Use max count instead of 1
#define ESCH_CLSN_COARSE            0x40    // Use coarse tests only
#define ESCH_CLSN_SPHERE            0x80    // Sphere member set manually

#define ESCH_CLSN_APP0              0x1000000   // Application defined bits
#define ESCH_CLSN_APP1              0x2000000
#define ESCH_CLSN_APP2              0x4000000
#define ESCH_CLSN_APP3              0x8000000
#define ESCH_CLSN_APP4              0x10000000
#define ESCH_CLSN_APP5              0x20000000
#define ESCH_CLSN_APP6              0x40000000
#define ESCH_CLSN_APP7              0x80000000


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPicking                                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_PICK_NOSETUP           0x1     // Assume structure setup already
#define ESCH_PICK_NOWALK            0x2     // Don't walk input list
#define ESCH_PICK_TESTSELF          0x4     // Test first item in input list
#define ESCH_PICK_ILIST             0x8     // Use input list instead of context
#define ESCH_PICK_ARENA             0x10    // Use arean instead of systems
#define ESCH_PICK_MAXCOUNT          0x20    // Use max count instead of 1
#define ESCH_PICK_COARSE            0x40    // Use coarse tests only
#define ESCH_PICK_CAMERA            0x80    // Use camera instead of context
#define ESCH_PICK_MAXDIST           0x100   // Limit maximum pick distance
#define ESCH_PICK_VPORT             0x200   // Pick using camera's viewport
#define ESCH_PICK_WORLD             0x400   // Pick using world data

#define ESCH_PICK_APP0              0x1000000   // Application defined bits
#define ESCH_PICK_APP1              0x2000000
#define ESCH_PICK_APP2              0x4000000
#define ESCH_PICK_APP3              0x8000000
#define ESCH_PICK_APP4              0x10000000
#define ESCH_PICK_APP5              0x20000000
#define ESCH_PICK_APP6              0x40000000
#define ESCH_PICK_APP7              0x80000000


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschDrawable                                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄ Flags
#define ESCH_DRW_SKIP               0x1     // Skip this drawable during draw
                                            // and collide/pick tests.
#define ESCH_DRW_OWNSDATA           0x2     // Buffers associated should be
                                            // deleted on destruction.
#define ESCH_DRW_SKIPTEST           0x4     // Skip this drawable during
                                            // collide/pick tests only

#define ESCH_DRW_APP0               0x1000000   // Application defined bits
#define ESCH_DRW_APP1               0x2000000
#define ESCH_DRW_APP2               0x4000000
#define ESCH_DRW_APP3               0x8000000
#define ESCH_DRW_APP4               0x10000000
#define ESCH_DRW_APP5               0x20000000
#define ESCH_DRW_APP6               0x40000000
#define ESCH_DRW_APP7               0x80000000

//ÄÄÄ Types
#ifdef __cplusplus
const word ESCH_DRWT_BASE           =0x0000;
const word ESCH_DRWT_POINTDRAW      =0x0100;
const word ESCH_DRWT_PARTICLE       =0x0200;
const word ESCH_DRWT_PRTPYRAMID     =0x0210;
const word ESCH_DRWT_PRTGEOMETRY    =0x0220;
const word ESCH_DRWT_PSYSTEM        =0x0300;
const word ESCH_DRWT_GEOM           =0x0400;
const word ESCH_DRWT_MESH           =0x0410;
const word ESCH_DRWT_TERRAIN        =0x0500;
const word ESCH_DRWT_SPRITE         =0x0600;
const word ESCH_DRWT_STARFIELD      =0x1000;
const word ESCH_DRWT_EXPLOSION      =0x1100;
#else
#define ESCH_DRWT_BASE              0x0000
#define ESCH_DRWT_POINTDRAW         0x0100
#define ESCH_DRWT_PARTICLE          0x0200
#define ESCH_DRWT_PRTPYRAMID        0x0210
#define ESCH_DRWT_PRTGEOMETRY       0x0220
#define ESCH_DRWT_PSYSTEM           0x0300
#define ESCH_DRWT_GEOM              0x0400
#define ESCH_DRWT_MESH              0x0410
#define ESCH_DRWT_TERRAIN           0x0500
#define ESCH_DRWT_SPRITE            0x0600
#define ESCH_DRWT_STARFIELD         0x1000
#define ESCH_DRWT_EXPLOSION         0x1100
#endif

//ÄÄÄ EschMeshDraw

#define ESCH_MSHD_OWNSTEXTURE       0x10000 // Own's instance textures, so
                                            // delete on detach.
#define ESCH_MSHD_NOEXTENTSCHK      0x20000 // Don't perform extent's check

//ÄÄÄ EschTerrain

#define ESCH_TRN_DOTS               0x10000 // Draws height field as dots 
#define ESCH_TRN_LOD                0x20000 // Draw w/ Level Of Detail adjustments

//ÄÄÄ EschSprite

#define ESCH_SPRITE_INFINITE        0x10000 // Sprite should be treated
                                            // as if it is at an infinite
                                            // distance.

//ÄÄÄ EschStarfield

#define ESCH_SFLD_FTL               0x10000 // Causes stars to move with
                                            // translation.


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschVertex                                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄ Volitile flags
#define ESCH_VVERT_TRANSFORMED      0x1     // Vertex transformed
#define ESCH_VVERT_PROJECTED        0x2     // Vertex projected
#define ESCH_VVERT_LIT              0x4     // Vertex lit
#define ESCH_VVERT_ISCLIPPED        0x8     // Vertix is clipped
#define ESCH_VVERT_CLIPLEFT         0x10    // Vertex is clipped left
#define ESCH_VVERT_CLIPRIGHT        0x20    // Vertex is clipped right
#define ESCH_VVERT_CLIPTOP          0x40    // Vertex is clipped top
#define ESCH_VVERT_CLIPBOTTOM       0x80    // Vertex is clipped bottom


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFace                                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄ Static flags
#define ESCH_FACE_WIRE              0x1     // Render with wireframe
#define ESCH_FACE_SOLID             0x2     // Render with solid colors
#define ESCH_FACE_FLAT              0x4     // Render with flat shading
#define ESCH_FACE_SMOOTH            0x8     // Render with smoothed shading
#define ESCH_FACE_SPECULAR          0x80    // Render with specular highlight

#define ESCH_FACE_ONESIDED          0x100   // Face visible from only one side

#define ESCH_FACE_TEXTURED          0x200   // Has a texture-map

#define ESCH_FACE_ALLOWPERSP        0x400   // Allow perspective mode

#define ESCH_FACE_ABLINE            0x1000  // Visiblity for wireframe mode
#define ESCH_FACE_BCLINE            0x2000
#define ESCH_FACE_CALINE            0x4000

#define ESCH_FACE_SELFILUM_MASK     0xf00000 // Face self illum level
                                             // (0 is no self-illumination,
                                             //  f is fully self-illuminated)

#define ESCH_FACE_APP0              0x10000000 // Application defined bits
#define ESCH_FACE_APP1              0x20000000
#define ESCH_FACE_APP2              0x40000000
#define ESCH_FACE_APP3              0x80000000


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMesh                                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄ Flags
#define ESCH_MSH_APP0               0x1     // Application defined bits
#define ESCH_MSH_APP1               0x2
#define ESCH_MSH_APP2               0x4
#define ESCH_MSH_APP3               0x8
#define ESCH_MSH_APP4               0x10
#define ESCH_MSH_APP5               0x20
#define ESCH_MSH_APP6               0x40
#define ESCH_MSH_APP7               0x80
#define ESCH_MSH_APP8               0x100
#define ESCH_MSH_APP9               0x200
#define ESCH_MSH_APPA               0x400
#define ESCH_MSH_APPB               0x800
#define ESCH_MSH_APPC               0x1000
#define ESCH_MSH_APPD               0x2000
#define ESCH_MSH_APPE               0x4000
#define ESCH_MSH_APPF               0x8000

#define ESCH_MSH_OWNSDATA           0x10000 // Buffers (except textures)
                                            // should be freed by destructor
#define ESCH_MSH_OWNSTEXTURE        0x20000 // Textures should be freed
                                            // by the destructor


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschScene                                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄ Flags
#define ESCH_SCENE_OWNSDATA         0x1

#define ESCH_SCENE_APP0               0x1000000   // Application defined bits
#define ESCH_SCENE_APP1               0x2000000
#define ESCH_SCENE_APP2               0x4000000
#define ESCH_SCENE_APP3               0x8000000
#define ESCH_SCENE_APP4               0x10000000
#define ESCH_SCENE_APP5               0x20000000
#define ESCH_SCENE_APP6               0x40000000
#define ESCH_SCENE_APP7               0x80000000

//ÄÄÄ Load Flags
#define ESCH_SCENELD_LIGHTS         0x1
#define ESCH_SCENELD_CAMERAS        0x2
#define ESCH_SCENELD_MESHES         0x4
#define ESCH_SCENELD_HIERARCHY      0x8
#define ESCH_SCENELD_ALL            0xf

#define ESCH_SCENELD_CAMSEX         0x10


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTerrain                                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_SURF_FLIPU             0x1
#define ESCH_SURF_FLIPV             0x2
#define ESCH_SURF_CINDISTXT         0x4
#define ESCH_SURF_CBIT4             0x8
#define ESCH_SURF_TILE1             0x10
#define ESCH_SURF_TILE2             0x20
#define ESCH_SURF_TILE3             0x40
#define ESCH_SURF_NOTILE            0x80
#define ESCH_SURF_HIGHONLY          0x100
#define ESCH_SURF_HIDDEN            0x200
#define ESCH_SURF_CBIT11            0x400
#define ESCH_SURF_CBIT12            0x800
#define ESCH_SURF_APP0              0x1000
#define ESCH_SURF_APP1              0x2000
#define ESCH_SURF_APP2              0x4000
#define ESCH_SURF_APP3              0x8000


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Misc. constants                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#ifdef __cplusplus
const ulong ESCH_MAX_NAME           =16;    // maximum name length
const ulong ESCH_MAX_ORTHOCOUNT     =8;

#else
#define ESCH_MAX_NAME               16      // maximum name length
#define ESCH_MAX_ORTHOCOUNT         8
#endif

#endif

//°±² End of header - esdefs.h ²±°

