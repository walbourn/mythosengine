//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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
#include "vnginlin.ipp"
#include "vngbd.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


class VngoVport : public VngoBaseDev
{

public:
    VngoVport() {};

    // virtual functions for drawing.
    virtual void pixel (VngoPoint *pt) = 0;
    virtual void line (VngoPoint *p1,VngoPoint *p2) = 0;
    virtual void gline (VngoPoint *p1,VngoPoint *p2) = 0;
    virtual void gline_persp (VngoPoint *p1,VngoPoint *p2) = 0;
    virtual void poly (int count,VngoPoint pts[]) = 0;
    virtual void gpoly (int count,VngoPoint pts[]) = 0;
    virtual void gpoly_persp (int count,VngoPoint pts[]) = 0;
    virtual void tpoly (int count,VngoPoint pts[],VngoTexture *tex) = 0;
    virtual void tpoly_persp (int count,VngoPoint pts[],VngoTexture *tex) = 0;
    virtual void gtpoly (int count,VngoPoint pts[],VngoTexture *tex) = 0;
    virtual void gtpoly_persp (int count,VngoPoint pts[],VngoTexture *tex) = 0;
   
    virtual void image_trans_mono (VngoRect *dest_rect,VngoTexture *img,dword fgcol,dword bgcol=VNGO_TRANSPARENT)=0;

};

class VngoVport8 : public VngoVport
{
public:
    VngoVport8() {};
    VngoVport8(long,long,long,long,VngoPal8 *,dword);
    virtual ~VngoVport8();

    virtual int init (long,long,long,long,VngoPal8 *,dword);

    // All of these functions will be virtuals eventualy.
    virtual void reset(dword c=0,dword farz=0xffffffff);


    virtual void vpcopy (int destx,int desty,VngoVport *dest);
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

};


// Function declarations.

extern VngoColor24bit vngo_get_pal(int index);

extern "C" {
extern void vngo_fill_pal_LUT(byte *pal15,byte *my_pal8);
extern void vngo_fill_y_table(VngoVbuffer *vbuf,int pix_size);
extern void vngo_fill_invert_table(dword *invert);
extern void vngo_std_mode(long mode);
extern int  vngo_std_getmode();
extern void vngo_vesa_mode(long mode);
extern int  vngo_vesa_getmode();

extern void vngo_set_pal(int index, VngoColor24bit color);
extern void vngo_line8(VngoVbuffer *vbuf,VngoPoint *p1,VngoPoint *p2);
extern void vngo_zline8(VngoVbuffer *vbuf,VngoPoint *p1,VngoPoint *p2);
extern void vngo_pixel8(VngoVbuffer *vbuf,VngoPoint *pt);
extern void vngo_zpixel8(VngoVbuffer *vbuf,VngoPoint *pt);
extern void vngo_rect8(VngoVbuffer *vbuf,VngoRect *rect, dword color);
extern void vngo_itrans8 (VngoVbuffer *vbuf,VngoRect *dest_rect, VngoTexture *img,dword flags);
extern void vngo_poly8 (VngoVbuffer *vbuf,int count,VngoPoint pts[]);
extern void vngo_zpoly8 (VngoVbuffer *vbuf,int count,VngoPoint pts[]);
extern void vngo_gpoly8 (VngoVbuffer *vbuf,int count,VngoPoint pts[]);
extern void vngo_gzpoly8 (VngoVbuffer *vbuf,int count,VngoPoint pts[]);
extern void vngo_tpoly8 (VngoVbuffer *vbuf,int count,VngoPoint pts[],VngoTexture *tex);
extern void vngo_tzpoly8 (VngoVbuffer *vbuf,int count,VngoPoint pts[],VngoTexture *tex);
extern void vngo_tgzpoly8 (VngoVbuffer *vbuf,int count,VngoPoint pts[],VngoTexture *tex);
}

#endif          // __VNGVP_HPP

//°±² End of module - vngvp.hpp ²±°

