;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
;
;                                                           %__________%
;                                                          %/ . .  .   \%
;           Van Gogh 2D-Display Library                     |  . .  o. | 
;                                                           |. _  .   .|
;          Microsoft Windows '95 Version                    | / \   .  | 
;                                                           |_|_|_._._.|
; Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.   |.-.-.-.-..|
;              All rights reserved.                        %\__________/%
;                                                           %          %
;
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
;
;           *** Charybdis Enterprises, Inc. Company Confidential ***
;
;  This file and all associated files are the company proprietary property
;        of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
;
; CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
; TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
; IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
; AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
; INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
;
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
;
; vngFPOLY8.ASM 
;
;      This module has all of the polygon scan conversion code for 8bpp 
;      vbuffers.
;
;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ


.486p

        OPTION SCOPED              ; Enable local labels.
        

;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
;
;                                Includes
;                                
;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

include macros.inc
include vngdefs.inc
include vngstrct.inc

;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
;
;                                Equates
;
;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
;
;                               Structures
;
;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
;
;                                 Data
;
;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

       ASSUME  ds:_DATA
_DATA  SEGMENT PARA PUBLIC USE32 'DATA'
_DATA  ENDS


;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
;
;                                Macros
;
;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
;
;                                 Code
;
;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±


_TEXT  SEGMENT PARA PUBLIC USE32 'CODE'


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; long vngo_calc_xstep(int x1,int x2,int dy);                              ³
;     This routine calculates the X step between the two Xs passed in over ³
;     the Y distance described in dy.  It returns a 12.20 step value.      ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

START_PROC vngo_calc_xstep,     C   x1:DWORD, x2:DWORD, dy:DWORD
        cmp     dy,0
        je      @f
        xor     eax,eax
        mov     edx,x2
        sub     edx,x1
        shrd    eax,edx,12
        sar     edx,12
        idiv    dy
        ret
@@:
        xor     eax,eax
        ret
END_PROC   vngo_calc_xstep

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; long vngo_calc_xstep(int s1,int s2,int dy);                              ³
;     This routine calculates the S step between the two Ss passed in over ³
;     the Y distance described in dy.  It returns a 12.20 step value.      ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

START_PROC vngo_calc_sstep,     C   s1:DWORD, s2:DWORD, dy:DWORD
        cmp     dy,0
        je      @f
        xor     eax,eax
        mov     edx,s2
        sub     edx,s1
        shrd    eax,edx,12
        sar     edx,12
        idiv    dy
        ret
@@:
        xor     eax,eax
        ret
END_PROC   vngo_calc_sstep


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; long vngo_calc_xstep(int z1,int z2,int dy);                              ³
;     This routine calculates the Z step between the two Zs passed in over ³
;     the Y distance described in dy.  It returns a 16.16 step value.      ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

START_PROC vngo_calc_zstep,     C   z1:DWORD, z2:DWORD, dy:DWORD
        cmp     dy,0
        je      zero_div
        mov     edx,z2
        sub     edx,z1
        mov     eax,edx
        cmp     edx,0
        jl      @f
        xor     edx,edx
        idiv    dy
        ret
@@:
        mov     edx,-1
        idiv    dy
        ret

zero_div:
        xor     eax,eax
        ret
END_PROC   vngo_calc_zstep


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; long vngo_calc_xstep(int z1,int z2,int dy);                              ³
;     This routine calculates the U/V step between the two U/Vs passed in, ³
;     over the Y distance described in dy.  It returns a 16.16 step value. ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

START_PROC vngo_calc_uvstep,    C   uv1:DWORD, uv2:DWORD, dy:DWORD
        cmp     dy,0
        je      zero_div
        mov     edx,uv2
        sub     edx,uv1
        mov     eax,edx
        cmp     edx,0
        jl      @f
        xor     edx,edx
        idiv    dy
        ret
@@:
        mov     edx,-1
        idiv    dy
        ret

zero_div:
        xor     eax,eax
        ret
END_PROC   vngo_calc_uvstep


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; long vngo_calc_xstep(int z1,int z2,int dy);                              ³
;     This routine calculates the U/V step between the two U/Vs passed in, ³
;     over the Y distance described in dy.  It returns a 16.16 step value. ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

START_PROC vngo_calc_wstep,     C   w1:DWORD, w2:DWORD, dy:DWORD
        cmp     dy,0
        je      zero_div
        mov     edx,w2
        sub     edx,w1
        mov     eax,edx
        cmp     edx,0
        jl      @f
        xor     edx,edx
        idiv    dy
        ret
@@:
        mov     edx,-1
        idiv    dy
        ret

zero_div:
        xor     eax,eax
        ret
END_PROC   vngo_calc_wstep


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; void vngo_calc_quadratic(long w1, long w2, long t1, long t2, long step,  ³
;                          long *s1ptr, long *s2ptr);                      ³
;                                                                          ³
;       This calculate the two step constants for a quadratic where the    ³
;       interpolation from term 1 (t1) to term 2 (t2) is done with respect ³
;       to w1 and w2.  The first step value is placed in s1ptr, and the    ³
;       second is stored in s2ptr.                                         ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

START_PROC vngo_calc_quadratic, C       w0:DWORD, w2:DWORD, t0:DWORD, t2:DWORD, step:DWORD, s1ptr:DWORD, s2ptr:DWORD

;;
;;      The basic algorythm is this:
;;
;;      pstep = 1 / step;
;;      tt0 = t0;
;;      tt2 = t2;
;;      tt1 = ((t0 * w0) + (t2 * w2)) / (w0 + w2);
;;
;;      a1 = (-3 * tt0 + 4 * tt1 - tt2) * pstep;
;;      a2 = 2 * (tt0 - 2 * tt1 + tt2) * pstep * pstep;
;;      *s1ptr = a1 + a2;
;;      *s2ptr = 2 * a2;
;;
        LOCAL   a1:DWORD
        LOCAL   a2:DWORD
        LOCAL   tt1:DWORD
        LOCAL   pstep:DWORD

        cmp     step,0
        jne     @f
        mov     eax,s1ptr
        mov     [eax],DWORD PTR 0
        mov     eax,s2ptr
        mov     [eax],DWORD PTR 0
        ret
@@:
        push    esi
        push    edi
        push    ebx

        ; pstep = 1 / step;
        mov     eax,020000h
        xor     edx,edx
        idiv    step
        sar     eax,1
        adc     eax,0
        mov     pstep,eax

        ; (t0 * w0)
        mov     eax,t0
        imul    w0
        mov     esi,eax
        mov     edi,edx
        ; (t2 * w2)
        mov     eax,t2
        imul    w2
        ; ((t0 * w0) + (t2 * w2))
        add     eax,esi
        adc     edx,edi
        ; (w0 + w2)
        mov     ecx,w0
        add     ecx,w2
        ; ((t0 * w0) + (t2 * w2)) / (w0 + w2)
        idiv    ecx
        mov     tt1,eax
        
        ; (4 * tt1)
        shl     eax,2
        ; (-3 * tt0)
        sub     eax,t0
        sub     eax,t0
        sub     eax,t0
        ; - tt2
        sub     eax,t2

        imul    pstep
        shrd    eax,edx,16
        mov     a1,eax
        mov     ecx,eax

        ; a2 = 2 * (tt0 - 2 * tt1 + tt2) * pstep * pstep
        mov     eax,t0
        sub     eax,tt1
        sub     eax,tt1
        add     eax,t2
        shl     eax,1
        imul    pstep
        shrd    eax,edx,16
        imul    pstep
        shrd    eax,edx,16
        mov     a2,eax

        ; *s1ptr = a1 + a2;
        mov     esi,s1ptr
        add     ecx,eax
        mov     [esi],ecx
        ; *s2ptr = 2 * a2;
        mov     edi,s2ptr
        shl     eax,1
        mov     [edi],eax

        pop     ebx
        pop     edi
        pop     esi

        ret
END_PROC   vngo_calc_quadratic

_text   ends
        end

;°±² End of module - vngPCALC.asm ²±°


