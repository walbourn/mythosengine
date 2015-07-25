//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
// Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.    | / \   .  |
//              All rights reserved.                         |_|_|_._._.|
//                                                           |.-.-.-.-..|
//                                                          %\__________/%
//                                                           %          %
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//           *** Charybdis Enterprises, Inc. Company Confidential ***
//
//  THIS FILE AND ALL ASSOCIATED FILES ARE THE COMPANY PROPRIETARY PROPERTY
//        OF CHARYBDIS ENTERPRISES, INC.  UNAUTHORIZED USE PROHIBITED.
//
// CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
// TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
// IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
// AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
// INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Tim Little
//
// vngdefs.h
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __VNGDEFS_H
#define __VNGDEFS_H    1

#ifdef __cplusplus
extern "C" {
#endif

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define VNGO_MAX_RESOLUTION     2048
#define VNGO_PERSP_OFF          VNGO_MAX_RESOLUTION + 1
#define VNGO_PERSP_PRECISION    VNGO_PERSP_OFF
#define VNGO_MAX_VERTCOUNT      12

#define VNGO_COLOR_24BIT        0x10000000
#define VNGO_COLOR_15BIT        0x20000000
#define VNGO_COLOR_16BIT        0x40000000

// Flags for the Screen manager
#define VNGO_SET_RESOLUTION     0x1
#define VNGO_TRUE_FLIP          0x2
#define VNGO_FORCE_SYSTEMMEMORY 0x4
#define VNGO_ALLOC_ZBUFFER      0x8
#define VNGO_3DDEVICE           0x10
#define VNGO_USE_PRIMARY        0x1000

// Flags for the ViewPort.
#define VNGO_PAL_MAPPED_DEV     0x1
#define VNGO_ZBUFFER_DEV        0x2
#define VNGO_ZBUFFER_ACTIVE     0x4
#define VNGO_INIT_NO_RESET      0x8
#define VNGO_NOCLEAR_VBUFFER    0x10
#define VNGO_MYMEM_ZBUFF        0x20
#define VNGO_MYMEM_VBUFF        0x40
#define VNGO_MYMEM_ZMAP         0x80
#define VNGO_PAL_CALC           0x100
#define VNGO_ZMAP_DEV           0x200
#define VNGO_ZMAP_ACTIVE        0x400
#define VNGO_ACTIVE_HAZE_DEV    0x1000
#define VNGO_PASSIVE_HAZE_DEV   0x2000
#define VNGO_HAZE_ON            0x4000

// Flags for the ViewPort Drawing control.
#define VNGO_DITHER_OFF         0x1000
#define VNGO_DITHER_4X4         0x2000
#define VNGO_TRUE_ALPHA         0x4000
#define VNGO_TEXTURE_FILTER     0x8000

#define VNGO_MYMEM_SHADE        0x10
#define VNGO_MYMEM_HAZE         0x20
#define VNGO_MYDDPAL            0x40

#define VNGO_PAL_SIZE           256
#define VNGO_SHADE_TABLE_SIZE   32
#define VNGO_8BIT               0x1
#define VNGO_15BIT              0x2
#define VNGO_16BIT              0x4
#define VNGO_24BIT              0x8
#define VNGO_32BIT              0x10
#define VNGO_SHADE_RGB          0x20

// Image transfer flags.
#define VNGO_TRANSPARENT        0xFF000000
#define VNGO_TRANSPARENT_COLOR  0xFF
#define VNGO_STRETCH            0x100
#define VNGO_COMPARE            0x200
#define VNGO_COMPARE_EQUAL      0x400
#define VNGO_COPY               0x000

// Flags for the Texture Manager
#define VNGO_TEXTURE_CACHED_OUT     0x0
#define VNGO_TEXTURE_CACHED_IN      0x1

// VangoTexture flags.
#define VNGO_TEXTURE_MONO           0x1
#define VNGO_TEXTURE_1BIT           0x1
#define VNGO_TEXTURE_2BIT           0x2     // Not Currently in use
#define VNGO_TEXTURE_4BIT           0x4     // Not Currently in use
#define VNGO_TEXTURE_8BIT           0x8
#define VNGO_TEXTURE_15BIT          0x10    // Only used for image_trans
#define VNGO_TEXTURE_16BIT          0x20    // Only used for image_trans
#define VNGO_TEXTURE_24BIT          0x40    // Not Currently in use
#define VNGO_TEXTURE_32BIT          0x80    // Not Currently in use
#define VNGO_TEXTURE_SHADOWS        0x100   // Not Currently in use
#define VNGO_TEXTURE_ALPHA          0x200   // Not Currently in use
#define VNGO_TEXTURE_ZMAP           0x400
#define VNGO_TEXTURE_SHADE          0x800   // Not Currently in use
#define VNGO_TEXTURE_COMPRESSED     0x1000
#define VNGO_TEXTURE_TRANSPARENT    0x2000

// VanGogh Clipping flags
#define VNGO_CLIP_Z                 0x1
#define VNGO_CLIP_SHADE             0x2
#define VNGO_CLIP_VERBOSE           0x10000

// VangoTexture3D flags.
#define VNGO_TEXTURE3D_DIRTY        0x1
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                 Types
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

enum _vngo_error_codes
{
   VNGO_NO_ERROR                = 0,
   VNGO_NOT_SUPPORTED           = 1,
   VNGO_MEMALLOC_ERROR          = 2,
   VNGO_WRONG_BITDEPTH          = 3,
   VNGO_FULLY_CLIPPED           = 4,
   VNGO_FULLY_INSIDE            = 5,
   VNGO_UNSUPPORTED_TEXTURE     = 6,
   VNGO_MEMORY_ERROR            = 7,
   VNGO_INTERNAL_ERROR          = 8,
   VNGO_NOSCREEN_ERROR          = 9,
   VNGO_MISSING_HARDWARE        = 10,
   VNGO_MISSING_FUNCTIONALITY   = 11,
   VNGO_NEEDS_PAL8              = 12,
   VNGO_NEEDS_PAL15             = 13,
   VNGO_NEEDS_PAL16             = 14,
}; 

typedef enum _vngo_error_codes VNGError;


enum _vngo_caps_sins
{
   VNGO_NO_SINS                 = 0,
   VNGO_NO_ZBUFFER              = 0x1,
   VNGO_NO_HWBLIT               = 0x2,
   VNGO_NO_BLIT                 = 0x4,

   VNGO_NO_8BIT_PAL_TEXTURES    = 0x10,
   VNGO_NO_CHROMAKEY_TEXTURES   = 0x20,
   VNGO_NO_TEXTURE_MODULATION   = 0x40,
   VNGO_NO_TEXTURE_TILE         = 0x80,
   VNGO_NO_FILTERS              = 0x100,
   VNGO_NO_PERSPECTIVE          = 0x200,
   VNGO_INVALID_TEXTURE_SIZES   = 0x400,

   VNGO_NO_CULLING_CONTROL      = 0x1000,
   VNGO_NO_DITHER               = 0x2000,
   VNGO_NO_SPECULAR             = 0x4000,

   VNGO_NO_TABLE_FOG            = 0x10000,
   VNGO_NO_VERTEX_FOG           = 0x20000,
   VNGO_NO_FOG                  = 0x30000,

   VNGO_NO_STIPPLE_ALPHA        = 0x40000,
   VNGO_NO_TRUE_ALPHA           = 0x80000,
   VNGO_NO_ALPHA                = 0xc0000,

   // Critical errors.  These will fail set_mode.
   VNGO_INVALID_RENDERDEPTH     = 0x10000000,
   VNGO_INVALID_COLORMODEL      = 0x20000000,
   VNGO_INVALID_VERTEX_FORMAT   = 0x30000000,
   VNGO_NOT_3DDEVICE            = 0x40000000,
   VNGO_NO_3D_2D_INTERLEAVE     = 0x80000000,
};

typedef enum _vngo_caps_sins VngoSins;

enum _vngo_texture_type
{
    VNGO_MEM_TEX                = 0,
    VNGO_D3D_TEX                = 1,
    VNGO_CLEAR3D_TEX            = 2,
    VNGO_OPENGL_TEX             = 3,
    VNGO_MSI_TEX                = 4,
    VNGO_GLIDE_TEX              = 5,
};

typedef enum _vngo_texture_type VngoTextureType;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#ifdef __cplusplus
}
#endif          // __cplusplus

#endif          // __VNGDEFS_H

//°±² End of module - vngdefs.h ²±°
