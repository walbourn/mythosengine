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
// vngvpdd8.hpp  
//
//
//อออออออออออออออออออออออออออออ Revision History ออออออออออออออออออออออออออออ
//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

#ifndef __VNGVPDD8_HPP
#define __VNGVPDD8_HPP

#include "vngvvp8.hpp"
#include <ddraw.h>

class VngoSurfaceManager
{
    int                     lock_status;
public:
    IDirectDrawSurface      *ddsurf;

    VngoSurfaceManager() {lock_status = 0;}
    VngoSurfaceManager(IDirectDrawSurface *_ddsurf) 
    {
        ddsurf = _ddsurf; 
        lock_status = 0;
    }

    int get_lock_status() {return lock_status;}

    int lock() 
    { 
        int t = lock_status;
        lock_status = 1;
        return t;
    }

    int unlock()
    {
        int t = lock_status;
        lock_status = 0;
        return t;
    }
};

class VngoVportDD8 : public VngoVVport8
{
    dword                   vp_offset;
    VngoRect                vp_rect;
    DDSURFACEDESC           ddsd;
    IDirectDrawSurface      *pddsurf;
    VngoSurfaceManager      *surf_stat;

public:
    VngoVportDD8 () {};
    VngoVportDD8 (VngoSurfaceManager *_pddsurf, VngoSurfaceManager *zbptr,
                  VngoPal *my_pal,dword flags);
    VngoVportDD8 (VngoSurfaceManager *_pddsurf, VngoSurfaceManager *zbptr,
                  VngoRect &srect, VngoPal *my_pal, dword flags);

    virtual ~VngoVportDD8();

    VNGError init (VngoSurfaceManager *_pddsurf, 
                           VngoSurfaceManager *zbptr,
                           VngoPal *my_pal,dword flags);

    VNGError init (VngoSurfaceManager *_pddsurf, VngoSurfaceManager *zbptr,
                           VngoRect &srect, VngoPal *my_pal,dword flags);

    virtual void reset(dword c=0,dword farz=0xffffffff);
    virtual VNGError frect (VngoRect *rect, dword color);
    virtual VNGError frect (VngoRect *rect, VngoColor24bit *rgb_val);
    virtual VNGError clip_frect (VngoRect *rect, dword color, VngoRect *clip=NULL);
    virtual VNGError clip_frect (VngoRect *rect, VngoColor24bit *rgb_val, VngoRect *clip=NULL);

// New  functions special for Direct Draw!
    virtual int lock();
    virtual int unlock();
};

#endif  // __VNGVPDD8_HPP
