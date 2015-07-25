//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. | 
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  | 
//                                                           |_|_|_._._.|
// Copyright (c) 1994-1996 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
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
#include "vngvp.hpp"
#include "vngvvp8.hpp"
#include "vngvpdd8.hpp"
#include "vngvpdb8.hpp"
#include "vngvvp16.hpp"


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern dword *vngo_get_invert();
extern void triangle_setup(VngoPoint2 *pts, VngoTriangle *tri);
extern void vngo_circle(VngoVport *vp,long xoffset, long yoffset,long r,dword color);
extern void vngo_circle(VngoVport *vp,long xoffset, long yoffset,long r,dword color, int width);
extern void vngo_clip_circle(VngoVport *vp,long xoffset, long yoffset,long r,dword color);
extern void vngo_clip_circle(VngoVport *vp,long xoffset, long yoffset,long r,dword color, int width);
extern void vngo_smooth_rect(VngoVport *vp, VngoPoint *pts, VngoRect *clip = NULL);
extern void vngo_line(VngoVport *vp, VngoPoint *p1, VngoPoint *p2, VngoColor24bit *rgv_val=NULL);
extern void vngo_gline(VngoVport *vp, VngoPoint *p1, VngoPoint *p2, VngoColor24bit *rgv_val=NULL);

extern void vngo_poly8 (VngoVport *vp, int count, VngoPoint2 *pts);
extern void vngo_gpoly8 (VngoVport *vp, int count, VngoPoint2 *pts);
extern void vngo_tpoly8 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTextureInfo *tex);
extern void vngo_tgpoly8 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTextureInfo *tex);
extern void vngo_tpoly_persp8 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTextureInfo *tex);
extern void vngo_tgpoly_persp8 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTextureInfo *tex);

extern void vngo_poly16 (VngoVport *vp, int count, VngoPoint2 *pts);
extern void vngo_gpoly16 (VngoVport *vp, int count, VngoPoint2 *pts);
extern void vngo_tpoly16 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTextureInfo *ttex);
extern void vngo_tgpoly16 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTextureInfo *ttex);
extern void vngo_tpoly_persp16 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTextureInfo *ttex);
extern void vngo_tgpoly_persp16 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTextureInfo *ttex);

extern void vngo_ttriangle8 (VngoVport *vp,VngoPoint2 *pts, VngoTextureInfo *ttex);
extern void vngo_zttriangle8 (VngoVport *vp,VngoPoint2 *pts, VngoTextureInfo *ttex);
extern void vngo_ztgtriangle8 (VngoVport *vp,VngoPoint2 *pts, VngoTextureInfo *ttex);
extern void vngo_tgtriangle8 (VngoVport *vp,VngoPoint2 *pts, VngoTextureInfo *ttex);


// Function declarations.
extern "C" {
extern long vngo_calc_xstep(int x1,int x2,int dy);                              
extern long vngo_calc_zstep(int z1,int z2,int dy);                              
extern long vngo_calc_sstep(int s1,int s2,int dy);                              
extern long vngo_calc_uvstep(int uv1,int uv2,int dy);                              
extern long vngo_calc_wstep(int w1,int w2,int dy);                              
extern long vngo_calc_quadratic(long w1,long w2,long t1,long t2,long step, 
                                long *step1,long *step2);
extern void vngo_midpt(VngoPoint2 *p1, VngoPoint2 *p2, VngoPoint2 *outpt);
extern void vngo_line8(VngoVbuffer *vbuf,VngoPoint *p1,VngoPoint *p2);
extern void vngo_zline8(VngoVbuffer *vbuf,VngoPoint *p1,VngoPoint *p2);
extern void vngo_pixel8(VngoVbuffer *vbuf,VngoPoint *pt);
extern void vngo_zpixel8(VngoVbuffer *vbuf,VngoPoint *pt);
extern void vngo_rect8(VngoVbuffer *vbuf,VngoRect *rect, dword color);
extern void vngo_itrans8 (VngoVbuffer *vbuf,VngoRect *dest_rect, VngoTexture *img,dword flags);
extern void vngo_itrans_s8 (VngoVbuffer *vbuf,VngoRect *dest_rect, VngoTexture *img,dword shade, dword flags);
extern void vngo_iline_s8(char *lptr,char *tptr,long xcount,void *shade_pal, dword flags);
extern void vngo_iline_z8(char *lptr,void *zptr,char *tptr,long xcount,dword depth, dword flags);
extern void vngo_iline8(char *lptr,char *tptr,long xcount,dword flags);
extern void vngo_ilinemono8(byte *lptr,byte *tptr,long xcount,dword tskip,dword fgcol,dword bgcol);

extern void vngo_line16(VngoVbuffer *vbuf,VngoPoint *p1,VngoPoint *p2);
extern void vngo_zline16(VngoVbuffer *vbuf,VngoPoint *p1,VngoPoint *p2);
extern void vngo_pixel16(VngoVbuffer *vbuf,VngoPoint *pt);
extern void vngo_zpixel16(VngoVbuffer *vbuf,VngoPoint *pt);
extern void vngo_rect16(VngoVbuffer *vbuf,VngoRect *rect, dword color);
extern void vngo_itrans16 (VngoVbuffer *vbuf,VngoRect *dest_rect, VngoTexture *img,dword flags);
extern void vngo_itrans_s16 (VngoVbuffer *vbuf,VngoRect *dest_rect, VngoTexture *img,dword shade, dword flags);
extern void vngo_iline_s16(char *lptr,char *tptr,long xcount,void *shade_pal, dword flags);
extern void vngo_iline16(char *lptr,char *tptr,long xcount,dword flags);
extern void vngo_ilinemono16(byte *lptr,byte *tptr,long xcount,dword tskip,dword fgcol,dword bgcol);

extern void vngo_zlinemono16(word *lptr,byte *tptr,long xcount,dword tskip,dword fdist,dword ndist);
extern void zbuff_reset_rect16(VngoVbuffer *vbuf,VngoRect *rect, dword depth);

extern void vng_clip_x_line(long p,VngoPoint *s, VngoPoint *f, VngoPoint *out_put);
extern void vng_clip_y_line(long p,VngoPoint *s, VngoPoint *f, VngoPoint *out_put);


}

#endif          // __VANGGOGH_HPP

//°±² End of module - vangogh.hpp ²±°

