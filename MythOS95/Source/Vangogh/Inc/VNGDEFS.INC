;อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
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
;ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
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
;ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
;
;                        http://www.mythos-engine.org/
;
;ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
;
; Created by Tim Little
;
; vngdefs.inc
;
;อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

ifndef __VNGDEFS_INC
__VNGDEFS_INC EQU 1

;ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
;
;                                Equates
;
;ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

VNGO_PERSP_PRECISION    EQU     128

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

; VngoTexture flags.
VNGO_TEXTURE_MONO       EQU     01h
VNGO_TEXTURE_1BIT       EQU     01h
VNGO_TEXTURE_2BIT       EQU     02h
VNGO_TEXTURE_4BIT       EQU     04h
VNGO_TEXTURE_8BIT       EQU     08h
VNGO_TEXTURE_15BIT      EQU     010h
VNGO_TEXTURE_16BIT      EQU     020h
VNGO_TEXTURE_24BIT      EQU     040h
VNGO_TEXTURE_32BIT      EQU     080h
; Just in case....:)
VNGO_TEXTURE_SHADOWS    EQU     0100h
VNGO_TEXTURE_ALPHA      EQU     0200h
VNGO_TEXTURE_ZMAP       EQU     0400h
VNGO_TEXTURE_SHADE      EQU 0800h

;ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
;
;                                Macros
;
;ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

endif          ; __VNGDEFS_INC

;ฐฑฒ End of module - vngdefs.inc ฒฑฐ
