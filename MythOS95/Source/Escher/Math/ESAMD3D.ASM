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
;ùùùùùùùùùùùùùùùùù Microsoft Windows 95/98/NT Version ùùùùùùùùùùùùùùùùùùùùùù
;ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
;ùùùCopyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbournùùù
;ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
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
; Created by Chuck Walbourn
;
; esamd3d.asm
;
; Contains the arithemetic operations customized for the AMD-3D
; extensions.  These routines perform a FEMMS to exit the MMX
; state on return to be FPU safe after exit except the _nofpu_
; versions which require fpureset be called before a FPU command is
; executed.
;
;       esch_amd3d_transform
;       esch_amd3d_transform_notran
;       esch_amd3d_cross
;       esch_amd3d_normalize
;       esch_amd3d_concatmatrix
;       esch_amd3d_fpureset
;       esch_amd3d_nofpu_transform
;       esch_amd3d_nofpu_transform_notran
;       esch_amd3d_nofpu_normalize
;
; WARNING:  All these routines assume that mythos_detect_amd3d() or a
;           similiar mechanism was used to verify that the run-time
;           processor supports the AMD-3D instruction set.  Processor
;           exceptions could otherwise occurr.
;
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
;
;    Code assembled with Microsoft (R) Macro Assembler Version 6.13 Beta
;
;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

.586p
.K3D

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

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_amd3d_transform                                                     ³
;                                                                          ³
; void (void *vect,EschMatrix *m);                                         ³
;                                                                          ³
; This function transforms the vector/point, by the matrix m.              ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

;
;             [A B C 0]   [ Ai+Dj+Gk+J ]
; [i j k 1] * [D E F 0] = [ Bi+Ej+Hk+K ]
;             [G H I 0]   [ Ci+Fj+Ik+L ]
;             [J K L 1]   [      1     ]
;

        ALIGN   16
START_PROC      esch_amd3d_transform, C vect:DWORD, m:DWORD, dest:DWORD
        mov             ecx,    vect
        movq            mm0,    [ecx]           ; j, i in mm0
        movd            mm1,    [ecx+8]         ; 0, k in mm1

        punpckhdq       mm2,    mm0             ; j, undef in mm2

        mov             edx,    m
        movq            mm3,    [edx]           ; B, A in mm3
        movq            mm6,    mm0             ; j, i in mm6

        movq            mm4,    [edx+8]         ; D, C in mm4
        punpckldq       mm0,    mm0             ; i, i in mm0

        movq            mm5,    [edx+16]        ; F, E in mm5
        pfmul           mm3,    mm0             ; Bi, Ai in mm3

        punpckhdq       mm2,    mm2             ; j, j in mm2
        pfmul           mm4,    mm6             ; Dj, Ci in mm4

        movq            mm7,    [edx+24]        ; H, G in mm7
        punpckldq       mm1,    mm1             ; k, k in mm1
        pfmul           mm5,    mm2             ; Fj, Ej in mm5

        movq            mm0,    [edx+32]        ; J, I in mm0
        pfmul           mm7,    mm1             ; Hk, Gk in mm7

        movq            mm2,    [edx+40]        ; L, K in mm2
        pfmul           mm1,    mm0             ; (X), Ik in mm1

        punpckhdq       mm0,    mm4             ; Dj, J in mm0
        pfadd           mm3,    mm7             ; Bi+Hk, Ai+Gk in mm3

        punpckldq       mm1,    mm4             ; Ci, Ik in mm1
        pfadd           mm2,    mm5             ; Fj+L, Ej+K in mm2

        pfacc           mm0,    mm1             ; Ci+Ik, Dj+J in mm0
        movq            mm4,    mm0

        punpckldq       mm0,    mm2             ; Ej+K, Dj+J in mm0
        punpckhdq       mm4,    mm2             ; Fj+L, Ci+Ik

        pfadd           mm0,    mm3             ; Bi+Ej+Hk+K, Ai+Dj+Gk+J
        pfacc           mm4,    mm5             ; (X), Ci+Fj+Ik+L

        mov             eax,    dest            ; store result
        movq            [eax],  mm0
        movd            [eax+8],mm4

        femms                                   ; exit MMX state
        ret
END_PROC        esch_amd3d_transform


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_amd3d_transform_notran                                              ³
;                                                                          ³
; void (void *vect,EschMatrix *m);                                         ³
;                                                                          ³
; This function transforms the vector/point, by the matrix m ignoring      ³
; translations.                                                            ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

;
;             [A B C 0]   [ Ai+Dj+Gk ]
; [i j k 1] * [D E F 0] = [ Bi+Ej+Hk ]
;             [G H I 0]   [ Ci+Fj+Ik ]
;             [J K L 1]   [    1     ]
;

        ALIGN   16
START_PROC      esch_amd3d_transform_notran, C vect:DWORD, m:DWORD, dest:DWORD
        mov             ecx,    vect
        movq            mm0,    [ecx]           ; j, i in mm0
        movd            mm1,    [ecx+8]         ; 0, k in mm1

        punpckhdq       mm2,    mm0             ; j, undef in mm2

        mov             edx,    m
        movq            mm3,    [edx]           ; B, A in mm3
        movq            mm6,    mm0             ; j, i in mm6

        movq            mm4,    [edx+8]         ; D, C in mm4
        punpckldq       mm0,    mm0             ; i, i in mm0

        movq            mm5,    [edx+16]        ; F, E in mm5
        pfmul           mm3,    mm0             ; Bi, Ai in mm3

        punpckhdq       mm2,    mm2             ; j, j in mm2
        pfmul           mm4,    mm6             ; Dj, Ci in mm4

        movq            mm7,    [edx+24]        ; H, G in mm7
        punpckldq       mm1,    mm1             ; k, k in mm1
        pfmul           mm5,    mm2             ; Fj, Ej in mm5

        movd            mm0,    [edx+32]        ; 0, I in mm0
        pfmul           mm7,    mm1             ; Hk, Gk in mm7

        movq            mm6,    mm4             ; Dj, Ci in mm6
        pfmul           mm0,    mm1             ; 0, Ik in mm0

        movq            mm1,    mm5             ; Fj, Ej in mm1
        pfadd           mm3,    mm7             ; Bi+Hk, Ai+Gk in mm3

        punpckhdq       mm5,    mm5             ; Fj, Fj in mm5
        pfadd           mm0,    mm6             ; (X), Ci+Ik in mm0

        punpckldq       mm1,    mm1             ; Ej, Ej in mm1
        pfadd           mm0,    mm5             ; (X), Ci+Fj+Ik in mm0

        punpckhdq       mm4,    mm1             ; Ej, Dj in mm4
        pfadd           mm3,    mm4             ; Bi+Ej+Hk, Ai+Dj+Gk in mm3

        mov             eax,    dest            ; store result
        movq            [eax],  mm3
        movd            [eax+8],mm0

        femms                                   ; exit MMX state
        ret
END_PROC        esch_amd3d_transform_notran


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_amd3d_cross                                                         ³
;                                                                          ³
; EVector * (EschVector *v1,EschVector *v2,EschVector *dest);              ³
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
START_PROC      esch_amd3d_cross, C v1:DWORD, v2:DWORD, dest:DWORD

        mov             ecx,    v1
        mov             edx,    v2

        movd            mm0,    [edx+8]         ; 0, v2.k in mm0
        movd            mm1,    [ecx+8]         ; 0, v1.k in mm1

        punpckldq       mm0,    mm0             ; v2.k, v2.k in mm0

        punpckldq       mm1,    mm1             ; v1.k, v1.k in mm1
        pfmul           mm0,    [ecx]           ; v1.j*v2.k, v1.i*v2.k in mm0

        movd            mm3,    [ecx+4]         ; 0, v1.j in mm3
        pfmul           mm1,    [edx]           ; v1.k*v2.j, v1.k*v2.i in mm1

        movd            mm4,    [edx+4]         ; 0, v2.j in mm4
        movq            mm2,    mm0             ; v1.j*v2.k, v1.i*v2.k in mm2

        pfmul           mm3,    [edx]           ; 0, v1.j*v2.i in mm3
        pfsub           mm0,    mm1             ; v1.j*v2.k - v1.k*v2.j, (X) in mm0

        pfmul           mm4,    [ecx]           ; 0, v1.i*v2.j in mm4
        pfsub           mm1,    mm2             ; (X), v1.k*v2.i - v1.i*v2.k in mm1

        psrlq           mm0,    32              ; 0, v1.j*v2.k - v1.k*v2.j in mm0
        pfsub           mm4,    mm3             ; 0, v1.i*v2.j - v1.j*v2.i in mm4

        mov             eax,    dest            ; store result
        movd            [eax],  mm0
        movd            [eax+4],mm1
        movd            [eax+8],mm4

        femms                                   ; exit MMX state
        ret
END_PROC        esch_amd3d_cross


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_amd3d_normalize                                                     ³
;                                                                          ³
; EVector * (EschVector *v1,EschVector *v2,EschVector *dest);              ³
;                                                                          ³
; Normalizes the vector (if the magnitude is too small, leaves the vector  ³
; unchanged).                                                              ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

        ALIGN   16
START_PROC      esch_amd3d_normalize, C vect:DWORD

        mov             ecx,    vect
        movq            mm0,    [ecx]           ; j, i in mm0
        movd            mm1,    [ecx+8]         ; 0, k in mm1

        movq            mm4,    mm0             ; j, i in mm4
        movq            mm3,    mm1             ; 0, k in mm3

        pfmul           mm0,    mm0             ; j*j, i*i in mm0
        pfmul           mm1,    mm1             ; 0, k*k in mm1

        pfacc           mm0,    mm0             ; (X), i*i+j*j in mm0
        pfadd           mm0,    mm1             ; (X), i*i+j*j+k*k in mm0

        movd            eax,    mm0             ; length into eax
        pfrsqrt         mm1,    mm0             ; approx. 1/mag in mm1
        movq            mm2,    mm1

        cmp             eax,    038D1B717h      ; 0.0001
        jl              exit                    ; if length < 0.0001

        pfmul           mm1,    mm1             ; refine rsqrt
        pfrsqit1        mm1,    mm0
        pfrcpit2        mm1,    mm2             ; (X), 1/mag in mm1

        punpckldq       mm1,    mm1             ; 1/mag, 1/mag in mm1

        pfmul           mm3,    mm1             ; 0, k/mag in mm3
        pfmul           mm4,    mm1             ; j/mag, i/mag in mm2

        movd            [ecx+8],mm3             ; store result
        movq            [ecx],  mm4

exit:
        femms                                   ; exit MMX state
        ret
END_PROC        esch_amd3d_normalize


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_amd3d_concatmatrix                                                  ³
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
START_PROC      esch_amd3d_concatmatrix, C source:DWORD, new:DWORD, dest:DWORD
        push            esi
        push            edi
                                                ; allocate work space
        sub             esp,    SIZEOF ESCH_MATRIX  

;ÄÄÄ Copy original to stack
        mov             esi,    source
        mov             edi,    esp
        mov             ecx,    (SIZEOF ESCH_MATRIX) SHR 2
    rep movsd                                   ; copy the source into
                                                ; the temp buffer.

        sub             edi,    (SIZEOF ESCH_MATRIX)

        mov             edx,    new
        mov             eax,    dest

;ÄÄÄ Calculate the A' = Aa+Bd+Cg, B' = Ab+Be+Ch, C' = Ac+Bf+Ci

        movd            mm7,    [edx+8]         ; 0, c in mm7
        movd            mm6,    [edx+32]        ; 0, i in mm6

        punpckldq       mm7,    [edx+20]        ; f, c in mm7

        movq            mm0,    [edi]           ; B, A in mm0
        movd            mm3,    [edi+8]         ; 0, C in mm3

        movq            mm1,    mm0             ; B, A in mm1
        pfmul           mm0,    mm7             ; Bf, Ac in mm0

        movq            mm2,    mm1             ; B, A in mm2
        punpckldq       mm1,    mm1             ; A, A in mm1

        pfmul           mm1,    [edx]           ; Ab, Aa in mm1
        punpckhdq       mm2,    mm2             ; B, B in mm2

        pfmul           mm2,    [edx+12]        ; Be, Bd in mm2
        pfacc           mm0,    mm0             ; (X), ADb+Ee, Da+Ed in mm2c+Bf in mm0

        movq            mm4,    mm3             ; 0, C in mm4
        punpckldq       mm3,    mm3             ; C, C in mm3

        pfmul           mm3,    [edx+24]        ; Ch, Cg in mm3
        pfadd           mm2,    mm1             ; Ab+Be, Aa+Bd in mm2

        pfmul           mm4,    mm6             ; 0, Ci in mm4
        movq            mm5,    [edi+12]        ; E, D in mm5

        pfadd           mm2,    mm3             ; Ab+Be+Ch, Aa+Bd+Cg in mm2
        movd            mm3,    [edi+20]        ; 0, F in mm3

        pfadd           mm4,    mm0             ; (X), Ac+Bf+Ci
        movq            mm1,    mm5             ; E, D in mm1

        movq            [eax],  mm2             ; store B', A'
        pfmul           mm5,    mm7             ; Ef, Dc in mm5

        movd            [eax+8],mm4             ; store C'
        movq            mm2,    mm1             ; E, D in mm2

;ÄÄÄ Calculate the D' = Da+Ed+Fg, E' = Db+Ee+Fh, F' = Dc+Ef+Fi

        punpckldq       mm1,    mm1             ; D, D in mm1
        movq            mm0,    [edi+24]        ; H, G in mm0

        pfmul           mm1,    [edx]           ; Db, Da in mm1
        punpckhdq       mm2,    mm2             ; E, E in mm2

        pfmul           mm2,    [edx+12]        ; Ee, Ed in mm2
        pfacc           mm5,    mm5             ; (X), Dc+Ef

        movq            mm4,    mm3             ; 0, F in mm4
        punpckldq       mm3,    mm3             ; F, F in mm4

        pfmul           mm3,    [edx+24]        ; Fh, Fg in mm3
        pfadd           mm2,    mm1             ; Db+Ee, Da+Ed in mm2

        pfmul           mm4,    mm6             ; (X), Fi in mm4

        pfadd           mm2,    mm3             ; Db+Ee+Fh, Da+Ed+Fg in mm2
        movd            mm3,    [edi+32]        ; 0, I in mm3

        pfadd           mm4,    mm5             ; (X), Dc+Ef+Fi in mm4
        movq            mm1,    mm0             ; H, G in mm1

        movq            [eax+12],mm2            ; store E', 'D
        pfmul           mm0,    mm7             ; Hf, Gc in mm0

        movd            [eax+20],mm4            ; store F'
        movq            mm2,    mm1             ; H, G in mm2

;ÄÄÄ Calculate the G' = Ga+Hd+Ig, H' = Gb+He+Ih, I' = Gc+Hf+Ii

        punpckldq       mm1,    mm1             ; G, G in mm1
        movq            mm5,    [edi+36]        ; K, J in mm5

        pfmul           mm1,    [edx]           ; Gb, Ga in mm1
        punpckhdq       mm2,    mm2             ; H, H in mm2

        pfmul           mm2,    [edx+12]        ; He, Hd in mm2
        pfacc           mm0,    mm0             ; (X), Hf+Gc in mm0

        movq            mm4,    mm3             ; 0, I in mm4
        punpckldq       mm3,    mm3             ; I, I in mm3

        pfmul           mm3,    [edx+24]        ; Ih, Ig in mm3
        pfadd           mm2,    mm1             ; Gb+He, Ga+Hd in mm2

        pfmul           mm4,    mm6             ; (X), Ii in mm4
        movq            mm1,    mm5             ; K, J in mm1

        pfadd           mm4,    mm0             ; (X), Hf+Gc+Ii in mm4
        movd            mm0,    [edi+44]        ; 0, L in mm0

        pfadd           mm2,    mm3             ; Gb+He+Ih, Ga+Hd+Ig in mm2
        pfmul           mm5,    mm7             ; Kf, Jc in mm5

        movd            [eax+32],mm4            ; store I'
        movq            mm4,    mm1             ; K, J in mm4

        movq            [eax+24],mm2            ; store H', G'
        punpckldq       mm1,    mm1             ; J, J in mm1

;ÄÄÄ Calculate the J' = Ja+Kd+Lg+j, K' = Jb+Ke+Lh+k, L' = Jc+Kf+Li+l

        pfmul           mm1,    [edx]           ; Jb, Ja in mm1
        punpckhdq       mm4,    mm4             ; K, K in mm4

        pfmul           mm4,    [edx+12]        ; Ke, Kd in mm4
        pfacc           mm5,    mm5             ; (X), Jc+Kf in mm5

        pfmul           mm6,    mm0             ; (X), Li in mm6
        punpckldq       mm0,    mm0             ; L, L in mm0

        pfmul           mm0,    [edx+24]        ; Lh, Lg in mm0
        pfadd           mm1,    mm4             ; Jb+Ke, Ja+Kd in mm1

        pfadd           mm6,    mm5             ; (X), Jc+Kf+Li in mm6

        pfadd           mm1,    mm0             ; Jb+Ke+Lh, Ja+Kd+Lg in mm1
        pfadd           mm6,    [edx+44]        ; (X), Jc+Kf+Li+l in mm6

        pfadd           mm1,    [edx+36]        ; Jb+Ke+Lh+k, Ja+Kd+Lg+j in mm1

        movd            [eax+44],mm6            ; store L'

        movq            [eax+36],mm1            ; store K', J'

;ÄÄÄ Exit
        femms                                   ; exit MMX state
                                                ; Free the work space
        add             esp,    SIZEOF ESCH_MATRIX

        pop             edi
        pop             esi
        ret
END_PROC        esch_amd3d_concatmatrix


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_adm3d_fpureset                                                      ³
;                                                                          ³
; void (void);                                                             ³
;                                                                          ³
; Performs a FEMMS command to reset the FPU.  For use in batch processing  ³
; along with nofpu routines.                                               ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

        ALIGN   16
START_PROC      esch_amd3d_fpureset, C
        femms                                   ; exit MMX state
        ret
END_PROC        esch_amd3d_fpureset


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_amd3d_nofpu_transform                                               ³
;                                                                          ³
; void (void *vect,EschMatrix *m);                                         ³
;                                                                          ³
; This function transforms the vector/point, by the matrix m but leaves the³
; processor in the MMX state which is not FPU safe.                        ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

;
;             [A B C 0]   [ Ai+Dj+Gk+J ]
; [i j k 1] * [D E F 0] = [ Bi+Ej+Hk+K ]
;             [G H I 0]   [ Ci+Fj+Ik+L ]
;             [J K L 1]   [      1     ]
;

        ALIGN   16
START_PROC      esch_amd3d_nofpu_transform, C vect:DWORD, m:DWORD, dest:DWORD
        mov             ecx,    vect
        movq            mm0,    [ecx]           ; j, i in mm0
        movd            mm1,    [ecx+8]         ; 0, k in mm1

        punpckhdq       mm2,    mm0             ; j, undef in mm2

        mov             edx,    m
        movq            mm3,    [edx]           ; B, A in mm3
        movq            mm6,    mm0             ; j, i in mm6

        movq            mm4,    [edx+8]         ; D, C in mm4
        punpckldq       mm0,    mm0             ; i, i in mm0

        movq            mm5,    [edx+16]        ; F, E in mm5
        pfmul           mm3,    mm0             ; Bi, Ai in mm3

        punpckhdq       mm2,    mm2             ; j, j in mm2
        pfmul           mm4,    mm6             ; Dj, Ci in mm4

        movq            mm7,    [edx+24]        ; H, G in mm7
        punpckldq       mm1,    mm1             ; k, k in mm1
        pfmul           mm5,    mm2             ; Fj, Ej in mm5

        movq            mm0,    [edx+32]        ; J, I in mm0
        pfmul           mm7,    mm1             ; Hk, Gk in mm7

        movq            mm2,    [edx+40]        ; L, K in mm2
        pfmul           mm1,    mm0             ; (X), Ik in mm1

        punpckhdq       mm0,    mm4             ; Dj, J in mm0
        pfadd           mm3,    mm7             ; Bi+Hk, Ai+Gk in mm3

        punpckldq       mm1,    mm4             ; Ci, Ik in mm1
        pfadd           mm2,    mm5             ; Fj+L, Ej+K in mm2

        pfacc           mm0,    mm1             ; Ci+Ik, Dj+J in mm0
        movq            mm4,    mm0

        punpckldq       mm0,    mm2             ; Ej+K, Dj+J in mm0
        punpckhdq       mm4,    mm2             ; Fj+L, Ci+Ik

        pfadd           mm0,    mm3             ; Bi+Ej+Hk+K, Ai+Dj+Gk+J
        pfacc           mm4,    mm5             ; (X), Ci+Fj+Ik+L

        mov             eax,    dest            ; store result
        movq            [eax],  mm0
        movd            [eax+8],mm4

        ret
END_PROC        esch_amd3d_nofpu_transform


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_amd3d_nofpu_transform_notran                                        ³
;                                                                          ³
; void (void *vect,EschMatrix *m);                                         ³
;                                                                          ³
; This function transforms the vector/point, by the matrix m ignoring      ³
; translations but leaves the processor in the MMX state which is not FPU  ³
; safe.                                                                    ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

;
;             [A B C 0]   [ Ai+Dj+Gk ]
; [i j k 1] * [D E F 0] = [ Bi+Ej+Hk ]
;             [G H I 0]   [ Ci+Fj+Ik ]
;             [J K L 1]   [    1     ]
;

        ALIGN   16
START_PROC      esch_amd3d_nofpu_transform_notran, C vect:DWORD, m:DWORD, dest:DWORD
        mov             ecx,    vect
        movq            mm0,    [ecx]           ; j, i in mm0
        movd            mm1,    [ecx+8]         ; 0, k in mm1

        punpckhdq       mm2,    mm0             ; j, undef in mm2

        mov             edx,    m
        movq            mm3,    [edx]           ; B, A in mm3
        movq            mm6,    mm0             ; j, i in mm6

        movq            mm4,    [edx+8]         ; D, C in mm4
        punpckldq       mm0,    mm0             ; i, i in mm0

        movq            mm5,    [edx+16]        ; F, E in mm5
        pfmul           mm3,    mm0             ; Bi, Ai in mm3

        punpckhdq       mm2,    mm2             ; j, j in mm2
        pfmul           mm4,    mm6             ; Dj, Ci in mm4

        movq            mm7,    [edx+24]        ; H, G in mm7
        punpckldq       mm1,    mm1             ; k, k in mm1
        pfmul           mm5,    mm2             ; Fj, Ej in mm5

        movd            mm0,    [edx+32]        ; 0, I in mm0
        pfmul           mm7,    mm1             ; Hk, Gk in mm7

        movq            mm6,    mm4             ; Dj, Ci in mm6
        pfmul           mm0,    mm1             ; 0, Ik in mm0

        movq            mm1,    mm5             ; Fj, Ej in mm1
        pfadd           mm3,    mm7             ; Bi+Hk, Ai+Gk in mm3

        punpckhdq       mm5,    mm5             ; Fj, Fj in mm5
        pfadd           mm0,    mm6             ; (X), Ci+Ik in mm0

        punpckldq       mm1,    mm1             ; Ej, Ej in mm1
        pfadd           mm0,    mm5             ; (X), Ci+Fj+Ik in mm0

        punpckhdq       mm4,    mm1             ; Ej, Dj in mm4
        pfadd           mm3,    mm4             ; Bi+Ej+Hk, Ai+Dj+Gk in mm3

        mov             eax,    dest            ; store result
        movq            [eax],  mm3
        movd            [eax+8],mm0

        ret
END_PROC        esch_amd3d_nofpu_transform_notran


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_amd3d_nofpu_normalize                                               ³
;                                                                          ³
; EVector * (EschVector *v1,EschVector *v2,EschVector *dest);              ³
;                                                                          ³
; Normalizes the vector (if the magnitude is too small, leaves the vector  ³
; unchanged) but leaves the processor in the MMX state which is not FPU    ³
; safe.                                                                    ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

        ALIGN   16
START_PROC      esch_amd3d_nofpu_normalize, C vect:DWORD

        mov             ecx,    vect
        movq            mm0,    [ecx]           ; j, i in mm0
        movd            mm1,    [ecx+8]         ; 0, k in mm1

        movq            mm4,    mm0             ; j, i in mm4
        movq            mm3,    mm1             ; 0, k in mm3

        pfmul           mm0,    mm0             ; j*j, i*i in mm0
        pfmul           mm1,    mm1             ; 0, k*k in mm1

        pfacc           mm0,    mm0             ; (X), i*i+j*j in mm0
        pfadd           mm0,    mm1             ; (X), i*i+j*j+k*k in mm0

        movd            eax,    mm0             ; length into eax
        pfrsqrt         mm1,    mm0             ; approx. 1/mag in mm1
        movq            mm2,    mm1

        cmp             eax,    038D1B717h      ; 0.0001
        jl              exit                    ; if length < 0.0001

        pfmul           mm1,    mm1             ; refine rsqrt
        pfrsqit1        mm1,    mm0
        pfrcpit2        mm1,    mm2             ; (X), 1/mag in mm1

        punpckldq       mm1,    mm1             ; 1/mag, 1/mag in mm1

        pfmul           mm3,    mm1             ; 0, k/mag in mm3
        pfmul           mm4,    mm1             ; j/mag, i/mag in mm2

        movd            [ecx+8],mm3             ; store result
        movq            [ecx],  mm4

exit:
        femms                                   ; exit MMX state
        ret
END_PROC        esch_amd3d_nofpu_normalize

_text   ends
        end

;°±² End of module - esamd3d.asm ²±°
