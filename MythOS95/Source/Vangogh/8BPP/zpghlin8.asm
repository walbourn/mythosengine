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
; zpghlinn8.ASM 
;
;      This module draws filled rectangles in all of their permutations.
;
;ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

.486P

.model FLAT

;PUBLIC  _draw_zpghlines
;PUBLIC  _draw_zpghlines_256x256_ntrans
;PUBLIC  _draw_zpghlines_128x128_ntrans
EXTRN   _calc_order:NEAR
EXTRN   __fltused:NEAR

EXTRN   _vngo_calc_quadratic2:NEAR
EXTRN   ?DitherMatrix@@3PAY03JA:BYTE                    ; DitherMatrix

_TEXT   SEGMENT
_tri$ = 8
_stable$ = -20
_count$ = -48
_pitch$ = -8
_zpitch$ = -4
_sstep_dx1$ = -12
_zstep_dx1$ = -16
_ustep_dx1$ = -104
_ustep_dx2$ = -76
o_vstep_dx1$ = -100
_vstep_dx2$ = -72
_scrn$ = -64
_zbuff$ = -60
_edge1$ = -112
_edge2$ = -108
_uup$ = -56
_vup$ = -52
_udown$ = -32
_vdown$ = -40
_start_y$ = -44
_tptr$ = -28
_mask$ = -36
_y$ = -96
_tz$23913 = -88
_ts$23914 = -84
_tv$23916 = -80
_ptr$23918 = -92
_dmatrix$23920 = -24
_dx$23921 = -68

if 0

_draw_zpghlines PROC NEAR
; Line 291
        mov     edx, DWORD PTR _tri$[esp-4]
        sub     esp, 112                                ; 00000070H
        push    ebx
        mov     eax, DWORD PTR [edx+8]
        push    esi
        push    edi
        push    ebp
        mov     ecx, DWORD PTR [eax+8]
; Line 292
        xor     esi, esi
        mov     eax, DWORD PTR [ecx+4]
; Line 294
        mov     cl, BYTE PTR [eax+4]
        mov     ebx, DWORD PTR [eax+16]
        shl     esi, cl
        add     esi, ebx
        mov     eax, DWORD PTR [edx+28]
        mov     ecx, DWORD PTR [edx+44]
        mov     DWORD PTR _stable$[esp+128], esi
; Line 296
        mov     DWORD PTR _count$[esp+128], eax
        mov     DWORD PTR _pitch$[esp+128], ecx
; Line 298
        mov     eax, DWORD PTR [edx+48]
        mov     ecx, DWORD PTR [edx+56]
        sar     eax, 1
        mov     ebx, DWORD PTR [edx+72]
        mov     DWORD PTR _zpitch$[esp+128], eax
        mov     DWORD PTR _sstep_dx1$[esp+128], ecx
; Line 301
        mov     eax, DWORD PTR [edx+88]
        mov     ecx, DWORD PTR [edx+92]
        mov     DWORD PTR _zstep_dx1$[esp+128], ebx
        mov     DWORD PTR _ustep_dx1$[esp+128], eax
; Line 303
        mov     ebx, DWORD PTR [edx+104]
        mov     eax, DWORD PTR [edx+108]
        mov     DWORD PTR _ustep_dx2$[esp+128], ecx
        mov     DWORD PTR _vstep_dx1$[esp+128], ebx
; Line 305
        mov     ecx, DWORD PTR [edx]
        mov     ebx, DWORD PTR [edx+4]
        mov     DWORD PTR _vstep_dx2$[esp+128], eax
        mov     DWORD PTR _scrn$[esp+128], ecx
; Line 308
        mov     eax, DWORD PTR [edx+12]
        mov     ecx, DWORD PTR [edx+16]
        mov     esi, DWORD PTR [edx+20]
        mov     DWORD PTR _zbuff$[esp+128], ebx
; Line 309
        mov     DWORD PTR _edge1$[esp+128], eax
        mov     DWORD PTR _edge2$[esp+128], ecx
; Line 311
        mov     eax, DWORD PTR [esi+16]
        mov     ecx, DWORD PTR [esi+20]
        mov     ebx, DWORD PTR [esi+24]
        mov     DWORD PTR _uup$[esp+128], eax
; Line 312
        mov     eax, DWORD PTR [esi+28]
        mov     edx, DWORD PTR [edx+24]
        mov     DWORD PTR _vup$[esp+128], ecx
        mov     DWORD PTR _udown$[esp+128], ebx
; Line 313
        mov     ecx, DWORD PTR [esi+8]
        mov     ebx, DWORD PTR [esi+4]
; Line 314
        sub     eax, ecx
        mov     DWORD PTR _start_y$[esp+128], edx
        mov     DWORD PTR _vdown$[esp+128], eax
; Line 316
        mov     eax, DWORD PTR [ebx+4]
        mov     DWORD PTR _tptr$[esp+128], eax
; Line 317
        mov     eax, 1
        shl     eax, cl
        dec     eax
        not     eax
        mov     ebp, DWORD PTR _count$[esp+128]
        mov     DWORD PTR _mask$[esp+128], eax
; Line 320
        mov     DWORD PTR _y$[esp+128], 0
        test    ebp, ebp
        jl      $L23881
$L23910:
; Line 322
        mov     eax, DWORD PTR _edge1$[esp+128]
        mov     ecx, DWORD PTR [eax+8]
        mov     edx, DWORD PTR [eax+16]
        mov     DWORD PTR _tz$23913[esp+128], ecx
        mov     DWORD PTR _ts$23914[esp+128], edx
; Line 323
        mov     edx, DWORD PTR [eax+20]
        mov     cl, BYTE PTR _uup$[esp+128]
; Line 324
        mov     ebx, edx
        mov     eax, DWORD PTR [eax+24]
        shl     ebx, cl
; Line 325
        mov     cl, BYTE PTR _vup$[esp+128]
        shl     eax, cl
        mov     ecx, DWORD PTR _edge1$[esp+128]
        mov     DWORD PTR _tv$23916[esp+128], eax
; Line 327
        mov     eax, DWORD PTR _scrn$[esp+128]
        nop
        mov     esi, DWORD PTR [ecx]
        mov     ecx, DWORD PTR _zbuff$[esp+128]
        add     esi, 32768                              ; 00008000H
        mov     ebp, DWORD PTR _y$[esp+128]
        sar     esi, 16                                 ; 00000010H
; Line 328
        add     eax, esi
        mov     DWORD PTR _ptr$23918[esp+128], eax
        lea     edi, DWORD PTR [ecx+esi*2]
; Line 330
        mov     eax, DWORD PTR _start_y$[esp+128]
        mov     ecx, DWORD PTR _edge2$[esp+128]
        add     eax, ebp
        and     eax, 3
        shl     eax, 4
        add     eax, OFFSET FLAT:?DitherMatrix@@3PAY03JA ; DitherMatrix
        mov     DWORD PTR _dmatrix$23920[esp+128], eax
; Line 331
        mov     eax, DWORD PTR [ecx]
        add     eax, 32768                              ; 00008000H
        sar     eax, 16                                 ; 00000010H
        mov     ebp, eax
        mov     DWORD PTR _dx$23921[esp+128], eax
; Line 332
        sub     ebp, esi
; Line 334
        test    ebp, ebp
        jle     SHORT $L23923
; Line 337
        mov     eax, DWORD PTR _uup$[esp+128]
        lea     ecx, DWORD PTR _ustep_dx2$[esp+128]
        push    eax
        push    ecx
        lea     eax, DWORD PTR _ustep_dx1$[esp+136]
        mov     ecx, DWORD PTR _edge2$[esp+136]
        push    eax
        push    ebp
        mov     eax, DWORD PTR [ecx+20]
        push    eax
        push    edx
        mov     edx, DWORD PTR [ecx+28]
        mov     eax, DWORD PTR _edge1$[esp+152]
        push    edx
        mov     ecx, DWORD PTR [eax+28]
        push    ecx
        call    _vngo_calc_quadratic2
        mov     ecx, DWORD PTR _vup$[esp+160]
        lea     edx, DWORD PTR _vstep_dx2$[esp+160]
        lea     eax, DWORD PTR _vstep_dx1$[esp+160]
        add     esp, 32                                 ; 00000020H
; Line 339
        push    ecx
        push    edx
        mov     ecx, DWORD PTR _edge2$[esp+136]
        push    eax
        mov     eax, DWORD PTR _edge1$[esp+140]
        push    ebp
        mov     edx, DWORD PTR [ecx+24]
        push    edx
        mov     ecx, DWORD PTR [eax+24]
        mov     edx, DWORD PTR _edge2$[esp+148]
        push    ecx
        mov     ecx, DWORD PTR _edge1$[esp+152]
        mov     eax, DWORD PTR [edx+28]
        push    eax
        mov     edx, DWORD PTR [ecx+28]
        push    edx
        call    _vngo_calc_quadratic2
        add     esp, 32                                 ; 00000020H
; Line 341
        jmp     SHORT $L23924
$L23923:
; Line 343
        mov     DWORD PTR _ustep_dx1$[esp+128], 0
; Line 344
        mov     DWORD PTR _ustep_dx2$[esp+128], 0
; Line 345
        mov     DWORD PTR _vstep_dx1$[esp+128], 0
; Line 346
        mov     DWORD PTR _vstep_dx2$[esp+128], 0
; Line 347
$L23924:
; Line 349
        mov     eax, DWORD PTR _dx$23921[esp+128]
        cmp     eax, esi
        jl      $L23928
$L23926:
; Line 351
        mov     edx, DWORD PTR _tz$23913[esp+128]
        sar     edx, 15                                 ; 0000000fH
; Line 352
        cmp     WORD PTR [edi], dx
        jbe     SHORT $L23930
; Line 355
        mov     ebp, DWORD PTR _tv$23916[esp+128]
        mov     cl, BYTE PTR _vdown$[esp+128]
        shr     ebp, cl
        mov     eax, DWORD PTR _mask$[esp+128]
        mov     cl, BYTE PTR _udown$[esp+128]
        and     ebp, eax
        mov     eax, ebx
        shr     eax, cl
        add     ebp, eax
        mov     ecx, DWORD PTR _tptr$[esp+128]
        mov     al, BYTE PTR [ebp+ecx]
; Line 357
        cmp     al, 255                                 ; 000000ffH
        je      SHORT $L23930
; Line 359
        mov     WORD PTR [edi], dx
        mov     ecx, esi
; Line 360
        and     ecx, 3
        mov     ebp, DWORD PTR _dmatrix$23920[esp+128]
        mov     edx, DWORD PTR [ebp+ecx*4]
        mov     ecx, DWORD PTR _ts$23914[esp+128]
        add     edx, ecx
        sar     edx, 19                                 ; 00000013H
; Line 361
        cmp     edx, 31                                 ; 0000001fH
        jle     SHORT $L23935
; Line 362
        mov     edx, 31                                 ; 0000001fH
; Line 363
        jmp     SHORT $L23936
$L23935:
        test    edx, edx
        jge     SHORT $L23936
; Line 364
        xor     edx, edx
; Line 366
$L23936:
        xor     ecx, ecx
        mov     cl, al
        mov     eax, DWORD PTR _stable$[esp+128]
        shl     ecx, 5
        add     ecx, eax
        mov     dl, BYTE PTR [ecx+edx]
        mov     ecx, DWORD PTR _ptr$23918[esp+128]
        mov     BYTE PTR [ecx], dl
; Line 369
$L23930:
        mov     eax, DWORD PTR _ptr$23918[esp+128]
        add     edi, 2
        inc     eax
        mov     ecx, DWORD PTR _zstep_dx1$[esp+128]
        mov     edx, DWORD PTR _tz$23913[esp+128]
        mov     ebp, DWORD PTR _ts$23914[esp+128]
        add     edx, ecx
        inc     esi
        mov     ecx, DWORD PTR _vstep_dx1$[esp+128]
        mov     DWORD PTR _ptr$23918[esp+128], eax
; Line 371
        mov     eax, DWORD PTR _sstep_dx1$[esp+128]
        mov     DWORD PTR _tz$23913[esp+128], edx
; Line 372
        add     ebp, eax
        mov     edx, DWORD PTR _ustep_dx2$[esp+128]
        mov     eax, DWORD PTR _ustep_dx1$[esp+128]
        mov     DWORD PTR _ts$23914[esp+128], ebp
; Line 373
        add     ebx, eax
; Line 374
        mov     eax, DWORD PTR _tv$23916[esp+128]
        add     eax, ecx
        mov     ecx, DWORD PTR _vstep_dx2$[esp+128]
        mov     DWORD PTR _tv$23916[esp+128], eax
; Line 375
        mov     eax, DWORD PTR _ustep_dx1$[esp+128]
        add     eax, edx
        mov     DWORD PTR _ustep_dx1$[esp+128], eax
; Line 376
        mov     eax, DWORD PTR _vstep_dx1$[esp+128]
        add     eax, ecx
        mov     DWORD PTR _vstep_dx1$[esp+128], eax
; Line 349
        mov     eax, DWORD PTR _dx$23921[esp+128]
        cmp     esi, eax
        jle     $L23926
; Line 377
$L23928:
; Line 378
        mov     eax, DWORD PTR _pitch$[esp+128]
        mov     ecx, DWORD PTR _scrn$[esp+128]
        add     ecx, eax
        mov     edx, DWORD PTR _zbuff$[esp+128]
        mov     eax, DWORD PTR _zpitch$[esp+128]
        mov     ebx, DWORD PTR _edge1$[esp+128]
        add     ebx, 32                                 ; 00000020H
        mov     ebp, DWORD PTR _edge2$[esp+128]
        lea     edx, DWORD PTR [edx+eax*2]
        add     ebp, 32                                 ; 00000020H
        mov     esi, DWORD PTR _y$[esp+128]
        mov     DWORD PTR _scrn$[esp+128], ecx
; Line 379
        inc     esi
        mov     edi, DWORD PTR _count$[esp+128]
        mov     DWORD PTR _zbuff$[esp+128], edx
        mov     DWORD PTR _edge1$[esp+128], ebx
; Line 381
        mov     DWORD PTR _edge2$[esp+128], ebp
        mov     DWORD PTR _y$[esp+128], esi
; Line 320
        cmp     esi, edi
        jle     $L23910
; Line 383
$L23881:
        pop     ebp
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 112                                ; 00000070H
        ret     0
_draw_zpghlines ENDP


_tri$ = 8
_stable$ = -20
_count$ = -36
_pitch$ = -8
_zpitch$ = -4
_sstep_dx1$ = -12
_zstep_dx1$ = -16
_ustep_dx1$ = -96
_ustep_dx2$ = -64
_vstep_dx1$ = -92
_vstep_dx2$ = -60
_scrn$ = -52
_zbuff$ = -48
_edge1$ = -104
_edge2$ = -100
_uup$ = -44
_vup$ = -40
_start_y$ = -32
_tptr$ = -24
_y$ = -88
_tz$23968 = -76
_ts$23969 = -72
_tv$23971 = -68
_ptr$23973 = -80
_dmatrix$23975 = -28
_dx$23976 = -56
_ldx$23977 = -84
_draw_zpghlines_256x256_ntrans PROC NEAR
; Line 386
        mov     edx, DWORD PTR _tri$[esp-4]
        sub     esp, 104                                ; 00000068H
        push    ebx
        mov     eax, DWORD PTR [edx+8]
        push    esi
        push    edi
        push    ebp
        mov     ecx, DWORD PTR [eax+8]
; Line 387
        xor     esi, esi
        mov     eax, DWORD PTR [ecx+4]
; Line 389
        mov     cl, BYTE PTR [eax+4]
        mov     ebx, DWORD PTR [eax+16]
        shl     esi, cl
        add     esi, ebx
        mov     eax, DWORD PTR [edx+28]
        mov     ecx, DWORD PTR [edx+44]
        mov     DWORD PTR _stable$[esp+120], esi
; Line 391
        mov     DWORD PTR _count$[esp+120], eax
        mov     DWORD PTR _pitch$[esp+120], ecx
; Line 393
        mov     eax, DWORD PTR [edx+48]
        mov     ecx, DWORD PTR [edx+56]
        sar     eax, 1
        mov     ebx, DWORD PTR [edx+72]
        mov     DWORD PTR _zpitch$[esp+120], eax
        mov     DWORD PTR _sstep_dx1$[esp+120], ecx
; Line 396
        mov     eax, DWORD PTR [edx+88]
        mov     ecx, DWORD PTR [edx+92]
        mov     DWORD PTR _zstep_dx1$[esp+120], ebx
        mov     DWORD PTR _ustep_dx1$[esp+120], eax
; Line 398
        mov     ebx, DWORD PTR [edx+104]
        mov     eax, DWORD PTR [edx+108]
        mov     DWORD PTR _ustep_dx2$[esp+120], ecx
        mov     DWORD PTR _vstep_dx1$[esp+120], ebx
; Line 400
        mov     ecx, DWORD PTR [edx]
        mov     ebx, DWORD PTR [edx+4]
        mov     DWORD PTR _vstep_dx2$[esp+120], eax
        mov     DWORD PTR _scrn$[esp+120], ecx
; Line 403
        mov     eax, DWORD PTR [edx+12]
        mov     ecx, DWORD PTR [edx+16]
        mov     DWORD PTR _zbuff$[esp+120], ebx
        mov     DWORD PTR _edge1$[esp+120], eax
; Line 405
        mov     DWORD PTR _edge2$[esp+120], ecx
        mov     ecx, DWORD PTR [edx+20]
; Line 406
        mov     edx, DWORD PTR [edx+24]
        nop
        mov     ebx, DWORD PTR [ecx+20]
        mov     eax, DWORD PTR [ecx+16]
        mov     DWORD PTR _uup$[esp+120], eax
        mov     DWORD PTR _vup$[esp+120], ebx
; Line 408
        mov     eax, DWORD PTR [ecx+4]
        mov     edi, DWORD PTR _count$[esp+120]
        mov     DWORD PTR _start_y$[esp+120], edx
        test    edi, edi
; Line 409
        mov     DWORD PTR _y$[esp+120], 0
        mov     ebp, DWORD PTR [eax+4]
        mov     DWORD PTR _tptr$[esp+120], ebp
; Line 412
        jl      $L23939
$L23965:
; Line 414
        mov     eax, DWORD PTR _edge1$[esp+120]
        mov     ecx, DWORD PTR [eax+8]
        mov     edx, DWORD PTR [eax+16]
        mov     DWORD PTR _tz$23968[esp+120], ecx
        mov     DWORD PTR _ts$23969[esp+120], edx
; Line 415
        mov     edx, DWORD PTR [eax+20]
        mov     cl, BYTE PTR _uup$[esp+120]
; Line 416
        mov     edi, edx
        mov     eax, DWORD PTR [eax+24]
        shl     edi, cl
; Line 417
        mov     cl, BYTE PTR _vup$[esp+120]
        shl     eax, cl
        mov     ecx, DWORD PTR _edge1$[esp+120]
        mov     DWORD PTR _tv$23971[esp+120], eax
; Line 419
        mov     eax, DWORD PTR _scrn$[esp+120]
        nop
        mov     esi, DWORD PTR [ecx]
        mov     ecx, DWORD PTR _zbuff$[esp+120]
        add     esi, 32768                              ; 00008000H
        mov     ebp, DWORD PTR _y$[esp+120]
        sar     esi, 16                                 ; 00000010H
; Line 420
        add     eax, esi
        mov     DWORD PTR _ptr$23973[esp+120], eax
        lea     ebx, DWORD PTR [ecx+esi*2]
; Line 422
        mov     eax, DWORD PTR _start_y$[esp+120]
        mov     ecx, DWORD PTR _edge2$[esp+120]
        add     eax, ebp
        and     eax, 3
        shl     eax, 4
        add     eax, OFFSET FLAT:?DitherMatrix@@3PAY03JA ; DitherMatrix
        mov     DWORD PTR _dmatrix$23975[esp+120], eax
; Line 423
        mov     eax, DWORD PTR [ecx]
        add     eax, 32768                              ; 00008000H
        sar     eax, 16                                 ; 00000010H
        mov     DWORD PTR _dx$23976[esp+120], eax
; Line 424
        sub     eax, esi
        mov     DWORD PTR _ldx$23977[esp+120], eax
        test    eax, eax
; Line 426
        jle     SHORT $L23978
; Line 429
        mov     eax, DWORD PTR _uup$[esp+120]
        lea     ecx, DWORD PTR _ustep_dx2$[esp+120]
        lea     ebp, DWORD PTR _ustep_dx1$[esp+120]
        push    eax
        mov     eax, DWORD PTR _ldx$23977[esp+124]
        push    ecx
        mov     ecx, DWORD PTR _edge2$[esp+128]
        push    ebp
        push    eax
        nop
        mov     eax, DWORD PTR [ecx+28]
        mov     ebp, DWORD PTR [ecx+20]
        push    ebp
        push    edx
        mov     edx, DWORD PTR _edge1$[esp+144]
        push    eax
        mov     ecx, DWORD PTR [edx+28]
        push    ecx
        call    _vngo_calc_quadratic2
        mov     ecx, DWORD PTR _vup$[esp+152]
        lea     edx, DWORD PTR _vstep_dx2$[esp+152]
        lea     eax, DWORD PTR _vstep_dx1$[esp+152]
        add     esp, 32                                 ; 00000020H
; Line 431
        push    ecx
        push    edx
        mov     ecx, DWORD PTR _ldx$23977[esp+128]
        push    eax
        mov     edx, DWORD PTR _edge2$[esp+132]
        push    ecx
        mov     ecx, DWORD PTR _edge1$[esp+136]
        mov     eax, DWORD PTR [edx+24]
        push    eax
        mov     edx, DWORD PTR [ecx+24]
        mov     eax, DWORD PTR _edge2$[esp+140]
        push    edx
        mov     edx, DWORD PTR _edge1$[esp+144]
        mov     ecx, DWORD PTR [eax+28]
        push    ecx
        mov     eax, DWORD PTR [edx+28]
        push    eax
        call    _vngo_calc_quadratic2
        add     esp, 32                                 ; 00000020H
; Line 433
        jmp     SHORT $L23979
$L23978:
; Line 435
        mov     DWORD PTR _ustep_dx1$[esp+120], 0
; Line 436
        mov     DWORD PTR _ustep_dx2$[esp+120], 0
; Line 437
        mov     DWORD PTR _vstep_dx1$[esp+120], 0
; Line 438
        mov     DWORD PTR _vstep_dx2$[esp+120], 0
; Line 439
$L23979:
; Line 441
        mov     eax, DWORD PTR _dx$23976[esp+120]
        cmp     eax, esi
        jl      $L23983
$L23981:
; Line 443
        mov     eax, DWORD PTR _tz$23968[esp+120]
        sar     eax, 15                                 ; 0000000fH
; Line 444
        cmp     WORD PTR [ebx], ax
        jbe     SHORT $L23985
; Line 446
        mov     WORD PTR [ebx], ax
        mov     ecx, DWORD PTR _dmatrix$23975[esp+120]
; Line 448
        mov     eax, esi
        mov     edx, DWORD PTR _ts$23969[esp+120]
        and     eax, 3
        mov     ecx, DWORD PTR [ecx+eax*4]
        add     ecx, edx
        sar     ecx, 19                                 ; 00000013H
; Line 449
        cmp     ecx, 31                                 ; 0000001fH
        jle     SHORT $L23987
; Line 450
        mov     ecx, 31                                 ; 0000001fH
; Line 451
        jmp     SHORT $L23988
$L23987:
        test    ecx, ecx
        jge     SHORT $L23988
; Line 452
        xor     ecx, ecx
; Line 454
$L23988:
; Line 457
        mov     edx, DWORD PTR _tv$23971[esp+120]
        mov     eax, edi
        shr     eax, 24                                 ; 00000018H
        and     edx, -16711681                          ; ff00ffffH
        shr     edx, 16                                 ; 00000010H
        mov     ebp, DWORD PTR _tptr$[esp+120]
        add     edx, eax
        xor     eax, eax
        mov     al, BYTE PTR [edx+ebp]
        mov     edx, DWORD PTR _stable$[esp+120]
        shl     eax, 5
        add     eax, edx
        mov     al, BYTE PTR [eax+ecx]
        mov     ecx, DWORD PTR _ptr$23973[esp+120]
        mov     BYTE PTR [ecx], al
; Line 459
$L23985:
        mov     eax, DWORD PTR _ptr$23973[esp+120]
        add     ebx, 2
        inc     eax
        mov     ecx, DWORD PTR _zstep_dx1$[esp+120]
        mov     edx, DWORD PTR _tz$23968[esp+120]
        mov     ebp, DWORD PTR _ts$23969[esp+120]
        add     edx, ecx
        inc     esi
        mov     ecx, DWORD PTR _vstep_dx1$[esp+120]
        mov     DWORD PTR _ptr$23973[esp+120], eax
; Line 461
        mov     eax, DWORD PTR _sstep_dx1$[esp+120]
        mov     DWORD PTR _tz$23968[esp+120], edx
; Line 462
        add     ebp, eax
        mov     edx, DWORD PTR _ustep_dx2$[esp+120]
        mov     eax, DWORD PTR _ustep_dx1$[esp+120]
        mov     DWORD PTR _ts$23969[esp+120], ebp
; Line 463
        add     edi, eax
; Line 464
        mov     eax, DWORD PTR _tv$23971[esp+120]
        add     eax, ecx
        mov     ecx, DWORD PTR _vstep_dx2$[esp+120]
        mov     DWORD PTR _tv$23971[esp+120], eax
; Line 465
        mov     eax, DWORD PTR _ustep_dx1$[esp+120]
        add     eax, edx
        mov     DWORD PTR _ustep_dx1$[esp+120], eax
; Line 466
        mov     eax, DWORD PTR _vstep_dx1$[esp+120]
        add     eax, ecx
        mov     DWORD PTR _vstep_dx1$[esp+120], eax
; Line 441
        mov     eax, DWORD PTR _dx$23976[esp+120]
        cmp     esi, eax
        jle     $L23981
; Line 467
$L23983:
; Line 468
        mov     eax, DWORD PTR _pitch$[esp+120]
        mov     ecx, DWORD PTR _scrn$[esp+120]
        add     ecx, eax
        mov     edx, DWORD PTR _zbuff$[esp+120]
        mov     eax, DWORD PTR _zpitch$[esp+120]
        mov     ebx, DWORD PTR _edge1$[esp+120]
        add     ebx, 32                                 ; 00000020H
        mov     ebp, DWORD PTR _edge2$[esp+120]
        lea     edx, DWORD PTR [edx+eax*2]
        add     ebp, 32                                 ; 00000020H
        mov     esi, DWORD PTR _y$[esp+120]
        mov     DWORD PTR _scrn$[esp+120], ecx
; Line 469
        inc     esi
        mov     edi, DWORD PTR _count$[esp+120]
        mov     DWORD PTR _zbuff$[esp+120], edx
        mov     DWORD PTR _edge1$[esp+120], ebx
; Line 471
        mov     DWORD PTR _edge2$[esp+120], ebp
        mov     DWORD PTR _y$[esp+120], esi
; Line 412
        cmp     esi, edi
        jle     $L23965
; Line 473
$L23939:
        pop     ebp
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 104                                ; 00000068H
        ret     0
_draw_zpghlines_256x256_ntrans ENDP


_tri$ = 8
_stable$ = -20
_count$ = -36
_pitch$ = -8
_zpitch$ = -4
_sstep_dx1$ = -12
_zstep_dx1$ = -16
_ustep_dx1$ = -96
_ustep_dx2$ = -64
_vstep_dx1$ = -92
_vstep_dx2$ = -60
_scrn$ = -52
_zbuff$ = -48
_edge1$ = -104
_edge2$ = -100
_uup$ = -44
_vup$ = -40
_start_y$ = -32
_tptr$ = -24
_y$ = -88
_tz$24022 = -76
_ts$24023 = -72
_tv$24025 = -68
_ptr$24027 = -80
_dmatrix$24029 = -28
_dx$24030 = -56
_ldx$24031 = -84
_draw_zpghlines_128x128_ntrans PROC NEAR
; Line 476
        mov     edx, DWORD PTR _tri$[esp-4]
        sub     esp, 104                                ; 00000068H
        push    ebx
        mov     eax, DWORD PTR [edx+8]
        push    esi
        push    edi
        push    ebp
        mov     ecx, DWORD PTR [eax+8]
; Line 477
        xor     esi, esi
        mov     eax, DWORD PTR [ecx+4]
; Line 479
        mov     cl, BYTE PTR [eax+4]
        mov     ebx, DWORD PTR [eax+16]
        shl     esi, cl
        add     esi, ebx
        mov     eax, DWORD PTR [edx+28]
        mov     ecx, DWORD PTR [edx+44]
        mov     DWORD PTR _stable$[esp+120], esi
; Line 481
        mov     DWORD PTR _count$[esp+120], eax
        mov     DWORD PTR _pitch$[esp+120], ecx
; Line 483
        mov     eax, DWORD PTR [edx+48]
        mov     ecx, DWORD PTR [edx+56]
        sar     eax, 1
        mov     ebx, DWORD PTR [edx+72]
        mov     DWORD PTR _zpitch$[esp+120], eax
        mov     DWORD PTR _sstep_dx1$[esp+120], ecx
; Line 486
        mov     eax, DWORD PTR [edx+88]
        mov     ecx, DWORD PTR [edx+92]
        mov     DWORD PTR _zstep_dx1$[esp+120], ebx
        mov     DWORD PTR _ustep_dx1$[esp+120], eax
; Line 488
        mov     ebx, DWORD PTR [edx+104]
        mov     eax, DWORD PTR [edx+108]
        mov     DWORD PTR _ustep_dx2$[esp+120], ecx
        mov     DWORD PTR _vstep_dx1$[esp+120], ebx
; Line 490
        mov     ecx, DWORD PTR [edx]
        mov     ebx, DWORD PTR [edx+4]
        mov     DWORD PTR _vstep_dx2$[esp+120], eax
        mov     DWORD PTR _scrn$[esp+120], ecx
; Line 493
        mov     eax, DWORD PTR [edx+12]
        mov     ecx, DWORD PTR [edx+16]
        mov     DWORD PTR _zbuff$[esp+120], ebx
        mov     DWORD PTR _edge1$[esp+120], eax
; Line 495
        mov     DWORD PTR _edge2$[esp+120], ecx
        mov     ecx, DWORD PTR [edx+20]
; Line 496
        mov     edx, DWORD PTR [edx+24]
        nop
        mov     ebx, DWORD PTR [ecx+20]
        mov     eax, DWORD PTR [ecx+16]
        mov     DWORD PTR _uup$[esp+120], eax
        mov     DWORD PTR _vup$[esp+120], ebx
; Line 498
        mov     eax, DWORD PTR [ecx+4]
        mov     edi, DWORD PTR _count$[esp+120]
        mov     DWORD PTR _start_y$[esp+120], edx
        test    edi, edi
; Line 499
        mov     DWORD PTR _y$[esp+120], 0
        mov     ebp, DWORD PTR [eax+4]
        mov     DWORD PTR _tptr$[esp+120], ebp
; Line 502
        jl      $L23993
$L24019:
; Line 504
        mov     eax, DWORD PTR _edge1$[esp+120]
        mov     ecx, DWORD PTR [eax+8]
        mov     edx, DWORD PTR [eax+16]
        mov     DWORD PTR _tz$24022[esp+120], ecx
        mov     DWORD PTR _ts$24023[esp+120], edx
; Line 505
        mov     edx, DWORD PTR [eax+20]
        mov     cl, BYTE PTR _uup$[esp+120]
; Line 506
        mov     edi, edx
        mov     eax, DWORD PTR [eax+24]
        shl     edi, cl
; Line 507
        mov     cl, BYTE PTR _vup$[esp+120]
        shl     eax, cl
        mov     ecx, DWORD PTR _edge1$[esp+120]
        mov     DWORD PTR _tv$24025[esp+120], eax
; Line 509
        mov     eax, DWORD PTR _scrn$[esp+120]
        nop
        mov     esi, DWORD PTR [ecx]
        mov     ecx, DWORD PTR _zbuff$[esp+120]
        add     esi, 32768                              ; 00008000H
        mov     ebp, DWORD PTR _y$[esp+120]
        sar     esi, 16                                 ; 00000010H
; Line 510
        add     eax, esi
        mov     DWORD PTR _ptr$24027[esp+120], eax
        lea     ebx, DWORD PTR [ecx+esi*2]
; Line 512
        mov     eax, DWORD PTR _start_y$[esp+120]
        mov     ecx, DWORD PTR _edge2$[esp+120]
        add     eax, ebp
        and     eax, 3
        shl     eax, 4
        add     eax, OFFSET FLAT:?DitherMatrix@@3PAY03JA ; DitherMatrix
        mov     DWORD PTR _dmatrix$24029[esp+120], eax
; Line 513
        mov     eax, DWORD PTR [ecx]
        add     eax, 32768                              ; 00008000H
        sar     eax, 16                                 ; 00000010H
        mov     DWORD PTR _dx$24030[esp+120], eax
; Line 514
        sub     eax, esi
        mov     DWORD PTR _ldx$24031[esp+120], eax
        test    eax, eax
; Line 516
        jle     SHORT $L24032
; Line 519
        mov     eax, DWORD PTR _uup$[esp+120]
        lea     ecx, DWORD PTR _ustep_dx2$[esp+120]
        lea     ebp, DWORD PTR _ustep_dx1$[esp+120]
        push    eax
        mov     eax, DWORD PTR _ldx$24031[esp+124]
        push    ecx
        mov     ecx, DWORD PTR _edge2$[esp+128]
        push    ebp
        push    eax
        mov     eax, DWORD PTR [ecx+28]
        nop
        mov     ebp, DWORD PTR [ecx+20]
        push    ebp
        push    edx
        mov     edx, DWORD PTR _edge1$[esp+144]
        push    eax
        mov     ecx, DWORD PTR [edx+28]
        push    ecx
        call    _vngo_calc_quadratic2
        mov     ecx, DWORD PTR _vup$[esp+152]
        lea     edx, DWORD PTR _vstep_dx2$[esp+152]
        lea     eax, DWORD PTR _vstep_dx1$[esp+152]
        add     esp, 32                                 ; 00000020H
; Line 521
        push    ecx
        push    edx
        mov     ecx, DWORD PTR _ldx$24031[esp+128]
        push    eax
        mov     edx, DWORD PTR _edge2$[esp+132]
        push    ecx
        mov     ecx, DWORD PTR _edge1$[esp+136]
        mov     eax, DWORD PTR [edx+24]
        push    eax
        mov     edx, DWORD PTR [ecx+24]
        mov     eax, DWORD PTR _edge2$[esp+140]
        push    edx
        mov     edx, DWORD PTR _edge1$[esp+144]
        mov     ecx, DWORD PTR [eax+28]
        push    ecx
        mov     eax, DWORD PTR [edx+28]
        push    eax
        call    _vngo_calc_quadratic2
        add     esp, 32                                 ; 00000020H
; Line 523
        jmp     SHORT $L24033
$L24032:
; Line 525
        mov     DWORD PTR _ustep_dx1$[esp+120], 0
; Line 526
        mov     DWORD PTR _ustep_dx2$[esp+120], 0
; Line 527
        mov     DWORD PTR _vstep_dx1$[esp+120], 0
; Line 528
        mov     DWORD PTR _vstep_dx2$[esp+120], 0
; Line 529


;; This is the start of the Inside Loop.
$L24033:
        ; Compare to see if we have finished the scan line.
        cmp     DWORD PTR _dx$24030[esp+120], esi
        jl      $L24037
$L24035:
        ; Now check the Z-Buffer.
        mov     eax, DWORD PTR _tz$24022[esp+120]
        mov     ecx, DWORD PTR _dmatrix$24029[esp+120]
        shr     eax, 15
        cmp     WORD PTR [ebx], ax
        jbe     SHORT $L24039

        ; We need to draw the pixel.

        mov     WORD PTR [ebx], ax                      ; write the new Z-Value.
        mov     eax, esi                                ; Calc the dither value.
        mov     edx, DWORD PTR _ts$24023[esp+120]
        and     eax, 3                                  ; align the dither pattern.
        mov     ecx, DWORD PTR [ecx+eax*4]              ; get the dither value.
        add     ecx, edx                                ; add the dither & shade values.
        shr     ecx, 19                                 ; scale it to the correct range.

        ; Check the shade level to make sure it is valid.
        cmp     ecx, 31
        jna     SHORT $L24042                           ; it is valid if we take this jump.
        jle     SHORT $L24041
        mov     ecx, 31
        jmp     SHORT $L24042
$L24041:
        test    ecx, ecx
        jge     SHORT $L24042
        xor     ecx, ecx
        ; We now have a valid shade level.
$L24042:
        ; Calc the texel color.
        mov     eax, edi
        mov     edx, DWORD PTR _tv$24025[esp+120]
        shr     eax, 25
        and     edx, 0fe03ffffH
        shr     edx, 18
        mov     ebp, DWORD PTR _tptr$[esp+120]
        add     edx, eax
        xor     eax, eax
        mov     al, BYTE PTR [edx+ebp]
        ; Now shade the color.
        mov     edx, DWORD PTR _stable$[esp+120]
        shl     eax, 5
        add     eax, edx
        mov     al, BYTE PTR [eax+ecx]
        mov     ecx, DWORD PTR _ptr$24027[esp+120]
        mov     BYTE PTR [ecx], al                      ; Write the pixel!
$L24039:
        mov     eax, DWORD PTR _ptr$24027[esp+120]
        add     ebx, 2
        inc     eax
        mov     ecx, DWORD PTR _zstep_dx1$[esp+120]
        mov     edx, DWORD PTR _tz$24022[esp+120]
        mov     ebp, DWORD PTR _ts$24023[esp+120]
        add     edx, ecx
        inc     esi
        mov     ecx, DWORD PTR _vstep_dx1$[esp+120]
        mov     DWORD PTR _ptr$24027[esp+120], eax
        mov     eax, DWORD PTR _sstep_dx1$[esp+120]
        mov     DWORD PTR _tz$24022[esp+120], edx
        add     ebp, eax
        mov     edx, DWORD PTR _ustep_dx2$[esp+120]
        mov     eax, DWORD PTR _ustep_dx1$[esp+120]
        mov     DWORD PTR _ts$24023[esp+120], ebp
        add     edi, eax
        mov     eax, DWORD PTR _tv$24025[esp+120]
        add     eax, ecx
        mov     ecx, DWORD PTR _vstep_dx2$[esp+120]
        mov     DWORD PTR _tv$24025[esp+120], eax
        mov     eax, DWORD PTR _ustep_dx1$[esp+120]
        add     eax, edx
        mov     DWORD PTR _ustep_dx1$[esp+120], eax
        mov     eax, DWORD PTR _vstep_dx1$[esp+120]
        add     eax, ecx
        mov     DWORD PTR _vstep_dx1$[esp+120], eax
        mov     eax, DWORD PTR _dx$24030[esp+120]
        cmp     esi, eax
        jle     $L24035
;; This is the end of  the inside loop.


; Line 557
$L24037:
; Line 558
        mov     eax, DWORD PTR _pitch$[esp+120]
        mov     ecx, DWORD PTR _scrn$[esp+120]
        add     ecx, eax
        mov     edx, DWORD PTR _zbuff$[esp+120]
        mov     eax, DWORD PTR _zpitch$[esp+120]
        mov     ebx, DWORD PTR _edge1$[esp+120]
        add     ebx, 32                                 ; 00000020H
        mov     ebp, DWORD PTR _edge2$[esp+120]
        lea     edx, DWORD PTR [edx+eax*2]
        add     ebp, 32                                 ; 00000020H
        mov     esi, DWORD PTR _y$[esp+120]
        mov     DWORD PTR _scrn$[esp+120], ecx
; Line 559
        inc     esi
        mov     edi, DWORD PTR _count$[esp+120]
        mov     DWORD PTR _zbuff$[esp+120], edx
        mov     DWORD PTR _edge1$[esp+120], ebx
; Line 561
        mov     DWORD PTR _edge2$[esp+120], ebp
        mov     DWORD PTR _y$[esp+120], esi
; Line 502
        cmp     edi, esi
        jge     $L24019
; Line 563
$L23993:
        pop     ebp
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 104                                ; 00000068H
        ret     0
_draw_zpghlines_128x128_ntrans ENDP
endif

_TEXT   ENDS
END
