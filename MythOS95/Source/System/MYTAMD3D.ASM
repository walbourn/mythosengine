;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
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
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
;
; THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
; OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
; PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
; LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
; OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
;
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
;
;                        http://www.mythos-engine.org/
;
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
;
; Created by Chuck Walbourn
;
; mytamd3d.asm
;
; Contains the mythos_detect_amd3d routine.
;
;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

.586p

        OPTION SCOPED                   ; Enable local labels.

;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
;
;                                Includes
;                                
;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

include macros.inc

;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
;
;                                 Data
;
;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

       ASSUME  ds:_DATA
_DATA  SEGMENT PARA PUBLIC USE32 'DATA'
_DATA  ENDS

;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
;
;                                 Code
;
;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

_TEXT  SEGMENT PARA PUBLIC USE32 'CODE'

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; int mythos_detect_amd3d();                                               �
;                                                                          �
; Returns 1 if the AMD-3D MMX instructions are supported, 0 otherwise.     �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

START_PROC     mythos_detect_amd3d,  C
        push    ebx

;陳� See if CPU ID will be supported by checking if bit 21 is writable
        pushfd
        pop     eax
        mov     edx, eax
        xor     eax, 00200000h
        push    eax
        popfd
        pushfd
        pop     eax
        cmp     eax, edx
        jz      no_amd3d

;陳� Execute CPUID and check for AuthenticAMD
        mov     eax,0
        cpuid
        cmp     eax,00000001h
        jne     no_amd3d
        cmp     ebx,68747541h
        jne     no_amd3d
        cmp     ecx,444d4163h
        jne     no_amd3d
        cmp     edx,69746e65h
        jne     no_amd3d

;陳� Execute CPUID check for extended functions
        mov     eax,80000000h
        cpuid
        cmp     eax,80000001h
        jl      no_amd3d

;陳� Execute CPUID check for AMD-3D (bit 31 of extended features)
        mov     eax,80000001h
        cpuid
        and     edx,80000000h
        jz      no_amd3d

;陳� AMD-3D Found!
        mov     eax,1
        jmp     exit

no_amd3d:
        xor     eax,eax

exit:
        pop     ebx
        ret
END_PROC       mythos_detect_amd3d

_TEXT   ends
        end

;葦� End of module - mytamd3d.asm 憶�
