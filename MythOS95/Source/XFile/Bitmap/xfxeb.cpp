//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//                      Microsoft Windows 95/NT Version
//
//            Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.
//                              All Rights Reserved.
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
// xfxeb.cpp
//
// Contains code for working with Charybdis' XEB form, which is
// a custom RLE format, which supports monochrome uncompressed and
// 8-bit, 16-bit, 24-bit, and 32-bit image data in both compressed
// and uncompressed forms.
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

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseXEB - read                                                        ³
//                                                                          ³
// Reads a XEB format bitmap from the file object.                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseXEB::read(XFBitmap *b)
{
    xf_error_codes err;
    XFParseIFF     iff;

    iff.attach(xf);
    if (iff.begin())
        return (errorn=iff.error());

    if (iff.seekform(iff.makeid('X','F','E','B')))
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

xf_error_codes XFParseXEB::read(XFParseIFF *iff, XFBitmap *b)
{
    xf_error_codes  err;
    byte            *work=0;
    ulong           size=0;
    XFXEBHeader     header;

    if (!b)
        b = bm;

//ÄÄ Verify correct form name
    if ((iff->chunkid != iff->makeid('F','O','R','M')
         && iff->chunkid != iff->makeid('R','I','F','F'))
        || iff->formid != iff->makeid('X','F','E','B'))
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

//ÄÄ Read header
    if (iff->seekchunk(iff->makeid('H','D','R',' '))
        || iff->chunkSize != sizeof(header))
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
    if (header.version != XFEB_VERSION
        || !header.width
        || !header.height
        || (header.compress != XF_XEB_COMPRESS_RLE
            && header.compress != XF_XEB_COMPRESS_NONE))
    {
        err=XF_ERR_NOTSUPPORTED;
        goto error_exit;
    }

    switch (header.bpp)
    {
        case XFBM_BPP_MONO:
        case XFBM_BPP_8BIT:
        case XFBM_BPP_15BIT:
        case XFBM_BPP_24BIT:
        case XFBM_BPP_32BIT:
            break;
        default:
            err=XF_ERR_NOTSUPPORTED;
            goto error_exit;
    }

//ÄÄÄ Setup bitmap object
    b->release();

    b->flags=0;
    b->clrinuse=0;
    b->width = header.width;
    b->height = header.height;
    b->bpp = header.bpp;

//ÄÄÄ Palette data
    if (b->bpp == XFBM_BPP_8BIT)
    {
        if (iff->seekchunk(iff->makeid('P','A','L',' ')))
        {
            err=XF_ERR_INVALIDPALETTE;
            goto error_exit;
        }

        if (iff->chunkSize != 256*4)
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
            err=XF_ERR_LOCKFAILED;
            goto error_exit;
        }

        memset(b->pal,0,sizeof(dword)*256);
        err=iff->read(b->pal);
        if (err)
        {
            err=XF_ERR_INVALIDPALETTE;
            goto error_exit;
        }
        b->clrinuse=255;
    }

//ÄÄÄ Image data
    if (iff->seekchunk(iff->makeid('B','O','D','Y'))
        || !iff->chunkSize)
    {
        err=XF_ERR_INVALIDIMAGE;
        goto error_exit;
    }

    size = (header.bpp == XFBM_BPP_MONO)
           ? (((b->width + 7) >> 3) * b->height)
           : (b->width * b->height * b->bpp);

    // Allocate memory
    b->handle = ivory_halloc(size);
    if (!b->handle)
    {
        err=XF_ERR_NOMEMORY;
        goto error_exit;
    }

    b->data = (byte *)ivory_hlock(b->handle);
    if (!b->data)
    {
        err=XF_ERR_LOCKFAILED;
        goto error_exit;
    }

    switch (header.compress)
    {
        case XF_XEB_COMPRESS_NONE:
            if (iff->chunkSize != size)
            {
                err=XF_ERR_INVALIDIMAGE;
                goto error_exit;
            }

            err=iff->read(b->data);
            if (err)
            {
                err=XF_ERR_INVALIDIMAGE;
                goto error_exit;
            }
            break;
        case XF_XEB_COMPRESS_RLE:
            if ((work = new byte[iff->chunkSize])==NULL)
            {
                err=XF_ERR_NOMEMORY;
                goto error_exit;
            }

            err=iff->read(work);
            if (err)
            {
                err=XF_ERR_INVALIDIMAGE;
                goto error_exit;
            }

            switch (b->bpp)
            {
                case XFBM_BPP_MONO:
                    if (uncompress_rle_mono(b->width,b->height,
                                            iff->chunkSize, work,
                                            b->data))
                    {
                        err=XF_ERR_INVALIDIMAGE;
                        goto error_exit;
                    }
                    break;
                case XFBM_BPP_15BIT:
                    if (uncompress_rle_16bpp(b->width,b->height,
                                             iff->chunkSize, work,
                                             b->data))
                    {
                        err=XF_ERR_INVALIDIMAGE;
                        goto error_exit;
                    }
                    break;
                case XFBM_BPP_24BIT:
                    if (uncompress_rle_24bpp(b->width,b->height,
                                             iff->chunkSize, work,
                                             b->data))
                    {
                        err=XF_ERR_INVALIDIMAGE;
                        goto error_exit;
                    }
                    break;
                case XFBM_BPP_32BIT:
                    if (uncompress_rle_32bpp(b->width,b->height,
                                             iff->chunkSize, work,
                                             b->data))
                    {
                        err=XF_ERR_INVALIDIMAGE;
                        goto error_exit;
                    }
                    break;
                default:
                    assert(b->bpp == XFBM_BPP_8BIT);
                    if (uncompress_rle_8bpp(b->width,b->height,
                                            iff->chunkSize, work,
                                            b->data))
                    {
                        err=XF_ERR_INVALIDIMAGE;
                        goto error_exit;
                    }
                    break;
            }
            break;
    }

//ÄÄÄ Cleanup
    if (work)
        delete [] work;

    iff->leaveform();
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
// XFParseXEB - write                                                       ³
//                                                                          ³
// Writes a XEB format bitmap to the file object.                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseXEB::write(XFBitmap *b)
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

xf_error_codes XFParseXEB::write(XFParseIFF *iff, XFBitmap *b)
{
    int             locked=0;
    xf_error_codes  err;
    byte            *work=0;
    ulong           size=0;
    XFXEBHeader     header;

    if (!b)
        b = bm;

    if (!b->width || !b->height)
        return (errorn=XF_ERR_NOTSUPPORTED);

    switch (b->bpp)
    {
        case XFBM_BPP_MONO:
        case XFBM_BPP_8BIT:
        case XFBM_BPP_15BIT:
        case XFBM_BPP_24BIT:
        case XFBM_BPP_32BIT:
            break;
        default:
            return (errorn=XF_ERR_NOTSUPPORTED);
    }

//ÄÄ Enter form
    if (iff->newform(iff->makeid('X','F','E','B')))
    {
        errorn=iff->error();
        return errorn;
    }

//ÄÄÄ Lock bitmap
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

//ÄÄÄ Compress data to determine if compression will work ÄÄÄ
    if (!b->data)
    {
        if (!locked)
            b->unlock();
        return (errorn=XF_ERR_INVALIDIMAGE);
    }

    size = (b->bpp == XFBM_BPP_MONO)
           ? (((b->width + 7) >> 3) * b->height)
           : (b->width * b->height * b->bpp);

    work=new byte[size];
    if (!work)
    {
        err=XF_ERR_NOMEMORY;
        goto error_exit;
    }

    switch (b->bpp)
    {
        case XFBM_BPP_MONO:
            size=compress_rle_mono(b->width,b->height,b->data,work);
            break;
        case XFBM_BPP_8BIT:
            size=compress_rle_8bpp(b->width,b->height,b->data,work);
            break;
        case XFBM_BPP_15BIT:
            size=compress_rle_16bpp(b->width,b->height,b->data,work);
            break;
        case XFBM_BPP_24BIT:
            size=compress_rle_24bpp(b->width,b->height,b->data,work);
            break;
        case XFBM_BPP_32BIT:
            size=compress_rle_32bpp(b->width,b->height,b->data,work);
            break;
        default:
            size=0;
            break;
    }

    if (!size)
    {
        delete [] work;
        work=0;
    }

//ÄÄÄ Write header ÄÄÄ
    memset(&header,0,sizeof(header));
    header.version = XFEB_VERSION;
    header.width = b->width;
    header.height = b->height;
    header.bpp = b->bpp;
    header.compress = (work) ? XF_XEB_COMPRESS_RLE : XF_XEB_COMPRESS_NONE;

    err=iff->write(iff->makeid('H','D','R',' '),&header,sizeof(header));
    if (err)
    {
        goto error_exit;
    }

//ÄÄÄ Palette data
    if (b->bpp == XFBM_BPP_8BIT)
    {
        if (!b->pal)
        {
            err=XF_ERR_INVALIDPALETTE;
            goto error_exit;
        }
    
        err=iff->write(iff->makeid('P','A','L',' '),b->pal,256*sizeof(dword));
        if (err)
        {
            goto error_exit;
        }
    }
    
//ÄÄÄ Image data
    if (work)
    {
        assert(header.compress == XF_XEB_COMPRESS_RLE);
        err=iff->write(iff->makeid('B','O','D','Y'),work,size);
    }
    else
    {
        assert(header.compress == XF_XEB_COMPRESS_NONE);

        size = (b->bpp == XFBM_BPP_MONO)
               ? (((b->width + 7) >> 3) * b->height)
               : (b->width * b->height * b->bpp);

        err=iff->write(iff->makeid('B','O','D','Y'),b->data,size);
    }

    if (err)
        goto error_exit;

//ÄÄÄ Cleanup
    if (!locked)
        b->unlock();

    if (work)
        delete [] work;

    iff->leaveform();
    return XF_ERR_NONE;

//ÄÄ Exit
error_exit: ;

    if (!locked)
        b->unlock();

    if (err)
        errorn=err;

    if (work)
        delete [] work;

    iff->leaveform();
    return err;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Monochrome °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseXEB - compress_rle_mono                                           ³
//                                                                          ³
// Compresses a monochrome pixel data set into a compressed worked buffer.  ³
// Returns the number of bytes in the compressed result or 0 if the         ³
// compressed version would take more than the original image size in bytes.³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ulong XFParseXEB::compress_rle_mono(ushort w, ushort h,
                                    byte *data, byte *cdata)
{
    assert(w > 0 && h > 0 && data && cdata);

    int     rsize = (w+7) >> 3;
    ulong   size = rsize*h;
    ulong   count = 0;
    
    byte *wptr = cdata;
    byte *ptr = data;

//ÄÄÄ Byte-based RLE
    for(int y=0; y < h; y++)
    {
        byte *lptr = 0;
        for(int i=0; i < rsize; ptr++)
        {
            //ÄÄÄ Scan for run
            byte *s=ptr;
            for(int j=0;
                (j < 127) && ((j+i+1) < rsize) && (*s == *(ptr+1));
                j++)
            {
                ptr++;
            }

            //ÄÄÄ Found run
            if (j > 0)
            {
                // Close last literal
                lptr=0;

                // Add rep run
                count += 2;
                if (count >= size)
                    return 0;

                *(wptr++) = (byte) (-(char)j);
                *(wptr++) = *ptr;

                i += j+1;
            }
            //ÄÄÄ Store literal
            else
            {
                if (lptr && *lptr < 127)
                {
                    // Add to literal
                    (*lptr)++;
                }
                else
                {
                    // Create new literal
                    if (++count >= size)
                        return 0;

                    lptr=wptr++;
                    *lptr = 0;
                }

                if (++count >= size)
                    return 0;

                *(wptr++) = *ptr;
                i++;
            }
        }
    }

    return count;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseXEB - uncompress_rle_mono                                         ³
//                                                                          ³
// Decompresses a monochrome compressed data set into a pixel data buffer.  ³
// Returns 0 if sucessful, or non-zero if an error occured.                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int XFParseXEB::uncompress_rle_mono(ushort w, ushort h, ulong csize,
                                    byte *cdata, byte *data)
{
    assert(w > 0 && h > 0 && csize > 0 && cdata > 0 && data > 0);

    byte *ptr=data;
    byte *eptr=data + ((w+7)>>3)*h;

//ÄÄÄ Byte-based RLE
    for(byte *wptr=cdata; wptr < cdata+csize; )
    {
        int j = (char) *(wptr++);
        if (j >= 0)
        {
            //ÄÄÄ Literial
            for(int i=0; i < j+1; i++)
            {
                if (ptr >= eptr)
                    return 1;

                *(ptr++) = *(wptr++);
            }
        }
        else
        {
            //ÄÄÄ Run
            j = -j+1;
            for(int i=0; i < j; i++)
            {
                if (ptr >= eptr)
                    return 1;

                *(ptr++) = *wptr;
            }
            wptr++;
        }
    }

    return 0;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°° 8 Bits Per Pixel °°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseXEB - compress_rle_8bpp                                           ³
//                                                                          ³
// Compresses a 8bpp pixel data set into a compressed worked buffer.        ³
// Returns the number of bytes in the compressed result or 0 if the         ³
// compressed version would take more than the original image size in bytes.³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ulong XFParseXEB::compress_rle_8bpp(ushort w, ushort h,
                                    byte *data, byte *cdata)
{
    assert(w > 0 && h > 0 && data && cdata);

    ulong   size = w*h;
    ulong   count = 0;
    
    byte *wptr = cdata;
    byte *ptr = data;

//ÄÄÄ Byte-based RLE
    for(int y=0; y < h; y++)
    {
        byte *lptr = 0;
        for(int i=0; i < w; ptr++)
        {
            //ÄÄÄ Scan for run
            byte *s=ptr;
            for(int j=0;
                (j < 127) && ((j+i+1) < w) && (*s == *(ptr+1));
                j++)
            {
                ptr++;
            }

            //ÄÄÄ Found run
            if (j > 0)
            {
                // Close last literal
                lptr=0;

                // Add rep run
                count += 2;
                if (count >= size)
                    return 0;

                *(wptr++) = (byte) (-(char)j);
                *(wptr++) = *ptr;

                i += j+1;
            }
            //ÄÄÄ Store literal
            else
            {
                if (lptr && *lptr < 127)
                {
                    // Add to literal
                    (*lptr)++;
                }
                else
                {
                    // Create new literal
                    if (++count >= size)
                        return 0;

                    lptr=wptr++;
                    *lptr = 0;
                }

                if (++count >= size)
                    return 0;

                *(wptr++) = *ptr;
                i++;
            }
        }
    }

    return count;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseXEB - uncompress_rle_8bpp                                         ³
//                                                                          ³
// Decompresses a 8bpp compressed data set into a pixel data buffer.        ³
// Returns 0 if sucessful, or non-zero if an error occured.                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int XFParseXEB::uncompress_rle_8bpp(ushort w, ushort h, ulong csize,
                                    byte *cdata, byte *data)
{
    assert(w > 0 && h > 0 && csize > 0 && cdata > 0 && data > 0);

    byte *ptr=data;
    byte *eptr=data + w*h;

//ÄÄÄ Byte-based RLE
    for(byte *wptr=cdata; wptr < cdata+csize; )
    {
        int j = (char) *(wptr++);
        if (j >= 0)
        {
            //ÄÄÄ Literial
            for(int i=0; i < j+1; i++)
            {
                if (ptr >= eptr)
                    return 1;

                *(ptr++) = *(wptr++);
            }
        }
        else
        {
            //ÄÄÄ Run
            j = -j+1;
            for(int i=0; i < j; i++)
            {
                if (ptr >= eptr)
                    return 1;

                *(ptr++) = *wptr;
            }
            wptr++;
        }
    }

    return 0;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°° 16 Bits Per Pixel °°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseXEB - compress_rle_16bpp                                          ³
//                                                                          ³
// Compresses a 16bpp pixel data set into a compressed worked buffer.       ³
// Returns the number of bytes in the compressed result or 0 if the         ³
// compressed version would take more than the original image size in bytes.³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ulong XFParseXEB::compress_rle_16bpp(ushort w, ushort h,
                                     byte *data, byte *cdata)
{
    assert(w > 0 && h > 0 && data && cdata);

    ulong   size = w*h*2;
    ulong   count = 0;
    
    byte *wptr = cdata;
    byte *ptr = data;

//ÄÄÄ Word-based RLE
    for(int y=0; y < h; y++)
    {
        byte *lptr = 0;
        for(int i=0; i < w; ptr += 2)
        {
            //ÄÄÄ Scan for run
            byte *s=ptr;
            for(int j=0;
                (j < 127) && ((j+i+1) < w)
                && (*s == *(ptr+2))
                && (*(s+1) == *(ptr+3));
                j++)
            {
                ptr += 2;
            }

            //ÄÄÄ Found run
            if (j > 0)
            {
                // Close last literal
                lptr=0;

                // Add rep run
                count += 3;
                if (count >= size)
                    return 0;

                *(wptr++) = (byte) (-(char)j);
                *(wptr++) = *ptr;
                *(wptr++) = *(ptr+1);

                i += j+1;
            }
            //ÄÄÄ Store literal
            else
            {
                if (lptr && *lptr < 127)
                {
                    // Add to literal
                    (*lptr)++;
                }
                else
                {
                    // Create new literal
                    if (++count >= size)
                        return 0;

                    lptr=wptr++;
                    *lptr = 0;
                }

                count += 2;
                if (count >= size)
                    return 0;

                *(wptr++) = *ptr;
                *(wptr++) = *(ptr+1);
                i++;
            }
        }
    }

    return count;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseXEB - uncompress_rle_16bpp                                        ³
//                                                                          ³
// Decompresses a 16bpp compressed data set into a pixel data buffer.       ³
// Returns 0 if sucessful, or non-zero if an error occured.                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int XFParseXEB::uncompress_rle_16bpp(ushort w, ushort h, ulong csize,
                                     byte *cdata, byte *data)
{
    assert(w > 0 && h > 0 && csize > 0 && cdata > 0 && data > 0);

    byte *ptr=data;
    byte *eptr=data + w*h*2;

//ÄÄÄ Word-based RLE
    for(byte *wptr=cdata; wptr < cdata+csize; )
    {
        int j = (char) *(wptr++);
        if (j >= 0)
        {
            //ÄÄÄ Literial
            for(int i=0; i < j+1; i++)
            {
                if (ptr+1 >= eptr)
                    return 1;

                *(ptr++) = *(wptr++);
                *(ptr++) = *(wptr++);
            }
        }
        else
        {
            //ÄÄÄ Run
            j = -j+1;
            for(int i=0; i < j; i++)
            {
                if (ptr+1 >= eptr)
                    return 1;

                *(ptr++) = *wptr;
                *(ptr++) = *(wptr+1);
            }
            wptr += 2;
        }
    }

    return 0;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°° 24 Bits Per Pixel °°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseXEB - compress_rle_24bpp                                          ³
//                                                                          ³
// Compresses a 24bpp pixel data set into a compressed worked buffer.       ³
// Returns the number of bytes in the compressed result or 0 if the         ³
// compressed version would take more than the original image size in bytes.³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ulong XFParseXEB::compress_rle_24bpp(ushort w, ushort h,
                                     byte *data, byte *cdata)
{
    assert(w > 0 && h > 0 && data && cdata);

    ulong   size = w*h*3;
    ulong   count = 0;
    
    byte *wptr = cdata;
    byte *ptr = data;

//ÄÄÄ 3-byte-based RLE
    for(int y=0; y < h; y++)
    {
        byte *lptr = 0;
        for(int i=0; i < w; ptr += 3)
        {
            //ÄÄÄ Scan for run
            byte *s=ptr;
            for(int j=0;
                (j < 127) && ((j+i+1) < w)
                && (*s == *(ptr+3))
                && (*(s+1) == *(ptr+4))
                && (*(s+2) == *(ptr+5));
                j++)
            {
                ptr += 3;
            }

            //ÄÄÄ Found run
            if (j > 0)
            {
                // Close last literal
                lptr=0;

                // Add rep run
                count += 4;
                if (count >= size)
                    return 0;

                *(wptr++) = (byte) (-(char)j);
                *(wptr++) = *ptr;
                *(wptr++) = *(ptr+1);
                *(wptr++) = *(ptr+2);

                i += j+1;
            }
            //ÄÄÄ Store literal
            else
            {
                if (lptr && *lptr < 127)
                {
                    // Add to literal
                    (*lptr)++;
                }
                else
                {
                    // Create new literal
                    if (++count >= size)
                        return 0;

                    lptr=wptr++;
                    *lptr = 0;
                }

                count += 3;
                if (count >= size)
                    return 0;

                *(wptr++) = *ptr;
                *(wptr++) = *(ptr+1);
                *(wptr++) = *(ptr+2);
                i++;
            }
        }
    }

    return count;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseXEB - uncompress_rle_24bpp                                        ³
//                                                                          ³
// Decompresses a 24bpp compressed data set into a pixel data buffer.       ³
// Returns 0 if sucessful, or non-zero if an error occured.                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int XFParseXEB::uncompress_rle_24bpp(ushort w, ushort h, ulong csize,
                                     byte *cdata, byte *data)
{
    assert(w > 0 && h > 0 && csize > 0 && cdata > 0 && data > 0);

    byte *ptr=data;
    byte *eptr=data + w*h*3;

//ÄÄÄ 3-byte-based RLE
    for(byte *wptr=cdata; wptr < cdata+csize; )
    {
        int j = (char) *(wptr++);
        if (j >= 0)
        {
            //ÄÄÄ Literial
            for(int i=0; i < j+1; i++)
            {
                if (ptr+2 >= eptr)
                    return 1;

                *(ptr++) = *(wptr++);
                *(ptr++) = *(wptr++);
                *(ptr++) = *(wptr++);
            }
        }
        else
        {
            //ÄÄÄ Run
            j = -j+1;
            for(int i=0; i < j; i++)
            {
                if (ptr+2 >= eptr)
                    return 1;

                *(ptr++) = *wptr;
                *(ptr++) = *(wptr+1);
                *(ptr++) = *(wptr+2);
            }
            wptr += 3;
        }
    }

    return 0;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°° 32 Bits Per Pixel °°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseXEB - compress_rle_32bpp                                          ³
//                                                                          ³
// Compresses a 32bpp pixel data set into a compressed worked buffer.       ³
// Returns the number of bytes in the compressed result or 0 if the         ³
// compressed version would take more than the original image size in bytes.³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ulong XFParseXEB::compress_rle_32bpp(ushort w, ushort h,
                                     byte *data, byte *cdata)
{
    assert(w > 0 && h > 0 && data && cdata);

    ulong   size = w*h*4;
    ulong   count = 0;
    
    byte *wptr = cdata;
    dword *ptr = (dword*)data;

//ÄÄÄ Dword-based RLE
    for(int y=0; y < h; y++)
    {
        byte *lptr = 0;
        for(int i=0; i < w; ptr++)
        {
            //ÄÄÄ Scan for run
            dword *s=ptr;
            for(int j=0;
                (j < 127) && ((j+i+1) < w)
                && (*s == *(ptr+1));
                j++)
            {
                ptr++;
            }

            //ÄÄÄ Found run
            if (j > 0)
            {
                // Close last literal
                lptr=0;

                // Add rep run
                count += 5;
                if (count >= size)
                    return 0;

                *(wptr++) = (byte) (-(char)j);
                *(wptr++) = *((byte*)ptr);
                *(wptr++) = *(((byte*)ptr)+1);
                *(wptr++) = *(((byte*)ptr)+2);
                *(wptr++) = *(((byte*)ptr)+3);

                i += j+1;
            }
            //ÄÄÄ Store literal
            else
            {
                if (lptr && *lptr < 127)
                {
                    // Add to literal
                    (*lptr)++;
                }
                else
                {
                    // Create new literal
                    if (++count >= size)
                        return 0;

                    lptr=wptr++;
                    *lptr = 0;
                }

                count += 4;
                if (count >= size)
                    return 0;

                *(wptr++) = *((byte*)ptr);
                *(wptr++) = *(((byte*)ptr)+1);
                *(wptr++) = *(((byte*)ptr)+2);
                *(wptr++) = *(((byte*)ptr)+3);
                i++;
            }
        }
    }

    return count;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseXEB - uncompress_rle_32bpp                                        ³
//                                                                          ³
// Decompresses a 32bpp compressed data set into a pixel data buffer.       ³
// Returns 0 if sucessful, or non-zero if an error occured.                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int XFParseXEB::uncompress_rle_32bpp(ushort w, ushort h, ulong csize,
                                     byte *cdata, byte *data)
{
    assert(w > 0 && h > 0 && csize > 0 && cdata > 0 && data > 0);

    byte *ptr=data;
    byte *eptr=data + w*h*4;

//ÄÄÄ Dword-based RLE
    for(byte *wptr=cdata; wptr < cdata+csize; )
    {
        int j = (char) *(wptr++);
        if (j >= 0)
        {
            //ÄÄÄ Literial
            for(int i=0; i < j+1; i++)
            {
                if (ptr+3 >= eptr)
                    return 1;

                *(ptr++) = *(wptr++);
                *(ptr++) = *(wptr++);
                *(ptr++) = *(wptr++);
                *(ptr++) = *(wptr++);
            }
        }
        else
        {
            //ÄÄÄ Run
            j = -j+1;
            for(int i=0; i < j; i++)
            {
                if (ptr+3 >= eptr)
                    return 1;

                *(ptr++) = *wptr;
                *(ptr++) = *(wptr+1);
                *(ptr++) = *(wptr+2);
                *(ptr++) = *(wptr+3);
            }
            wptr += 4;
        }
    }

    return 0;
}

//°±² End of module - xfxeb.cpp ²±°

