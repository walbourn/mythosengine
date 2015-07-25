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
// xfcel.cpp
//
// .CEL files are Autodesk Animator files used by 3D Studio for
// textures in many materials.  There is an Autodesk Animator Pro
// .CEL file that is actually a .FLC file.  This code only supports
// the .CEL file from Autodesk Animator.  This code will also
// read Autodesk Animator .PIC files.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <string.h>

#include "xfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

struct Header
{
   word    type;       // 0x9119 is magic tag for .CEL
   word    width;
   word    height;
   word    xcoord;
   word    ycoord;
   byte    depth;
   byte    compress;
   dword   datasize;
   char    reserved[16];
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
// XFParseCEL - read                                                        ³
//                                                                          ³
// Reads a CEL format bitmap from the file object.                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseCEL::read(XFBitmap *b)
{
    ushort xcoord, ycoord;

    return read(xcoord, ycoord, b);
}

xf_error_codes XFParseCEL::read(ushort &xcoord, ushort &ycoord, XFBitmap *b)
{
    int             i;
    byte            *ptr;
    struct  Header  header;
    byte            work[3*256];

    if (!b)
        b = bm;

//ÄÄÄ Read file header ÄÄÄ
    if (xf->read(&header,sizeof(Header)) != sizeof(Header))
        return (errorn=xf->error());

//ÄÄÄ Verify valid file header ÄÄÄ
    if (header.type != 0x9119)
        return (errorn=XF_ERR_INVALIDHEADER);

//ÄÄÄ Check for unsupported formats ÄÄÄ
    if (header.compress
        || header.depth != 8)
       return (errorn=XF_ERR_NOTSUPPORTED);

//ÄÄÄ Setup bitmap object ÄÄÄ
    b->release();

    b->flags=0;
    b->clrinuse=255;
    b->width = (ushort) header.width;
    b->height = (ushort) header.height;
    b->bpp = XFBM_BPP_8BIT;

    xcoord = header.xcoord;
    ycoord = header.ycoord;

//ÄÄÄ Get palette data ÄÄÄ

    // Allocate memory
    b->palhandle = ivory_halloc(sizeof(dword)*256);
    if (!b->palhandle)
    {
        return (errorn=XF_ERR_NOMEMORY);
    }

    b->pal = (dword *)ivory_hlock(b->palhandle);
    if (!b->pal)
    {
        b->release();
        return (errorn=XF_ERR_LOCKFAILED);
    }

    memset(b->pal,0,sizeof(dword)*256);

    // Load palette into work-memory
    if (xf->read(work,3*256) != 3*256)
    {
        b->release();
        return (errorn=XF_ERR_INVALIDPALETTE);
    }

    // Move to standard Van Gogh order color dwords RGBX.
    // (original palette is always in range 0-63 for color components)
    for (i=0, ptr=(byte*)b->pal; i < 256; i++)
    {
        *(ptr++) = (byte)(work[i*3] << 2);      // red
        *(ptr++) = (byte)(work[i*3+1] << 2);    // green
        *(ptr++) = (byte)(work[i*3+2] << 2);    // blue
        *(ptr++) = 0;                           // na to make dword
    }

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

    // Load image directly into data area
    if (xf->read(b->data,b->width * b->height) != ulong (b->width*b->height))
    {
        b->release();
        return (errorn=XF_ERR_INVALIDIMAGE);
    }

    return XF_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseCEL - write                                                       ³
//                                                                          ³
// Writes a CEL format bitmap to the file object.                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseCEL::write(XFBitmap *b)
{
    return write(0,0,b);
}

xf_error_codes XFParseCEL::write(ushort xcoord, ushort ycoord, XFBitmap *b)
{
    int             i;
    byte            *ptr;
    int             locked=0;
    struct  Header  header;
    byte            work[3*256];

    if (!b)
        b = bm;

    if (b->bpp != XFBM_BPP_8BIT
        || !b->width || !b->height)
        return (errorn=XF_ERR_NOTSUPPORTED);

//ÄÄÄ Create/write file header ÄÄÄ
    memset(&header,0,sizeof(Header));
    header.type=0x9119;
    header.width=b->width;
    header.height=b->height;
    header.xcoord = xcoord;
    header.ycoord = ycoord;
    header.depth=8;
    header.datasize=b->width*b->height;

    if (xf->write(&header,sizeof(Header)) != sizeof(Header))
    {
        errorn=xf->error();
        return errorn;
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
 
//ÄÄÄ Write out palette ÄÄÄ
    if (!b->pal)
    {
        if (!locked)
            b->unlock();
        return (errorn=XF_ERR_INVALIDPALETTE);
    }
     
    for (i=0, ptr=(byte*)b->pal; i < 256; i++)
    {
        work[i*3]   = (byte)(*(ptr++) >> 2); // red
        work[i*3+1] = (byte)(*(ptr++) >> 2); // green
        work[i*3+2] = (byte)(*(ptr++) >> 2); // blue
        ptr++;                               // na to make dword
    }

    if (xf->write(work,3*256) != 3*256)
    {
        if (!locked)
            b->unlock();
        errorn=xf->error();
        return errorn;
    }

//ÄÄÄ Write out image ÄÄÄ
    if (!b->data)
    {
        if (!locked)
            b->unlock();
        return (errorn=XF_ERR_INVALIDIMAGE);
    }

    if (xf->write(b->data,b->width * b->height) != ulong (b->width*b->height))
    {
        if (!locked)
            b->unlock();
        errorn=xf->error();
        return errorn;
    }

    if (!locked)
        b->unlock();

    return XF_ERR_NONE;
}

//°±² End of module - xfcel.cpp ²±°

