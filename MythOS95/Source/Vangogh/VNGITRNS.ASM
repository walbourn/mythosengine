;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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
; vngITRNS.ASM 
;
;      This module transfers a rectangular bitmap image from raw data to a
;      vngo_vbuffer.
;
;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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
START_PROC      vngo_iline8,    C lptr:DWORD,tptr:DWORD,xcount:DWORD,flags:DWORD

        push    esi
        push    edi
        mov     esi,tptr
        mov     edi,lptr
        mov     ecx,xcount

        cmp     flags,VNGO_TRANSPARENT
        je      clear_transfer_loop

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
        je      clear_transfer_loop_start


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
        jmp     start_byte
exit:
        jmp     exit2

;; This does the monochrome expansion with transparency!
;; First expand the bottom bits of the first byte of data.
clear_transfer_loop_start:
        mov     ebx,fgcol
        mov     eax,bgcol
        shl     ebx,8           ; bh is the forground color.
        mov     bl,al           ; bl is the background color.
start_byte_trans:
        mov     al,[esi]
        cmp     bit_off,0
        je      tskip_0
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
        jz      tskip_1
        dec     edx
        jz      tskip_2
        dec     edx
        jz      tskip_3
        dec     edx
        jz      tskip_4
        dec     edx
        jz      tskip_5
        dec     edx
        jz      tskip_6
        dec     edx
        jz      tskip_7

tskip_0:
        shl     al,1
        jnc     @f
        mov     [edi],bh        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_1:
        inc     edi
        shl     al,1
        jnc     @f
        mov     [edi],bh        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_2:
        inc     edi
        shl     al,1
        jnc     @f
        mov     [edi],bh        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_3:
        inc     edi
        shl     al,1
        jnc     @f
        mov     [edi],bh        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_4:
        inc     edi
        shl     al,1
        jnc     @f
        mov     [edi],bh        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_5:
        inc     edi
        shl     al,1
        jnc     @f
        mov     [edi],bh        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_6:
        inc     edi
        shl     al,1
        jnc     @f
        mov     [edi],bh        ; draw the forground color.
@@:
        dec     ecx
        jz      exit


tskip_7:
        inc     edi
        shl     al,1
        jnc     @f
        mov     [edi],bh        ; draw the forground color.
@@:
        dec     ecx
        jz      exit
        inc     esi
        inc     edi
        jmp     start_byte_trans

exit2:
        pop     ebx
        pop     edi
        pop     esi

        ret
END_PROC        vngo_ilinemono8
                

START_PROC      vngo_itrans8,   C CurScreen:DWORD, dest:DWORD, img:DWORD, flags:DWORD

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

        mov     ebx,img
        mov     edx,(VNGO_VBUFFER PTR [esi]).vb_width
        sub     dx,WORD PTR (VNGO_TEXTURE PTR [ebx]).tx_width
        jl      BigTexture

        mov     esi,(VNGO_TEXTURE PTR [ebx]).tex
        movzx   eax,(VNGO_TEXTURE PTR [ebx]).tx_width
        movzx   ebx,(VNGO_TEXTURE PTR [ebx]).tx_height
        or      ebx,ebx
        jz      exit
        cmp     flags,VNGO_TRANSPARENT
        je      clear_transfer_loop_begin

transfer_loop:
        mov     ecx,eax
        shr     ecx,1
    rep movsw
        jnc     @f
        movsb
@@:
        add     edi,edx
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
        dec     ebx
        jnz     SHORT clear_transfer_loop

BigTexture:
exit:
        pop     edi
        pop     esi
        pop     ebx
        ret
END_PROC        vngo_itrans8



START_PROC     vngo_Xitrans8,  C CurScreen:DWORD, dest:DWORD, img:DWORD, flags:DWORD
        LOCAL    CURX
        LOCAL    CURY
        LOCAL    W

        push    esi
        push    edi
        push    ebx

        mov     CURX,0
        mov     CURY,0
;        mov     ebx,dest
;        mov     eax,(VNGO_RECT PTR [ebx]).rect_x
;        mov     CURX,eax
;        mov     eax,(VNGO_RECT PTR [ebx]).rect_y
;        mov     CURY,eax

        mov     ebx,img
        mov     esi,(VNGO_TEXTURE PTR [ebx]).tex
        movzx   eax,(VNGO_TEXTURE PTR [ebx]).tx_width
        movzx   ebx,(VNGO_TEXTURE PTR [ebx]).tx_height
        or      ebx,ebx
        jz      exit
        mov     W,eax
       
outside_loop:
        mov     eax,W
inside_loop:
        mov     cl,[esi]
        movzx   ecx,cl
        push    ecx
        push    CURY
        push    CURX

        call    setpixel
        add     esp,(3 * 4)
        inc     esi
        inc     CURX
        dec     eax
        jnz     inside_loop
        inc     CURY
        dec     ebx
        jnz     outside_loop


exit:
        pop     ebx
        pop     edi
        pop     esi
        ret
END_PROC        vngo_Xitrans8
                

START_PROC setpixel, C, x:DWORD, y:DWORD, color:DWORD
        push    ecx
        push    eax
        push    edx
        push    edi

        mov     eax,80
			        ;there are 4 pixels at each address, so
			        ; each 320-pixel row is 80 bytes wide
			        ; in each plane
	mul	y               ;point to start of desired row
        
        mov     ecx,x
        mov     edi,ecx

        shr     edi,2
        add     edi,eax
        add     edi,0a0000h

	and	cl,3	        ;get the plane # of the pixel
	mov	ah,1
	shl	ah,cl	        ;set the bit corresponding to the plane
			        ; the pixel is in
	mov	al,MAP_MASK
	mov	dx,SC_INDEX
        out     dx,ax
	                        ;set to write to the proper plane for
			        ; the pixel
        mov     ecx,color
        mov     [edi],cl

        pop     edi
        pop     edx
        pop     eax
        pop     ecx
	ret

END_PROC setpixel

_text   ends
        end

;°±² End of module - vngitrns.asm ²±°
