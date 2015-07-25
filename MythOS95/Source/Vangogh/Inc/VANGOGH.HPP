//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. | 
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  | 
//                                                           |_|_|_._._.|
// Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.   |.-.-.-.-..|
//              All rights reserved.                        %\__________/%
//                                                           %          %
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
// VanGogh.hpp  
//
//     The Generic include file for users to include to use the
//     Van Gogh 2D draw library.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __VANGOGH_HPP
#define __VANGOGH_HPP  1


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//             
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "portable.h"
#include "vngdefs.h"
#include "vngstrct.hpp"
#include "vnginlin.ipp"
#include "vngvp.hpp"
#include "vngvvp8.hpp"
// #include "vngpvp8.hpp"
#include "vngvpdd8.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern void triangle_setup(VngoPoint *pts, VngoTriangle *tri);
extern void vngo_circle(VngoVport *vp,long xoffset, long yoffset,long r,dword color);
extern VngoColor24bit vngo_get_pal(int index);

extern void vngo_poly (VngoVport *vp, int count, VngoPoint *pts);
extern void vngo_gpoly (VngoVport *vp, int count, VngoPoint *pts);
extern void vngo_tpoly (VngoVport *vp, int count, VngoPoint *pts, VngoTexture *tex);
extern void vngo_tgpoly (VngoVport *vp, int count, VngoPoint *pts, VngoTexture *tex);
extern void vngo_tpoly_persp (VngoVport *vp, int count, VngoPoint *pts, VngoTexture *tex);
extern void vngo_tgpoly_persp (VngoVport *vp, int count, VngoPoint *pts, VngoTexture *tex);

extern void vngo_poly8 (VngoVport *vp, int count, VngoPoint *pts);
extern void vngo_gpoly8 (VngoVport *vp, int count, VngoPoint *pts);
extern void vngo_tpoly8 (VngoVport *vp, int count, VngoPoint *pts, VngoTexture *tex);
extern void vngo_tgpoly8 (VngoVport *vp, int count, VngoPoint *pts, VngoTexture *tex);
extern void vngo_tpoly_persp8 (VngoVport *vp, int count, VngoPoint *pts, VngoTexture *tex);
extern void vngo_tgpoly_persp8 (VngoVport *vp, int count, VngoPoint *pts, VngoTexture *tex);


// Function declarations.
extern "C" {
extern void vngo_fill_pal_LUT(byte *pal15,byte *my_pal8);
extern void vngo_fill_y_table(VngoVbuffer *vbuf,int pix_size);
extern void vngo_fill_invert_table(dword *invert);

extern long vngo_calc_xstep(int x1,int x2,int dy);                              
extern long vngo_calc_zstep(int z1,int z2,int dy);                              
extern long vngo_calc_sstep(int s1,int s2,int dy);                              
extern long vngo_calc_uvstep(int uv1,int uv2,int dy);                              
extern long vngo_calc_wstep(int w1,int w2,int dy);                              
extern long vngo_calc_quadratic(long w1,long w2,long t1,long t2,long step, 
                                long *step1,long *step2);

extern void vngo_Xrect8(VngoVbuffer *vbuf,VngoRect *rect, dword color);
extern void vngo_Xitrans8 (VngoVbuffer *vbuf,VngoRect *dest_rect, VngoTexture *img,dword flags);
extern void vngo_line8(VngoVbuffer *vbuf,VngoPoint *p1,VngoPoint *p2);
extern void vngo_zline8(VngoVbuffer *vbuf,VngoPoint *p1,VngoPoint *p2);
extern void vngo_pixel8(VngoVbuffer *vbuf,VngoPoint *pt);
extern void vngo_zpixel8(VngoVbuffer *vbuf,VngoPoint *pt);
extern void vngo_rect8(VngoVbuffer *vbuf,VngoRect *rect, dword color);
extern void vngo_itrans8 (VngoVbuffer *vbuf,VngoRect *dest_rect, VngoTexture *img,dword flags);
extern void vngo_iline8(char *lptr,char *tptr,long xcount,dword flags);
extern void vngo_ilinemono8(byte *lptr,byte *tptr,long xcount,dword tskip,dword fgcol,dword bgcol);
extern void vngo_tpoly8 (VngoVbuffer *vbuf,int count,VngoPoint pts[],VngoTexture *tex);
extern void vngo_tzpoly8 (VngoVbuffer *vbuf,int count,VngoPoint pts[],VngoTexture *tex);
extern void vngo_tgzpoly8 (VngoVbuffer *vbuf,int count,VngoPoint pts[],VngoTexture *tex);
extern void vngo_ptzpoly8 (VngoVbuffer *vbuf,int count,VngoPoint pts[],VngoTexture *tex);
extern void vngo_ptgzpoly8 (VngoVbuffer *vbuf,int count,VngoPoint pts[],VngoTexture *tex);
extern void zbuff_reset_rect16(VngoVbuffer *vbuf,VngoRect *rect, dword depth);

extern void vngo_gzhline8(void);
extern void vngo_tgzhline8(void);
extern void vngo_tzhline8(void);
}

#endif          // __VANGGOGH_HPP

//°±² End of module - vangogh.hpp ²±°

