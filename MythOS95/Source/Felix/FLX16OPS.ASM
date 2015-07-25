;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
;
;
;            _,'|             _.-''``-...___..--';)
;           /_ \'.      __..-' ,      ,--...--'''
;          <\    .`--'''       `     /'     
;           `-';'               ;   ; ;  Felix the Fixed-point Library
;     __...--''     ___...--_..'  .;.'
;    (,__....----'''       (,..--''
;
;                      Microsoft Windows '95 Version
;   
;           Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.
;                           All Rights Reserved.
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
; flx16ops.asm
;
;     This file has all of the Felix 16.16 operator functions.
;
;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

.486p

        OPTION SCOPED                   ; Enable local labels.

;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
;
;                                Includes
;                                
;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

include felix.inc
include macros.inc

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
; flx_muldiv (flx16 flx1,flx16 flx2,flx16 flx3);                           ³
;      This function takes three felix 16's and multiplies the first two   ³
;      together and then divides the result by the third and it does so    ³
;      without a loss of precision in the intermediate value.              ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
if 1
START_PROC      asm_flx_muldiv,     C   flx1:DWORD,flx2:DWORD,flx3:DWORD
       mov      edx,flx2
       mov      eax,flx1
       mov      ecx,flx3
       imul     edx
       idiv     ecx
       ret
END_PROC        asm_flx_muldiv

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; flx_16mul16(flx16 flx1,flx16 flx2);                                      ³
;       This function takes two felix 16's and multiplies them together    ³
;       with no loss in precision.  It returns a flx16 with the result.    ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      asm_flx_16mul16,    C       flx1:DWORD, flx2:DWORD
        mov     eax,flx1
        imul    flx2
        shrd    eax,edx,16
        adc     eax,0           ; round the least significant bit.
        ret
END_PROC        asm_flx_16mul16

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; flx_16mul30(flx16 flx1,flx16 flx2);                                      ³
;       This function takes a felix 16 and multiplies it with a felix 30   ³
;       It returns a flx16 with the result.                                ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      asm_flx_16mul30,    C       flx1:DWORD, flx2:DWORD
        mov     eax,flx1
        imul    flx2
        shrd    eax,edx,16
        adc     eax,0           ; round the least significant bit.
        ret
END_PROC        asm_flx_16mul30

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; flx_16div16(flx16 flx1,flx16 flx2);                                      ³
;       This function takes two felix 16's and divides the 1st by the 2nd  ³
;       with no loss in precision.  It returns a flx16 with the result.    ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      asm_flx_16div16,    C       flx1:DWORD, flx2:DWORD
        mov     edx,flx1
        xor     eax,eax
        shrd    eax,edx,16
        sar     edx,16
        idiv    flx2
;        mov     eax,flx1
;        shld    edx,eax,16
;        shl     eax,16
;        movsx   edx,dx
;        idiv    flx2
        ret
END_PROC        asm_flx_16div16



;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; asm_flx_recip230(flx16 flx1);                                            ³
;       This function takes a felix 16 and does the reciprical of it and   ³
;       returns it as a signed 2.30 in a dword.                            ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      asm_flx_recip230,   C   flx1:DWORD
        mov     edx,08000h
        xor     eax,eax
        idiv    flx1
        shr     eax,1
        adc     eax,0
        ; the reciprical is now in eax.
        ret
END_PROC        asm_flx_recip230
endif

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; flx_sin(flx16 degrees);                                                  ³
;       This function takes a felix 16 as degrees and returns the sine of  ³
;       the passed in degrees in a felix 16.                               ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

START_PROC      asm_flx_sin,        C       degrees:DWORD
        mov     eax,degrees
        cmp     eax,0           ; is it negative?
        jl      do_negative
@@:
        cmp     eax,(360 SHL FLX16_SHIFTS)
        jl      SHORT get_val
        sub     eax,(360 SHL FLX16_SHIFTS)
        jmp     SHORT @b
get_val:
        shr     eax,(FLX16_SHIFTS-FLX_DEGRES_SHIFT)
        mov     edx,eax         ; save the degrees. in 31.1
        cmp     eax,(180 SHL FLX_DEGRES_SHIFT)
        jl      @f
        sub     eax,(180 SHL FLX_DEGRES_SHIFT)
@@:
        cmp     eax,(90 SHL FLX_DEGRES_SHIFT)
        jl      all_adjust_done ; is it in the 1st quadrant?
        push    ebx
        mov     ebx,(180 SHL FLX_DEGRES_SHIFT)
        sub     ebx,eax
        mov     eax,ebx
        pop     ebx
all_adjust_done:
        mov     ecx,offset Flx16_sin_data
        mov     eax,[ecx+eax*4]
        cmp     edx,(180 SHL FLX_DEGRES_SHIFT)
                                ; is it in quadrant 3 or 4?       
        jle     SHORT done
        neg     eax
done:
        ret
do_negative:
        add     eax,(360 SHL FLX16_SHIFTS)
        cmp     eax,0
        jge     SHORT get_val
        jmp     SHORT do_negative
END_PROC        asm_flx_sin



;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; flx_cos(flx16 degrees);                                                  ³
;       This function takes a felix 16 as degrees and returns the cosine   ³
;       of the passed in degrees in a felix 16.                            ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      asm_flx_cos,        C       degrees:DWORD
        mov     eax,degrees
        add     eax,(90 SHL FLX16_SHIFTS)
                                ; add 90 degrees and go to the sin function.
        push    eax
        call    asm_flx_sin
        add     esp,4
        ret
END_PROC        asm_flx_cos



;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; flx_abs(flx16 flx);                                                      ³
;       This function takes a felix 16 and returns the absolute value of   ³
;       it.                                                                ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      asm_flx_abs,        C       flx:DWORD
        mov     eax,flx
        cmp     eax,0
        jg      @f              ; if it is less than zero, negate it!
        neg     eax
@@:
        ret
END_PROC        asm_flx_abs
_text   ends        
        end
;°±² End of module - flx16ops.asm ²±°
