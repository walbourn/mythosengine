//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//        Microsoft Windows 95/98/NT Version                 | / \   .  |
//                                                           |_|_|_._._.|
//                                                           |.-.-.-.-..|
//                                                          %\__________/%
//                                                           %          %
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                        http://www.mythos-engine.org/
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Tim Little
//
// vngtxtr.cpp
//
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
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°° VngoTexture °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoTexture - release
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void VngoTexture::release()
{
    VngoTexture3D *tptr = vtex3d;
    while(tptr)
    {
        VngoTexture3D *temp = tptr->next;
        delete (tptr);
        tptr = temp;
    }
    vtex3d = 0;
}

void VngoTexture::make_dirty()
{
    VngoTexture3D   *tptr=vtex3d;
    while(tptr)
    {
        tptr->flags |= VNGO_TEXTURE3D_DIRTY;
        tptr=tptr->next;
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoTexture - create
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VNGError VngoTexture::create(short w, short h, int bits, int trans)
{
    release();

    if (w < 1 || h < 1)
        return VNGO_NOT_SUPPORTED;

    width = w;
    height = h;
    flags &= ~(VNGO_TEXTURE_MONO
               | VNGO_TEXTURE_8BIT
               | VNGO_TEXTURE_15BIT
               | VNGO_TEXTURE_16BIT
               | VNGO_TEXTURE_TRANSPARENT);

    switch (bits)
    {
        case 1:
            {
                flags |= VNGO_TEXTURE_MONO;
                ulong size = ((w + 7) >> 3) * h;

                tex = new byte[size];
                if (!tex)
                    return VNGO_MEMALLOC_ERROR;

                memset(tex,0,size);
            }
            break;
        case 8:
            {
                flags |= VNGO_TEXTURE_8BIT;
                ulong size = w * h;

                tex = new byte[size];
                if (!tex)
                    return VNGO_MEMALLOC_ERROR;

                memset(tex,0,size);
            }
            break;
        case 15:
        case 16:
            {
                if (bits == 16)
                    flags |= VNGO_TEXTURE_16BIT;
                else
                    flags |= VNGO_TEXTURE_15BIT;

                ulong size = w * h * 2;
                tex = new byte[size];
                if (!tex)
                    return VNGO_MEMALLOC_ERROR;

                memset(tex,0,size);
            }
            break;
        default:
            return VNGO_NOT_SUPPORTED;
    }

    if (trans)
        flags |= VNGO_TEXTURE_TRANSPARENT;

    return VNGO_NO_ERROR;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoTexture - convert
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VNGError VngoTexture::convert(XFBitmap *bm, VngoPal *pal)
{
    release();

    if (!bm
        || (short)bm->width != width
        || (short)bm->height != height)
        return VNGO_NOT_SUPPORTED;

    bm->lock();

    if (!bm->data || !tex)
        return VNGO_MEMORY_ERROR;

    switch (bm->bpp)
    {
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Monochrome bitmap
        case 0:
            {
                if (!(flags & VNGO_TEXTURE_MONO))
                    return VNGO_NOT_SUPPORTED;

                ulong size = ((width + 7) >> 3) * height;

                memcpy(tex,bm->data,size);
            }
            break;
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ 8-bit bitmap
        case 1:
            if (flags & VNGO_TEXTURE_8BIT)
            {
                if (pal && bm->pal)
                {
                    byte mypal[256];
                    int loop_count = 256;

                    if (flags & VNGO_TEXTURE_TRANSPARENT)
                    {
                        mypal[255] = 255;      // 255 is always transparent if the
                        loop_count--;          // texture has transparentcies.
                    }
                    for(int i=0; i < loop_count; i++)
                    {
                        VngoColor24bit clr = VngoColor24bit(bm->pal[i]);

                        if ((flags & VNGO_TEXTURE_TRANSPARENT)
                            && (clr.r == 255)
                            && (clr.b == 255)
                            && (clr.g == 0))
                        {
                            mypal[i] = 255;
                        }
                        else
                        {
                            mypal[i] = (byte)pal->get_index(clr);
                        }
                    }

                    byte *sptr = bm->data, *dptr = (byte*)tex;
                    for(int i=0; i < width*height; i++)
                    {
                        *(dptr++) = mypal[*(sptr++)];
                    }
                }
                else
                {
                    memcpy(tex,bm->data,width*height);
                }

                pal_ptr = pal;
            }
            else if (flags & VNGO_TEXTURE_15BIT)
            {
                word npal[256];

                if (bm->pal)
                {
                    for(int i=0; i < 256; i++)
                    {
                        VngoColor15bit clr = VngoColor24bit(bm->pal[i]);
                        npal[i] = clr.pcolor;
                    }

                    if (flags & VNGO_TEXTURE_TRANSPARENT)
                    {
                        VngoColor24bit clr = bm->pal[255];
                        if ((clr.r == 255)
                            && (clr.b == 255)
                            && (clr.g == 0))
                        {
                            npal[255] = (word)0x7c1f;
                        }
                    }
                }
                else
                {
                    if (!pal)
                        return VNGO_NOT_SUPPORTED;

                    for(int i=0; i < 256; i++)
                    {
                        VngoColor15bit clr = VngoColor24bit(pal->get_RGB(i));
                        npal[i] = clr.pcolor;
                    }

                    if (flags & VNGO_TEXTURE_TRANSPARENT)
                        npal[255] = (word)0x7c1f;
                }

                byte *sptr = bm->data;
                word *dptr = (word*)tex;
                for(int i=0; i < width*height; i++)
                {
                    *(dptr++) = npal[*(sptr++)];
                }
            }
            else if (flags & VNGO_TEXTURE_16BIT)
            {
                word npal[256];

                if (bm->pal)
                {
                    for(int i=0; i < 256; i++)
                    {
                        VngoColor16bit clr = VngoColor24bit(bm->pal[i]);
                        npal[i] = clr.pcolor;
                    }

                    if (flags & VNGO_TEXTURE_TRANSPARENT)
                    {
                        VngoColor24bit clr = bm->pal[255];
                        if ((clr.r == 255)
                            && (clr.b == 255)
                            && (clr.g == 0))
                        {
                            npal[255] = (word)0xf81f;
                        }
                    }
                }
                else
                {
                    if (!pal)
                        return VNGO_NOT_SUPPORTED;

                    for(int i=0; i < 256; i++)
                    {
                        VngoColor16bit clr = VngoColor24bit(pal->get_RGB(i));
                        npal[i] = clr.pcolor;
                    }

                    if (flags & VNGO_TEXTURE_TRANSPARENT)
                        npal[255] = (word)0xf81f;
                }

                byte *sptr = bm->data;
                word *dptr = (word*)tex;
                for(int i=0; i < width*height; i++)
                {
                    *(dptr++) = npal[*(sptr++)];
                }
            }
            else
                return VNGO_NOT_SUPPORTED;
            break;
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ 15-bit bitmap
        case 2:
            if (flags & VNGO_TEXTURE_8BIT)
            {
                if (!pal)
                    return VNGO_NOT_SUPPORTED;

                byte *sptr=bm->data, *dptr=(byte*)tex;
                for(int i=0; i < width*height; i++)
                {
                    word pcolor = *sptr | (*(sptr+1) << 8);
                    sptr += 2;

                    VngoColor24bit clr;
                    clr.r = (pcolor >> 7) & 0xf8;
                    clr.g = (pcolor >> 2) & 0xf8;
                    clr.b = (pcolor << 3) & 0xf8;

                    if ((flags & VNGO_TEXTURE_TRANSPARENT)
                        && (clr.r >= 0xf8)
                        && (clr.b >= 0xf8)
                        && (clr.g == 0))
                    {
                        *(dptr++) = (byte)255;
                    }
                    else
                    {
                        *(dptr++) = (byte)pal->get_index(clr);
                    }
                }

                pal_ptr = pal;
            }
            else if (flags & VNGO_TEXTURE_15BIT)
            {
                word *sptr=(word*)bm->data, *dptr=(word*)tex;
                for(int i=0; i < width*height; i++)
                {
                    VngoColor24bit trgb;
                    trgb.r = (*sptr >> 7) & 0xF8;
                    trgb.g = (*sptr >> 2) & 0xF8;
                    trgb.b = (*sptr << 3) & 0xF8;
                    sptr++;

                    if ((flags & VNGO_TEXTURE_TRANSPARENT)
                        && (trgb.r >= 0xf8)
                        && (trgb.g == 0)
                        && (trgb.b >= 0xf8))
                    {
                        *(dptr++) = (word)0x7c1f;
                    }
                    else
                    {
                        gamma_correct_RGB(&trgb);
                        *dptr = trgb.compress();
                        dptr++;
                    }
                }
//                memcpy(tex, bm->data, width*height*2);
            }
            else if (flags & VNGO_TEXTURE_16BIT)
            {
                word *sptr=(word*)bm->data, *dptr=(word*)tex;
                for(int i=0; i < width*height; i++)
                {
                    VngoColor24bit trgb;
                    trgb.r = (*sptr >> 7) & 0xF8;
                    trgb.g = (*sptr >> 2) & 0xF8;
                    trgb.b = (*sptr << 3) & 0xF8;
                    sptr++;

                    if ((flags & VNGO_TEXTURE_TRANSPARENT)
                        && (trgb.r >= 0xf8)
                        && (trgb.g == 0)
                        && (trgb.b >= 0xf8))
                    {
                        *(dptr++) = (word)0xf81f;
                    }
                    else
                    {
                        gamma_correct_RGB(&trgb);
                        *dptr = trgb.compress16();
                        dptr++;
                    }
                }
            }
            else
                return VNGO_NOT_SUPPORTED;
            break;
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ 24-bit bitmap
        case 3:
            if (flags & VNGO_TEXTURE_8BIT)
            {
                if (!pal)
                    return VNGO_NOT_SUPPORTED;

                byte *sptr=bm->data, *dptr=(byte*)tex;
                for(int i=0; i < width*height; i++)
                {
                    VngoColor24bit clr;
                    clr.r = *(sptr++);
                    clr.g = *(sptr++);
                    clr.b = *(sptr++);

                    if ((flags & VNGO_TEXTURE_TRANSPARENT)
                        && (clr.r == 255)
                        && (clr.b == 255)
                        && (clr.g == 0))
                    {
                        *(dptr++) = (byte)255;
                    }
                    else
                    {
                        *(dptr++) = (byte)pal->get_index(clr);
                    }
                }

                pal_ptr = pal;
            }
            else if (flags & VNGO_TEXTURE_15BIT)
            {
                byte *sptr=bm->data;
                word *dptr=(word*)tex;
                for(int i=0; i < width*height; i++)
                {
                    VngoColor24bit clr;
                    clr.r = *(sptr++);
                    clr.g = *(sptr++);
                    clr.b = *(sptr++);

                    if ((flags & VNGO_TEXTURE_TRANSPARENT)
                        && (clr.r == 255)
                        && (clr.b == 255)
                        && (clr.g == 0))
                    {
                        *(dptr++) = (word)0x7c1f;
                    }
                    else
                    {
                        gamma_correct_RGB(&clr);
                        *(dptr++) = clr.compress();
                    }
                }
            }
            else if (flags & VNGO_TEXTURE_16BIT)
            {
                byte *sptr=bm->data;
                word *dptr=(word*)tex;
                for(int i=0; i < width*height; i++)
                {
                    VngoColor24bit clr;
                    clr.r = *(sptr++);
                    clr.g = *(sptr++);
                    clr.b = *(sptr++);

                    if ((flags & VNGO_TEXTURE_TRANSPARENT)
                        && (clr.r == 255)
                        && (clr.b == 255)
                        && (clr.g == 0))
                    {
                        *(dptr++) = (word)0xf81f;
                    }
                    else
                    {
                        gamma_correct_RGB(&clr);
                        *(dptr++) = clr.compress16();
                    }
                }
            }
            else
                return VNGO_NOT_SUPPORTED;
            break;
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Unknown bitmap
        default:
            return VNGO_NOT_SUPPORTED;
    }

    return VNGO_NO_ERROR;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° VngoCTexture °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoCTexture
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VngoCTexture::VngoCTexture (VngoTexture *_tex)
{
    ytable = NULL;
    init(_tex);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoCTexture
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
        int j=0;
        for (j=0;j < height;j++)
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
        int j=0;
        for (j=0;j < height;j++)
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoCTexture
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void VngoCTexture::release()
{
    if (tex)
    {
        delete tex;
        tex = 0;
    }
    if (ytable)
    {
        delete ytable;
        ytable = 0;
    }

    VngoTexture::release();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°° VngoMemTexture3D °°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoMemTexture3D
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VngoMemTexture3D::VngoMemTexture3D(VngoTexture *_src,VngoPal *_pal)
{
    dev_type = VNGO_MEM_TEX;
    err_status = init(_src,_pal);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoMemTexture3D
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VngoMemTexture3D::~VngoMemTexture3D()
{
    release();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoMemTexture3D
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
            switch(_src->height)
            {
                case    16:
                    tdimension = TEX32x16;
                    break;
                case    32:
                    tdimension = TEX32x32;
                    break;
                case    64:
                    tdimension = TEX32x64;
                    break;
                case    128:
                    tdimension = TEX32x128;
                    break;
                case    256:
                    tdimension = TEX32x256;
                    break;
            }
            break;
        case    64:
            widthshift     = 6;
            u_upshift      = 10;
            switch(_src->height)
            {
                case    16:
                    tdimension = TEX64x16;
                    break;
                case    32:
                    tdimension = TEX64x32;
                    break;
                case    64:
                    tdimension = TEX64x64;
                    break;
                case    128:
                    tdimension = TEX64x128;
                    break;
                case    256:
                    tdimension = TEX64x256;
                    break;
            }
            break;
        case    128:
            widthshift     = 7;
            u_upshift      = 9;
            switch(_src->height)
            {
                case    16:
                    tdimension = TEX128x16;
                    break;
                case    32:
                    tdimension = TEX128x32;
                    break;
                case    64:
                    tdimension = TEX128x64;
                    break;
                case    128:
                    tdimension = TEX128x128;
                    break;
                case    256:
                    tdimension = TEX128x256;
                    break;
            }
            break;
        case    256:
            widthshift     = 8;
            u_upshift      = 8;
            switch(_src->height)
            {
                case    16:
                    tdimension = TEX256x16;
                    break;
                case    32:
                    tdimension = TEX256x32;
                    break;
                case    64:
                    tdimension = TEX256x64;
                    break;
                case    128:
                    tdimension = TEX256x128;
                    break;
                case    256:
                    tdimension = TEX256x256;
                    break;
            }
            break;
        case    16:
            widthshift     = 4;
            u_upshift      = 12;
            switch(_src->height)
            {
                case    16:
                    tdimension = TEX16x16;
                    break;
                case    32:
                    tdimension = TEX16x32;
                    break;
                case    64:
                    tdimension = TEX16x64;
                    break;
                case    128:
                    tdimension = TEX16x128;
                    break;
                case    256:
                    tdimension = TEX16x256;
                    break;
            }
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoMemTexture3D
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VNGError VngoMemTexture3D::reinit(VngoTexture *_src,VngoPal *_pal)
{
    release();
    err_status = init(_src,_pal);
    return err_status;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoMemTexture3D
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° VngoCacheHndl °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoCacheHndl - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VngoCacheHndl::~VngoCacheHndl()
{
    if (VgSystem->DIBTx)
    {
        if (VgSystem->DIBTx->remove(this) == VNGO_NO_ERROR)
            return;
    }
    if (VgSystem->DDTx)
    {
        if (VgSystem->DDTx->remove(this) == VNGO_NO_ERROR)
            return;
    }
    if (VgSystem->D3DTx)
    {
        if (VgSystem->D3DTx->remove(this) == VNGO_NO_ERROR)
            return;
    }
    if (VgSystem->OGLTx)
    {
        if (VgSystem->OGLTx->remove(this) == VNGO_NO_ERROR)
            return;
    }
    return;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°° VngoTextureManager °°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoTextureManager
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VngoTextureManager::~VngoTextureManager()
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoTextureManager
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VNGError VngoTextureManager::ready(VngoCacheHndl *hndl)
{
    // This makes sure that a texture is properly loaded and ready for use
    // another way of thinking of it is "cached in".
    if (!(hndl->flags & VNGO_TEXTURE_CACHED_IN))
    {
        remove(hndl);
        add (hndl);
    }
    return VNGO_NO_ERROR;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoTextureManager
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VNGError VngoTextureManager::add(VngoCacheHndl *ntex,int ready)
{
if (ntex->next != NULL)
    char *huH="Whats UP";

if (ntex->prev != NULL)
    char *huH="Whats UP";


    if(ready)
    {
        // The texture is ready to go and should be put in the ready queue.
        if (!ready_head)
        {
            ready_head = ntex;
            ready_tail = NULL;
        }
        if (ready_tail)
        {
            ready_tail->next = ntex;
        }

        ntex->next = NULL;
        ntex->prev = ready_tail;
        ready_tail = ntex;
        ntex->flags |= VNGO_TEXTURE_CACHED_IN;
    }
    else
    {
        // put it in the out queue at the tail.
        if (!out_head)
        {
            out_head = ntex;
            out_tail = NULL;
        }
        if (out_tail)
        {
            out_tail->next = ntex;
        }

        ntex->next = NULL;
        ntex->prev = out_tail;
        out_tail = ntex;
        ntex->flags |= VNGO_TEXTURE_CACHED_OUT;
    }
    return VNGO_NO_ERROR;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoTextureManager
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VNGError VngoTextureManager::remove(VngoCacheHndl *ntex)
{
    if (ntex != NULL)
    {
        if (ready_head == ready_tail)
        {
            if (ready_head == ntex)
            {
                // remove from the ready head position.
                ready_head = NULL;
                ready_tail = NULL;
            }
        }
        if (out_head == out_tail)
        {
            if (out_head == ntex)
            {
                // remove from the out head position.
                out_head = NULL;
                out_tail = NULL;
            }
        }

        if(ready_head == ntex)
        {
            // remove from the ready head position.
            ready_head = ntex->next;
            if (ready_head)
                ready_head->prev = NULL;
        }

        if (ready_tail == ntex)
        {
            // remove from the ready tail position.
            ready_tail = ntex->prev;
            if (ready_tail)
                ready_tail->next = NULL;
        }

        if (out_head == ntex)
        {
            // remove from the out head position.
            out_head = ntex->next;
            if (out_head)
                out_head->prev = NULL;
        }

        if (out_tail == ntex)
        {
            // remove from the out tail position.
            out_tail = ntex->prev;
            if (out_tail)
                out_tail->next = NULL;
        }

        if (ntex->prev)
            ntex->prev->next = ntex->next;

        if (ntex->next)
            ntex->next->prev = ntex->prev;

        ntex->prev = NULL;
        ntex->next = NULL;

        ntex->flags &= ~VNGO_TEXTURE_CACHED_IN;
        ntex->flags &= ~VNGO_TEXTURE_CACHED_OUT;
    }
    return VNGO_NO_ERROR;
}

//°±² End of module - vngtxtr.cpp ²±°

