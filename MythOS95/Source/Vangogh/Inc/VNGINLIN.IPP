//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. | 
//                                                           |. _  .   .|
// Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.   | / \   .  | 
//              All rights reserved.                         |_|_|_._._.|
//                                                           |.-.-.-.-..|
//                                                          %\__________/%
//                                                           %          %
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
//           *** Charybdis Enterprises, Inc. Company Confidential ***
//
//  THIS FILE AND ALL ASSOCIATED FILES ARE THE COMPANY PROPRIETARY PROPERTY
//        OF CHARYBDIS ENTERPRISES, INC.  UNAUTHORIZED USE PROHIBITED.
//
// CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
// TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
// IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
// AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
// INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
// VngInlin.ipp  
//
//     These are the inline functions defined for use with Van Gogh.
//
//อออออออออออออออออออออออออออออ Revision History ออออออออออออออออออออออออออออ
//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
#ifndef __VNGINLIN_IPP
#define __VNGINLIN_IPP 1

void vbuff_reset(void *scrn,dword size,dword color);
void zbuff_reset32(void *zb,dword size,dword depth);
void zbuff_reset16(void *zb,dword size,dword depth);

#ifdef __WATCOMC__
#pragma aux vbuff_reset =  \ 
    "mov   ah,al"           \
    "push  ax"              \
    "shl   eax,16"          \
    "pop   ax"              \
    "push  ecx"             \
    "shr   ecx,2"           \
    "rep stosd"             \
    "pop   ecx"             \
    "and   ecx,3"           \
    "rep stosb"             \
    parm caller  [edi][ecx][eax] \
    modify [eax edi ecx];

#pragma aux zbuff_reset32 = \
    "rep stosd"              \
    parm caller [edi][ecx][eax] \
    modify [edi ecx];


#pragma aux zbuff_reset16 = \
    "shr ecx,1"              \
    "shr eax,16"             \
    "push ebx"              \
    "shld ebx,eax,16"       \
    "mov ax,bx"             \
    "pop ebx"               \
    "rep stosd"              \
    parm caller [edi][ecx][eax] \
    modify [edi ecx];
#else
inline void vbuff_reset(void *scrn,dword sz,dword color)
{
    // Expand color to a dword from a byte.
    color |= color << 8;
    color |= color << 16;

    _asm {
        mov     eax,color
        mov     ecx,sz
        mov     edi,scrn
        push    ecx
        shr     ecx,2
    rep stosd
        pop     ecx
        and     ecx,3
    rep stosb
    }
}

inline void zbuff_reset16(void *zb,dword sz,dword depth)
{
    _asm {
        mov     edi,zb
        mov     eax,depth
        shr     eax,16      // because the 16 MSBs are the mose important.
        mov     ecx,sz
    rep stosw
    }
}

inline void zbuff_reset32(void *zb,dword sz,dword depth)
{
    _asm {
        mov     ecx,sz
        mov     edi,zb
        mov     eax,depth
    rep stosd
    }
}
#endif

#endif          // __VNGINLIN_IPP

//ฐฑฒ End of module - vnginlin.ipp ฒฑฐ


