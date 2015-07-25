;ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ
;ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
;שששששששששש°°°°°°°°°°ש°°°°°°°°ששש°°°°°°°°שש°°°שששש°°°ש°°°°°°°°°°ש°°°°°°°°°שש
;ששששששששש°±°ששששששש°±°שששש°±°ש°±°שששש°±°ש°±°שששש°±°ש°±°שששששששש°±°שששש°±°שש
;שששששששש±°±ששששששש±°±שששששששש±°±שששששששש±°±שששש±°±ש±°±שששששששש±°±שששש±°±ששש
;ששששששש±²±±°±±²שש±²±±°±±²±±ש±²±שששששששש±²±±°±±²±±ש±²±±°±±²ששש±²±±°±±²°ששששש
;שששששש±²±שששששששששששששש±²±ש±²±שששששששש±²±שששש±²±ש±²±שששששששש±²±שששש±²±ששששש
;ששששש²±²ששששששש²±²שששש²±²ש²±²שששש²±²ש²±²שששש²±²ש²±²שששששששש²±²שששש²±²שששששש
;שששש²²²²²²²²²²ש²²²²²²²²ששש²²²²²²²²שש²²²שששש²²²ש²²²²²²²²²²ש²²²שששש²²²ששששששש
;ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
;שששששששששששCopyrightש(c)ש1994-1996שbyשCharybdisשEnterprises,שInc.שששששששששש
;ששששששששששששששששששששששששששAllשRightsשReserved.ששששששששששששששששששששששששששששש
;ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
;ששששששששששששששששששששש Microsoft Windows '95 Version ששששששששששששששששששששששש
;ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
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
;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
;
; Created by Tim Little & Chuck Walbourn
;
; esmisc.asm
;
; Contains support assembly routines for misc. use.
;
;       asm_esch_raySphere
;
;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
;
;        Code assembled with Microsoft (R) Macro Assembler Version 6.11
;
;ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

.486p

        OPTION SCOPED                   ; Enable local labels.

;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
;
;                                Includes
;                                
;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

include macros.inc
include esmath.inc
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

;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
; asm_esch_raySphere                                                       ³
;                                                                          ³
; Computes the ray/sphere intersection of the ray starting at point and    ³
; moving along the unit vector ray with the sphere defined by the center   ³
; and the radius.                                                          ³
;                                                                          ³
; Flx16 asm_esch_raySphere(const EschPoint *point, const EschVector *ray,  ³
;                          const EschPoint *center, const Flx16 radius);   ³ 
;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ

; 
;  tvec.i = center.x - point.x
;  tvec.j = center.y - point.y
;  tvec.k = center.z - point.z
;
;  dot = tvec DOT ray
;
;  disc = (radius * radius) - (tvec DOT tvec) + (dot * dot)
;  (computed as disclow and dischigh)
;
;  if (disc < 0)
;       return 0
;
;  disc = sqrt(disc)
;
;  t2 = dot+disc
;  if (t2 <= 0)
;       return 0
;
;  t1 = dot-disc
;  if (t1 <= 0)
;       return t2
;
;  return t1
;

        ALIGN   16
START_PROC      asm_esch_raySphere,   C         point:DWORD, ray:DWORD, center:DWORD, radius:DWORD

        LOCAL   disclow:DWORD
        LOCAL   dischigh:DWORD
        LOCAL   dot:DWORD
        LOCAL   tvecI:DWORD
        LOCAL   tvecJ:DWORD
        LOCAL   tvecK:DWORD

        push    esi
        push    edi
        push    ebx

; Compute tvec from center and point

        mov     esi,center
        mov     edi,point
        
        mov     eax,(ESCH_POINT PTR [esi]).ep_x
        sub     eax,(ESCH_POINT PTR [edi]).ep_x
        mov     tvecI,eax
        
        mov     eax,(ESCH_POINT PTR [esi]).ep_y
        sub     eax,(ESCH_POINT PTR [edi]).ep_y
        mov     tvecJ,eax
        
        mov     eax,(ESCH_POINT PTR [esi]).ep_z
        sub     eax,(ESCH_POINT PTR [edi]).ep_z
        mov     tvecK,eax
        
; Compute dot-vector of tvec and ray, store as 'dot'

        mov     esi,ray

        ; I component
        mov     eax,(ESCH_VECTOR PTR [esi]).ev_i
        imul    tvecI
        mov     ebx,edx
        mov     ecx,eax

        ; J component
        mov     eax,(ESCH_VECTOR PTR [esi]).ev_j
        imul    tvecJ
        add     ecx,eax
        adc     ebx,edx

        ; K component.
        mov     eax,(ESCH_VECTOR PTR [esi]).ev_k
        imul    tvecK
        add     eax,ecx
        adc     edx,ebx
        shrd    eax,edx,16

        mov     dot,eax

; Compute disc

        mov     eax,radius
        imul    eax
        mov     disclow,eax
        mov     dischigh,edx

        mov     eax,dot
        imul    eax
        add     disclow,eax
        adc     dischigh,edx

        ; Compute the DOT product of tvec with itself.
        ; I component
        mov     eax,tvecI
        imul    eax
        mov     ebx,edx
        mov     ecx,eax

        ; J component
        mov     eax,tvecJ
        imul    eax
        add     ecx,eax
        adc     ebx,edx

        ; K component.
        mov     eax,tvecK
        imul    eax
        add     eax,ecx
        adc     edx,ebx

        sub     disclow,eax
        sbb     dischigh,edx

        mov     eax,disclow
        mov     edx,dischigh

        shrd    eax,edx,16
        sar     edx,16

; Check to see if sum is negative, which means no intersection

        cmp     edx,0
        jg      non_zero
        je      @f
        xor     eax,eax
        jmp     short exit
@@:
        cmp     eax,0
        jg      non_zero
        xor     eax,eax
        jmp     short exit
non_zero:

; Compute square-root of disc

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

        mov     disclow,eax

; Compute roots and return the one closest in front

        ; t2 = dot+disc

        add     eax,dot
        cmp     eax,0
        jg      @f
        xor     eax,eax
        jmp     short exit
@@:
        ; t1 = dot-disc

        mov     ebx,dot
        sub     ebx,disclow
        cmp     ebx,0
        jg      @f
        jmp     short exit

@@:
        mov     eax,ebx

exit:        
        pop     ebx
        pop     edi
        pop     esi
        ret

END_PROC        asm_esch_raySphere

_text   ends
        end

;°±² End of module - esmisc.asm ²±°
