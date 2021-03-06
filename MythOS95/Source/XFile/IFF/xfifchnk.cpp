//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
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
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// Created by Chuck Walbourn
//
// xfifchnk.cpp
//
// This contains the chunk-based movement and reading/writing for the
// XFParseIFF object.
//
// If the control flag has XF_IFF_RIFF set, then 'RIFF' is used instead
// of 'FORM' and the sizes are in Intel rather than Motorola format.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "xfile.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFParseIFF - seekchunk                                                   �
//                                                                          �
// Scans the current form-level for the given chunk id.  If found, then the �
// chunk is the current chunk.  If not found, then the current position is  �
// at the end of the form.                                                  �
//                                                                          �
// Returns 0 or error condition.                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
xf_error_codes XFParseIFF::seekchunk(dword id)
{
    while(!next())
    {
        if (chunkid==id)
            return XF_ERR_NONE;
    }

    return XF_ERR_CHUCKNOTFOUND;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFParseIFF - read                                                        �
//                                                                          �
// Reads the current chunk from the file into a given memory buffer.        �
//                                                                          �
// Returns 0 or error condition.                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
xf_error_codes XFParseIFF::read(void *ptr)
{
    ulong   r;

    if (!ichunkSize)
    {
        errorn=XF_ERR_UNEXPECTEDEOF;
        return errorn;
    }

    r=xf->read(ptr,ichunkSize);

    // Handle pad byte for odd
    if ( ichunkSize & 0x1
         && !(cflags & XF_IFF_NOPAD))
    {
        icurPos = xf->seek_cur(1);
    }
    else
    {
        icurPos = xf->tell();
    }

    ichunkSize=0;
    if (r == -1)
    {
        errorn=xf->error();
        return errorn;
    }

    return XF_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFParseIFF - write                                                       �
//                                                                          �
// Writes a chunk, either overwriting a chunk in place or appending to the  �
// the file at the current level.                                           �
//                                                                          �
// Returns 0 or error condition.                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
xf_error_codes XFParseIFF::write(dword id, const void *ptr, ulong size)
{
    ulong   i;
    ulong   w;
    char    buff[8];

//陳� Check to see if we are in the middle of a form/chunk (overwrite
//陳� in place allowed).
    if (chunkid)
    {
        if (chunkid != id || ichunkSize != size)
        {
            errorn=XF_ERR_WRITENOTALLOWED;
            return errorn;
        }

        w=xf->write(ptr,size);

        // Handle pad byte for odd
        if (size & 0x1
            && !(cflags & XF_IFF_NOPAD))
        {
            buff[0]=0;
            xf->write(buff,1);
        }

        ichunkSize=0;
        icurPos = xf->tell();
        if (w == -1)
        {
            errorn=xf->error();
            return errorn;
        }

        return XF_ERR_NONE;
    }

//陳� Handle append at current form level

   //陳� Write chunk header
    *((dword *)&buff[0]) = id;
    *((dword *)&buff[4]) =
                (ulong) ((cflags & XF_IFF_RIFF) ? size : swapendian(size));
    if ( xf->write(buff,8) != 8)
    {
        errorn=xf->error();
        return errorn;
    }

    //陳� Write chunk
    w=xf->write(ptr,size);

    // Handle pad byte for odd
    if (size & 0x1
        && !(cflags & XF_IFF_NOPAD))
    {
        buff[0]=0;
        xf->write(buff,1);
    }

    ichunkSize=0;
    icurPos = xf->tell();
    if (w != size)
    {
        errorn=xf->error();
        return errorn;
    }

    //陳� Update file length and current context length
    ilength += size + 8;
    for(i=idepth; i > 0; i--)
    {
        iforms[i-1].flags |= XF_IFFFORM_DIRTY;
        iforms[i-1].len += size + 8
                        + ((size & 0x1 && !(cflags & XF_IFF_NOPAD)) ? 1 : 0);
    }

    chunkSize=0;
    chunkid=0;

    return XF_ERR_NONE;
}

//葦� End of module - xfifchnk.cpp 憶�

