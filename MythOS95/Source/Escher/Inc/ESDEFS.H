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
    ESCH_ERR_INVALIDBEND            =21,    // Invalid bend constraint data

    //ÄÄÄ Drawable picking/collide/traverse error codes
    ESCH_ERR_NEEDILIST              =30,    // No input list
    ESCH_ERR_NEEDARENA              =31,    // Arena missing
    ESCH_ERR_NEEDCAMERA             =32,    // Need camera data
    ESCH_ERR_NEEDTERRAIN            =33,    // Need terrain data
    ESCH_ERR_STOPPED                =34,    // Traverse callback returned non-zero

    //ÄÄÄ Shade-table generation error codes
    ESCH_ERR_NEEDVPORT              =40,    // Camera needs viewport

    //ÄÄÄ Texture errors
    ESCH_ERR_INVALIDSIZE            =50,    // Input size invalid

    //ÄÄÄ Builder errors
    ESCH_ERR_NOMORE                 =60,    // No more room

} esch_error_codes;


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Clip draw face flags                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_CDF_CLIP           0x1
#define ESCH_CDF_BFCULL         0x2
#define ESCH_CDF_INFINITEZ      0x4
#define ESCH_CDF_MUSTTXT        0x8
#define ESCH_CDF_DONTSORT       0x10
#define ESCH_CDF_COLOR          0x20
#define ESCH_CDF_ALPHA          0x40

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
// EschSystem                                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_SYS_AMD3D              0x2

#define ESCH_SYS_MMX_FOUND          0x10000
#define ESCH_SYS_AMD3D_FOUND        0x20000


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschElement                                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄ Types
#define ESCH_ELMNT_BASE             0x0000
#define ESCH_ELMNT_PIXEL            0x0100
#define ESCH_ELMNT_LINE             0x0200
#define ESCH_ELMNT_POLY             0x0300
#define ESCH_ELMNT_GPOLY            0x0301
#define ESCH_ELMNT_GPOLY_PERSP      0x0302
#define ESCH_ELMNT_POLY_A           0x0310
#define ESCH_ELMNT_GPOLY_A          0x0311
#define ESCH_ELMNT_GPOLY_PERSP_A    0x0312
#define ESCH_ELMNT_TXTPOLY          0x0320
#define ESCH_ELMNT_TXTPOLY_PERSP    0x0321
#define ESCH_ELMNT_GTXTPOLY         0x0322
#define ESCH_ELMNT_GTXTPOLY_PERSP   0x0323
#define ESCH_ELMNT_TXTPOLY_A        0x0330
#define ESCH_ELMNT_TXTPOLY_PERSP_A  0x0331
#define ESCH_ELMNT_GTXTPOLY_A       0x0332
#define ESCH_ELMNT_GTXTPOLY_PERSP_A 0x0333


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTexture                                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_TXT_LOCKED             0x1     // Texture ptr valid
#define ESCH_TXT_SKIPANIMATE        0x2     // Skip texture for animate()
#define ESCH_TXT_OWNSDATA           0x10000 // Texture should free data on destruct
#define ESCH_TXT_SHARED             0x20000 // Texture instance shares
                                            // data in texture cache

#define ESCH_TXT_APP0               0x1000000   // Application defined bits
#define ESCH_TXT_APP1               0x2000000
#define ESCH_TXT_APP2               0x4000000
#define ESCH_TXT_APP3               0x8000000
#define ESCH_TXT_APP4               0x10000000
#define ESCH_TXT_APP5               0x20000000
#define ESCH_TXT_APP6               0x40000000
#define ESCH_TXT_APP7               0x80000000

//ÄÄÄ Multi-frame Textures
#define ESCH_MFTXT_TIMEBASED        0x100   // Animated based on rate/interval

//ÄÄÄ Types
#define ESCH_TXTT_BASE              0x0000
#define ESCH_TXTT_STATIC            0x0100
#define ESCH_TXTT_MFRAME            0x0200
#define ESCH_TXTT_PRC               0x0300
#define ESCH_TXTT_PRCFIRE           0x0301

#define ESCH_TXTT_BASEMASK          0xff00

//ÄÄÄ Load flags
#define ESCH_TXTLD_SHARE            0x1
#define ESCH_TXTLD_MFRAME           0x2

#define ESCH_TXTLD_ALL              0xf


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera                                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_CAM_SHADE_WIRE         0x1         // Render with wireframe
#define ESCH_CAM_SHADE_SOLID        0x2         // Render with solid colors
#define ESCH_CAM_SHADE_FLAT         0x4         // Render with flat shading
#define ESCH_CAM_SHADE_SMOOTH       0x8         // Render with smoothed shading
#define ESCH_CAM_SHADE_SPECULAR     0x80        // Render with specular highlight

#define ESCH_CAM_BACKCULL           0x100       // Backface culling
#define ESCH_CAM_TEXTURED           0x200       // If set, textures on faces drawn
#define ESCH_CAM_PERSPECTIVE        0x400       // Draw with perspective routines
#define ESCH_CAM_ALPHA              0x800       // If set, alpha on faces is used

#define ESCH_CAM_SHOW_ALL_LINES     0x1000      // Don't use visibility flags for
                                                // wireframe mode

#define ESCH_CAM_VPWASLOCKED        0x2000      // pre_rend() sets/clears this for post_rend()

#define ESCH_CAM_NOCLEAR            0x4000      // Don't clear viewport on render

#define ESCH_CAM_MODELSPACE         0x8000      // Perform lighting in model-space
                                                // instead of world-space.

#define ESCH_CAM_SORT               0x10000     // Must sort all output elements
                                                // (pixels, lines, triangles, etc.)

#define ESCH_CAM_NOFLUSH            0x20000     // Don't flush element list on render

#define ESCH_CAM_TRUESORT           0x40000     // Use true sorting during flush

#define ESCH_CAM_ORTHO              0x80000     // Camera is orthographic, not perspective

#define ESCH_CAM_IGNORE_BMAP        0x100000    // Ignore's background bitmap if defined (Ex)
#define ESCH_CAM_GRADIENT           0x200000    // Gradient background (Ex)

#define ESCH_CAM_OWNSBITMAP         0x400000    // Owns background bitmap (Ex)
#define ESCH_CAM_OWNSGRADIENT       0x800000    // Owns gradient palette (Ex)

#define ESCH_CAM_APP0               0x1000000   // Application defined bits
#define ESCH_CAM_APP1               0x2000000
#define ESCH_CAM_APP2               0x4000000
#define ESCH_CAM_APP3               0x8000000
#define ESCH_CAM_APP4               0x10000000
#define ESCH_CAM_APP5               0x20000000
#define ESCH_CAM_APP6               0x40000000
#define ESCH_CAM_APP7               0x80000000

#define ESCH_CAM_FRUSTRUM_HITHER    0
#define ESCH_CAM_FRUSTRUM_YON       1
#define ESCH_CAM_FRUSTRUM_LEFT      2
#define ESCH_CAM_FRUSTRUM_RIGHT     3
#define ESCH_CAM_FRUSTRUM_TOP       4
#define ESCH_CAM_FRUSTRUM_BOTTOM    5


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschLight                                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄ Flags
#define ESCH_LGT_OFF                0x1         // Light is off
#define ESCH_LGT_DARK               0x2         // Light is a darklight
#define ESCH_LGT_ATTEN              0x10        // Light attenuates over a range

#define ESCH_LGT_APP0               0x1000000   // Application defined bits
#define ESCH_LGT_APP1               0x2000000
#define ESCH_LGT_APP2               0x4000000
#define ESCH_LGT_APP3               0x8000000
#define ESCH_LGT_APP4               0x10000000
#define ESCH_LGT_APP5               0x20000000
#define ESCH_LGT_APP6               0x40000000
#define ESCH_LGT_APP7               0x80000000

//ÄÄÄ Types
#define ESCH_LGTT_AMBIENT           0x0000
#define ESCH_LGTT_VECTOR            0x0100
#define ESCH_LGTT_FPOINT            0x0200
#define ESCH_LGTT_FATTEN            0x0210
#define ESCH_LGTT_FSPOT             0x0211
#define ESCH_LGTT_POINT             0x0300
#define ESCH_LGTT_ATTEN             0x0310
#define ESCH_LGTT_SPOT              0x0311


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCollision                                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_CLSN_NOSETUP           0x1     // Assume structure setup already
#define ESCH_CLSN_NOWALK            0x2     // Only use first item in input list
#define ESCH_CLSN_TESTSELF          0x4     // Test first item in input list
#define ESCH_CLSN_ILIST             0x8     // Use input list instead of context
#define ESCH_CLSN_ARENA             0x10    // Use arena instead of systems
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

#define ESCH_DRW_OWNSDATA           0x2     // Buffers associated should be
                                            // deleted on destruction.
#define ESCH_DRW_SKIPTEST           0x4     // Skip this drawable during
                                            // collide/pick tests only
#define ESCH_DRW_SKIPANIMATE        0x8     // Skip this drawable during
                                            // animate calls.
#define ESCH_DRW_SKIPTRAVERSE       0x10    // Skip this drawable during
                                            // partition traverse calls.

#define ESCH_DRW_VISIBLE            0x100   // Set if a drawable is not rejected
                                            // by clipping.

#define ESCH_DRW_PARTNSTATIC        0x200   // Partition should skip on updates
                                            // since the position won't change

#define ESCH_DRW_APP0               0x1000000   // Application defined bits
#define ESCH_DRW_APP1               0x2000000
#define ESCH_DRW_APP2               0x4000000
#define ESCH_DRW_APP3               0x8000000
#define ESCH_DRW_APP4               0x10000000
#define ESCH_DRW_APP5               0x20000000
#define ESCH_DRW_APP6               0x40000000
#define ESCH_DRW_APP7               0x80000000

//ÄÄÄ Types
#define ESCH_DRWT_BASE              0x0000
#define ESCH_DRWT_POINTDRAW         0x0100
#define ESCH_DRWT_PARTICLE          0x0200
#define ESCH_DRWT_PRTPYRAMID        0x0210
#define ESCH_DRWT_PRTGEOMETRY       0x0220
#define ESCH_DRWT_PRTSPRITE         0x0230
#define ESCH_DRWT_PRTLINE           0x0240
#define ESCH_DRWT_PSYSTEM           0x0300
#define ESCH_DRWT_PGENERATOR        0x0310
#define ESCH_DRWT_GEOM              0x0400
#define ESCH_DRWT_MESH              0x0410
#define ESCH_DRWT_SKELETON          0x0411
#define ESCH_DRWT_TERRAIN           0x0500
#define ESCH_DRWT_SPRITE            0x0600
#define ESCH_DRWT_PARTITION         0x0700
#define ESCH_DRWT_PRTN_GRID         0x0710
#define ESCH_DRWT_PRTN_QUAD         0x0720
#define ESCH_DRWT_PRTN_OCT          0x0730
#define ESCH_DRWT_LINEDRAW          0x0800
#define ESCH_DRWT_STARFIELD         0x1000
#define ESCH_DRWT_EXPLOSION         0x1100
#define ESCH_DRWT_METABOX           0x1200
#define ESCH_DRWT_LOD               0x1300

//ÄÄÄ EschParticle

#define ESCH_PRT_TIMEBASED          0x10000 // Lifetime based on interval

//ÄÄÄ EschParticleGenerator

#define ESCH_PRTG_CIRCLE            0x10000 // Generation area is a circle
#define ESCH_PRTG_RECTANGLE         0x20000 // Generation area is a rectangle
#define ESCH_PRTG_NOAUTOGENERATE    0x100000 // Don't generate on animate()
#define ESCH_PRTG_FRAMEBASED        0x200000 // Values for parts & lifetime
                                             // given in frames

//ÄÄÄ EschMeshDraw

#define ESCH_MSHD_OWNSTEXTURE       0x10000 // Own's instance textures, so
                                            // delete on detach.
#define ESCH_MSHD_NOEXTENTSCHK      0x20000 // Don't perform extent's check

#define ESCH_MSHD_OWNSNOSTCTXT      0x100000 // If OWNSTEXTURE is set,
                                             // don't delete any Static textures
#define ESCH_MSHD_OWNSNOMFTXT       0x200000 // If OWNSTEXTURE is set,
                                             // don't delete any MultiFrame textures
#define ESCH_MSHD_OWNSNOPRCTXT      0x400000 // If OWNSTEXTURE is set,
                                             // don't delete any Procedural textures

//ÄÄÄ EschTerrain

#define ESCH_TRN_DOTS               0x10000 // Draws height field as dots
#define ESCH_TRN_LOD                0x20000 // Draw w/ Level Of Detail adjustments
#define ESCH_TRN_DEBUG              0x40000 // Draw the debug info.

//ÄÄÄ EschSprite

#define ESCH_SPRITE_INFINITE        0x10000 // Sprite should be treated
                                            // as if it is at an infinite
                                            // distance.

//ÄÄÄ EschPartition

#define ESCH_PARTN_OWNSDRAWS        0x10000 // Own's drawables within
                                            // partition, so delete on release.
#define ESCH_PARTN_OFF              0x20000 // Causes draw(), pick(), and
                                            // collide(), and traverse()
                                            // to test draws in 'dumb' order

//ÄÄÄ EschStarfield

#define ESCH_SFLD_FTL               0x10000 // Causes stars to move with
                                            // translation.

//ÄÄÄ EschPlosion

#define ESCH_PLSN_CIRCULAR          0x10000 // Causes the explosion to be
                                            // circular instead of upwards.
#define ESCH_PLSN_TRIANGULAR        0x20000 // Causes the explosion to be
                                            // pointed at the bottom.

//ÄÄÄ EschMetabox
#define ESCH_MBOX_TOP               0x10000
#define ESCH_MBOX_BOTTOM            0x20000
#define ESCH_MBOX_FRONT             0x40000
#define ESCH_MBOX_BACK              0x80000
#define ESCH_MBOX_LEFT              0x100000
#define ESCH_MBOX_RIGHT             0x200000

#define ESCH_MBOX_FACE_TOP          0
#define ESCH_MBOX_FACE_BOTTOM       1
#define ESCH_MBOX_FACE_FRONT        2
#define ESCH_MBOX_FACE_BACK         3
#define ESCH_MBOX_FACE_LEFT         4
#define ESCH_MBOX_FACE_RIGHT        5

//ÄÄÄ EschLevelOfDetail

#define ESCH_LOD_AUTOSWITCH         0x10000

#define ESCH_LOD_MAX_LEVELS         4


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

#define ESCH_VVERT_SHADE_CONVERT    0x10000 // Vertex has shading converted

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

#define ESCH_FACE_ALPHA             0x800   // Face has Alpha value

#define ESCH_FACE_ABLINE            0x1000  // Visiblity for wireframe mode
#define ESCH_FACE_BCLINE            0x2000
#define ESCH_FACE_CALINE            0x4000

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

//ÄÄÄ Load flags
#define ESCH_MSHLD_USEMFTXT         0x1
#define ESCH_MSHLD_SHARETXT         0x2
#define ESCH_MSHLD_FILETXT          0x4

#define ESCH_MSHLD_ALL              0xf


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
#define ESCH_SCENELD_NOMFTXT        0x20
#define ESCH_SCENELD_NOSHARETXT     0x40
#define ESCH_SCENELD_NOFILETXT      0x80

#define ESCH_SCENELD_SKELETON       0x100


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

//ÄÄÄ Load flags
#define ESCH_TRNLD_USEMFTXT         0x1
#define ESCH_TRNLD_SHARETXT         0x2
#define ESCH_TRNLD_FILETXT          0x4

#define ESCH_TRNLD_ALL              0xf


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTraverse                                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_TRAV_DIRECTION         0x1         // Use direction vector
#define ESCH_TRAV_DIST              0x2         // Use distance value
#define ESCH_TRAV_ARENA             0x4         // Use arena instead of systems

#define ESCH_TRAV_APP0              0x1000000   // Application defined bits
#define ESCH_TRAV_APP1              0x2000000
#define ESCH_TRAV_APP2              0x4000000
#define ESCH_TRAV_APP3              0x8000000
#define ESCH_TRAV_APP4              0x10000000
#define ESCH_TRAV_APP5              0x20000000
#define ESCH_TRAV_APP6              0x40000000
#define ESCH_TRAV_APP7              0x80000000


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschBuildTexture                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_TBLD_8BIT              0x1
#define ESCH_TBLD_TC                0x2
#define ESCH_TBLD_COMPRESS          0x4

#define ESCH_TBLD_TRANSP            0x10


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschBuildMesh                                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_MBLD_MATRIX            0x1
#define ESCH_MBLD_EXTENTS           0x2
#define ESCH_MBLD_HEIR              0x4
#define ESCH_MBLD_MTLS              0x8
#define ESCH_MBLD_ALL               0xf

#define ESCH_MBLD_INSCENE           0x10
#define ESCH_MBLD_FIXED             0x20
#define ESCH_MBLD_OLDFLOAT          0x40


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschLimbSegment                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
#define ESCH_FOOT_MAX_PITCH         45
#define ESCH_FOOT_MIN_PITCH         -60
#define ESCH_FOOT_MAX_ROLL          30
#define ESCH_FOOT_MIN_ROLL          -30
#define ESCH_FOOT_MAX_YAW           90
#define ESCH_FOOT_MIN_YAW           -10
#define ESCH_HAND_MAX_PITCH         90
#define ESCH_HAND_MIN_PITCH         -90
#define ESCH_HAND_MAX_ROLL          0
#define ESCH_HAND_MIN_ROLL          0
#define ESCH_HAND_MAX_YAW           0
#define ESCH_HAND_MIN_YAW           0
#define ESCH_SHIN_MAX_PITCH         5
#define ESCH_SHIN_MIN_PITCH         -100
#define ESCH_SHIN_MAX_ROLL          45
#define ESCH_SHIN_MIN_ROLL          -45
#define ESCH_SHIN_MAX_YAW           0
#define ESCH_SHIN_MIN_YAW           0
#define ESCH_FOREARM_MAX_PITCH      135
#define ESCH_FOREARM_MIN_PITCH      -5
#define ESCH_FOREARM_MAX_ROLL       45
#define ESCH_FOREARM_MIN_ROLL       -45
#define ESCH_FOREARM_MAX_YAW        0
#define ESCH_FOREARM_MIN_YAW        0
#define ESCH_THIGH_MAX_PITCH        135
#define ESCH_THIGH_MIN_PITCH        -30

#define ESCH_THIGH_MAX_ROLL         45
#define ESCH_THIGH_MIN_ROLL         -45

#define ESCH_THIGH_MAX_YAW          45
#define ESCH_THIGH_MIN_YAW          -5
#define ESCH_UPARM_MAX_PITCH        160
#define ESCH_UPARM_MIN_PITCH        -5
#define ESCH_UPARM_MAX_ROLL         90
#define ESCH_UPARM_MIN_ROLL         -90
#define ESCH_UPARM_MAX_YAW          90
#define ESCH_UPARM_MIN_YAW          -90
#define ESCH_TORSO_MAX_PITCH        45
#define ESCH_TORSO_MIN_PITCH        -30
#define ESCH_TORSO_MAX_ROLL         0
#define ESCH_TORSO_MIN_ROLL         0
#define ESCH_TORSO_MAX_YAW          80
#define ESCH_TORSO_MIN_YAW          -80
#define ESCH_HEAD_MAX_PITCH         30
#define ESCH_HEAD_MIN_PITCH         -30
#define ESCH_HEAD_MAX_ROLL          10
#define ESCH_HEAD_MIN_ROLL          -10
#define ESCH_HEAD_MAX_YAW           95
#define ESCH_HEAD_MIN_YAW           -95
#define ESCH_SHLDR_MAX_PITCH        15
#define ESCH_SHLDR_MIN_PITCH        -15
#define ESCH_SHLDR_MAX_ROLL         15
#define ESCH_SHLDR_MIN_ROLL         -5
#define ESCH_SHLDR_MAX_YAW          0
#define ESCH_SHLDR_MIN_YAW          0
#define ESCH_DOME_MAX_PITCH         0
#define ESCH_DOME_MIN_PITCH         0
#define ESCH_DOME_MAX_ROLL          0
#define ESCH_DOME_MIN_ROLL          0
#define ESCH_DOME_MAX_YAW           0
#define ESCH_DOME_MIN_YAW           0
#define ESCH_HIP_MAX_PITCH          45
#define ESCH_HIP_MIN_PITCH          -30
#define ESCH_HIP_MAX_ROLL           0
#define ESCH_HIP_MIN_ROLL           0
#define ESCH_HIP_MAX_YAW            0
#define ESCH_HIP_MIN_YAW            0

typedef long esch_limb_type;
#define M_TYPE_LEN      80

#define ESCH_TOKEN_VERSION                  0x001

// Flags
#define ESCH_KEYFRAME_LOOPING               0x01
#define ESCH_KEYFRAME_PING_PONG             0x02
#define ESCH_KEYFRAME_CHAINING              0x04
#define ESCH_KEYFRAME_SWAPPING_1            0x08
#define ESCH_KEYFRAME_SWAPPING_2            0x10
#define ESCH_KEYFRAME_FIRST_CHAIN           0x20
#define ESCH_KEYFRAME_LAST_CHAIN            0x40

#define ESCH_KEYFRAME_DATAERROR             -1
#define ESCH_KEYFRAME_FRAMENUMSYNCERR       -2
#define ESCH_KEYFRAME_LOOPEND               -3

// Base types
#define ESCH_KEYFRAME_NONE                  0x00000000
#define ESCH_KEYFRAME_FOOT                  0x00000001
#define ESCH_KEYFRAME_SHIN                  0x00000002
#define ESCH_KEYFRAME_THIGH                 0x00000004
#define ESCH_KEYFRAME_UPARM                 0x00000008
#define ESCH_KEYFRAME_FOREARM               0x00000010
#define ESCH_KEYFRAME_HAND                  0x00000020
#define ESCH_KEYFRAME_TORSO                 0x00000040
#define ESCH_KEYFRAME_HEAD                  0x00000080
#define ESCH_KEYFRAME_WAIST                 0x00000100
#define ESCH_KEYFRAME_HIP                   0x00000200
#define ESCH_KEYFRAME_DOME                  0x00000400
#define ESCH_KEYFRAME_SHLDR                 0x00000800

// Duplicates one of the above -- base object for a hierarchy
#define ESCH_KEYFRAME_ROOT                  0x00000100

// Modifiers
#define ESCH_KEYFRAME_LEADING               0x00001000
#define ESCH_KEYFRAME_TRAILING              0x00002000
#define ESCH_KEYFRAME_LEFT                  0x00004000
#define ESCH_KEYFRAME_RIGHT                 0x00008000
#define ESCH_KEYFRAME_ARM                   0x00010000
#define ESCH_KEYFRAME_LEG                   0x00020000
#define ESCH_KEYFRAME_MISC                  0x00040000
#define ESCH_KEYFRAME_LEADING_2             0x00080000
#define ESCH_KEYFRAME_TRAILING_2            0x00100000

#define ESCH_KEYFRAME_WEAP1                 0x00200000
#define ESCH_KEYFRAME_WEAP1F                0x00400000
#define ESCH_KEYFRAME_WEAP2                 0x00800000
#define ESCH_KEYFRAME_WEAP2F                0x01000000
#define ESCH_KEYFRAME_WEAP3                 0x02000000
#define ESCH_KEYFRAME_WEAP3F                0x04000000

// Combined Leading Leg
#define ESCH_KEYFRAME_FOOTLL                0x00021001
#define ESCH_KEYFRAME_SHINLL                0x00021002
#define ESCH_KEYFRAME_THIGHLL               0x00021004
#define ESCH_KEYFRAME_HIPLL                 0x00021200

// Combined Leading Arm
#define ESCH_KEYFRAME_UPARMLA               0x00011008
#define ESCH_KEYFRAME_FOREARMLA             0x00011010
#define ESCH_KEYFRAME_HANDLA                0x00011020
#define ESCH_KEYFRAME_SHLDRLA               0x00011800

// Combined Trailing Leg
#define ESCH_KEYFRAME_FOOTTL                0x00022001
#define ESCH_KEYFRAME_SHINTL                0x00022002
#define ESCH_KEYFRAME_THIGHTL               0x00022004
#define ESCH_KEYFRAME_HIPTL                 0x00022200

// Combined Trailing Arm
#define ESCH_KEYFRAME_UPARMTA               0x00012008
#define ESCH_KEYFRAME_FOREARMTA             0x00012010
#define ESCH_KEYFRAME_HANDTA                0x00012020
#define ESCH_KEYFRAME_SHLDRTA               0x00012800

// Combined Miscellaneous
#define ESCH_KEYFRAME_TORSOM                0x00040040
#define ESCH_KEYFRAME_HEADM                 0x00040080
#define ESCH_KEYFRAME_WAISTM                0x00040100
#define ESCH_KEYFRAME_DOMEM                 0x00040400

#define ESCH_KEYFRAME_ALL                   0xFFFFFFFF


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschKeyframer Motion types                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define     ESCH_MAX_MOTION_TYPES           31
#define     ESCH_MAX_SIMULTANEOUS           6


#define     ESCH_MOTION_NONE                0x0
#define     ESCH_MOTION_LEADING             0x1
#define     ESCH_MOTION_TRAILING            0x2
#define     ESCH_MOTION_LOOPING             0x4
#define     ESCH_MOTION_PING_PONG           0x8
#define     ESCH_MOTION_SWAPPING            0x10


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Misc. constants                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

#define ESCH_MAX_NAME               16      // maximum name length
#define ESCH_MAX_ORTHOCOUNT         4096

#endif

//°±² End of header - esdefs.h ²±°

