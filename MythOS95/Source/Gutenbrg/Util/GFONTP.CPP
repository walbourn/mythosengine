//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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
//                          Microsoft Windows '95 Version
//
//               Copyright (c) 1995 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                              *** Utilities ***
//
// Created by Chuck Walbourn
//
// gfontp.cpp
//
//     This is the parse module for the font compiler.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <assert.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "debug.h"
#include "xfile.hpp"

#include "gfont.h"

#include "gutenbrg.hpp"
#include "gbrgfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


//ÄÄ External from scanner.
extern "C" int yylex();

//ÄÄ External from main module.
void print_error(XFParseIFF &xp, char *s=0);

//ÄÄ Local
STATIC void match(int tok);
STATIC void error(char *str);
STATIC void warning(char *str);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄ External from scanner.
extern "C" long    YY_integer;
extern "C" int     YY_lineno;
extern "C" char    *yytext;
extern "C" int     YY_hexmode;

//ÄÄ External from main module.
extern XFParseIFF  IFF;
extern dword       Flags;

//ÄÄ Local         
STATIC int         CurrentToken;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// compile                                                                  ³
//                                                                          ³
// Parses file into output IFF (both already opened by main).               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void compile(char *name)
{
    int                 i, ch, chi;
    int                 xoff, yoff;
    byte                *font, *fptr;
    dword               dw;
    ulong               fontSize;
    GBergFileFontHDR    header;

    memset(&header,0,sizeof(GBergFileFontHDR));
    strcpy(header.name,name);

    // For now, only supports MONOFIXED non-COMPRESSED fonts.
    header.compression = 0;
    header.type = GBERG_FNT_MONOFIXED;

    if (!(Flags & FLAGS_QUIET))
    {
        cout << "Compiling font " << name << "...\n";
    }

    CurrentToken = yylex();

//ÄÄ Font Header
    if (CurrentToken != YY_STARTFONT)
        error("Expected STARTFONT for a BDF file");
    match(YY_STARTFONT);

    // Read FONTBOUNDINGBOX
    while (CurrentToken)
    {
        if (CurrentToken == YY_FONTBOUNDINGBOX)
            break;
        CurrentToken = yylex();
    }

    if (CurrentToken != YY_FONTBOUNDINGBOX)
        error("Expected FONTBOUNDINGBOX in BDF file");
    match(YY_FONTBOUNDINGBOX);

    if (CurrentToken != YY_INTEGER)
    {
        error("FONTBOUNDINGBOX should be followed by Width, Height, XOffset, YOffset");
    }
    header.width = (ushort)YY_integer;
    match(YY_INTEGER);
    if (header.width > 16)
    {
        error("Fonts must be 16 pixels or less in width");
    }

    if (CurrentToken != YY_INTEGER)
    {
        error("FONTBOUNDINGBOX should be followed by Width, Height, XOffset, YOffset");
    }
    header.height = (ushort)YY_integer;
    match(YY_INTEGER);

    if (CurrentToken != YY_INTEGER)
    {
        error("FONTBOUNDINGBOX should be followed by Width, Height, XOffset, YOffset");
    }
    xoff = YY_integer;
    match(YY_INTEGER);

    if (CurrentToken != YY_INTEGER)
    {
        error("FONTBOUNDINGBOX should be followed by Width, Height, XOffset, YOffset");
    }
    yoff = YY_integer;
    match(YY_INTEGER);

    // Compute bytes per character cell
    header.bpc = (ushort)(((header.width + 7) >> 3) * header.height);

    // Write header
    if (IFF.write(IFF.makeid('H','D','R',' '),&header,sizeof(GBergFileFontHDR)))
    {
        print_error(IFF,"Failed to write header chunk");
        exit(1);
    }

//ÄÄ Scan properties
    while (CurrentToken)
    {
        if (CurrentToken == YY_STARTPROPERTIES)
            break;
        CurrentToken = yylex();
    }
    if (CurrentToken != YY_STARTPROPERTIES)
        error("Expected STARTPROPERTIES for a BDF file");
    match(YY_STARTPROPERTIES);

    while (CurrentToken)
    {
        if (CurrentToken == YY_ENDPROPERTIES)
            break;
        else if (CurrentToken == YY_COPYRIGHT)
        {
            // Handle copyright property by copying it to the target IFF file

            match(YY_COPYRIGHT);
            if (CurrentToken != YY_STRING)
                error("COPYRIGHT should be followed by a non-empty string");

            if (IFF.write(IFF.makeid('C','O','P','Y'),yytext,strlen(yytext)))
            {
                print_error(IFF,"Failed to write copyright chunk");
                exit(1);
            }
        }
        CurrentToken = yylex();
    }
    if (CurrentToken != YY_ENDPROPERTIES)
        error("Expected ENDPROPERTIES for a BDF file");
    match(YY_ENDPROPERTIES);

//ÄÄ Number of Characters
    while (CurrentToken)
    {
        if (CurrentToken == YY_CHARS)
            break;
        CurrentToken = yylex();
    }
    if (CurrentToken != YY_CHARS)
        error("Expected CHARS for a BDF file");
    match(YY_CHARS);

    if (CurrentToken != YY_INTEGER)
        error("CHARS should be followed by a number");

    // Since it only supports MONOFIXED, this number must be greater than
    // or equal to 128 or the font is missing characters.
    assert(header.type == GBERG_FNT_MONOFIXED);
    if (YY_integer < 128)
        warning("This font does not have at least 128 characters");
    match(YY_INTEGER);

//ÄÄ Character encode
    fontSize = 128*header.bpc;
    font = new byte[fontSize];
    if (!font)
        error("Could not allocate memory for font buffer");
    memset(font,0,fontSize);

    for(ch=0; ch < 128; ch++)
    {
        if (!(Flags & FLAGS_QUIET))
            cout << ".";
        
        if (CurrentToken == YY_STARTCHAR)
        {
            //ÄÄ Character read
            while (CurrentToken)
            {
                if (CurrentToken == YY_ENCODING)
                    break;
                CurrentToken = yylex();
            }
            if (CurrentToken != YY_ENCODING)
                error("Character must have ENCODING field");
            match(YY_ENCODING);

            if (CurrentToken != YY_INTEGER)
                error("ENCODING should be followed by a number");
            chi = YY_integer;
            match(YY_INTEGER);
            
            if (chi < 128)
            {
                
                // BBX
                while(CurrentToken)
                {
                    if (CurrentToken == YY_BBX)
                        break;
                    CurrentToken = yylex();
                }
                if (CurrentToken != YY_BBX)
                    error("BBX for character not found");
                match(YY_BBX);

                // Since this only supports MONOFIXED, the BBX must
                // match header.

                if (CurrentToken != YY_INTEGER)
                    error("BBX should be followed by the character's Width, Height, XOffset, and YOffset");
                assert(header.type == GBERG_FNT_MONOFIXED);
                if (YY_integer != header.width)
                    error("Character's width doesn't match fonts");
                match(YY_INTEGER);

                if (CurrentToken != YY_INTEGER)
                    error("BBX should be followed by the character's Width, Height, XOffset, and YOffset");
                assert(header.type == GBERG_FNT_MONOFIXED);
                if (YY_integer != header.height)
                    error("Character's height doesn't match fonts");
                match(YY_INTEGER);

                if (CurrentToken != YY_INTEGER)
                    error("BBX should be followed by the character's Width, Height, XOffset, and YOffset");
                xoff = YY_integer;
                match(YY_INTEGER);

                if (CurrentToken != YY_INTEGER)
                    error("BBX should be followed by the character's Width, Height, XOffset, and YOffset");
                yoff = YY_integer;
                match(YY_INTEGER);

                // BITMAP
                while(CurrentToken)
                {
                    if (CurrentToken == YY_BITMAP)
                        break;
                    CurrentToken = yylex();
                }

                if (CurrentToken != YY_BITMAP)
                    error("BITMAP for character not found");

                YY_hexmode=1;

                match(YY_BITMAP);

                for(i=0, fptr = &font[chi * header.bpc];
                    i < header.height; i++)
                {
                    if (CurrentToken != YY_INTEGER)
                        error("Not enough data for character");

                    if (YY_integer & 0xffff0000)
                    {
                        error("BDF does not allow more than 4 digits of hex");
                    }
                    else if (YY_integer & 0xff00)
                    {
                        if (header.width <= 8)
                        {
                            // aa00 ==> aa
                            dw = ((YY_integer >> 8) & 0xff);
                        }
                        else
                        {
                            assert(header.width <= 16);

                            // aabb ==> bbaa
                            dw = ((YY_integer >> 8) & 0xff)
                                 | ((YY_integer << 8) & 0xff00);
                        }
                    }
                    else 
                    {
                        if (header.width <= 8)
                        {
                            // aa ==> aa
                            dw = (YY_integer & 0xff);
                        }
                        else
                        {
                            // aa ==> aa00
                            dw = ((YY_integer << 8) & 0xff00);
                        }
                    }

                    // Store dword

                    *(fptr++) = (byte)(dw & 0xff);

                    if (header.width > 8)
                        *(fptr++) = (byte)((dw >> 8) & 0xff);

                    match(YY_INTEGER);
                }

                YY_hexmode=0;
            }

            while(CurrentToken)
            {
                if (CurrentToken == YY_ENDCHAR)
                    break;
                CurrentToken = yylex();
            }
            if (CurrentToken != YY_ENDCHAR)
                error("ENDCHAR for character not found");
            match(YY_ENDCHAR);
        }
        else if (!CurrentToken)
        {
            warning("Not enough characters in font");
            break;
        }
        else
            CurrentToken = yylex();
    }

    while (CurrentToken)
    {
        if (CurrentToken == YY_ENDFONT)
            break;
        CurrentToken = yylex();
    }
    if (CurrentToken != YY_ENDFONT)
        error("Expected ENDFONT for a BDF file");
    match(YY_ENDFONT);

    // Output font
    if (IFF.write(IFF.makeid('B','O','D','Y'),font,fontSize))
    {
        print_error(IFF,"Failed to write font data chunk");
        exit(1);
    }

    if (!(Flags & FLAGS_QUIET))
    {
        cout << "\nDone\n";
    }

}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// match                                                                    ³
//                                                                          ³
// Matches input token again target; if it failes, then it prints an error. ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void match(int tok)
{
    if (tok != CurrentToken) {
        error("Unexpected token in source file");
    }

    CurrentToken = yylex();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// error                                                                    ³
//                                                                          ³
// Emits an error and aborts processing.                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void error(char *str)
{
    cout << " Error(" << YY_lineno << "): " << str << "\n";
    exit(1);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// warning                                                                  ³
//                                                                          ³
// Emits a warning.                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void warning(char *str)
{
    cout << " Warning(" << YY_lineno << "): " << str << "\n";
}

//°±² End of module - gfontp.cpp ²±°

