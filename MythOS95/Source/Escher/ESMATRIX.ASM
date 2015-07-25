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
; esmatrix.asm
;
;       Contains the functions that are called by the EschMatrix class
;       in the 'math' header.
;
;               esch_concatmatrix
;               esch_detmatrix
;               esch_inversematrix
;
;       Assumes all values are represented as signed 16.16 fixed-point.
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

M1      equ     (ESCH_MATRIX PTR [edi])
M2      equ     (ESCH_MATRIX PTR [ebx])
DM1     equ     (ESCH_MATRIX PTR [esi])

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_concatmatrix                                                        ³
;                                                                          ³
; void (EschMatrix *source,EschMatrix *new,EschMatrix *dest);              ³
;                                                                          ³
;       This function concatinates the matrix "new" to the "dest" matrix   ³
;       by performing a multiply of the two input matricies (treating the  ³
;       implied last column as 0 0 0 1).                                   ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

; [A B C 0]      [a b c 0]    [Aa+Bd+Cg   Ab+Be+Ch   Ac+Bf+Ci   0]
; [D E F 0]      [d e f 0]    [Da+Ed+Fg   Db+Ee+Fh   Dc+Ef+Fi   0]
; [G H I 0]  *   [g h i 0] =  [Ga+Hd+Ig   Gb+He+Ih   Gc+Hf+Ii   0]
; [J K L 1]      [j k l 1]    [Ja+Kd+Lg+j Jb+Ke+Lh+k Jc+Kf+Li+l 1]

        ALIGN   16
START_PROC      esch_concatmatrix,      C source:DWORD, new:DWORD, dest:DWORD
        push    esi
        push    edi
        push    ebx
        sub     esp,SIZEOF ESCH_MATRIX  
                                ; allocate work space on the stack.

        mov     esi,source
        mov     edi,esp
        mov     ebx,new
        mov     ecx,(SIZEOF ESCH_MATRIX) SHR 2
    rep movsd                   ; copy the source into the temp buffer.
        sub     edi,(SIZEOF ESCH_MATRIX)
        mov     esi,dest

; Calculate the new a: Aa+Bd+Cg

        mov     eax,M1.mtx_a
        imul    M2.mtx_a
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_b
        imul    M2.mtx_d
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,M1.mtx_c
        imul    M2.mtx_g
        shrd    eax,edx,16
        add     ecx,eax
        mov     DM1.mtx_a,ecx

; Calculate the new b: Ab+Be+Ch

        mov     eax,M1.mtx_a
        imul    M2.mtx_b
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_b
        imul    M2.mtx_e
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,M1.mtx_c
        imul    M2.mtx_h
        shrd    eax,edx,16
        add     ecx,eax
        mov     DM1.mtx_b,ecx

; Calculate the new c: Ac+Bf+Ci

        mov     eax,M1.mtx_a
        imul    M2.mtx_c
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_b
        imul    M2.mtx_f
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,M1.mtx_c
        imul    M2.mtx_i
        shrd    eax,edx,16
        add     ecx,eax
        mov     DM1.mtx_c,ecx

; Calculate the new d: Da+Ed+Fg

        mov     eax,M1.mtx_d
        imul    M2.mtx_a
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_e
        imul    M2.mtx_d
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,M1.mtx_f
        imul    M2.mtx_g
        shrd    eax,edx,16
        add     ecx,eax
        mov     DM1.mtx_d,ecx

; Calculate the new e: Db+Ee+Fh

        mov     eax,M1.mtx_d
        imul    M2.mtx_b
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_e
        imul    M2.mtx_e
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,M1.mtx_f
        imul    M2.mtx_h
        shrd    eax,edx,16
        add     ecx,eax
        mov     DM1.mtx_e,ecx

; Calculate the new f: Dc+Ef+Fi

        mov     eax,M1.mtx_d
        imul    M2.mtx_c
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_e
        imul    M2.mtx_f
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,M1.mtx_f
        imul    M2.mtx_i
        shrd    eax,edx,16
        add     ecx,eax
        mov     DM1.mtx_f,ecx

; Calculate the new g: Ga+Hd+Ig

        mov     eax,M1.mtx_g
        imul    M2.mtx_a
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_h
        imul    M2.mtx_d
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,M1.mtx_i
        imul    M2.mtx_g
        shrd    eax,edx,16
        add     ecx,eax
        mov     DM1.mtx_g,ecx

; Calculate the new h: Gb+He+Ih

        mov     eax,M1.mtx_g
        imul    M2.mtx_b
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_h
        imul    M2.mtx_e
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,M1.mtx_i
        imul    M2.mtx_h
        shrd    eax,edx,16
        add     ecx,eax
        mov     DM1.mtx_h,ecx

; Calculate the new i: Gc+Hf+Ii

        mov     eax,M1.mtx_g
        imul    M2.mtx_c
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_h
        imul    M2.mtx_f
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,M1.mtx_i
        imul    M2.mtx_i
        shrd    eax,edx,16
        add     ecx,eax
        mov     DM1.mtx_i,ecx

; Calculate the new j: Ja+Kd+Lg+j

        mov     eax,M1.mtx_j
        imul    M2.mtx_a
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_k
        imul    M2.mtx_d
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,M1.mtx_l
        imul    M2.mtx_g
        shrd    eax,edx,16
        add     ecx,eax
        add     ecx,M2.mtx_j
        mov     DM1.mtx_j,ecx

; Calculate the new k: Jb+Ke+Lh+k

        mov     eax,M1.mtx_j
        imul    M2.mtx_b
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_k
        imul    M2.mtx_e
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,M1.mtx_l
        imul    M2.mtx_h
        shrd    eax,edx,16
        add     ecx,eax
        add     ecx,M2.mtx_k
        mov     DM1.mtx_k,ecx

; Calculate the new l: Jc+Kf+Li+l

        mov     eax,M1.mtx_j
        imul    M2.mtx_c
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_k
        imul    M2.mtx_f
        shrd    eax,edx,16
        add     ecx,eax
        mov     eax,M1.mtx_l
        imul    M2.mtx_i
        shrd    eax,edx,16
        add     ecx,eax
        add     ecx,M2.mtx_l
        mov     DM1.mtx_l,ecx

; Exit
        add     esp,SIZEOF ESCH_MATRIX
                                ; Free the work space on the stack.
        pop     ebx
        pop     edi
        pop     esi
        ret
END_PROC        esch_concatmatrix


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; asm_esch_detmatrix                                                       ³
;                                                                          ³
; Flx16 (EschMatrix *m);                                                   ³
;                                                                          ³
;       This functions computes the determinant of the given matrix, which ³
;       is a single scalar value (treats the implied last column as 0 0 0  ³
;       1).                                                                ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

;    [A B C 0]      
;det [D E F 0] =  A |E F 0|  - B |D F 0|  + C |D E 0|   - 0 |D E F|
;    [G H I 0]      |H I 0|      |G I 0|      |G H 0|       |G H I|
;    [J K L 1]      |K L 1|      |J L 1|      |J K 1|       |H K L|
;
;
;              =  A(                ) 
;                  ( E|I 0| - F|H 0|)
;                  (  |L 1|    |K 1|)
;
;                -B(                )
;                  ( D|I 0| - F|G 0|)
;                  (  |L 1|    |J 1|)
;
;                +C(                )
;                  ( D|H 0| - E|G 0|)
;                  (  |K 1|    |J 1|)
;
;              =  A(EI - FH) - B(DI - FG) + C(DH - EG)
;

        ALIGN   16
START_PROC      asm_esch_detmatrix,     C matrix:DWORD
        push    edi
        push    ebx

        mov     edi,matrix

; A |E F 0|
;   |H I 0| = A (EI - FH)
;   |K L 1|

        mov     eax,M1.mtx_e
        imul    M1.mtx_i
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_f
        imul    M1.mtx_h
        shrd    eax,edx,16
        sub     ecx,eax
        mov     eax,M1.mtx_a
        imul    ecx
        shrd    eax,edx,16
        mov     ebx,eax                     ; Accumulate term into EBX

; - B |D F 0| 
;     |G I 0| = - B (DI - FG) 
;     |J L 1|

        mov     eax,M1.mtx_d
        imul    M1.mtx_i
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_f
        imul    M1.mtx_g
        shrd    eax,edx,16
        sub     ecx,eax
        mov     eax,M1.mtx_b
        imul    ecx
        shrd    eax,edx,16
        sub     ebx,eax                     ; Accumulate term into EBX

; C |D E 0|
;   |G H 0| = C (DH - EG)
;   |J K 1|

        mov     eax,M1.mtx_d
        imul    M1.mtx_h
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_e
        imul    M1.mtx_g
        shrd    eax,edx,16
        sub     ecx,eax
        mov     eax,M1.mtx_c
        imul    ecx
        shrd    eax,edx,16
        add     eax,ebx                     ; Use accumulation in EBX

; Exit
        pop     ebx
        pop     edi
        ret
END_PROC        asm_esch_detmatrix


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_inversematrix                                                       ³
;                                                                          ³
; int  (EschMatrix *m,EschMatrix *d);                                      ³
;                                                                          ³
;       This function inverses the matrix "m" to the "d" matrix            ³
;       (treating the implied last column as 0 0 0 1).                     ³
;                                                                          ³
; 38 muls, 12 divs, 21 adds                                                ³
;                                                                          ³
; Returns 0 if ok, non-zero if inverse does not exist (det is 0).          ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

; [A B C 0]      det is A(EI - FH) - B(DI - FG) + C(DH - EG)
; [D E F 0]      
; [G H I 0]
; [J K L 1]      The inverse is :-
;
;
;                [ |E F 0|   |B C 0|   |B C 0|   |B C 0| ]
;                [ |H I 0|  -|H I 0|   |E F 0|  -|E F 0| ]
;                [ |K L 1|   |K L 1|   |K L 1|   |H I 0| ]
;                [                                       ]
;                [ |D F 0|   |A C 0|   |A C 0|   |A C 0| ]
;          1     [-|G I 0|   |G I 0|  -|D F 0|   |D F 0| ]
;        ----- * [ |J L 1|   |J L 1|   |J L 1|   |G I 0| ]
;         det    [                                       ]
;                [ |D E 0|   |A B 0|   |A B 0|   |A B 0| ]
;                [ |G H 0|  -|G H 0|   |D E 0|  -|D E 0| ]
;                [ |J K 1|   |J K 1|   |J K 1|   |G H 0| ]
;                [                                       ]
;                [ |D E F|   |A B C|   |A B C|   |A B C| ]
;                [-|G H I|   |G H I|  -|D E F|   |D E F| ]
;                [ |J K L|   |J K L|   |J K L|   |G H I| ]
;
;    |E F 0|
;    |H I 0| =  E|I 0| - F|H 0| + 0|H I| = EI - FH
;    |K L 1|     |L 1|    |K 1|    |K L|
;           
;    |D F 0|
;   -|G I 0| = -D|I 0| + F|G 0| - 0|G I| = -DI + FG
;    |J L 1|     |L 1|    |J 1|    |J L|
;           
;    |D E 0|
;    |G H 0| =  D|H 0| - E|G 0| + 0|G H| = DH - EG
;    |J K 1|     |K 1|    |J 1|    |J K|
;           
;    |D E F|
;   -|G H I| = -D|H I| + E|G I| - F|G H| = -D(HL-KI) + E(GL-IJ) - F(GK-JH)
;    |J K L|     |K L|    |J L|    |J K|
;
;    |B C 0|
;   -|H I 0| = -B|I 0| + C|H 0| - 0|H I| = -BI + CH
;    |K L 1|     |L 1|    |K 1|    |K L|
;           
;    |A C 0|
;    |G I 0| =  A|I 0| - C|G 0| + 0|G I| = AI - CG
;    |J L 1|     |L 1|    |J 1|    |J L|
;           
;    |A B 0|
;   -|G H 0| = -A|H 0| + B|G 0| - 0|G H| = -AH + BG
;    |J K 1|     |K 1|    |J 1|    |J K|
;           
;    |A B C|
;    |G H I| =  A|H I| - B|G I| + C|G H| = A(HL-KI) - B(GL-JI) + C(GK-JH)
;    |J K L|     |K L|    |J L|    |J K|
;
;    |B C 0|
;    |E F 0| =  B|F 0| - C|E 0| + 0|E F| = BF - CE
;    |K L 1|     |L 1|    |K 1|    |K L|
;           
;    |A C 0|
;   -|D F 0| = -A|F 0| + C|D 0| - 0|D F| = -AF + CD
;    |J L 1|     |L 1|    |J 1|    |J L|
;           
;    |A B 0|
;    |D E 0| =  A|E 0| - B|D 0| + 0|D E| = AE - BD
;    |J K 1|     |K 1|    |J 1|    |J K|
;           
;    |A B C|
;   -|D E F| = -A|E F| + B|D F| - C|D E| = -A(EL-KF) + B(DL-JF) - C(DK-JE)
;    |J K L|     |K L|    |J L|    |J K|
;
;    |B C 0|
;   -|E F 0| = 0
;    |H I 0|
;           
;    |A C 0|
;    |D F 0| = 0
;    |G I 0|
;           
;    |A B 0|
;   -|D E 0| = 0
;    |G H 0|
;           
;    |A B C|
;    |D E F| = det
;    |G H I|
;
         
        ALIGN   16
START_PROC      esch_inversematrix,      C source:DWORD, dest:DWORD

        LOCAL   det:DWORD                   ; Determinant

        LOCAL   iv1:DWORD                   ; Shared intermediate values
        LOCAL   iv2:DWORD
        LOCAL   iv3:DWORD

        push    esi
        push    edi
        push    ebx
        sub     esp,SIZEOF ESCH_MATRIX  
                                ; allocate work space on the stack.

        mov     esi,source
        mov     edi,esp
        mov     ecx,(SIZEOF ESCH_MATRIX) SHR 2
    rep movsd                   ; copy the source into the temp buffer.
        sub     edi,(SIZEOF ESCH_MATRIX)
        mov     esi,dest

; Compute inverse of determinant of matrix.
        push    source
        call    asm_esch_detmatrix
        add     esp,4

        or      eax,eax
        jz      error                       ; No inverse exists if det is 0.

        mov     det,eax

;<need to do the work here with M1 and DM1>

; <A>
;     1      |E F 0|
;   ----- *  |H I 0| = ( EI - FH ) / det
;    det     |K L 1|    

        mov     eax,M1.mtx_e
        imul    M1.mtx_i
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_f
        imul    M1.mtx_h
        shrd    eax,edx,16
        neg     eax
        add     eax,ecx
        shld    edx,eax,16
        shl     eax,16
        movsx   edx,dx
        idiv    det
        mov     DM1.mtx_a,eax

; <D>
;     1      |D F 0|
;   ----- * -|G I 0| = ( FG - DI ) / det
;    det     |J L 1| 

        mov     eax,M1.mtx_f
        imul    M1.mtx_g
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_d
        imul    M1.mtx_i
        shrd    eax,edx,16
        neg     eax
        add     eax,ecx
        shld    edx,eax,16
        shl     eax,16
        movsx   edx,dx
        idiv    det
        mov     DM1.mtx_d,eax

; <G>
;     1      |D E 0|
;   ----- *  |G H 0| = ( DH - EG ) / det
;    det     |J K 1|    

        mov     eax,M1.mtx_d
        imul    M1.mtx_h
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_e
        imul    M1.mtx_g
        shrd    eax,edx,16
        neg     eax
        add     eax,ecx
        shld    edx,eax,16
        shl     eax,16
        movsx   edx,dx
        idiv    det
        mov     DM1.mtx_g,eax
; <J>
;     1      |D E F|       <IV1>      <IV2>      <IV3>
;   ----- * -|G H I| = ( E(GL-IJ) - D(HL-KI) - F(GK-JH) ) / det
;    det     |J K L| 

        mov     eax,M1.mtx_g
        imul    M1.mtx_l
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_i
        imul    M1.mtx_j
        shrd    eax,edx,16
        sub     ecx,eax
        mov     iv1,ecx                     ; (GL-IJ) - store for reuse!
        mov     eax,M1.mtx_e
        imul    ecx
        shrd    eax,edx,16
        mov     ebx,eax                     ; Accumulate term into EBX
                
        mov     eax,M1.mtx_h
        imul    M1.mtx_l
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_k
        imul    M1.mtx_i
        shrd    eax,edx,16
        sub     ecx,eax
        mov     iv2,ecx                     ; (HL-KI) - store for reuse!
        mov     eax,M1.mtx_d
        imul    ecx
        shrd    eax,edx,16
        sub     ebx,eax                     ; Accumulate term into EBX
                
        mov     eax,M1.mtx_g
        imul    M1.mtx_k
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_j
        imul    M1.mtx_h
        shrd    eax,edx,16
        sub     ecx,eax
        mov     iv3,ecx                     ; (GK-JH) - store for reuse!
        mov     eax,M1.mtx_f
        imul    ecx
        shrd    eax,edx,16
        neg     eax
        add     eax,ebx                     ; Use accumulation in EBX

        shld    edx,eax,16
        shl     eax,16
        movsx   edx,dx
        idiv    det
        mov     DM1.mtx_j,eax

; <B>
;     1      |B C 0|
;   ----- * -|H I 0| = ( CH - BI ) / det
;    det     |K L 1|   

        mov     eax,M1.mtx_c
        imul    M1.mtx_h
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_b
        imul    M1.mtx_i
        shrd    eax,edx,16
        neg     eax
        add     eax,ecx
        shld    edx,eax,16
        shl     eax,16
        movsx   edx,dx
        idiv    det
        mov     DM1.mtx_b,eax

; <E>
;     1      |A C 0|
;   ----- *  |G I 0| = ( AI - CG ) / det
;    det     |J L 1|   

        mov     eax,M1.mtx_a
        imul    M1.mtx_i
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_c
        imul    M1.mtx_g
        shrd    eax,edx,16
        neg     eax
        add     eax,ecx
        shld    edx,eax,16
        shl     eax,16
        movsx   edx,dx
        idiv    det
        mov     DM1.mtx_e,eax

; <H>          
;     1      |A B 0|
;   ----- * -|G H 0| = ( BG - AH ) / det
;    det     |J K 1|   

        mov     eax,M1.mtx_b
        imul    M1.mtx_g
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_a
        imul    M1.mtx_h
        shrd    eax,edx,16
        neg     eax
        add     eax,ecx
        shld    edx,eax,16
        shl     eax,16
        movsx   edx,dx
        idiv    det
        mov     DM1.mtx_h,eax

; <K>          
;     1      |A B C|       <IV2>      <IV1>      <IV3>
;   ----- *  |G H I| = ( A(HL-KI) - B(GL-JI) + C(GK-JH) ) / det
;    det     |J K L|   

        mov     eax,M1.mtx_a
        imul    iv2                         ; (HL-KI) - reuse
        shrd    eax,edx,16
        mov     ebx,eax                     ; Accumulate term into EBX
                
        mov     eax,M1.mtx_b
        imul    iv1                         ; (GL-IJ) - reuse
        shrd    eax,edx,16
        sub     ebx,eax                     ; Accumulate term into EBX
                
        mov     eax,M1.mtx_c
        imul    iv3                         ; (GK-JH) - store for reuse!
        shrd    eax,edx,16
        add     eax,ebx                     ; Use accumulation in EBX

        shld    edx,eax,16
        shl     eax,16
        movsx   edx,dx
        idiv    det
        mov     DM1.mtx_k,eax

; <C>
;     1      |B C 0|
;   ----- *  |E F 0| = ( BF - CE ) / det
;    det     |K L 1|   

        mov     eax,M1.mtx_b
        imul    M1.mtx_f
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_c
        imul    M1.mtx_e
        shrd    eax,edx,16
        neg     eax
        add     eax,ecx
        shld    edx,eax,16
        shl     eax,16
        movsx   edx,dx
        idiv    det
        mov     DM1.mtx_c,eax

; <F>
;     1      |A C 0|
;   ----- * -|D F 0| = ( CD - AF ) / det
;    det     |J L 1|   

        mov     eax,M1.mtx_c
        imul    M1.mtx_d
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_a
        imul    M1.mtx_f
        shrd    eax,edx,16
        neg     eax
        add     eax,ecx
        shld    edx,eax,16
        shl     eax,16
        movsx   edx,dx
        idiv    det
        mov     DM1.mtx_f,eax

; <I>
;     1      |A B 0|
;   ----- *  |D E 0| = ( AE - BD ) / det
;    det     |J K 1|   

        mov     eax,M1.mtx_a
        imul    M1.mtx_e
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_b
        imul    M1.mtx_d
        shrd    eax,edx,16
        neg     eax
        add     eax,ecx
        shld    edx,eax,16
        shl     eax,16
        movsx   edx,dx
        idiv    det
        mov     DM1.mtx_i,eax

; <L>
;     1      |A B C|
;   ----- * -|D E F| = ( B(DL-JF) - A(EL-KF) - C(DK-JE) ) / det
;    det     |J K L| 


        mov     eax,M1.mtx_d
        imul    M1.mtx_l
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_j
        imul    M1.mtx_f
        shrd    eax,edx,16
        sub     ecx,eax
        mov     eax,M1.mtx_b
        imul    ecx
        shrd    eax,edx,16
        mov     ebx,eax                     ; Accumulate term into EBX
                
        mov     eax,M1.mtx_e
        imul    M1.mtx_l
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_k
        imul    M1.mtx_f
        shrd    eax,edx,16
        sub     ecx,eax
        mov     eax,M1.mtx_a
        imul    ecx
        shrd    eax,edx,16
        sub     ebx,eax                     ; Accumulate term into EBX
                
        mov     eax,M1.mtx_d
        imul    M1.mtx_k
        shrd    eax,edx,16
        mov     ecx,eax
        mov     eax,M1.mtx_j
        imul    M1.mtx_e
        shrd    eax,edx,16
        sub     ecx,eax
        mov     eax,M1.mtx_c
        imul    ecx
        shrd    eax,edx,16
        neg     eax
        add     eax,ebx                     ; Use accumulation in EBX

        shld    edx,eax,16
        shl     eax,16
        movsx   edx,dx
        idiv    det
        mov     DM1.mtx_l,eax

; Exit
        xor     eax,eax

exit:

        add     esp,SIZEOF ESCH_MATRIX
                                ; Free the work space on the stack.
        pop     ebx
        pop     edi
        pop     esi
        ret

; Error, no inverse exists

error:
        mov     eax,1
        jmp     short exit

END_PROC        esch_inversematrix

_text   ends
        end

;°±² End of module - esmatrix.asm ²±°
