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
// d3dtxt.cpp
//
//     The C pluss pluss D3D texture managment file.
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
#include "debug.h"
#include "portable.h"
#include "ivory.h"

// This file always needs _D3D defined.
#ifndef _OEMS
#define _OEMS
#define _OEMS_TEMP
#endif

#ifndef _CLEAR_3D
#define _CLEAR_3D_TEMP
#define _CLEAR_3D
#endif

#include "vangogh.hpp"
#include "vngoems.hpp"

#ifdef  _CLEAR_3D_TEMP
#undef  _CLEAR_3D
#undef  _CLEAR_3D_TEMP
#endif

#ifdef  _OEMS_TEMP
#undef  _OEMS
#undef  _OEMS_TEMP
#endif

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

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

extern VngoSystem   VgSystem;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

VngoCL3DTexture3D::VngoCL3DTexture3D(VngoTexture *_src,VngoPal *_pal) :
    DeviceSurface(0),
    pal(0)
{
    dev_type = VNGO_CLEAR3D_TEX;
    err_status = init(_src,_pal);
}

VngoCL3DTexture3D::~VngoCL3DTexture3D()
{
    release();
}

VNGError VngoCL3DTexture3D::init(VngoTexture *_src,VngoPal *_pal)
{
    if (VgSystem.CL3DTx == NULL)
        return VNGO_NOSCREEN_ERROR;

    VngoClear3D    *cl3dscreen = (VngoClear3D*)VgSystem.CL3DTx->screen;

    palette = _pal;
    ref     = _src;
    chandle = new VngoCacheHndl;
    next = ref->vtex3d;
    ref->vtex3d = this;

    assert(VgSystem.CL3DTx != NULL);
    VgSystem.CL3DTx->add(chandle);

    long    bpp;
    if (ref->flags & VNGO_TEXTURE_8BIT)
    {
        bpp = 8;
    }
    else if(ref->flags & VNGO_TEXTURE_15BIT)
    {
        bpp = 16;
    }
    else if (ref->flags & VNGO_TEXTURE_16BIT)
    {
        bpp = 16;
    }

    DDSURFACEDESC   ddsd;
    ZeroMemory(&ddsd,sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);

    ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PIXELFORMAT;
    ddsd.dwWidth = ref->width;
    ddsd.dwHeight = ref->height;
    ddsd.ddsCaps.dwCaps = DDSCAPS_VIDEOMEMORY | DDSCAPS_TEXTURE;

    ddsd.ddpfPixelFormat.dwSize        = sizeof(ddsd.ddpfPixelFormat);
    ddsd.ddpfPixelFormat.dwRGBBitCount = bpp;
    ddsd.ddpfPixelFormat.dwFlags       = DDPF_RGB;
    if( bpp < 16 )
        ddsd.ddpfPixelFormat.dwFlags  |= DDPF_PALETTEINDEXED8;


    if (cl3dscreen->dd->CreateSurface(&ddsd,&DeviceSurface,NULL) != DD_OK)
    {
        release();
        return VNGO_INTERNAL_ERROR;
    }

    if (palette == NULL)
    {
        return VNGO_INTERNAL_ERROR;
    }
    else
    {
        palette->create_ddpal(cl3dscreen->dd,&pal);
        DeviceSurface->SetPalette(pal);
    }


    int fail_safe=0;
    HRESULT hr = DDERR_SURFACELOST; // prime it so it will loop at least once.

    do
    {
        fail_safe++;    // just so we can't loop infinately.
        hr = DeviceSurface->Lock (NULL, &ddsd,
                                  DDLOCK_SURFACEMEMORYPTR
                                  | DDLOCK_WAIT, NULL);
    }
    while (hr != DD_OK && (fail_safe < 1000));

    if (hr != DD_OK)
    {
        return VNGO_INTERNAL_ERROR;        // failure to lock;
    }

    //
    // We want to copy with bpp conversion here if 8bpp is not
    // supported on the hardware.
    //
    if (ddsd.ddpfPixelFormat.dwRGBBitCount != 8)
    {
        if (ddsd.ddpfPixelFormat.dwRBitMask == 0xf800)
        {
            // we have a 5 - 6 - 5 rgb.
            byte *sptr = (byte*)ref->tex;
            word *dptr = (word*)ddsd.lpSurface;
            int count =(ref->width * ref->height);
            for (int i=0;i < ref->height; i++)
            {
                for (int j=0;j < ref->width; j++)
                {
                    VngoColor24bit tclr = palette->get_RGB(sptr[j]);
                    dptr[j] = tclr.compress16();
                }
                sptr +=ref->width;
                dptr = (word*)(dword(dptr)+ddsd.lPitch);
            }

            DeviceSurface->Unlock(NULL);

            if (ref->flags & VNGO_TEXTURE_TRANSPARENT)
            {
                DDCOLORKEY  cc;
                cc.dwColorSpaceLowValue = 0xf81f;
                cc.dwColorSpaceHighValue = 0xf81f;
                DeviceSurface->SetColorKey(DDCKEY_SRCBLT,&cc);
            }
        }
        else if (ddsd.ddpfPixelFormat.dwRBitMask == 0x7c00)
        {
            // we have a 5 - 5 - 5 rgb.
            byte *sptr = (byte*)ref->tex;
            word *dptr = (word*)ddsd.lpSurface;
            int count =(ref->width * ref->height);
            for (int i=0;i < ref->height; i++)
            {
                for (int j=0;j < ref->width; j++)
                {
                    VngoColor24bit tclr = palette->get_RGB(sptr[j]);
                    dptr[j] = tclr.compress();
                }
                sptr +=ref->width;
                dptr = (word*)(dword(dptr)+ddsd.lPitch);
            }
            DeviceSurface->Unlock(NULL);

            if (ref->flags & VNGO_TEXTURE_TRANSPARENT)
            {
                DDCOLORKEY  cc;
                cc.dwColorSpaceLowValue = 0x7c1f;
                cc.dwColorSpaceHighValue = 0x7c1f;
                DeviceSurface->SetColorKey(DDCKEY_SRCBLT,&cc);
            }
        }
        else
        {
            // we don't readily support this.
            release();
            return VNGO_INTERNAL_ERROR;
        }
    }
    else
    {
        // Ok since we use the same format, just update the M
        byte *sptr = (byte*)ref->tex;
        byte *dptr = (byte*)ddsd.lpSurface;
        for (int i=0;i < ref->height; i++)
        {
            for (int j=0;j < ref->width; j++)
            {
                dptr[j] = sptr[j];
            }
            sptr +=ref->width;
            dptr = (byte*)(dword(dptr)+ddsd.lPitch);
        }

//        memcpy(dptr,sptr,(ref->width * ref->height));
        DeviceSurface->Unlock(NULL);

        if (ref->flags & VNGO_TEXTURE_TRANSPARENT)
        {
            DDCOLORKEY  cc;
            cc.dwColorSpaceLowValue = 255;
            cc.dwColorSpaceHighValue = 255;
            DeviceSurface->SetColorKey(DDCKEY_SRCBLT,&cc);
        }
    }

    return VNGO_NO_ERROR;
}

VNGError VngoCL3DTexture3D::ready_texture()
{
    if (DeviceSurface == NULL)
    {

    }
    return VNGO_NO_ERROR;
}

VNGError VngoCL3DTexture3D::reinit(VngoTexture *_src,VngoPal *_pal)
{
    return VNGO_NO_ERROR;
}

void VngoCL3DTexture3D::release()
{
    if (DeviceSurface)
    {
        DeviceSurface->Release();
        DeviceSurface = NULL;
    }
#if 0
    if (pal)
    {
        pal->Release();
        pal = NULL;
    }
#endif
    if (chandle)
    {
        delete chandle;
        chandle = NULL;
    }
    return;
}

VNGError VngoCL3DTexture3D::restore()
{
    // For now don't do anything, but we will likely
    // need to restore lost surfaces here.
    return VNGO_NO_ERROR;
};



//°±² End of module - d3dtxt.cpp ²±°

