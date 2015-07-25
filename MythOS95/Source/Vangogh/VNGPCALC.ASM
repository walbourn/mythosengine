;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
;
;                                                           %__________%
;                                                          %/ . .  .   \%
;           Van Gogh 2D-Display Library                     |  . .  o. | 
;                                                           |. _  .   .|
;          Microsoft Windows '95 Version                    | / \   .  | 
;                                                           |_|_|_._._.|
; Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
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

;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
;
;                                 Data
;
;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
       ASSUME  ds:_DATA
_DATA  SEGMENT PARA PUBLIC USE32 'DATA'
_DATA  ENDS

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
ALIGN   4
START_PROC vngo_calc_sstep,	C   s1:DWORD, s2:DWORD, dy:DWORD
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

START_PROC vngo_calc_xstep,     C   x1:DWORD, x2:DWORD, dy:DWORD
        cmp     dy,0
        je      @f
if 1
	xor	edx,edx
	mov	eax,x2
	sub	eax,x1
	test	eax,080000000h
	jns	@f
	mov	edx,-1
@@:
else
        xor     eax,eax
        mov     edx,x2
        sub     edx,x1
        shrd    eax,edx,12
        sar     edx,12
endif
        idiv    dy
        ret
@@:
        xor     eax,eax
        ret
END_PROC   vngo_calc_xstep


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; long vngo_calc_zstep(int z1,int z2,int dy);                              ³
;     This routine calculates the Z step between the two Zs passed in over ³
;     the Y distance described in dy.  It returns a 16.16 step value.      ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ALIGN   4
        public _vngo_calc_uvstep
_vngo_calc_uvstep:
        public vngo_calc_uvstep_
vngo_calc_uvstep_:
        public vngo_calc_uvstep
vngo_calc_uvstep:

        public _vngo_calc_wstep
_vngo_calc_wstep:
        public vngo_calc_wstep_
vngo_calc_wstep_:
        public vngo_calc_wstep
vngo_calc_wstep:

START_PROC vngo_calc_zstep,     C   z1:DWORD, z2:DWORD, dy:DWORD
        cmp     dy,0
        je      zero_div
        mov     edx,z2
        sub     edx,z1
        mov     eax,edx
        sar     edx,31
        idiv    dy
        ret
zero_div:
        xor     eax,eax
        ret
END_PROC   vngo_calc_zstep

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
  ; Start by checking to make sure there is something to calc.
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





;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; void vngo_calc_quadratic2(long w1, long w2, long t1, long t2, long step, ³
;                          long *s1ptr, long *s2ptr,ushift);               ³
;                                                                          ³
;       This calculate the two step constants for a quadratic where the    ³
;       interpolation from term 1 (t1) to term 2 (t2) is done with respect ³
;       to w1 and w2.  The first step value is placed in s1ptr, and the    ³
;       second is stored in s2ptr.                                         ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC vngo_calc_quadratic2, C       w0:DWORD, w2:DWORD, t0:DWORD, t2:DWORD, step:DWORD, s1ptr:DWORD, s2ptr:DWORD, ushift:DWORD
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
  ; Start by checking to make sure there is something to calc.
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
;        mov     eax,010000h
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
;; leave result shifted up by the correct amount.
		mov	ecx,16
		sub	ecx,ushift
        shrd    eax,edx,cl
;; done with up shift with precision.
;        shrd    eax,edx,16
        mov     a1,eax
        mov     ecx,eax
  ; a2 = 2 * (tt0 - 2 * tt1 + tt2) * pstep * pstep
        mov     eax,t0
        sub     eax,tt1
        sub     eax,tt1
        add     eax,t2
        shl     eax,1
        imul    pstep
;; leave result shifted up by the correct amount.
		push	ecx
		mov	ecx,16
		sub	ecx,ushift
        shrd    eax,edx,cl
		pop	ecx
;; done with up shift with precision.
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
END_PROC   vngo_calc_quadratic2

START_PROC 	vngo_midpt, C	p1:DWORD, p2:DWORD, outpt:DWORD
	LOCAL	HighVal:DWORD
	LOCAL	LowVal:DWORD
	push	esi
	push	edi
	push	ebx

	mov	ebx,p1
	mov	esi,p2
	mov	edi,outpt

	mov	eax,(VNGO_POINT2 PTR [ebx]).pt_clr
	mov	(VNGO_POINT2 PTR [edi]).pt_clr,eax

	mov	eax,(VNGO_POINT2 PTR [ebx]).pt_x
	add	eax,(VNGO_POINT2 PTR [esi]).pt_x
	sar	eax,1
	mov	(VNGO_POINT2 PTR [edi]).pt_x, eax

	mov	eax,(VNGO_POINT2 PTR [ebx]).pt_y
	add	eax,(VNGO_POINT2 PTR [esi]).pt_y
	sar	eax,1
	mov	(VNGO_POINT2 PTR [edi]).pt_y, eax

	mov	eax,(VNGO_POINT2 PTR [ebx]).pt_w
	add	eax,(VNGO_POINT2 PTR [esi]).pt_w
	sar	eax,1
	mov	(VNGO_POINT2 PTR [edi]).pt_w, eax

;; These need to be perspectively corrected.
	mov	eax,(VNGO_POINT2 PTR [ebx]).pt_z
	imul	(VNGO_POINT2 PTR [ebx]).pt_w
	mov	HighVal,edx
	mov	LowVal,eax
	mov	eax,(VNGO_POINT2 PTR [esi]).pt_z
	imul	(VNGO_POINT2 PTR [esi]).pt_w
	add	eax,LowVal
	adc	edx,HighVal
	shrd	eax,edx,1
	sar	edx,1
	idiv	(VNGO_POINT2 PTR [edi]).pt_w
	mov	(VNGO_POINT2 PTR [edi]).pt_z, eax

	mov	eax,(VNGO_POINT2 PTR [ebx]).pt_shade
	imul	(VNGO_POINT2 PTR [ebx]).pt_w
	mov	HighVal,edx
	mov	LowVal,eax
	mov	eax,(VNGO_POINT2 PTR [esi]).pt_shade
	imul	(VNGO_POINT2 PTR [esi]).pt_w
	add	eax,LowVal
	adc	edx,HighVal
	shrd	eax,edx,1
	sar	edx,1
	idiv	(VNGO_POINT2 PTR [edi]).pt_w
	mov	(VNGO_POINT2 PTR [edi]).pt_shade, eax

	mov	eax,(VNGO_POINT2 PTR [ebx]).pt_u
	imul	(VNGO_POINT2 PTR [ebx]).pt_w
	mov	HighVal,edx
	mov	LowVal,eax
	mov	eax,(VNGO_POINT2 PTR [esi]).pt_u
	imul	(VNGO_POINT2 PTR [esi]).pt_w
	add	eax,LowVal
	adc	edx,HighVal
	shrd	eax,edx,1
	sar	edx,1
	idiv	(VNGO_POINT2 PTR [edi]).pt_w
	mov	(VNGO_POINT2 PTR [edi]).pt_u, eax

	mov	eax,(VNGO_POINT2 PTR [ebx]).pt_v
	imul	(VNGO_POINT2 PTR [ebx]).pt_w
	mov	HighVal,edx
	mov	LowVal,eax
	mov	eax,(VNGO_POINT2 PTR [esi]).pt_v
	imul	(VNGO_POINT2 PTR [esi]).pt_w
	add	eax,LowVal
	adc	edx,HighVal
	shrd	eax,edx,1
	sar	edx,1
	idiv	(VNGO_POINT2 PTR [edi]).pt_w
	mov	(VNGO_POINT2 PTR [edi]).pt_v, eax

        pop     ebx
        pop     edi
        pop     esi

        ret
END_PROC   	vngo_midpt

_text   ends
        end

;°±² End of module - vngPCALC.asm ²±°


