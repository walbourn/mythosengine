//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//
//            _,'|             _.-''``-...___..--';)
//           /_ \'.      __..-' ,      ,--...--'''
//          <\    .`--'''       `     /'     
//           `-';'               ;   ; ;  Felix the Fixed-point Library
//     __...--''     ___...--_..'  .;.'
//    (,__....----'''       (,..--''
//
//   
//           Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// felix.ipp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __FELIX_IPP
#define __FELIX_IPP    1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//             
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//							   Inline Functions
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#if 1
#pragma aux flx_16mul16 =      \
   "imul   edx"                \
   "shrd   eax,edx,16"         \
   parm caller [eax][edx] nomemory \
   value [eax]                 \
   modify [eax edx] nomemory;

#pragma aux flx_16mul30 =      \
   "imul   edx"                \
   "shrd   eax,edx,30"         \
   parm caller [eax][edx] nomemory \
   value [eax]                 \
   modify [eax edx] nomemory;


#pragma aux flx_16div16 =      \
   "xor    eax,eax"            \
   "shrd   eax,edx,16"         \
   "sar    edx,16"             \
   "idiv   ecx"                \
   parm caller [edx][ecx] nomemory \
   value   [eax]               \
   modify  [eax edx] nomemory;

#pragma aux flx_muldiv =       \
   "imul   edx"                \
   "idiv   ecx"                \
   parm caller [eax][edx][ecx] nomemory \
   value   [eax]               \
   modify  [eax edx] nomemory;

#pragma aux flx_recip230 =     \
   "mov    edx,04000h"         \
   "xor    eax,eax"            \
   "idiv   ecx"                \
   parm caller [ecx] nomemory  \
   value   [eax]               \
   modify  [eax edx] nomemory; 

#endif


// Intrinsic functions.
inline Flx16 flx_cos(const Flx16 degrees)
{
   return (flx_sin(degrees+90));
}

inline Flx16 flx_tan(const Flx16 degrees)
{
   return (flx_sin(degrees)/flx_cos(degrees));
}

inline Flx16 operator + (const Flx16 a, const Flx16 b)
{
   return Flx16(a.flx + b.flx, 0);
}

inline Flx16 operator - (const Flx16 a, const Flx16 b)
{
   return Flx16(a.flx - b.flx, 0);
}

inline Flx16 operator - (const Flx16 a)
{
   return Flx16(-a.flx, 0);
}

inline Flx16 operator * (Flx16 a, Flx16 b)
{
   return(flx_16mul16(a,b));
}

inline Flx16 operator / (const Flx16 a, const Flx16 b)
{
   return(flx_16div16(a,b));
}

inline int operator == (const Flx16 a, const Flx16 b)
{
   return(a.flx==b.flx);
}

inline int operator == (const Flx16 a, const int b)
{
   return(a.flx==(b << 16));
}

inline int operator == (const int a, const Flx16 b)
{
   return((a << 16)==b.flx);
}

inline int operator != (const Flx16 a, const Flx16 b)
{
   return(a.flx!=b.flx);
}

inline int operator != (const Flx16 a, const int b)
{
   return(a.flx!=(b << 16));
}

inline int operator != (const int a, const Flx16 b)
{
   return((a << 16)!=b.flx);
}

inline int operator > (const Flx16 a, const Flx16 b)
{
   return(a.flx>b.flx);
}

inline int operator > (const Flx16 a, const int b)
{                       
   return(a.flx>(b << 16));
}

inline int operator > (const int a, const Flx16 b)
{
   return((a << 16)>b.flx);
}

inline int operator >= (const Flx16 a, const Flx16 b)
{
   return(a.flx>=b.flx);
}

inline int operator >= (const Flx16 a, const int b)
{
   return(a.flx>=(b << 16));
}

inline int operator >= (const int a, const Flx16 b)
{
   return((a << 16)>=b.flx);
}

inline int operator < (const Flx16 a, const Flx16 b)
{
   return(a.flx<b.flx);
}

inline int operator < (const Flx16 a, const int b)
{
   return(a.flx<(b << 16));
}

inline int operator < (const int a, const Flx16 b)
{
   return((a << 16)<b.flx);
}

inline int operator <= (const Flx16 a, const Flx16 b)
{
   return(a.flx<=b.flx);
}

inline int operator <= (const Flx16 a, const int b)
{
   return(a.flx<=(b << 16));
}

inline int operator <= (const int a, const Flx16 b)
{
   return((a << 16)<=b.flx);
}                    

#endif         // __FELIX_IPP

//°±² End of header - felix.ipp ²±°


