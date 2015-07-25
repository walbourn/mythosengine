//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  |
//                                                           |_|_|_._._.|
// Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
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
// Created by Tim Little
//
// vangogh.hpp
//
// The Generic include file for users to include to use the
// Van Gogh 2D draw library.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __VANGOGH_HPP
#define __VANGOGH_HPP  1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <portable.h>
#include <debug.h>

#include "vngdefs.h"
#include "vngstrct.hpp"
#include "vngvp.hpp"
#include "vngvvp8.hpp"
#include "vngvpdd8.hpp"
#include "vngvpdb8.hpp"
#include "vngvvp16.hpp"
#include "vgvpdb16.hpp"
#include "vgvpdd16.hpp"
#include "vngscrn.hpp"
// #include "vngoems.hpp"
#include "vngd3d.hpp"

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern dword *vngo_get_invert();
extern void triangle_setup(VngoPoint2 *pts, VngoTriangle *tri);
extern void vngo_circle(VngoVport *vp,VngoPoint *center,long r);
extern void vngo_circle(VngoVport *vp,long xoffset, long yoffset,long r,dword color);
extern void vngo_circle(VngoVport *vp,long xoffset, long yoffset,long r,VngoColor24bit *color);
extern void vngo_circle(VngoVport *vp,long xoffset, long yoffset,long r,dword color, int width);
extern void vngo_clip_circle(VngoVport *vp,VngoPoint *center,long r);
extern void vngo_clip_circle(VngoVport *vp,long xoffset, long yoffset,long r,dword color);
extern void vngo_clip_circle(VngoVport *vp,long xoffset, long yoffset,long r,VngoColor24bit *color);
extern void vngo_clip_circle(VngoVport *vp,long xoffset, long yoffset,long r,dword color, int width);
extern void vngo_smooth_rect(VngoVport *vp, VngoPoint *pts, VngoRect *clip = NULL);
extern VNGError vngo_smooth_blit(VngoVport *vp,VngoTexture *img, VngoRect *target,VngoRect *clip = NULL);
extern void vngo_line(VngoVport *vp, VngoPoint *p1, VngoPoint *p2, VngoColor24bit *rgv_val=NULL);
extern void vngo_gline(VngoVport *vp, VngoPoint *p1, VngoPoint *p2, VngoColor24bit *rgv_val=NULL);

extern void vngo_stretch_blt8 (VngoVport *vp, VngoRect *dest_rect, VngoTexture *img,
                               dword flags = VNGO_TRANSPARENT);
extern void vngo_stretch_zblt8 (VngoVport *vp, VngoRect *dest_rect, VngoTexture *img,
                                word *zsource,dword flags = VNGO_TRANSPARENT);

extern void vngo_poly8 (VngoVport *vp, int count, VngoPoint2 *pts);
extern void vngo_gpoly8 (VngoVport *vp, int count, VngoPoint2 *pts);
extern void vngo_tpoly8 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTexture3D *tex);
extern void vngo_tgpoly8 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTexture3D *tex);
extern void vngo_tpoly_persp8 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTexture3D *tex);
extern void vngo_tgpoly_persp8 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTexture3D *tex);
extern void vngo_grpoly8 (VngoVport *vp, int count, VngoPoint2 *pts);

extern void vngo_apoly8 (VngoVport *vp, int count, VngoPoint2 *pts,long alpha);
extern void vngo_agpoly8 (VngoVport *vp, int count, VngoPoint2 *pts,long alpha);
extern void vngo_atpoly8 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTexture3D *tex,long alpha);
extern void vngo_atgpoly8 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTexture3D *tex,long alpha);
extern void vngo_atpoly_persp8 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTexture3D *tex, long alpha);
extern void vngo_atgpoly_persp8 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTexture3D *tex, long alpha);

// extern VngoCTexture *vngo_compres_texture(VngoTexture *tex,dword flags);
// extern void vngo_apoly8 (VngoVport *vp, int count, VngoPoint2 *pts);
// extern void vngo_ttriangle8 (VngoVport *vp,VngoPoint *pts, VngoTexture3D *ttex);
// extern void vngo_zttriangle8 (VngoVport *vp,VngoPoint *pts, VngoTexture3D *ttex);
// extern void vngo_ztgtriangle8 (VngoVport *vp,VngoPoint *pts, VngoTexture3D *ttex);
// extern void vngo_tgtriangle8 (VngoVport *vp,VngoPoint *pts, VngoTexture3D *ttex);
// extern void vngo_apoly16 (VngoVport *vp, int count, VngoPoint2 *pts);

extern void vngo_poly16 (VngoVport *vp, int count, VngoPoint2 *pts);
extern void vngo_gpoly16 (VngoVport *vp, int count, VngoPoint2 *pts);
extern void vngo_tpoly16 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTexture3D *tex);
extern void vngo_tgpoly16 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTexture3D *tex);
extern void vngo_tpoly_persp16 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTexture3D *tex);
extern void vngo_tgpoly_persp16 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTexture3D *tex);
extern void vngo_grpoly16 (VngoVport *vp, int count, VngoPoint2 *pts);

extern void vngo_apoly16 (VngoVport *vp, int count, VngoPoint2 *pts,long alpha);
extern void vngo_agpoly16 (VngoVport *vp, int count, VngoPoint2 *pts,long alpha);
extern void vngo_atpoly16 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTexture3D *tex,long alpha);
extern void vngo_atgpoly16 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTexture3D *tex,long alpha);
extern void vngo_atpoly_persp16 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTexture3D *tex, long alpha);
extern void vngo_atgpoly_persp16 (VngoVport *vp, int count, VngoPoint2 *pts, VngoTexture3D *tex, long alpha);

extern "C"
{

typedef void (*lineproc) (VngoTriangle *tri);

extern void calc_order(int &high_pt,int &mid_pt, int &low_pt, VngoPoint2 *pts);
extern long vngo_calc_xstep(int x1,int x2,int dy);
extern long vngo_calc_zstep(int z1,int z2,int dy);
extern long vngo_calc_sstep(int s1,int s2,int dy);
extern long vngo_calc_uvstep(int uv1,int uv2,int dy);
extern long vngo_calc_wstep(int w1,int w2,int dy);
extern long vngo_calc_quadratic(long w1,long w2,long t1,long t2,long step,
                                long *step1,long *step2);
extern long vngo_calc_quadratic2(long w1,long w2,long t1,long t2,long step,
                                 long *step1,long *step2,long ushift);
extern void vngo_midpt(VngoPoint2 *p1, VngoPoint2 *p2, VngoPoint2 *outpt);
extern void vngo_line8(VngoVbuffer *vbuf,VngoPoint *p1,VngoPoint *p2);

// extern void vngo_zline8(VngoVbuffer *vbuf,VngoPoint *p1,VngoPoint *p2);

extern void vngo_pixel8(VngoVbuffer *vbuf,VngoPoint *pt);
extern void vngo_zpixel8(VngoVbuffer *vbuf,VngoPoint *pt);
extern void vngo_rect8(VngoVbuffer *vbuf,VngoRect *rect, dword color);
extern void vngo_itrans8 (VngoVbuffer *vbuf,VngoRect *dest_rect, VngoTexture *img,dword flags);
extern void vngo_iline8(char *lptr,char *tptr,long xcount,dword flags);
extern void vngo_ilinemono8(byte *lptr,byte *tptr,long xcount,dword tskip,dword fgcol,dword bgcol);

// extern void vngo_line16(VngoVbuffer *vbuf,VngoPoint *p1,VngoPoint *p2);
// extern void vngo_zline16(VngoVbuffer *vbuf,VngoPoint *p1,VngoPoint *p2);

extern void vngo_pixel16(VngoVbuffer *vbuf,VngoPoint *pt);
extern void vngo_zpixel16(VngoVbuffer *vbuf,VngoPoint *pt);
extern void vngo_pixel_rgb16(VngoVbuffer *vbuf,VngoPoint *pt,dword color);
extern void vngo_zpixel_rgb16(VngoVbuffer *vbuf,VngoPoint *pt,dword color);
extern void vngo_rect16(VngoVbuffer *vbuf,VngoRect *rect, dword color);
extern void vngo_iline15(word *lptr,word *tptr,long xcount,dword flags);
extern void vngo_iline16(word *lptr,word *tptr,long xcount,dword flags);
extern void vngo_iline8to16(word *lptr,byte *btptr,long xcount,word *tpal,dword flags);
extern void vngo_ilinemono16(word *lptr,byte *tptr,long xcount,dword tskip,dword fgcol,dword bgcol);

extern void vngo_zlinemono16(word *lptr,byte *tptr,long xcount,dword tskip,dword fdist,dword ndist);
extern void zbuff_reset_rect16(VngoVbuffer *vbuf,VngoRect *rect, dword depth);

extern void vng_clip_x_line(long p,VngoPoint *s, VngoPoint *f, VngoPoint *out_put);
extern void vng_clip_y_line(long p,VngoPoint *s, VngoPoint *f, VngoPoint *out_put);

extern void vngo_poly(VngoVport *vp,int count, dword flags, VngoPointF *pts, VngoTexture *tex, long alpha);

}

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif          // __VANGOGH_HPP

//°±² End of module - vangogh.hpp ²±°

