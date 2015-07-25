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
// vngbd.hpp
//
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __VNGBD_HPP
#define __VNGBD_HPP  1


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "portable.h"
#include "vngdefs.h"
#include "vngstrct.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


class VngoBaseDev
{
protected:
    dword               size_in_bytes;
    int                 lock_status;
    VNGError            init_status;

public:
    dword               vflags;
    int                 vzdepth_in_bits;
    VngoVbuffer         vbuff;


    virtual ~VngoBaseDev() {}

    // Inline functions.
    inline VngoVbuffer *get_vbuff() {return &vbuff;}
    inline void zbuffer_on() {if (vflags & VNGO_ZBUFFER_DEV) vflags |= VNGO_ZBUFFER_ACTIVE;}
    inline void zbuffer_off() {vflags &= ~VNGO_ZBUFFER_ACTIVE;}

    inline int  get_zbuffer_precision()
    {
        if (vflags &= VNGO_ZBUFFER_ACTIVE)
            return (vzdepth_in_bits);
        else
            return (0);
    }

    inline void clear_screen_on() { vflags &= ~VNGO_NOCLEAR_VBUFFER;}
    inline void clear_screen_off() { vflags |= VNGO_NOCLEAR_VBUFFER;}
    inline VNGError get_init_state() {return (init_status);}

    // Virtual funcitons for drawing.
    virtual void reset(dword c=0,dword farz=0xffffffff)=0;
    virtual VNGError vpcopy (int destx,int desty,VngoBaseDev *dest)=0;
    virtual VNGError frect (VngoRect *rect,dword color) = 0;
    virtual VNGError frect (VngoRect *rect,VngoColor24bit *rgb_val = NULL) = 0;

    virtual VNGError pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL) = 0;
    virtual VNGError pixel (VngoPoint2 *pt, VngoColor24bit *rgb_val = NULL) = 0;
    virtual VNGError clip_pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL, VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_pixel (VngoPoint2 *pt, VngoColor24bit *rgb_val = NULL, VngoRect *clip_rect=NULL) = 0;
    virtual dword read_pixel (VngoPoint *pt, VngoPoint *dest)=0;
    virtual dword read_pixel (int x, int y, VngoPoint *dest)=0;
    virtual VNGError clip_frect (VngoRect *rect,dword color, VngoRect *clip=NULL) = 0;
    virtual VNGError clip_frect (VngoRect *rect,VngoColor24bit *rgb_val, VngoRect *clip=NULL) = 0;

    // virtual functions for transfering data directly to the vport.
    virtual VNGError image_trans (VngoRect *dest_rect,VngoTexture *img,dword flags=0) = 0;
    virtual VNGError image_trans_s (VngoRect *dest_rect,VngoTexture *img,dword shade, dword flags=0) = 0;
    virtual VNGError image_trans_z (VngoRect *dest_rect,VngoTexture *img,dword depth, dword flags=0) = 0;
    virtual VNGError image_trans_zs (VngoRect *dest_rect,VngoTexture *img,dword depth,dword shade,dword flags=0) = 0;

    virtual VNGError image_trans_mono (VngoRect *dest_rect,VngoTexture *img,dword fgcol,dword bgcol=VNGO_TRANSPARENT) = 0;
    virtual VNGError zblit_mono (VngoRect *dest_rect,VngoZMap *zmp,dword fdist,dword ndist=0) = 0;

    // Buffering syncronization call.  (if a BaseDev or ViewPort wants to
    // buffer output for self sorting etc then it can queue thing up until
    // the sync call is made at which time all buffered commands must be made.)

    virtual void sync() {};

    virtual int  lock()
    {
        int ret_val = lock_status;
        lock_status = 1;
        return (ret_val);
    };
    virtual int  unlock()
    {
        int ret_val = lock_status;
        lock_status = 0;
        return (ret_val);
    };


};


#endif          // __VNGBD_HPP

//°±² End of module - vngbd.hpp ²±°

