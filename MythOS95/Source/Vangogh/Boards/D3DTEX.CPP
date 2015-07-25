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

#ifndef _D3D
#define _D3D_TEMP
#define _D3D
#endif

#include "vangogh.hpp"
#include "vngd3d.hpp"

#ifdef  _D3D_TEMP
#undef  _D3D
#undef  _D3D_TEMP
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

static IDirectDraw *GetDD(IDirect3DDevice2 *Device);
void ChooseTextureFormat(IDirect3DDevice2 *Device, DWORD bpp, DDPIXELFORMAT *pddpf);

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

VngoD3DTexture3D::VngoD3DTexture3D(VngoTexture *_src,VngoPal *_pal) :
    MemorySurface(0),
    DeviceSurface(0),
    pal(0),
    handle(0)
{
    dev_type = VNGO_D3D_TEX;
    err_status = init(_src,_pal);
}

VngoD3DTexture3D::~VngoD3DTexture3D()
{
    release();
}

VNGError VngoD3DTexture3D::init(VngoTexture *_src,VngoPal *_pal)
{
    if (VgSystem.D3DTx == NULL)
        return VNGO_NOSCREEN_ERROR;

    VngoDirect3D    *d3dscreen = (VngoDirect3D*)VgSystem.D3DTx->screen;

    palette = 0;
    ref     = _src;
    chandle = new VngoCacheHndl;

    assert(VgSystem.D3DTx != NULL);
    VgSystem.D3DTx->add(chandle);

    long    bpp;
    if (ref->flags & VNGO_TEXTURE_8BIT)
    {
        bpp = 8;
    }
    else if(ref->flags & VNGO_TEXTURE_15BIT)
    {
        bpp = 15;
    }
    else if (ref->flags & VNGO_TEXTURE_16BIT)
    {
        bpp = 16;
    }


    DDSURFACEDESC   ddsd;
    ZeroMemory(&ddsd,sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);

    ChooseTextureFormat(d3dscreen->d3dDevice,bpp,&ddsd.ddpfPixelFormat);

    ddsd.dwFlags |= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PIXELFORMAT;
    ddsd.dwWidth = ref->width;
    ddsd.dwHeight = ref->height;

    D3DDEVICEDESC   hal,hel;
    ZeroMemory (&hal,sizeof(hal));
    hal.dwSize = sizeof(hal);
    ZeroMemory (&hel,sizeof(hel));
    hel.dwSize = sizeof(hel);

    d3dscreen->d3dDevice->GetCaps(&hal,&hel);


    if (hal.dcmColorModel)
        ddsd.ddsCaps.dwCaps = DDSCAPS_VIDEOMEMORY | DDSCAPS_TEXTURE | DDSCAPS_ALLOCONLOAD;
    else
        ddsd.ddsCaps.dwCaps = DDSCAPS_SYSTEMMEMORY | DDSCAPS_TEXTURE;

    if (d3dscreen->dd->CreateSurface(&ddsd,&DeviceSurface,NULL) != DD_OK)
    {
        release();
        return VNGO_INTERNAL_ERROR;
    }

    if (hal.dcmColorModel)
    {
        ddsd.ddsCaps.dwCaps = DDSCAPS_SYSTEMMEMORY | DDSCAPS_TEXTURE;

        if (d3dscreen->dd->CreateSurface(&ddsd,&MemorySurface,NULL) != DD_OK)
        {
            release();
            return VNGO_INTERNAL_ERROR;
        }
    }
    else
    {
        MemorySurface = DeviceSurface;
        DeviceSurface->AddRef();
    }

    VNGError err = load_texture();
    if (err != VNGO_NO_ERROR)
    {
        return err;
    }

    IDirect3DTexture2   *Texture;

    DeviceSurface->QueryInterface(IID_IDirect3DTexture2, (void**)&Texture);

    Texture->GetHandle(d3dscreen->d3dDevice,&handle);
    Texture->Release();

    restore();

    next = ref->vtex3d;
    ref->vtex3d = this;

    return VNGO_NO_ERROR;
}

VNGError VngoD3DTexture3D::ready_texture()
{
    if (flags & VNGO_TEXTURE3D_DIRTY && DeviceSurface != NULL && handle != NULL)
    {
        load_texture();
        restore();
    }
    else if (DeviceSurface == NULL || handle == NULL)
    {
         // Here is where we find a new device surface and set that up.
         return VNGO_NOT_SUPPORTED;

         if (flags & VNGO_TEXTURE3D_DIRTY)
         {
            load_texture();
         }
         restore();
    }
    return VNGO_NO_ERROR;
}

VNGError VngoD3DTexture3D::reinit(VngoTexture *_src,VngoPal *_pal)
{
    return VNGO_NO_ERROR;
}

void VngoD3DTexture3D::release()
{
    if (MemorySurface == DeviceSurface)
    {
        MemorySurface = NULL;
    }
    if (MemorySurface)
    {
        MemorySurface->Release();
        MemorySurface = NULL;
    }
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
    handle = NULL;

    if (chandle)
    {
        delete chandle;
        chandle = NULL;
    }
    return;
}

VNGError VngoD3DTexture3D::restore()
{
    HRESULT err;
    IDirect3DTexture2   *MemTexture;
    IDirect3DTexture2   *DevTexture;

    if (DeviceSurface == MemorySurface)
        return VNGO_NO_ERROR;

    if (DeviceSurface->Restore() != DD_OK)
        return VNGO_INTERNAL_ERROR;

    DeviceSurface->QueryInterface(IID_IDirect3DTexture2, (void**)&DevTexture);
    MemorySurface->QueryInterface(IID_IDirect3DTexture2, (void**)&MemTexture);

    err = DevTexture->Load(MemTexture);

    DevTexture->Release();
    MemTexture->Release();

    return VNGO_NO_ERROR;
};

VNGError    VngoD3DTexture3D::load_texture()
{
    VngoDirect3D    *d3dscreen = (VngoDirect3D*)VgSystem.D3DTx->screen;

    if (palette != ref->pal_ptr)
    {
        palette = ref->pal_ptr;
        palette->create_ddpal(d3dscreen->dd,&pal);
        MemorySurface->SetPalette(pal);
        DeviceSurface->SetPalette(pal);
    }

    int fail_safe=0;
    HRESULT hr = DDERR_SURFACELOST; // prime it so it will loop at least once.
    DDSURFACEDESC   ddsd;
    ZeroMemory(&ddsd,sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);

    do
    {
        fail_safe++;    // just so we can't loop infinately.
        hr = MemorySurface->Lock (NULL, &ddsd,
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
    if (ddsd.ddpfPixelFormat.dwRGBBitCount != 8
        || ddsd.lPitch != ref->width)
    {
        if (ddsd.ddpfPixelFormat.dwRBitMask == 0xf800)
        {
            if (ref->flags & VNGO_TEXTURE_TRANSPARENT)
            {
                DDCOLORKEY  cc;
                cc.dwColorSpaceLowValue = 0xf81f;
                cc.dwColorSpaceHighValue = 0xf81f;
                MemorySurface->SetColorKey(DDCKEY_SRCBLT,&cc);
            }
            // we have a 5 - 6 - 5 rgb.
            byte *sptr = (byte*)ref->tex;
            word *dptr = (word*)ddsd.lpSurface;
            int count =(ref->width * ref->height);
            for (int i=0;i < count; i++)
            {
                if (*sptr == 255)
                {
                    *dptr = 0xf81f;
                }
                else
                {
                    VngoColor24bit tclr = palette->get_RGB(*sptr);
                    *dptr = tclr.compress16();
                }
                sptr++;
                dptr++;
            }
        }
        else if (ddsd.ddpfPixelFormat.dwRBitMask == 0x7c00)
        {
            if (ref->flags & VNGO_TEXTURE_TRANSPARENT)
            {
                DDCOLORKEY  cc;
                cc.dwColorSpaceLowValue = 0x7c1f;
                cc.dwColorSpaceHighValue = 0x7c1f;
                MemorySurface->SetColorKey(DDCKEY_SRCBLT,&cc);
            }
            // we have a 5 - 5 - 5 rgb.
            byte *sptr = (byte*)ref->tex;
            word *dptr = (word*)ddsd.lpSurface;
            int count =(ref->width * ref->height);
            for (int i=0;i < count; i++)
            {
                if (*sptr == 255)
                {
                    *dptr = 0x7c1f;
                }
                else
                {
                    VngoColor24bit tclr = palette->get_RGB(*sptr);
                    *dptr = tclr.compress();
                }
                sptr++;
                dptr++;
            }
        }
        else
        {
            // we don't readily support this.
            release();
            MemorySurface->Unlock(NULL);
            return VNGO_INTERNAL_ERROR;
        }
    }
    else
    {
        if (ref->flags & VNGO_TEXTURE_TRANSPARENT)
        {
            DDCOLORKEY  cc;
            cc.dwColorSpaceLowValue = 255;
            cc.dwColorSpaceHighValue = 255;
            MemorySurface->SetColorKey(DDCKEY_SRCBLT,&cc);
        }

        // Ok since we use the same format, just update the M
        byte *sptr = (byte*)ref->tex;
        byte *dptr = (byte*)ddsd.lpSurface;
        memcpy(dptr,sptr,(ref->width * ref->height));
    }


    MemorySurface->Unlock(NULL);
    return VNGO_NO_ERROR;
}

struct FindTextureData
{
    dword           bpp;
    DDPIXELFORMAT   ddpf;
};

HRESULT CALLBACK FindTextureCallback (DDSURFACEDESC *DeviceFmt, LPVOID lParam)
{
    FindTextureData *FindData = (FindTextureData *)lParam;
    DDPIXELFORMAT   ddpf = DeviceFmt->ddpfPixelFormat;

    if (ddpf.dwFlags & (DDPF_ALPHA | DDPF_ALPHAPIXELS))
        return DDENUMRET_OK;

    if (ddpf.dwRGBBitCount <= 8 &&
        !(ddpf.dwFlags & (DDPF_PALETTEINDEXED8 | DDPF_PALETTEINDEXED4)))
        return DDENUMRET_OK;

    if (ddpf.dwRGBBitCount < 8)
        return DDENUMRET_OK;

    if (FindData->ddpf.dwRGBBitCount == 0 ||
        (ddpf.dwRGBBitCount >= FindData->bpp &&
        (UINT) (ddpf.dwRGBBitCount - FindData->bpp) < (UINT) (FindData->ddpf.dwRGBBitCount - FindData->bpp)))
    {
        FindData->ddpf = ddpf;
    }

    return DDENUMRET_OK;
}

void ChooseTextureFormat(IDirect3DDevice2 *Device, DWORD bpp, DDPIXELFORMAT *pddpf)
{
    FindTextureData FindData;
    ZeroMemory (&FindData, sizeof (FindData));
    FindData.bpp = bpp;
    Device->EnumTextureFormats(FindTextureCallback,(LPVOID)&FindData);
    *pddpf = FindData.ddpf;
}

static IDirectDraw *GetDD(IDirect3DDevice2 *Device)
{
    IDirectDraw         *DirectDraw;
    IDirectDrawSurface  *Target;
    IDirectDrawSurface2 *Target2;

    //
    // Get the render target (We need it to get the IDirectDraw).
    //

    if (Device == NULL || Device->GetRenderTarget(&Target) != DD_OK)
        return NULL;

    //
    // Get the DirectDraw object, but first we need a IDirectDrawSurface2
    //

    if (Target->QueryInterface(IID_IDirectDrawSurface2, (void**)&Target) != DD_OK)
        return NULL;

    Target->Release();
    Target2->GetDDInterface((void**)&DirectDraw);
    Target2->Release();
    DirectDraw->Release();  // Don't up the refcount.

    return DirectDraw;

}

//°±² End of module - d3dtxt.cpp ²±°

