//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//            Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
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
// xflbm.cpp
//
// Contains code for working with IFF '85 standard ILBM files.
// Does not support:  Amiga-specific formats, PBM form used by
//                    latest DPaint, transparent mask, or
//                    direct color (24-bit).
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

// Masking type
#define MASKING_NONE        0   // No mask, all pixels opaque
#define MASKING_HASMASK     1   // Explicit mask (extra plane)
#define MASKING_HASTRANSP   2   // Transparent color index
#define MASKING_LASSO       3   // Transparent color index if against edge of
                                // bitmap

// Compression type
#define COMP_NONE           0   // No compression
#define COMP_BYTERUN1       1   // Simple RLE compression

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

// All data is unsigned in big-endian!
struct Bitmap_header
{
    ushort  w;              // Width
    ushort  h;              // Height
    ushort  x;              // Original X
    ushort  y;              // Original Y
    byte    nPlanes;        // Depth of image
    byte    masking;        // Masking type
    byte    compression;    // Compression type
    byte    pad1;           // Unused (set to 0)
    ushort  trclr;          // Transparent color
    byte    xAspect;        // X aspect ratio
    byte    yAspect;        // Y aspect ratio
    ushort  pWidth;         // Original width
    ushort  pHeight;        // Original height
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
// XFParseLBM - read                                                        ³
//                                                                          ³
// Reads a LBM format bitmap from the file object.                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseLBM::read(XFBitmap *b)
{
    xf_error_codes err;
    XFParseIFF     iff;

    iff.attach(xf);
    if (iff.begin())
        return (errorn=iff.error());

    if (iff.seekform(iff.makeid('I','L','B','M')))
    {
        errorn=iff.error();
        iff.end();
        return (errorn);
    }

    err=read(&iff,b);
    if (err)
        errorn=err;

    iff.end();
    return err;
}

xf_error_codes XFParseLBM::read(XFParseIFF *iff, XFBitmap *b)
{
    int             i, j, k, t, t2;
    ulong           size;
    ulong           rowsize, prsize;
    byte            *ptr, *src, *org;
    byte            msk, pmsk, x;
    xf_error_codes  err;
    Bitmap_header   header;
    byte            *work=0;
    byte            tpal[3*256];

    if (!b)
        b = bm;

//ÄÄ Verify correct form name
    if ((iff->chunkid != iff->makeid('F','O','R','M')
         && iff->chunkid != iff->makeid('R','I','F','F'))
        || iff->formid != iff->makeid('I','L','B','M'))
    {
        errorn=XF_ERR_NOTSUPPORTED;
        return errorn;
    }

//ÄÄ Enter form
    if (iff->enterform())
    {
        errorn=iff->error();
        return errorn;
    }

    err=XF_ERR_NONE;

//ÄÄ Read header
    if (iff->seekchunk(iff->makeid('B','M','H','D'))
        || iff->chunkSize != sizeof(Bitmap_header))
    {
        err=XF_ERR_INVALIDHEADER;
        goto error_exit;
    }

    if (iff->read(&header))
    {
        err=XF_ERR_INVALIDHEADER;
        goto error_exit;
    }

//ÄÄ Check header values
    switch (header.nPlanes)
    {
        case 1:
        case 4:
        case 8:
            break;

        default:
            err=XF_ERR_NOTSUPPORTED;
            goto error_exit;
    }

    if (header.masking != MASKING_NONE
        && header.masking != MASKING_HASTRANSP)
    {
        err=XF_ERR_NOTSUPPORTED;
        goto error_exit;
    }

    if (header.compression != COMP_NONE && header.compression != COMP_BYTERUN1)
    {
        err=XF_ERR_NOTSUPPORTED;
        goto error_exit;
    }

//ÄÄÄ Setup bitmap object ÄÄÄ
    b->release();

    b->flags=0;
    b->clrinuse=0;
    b->width = (ushort) ((header.w & 0xff) << 8) | (ushort) ((header.w & 0xff00) >> 8);
    b->height = (ushort) ((header.h & 0xff) << 8) | (ushort) ((header.h & 0xff00) >> 8);
    b->bpp = 1;

//ÄÄÄ Palette data ÄÄÄ
    if (iff->seekchunk(iff->makeid('C','M','A','P')))
    {
        err=XF_ERR_INVALIDPALETTE;
        goto error_exit;
    }

    if (iff->chunkSize > 256*3)
    {
        err=XF_ERR_INVALIDPALETTE;
        goto error_exit;
    }

    // Allocate memory
    b->palhandle = ivory_halloc(sizeof(dword)*256);
    if (!b->palhandle)
    {
        err=XF_ERR_NOMEMORY;
        goto error_exit;
    }

    b->pal = (dword *)ivory_hlock(b->palhandle);
    if (!b->pal)
    {
        b->release();
        err=XF_ERR_LOCKFAILED;
        goto error_exit;
    }

    memset(b->pal,0,sizeof(dword)*256);

    err=iff->read(tpal);
    if (err)
    {
        err=XF_ERR_INVALIDPALETTE;
        goto error_exit;
    }
    
    for(i=0, ptr=(byte *)b->pal; i < int (iff->chunkSize / 3); i++)
    {
        *(ptr++) = tpal[i*3];       // red
        *(ptr++) = tpal[i*3+1];     // green
        *(ptr++) = tpal[i*3+2];     // blue
        *(ptr++) = 0;               // na to make dword
    }

    b->clrinuse=int (iff->chunkSize / 3) - 1;

//ÄÄÄ Image data ÄÄÄ
    //
    // Compute size of bitpacked rows
    //

    rowsize = (b->width + 7) >> 3;
    prsize = rowsize + ((rowsize & 0x1) ? 1 : 0);

    if (iff->seekchunk(iff->makeid('B','O','D','Y')) || !iff->chunkSize)
    {
        err=XF_ERR_INVALIDIMAGE;
        goto error_exit;
    }

    // Allocate memory
    b->handle = ivory_halloc(b->width * b->height * b->bpp);
    if (!b->handle)
    {
        b->release();
        err=XF_ERR_NOMEMORY;
        goto error_exit;
    }

    b->data = (byte *)ivory_hlock(b->handle);
    if (!b->data)
    {
        b->release();
        err=XF_ERR_LOCKFAILED;
        goto error_exit;
    }

    if ((work = (byte *)new byte[iff->chunkSize + prsize])==NULL)
    {
        b->release();
        err=XF_ERR_NOMEMORY;
        goto error_exit;
    }

    // Read BODY of image (work area has an extra row at start 
    //                     for using during decompression)

    err=iff->read(work+prsize);
    if (err)
    {
        err=XF_ERR_INVALIDIMAGE;
        goto error_exit;
    }

    // Convert from interlaced, bitpacked format

    for(j=0, org=work + prsize, size=0; j < b->height; j++)
    {
        for(k=0, pmsk=0x1; k < header.nPlanes; k++, pmsk <<= 1)
        {
            if (header.compression == COMP_BYTERUN1)
            {
                for(t=0, src=work; ulong (t) < prsize;)
                {
                    if (*org > 129)
                    {
                         size += 2;
                         if (size > iff->chunkSize)
                         {
                             err=XF_ERR_INVALIDIMAGE;
                             goto error_exit;
                         }
                         
                         for(t2=(257 - *(org++)), x = *(org++);
                             t2 > 0; t2--, t++)
                         {
                             *(src++) = x;
                         }
                    }
                    else if (*org == 128)
                    {
                        if (++size > iff->chunkSize)
                        {
                            err=XF_ERR_INVALIDIMAGE;
                            goto error_exit;
                        }
                        org++;
                    }
                    else
                    {
                        t2 = (*(org++) + 1);
                        size += t2 + 1;
                        if (size > iff->chunkSize)
                        {
                            err=XF_ERR_INVALIDIMAGE;
                            goto error_exit;
                        }
     
                        for (;t2 > 0; t2--, t++)
                        {
                            *(src++) = *(org++);
                        }
                    }
                }
                src = work;
            }
            else
            {
                t=prsize * ((header.nPlanes * j) + k);
                if ((t + prsize) > iff->chunkSize)
                {
                    err=XF_ERR_INVALIDIMAGE;
                    goto error_exit;
                }
                src = work + prsize + t;
            }

            ptr = (byte *)b->data + (b->width * j);
            for(i=0, msk=0x80; i < b->width; i++)
            {
                if (*src & msk)
                    *ptr |= pmsk;
                else
                    *ptr &= ~pmsk;
                ptr++;

                if (msk == 0x1)
                {
                    msk = 0x80;
                    src++;
                }
                else msk >>= 1;
            }

            if (msk != 0x80)
            {
                src++;
            }

            if (rowsize & 0x1)
                src++;
        }
    }

    // Cleanup

    if (work)
        delete [] work;

    return XF_ERR_NONE;

//ÄÄ Exit

error_exit: ;

    b->release();

    if (work)
        delete [] work;

    iff->leaveform();

    if (err)
        errorn=err;

    return err;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseLBM - write                                                       ³
//                                                                          ³
// Writes a LBM format bitmap to the file object.                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseLBM::write(XFBitmap *b)
{
    xf_error_codes err;
    XFParseIFF     iff;

    if (!b)
        b = bm;

    iff.attach(xf);
    if (iff.begin())
        return (errorn=iff.error());

    err=write(&iff,b);
    if (err)
        errorn=err;

    iff.end();
    return err;
}

xf_error_codes XFParseLBM::write(XFParseIFF *iff, XFBitmap *b)
{
    int             i, j, k;
    ulong           size;
    ulong           rowsize;
    byte            *ptr, *src;
    byte            msk, pmsk;
    int             locked=0;
    xf_error_codes  err;
    Bitmap_header   header;
    byte            *work=0;
    byte            tpal[3*256];

    if (!b)
        b = bm;

    if (b->bpp != 1 || !b->width || !b->height)
        return XF_ERR_NOTSUPPORTED;

//ÄÄ Enter form
    if (iff->newform(iff->makeid('I','L','B','M')))
    {
        errorn=iff->error();
        return errorn;
    }

//ÄÄÄ Header ÄÄÄ
    memset(&header,0,sizeof(Bitmap_header));

    header.w =  (ushort) ((b->width & 0xff) << 8) | (ushort) ((b->width & 0xff00) >> 8);
    header.h =  (ushort) ((b->height & 0xff) << 8) | (ushort) ((b->height & 0xff00) >> 8);
    header.nPlanes = 8;
    header.masking = MASKING_NONE;
    header.compression = COMP_NONE;

    err=iff->write(iff->makeid('B','M','H','D'),&header,sizeof(Bitmap_header));
    if (err)
    {
        goto error_exit;
    }

    if (b->pal || b->data)
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
 
//ÄÄÄ Color map ÄÄÄ
    if (!b->pal)
    {
        if (!locked)
            b->unlock();
        return (errorn=XF_ERR_INVALIDPALETTE);
    }
    
    for(i=0, ptr=(byte *)b->pal; i < 256; i++)
    {
        tpal[i*3] = *(ptr++);       // red
        tpal[i*3+1] = *(ptr++);     // green
        tpal[i*3+2] = *(ptr++);     // blue
        ptr++;                      // na to make dword
    }

    err=iff->write(iff->makeid('C','M','A','P'),tpal,256*3);
    if (err)
    {
        if (!locked)
            b->unlock();
        goto error_exit;
    }
    
//ÄÄÄ Body ÄÄÄ
    if (!b->data)
    {
        if (!locked)
            b->unlock();
        return (errorn=XF_ERR_INVALIDIMAGE);
    }

    //
    // Compute size of workspace as number of bitpacked padded rows in total
    //
    // Each row is stored as 8 bitpacked rows.
    //

    rowsize = (b->width + 7) >> 3;

    size = (rowsize + ( (rowsize & 0x1) ? 1 : 0 )) * header.nPlanes * b->height;

    // Allocate work space
    assertMyth("XFParseLBM::write expected positive result of workspace computation",
               size);
    work=new byte[size];
    if (!work)
    {
        err=XF_ERR_NOMEMORY;
        if (!locked)
            b->unlock();
        goto error_exit;
    }
    memset(work,0,size);

    // Convert to interlaced, bitpacked format

    assertMyth("XFParseLBM::write expected 8 planes in the header",
               header.nPlanes == 8);

    for(j=0, ptr=work; j < b->height; j++)
    {
        for(k=0, pmsk=0x1; k < header.nPlanes; k++, pmsk <<= 1)
        {
            assert(ptr < work+size);

            for(i=0, msk=0x80, src=(byte*)b->data + (b->width*j);
                i < b->width; 
                i++)
            {
                assert(ptr < work+size);
                if (*(src++) & pmsk)
                    *ptr |= msk;

                if (msk == 0x1)
                {
                    msk = 0x80;
                    ptr++;
                }
                else msk >>= 1;
            }
            if (msk != 0x80)
            {
                ptr++;
            }

            if (rowsize & 0x1)
            {
                ptr++;
            }
        }
    }

    if (!locked)
        b->unlock();

    // Output BODY of image

    err=iff->write(iff->makeid('B','O','D','Y'),work,size);
    if (err)
    {
        goto error_exit;
    }

    // Cleanup

    delete [] work;
    iff->leaveform();
    return XF_ERR_NONE;

//ÄÄ Exit

error_exit: ;

    iff->leaveform();

    if (work)
        delete [] work;

    if (err)
        errorn=err;

    return err;
}

//°±² End of module - xflbm.cpp ²±°

