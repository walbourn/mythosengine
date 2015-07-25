//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. | 
//                                                           |. _  .   .|
// Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.   | / \   .  | 
//              All rights reserved.                         |_|_|_._._.|
//                                                           |.-.-.-.-..|
//                                                          %\__________/%
//                                                           %          %
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
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
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
// vngdefs.h
//
//อออออออออออออออออออออออออออออ Revision History ออออออออออออออออออออออออออออ
//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
#ifndef __VNGDEFS_H
#define __VNGDEFS_H    1


#ifdef __cplusplus
extern "C" {
#endif

//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//
//                                Includes
//                                
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//
//                                Equates
//
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

                                
// Flags for the ViewPort.
#define VNGO_PHYSICAL_DEV       0x1
#define VNGO_PAL_MAPPED_DEV     0x2
#define VNGO_ZBUFFER_DEV        0x4
#define VNGO_ZBUFFER_ACTIVE     0x8
#define VNGO_INIT_NO_RESET      0x10
#define VNGO_NOCLEAR_VBUFFER    0x20
#define VNGO_BACKBUFFER         0x40
#define VNGO_MYMEM_ZBUFF        0x80
#define VNGO_MYMEM_VBUFF        0x100

// Flags for the Palette.
#define VNGO_PAL_HWINIT         0x1
#define VNGO_PAL_CALC           0x2

#define VNGO_MYMEM_SHADE        0x10
#define VNGO_MYMEM_HAZE         0x20

#define VNGO_PAL_SIZE           256
#define VNGO_SHADE_TABLE_SIZE   32
#define VNGO_8BIT               0x1

// Image transfer flags.
#define VNGO_TRANSPARENT        0xFF000000
#define VNGO_TRANSPARENT_COLOR  0xFF

// Mode X defines.
#define VNGO_M1_X_PAGING        0x1
#define VNGO_M2_X_PAGING        0x2
#define VNGO_M3_X_PAGING        0x4
#define VNGO_M4_X_PAGING        0x8

#define VNGO_X_320x200          1
#define VNGO_X_320x240          2
#define VNGO_X_320x400          3
#define VNGO_X_320x480          4
#define VNGO_X_360x480          5
#define VNGO_X_640x400          6

#define VNGO_VESA_640x400x8     0x100
#define VNGO_VESA_640x480x8     0x101
#define VNGO_VESA_800x600x4     0x102
#define VNGO_VESA_800x600x8     0x103
#define VNGO_VESA_1024x768x4    0x104
#define VNGO_VESA_1024x768x8    0x105
#define VNGO_VESA_1280x1024x4   0x106
#define VNGO_VESA_1280x1024x8   0x107

#define VNGO_VESA_320x200x15    0x10d
#define VNGO_VESA_320x200x16    0x10e
#define VNGO_VESA_320x200x24    0x10f
#define VNGO_VESA_640x480x15    0x110
#define VNGO_VESA_640x480x16    0x111
#define VNGO_VESA_640x480x24    0x112
#define VNGO_VESA_800x600x15    0x113
#define VNGO_VESA_800x600x16    0x114
#define VNGO_VESA_800x600x24    0x115
#define VNGO_VESA_1024x768x15   0x116
#define VNGO_VESA_1024x768x16   0x117
#define VNGO_VESA_1024x768x24   0x118
#define VNGO_VESA_1280x1024x15  0x119
#define VNGO_VESA_1280x1024x16  0x11a
#define VNGO_VESA_1280x1024x24  0x11b


//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//
//                                 Types
//
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

enum _vngo_error_codes
{
   VNGO_NO_ERROR                = 0,
   VNGO_MODE_NOT_SUPPORTED      = 1,
   VNGO_MEMALLOC_ERROR          = 2,
   VNGO_RMEMALLOC_ERROR         = 3,
   VNGO_BIOS_INIT_FAILURE       = 4,
   VNGO_UNKNOWN_MODE_NUMBER     = 5,
   VNGO_VESA_NOT_SUPPORTED      = 6,
   VNGO_VESA_CALL_FAILED        = 7
};

typedef enum _vngo_error_codes vngo_error_codes;

//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//
//                                Macros
//
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//
//                               Structures
//
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ


#ifdef __cplusplus
}
#endif          // __cplusplus
#endif          // __VNGDEFS_INC

//ฐฑฒ End of module - vngdefs.inc ฒฑฐ
