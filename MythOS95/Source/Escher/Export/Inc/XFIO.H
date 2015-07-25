//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//    Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
// xfio.h
//
//      This contains the C-callable low-level routines used by the
//      XFile class.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __XFIO_H
#define __XFIO_H    1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "debug.h"
#include "portable.h"
#include "xfdefs.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Structure needed by the xf_findfirst, xf_findnext routines.              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
struct xf_find_type {
       byte            xf_reserved[21];
       byte            xf_attrib;
       word            xf_wr_time;
       word            xf_wr_date;
       ulong           xf_size;
       char            xf_name[13];
};

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern xf_error_codes xf_last_error;

#ifdef __WATCOMC__
#pragma aux xf_last_error "*";
#endif

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// File-level i/o (used by XFile)                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

int xf_open(const char *name, dword flags);
int xf_opentmp(char *name, dword flags);
xf_error_codes xf_close(int fhandle);
xf_error_codes xf_flush(int fhandle);
ulong xf_read(int fhandle, void *ptr, ulong size);
ulong xf_write(int fhandle, const void *ptr, ulong size);
ulong xf_seek(int fhandle, int mode, long offset);

xf_error_codes xf_lock(int fhandle, ulong offset, ulong nbytes);
xf_error_codes xf_unlock(int fhandle, ulong offset, ulong nbytes);

ulong xf_getsize(int fhandle);
ulong xf_setsize(int fhandle, ulong size);

word xf_getfdate(int fhandle);
word xf_getftime(int fhandle);
xf_error_codes xf_setfdate(int fhandle, word date);
xf_error_codes xf_setftime(int fhandle, word time);

#ifdef __WATCOMC__
#pragma aux (_ASMSTKCALL_) xf_open;
#pragma aux (_ASMSTKCALL_) xf_opentmp;
#pragma aux (_ASMSTKCALL_) xf_close;
#pragma aux (_ASMSTKCALL_) xf_flush;
#pragma aux (_ASMSTKCALL_) xf_read;
#pragma aux (_ASMSTKCALL_) xf_write;
#pragma aux (_ASMSTKCALL_) xf_seek;
#pragma aux (_ASMSTKCALL_) xf_lock;
#pragma aux (_ASMSTKCALL_) xf_unlock;
#pragma aux (_ASMSTKCALL_) xf_getsize;
#pragma aux (_ASMSTKCALL_) xf_setsize;
#pragma aux (_ASMSTKCALL_) xf_getfdate;
#pragma aux (_ASMSTKCALL_) xf_getftime;
#pragma aux (_ASMSTKCALL_) xf_setfdate;
#pragma aux (_ASMSTKCALL_) xf_steftime;
#endif


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Utility routines for DOS file operations                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

xf_error_codes xf_remove(const char *name);
xf_error_codes xf_rename(const char *oldname, const char *newname);
int xf_exist(const char *name);
word xf_getattr(const char *name);
word xf_setattr(const char *name, word attr);

xf_error_codes xf_findfirst(const char *fname, int attr, struct xf_find_type *fileinfo);
xf_error_codes xf_findnext(struct xf_find_type *fileinfo);

char xf_getdrive(void);                    // Returns drive letter 'A'-...
ulong xf_getfreebytes(char drive);         // 0 for drive is current drive

char *xf_getdir(char *path);               // Buffer should be 67-bytes or more
xf_error_codes xf_chdir(const char *path);
xf_error_codes xf_mkdir(const char *path);
xf_error_codes xf_rmdir(const char *path);

xf_error_codes xf_abs_read(char drive, ulong sector, ushort len, void *data);
xf_error_codes xf_abs_write(char drive, ulong sector, ushort len, const void *data);

#ifdef __WATCOMC__
#pragma aux (_ASMSTKCALL_) xf_remove;
#pragma aux (_ASMSTKCALL_) xf_rename;
#pragma aux (_ASMSTKCALL_) xf_exist;
#pragma aux (_ASMSTKCALL_) xf_getattr;
#pragma aux (_ASMSTKCALL_) xf_setattr;
#pragma aux (_ASMSTKCALL_) xf_findfirst;
#pragma aux (_ASMSTKCALL_) xf_findnext;
#pragma aux (_ASMSTKCALL_) xf_getdrive;
#pragma aux (_ASMSTKCALL_) xf_getfreebytes;
#pragma aux (_ASMSTKCALL_) xf_getdir;
#pragma aux (_ASMSTKCALL_) xf_chdir;
#pragma aux (_ASMSTKCALL_) xf_mkdir;
#pragma aux (_ASMSTKCALL_) xf_rmdir;
#pragma aux (_ASMSTKCALL_) xf_abs_read;
#pragma aux (_ASMSTKCALL_) xf_abs_write;
#endif


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Miscellaneous routines                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

char *xf_getenv(const char *varname);
char *xf_searchenv(const char *filename, const char *env_var, char *path);

char *xf_makepath(char *path, const char *drive, const char *dir, const char *fname, const char *ext);
void xf_splitpath(const char *path, char *drive, char *dir, char *fname, char *ext);

#ifdef __WATCOMC__
#pragma aux (_ASMSTKCALL_) xf_getenv;
#pragma aux (_ASMSTKCALL_) xf_putenv;
#pragma aux (_ASMSTKCALL_) xf_searchenv;
#pragma aux (_ASMSTKCALL_) xf_makepath;
#pragma aux (_ASMSTKCALL_) xf_splitpath;
#endif


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Error return routine for low-level i/o functions                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

xf_error_codes xf_error(void);

#ifdef __WATCOMC__
#pragma aux (_ASMSTKCALL_) xf_error;

#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#ifdef __cplusplus
};
#endif

#endif

//°±² End of header - xfio.h ²±°

