//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//            Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
//                             All Rights Reserved.
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
// xfdefs.h
//
//      This contains the public defines used by the XFile library.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __XFDEFS_H
#define __XFDEFS_H    1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "portable.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//--- Error values ---
typedef enum _xf_error_codes {
    XF_ERR_NONE                         =0,

                                        // 1-255 Reserved for DOS
    XF_ERR_FUNCINVALID                  =0x1,
    XF_ERR_FILENOTFOUND                 =0x2,
    XF_ERR_PATHNOTFOUND                 =0x3,
    XF_ERR_NOHANDLES                    =0x4,
    XF_ERR_ACCESSDENIED                 =0x5,
    XF_ERR_INVALIDHANDLE                =0x6,
    XF_ERR_MCBDESTROYED                 =0x7,
    XF_ERR_NOMEMORY                     =0x8,
    XF_ERR_MCBINVALID                   =0x9,
    XF_ERR_ENVINVALID                   =0xa,
    XF_ERR_FORMATINVALID                =0xb,
    XF_ERR_ACCESSCODEINVALID            =0xc,
    XF_ERR_DATAINVALID                  =0xd,
    XF_ERR_INVALIDDRIVE                 =0xf,
    XF_ERR_CANTREMOVECHDIR              =0x10,
    XF_ERR_NOTSAMEDEVICE                =0x11,
    XF_ERR_NOMOREFILES                  =0x12,
    XF_ERR_WRITEPROTECTED               =0x13,
    XF_ERR_UNKNOWNUNIT                  =0x14,
    XF_ERR_DRIVENOTREADY                =0x15,
    XF_ERR_UNKCOMMAND                   =0x16,
    XF_ERR_CRCERROR                     =0x17,
    XF_ERR_BADREQLEN                    =0x18,
    XF_ERR_SEEKERROR                    =0x19,
    XF_ERR_NONDOSDISK                   =0x1a,
    XF_ERR_SECTORNOTFOUND               =0x1b,
    XF_ERR_OUTOFPAPER                   =0x1c,
    XF_ERR_WRITEFAULT                   =0x1d,
    XF_ERR_READFAULT                    =0x1e,
    XF_ERR_GENERALFAILURE               =0x1f,
    XF_ERR_SHAREVIOLATION               =0x20,
    XF_ERR_LOCKVIOLATION                =0x21,
    XF_ERR_DISKCHANGEINVALID            =0x22,
    XF_ERR_FCBUNAVAIL                   =0x23,
    XF_ERR_SHAREBUFFEROVERFLOW          =0x24,
    XF_ERR_CPMISMATCH                   =0x25,
    XF_ERR_OUTOFINPUT                   =0x26,
    XF_ERR_OUTOFDISKSPACE               =0x27,
    XF_ERR_NETREQNOTSUPPORTED           =0x32,
    XF_ERR_REMOTENOTLISTENING           =0x33,
    XF_ERR_DUPNAMEONNET                 =0x34,
    XF_ERR_NETNAMENOTFOUND              =0x35,
    XF_ERR_NETBUSY                      =0x36,
    XF_ERR_NETDEVNOLONGEREXIST          =0x37,
    XF_ERR_NETCOMLIMITEXCEEDED          =0x38,
    XF_ERR_NETHWERROR                   =0x39,
    XF_ERR_INVALIDNETRESPONSE           =0x3a,
    XF_ERR_UNEXPECTEDNETERROR           =0x3b,
    XF_ERR_INCOMPATREMOTEHW             =0x3c,
    XF_ERR_PRINTQUEUEFULL               =0x3d,
    XF_ERR_NOSPACEFORPRINT              =0x3e,
    XF_ERR_PRINTDELETED                 =0x3f,
    XF_ERR_NETNAMEDELETED               =0x40,
    XF_ERR_NETACCESSDENIED              =0x41,
    XF_ERR_NETDEVTYPEINCORRECT          =0x42,
    XF_ERR_NETNAMENOTFOUND2             =0x43,
    XF_ERR_NETNAMELIMITEXCEEDED         =0x44,
    XF_ERR_NETSESSIONLIMITEXCEEDED      =0x45,
    XF_ERR_TEMPORARYPAUSE               =0x46,
    XF_ERR_NETREQNOTACCEPTED            =0x47,
    XF_ERR_NETREDIRECTIONPAUSED         =0x48,
    XF_ERR_LANT_INVALIDVERSION          =0x49,
    XF_ERR_LANT_ACCOUNTEXPIRED          =0x4a,
    XF_ERR_LANT_PWEXPIRED               =0x4b,
    XF_ERR_LANT_LOGININVALID            =0x4c,
    XF_ERR_LANT_DISKLIMITEXCEEDED       =0x4d,
    XF_ERR_LANT_NOTLOGGEDIN             =0x4e,
    XF_ERR_FILEEXISTS                   =0x50,
    XF_ERR_CANTMAKEDIRECTORY            =0x52,
    XF_ERR_FAILONINT24                  =0x53,
    XF_ERR_TOOMANYREDIRECTIONS          =0x54,
    XF_ERR_DUPLICATEREDIRECTION         =0x55,
    XF_ERR_INVALIDPASSWORD              =0x56,
    XF_ERR_INVALIDPARAMETER             =0x57,
    XF_ERR_NETWRITEFAULT                =0x58,
    XF_ERR_NETFUNCNOTSUPPORTED          =0x59,
    XF_ERR_REQHWNOTFOUND                =0x5a,
 
                                        // 256-511 Reserved for low-level errors
    XF_ERR_EOF                          =256,

                                        // 512-999 Reserved for XFile
    XF_ERR_NOTOPEN                      =512,
    XF_ERR_ALREADYOPEN                  =513,
    XF_ERR_LOCKFAILED                   =514,

                                        // 1000-1999 Reserved for XFileINI
    XF_ERR_ITEM_NOT_FOUND               =1000,
    XF_ERR_SECTION_NOT_FOUND            =1001,
    XF_ERR_NEEDREADORWRITE              =1002,
    XF_ERR_NAME_TOO_LONG                =1003,
    
                                        // 2000-2999 Reserved for XFileBitmap
    XF_ERR_NOTSUPPORTED                 =2000,
    XF_ERR_INVALIDHEADER                =2001,
    XF_ERR_INVALIDPALETTE               =2002,
    XF_ERR_INVALIDIMAGE                 =2003,
 
                                        // 3000-3999 Reserved for XFileIFF
    XF_ERR_NOTIFF                       =3000,
    XF_ERR_CHUCKNOTFOUND                =3001,
    XF_ERR_CHUNKNOTFOUND                =3001,
    XF_ERR_FORMNOTFOUND                 =3002,
    XF_ERR_UNEXPECTEDEOF                =3003,
    XF_ERR_INVALIDFORFORM               =3004,
    XF_ERR_INVALIDFORCHUNK              =3005,
    XF_ERR_INVALIDID                    =3006,
    XF_ERR_TRUNCATEDCHUNK               =3007,
    XF_ERR_WRITENOTALLOWED              =3008,
    XF_ERR_MAXDEPTHREACHED              =3009,
} xf_error_codes;


//--- Flags for open/create ---

#define XF_OPEN_READ            0x1         // Read-mode
#define XF_OPEN_WRITE           0x2         // Write-mode
#define XF_OPEN_APPEND          0x4         // Append to current file, if any
#define XF_OPEN_CREATE          0x8         // Create new file and set to 0 length
#define XF_OPEN_EXCLUSIVE       0x10        // Fails if creating file already existing

#define XF_OPEN_KILL            0x1000      // Kills on close (XFileDOS only)

#define XF_OPEN_READONLY        0x10000     // File attributes (server/open)
#define XF_OPEN_HIDDEN          0x20000     // (low byte of high word)
#define XF_OPEN_SYSTEM          0x40000
#define XF_OPEN_ARCHIVE         0x200000
#define XF_OPEN_SHAREABLE       0x400000

#define XF_OPEN_DENYALL         0x10000000  // Share mode for open (high byte)
#define XF_OPEN_DENYWRITE       0x20000000
#define XF_OPEN_DENYREAD        0x30000000
#define XF_OPEN_DENYNONE        0x40000000
                                
#define XF_OPEN_PRIVATE         0x80000000  // Inheritance for open (high bit)


//--- Attributes

#define XF_ATTRIB_NORMAL        0x0
#define XF_ATTRIB_READONLY      0x1
#define XF_ATTRIB_HIDDEN        0x2
#define XF_ATTRIB_SYSTEM        0x4
#define XF_ATTRIB_LABEL         0x8
#define XF_ATTRIB_DIRECTORY     0x10
#define XF_ATTRIB_ARCHIVE       0x20
#define XF_ATTRIB_SHAREABLE     0x100

//--- Values for status ---

#define XF_STATUS_READ          0x1     // Readable
#define XF_STATUS_WRITE         0x2     // Writable
#define XF_STATUS_OPEN          0x4     // Open file
#define XF_STATUS_ISTMP         0x8     // Opened with xf_opentmp
#define XF_STATUS_KILL          0x10    // Will delete file on close

#define XF_STATUS_DIRTY         0x10000 // Buffer needs flushing
#define XF_STATUS_LASTREAD      0x20000 // Last action was a read
#define XF_STATUS_LASTWRITE     0x40000 // Last action was a write

//--- File related maximums
#ifdef __cplusplus
const ulong XF_MAX_PATH        =144;    // maximum length of full pathname
const ulong XF_MAX_DRIVE       =3;	    // maximum length of drive component
const ulong XF_MAX_DIR         =130;    // maximum length of path component
const ulong XF_MAX_FNAME       =9;   	// maximum length of file name component
const ulong XF_MAX_EXT         =5;	    // maximum length of extension component
const ulong XF_MAX_NAME        =13;     // maximum length of file name (with extension)

#else
#ifdef __WATCOMC__
#pragma off(unreferenced);
#endif
#define XF_MAX_PATH            144      // maximum length of full pathname
#define XF_MAX_DRIVE           3        // maximum length of drive component
#define XF_MAX_DIR             130      // maximum length of path component
#define XF_MAX_FNAME           9   	    // maximum length of file name component
#define XF_MAX_EXT             5	    // maximum length of extension component
#define XF_MAX_NAME            13       // maximum length of file name (with extension)
#ifdef __WATCOMC__
#pragma on(unreferenced);
#endif
#endif

#endif

//°±² End of header - xfdefs.h ²±°

