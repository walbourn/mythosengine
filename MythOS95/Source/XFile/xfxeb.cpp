//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//            Copyright (c) 1994-1996 by Charybdis Enterprises, Inc.
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
// xfxeb.cpp
//
//     Contains code for working with Charybdis' XEB form, which is
//     a custom RLE format.
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
    int             i, j;
    byte            *ptr, *wptr, *eptr;
    xf_error_codes  err;
    byte            *work=0;
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
        || header.bpp != 1)  
    {
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
        b->release();
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

//ÄÄÄ Image data
    if (iff->seekchunk(iff->makeid('B','O','D','Y'))
        || !iff->chunkSize)
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

    if ((work = new byte[iff->chunkSize])==NULL)
    {
        b->release();
        err=XF_ERR_NOMEMORY;
        goto error_exit;
    }

    err=iff->read(work);
    if (err)
    {
        err=XF_ERR_INVALIDIMAGE;
        goto error_exit;
    }

    ptr=b->data;
    eptr=b->data + b->width*b->height*b->bpp;
    for(wptr=work; wptr < work+iff->chunkSize; )
    {
        j = (char) *(wptr++);
        if (j >= 0)
        {
            // Literial
            for(i=0; i < j+1; i++)
            {
                if (ptr >= eptr)
                {
                    err=XF_ERR_INVALIDIMAGE;
                    goto error_exit;
                }
                *(ptr++) = *(wptr++);
            }
        }
        else
        {
            // Run
            j = -j+1;
            for(i=0; i < j; i++)
            {
                if (ptr >= eptr)
                {
                    err=XF_ERR_INVALIDIMAGE;
                    goto error_exit;
                }
                *(ptr++) = *wptr;
            }
            wptr++;
        }
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
    int             i, j;
    int             y;
    int             locked=0;
    byte            *s;
    byte            *ptr, *wptr, *lptr;
    xf_error_codes  err;
    byte            *work=0;
    dword           size;
    XFXEBHeader     header;

    if (!b)
        b = bm;

    if (b->bpp != 1)
        return XF_ERR_NOTSUPPORTED;

//ÄÄ Enter form
    if (iff->newform(iff->makeid('X','F','E','B')))
    {
        errorn=iff->error();
        return errorn;
    }

//ÄÄÄ Write header ÄÄÄ
    memset(&header,0,sizeof(header));
    header.version = XFEB_VERSION;
    header.width = b->width;
    header.height = b->height;
    header.bpp = b->bpp;

    err=iff->write(iff->makeid('H','D','R',' '),&header,sizeof(header));
    if (err)
        goto error_exit;

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
 
//ÄÄÄ Palette data
    if (!b->palhandle)
    {
        if (!locked)
            b->unlock();
        return (errorn=XF_ERR_INVALIDPALETTE);
    }
    
    err=iff->write(iff->makeid('P','A','L',' '),b->pal,256*sizeof(dword));
    if (err)
    {
        if (!locked)
            b->unlock();
        goto error_exit;
    }
    
//ÄÄÄ Image data
    if (!b->handle)
    {
        if (!locked)
            b->unlock();
        return (errorn=XF_ERR_INVALIDIMAGE);
    }

    size = b->height * (b->width + (b->width << 1));
    assertMyth("XFParseXEB::write expected positive result of workspace computation",
               size);
    work=new byte[size];
    if (!work)
    {
        err=XF_ERR_NOMEMORY;
        if (!locked)
            b->unlock();
        goto error_exit;
    }

    for(y=0, wptr=work, ptr = b->data; y < b->height; y++)
    {
        for(i=0, lptr=0; i < b->width; ptr++)
        {
            for(s=ptr, j=0;
                (j < 127) && ((j+i+1) < b->width) && (*s == *(ptr+1));
                j++)
            {
                ptr++;
            }

            // Found reps
            if (j > 0)
            {
                // Close last literal
                lptr=0;

                // Add rep run
                *(wptr++) = (byte) (-(char)j);
                *(wptr++) = *ptr;

                i += j+1;
            }
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
                    lptr=wptr++;
                    *lptr = 0;
                }

                *(wptr++) = *ptr;
                i++;
            }
            assert(wptr <= work+size);
        }
    }

    err=iff->write(iff->makeid('B','O','D','Y'),work,wptr-work);
    if (err)
        goto error_exit;

//ÄÄÄ Cleanup
    if (work)
        delete [] work;

    iff->leaveform();
    return XF_ERR_NONE;

//ÄÄ Exit
error_exit: ;

    iff->leaveform();

    if (err)
        errorn=err;

    if (work)
        delete [] work;

    return err;
}

//°±² End of module - xfxeb.cpp ²±°

