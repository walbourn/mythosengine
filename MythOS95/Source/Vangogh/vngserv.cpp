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
// vngserv.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <assert.h>
#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern VngoSystem VgSystem;
STATIC  dword invert_table[2048];

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

dword * vngo_get_invert()
{
    static  needs_init = 1;

    if (needs_init)
    {
        invert_table[0] = 1;
        for (int i=1;i < 2048;i++)
        {
            dword t;
            _asm {
                mov     eax,080000000h
                xor     edx,edx
                div     i
                shr     eax,1
                adc     eax,0
                mov     t,eax
            }
            invert_table[i] = t;        // 1 in 16.16 divided by i gives a value
                                        // to multiply by to get an effective
                                        // divide by i in 16.16.
        }
        needs_init=0;
    }
    return (&invert_table[0]);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  clip_to
//      Clip the rect to the passed in rectangle.  It will return the
//      resulting rectangle.  If the rect is completely clipped, it will
//      return a rectangle with all elements = 0.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VNGError VngoRect::clip_to(VngoRect &crect)
{
    VngoRect trect = *this;
    if ((trect.x >= crect.x + crect.dx) ||
        (trect.x + trect.dx < crect.x) ||
        (trect.y >= crect.y + crect.dy) ||
        (trect.y + trect.dy < crect.y))
    {
        return (VNGO_FULLY_CLIPPED);
    }
    if (trect.x < crect.x)
    {
        int t = crect.x - trect.x;
        if (trect.dx > t)
            trect.dx -= t;
        else
        {
            return (VNGO_FULLY_CLIPPED);
        }
        trect.x = crect.x;
    }
    if (trect.y < crect.y)
    {
        int t = crect.y - trect.y;
        if (trect.dy > t)
            trect.dy -= t;
        else
        {
            return (VNGO_FULLY_CLIPPED);
        }
        trect.y = crect.y;
    }
    if ((trect.x + trect.dx) > (crect.x + crect.dx))
    {
        trect.dx = (crect.x + crect.dx) - trect.x;
    }
    if ((trect.y + trect.dy) > (crect.y + crect.dy))
    {
        trect.dy = (crect.y + crect.dy) - trect.y;
    }
    *this = trect;
    return (VNGO_NO_ERROR);
}


VngoTexture::~VngoTexture()
{
    VngoTexture3D   *tptr = vtex3d;
    while(tptr)
    {
        VngoTexture3D   *temp = tptr->next;
        delete (tptr);
        tptr = temp;
    }
}

VngoCTexture::VngoCTexture (VngoTexture *_tex)
{
    ytable = NULL;
    init(_tex);
}

VNGError VngoCTexture::init(VngoTexture *_tex)
{
    if (_tex->flags & VNGO_TEXTURE_8BIT)
    {

        short   lcount = 0;
        long    hsize=0;

        byte    *tsource = (byte*)_tex->tex;
        width = _tex->width;
        height = _tex->height;
        flags = _tex->flags;
        ytable = new dword [height+1];

        if (ytable == NULL)
        {
            return VNGO_MEMORY_ERROR;
        }
        for (int j=0;j < height;j++)
        {
            if (j==0)
                ytable[j] = 0;
            else
                ytable[j] = ytable[j-1] + hsize;

            hsize = 0;
            for (int i=0;i < width;)
            {
                hsize+=2;
                while((tsource[(j*width)+i] != VNGO_TRANSPARENT_COLOR) && i < width)
                {
                    i++;
                    hsize++;
                }
                hsize+=2;
                while((tsource[(j*width)+i] == VNGO_TRANSPARENT_COLOR) && i < width)
                {
                    i++;
                }
            }
        }
        long    tsize=ytable[j-1] + hsize;
        tex = new byte[tsize];

        if (tex == NULL)
            return VNGO_MEMORY_ERROR;

        for (j=0;j < height;j++)
        {
            byte *ptr = (byte*)tex + ytable[j];
            for (int i=0;i < width;)
            {
                word *cptr = (word *)ptr;
                ptr += 2;
                lcount = 0;
                while((tsource[(j*width)+i] != VNGO_TRANSPARENT_COLOR) && i < width)
                {
                    *ptr=tsource[(j*width)+i];
                    lcount++;
                    i++;
                    ptr++;
                }
                *cptr = lcount;
                cptr = (word *)ptr;
                ptr += 2;
                lcount = 0;
                while((tsource[(j*width)+i] == VNGO_TRANSPARENT_COLOR) && i < width)
                {
                    lcount++;
                    i++;
                }
                *cptr = lcount;
            }
        }
        flags |= VNGO_TEXTURE_COMPRESSED;
        return VNGO_NO_ERROR;
    }
    else if (_tex->flags & VNGO_TEXTURE_15BIT
             || _tex->flags & VNGO_TEXTURE_16BIT)
    {

        word    *tsource = (word*)_tex->tex;
        short   lcount = 0;
        long    hsize=0;

        width = _tex->width;
        height = _tex->height;
        flags = _tex->flags;
        ytable = new dword [height+1];

        if (ytable == NULL)
        {
            return VNGO_MEMORY_ERROR;
        }
        for (int j=0;j < height;j++)
        {
            if (j==0)
                ytable[j] = 0;
            else
                ytable[j] = ytable[j-1] + (hsize << 1);

            hsize = 0;
            for (int i=0;i < width;)
            {
                hsize++;
                if (_tex->flags & VNGO_TEXTURE_15BIT)
                { // 0x7c1f is the transparent color for 15bpp.
                    while((tsource[(j*width)+i] != 0x7c1f) && i < width)
                    {
                        i++;
                        hsize++;
                    }
                    hsize++;
                    while((tsource[(j*width)+i] == 0x7c1f) && i < width)
                    {
                        i++;
                    }
                }
                else
                { // 0xf81f is the transparent color for 16bpp.
                    while((tsource[(j*width)+i] != 0xf81f) && i < width)
                    {
                        i++;
                        hsize++;
                    }
                    hsize++;
                    while((tsource[(j*width)+i] == 0xf81f) && i < width)
                    {
                        i++;
                    }
                }
            }
        }
        long    tsize=ytable[j-1] + (hsize << 1);
        tex = new byte[tsize];

        if (tex == NULL)
            return VNGO_MEMORY_ERROR;

        for (j=0;j < height;j++)
        {
            word *ptr = (word*)((byte*)tex + ytable[j]);
            for (int i=0;i < width;)
            {
                if (_tex->flags & VNGO_TEXTURE_15BIT)
                { // 0x7c1f is the transparent color for 15bpp.
                    word *cptr = ptr;
                    ptr++;
                    lcount = 0;
                    while((tsource[(j*width)+i] != 0x7c1f) && i < width)
                    {
                        *ptr=tsource[(j*width)+i];
                        lcount++;
                        i++;
                        ptr++;
                    }
                    *cptr = lcount;
                    cptr = ptr;
                    ptr++;
                    lcount = 0;
                    while((tsource[(j*width)+i] == 0x7c1f) && i < width)
                    {
                        lcount++;
                        i++;
                    }
                    *cptr = lcount;
                }
                else
                { // 0xf81f is the transparent color for 16bpp.
                    word *cptr = ptr;
                    ptr++;
                    lcount = 0;
                    while((tsource[(j*width)+i] != 0xf81f) && i < width)
                    {
                        *ptr=tsource[(j*width)+i];
                        lcount++;
                        i++;
                        ptr++;
                    }
                    *cptr = lcount;
                    cptr = (word *)ptr;
                    ptr++;
                    lcount = 0;
                    while((tsource[(j*width)+i] == 0xf81f) && i < width)
                    {
                        lcount++;
                        i++;
                    }
                    *cptr = lcount;
                }
            }
        }
        flags |= VNGO_TEXTURE_COMPRESSED;
        return VNGO_NO_ERROR;
    }
    return VNGO_UNSUPPORTED_TEXTURE;
}

void VngoCTexture::release()
{
    if (tex)
        delete tex;
    if (ytable)
        delete ytable;
}


VngoMemTexture3D::VngoMemTexture3D(VngoTexture *_src,VngoPal *_pal)
{
    dev_type = VNGO_MEM_TEX;
    err_status = init(_src,_pal);
}

VngoMemTexture3D::~VngoMemTexture3D()
{
    release();
}

VNGError VngoMemTexture3D::init(VngoTexture *_src,VngoPal *_pal)
{
    palette = _pal;
    ref = _src;
    vtxt = _src;
    switch (_src->width)
    {
        case    32:
            widthshift     = 5;
            u_upshift      = 11;
            break;
        case    64:
            widthshift     = 6;
            u_upshift      = 10;
            break;
        case    128:
            widthshift     = 7;
            u_upshift      = 9;
            break;
        case    256:
            widthshift     = 8;
            u_upshift      = 8;
            break;
        case    16:
            widthshift     = 4;
            u_upshift      = 12;
            break;
        default:
            // Could also at this point create a texture of the closest
            // supported size and resample source into it.
            return (VNGO_UNSUPPORTED_TEXTURE);
    }
    u_downshift    = 32 - widthshift;

    switch (_src->height)
    {
        case    32:
            heightshift    = 5;
            v_upshift      = 11;
            v_downshift    = 27;
            break;
        case    64:
            heightshift    = 6;
            v_upshift      = 10;
            v_downshift    = 26;
            break;
        case    128:
            heightshift    = 7;
            v_upshift      = 9;
            v_downshift    = 25;
            break;
        case    256:
            heightshift    = 8;
            v_upshift      = 8;
            v_downshift    = 24;
            break;
        case    16:
            heightshift    = 4;
            v_upshift      = 12;
            v_downshift    = 28;
            break;
        default:
            // Could also at this point create a texture of the closest
            // supported size and resample source into it.
            return (VNGO_UNSUPPORTED_TEXTURE);
    }
    next = _src->vtex3d;
    _src->vtex3d = this;
    return VNGO_NO_ERROR;
}

VNGError VngoMemTexture3D::reinit(VngoTexture *_src,VngoPal *_pal)
{
    release();
    err_status = init(_src,_pal);
    return err_status;
}

void VngoMemTexture3D::release()
{
    palette = NULL;
    VngoTexture3D   *prev = NULL;
    VngoTexture3D   *cur = ref->vtex3d;
    while(cur != this && cur !=NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    if (cur != NULL)
    {   // This means we have not already been removed.
        if (prev)
        {   // This means we are not the head of the list.
            prev->next = cur->next;
            cur->next = NULL;
        }
        else
        {   // We are the head.
            ref->vtex3d = cur->next;
        }
    }
    ref = NULL;
    vtxt = NULL;
}

VngoTextureManager::~VngoTextureManager()
{
}

VNGError VngoTextureManager::ready()
{
    // This makes sure that a texture is properly loaded and ready for use
    // another way of thinking of it is "cached in".
    return VNGO_NO_ERROR;
}

VNGError VngoTextureManager::add(VngoCacheHndl *ntex,int ready)
{
    if(ready)
    {
        // The texture is ready to go and should be put in the ready queue.
        if (ready_tail)
        {
            ntex->prev = ready_tail;
            ready_tail->next = ntex;
        }
        else
        {
            ready_head = ntex;
            ntex->prev = NULL;
        }
        ntex->next = NULL;
        ready_tail = ntex;
        ntex->flags = VNGO_TEXTURE_CACHED_IN;
    }
    else
    {
        // put it in the out queue at the tail.
        if (out_tail)
        {
            ntex->prev = out_tail;
            out_tail->next = ntex;
        }
        else
        {
            out_head = ntex;
            ntex->prev = NULL;
        }
        ntex->next = NULL;
        out_tail = ntex;
        ntex->flags = VNGO_TEXTURE_CACHED_OUT;
    }
    return VNGO_NO_ERROR;
}

VNGError VngoTextureManager::remove(VngoCacheHndl *ntex)
{
    if(ready_head == ntex)
    {
        // remove from the ready head position.
    }
    else if (ready_tail == ntex)
    {
        // remove from the ready tail position.
    }
    else if (out_head == ntex)
    {
        // remove from the out head position.
    }
    else if (out_tail == ntex)
    {
        // remove from the out tail position.
    }
    else
    {
        // look through the ready queue for the texture and remove it.
        // then look through the out queue for the texture and remove it.
    }
    return VNGO_NO_ERROR;
}

VngoCacheHndl::~VngoCacheHndl()
{
    if (VgSystem.DIBTx)
    {
        if (VgSystem.DIBTx->remove(this) == VNGO_NO_ERROR)
            return;
    }
    if (VgSystem.DDTx)
    {
        if (VgSystem.DDTx->remove(this) == VNGO_NO_ERROR)
            return;
    }
    if (VgSystem.D3DTx)
    {
        if (VgSystem.D3DTx->remove(this) == VNGO_NO_ERROR)
            return;
    }
    if (VgSystem.OGLTx)
    {
        if (VgSystem.OGLTx->remove(this) == VNGO_NO_ERROR)
            return;
    }
    if (VgSystem.CL3DTx)
    {
        if (VgSystem.CL3DTx->remove(this) == VNGO_NO_ERROR)
            return;
    }
    if (VgSystem.GlideTx)
    {
        if (VgSystem.GlideTx->remove(this) == VNGO_NO_ERROR)
            return;
    }
    if (VgSystem.MSITx)
    {
        if (VgSystem.MSITx->remove(this) == VNGO_NO_ERROR)
            return;
    }
    return;
}

//°±² End of module - vngserv.cpp ²±°

