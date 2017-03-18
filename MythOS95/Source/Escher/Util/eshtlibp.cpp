//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùù°°°°°°°°°°ù°°°°°°°°ùùù°°°°°°°°ùù°°°ùùùù°°°ù°°°°°°°°°°ù°°°°°°°°°ùù
//ùùùùùùùùù°±°ùùùùùùù°±°ùùùù°±°ù°±°ùùùù°±°ù°±°ùùùù°±°ù°±°ùùùùùùùù°±°ùùùù°±°ùù
//ùùùùùùùù±°±ùùùùùùù±°±ùùùùùùùù±°±ùùùùùùùù±°±ùùùù±°±ù±°±ùùùùùùùù±°±ùùùù±°±ùùù
//ùùùùùùù±²±±°±±²ùù±²±±°±±²±±ù±²±ùùùùùùùù±²±±°±±²±±ù±²±±°±±²ùùù±²±±°±±²°ùùùùù
//ùùùùùù±²±ùùùùùùùùùùùùùù±²±ù±²±ùùùùùùùù±²±ùùùù±²±ù±²±ùùùùùùùù±²±ùùùù±²±ùùùùù
//ùùùùù²±²ùùùùùùù²±²ùùùù²±²ù²±²ùùùù²±²ù²±²ùùùù²±²ù²±²ùùùùùùùù²±²ùùùù²±²ùùùùùù
//ùùùù²²²²²²²²²²ù²²²²²²²²ùùù²²²²²²²²ùù²²²ùùùù²²²ù²²²²²²²²²²ù²²²ùùùù²²²ùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùù Microsoft Windows 95/98/NT Version ùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùCopyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbournùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                        http://www.mythos-engine.org/
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                              *** Utilities ***
//
// Created by Chuck Walbourn
//
// eshtlibp.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "debug.h"
#include "xfile.hpp"
#include "escher.hpp"
#include "esfile.hpp"

#include "eshtlib.h"
#include "eshtltok.h"

using namespace std;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define MAX_FRAMES      128

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄ External from scanner.
extern "C" int yylex();
extern "C" int yy_pushfile(const char *fname);

//ÄÄ External from main module.
void print_error(XFParseIFF *xp, char *s=0);

int extract(XFParseIFF &iff);

int find_txtname(const char *n);
int add_txtname(const char *n);

//ÄÄ Local
STATIC void ctf();
STATIC void include();
STATIC void description();
STATIC void copyright();
STATIC void author();
STATIC void extract();
STATIC void texture();
STATIC void txtopts(EschBuildTexture &tbld, dword &ctrlfl);

STATIC ulong uinteger(void);
STATIC ulong uexpr(void);
STATIC ulong uterm(void);
STATIC ulong ufactor(void);

STATIC void match(int tok);
extern "C" void error(const char *str);
extern "C" void warning(const char *str);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄ External from scanner.
extern "C" long     YY_integer;
extern "C" int      YY_lineno;
extern "C" int      YY_esc_allowed;
extern "C" char     *yytext;
extern "C" int      yyleng;

//ÄÄ External from main module.
extern XFParseIFF   *TxtIFF;
extern XFParseIFF   *RmdrIFF;
extern dword        Flags;
extern VngoPal      *Palette;

//ÄÄ Local
STATIC int          CurrentToken;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// compile                                                                  ³
//                                                                          ³
// Parses file into output IFF(s) (both already opened by main).            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void compile()
{
    assert(TxtIFF != 0);

    CurrentToken = yylex();
    while (CurrentToken)
    {
        ctf();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ctf                                                                      ³
//                                                                          ³
//          ctf :- include                                                  ³
//                 description                                              ³
//                 copyright                                                ³
//                 author                                                   ³
//                 extract                                                  ³
//                 texture                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ctf()
{
    switch (CurrentToken)
    {
        case YY_INCLUDE:
            include();
            break;
        case YY_DESC:
            description();
            break;
        case YY_COPYRIGHT:
            copyright();
            break;
        case YY_AUTHOR:
            author();
            break;
        case YY_EXTRACT:
            extract();
            break;
        case YY_TEXTURE:
            texture();
            break;
        default:
            error("Invalid operation: expected include, description, "
                  " copyright, author, extract, or texture statement");
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// include                                                                  ³
//                                                                          ³
//     include :- 'include' <string>                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void include()
{
    int err;

    YY_esc_allowed=0;
    match(YY_INCLUDE);
    YY_esc_allowed=1;

    switch(CurrentToken)
    {
        case YY_STRING:
            if (!(Flags & FLAGS_QUIET))
            {
                cout << "   °°° including '" << yytext << "' °°°\n";
            }

            err=yy_pushfile(yytext);
            switch (err)
            {
                case 0:
                    /* OK */
                    break;
                case 1:
                    error("too many nested includes");
                    break;
                case 2:
                    error("could not open include file");
                    break;
                case 3:
                    error("not enough memory to include file");
                default:
                    error("include failed");
                    break;
            }

            // Read first token from new file and continue processing
            // yywrap will undo include later

            CurrentToken = yylex();

            break;
        default:
            error("Invalid include command, expecting filename of CTF file to include");
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// description                                                              ³
//                                                                          ³
//     description :- 'description' <string>                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void description()
{
    match(YY_DESC);

    switch(CurrentToken)
    {
        case YY_STRING:
            yytext[yyleng]=0;
            if (TxtIFF->write(TxtIFF->makeid('D','E','S','C'),
                              yytext, yyleng))
            {
                print_error(TxtIFF,"Could not create description");
                exit(1);
            }

            match(YY_STRING);
            break;
        default:
            error("'description' must be followed by a string.");
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// copyright                                                                ³
//                                                                          ³
//     copyright :- 'copyright' <string>                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void copyright()
{
    match(YY_COPYRIGHT);

    switch(CurrentToken)
    {
        case YY_STRING:
            yytext[yyleng]=0;
            if (TxtIFF->write(TxtIFF->makeid('(','C',')',' '),
                              yytext, yyleng))
            {
                print_error(TxtIFF,"Could not create copyright");
                exit(1);
            }

            match(YY_STRING);
            break;
        default:
            error("'copyright' must be followed by a string.");
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// author                                                                   ³
//                                                                          ³
//     author :- 'author' <string>                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void author()
{
    match(YY_AUTHOR);

    switch(CurrentToken)
    {
        case YY_STRING:
            yytext[yyleng]=0;
            if (TxtIFF->write(TxtIFF->makeid('A','U','T','H'),
                              yytext, yyleng))
            {
                print_error(TxtIFF,"Could not create author");
                exit(1);
            }

            match(YY_STRING);
            break;
        default:
            error("'author' must be followed by a string.");
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// extract                                                                  ³
//                                                                          ³
//     extract :- 'extract' <string>                                        ³
//                          '{' (<string> [','])* '}'                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void extract()
{
    YY_esc_allowed=0;
    match(YY_EXTRACT);

    if (CurrentToken == YY_LBRACE)
    {
        match(YY_LBRACE);

        while (CurrentToken && CurrentToken != YY_RBRACE)
        {
            if (CurrentToken != YY_STRING)
            {
                error("'extract {' must be followed filenames and then '}'");
                exit(1);
            }

            if (!(Flags & FLAGS_QUIET))
            {
                cout << "Extracting '" << yytext << "'...\n";
            }

            XFParseIFF iff;
            if (iff.open(yytext, XF_OPEN_READ | XF_OPEN_DENYWRITE))
            {
                error("Failed to open input file for 'extract'");
                exit(1);
            }

            if (extract(iff))
                error("Extract failed.");

            iff.close();

            match(YY_STRING);

            if (CurrentToken == YY_COMMA)
                match(YY_COMMA);
        }

        YY_esc_allowed=1;
        match(YY_RBRACE);
    }
    else if (CurrentToken != YY_STRING)
    {
        error("'extract' must be followed by a filename or '{' filename(s) '}'");
        exit(1);
    }
    else
    {
        if (!(Flags & FLAGS_QUIET))
        {
            cout << "Extracting '" << yytext << "'...\n";
        }

        XFParseIFF iff;
        if (iff.open(yytext, XF_OPEN_READ | XF_OPEN_DENYWRITE))
        {
            error("Failed to open input file for 'extract'");
            exit(1);
        }

        if (extract(iff))
            error("Extract failed.");

        iff.close();

        YY_esc_allowed=1;
        match(YY_STRING);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// texture                                                                  ³
//                                                                          ³
//     texture :- 'texture' <string> txtopts '{' <string>* '}'              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void texture()
{
    match(YY_TEXTURE);

//ÄÄÄ Setup control flags
    dword ctrlfl=0;
    if (!(Flags & FLAGS_UNCOMPRESS))
        ctrlfl |= ESCH_TBLD_COMPRESS;
    if (Flags & FLAGS_XPARENT)
        ctrlfl |= ESCH_TBLD_TRANSP;

//ÄÄÄ Setup texture builder
    EschBuildTexture txt;
    if (txt.init(MAX_FRAMES))
    {
        error("out of memory for texture builder");
        exit(1);
    }

    if (CurrentToken != YY_STRING)
    {
        error("'texture' must be followed by texture name");
        exit(1);
    }

    if (find_txtname(yytext))
    {
        warning("texture name already exists in texture file");
    }
    else if (add_txtname(yytext))
    {
        error("Out of memory for texture names");
    }

    strncpy(txt.name,yytext,ESCH_MAX_NAME);

    match(YY_STRING);

//ÄÄÄ Match options
    while (CurrentToken && CurrentToken != YY_LBRACE)
    {
        txtopts(txt,ctrlfl);
    }

    YY_esc_allowed=0;
    match(YY_LBRACE);

//ÄÄÄ Output info
    if (!(Flags & FLAGS_QUIET))
    {
        cout << "Compiling texture '" << txt.name << "'...\n";
    }

//ÄÄÄ Match bitmap names
    while (CurrentToken && CurrentToken != YY_RBRACE)
    {
        if (CurrentToken != YY_STRING)
        {
            error("'texture' must be followed by '{' bitmap filenames and then '}'");
            exit(1);
        }

        if (!(Flags & FLAGS_QUIET))
        {
            cout << "   Adding frame '" << yytext << "'...\n";
        }

        strlwr(yytext);

        XFBitmap *bm = new XFBitmap;
        assert(bm != 0);

        xf_error_codes err=XF_ERR_NONE;
        if (strstr(yytext,".tga"))
        {
            XFParseTGA  tga;

            err=tga.nameread(yytext,bm);
        }
        else if (strstr(yytext,".pcx"))
        {
            XFParsePCX  pcx;

            err=pcx.nameread(yytext,bm);
        }
        else if (strstr(yytext,".lbm"))
        {
            XFParseLBM  lbm;

            err=lbm.nameread(yytext,bm);
        }
        else if (strstr(yytext,".cel"))
        {
            XFParseCEL  cel;

            err=cel.nameread(yytext,bm);
        }
        else if (strstr(yytext,".bmp"))
        {
            XFParseBMP  bmp;

            err=bmp.nameread(yytext,bm);
        }
        else if (strstr(yytext,".xeb"))
        {
            XFParseXEB  xeb;

            err=xeb.nameread(yytext,bm);
        }
        else
        {
            error("Unknown bitmap image extender\n");
            exit(1);
        }
        if (err)
        {
            error("Failed to load bitmap");
            exit(1);
        }

        if (txt.add_frame(bm))
        {
            error("Failed to add bitmap to texture");
            exit(1);
        }

        match(YY_STRING);

        if (CurrentToken == YY_COMMA)
            match(YY_COMMA);
    }

    YY_esc_allowed=1;
    match(YY_RBRACE);

    if (txt.nframes < 1)
    {
        error("'texture' needs at least one bitmap filename");
        exit(1);
    }

    if (!(ctrlfl & (ESCH_TBLD_8BIT | ESCH_TBLD_15BIT | ESCH_TBLD_TC)))
    {
        if (txt.bms[0]->bpp == 1)
        {
            ctrlfl |= ESCH_TBLD_8BIT;
        }
        else if (txt.bms[0]->bpp == 2)
        {
            ctrlfl |= ESCH_TBLD_15BIT;
        }
        else if (txt.bms[0]->bpp == 3)
        {
            ctrlfl |= ESCH_TBLD_TC;
            ctrlfl &= ~ESCH_TBLD_TRANSP;
        }
        else if (txt.bms[0]->bpp == 4)
        {
            ctrlfl |= ESCH_TBLD_TC | ESCH_TBLD_TRANSP;
        }
        else
        {
            error("Invalid bit-depth for frames");
            exit(1);
        }
    }

//ÄÄÄ Write texture
    esch_error_codes err = txt.save(TxtIFF, ctrlfl, Palette);
    if (err)
    {
        char buff[128];
        sprintf(buff,"Failed to write texture (error #%d)",err);
        error(buff);
        exit(1);
    }

    txt.release(1);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// txtopts                                                                  ³
//                                                                          ³
//     txtopts :- 'rle'                                                     ³
//                'uncompressed'                                            ³
//                'flags' '=' <uinteger>                                    ³
//                'transparent'                                             ³
//                'notransparent'                                           ³
//                'bpp' <integer>                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void txtopts(EschBuildTexture &tbld, dword &ctrlfl)
{
    switch (CurrentToken)
    {
        case YY_LBRACE:
            break;

        case YY_RLE:
            match(YY_RLE);
            ctrlfl |= ESCH_TBLD_COMPRESS;
            break;

        case YY_UNCOMPRESSED:
            match(YY_UNCOMPRESSED);
            ctrlfl &= ~ESCH_TBLD_COMPRESS;
            break;

        case YY_FLAGS:
            match(YY_FLAGS);
            match(YY_EQUAL);
            tbld.tflags = uexpr();
            break;

        case YY_TRANSPARENT:
            match(YY_TRANSPARENT);
            ctrlfl |= ESCH_TBLD_TRANSP;
            break;

        case YY_NOTRANSPARENT:
            match(YY_NOTRANSPARENT);
            ctrlfl &= ~ESCH_TBLD_TRANSP;
            break;

        case YY_BPP:
            {
                match(YY_BPP);
                match(YY_EQUAL);
                ctrlfl &= ~(ESCH_TBLD_8BIT | ESCH_TBLD_15BIT | ESCH_TBLD_TC);
                ulong bpp = uexpr();
                switch (bpp)
                {
                    case 1:
                        ctrlfl |= ESCH_TBLD_8BIT;
                        break;
                    case 2:
                        ctrlfl |= ESCH_TBLD_15BIT;
                        break;
                    case 3:
                        ctrlfl |= ESCH_TBLD_TC;
                        ctrlfl &= ~ESCH_TBLD_TRANSP;
                        break;
                    case 4:
                        ctrlfl |= ESCH_TBLD_TC | ESCH_TBLD_TRANSP;
                        break;

                    default:
                        error("bpp must be followed by a 1, 2, 3, or 4");
                        break;
                }
            }
            break;

        default:
            error("expected 'rle', 'uncompressed', 'flags', 'transparent', "
                  "'notransparent', 'bpp', or '{'");
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// uinteger/uexpr                                                           ³
//                                                                          ³
// Unsigned integer expression parsers.                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC ulong uinteger(void)
{
    ulong   t=0;

    if (CurrentToken == YY_INTEGER)
    {
        t=(ulong)YY_integer;
        match(YY_INTEGER);
    }

    return(t);
}


STATIC ulong uexpr(void)
{
    ulong   t1, t2;

    t1 = uterm();
    switch(CurrentToken)
    {
        case YY_PLUS:
            match(YY_PLUS);
            t2 = uterm();
            return (t1 + t2);
        case YY_MINUS:
            match(YY_MINUS);
            t2 = uterm();
            return (t1 - t2);
        default:
            return t1;
    }
}

STATIC ulong uterm(void)
{
    ulong   t1, t2;

    t1 = ufactor();
    switch (CurrentToken)
    {
        case YY_MULTIPLY:
            match(YY_MULTIPLY);
            t2 = uterm();
            return (t1 * t2);
        case YY_DIVIDE:
            match(YY_DIVIDE);
            t2 = uterm();
            if (!t2)
                error("Divide by zero in expression");
            return (t1 / t2);
        default:
            return t1;
    }
}

STATIC ulong ufactor(void)
{
    ulong   t;

    switch(CurrentToken)
    {
        case YY_LPAREN:
            match(YY_LPAREN);
            t = uexpr();
            match(YY_RPAREN);
            return (t);
        case YY_INTEGER:
            return (uinteger());
        case YY_PLUS:
            match(YY_PLUS);
            return uexpr();
        case YY_MINUS:
            error("Expected unsigned integer");
            break;
        default:
            error("Invalid unsigned integer expression");
            break;
    }

    return 0;
}
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// match                                                                    ³
//                                                                          ³
// Matches input token again target; if it failes, then it prints an error. ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void match(int tok)
{
    if (tok != CurrentToken)
    {
        switch (tok)
        {
            case YY_LBRACE:
                error("Expected a '{'");
                break;
            case YY_RBRACE:
                error("Expected a '}'");
                break;
            case YY_LPAREN:
                error("Expected a '('");
                break;
            case YY_RPAREN:
                error("Expected a ')'");
                break;
            case YY_COMMA:
                error("Expected a ','");
                break;
            case YY_EQUAL:
                error("Expected a '='");
                break;
            default:
                error("Unexpected token in source file");
                break;
        }
    }

    CurrentToken = yylex();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// error                                                                    ³
//                                                                          ³
// Emits an error and aborts processing.                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void error(const char *str)
{
    cout << " Error(" << YY_lineno << "): " << str << "\n";
    exit(1);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// warning                                                                  ³
//                                                                          ³
// Emits a warning.                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void warning(const char *str)
{
    cout << " Warning(" << YY_lineno << "): " << str << "\n";
}

//°±² End of module - eshtlibp.cpp ²±°

