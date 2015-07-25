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
// vngoems.hpp
//
// Contains the 3D hardware specific viewport classes.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __VNGOEMS_HPP
#define __VNGOEMS_HPP  1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "portable.h"
#include "vngdefs.h"
#include "vngvp.hpp"
#include "vngstrct.hpp"

#ifdef _OEMS
#ifdef _3DFX
    extern "C" {
    #include <glide.h>
    }
#endif // _3DFX

#ifdef _MSI
    #include <MSI95.h>
#endif // _MSI

#ifdef _CLEAR_3D
    #include <wll3d.h>
#endif // _CLEAR_3D
#endif // _OEMS

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// 3D/fx Glide
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#ifdef _OEMS
#ifdef _3DFX
class VngoVport3Dfx : public VngoVport
{
public:


    VngoVport3Dfx() {};
    VngoVport3Dfx(long,long,long,long,VngoPal *,dword);
    virtual ~VngoVport3Dfx();

    virtual VNGError init (long,long,long,long,VngoPal *,dword);

    // All of these functions will be virtuals eventualy.
    virtual void reset(dword c=0,dword farz=0xffffffff);


    virtual VNGError vpcopy (int destx,int desty,VngoVport *dest);

    virtual VNGError pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL);
    virtual VNGError pixel (VngoPointF *pt, VngoColor24bit *rgb_val = NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL,
                                 VngoRect *clip_rect=NULL);
    virtual VNGError clip_pixel (VngoPointF *pt, VngoColor24bit *rgb_val = NULL,
                                 VngoRect *clip_rect=NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual dword read_pixel (VngoPoint *pt, VngoPoint *dest);
    virtual dword read_pixel (int x, int y, VngoPoint *dest);

    virtual VNGError frect (VngoRect *rect, dword color);
    virtual VNGError frect (VngoRect *rect, VngoColor24bit *rgb_val);
    virtual VNGError clip_frect (VngoRect *rect,
                                 dword color,
                                 VngoRect *clip_rect=NULL);
    virtual VNGError clip_frect (VngoRect *rect,
                                 VngoColor24bit *rgb_val,
                                 VngoRect *clip_rect=NULL);

    virtual VNGError line (VngoPoint *p1, VngoPoint *p2,
                           VngoColor24bit *rgb_val=NULL);
    virtual VNGError line (VngoPointF *p1, VngoPointF *p2,
                           VngoColor24bit *rgb_val=NULL)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError gline (VngoPoint *p1, VngoPoint *p2);
    virtual VNGError gline (VngoPointF *p1, VngoPointF *p2)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError gline_persp (VngoPoint *p1, VngoPoint *p2);
    virtual VNGError gline_persp (VngoPointF *p1, VngoPointF *p2)
            { return VNGO_NOT_SUPPORTED;};

    virtual VNGError clip_line (VngoPoint *p1, VngoPoint *p2,
                                VngoColor24bit *rgb_val=NULL,
                                VngoRect *clip_rect=NULL);
    virtual VNGError clip_line (VngoPointF *p1, VngoPointF *p2,
                                VngoColor24bit *rgb_val=NULL,
                                VngoRect *clip_rect=NULL)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gline (VngoPoint *p1, VngoPoint *p2,
                                 VngoRect *clip_rect=NULL);
    virtual VNGError clip_gline (VngoPointF *p1, VngoPointF *p2,
                                 VngoRect *clip_rect=NULL)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gline_persp (VngoPoint *p1, VngoPoint *p2,
                                       VngoRect *clip_rect=NULL) ;
    virtual VNGError clip_gline_persp (VngoPointF *p1, VngoPointF *p2,
                                       VngoRect *clip_rect=NULL)
            { return VNGO_NOT_SUPPORTED;};

// Not yet implemented.
    virtual VNGError poly (int count, VngoPoint pts[]);
    virtual VNGError poly (int count, VngoPointF pts[])
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError gpoly (int count, VngoPoint pts[]);
    virtual VNGError gpoly (int count, VngoPointF pts[])
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError gpoly_persp (int count, VngoPoint pts[]);
    virtual VNGError gpoly_persp (int count, VngoPointF pts[])
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError tpoly (int count, VngoPoint pts[],VngoTexture *tex);
    virtual VNGError tpoly (int count, VngoPointF pts[],VngoTexture *tex)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError tpoly_persp (int count, VngoPoint pts[],VngoTexture *tex);
    virtual VNGError tpoly_persp (int count, VngoPointF pts[],VngoTexture *tex)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError gtpoly (int count, VngoPoint pts[],VngoTexture *tex);
    virtual VNGError gtpoly (int count, VngoPointF pts[],VngoTexture *tex)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError gtpoly_persp (int count, VngoPoint pts[],VngoTexture *tex);
    virtual VNGError gtpoly_persp (int count, VngoPointF pts[],VngoTexture *tex)
            { return VNGO_NOT_SUPPORTED;};
// Not yet implemented.
    virtual VNGError clip_poly (int count, VngoPoint pts[], VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_poly (int count, VngoPointF pts[],
                                VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gpoly (int count, VngoPoint pts[],
                                 VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gpoly (int count, VngoPointF pts[],
                                 VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gpoly_persp (int count, VngoPoint pts[],
                                       VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gpoly_persp (int count, VngoPointF pts[],
                                       VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_tpoly (int count, VngoPoint pts[],VngoTexture *tex,
                                 VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_tpoly (int count, VngoPointF pts[],VngoTexture *tex,
                                 VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_tpoly_persp (int count, VngoPoint pts[],
                                       VngoTexture *tex,
                                       VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_tpoly_persp (int count, VngoPointF pts[],
                                       VngoTexture *tex,
                                       VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gtpoly (int count, VngoPoint pts[],VngoTexture *tex,
                                  VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gtpoly (int count, VngoPointF pts[],VngoTexture *tex,
                                  VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gtpoly_persp (int count, VngoPoint pts[],
                                        VngoTexture *tex, VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gtpoly_persp (int count, VngoPointF pts[],
                                        VngoTexture *tex, VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError grpoly (int count,VngoPoint pts[])
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError grpoly (int count,VngoPointF pts[])
            { return VNGO_NOT_SUPPORTED;};

// Alpha blended versions
    virtual VNGError poly_a (int count, VngoPoint pts[],long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError poly_a (int count, VngoPointF pts[],long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gpoly_a (int count, VngoPoint pts[],long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gpoly_a (int count, VngoPointF pts[],long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gpoly_persp_a (int count, VngoPoint pts[],long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gpoly_persp_a (int count, VngoPointF pts[],long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError tpoly_a (int count, VngoPoint pts[],VngoTexture *tex,
                              long alpha=127) {return VNGO_NOT_SUPPORTED;}
    virtual VNGError tpoly_a (int count, VngoPointF pts[],VngoTexture *tex,
                              long alpha=127) {return VNGO_NOT_SUPPORTED;}
    virtual VNGError tpoly_persp_a (int count, VngoPoint pts[],
                                    VngoTexture *tex,long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError tpoly_persp_a (int count, VngoPointF pts[],
                                    VngoTexture *tex,long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gtpoly_a (int count, VngoPoint pts[],VngoTexture *tex,
                               long alpha=127) {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gtpoly_a (int count, VngoPointF pts[],VngoTexture *tex,
                               long alpha=127) {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gtpoly_persp_a (int count, VngoPoint pts[],
                                     VngoTexture *tex,long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gtpoly_persp_a (int count, VngoPointF pts[],
                                     VngoTexture *tex,long alpha=127)
            {return VNGO_NOT_SUPPORTED;}

// Not yet implemented.
    virtual VNGError image_trans (VngoRect *dest_rect,VngoTexture *img,
                                  dword flags=0);
    virtual VNGError image_trans_s (VngoRect *dest_rect,VngoTexture *img,
                                    dword shade, dword flags=0);
    virtual VNGError image_trans_z (VngoRect *dest_rect,VngoTexture *img,
                                    dword depth, dword flags=0);
    virtual VNGError image_trans_zs (VngoRect *dest_rect,VngoTexture *img,
                                     dword depth,dword shade,dword flags=0);

// Alpha blended versions
    virtual VNGError clip_poly_a (int count, VngoPoint pts[],
                                  VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_poly_a (int count, VngoPointF pts[],
                                  VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gpoly_a (int count, VngoPoint pts[],
                                   VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gpoly_a (int count, VngoPointF pts[],
                                   VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gpoly_persp_a (int count, VngoPoint pts[],
                                         VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gpoly_persp_a (int count, VngoPointF pts[],
                                         VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_tpoly_a (int count, VngoPoint pts[],VngoTexture *tex,
                                   VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_tpoly_a (int count, VngoPointF pts[],VngoTexture *tex,
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
    virtual VNGError clip_tpoly_persp_a (int count, VngoPointF pts[],
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
    virtual VNGError clip_gtpoly_a (int count, VngoPointF pts[],
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
    virtual VNGError clip_gtpoly_persp_a (int count, VngoPointF pts[],
                                          VngoTexture *tex, VngoRect *clip_rect,
                                          long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }

// Not yet implemented.
    virtual VNGError image_trans_mono (VngoRect *dest_rect,VngoTexture *img,
                                       dword fgcol,dword bgcol=VNGO_TRANSPARENT);
    virtual VNGError zblit_mono (VngoRect *dest_rect,VngoZMap *zmp,dword fdist,
                                 dword ndist=0);
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
#endif // _3DFX
#endif // _OEMS


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Matrox Simple Interface
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#ifdef _OEMS
#ifdef _MSI
class VngoVportMSI : public VngoVport
{
    VngoMSI     *screen;
public:


    VngoVportMSI() {};
    VngoVportMSI(long,long,long,long,VngoPal *,dword,VngoScreenManager *_screen);
    virtual ~VngoVportMSI();

    virtual VNGError init (long,long,long,long,VngoPal *,dword,VngoScreenManager *_screen);

    // All of these functions will be virtuals eventualy.
    virtual void reset(dword c=0,dword farz=0xffffffff);


    virtual VNGError vpcopy (int destx,int desty,VngoVport *dest)
            {return VNGO_NOT_SUPPORTED;};

    virtual VNGError pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError pixel (VngoPointF *pt, VngoColor24bit *rgb_val = NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL,
                                 VngoRect *clip_rect=NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_pixel (VngoPointF *pt, VngoColor24bit *rgb_val = NULL,
                                 VngoRect *clip_rect=NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual dword read_pixel (VngoPoint *pt, VngoPoint *dest)
            {return VNGO_NOT_SUPPORTED;};
    virtual dword read_pixel (int x, int y, VngoPoint *dest)
            {return VNGO_NOT_SUPPORTED;};

    virtual VNGError frect (VngoRect *rect, dword color)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError frect (VngoRect *rect, VngoColor24bit *rgb_val)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_frect (VngoRect *rect,
                                 dword color,
                                 VngoRect *clip_rect=NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_frect (VngoRect *rect,
                                 VngoColor24bit *rgb_val,
                                 VngoRect *clip_rect=NULL)
            {return VNGO_NOT_SUPPORTED;};

    virtual VNGError line (VngoPoint *p1, VngoPoint *p2,
                           VngoColor24bit *rgb_val=NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError line (VngoPointF *p1, VngoPointF *p2,
                           VngoColor24bit *rgb_val=NULL)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError gline (VngoPoint *p1, VngoPoint *p2)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gline (VngoPointF *p1, VngoPointF *p2)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError gline_persp (VngoPoint *p1, VngoPoint *p2)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError gline_persp (VngoPointF *p1, VngoPointF *p2)
            { return VNGO_NOT_SUPPORTED;};

    virtual VNGError clip_line (VngoPoint *p1, VngoPoint *p2,
                                VngoColor24bit *rgb_val=NULL,
                                VngoRect *clip_rect=NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_line (VngoPointF *p1, VngoPointF *p2,
                                VngoColor24bit *rgb_val=NULL,
                                VngoRect *clip_rect=NULL)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gline (VngoPoint *p1, VngoPoint *p2,
                                 VngoRect *clip_rect=NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gline (VngoPointF *p1, VngoPointF *p2,
                                 VngoRect *clip_rect=NULL)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gline_persp (VngoPoint *p1, VngoPoint *p2,
                                       VngoRect *clip_rect=NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gline_persp (VngoPointF *p1, VngoPointF *p2,
                                       VngoRect *clip_rect=NULL)
            { return VNGO_NOT_SUPPORTED;};

// Polygon functions.
    virtual VNGError poly (int count, VngoPoint pts[]);
    virtual VNGError poly (int count, VngoPointF pts[]);
    virtual VNGError gpoly (int count, VngoPoint pts[]);
    virtual VNGError gpoly (int count, VngoPointF pts[]);

    virtual VNGError gpoly_persp (int count, VngoPoint pts[])
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError gpoly_persp (int count, VngoPointF pts[])
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError tpoly (int count, VngoPoint pts[],VngoTexture *tex)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError tpoly (int count, VngoPointF pts[],VngoTexture *tex)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError tpoly_persp (int count, VngoPoint pts[],VngoTexture *tex)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError tpoly_persp (int count, VngoPointF pts[],VngoTexture *tex)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError gtpoly (int count, VngoPoint pts[],VngoTexture *tex)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError gtpoly (int count, VngoPointF pts[],VngoTexture *tex)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError gtpoly_persp (int count, VngoPoint pts[],VngoTexture *tex)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError gtpoly_persp (int count, VngoPointF pts[],VngoTexture *tex)
            { return VNGO_NOT_SUPPORTED;};

// Clipped versions.
    virtual VNGError clip_poly (int count, VngoPoint pts[], VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_poly (int count, VngoPointF pts[],
                                VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gpoly (int count, VngoPoint pts[],
                                 VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gpoly (int count, VngoPointF pts[],
                                 VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gpoly_persp (int count, VngoPoint pts[],
                                       VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gpoly_persp (int count, VngoPointF pts[],
                                       VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_tpoly (int count, VngoPoint pts[],VngoTexture *tex,
                                 VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_tpoly (int count, VngoPointF pts[],VngoTexture *tex,
                                 VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_tpoly_persp (int count, VngoPoint pts[],
                                       VngoTexture *tex,
                                       VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_tpoly_persp (int count, VngoPointF pts[],
                                       VngoTexture *tex,
                                       VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gtpoly (int count, VngoPoint pts[],VngoTexture *tex,
                                  VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gtpoly (int count, VngoPointF pts[],VngoTexture *tex,
                                  VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gtpoly_persp (int count, VngoPoint pts[],
                                        VngoTexture *tex, VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gtpoly_persp (int count, VngoPointF pts[],
                                        VngoTexture *tex, VngoRect *clip_rect)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError grpoly (int count,VngoPoint pts[])
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError grpoly (int count,VngoPointF pts[])
            { return VNGO_NOT_SUPPORTED;};

// Alpha blended versions
    virtual VNGError poly_a (int count, VngoPoint pts[],long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError poly_a (int count, VngoPointF pts[],long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gpoly_a (int count, VngoPoint pts[],long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gpoly_a (int count, VngoPointF pts[],long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gpoly_persp_a (int count, VngoPoint pts[],long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gpoly_persp_a (int count, VngoPointF pts[],long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError tpoly_a (int count, VngoPoint pts[],VngoTexture *tex,
                              long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError tpoly_a (int count, VngoPointF pts[],VngoTexture *tex,
                              long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError tpoly_persp_a (int count, VngoPoint pts[],
                                    VngoTexture *tex,long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError tpoly_persp_a (int count, VngoPointF pts[],
                                    VngoTexture *tex,long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gtpoly_a (int count, VngoPoint pts[],VngoTexture *tex,
                               long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gtpoly_a (int count, VngoPointF pts[],VngoTexture *tex,
                               long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gtpoly_persp_a (int count, VngoPoint pts[],
                                     VngoTexture *tex,long alpha=127)
            {return VNGO_NOT_SUPPORTED;}
    virtual VNGError gtpoly_persp_a (int count, VngoPointF pts[],
                                     VngoTexture *tex,long alpha=127)
            {return VNGO_NOT_SUPPORTED;}

// Not yet implemented.
    virtual VNGError image_trans (VngoRect *dest_rect,VngoTexture *img,
                                  dword flags=0)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError image_trans_s (VngoRect *dest_rect,VngoTexture *img,
                                    dword shade, dword flags=0)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError image_trans_z (VngoRect *dest_rect,VngoTexture *img,
                                    dword depth, dword flags=0)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError image_trans_zs (VngoRect *dest_rect,VngoTexture *img,
                                     dword depth,dword shade,dword flags=0)
            {return VNGO_NOT_SUPPORTED;};

// Alpha blended versions
    virtual VNGError clip_poly_a (int count, VngoPoint pts[],
                                  VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_poly_a (int count, VngoPointF pts[],
                                  VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gpoly_a (int count, VngoPoint pts[],
                                   VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gpoly_a (int count, VngoPointF pts[],
                                   VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gpoly_persp_a (int count, VngoPoint pts[],
                                         VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_gpoly_persp_a (int count, VngoPointF pts[],
                                         VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_tpoly_a (int count, VngoPoint pts[],VngoTexture *tex,
                                   VngoRect *clip_rect,long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError clip_tpoly_a (int count, VngoPointF pts[],VngoTexture *tex,
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
    virtual VNGError clip_tpoly_persp_a (int count, VngoPointF pts[],
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
    virtual VNGError clip_gtpoly_a (int count, VngoPointF pts[],
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
    virtual VNGError clip_gtpoly_persp_a (int count, VngoPointF pts[],
                                          VngoTexture *tex, VngoRect *clip_rect,
                                          long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }

// Not yet implemented.
    virtual VNGError image_trans_mono (VngoRect *dest_rect,VngoTexture *img,
                                       dword fgcol,dword bgcol=VNGO_TRANSPARENT)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError zblit_mono (VngoRect *dest_rect,VngoZMap *zmp,dword fdist,
                                 dword ndist=0)
            {return VNGO_NOT_SUPPORTED;};
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
#endif // _MSI
#endif // _OEMS


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Cirrus Clear3D
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#ifdef _OEMS
#ifdef _CLEAR_3D
class VngoVportCL3D : public VngoVport
{
    long            left,top;
    VngoClear3D     *screen;

    int plock();
    int punlock();
public:


    VngoVportCL3D() {};
    VngoVportCL3D(long,long,long,long,VngoPal *,dword,VngoScreenManager *_screen);
    virtual ~VngoVportCL3D();

    virtual VNGError init (long,long,long,long,VngoPal *,dword,VngoScreenManager *_screen);

    // All of these functions will be virtuals eventualy.
    virtual void reset(dword c=0,dword farz=0xffffffff);


    virtual VNGError vpcopy (int destx,int desty,VngoVport *dest);

    virtual VNGError pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL);
    virtual VNGError pixel (VngoPointF *pt, VngoColor24bit *rgb_val = NULL);
    virtual VNGError clip_pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL,
                                 VngoRect *clip_rect=NULL);
    virtual VNGError clip_pixel (VngoPointF *pt, VngoColor24bit *rgb_val = NULL,
                                 VngoRect *clip_rect=NULL);
    virtual dword read_pixel (VngoPoint *pt, VngoPoint *dest)
            {return VNGO_NOT_SUPPORTED;};
    virtual dword read_pixel (int x, int y, VngoPoint *dest)
            {return VNGO_NOT_SUPPORTED;};

    virtual VNGError frect (VngoRect *rect, dword color);
    virtual VNGError frect (VngoRect *rect, VngoColor24bit *rgb_val);
    virtual VNGError clip_frect (VngoRect *rect,
                                 dword color,
                                 VngoRect *clip_rect=NULL);
    virtual VNGError clip_frect (VngoRect *rect,
                                 VngoColor24bit *rgb_val,
                                 VngoRect *clip_rect=NULL);

    virtual VNGError line (VngoPoint *p1, VngoPoint *p2,
                           VngoColor24bit *rgb_val=NULL);
    virtual VNGError line (VngoPointF *p1, VngoPointF *p2,
                           VngoColor24bit *rgb_val=NULL);
    virtual VNGError gline (VngoPoint *p1, VngoPoint *p2);
    virtual VNGError gline (VngoPointF *p1, VngoPointF *p2);
    virtual VNGError gline_persp (VngoPoint *p1, VngoPoint *p2);
    virtual VNGError gline_persp (VngoPointF *p1, VngoPointF *p2);

    virtual VNGError clip_line (VngoPoint *p1, VngoPoint *p2,
                                VngoColor24bit *rgb_val=NULL,
                                VngoRect *clip_rect=NULL);
    virtual VNGError clip_line (VngoPointF *p1, VngoPointF *p2,
                                VngoColor24bit *rgb_val=NULL,
                                VngoRect *clip_rect=NULL);
    virtual VNGError clip_gline (VngoPoint *p1, VngoPoint *p2,
                                 VngoRect *clip_rect=NULL);
    virtual VNGError clip_gline (VngoPointF *p1, VngoPointF *p2,
                                 VngoRect *clip_rect=NULL);
    virtual VNGError clip_gline_persp (VngoPoint *p1, VngoPoint *p2,
                                       VngoRect *clip_rect=NULL);
    virtual VNGError clip_gline_persp (VngoPointF *p1, VngoPointF *p2,
                                       VngoRect *clip_rect=NULL);

// Polygon functions.
    virtual VNGError poly (int count, VngoPoint pts[]);
    virtual VNGError poly (int count, VngoPointF pts[]);
    virtual VNGError gpoly (int count, VngoPoint pts[]);
    virtual VNGError gpoly (int count, VngoPointF pts[]);

    virtual VNGError gpoly_persp (int count, VngoPoint pts[]);
    virtual VNGError gpoly_persp (int count, VngoPointF pts[]);
    virtual VNGError tpoly (int count, VngoPoint pts[],VngoTexture *tex);
    virtual VNGError tpoly (int count, VngoPointF pts[],VngoTexture *tex);
    virtual VNGError tpoly_persp (int count, VngoPoint pts[],VngoTexture *tex);
    virtual VNGError tpoly_persp (int count, VngoPointF pts[],VngoTexture *tex);
    virtual VNGError gtpoly (int count, VngoPoint pts[],VngoTexture *tex);
    virtual VNGError gtpoly (int count, VngoPointF pts[],VngoTexture *tex);
    virtual VNGError gtpoly_persp (int count, VngoPoint pts[],VngoTexture *tex);
    virtual VNGError gtpoly_persp (int count, VngoPointF pts[],VngoTexture *tex);
    virtual VNGError grpoly (int count,VngoPoint pts[]);
    virtual VNGError grpoly (int count,VngoPointF pts[]);

// Alpha blended versions
    virtual VNGError poly_a (int count, VngoPoint pts[],long alpha=127);
    virtual VNGError poly_a (int count, VngoPointF pts[],long alpha=127);
    virtual VNGError gpoly_a (int count, VngoPoint pts[],long alpha=127);
    virtual VNGError gpoly_a (int count, VngoPointF pts[],long alpha=127);
    virtual VNGError gpoly_persp_a (int count, VngoPoint pts[],long alpha=127);
    virtual VNGError gpoly_persp_a (int count, VngoPointF pts[],long alpha=127);
    virtual VNGError tpoly_a (int count, VngoPoint pts[],VngoTexture *tex,
                              long alpha=127);
    virtual VNGError tpoly_a (int count, VngoPointF pts[],VngoTexture *tex,
                              long alpha=127);
    virtual VNGError tpoly_persp_a (int count, VngoPoint pts[],
                                    VngoTexture *tex,long alpha=127);
    virtual VNGError tpoly_persp_a (int count, VngoPointF pts[],
                                    VngoTexture *tex,long alpha=127);
    virtual VNGError gtpoly_a (int count, VngoPoint pts[],VngoTexture *tex,
                               long alpha=127);
    virtual VNGError gtpoly_a (int count, VngoPointF pts[],VngoTexture *tex,
                               long alpha=127);
    virtual VNGError gtpoly_persp_a (int count, VngoPoint pts[],
                                     VngoTexture *tex,long alpha=127);
    virtual VNGError gtpoly_persp_a (int count, VngoPointF pts[],
                                     VngoTexture *tex,long alpha=127);

    virtual VNGError image_trans (VngoRect *dest_rect,VngoTexture *img,
                                  dword flags=0);
    virtual VNGError image_trans_mono (VngoRect *dest_rect,VngoTexture *img,
                                       dword fgcol,dword bgcol=VNGO_TRANSPARENT);
    virtual VNGError zblit_mono (VngoRect *dest_rect,VngoZMap *zmp,dword fdist,
                                 dword ndist=0);
    virtual VNGError image_trans_a (VngoRect *dest_rect,VngoTexture *img,
                                    long alpha=127, dword flags=0)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError image_trans_mono_a (VngoRect *dest_rect,VngoTexture *img,
                                         dword fgcol,dword bgcol=VNGO_TRANSPARENT,
                                         long alpha=127)
            {return VNGO_NOT_SUPPORTED;};

    virtual VNGError haze(VngoShadePal *hazepal,long startZ=0,VngoRect *rect=NULL)
            {return VNGO_NOT_SUPPORTED;};
};
#endif // _CLEAR_3D
#endif // _OEMS

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif          // __VNGOEMS_HPP

//°±² End of module - vngoems.hpp ²±°


