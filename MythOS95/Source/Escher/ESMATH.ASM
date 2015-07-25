;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
;ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
;ùùùùùùùùùù°°°°°°°°°°ù°°°°°°°°ùùù°°°°°°°°ùù°°°ùùùù°°°ù°°°°°°°°°°ù°°°°°°°°°ùù
;ùùùùùùùùù°±°ùùùùùùù°±°ùùùù°±°ù°±°ùùùù°±°ù°±°ùùùù°±°ù°±°ùùùùùùùù°±°ùùùù°±°ùù
;ùùùùùùùù±°±ùùùùùùù±°±ùùùùùùùù±°±ùùùùùùùù±°±ùùùù±°±ù±°±ùùùùùùùù±°±ùùùù±°±ùùù
;ùùùùùùù±²±±°±±²ùù±²±±°±±²±±ù±²±ùùùùùùùù±²±±°±±²±±ù±²±±°±±²ùùù±²±±°±±²°ùùùùù
;ùùùùùù±²±ùùùùùùùùùùùùùù±²±ù±²±ùùùùùùùù±²±ùùùù±²±ù±²±ùùùùùùùù±²±ùùùù±²±ùùùùù
;ùùùùù²±²ùùùùùùù²±²ùùùù²±²ù²±²ùùùù²±²ù²±²ùùùù²±²ù²±²ùùùùùùùù²±²ùùùù²±²ùùùùùù
;ùùùù²²²²²²²²²²ù²²²²²²²²ùùù²²²²²²²²ùù²²²ùùùù²²²ù²²²²²²²²²²ù²²²ùùùù²²²ùùùùùùù
;ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
;ùùùùùùùùùùCopyrightù(c)ù1994,ù1995ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
;ùùùùùùùùùùùùùùùùùùùùùùùùùùAllùRightsùReserved.ùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
;ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
;ùùùùùùùùùùùùùùùùùùùùù Microsoft Windows '95 Version ùùùùùùùùùùùùùùùùùùùùùùù
;ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
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
; Created by Tim Little & Chuck Walbourn
;
; esmath.asm
;
;       Contains the various arithmetic operations for the EschPoint and
;       EschVector classes in the 'math' header.
;
;               esch_rotatex
;               esch_rotatey
;               esch_rotatez
;               esch_transform
;               esch_transform_notran
;
;       These routines assume that the EschPoint and EschVector classes are
;       identical to the assembly routine with x/i, y/j, z/k as the first
;       three dwords, represented as signed 16.16 fixed-point math.
;
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
;
;        Code assembled with Microsoft (R) Macro Assembler Version 6.11
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
include esmath.inc
include felix.inc

;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
;
;                                Equates
;
;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

MTX     equ     (ESCH_MATRIX PTR [edi])
VCT     equ     (ESCH_VECTOR PTR [esi])

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

EXTRN   asm_flx_sin     :NEAR
EXTRN   asm_flx_cos     :NEAR

_TEXT  SEGMENT PARA PUBLIC USE32 'CODE'

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_rotatex                                                             ³
;                                                                          ³
; void (void *vect,Flx16 deg);                                             ³
;                                                                          ³
;       This function rotates the passed in vector/point about the X-axis  ³
;       by the number of degrees specified in deg.                         ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

;
;  (i', j', k') = rotate-about-x (i, j, k)
;
;       i' = i
;       j' = j * c + k * s
;       k' = j * s + k * c
;

        ALIGN   16
START_PROC      esch_rotatex,   C       vect:DWORD, deg:DWORD, dest:DWORD

        LOCAL   newJ:DWORD

        push    esi
        push    edi
        push    ebx

; Get the sin & cosine for the rotation.
; Stores sin into 'esi' and cos into 'edi'

        mov     eax,deg
        push    eax
        call    asm_flx_sin
        add     esp,4
        mov     esi,eax
        mov     eax,deg
        push    eax
        call    asm_flx_cos
        add     esp,4
        mov     edi,eax

; Now rotate the vector.
        mov     ebx,vect

        ; First the J component: j' = j * c + k * s

        mov     eax,(ESCH_VECTOR PTR [ebx]).ev_j
        imul    edi
        shrd    eax,edx,16
        mov     ecx,eax

        mov     eax,(ESCH_VECTOR PTR [ebx]).ev_k
        imul    esi
        shrd    eax,edx,16
        add     ecx,eax
        mov     newJ,ecx

        ; Now the K component: k' = j * s + k * c

        mov     eax,(ESCH_VECTOR PTR [ebx]).ev_j
        neg     eax
        imul    esi
        shrd    eax,edx,16
        mov     ecx,eax

        mov     eax,(ESCH_VECTOR PTR [ebx]).ev_k
        imul    edi
        shrd    eax,edx,16
        add     ecx,eax

; Now store the results.
        mov     eax,(ESCH_VECTOR PTR [ebx]).ev_i
        mov     ebx,dest

        mov     (ESCH_VECTOR PTR [ebx]).ev_k,ecx
        mov     edx,newJ
        mov     (ESCH_VECTOR PTR [ebx]).ev_j,edx
        mov     (ESCH_VECTOR PTR [ebx]).ev_i,eax

        pop     ebx
        pop     edi
        pop     esi
        ret

END_PROC        esch_rotatex


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_rotatey                                                             ³
;                                                                          ³
; void (void *vect,Flx16 deg);                                             ³
;                                                                          ³
;       This function rotates the passed in vector/point about the Y-axis  ³
;       by the number of degrees specified in deg.                         ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

;
;  (i', j', k') = rotate-about-y (i, j, k)
;
;       i' = i * c + k * s
;       j' = j
;       k' = i * s + k * c
;

        ALIGN   16
START_PROC      esch_rotatey,   C       vect:DWORD, deg:DWORD, dest:DWORD

        LOCAL   newI:DWORD

        push    esi
        push    edi
        push    ebx

; Get the sin & cosine for the rotation.
; Stores sin into 'esi' and cos into 'edi'

        mov     eax,deg
        push    eax
        call    asm_flx_sin
        add     esp,4
        mov     esi,eax
        mov     eax,deg
        push    eax
        call    asm_flx_cos
        add     esp,4
        mov     edi,eax

; Now rotate the vector.
        mov     ebx,vect

        ; First the I component: i * c + k * s 

        mov     eax,(ESCH_VECTOR PTR [ebx]).ev_i
        imul    edi
        shrd    eax,edx,16
        mov     ecx,eax

        mov     eax,(ESCH_VECTOR PTR [ebx]).ev_k
        neg     eax
        imul    esi
        shrd    eax,edx,16
        add     ecx,eax
        mov     newI,ecx

        ; Now the K component: k' = i * s + k * c

        mov     eax,(ESCH_VECTOR PTR [ebx]).ev_i
        imul    esi
        shrd    eax,edx,16
        mov     ecx,eax

        mov     eax,(ESCH_VECTOR PTR [ebx]).ev_k
        imul    edi
        shrd    eax,edx,16
        add     ecx,eax

; Now store the results.
        mov     edx,(ESCH_VECTOR PTR [ebx]).ev_j
        mov     ebx,dest

        mov     (ESCH_VECTOR PTR [ebx]).ev_k,ecx
        mov     eax,newI
        mov     (ESCH_VECTOR PTR [ebx]).ev_j,edx
        mov     (ESCH_VECTOR PTR [ebx]).ev_i,eax

        pop     ebx
        pop     edi
        pop     esi
        ret

END_PROC        esch_rotatey


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_rotatez                                                             ³
;                                                                          ³
; void (void *vect,Flx16 deg);                                             ³
;                                                                          ³
;       This function rotates the passed in vector/point about the Z-axis  ³
;       by the number of degrees specified in deg.                         ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

;
;  (i', j', k') = rotate-about-x (i, j, k)
;
;       i' = i * c + j * s
;       j' = i * s + j * c
;       k' = k
;

        ALIGN   16
START_PROC      esch_rotatez,   C       vect:DWORD, deg:DWORD, dest:DWORD
        LOCAL   newI:DWORD

        push    esi
        push    edi
        push    ebx

; Get the sin & cosine for the rotation.
; Stores sin into 'esi' and cos into 'edi'
        mov     eax,deg
        push    eax
        call    asm_flx_sin
        add     esp,4
        mov     esi,eax
        mov     eax,deg
        push    eax
        call    asm_flx_cos
        add     esp,4
        mov     edi,eax

; Now rotate the vector.
        mov     ebx,vect

        ; First the I component: i' = i * c + j * s

        mov     eax,(ESCH_VECTOR PTR [ebx]).ev_i
        imul    edi
        shrd    eax,edx,16
        mov     ecx,eax

        mov     eax,(ESCH_VECTOR PTR [ebx]).ev_j
        imul    esi
        shrd    eax,edx,16
        add     ecx,eax
        mov     newI,ecx

        ; Now the J component: j' = i * s + j * c

        mov     eax,(ESCH_VECTOR PTR [ebx]).ev_i
        neg     eax
        imul    esi
        shrd    eax,edx,16
        mov     ecx,eax

        mov     eax,(ESCH_VECTOR PTR [ebx]).ev_j
        imul    edi
        shrd    eax,edx,16
        add     ecx,eax

; Now store the results.
        mov     eax,(ESCH_VECTOR PTR [ebx]).ev_k
        mov     ebx,dest

        mov     (ESCH_VECTOR PTR [ebx]).ev_k,eax
        mov     edx,newI
        mov     (ESCH_VECTOR PTR [ebx]).ev_j,ecx
        mov     (ESCH_VECTOR PTR [ebx]).ev_i,edx

        pop     ebx
        pop     edi
        pop     esi
        ret

END_PROC        esch_rotatez


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_transform                                                           ³
;                                                                          ³
; void (void *vect,EschMatrix *m);                                         ³
;                                                                          ³
;       This function transforms the vector/point, by the matrix m.        ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

;
;             [A B C 0]   [ Ai+Dj+Gk+J ]
; [i j k 1] * [D E F 0] = [ Bi+Ej+Hk+K ]
;             [G H I 0]   [ Ci+Fj+Ik+L ]
;             [J K L 1]   [      1     ]
;

        ALIGN   16
START_PROC      esch_transform, C       vect:DWORD, m:DWORD, dest:DWORD
        LOCAL   newI:DWORD
        LOCAL   newJ:DWORD
        LOCAL   newK:DWORD

        push    esi
        push    edi

        mov     edi,m
        mov     esi,vect

if 0    ; This method should present fewer memory contentions.
        ; but it is slower for some reason
        mov     ecx,VCT.ev_i        
        mov     eax,MTX.mtx_a
        imul    ecx
        shld    edx,eax,16
        mov     newI,edx
        mov     eax,MTX.mtx_b
        imul    ecx
        shld    edx,eax,16
        mov     newJ,edx
        mov     eax,MTX.mtx_c
        imul    ecx
        shld    edx,eax,16
        mov     newK,edx

        mov     ecx,VCT.ev_j
        mov     eax,MTX.mtx_d
        imul    ecx
        shld    edx,eax,16
        add     newI,edx
        mov     eax,MTX.mtx_e
        imul    ecx
        shld    edx,eax,16
        add     newJ,edx
        mov     eax,MTX.mtx_f
        imul    ecx
        shld    edx,eax,16
        add     newK,edx

        mov     ecx,VCT.ev_k
        mov     eax,MTX.mtx_g
        imul    ecx
        shld    edx,eax,16
        add     newI,edx
        mov     eax,MTX.mtx_h
        imul    ecx
        shld    edx,eax,16
        add     newJ,edx
        mov     eax,MTX.mtx_i
        imul    ecx
        shld    edx,eax,16
        add     newK,edx

        mov     esi,dest
        mov     eax,newI
        mov     ecx,newJ
        mov     edx,newK
        add     eax,MTX.mtx_j
        add     ecx,MTX.mtx_k
        add     edx,MTX.mtx_l
        mov     VCT.ev_i,eax
        mov     VCT.ev_j,ecx
        mov     VCT.ev_k,edx
else

; Calculate the new I component: Ai+Dj+Gk+J

        mov     eax,VCT.ev_i
        imul    MTX.mtx_a
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,VCT.ev_j
        imul    MTX.mtx_d
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,VCT.ev_k
        imul    MTX.mtx_g
        shrd    eax,edx,16
        add     ecx,eax
        add     ecx,MTX.mtx_j
        mov     newI,ecx

; Calculate the new J component: Bi+Ej+Hk+K

        mov     eax,VCT.ev_i
        imul    MTX.mtx_b
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,VCT.ev_j
        imul    MTX.mtx_e
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,VCT.ev_k
        imul    MTX.mtx_h
        shrd    eax,edx,16
        add     ecx,eax
        add     ecx,MTX.mtx_k
        mov     newJ,ecx

; Calculate the new K component: Ci+Fj+Ik+L

        mov     eax,VCT.ev_i
        imul    MTX.mtx_c
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,VCT.ev_j
        imul    MTX.mtx_f
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,VCT.ev_k
        imul    MTX.mtx_i
        shrd    eax,edx,16
        add     ecx,eax
        add     ecx,MTX.mtx_l

; Now store the results.
        mov     esi,dest
        mov     VCT.ev_k,ecx
        mov     ecx,newJ
        mov     VCT.ev_j,ecx
        mov     ecx,newI
        mov     VCT.ev_i,ecx
endif

        pop     edi
        pop     esi
        ret

END_PROC        esch_transform


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_transform_notran                                                    ³
;                                                                          ³
; void (void *vect,EschMatrix *m);                                         ³
;                                                                          ³
;       This function transforms the vector/point, by the matrix m,        ³
;       ignoring any translation components--actually assumes that the     ³
;       J K L components of the transform matrix.                          ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

;
;             [A B C 0]   [ Ai+Dj+Gk ]
; [i j k 1] * [D E F 0] = [ Bi+Ej+Hk ]
;             [G H I 0]   [ Ci+Fj+Ik ]
;             [0 0 0 1]   [     1    ]
;

        ALIGN   16
START_PROC      esch_transform_notran, C       vect:DWORD, m:DWORD, dest:DWORD
        LOCAL   newI:DWORD
        LOCAL   newJ:DWORD
        LOCAL   newK:DWORD


        push    esi
        push    edi

        mov     edi,m
        mov     esi,vect

if 0    ; This method should present fewer memory contentions.
        ; but it is slower for some reason
        mov     ecx,VCT.ev_i        
        mov     eax,MTX.mtx_a
        imul    ecx
        shld    edx,eax,16
        mov     newI,edx
        mov     eax,MTX.mtx_b
        imul    ecx
        shld    edx,eax,16
        mov     newJ,edx
        mov     eax,MTX.mtx_c
        imul    ecx
        shld    edx,eax,16
        mov     newK,edx

        mov     ecx,VCT.ev_j
        mov     eax,MTX.mtx_d
        imul    ecx
        shld    edx,eax,16
        add     newI,edx
        mov     eax,MTX.mtx_e
        imul    ecx
        shld    edx,eax,16
        add     newJ,edx
        mov     eax,MTX.mtx_f
        imul    ecx
        shld    edx,eax,16
        add     newK,edx

        mov     ecx,VCT.ev_k
        mov     eax,MTX.mtx_g
        imul    ecx
        shld    edx,eax,16
        add     newI,edx
        mov     eax,MTX.mtx_h
        imul    ecx
        shld    edx,eax,16
        add     newJ,edx
        mov     eax,MTX.mtx_i
        imul    ecx
        shld    edx,eax,16
        add     newK,edx

        mov     esi,dest
        mov     eax,newI
        mov     ecx,newJ
        mov     edx,newK
        mov     VCT.ev_i,eax
        mov     VCT.ev_j,ecx
        mov     VCT.ev_k,edx
else

; Calculate the new I component: Ai+Dj+Gk

        mov     eax,VCT.ev_i
        imul    MTX.mtx_a
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,VCT.ev_j
        imul    MTX.mtx_d
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,VCT.ev_k
        imul    MTX.mtx_g
        shrd    eax,edx,16
        add     ecx,eax
        mov     newI,ecx

; Calculate the new J component: Bi+Ej+Hk

        mov     eax,VCT.ev_i
        imul    MTX.mtx_b
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,VCT.ev_j
        imul    MTX.mtx_e
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,VCT.ev_k
        imul    MTX.mtx_h
        shrd    eax,edx,16
        add     ecx,eax
        mov     newJ,ecx

; Calculate the new K component: Ci+Fj+Ik

        mov     eax,VCT.ev_i
        imul    MTX.mtx_c
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,VCT.ev_j
        imul    MTX.mtx_f
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,VCT.ev_k
        imul    MTX.mtx_i
        shrd    eax,edx,16
        add     ecx,eax

; Now store the results.
        mov     esi,dest
        mov     VCT.ev_k,ecx
        mov     ecx,newJ
        mov     VCT.ev_j,ecx
        mov     ecx,newI
        mov     VCT.ev_i,ecx
endif

        pop     edi
        pop     esi
        ret

END_PROC        esch_transform_notran

_text   ends
        end

;°±² End of module - esmath.asm ²±°
