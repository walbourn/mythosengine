;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
;
;                                /\    /\
;                               /  \  /  \
;                              /    \/    \
;                             /  /\    /\  \
;                            /  /  \  /  Y T H O S
;                           /  /    \/    \  \
;                          /  /            \  \
;                         /__/              \__\
;
;                  Microsoft Windows 95/98/NT Version
;
;  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
;
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
; Created by Chuck Walbourn
;
; mytmmx.asm
;
; Contains the mythos_detect_mmx routine.
;
;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

.586p

        OPTION SCOPED                   ; Enable local labels.

;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
;
;                                Includes
;                                
;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

include macros.inc

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
; int mythos_detect_mmx();                                                 ³
;                                                                          ³
; Returns 1 if MMX instructions are supported, 0 otherwise.                ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

START_PROC     mythos_detect_mmx,  C
        push    ebx

;ÄÄÄ See if CPU ID will be supported by checking if bit 21 is writable
        pushfd
        pop     eax
        mov     edx, eax
        xor     eax, 00200000h
        push    eax
        popfd
        pushfd
        pop     eax
        cmp     eax, edx
        jz      no_mmx
        cmp     eax, 1
        jl      no_mmx

;ÄÄÄ Execute CPUID and check feature bit for MMX (bit 23)
        mov     eax,1
        cpuid
        and     edx, 00800000h
        jz      no_mmx

;ÄÄÄ MMX Found!
        mov     eax,1
        jmp     exit

no_mmx:
        xor     eax,eax

exit:
        pop     ebx
        ret
END_PROC       mythos_detect_mmx

_TEXT   ends
        end

;°±² End of module - mytmmx.asm ²±°
