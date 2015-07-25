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
// Ported to Windows by Dan Higdon
//
// xfiobase.c
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "xfio.h"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// HANDLE xf_open(const char *fname, dword flags);                          ³
//                                                                          ³
// Opens a DOS file for use by the other xf_ low-level routines.  Flags     ³
// determines the type of file opened and uses defines in the               ³
//                                                                          ³
//       name - Pointer to path/filename for the file to open.              ³
//                                                                          ³
//       flags -                                                            ³
//               XF_OPEN_READ     - Read file mode                          ³
//               XF_OPEN_WRITE    - Write file mode                         ³
//               XF_OPEN_APPEND   - Append to file if one exists (write)    ³
//               XF_OPEN_CREATE   - Create file if it doesn't exist         ³
//               XF_OPEN_EXCLUSIVE- Fails if creating file already existing ³
//               XF_OPEN_READONLY - File attributes                         ³
//               XF_OPEN_HIDDEN        (used for create as file,            ³
//               XF_OPEN_SYSTEM         used for open as mask)              ³
//               XF_OPEN_ARCHIVE                                            ³
//               XF_OPEN_SHAREABLE                                          ³
//               XF_OPEN_DENYALL  - Share mode                              ³
//               XF_OPEN_DENYWRITE                                          ³
//               XF_OPEN_DENYREAD                                           ³
//               XF_OPEN_DENYNONE                                           ³
//                                                                          ³
//               XF_OPEN_PRIVATE  - Inheritance (open only)                 ³
//                                                                          ³
// Returns INVALID_HANDLE_VALUE if failure, file handle otherwise.          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
HANDLE xf_open (const char *fname, dword flags)
{
    HANDLE  res;
    DWORD   dwAccess;
    DWORD   dwShare;
    DWORD   dwCreate;
    DWORD   dwAttrib;

    // Build the dwAccess parameter
    dwAccess = 0;
    if (flags & XF_OPEN_READ)
        dwAccess |= GENERIC_READ;
    if (flags & (XF_OPEN_WRITE | XF_OPEN_CREATE | XF_OPEN_APPEND))
        dwAccess |= GENERIC_WRITE;

    // Build the Share parameter
    dwShare = 0;
    switch (flags & 0xf0000000)
    {
    case XF_OPEN_DENYWRITE:
        dwShare = FILE_SHARE_READ;
        break;

    case XF_OPEN_DENYREAD:
        dwShare = FILE_SHARE_WRITE;
        break;

    case XF_OPEN_DENYNONE:
        dwShare = FILE_SHARE_READ | FILE_SHARE_WRITE;
        break;

    default:
        dwShare = 0;    // No sharing by default
        break;
    }

    // Build the dwCreate parameter
    if ((flags & XF_OPEN_EXCLUSIVE) && (flags & XF_OPEN_CREATE))
        dwCreate = CREATE_NEW;
    else if (flags & XF_OPEN_CREATE)
        dwCreate = CREATE_ALWAYS;
    else
        dwCreate = OPEN_EXISTING;

    // Build the attribute parameter
    dwAttrib = FILE_ATTRIBUTE_NORMAL;
    if (flags & XF_OPEN_READONLY)
        dwAttrib |= FILE_ATTRIBUTE_READONLY;
    if (flags & XF_OPEN_HIDDEN)
        dwAttrib |= FILE_ATTRIBUTE_HIDDEN;
    if (flags & XF_OPEN_SYSTEM)
        dwAttrib |= FILE_ATTRIBUTE_SYSTEM;
    if (flags & XF_OPEN_ARCHIVE)
        dwAttrib |= FILE_ATTRIBUTE_ARCHIVE;
    if (flags & XF_OPEN_KILL)
        dwAttrib |= FILE_FLAG_DELETE_ON_CLOSE;
    if (flags & XF_OPEN_RANDOM_ACCESS)
        dwAttrib |= FILE_FLAG_RANDOM_ACCESS;
    if (flags & XF_OPEN_SEQUENTIAL_ACCESS)
        dwAttrib |= FILE_FLAG_SEQUENTIAL_SCAN;

    res = CreateFile (fname, dwAccess, dwShare, NULL, dwCreate, dwAttrib, NULL);

    if (res == INVALID_HANDLE_VALUE)
        xf_last_error = GetLastError ();

    // If we're in append mode, then put us at the end of the file
    if (flags & XF_OPEN_APPEND)
        xf_seek (res, 2, 0);

    return res;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// HANLDE xf_opentmp(const char *fname, dword flags);                       ³
//                                                                          ³
// Opens a DOS file, generating a temporary filename.  Tempfile assumes that³
// CREATE and WRITE are implied.                                            ³
//                                                                          ³
//       name - Pointer to path.                                            ³
//                                                                          ³
//       flags -                                                            ³
//               same as xf_open                                            ³
//                                                                          ³
// Returns INVALID_HANDLE_VALUE if failure, file handle otherwise.          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
HANDLE xf_opentmp (const char *fname, dword flags)
{
    TCHAR   szTmpName[MAX_PATH];
    TCHAR   szTmpPath[MAX_PATH];

    if (GetTempPath (sizeof (szTmpPath), szTmpPath) != 0 &&
        GetTempFileName (szTmpPath, fname, 0, szTmpName) != 0)
        return xf_open (szTmpName, flags | XF_OPEN_WRITE & ~XF_OPEN_CREATE);

    xf_last_error = GetLastError ();
    return INVALID_HANDLE_VALUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ulong xf_read(int fhandle, void *ptr, ulong size);                       ³
//                                                                          ³
// Read data from file into buffer.                                         ³
//                                                                          ³
// Returns number of bytes read, 0 on eof, and -1 on error.                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ulong xf_read (HANDLE fhandle, void *ptr, ulong size)
{
    ulong res;

    if (ReadFile (fhandle, ptr, size, &res, NULL))
    {
        if (res == 0)
            xf_last_error = XF_ERR_EOF;
        return res;
    }

    xf_last_error = GetLastError();
    return (ulong)-1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ulong xf_write(int fhandle, const void *ptr, ulong size);                ³
//                                                                          ³
// Write data from a buffer into a file.                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ulong xf_write (HANDLE fhandle, const void *ptr, ulong size)
{
    DWORD res;

    if (WriteFile (fhandle, ptr, size, &res, NULL))
        return res;

    xf_last_error = GetLastError ();
    return (ulong)-1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ulong xf_seek(int fhandle, int mode, long offset);                       ³
//                                                                          ³
// Seeks to a given position in the file, with mode set to 0 for start,     ³
// 1 for current, 2 for eof relative movement.                              ³
//                                                                          ³
// Returns -1 if error, or offset from start of file.                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ulong xf_seek (HANDLE fhandle, int mode, long offset)
{
static const int translate_seekmode[] = { FILE_BEGIN, FILE_CURRENT, FILE_END };
    DWORD   res;

    res = SetFilePointer (fhandle, offset, NULL, translate_seekmode[mode & 3]);

    if (res == -1)
        xf_last_error = GetLastError();

    return res;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// xf_error_codes xf_flush(int fhandle);                                    ³
//                                                                          ³
// Flushes a file handle.                                                   ³
//                                                                          ³
// Returns 0 or error                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes xf_flush (HANDLE fhandle)
{
    if (FlushFileBuffers (fhandle))
        return 0;

    xf_last_error = GetLastError ();
    return xf_last_error;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// xf_error_codes xf_close(HANDLE fhandle);                                 ³
//                                                                          ³
// Closes a file handle.                                                    ³
//                                                                          ³
// Returns 0 or XF_ERR_INVALIDHANDLE                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes xf_close (HANDLE fhandle)
{
    if (CloseHandle (fhandle))
        return 0;

    return XF_ERR_INVALIDHANDLE;
}

//°±² End of module - xfiobase.c ²±°

