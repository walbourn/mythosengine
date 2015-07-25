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
// vngvvp8.hpp
//
//     This is the Virtual 8bpp viewport Class header file for the
//     Van Gogh 2D draw library.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __VNGVVP8_HPP
#define __VNGVVP8_HPP  1


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


class VngoVVport8 : public VngoVport
{
public:
    VngoVVport8() {};
    VngoVVport8(long,long,long,long,VngoPal *,dword);
    virtual ~VngoVVport8();

    virtual VNGError init (long,long,long,long,VngoPal *,dword);

    virtual void reset(dword c=0,dword farz=0xffffffff);


    virtual VNGError vpcopy (int destx,int desty,VngoBaseDev *dest);

    virtual VNGError pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL);
    virtual VNGError pixel (VngoPoint2 *pt, VngoColor24bit *rgb_val = NULL);
    virtual VNGError clip_pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL,
                                 VngoRect *clip_rect=NULL);
    virtual VNGError clip_pixel (VngoPoint2 *pt, VngoColor24bit *rgb_val = NULL,
                                 VngoRect *clip_rect=NULL);
    virtual dword read_pixel (VngoPoint *pt, VngoPoint *dest);
    virtual dword read_pixel (int x, int y, VngoPoint *dest);

    virtual VNGError frect (VngoRect *rect, dword color);
    virtual VNGError frect (VngoRect *rect, VngoColor24bit *rgb_val);
    virtual VNGError clip_frect (VngoRect *rect, dword color,
                                 VngoRect *clip_rect=NULL);
    virtual VNGError clip_frect (VngoRect *rect,
                                 VngoColor24bit *rgb_val,
                                 VngoRect *clip_rect=NULL);

    virtual VNGError line (VngoPoint *p1, VngoPoint *p2,
                           VngoColor24bit *rgb_val=NULL);
    virtual VNGError line (VngoPoint2 *p1, VngoPoint2 *p2,
                           VngoColor24bit *rgb_val=NULL);
    virtual VNGError gline (VngoPoint *p1, VngoPoint *p2);
    virtual VNGError gline (VngoPoint2 *p1, VngoPoint2 *p2);
// Not yet implemented.
    virtual VNGError gline_persp (VngoPoint *p1, VngoPoint *p2);
    virtual VNGError gline_persp (VngoPoint2 *p1, VngoPoint2 *p2);

    virtual VNGError clip_line (VngoPoint *p1, VngoPoint *p2,
                                VngoColor24bit *rgb_val=NULL,
                                VngoRect *clip_rect=NULL);
    virtual VNGError clip_line (VngoPoint2 *p1, VngoPoint2 *p2,
                                VngoColor24bit *rgb_val=NULL,
                                VngoRect *clip_rect=NULL);
    virtual VNGError clip_gline (VngoPoint *p1, VngoPoint *p2,
                                 VngoRect *clip_rect=NULL);
    virtual VNGError clip_gline (VngoPoint2 *p1, VngoPoint2 *p2,
                                 VngoRect *clip_rect=NULL);
// Not yet implemented.
    virtual VNGError clip_gline_persp (VngoPoint *p1, VngoPoint *p2,
                                       VngoRect *clip_rect=NULL);
    virtual VNGError clip_gline_persp (VngoPoint2 *p1, VngoPoint2 *p2,
                                       VngoRect *clip_rect=NULL);

    virtual VNGError poly (int count, VngoPoint pts[]);
    virtual VNGError poly (int count, VngoPoint2 pts[]);
    virtual VNGError gpoly (int count, VngoPoint pts[]);
    virtual VNGError gpoly (int count, VngoPoint2 pts[]);
    virtual VNGError gpoly_persp (int count, VngoPoint pts[]);
    virtual VNGError gpoly_persp (int count, VngoPoint2 pts[]);
    virtual VNGError tpoly (int count, VngoPoint pts[],VngoTexture *tex);
    virtual VNGError tpoly (int count, VngoPoint2 pts[],VngoTexture *tex);
    virtual VNGError tpoly_persp (int count, VngoPoint pts[],VngoTexture *tex);
    virtual VNGError tpoly_persp (int count, VngoPoint2 pts[],VngoTexture *tex);
    virtual VNGError gtpoly (int count, VngoPoint pts[],VngoTexture *tex);
    virtual VNGError gtpoly (int count, VngoPoint2 pts[],VngoTexture *tex);
    virtual VNGError gtpoly_persp (int count, VngoPoint pts[],VngoTexture *tex);
    virtual VNGError gtpoly_persp (int count, VngoPoint2 pts[],VngoTexture *tex);
    virtual VNGError grpoly (int count,VngoPoint pts[]);
    virtual VNGError grpoly (int count,VngoPoint2 pts[]);
// Alpha blended versions
    virtual VNGError poly_a (int count, VngoPoint pts[],long alpha=127);
    virtual VNGError poly_a (int count, VngoPoint2 pts[],long alpha=127);
    virtual VNGError gpoly_a (int count, VngoPoint pts[],long alpha=127);
    virtual VNGError gpoly_a (int count, VngoPoint2 pts[],long alpha=127);
    virtual VNGError gpoly_persp_a (int count, VngoPoint pts[],long alpha=127);
    virtual VNGError gpoly_persp_a (int count, VngoPoint2 pts[],long alpha=127);
    virtual VNGError tpoly_a (int count, VngoPoint pts[],VngoTexture *tex,
                              long alpha=127);
    virtual VNGError tpoly_a (int count, VngoPoint2 pts[],VngoTexture *tex,
                              long alpha=127);
    virtual VNGError tpoly_persp_a (int count, VngoPoint pts[],
                                    VngoTexture *tex,long alpha=127);
    virtual VNGError tpoly_persp_a (int count, VngoPoint2 pts[],
                                    VngoTexture *tex,long alpha=127);
    virtual VNGError gtpoly_a (int count, VngoPoint pts[],VngoTexture *tex,
                               long alpha=127);
    virtual VNGError gtpoly_a (int count, VngoPoint2 pts[],VngoTexture *tex,
                               long alpha=127);
    virtual VNGError gtpoly_persp_a (int count, VngoPoint pts[],
                                     VngoTexture *tex,long alpha=127);
    virtual VNGError gtpoly_persp_a (int count, VngoPoint2 pts[],
                                     VngoTexture *tex,long alpha=127);

// Not yet implemented.
    virtual VNGError clip_poly (int count, VngoPoint pts[],
                                VngoRect *clip_rect)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_poly (int count, VngoPoint2 pts[],
                                VngoRect *clip_rect)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gpoly (int count, VngoPoint pts[],
                                 VngoRect *clip_rect)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gpoly (int count, VngoPoint2 pts[],
                                 VngoRect *clip_rect)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gpoly_persp (int count, VngoPoint pts[],
                                       VngoRect *clip_rect)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gpoly_persp (int count, VngoPoint2 pts[],
                                       VngoRect *clip_rect)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_tpoly (int count, VngoPoint pts[],VngoTexture *tex,
                                 VngoRect *clip_rect)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_tpoly (int count, VngoPoint2 pts[],VngoTexture *tex,
                                 VngoRect *clip_rect)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_tpoly_persp (int count, VngoPoint pts[],
                                       VngoTexture *tex, VngoRect *clip_rect)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_tpoly_persp (int count, VngoPoint2 pts[],
                                       VngoTexture *tex, VngoRect *clip_rect)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gtpoly (int count, VngoPoint pts[],
                                  VngoTexture *tex, VngoRect *clip_rect)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gtpoly (int count, VngoPoint2 pts[],
                                  VngoTexture *tex, VngoRect *clip_rect)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gtpoly_persp (int count, VngoPoint pts[],
                                        VngoTexture *tex, VngoRect *clip_rect)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gtpoly_persp (int count, VngoPoint2 pts[],
                                        VngoTexture *tex, VngoRect *clip_rect)
    {
        return VNGO_NOT_SUPPORTED;
    }
// Alpha blended versions
    virtual VNGError clip_poly_a (int count, VngoPoint pts[],
                                  VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_poly_a (int count, VngoPoint2 pts[],
                                  VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gpoly_a (int count, VngoPoint pts[],
                                   VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gpoly_a (int count, VngoPoint2 pts[],
                                   VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gpoly_persp_a (int count, VngoPoint pts[],
                                         VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gpoly_persp_a (int count, VngoPoint2 pts[],
                                         VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_tpoly_a (int count, VngoPoint pts[],VngoTexture *tex,
                                   VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_tpoly_a (int count, VngoPoint2 pts[],VngoTexture *tex,
                                   VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_tpoly_persp_a (int count, VngoPoint pts[],
                                         VngoTexture *tex, VngoRect *clip_rect,
                                         long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_tpoly_persp_a (int count, VngoPoint2 pts[],
                                         VngoTexture *tex, VngoRect *clip_rect,
                                         long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    };
    virtual VNGError clip_gtpoly_a (int count, VngoPoint pts[],VngoTexture *tex,
                                    VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gtpoly_a (int count, VngoPoint2 pts[],
                                    VngoTexture *tex, VngoRect *clip_rect,
                                    long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gtpoly_persp_a (int count, VngoPoint pts[],
                                          VngoTexture *tex, VngoRect *clip_rect,
                                          long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gtpoly_persp_a (int count, VngoPoint2 pts[],
                                          VngoTexture *tex, VngoRect *clip_rect,
                                          long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }

    virtual VNGError image_trans (VngoRect *dest_rect,VngoTexture *img,
                                  dword flags=0);
    virtual VNGError image_trans_s (VngoRect *dest_rect,VngoTexture *img,
                                    dword shade, dword flags=0);
    virtual VNGError image_trans_z (VngoRect *dest_rect,VngoTexture *img,
                                    dword depth, dword flags=0);
    virtual VNGError image_trans_zs (VngoRect *dest_rect,VngoTexture *img,
                                     dword depth,dword shade,dword flags=0);

    virtual VNGError image_trans_mono (VngoRect *dest_rect,VngoTexture *img,
                                       dword fgcol,dword bgcol=VNGO_TRANSPARENT);
    virtual VNGError zblit_mono (VngoRect *dest_rect,VngoZMap *zmp,
                                 dword fdist,dword ndist=0);

    virtual VNGError image_trans_a (VngoRect *dest_rect,VngoTexture *img,
                                    long alpha=127, dword flags=0)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError image_trans_mono_a (VngoRect *dest_rect,VngoTexture *img,
                                         dword fgcol,dword bgcol=VNGO_TRANSPARENT,
                                         long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }

    virtual VNGError haze(VngoShadePal *hazepal,long startZ=0,VngoRect *rect=NULL)
    {
        return VNGO_NOT_SUPPORTED;
    }

};

#endif          // __VNGVVP8_HPP

//°±² End of module - vngvvp8.hpp ²±°

