;อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
;                                   ____
;                                  / __ \
;                                 ( (__) )
;                                 _\____/___
;                                /  |  |   /\
;                               /_________/  \_
;                              /          \    \
;                             /            \    \_
;                            /              \     \
;                           /                \     \_
;                          /                  \      \
;                         /                    \      \_
;                        /                      \       \
;                       /                        \       \_
;                      /                          \        \
;                     /                            \        \_
;                    /                              \         \
;                   / N  N EEE W   W TTTTT  OO  N  N \        /
;                  /  NN N E_  W   W   T   O  O NN N  \      /
;                 /   N NN E   W W W   T   O  O N NN   \    /
;                /    N  N EEE  W W    T    OO  N  N    \  /
;               /________________________________________\/
;
;                     Newtonian Physics Simulation Library
;
;                      Microsoft Windows 95/98/NT Version
;
;  Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
; Creatd by Dan Higdon
;
; newtmath.inc
;
; Newton math support header.
;
;อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

;ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
;
;                               Structures
;
;ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

;ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ
; NewtVector - 3D i,j,k vector.                                            ณ
;ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤู
NEWT_VECTOR    STRUCT
nv_i           dd ?    ; I component of the vector.
nv_j           dd ?    ; J component of the vector.
nv_k           dd ?    ; K component of the vector.
nv_flags       dd ?    ; flag dword in vector.
NEWT_VECTOR    ENDS

;ฐฑฒ End of header - newtmath.inc ฒฑฐ

