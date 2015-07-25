//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//            Copyright (c) 1994,1995 by Charybdis Enterprises, Inc.
//                              All Rights Reserved.
//                        Microsoft Windows '95 Version
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
// Created by Chuck Walbourn
//
// xftga.cpp
//
//      Contains code for working with TrueVision Targa TGA files.  This
//      object only supports true-color images with no color map and 24
//      or 32 bits per pixel uncompressed.
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

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseTGA - read                                                        ³
//                                                                          ³
// Reads a TGA format bitmap from the file object.                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseTGA::read(XFBitmap *b)
{
    int                 i;
    int                 y;
    ulong               lsize;
    byte                *sptr, *dptr;
    byte                *work;
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
         || (header.bpp != 24 && header.bpp != 32)  // 24- or 32-bit only
         || header.img_type != IMG_TC               // Uncompressed truecolor
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
    b->bpp = 3;
 
//ÄÄÄ Load image data ÄÄÄ

    // Allocate memory
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

    lsize = ulong (b->width) * ((header.bpp == 32) ? 4ul : 3ul);

    // Allocate workspace
    work = new byte[lsize];
    if (!work)
    {
        b->release();
        return (errorn=XF_ERR_NOMEMORY);
    }

    for(y=0; y < b->height; y++)
    {
        // Compute start location for current line given images bits
        dptr = b->data + ( (b->width * 3)
                           * ( (header.ibits & 0x20) ? y : (b->height - y - 1) ) )
                       + ( (header.ibits & 0x10) ? (b->width-1)*3 : 0  );

        // Read scanline into workspace
        if (xf->read (work,lsize) != lsize)
        {
            b->release();
            delete [] work;
            return (errorn=XF_ERR_INVALIDIMAGE);
        }

        // Convert BGRA or BGR to proper order while copying to data area
        for(sptr=work, i=0; i < b->width; i++)
        {
            *(dptr+2) = *(sptr++);      // Blue
            *(dptr+1) = *(sptr++);      // Green
            *dptr     = *(sptr++);      // Red

            if (header.bpp == 32)       // Skip Alpha
                sptr++;

            if (header.ibits & 0x10)    // Right to left transversal
                dptr -= 3;
            else
                dptr += 3;
        }
    }

    delete [] work;

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
    int                 locked;
    struct TGA_header   header;

    if (!b)
        b = bm;

    if (b->bpp != 3)
        return XF_ERR_NOTSUPPORTED;

//ÄÄÄ Create/write header ÄÄÄ
    memset(&header,0,sizeof(TGA_header));
    header.imgw = b->width;
    header.imgh = b->height;
    header.bpp = 24;
    header.img_type = IMG_TC;
    header.ibits = 0x20;                // Left to right, top to bottom

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
    if (!b->handle)
    {
        if (!locked)
            b->unlock();
        return (errorn=XF_ERR_INVALIDIMAGE);
    }

    lsize = b->width * 3ul;

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
        // Convert RGB to BGR order
        for(dptr=work, i=0; i < b->width; i++)
        {
            *(dptr++) = *(sptr+2);      // Blue
            *(dptr++) = *(sptr+1);      // Green
            *(dptr++) = *sptr;          // Red

            sptr += 3;
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

    delete [] work;

    return XF_ERR_NONE;
}

//°±² End of module - xftga.cpp ²±°

