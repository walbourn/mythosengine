;ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ
;ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
;שששששששששש°°°°°°°°°°ש°°°°°°°°ששש°°°°°°°°שש°°°שששש°°°ש°°°°°°°°°°ש°°°°°°°°°שש
;ששששששששש°±°ששששששש°±°שששש°±°ש°±°שששש°±°ש°±°שששש°±°ש°±°שששששששש°±°שששש°±°שש
;שששששששש±°±ששששששש±°±שששששששש±°±שששששששש±°±שששש±°±ש±°±שששששששש±°±שששש±°±ששש
;ששששששש±²±±°±±²שש±²±±°±±²±±ש±²±שששששששש±²±±°±±²±±ש±²±±°±±²ששש±²±±°±±²°ששששש
;שששששש±²±שששששששששששששש±²±ש±²±שששששששש±²±שששש±²±ש±²±שששששששש±²±שששש±²±ששששש
;ששששש²±²ששששששש²±²שששש²±²ש²±²שששש²±²ש²±²שששש²±²ש²±²שששששששש²±²שששש²±²שששששש
;שששש²²²²²²²²²²ש²²²²²²²²ששש²²²²²²²²שש²²²שששש²²²ש²²²²²²²²²²ש²²²שששש²²²ששששששש
;ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
;שששששששששששCopyrightש(c)ש1994-1997שbyשCharybdisשEnterprises,שInc.שששששששששש
;ששששששששששששששששששששששששששAllשRightsשReserved.ששששששששששששששששששששששששששששש
;ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
;ששששששששששששששששששששש Microsoft Windows '95 Version ששששששששששששששששששששששש
;ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
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
;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
;
; Created by Tim Little & Chuck Walbourn
;
; esmath.inc
;
;     Contains assembly structures for the various 'math' classes.
;
;ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
;
;                               Structures
;
;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
; EschPoint - 3D point (needs to match first four members of VngoPoint).   ³
;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
ESCH_POINT     STRUCT
ep_x           dd ?    ; X position of the point.
ep_y           dd ?    ; Y position of the point.
ep_z           dd ?    ; Z position of the point.
ep_color       dd ?    ; color of the point.
ESCH_POINT     ENDS

;Note:  ESCH_POINT & ESCH_VECTOR are assumed to be 'identical' in terms of
;       their first three data points for the various math operations.

;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
; EschVector - 3D i,j,k vector.                                              ³
;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
ESCH_VECTOR    STRUCT
ev_i           dd ?    ; I component of the vector.
ev_j           dd ?    ; J component of the vector.
ev_k           dd ?    ; K component of the vector.
               dd ?    ; filler to make it 16 bytes.
ESCH_VECTOR    ENDS

;Note:  ESCH_POINT & ESCH_VECTOR are assumed to be 'identical' in terms of
;       their first three data points for the various math operations.

;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
; EschVertex - A 3D point and a normal at the point.                         ³
;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
ESCH_VERTEX    STRUCT
evr_x          dd ?    ; X position of the vertex.
evr_y          dd ?    ; Y position of the vertex.
evr_z          dd ?    ; Z position of the vertex.
evr_color      dd ?    ; color of the  vertex..
evr_i          dd ?    ; I component of the normal @ vertex.
evr_j          dd ?    ; J component of the normal @ vertex.
evr_k          dd ?    ; K component of the normal @ vertex.
               dd ?    ; filler to make it 32 bytes.
ESCH_VERTEX    ENDS

;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
; EschMatrix - A matrix is a 3x4 homogenous matrix (column-major).           ³
;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ

; [A B C 0]
; [D E F 0]
; [G H I 0]
; [J K L 1]

ESCH_MATRIX    STRUCT
mtx_a         dd ?
mtx_b         dd ?
mtx_c         dd ?
mtx_d         dd ?
mtx_e         dd ?
mtx_f         dd ?
mtx_g         dd ?
mtx_h         dd ?
mtx_i         dd ?
mtx_j         dd ?
mtx_k         dd ?
mtx_l         dd ?
ESCH_MATRIX    ENDS

;Note:  ESCH_MATRIX & ESCH_FOFREF are assumed to be idential in terms
;       of the first 12 data points for the various matrix operations.

;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
; EschFrameRef - Frame of reference                                          ³
;ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
; [A B C 0]
; [D E F 0]
; [G H I 0]
; [J K L 1]
;
; [di dj dk];

ESCH_FOFREF    STRUCT
for_a         dd ?
for_b         dd ?
for_c         dd ?
for_d         dd ?
for_e         dd ?
for_f         dd ?
for_g         dd ?
for_h         dd ?
for_i         dd ?
for_j         dd ?
for_k         dd ?
for_l         dd ?
for_di        dd ? 
for_dj        dd ? 
for_dk        dd ? 
              dd ?    ; filler
ESCH_FOFREF    ENDS

;°±² End of module - esmath.inc ²±°
