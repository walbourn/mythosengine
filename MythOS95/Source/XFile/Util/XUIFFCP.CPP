//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//            Copyright (c) 1994-1996 by Charybdis Enterprises, Inc.
//                              All Rights Reserved.
//                        Microsoft Windows '95 Version
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
// xuiffcp.cpp
//
//     This is the parse module for the IFF compiler.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>

#include "debug.h"
#include "xfile.hpp"

#include "xuifftok.h"
#include "xuiffc.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define CHUNKOPTS_INTEL        0x1
#define CHUNKOPTS_MOTOROLA     0x2

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
void expand_work(ulong target);

//ÄÄ Local
STATIC void iff(void);
STATIC void form(void);
STATIC void chunk(void);
STATIC void opts(void);
STATIC void data(void);
STATIC void merge(void);
STATIC void include(void);
STATIC void bitmap(void);

STATIC long integer(void);
STATIC long expr(void);
STATIC long term(void);
STATIC long factor(void);

STATIC ulong uinteger(void);
STATIC ulong uexpr(void);
STATIC ulong uterm(void);
STATIC ulong ufactor(void);

STATIC double real(void);
STATIC double rexpr(void);
STATIC double rterm(void);
STATIC double rfactor(void);

STATIC void match(int tok);
extern "C" void error(const char *str);
extern "C" void warning(const char *str);

STATIC void add_to_work(byte v, ulong repcount);
STATIC void add_to_work(word v, ulong repcount);
STATIC void add_to_work(dword v, ulong repcount);
STATIC void add_to_work(const char *str, ulong slen, ulong maxlen=0);
STATIC void add_to_work_file(const char *fname);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄ External from scanner.
extern "C" long     YY_integer;
extern "C" double   YY_real;
extern "C" int      YY_lineno;
extern "C" int      YY_esc_allowed;
extern "C" char     *yytext;
extern "C" int      yyleng;

//ÄÄ External from main module.
extern XFParseIFF   *IFF;
extern byte         *Work;
extern ulong        WorkSize;
extern dword        Flags;

//ÄÄ Local         
STATIC dword        ChunkOpts;
STATIC ulong        ChunkSize;
STATIC ulong        ChunkMaxSize;
STATIC ulong        WorkCurrent;

STATIC int          CurrentToken;

STATIC char         *InvalidIds[] =
                    { "FORM",
                      "FOR0",
                      "FOR1",
                      "FOR2",
                      "FOR3",
                      "FOR4",
                      "FOR5",
                      "FOR6",
                      "FOR7",
                      "FOR8",
                      "FOR9",
                      "PROP",
                      "PRO0",
                      "PRO1",
                      "PRO2",
                      "PRO3",
                      "PRO4",
                      "PRO5",
                      "PRO6",
                      "PRO7",
                      "PRO8",
                      "PRO9",
                      "CAT ",
                      "CAT0",
                      "CAT1",
                      "CAT2",
                      "CAT3",
                      "CAT4",
                      "CAT5",
                      "CAT6",
                      "CAT7",
                      "CAT8",
                      "CAT9",
                      "LIST",
                      "LIS0",
                      "LIS1",
                      "LIS2",
                      "LIS3",
                      "LIS4",
                      "LIS5",
                      "LIS6",
                      "LIS7",
                      "LIS8",
                      "LIS9",
                      "    ",
                      "JJJJ" };


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
void compile(void)
{
    CurrentToken = yylex();
    while (CurrentToken)
    {
        iff();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// iff                                                                      ³
//                                                                          ³
//         iff :-  form                                                     ³
//                 chunk                                                    ³
//                 merge                                                    ³
//                 include                                                  ³
//                 bitmap                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void iff(void)
{
    switch (CurrentToken)
    {
        case YY_FORM:
            form();
            break;
        case YY_CHUNK:
            chunk();
            break;
        case YY_MERGE:
            merge();
            break;
        case YY_INCLUDE:
            include();
            break;
        case YY_BITMAP:
            bitmap();
            break;
        default:
            error("Invalid operation: expected a form, chunk, merge, include, or bitmap");
            break;                  
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// form                                                                     ³
//                                                                          ³
//     form :- 'form' id '{' iff '}'                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void form(void)
{
    ulong   i;
    dword   id;
    char    buff[5] = { 0, 0, 0, 0, 0 };

    match(YY_FORM);

    switch(CurrentToken)
    {

//ÄÄÄ Identifier
        case YY_STRING:
            if (strlen(yytext) != 4)
                error("Form identifier must be 4 characters");

            for(i=0; i < 4; i++)
            {
                if (yytext[i] != 0x20
                    && (yytext[i] < 48 || yytext[i] > 57)
                    && (yytext[i] < 65 || yytext[i] > 90))
                {
                    error ("Form identifier must consists of digits, upper-case characters, and space");
                }
            }

            for(i=0; i < sizeof(InvalidIds)/sizeof(char*); i++)
            {
                if (!strcmp(yytext,InvalidIds[i]))
                    error("Identifier reserved and cannot be used for FORM id");
            }

            id = IFF->makeid(yytext[0],yytext[1],yytext[2],yytext[3]);

            match(YY_STRING);

            if (IFF->newform(id))
            {
                print_error(IFF,"Could not create form");
                exit(1);
            }

            //ÄÄÄ Output information to screen
            if (!(Flags & FLAGS_QUIET))
            {
                for(i=0; i < IFF->depth; i++)
                    cout << "  ";
                cout << " ° form '" << IFF->strid(id,buff) << "' °\n";
            }

            break;
        default:
            error("'form' must be followed by a form id");
            break;
    }

//ÄÄÄ Body of FORM
    match(YY_LBRACE);

    while (CurrentToken && CurrentToken != YY_RBRACE)
    {
       iff();
    }

    IFF->leaveform();

    match(YY_RBRACE);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// chunk                                                                    ³
//                                                                          ³
//     chunk :- 'chunk' id opts '{' data* '}'                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void chunk(void)
{
    ulong   i;
    dword   id;
    char    buff[5] = { 0, 0, 0, 0, 0 };

    match(YY_CHUNK);

    switch(CurrentToken)
    {

//ÄÄÄ Identifier
        case YY_STRING:
           
            if (strlen(yytext) != 4)
                error("Chunk identifier must be 4 characters");

            for(i=0; i < 4; i++)
            {
                if (yytext[i] < 0x20 || yytext[i] > 0x7f)
                    error("Chunk identifier must be printable 7-bit characters");
            }

            for(i=0; i < sizeof(InvalidIds)/sizeof(char*); i++)
            {
                if (!strcmp(yytext,InvalidIds[i]))
                    error("Identifier reserved and cannot be used for CHUNK id");
            }

            id = IFF->makeid(yytext[0],yytext[1],yytext[2],yytext[3]);

            match(YY_STRING);

            break;
        default:
            error("'chunk' must be followed by a chunk id");
            break;
    }

//ÄÄÄ Chunk options
    ChunkOpts = CHUNKOPTS_INTEL;
    ChunkSize = 0;
    ChunkMaxSize = 0;
    while (CurrentToken && CurrentToken != YY_LBRACE)
    {
        opts();
    }

   //ÄÄÄ Output information to screen
    if (!(Flags & FLAGS_QUIET))
    {
        for(i=0; i < IFF->depth; i++)
            cout << "  ";
        cout << "   chunk '" << IFF->strid(id,buff) << "'";
        if (ChunkOpts)
        {
            if (ChunkOpts & CHUNKOPTS_INTEL)
                cout << "  intel byte-ordering";
            if (ChunkOpts & CHUNKOPTS_MOTOROLA)
                cout << "  motorola byte-ordering";
            if (ChunkSize)
                cout << "  size=" << ChunkSize;
            if (ChunkMaxSize)
                cout << "  maxsize=" << ChunkMaxSize;
        }
        cout << "\n";
    }

//ÄÄÄ Body of CHUNK
    match(YY_LBRACE);

    WorkCurrent=0;
    while (CurrentToken && CurrentToken != YY_RBRACE)
    {
        data();
    }

    if (WorkCurrent)
    {
        if (ChunkSize && WorkCurrent != ChunkSize)
        {
            char    buff[128];

            sprintf(buff,
                    "Actual chunk size of %d doesn't match size target of %d",
                    WorkCurrent,
                    ChunkSize);

            error(buff);
        }

        if (ChunkMaxSize && WorkCurrent > ChunkMaxSize)
        {
            char    buff[128];

            sprintf(buff,
                    "Actual chunk size of %d exceeds maximum size %d",
                    WorkCurrent,
                    ChunkMaxSize);

            error(buff);
        }

        IFF->write(id,Work,WorkCurrent);
    }
    else if (!(Flags & FLAGS_EMPTYOK))
        warning("Empty chunk");

    match(YY_RBRACE);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// opts                                                                     ³
//                                                                          ³
//     opts :- 'intel'                                                      ³
//             'bigendian'                                                  ³
//             'motorola'                                                   ³
//             'littleendian'                                               ³
//             'size' <uexpr>                                               ³
//             'maxsize' <uexpr>                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void opts(void)
{
    switch(CurrentToken)
    {
        case YY_LBRACE:
            /* LBrace terminates option section for chunk */
            break;

        case YY_INTEL:
            match(YY_INTEL);
            ChunkOpts |= CHUNKOPTS_INTEL;
            ChunkOpts &= ~CHUNKOPTS_MOTOROLA;
            break;
        case YY_BIGENDIAN:
            match(YY_BIGENDIAN);
            ChunkOpts |= CHUNKOPTS_INTEL;
            ChunkOpts &= ~CHUNKOPTS_MOTOROLA;
            break;

        case YY_MOTOROLA:
            match(YY_MOTOROLA);
            ChunkOpts |= CHUNKOPTS_MOTOROLA;
            ChunkOpts &= ~CHUNKOPTS_INTEL;
            break;
        case YY_LITTLEENDIAN:
            match(YY_LITTLEENDIAN);
            ChunkOpts |= CHUNKOPTS_MOTOROLA;
            ChunkOpts &= ~CHUNKOPTS_INTEL;
            break;

        case YY_SIZE:
            if (ChunkMaxSize)
                error("Incompatable chunk options: 'size' and 'maxsize'");

            match(YY_SIZE);

            ChunkSize=uexpr();

            if (!ChunkSize)
                error("Expression after 'size' must be positive and non-zero");

            break;

        case YY_MAXSIZE:
            if (ChunkSize)
                error("Incompatable chunk options: 'size' and 'maxsize'");

            match(YY_MAXSIZE);

            ChunkMaxSize=uexpr();

            if (!ChunkMaxSize)
                error("Expression after 'maxsize' must be positive and non-zero");

            break;

        default:
            error("Expected a '{', 'intel', 'motorola', 'size', or 'maxsize'");
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// data                                                                     ³
//                                                                          ³
//     data :-                                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void data(void)
{
    long    t;
    ulong   ut;
    ulong   repcount;
    double  rt;

    union
    {
        float st;
        dword sdword;
    } rsingle;
    union
    {
       double dt;
       dword  dqword[2];
    } rdouble;

    switch(CurrentToken)
    {
        case YY_RBRACE:
            /* RBrace terminates option section for chunk */
            break;

        case YY_BYTE:
            match(YY_BYTE);

            if (CurrentToken == YY_LBRACE)
            {
                match (YY_LBRACE);
                for(;;)
                {
                    t=expr();

                    if (t < -128 || t > 127)
                        warning("Expression exceeds size of byte");

                    repcount=1;
                    if (CurrentToken == YY_LBRACKET)
                    {
                        match(YY_LBRACKET);
                        repcount = uexpr();
                        match(YY_RBRACKET);
                    }
               
                    add_to_work((byte)(char)t,repcount);

                    if (CurrentToken == YY_RBRACE)
                        break;
                    match (YY_COMMA);
                }
                match (YY_RBRACE);
            }
            else
            {
                t=expr();

                if (t < -128 || t > 127)
                    warning("Expression exceeds size of byte");

                repcount=1;
                if (CurrentToken == YY_LBRACKET)
                {
                    match(YY_LBRACKET);
                    repcount = uexpr();
                    match(YY_RBRACKET);
                }
               
                add_to_work((byte)(char)t,repcount);
            }
            break;

        case YY_UBYTE:
            match(YY_UBYTE);

            if (CurrentToken == YY_LBRACE)
            {
                match (YY_LBRACE);
                for(;;)
                {
                    ut=uexpr();

                    if (ut < 0 || ut > 255)
                        warning("Expression exceeds size of unsigned byte");

                    repcount=1;
                    if (CurrentToken == YY_LBRACKET)
                    {
                        match(YY_LBRACKET);
                        repcount = uexpr();
                        match(YY_RBRACKET);
                    }

                    add_to_work((byte)ut,repcount);

                    if (CurrentToken == YY_RBRACE)
                        break;
                    match(YY_COMMA);
                }
                match (YY_RBRACE);
            }
            else
            {
                ut=uexpr();

                if (ut < 0 || ut > 255)
                    warning("Expression exceeds size of unsigned byte");

                repcount=1;
                if (CurrentToken == YY_LBRACKET)
                {
                    match(YY_LBRACKET);
                    repcount = uexpr();
                    match(YY_RBRACKET);
                }

                add_to_work((byte)ut,repcount);
            }
            break;

        case YY_WORD:
            match(YY_WORD);

            if (CurrentToken == YY_LBRACE)
            {
                match (YY_LBRACE);
                for(;;)
                {
                    t=expr();
                    
                    if (t < (-32768) || t > 32767)
                        warning("Expression exceeds size of word");
                    
                    repcount=1;
                    if (CurrentToken == YY_LBRACKET)
                    {
                        match(YY_LBRACKET);
                        repcount = uexpr();
                        match(YY_RBRACKET);
                    }

                    add_to_work((word)(short)t,repcount);

                    if (CurrentToken == YY_RBRACE)
                        break;
                    match(YY_COMMA);
                }
                match (YY_RBRACE);
            }
            else
            {
                t=expr();

                if (t < (-32768) || t > 32767)
                    warning("Expression exceeds size of word");

                repcount=1;
                if (CurrentToken == YY_LBRACKET)
                {
                    match(YY_LBRACKET);
                    repcount = uexpr();
                    match(YY_RBRACKET);
                }

                add_to_work((word)(short)t,repcount);
            }
            break;

        case YY_UWORD:
            match(YY_UWORD);

            if (CurrentToken == YY_LBRACE)
            {
                match (YY_LBRACE);
                for(;;)
                {
                    ut=uexpr();
                    
                    if (ut < 0 || ut > 65535)
                        warning("Expression exceeds size of unsigned word");
                    
                    repcount=1;
                    if (CurrentToken == YY_LBRACKET)
                    {
                        match(YY_LBRACKET);
                        repcount = uexpr();
                        match(YY_RBRACKET);
                    }

                    add_to_work((word)ut,repcount);

                    if (CurrentToken == YY_RBRACE)
                        break;
                    match(YY_COMMA);
                }
                match (YY_RBRACE);
            }
            else
            {
                ut=uexpr();

                if (ut < 0 || ut > 65535)
                    warning("Expression exceeds size of unsigned word");

                repcount=1;
                if (CurrentToken == YY_LBRACKET)
                {
                    match(YY_LBRACKET);
                    repcount = uexpr();
                    match(YY_RBRACKET);
                }

                add_to_work((word)ut,repcount);
            }
            break;

        case YY_DWORD:
            match(YY_DWORD);

            if (CurrentToken == YY_LBRACE)
            {
                match (YY_LBRACE);
                for(;;)
                {
                    t=expr();

                    repcount=1;
                    if (CurrentToken == YY_LBRACKET)
                    {
                        match(YY_LBRACKET);
                        repcount = uexpr();
                        match(YY_RBRACKET);
                    }

                    add_to_work((dword)t,repcount);

                    if (CurrentToken == YY_RBRACE)
                        break;
                    match(YY_COMMA);
                }
                match (YY_RBRACE);
            }
            else
            {
                t=expr();

                repcount=1;
                if (CurrentToken == YY_LBRACKET)
                {
                    match(YY_LBRACKET);
                    repcount = uexpr();
                    match(YY_RBRACKET);
                }

                add_to_work((dword)t,repcount);
            }
            break;

        case YY_UDWORD:
            match(YY_UDWORD);

            if (CurrentToken == YY_LBRACE)
            {
                match (YY_LBRACE);
                for(;;)
                {
                    ut=uexpr();

                    repcount=1;
                    if (CurrentToken == YY_LBRACKET)
                    {
                        match(YY_LBRACKET);
                        repcount = uexpr();
                        match(YY_RBRACKET);
                    }

                    add_to_work((dword)ut,repcount);

                    if (CurrentToken == YY_RBRACE)
                        break;
                    match(YY_COMMA);
                }
                match (YY_RBRACE);
            }
            else
            {
                ut=uexpr();

                repcount=1;
                if (CurrentToken == YY_LBRACKET)
                {
                    match(YY_LBRACKET);
                    repcount = uexpr();
                    match(YY_RBRACKET);
                }

                add_to_work((dword)ut,repcount);
            }
            break;

        case YY_TEXT:
            match(YY_TEXT);

            if (CurrentToken == YY_LBRACE)
            {
                match (YY_LBRACE);
                for(;;)
                {
                    if (CurrentToken != YY_STRING)
                    {
                        error("Expected a text string");
                    }

                    add_to_work(yytext,yyleng);
                    match(YY_STRING);

                    if (CurrentToken == YY_RBRACE)
                        break;
                    match(YY_COMMA);
                }
                match (YY_RBRACE);
            }
            else
            {
                if (CurrentToken != YY_STRING)
                {
                    error("Expected a text string");
                }

                add_to_work(yytext,yyleng);
                match(YY_STRING);
            }
            break;

        case YY_NTEXT:
            match(YY_NTEXT);

            if (CurrentToken == YY_LBRACE)
            {
                match (YY_LBRACE);
                for(;;)
                {
                    ulong size = uexpr();
                    if (!size)
                    {
                        error("'ntext' requires a positive, non-zero size value.");
                    }

                    if (CurrentToken != YY_STRING)
                    {
                        error("Expected a text string");
                    }

                    if ((ulong)yyleng > size)
                    {
                        warning("String truncated");
                    }

                    add_to_work(yytext,yyleng,size);
                    match(YY_STRING);

                    if (CurrentToken == YY_RBRACE)
                        break;
                    match(YY_COMMA);
                }
                match (YY_RBRACE);
            }
            else
            {
                ulong size = uexpr();
                if (!size)
                {
                    error("'ntext' requires a positive, non-zero size value.");
                }

                if (CurrentToken != YY_STRING)
                {
                    error("Expected a text string");
                }

                if ((ulong)yyleng > size)
                {
                    warning("'ntext' string truncated");
                }

                add_to_work(yytext,yyleng,size);
                match(YY_STRING);
            }
            break;

       case YY_BINARY:
            match(YY_BINARY);

            if (CurrentToken != YY_STRING)
            {
                error("Expected a filename");
            }

            add_to_work_file(yytext);
            match(YY_STRING);
            break;

        case YY_FLOAT:
            match(YY_FLOAT);

            if (CurrentToken == YY_LBRACE)
            {
                match (YY_LBRACE);
                for(;;)
                {
                    rsingle.st = float (rexpr());

                    repcount=1;
                    if (CurrentToken == YY_LBRACKET)
                    {
                        match(YY_LBRACKET);
                        repcount = uexpr();
                        match(YY_RBRACKET);
                    }

                    add_to_work(rsingle.sdword,repcount);

                    if (CurrentToken == YY_RBRACE)
                        break;
                    match(YY_COMMA);
                }
                match (YY_RBRACE);
            }
            else
            {
                rsingle.st = float (rexpr());

                repcount=1;
                if (CurrentToken == YY_LBRACKET)
                {
                    match(YY_LBRACKET);
                    repcount = uexpr();
                    match(YY_RBRACKET);
                }

                add_to_work(rsingle.sdword,repcount);
            }
            break;

       case YY_DOUBLE:
            match(YY_DOUBLE);

            if (CurrentToken == YY_LBRACE)
            {
                match (YY_LBRACE);
                for(;;)
                {
                    rdouble.dt = rexpr();

                    repcount=1;
                    if (CurrentToken == YY_LBRACKET)
                    {
                        match(YY_LBRACKET);
                        repcount = uexpr();
                        match(YY_RBRACKET);
                    }

                    if (ChunkOpts & CHUNKOPTS_INTEL) 
                    {
                        add_to_work(rdouble.dqword[0],repcount);
                        add_to_work(rdouble.dqword[1],repcount);
                    }
                    else
                    {
                        add_to_work(rdouble.dqword[1],repcount);
                        add_to_work(rdouble.dqword[0],repcount);
                    }

                    if (CurrentToken == YY_RBRACE)
                        break;
                    match(YY_COMMA);
                }
                match (YY_RBRACE);
            }
            else
            {
                rdouble.dt = rexpr();

                repcount=1;
                if (CurrentToken == YY_LBRACKET)
                {
                    match(YY_LBRACKET);
                    repcount = uexpr();
                    match(YY_RBRACKET);
                }

                if (ChunkOpts & CHUNKOPTS_INTEL) 
                {
                    add_to_work(rdouble.dqword[0],repcount);
                    add_to_work(rdouble.dqword[1],repcount);
                }
                else
                {
                    add_to_work(rdouble.dqword[1],repcount);
                    add_to_work(rdouble.dqword[0],repcount);
                }
            }
            break;

       case YY_FIXED16:
            match(YY_FIXED16);

            if (CurrentToken == YY_LBRACE)
            {
                match (YY_LBRACE);
                for(;;)
                {
                    rt=rexpr();

                    if ((rt < -32768.0) || (rt > 32767.0))
                        warning("Expression exceeds size of fixed16");

                    repcount=1;
                    if (CurrentToken == YY_LBRACKET)
                    {
                        match(YY_LBRACKET);
                        repcount = uexpr();
                        match(YY_RBRACKET);
                    }

                    add_to_work((dword)(rt * 65536.0),repcount);

                    if (CurrentToken == YY_RBRACE)
                        break;
                    match(YY_COMMA);
                }
                match (YY_RBRACE);
            }
            else
            {

                rt=rexpr();

                if ((rt < -32768.0) || (rt > 32767.0))
                    warning("Expression exceeds size of fixed16");

                repcount=1;
                if (CurrentToken == YY_LBRACKET)
                {
                    match(YY_LBRACKET);
                    repcount = uexpr();
                    match(YY_RBRACKET);
                }

                add_to_work((dword)(rt * 65536.0),repcount);
            }
            break;

       default:
           error("Expected a data item");
           break;
   }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// merge                                                                    ³
//                                                                          ³
//     merge :- 'merge' <string>                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void merge(void)
{
    ulong       i;
    ulong       size;

    XFParseIFF  iffm( ((Flags & FLAGS_RIFF) ? XF_IFF_RIFF : 0)
                     | ((Flags & FLAGS_NOPAD) ? XF_IFF_NOPAD : 0) );

    char buff[5] = { 0, 0, 0, 0, 0 };

    YY_esc_allowed=0;
    match(YY_MERGE);
    YY_esc_allowed=1;

    switch(CurrentToken)
    {
        case YY_STRING:
        
            if (!(Flags & FLAGS_QUIET))
            {
                for(i=0; i < IFF->depth; i++)
                    cout << "  ";
                cout << "   merging '" << yytext << "'\n";
            }
     
            if (iffm.open(yytext,XF_OPEN_READ))
            {
                print_error(&iffm,"Cannot open merge file");
                exit(1);
            }
            else
            {
     
                while (iffm.next() == XF_ERR_NONE)
                {
                    size=iffm.chunkSize;
     
                    if (!(Flags & FLAGS_QUIET))
                    {
                        for(i=0; i < IFF->depth; i++)
                            cout << "  ";
                        cout << "     ";

                        if (iffm.makeid('F','O','R','M') == iffm.chunkid)
                        {
                            cout << "FORM '" << iffm.strid(iffm.formid,buff);
                        }
                        else if (iffm.makeid('R','I','F','F') == iffm.chunkid)
                        {
                            cout << "RIFF '" << iffm.strid(iffm.formid,buff);
                        }
                        else
                        {
                            cout << "'" << iffm.strid(iffm.chunkid,buff);
                        }
                        cout << "' " << iffm.chunkSize << " bytes\n";
                    }
     
                    if (size > WorkSize)
                    {
                        expand_work(size);
                    }
                    
                    if (iffm.read(Work))
                    {
                        print_error(&iffm,"Failed to read merge chunk");
                        iffm.close();
                        exit(1);
                    }
     
                    if (IFF->write(iffm.chunkid,Work,size))
                    {
                        print_error(IFF,"Failed to write merge chunk");
                        iffm.close();
                        exit(1);
                    }
     
                }
     
                iffm.close();
            }
     
            match(YY_STRING);
            break;
        default:
            error("Invalid merge command, expecting filename of IFF file to merge");
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// include                                                                  ³
//                                                                          ³
//     include :- 'include' <string>                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void include(void)
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
            error("Invalid include command, expecting filename of CIF file to include");
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// bitmap                                                                   ³
//                                                                          ³
//     bitmap :- 'bitmap' <string>                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void bitmap(void)
{
    int err;
    ulong i;

    YY_esc_allowed=0;
    match(YY_BITMAP);
    YY_esc_allowed=1;

    if (CurrentToken !=  YY_STRING)
        error("Invalid bitmap command, expecting filename of bitmap file to insert");

    if (!(Flags & FLAGS_QUIET))
    {
        for(i=0; i < IFF->depth; i++)
            cout << "  ";
        cout << "   inserting bitmap '" << yytext << "' as form ";
        
        if (Flags & FLAGS_XEB)
        {
            cout << "'XFEB'\n";
        }
        else
        {
            cout << "'ILBM'\n";
        }
    }

//ÄÄÄ Determine extender of file
    char buff[4];

    memset(buff,0,sizeof(buff));
    for(const char *c=yytext + strlen(yytext) - 1; *c; c--)
    {
        if (*c == '.')
        {
            strncpy(buff,c+1,3);
            break;
        }
    }
    strlwr(buff);

//ÄÄÄ Load bitmap, if possible
    XFBitmap bm;

    if (!strcmp(buff,"bmp"))
    {
        XFParseBMP  bmp(&bm);

        if (bmp.nameread(yytext))
            error("Failed to read file as Windows BMP format");
    }
    else if (!strcmp(buff,"pcx"))
    {
        XFParsePCX  pcx(&bm);

        if (pcx.nameread(yytext))
            error("Failed to read file as PCX format");
    }
    else if (!strcmp(buff,"lbm"))
    {
        XFParseLBM  lbm(&bm);

        if (lbm.nameread(yytext))
            error("Failed to read file as LBM format");
    }
    else if (!strcmp(buff,"cel"))
    {
        XFParseCEL  cel(&bm);

        if (cel.nameread(yytext))
            error("Failed to read file as CEL format");
    }
    else if (!strcmp(buff,"tga"))
    {
        XFParseTGA  tga(&bm);

        if (tga.nameread(yytext))
            error("Failed to read file as TGA format");
    }
    else if (!strcmp(buff,"xeb"))
    {
        XFParseXEB  xeb(&bm);

        if (xeb.nameread(yytext))
            error("Failed to read file as XEB format");
    }

//ÄÄÄ Output image info
    if (!(Flags & FLAGS_QUIET))
    {
        for(i=0; i < IFF->depth; i++)
            cout << "  ";
        cout << "      " << (int)bm.width << " by " << (int)bm.height
             << "  " << (int)bm.bpp << " bytes/pixel\n";
    }

//ÄÄÄ Insert into current IFF
    if (Flags & FLAGS_XEB)
    {
        XFParseXEB  xeb(&bm);

        err=xeb.write(IFF);
        if (err == XF_ERR_NOTSUPPORTED)
            error("Image format not supported for write by XFile as XEB");
        else if (err)
            error("Failed to insert image as XEB");
    }
    else
    {
        XFParseLBM  lbm(&bm);

        err=lbm.write(IFF);
        if (err == XF_ERR_NOTSUPPORTED)
            error("Image format not supported for write by XFile as LBM");
        else if (err)
            error("Failed to insert image as LBM");
    }

    match(YY_STRING);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// integer/expr                                                             ³
//                                                                          ³
// Signed integer expression parsers.                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC long integer(void)
{
    long    t=0;

    if (CurrentToken == YY_INTEGER)
    {
        t=YY_integer;
        match(YY_INTEGER);
    }
    else
        error("Integer expected");
    
    return(t);
}

STATIC long expr(void)
{
    long    t1, t2;

    t1 = term();
    switch(CurrentToken)
    {
        case YY_PLUS:
            match(YY_PLUS);
            t2 = term();
            return (t1 + t2);
        case YY_MINUS:
            match(YY_MINUS);
            t2 = term();
            return (t1 - t2);
        default:
            return t1;
    }
}

STATIC long term(void)
{
    long    t1, t2;

    t1 = factor();
    switch (CurrentToken)
    {
        case YY_MULTIPLY:
            match(YY_MULTIPLY);
            t2 = term();
            return (t1 * t2);
        case YY_DIVIDE:
            match(YY_DIVIDE);
            t2 = term();
            if (!t2)
                error("Divide by zero in expression");
            return (t1 / t2);
        default:
            return t1;
    }
}

STATIC long factor(void)
{
    long    t;

    switch(CurrentToken)
    {
        case YY_LPAREN:
            match(YY_LPAREN);
            t = expr();
            match(YY_RPAREN);
            return (t);
        case YY_INTEGER:
            return (integer());
        case YY_FLOAT:
            error("Floating-point valid is invalid in integer expression");
            break;
        case YY_PLUS:
            match(YY_PLUS);
            return expr();
        case YY_MINUS:
            match(YY_MINUS);
            return -expr();
        default:
            error("Invalid integer expression");
            break;
    }

    return 0;
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
        case YY_FLOAT:
            error("Floating-point valid is invalid in unsigned integer expression");
            break;
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
// real/rexpr                                                               ³
//                                                                          ³
// Signed floating-point expression parsers.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC double real(void)
{
    double  t=0;

    if (CurrentToken == YY_REAL)
    {
        t=YY_real;
        match(YY_REAL);
    }
    else if (CurrentToken == YY_INTEGER)
    {
        t=(double)YY_integer;
        match(YY_INTEGER);
    }
    else
        error("Real or integer expected");

    return(t);
}

STATIC double rexpr(void)
{
    double  t1, t2;

    t1 = rterm();
    switch(CurrentToken)
    {
        case YY_PLUS:
            match(YY_PLUS);
            t2 = rterm();
            return (t1 + t2);
        case YY_MINUS:
            match(YY_MINUS);
            t2 = rterm();
            return (t1 - t2);
        default:
            return t1;
    }
}

STATIC double rterm(void)
{
   double  t1, t2;

   t1 = rfactor();
   switch (CurrentToken)
   {
       case YY_MULTIPLY:
           match(YY_MULTIPLY);
           t2 = rterm();
           return (t1 * t2);
       case YY_DIVIDE:
           match(YY_DIVIDE);
           t2 = rterm();
           if (!t2)
               error("Divide by zero in expression");
           return (t1 / t2);
       default:
           return t1;
    }
}

STATIC double rfactor(void)
{
    double  t;

    switch(CurrentToken)
    {
        case YY_LPAREN:
            match(YY_LPAREN);
            t = rexpr();
            match(YY_RPAREN);
            return (t);
        case YY_INTEGER:
        case YY_REAL:
            return (real());
        case YY_PLUS:
            match(YY_PLUS);
            return rexpr();
        case YY_MINUS:
            match(YY_MINUS);
            return -rexpr();
        default:
            error("Invalid real expression");
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
            case YY_LBRACKET:
                error("Expected a '['");
                break;
            case YY_RBRACKET:
                error("Expected a ']'");
                break;
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// add_to_work                                                              ³
//                                                                          ³
// Adds data to the work buffer.                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void add_to_work(byte b, ulong repcount)
{
    ulong i;

    if (WorkCurrent + repcount >= WorkSize)
    {
        expand_work(WorkCurrent+repcount);
    }

    for(i=0; i < repcount; i++)
        Work[WorkCurrent++] = b;
}

STATIC void add_to_work(word w, ulong repcount)
{
    ulong i;

    if (WorkCurrent + (repcount * sizeof(word)) >= WorkSize)
    {
        expand_work(WorkCurrent+(repcount*sizeof(word)));
    }

    for(i=0; i < repcount; i++)
    {
        if (ChunkOpts & CHUNKOPTS_INTEL)
        {
            Work[WorkCurrent++] = (byte)(w & 0xff);
            Work[WorkCurrent++] = (byte)((w>>8) & 0xff);
        }
        else
        {
            Work[WorkCurrent++] = (byte)((w>>8) & 0xff);
            Work[WorkCurrent++] = (byte)(w & 0xff);
        }
    }
}

STATIC void add_to_work(dword d, ulong repcount)
{
    ulong i;

    if (WorkCurrent + (repcount * sizeof(dword)) >= WorkSize)
    {
        expand_work(WorkCurrent+(repcount*sizeof(dword)));
    }

    for(i=0; i < repcount; i++)
    {
        if (ChunkOpts & CHUNKOPTS_INTEL)
        {
            Work[WorkCurrent++] = (byte)(d & 0xff);
            Work[WorkCurrent++] = (byte)((d>>8) & 0xff);
            Work[WorkCurrent++] = (byte)((d>>16) & 0xff);
            Work[WorkCurrent++] = (byte)((d>>24) & 0xff);
        }
        else
        {
            Work[WorkCurrent++] = (byte)((d>>24) & 0xff);
            Work[WorkCurrent++] = (byte)((d>>16) & 0xff);
            Work[WorkCurrent++] = (byte)((d>>8) & 0xff);
            Work[WorkCurrent++] = (byte)(d & 0xff);
        }
    }
}

STATIC void add_to_work(const char *str, ulong slen, ulong maxlen)
{
    if (!maxlen)
    {
        if ((WorkCurrent+slen+1)>= WorkSize)
        {
            expand_work(WorkCurrent+slen+1);
        }

        memcpy((char*)&Work[WorkCurrent],str,slen);
        WorkCurrent += slen;
        Work[WorkCurrent++]=0;
    }
    else
    {
        if ((WorkCurrent+maxlen)>= WorkSize)
        {
            expand_work(WorkCurrent+maxlen);
        }

        ulong count = (slen < maxlen) ? slen : maxlen;

        memcpy((char*)&Work[WorkCurrent],str,count);
        WorkCurrent += count;
        while (count < maxlen)
        {
            Work[WorkCurrent++] = 0;
            count++;
        }
    }
}

STATIC void add_to_work_file(const char *fname)
{
    ulong       size;
    XFileDisk   xf;

    if (xf.open(fname,XF_OPEN_READ))
    {
        error("Failed to open binary file");
    }

    size = xf.getsize();

    if (WorkCurrent + size >= WorkSize)
    {
        expand_work(WorkCurrent+size);
    }

    if (xf.read(&Work[WorkCurrent],size) != size)
    {
        error("Failed during read of data from binary file");
    }

    WorkCurrent += size;

    xf.close();
}

//°±² End of module - xuiffcp.cpp ²±°

