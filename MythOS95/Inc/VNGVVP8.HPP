//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. | 
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  | 
//                                                           |_|_|_._._.|
// Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.   |.-.-.-.-..|
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
// vngvvp8.hpp  
//
//     This is the Virtual 8bpp viewport Class header file for the
//     Van Gogh 2D draw library.
//
//อออออออออออออออออออออออออออออ Revision History ออออออออออออออออออออออออออออ
//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

#ifndef __VNGVVP8_HPP
#define __VNGVVP8_HPP  1


//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//             
//                                Includes
//                                
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

#include "portable.h"
#include "vngdefs.h"
#include "vngvp.hpp"
#include "vngstrct.hpp"
#include "vnginlin.ipp"

//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//
//                               Prototypes
//
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ


class VngoVVport8 : public VngoVport
{
public:
    VngoVVport8() {};
    VngoVVport8(long,long,long,long,VngoPal *,dword);
    virtual ~VngoVVport8();

    virtual vngo_error_codes init (long,long,long,long,VngoPal *,dword);

    // All of these functions will be virtuals eventualy.
    virtual void reset(dword c=0,dword farz=0xffffffff);


    virtual void vpcopy (int destx,int desty,VngoBaseDev *dest);
    virtual void pixel (VngoPoint *pt);
    virtual void frect (VngoRect *rect, dword color);

    virtual void line (VngoPoint *p1, VngoPoint *p2);
    virtual void gline (VngoPoint *p1, VngoPoint *p2);
    virtual void gline_persp (VngoPoint *p1, VngoPoint *p2);

    virtual void poly (int count, VngoPoint pts[]);
    virtual void gpoly (int count, VngoPoint pts[]);
    virtual void gpoly_persp (int count, VngoPoint pts[]);
    virtual void tpoly (int count, VngoPoint pts[],VngoTexture *tex);
    virtual void tpoly_persp (int count, VngoPoint pts[],VngoTexture *tex);
    virtual void gtpoly (int count, VngoPoint pts[],VngoTexture *tex);
    virtual void gtpoly_persp (int count, VngoPoint pts[],VngoTexture *tex);

    virtual void image_trans (VngoRect *dest_rect,VngoTexture *img,dword flags=0);
    virtual void image_trans_mono (VngoRect *dest_rect,VngoTexture *img,dword fgcol,dword bgcol=VNGO_TRANSPARENT);

    void compress_last_list(){};

};

#endif          // __VNGVVP8_HPP

//ฐฑฒ End of module - vngvvp8.hpp ฒฑฐ

