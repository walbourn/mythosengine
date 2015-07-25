//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//           __ ,                                                  
//            ,-| ~           ,               ,,                      
//           ('||/__,        ||               ||                  _   
//          (( |||  | \\ \\ =||=   _-_  \\/\\ ||/|,  _-_  ,._-_  / \\ 
//          (( |||==| || ||  ||   || \\ || || || || || \\  ||   || || 
//           ( / |  , || ||  ||   ||/   || || || |' ||/    ||   || || 
//            -____/  \\/\\  \\,  \\,/  \\ \\ \\/   \\,/   \\,  \\_-| 
//                                                               /  \ 
//                                                              '----`
//                     Text Output and Font Management System
//                        Microsoft Windows 95/NT Version
//
//            Copyright (c) 1995-1998 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
//           *** Charybdis Enterprises, Inc. Company Confidential ***
//
//  This file and all associated files are the company proprietary property
//        of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
//
// CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
// TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
// IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
// AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
// INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
//                              *** Utilities ***
//
// Created by Chuck Walbourn
//
// gfont.h
//
//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

#ifndef __GFONT_H
#define __GFONT_H    1

//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//
//                                Equates
//
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

#define YY_BBX                  1
#define YY_BITMAP               2
#define YY_CHARS                3
#define YY_COPYRIGHT            4
#define YY_ENCODING             5
#define YY_ENDCHAR              6
#define YY_ENDFONT              7
#define YY_ENDPROPERTIES        8
#define YY_FAMILY_NAME          9
#define YY_FONTBOUNDINGBOX      10
#define YY_STARTCHAR            11
#define YY_STARTFONT            12
#define YY_STARTPROPERTIES      13

#define YY_INTEGER              100
#define YY_STRING               101


#define FLAGS_QUIET             0x1
#define FLAGS_INVERSE           0x2

#define FLAGS_TT_BOLD           0x10000
#define FLAGS_TT_ITALIC         0x20000
#define FLAGS_TT_UNDERLINE      0x40000
#define FLAGS_TT_STRIKEOUT      0x80000
#define FLAGS_TT_OEMCHARSET     0x100000
#define FLAGS_TT_CP850          0x200000

#endif

//ฐฑฒ End of header - gfont.h ฒฑฐ

