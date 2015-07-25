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
// VanGogh.h  
//
//     The Generic include file for users to include to use the
//     Van Gogh 2D draw library.
//
//อออออออออออออออออออออออออออออ Revision History ออออออออออออออออออออออออออออ
//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

#ifndef __VANGOGH_H
#define __VANGOGH_H 1


//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//             
//                                Includes
//                                
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

#include "portable.h"
#include "vngdefs.h"
#include "vngstrct.h"



//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//
//                               Prototypes
//
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ


#ifdef __cplusplus
extern "C" {
#endif

// extern VngoVbuffer *CurScreen;

extern void vngo_fill_pal_LUT(byte *pal15,byte *my_pal8);
extern void vngo_fill_y_table(VngoVbuffer *vbuf,int pix_size);
extern void vngo_fill_invert_table(dword *invert);
extern void vngo_std_mode(long mode);
extern void vngo_set_pal(byte *);
extern void vngo_line8(VngoVbuffer *vbuf,VngoPoint *p1,VngoPoint *p2);
extern void vngo_zline8(VngoVbuffer *vbuf,VngoPoint *p1,VngoPoint *p2);
extern void vngo_pixel8(VngoVbuffer *vbuf,VngoPoint *pt);
extern void vngo_zpixel8(VngoVbuffer *vbuf,VngoPoint *pt);
extern void vngo_rect8(VngoVbuffer *vbuf,VngoRect *rect, dword color);
extern void vngo_itrans8 (VngoVbuffer *vbuf,VngoRect *dest_rect, VngoTexture *img,dword flags);
extern void vngo_poly8 (VngoVbuffer *vbuf,int count,VngoPoint pts[]);
extern void vngo_zpoly8 (VngoVbuffer *vbuf,int count,VngoPoint pts[]);
extern void vngo_tpoly8 (VngoVbuffer *vbuf,int count,VngoPoint pts[],VngoTexture *tex);
extern void vngo_ztpoly8 (VngoVbuffer *vbuf,int count,VngoPoint pts[],VngoTexture *tex);

#ifdef __cplusplus
}
#endif         // __cplusplus
#endif         // __VANGOGH_H

//ฐฑฒ End of header - VanGogh.h ฒฑฐ



