//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
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
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// Created by Chuck Walbourn
// Ported to Windows by Dan Higdon
//
// xfiofmsc.c
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//                                
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "xfio.h"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// int xf_exist(const char *name)                                           �
//                                                                          �
// Tests for existance of the file.                                         �
//                                                                          �
// Returns 1 if exists, 0 if it does not.                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int xf_exist (const char *name)
{
    return GetFileAttributes (name) != (DWORD)-1;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// xf_error_codes xf_lock(int fhandle, ulong offset, ulong nbytes);         �
//                                                                          �
// Locks a region of the file, if possible.                                 �
//                                                                          �
// Returns 0 if ok, XF_ERR_FUNCINVALID, XF_ERR_INVALIDHANDLE,               �
// XF_ERR_LOCKVIOLATION, or XF_ERR_SHAREBUFFEROVERFLOW                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
xf_error_codes xf_lock (HANDLE fhandle, ulong offset, ulong nbytes)
{
    if (LockFile (fhandle, offset, 0, nbytes, 0))
        return 0;

    xf_last_error = GetLastError ();
    return xf_last_error;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// xf_error_codes xf_remove(const char *name);                              �
//                                                                          �
// Removes (unlinks) the file.                                              �
//                                                                          �
// Returns 0 if ok, XF_ERR_FILENOTFOUND, XF_ERR_PATHNOTFOUND,               �
// or XF_ERR_ACCESSDENIED                                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
xf_error_codes xf_remove (const char *name)
{
    if (DeleteFile (name))
        return 0;

    xf_last_error = GetLastError ();
    return xf_last_error;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// xf_error_codes xf_rename(const char *oldname, const char *newname);      �
//                                                                          �
// Renames the file.                                                        �
//                                                                          �
// Returns 0 if ok, XF_ERR_FILENOTFOUND, XF_ERR_PATHNOTFOUND,               �
// XF_ERR_ACCESSDENIED, or XF_ERR_NOTSAMEDEVICE                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
xf_error_codes xf_rename (const char *oldname, const char *newname)
{
    if (MoveFile (oldname, newname))
        return 0;

    xf_last_error = GetLastError ();
    return xf_last_error;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// xf_error_codes xf_unlock(int fhandle, ulong offset, ulong nbytes);       �
//                                                                          �
// Unlocks a region of the file, if possible.                               �
//                                                                          �
// Returns 0 if ok, XF_ERR_FUNCINVALID, XF_ERR_INVALIDHANDLE,               �
// XF_ERR_LOCKVIOLATION, or XF_ERR_SHAREBUFFEROVERFLOW                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
xf_error_codes xf_unlock (HANDLE fhandle, ulong offset, ulong nbytes)
{
    if (UnlockFile (fhandle, offset, 0, nbytes, 0))
        return 0;

    xf_last_error = GetLastError ();
    return xf_last_error;
}

//葦� End of module - xfiofmsc.c 憶�

