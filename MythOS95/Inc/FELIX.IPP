//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//
//            _,'|             _.-''``-...___..--';)
//           /_ \'.      __..-' ,      ,--...--'''
//          <\    .`--'''       `     /'
//           `-';'               ;   ; ;  Felix the Fixed-point Library
//     __...--''     ___...--_..'  .;.'
//    (,__....----'''       (,..--''
//
//                    Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// Created by Tim Little
//
// felix.ipp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __FELIX_IPP
#define __FELIX_IPP     1

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define INLINE_FELIX    1

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Prototypes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                                         Inline Functions
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

// These are the rapper functions to make the C++ functions return correctly.
inline Flx16 flx_rand()
{
    return (Flx16(asm_flx_rand(),0));
}

inline Flx16 flx_16mul30(dword a,dword b)
{
    return (Flx16(asm_flx_16mul30(a,b),0));
}


inline Flx16 flx_muldiv(Flx16 a,Flx16 b, Flx16 c)
{
#ifdef INLINE_FELIX
    Flx16 ret_val;

    _asm {
        mov     eax,a.flx
        mov     edx,b.flx
        mov     ecx,c.flx
        imul    edx

        cmp     ecx,0
        jge     t2
        neg     ecx
t2:
        push    edx
        cmp     edx,0
        jge     t1
        neg     edx
t1:
        shr     ecx,1
        cmp     edx,ecx
        jge     error_trap
        mov     ecx,c.flx
        pop     edx
        idiv    ecx
        jmp     done

error_trap:
        pop     edx
        mov     ecx,c.flx
        xor     edx,ecx
        jl      t3
        mov     eax,0x7fffffff
        jmp     done
t3:
        mov     eax,0x80000000

done:
        mov     ret_val.flx,eax
    };

    return (ret_val);
#else
    return (Flx16(asm_flx_muldiv(a,b,c),0));
#endif
}

inline Flx16 flx_16mul16(Flx16 a,Flx16 b)
{
#ifdef INLINE_FELIX
    Flx16   ret_val;

    _asm {
        mov     eax,a.flx
        imul    b.flx
        shrd    eax,edx,16
        mov     ret_val.flx,eax
    };
    return (ret_val);
#else
    return (Flx16(asm_flx_16mul16(a,b),0));
#endif
}

inline Flx16 flx_16div16(Flx16 a,Flx16 b)
{
    Flx16   ret_val;
#ifdef INLINE_FELIX

    _asm {
        mov     edx,a.flx
        xor     eax,eax
        shrd    eax,edx,16
        sar     edx,16
#ifdef SAFE_DIVIDE
        mov     ecx,b.flx
        cmp     ecx,0
        jge     jump_1
        neg     ecx
jump_1:
        push    edx
        cmp     edx,0
        jge     jump_2
        neg     edx
jump_2:
        shr     ecx,1
        cmp     edx,ecx
        jge     error_trap
        pop     edx
#endif
        idiv    b.flx
        mov     ret_val.flx,eax
        jmp     _done
#ifdef SAFE_DIVIDE
error_trap:
        pop     edx
        xor     edx,b.flx
        cmp     edx,0
        jl      jump_3
        mov     ret_val.flx,0x7fffffff
        jmp     _done
jump_3:
        mov     ret_val.flx,0x80000000
#endif
_done:
    }
    return (ret_val);
#else
    return (Flx16(asm_flx_16div16(a,b),0));
#endif
}


inline Flx16 flx_abs(const Flx16 a)
{
#ifdef INLINE_FELIX
    if (a.flx < 0)
        return (-a);
    else
        return (a);
#else
    return(Flx16(asm_flx_abs(a),0));
#endif
}

inline Flx16 flx_sqrt(const Flx16 a)
{
    return(Flx16(asm_flx_sqrt(a),0));
}

inline dword flx_recip230(Flx16 a)
{
    return (asm_flx_recip230(a));
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Intrinsic functions are defined here.                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

inline Flx16 flx_sin(const Flx16 degrees)
{
    return(Flx16(asm_flx_sin(degrees),0));
}

inline Flx16 flx_cos(const Flx16 degrees)
{
   return (flx_sin(degrees+Flx16(90)));
}

inline Flx16 flx_acos (const Flx16  a)
{
    return (flx_abs(Flx16(90) - flx_asin(a)));
}

inline Flx16 flx_tan(const Flx16 degrees)
{
   return (flx_sin(degrees)/flx_cos(degrees));
}

inline Flx16 flx_cot (const Flx16 a)
{
    return (flx_cos(a)/flx_sin(a));
}

inline Flx16 flx_sec (const Flx16 a)
{
    return (Flx16(1)/flx_cos(a));
}

inline Flx16 flx_csc (const Flx16 a)
{
    return (Flx16(1)/flx_sin(a));
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Operator overloads are defined here.                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

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


inline Flx16 operator += (Flx16 &a, const Flx16 b)
{
    a.flx += b.flx;
    return a;
}

inline Flx16 operator -= (Flx16 &a, const Flx16 b)
{
    a.flx -= b.flx;
    return a;
}

inline Flx16 operator *= (Flx16 &a, Flx16 b)
{
#ifdef INLINE_FELIX
    long l = a.flx;
    _asm {
        mov     eax,l
        imul    b.flx
        shrd    eax,edx,16
        mov     l,eax
    };
    a.flx = l;
#else
    a.flx = asm_flx_16mul16 (a, b);
#endif
    return a;
}

inline Flx16 operator /= (Flx16 &a, const Flx16 b)
{
#ifdef SAFE_DIVIDE
    Flx16   ret_val;
    int t;
    t = flx_abs(a);
    if (t > (flx_abs(b).flx >> 1))
    {
        if ((a.flx ^ b.flx) < 0)
            ret_val.flx = 0x8000000;
        else
            ret_val.flx = 0x7ffffff;

        return (ret_val);
    }
#endif

#ifdef INLINE_FELIX
    long l = a.flx;
    _asm {
        xor     eax,eax
        mov     edx,l
        shrd    eax,edx,16
        sar     edx,16
        idiv    b.flx
        mov     l,eax
    }
    a.flx = l;
#else
    a.flx = asm_flx_16div16 (a, b);
#endif
    return a;
}



#endif         // __FELIX_IPP

//葦� End of header - felix.ipp 憶�


