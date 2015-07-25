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
// Created by Tim Little
//
// vngd3d.hpp
//
// Contains the Direct3D viewport class definition
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __VNGD3D_HPP
#define __VNGD3D_HPP  1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "portable.h"
#include "vngdefs.h"
#include "vngvp.hpp"
#include "vngstrct.hpp"
#include "vngscrn.hpp"

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

class VngoVportD3D : public VngoVport
{
    long            left,top;
    DDSURFACEDESC   ddsd;
    VngoDirect3D    *screen;
    VngoHazeInfoD3D fog_table;

    int plock();
    int punlock();
public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    VngoVportD3D() {};
    VngoVportD3D(VngoRect &dim,VngoPal *,dword,VngoScreenManager *_screen);

    virtual ~VngoVportD3D();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    VNGError init (VngoRect &dim,VngoPal *,dword,VngoScreenManager *_screen);

    virtual void zbuffer_on();
    virtual void zbuffer_off();

    virtual void texture_filter_on()
    {
        vflags |= VNGO_TEXTURE_FILTER;
        VgSystem.cur_vport = NULL;
        make_current();
    }
    virtual void texture_filter_off()
    {
        vflags &= ~VNGO_TEXTURE_FILTER;
        VgSystem.cur_vport = NULL;
        make_current();
    }

    virtual void true_alpha_on()
    {
        vflags |= VNGO_TRUE_ALPHA;
        VgSystem.cur_vport = NULL;
        make_current();
    }
    virtual void true_alpha_off()
    {
        vflags &= ~VNGO_TRUE_ALPHA;
        VgSystem.cur_vport = NULL;
        make_current();
    }

    virtual void haze_on()
    {
        VngoVport::haze_on();
        VgSystem.cur_vport = NULL;
        make_current();
    }
    virtual void haze_off()
    {
        VngoVport::haze_off();
        VgSystem.cur_vport = NULL;
        make_current();
    }


    virtual void make_current();

    virtual VNGError capture(XFBitmap *bm)
    {
        VNGError err = VNGO_INTERNAL_ERROR;
        int was_locked = plock();
        if(was_locked != -1)
        {
            err = VngoVport::capture(bm);
            if (!was_locked)
                punlock();
        }
        return err;
    }

    //ÄÄÄ Basic drawing functions
    virtual void reset(dword c=0,dword farz=0xffffffff);
    virtual VNGError vpcopy (int destx,int desty,VngoVport *dest);

    //ÄÄÄ Rectangle drawing functions
    virtual VNGError frect (VngoRect *rect, dword color);
    virtual VNGError frect (VngoRect *rect, VngoColor24bit *rgb_val);
    virtual VNGError clip_frect (VngoRect *rect,
                                 dword color,
                                 VngoRect *clip_rect=NULL);
    virtual VNGError clip_frect (VngoRect *rect,
                                 VngoColor24bit *rgb_val,
                                 VngoRect *clip_rect=NULL);

    //ÄÄÄ Pixel drawing functions
    virtual VNGError pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL);
    virtual VNGError pixel (VngoPointF *pt, VngoColor24bit *rgb_val = NULL);
    virtual VNGError clip_pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL,
                                 VngoRect *clip_rect=NULL);
    virtual VNGError clip_pixel (VngoPointF *pt, VngoColor24bit *rgb_val = NULL,
                                 VngoRect *clip_rect=NULL);
    virtual dword read_pixel (VngoPoint *pt, VngoPoint *dest)
        { return VNGO_NOT_SUPPORTED; }
    virtual dword read_pixel (int x, int y, VngoPoint *dest)
        { return VNGO_NOT_SUPPORTED; }

    //ÄÄÄ Image transfer functions
    virtual VNGError image_trans (VngoRect *dest_rect,VngoTexture *img,
                                  dword flags=0);
    virtual VNGError image_trans_a (VngoRect *dest_rect,VngoTexture *img,
                                    long alpha=127, dword flags=0)
        { return VNGO_NOT_SUPPORTED; }

    virtual VNGError image_trans_mono (VngoRect *dest_rect,VngoTexture *img,
                                       dword fgcol,dword bgcol=VNGO_TRANSPARENT);
    virtual VNGError zblit_mono (VngoRect *dest_rect,VngoZMap *zmp,dword fdist,
                                 dword ndist=0);

    //ÄÄÄ Line drawing functions
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

    //ÄÄÄ Polygon drawing functions
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

    //ÄÄÄ Alpha-blended polygon drawing functions
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

    //ÄÄÄ Fogging/hazing functions
    virtual VNGError set_haze(VngoHazeInfo *haze_info)
    {
        fog_table.setup(haze_info);
        return VNGO_NO_ERROR;
    }
    virtual VNGError haze()
        { return VNGO_NOT_SUPPORTED; }
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif          // __VNGD3D_HPP

//°±² End of module - vngd3d.hpp ²±°

