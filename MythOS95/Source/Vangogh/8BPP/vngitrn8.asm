;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
;
;                                                           %__________%
;                                                          %/ . .  .   \%
;           Van Gogh 2D-Display Library                     |  . .  o. |
;                                                           |. _  .   .|
;        Microsoft Windows 95/98/NT Version                 | / \   .  |
;                                                           |_|_|_._._.|
;                                                           |.-.-.-.-..|
;                                                          %\__________/%
;                                                           %          %
;
;  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
;
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
; Created by Tim Little
;
; vngITRN8.ASM 
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
include vngdefs.inc
include vngstrct.inc

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
_DATA   SEGMENT PARA PUBLIC USE32 'DATA'


_DATA   ENDS


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
; vngo_iline8 (char *lptr, char *tptr, long xcount, dword flags);          ³
;       This funtion transfers a line of data to the viewport.  This       ³
;       routine assumes that all clipping has been done.  This function is ³
;       used by the image transfer function when some portion of the image ³
;       has been clipped.                                                  ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      vngo_iline8,    C lptr:DWORD,tptr:DWORD,xcount:DWORD,flags:DWORD

        push    esi
        push    edi
        mov     esi,tptr
        mov     edi,lptr
        mov     ecx,xcount

        test    flags,VNGO_TRANSPARENT
        js      clear_transfer_loop

transfer_loop:
        shr     ecx,1
    rep movsw
        jnc     SHORT exit
        movsb
        jmp     SHORT exit

clear_transfer_loop:
        mov     al,[esi]
        cmp     al,255
        je      @f
        mov     [edi],al
@@:
        inc     esi
        inc     edi
        dec     ecx
        jnz     SHORT clear_transfer_loop

exit:
        pop     edi
        pop     esi

        ret
END_PROC        vngo_iline8


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; vngo_iline_s8 (char *lptr, char *tptr, long xcount,                      ³
;                void *shade_pal, dword flags);                            ³     
;       This funtion does the exact same thing as vngo_iline8 except it    ³
;       supports shading and is called from the shading version of image   ³
;       transfer.                                                          ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      vngo_iline_s8,    C lptr:DWORD,tptr:DWORD,xcount:DWORD,shade_pal:DWORD,flags:DWORD
        LOCAL   spal:DWORD      ; pointer to the current shade palette.

        push    esi
        push    edi
        mov     esi,tptr
        mov     edi,lptr
        mov     ecx,xcount

        test    flags,VNGO_TRANSPARENT
        js      clear_transfer_loop

transfer_loop:
        shr     ecx,1
    rep movsw
        jnc     SHORT exit
        movsb
        jmp     SHORT exit

clear_transfer_loop:
        mov     al,[esi]
        cmp     al,255
        je      @f
        mov     [edi],al
@@:
        inc     esi
        inc     edi
        dec     ecx
        jnz     SHORT clear_transfer_loop

exit:
        pop     edi
        pop     esi

        ret
END_PROC        vngo_iline_s8

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; vngo_iline_z8 (char *lptr, void *zptr, char *tptr, long xcount,          ³
;                dword depth, dword flags);                                ³     
;       This funtion does the exact same thing as vngo_iline8 except it    ³
;       supports Z-Buffering and is called from the Z-buffering version    ³
;       of image transfer.                                                 ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      vngo_iline_z8,    C lptr:DWORD,zptr:DWORD,tptr:DWORD,xcount:DWORD,depth:DWORD,flags:DWORD
        LOCAL   tdepth:DWORD    ; pointer to the current shade palette.

        push    esi
        push    edi
        push    ebx

        mov     esi,tptr
        mov     edi,lptr
        mov     ecx,xcount
        mov     eax,depth
        shr     eax,16
        mov     tdepth,eax
        mov     edx,zptr
        xor     ebx,ebx

        test    flags,VNGO_TRANSPARENT
        js      clear_transfer_loop

transfer_loop:
        mov     bx,WORD PTR [edx]
        cmp     ebx,tdepth
        jle     @f
        mov     al,[esi]
        mov     [edi],al
@@:
        inc     esi
        lea     edx,[edx+2]
        inc     edi
        dec     ecx
        jnz     SHORT transfer_loop

        shr     ecx,1
    rep movsw
        jnc     SHORT exit
        movsb
        jmp     SHORT exit

clear_transfer_loop:
        mov     al,[esi]
        cmp     al,255
        je      @f
        mov     bx,WORD PTR [edx]
        cmp     ebx,tdepth
        jle     @f
        mov     [edi],al
@@:
        inc     esi
        lea     edx,[edx+2]
        inc     edi
        dec     ecx
        jnz     SHORT clear_transfer_loop

exit:
        pop     ebx
        pop     edi
        pop     esi

        ret
END_PROC        vngo_iline_z8



;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; vngo_ilinemono8 (byte *lptr, byte *tptr, long xcount,                    ³
;                  dword tskip, dword fgcol, dword bgcol);                 ³
;       This function does monochrome expansion as it performs a similar   ³
;       operation to the vngo_iline8 function described above.  This       ³
;       routine is used by the image transfer member that does clipping    ³
;       and monochrome expansion.                                          ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      vngo_ilinemono8,    C lptr:DWORD,tptr:DWORD,xcount:DWORD,bit_off:DWORD,fgcol:DWORD,bgcol:DWORD

        push    esi
        push    edi
        push    ebx
        mov     esi,tptr
        mov     edi,lptr
        mov     ecx,xcount
        or      ecx,ecx
        jnz     cont            ; Don't do anything if there is nothing to do!
        jmp     exit
cont:
        cmp     bgcol,VNGO_TRANSPARENT
        je      clear_transfer_loop_start_bg
        cmp     bgcol,VNGO_TRANSPARENT_COLOR
        je      clear_transfer_loop_start_bg

        cmp     fgcol,VNGO_TRANSPARENT
        je      clear_transfer_loop_start_fg
        cmp     fgcol,VNGO_TRANSPARENT_COLOR
        je      clear_transfer_loop_start_fg


;; This does the monochrome expansion with forground and background expansion!
;; First expand the bottom bits of the first byte of data.
transfer_start:
        mov     ebx,fgcol
        mov     eax,bgcol
        shl     ebx,8           ; bh is the forground color.
        mov     bl,al           ; bl is the background color.
start_byte:
        mov     al,[esi]
        cmp     bit_off,0
        je      skip_0
        push    ecx
        mov     ecx,bit_off
        and     cl,07h          ; make sure it doesn't skip more than a byte.
        shl     al,cl           ; shift off all of the skipped bits.
        mov     edx,ecx         ; get the number of bits that we skipped,
                                ; in edx for safe keeping. (jump past that
                                ; many itterations of the move.
        mov     bit_off,0       ; only skip for the first byte.
        pop     ecx   
        dec     edx
        jz      skip_1
        dec     edx
        jz      skip_2
        dec     edx
        jz      skip_3
        dec     edx
        jz      skip_4
        dec     edx
        jz      skip_5
        dec     edx
        jz      skip_6
        dec     edx
        jz      skip_7


skip_0:
        shl     al,1
        jnc     t1                      
        mov     [edi],bh        ; draw the forground color.
        jmp     short t2
t1:
        mov     [edi],bl        ; draw the background color.
t2:
        dec     ecx
        jz      exit

skip_1:
        inc     edi
        shl     al,1
        jnc     t12
        mov     [edi],bh        ; draw the forground color.
        jmp     short t22
t12:
        mov     [edi],bl        ; draw the background color.
t22:
        dec     ecx
        jz      exit

skip_2:
        inc     edi
        shl     al,1
        jnc     t13
        mov     [edi],bh        ; draw the forground color.
        jmp     short t23
t13:
        mov     [edi],bl        ; draw the background color.
t23:
        dec     ecx
        jz      exit

skip_3:
        inc     edi
        shl     al,1
        jnc     t14
        mov     [edi],bh        ; draw the forground color.
        jmp     short t24
t14:
        mov     [edi],bl        ; draw the background color.
t24:
        dec     ecx
        jz      exit

skip_4:
        inc     edi
        shl     al,1
        jnc     t15
        mov     [edi],bh        ; draw the forground color.
        jmp     short t25
t15:
        mov     [edi],bl        ; draw the background color.
t25:
        dec     ecx
        jz      exit

skip_5:
        inc     edi
        shl     al,1
        jnc     t16
        mov     [edi],bh        ; draw the forground color.
        jmp     short t26
t16:
        mov     [edi],bl        ; draw the background color.
t26:
        dec     ecx
        jz      exit

skip_6:
        inc     edi
        shl     al,1
        jnc     t17
        mov     [edi],bh        ; draw the forground color.
        jmp     short t27
t17:
        mov     [edi],bl        ; draw the background color.
t27:
        dec     ecx
        jz      exit

skip_7:
        inc     edi
        shl     al,1
        jnc     t18
        mov     [edi],bh        ; draw the forground color.
        jmp     short t28
t18:
        mov     [edi],bl        ; draw the background color.
t28:
        dec     ecx
        jz      exit
        inc     esi
        inc     edi
        jmp     start_byte
exit:
        jmp     exit3

;; This does the monochrome expansion with transparency!
;; First expand the bottom bits of the first byte of data.
clear_transfer_loop_start_bg:
        mov     ebx,fgcol
        mov     eax,bgcol
        shl     ebx,8           ; bh is the forground color.
        mov     bl,al           ; bl is the background color.
start_byte_trans_bg:
        mov     al,[esi]
        cmp     bit_off,0
        je      tskip_0_bg
        push    ecx
        mov     ecx,bit_off
        and     cl,07h          ; make sure it doesn't skip more than a byte.
        shl     al,cl           ; shift off all of the skipped bits.
        mov     edx,ecx         ; get the number of bits that we skipped,
                                ; in edx for safe keeping. (jump past that
                                ; many itterations of the move.
        mov     bit_off,0       ; only skip for the first byte.
        pop     ecx   
        dec     edx
        jz      tskip_1_bg
        dec     edx
        jz      tskip_2_bg
        dec     edx
        jz      tskip_3_bg
        dec     edx
        jz      tskip_4_bg
        dec     edx
        jz      tskip_5_bg
        dec     edx
        jz      tskip_6_bg
        dec     edx
        jz      tskip_7_bg

tskip_0_bg:
        shl     al,1
        jnc     @f
        mov     [edi],bh        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_1_bg:
        inc     edi
        shl     al,1
        jnc     @f
        mov     [edi],bh        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_2_bg:
        inc     edi
        shl     al,1
        jnc     @f
        mov     [edi],bh        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_3_bg:
        inc     edi
        shl     al,1
        jnc     @f
        mov     [edi],bh        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_4_bg:
        inc     edi
        shl     al,1
        jnc     @f
        mov     [edi],bh        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_5_bg:
        inc     edi
        shl     al,1
        jnc     @f
        mov     [edi],bh        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_6_bg:
        inc     edi
        shl     al,1
        jnc     @f
        mov     [edi],bh        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_7_bg:
        inc     edi
        shl     al,1
        jnc     @f
        mov     [edi],bh        ; draw the forground color.
@@:
        dec     ecx
        jz      exit2
        inc     esi
        inc     edi
        jmp     start_byte_trans_bg

exit2:
        jmp     exit3

clear_transfer_loop_start_fg:
        mov     ebx,bgcol
        mov     eax,fgcol
        shl     ebx,8           ; bh is the background color.
        mov     bl,al           ; bl is the Forground color.
start_byte_trans_fg:
        mov     al,[esi]
        cmp     bit_off,0
        je      tskip_0_fg
        push    ecx
        mov     ecx,bit_off
        and     cl,07h          ; make sure it doesn't skip more than a byte.
        shl     al,cl           ; shift off all of the skipped bits.
        mov     edx,ecx         ; get the number of bits that we skipped,
                                ; in edx for safe keeping. (jump past that
                                ; many itterations of the move.
        mov     bit_off,0       ; only skip for the first byte.
        pop     ecx   
        dec     edx
        jz      tskip_1_fg
        dec     edx
        jz      tskip_2_fg
        dec     edx
        jz      tskip_3_fg
        dec     edx
        jz      tskip_4_fg
        dec     edx
        jz      tskip_5_fg
        dec     edx
        jz      tskip_6_fg
        dec     edx
        jz      tskip_7_fg

tskip_0_fg:
        shl     al,1
        jc      @f
        mov     [edi],bh        ; draw the background color.
@@:
        dec     ecx
        jz      exit


tskip_1_fg:
        inc     edi
        shl     al,1
        jc      @f
        mov     [edi],bh        ; draw the background color.
@@:
        dec     ecx
        jz      exit


tskip_2_fg:
        inc     edi
        shl     al,1
        jc      @f
        mov     [edi],bh        ; draw the background color.
@@:
        dec     ecx
        jz      exit


tskip_3_fg:
        inc     edi
        shl     al,1
        jc      @f
        mov     [edi],bh        ; draw the background color.
@@:
        dec     ecx
        jz      exit


tskip_4_fg:
        inc     edi
        shl     al,1
        jc      @f
        mov     [edi],bh        ; draw the background color.
@@:
        dec     ecx
        jz      exit


tskip_5_fg:
        inc     edi
        shl     al,1
        jc      @f
        mov     [edi],bh        ; draw the background color.
@@:
        dec     ecx
        jz      exit


tskip_6_fg:
        inc     edi
        shl     al,1
        jc      @f
        mov     [edi],bh        ; draw the background color.
@@:
        dec     ecx
        jz      exit


tskip_7_fg:
        inc     edi
        shl     al,1
        jc      @f
        mov     [edi],bh        ; draw the background color.
@@:
        dec     ecx
        jz      exit3
        inc     esi
        inc     edi
        jmp     start_byte_trans_fg

exit3:

        pop     ebx
        pop     edi
        pop     esi

        ret
END_PROC        vngo_ilinemono8


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; vngo_itrans8 (VngoVbuffer *vbuf, VngoRect *dest_rect,                    ³
;               VngoTexture *img,dword flags);                             ³
;       This routine transfers a VngoTexture to the target viewport.       ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      vngo_itrans8,   C CurScreen:DWORD, dest:DWORD, img:DWORD, flags:DWORD
        LOCAL   delta_pitch:DWORD

        push    ebx
        push    esi
        push    edi

        mov     esi,CurScreen
        mov     ebx,dest


        mov     ax,ds
        mov     es,ax

        mov     edi,(VNGO_VBUFFER PTR [esi]).vb_scrn_ptr
        mov     edx,(VNGO_VBUFFER PTR [esi]).vb_ytable
        mov     ebx,dest
        mov     ecx,(VNGO_RECT PTR [ebx]).rect_x
        mov     eax,(VNGO_RECT PTR [ebx]).rect_y
        mov     edx,[edx+eax*4]     ; get the address of the start of this line.
        add     edx,ecx             ; add x to get the starting offset.
        lea     edi,[edi+edx]       ; add offset to the buffer pointer.

        mov     eax,(VNGO_RECT PTR [ebx]).rect_dx
        mov     ecx,(VNGO_RECT PTR [ebx]).rect_dy

        mov     ebx,img
        mov     edx,(VNGO_VBUFFER PTR [esi]).vb_pitch
; Take the narrower of the two, (texture width or clip rect width).
        xor     esi,esi
        mov     si,WORD PTR (VNGO_TEXTURE PTR [ebx]).tx_width
        sub     si,ax
        jg      @f      
        movzx   eax,WORD PTR (VNGO_TEXTURE PTR [ebx]).tx_width
        mov     esi,0
@@:
        mov     delta_pitch,esi
        sub     edx,eax
        jl      BigTexture

        mov     esi,(VNGO_TEXTURE PTR [ebx]).tex
; Take the shorter of the two, (texture height or clip rect height).
        cmp     cx,(VNGO_TEXTURE PTR [ebx]).tx_height
        jl      @f
        movzx   ecx,(VNGO_TEXTURE PTR [ebx]).tx_height
@@:
        mov     ebx,ecx
        or      ebx,ebx
        jz      exit
        test    flags,VNGO_TRANSPARENT
        js      clear_transfer_loop_begin

transfer_loop:
        mov     ecx,eax
        shr     ecx,1
    rep movsw
        jnc     @f
        movsb
@@:
        add     edi,edx
        add     esi,delta_pitch
        dec     ebx
        jnz     SHORT transfer_loop
        jmp     SHORT exit

clear_transfer_loop_begin:
        shl     eax,16
clear_transfer_loop:
        mov     ecx,eax
        shr     ecx,16
inside_loop:
        mov     al,[esi]
        cmp     al,255
        je      @f
        mov     [edi],al
@@:
        inc     esi
        inc     edi
        dec     ecx
        jnz     SHORT inside_loop
        add     edi,edx
        add     esi,delta_pitch
        dec     ebx
        jnz     SHORT clear_transfer_loop

BigTexture:
exit:
        pop     edi
        pop     esi
        pop     ebx
        ret
END_PROC        vngo_itrans8


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; vngo_iline_s8 (char *lptr, char *tptr, long xcount,                      ³
;                void *shade_pal, dword flags);                            ³
;       This routine transfers a VngoTexture to the target viewport.  Using³
;       the supplied shade palette to shade it.                            ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      vngo_itrans_s8,   C CurScreen:DWORD, dest:DWORD, img:DWORD, shade:DWORD, flags:DWORD
        LOCAL   spal:DWORD      ; pointer to the current shade palette.
        LOCAL   count:DWORD
        LOCAL   delta_pitch:DWORD

        push    ebx
        push    esi
        push    edi

        mov     esi,CurScreen
        mov     ebx,dest


        mov     ax,ds
        mov     es,ax

        mov     eax,shade
        shr     eax,3

        mov     edx,(VNGO_VBUFFER PTR [esi]).vb_pal
        mov     edx,[edx+4]
        mov     edx,[edx]
        add     edx,eax         ; add the shade offset.
        mov     spal,edx

        mov     edi,(VNGO_VBUFFER PTR [esi]).vb_scrn_ptr
        mov     edx,(VNGO_VBUFFER PTR [esi]).vb_ytable
        mov     ebx,dest
        mov     ecx,(VNGO_RECT PTR [ebx]).rect_x
        mov     eax,(VNGO_RECT PTR [ebx]).rect_y
        mov     edx,[edx+eax*4]     ; get the address of the start of this line.
        add     edx,ecx             ; add x to get the starting offset.
        lea     edi,[edi+edx]       ; add offset to the buffer pointer.

        mov     eax,(VNGO_RECT PTR [ebx]).rect_dx
        mov     ecx,(VNGO_RECT PTR [ebx]).rect_dy

        mov     ebx,img
        mov     edx,(VNGO_VBUFFER PTR [esi]).vb_pitch
; Take the narrower of the two, (texture width or clip rect width).
        xor     esi,esi
        mov     si,WORD PTR (VNGO_TEXTURE PTR [ebx]).tx_width
        sub     si,ax
        jg      @f      
        movzx   eax,WORD PTR (VNGO_TEXTURE PTR [ebx]).tx_width
        mov     esi,0
@@:
        mov     delta_pitch,esi
        mov     count,eax
        sub     edx,eax
        jl      BigTexture

        mov     esi,(VNGO_TEXTURE PTR [ebx]).tex
; Take the shorter of the two, (texture height or clip rect height).
        cmp     cx,(VNGO_TEXTURE PTR [ebx]).tx_height
        jl      @f
        movzx   ecx,(VNGO_TEXTURE PTR [ebx]).tx_height
@@:
        mov     ebx,ecx
        or      ebx,ebx
        jz      exit
        test    flags,VNGO_TRANSPARENT
        js      clear_transfer_loop

transfer_loop:
        mov     ecx,count
        push    edx
inside_loop:
        xor     eax,eax
        mov     al,[esi]
        mov     edx,spal
        shl     eax,5
        mov     eax,[edx+eax]
        mov     [edi],al
        inc     esi
        inc     edi
        dec     ecx
        jnz     SHORT inside_loop
        pop     edx
        add     edi,edx
        add     esi,delta_pitch
        dec     ebx
        jnz     SHORT transfer_loop
        jmp     SHORT exit

clear_transfer_loop:
        mov     ecx,count
        push    edx
clear_inside_loop:
        xor     eax,eax
        mov     al,[esi]
        cmp     al,255
        je      @f
        mov     edx,spal
        shl     ax,5
        mov     eax,[edx+eax]
        mov     [edi],al
@@:
        inc     esi
        inc     edi
        dec     ecx
        jnz     SHORT clear_inside_loop
        pop     edx
        add     edi,edx
        add     esi,delta_pitch
        dec     ebx
        jnz     SHORT clear_transfer_loop

BigTexture:
exit:
        pop     edi
        pop     esi
        pop     ebx
        ret
END_PROC        vngo_itrans_s8



;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; vngo_itrans_z8 (VngoVbuffer *vbuf, VngoRect *dest_rect,                  ³
;               VngoTexture *img,dword flags);                             ³
;       This routine transfers a VngoTexture to the target viewport.       ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      vngo_itrans_z8, C CurScreen:DWORD, dest:DWORD, img:DWORD, flags:DWORD
        LOCAL   delta_pitch:DWORD
        LOCAL   delta_zpitch:DWORD
        LOCAL   zptr:DWORD

        push    ebx
        push    esi
        push    edi

        mov     esi,CurScreen
        mov     ebx,dest


        mov     ax,ds
        mov     es,ax

        mov     edi,(VNGO_VBUFFER PTR [esi]).vb_scrn_ptr
        mov     edx,(VNGO_VBUFFER PTR [esi]).vb_ytable
        mov     ebx,dest
        mov     ecx,(VNGO_RECT PTR [ebx]).rect_x
        mov     eax,(VNGO_RECT PTR [ebx]).rect_y
        mov     edx,[edx+eax*4]     ; get the address of the start of this line.
        add     edx,ecx             ; add x to get the starting offset.
        lea     edi,[edi+edx]       ; add offset to the buffer pointer.

        mov     eax,(VNGO_RECT PTR [ebx]).rect_dx
        mov     ecx,(VNGO_RECT PTR [ebx]).rect_dy

        mov     ebx,img
        mov     edx,(VNGO_VBUFFER PTR [esi]).vb_pitch
; Take the narrower of the two, (texture width or clip rect width).
        xor     esi,esi
        mov     si,WORD PTR (VNGO_TEXTURE PTR [ebx]).tx_width
        sub     si,ax
        jg      @f      
        movzx   eax,WORD PTR (VNGO_TEXTURE PTR [ebx]).tx_width
        mov     esi,0
@@:
        mov     delta_pitch,esi
        sub     edx,eax
        jl      BigTexture

        mov     esi,(VNGO_TEXTURE PTR [ebx]).tex
; Take the shorter of the two, (texture height or clip rect height).
        cmp     cx,(VNGO_TEXTURE PTR [ebx]).tx_height
        jl      @f
        movzx   ecx,(VNGO_TEXTURE PTR [ebx]).tx_height
@@:
        mov     ebx,ecx
        or      ebx,ebx
        jz      exit
        test    flags,VNGO_TRANSPARENT
        js      clear_transfer_loop_begin

transfer_loop:
        mov     ecx,eax
        shr     ecx,1
    rep movsw
        jnc     @f
        movsb
@@:
        add     edi,edx
        add     esi,delta_pitch
        dec     ebx
        jnz     SHORT transfer_loop
        jmp     SHORT exit

clear_transfer_loop_begin:
        shl     eax,16
clear_transfer_loop:
        mov     ecx,eax
        shr     ecx,16
inside_loop:
        mov     al,[esi]
        cmp     al,255
        je      @f
        mov     [edi],al
@@:
        inc     esi
        inc     edi
        dec     ecx
        jnz     SHORT inside_loop
        add     edi,edx
        add     esi,delta_pitch
        dec     ebx
        jnz     SHORT clear_transfer_loop

BigTexture:
exit:
        pop     edi
        pop     esi
        pop     ebx
        ret
END_PROC        vngo_itrans_z8

_text   ends
        end

;°±² End of module - vngitrns.asm ²±°
