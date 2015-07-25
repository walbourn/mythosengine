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
;            Copyright (c) 1995-1998 by Charybdis Enterprises, Inc.
;                           All Rights Reserved.
;
;                     Microsoft Windows 95/NT Version
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

