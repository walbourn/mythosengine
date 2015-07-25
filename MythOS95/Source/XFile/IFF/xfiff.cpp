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
// xfiff.cpp
//
// The XFParseIFF object provides reading and writing of the Electronic Arts
// 'IFF' file format.  FORMs are supported, but CATs and LISTs are ignored.
//
// If the control flag has XF_IFF_RIFF set, then 'RIFF' is used instead
// of 'FORM' and the sizes are in Intel rather than Motorola format.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "xfile.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseIFF - Contructor for the .INI object.                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
XFParseIFF::XFParseIFF(dword cf) :
    cflags(cf)
{
    xf=&xfile;
    initvars();
}

XFParseIFF::XFParseIFF(XFile *f, dword cf) :
    cflags(cf),
    xf(f)
{
    initvars();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseIFF - Destructor for the .INI object.                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
XFParseIFF::~XFParseIFF()
{
    end();
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseIFF - begin                                                       ³
//                                                                          ³
// Sets up for processing of the .IFF file.                                 ³
//                                                                          ³
// Returns 0 if ok, error number otherwise.                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseIFF::begin(void)
{
    char           buff[8];

    if (!(xf->status() & (XF_OPEN_READ|XF_OPEN_WRITE)))
    {
        errorn=XF_ERR_NEEDREADORWRITE;
        return errorn;
    }

//ÄÄÄ Get initial file statistics ÄÄÄ
    icurPos=xf->tell();
    ilength=xf->getsize();

//ÄÄÄ Check for IFF chunk-based file if non-zero length ÄÄÄ
    if (ilength)
    {
        //ÄÄÄ Read first id/size pair
        if (xf->read(buff,8) != 8)
        {
            goto invalid_iff;
        }

        //ÄÄÄ Check id is in valid IFF range
        if ((buff[0] < 0x20 || buff[0] > 0x7e)
            || (buff[1] < 0x20 || buff[1] > 0x7e)
            || (buff[2] < 0x20 || buff[2] > 0x7e)
            || (buff[3] < 0x20 || buff[3] > 0x7e))
        {
            goto invalid_iff;
        }

        //ÄÄÄ See if size exceeds size of file
        if (((ulong) ((cflags & XF_IFF_RIFF)
                      ? *((dword *)&buff[4])
                      : swapendian(*((dword *)&buff[4]))) + 8) > ilength)
        {
            goto invalid_iff;
        }

        //ÄÄÄ Reset to start of file
        xf->seek_set(icurPos);
    }

//ÄÄÄ return success ÄÄÄ
    return XF_ERR_NONE;

//ÄÄÄ invalid IFF ÄÄÄ
invalid_iff: ;
    errorn=XF_ERR_NOTIFF;
    return errorn;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseIFF - end                                                         ³
//                                                                          ³
// End processing of the .IFF file.                                         ³
//                                                                          ³
// Returns 0 if ok, error number otherwise.                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseIFF::end(void)
{
    xf_error_codes err;

//ÄÄÄ Must leave all open forms to ensure sizes are correct ÄÄÄ
    if (xf->status() & XF_STATUS_WRITE)
    {
        leaveform();
        while (idepth)
            leaveform();
    }

//ÄÄÄ Reset internal state ÄÄÄ
    initvars();

//ÄÄÄ Flush the filehandle ÄÄÄ
    err=xf->flush();
    if (err)
        errorn=err;

    return err;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseIFF - leaveform                                                   ³
//                                                                          ³
// Leaves the current form context.                                         ³
//                                                                          ³
// Returns 0 if ok, error number otherwise.                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseIFF::leaveform(void)
{
    ulong   w;
    XFForm  *f;
    char    buff[4];

    if (idepth > 0)
    {

//ÄÄÄ If FORM is dirty, must update file's FORM size count ÄÄÄ
        f=&iforms[idepth-1];

        if (f->flags & XF_IFFFORM_DIRTY)
        {

            *((dword *)&buff[0]) = (ulong)
                      ((cflags & XF_IFF_RIFF)
                       ? (f->len+4)
                       : swapendian(f->len+4));

            xf->seek_set(f->start-8);
            w=xf->write(buff,4);

            if (w != 4)
            {
                xf->seek_set(icurPos);
                errorn=xf->error();
                return errorn;
            }
        }

//ÄÄÄ Set current position to end of form ÄÄÄ
        w = f->start+f->len+((f->len & 0x1 & !(cflags & XF_IFF_NOPAD)) ? 1 : 0);
        icurPos=w;
        if (xf->seek_set(w) != w)
        {
            errorn=xf->error();
            return errorn;
        }

//ÄÄÄ Reduce depth ÄÄÄ
        idepth--;
        depth = idepth;

//ÄÄÄ Clear current chunk ÄÄÄ
        ichunkSize=0;
        chunkid=0;
        formid=(idepth) ? iforms[idepth-1].id : 0;
    }

    return XF_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseIFF - next                                                        ³
//                                                                          ³
// Moves the file to the next data block in the current form (or whole file ³
// if no current form).                                                     ³
//                                                                          ³
// Returns 0 or error condition.                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseIFF::next(void)
{
    char    buff[8];

//ÄÄÄ If chunkSize internal set, then skip previous unread chunk ÄÄÄ
    if (ichunkSize)
    {

        // Handle odd-byte padding
        if (ichunkSize & 0x1
            && !(cflags & XF_IFF_NOPAD))
            ichunkSize++;

        icurPos = xf->seek_cur(ichunkSize);
        ichunkSize=0;
    }

//ÄÄÄ Check for EOF ÄÄÄ
    if ( (!idepth && icurPos >= ilength)
        || (idepth && (icurPos - iforms[idepth-1].start) >= iforms[idepth-1].len) )
    {
        chunkid=0;
        errorn=XF_ERR_EOF;
        return errorn;
    }

//ÄÄÄ Read current chunk id/size pair ÄÄÄ
    if (xf->read(buff,8) != 8)
    {
        errorn=XF_ERR_UNEXPECTEDEOF;
        xf->seek_set(icurPos);
        return errorn;
    }

//ÄÄÄ Check id is in valid IFF range ÄÄÄ
    if ((buff[0] < 0x20 || buff[0] > 0x7e)
        || (buff[1] < 0x20 || buff[1] > 0x7e)
        || (buff[2] < 0x20 || buff[2] > 0x7e)
        || (buff[3] < 0x20 || buff[3] > 0x7e))
    {
        errorn=XF_ERR_INVALIDID;
        xf->seek_set(icurPos);
        return errorn;
    }
    chunkid = *((dword *)&buff[0]);

    icurPos += 8;

//ÄÄÄ Get chunk size ÄÄÄ
    chunkSize = ichunkSize = (ulong)
                    ((cflags & XF_IFF_RIFF)
                     ? *((dword *)&buff[4])
                     : swapendian(*((dword *)&buff[4])));

//ÄÄÄ Handle FORM/RIFF ÄÄÄ
    if (chunkid == ((cflags & XF_IFF_RIFF)
                    ? makeid('R','I','F','F')
                    : makeid('F','O','R','M')))
    {

        if ((ichunkSize < 4)
            || (xf->read(buff,4) != 4))
        {
            errorn=XF_ERR_TRUNCATEDCHUNK;
            return errorn;
        }

        xf->seek_set(icurPos);
        formid = *((dword *)&buff[0]);
    }

#if 0
//ÄÄÄ Check for chunk size too large for context ÄÄÄ
    if ( (!idepth && ((ichunkSize + icurPos) > ilength))
         || (idepth && ((ichunkSize +
             (icurPos - iforms[idepth-1].start)) > iforms[idepth-1].len)))
    {
        ichunkSize = (len-icurPos);
        errorn=XF_ERR_TRUNCATEDCHUNK;
        return errorn;
    }
#endif

    return XF_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseIFF - topofcontext                                                ³
//                                                                          ³
// Moves the pointer to the top of the current context.                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseIFF::topofcontext(int donext)
{
    ichunkSize=0;

    if (!idepth)
    {
        icurPos = xf->seek_set(0);
    }
    else
    {
        icurPos = xf->seek_set(iforms[idepth-1].start);
    }

    if (!donext)
        return XF_ERR_NONE;

    return next();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                           °°° Private °°°                                ³
// XFParseIFF - initvars                                                    ³
//                                                                          ³
// Sets the internal private members to initial values.                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void XFParseIFF::initvars(void)
{
    idepth=0;
    ichunkSize=0;
    depth=0;
    formid=0;
    chunkid=0;
    chunkSize=0;
}

//°±² End of module - xfiff.cpp ²±°

