;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
;
;                                                           %__________%
;                                                          %/ . .  .   \%
;           Van Gogh 2D-Display Library                     |  . .  o. | 
;                                                           |. _  .   .|
;          Microsoft Windows '95 Version                    | / \   .  | 
;                                                           |_|_|_._._.|
;  Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.   |.-.-.-.-..|
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
; Contains the general structure definitions
;
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
; VNGO_POINT2 is an internal version of VNGO_POINT                         ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VNGO_POINT2     STRUCT
pt_x            dd ?            ; 2D X value
pt_y            dd ?            ; 2D Y value
pt_z            dd ?            ; Scaled Z value for z-buffering.
pt_clr          dd ?            ; Base color of the point.
pt_shade        dd ?            ; The shading percentage of the base color.
pt_u            dd ?            ; Texture map U coordiante.
pt_v            dd ?            ; Texture map V coordinate.
pt_w            dd ?            ; Texture map W (used for perspective.)
VNGO_POINT2     ENDS


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; VNGO_TRIANGLE is an internal structure.                                  ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VNGO_TRIANGLE   STRUCT

long_top        dd ?            ; VNGO_POINT ptr
long_bottom     dd ?            ; VNGO_POINT ptr
short_top       dd ?            ; VNGO_POINT ptr
short_bottom    dd ?            ; VNGO_POINT ptr
hline_bptr      dd ?            ; byte ptr
hline_zptr      dd ?            ; word ptr
stable_ptr      dd ?            ; byte ptr

; Horizontal line info.
x_dir           dd ?            ; long
z_step          dd ?            ; long
shade_step      dd ?            ; long
u_step1         dd ?            ; long
u_step2         dd ?            ; long
v_step1         dd ?            ; long
v_step2         dd ?            ; long

; Texture information
u_upshift       dd ?            ; long
u_downshift     dd ?            ; long
v_upshift       dd ?            ; long
v_downshift     dd ?            ; long
widthshift      dd ?            ; long

; Long edge info.
long_x          dd ?            ; long
long_x_step     dd ?            ; long
long_z          dd ?            ; long
long_z_step     dd ?            ; long
long_s          dd ?            ; long
long_s_step     dd ?            ; long
long_u          dd ?            ; long
long_u_step1    dd ?            ; long
long_u_step2    dd ?            ; long
long_v          dd ?            ; long
long_v_step1    dd ?            ; long
long_v_step2    dd ?            ; long
long_w          dd ?            ; long
long_w_step     dd ?            ; long

; Short edge info.
short_x         dd ?            ; long
short_x_step    dd ?            ; long
short_u         dd ?            ; long
short_u_step1   dd ?            ; long
short_u_step2   dd ?            ; long
short_v         dd ?            ; long
short_v_step1   dd ?            ; long
short_v_step2   dd ?            ; long
short_w         dd ?            ; long
short_w_step    dd ?            ; long             

VNGO_TRIANGLE   ENDS            


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; VNGO_VBUFFER is a view port structure which contains all of the info     ³
; needed to draw into the view port.                                       ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VNGO_VBUFFER    STRUCT
vb_width        dd ?            ; width of actual buffer.
vb_height       dd ?            ; height of the actual buffer.
vb_pal          dd ?            ; pointer to the alternate LUT for this mode.

vb_scrn_ptr     dd ?            ; view buffer pointer.
vb_pitch        dd ?            ; screen pitch.
vb_ytable       dd ?            ; pointer to the table of pre-calculated y offsets.

vb_zbuff_ptr    dd ?            ; pointer to the zbuffer if it exist.
vb_zpitch       dd ?            ; zbuffer pitch.
vb_ztable       dd ?            ; y table for the zbuffer.   

vb_edge1	dd ?		; Edge arrays for the scan converters to use.  
vb_edge2	dd ?		; Edge arrays for the scan converters to use.  

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


;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; VNGO_TEXTURE is the texture structure                                    ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VNGO_TEXTURE    STRUCT
tx_width        dw ?
tx_height       dw ?
tex             dd ?
flags           dd ?
tex3d           dd ?
VNGO_TEXTURE    ENDS

endif          ; __VNGSTRCT_INC

;°±² End of module - vngstrct.inc ²±°

