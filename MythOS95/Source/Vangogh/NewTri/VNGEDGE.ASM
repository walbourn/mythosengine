;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
;
;                                                           %__________%
;                                                          %/ . .  .   \%
;           Van Gogh 2D-Display Library                     |  . .  o. | 
;                                                           |. _  .   .|
;          Microsoft Windows '95 Version                    | / \   .  | 
;                                                           |_|_|_._._.|
; Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
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
; vngedge.ASM 
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

PUBLIC  _vngo_build_edgezgt

PUBLIC  _vngo_build_edgegt

_TEXT  SEGMENT PARA PUBLIC USE32 'CODE'

_edge = 8
_p1 = 12
_p2 = 16
_is_right = 20
_idy = 16
_curz = -36
_ycnt = -20
_curv = -32
_curx = -28

_xstep = -4
_ustep = -8
_vstep = -12
_zstep = -16
_sstep = -24

__xstep = _xstep + 56
__ustep = _ustep + 56
__vstep = _vstep + 56
__zstep = _zstep + 56
__sstep = _sstep + 56

__curv = _curv + 56
__curz = _curz + 56
__ycnt = _ycnt + 56

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; Compute edges for zbuffered triangles
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
_vngo_build_edgezgt  PROC NEAR
        push    ebp
        mov     ebp, esp
        sub     esp, 40                                 
        push    ebx
        push    esi

        mov     esi, DWORD PTR _p1[ebp]
        push    edi
        mov     edi, DWORD PTR _p2[ebp]
        mov     edx, DWORD PTR [esi+4]
        mov     ecx, DWORD PTR [edi+4]
        sub     ecx, edx

        cmp     ecx, 1                                  ; 1 is so small we won't mess with it.                                          
        jle     done                                    ; Bail if there is nothing to do.

; Compute idy.
        mov     edx,1
        xor     eax,eax
        idiv    ecx

        mov     edx, DWORD PTR [esi+4]
        mov     ecx, DWORD PTR [edi+4]
        mov     ebx, DWORD PTR [esi+8]
        mov     DWORD PTR _idy[ebp], eax
        lea     eax, DWORD PTR [edx+65535]
        add     ecx, 0000ffffH
        and     eax, 0ffff0000H
        and     ecx, 0ffff0000H
        sub     ecx, eax
        sub     eax, edx
        mov     edx, DWORD PTR [edi+8]
        shr     ecx, 16                                 
        sub     edx, ebx

        cmp     ecx,1
        jl      done
        mov     DWORD PTR _ycnt[ebp],ecx

        mov     ecx,eax

        mov     eax,edx
        imul    DWORD PTR _idy[ebp]


        shrd    eax, edx, 16
        mov     DWORD PTR _zstep[ebp], eax
        mov     ebx, DWORD PTR [esi+8]

        imul    ecx
        shld    edx,eax,16

        mov     eax, DWORD PTR [edi]
        add     edx, ebx
        mov     DWORD PTR _curz[ebp], edx
        mov     ebx, DWORD PTR [esi]
        sub     eax, ebx
        imul    DWORD PTR _idy[ebp]
        shld    edx, eax, 16

        mov     DWORD PTR _xstep[ebp],edx
        mov     eax,ecx
        imul    edx
        shrd    eax, edx, 16

        mov     edx, DWORD PTR [edi+20]
        lea     eax,[eax+ebx+65535]
;        cmp     DWORD PTR _is_right[ebp],0
;        jne     @f
;        dec     eax
;@@:
        mov     ebx, DWORD PTR [esi+20]
        mov     DWORD PTR _curx[ebp], eax


        sub     edx, ebx
        mov     eax, edx
        imul    DWORD PTR _idy[ebp]
        shrd    eax, edx, 16
        mov     DWORD PTR _ustep[ebp], eax

        imul    ecx
        shld    edx,eax,16

        mov     eax, DWORD PTR [edi+24]
        add     ebx, edx
        mov     edx, DWORD PTR [esi+24]

        sub     eax, edx
        imul    DWORD PTR _idy[ebp]
        shrd    eax,edx,16
        mov     DWORD PTR _vstep[ebp], eax

        imul    ecx
        shld    edx,eax,16

        mov     eax, DWORD PTR [esi+24]
        add     edx, eax
        mov     DWORD PTR _curv[ebp], edx

        mov     eax, DWORD PTR [edi+16]
        sub     eax, DWORD PTR [esi+16]
        imul    DWORD PTR _idy[ebp]
        shrd    eax, edx, 16

        mov     DWORD PTR _sstep[ebp],eax
        mov     esi, DWORD PTR [esi+16]
        imul    ecx


        shrd    eax, edx, 16

        mov     edi, DWORD PTR _curz[ebp]
        lea     edx, DWORD PTR [eax+esi]
        mov     esi, DWORD PTR _curx[ebp]
        mov     eax, DWORD PTR _edge[ebp]


        push    ebp                     ; this is an un-orthodox practice.
        mov     ebp,__curv[esp]
        jmp     SHORT inside_loop

ALIGN   16
;==============================================================================
;
; Main loop!
;       ecx     work register.
;       eax     edge pointer
;       ebx     current U
;       ebp     current V
;       edx     current Shade
;       esi     current X
;       edi     current Z
;
;==============================================================================
inside_loop:
; Start X compute
        mov     ecx, esi
        lea     eax,[eax+32]             ; increment edge. 
        shr     ecx, 16                                 
        mov     DWORD PTR [eax-32], ecx
        add     esi, DWORD PTR __xstep[esp]
; End X compute.
; Start U compute.
        mov     DWORD PTR [eax-12], ebx
        add     ebx, DWORD PTR __ustep[esp]
; End U compute
; Start V compute
        mov     DWORD PTR [eax-8], ebp
        add     ebp, DWORD PTR __vstep[esp]
; End V compute
; Start Z compute
        mov     DWORD PTR [eax-24], edi
        add     edi, DWORD PTR __zstep[esp]
; End of Z compute
; Start S compute
        mov     DWORD PTR [eax-16], edx
        add     edx, DWORD PTR __sstep[esp]
; End S compute
        dec     DWORD PTR __ycnt[esp]
        jne     SHORT inside_loop
        pop     ebp                     ; this is an un-orthodox practice.

;==============================================================================
;
; Main loop end.
;
;==============================================================================
done:
        pop     edi
        pop     esi
        pop     ebx
        mov     esp, ebp
        pop     ebp
        ret     0
_vngo_build_edgezgt  ENDP


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; Compute edges for non-zbuffered triangles
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿

_vngo_build_edgegt   PROC NEAR
        push    ebp
        mov     ebp, esp
        sub     esp, 40                                 
        push    ebx
        push    esi

        mov     esi, DWORD PTR _p1[ebp]
        push    edi
        mov     edi, DWORD PTR _p2[ebp]
        mov     edx, DWORD PTR [esi+4]
        mov     ecx, DWORD PTR [edi+4]
        sub     ecx, edx

        cmp     ecx,1
        jle     done                                    ; Bail if there is nothing to do.

; Compute idy.
        mov     edx,1
        xor     eax,eax
        idiv    ecx

        mov     edx, DWORD PTR [esi+4]
        mov     ecx, DWORD PTR [edi+4]
        mov     ebx, DWORD PTR [esi+8]
        mov     DWORD PTR _idy[ebp], eax
        lea     eax, DWORD PTR [edx+65535]
        add     ecx, 0000ffffH
        and     eax, 0ffff0000H
        and     ecx, 0ffff0000H
        sub     ecx, eax
        sub     eax, edx
        mov     edx, DWORD PTR [edi+8]
        shr     ecx, 16                                 ; 00000010H
        sub     edx, ebx

        cmp     ecx,1
        jl      done
        mov     DWORD PTR _ycnt[ebp],ecx

        mov     ecx,eax

        mov     eax, DWORD PTR [edi]

        mov     ebx, DWORD PTR [esi]
        sub     eax, ebx
        imul    DWORD PTR _idy[ebp]
        shld    edx, eax, 16

        mov     DWORD PTR _xstep[ebp],edx
        mov     eax,ecx
        imul    edx
        shrd    eax, edx, 16

        mov     edx, DWORD PTR [edi+20]
        lea     eax,[eax+ebx+65535]
;        cmp     DWORD PTR _is_right[ebp], 0
;        jne     @f
;        dec     eax
;@@:
        mov     ebx, DWORD PTR [esi+20]
        mov     DWORD PTR _curx[ebp], eax


        sub     edx, ebx
        mov     eax, edx
        imul    DWORD PTR _idy[ebp]
        shrd    eax, edx, 16
        mov     DWORD PTR _ustep[ebp], eax

        imul    ecx
        shld    edx,eax,16

        mov     eax, DWORD PTR [edi+24]
        add     ebx, edx
        mov     edx, DWORD PTR [esi+24]

        sub     eax, edx
        imul    DWORD PTR _idy[ebp]
        shrd    eax,edx,16
        mov     DWORD PTR _vstep[ebp], eax

        imul    ecx
        shld    edx,eax,16

        mov     eax, DWORD PTR [esi+24]
        add     edx, eax
        mov     DWORD PTR _curv[ebp], edx

        mov     eax, DWORD PTR [edi+16]
        sub     eax, DWORD PTR [esi+16]
        imul    DWORD PTR _idy[ebp]
        shrd    eax, edx, 16

        mov     DWORD PTR _sstep[ebp],eax
        mov     esi, DWORD PTR [esi+16]
        imul    ecx


        shrd    eax, edx, 16

        mov     edi, DWORD PTR _curz[ebp]
        lea     edx, DWORD PTR [eax+esi]
        mov     esi, DWORD PTR _curx[ebp]
        mov     eax, DWORD PTR _edge[ebp]
        mov     edi, _xstep[ebp]

        push    ebp                     ; this is an un-orthodox practice.
        mov     ebp,__curv[esp]
        jmp     SHORT inside_loop

ALIGN   16
;==============================================================================
;
; Main loop!
;       ecx     work register.
;       eax     edge pointer
;       ebx     current U
;       ebp     current V
;       edx     current Shade
;       esi     current X
;       edi     xstep
;
;==============================================================================
inside_loop:
; Start X compute
        mov     ecx, esi
        lea     eax,[eax+32]             ; increment edge. 
        shr     ecx, 16                                 
        mov     DWORD PTR [eax-32], ecx
        add     esi, edi
; End X compute.
; Start U compute.
        mov     DWORD PTR [eax-12], ebx
        add     ebx, DWORD PTR __ustep[esp]
; End U compute
; Start V compute
        mov     DWORD PTR [eax-8], ebp
        add     ebp, DWORD PTR __vstep[esp]
; End V compute
; Start S compute
        mov     DWORD PTR [eax-16], edx
        add     edx, DWORD PTR __sstep[esp]
; End S compute
        dec     DWORD PTR __ycnt[esp]
        jne     SHORT inside_loop
        pop     ebp                     ; this is an un-orthodox practice.

;==============================================================================
;
; Main loop end.
;
;==============================================================================
done:
        pop     edi
        pop     esi
        pop     ebx
        mov     esp, ebp
        pop     ebp
        ret     0
_vngo_build_edgegt   ENDP

_TEXT   ENDS

END
