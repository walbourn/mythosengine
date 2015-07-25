;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
;                                   ____
;                                  / __ \
;                                 ( (__) )
;                                 _\____/___
;                                /  |  |   /\
;                               /_________/  \_
;                              /          \    \
;                             /            \    \_
;                            /              \     \
;                           /                \     \_
;                          /                  \      \
;                         /                    \      \_
;                        /                      \       \
;                       /                        \       \_
;                      /                          \        \
;                     /                            \        \_
;                    /                              \         \
;                   / N  N EEE W   W TTTTT  OO  N  N \        /
;                  /  NN N E_  W   W   T   O  O NN N  \      /
;                 /   N NN E   W W W   T   O  O N NN   \    /
;                /    N  N EEE  W W    T    OO  N  N    \  /
;               /________________________________________\/
;
;                     Newtonian Physics Simulation Library
;
;            Copyright (c) 1995, 1996 by Charybdis Enterprises, Inc.
;                           All Rights Reserved.
;
;                       Microsoft Windows '95 Version
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
; Created by Dan Higdon
;
; newtmath.asm
;
;       Contains the various arithmetic operations for the NewtVector class
;       in the 'math' header.
;
;               newt_cross
;               asm_newt_dot
;               asm_newt_magnitude
;
;       Assumes all values are represented as signed 16.16 fixed-point.
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
include newtmath.inc
include felix.inc

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

EXTERN  asm_flx_sqrt:NEAR

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; newt_cross                                                               ³
;                                                                          ³
; NewtVector * (NewtVector *v1,NewtVector *v2,NewtVector *dest);           ³
;                                                                          ³
;       This returns the pointer to the dest, and dest is filled out by the³
;       completion of the cross product of v1 & v2.                        ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

;
; (i', j', k') = v1 CROSS v2
;
;       i' = (v1.j * v2.k) - (v1.k * v2.j)
;       j' = (v1.k * v2.i) - (v1.i * v2.k)
;       k' = (v1.i * v2.j) - (v1.j * v2.i)
;

        ALIGN   16
START_PROC      newt_cross,     C       v1:DWORD, v2:DWORD,dest:DWORD
        LOCAL   icomp:DWORD
        LOCAL   jcomp:DWORD

        push    esi
        push    edi

        mov     esi,v1
        mov     edi,v2

; Compute I component: i' = (v1.j * v2.k) - (v1.k * v2.j)

        mov     eax,(NEWT_VECTOR PTR [esi]).nv_j
        imul    (NEWT_VECTOR PTR [edi]).nv_k
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,(NEWT_VECTOR PTR [esi]).nv_k
        imul    (NEWT_VECTOR PTR [edi]).nv_j
        shrd    eax,edx,16
        sub     ecx,eax
        mov     icomp,ecx

; Compute J component: j' = (v1.k * v2.i) - (v1.i * v2.k)

        mov     eax,(NEWT_VECTOR PTR [esi]).nv_k
        imul    (NEWT_VECTOR PTR [edi]).nv_i
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,(NEWT_VECTOR PTR [esi]).nv_i
        imul    (NEWT_VECTOR PTR [edi]).nv_k
        shrd    eax,edx,16
        sub     ecx,eax
        mov     jcomp,ecx

; Compute K component: k' = (v1.i * v2.j) - (v1.j * v2.i)

        mov     eax,(NEWT_VECTOR PTR [esi]).nv_i
        imul    (NEWT_VECTOR PTR [edi]).nv_j
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,(NEWT_VECTOR PTR [esi]).nv_j
        imul    (NEWT_VECTOR PTR [edi]).nv_i
        shrd    eax,edx,16
        sub     ecx,eax

; Now save the results.
        mov     eax,dest
        mov     (NEWT_VECTOR PTR [eax]).nv_k,ecx
        mov     ecx,jcomp
        mov     (NEWT_VECTOR PTR [eax]).nv_j,ecx
        mov     ecx,icomp
        mov     (NEWT_VECTOR PTR [eax]).nv_i,ecx

; EAX already has the dest pointer in it to be returned.

        pop     edi
        pop     esi
        ret

END_PROC        newt_cross


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; asm_newt_dot                                                             ³
;                                                                          ³
; Flx16 (NewtVector *v1,NewtVector *v2);                                   ³
;                                                                          ³
;       This function returns a Flx16 as the result of a DOT product       ³
;       between the two vectors that are passed in as paramaters.          ³
;       This function caries 32.32 precision until complete then converts  ³
;       back to 16.16                                                      ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

;
; x = v1 DOT v2 =  (v1.i*v2.i) + (v1.j*v2.j) + (v1.k*v2.k)
;

        ALIGN   16
START_PROC      asm_newt_dot,   C       v1:DWORD, v2:DWORD
        push    esi
        push    edi
        push    ebx
        mov     esi,v1
        mov     edi,v2

        ; I component
        mov     eax,(NEWT_VECTOR PTR [esi]).nv_i
        imul    (NEWT_VECTOR PTR [edi]).nv_i
        mov     ebx,edx
        mov     ecx,eax

        ; J component
        mov     eax,(NEWT_VECTOR PTR [esi]).nv_j
        imul    (NEWT_VECTOR PTR [edi]).nv_j
        add     ecx,eax
        adc     ebx,edx

        ; K component.
        mov     eax,(NEWT_VECTOR PTR [esi]).nv_k
        imul    (NEWT_VECTOR PTR [edi]).nv_k
        add     eax,ecx
        adc     edx,ebx
        shrd    eax,edx,16
        
        ; eax has the 16.16 result of the dot product.
        pop     ebx
        pop     edi
        pop     esi
        ret

END_PROC        asm_newt_dot


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; asm_newt_magnitude                                                       ³
;                                                                          ³
; returns:  Flx16                                                          ³
;                                                                          ³
; parms:    NewtVector *  vector to take the magnitude of.                 ³
;                                                                          ³
;       This function returns a Flx16 as the magnitude of the vector that  ³
;       is passed into the function.  This function uses 64bit internal    ³
;       math to prnvent overflow and then converts back to 16.16 for the   ³
;       final result.                                                      ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

;
; magnitude = sqrt(i^2 + j^2 + k^3)
;

        ALIGN   16
START_PROC      asm_newt_magnitude,     C       vect:DWORD
        LOCAL   resulth:DWORD
        LOCAL   resultl:DWORD
        push    esi
        mov     esi,vect

; Square I component.

        mov     eax,(NEWT_VECTOR PTR [esi]).nv_i
        imul    eax
        shrd    eax,edx,16      ; adjust back to 48.16 notation.
        sar     edx,16
        mov     resultl,eax
        mov     resulth,edx

; Square J component.

        mov     eax,(NEWT_VECTOR PTR [esi]).nv_j
        imul    eax
        shrd    eax,edx,16      ; adjust back to 48.16 notation.
        sar     edx,16
        add     resultl,eax
        adc     resulth,edx

; Square K component.

        mov     eax,(NEWT_VECTOR PTR [esi]).nv_k
        imul    eax
        shrd    eax,edx,16      ; adjust back to 48.16 notation.
        sar     edx,16
        add     eax,resultl
        adc     edx,resulth


; the maximum result is a 34.16 number.
; Edx,Eax now has the 64bit Sum of the squares.

        xor     ecx,ecx
check_again:
        or      edx,edx
        jnz     @f
        cmp     eax,0
        jl      @f
        jmp     short get_sqrt
@@:
        shrd    eax,edx,2
        shr     edx,2
        inc     ecx
        jmp     short check_again

get_sqrt:
        push    ecx
        push    eax
        call    asm_flx_sqrt
        lea     esp,[esp+4]     ; clear parms.

        pop     ecx             ; restore the shift quantity.
        shl     eax,cl          ; shift up to the correct scale.
                                
        pop     esi
        ret
END_PROC        asm_newt_magnitude

_text   ends
        end

;°±² End of module - newtmath.asm ²±°
