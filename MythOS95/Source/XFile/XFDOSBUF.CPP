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
// xfdosbuf.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <assert.h>
#include <string.h>

#include "xfbase.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define XF_BUFFINIT 1024

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Constructor for the buffered DOS file object.                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
XFileDOSBuff::XFileDOSBuff() : XFileDOS()
{
    end=next=data=0;
    buffSize=0;
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Destructor for the buffered DOS file object.                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
XFileDOSBuff::~XFileDOSBuff()
{
//ÄÄÄ Close the file handle, if open ÄÄÄ
    if (sFlags & XF_STATUS_OPEN)
        close();
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFileDOSBuff - open                                                      ³
//                                                                          ³
// Opens file handle for object.  Returns 0 if ok, error number otherwise.  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFileDOSBuff::open(const char *name, dword flags)
{
    xf_error_codes  err;

//ÄÄ Perform base open
    err=XFileDOS::open(name,flags);
    if (err)
        return err;

//ÄÄ Allocate buffer space
    data = new byte [XF_BUFFINIT];
    if (!data)
    {
        errorn=XF_ERR_NOMEMORY;
        close();
        return errorn;
    }
    buffSize = XF_BUFFINIT;
    next = end = data;

    sFlags &= ~(XF_STATUS_DIRTY|XF_STATUS_LASTREAD|XF_STATUS_LASTWRITE);

    return XF_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFileDOSBuff - opentmp                                                   ³
//                                                                          ³
// Opens file handle for object with temporary filename.  Returns 0 if ok,  ³
// error number otherwise.                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFileDOSBuff::opentmp (const char *name, dword flags)
{
    xf_error_codes  err;

//ÄÄ Perform base open
    err=XFileDOS::opentmp(name,flags);
    if (err)
        return err;

//ÄÄ Allocate buffer space
    data = new byte [XF_BUFFINIT];
    if (!data)
    {
        errorn=XF_ERR_NOMEMORY;
        close();
        return errorn;
    }
    buffSize = XF_BUFFINIT;
    next = end = data;

    sFlags &= ~(XF_STATUS_DIRTY|XF_STATUS_LASTREAD|XF_STATUS_LASTWRITE);

    return XF_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFileDOSBuff - close                                                     ³
//                                                                          ³
// Closes a file handle for object.  Returns 0 if ok, error number otherwise³
// If STATUS_KILL is active, then the file is killed on close.              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFileDOSBuff::close ()
{
    xf_error_codes  err=XF_ERR_NONE;

    if (!(sFlags & XF_STATUS_OPEN))
        return XF_ERR_NOTOPEN;

//ÄÄ Perform flush, if needed
    if (sFlags & XF_STATUS_WRITE)
        err=flush();

//ÄÄ Free buffer
    if (data)
    {
        delete [] data;
        next=end=data=0;
        buffSize=0;
    }

//ÄÄ Perform base close
    if (err)
        XFileDOS::close();
    else
        err=XFileDOS::close();

    return err;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFileDOSBuff - flush                                                     ³
//                                                                          ³
// Flushes any buffered writes and forces DOS to update it's structures.    ³
// Returns 0 if ok, error number otherwise.                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFileDOSBuff::flush ()
{
    xf_error_codes  err = XF_ERR_NONE;

    if (!(sFlags & XF_STATUS_OPEN))
        return XF_ERR_NOTOPEN;

    assertMyth("XFileDOSBuff::flush assumes buffer exists",
               data);

    if (!(sFlags & XF_STATUS_WRITE))
    {
        return XF_ERR_NONE;
    }

    if (sFlags & XF_STATUS_LASTWRITE && ((next - data) > 0))
    {
        if (XFileDOS::write (data,next - data) != ulong (next-data))
        {
            err = XF_ERR_WRITEFAULT;
            errorn = err;
        }
    }

    next = end = data;
    sFlags &= ~(XF_STATUS_DIRTY|XF_STATUS_LASTWRITE);

//ÄÄ Perform base flush
    if (err)
        XFileDOS::flush();
    else
        err=XFileDOS::flush();

    return err;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFileDOSBuff - read                                                      ³
//                                                                          ³
// Read a block of the given size from the open file.                       ³
// Returns number of bytes read or 0 if error.                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ulong XFileDOSBuff::read (void *ptr, ulong size)
{
    ulong   t;
    ulong   ns;
    byte    *p = (byte*)ptr;

    assertMyth("XFileDOSBuff::read assumes buffer exists",
               data);

    if (!size || !(sFlags & XF_STATUS_READ))
        return 0;

    if (sFlags & XF_STATUS_LASTWRITE)
    {
        if (flush())
            return 0;
    }

    sFlags |= XF_STATUS_LASTREAD;

    for(ns=size; ns > 0;)
    {
        if (next >= end)
        {
            t=XFileDOS::read(data,buffSize);
            if (!t)
                break;
            next = data;
            end = data + t;
        }

        t = end-next;
        if (ns < t)
            t = ns;

        memcpy(p, next, t);
        p += t;
        next += t;
        ns -= t;
    }

    return (size - ns);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFileDOSBuff - write                                                     ³
//                                                                          ³
// Write a block of the given size to the open file.                        ³
// Returns number of bytes written or 0 if error.                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ulong XFileDOSBuff::write (const void *ptr, ulong size)
{
    ulong   t;
    ulong   ns;
    byte    *p = (byte*)ptr;

    assertMyth("XFileDOSBuff::write assumes buffer exists",
               data);

    if (!size || !(sFlags & XF_STATUS_WRITE))
        return 0;

    if (sFlags & XF_STATUS_LASTREAD)
    {
        seek_cur(0);
    }

    for(ns=size; ns > 0;)
    {
        if (next >= end)
        {
            if (sFlags & XF_STATUS_LASTWRITE && ((next - data) > 0))
            {
                if (XFileDOS::write(data,next - data) != ulong (next-data))
                {
                    errorn = XF_ERR_WRITEFAULT;
                    return 0;
                }
            }

            sFlags |= XF_STATUS_DIRTY|XF_STATUS_LASTWRITE;
            next = data;
            end = data + buffSize;
        }

        t = end-next;
        if (ns < t)
            t = ns;

        memcpy(next, p, t);
        p += t;
        next += t;
        ns -= t;
    }

    return (size - ns);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFileDOSBuff - seek                                                      ³
//                                                                          ³
// Seeks to an offset in the file (0=set, 1=current, 2=end)                 ³
// Returns -1 if error, offset within file otherwise.                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ulong XFileDOSBuff::seek(long offset, int mode)
{
    xf_error_codes  err;

//ÄÄ Perform flush, if needed
    if (sFlags & XF_STATUS_LASTWRITE)
    {
        err=flush();
        if (err) 
            return err;
    }
    else if (sFlags & XF_STATUS_LASTREAD)
    {
        if (mode == 1)
        {
            offset -= (long)(end-next);
        }

        sFlags &= ~XF_STATUS_LASTREAD;
        next = end = data;
    }

//ÄÄ Perform base seek
    return XFileDOS::seek(offset,mode);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFileDOSBuff - setbuffersize                                             ³
//                                                                          ³
// Sets the size of the buffer based on the input size, forcing it to a 1K  ³
// boundary.                                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ulong XFileDOSBuff::setbuffersize(ulong size)
{
    byte *nb;

    if (!(sFlags & XF_STATUS_OPEN))
        return XF_ERR_NOTOPEN;

    assertMyth("XFileDOSBuff::setbuffersize assumes buffer exists",
               data);

    size &= 0xfffffe00;
    if (size < XF_BUFFINIT)
        size = XF_BUFFINIT;

    seek_cur(0);

    nb = new byte[size];
    if (nb)
    {
        delete [] data;
        data = nb;
        buffSize = size;
    }

    return buffSize;
}


//°±² End of module - xfdosbuf.cpp ²±°

