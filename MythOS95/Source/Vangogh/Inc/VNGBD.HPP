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
#include "vnginlin.ipp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


class VngoBaseDev
{
public:
    VngoVbuffer         vbuff;
    VngoRectList        *damage_list;
    VngoRectList        *last_damage_list;
    dword               vflags;
    dword               old_mode;
    dword               size_in_bytes;
    int                 vzdepth_in_bits;
    vngo_error_codes    init_status;

                        
    virtual ~VngoBaseDev() 
    {
        //
        // This must be called twice to get this frame & last frame.
        //
        free_hot_rects();
        free_hot_rects();
    }

    // Inline functions.
    inline VngoVbuffer *get_vbuff() {return &vbuff;}
    inline void zbuffer_on() {vflags |= VNGO_ZBUFFER_ACTIVE;}
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
    inline vngo_error_codes get_init_state() {return (init_status);}

    // Virtual funcitons for drawing.
    virtual void reset(dword c=0,dword farz=0xffffffff)=0;
    virtual void vpcopy (int destx,int desty,VngoBaseDev *dest)=0;
    virtual void frect (VngoRect *rect,dword color) = 0;

    // virtual functions for transfering data directly to the vport.
    virtual void image_trans (VngoRect *dest_rect,VngoTexture *img,dword flags=0) = 0;

    // Buffering syncronization call.  (if a BaseDev or ViewPort wants to 
    // buffer output for self sorting etc then it can queue thing up until
    // the sync call is made at which time all buffered commands must be made.)

    virtual void sync() {};

    // Hot rect managment routines.
   
    virtual void add_hot_rect(VngoRectList *new_rect) 
    {
        new_rect->next = damage_list;
        damage_list = new_rect;
    };

    virtual void free_hot_rects()
    {
        VngoRectList *t;
        while (last_damage_list != NULL)
        {
            t = last_damage_list->next;
            delete (last_damage_list);
            last_damage_list = t;
        }
        last_damage_list = damage_list;
        damage_list = NULL;
    }

};


#endif          // __VNGBD_HPP

//°±² End of module - vngbd.hpp ²±°

