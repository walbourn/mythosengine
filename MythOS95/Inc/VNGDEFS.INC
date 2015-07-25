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
; vngdefs.inc
;
;อออออออออออออออออออออออออออออ Revision History ออออออออออออออออออออออออออออ
;อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
ifndef __VNGDEFS_INC
__VNGDEFS_INC EQU 1


;ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
;
;                                Includes
;                                
;ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

;ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
;
;                                Equates
;
;ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

VNGO_PHYSICAL_DEV       EQU     01h
VNGO_PAL_MAPPED_DEV     EQU     02h
VNGO_ZBUFFER_DEV        EQU     04h
VNGO_ZBUFFER_ACTIVE     EQU     08h
VNGO_INIT_NO_RESET      EQU     010h
VNGO_NOCLEAR_VBUFFER    EQU     020h
VNGO_BACKBUFFER         EQU     040h

                                
VNGO_MAX_FACE_PTCT      EQU     4
VNGO_MAX_POLYG_PTCT     EQU     VNGO_MAX_FACE_PTCT * 2 +1

;; Image transfer flags.
VNGO_TRANSPARENT        EQU     0ff000000h
VNGO_TRANSPARENT_COLOR  EQU     0ffh

VNGO_M1_X_PAGING        EQU     01h
VNGO_M2_X_PAGING        EQU     02h
VNGO_M3_X_PAGING        EQU     04h
VNGO_M4_X_PAGING        EQU     08h

VNGO_X_320x200          EQU     01
VNGO_X_320x240          EQU     02
VNGO_X_320x400          EQU     03
VNGO_X_320x480          EQU     04
VNGO_X_360x480          EQU     05
VNGO_X_640x400          EQU     06


; Hardware equates
SC_INDEX                EQU     3c4h    ;Sequence Controller Index register
GC_INDEX                EQU     3ceh    ;Graphics Controller Index register
CRTC_INDEX              EQU     3d4h    ;CRT Controller Index register
MAP_MASK                EQU     2       ;Map Mask register index in SC
MEMORY_MODE             EQU     4       ;Memory Mode register index in SC
MAX_SCAN_LINE           EQU     9       ;Maximum Scan Line reg index in CRTC
START_ADDRESS_HIGH      EQU     0ch     ;Start Address High reg index in CRTC
UNDERLINE               EQU     14h     ;Underline Location reg index in CRTC
MODE_CONTROL            EQU     17h     ;Mode Control register index in CRTC
GRAPHICS_MODE           EQU     5       ;Graphics Mode register index in GC
MISCELLANEOUS           EQU     6       ;Miscellaneous register index in GC


;ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
;
;                                Macros
;
;ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

;ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
;
;                               Structures
;
;ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ


endif          ; __VNGDEFS_INC

;ฐฑฒ End of module - vngdefs.inc ฒฑฐ
