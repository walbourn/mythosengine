;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
;                oooooooooo.                                 
;                `888'   `Y8b                                
;                 888     888  .ooooo.    oooooooo  .ooooo.  
;                 888oooo888' d88' `88b  d'""7d8P  d88' `88b 
;                 888    `88b 888   888    .d8P'   888   888 
;                 888    .88P 888   888  .d8P'  .P 888   888 
;                o888bood8P'  `Y8bod8P' d8888888P  `Y8bod8P' 
;                           _                       
;                          /_\     |    _  _ | _ ._ 
;                         /   \  \_||_|(_|(_||(/_|  
;                                       _| _|       
;                     Microsoft Windows 95/98/NT Version
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
; BzJump
;
;      These are special versions of the setjmp() and longjmp() routines
; that only save the part of the context absolutely required by the
; Watcom compiler.  In this case, since we're non-preemptive, and only
; operate in FLAT model, they are: eip, esp, ebp, esi, edi, ebx
;
;       In this implemenation, we don't actually save eip, we save the
; return address of the bz_setjmp() call.  As it turns out, we can't
; rely on the stack to save that value, because everything from the
; return address "up" can be clobbered by the calling routine.
; However, we are guaranteed by the semantics of the setjmp() paradigm
; that values below this line are preserved.  So, we just save the
; return address, and place it back on the stack before the context
; switch.  I suppose I could save esp-4 and push the value back on,
; but I don't think there would be any performance advantage.
;
;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

.486p

;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
;
;                                Includes
;                                
;°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

include macros.inc


;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
;
;                                 Code
;
;±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

_text   segment public PARA USE32 'CODE'

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
;   Emulates the setjmp() function.                                        ³
;       This only saves the registers that Watcom expects to be            ³
;       preserved accross a call.  The segment registers are not saved,    ³
;       which saves alot of time, but means we're stuck with flat model.   ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

START_PROC      bz_setjmp

        ;;;     Get the buffer address
        mov     eax,DWORD PTR[esp+4]

        ;;;     Save the return address (and allow eax to get updated)
        mov     ecx,[esp]

        ;;;     Now, save the registers
        mov     [eax+0],esi
        mov     [eax+4],edi
        mov     [eax+8],ebx
        mov     [eax+12],ebp
        mov     [eax+16],esp

        ;;;     save the return address previously fetched
        mov     [eax+20],ecx

        ;;;     Now, return the expected zero result
        xor     eax,eax
        ret

END_PROC        bz_setjmp

;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
;   bz_longjmp (dword *buffer)                                             ³
;   Emulates the longjmp() function.                                       ³
;       Restore the registers saved by bz_setjmp().                        ³
;       In this case, we need to restore the return address as well,       ³
;       since it is often clobbered by the task switch procedure.          ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

START_PROC      bz_longjmp

        mov     ecx,DWORD PTR[esp+4]
        assume  ecx:PTR DWORD

        ;;;     Restore the register contexts
        mov     esi,[ecx+0]
        mov     edi,[ecx+4]
        mov     ebx,[ecx+8]
        mov     ebp,[ecx+12]
        mov     esp,[ecx+16]

        ;;;     Restore the correct return address
        mov     eax,[ecx+20]
        mov     [esp],eax

        ;;;     Now that the stack is restored, we can return to the
        ;;;     old return address (saved already on the stack)
        mov     eax,1
        ret

END_PROC        bz_longjmp



;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
;   bz_stackthunk (void *func, void *parm)                                 ³
;   Call the function pointed to by param 1 with parm 2 loaded as          ³
;   a register-calling convention parameter.                               ³
;   This is used to permit register calling convention functions to        ³
;   work in the Bozo initialization system.  See bzartn.c for details.     ³
;ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
START_PROC      bz_stackthunk
        pop     edx             ;get the return address
        pop     ecx             ;get the function pointer
        pop     eax             ;get parameter into the appropriate register
        push    edx             ;put the return address back on!
        jmp     ecx             ;leap into the routine!
END_PROC        bz_stackthunk

_text   ends
        end

;°±² End of module - bzjump.asm ²±°
