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
; vngITRN16.ASM
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

START_PROC      vngo_wordcopy,   C dptr:DWORD,sptr:DWORD,count:DWORD
        push    esi
        push    edi
        push    ebx
        mov     ecx,count
        mov     esi,sptr
        mov     edi,dptr

        ; Make sure there is something to do.
        or      ecx,ecx
        jz      _finished

        ; Align destination to dword boundary.
        test    edi,03h
        jns     @f
        mov     ax,word ptr [esi]
        dec     ecx
        lea     esi,[esi+2]
        mov     word ptr [edi],ax
        lea     edi,[edi+2]
        jz      SHORT _finished
@@:
        mov     ebx,ecx
        shr     ecx,1

        jz      SHORT wrap_up
;    rep movsd                       ; move the dwords.
if 1
loop_entry:
        mov     eax,[esi]
        sub     ecx,1
        mov     [edi],eax
        jz      SHORT add_4
        mov     edx,[esi+4]
        sub     ecx,1
        mov     [edi+4],edx
        jz      SHORT add_8
        mov     eax,[esi+8]
        sub     ecx,1
        mov     [edi+8],eax
        jz      SHORT add_12
        mov     edx,[esi+12]
        sub     ecx,1
        mov     [edi+12],edx
        jz      SHORT add_16
        mov     eax,[esi+16]
        sub     ecx,1
        mov     [edi+16],eax
        jz      SHORT add_20
        mov     edx,[esi+20]
        sub     ecx,1
        mov     [edi+20],edx
        jz      SHORT add_24
        mov     eax,[esi+24]
        sub     ecx,1
        mov     [edi+24],eax
        jz      SHORT add_28
        mov     edx,[esi+28]
        sub     ecx,1
        mov     [edi+28],edx
        lea     esi,[esi+32]
        lea     edi,[edi+32]
        jnz     SHORT loop_entry
endif
wrap_up:
        shr     ebx,1
        jnc     SHORT _finished
        mov     ax,word ptr [esi]   ; move last word if needed.
        mov     word ptr [edi],ax

_finished:
        pop     ebx
        pop     edi
        pop     esi
        ret

if 1
add_4:
        lea     edi,[edi+4]
        add     esi,4
        jmp     SHORT wrap_up
add_8:
        lea     edi,[edi+8]
        add     esi,8
        jmp     SHORT wrap_up
add_12:
        lea     edi,[edi+12]
        add     esi,12
        jmp     SHORT wrap_up
add_16:
        lea     edi,[edi+16]
        add     esi,16
        jmp     SHORT wrap_up
add_20:
        lea     edi,[edi+20]
        add     esi,20
        jmp     SHORT wrap_up
add_24:
        lea     edi,[edi+24]
        add     esi,24
        jmp     SHORT wrap_up
add_28:
        lea     edi,[edi+28]
        add     esi,28
        jmp     SHORT wrap_up
endif
END_PROC        vngo_wordcopy



;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; vngo_iline8 (char *lptr, char *tptr, long xcount, dword flags);          ³
;       This funtion transfers a line of data to the viewport.  This       ³
;       routine assumes that all clipping has been done.  This function is ³
;       used by the image transfer function when some portion of the image ³
;       has been clipped.                                                  ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      vngo_iline15,    C lptr:DWORD,tptr:DWORD,xcount:DWORD,flags:DWORD

        push    esi
        push    edi
        mov     esi,tptr
        mov     edi,lptr
        mov     ecx,xcount
        jcxz    exit

        test    flags,VNGO_TRANSPARENT
        js      clear_transfer_loop

transfer_loop:
        shr     ecx,1
    rep movsd
        jnc     @f
        movsw
@@:
        jmp     SHORT exit

clear_transfer_loop:
        mov     ax,[esi]
        cmp     ax,0111110000011111b
        je      @f
        mov     [edi],ax
@@:
        lea     edi,[edi+2]
        add     esi,2
        dec     ecx
        jnz     SHORT clear_transfer_loop

exit:
        pop     edi
        pop     esi

        ret
END_PROC        vngo_iline15


START_PROC      vngo_iline16,    C lptr:DWORD,tptr:DWORD,xcount:DWORD,flags:DWORD

        push    esi
        push    edi
        mov     esi,tptr
        mov     edi,lptr
        mov     ecx,xcount
        jcxz    exit

        test    flags,VNGO_TRANSPARENT
        js      clear_transfer_loop

transfer_loop:
        shr     ecx,1
    rep movsd
        jnc     @f
        movsw
@@:
        jmp     SHORT exit

clear_transfer_loop:
        mov     ax,[esi]
        cmp     ax,01111100000011111b
        je      @f
        mov     [edi],ax
@@:
        lea     edi,[edi+2]
        add     esi,2
        dec     ecx
        jnz     SHORT clear_transfer_loop

exit:
        pop     edi
        pop     esi

        ret
END_PROC        vngo_iline16


START_PROC      vngo_iline8to16,    C lptr:DWORD,tptr:DWORD,xcount:DWORD,tpal:DWORD,flags:DWORD

        push    esi
        push    edi
        mov     esi,tptr
        mov     edi,lptr
        mov     edx,tpal
        mov     ecx,xcount
        jcxz    exit

        test    flags,VNGO_TRANSPARENT
        js      clear_transfer_loop

transfer_loop:
        xor     eax,eax
        mov     al,[esi]
        shl     eax,5
        mov     ax,[edx+(eax*2)]
        mov     [edi],ax
        inc     esi
        lea     edi,[edi+2]
        dec     ecx
        jnz     transfer_loop
        jmp     SHORT exit

clear_transfer_loop:
        xor     eax,eax
        mov     al,[esi]
        cmp     al,VNGO_TRANSPARENT_COLOR
        je      @f
        shl     eax,6
        mov     ax,[eax+edx]
        mov     [edi],ax
@@:
        lea     edi,[edi+2]
        inc     esi
        dec     ecx
        jnz     SHORT clear_transfer_loop

exit:
        pop     edi
        pop     esi

        ret
END_PROC        vngo_iline8to16



;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; vngo_ilinemono16 (byte *lptr, byte *tptr, long xcount,                   ³
;                  dword tskip, dword fgcol, dword bgcol);                 ³
;       This function does monochrome expansion as it performs a similar   ³
;       operation to the vngo_iline8 function described above.  This       ³
;       routine is used by the image transfer member that does clipping    ³
;       and monochrome expansion.                                          ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      vngo_ilinemono16,    C lptr:DWORD,tptr:DWORD,xcount:DWORD,bit_off:DWORD,fgcol:DWORD,bgcol:DWORD

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
        shl     ebx,16          ; upper word of ebx is the forground color.
        mov     bx,ax           ; bx is the background color.
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
        rol     ebx,16
        mov     [edi],bx        ; draw the forground color.
        rol     ebx,16
        jmp     short t2
t1:
        mov     [edi],bx        ; draw the background color.
t2:
        dec     ecx
        jz      exit

skip_1:
        lea     edi,[edi+2]
        shl     al,1
        jnc     t12
        rol     ebx,16
        mov     [edi],bx        ; draw the forground color.
        rol     ebx,16
        jmp     short t22
t12:
        mov     [edi],bx        ; draw the background color.
t22:
        dec     ecx
        jz      exit

skip_2:
        lea     edi,[edi+2]
        shl     al,1
        jnc     t13
        rol     ebx,16
        mov     [edi],bx        ; draw the forground color.
        rol     ebx,16
        jmp     short t23
t13:
        mov     [edi],bx        ; draw the background color.
t23:
        dec     ecx
        jz      exit

skip_3:
        lea     edi,[edi+2]
        shl     al,1
        jnc     t14
        rol     ebx,16
        mov     [edi],bx        ; draw the forground color.
        rol     ebx,16
        jmp     short t24
t14:
        mov     [edi],bx        ; draw the background color.
t24:
        dec     ecx
        jz      exit

skip_4:
        lea     edi,[edi+2]
        shl     al,1
        jnc     t15
        rol     ebx,16
        mov     [edi],bx        ; draw the forground color.
        rol     ebx,16
        jmp     short t25
t15:
        mov     [edi],bx        ; draw the background color.
t25:
        dec     ecx
        jz      exit

skip_5:
        lea     edi,[edi+2]
        shl     al,1
        jnc     t16
        rol     ebx,16
        mov     [edi],bx        ; draw the forground color.
        rol     ebx,16
        jmp     short t26
t16:
        mov     [edi],bx        ; draw the background color.
t26:
        dec     ecx
        jz      exit

skip_6:
        lea     edi,[edi+2]
        shl     al,1
        jnc     t17
        rol     ebx,16
        mov     [edi],bx        ; draw the forground color.
        rol     ebx,16
        jmp     short t27
t17:
        mov     [edi],bx        ; draw the background color.
t27:
        dec     ecx
        jz      exit

skip_7:
        lea     edi,[edi+2]
        shl     al,1
        jnc     t18
        rol     ebx,16
        mov     [edi],bx        ; draw the forground color.
        rol     ebx,16
        jmp     short t28
t18:
        mov     [edi],bx        ; draw the background color.
t28:
        dec     ecx
        jz      exit
        inc     esi
        lea     edi,[edi+2]
        jmp     start_byte
exit:
        jmp     exit3

;; This does the monochrome expansion with transparency!
;; First expand the bottom bits of the first byte of data.
clear_transfer_loop_start_bg:
        mov     ebx,fgcol
;        mov     eax,bgcol
;        shl     ebx,16          ; upper word of ebx is the forground color.
;        mov     bx,ax           ; bx is the background color.
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
        mov     [edi],bx        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_1_bg:
        lea     edi,[edi+2]
        shl     al,1
        jnc     @f
        mov     [edi],bx        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_2_bg:
        lea     edi,[edi+2]
        shl     al,1
        jnc     @f
        mov     [edi],bx        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_3_bg:
        lea     edi,[edi+2]
        shl     al,1
        jnc     @f
        mov     [edi],bx        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_4_bg:
        lea     edi,[edi+2]
        shl     al,1
        jnc     @f
        mov     [edi],bx        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_5_bg:
        lea     edi,[edi+2]
        shl     al,1
        jnc     @f
        mov     [edi],bx        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_6_bg:
        lea     edi,[edi+2]
        shl     al,1
        jnc     @f
        mov     [edi],bx        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_7_bg:
        lea     edi,[edi+2]
        shl     al,1
        jnc     @f
        mov     [edi],bx        ; draw the forground color.
@@:
        dec     ecx
        jz      exit2
        inc     esi
        lea     edi,[edi+2]
        jmp     start_byte_trans_bg

exit2:
        jmp     exit3

clear_transfer_loop_start_fg:
        mov     ebx,bgcol
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
        mov     [edi],bx        ; draw the background color.
@@:
        dec     ecx
        jz      exit


tskip_1_fg:
        lea     edi,[edi+2]
        shl     al,1
        jc      @f
        mov     [edi],bx        ; draw the background color.
@@:
        dec     ecx
        jz      exit


tskip_2_fg:
        lea     edi,[edi+2]
        shl     al,1
        jc      @f
        mov     [edi],bx        ; draw the background color.
@@:
        dec     ecx
        jz      exit


tskip_3_fg:
        lea     edi,[edi+2]
        shl     al,1
        jc      @f
        mov     [edi],bx        ; draw the background color.
@@:
        dec     ecx
        jz      exit


tskip_4_fg:
        lea     edi,[edi+2]
        shl     al,1
        jc      @f
        mov     [edi],bx        ; draw the background color.
@@:
        dec     ecx
        jz      exit


tskip_5_fg:
        lea     edi,[edi+2]
        shl     al,1
        jc      @f
        mov     [edi],bx        ; draw the background color.
@@:
        dec     ecx
        jz      exit


tskip_6_fg:
        lea     edi,[edi+2]
        shl     al,1
        jc      @f
        mov     [edi],bx        ; draw the background color.
@@:
        dec     ecx
        jz      exit


tskip_7_fg:
        lea     edi,[edi+2]
        shl     al,1
        jc      @f
        mov     [edi],bx        ; draw the background color.
@@:
        dec     ecx
        jz      exit3
        inc     esi
        lea     edi,[edi+2]
        jmp     start_byte_trans_fg

exit3:

        pop     ebx
        pop     edi
        pop     esi

        ret
END_PROC        vngo_ilinemono16

if 0
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

endif

_text   ends
        end

;°±² End of module - vngitrns.asm ²±°
