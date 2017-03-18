;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
;
;        °°°°°°°°°°°°°°°°°°°°°°
;         °°                °°
;          °°              °°
;           °°        ÚÄÄÄÄÄ  ³   ³ ÚÄÄÄ¿ ÚÄÄÄ¿ ³   ³ ÚÄÄÄ¿  ÚÄÄÄ¿
;            °°       ³  °°   ³   ³ ³   ³ ³   ³ ³   ³ ³   ³  ³
;             °°±± ± ²³±°°    ³   ³ ³   ³ ³   ³ ³\  ³ ³   ³  ³
;              °°² ²±±³°°     ÃÄÄÄ´ ÃÄÄÄÙ ³   ³ ³\\ ³ ³   ³  ÀÄÄÄ¿
;               °°±±² ³°      ³   ³ ³\    ³   ³ ³ \\³ ³   ³      ³
;               °°    ³°      ³   ³ ³ \   ³   ³ ³  \³ ³   ³      ³
;              °° ° ° ÀÄÄÄÄÄ  ³   ³ ³  \  ÀÄÄÄÙ ³   ³ ÀÄÄÄÙ  ÀÄÄÄÙ
;             °°   ± °  °°
;            °° ±°±°°°±  °°
;           °° ±±°°²±±°°±°°°            Timer Library
;          °°±±±²±²²²±±²±²±°°
;         °°²²²²²²²²²²²²²²²²°°
;        °°°°°°°°°°°°°°°°°°°°°°
;
;                    Microsoft Windows 95/98/NT Version
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
; Created by Dan Higdon
;
; chrrdtsc.asm
;
;     This file contains the chronos_rdtsc routine
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

;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
;
;                                 Data
;
;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

       ASSUME  ds:_DATA
_DATA  SEGMENT PARA PUBLIC USE32 'DATA'
_DATA  ENDS

;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
;
;                                 Code
;
;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

EXTRN   __fltused:NEAR

_TEXT  SEGMENT PARA PUBLIC USE32 'CODE'
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
; chronos_rdtsc();                                                         ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      chronos_rdtsc, C
        sub     esp,0000008H
        db      0fH, 31H
        mov     dword ptr [esp+0],eax
        mov     dword ptr [esp+4],edx
        fild    qword ptr [esp+0]
        add     esp,000000008H
        ret
END_PROC        chronos_rdtsc

_text   ends
        end

;°±² End of module - chrrdtsc.asm ²±°
