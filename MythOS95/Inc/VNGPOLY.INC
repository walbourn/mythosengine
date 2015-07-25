;อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
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
;ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
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
;ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
;
; vngpoly.inc
;
;      This is set of macros used by all of the polygon scan conversion 
;      routines used in Van Gogh.
;
;อออออออออออออออออออออออออออออ Revision History ออออออออออออออออออออออออออออ
;อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
ifndef  __VNGPOLY_INC
__VNGPOLY_INC  EQU 1

POLYSETUP      MACRO
       LOCAL   svert
       LOCAL   sort_loop
       LOCAL   find_first_left
       LOCAL   find_first_right
       ;
       ; Sort the Verticies for drawing.
       ;
svert:
       mov     esi,pts                 ; The top of the list.
       mov     edi,esi

       mov     eax,count
       dec     eax                     
@@:
       add     edi,SIZEOF VNGO_POINT
       dec     eax
       jnz     @b
                                       ; edi now has the end of the list.
       mov     vl_start,esi
       mov     vl_end,edi


       xor     ecx,ecx                 ; a false bottom.
       mov     ebx,7ffffffh            ; a false top
                                       
 
       mov     eax,count
       push    ebp
       mov     ebp,eax

sort_loop:
   ; Is this the top point?
       mov     eax,(VNGO_POINT PTR [esi]).pt_y
       cmp     eax,ebx
       jge     @f
       mov     ebx,eax                 ; save the top y
       mov     edx,esi                 ; save the pointer to the top vert.
@@:
   ; Is this the bottom point?
       cmp     eax,ecx
       jl      @f
       mov     ecx,eax                 ; save the bottom y
@@:
       add     esi,SIZEOF VNGO_POINT
       dec     ebp
       jnz     SHORT sort_loop

       pop     ebp

       mov     lvert,edx               ; Set the starting vert.
       mov     rvert,edx               ; Set the starting vert.
        
       sub     ecx,ebx
       jz      poly_done
       mov     ycount,ecx              ; save the number of Y lines to do.

       ;
       ; Find the first left and right verts.
       ;

       mov     eax,(VNGO_POINT PTR [edx]).pt_y
       mov     cur_y,eax

find_first_left:
       mov     eax,(VNGO_POINT PTR [edx]).pt_y
       mov     ebx,edx
       sub     ebx,SIZEOF VNGO_POINT
       cmp     ebx,vl_start
       jae     @f                      ; if we have stepped past the first
       mov     ebx,vl_end              ; vert then go to the last vert.
@@:
       cmp     (VNGO_POINT PTR [ebx]).pt_y,eax
       jne     @f
       mov     edx,ebx
       jmp     SHORT find_first_left

@@:
       mov     lvert,edx
       mov     lnvert,ebx
       mov     edx,rvert

find_first_right:
       mov     eax,(VNGO_POINT PTR [edx]).pt_y
       mov     ebx,edx
       add     ebx,SIZEOF VNGO_POINT
       cmp     ebx,vl_end
       jle     @f
       mov     ebx,vl_start
@@:
       cmp     (VNGO_POINT PTR [ebx]).pt_y,eax
       jne     @f
       mov     edx,ebx
       jmp     SHORT find_first_right
@@:
       mov     rvert,edx
       mov     rnvert,ebx

               ENDM

endif          ; __VNGPOLY_INC

;ฐฑฒ End of module - vngpoly.inc ฒฑฐ


