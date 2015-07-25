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
//                       Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
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
// gstringp.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>
#include <string.h>

#include "debug.h"
#include "xfile.hpp"

#include "gstring.h"

#include "gbrgfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define MAX_OPTS_STRING 128
#define MAX_ID          32

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄ External from scanner.
extern "C" int yylex();
extern "C" int yy_pushfile(const char *fname);

//ÄÄ External from main module.
void print_error(XFParseIFF &xp, char *s=0);
void expand_work(ulong target);

//ÄÄ Local
STATIC void cst(void);
STATIC void stringtable(void);
STATIC void opts(GBergFileTextHDR *hdr, char *auth, char *desc, char *copy);
STATIC void data(ulong *count);
STATIC void include(void);

STATIC ulong uinteger(void);
STATIC ulong uexpr(void);
STATIC ulong uterm(void);
STATIC ulong ufactor(void);

STATIC void match(int tok);
STATIC void error(const char *str);
STATIC void warning(const char *str);

STATIC void add_to_work(ulong num, const char *str, ulong slen);
STATIC void append_to_work(const char *str, ulong slen);

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
extern XFParseIFF   IFF;
extern XFileDOS     header;
extern byte         *Work;
extern ulong        WorkSize;
extern dword        Flags;

//ÄÄ Local
STATIC ulong        WorkCurrent;

STATIC int          CurrentToken;

STATIC ulong        CurrentNumber;

STATIC char         cpp_comment[] =
{
    "//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\r\n"
    "// Gutenberg -- Font and external string support                            ³\r\n"
    "// (C) 1995-1999 by Charybdis Enterprises, Inc.  All Rights Reserved.            ³\r\n"
    "//                                                                          ³\r\n"
    "// String identifier header file for C++                                    ³\r\n"
    "//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\r\n"
};

STATIC char         c_comment[] =
{
    "/*ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\r\n"
    " * Gutenberg -- Font and external string support                            ³\r\n"
    " * (C) 1995-1999 by Charybdis Enterprises, Inc.  All Rights Reserved.            ³\r\n"
    " *                                                                          ³\r\n"
    " * String identifier header file for C/C++                                  ³\r\n"
    " *ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\r\n"
    " */\r\n"
};

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
    char buf[128];

    if (Flags & FLAGS_MAKE_H)
        header.write (c_comment, sizeof(c_comment)-1);
    else
        header.write (cpp_comment, sizeof(cpp_comment)-1);

    CurrentToken = yylex();
    while (CurrentToken) {
        cst();
    }

    if (Flags & FLAGS_MAKE_H)
        strcpy (buf, "\r\n/* EOF */\r\n");
    else
        strcpy (buf, "\r\n// EOF\r\n");
    header.write (buf, strlen (buf));
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// cst                                                                      ³
//                                                                          ³
//         cst :-  stringtable                                              ³
//                 include                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void cst(void)
{
    switch (CurrentToken) {
        case YY_STRINGTABLE:
            stringtable();
            break;
        case YY_INCLUDE:
            include();
            break;
        default:
            error("Invalid operation, expected a stringtable or include block");
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// stringtable                                                              ³
//                                                                          ³
//     stringtable :- 'stringtable' opts '{' data* '}'                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void stringtable(void)
{
    GBergFileTextHDR    hdr;
    char                auth[MAX_OPTS_STRING];
    char                desc[MAX_OPTS_STRING];
    char                copy[MAX_OPTS_STRING];
    char                buf[128];

    WorkCurrent=0;
    CurrentNumber=1;

    memset(&hdr,0,sizeof(GBergFileTextHDR));

    auth[0]=desc[0]=copy[0]=0;

    match(YY_STRINGTABLE);

    if (!(Flags & FLAGS_QUIET))
    {
        cout << "\n   ° StringTable °\n";
    }

    while (CurrentToken && CurrentToken != YY_LBRACE)
    {
        opts(&hdr,auth,desc,copy);
    }

    if (!(Flags & FLAGS_QUIET))
    {
        if (*hdr.name)
            cout << "        Name: " << hdr.name << "\n";
        if (*auth)
            cout << "      Author: " << auth << "\n";
        if (*desc)
            cout << "        Desc: " << desc << "\n";
        if (*copy)
            cout << "   Copyright: " << copy << "\n";
    }

    if (!*hdr.name)
        error("'name' required for string table");

    match(YY_LBRACE);

    if (Flags & FLAGS_MAKE_H)
        sprintf(buf,"\r\n/* Identifiers for table: %s */\r\n",hdr.name);
    else
        sprintf(buf,"\r\n// Identifiers for table: %s\r\n",hdr.name);
    header.write(buf,strlen(buf));

    while (CurrentToken && CurrentToken != YY_RBRACE)
    {
        data(&hdr.number_of_strings);
    }

    match(YY_RBRACE);

    if (!(Flags & FLAGS_QUIET))
    {
        cout << "       Count: " << hdr.number_of_strings << "\n";
    }

//ÄÄÄ Output Data
    if (!WorkCurrent)
    {
        warning("String table is empty, not written");
    }
    else {

        if (IFF.newform(IFF.makeid('G','T','X','T')))
        {
            print_error(IFF,"Could not create form");
            exit(1);
        }

        //ÄÄÄ Output header and information blocks
        if (IFF.write(IFF.makeid('H','D','R',' '),&hdr,sizeof(GBergFileTextHDR)))
        {
            print_error(IFF,"Write of 'HDR ' chunk failed");
            exit(1);
        }
        if (*auth && !(Flags & FLAGS_RELEASE))
        {
            if (IFF.write(IFF.makeid('A','U','T','H'),auth,strlen(auth)+1))
            {
                print_error(IFF,"Write of 'AUTH' chunk failed");
                exit(1);
            }
        }
        if (*desc && !(Flags & FLAGS_RELEASE))
        {
            if (IFF.write(IFF.makeid('D','E','S','C'),desc,strlen(desc)+1))
            {
                print_error(IFF,"Write of 'DESC' chunk failed");
                exit(1);
            }
        }
        if (*copy)
        {
            if (IFF.write(IFF.makeid('(','C',')',' '),copy,strlen(copy)+1))
            {
                print_error(IFF,"Write of '(C) ' chunk failed");
                exit(1);
            }
        }

        if (IFF.write(IFF.makeid('B','O','D','Y'),Work,WorkCurrent))
        {
            print_error(IFF,"Write of 'BODY' chunk failed");
            exit(1);
        }

        //ÄÄÄ End form
        IFF.leaveform();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// opts                                                                     ³
//                                                                          ³
//     opts :- 'name' <string>                                              ³
//             'author' <string>                                            ³
//             'description' <string>                                       ³
//             'copyright' <string>                                         ³
//             include                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void opts(GBergFileTextHDR *hdr, char *auth, char *desc, char *copy)
{
    switch(CurrentToken) {
        case YY_LBRACE:
            /* LBrace terminates option section for stringtable */
            break;

        case YY_INCLUDE:
            include();
            break;

        case YY_NAME:
            match(YY_NAME);
            if (*hdr->name)
            {
                warning("'name' already defined, skipping duplicate");
                match(YY_STRING);
            }
            if (CurrentToken != YY_STRING)
                error("Expected a string after 'name'");
            if (yyleng >= MAX_OPTS_STRING-1)
                error("'name' string is too long");
            memcpy(hdr->name,yytext,yyleng+1);
            match(YY_STRING);
            break;

        case YY_AUTHOR:
            match(YY_AUTHOR);
            if (*auth)
            {
                warning("'author' already defined, skipping duplicate");
                match(YY_STRING);
            }
            if (CurrentToken != YY_STRING)
                error("Expected a string after 'author'");
            if (yyleng >= MAX_OPTS_STRING-1)
                error("'author' string is too long");
            memcpy(auth,yytext,yyleng+1);
            match(YY_STRING);
            break;

        case YY_DESCRIPTION:
            match(YY_DESCRIPTION);
            if (*desc)
            {
                warning("'description' already defined, skipping duplicate");
                match(YY_STRING);
            }
            if (CurrentToken != YY_STRING)
                error("Expected a string after 'description'");
            if (yyleng >= MAX_OPTS_STRING-1)
                error("'description' string is too long");
            memcpy(desc,yytext,yyleng+1);
            match(YY_STRING);
            break;

        case YY_COPYRIGHT:
            match(YY_COPYRIGHT);
            if (*copy)
            {
                warning("'copyright' already defined, skipping duplicate");
                match(YY_STRING);
            }
            if (CurrentToken != YY_STRING)
                error("Expected a string after 'copyright'");
            if (yyleng >= MAX_OPTS_STRING-1)
                error("'copyright' string is too long");
            memcpy(copy,yytext,yyleng+1);
            match(YY_STRING);
            break;

        default:
            error("Expected a '{', 'name', 'author', 'description', or 'copyright'");
            break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// data                                                                     ³
//                                                                          ³
//     data :- (<id> <string>*)*                                            ³
//             include                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void data(ulong *count)
{
    char    buff[128];
    char    id[MAX_ID];

    switch(CurrentToken) {
        case YY_RBRACE:
            /* RBrace terminates option section for stringtable */
            break;

        case YY_INCLUDE:
            include();
            break;

        case YY_ID:
            if (yyleng >= MAX_ID-1)
                warning("identifier too long, truncated");
            strncpy(id,yytext,MAX_ID-1);

            match(YY_ID);

            (*count)++;

            if (CurrentToken == YY_EQUAL)
            {
                match(YY_EQUAL);
                match(YY_INTEGER);

                CurrentNumber=YY_integer;
            }

            if (CurrentToken != YY_STRING)
                error("Expected a 'string'");

            if (strlen(yytext) != (ulong)yyleng)
            {
                error("String must not contain embedded NULs");
            }

            add_to_work(CurrentNumber,yytext,yyleng);

            match(YY_STRING);

            while (CurrentToken == YY_STRING) {
                if (strlen(yytext) != (ulong)yyleng)
                {
                    error("String must not contain embedded NULs");
                }

                append_to_work(yytext,yyleng);
                match(YY_STRING);
            }

            sprintf(buff,(Flags & FLAGS_MAKE_H) ?
                          "#define %-45s %li\r\n"
                          : "const unsigned long %-45s = %li;\r\n",
                         id,
                         CurrentNumber++);
            header.write (buff, strlen(buff));
            break;

        default:
            error("Expected a string table entry identifier");
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

    switch(CurrentToken) {
        case YY_STRING:
            if (!(Flags & FLAGS_QUIET)) {
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
            error("Invalid include command, expecting filename of CST file to include");
            break;
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
            case YY_EQUAL:
                error("Expected a '='");
                break;
            case YY_STRING:
                error("Expected a string");
                break;
            case YY_ID:
                error("Expected an identifier");
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
STATIC void error(const char *str)
{
    cout << " Error(" << YY_lineno << "): " << str << "\n";
    exit(1);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// warning                                                                  ³
//                                                                          ³
// Emits a warning.                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void warning(const char *str)
{
    cout << " Warning(" << YY_lineno << "): " << str << "\n";
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// add_to_work                                                              ³
//                                                                          ³
// Adds data to the work buffer.                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void add_to_work(ulong num, const char *str, ulong slen)
{
    if ((WorkCurrent+slen+1+4)>= WorkSize)
    {
        expand_work(WorkCurrent+slen+4+1);
    }

    *((ulong*)&Work[WorkCurrent])=num;
    WorkCurrent += 4;

    memcpy((char*)&Work[WorkCurrent],str,slen);
    WorkCurrent += slen;

    Work[WorkCurrent++]=0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// append_to_work                                                           ³
//                                                                          ³
// This version adds a 'continuation' of the string onto a previous         ³
// string.                                                                  ³
//                                                                          ³
// MUST be called AFTER a valid add_to_work if used.                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void append_to_work(const char *str, ulong slen)
{
    if ((WorkCurrent+slen+4)>= WorkSize)
    {
        expand_work(WorkCurrent+slen+4+1);
    }

    memcpy((char*)&Work[WorkCurrent-1],str,slen);
    WorkCurrent += slen-1;

    Work[WorkCurrent++]=0;
}

//°±² End of module - gstringp.cpp ²±°
