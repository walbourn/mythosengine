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
//                      Microsoft Windows '95 Version
//   
//           Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
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
// felix.hpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __FELIX_HPP
#define __FELIX_HPP    1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//             
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "portable.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

class Flx16;

Flx16 flx_rand();
Flx16 flx_muldiv(Flx16 a,Flx16 b,Flx16 c);
dword flx_recip230(Flx16 a);
Flx16 flx_16mul16(Flx16 a,Flx16 b);
Flx16 flx_16mul30(dword a,dword b);
Flx16 flx_16div16(Flx16 a,Flx16 b);
Flx16 flx_sin(const Flx16 degrees);
Flx16 flx_abs(const Flx16 a);
Flx16 flx_sqrt(const Flx16 a);

extern "C" {
void  flx_srand(long s1,long s2);
dword asm_flx_recip230(Flx16 a);
long asm_flx_rand();
long asm_flx_muldiv(Flx16 a,Flx16 b,Flx16 c);
long asm_flx_16mul16(Flx16 a,Flx16 b);
long asm_flx_16div16(Flx16 a,Flx16 b);
long asm_flx_sin(const Flx16 degrees);
long asm_flx_abs(const Flx16 a);
long asm_flx_sqrt(const Flx16 a);
long asm_flx_16mul30(dword a,dword b);
}

#ifdef __WATCOMC__
#pragma aux (_ASMSTKCALL_) flx_sin;
#pragma aux (_ASMSTKCALL_) flx_abs;
#pragma aux (_ASMSTKCALL_) flx_sqrt;
#pragma aux (_ASMSTKCALL_) flx_rand;
#pragma aux (_ASMSTKCALL_) flx_srand;
#endif

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

Flx16 flx_cos(const Flx16 degrees);
Flx16 flx_tan(const Flx16 degrees);
Flx16 operator + (const Flx16 a, const Flx16 b);
Flx16 operator - (const Flx16 a, const Flx16 b);
Flx16 operator - (const Flx16 a);
Flx16 operator * (Flx16 a, Flx16 b);
Flx16 operator / (const Flx16 a, const Flx16 b);
int operator == (const Flx16 a, const Flx16 b);
int operator == (const Flx16 a, const int b);
int operator == (const int a, const Flx16 b);
int operator != (const Flx16 a, const Flx16 b);
int operator != (const Flx16 a, const int b);
int operator != (const int a, const Flx16 b);
int operator > (const Flx16 a, const Flx16 b);
int operator > (const Flx16 a, const int b);
int operator > (const int a, const Flx16 b);
int operator >= (const Flx16 a, const Flx16 b);
int operator >= (const Flx16 a, const int b);
int operator >= (const int a, const Flx16 b);
int operator < (const Flx16 a, const Flx16 b);
int operator < (const Flx16 a, const int b);
int operator < (const int a, const Flx16 b);
int operator <= (const Flx16 a, const Flx16 b);
int operator <= (const Flx16 a, const int b);
int operator <= (const int a, const Flx16 b);

Flx16 operator += (const Flx16 &a, const Flx16 b);
Flx16 operator -= (const Flx16 &a, const Flx16 b);
Flx16 operator *= (const Flx16 &a, const Flx16 b);
Flx16 operator /= (const Flx16 &a, const Flx16 b);

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

class Flx16
{
public:
   long    flx;

// Constructors.
   Flx16() {}
   Flx16(const int num) {flx = (num <<16);}
   Flx16(const long num) {flx = (num <<16);}
   Flx16(const long num, int dummy) {flx = num; dummy=dummy;}
   Flx16(const short num) {flx = ((int)num <<16);}
   Flx16(const char num) {flx = ((int)num << 16);}
//   Flx16(const Flx16 &r) { flx = r.flx; }
   Flx16(const double num) {flx = (int) (num * 65536.0);}

// Operator.
   inline operator int() const {return(flx>>16);}
   inline operator long() const {return (flx>>16);}
   inline operator float() const {return ((float)(flx / 65536.0));}

// Intrensic functions.
   inline Flx16 sin() const { return (flx_sin(*this));}
   inline Flx16 cos() const { return (flx_sin(*this+Flx16(90)));}
   inline Flx16 tan() const { return (flx_sin(*this)/flx_sin(*this+Flx16(90)));}
   inline Flx16 sqrt() const { return (flx_sqrt(*this));}
   inline Flx16 abs() const { return (flx_abs(*this));}

#if 0
   inline Flx16 acos() const {return (flxacos(flx));}
   inline Flx16 asin() const {return (flxasin(flx));}
   inline Flx16 tan() const {return (flxtan(flx));}
   inline Flx16 atan() const {return (flxatan(flx));}
   inline Flx16 atan2() const {return (flxatan2(flx));}
   inline Flx16 exp() const {return flxexp(flx));}
   inline Flx16 pow() const {return flxpow(flx));}
   inline Flx16 log10() const {return flxlog10(flx));}
   inline Flx16 log() const {return flxlog(flx));}
#endif
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

const Flx16 FLX16_ZERO  = 0;
const Flx16 FLX16_ONE   = 1;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//							   Inline Functions
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <felix.ipp>

#endif         // __FELIX_HPP

//°±² End of header - felix.hpp ²±°


