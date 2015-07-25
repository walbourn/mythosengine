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
; esclip.asm
;
;       Contains the clipping support code.
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
include felix.inc
include vngstrct.inc

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
; esch_clip_x_line                                                         ³
;                                                                          ³
;       This function fills in the data for the output point after it is   ³
;       clipped to the line in p.                                          ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

        ALIGN   16
START_PROC esch_clip_x_line,    C  p:dword, s:dword, f:dword, out_point:dword
        LOCAL   t:DWORD         ; this is to be used as a 2.30 fixed point.

        push    ebx
        push    esi
        push    edi

        mov     ebx,p
        mov     esi,f
        mov     edi,s
        mov     ecx,out_point

        mov     eax,(VNGO_POINT PTR [esi]).pt_clr
        mov     (VNGO_POINT PTR [ecx]).pt_clr,eax

        
       
        mov     edx,ebx
        cmp     edx,(VNGO_POINT PTR [edi]).pt_x
        jge     @f
        xchg    esi,edi
@@:
        sub     edx,(VNGO_POINT PTR [edi]).pt_x
        xor     eax,eax
        mov     (VNGO_POINT PTR [ecx]).pt_x,ebx
        mov     ebx,(VNGO_POINT PTR [esi]).pt_x
        sub     ebx,(VNGO_POINT PTR [edi]).pt_x
        shrd    eax,edx,2
        sar     edx,2
        idiv    ebx
        mov     t,eax                   ; store 2.30 result.

;; Calculate the new Y.
        mov     ebx,(VNGO_POINT PTR [esi]).pt_y
        sub     ebx,(VNGO_POINT PTR [edi]).pt_y
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_y
        mov     (VNGO_POINT PTR [ecx]).pt_y,eax


;; Calculate the new shade.
        mov     eax,t                   ; get the multiplier again.
        mov     ebx,(VNGO_POINT PTR [esi]).pt_shade
        sub     ebx,(VNGO_POINT PTR [edi]).pt_shade
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_shade
        mov     (VNGO_POINT PTR [ecx]).pt_shade,eax

;; Calculate the new U.
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_u
        sub     ebx,(VNGO_POINT PTR [edi]).pt_u
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_u
        mov     (VNGO_POINT PTR [ecx]).pt_u,eax

;; Calculate the new V.
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_v
        sub     ebx,(VNGO_POINT PTR [edi]).pt_v
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_v
        mov     (VNGO_POINT PTR [ecx]).pt_v,eax

;; Calculate the new Z.
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_z
        sub     ebx,(VNGO_POINT PTR [edi]).pt_z
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_z
        mov     (VNGO_POINT PTR [ecx]).pt_z,eax

;; Calculate the new W.
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_w
        sub     ebx,(VNGO_POINT PTR [edi]).pt_w
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_w
        mov     (VNGO_POINT PTR [ecx]).pt_w,eax

        pop     edi
        pop     esi
        pop     ebx

        ret

change_directions:
END_PROC   esch_clip_x_line


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_clip_y_line                                                         ³
;                                                                          ³
;       This function fills in the data for the output point after it is   ³
;       clipped to the line in p.                                          ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

        ALIGN   16
START_PROC esch_clip_y_line,    C  p:dword, s:dword, f:dword, out_point:dword
        LOCAL   t:DWORD         ; this is to be used as a 2.30 fixed point.

        push    ebx
        push    esi
        push    edi

        mov     ebx,p
        mov     esi,f
        mov     edi,s
        mov     ecx,out_point

        mov     eax,(VNGO_POINT PTR [esi]).pt_clr
        mov     (VNGO_POINT PTR [ecx]).pt_clr,eax

        mov     edx,ebx
        cmp     edx,(VNGO_POINT PTR [edi]).pt_y
        jge     @f
        xchg    esi,edi
@@:

        sub     edx,(VNGO_POINT PTR [edi]).pt_y
        xor     eax,eax
        mov     (VNGO_POINT PTR [ecx]).pt_y,ebx
        mov     ebx,(VNGO_POINT PTR [esi]).pt_y
        sub     ebx,(VNGO_POINT PTR [edi]).pt_y
        shrd    eax,edx,2
        sar     edx,2
        idiv    ebx
        mov     t,eax                   ; store 2.30 result.

;; Calculate the new X.
        mov     ebx,(VNGO_POINT PTR [esi]).pt_x
        sub     ebx,(VNGO_POINT PTR [edi]).pt_x
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_x
        mov     (VNGO_POINT PTR [ecx]).pt_x,eax


;; Calculate the new shade.
        mov     eax,t                   ; get the multiplier again.
        mov     ebx,(VNGO_POINT PTR [esi]).pt_shade
        sub     ebx,(VNGO_POINT PTR [edi]).pt_shade
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_shade
        mov     (VNGO_POINT PTR [ecx]).pt_shade,eax

;; Calculate the new U.
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_u
        sub     ebx,(VNGO_POINT PTR [edi]).pt_u
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_u
        mov     (VNGO_POINT PTR [ecx]).pt_u,eax

;; Calculate the new V.
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_v
        sub     ebx,(VNGO_POINT PTR [edi]).pt_v
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_v
        mov     (VNGO_POINT PTR [ecx]).pt_v,eax

;; Calculate the new Z.
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_z
        sub     ebx,(VNGO_POINT PTR [edi]).pt_z
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_z
        mov     (VNGO_POINT PTR [ecx]).pt_z,eax

;; Calculate the new W.
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_w
        sub     ebx,(VNGO_POINT PTR [edi]).pt_w
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_w
        mov     (VNGO_POINT PTR [ecx]).pt_w,eax

        pop     edi
        pop     esi
        pop     ebx

        ret
END_PROC   esch_clip_y_line

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_clip_z_line                                                         ³
;                                                                          ³
;       This function fills in the data for the output point after it is   ³
;       clipped to the line in p.                                          ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

        ALIGN   16
START_PROC      esch_clip_z_line,  C  p:dword, s:dword, f:dword, out_point:dword
        LOCAL   t:DWORD         ; this is to be used as a 2.30 fixed point.

        push    ebx
        push    esi
        push    edi

        mov     ebx,p
        mov     esi,f
        mov     edi,s
        mov     ecx,out_point

        mov     eax,(VNGO_POINT PTR [esi]).pt_clr
        mov     (VNGO_POINT PTR [ecx]).pt_clr,eax

        mov     edx,ebx
        cmp     edx,(VNGO_POINT PTR [edi]).pt_wz
        jge     @f
        xchg    esi,edi
@@:

        sub     edx,(VNGO_POINT PTR [edi]).pt_wz
        xor     eax,eax
        mov     (VNGO_POINT PTR [ecx]).pt_wz,ebx
        mov     ebx,(VNGO_POINT PTR [esi]).pt_wz
        sub     ebx,(VNGO_POINT PTR [edi]).pt_wz

        ;; At this point ebx is the delta Z.

        shrd    eax,edx,2
        sar     edx,2
        idiv    ebx
        mov     t,eax                   ; store 2.30 result.

;; Calculate the new X.
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_wx
        sub     ebx,(VNGO_POINT PTR [edi]).pt_wx
        imul    ebx
        shld    edx,eax,2
        add     edx,(VNGO_POINT PTR [edi]).pt_wx
        mov     (VNGO_POINT PTR [ecx]).pt_wx,edx


;; Calculate the new Y.
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_wy
        sub     ebx,(VNGO_POINT PTR [edi]).pt_wy
        imul    ebx
        shld    edx,eax,2
        add     edx,(VNGO_POINT PTR [edi]).pt_wy
        mov     (VNGO_POINT PTR [ecx]).pt_wy,edx


;; Calculate the new shade.
        mov     eax,t                   ; get the multiplier again.
        mov     ebx,(VNGO_POINT PTR [esi]).pt_shade
        sub     ebx,(VNGO_POINT PTR [edi]).pt_shade
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_shade
        mov     (VNGO_POINT PTR [ecx]).pt_shade,eax

;; Calculate the new U.
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_u
        sub     ebx,(VNGO_POINT PTR [edi]).pt_u
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_u
        mov     (VNGO_POINT PTR [ecx]).pt_u,eax

;; Calculate the new V.
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_v
        sub     ebx,(VNGO_POINT PTR [edi]).pt_v
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_v
        mov     (VNGO_POINT PTR [ecx]).pt_v,eax

        pop     edi
        pop     esi
        pop     ebx

        ret

END_PROC        esch_clip_z_line


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; esch_rotate_check                                                        ³
;                                                                          ³
;       This function checks to see if a polygon is clockwise or counter   ³
;       clockwise in its rotation.  It return 1 if it is clockwise.        ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

        ALIGN   16
START_PROC      esch_rotate_check, C    count:DWORD, pts:DWORD

        LOCAL   lvert:DWORD
        LOCAL   lnvert:DWORD
        LOCAL   rvert:DWORD
        LOCAL   rnvert:DWORD
        LOCAL   ycount:DWORD
        LOCAL   lx:DWORD
        LOCAL   rx:DWORD
        LOCAL   cur_y:DWORD
        LOCAL   vl_start:DWORD
        LOCAL   vl_end:DWORD
        LOCAL   clock_flag:DWORD
        LOCAL   lcnt:DWORD
        LOCAL   rcnt:DWORD
        LOCAL   lxstep:DWORD
        LOCAL   rxstep:DWORD

        push    esi
        push    edi
        push    ebx

        mov     clock_flag,1
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
        cmp     ecx,0
        jle     test_done
        inc     ecx                     ; dy+1
        mov     ycount,ecx              ; save the number of Y lines to do.

        ;
        ; Find the first left and right verts.
        ;

        mov     eax,(VNGO_POINT PTR [edx]).pt_y
        mov     cur_y,eax

find_first_cclock:
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
        jmp     SHORT find_first_cclock

@@:
        mov     lvert,edx
        mov     lnvert,ebx
        mov     edx,rvert

find_first_clock:
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
        jmp     SHORT find_first_clock
@@:
        mov     rvert,edx
        mov     rnvert,ebx

   ; Now that we have come this far, decide if the polygon is clockwise or
   ; counter clockwise.
        mov     clock_flag,0ffffh       ; this means that we have not yet
                                        ; yet determined the rotation.
        mov     ebx,lvert               
        cmp     edx,ebx                 ; are the first clockwise and 
                                        ; counter-clockwise verticies the 
        je      simple_check            ; same one?

        mov     eax,(VNGO_POINT PTR [ebx]).pt_x
        cmp     eax,(VNGO_POINT PTR [edx]).pt_x
        je      simple_check
        mov     clock_flag,1
        jl      @f
        mov     clock_flag,0            ; it is not clockwise.
@@:
        ; Now we calc the clock & counter-clock xsteps for the first segments.        
simple_check:
        ; Fisrt calc the counter-clock side.

        mov     ebx,lvert
        mov     esi,lnvert
        mov     edi,(VNGO_POINT PTR [esi]).pt_y
        sub     edi,(VNGO_POINT PTR [ebx]).pt_y ; calculate the dy.
        mov     lcnt,edi                ; this is the number of steps to take.
        inc     lcnt                    ; try dy + 1.
        ; calc. 1/dy.
        mov     eax,080000000h
        xor     edx,edx
        div     edi
        shr     eax,1
        adc     eax,0
        mov     ecx,eax

        mov     eax,(VNGO_POINT PTR [esi]).pt_x
        sub     eax,(VNGO_POINT PTR [ebx]).pt_x ; calculate the dx.
        imul    ecx                     
        shrd    eax,edx,10              ; the result is now in 34.30
        mov     lxstep,eax
        mov     eax,(VNGO_POINT PTR [ebx]).pt_x
        shl     eax,20                  ; convert to 12.20
        mov     lx,eax

        ; Now calc the clockwise side.
        mov     ebx,rvert
        mov     esi,rnvert
        mov     edi,(VNGO_POINT PTR [esi]).pt_y
        sub     edi,(VNGO_POINT PTR [ebx]).pt_y
        mov     rcnt,edi
        inc     rcnt                    ; try dy + 1.

        ; calc. 1/dy.
        mov     eax,080000000h
        xor     edx,edx
        div     edi
        shr     eax,1
        adc     eax,0
        mov     ecx,eax

        mov     eax,(VNGO_POINT PTR [esi]).pt_x
        sub     eax,(VNGO_POINT PTR [ebx]).pt_x ; calculate the dx.
        imul    ecx                     
        shrd    eax,edx,10              ; the result is now in 34.30
        mov     rxstep,eax
        mov     eax,(VNGO_POINT PTR [ebx]).pt_x
        shl     eax,20                  ; convert to 12.20
        mov     rx,eax

        cmp     clock_flag,0ffffh       ; has the rotation been detected yet?
        jne     test_done
        ; if not, do that now.
        mov     clock_flag,1            ; assume clockwise
        mov     eax,rxstep
        cmp     eax,lxstep
        jg      test_done
        mov     clock_flag,0
test_done:
        pop     ebx
        pop     edi
        pop     esi

        mov     eax,clock_flag          ; set it up as the return value.

        ret
END_PROC        esch_rotate_check

_text   ends
        end

;°±² End of module - esclip.asm ²±°
