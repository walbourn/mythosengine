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
// Ported to Windows by Dan Higdon
//
// xfiofind.c
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "xfio.h"
#include <assert.h>

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// xf_error_codes xf_findfirst(const char *fname, int attr,                 ³
//                  struct xf_find_type *fileinfo);                         ³
//                                                                          ³
// Starts a file search based on a wildcard.                                ³
//                                                                          ³
// Returns 0 if ok, XF_ERR_FILENOTFOUND, XF_ERR_PATHNOTFOUND,               ³
// or XF_ERR_NOMOREFILES                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes xf_findfirst (const char *fname, int attr,
                             struct xf_find_type *fileinfo)
{
    // If this context is in use, close it.
    if (fileinfo->xf_hFind != NULL)
        FindClose (fileinfo->xf_hFind);

    // Set up a pointer for backward compatability with MythOS
    fileinfo->xf_name = &fileinfo->xf_find.cFileName[0];

    // Start the search
    fileinfo->xf_hFind = FindFirstFile (fname, &fileinfo->xf_find);

    if (fileinfo->xf_hFind == INVALID_HANDLE_VALUE)
        return xf_last_error = GetLastError();

    // Stuff the fields for backwards compatability
    fileinfo->xf_size   = fileinfo->xf_find.nFileSizeLow;
    fileinfo->xf_attrib = fileinfo->xf_find.dwFileAttributes;
    FileTimeToDosDateTime (&fileinfo->xf_find.ftLastWriteTime, 
                           &fileinfo->xf_wr_date, 
                           &fileinfo->xf_wr_time);
    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// xf_error_codes xf_findnext(struct xf_find_type *fileinfo);               ³
//                                                                          ³
// Continues a file search based on a wildcard.                             ³
//                                                                          ³
// Returns 0 if ok, or XF_ERR_NOMOREFILES                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes xf_findnext (struct xf_find_type *fileinfo)
{
    assertMyth("xf_findnext assumes valid find handle in fileinfo",
               fileinfo->xf_hFind != INVALID_HANDLE_VALUE);

    if (FindNextFile (fileinfo->xf_hFind, &fileinfo->xf_find))
    {
        // Stuff the fields for backwards compatability
        fileinfo->xf_size   = fileinfo->xf_find.nFileSizeLow;
        fileinfo->xf_attrib = fileinfo->xf_find.dwFileAttributes;
        FileTimeToDosDateTime (&fileinfo->xf_find.ftLastWriteTime, 
                               &fileinfo->xf_wr_date, 
                               &fileinfo->xf_wr_time);
        return 0;
    }

    FindClose (fileinfo->xf_hFind);
    fileinfo->xf_hFind = INVALID_HANDLE_VALUE;
    return XF_ERR_NOMOREFILES;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// xf_error_codes xf_findclose(struct xf_find_type *fileinfo);              ³
//                                                                          ³
// Ends the file file search, freeing any resources.                        ³
//                                                                          ³
// Returns 0 if ok, or XF_ERR_INVALIDHANDLE                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes xf_findclose (struct xf_find_type *fileinfo)
{
    if (fileinfo->xf_hFind == INVALID_HANDLE_VALUE)
        return XF_ERR_INVALIDHANDLE;

    FindClose (fileinfo->xf_hFind);
    return 0;
}

//°±² End of module - xfiofind.c ²±°

