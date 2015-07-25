;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
;
;                                                           %__________%
;                                                          %/ . .  .   \%
;           Van Gogh 2D-Display Library                     |  . .  o. |
;                                                           |. _  .   .|
;        Microsoft Windows 95/98/NT Version                 | / \   .  |
;                                                           |_|_|_._._.|
;                                                           |.-.-.-.-..|
;                                                          %\__________/%
;                                                           %          %
;
;  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
;
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
;
; This file and all associated files are subject to the terms of the
; GNU Lesser General Public License version 2 as published by the
; Free Software Foundation (http://www.gnu.org).   They remain the
; property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
; See LICENSE.TXT in the distribution for a copy of this license.
;
; THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
; OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
; PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
; LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
; OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
;
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
;
;                        http://www.mythos-engine.org/
;
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
;
; Created by Tim Little
;
; vngLINE.ASM 
;
;      This module does the 2D-Line draw in all of its permutations.
;
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
_DATA   SEGMENT PARA PUBLIC USE32 'DATA'
_DATA   ENDS

;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
;
;                                Macros
;
;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; Setup vport info and set EDI to point to the location in the buffer to   ³
; begin drawing to.  ESI is the Y step value (either positive or negative  ³
; buffer width.  It also will convert the color from RGB to 8bit if needed.³
;                                                                          ³
; This macro is used for all lines which are physicaly drawn with 8 bits.  ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
SETUP_LINE_DRAW8   MACRO  
        mov     esi,CurScreen

        mov     edi,(VNGO_VBUFFER PTR [esi]).vb_scrn_ptr
        mov     eax,LY1
        shr     eax,16
        mov     ebx,(VNGO_VBUFFER PTR [esi]).vb_pitch
        mov     edx,(VNGO_VBUFFER PTR [esi]).vb_ytable
        mov     edx,[edx+(eax*4)]
        add     edi,edx
        mov     eax,LX1
        shr     eax,16
        add     edi,eax
        mov     eax,LY1
        cmp     eax,LY2
        mov     esi,ebx         ; vb_pitch
        jl      @f
        neg     esi
@@:
        ENDM

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; This macro sorts the endpoints to always draw x-positive and converts    ³
; all of the endpoints into 16.16 format and puts them in LOCAL vars.      ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ADJ_LINE_PARMS  MACRO
        LOCAL   adj_exit
   ;Adjust X1,X2 to 16.16 and check for sort order.
        mov     ecx,p1
        mov     edx,p2
        mov     eax,(VNGO_POINT PTR [ecx]).pt_x                  
        mov     ebx,(VNGO_POINT PTR [edx]).pt_x 
        shl     eax,16
        shl     ebx,16
        cmp     eax,ebx
        jle     @f
   ;Sort order is X2 is left of X1:
   ;now we swap X1,X2, and Adjust Y1,Y2 to 16.16 and swap them.
        mov     LX1,ebx
        mov     LX2,eax
        mov     eax,(VNGO_POINT PTR [ecx]).pt_y
        mov     ebx,(VNGO_POINT PTR [edx]).pt_y 
        shl     eax,16
        shl     ebx,16
        mov     LY1,ebx
        mov     LY2,eax
        jmp     short adj_exit          ; done.
@@:
   ;Sort order is X1 is left of X2:
   ;Adjust Y1,Y2 to 16.16.
        mov     LX1,eax
        mov     LX2,ebx
        mov     eax,(VNGO_POINT PTR [ecx]).pt_y  
        mov     ebx,(VNGO_POINT PTR [edx]).pt_y 
        shl     eax,16
        shl     ebx,16
        mov     LY1,eax
        mov     LY2,ebx                 ; done.
adj_exit:
        ENDM


;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
;
;                                 Code
;
;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

_TEXT  SEGMENT PARA PUBLIC USE32 'CODE'

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
;  vngo_line8(dword color, long X1, long Y1, long X2, long Y2);            ³
;      Expects color to be an 8bit color value, and (X1,Y1)/(X2/Y2) to be  ³
;      screen co-ordinates.                                                ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC     vngo_line8, C CurScreen:DWORD, p1:DWORD, p2:DWORD
        LOCAL   LX1             ; x1 in 16.16 notation.
        LOCAL   LX2             ; x2 in 16.16 notation.
        LOCAL   LY1             ; y1 in 16.16 notation.
        LOCAL   LY2             ; y2 in 16.16 notation.
        LOCAL   color           ; hold the color.

        push    edi
        push    esi
        push    ebx

        mov     eax,p1
        mov     ebx,(VNGO_POINT PTR [eax]).pt_shade
        shr     ebx,3
        mov     eax,(VNGO_POINT PTR [eax]).pt_clr
        mov     ecx,CurScreen
        shl     eax,5
        mov     ecx,(VNGO_VBUFFER PTR [ecx]).vb_pal
        mov     ecx,[ecx+4]
        mov     ecx,[ecx]
        lea     ebx,[ebx+eax]
        xor     eax,eax
        mov     al,byte ptr [ebx+ecx]
        mov     color,eax

        ; Sort end points so that x_step is positive.
        ; Also puts them in 16.16 notation.

        ADJ_LINE_PARMS

        ; Setup veiw port info for the line draw and also
        ; setup y_step to be either pos or neg buffer width.

        SETUP_LINE_DRAW8

        ; Now determine if line is x major or y major.

        mov     eax,LX2         ; because ADJ_LINE_PARMS sorted the line
        sub     eax,LX1         ; for X, we know this value is >= 0.
                                ; so no need to perform ABS on it.
        je      VLine           ; if LX1 = LX2 then it is Vertical.
        mov     ecx,LY2
        sub     ecx,LY1
        je      HLine           ; if LY1 = LY2 then it is Horizontal.
        ABS     ecx
        cmp     ecx,1
        ja      @f
        dec     ecx
@@:
        cmp     eax,ecx
        jg      x_primary       ; jump if x primary line.
        jl      y_primary       ; jump if y primary line.

                                ; otherwise it is perfectly diagonal.
no_primary:
        inc     ecx             ; draw both ends.
        shr     ecx,16 
        mov     eax,color
        inc     esi
nop_loop:
        mov     [edi],al
        add     edi,esi
        dec     ecx
        jnz     nop_loop
        jmp     SHORT dline_exit

y_primary:
;; Use the 1/y table that is initialized for this mode rather than
;; doing the divide.  It is a little faster.
        mov     edx,CurScreen
        mov     edx,(VNGO_VBUFFER PTR [edx]).vb_invert
        shr     ecx,16          ; get dy in non fixed point. 
        inc     ecx             ; draw both ends.
        mov     edx,[edx+ecx*4] ; get 1/dy to multiply by.
        imul    edx
        shrd    eax,edx,14
        adc     eax,0           ; round it.
        mov     edx,eax         ; x_step in 0.32

        ; Screen pointer is in edi, and vport pitch in esi.

        mov     eax,color
;       mov     ebx,0
        mov     ebx,080000000h  ; .5 in 0.32

; total inside loop cycle count. (3 for pixel 4 for loop.  7 average.)
        ALIGN   4
yp_loop:        
        mov     [edi],al        ; write the color.
        add     ebx,edx         ; accumulate error  
        adc     edi,esi         ; just inc y if no role over other 
                                ; wise inc both.
        dec     ecx
        jnz     SHORT yp_loop   ; the dec and jnz are only 4 cycles
                                ; instead of the 7 for the loop.
                                ; go figure.
        jmp     SHORT dline_exit

x_primary:
;; Use the 1/y table that is initialized for this mode rather than
;; doing the divide.  It is a little faster.
        xchg    ecx,eax
        mov     edx,CurScreen
        mov     edx,(VNGO_VBUFFER PTR [edx]).vb_invert
        shr     ecx,16          ; get dx in non fixed point.
        inc     ecx             ; draw both ends.
        mov     edx,[edx+ecx*4] ; get 1/dx to multiply by.
        imul    edx
        shrd    eax,edx,14
        adc     eax,0           ; round it.
        mov     edx,eax         ; y_step in 0.32

        ; Screen pointer is in edi, and vport pitch in esi.

        mov     eax,color
;       mov     ebx,0
        mov     ebx,080000000h  ; .5 in 0.32

; total inside loop cycle count. (4 for pixel when no jump, 7 when jump,
;                                 4 for loop.  9.5 average.)
       ALIGN   4
xp_loop:
        mov     [edi],al        ; write the color.
        inc     edi             ; always inc X
        add     ebx,edx         ; accumulate error  
        jc      step_y          ; jump on carry since we will not
                                ; carry most of the time.
        dec     ecx             ; the dec and jnz are only 4 cycles
        jnz     SHORT xp_loop   ; instead of the 7 for the loop.
                                ; go figure. 
        jmp     short dline_exit
        ALIGN   4
step_y:
        add     edi,esi         ; just step Y on role over.
        dec     ecx             ; the dec and jnz are only 4 cycles
        jnz     SHORT xp_loop   ; instead of the 7 for the loop.
                                ; go figure. 

dline_exit:
        pop     ebx
        pop     esi
        pop     edi
        ret

HLine:
        mov     ecx,LX2
        sub     ecx,LX1
        inc     ecx             ; draw both ends.
        mov     eax,color
        mov     ah,al
        shr     ecx,17
    rep stosw
        jnc     @f
        mov     BYTE PTR [edi],al     
@@:
        jmp     SHORT dline_exit

VLine:
        mov     ecx,LY2
        sub     ecx,LY1
        ABS     ecx                     ; make shure we get a positive count.
        shr     ecx,16
        inc     ecx             ; draw both ends.
        mov     eax,color
        jcxz    SHORT one_pix           ; check for a zero length line.

        ALIGN   4
@@:
        mov     BYTE PTR [edi],al
        add     edi,esi
        dec     ecx
        jnz     @b
        jmp     SHORT dline_exit

one_pix:
        mov     BYTE PTR [edi],al
        jmp     SHORT dline_exit

END_PROC       vngo_line8     


START_PROC     vngo_zline8, C CurScreen:DWORD, p1:DWORD, p2:DWORD
        ret     ;; The Z-Buffered version of line is not yet supported.
END_PROC       vngo_zline8     

_text   ends
        end
;°±² End of module - vngline.asm ²±°
