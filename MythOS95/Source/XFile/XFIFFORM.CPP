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
// xfifform.cpp
//
// This contains the form-based movement for the XFParseIFF object.
//
// If the control flag has XF_IFF_RIFF set, then 'RIFF' is used instead
// of 'FORM' and the sizes are in Intel rather than Motorola format.
//
// (leaveform is in the main module since it is always called by
//  the end() function).
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

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseIFF - seekform                                                    ³
//                                                                          ³
// Scans the current form-level for the given form id.  If found, then the  ³
// form is the current chunk.  If not found, then the current position is   ³
// at the end of the current form.                                          ³
//                                                                          ³
// Returns 0 or error condition.                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseIFF::seekform(dword id)
{
    while(!next())
    {
        if (chunkid == ((cflags & XF_IFF_RIFF)
                        ? makeid('R','I','F','F')
                        : makeid('F','O','R','M'))
             && formid==id)
            return XF_ERR_NONE;
    }

    return XF_ERR_FORMNOTFOUND;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseIFF - newform                                                     ³
//                                                                          ³
// Creates a new form and enters it.                                        ³
//                                                                          ³
// Returns 0 or error condition.                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseIFF::newform(dword id)
{
    ulong   i;
    ulong   w;
    XFForm  *f;
    char    buff[12];

//ÄÄÄ Check to see if we are in the middle of a form/chunk (overwrite
//ÄÄÄ not current allowed).

    if (chunkid)
    {
        errorn=XF_ERR_WRITENOTALLOWED;
        return errorn;
    }

//ÄÄÄ Make sure that FORM is not used as the FORM's id ÄÄÄ
    if (id == ((cflags & XF_IFF_RIFF)
               ? makeid('R','I','F','F')
               : makeid('F','O','R','M')))
    {
        errorn=XF_ERR_INVALIDID;
        return errorn;
    }

//ÄÄÄ If too deep, error ÄÄÄ
    if (idepth+1 >= XF_MAX_IFFDEPTH)
    {
        errorn=XF_ERR_MAXDEPTHREACHED;
        return errorn;
    }

//ÄÄÄ Write FORM empty entry (will be filled in later on leaveform()) ÄÄÄ
    *((dword *)&buff[0]) = (cflags & XF_IFF_RIFF)
                            ? makeid('R','I','F','F')
                            : makeid('F','O','R','M');
    *((dword *)&buff[4]) = 4;
    *((dword *)&buff[8]) = id;
    w=xf->write(buff,12);
    icurPos += 12;
    if (w == -1)
    {
        errorn=xf->error();
        return errorn;
    }

//ÄÄÄ Must set previous depths to DIRTY and increase size by 12
    for(i=idepth; i > 0; i--)
    {
        iforms[i-1].flags |= XF_IFFFORM_DIRTY;
        iforms[i-1].len += 12;
    }

//ÄÄÄ Setup context structure (array index is idepth-1 with 0 being full file)
    f=&iforms[idepth++];
    depth=idepth;
   
    f->id = id;
    f->flags = 0;
    f->start = icurPos;
    f->len = 0;

//ÄÄÄ Clear data in context ÄÄÄ
    formid = id;
    ichunkSize=0;
    chunkid=0;

    return XF_ERR_NONE;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseIFF - enterform                                                   ³
//                                                                          ³
// Enters the current FORM chunk, if any.                                   ³
//                                                                          ³
// Returns 0 or error condition.                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseIFF::enterform(void)
{
    XFForm  *f;
    char    buff[4];

//ÄÄÄ Make sure current chunk is an enterable form ÄÄÄ
    if (chunkid != ((cflags & XF_IFF_RIFF)
                    ? makeid('R','I','F','F')
                    : makeid('F','O','R','M')))
    {
        errorn=XF_ERR_INVALIDFORCHUNK;
        return errorn;
    }

//ÄÄÄ If too deep, error ÄÄÄ
    if (idepth+1 >= XF_MAX_IFFDEPTH)
    {
        errorn=XF_ERR_MAXDEPTHREACHED;
        return errorn;
    }

//ÄÄÄ Read FORM id ÄÄÄ
    if ((ichunkSize < 4)
        || (xf->read(buff,4) != 4))
    {
        errorn=XF_ERR_TRUNCATEDCHUNK;
        return errorn;
    }
    formid = *((dword *)&buff[0]);
    icurPos += 4;

//ÄÄÄ Setup context structure (array index is idepth-1 with 0 being full file)

    f=&iforms[idepth++];
    depth=idepth;
    
    f->id = formid;
    f->flags = 0;
    f->start = icurPos;
    f->len = ichunkSize - 4;

//ÄÄÄ Clear data in context ÄÄÄ
    ichunkSize=0;
    chunkid=0;

    return XF_ERR_NONE;
}

//°±² End of module - xfifform.cpp ²±°

