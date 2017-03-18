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
; vngITRNS.ASM 
;
;      This module transfers a rectangular bitmap image from raw data to a
;      vngo_vbuffer.
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
; vngo_zlinemono16 (word *lptr, byte *tptr, long xcount,                   ³
;                   dword tskip, dword fdist, dword ndist);                ³
;       This is used for the Z-Map support in the Z-Buffered viewports.    ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      vngo_zlinemono16,       C lptr:DWORD,tptr:DWORD,xcount:DWORD,bit_off:DWORD,fdist:DWORD,ndist:DWORD

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

;; This does the monochrome expansion with forground and background expansion!
;; First expand the bottom bits of the first byte of data.
transfer_start:
        mov     eax,fdist
        mov     ebx,ndist
        shl     ebx,16          ; the upper word is the near dist.
        mov     bx,ax           ; the lower word is the far dist..
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
        mov     [edi],bx        ; set the distance to far.
        jmp     short t2
t1:
        rol     ebx,16
        mov     [edi],bx        ; set the distance to near.
        rol     ebx,16
t2:
        dec     ecx
        jz      exit

skip_1:
        lea     edi,[edi+2]
        shl     al,1
        jnc     t12
        mov     [edi],bx        ; set the distance to far.
        jmp     short t22
t12:
        rol     ebx,16
        mov     [edi],bx        ; set the distance to near.
        rol     ebx,16
t22:
        dec     ecx
        jz      exit

skip_2:
        lea     edi,[edi+2]
        shl     al,1
        jnc     t13
        mov     [edi],bx        ; set the distance to far.
        jmp     short t23
t13:
        rol     ebx,16
        mov     [edi],bx        ; set the distance to near.
        rol     ebx,16
t23:
        dec     ecx
        jz      exit

skip_3:
        lea     edi,[edi+2]
        shl     al,1
        jnc     t14
        mov     [edi],bx        ; set the distance to far.
        jmp     short t24
t14:
        rol     ebx,16
        mov     [edi],bx        ; set the distance to near.
        rol     ebx,16
t24:
        dec     ecx
        jz      exit

skip_4:
        lea     edi,[edi+2]
        shl     al,1
        jnc     t15
        mov     [edi],bx        ; set the distance to far.
        jmp     short t25
t15:
        rol     ebx,16
        mov     [edi],bx        ; set the distance to near.
        rol     ebx,16
t25:                    
        dec     ecx
        jz      exit

skip_5:
        lea     edi,[edi+2]
        shl     al,1
        jnc     t16
        mov     [edi],bx        ; set the distance to far.
        jmp     short t26
t16:
        rol     ebx,16
        mov     [edi],bx        ; set the distance to near.
        rol     ebx,16
t26:
        dec     ecx
        jz      exit

skip_6:
        lea     edi,[edi+2]
        shl     al,1
        jnc     t17
        mov     [edi],bx        ; set the distance to far.
        jmp     short t27
t17:
        rol     ebx,16
        mov     [edi],bx        ; set the distance to near.
        rol     ebx,16
t27:
        dec     ecx
        jz      exit

skip_7:
        lea     edi,[edi+2]
        shl     al,1
        jnc     t18
        mov     [edi],bx        ; set the distance to far.
        jmp     short t28
t18:
        rol     ebx,16
        mov     [edi],bx        ; set the distance to near.
        rol     ebx,16
t28:
        dec     ecx
        jz      exit
        inc     esi
        lea     edi,[edi+2]
        jmp     start_byte
exit:
        pop     ebx
        pop     edi
        pop     esi

        ret
END_PROC        vngo_zlinemono16


_text   ends
        end

;°±² End of module - vngitrns.asm ²±°
