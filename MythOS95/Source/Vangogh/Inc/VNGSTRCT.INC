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
; vngstrct.inc
;
;      This is the definition of the VNGO_VBUFFER.
;
;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Revision History ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
ifndef __VNGSTRCT_INC
__VNGSTRCT_INC EQU 1


;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
;
;                                Includes
;                                
;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

include vngdefs.inc

;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
;
;                                Equates
;
;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
;
;                                Macros
;
;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
;
;                               Structures
;
;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; VNGO_RECT is a 2D filled rectangle, which has its uper left hand corner  ³
; defined by the point (x,y), it's width in dx, and it's height in dy.     ³
; This structure is intentionaly 16 BYTES long.                            ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VNGO_RECT       STRUCT
rect_x          dd ? 
rect_y          dd ? 
rect_dx         dd ? 
rect_dy         dd ?    
VNGO_RECT       ENDS
                
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; VNGO_POINT is a 2D draw point, it contains all of the needed information ³
; needed to draw into the view port for most drawing types.                ³
; This structure is intentionaly 32 BYTES long.                            ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
                
VNGO_POINT      STRUCT
pt_wx           dd ?            ; 3D X value
pt_wy           dd ?            ; 3D Y value
pt_wz           dd ?            ; 3D Z value for z-buffering (in eye frame).
pt_x            dd ?            ; 2D X value
pt_y            dd ?            ; 2D Y value
pt_z            dd ?            ; Scaled Z value for z-buffering.
pt_clr          dd ?            ; Base color of the point.
pt_shade        dd ?            ; The shading percentage of the base color.
pt_u            dd ?            ; Texture map U coordiante.
pt_v            dd ?            ; Texture map V coordinate.
pt_w            dd ?            ; Texture map W (used for perspective.)
pt_pflags       dd ?            ; flags.
VNGO_POINT      ENDS





;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; VNGO_VBUFFER is a view port structure which contains all of the info     ³
; needed to draw into the view port.                                       ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
                
VNGO_VBUFFER    STRUCT
vb_width        dd ?            ; width of actual buffer.
vb_height       dd ?            ; height of the actual buffer.
vb_left         dd ?            ; left edge of buffer's clipping window.
vb_top          dd ?            ; top edge of buffer's clipping window.
vb_scrn_ptr     dd ?            ; view buffer pointer.
vb_pal          dd ?            ; pointer to the alternate LUT for this mode.
vb_ytable       dd ?            ; pointer to the table of pre-calculated y offsets.
vb_invert       dd ?            ; table of 1/max(xres,yres) values to save divides.
vb_zbuff_ptr    dd ?            ; pointer to the zbuffer if it exist.
vb_na           dd ?            ; na.
VNGO_VBUFFER    ENDS            


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; the lower 24bits of this are the RGB triple in x:8:8:8 format.           ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

VNGO_RGB_COLOR  STRUCT
r               db ?
g               db ?
b               db ?
flags           db ?
VNGO_RGB_COLOR  ENDS

VNGO_TEXTURE    STRUCT
tx_width        dw ?
tx_height       dw ?
tex             dd ?
VNGO_TEXTURE    ENDS



;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; The folowing section is the block of data structures defined for use     ³
; with the VESA compatible modes.                                          ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

VgaInfoBlock    STRUCT
VESASignature   db      'VESA'          ;4 signature bytes.  Should be 'VESA'
VESAVersion     dw      ?               ;VESA version number.
OEMStringPtr    dd      ?               ;Pointer to OEM string.
Capabilities    db      4 dup (?)       ;capabilities of the video environment.
VideoModePtr    dd      ?               ;pointer to supported Super VGA modes.
TotalMemory     dw      ?               ;Number of 64kb memory blocks on board.
Reserved        db      236 dup (?)     ;Remainder of VgaInfoBlock.
VgaInfoBlock    ENDS
                        
ModeInfoBlock   STRUCT
ModeAttributes          dw      ?
WinAAttributes          db      ?
WinBAttributes          db      ?
WinGranularity          dw      ?
WinSize                 dw      ?
WinASegment             dw      ?
WinBSegment             dw      ?
WinFuncPtr              dd      ?
BytesPerScanLine        dw      ?
;
XResolution             dw      ?
YResolution             dw      ?
XCharSize               db      ?
YCharSize               db      ?
NumberOfPlanes          db      ?
BitsPerPixel            db      ?
NumberOfBanks           db      ?
MemoryModel             db      ?
BankSize                db      ?
NumberOfImagePages      db      ?
Reserved1               db      ?
;
RedMaskSize             db      ?
RedFieldPosition        db      ?
GreenMaskSize           db      ?
GreenFieldPosition      db      ?
BlueMaskSize            db      ?
BlueFieldPosition       db      ?
RsvdMaskSize            db      ?
RsvdFieldPosition       db      ?
DirectColorModeInfo     db      ?
;
Reserved                db      216 dup (?)
ModeInfoBlock   ENDS

RM_call_struct  STRUCT
RMI_edi         dd      ?
RMI_esi         dd      ?
RMI_ebp         dd      ?
RMI_reserved    dd      ?
RMI_ebx         dd      ?
RMI_edx         dd      ?
RMI_ecx         dd      ?
RMI_eax         dd      ?
RMI_flags       dw      ?
RMI_es          dw      ?
RMI_ds          dw      ?
RMI_fs          dw      ?
RMI_gs          dw      ?
RMI_ip          dw      ?
RMI_cs          dw      ?
RMI_sp          dw      ?
RMI_ss          dw      ?

RM_call_struct  ENDS


endif          ; __VNGSTRCT_INC

;°±² End of module - vngstrct.inc ²±°

