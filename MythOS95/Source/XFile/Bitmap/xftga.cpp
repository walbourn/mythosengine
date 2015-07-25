//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//                    Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
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
// Created by Chuck Walbourn
//
// xftga.cpp
//
//  Contains code for working with TrueVision Targa TGA files.  This
//  object only supports true-color images with no color map and 24
//  or 32 bits per pixel uncompressed.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <assert.h>
#include <string.h>

#include "xfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define IMG_NONE        0               // No image present
#define IMG_CMAP        1               // Color-mapped, uncompressed
#define IMG_TC          2               // True color, uncompressed
#define IMG_BW          3               // Black and white, uncompressed
#define IMG_CMAP_RLE    9               // Color-mapped, RLE compressed
#define IMG_TC_RLE      10              // True color, RLE compressed
#define IMG_BW_RLE      11              // Black and white, RLE compressed

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

struct TGA_header
{
    byte    id_len;                     // ID field length
    byte    cmap_type;                  // Color map type
                                        // 1=has map, 0 otherwise
    byte    img_type;                   // Image type
    ushort  cmap_first;                 // First color map entry
    ushort  cmap_len;                   // Color map length
    byte    cmap_size;                  // Color map entry size
                                        // 15, 16, 24, or 32
    ushort  imgx;                       // Image X origin
    ushort  imgy;                       // Image Y origin
    ushort  imgw;                       // Image width
    ushort  imgh;                       // Image height
    byte    bpp;                        // Bits per pixel
    byte    ibits;                      // Image descriptor bits
};

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseTGA - read                                                        ³
//                                                                          ³
// Reads a TGA format bitmap from the file object.                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseTGA::read(XFBitmap *b)
{
    int                 x;
    int                 y;
    byte                *sptr, *dptr;
    struct TGA_header   header;

    if (!b)
        b = bm;

//ÄÄÄ Read header ÄÄÄ
    if (xf->read(&header,sizeof(TGA_header)) != sizeof(TGA_header))
        return (errorn=xf->error());

    // Skip any ID field
    if (header.id_len)
        xf->seek_cur(header.id_len);

//ÄÄÄ Check for unsupported formats ÄÄÄ
    if ( header.cmap_type                           // No colormap
         || (header.img_type != IMG_TC
             && header.img_type != IMG_TC_RLE)      // Truecolor
         || (header.ibits & 0xc0)                   // Non interleaved
         || !header.imgw || !header.imgh            // Non-empty size
       )
        return (errorn=XF_ERR_NOTSUPPORTED);

//ÄÄÄ Setup bitmap object ÄÄÄ
    b->release();

    b->flags=0;
    b->clrinuse=0;
    b->width = header.imgw;
    b->height = header.imgh;

    switch (header.bpp)
    {
        case 15:
        case 16:
            b->bpp = XFBM_BPP_15BIT;
            break;
        case 24:
            b->bpp = XFBM_BPP_24BIT;
            break;
        case 32:
            b->bpp = XFBM_BPP_32BIT;
            break;
        default:
            return (errorn=XF_ERR_NOTSUPPORTED);
    }

//ÄÄÄ Setup memory ÄÄÄ
    b->handle = ivory_halloc(b->width * b->height * b->bpp);
    if (!b->handle)
    {
        b->release();
        return (errorn=XF_ERR_NOMEMORY);
    }

    b->data = (byte *)ivory_hlock(b->handle);
    if (!b->data)
    {
        b->release();
        return (errorn=XF_ERR_LOCKFAILED);
    }

//ÄÄÄ Load image data ÄÄÄ
    switch (header.img_type)
    {
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ RLE Compressed
        case IMG_TC_RLE:
            {
                byte work[4];

                for(y=0; y < b->height; y++)
                {
                    // Compute start location for current line given images bits
                    dptr = b->data + ( (b->width*b->bpp)
                                       * ( (header.ibits & 0x20)
                                           ? y
                                           : (b->height - y - 1) ) )
                                   + ( (header.ibits & 0x10)
                                       ? (b->width-1)*b->bpp
                                       : 0 );

                    for(x=0; x < b->width;)
                    {
                        if (xf->read(work,1) != 1)
                        {
                            b->release();
                            return (errorn=XF_ERR_INVALIDIMAGE);
                        }

                        if ((*work & 0x80) == 0x80)
                        {
                            // Repeat
                            int j = (*work & 0x7f) + 1;

                            if (xf->read(work,b->bpp) != b->bpp)
                            {
                                b->release();
                                return (errorn=XF_ERR_INVALIDIMAGE);
                            }

                            for(; j > 0; j--, x++)
                            {
                                if (x >= b->width)
                                {
                                    b->release();
                                    return (errorn=XF_ERR_INVALIDIMAGE);
                                }

                                switch (b->bpp)
                                {
                                    case XFBM_BPP_15BIT:
                                        *dptr     = *work;
                                        *(dptr+1) = *(work+1);

                                                 // Right to left transversal
                                        if (header.ibits & 0x10)
                                            dptr -= 2;
                                        else
                                            dptr += 2;
                                        break;

                                    case XFBM_BPP_24BIT:
                                        *(dptr+2) = *work;      // Blue
                                        *(dptr+1) = *(work+1);  // Green
                                        *dptr     = *(work+2);  // Red

                                                 // Right to left transversal
                                        if (header.ibits & 0x10)
                                            dptr -= 3;
                                        else
                                            dptr += 3;
                                        break;

                                    case XFBM_BPP_32BIT:
                                        *(dptr+2) = *work;      // Blue
                                        *(dptr+1) = *(work+1);  // Green
                                        *dptr     = *(work+2);  // Red
                                        *(dptr+3) = *(work+3);  // Alpha

                                                 // Right to left transversal
                                        if (header.ibits & 0x10)
                                            dptr -= 4;
                                        else
                                            dptr += 4;
                                        break;
                                }
                            }
                        }
                        else
                        {
                            // Literal
                            int j = (*work & 0x7f) + 1;

                            for(; j > 0; j--, x++)
                            {
                                if (xf->read(work,b->bpp) != b->bpp)
                                {
                                    b->release();
                                    return (errorn=XF_ERR_INVALIDIMAGE);
                                }

                                if (x >= b->width)
                                {
                                    b->release();
                                    return (errorn=XF_ERR_INVALIDIMAGE);
                                }

                                switch (b->bpp)
                                {
                                    case XFBM_BPP_15BIT:
                                        *dptr     = *work;
                                        *(dptr+1) = *(work+1);

                                                 // Right to left transversal
                                        if (header.ibits & 0x10)
                                            dptr -= 2;
                                        else
                                            dptr += 2;
                                        break;

                                    case XFBM_BPP_24BIT:
                                        *(dptr+2) = *work;      // Blue
                                        *(dptr+1) = *(work+1);  // Green
                                        *dptr     = *(work+2);  // Red

                                                 // Right to left transversal
                                        if (header.ibits & 0x10)
                                            dptr -= 3;
                                        else
                                            dptr += 3;
                                        break;

                                    case XFBM_BPP_32BIT:
                                        *(dptr+2) = *work;      // Blue
                                        *(dptr+1) = *(work+1);  // Green
                                        *dptr     = *(work+2);  // Red
                                        *(dptr+3) = *(work+3);  // Alpha

                                                 // Right to left transversal
                                        if (header.ibits & 0x10)
                                            dptr -= 4;
                                        else
                                            dptr += 4;
                                        break;
                                }
                            }
                        }
                    }
                }
            }
            break;
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Uncompressed
        case IMG_TC:
            {
                ulong lsize = ulong (b->width) * b->bpp;

                // Allocate workspace
                byte *work = new byte[lsize];
                if (!work)
                {
                    b->release();
                    return (errorn=XF_ERR_NOMEMORY);
                }

                for(y=0; y < b->height; y++)
                {
                    // Compute start location for current line given images bits
                    dptr = b->data + ( (b->width*b->bpp)
                                       * ( (header.ibits & 0x20)
                                           ? y
                                           : (b->height - y - 1) ) )
                                   + ( (header.ibits & 0x10)
                                       ? (b->width-1)*b->bpp
                                       : 0 );

                    // Read scanline into workspace
                    if (xf->read (work,lsize) != lsize)
                    {
                        b->release();
                        delete [] work;
                        return (errorn=XF_ERR_INVALIDIMAGE);
                    }

                    switch (b->bpp)
                    {
                        case XFBM_BPP_15BIT:
                            for(sptr=work, x=0; x < b->width; x++)
                            {
                                *dptr     = *(sptr++);
                                *(dptr+1) = *(sptr++);

                                                 // Right to left transversal
                                if (header.ibits & 0x10)
                                    dptr -= 2;
                                else
                                    dptr += 2;
                            }
                            break;

                        case XFBM_BPP_24BIT:
                            // Convert BGR to proper order while copying
                            for(sptr=work, x=0; x < b->width; x++)
                            {
                                *(dptr+2) = *(sptr++);      // Blue
                                *(dptr+1) = *(sptr++);      // Green
                                *dptr     = *(sptr++);      // Red

                                                 // Right to left transversal
                                if (header.ibits & 0x10)
                                    dptr -= 3;
                                else
                                    dptr += 3;
                            }
                            break;

                        case XFBM_BPP_32BIT:
                            // Convert BGRA to proper order while copying
                            for(sptr=work, x=0; x < b->width; x++)
                            {
                                *(dptr+2) = *(sptr++);      // Blue
                                *(dptr+1) = *(sptr++);      // Green
                                *dptr     = *(sptr++);      // Red
                                *(dptr+3) = *(sptr++);      // Alpha

                                                 // Right to left transversal
                                if (header.ibits & 0x10)
                                    dptr -= 4;
                                else
                                    dptr += 4;
                            }
                            break;
                    }
                }

                delete [] work;
            }
            break;
    }

    return XF_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseTGA - write                                                       ³
//                                                                          ³
// Writes a TGA format bitmap to the file object.                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseTGA::write(XFBitmap *b)
{
    int                 i;
    int                 y;
    ulong               lsize;
    byte                *sptr, *dptr;
    byte                *work;
    int                 locked=0;
    struct TGA_header   header;

    if (!b)
        b = bm;

    if (!b->width || !b->height)

    switch (b->bpp)
    {
        case XFBM_BPP_15BIT:
        case XFBM_BPP_24BIT:
        case XFBM_BPP_32BIT:
            break;
        default:
            return (errorn=XF_ERR_NOTSUPPORTED);
    }

//ÄÄÄ Create/write header ÄÄÄ
    memset(&header,0,sizeof(TGA_header));
    header.imgw = b->width;
    header.imgh = b->height;
    header.img_type = IMG_TC;
    header.ibits = 0x20;                // Left to right, top to bottom

    switch (b->bpp)
    {
        case XFBM_BPP_15BIT:
            header.bpp = 15;
            break;
        case XFBM_BPP_24BIT:
            header.bpp = 24;
            break;
        case XFBM_BPP_32BIT:
            header.bpp = 32;
            break;
    }

    if (xf->write(&header,sizeof(TGA_header)) != sizeof(TGA_header))
    {
        errorn=xf->error();
        return errorn;
    }

    if (b->data)
    {
        locked=1;
    }
    else
    {
        xf_error_codes err;

        err=b->lock();
        if (err)
        {
            return (errorn=err);
        }
    }

//ÄÄÄ Write out image ÄÄÄ
    if (!b->data)
    {
        if (!locked)
            b->unlock();
        return (errorn=XF_ERR_INVALIDIMAGE);
    }

    lsize = b->width * b->bpp;

    // Allocate workspace
    work = new byte[lsize];
    if (!work)
    {
        if (!locked)
            b->unlock();
        return (errorn=XF_ERR_NOMEMORY);
    }

    for(y=0, sptr=b->data; y < b->height; y++)
    {
        switch (b->bpp)
        {
            case XFBM_BPP_15BIT:
                for(dptr=work, i=0; i < b->width; i++)
                {
                    *(dptr++) = *sptr;
                    *(dptr++) = *(sptr+1);

                    sptr += 2;
                }
                break;

            case XFBM_BPP_24BIT:
                // Convert RGB to BGR order
                for(dptr=work, i=0; i < b->width; i++)
                {
                    *(dptr++) = *(sptr+2);      // Blue
                    *(dptr++) = *(sptr+1);      // Green
                    *(dptr++) = *sptr;          // Red

                    sptr += 3;
                }
                break;

            case XFBM_BPP_32BIT:
                // Convert RGBA to BGRA order
                for(dptr=work, i=0; i < b->width; i++)
                {
                    *(dptr++) = *(sptr+2);      // Blue
                    *(dptr++) = *(sptr+1);      // Green
                    *(dptr++) = *sptr;          // Red
                    *(dptr++) = *(sptr+3);      // Alpha

                    sptr += 4;
                }
                break;
        }

        // Write scanline from workspace
        if (xf->write(work,lsize) != lsize)
        {
            if (!locked)
                b->unlock();
            delete [] work;
            return (errorn=xf->error());
        }
    }

    if (!locked)
        b->unlock();

    delete [] work;

    return XF_ERR_NONE;
}

//°±² End of module - xftga.cpp ²±°

