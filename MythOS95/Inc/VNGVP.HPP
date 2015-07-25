//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
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
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
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
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
// vngvp.hpp  
//
//
//อออออออออออออออออออออออออออออ Revision History ออออออออออออออออออออออออออออ
//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

#ifndef __VNGVP_HPP
#define __VNGVP_HPP  1


//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//             
//                                Includes
//                                
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

#include "portable.h"
#include "vngdefs.h"
#include "vngstrct.hpp"
#include "vngbd.hpp"

//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//
//                               Prototypes
//
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ


class VngoVport : public VngoBaseDev
{
protected:
    VngoZMap    *zmap;

public:
    int         persp_pixcount;

    VngoVport() {zmap = NULL; persp_pixcount = VNGO_PERSP_PRECISION;};
    // Inline functions.
    inline void set_zmap(VngoZMap *_zmap) {zmap = _zmap;}
    inline void set_perspective (int pcount) {persp_pixcount = pcount;}


    // virtual functions for drawing.
    virtual VNGError line (VngoPoint *p1,VngoPoint *p2, VngoColor24bit *rgb_val=NULL) = 0;
//Not yet implemented.
    virtual VNGError gline (VngoPoint *p1,VngoPoint *p2) = 0;
    virtual VNGError gline_persp (VngoPoint *p1,VngoPoint *p2) = 0;

    virtual VNGError clip_line (VngoPoint *p1,VngoPoint *p2, VngoColor24bit *rgb_val=NULL, VngoRect *clip_rect = NULL) = 0;
//Not yet implemented.
    virtual VNGError clip_gline (VngoPoint *p1,VngoPoint *p2, VngoRect *clip_rect = NULL) = 0;
    virtual VNGError clip_gline_persp (VngoPoint *p1,VngoPoint *p2, VngoRect *clip_rect = NULL) = 0;

    virtual VNGError poly (int count,VngoPoint pts[]) = 0;
    virtual VNGError gpoly (int count,VngoPoint pts[]) = 0;
    virtual VNGError gpoly_persp (int count,VngoPoint pts[]) = 0;
    virtual VNGError tpoly (int count,VngoPoint pts[],VngoTexture *tex) = 0;
    virtual VNGError tpoly_persp (int count,VngoPoint pts[],VngoTexture *tex) = 0;
    virtual VNGError gtpoly (int count,VngoPoint pts[],VngoTexture *tex) = 0;
    virtual VNGError gtpoly_persp (int count,VngoPoint pts[],VngoTexture *tex) = 0;

//Not yet implemented.
    virtual VNGError clip_poly (int count,VngoPoint pts[],VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_gpoly (int count,VngoPoint pts[],VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_gpoly_persp (int count,VngoPoint pts[],VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_tpoly (int count,VngoPoint pts[],VngoTexture *tex,VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_tpoly_persp (int count,VngoPoint pts[],VngoTexture *tex,VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_gtpoly (int count,VngoPoint pts[],VngoTexture *tex,VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_gtpoly_persp (int count,VngoPoint pts[],VngoTexture *tex,VngoRect *clip_rect=NULL) = 0;

    virtual VNGError image_trans_mono (VngoRect *dest_rect,VngoTexture *img,dword fgcol,dword bgcol=VNGO_TRANSPARENT)=0;
    virtual VNGError zblit_mono (VngoRect *dest_rect,VngoZMap *zmp,dword fdist,dword ndist=0)=0;

};

#endif          // __VNGVP_HPP

//ฐฑฒ End of module - vngvp.hpp ฒฑฐ

