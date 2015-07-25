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
// vgvpdd16.cpp
//
//     The C pluss pluss 8bpp view port classes for Direct Draw.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <string.h>
#include <assert.h>
#include <ddraw.h>
#include "debug.h"
#include "portable.h"
#include "ivory.h"
#include "vangogh.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define MIN(a,b)  ((a) < (b)) ? (a) : (b)

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
// This is the constructor of the VngoVport8 class.  It initializes all of  ³
// the data needed to draw into an 8bit device.                             ³
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                                                                          ³
// This is the Virtual View Port stuff.                                     ³
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ


VngoVportDD16::VngoVportDD16 (VngoSurfaceManager *_pddsurf,
                              VngoSurfaceManager *zbptr,
                              VngoPal *my_pal,dword flags)

{
    lock_status = _pddsurf->get_lock_status();
    ZeroMemory (&ddsd,sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    init_status = init ( _pddsurf, zbptr,my_pal,flags);
}

VNGError VngoVportDD16::init (VngoSurfaceManager *_pddsurf,
                              VngoSurfaceManager *zbptr,
                              VngoPal *my_pal,dword flags)
{
    persp_pixcount = VNGO_PERSP_PRECISION;
    vp_offset = 0;
    zp_offset = 0;
    vflags = flags;
    vflags |= VNGO_PAL_MAPPED_DEV;
    vbuff.zbuff_ptr = NULL;

    surf_stat = _pddsurf;
    pddsurf = _pddsurf->ddsurf;


// Doing this lock fills in some needed information.
    int was_locked = lock();
    if (was_locked == -1)
        return (VNGO_INTERNAL_ERROR);

    if (!was_locked)
        unlock();

    vbuff.width = ddsd.dwWidth;
    vbuff.height = ddsd.dwHeight;
//    vbuff.pitch = ddsd.lPitch;
    size_in_bytes = (vbuff.width * vbuff.height * 2);

    vp_rect.x = 0;
    vp_rect.y = 0;
    vp_rect.dx = vbuff.width;
    vp_rect.dy = vbuff.height;

    if (vflags & VNGO_ZBUFFER_DEV)
    {
        // if we don't have a ddraw surface to use
        // as the ZBuffer then allocate one.
        if (surf_stat->zddsurf == NULL)
        {
            vzdepth_in_bits = 16;
            int z_size_shift = vzdepth_in_bits >> 4;
            if (vbuff.zbuff_ptr == NULL)
            {
                vbuff.zbuff_ptr = (word *)ivory_alloc(size_in_bytes << z_size_shift);
                vbuff.zpitch = vbuff.width << 1;
                vflags |= VNGO_MYMEM_ZBUFF;
            }
            if (!vbuff.zbuff_ptr)
            {
                return (VNGO_MEMALLOC_ERROR);
            }
            assert(vbuff.zbuff_ptr != 0);
        }
        else
        {
            zp_offset = 0;
        }

        vflags |= VNGO_ZBUFFER_ACTIVE;
    }

    // allocate all tables.

    vbuff.ytable = (dword *)ivory_alloc(vbuff.height * sizeof(dword));
    if (!vbuff.ytable)
    {
        if ((vflags & VNGO_ZBUFFER_DEV) && (vflags & VNGO_MYMEM_ZBUFF))
        {
            ivory_free((void **)&(vbuff.zbuff_ptr));
        }
        return (VNGO_MEMALLOC_ERROR);
    }
    if (vflags & VNGO_ZBUFFER_DEV)
    {
        vbuff.ztable = (dword *)ivory_alloc(vbuff.height * sizeof(dword));
        if (!vbuff.ztable)
        {
            if ((vflags & VNGO_ZBUFFER_DEV) && (vflags & VNGO_MYMEM_ZBUFF))
            {
                ivory_free((void **)&(vbuff.zbuff_ptr));
            }
            ivory_free((void **)&(vbuff.ytable));
            return (VNGO_MEMALLOC_ERROR);
        }
    }
    long max_dem = vbuff.width;
    if (vbuff.height > vbuff.width)
        max_dem = vbuff.height;

    vbuff.edge1 = (VngoPoint2 *)ivory_alloc(max_dem * sizeof(VngoPoint2));
    if (vbuff.edge1 == NULL)
    {
        if(vflags & VNGO_ZBUFFER_DEV)
        {
            ivory_free((void **)&(vbuff.zbuff_ptr));
            ivory_free((void **)&(vbuff.ztable));
        }
        ivory_free((void**)&(vbuff.ytable));
        return (VNGO_MEMALLOC_ERROR);
    }

    vbuff.edge2 = (VngoPoint2 *)ivory_alloc(max_dem * sizeof(VngoPoint2));
    if (vbuff.edge2 == NULL)
    {
        if(vflags & VNGO_ZBUFFER_DEV)
        {
            ivory_free((void **)&(vbuff.zbuff_ptr));
            ivory_free((void **)&(vbuff.ztable));
        }
        ivory_free((void**)&(vbuff.ytable));
        ivory_free((void**)&(vbuff.edge1));
        return (VNGO_MEMALLOC_ERROR);
    }



    if (my_pal)
    {
        vbuff.pal = my_pal;
    }
    else
    {
        // here you will normaly build a new default palette.
        vbuff.pal = NULL;
    }

    // Fill all tables.
    vbuff.ytable[0] = 0;
    if (vflags & VNGO_ZBUFFER_DEV)
        vbuff.ztable[0] = 0;

    for (int i=1; i < vbuff.height; i++)
    {
        vbuff.ytable[i] = vbuff.ytable[i-1] + vbuff.pitch;
        if (vflags & VNGO_ZBUFFER_DEV)
            vbuff.ztable[i] = vbuff.ztable[i-1] + vbuff.zpitch;
    }

    if (!(vflags & VNGO_INIT_NO_RESET))
    {
        was_locked = lock();
        if (was_locked != -1)
        {
            reset();
            if (!was_locked)
                unlock();
        }
    }

    return (VNGO_NO_ERROR);
}





VngoVportDD16::VngoVportDD16 (VngoSurfaceManager *_pddsurf, VngoSurfaceManager *zbptr,
                            VngoRect &srect, VngoPal *my_pal,dword flags)
{
    lock_status = _pddsurf->get_lock_status();
    ZeroMemory(&ddsd,sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    init_status = init ( _pddsurf, zbptr, srect, my_pal, flags);
}

VNGError VngoVportDD16::init (VngoSurfaceManager *_pddsurf,
                             VngoSurfaceManager *zbptr,
                             VngoRect &srect, VngoPal *my_pal,dword flags)
{
    persp_pixcount = VNGO_PERSP_PRECISION;
    vflags = flags;
    vflags |= VNGO_PAL_MAPPED_DEV;
    vbuff.zbuff_ptr = NULL;

    surf_stat = _pddsurf;
    pddsurf = _pddsurf->ddsurf;

    int was_locked = lock();
    if (was_locked == -1)
        return (VNGO_INTERNAL_ERROR);


    if (!was_locked)
        unlock();

    vbuff.width = srect.dx;
    vbuff.height = srect.dy;

    size_in_bytes = (vbuff.width * vbuff.height * 2);

    vp_offset = (srect.y * vbuff.pitch) + (srect.x * 2);
    vp_rect = srect;

    // if we don't have a ddraw surface to use as the ZBUFFER then allocate one.
    if (vflags & VNGO_ZBUFFER_DEV)
    {
        if (surf_stat->zddsurf == NULL)
        {
            vzdepth_in_bits = 16;
            int z_size_shift = vzdepth_in_bits >> 4;
            if (vbuff.zbuff_ptr == NULL)
            {
                vbuff.zbuff_ptr = (word *)ivory_alloc(size_in_bytes << z_size_shift);
                vbuff.zpitch = vbuff.width << 1;
                vflags |= VNGO_MYMEM_ZBUFF;
            }
            if (!vbuff.zbuff_ptr)
            {
                return (VNGO_MEMALLOC_ERROR);
            }
            assert(vbuff.zbuff_ptr != 0);
        }
        else
        {
            zp_offset = (srect.y * vbuff.zpitch) + (srect.x * 2);
        }
        vflags |= VNGO_ZBUFFER_ACTIVE;
    }

    // allocate all tables.

    vbuff.ytable = (dword *)ivory_alloc(vbuff.height * sizeof(dword));
    if (!vbuff.ytable)
    {
        if ((vflags & VNGO_ZBUFFER_DEV) && (vflags & VNGO_MYMEM_ZBUFF))
        {
            ivory_free((void **)&(vbuff.zbuff_ptr));
        }
        return (VNGO_MEMALLOC_ERROR);
    }
    if (vflags & VNGO_ZBUFFER_DEV)
    {
        vbuff.ztable = (dword *)ivory_alloc(vbuff.height * sizeof(dword));
        if (!vbuff.ztable)
        {
            if ((vflags & VNGO_ZBUFFER_DEV) && (vflags & VNGO_MYMEM_ZBUFF))
            {
                ivory_free((void **)&(vbuff.zbuff_ptr));
            }
            ivory_free((void **)&(vbuff.ytable));
            return (VNGO_MEMALLOC_ERROR);
        }
    }
    long max_dem = vbuff.width;
    if (vbuff.height > vbuff.width)
        max_dem = vbuff.height;

    vbuff.edge1 = (VngoPoint2*)ivory_alloc(max_dem * sizeof(VngoPoint2));
    if (vbuff.edge1 == NULL)
    {
        if(vflags & VNGO_ZBUFFER_DEV)
        {
            ivory_free((void **)&(vbuff.zbuff_ptr));
            ivory_free((void **)&(vbuff.ztable));
        }
        ivory_free((void**)&(vbuff.ytable));
        return (VNGO_MEMALLOC_ERROR);
    }

    vbuff.edge2 = (VngoPoint2*)ivory_alloc(max_dem * sizeof(VngoPoint2));
    if (vbuff.edge2 == NULL)
    {
        if(vflags & VNGO_ZBUFFER_DEV)
        {
            ivory_free((void **)&(vbuff.zbuff_ptr));
            ivory_free((void **)&(vbuff.ztable));
        }
        ivory_free((void**)&(vbuff.ytable));
        ivory_free((void**)&(vbuff.edge1));
        return (VNGO_MEMALLOC_ERROR);
    }


    if (my_pal)
    {
        vbuff.pal = my_pal;
    }
    else
    {
        // here you will normaly build a new default palette.
        vbuff.pal = NULL;
    }

    // Fill all tables.
    vbuff.ytable[0] = 0;
    if (vflags & VNGO_ZBUFFER_DEV)
        vbuff.ztable[0] = 0;

    for (int i=1; i < vbuff.height; i++)
    {
        vbuff.ytable[i] = vbuff.ytable[i-1] + vbuff.pitch;
        if (vflags & VNGO_ZBUFFER_DEV)
            vbuff.ztable[i] = vbuff.ztable[i-1] + vbuff.zpitch;
    }

    if (!(vflags & VNGO_INIT_NO_RESET))
    {
        int was_locked = lock();
        if (was_locked != -1)
        {
            reset();
            if (!was_locked)
                unlock();
        }
    }
    return (VNGO_NO_ERROR);
}

int VngoVportDD16::lock()
{
    int fail_safe=0;
    int ret_val = surf_stat->lock();
    if (ret_val != 1)
    {
        int locked=0;
        HRESULT hr;
        while (!locked && (fail_safe < 1000))
        {
            fail_safe++;    // just so we can't loop infinately.
            if ((hr = pddsurf->Lock (NULL, &ddsd,
                                     DDLOCK_SURFACEMEMORYPTR
                                     | DDLOCK_WAIT, NULL)) == DD_OK)
            {
                vbuff.pitch = ddsd.lPitch;
                vbuff.scrn_ptr = (byte *) ((dword)ddsd.lpSurface + vp_offset);
                locked = 1;
            }
            if (hr == DDERR_SURFACELOST)
            {
                hr = pddsurf->Restore();
                if (hr != DD_OK)
                    locked = 1; // an error occured while
                                // restoring the surface, so it cannot be locked.
            }
        }

        if (hr != DD_OK)
        {
            surf_stat->unlock();
            return (-1);        // failure to lock;
        }

#if 0
        // Now do the zbuffer if needed.
        if (surf_stat->zddsurf)
        {
            locked = 0;
            fail_safe = 0;
            while (!locked && (fail_safe < 1000))
            {
                fail_safe++;    // just so we can't loop infinately.
                if ((hr = surf_stat->zddsurf->Lock (NULL, &ddsd,
                                                    DDLOCK_SURFACEMEMORYPTR
                                                    | DDLOCK_WAIT, NULL)) == DD_OK)
                {
                    vbuff.zpitch = ddsd.lPitch;
                    vbuff.zbuff_ptr = (word *) ((dword)ddsd.lpSurface + zp_offset);
                    locked = 1;
                }
                if (hr == DDERR_SURFACELOST)
                {
                    hr = surf_stat->zddsurf->Restore();
                    if (hr != DD_OK)
                        locked = 1; // an error occured while
                                    // restoring the surface, so it cannot be locked.
                }
            }

            if (hr != DD_OK)
            {
                surf_stat->unlock();
                return (-1);        // failure to lock;
            }
        }
#endif
    }

    lock_status = 1;
    return(ret_val);
}


int VngoVportDD16::unlock()
{
    vbuff.scrn_ptr = NULL;

    int ret_val= surf_stat->unlock();
    if (ret_val != 0)
    {
        pddsurf->Unlock( NULL );
        if (surf_stat->zddsurf)
        {
            surf_stat->zddsurf->Unlock( NULL );
            vbuff.zbuff_ptr = NULL;
        }
    }
    lock_status = 0;

    return (ret_val);
}

VNGError VngoVportDD16::clip_frect(VngoRect *rect,VngoColor24bit *rgb_val, VngoRect *clip)
{
    VngoRect trect = *rect;
    VngoRect vprect(0,0,vbuff.width,vbuff.height);

    if (clip)
    {
        if (trect.clip_to(*clip) == VNGO_FULLY_CLIPPED)
            return VNGO_NO_ERROR;
    }

    if (trect.clip_to(vprect) == VNGO_FULLY_CLIPPED)
        return VNGO_NO_ERROR;

    int t;
    t = unlock();

    RECT    wtrect;
    DDBLTFX ddbltfx;
    wtrect.left = trect.x + vp_rect.x;
    wtrect.right = wtrect.left + trect.dx;
    wtrect.top = trect.y + vp_rect.y;
    wtrect.bottom = wtrect.top + trect.dy;

    ddbltfx.dwSize = sizeof(ddbltfx);
    if (vbuff.pal->flags & VNGO_15BIT)
        ddbltfx.dwFillColor = rgb_val->compress();
    else
        ddbltfx.dwFillColor = rgb_val->compress16();

    pddsurf->Blt( &wtrect, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);

    if (t)
        lock();
    return VNGO_NO_ERROR;
}


VNGError VngoVportDD16::clip_frect(VngoRect *rect,dword color, VngoRect *clip)
{
    VngoColor24bit tclr = vbuff.pal->get_RGB(color);
    return clip_frect(rect,&tclr,clip);

}


VNGError VngoVportDD16::frect(VngoRect *rect,VngoColor24bit *rgb_val)
{
    VngoRect trect = *rect;
    VngoRect vprect(0,0,vbuff.width,vbuff.height);

    int t;
    t = unlock();

    RECT    wtrect;
    DDBLTFX ddbltfx;
    wtrect.left = trect.x + vp_rect.x;
    wtrect.right = wtrect.left + trect.dx;
    wtrect.top = trect.y + vp_rect.y;
    wtrect.bottom = wtrect.top + trect.dy;

    ddbltfx.dwSize = sizeof(ddbltfx);
    if (vbuff.pal->flags & VNGO_15BIT)
        ddbltfx.dwFillColor = rgb_val->compress();
    else
        ddbltfx.dwFillColor = rgb_val->compress16();

    pddsurf->Blt( &wtrect, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);

    if (t)
        lock();
    return VNGO_NO_ERROR;
}


VNGError VngoVportDD16::frect(VngoRect *rect,dword color)
{
    VngoColor24bit tclr = vbuff.pal->get_RGB(color);
    return frect(rect,&tclr);
}

void VngoVportDD16::reset(dword c,dword farz)
{
    dword           t;
    VngoRect        trect;

    trect.x = trect.y = 0;
    trect.dx = vbuff.width;
    trect.dy = vbuff.height;

    if (!(vflags & VNGO_NOCLEAR_VBUFFER))
    {
        if (zmap && 0)
        {
            assert(zmap->zmap.flags & VNGO_TEXTURE_ZMAP);
            assert(zmap->zmap.flags & VNGO_TEXTURE_MONO);
            image_trans_mono (&trect,&zmap->zmap ,c,zmap->color);
        }
        else
        {
            frect(&trect,c);
        }
    }

    if (vflags & VNGO_ZBUFFER_ACTIVE)
    {
        if (vzdepth_in_bits == 32)
        {
            return; // no longer supported.
        }
        else if (vzdepth_in_bits == 16)
        {

            t = farz & 0xffff0000;
            t |= ((farz & 0xffff0000) >> 16);

            if (zmap)
            {
                assert(zmap->zmap.flags & VNGO_TEXTURE_ZMAP);
                assert(zmap->zmap.flags & VNGO_TEXTURE_MONO);
                zblit_mono (&trect,zmap,t,zmap->depth);
            }
            else
            {
                if (surf_stat->zddsurf)
                {
                    int was_locked = unlock();

                    HRESULT         ddrval;
                    DDBLTFX         ddbltfx;
                    RECT            destRect;
                    // Use direct draw to clear the screen.

                    memset(&ddbltfx, 0,sizeof(ddbltfx));
                    ddbltfx.dwSize = sizeof(ddbltfx);
                    ddbltfx.dwFillColor = 0xffff;

                    destRect.left   = vp_rect.x;
                    destRect.top    = vp_rect.y;
                    destRect.right  = vp_rect.x + vbuff.width;
                    destRect.bottom = vp_rect.y + vbuff.height;

                    int try1=0;
                    do
                    {
                        ddrval = surf_stat->zddsurf->Blt( &destRect,
                                                          NULL, NULL,
                                                          DDBLT_COLORFILL | DDBLT_WAIT,
                                                          &ddbltfx );

                        if( ddrval == DDERR_SURFACELOST ) {
                            ddrval = surf_stat->zddsurf->Restore();
                        }
                        try1++;

                    } while((ddrval != DD_OK) && (try1 < 150));
                    if (was_locked)
                        lock();

                }
                else
                    zbuff_reset_rect16(&vbuff,&trect,t);

            }
        }
    }
}


VngoVportDD16::~VngoVportDD16()
{
    vbuff.scrn_ptr = NULL;
    if ((vflags & VNGO_ZBUFFER_DEV) && (vflags & VNGO_MYMEM_ZBUFF))
    {
        if (vbuff.zbuff_ptr)
        {
            ivory_free((void **)&(vbuff.zbuff_ptr));
        }
    }
    vbuff.zbuff_ptr = NULL;
    if (vbuff.ytable)
    {
        ivory_free((void **)&(vbuff.ytable));
    }
    if (vbuff.ztable && vflags & VNGO_ZBUFFER_DEV)
    {
        ivory_free((void **)&(vbuff.ztable));
    }
    if (vbuff.edge1)
    {
        ivory_free((void **)&(vbuff.edge1));
    }
    if (vbuff.edge2)
    {
        ivory_free((void **)&(vbuff.edge2));
    }

}


VNGError VngoVportDD16::pixel (VngoPoint *pt, VngoColor24bit *rgb_val)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::pixel(pt,rgb_val);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::pixel (VngoPointF *pt, VngoColor24bit *rgb_val)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::pixel(pt,rgb_val);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::clip_pixel (VngoPoint *pt, VngoColor24bit *rgb_val,
                                  VngoRect *clip_rect)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::clip_pixel(pt,rgb_val,clip_rect);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::clip_pixel (VngoPointF *pt, VngoColor24bit *rgb_val,
                                  VngoRect *clip_rect)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::clip_pixel(pt,rgb_val,clip_rect);
        if (!was_locked)
            unlock();
    }
    return retval;
}

dword VngoVportDD16::read_pixel (VngoPoint *pt, VngoPoint *dest)
{
    int was_locked = lock();
    dword retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::read_pixel(pt,dest);
        if (!was_locked)
            unlock();
    }
    return retval;
}

dword VngoVportDD16::read_pixel (int x, int y, VngoPoint *dest)
{
    int was_locked = lock();
    dword retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::read_pixel(x,y,dest);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::line (VngoPoint *p1, VngoPoint *p2,
                             VngoColor24bit *rgb_val)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::line(p1,p2,rgb_val);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::line (VngoPointF *p1, VngoPointF *p2,
                             VngoColor24bit *rgb_val)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::line(p1,p2,rgb_val);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::gline (VngoPoint *p1, VngoPoint *p2)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gline(p1,p2);
        if (!was_locked)
            unlock();
    }
    return retval;
}
VNGError VngoVportDD16::gline (VngoPointF *p1, VngoPointF *p2)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gline(p1,p2);
        if (!was_locked)
            unlock();
    }
    return retval;
}
VNGError VngoVportDD16::clip_line (VngoPoint *p1, VngoPoint *p2,
                                  VngoColor24bit *rgb_val,
                                  VngoRect *clip_rect)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::clip_line(p1,p2,rgb_val,clip_rect);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::clip_line (VngoPointF *p1, VngoPointF *p2,
                                  VngoColor24bit *rgb_val,
                                  VngoRect *clip_rect)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::clip_line(p1,p2,rgb_val,clip_rect);
        if (!was_locked)
            unlock();
    }
    return retval;
}
VNGError VngoVportDD16::clip_gline (VngoPoint *p1, VngoPoint *p2,
                                  VngoRect *clip_rect)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::clip_gline(p1,p2,clip_rect);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::clip_gline (VngoPointF *p1, VngoPointF *p2,
                                  VngoRect *clip_rect)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::clip_gline(p1,p2,clip_rect);
        if (!was_locked)
            unlock();
    }
    return retval;
}


VNGError VngoVportDD16::poly (int count, VngoPoint pts[])
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::poly(count,pts);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::poly (int count, VngoPointF pts[])
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::poly(count,pts);
        if (!was_locked)
            unlock();
    }
    return retval;
}
VNGError VngoVportDD16::gpoly (int count, VngoPoint pts[])
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gpoly(count,pts);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::gpoly (int count, VngoPointF pts[])
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gpoly(count,pts);
        if (!was_locked)
            unlock();
    }
    return retval;
}
VNGError VngoVportDD16::gpoly_persp (int count, VngoPoint pts[])
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gpoly(count,pts);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::gpoly_persp (int count, VngoPointF pts[])
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gpoly(count,pts);
        if (!was_locked)
            unlock();
    }
    return retval;
}


VNGError VngoVportDD16::tpoly (int count, VngoPoint pts[],VngoTexture *tex)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::tpoly(count,pts,tex);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::tpoly (int count, VngoPointF pts[],VngoTexture *tex)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::tpoly(count,pts,tex);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::tpoly_persp (int count, VngoPoint pts[],VngoTexture *tex)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::tpoly_persp(count,pts,tex);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::tpoly_persp (int count, VngoPointF pts[],VngoTexture *tex)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::tpoly_persp(count,pts,tex);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::gtpoly (int count, VngoPoint pts[],VngoTexture *tex)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gtpoly(count,pts,tex);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::gtpoly (int count, VngoPointF pts[],VngoTexture *tex)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gtpoly(count,pts,tex);
        if (!was_locked)
            unlock();
    }
    return retval;
}


VNGError VngoVportDD16::gtpoly_persp (int count, VngoPoint pts[],VngoTexture *tex)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gtpoly_persp(count,pts,tex);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::gtpoly_persp (int count, VngoPointF pts[],VngoTexture *tex)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gtpoly_persp(count,pts,tex);
        if (!was_locked)
            unlock();
    }
    return retval;
}
VNGError VngoVportDD16::grpoly (int count,VngoPoint pts[])
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::grpoly(count,pts);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::grpoly (int count,VngoPointF pts[])
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::grpoly(count,pts);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::poly_a (int count, VngoPoint pts[],long alpha)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::poly_a(count,pts,alpha);
        if (!was_locked)
            unlock();
    }
    return retval;
}
VNGError VngoVportDD16::poly_a (int count, VngoPointF pts[],long alpha)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::poly_a(count,pts,alpha);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::gpoly_a (int count, VngoPoint pts[],long alpha)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gpoly_a(count,pts,alpha);
        if (!was_locked)
            unlock();
    }
    return retval;
}
VNGError VngoVportDD16::gpoly_a (int count, VngoPointF pts[],long alpha)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gpoly_a(count,pts,alpha);
        if (!was_locked)
            unlock();
    }
    return retval;
}
VNGError VngoVportDD16::gpoly_persp_a (int count, VngoPoint pts[],long alpha)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gpoly_persp_a(count,pts,alpha);
        if (!was_locked)
            unlock();
    }
    return retval;
}
VNGError VngoVportDD16::gpoly_persp_a (int count, VngoPointF pts[],long alpha)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gpoly_persp_a(count,pts,alpha);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::tpoly_a (int count, VngoPoint pts[],VngoTexture *tex,long alpha)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::tpoly_a(count,pts,tex,alpha);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::tpoly_a (int count, VngoPointF pts[],VngoTexture *tex,long alpha)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::tpoly_a(count,pts,tex,alpha);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::tpoly_persp_a (int count, VngoPoint pts[],VngoTexture *tex,long alpha)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::tpoly_persp_a(count,pts,tex,alpha);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::tpoly_persp_a (int count, VngoPointF pts[],VngoTexture *tex,long alpha)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::tpoly_persp_a(count,pts,tex,alpha);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::gtpoly_a (int count, VngoPoint pts[],VngoTexture *tex,long alpha)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gtpoly_a(count,pts,tex,alpha);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::gtpoly_a (int count, VngoPointF pts[],VngoTexture *tex,long alpha)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gtpoly_a(count,pts,tex,alpha);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::gtpoly_persp_a (int count, VngoPoint pts[],VngoTexture *tex,long alpha)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gtpoly_persp_a(count,pts,tex,alpha);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::gtpoly_persp_a (int count, VngoPointF pts[],VngoTexture *tex,long alpha)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::gtpoly_persp_a(count,pts,tex,alpha);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::image_trans (VngoRect *dest_rect,VngoTexture *img,dword flags)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::image_trans(dest_rect,img,flags);
        if (!was_locked)
            unlock();
    }
    return retval;
}

#if 0
VNGError VngoVportDD16::image_trans_s (VngoRect *dest_rect,VngoTexture *img,dword shade,dword flags)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::image_trans_s(dest_rect,img,shade,flags);
        if (!was_locked)
            unlock();
    }
    return retval;
}
VNGError VngoVportDD16::image_trans_z (VngoRect *dest_rect,VngoTexture *img,dword depth,dword flags)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::image_trans_z(dest_rect,img,depth,flags);
        if (!was_locked)
            unlock();
    }
    return retval;
}
VNGError VngoVportDD16::image_trans_zs (VngoRect *dest_rect,VngoTexture *img,dword depth,dword shade,dword flags)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::image_trans_zs(dest_rect,img,depth,shade,flags);
        if (!was_locked)
            unlock();
    }
    return retval;
}
#endif

VNGError VngoVportDD16::image_trans_mono (VngoRect *dest_rect,VngoTexture *img,
                                         dword fgcol,dword bgcol)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VNGO_NOT_SUPPORTED;
        retval = VngoVVport16::image_trans_mono(dest_rect,img,fgcol,bgcol);
        if (!was_locked)
            unlock();
    }
    return retval;
}

VNGError VngoVportDD16::zblit_mono (VngoRect *dest_rect,VngoZMap *zmp,
                                   dword fdist,dword ndist)
{
    int was_locked = lock();
    VNGError retval = VNGO_INTERNAL_ERROR;
    if (was_locked != -1)
    {
        retval = VngoVVport16::zblit_mono(dest_rect,zmp,fdist,ndist);
        if (!was_locked)
            unlock();
    }
    return retval;
}

//°±² End of module - vngvpDD16.cpp ²±°
