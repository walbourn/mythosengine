//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                      Ivory -- A Memory Management Library
//                          Microsoft Windows '95 Version
//
//            Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
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
// Ivory DPMI Memory interface
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __IVMEM_H
#define __IVMEM_H 1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//                                
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "portable.h"


//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#ifdef __WATCOMC__
#pragma pack(1);
#endif


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
// The Memory allocation structure
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
typedef struct _IvoryMemory IvoryMemory;
struct _IvoryMemory
{
    void    *pointer;
    dword   memsize;
    dword   handle;
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
//  DPMI information structure
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
typedef struct __DPMI_meminfo DPMI_meminfo;
struct __DPMI_meminfo
{
    dword   LargestBlockAvail;
    dword   MaxUnlockedPage;
    dword   LargestLockablePage;
    dword   LinAddrSpace;
    dword   NumFreePagesAvail;
    dword   NumPhysicalPagesFree;
    dword   TotalPhysicalPages;
    dword   FreeLinAddrSpace;
    dword   SizeOfPageFile;
    dword   reserved[3];
};

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

void ivory_iMemInfo   (DPMI_meminfo *);
int  ivory_iAllocMem  (IvoryMemory *, ulong);
int  ivory_iLockMem   (IvoryMemory *);
int  ivory_iUnlockMem (IvoryMemory *);
void ivory_iFreeMem   (IvoryMemory *);

// For the imported ASM functions
#ifdef __WATCOMC__
#pragma aux (_ASMSTKCALL_) ivory_iMemInfo;
#pragma aux (_ASMSTKCALL_) ivory_iAllocMem;
#pragma aux (_ASMSTKCALL_) ivory_iFreeMem;
#pragma aux (_ASMSTKCALL_) ivory_iLockMem;
#pragma aux (_ASMSTKCALL_) ivory_iUnlockMem;
#endif


#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of fle - ivmem.cpp 憶�
