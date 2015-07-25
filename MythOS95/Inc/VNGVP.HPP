//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  |
//                                                           |_|_|_._._.|
// Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
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
// vngvp.hpp
//
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __VNGVP_HPP
#define __VNGVP_HPP  1


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "portable.h"
#include "vngdefs.h"
#include "vngstrct.hpp"
#include "vngbd.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


class VngoVport : public VngoBaseDev
{
protected:
    VngoZMap    *zmap;

public:
    int         persp_pixcount;

    VngoVport() {zmap = NULL; persp_pixcount = VNGO_PERSP_PRECISION;};
    // Inline functions.
    inline void set_zmap(VngoZMap *_zmap) {zmap = _zmap; vflags |= VNGO_ZMAP_DEV | VNGO_ZMAP_ACTIVE;}
        inline void zmap_on() {if (vflags & VNGO_ZMAP_DEV) vflags |= VNGO_ZMAP_ACTIVE;}
        inline void zmap_off() { vflags &= ~VNGO_ZMAP_ACTIVE;}
        inline VngoZMap * get_zmap() {return zmap;}
    inline void set_perspective (int pcount) {persp_pixcount = pcount;}


    // virtual functions for drawing.
    virtual VNGError line (VngoPoint *p1,VngoPoint *p2,
                           VngoColor24bit *rgb_val=NULL) = 0;
    virtual VNGError line (VngoPoint2 *p1,VngoPoint2 *p2,
                           VngoColor24bit *rgb_val=NULL) = 0;
    virtual VNGError gline (VngoPoint *p1,VngoPoint *p2) = 0;
    virtual VNGError gline (VngoPoint2 *p1,VngoPoint2 *p2) = 0;
    virtual VNGError gline_persp (VngoPoint *p1,VngoPoint *p2) = 0;
    virtual VNGError gline_persp (VngoPoint2 *p1,VngoPoint2 *p2) = 0;

    virtual VNGError clip_line (VngoPoint *p1,VngoPoint *p2,
                                VngoColor24bit *rgb_val=NULL,
                                VngoRect *clip_rect = NULL) = 0;
    virtual VNGError clip_line (VngoPoint2 *p1,VngoPoint2 *p2,
                                VngoColor24bit *rgb_val=NULL,
                                VngoRect *clip_rect = NULL) = 0;
    virtual VNGError clip_gline (VngoPoint *p1,VngoPoint *p2,
                                 VngoRect *clip_rect = NULL) = 0;
    virtual VNGError clip_gline (VngoPoint2 *p1,VngoPoint2 *p2,
                                 VngoRect *clip_rect = NULL) = 0;
    virtual VNGError clip_gline_persp (VngoPoint *p1,VngoPoint *p2,
                                       VngoRect *clip_rect = NULL) = 0;
    virtual VNGError clip_gline_persp (VngoPoint2 *p1,VngoPoint2 *p2,
                                       VngoRect *clip_rect = NULL) = 0;

    virtual VNGError poly (int count,VngoPoint pts[]) = 0;
    virtual VNGError poly (int count,VngoPoint2 pts[]) = 0;
    virtual VNGError gpoly (int count,VngoPoint pts[]) = 0;
    virtual VNGError gpoly (int count,VngoPoint2 pts[]) = 0;
    virtual VNGError gpoly_persp (int count,VngoPoint pts[]) = 0;
    virtual VNGError gpoly_persp (int count,VngoPoint2 pts[]) = 0;
    virtual VNGError tpoly (int count,VngoPoint pts[],
                            VngoTexture *tex) = 0;
    virtual VNGError tpoly (int count,VngoPoint2 pts[],
                            VngoTexture *tex) = 0;
    virtual VNGError tpoly_persp (int count,VngoPoint pts[],
                                  VngoTexture *tex) = 0;
    virtual VNGError tpoly_persp (int count,VngoPoint2 pts[],
                                  VngoTexture *tex) = 0;
    virtual VNGError gtpoly (int count,VngoPoint pts[],
                             VngoTexture *tex) = 0;
    virtual VNGError gtpoly (int count,VngoPoint2 pts[],
                             VngoTexture *tex) = 0;
    virtual VNGError gtpoly_persp (int count,VngoPoint pts[],
                                   VngoTexture *tex) = 0;
    virtual VNGError gtpoly_persp (int count,VngoPoint2 pts[],
                                   VngoTexture *tex) = 0;

    virtual VNGError grpoly (int count,VngoPoint pts[])=0;
    virtual VNGError grpoly (int count,VngoPoint2 pts[])=0;
// Alpha blended versions.
    virtual VNGError poly_a (int count,VngoPoint pts[],
                             long alpha=127) = 0;
    virtual VNGError poly_a (int count,VngoPoint2 pts[],
                             long alpha=127) = 0;
    virtual VNGError gpoly_a (int count,VngoPoint pts[],
                              long alpha=127) = 0;
    virtual VNGError gpoly_a (int count,VngoPoint2 pts[],
                              long alpha=127) = 0;
    virtual VNGError gpoly_persp_a (int count,VngoPoint pts[],
                                    long alpha=127) = 0;
    virtual VNGError gpoly_persp_a (int count,VngoPoint2 pts[],
                                    long alpha=127) = 0;
    virtual VNGError tpoly_a (int count,VngoPoint pts[],VngoTexture *tex,
                              long alpha=127) = 0;
    virtual VNGError tpoly_a (int count,VngoPoint2 pts[],VngoTexture *tex,
                              long alpha=127) = 0;
    virtual VNGError tpoly_persp_a (int count,VngoPoint pts[],VngoTexture *tex,
                                    long alpha=127) = 0;
    virtual VNGError tpoly_persp_a (int count,VngoPoint2 pts[],VngoTexture *tex,
                                    long alpha=127) = 0;
    virtual VNGError gtpoly_a (int count,VngoPoint pts[],VngoTexture *tex,
                               long alpha=127) = 0;
    virtual VNGError gtpoly_a (int count,VngoPoint2 pts[],VngoTexture *tex,
                               long alpha=127) = 0;
    virtual VNGError gtpoly_persp_a (int count,VngoPoint pts[],VngoTexture *tex,
                                     long alpha=127) = 0;
    virtual VNGError gtpoly_persp_a (int count,VngoPoint2 pts[],
                                     VngoTexture *tex,long alpha=127) = 0;

//Not yet implemented.
    virtual VNGError clip_poly (int count,VngoPoint pts[],
                                VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_poly (int count,VngoPoint2 pts[],
                                VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_gpoly (int count,VngoPoint pts[],
                                 VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_gpoly (int count,VngoPoint2 pts[],
                                 VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_gpoly_persp (int count,VngoPoint pts[],
                                       VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_gpoly_persp (int count,VngoPoint2 pts[],
                                       VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_tpoly (int count,VngoPoint pts[],
                                 VngoTexture *tex,
                                 VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_tpoly (int count,VngoPoint2 pts[],
                                 VngoTexture *tex,
                                 VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_tpoly_persp (int count,VngoPoint pts[],
                                       VngoTexture *tex,
                                       VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_tpoly_persp (int count,VngoPoint2 pts[],
                                       VngoTexture *tex,
                                       VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_gtpoly (int count,VngoPoint pts[],VngoTexture *tex,
                                  VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_gtpoly (int count,VngoPoint2 pts[],
                                  VngoTexture *tex,VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_gtpoly_persp (int count,VngoPoint pts[],
                                        VngoTexture *tex,
                                        VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_gtpoly_persp (int count,VngoPoint2 pts[],
                                        VngoTexture *tex,
                                        VngoRect *clip_rect=NULL) = 0;
// Alpha blended versions.
    virtual VNGError clip_poly_a (int count, VngoPoint pts[],
                                  VngoRect *clip_rect,long alpha=127) = 0;
    virtual VNGError clip_poly_a (int count, VngoPoint2 pts[],
                                  VngoRect *clip_rect,long alpha=127) = 0;
    virtual VNGError clip_gpoly_a (int count, VngoPoint pts[],
                                   VngoRect *clip_rect,long alpha=127) = 0;
    virtual VNGError clip_gpoly_a (int count, VngoPoint2 pts[],
                                   VngoRect *clip_rect,long alpha=127) = 0;
    virtual VNGError clip_gpoly_persp_a (int count, VngoPoint pts[],
                                         VngoRect *clip_rect,long alpha=127) = 0;
    virtual VNGError clip_gpoly_persp_a (int count, VngoPoint2 pts[],
                                         VngoRect *clip_rect,long alpha=127) = 0;
    virtual VNGError clip_tpoly_a (int count, VngoPoint pts[],VngoTexture *tex,
                                   VngoRect *clip_rect,long alpha=127) = 0;
    virtual VNGError clip_tpoly_a (int count, VngoPoint2 pts[],VngoTexture *tex,
                                   VngoRect *clip_rect,long alpha=127) = 0;
    virtual VNGError clip_tpoly_persp_a (int count, VngoPoint pts[],
                                         VngoTexture *tex, VngoRect *clip_rect,
                                         long alpha=127) = 0;
    virtual VNGError clip_tpoly_persp_a (int count, VngoPoint2 pts[],
                                         VngoTexture *tex, VngoRect *clip_rect,
                                         long alpha=127) = 0;
    virtual VNGError clip_gtpoly_a (int count, VngoPoint pts[],VngoTexture *tex,
                                    VngoRect *clip_rect,long alpha=127) = 0;
    virtual VNGError clip_gtpoly_a (int count, VngoPoint2 pts[],VngoTexture *tex,
                                    VngoRect *clip_rect,long alpha=127) = 0;
    virtual VNGError clip_gtpoly_persp_a (int count, VngoPoint pts[],
                                          VngoTexture *tex, VngoRect *clip_rect,
                                          long alpha=127) = 0;
    virtual VNGError clip_gtpoly_persp_a (int count, VngoPoint2 pts[],
                                          VngoTexture *tex, VngoRect *clip_rect,
                                          long alpha=127) = 0;

    virtual VNGError image_trans_a (VngoRect *dest_rect,VngoTexture *img,
                                    long alpha=127, dword flags=0) = 0;
    virtual VNGError image_trans_mono_a (VngoRect *dest_rect,VngoTexture *img,
                                         dword fgcol,
                                         dword bgcol=VNGO_TRANSPARENT,
                                         long alpha=127) = 0;

    virtual VNGError haze(VngoShadePal *hazepal,long startZ=0,VngoRect *rect=NULL) = 0;
};

#endif          // __VNGVP_HPP

//°±² End of module - vngvp.hpp ²±°

