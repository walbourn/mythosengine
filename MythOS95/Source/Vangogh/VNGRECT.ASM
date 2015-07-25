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
; vngRECT.ASM 
;
;      This module draws filled rectangles in all of their permutations.
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


SETUP_RECT_DRAW8   MACRO  
        mov     esi,CurScreen

        mov     edi,(VNGO_VBUFFER PTR [esi]).vb_scrn_ptr
        mov     ebx,(VNGO_VBUFFER PTR [esi]).vb_width

        mov     ecx,rectptr
        mov     eax,(VNGO_RECT PTR [ecx]).rect_x
        mov     LX1,eax
        mov     eax,(VNGO_RECT PTR [ecx]).rect_dx
        mov     LDX,eax
        mov     eax,(VNGO_RECT PTR [ecx]).rect_dy
        mov     LDY,eax
        mov     eax,(VNGO_RECT PTR [ecx]).rect_y
        mov     LY1,eax
        mov     ecx,(VNGO_VBUFFER PTR [esi]).vb_ytable
        lea     eax,[ecx+eax*4]
        mov     eax,[eax]

ENDM


;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
;
;                                 Code
;
;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±


_TEXT  SEGMENT PARA PUBLIC USE32 'CODE'

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
;  vngo_rect8 (rectangle *,dword color);                                   ³
;      Expects color to be either an 8bit or 24bit color which it will use ³
;      to fill the screen with.                                            ³
;                                                                          ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

START_PROC     vngo_rect8, C CurScreen:DWORD, rectptr:DWORD, color:DWORD

        LOCAL   LX1             ; Top left x of the rect to fill.
        LOCAL   LDX             ; width of the rect to fill.
        LOCAL   LY1             ; Top left y of the rect to fill.
        LOCAL   LDY             ; height of the rect to fill.

        push    edi
        push    esi
        push    ebx

        SETUP_RECT_DRAW8   

        add     eax,LX1
        add     edi,eax
        mov     ecx,LDX

        mov     eax,color
        mov     ah,al
        mov     edx,eax
        shl     eax,16
        and     edx,0ffffh
        or      eax,edx
        mov     edx,LDY
        mov     esi,ecx
        sub     ebx,esi

y_loop:
        mov     ecx,esi
        shr     ecx,2
    rep stosd
        mov     ecx,esi
        and     ecx,03h
    rep stosb
        add     edi,ebx         ; go to the next scan line.
        dec     edx
        jg      y_loop

        pop	ebx
        pop	esi
        pop	edi
        ret
END_PROC       vngo_rect8     


START_PROC      vngo_Xrect8, C CurScreen:DWORD, rectptr:DWORD, color:DWORD
        LOCAL   LX1             ; Top left x of the rect to fill.
        LOCAL   LDX             ; width of the rect to fill.
        LOCAL   LY1             ; Top left Y of the rect to fill.
        LOCAL   LDY             ; height of the rect to fill.
        LOCAL   LDX2
        

        push    edi
        push    esi
        push    ebx

        SETUP_RECT_DRAW8

        add     eax,LX1
        shr     eax,2
        shr     ebx,2
        add     edi,eax
        mov     ecx,LDX
        shr     ecx,2
        mov     LDX2,ecx
        mov     esi,4

OutSide_loop:
        mov     ecx,LX1
        and     ecx,3
        mov     eax,(100h+MAP_MASK)
        mov     dx,SC_INDEX
        shl     ah,cl
        out     dx,ax

        mov     eax,color
        mov     ah,al

Inside_loop:
        mov     ecx,LDX2
        shr     ecx,3
        rep stosw
        adc     ecx,0
        rep stosb
        add     edi,ebx
        dec     LDY
        jnz     Inside_loop
        inc     LX1
        dec     LDX
        dec     esi
        jnz     OutSide_loop

        pop     ebx
        pop     esi
        pop     edi
        ret

END_PROC       vngo_Xrect8




;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
;  vngo_rect8 (rectangle *,dword color);                                   ³
;      Expects color to be either an 8bit or 24bit color which it will use ³
;      to fill the screen with.                                            ³
;                                                                          ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

START_PROC     zbuff_reset_rect16, C CurScreen:DWORD, rectptr:DWORD, depth:DWORD

        LOCAL   LX1             ; Top left x of the rect to fill.
        LOCAL   LDX             ; width of the rect to fill.
        LOCAL   LY1             ; Top left y of the rect to fill.
        LOCAL   LDY             ; height of the rect to fill.

        push    edi
        push    esi
        push    ebx

        SETUP_RECT_DRAW8        ; setup as 8bits and then modify the results
                                ; for 16bits.

        add     eax,LX1
        shl     eax,1           ; mul * 2 for 16bits rather than 8bits.
        mov     edi,(VNGO_VBUFFER PTR [esi]).vb_zbuff_ptr
        add     edi,eax
        mov     ecx,LDX         
        shl     ecx,1           ;
        shl     ebx,1           ; pitch is doubled for 16bits.

        mov     eax,depth       ; it is already expanded to 32bits.

        mov     edx,LDY         ; LDY doesn't get modified, since it is pixels.
        mov     esi,ecx
        sub     ebx,esi

y_loop:
        mov     ecx,esi
        shr     ecx,2
    rep stosd
        mov     ecx,esi
        and     ecx,03h
    rep stosb
        add     edi,ebx         ; go to the next scan line.
        dec     edx
        jg      y_loop

        pop	ebx
        pop	esi
        pop	edi
        ret
END_PROC       zbuff_reset_rect16     

_text   ends
        end

;°±² End of module - vngRECT.asm ²±°
