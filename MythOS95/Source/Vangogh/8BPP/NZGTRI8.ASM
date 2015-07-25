;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
;
;                                                           %__________%
;                                                          %/ . .  .   \%
;           Van Gogh 2D-Display Library                     |  . .  o. | 
;                                                           |. _  .   .|
;          Microsoft Windows '95 Version                    | / \   .  | 
;                                                           |_|_|_._._.|
;  Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.   |.-.-.-.-..|
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
; vngPIX8.ASM 
;
;      This module draws a pixel on the screen in the specified color.
;
;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

.486p
        OPTION SCOPED                   ; Enable local labels.

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
_DATA   SEGMENT PARA PUBLIC USE32 'DATA'
_DATA   ENDS

;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
;
;                                 Code
;
;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

_TEXT  SEGMENT PARA PUBLIC USE32 'CODE'

EXTERN _calc_order:NEAR


; File ZGTRI8.cpp
_vb$ = 8
_pts$ = 12
_color$ = 16
_high_pt_idx$ = -16
_has_flat_top$ = -44
_low_pt_idx$ = -8
_mid_pt_idx$ = -12
_mid_pt$ = -124
_low_pt$ = -116
_edge1$ = -120
_edge2$ = -112
_s1$ = -88
_s2$ = -68
_z1$ = -84
_z2$ = -72
_xstep1$ = -40
_xstep2$ = -48
_sstep1$ = -32
_sstep2$ = -20
_sstep$ = -92
_zstep1$ = -28
_zstep2$ = -24
_zstep$ = -96
_edge1_on_left$ = -36
_line_count$ = -108
_stble$ = -80
_scrnptr$ = -64
_zptr$ = -60
_pitch$ = -4
_zpitch$ = -100
_curz$ = -76
_vngo_zgtriangle8 PROC NEAR
; Line 86
        sub     esp, 124                                
        mov     DWORD PTR _high_pt_idx$[esp+124], 0
        mov     DWORD PTR _has_flat_top$[esp+124], 0
        mov     DWORD PTR _low_pt_idx$[esp+124], 2
        mov     DWORD PTR _mid_pt_idx$[esp+124], 1
        lea     eax, DWORD PTR _low_pt_idx$[esp+124]
        push    ebx
        push    esi
        push    edi
        push    ebp
; Line 92
        mov     esi, DWORD PTR _pts$[esp+136]
        lea     ecx, DWORD PTR _mid_pt_idx$[esp+140]
        lea     edx, DWORD PTR _high_pt_idx$[esp+140]
        push    esi
        push    eax
        push    ecx
        push    edx
        call    _calc_order
        mov     eax, DWORD PTR _high_pt_idx$[esp+156]
        add     esp, 16                                 
; Line 94
        shl     eax, 5
        lea     edi, DWORD PTR [eax+esi]
; Line 95
        mov     eax, DWORD PTR _mid_pt_idx$[esp+140]
        shl     eax, 5
        add     eax, esi
        mov     ebp, DWORD PTR [edi+4]
        sar     ebp, 20                                 
        mov     DWORD PTR _mid_pt$[esp+140], eax
; Line 96
        mov     eax, DWORD PTR _low_pt_idx$[esp+140]
        shl     eax, 5
        add     eax, esi
        mov     DWORD PTR _low_pt$[esp+140], eax
        nop
; Line 98
        mov     ebx, DWORD PTR [eax+4]
        mov     eax, DWORD PTR _mid_pt$[esp+140]
        add     ebx, 524288                             
        sar     ebx, 20                                 
        mov     ecx, DWORD PTR [eax+4]
        sub     ebx, ebp
        add     ecx, 524288                             
        sar     ecx, 20                                 
;        inc     ebx
; Line 99
        sub     ecx, ebp
;       inc     ecx
; Line 101
        test    ebx, ebx
        je      $L23346
; Line 107
        mov     eax, DWORD PTR [edi]
        mov     edx, DWORD PTR [edi+16]
        mov     DWORD PTR _edge1$[esp+140], eax
        mov     DWORD PTR _s1$[esp+140], edx
; Line 109
        mov     eax, DWORD PTR [edi+8]
        mov     edx, DWORD PTR _low_pt$[esp+140]
        shr     eax, 1
        mov     DWORD PTR -80+[esp+140], eax
        mov     esi, DWORD PTR [edx]
; Line 111
        mov     edx, DWORD PTR [edi]
        mov     DWORD PTR _z1$[esp+140], eax
; Line 113
        mov     eax, esi
        sub     eax, edx
        cdq
        idiv    ebx
        mov     DWORD PTR _xstep1$[esp+140], eax
        test    ecx, ecx
; Line 124
        jne     $L23373
        mov     eax, DWORD PTR _mid_pt$[esp+140]
        mov     ecx, DWORD PTR [eax]
        mov     edx, DWORD PTR [eax+16]
        mov     DWORD PTR -100+[esp+140], ecx
        mov     DWORD PTR _edge2$[esp+140], ecx
; Line 126
        mov     ecx, DWORD PTR [eax+8]
        mov     DWORD PTR -104+[esp+140], edx
; Line 127
        shr     ecx, 1
        mov     eax, DWORD PTR -100+[esp+140]
        sub     esi, eax
        mov     DWORD PTR _s2$[esp+140], edx
; Line 128
        mov     eax, esi
        mov     DWORD PTR _z2$[esp+140], ecx
; Line 129
        cdq
        idiv    ebx
        mov     edx, DWORD PTR [edi]
        mov     DWORD PTR _xstep2$[esp+140], eax
; Line 131
        mov     eax, DWORD PTR -100+[esp+140]
        mov     DWORD PTR _line_count$[esp+140], ebx
        mov     DWORD PTR _has_flat_top$[esp+140], 1
; Line 135
        cmp     eax, edx
        jle     SHORT $L23374
        mov     eax, DWORD PTR _low_pt$[esp+140]
        mov     ecx, DWORD PTR -80+[esp+140]
        add     eax, 8
        mov     DWORD PTR -56+[esp+140], eax
; Line 137
        mov     eax, DWORD PTR [eax]
        shr     eax, 1
        sub     eax, ecx
        cdq
        idiv    ebx
        mov     edx, DWORD PTR [edi+16]
        mov     DWORD PTR _zstep1$[esp+140], eax
        mov     eax, DWORD PTR _low_pt$[esp+140]
        add     eax, 16                                 ; 00000010H
        mov     DWORD PTR _edge1_on_left$[esp+140], 1
        mov     ecx, DWORD PTR _edge2$[esp+140]
        mov     DWORD PTR -52+[esp+140], eax
; Line 138
        mov     eax, DWORD PTR [eax]
        add     ecx, 524288                             ; 00080000H
        sar     ecx, 20                                 ; 00000014H
        sub     eax, edx
        cdq
        idiv    ebx
        mov     DWORD PTR _sstep1$[esp+140], eax
; Line 140
        mov     eax, DWORD PTR _edge1$[esp+140]
        sar     eax, 20                                 ; 00000014H
        sub     ecx, eax
; Line 141
        je      $L23586
; Line 143
        mov     eax, DWORD PTR _s2$[esp+140]
        mov     edx, DWORD PTR _s1$[esp+140]
        sub     eax, edx
        mov     ebx, DWORD PTR _z1$[esp+140]
        cdq
        idiv    ecx
        mov     DWORD PTR _sstep$[esp+140], eax
; Line 144
        mov     eax, DWORD PTR _z2$[esp+140]
        sub     eax, ebx
        cdq
        idiv    ecx
        jmp     $L23587
; Line 152
$L23374:
; Line 154
        mov     eax, DWORD PTR _low_pt$[esp+140]
        mov     edx, DWORD PTR -104+[esp+140]
        mov     DWORD PTR _edge1_on_left$[esp+140], 0
        add     eax, 16                                 ; 00000010H
        mov     DWORD PTR -52+[esp+140], eax
; Line 155
        mov     eax, DWORD PTR [eax]
        sub     eax, edx
        cdq
        idiv    ebx
        mov     DWORD PTR _sstep2$[esp+140], eax
        mov     eax, DWORD PTR _low_pt$[esp+140]
        add     eax, 8
        mov     DWORD PTR -56+[esp+140], eax
; Line 156
        mov     eax, DWORD PTR [eax]
        shr     eax, 1
        sub     eax, ecx
        mov     ecx, DWORD PTR _edge1$[esp+140]
        cdq
        idiv    ebx
        add     ecx, 524288                             ; 00080000H
        mov     DWORD PTR _zstep2$[esp+140], eax
; Line 158
        sar     ecx, 20                                 ; 00000014H
        mov     eax, DWORD PTR _edge2$[esp+140]
        sar     eax, 20                                 ; 00000014H
        sub     ecx, eax
; Line 159
        je      $L23586
; Line 161
        mov     eax, DWORD PTR _s1$[esp+140]
        mov     edx, DWORD PTR _s2$[esp+140]
        sub     eax, edx
        mov     ebx, DWORD PTR _z2$[esp+140]
        cdq
        idiv    ecx
        mov     DWORD PTR _sstep$[esp+140], eax
; Line 162
        mov     eax, DWORD PTR _z1$[esp+140]
        sub     eax, ebx
        cdq
        idiv    ecx
        jmp     $L23587
; Line 171
$L23373:
; Line 173
        mov     eax, DWORD PTR _s1$[esp+140]
        mov     edx, DWORD PTR _z1$[esp+140]
        mov     esi, DWORD PTR _edge1$[esp+140]
        mov     DWORD PTR _s2$[esp+140], eax
; Line 174
        mov     eax, DWORD PTR _mid_pt$[esp+140]
        mov     DWORD PTR _z2$[esp+140], edx
; Line 175
        mov     edx, DWORD PTR [edi]
        mov     DWORD PTR _edge2$[esp+140], esi
        mov     esi, DWORD PTR [eax]
; Line 177
        mov     eax, esi
        sub     eax, edx
        cdq
        idiv    ecx
        mov     edx, DWORD PTR [edi+16]
        mov     DWORD PTR _xstep2$[esp+140], eax
        mov     eax, DWORD PTR _low_pt$[esp+140]
        add     eax, 16                                 ; 00000010H
        mov     DWORD PTR -52+[esp+140], eax
; Line 178
        mov     eax, DWORD PTR [eax]
        sub     eax, edx
        cdq
        idiv    ebx
        mov     edx, DWORD PTR -80+[esp+140]
        mov     DWORD PTR _sstep1$[esp+140], eax
        mov     eax, DWORD PTR _low_pt$[esp+140]
        add     eax, 8
        mov     DWORD PTR -56+[esp+140], eax
; Line 179
        mov     DWORD PTR _line_count$[esp+140], ecx
        mov     eax, DWORD PTR [eax]
        shr     eax, 1
        sub     eax, edx
        cdq
        idiv    ebx
        mov     ebx, DWORD PTR _xstep2$[esp+140]
        mov     DWORD PTR _zstep1$[esp+140], eax
; Line 183
        mov     eax, DWORD PTR _xstep1$[esp+140]
        cmp     ebx, eax
        jle     SHORT $L23383
; Line 185
        add     esi, 524288                             ; 00080000H
        mov     edx, DWORD PTR _edge1$[esp+140]
        mov     DWORD PTR _edge1_on_left$[esp+140], 1
; Line 186
        imul    eax, ecx
        sar     esi, 20                                 ; 00000014H
        add     eax, edx
        sar     eax, 20                                 ; 00000014H
        mov     edi, DWORD PTR _s1$[esp+140]
        sub     esi, eax
; Line 187
        mov     eax, DWORD PTR _sstep1$[esp+140]
        imul    eax, ecx
        imul    ecx, DWORD PTR _zstep1$[esp+140]
        add     edi, eax
        add     ecx, DWORD PTR _z1$[esp+140]
; Line 190
        test    esi, esi
        je      $L23586
; Line 192
        mov     eax, DWORD PTR _mid_pt$[esp+140]
        mov     eax, DWORD PTR [eax+16]
        sub     eax, edi
        cdq
        idiv    esi
        mov     edx, DWORD PTR _mid_pt$[esp+140]
        mov     DWORD PTR _sstep$[esp+140], eax
; Line 193
        mov     eax, DWORD PTR [edx+8]
        shr     eax, 1
        sub     eax, ecx
        cdq
        idiv    esi
        jmp     $L23587
; Line 201
$L23383:
; Line 203
        mov     eax, DWORD PTR _mid_pt$[esp+140]
        mov     ebx, DWORD PTR [edi+16]
        mov     DWORD PTR _edge1_on_left$[esp+140], 0
        mov     edx, DWORD PTR [eax+16]
        mov     eax, edx
        mov     DWORD PTR -104+[esp+140], edx
; Line 204
        sub     eax, ebx
        cdq
        idiv    ecx
        mov     edx, DWORD PTR _mid_pt$[esp+140]
        mov     edi, DWORD PTR -80+[esp+140]
        mov     DWORD PTR _sstep2$[esp+140], eax
        mov     eax, DWORD PTR [edx+8]
        shr     eax, 1
        mov     DWORD PTR -100+[esp+140], eax
; Line 205
        sub     eax, edi
        cdq
        idiv    ecx
        mov     edi, DWORD PTR _xstep1$[esp+140]
        mov     DWORD PTR _zstep2$[esp+140], eax
; Line 207
        sar     esi, 20                                 ; 00000014H
        mov     eax, DWORD PTR _edge1$[esp+140]
        imul    edi, ecx
        add     edi, eax
        mov     eax, DWORD PTR _sstep1$[esp+140]
        imul    eax, ecx
        imul    ecx, DWORD PTR _zstep1$[esp+140]
        add     edi, 524288                             ; 00080000H
        add     eax, DWORD PTR _s1$[esp+140]
        sar     edi, 20                                 ; 00000014H
        add     ecx, DWORD PTR _z1$[esp+140]
        sub     edi, esi
; Line 211
        test    edi, edi
        jle     SHORT $L23586
; Line 213
        sub     eax, DWORD PTR -104+[esp+140]
        cdq
        idiv    edi
        mov     DWORD PTR _sstep$[esp+140], eax
; Line 214
        mov     eax, ecx
        sub     eax, DWORD PTR -100+[esp+140]
        cdq
        idiv    edi
        jmp     SHORT $L23587
$L23586:
; Line 218
        xor     eax, eax
        mov     DWORD PTR _sstep$[esp+140], eax
$L23587:
; Line 219
        mov     edx, DWORD PTR _vb$[esp+136]
        mov     esi, DWORD PTR _color$[esp+136]
        mov     DWORD PTR _zstep$[esp+140], eax
; Line 226
        mov     eax, DWORD PTR [edx+20]
        mov     eax, DWORD PTR [eax+4]
; Line 228
        mov     cl, BYTE PTR [eax+4]
        mov     ebx, DWORD PTR [edx+16]
        shl     esi, cl
        mov     ecx, DWORD PTR [eax+16]
        mov     eax, DWORD PTR [edx+24]
        add     esi, ecx
        mov     ecx, DWORD PTR [edx+44]
        mov     eax, DWORD PTR [eax+ebp*4]
        mov     DWORD PTR _stble$[esp+140], esi
; Line 230
        add     eax, ebx
        mov     DWORD PTR _scrnptr$[esp+140], eax
; Line 231
        mov     eax, DWORD PTR [ecx+ebp*4]
        and     eax, -2                                 ; fffffffeH
        mov     ebp, DWORD PTR [edx+32]
        add     eax, ebp
        mov     ecx, DWORD PTR [edx+36]
        mov     edi, 4194304                            ; 00400000H
        mov     DWORD PTR _zptr$[esp+140], eax
; Line 232
        mov     eax, DWORD PTR [edx+40]
        mov     DWORD PTR _pitch$[esp+140], ecx
; Line 233
        shr     eax, 1
        mov     DWORD PTR _zpitch$[esp+140], eax

;  this is for problems with the seams.
        inc     DWORD PTR _line_count$[esp+140]

;;
;; Start of display loop.....
;;


; Line 242
        mov     eax, DWORD PTR _has_flat_top$[esp+140]
        cmp     eax, 2
        jge     $L23346
$L23411:
; Line 244
        mov     eax, DWORD PTR _edge1_on_left$[esp+140]
        test    eax, eax

        ;;
        ;; Start of outside loop 1.
        ;;

; Line 246
        mov     eax, DWORD PTR _line_count$[esp+140]
        je      $L23574
        test    eax, eax
        je      $L23430
        mov     eax, DWORD PTR _zpitch$[esp+140]
        add     eax, eax
        mov     DWORD PTR -104+[esp+140], eax
$L23415:
; Line 248
        mov     ecx, DWORD PTR _edge1$[esp+140]
        mov     esi, DWORD PTR _scrnptr$[esp+140]
;       add     ecx, 00080000h
        mov     edx, DWORD PTR _zptr$[esp+140]
        sar     ecx, 20                                 ; 00000014H
        mov     ebx, DWORD PTR _edge2$[esp+140]
; Line 249
; Added to help seaming problems.
        add     ebx, 080000h
        sar     ebx, 20                                 ; 00000014H
        add     esi, ecx
; Line 250
        lea     eax, DWORD PTR [edx+ecx*2]
        sub     ebx, ecx
; Line 253
        mov     ecx, DWORD PTR _s1$[esp+140]
        mov     edx, DWORD PTR _z1$[esp+140]
; Line 254

;;-----------------------------------------------------------------------------
;;
;; Setup of inside loop 1.
;; 
        mov     DWORD PTR _curz$[esp+140], edx
        js      SHORT $L23423
        inc     ebx
;; Start of inside loop 1.
        mov     edx, DWORD PTR _curz$[esp+140]          ; this is put back in edx 
        ALIGN 4                                         ; at the end of the loop.
$L23421:
        shr     edx, 15                                 ; get a working z value.
        cmp     WORD PTR [eax], dx                      ; leave if existing pixel 
        jbe     SHORT $L23425                           ; is closer than ours.  
;;
;; Start writing the pixel.
;;
        mov     WORD PTR [eax], dx                      ; write the new z value.
        lea     ebp, DWORD PTR [ecx+edi]                ; get the new shade value.

        sar     ebp, 23                                 ; put it in range for 
                                                        ; shade level. 
        mov     edx, DWORD PTR _stble$[esp+140]         ; get the shade table ptr
                                                        ; now to avoid an agi later.
        cmp     ebp, 31                                 ; Clamp the shade level.
        jna     SHORT $L23428                           ; Only do the clamp logic if bits outside of 0-4 are set. 
        jle     @f                                      ;   ||                            
        mov     ebp, 31                                 ;   ||                           
        jmp     SHORT $L23428                           ;   ||                           
@@:     test    ebp, ebp                                ;   ||                           
        jge     SHORT $L23428                           ;   \/                           
        xor     ebp, ebp                                ; Done clamping the shade level  
$L23428:
        mov     dl, BYTE PTR [ebp+edx]                  ; get the color.
        mov     BYTE PTR [esi], dl                      ; store the color.
;;
;; Done writing the pixel
;;
$L23425:
        inc     esi                                     ; Increment the screen ptr.
        mov     edx, DWORD PTR _sstep$[esp+140]
        mov     ebp, DWORD PTR _zstep$[esp+140]
        add     ecx, edx
        mov     edx, DWORD PTR _curz$[esp+140]
        xor     edi, 0400000h           
        add     edx, ebp
        dec     ebx                                     ; Decrement the loop counter.
                                                        ; doing this up here help branch prediction.
        lea     eax, [eax+2]                            ; Increment the Z-buffer ptr.
        mov     DWORD PTR _curz$[esp+140], edx

        jne     SHORT $L23421
;;
;; End of inside loop 1.
;;
;;-----------------------------------------------------------------------------
$L23423:
        mov     eax, DWORD PTR _xstep1$[esp+140]
        mov     ecx, DWORD PTR _edge1$[esp+140]
        add     ecx, eax
        mov     edx, DWORD PTR _xstep2$[esp+140]
        mov     ebx, DWORD PTR _edge2$[esp+140]
        mov     eax, DWORD PTR _sstep1$[esp+140]
        add     ebx, edx
        mov     ebp, DWORD PTR _s1$[esp+140]
        add     ebp, eax
        mov     edx, DWORD PTR _zstep1$[esp+140]
        mov     esi, DWORD PTR _z1$[esp+140]
        mov     eax, DWORD PTR _line_count$[esp+140]
        add     esi, edx
        dec     eax
        mov     DWORD PTR _edge1$[esp+140], ecx
        mov     DWORD PTR _edge2$[esp+140], ebx
        mov     ecx, DWORD PTR _pitch$[esp+140]
        mov     DWORD PTR _s1$[esp+140], ebp
        mov     edx, DWORD PTR -104+[esp+140]
        mov     DWORD PTR _z1$[esp+140], esi
        mov     DWORD PTR _line_count$[esp+140], eax
        mov     eax, DWORD PTR _scrnptr$[esp+140]
        add     eax, ecx
        mov     ecx, DWORD PTR _line_count$[esp+140]
        mov     DWORD PTR _scrnptr$[esp+140], eax
        mov     eax, DWORD PTR _zptr$[esp+140]
        add     eax, edx
        test    ecx, ecx
        mov     DWORD PTR _zptr$[esp+140], eax
        jne     $L23415
        jmp     $L23430
;;
;; End of outside loop 1.
;;

$L23574:
        test    eax, eax
        je      $L23430
        mov     eax, DWORD PTR _zpitch$[esp+140]
        add     eax, eax
        mov     DWORD PTR -104+[esp+140], eax
; Line 285
$L23432:
; Line 287
        mov     ecx, DWORD PTR _edge2$[esp+140]
        mov     esi, DWORD PTR _scrnptr$[esp+140]
;       add     ecx, 524288                             ; 00080000H
        mov     edx, DWORD PTR _zptr$[esp+140]
        sar     ecx, 20                                 ; 00000014H
        mov     ebx, DWORD PTR _edge1$[esp+140]
; Line 288
; added for seaming problems.
        add     ebx, 080000h
        sar     ebx, 20                                 ; 00000014H
        add     esi, ecx
; Line 289
        lea     eax, DWORD PTR [edx+ecx*2]
        sub     ebx, ecx
; Line 293

;;-----------------------------------------------------------------------------
;;
;; Inside loop 2. setup
;;
        mov     ecx, DWORD PTR _s2$[esp+140]
        mov     edx, DWORD PTR _z2$[esp+140]
        mov     DWORD PTR _curz$[esp+140], edx
        js      SHORT $L23440
        inc     ebx
;; Inside loop 2. start 
ALIGN 4
$L23438:
        shr     edx, 15                                 ; get  working z value.
        cmp     WORD PTR [eax], dx                      ; see if we are nearer.
        jbe     SHORT $L23442
;;
;; Start writing the pixel.
;;
        mov     WORD PTR [eax], dx                      ; Store the new Z.
        lea     ebp, DWORD PTR [ecx+edi]                ; get the new shade value.
        sar     ebp, 23                                 ; put it in range for 
                                                        ; shade level. 
        mov     edx, DWORD PTR _stble$[esp+140]         ; get the shade table ptr
                                                        ; now to avoid an agi later.
        cmp     ebp, 31                                 ; Clamp the shade level.
        jna     SHORT $L23445                           ; Only do the clamp logic if bits outside of 0-4 are set. 
        jle     @f                                      ;   ||                            
        mov     ebp, 31                                 ;   ||                           
        jmp     SHORT $L23445                           ;   ||                           
@@:     test    ebp, ebp                                ;   ||                           
        jge     SHORT $L23445                           ;   \/                           
        xor     ebp, ebp                                ; Done clamping the shade level  
$L23445:
        mov     dl, BYTE PTR [ebp+edx]                  ; get the color.
        mov     BYTE PTR [esi], dl                      ; store the color.
$L23442:
;;
;; Done writing the pixel.
;;
        inc     esi                                     ; Increment the screen ptr.
        mov     edx, DWORD PTR _sstep$[esp+140]
        mov     ebp, DWORD PTR _zstep$[esp+140]
        add     ecx, edx
        mov     edx, DWORD PTR _curz$[esp+140]
        add     edx, ebp
        xor     edi, 00400000h
        dec     ebx                                     ; Decrement the loop counter.
                                                        ; doing this up here help branch prediction.
        lea     eax, [eax+2]                            ; Increment the Z-buffer ptr.
        mov     DWORD PTR _curz$[esp+140], edx
        jne     SHORT $L23438
;;
;; End of inside loop 2.
;;
;;-----------------------------------------------------------------------------
$L23440:
        mov     eax, DWORD PTR _xstep1$[esp+140]
        mov     ecx, DWORD PTR _edge1$[esp+140]
        add     ecx, eax
        mov     edx, DWORD PTR _xstep2$[esp+140]
        mov     ebx, DWORD PTR _edge2$[esp+140]
        mov     eax, DWORD PTR _sstep2$[esp+140]
        add     ebx, edx
        mov     ebp, DWORD PTR _s2$[esp+140]
        add     ebp, eax
        mov     esi, DWORD PTR _z2$[esp+140]
        mov     eax, DWORD PTR _line_count$[esp+140]
        mov     DWORD PTR _edge1$[esp+140], ecx
        mov     ecx, DWORD PTR _zstep2$[esp+140]
        dec     eax
        add     esi, ecx
        mov     DWORD PTR _edge2$[esp+140], ebx
        mov     ecx, DWORD PTR _pitch$[esp+140]
        mov     DWORD PTR _s2$[esp+140], ebp
        mov     edx, DWORD PTR -104+[esp+140]
        mov     DWORD PTR _z2$[esp+140], esi
        mov     DWORD PTR _line_count$[esp+140], eax
        mov     eax, DWORD PTR _scrnptr$[esp+140]
        add     eax, ecx
        mov     ecx, DWORD PTR _line_count$[esp+140]
        mov     DWORD PTR _scrnptr$[esp+140], eax
        mov     eax, DWORD PTR _zptr$[esp+140]
        add     eax, edx
        test    ecx, ecx
        mov     DWORD PTR _zptr$[esp+140], eax
        jne     $L23432

;;
;; End of outer loop 2.
;;

$L23430:
; Line 324
        mov     eax, DWORD PTR _has_flat_top$[esp+140]
        test    eax, eax
        jne     $L23346
; Line 326
        mov     eax, DWORD PTR _low_pt$[esp+140]
        mov     ecx, DWORD PTR [eax+4]
        mov     eax, DWORD PTR _mid_pt$[esp+140]
        add     ecx, 080000h
        sar     ecx, 20                                 ; 00000014H
        mov     eax, DWORD PTR [eax+4]
        add     eax, 524288                             ; 00080000H
        sar     eax, 20                                 ; 00000014H
        sub     ecx, eax
;       inc     ecx
; Line 328
        test    ecx, ecx
        jle     SHORT $L23346
        mov     eax, DWORD PTR _mid_pt$[esp+140]
        mov     edx, DWORD PTR _low_pt$[esp+140]
        mov     ebx, DWORD PTR _edge1_on_left$[esp+140]
        nop
        mov     esi, DWORD PTR [eax]
; Line 330
        mov     eax, DWORD PTR [edx]
        sub     eax, esi
        cdq
        idiv    ecx
        mov     DWORD PTR _xstep2$[esp+140], eax
        test    ebx, ebx
; Line 331
        jne     SHORT $L23449
        mov     eax, DWORD PTR _mid_pt$[esp+140]
        mov     ebx, DWORD PTR [eax+8]
        mov     eax, DWORD PTR -56+[esp+140]
        shr     ebx, 1
; Line 333
        mov     eax, DWORD PTR [eax]
        shr     eax, 1
        sub     eax, ebx
        cdq
        idiv    ecx
        mov     edx, DWORD PTR _mid_pt$[esp+140]
        mov     DWORD PTR _zstep2$[esp+140], eax
; Line 335
        add     eax, ebx
        mov     DWORD PTR _z2$[esp+140], eax
        mov     ebx, DWORD PTR [edx+16]
; Line 336
        mov     eax, DWORD PTR -52+[esp+140]
        mov     eax, DWORD PTR [eax]
        sub     eax, ebx
        cdq
        idiv    ecx
        mov     DWORD PTR _sstep2$[esp+140], eax
; Line 338
        add     eax, ebx
        mov     DWORD PTR _s2$[esp+140], eax
; Line 340
$L23449:
        mov     eax, DWORD PTR _xstep2$[esp+140]
;       dec     ecx     ; because we are no longer adding 1 above
        add     eax, esi
        mov     edx, DWORD PTR _has_flat_top$[esp+140]
        inc     edx
        mov     DWORD PTR _edge2$[esp+140], eax
; Line 341
        mov     DWORD PTR _line_count$[esp+140], ecx
        mov     DWORD PTR _has_flat_top$[esp+140], edx
; Line 344
        cmp     edx, 2
        jl      $L23411
; Line 355
$L23346:
        pop     ebp
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 124                                ; 0000007cH
        ret     0
        ; This stuff is for alignment, I think.
        DB 08Dh, 49h, 00h
        DB 8dh, 0a4h, 24h, 00h,00h,00h,00h
_vngo_zgtriangle8 ENDP
_TEXT   ENDS
END
