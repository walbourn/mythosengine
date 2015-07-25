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
// vngvvp8.hpp  
//
//     This is the Virtual 8bpp viewport Class header file for the
//     Van Gogh 2D draw library.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __VNGVVP16_HPP
#define __VNGVVP16_HPP  1


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//             
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "portable.h"
#include "vngdefs.h"
#include "vngvp.hpp"
#include "vngstrct.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


class VngoVVport16 : public VngoVport
{
public:
    VngoVVport16() {};
    VngoVVport16(long,long,long,long,VngoPal *,dword);
    virtual ~VngoVVport16();

    virtual VNGError init (long,long,long,long,VngoPal *,dword);

    // All of these functions will be virtuals eventualy.
    virtual void reset(dword c=0,dword farz=0xffffffff);


    virtual VNGError vpcopy (int destx,int desty,VngoBaseDev *dest);

    virtual VNGError pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL);
    virtual VNGError clip_pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL,VngoRect *clip_rect=NULL);
    virtual dword read_pixel (VngoPoint *pt, VngoPoint *dest);
    virtual dword read_pixel (int x, int y, VngoPoint *dest);

    virtual VNGError frect (VngoRect *rect, dword color);
    virtual VNGError frect (VngoRect *rect, VngoColor24bit *rgb_val);
    virtual VNGError clip_frect (VngoRect *rect, dword color, VngoRect *clip_rect=NULL);
    virtual VNGError clip_frect (VngoRect *rect, VngoColor24bit *rgb_val, VngoRect *clip_rect=NULL);

    virtual VNGError line (VngoPoint *p1, VngoPoint *p2, VngoColor24bit *rgb_val=NULL);
// Not yet implemented.
    virtual VNGError gline (VngoPoint *p1, VngoPoint *p2);
    virtual VNGError gline_persp (VngoPoint *p1, VngoPoint *p2);

    virtual VNGError clip_line (VngoPoint *p1, VngoPoint *p2, VngoColor24bit *rgb_val=NULL,VngoRect *clip_rect=NULL);
// Not yet implemented.
    virtual VNGError clip_gline (VngoPoint *p1, VngoPoint *p2,VngoRect *clip_rect=NULL);
    virtual VNGError clip_gline_persp (VngoPoint *p1, VngoPoint *p2,VngoRect *clip_rect=NULL);

    virtual VNGError poly (int count, VngoPoint pts[]);
    virtual VNGError gpoly (int count, VngoPoint pts[]);
    virtual VNGError gpoly_persp (int count, VngoPoint pts[]);
    virtual VNGError tpoly (int count, VngoPoint pts[],VngoTexture *tex);
    virtual VNGError tpoly_persp (int count, VngoPoint pts[],VngoTexture *tex);
    virtual VNGError gtpoly (int count, VngoPoint pts[],VngoTexture *tex);
    virtual VNGError gtpoly_persp (int count, VngoPoint pts[],VngoTexture *tex);
// Not yet implemented.
    virtual VNGError clip_poly (int count, VngoPoint pts[], VngoRect *clip_rect) { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gpoly (int count, VngoPoint pts[], VngoRect *clip_rect) { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gpoly_persp (int count, VngoPoint pts[], VngoRect *clip_rect) { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_tpoly (int count, VngoPoint pts[],VngoTexture *tex, VngoRect *clip_rect) { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_tpoly_persp (int count, VngoPoint pts[],VngoTexture *tex, VngoRect *clip_rect) { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gtpoly (int count, VngoPoint pts[],VngoTexture *tex, VngoRect *clip_rect) { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gtpoly_persp (int count, VngoPoint pts[],VngoTexture *tex, VngoRect *clip_rect) { return VNGO_NOT_SUPPORTED;};

    virtual VNGError image_trans (VngoRect *dest_rect,VngoTexture *img,dword flags=0);
    virtual VNGError image_trans_s (VngoRect *dest_rect,VngoTexture *img,dword shade, dword flags=0);
    virtual VNGError image_trans_z (VngoRect *dest_rect,VngoTexture *img,dword depth, dword flags=0);
    virtual VNGError image_trans_zs (VngoRect *dest_rect,VngoTexture *img,dword depth,dword shade,dword flags=0);

    virtual VNGError image_trans_mono (VngoRect *dest_rect,VngoTexture *img,dword fgcol,dword bgcol=VNGO_TRANSPARENT);
    virtual VNGError zblit_mono (VngoRect *dest_rect,VngoZMap *zmp,dword fdist,dword ndist=0);


};

#endif          // __VNGVVP8_HPP

//°±² End of module - vngvvp8.hpp ²±°

