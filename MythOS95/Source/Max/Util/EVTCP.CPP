//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                  ooo        ooooo                       
//                  `88.       .888'                       
//                   888b     d'888   .oooo.   oooo    ooo 
//                   8 Y88. .P  888  `P  )88b   `88b..8P'  
//                   8  `888'   888   .oP"888     Y888'    
//                   8    Y     888  d8(  888   .o8"'88b   
//                  o8o        o888o `Y888""8o o88'   888o 
//
//                          Across the event horizon...
//
//            Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.
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
// evtcp.cpp
//
//     This is the parse module for the IFF event compiler.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <conio.h>
#include <iostream.h>
#include <strstrea.h>
#include <stdlib.h>
#include <debug.h>

#include <xfiff.hpp>
#include <max.hpp>

#include "evttok.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄ External from scanner.
extern "C" int yylex (void);
extern "C" int yy_pushfile (const char *fname);
extern "C" int yywrap (void);

//ÄÄ External from main module.
void print_error (XFParseIFF &xp, char *s=0);
void expand_work (ulong target);

//ÄÄ Local

STATIC void include();
STATIC void event();
STATIC void trigger();
STATIC void constraint();

STATIC long integer(void);
STATIC long expr(void);
STATIC long term(void);
STATIC long factor(void);

STATIC void match(int tok);
STATIC void error(const char *str);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄ External from scanner.
extern "C" long    YY_integer;
extern "C" double  YY_real;
extern "C" int     YY_lineno;
extern "C" char    *yytext;

//ÄÄ External from main module.
extern XFParseIFF  IFF;
extern XFileDOS    header;
extern byte        *Work;
extern ulong       Work_size;
extern dword       Flags;

//ÄÄ Local         
STATIC int  CurrentToken;

MaxTrigger  theTrigger;
int         event_id = 0;
int         triggers = 0;
int         trig_key = 0;

// These should be dynamically allocated.
const int MAX_TRIGS = 1024;
dword       EVNT[MAX_TRIGS];
MaxTrigger  TRGS[MAX_TRIGS];

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                               Messages
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

STATIC char cpp_header[] =
{
    "//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\r\n"
    "// MaxC -- Event and Trigger Definition System                              ³\r\n"
    "// (C) 1995 by Charybdis Enterprises, Inc.  All Rights Reserved.            ³\r\n"
    "//                                                                          ³\r\n"
    "// Event Constants header file for C++                                      ³\r\n"
    "//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\r\n"
};

STATIC char cpp_trailer[] =
{
    "// EOF\r\n"
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
void compile (const char *evt_name)
{
    MaxEventUser::MaxHeader HDR;

    header.write (cpp_header, sizeof (cpp_header) - 1);

    event_id = triggers = 0;

    CurrentToken = yylex();
    while (CurrentToken)
        event();

    header.write (cpp_trailer, sizeof (cpp_trailer) - 1);

    // Write chunks out to the IFF file
    IFF.newform (IFF.makeid('M','E','V','T'));
    strcpy (HDR.name, evt_name);
    HDR.num_trigs = triggers;
    IFF.write (IFF.makeid('H','D','R',' '), &HDR, sizeof (HDR));
    IFF.write (IFF.makeid('E','V','N','T'), EVNT, sizeof (EVNT[0]) * triggers);
    IFF.write (IFF.makeid('T','R','G','S'), TRGS, sizeof (TRGS[0]) * triggers);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// event                                                                    ³
//                                                                          ³
//      event :-  'event' <id> '{' <trigger> '}'                            ³
//            |   'include' '"'filename'"'                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void event()
{
    ostrstream s;
    char ident[64];

    switch (CurrentToken) 
    {
    case YY_EVENT:
        match (YY_EVENT);
        if (CurrentToken == YY_ID)
        {
            strcpy (ident, yytext);
            match (YY_ID);
        }
        else
        {
            error ("Expecting an identifier.");
        }

        // store the event number with the specified trigger
        s << "const MaxEvent "<< ident << "(" << event_id << ");\r\n";
        header.write (s.str(), s.pcount());

        match (YY_LBRACE);
        while (CurrentToken && CurrentToken != YY_RBRACE)
            trigger();
        match (YY_RBRACE);

        // Advance to the next event_id
        event_id++;

        break;

    case YY_INCLUDE:
        include();
        break;

    default:
        error("Invalid operation, expected an event");
        break;                  
   }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// include                                                                  ³
//                                                                          ³
//     include :- 'include' <string>                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void include ()
{
    int err;

    match (YY_INCLUDE);

    switch (CurrentToken)
    {
    case YY_STRING:
#if 0
        if (!(Flags & FLAGS_QUIET))
            cout << "   °°° including '" << yytext << "' °°°" << endl;
#endif

        err = yy_pushfile (yytext);
        switch (err)
        {
        case 0:     /* OK */
            break;
        case 1:     error("too many nested includes");
            break;
        case 2:     error("could not open include file");
            break;
        case 3:     error("not enough memory to include file");
        default:    error("include failed");
            break;
        }

        // Read first token from new file and continue processing
        // yywrap will undo include later
        CurrentToken = yylex();
        break;

    default:
        error("Invalid include command, expecting filename of CEL file to include");
        break;
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// trigger                                                                  ³
//                                                                          ³
//     trigger :- '[' <constraint> * ']'                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void trigger ()
{
    EVNT[triggers] = event_id;

    match (YY_LBRACKET);

    // Collect all constraints
    trig_key = 0;
    theTrigger = MaxTrigger();
    while (CurrentToken && CurrentToken != YY_RBRACKET)
        constraint();

    match (YY_RBRACKET);

    TRGS[triggers] = theTrigger;

    // Advance to the next trigger
    triggers++;
    if (triggers > MAX_TRIGS)
        error ("Exceeded internal compiler limits -- too many triggers\n");
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// constraint                                                               ³
//                                                                          ³
//     constraint :- <key> | <mouseb> | <mousepos> | <mouserange>           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void constraint ()
{
    switch (CurrentToken)
    {
    case YY_NOT:
        match (YY_NOT);
        match (YY_KEY);
        if (trig_key >= MaxTrigger::max_keys)
            error("Too many keys defined for event");
        else
            theTrigger.Keys[trig_key++] = word (0x200 | expr());
        break;

    case YY_KEY:
        match (YY_KEY);
        if (trig_key >= MaxTrigger::max_keys)
            error("Too many keys defined for event");
        else
            theTrigger.Keys[trig_key++] = word (expr());
        break;

    case YY_MOUSEB:
        match (YY_MOUSEB);
        // The number read is a bit position
        theTrigger.MouseButtons |= word (1 << (expr() - 1));
        break;

    case YY_JOYB:
        match (YY_JOYB);
        // The number read is a bit position
        theTrigger.JoyButtons |= word (1 << (expr() - 1));
        break;

    case YY_MOUSERANGE:
        match (YY_MOUSERANGE);
        theTrigger.BegX = (short)expr(); match (YY_COMMA);
        theTrigger.BegY = (short)expr(); match (YY_COMMA);
        theTrigger.EndX = (short)expr(); match (YY_COMMA);
        theTrigger.EndY = (short)expr();
        break;

    case YY_MOUSEDELTA:
        match (YY_MOUSEDELTA);
        theTrigger.DeltaX = (short)expr(); match (YY_COMMA);
        theTrigger.DeltaY = (short)expr();
        break;

    default:
        error("constraints must be either 'key', 'joyb', 'mouseb', 'mousedelta', or 'mouserange'");
        break;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// integer/expr                                                             ³
//                                                                          ³
// Signed integer expression parsers.                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC long integer ()
{
    long    t = 0L;

    if (CurrentToken == YY_INTEGER)
    {
        t = YY_integer;
        match (YY_INTEGER);
    }
    else
        error("Integer expected");

    return t;
}


STATIC long expr ()
{
    long    t1, t2;

    t1 = term ();
    switch (CurrentToken)
    {
    case YY_PLUS:
        match (YY_PLUS);
        t2 = term();
        return (t1 + t2);

    case YY_MINUS:
        match (YY_MINUS);
        t2 = term();
        return (t1 - t2);

    default:
        return t1;
    }
}

STATIC long term ()
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

STATIC long factor()
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

    case YY_PLUS:
        match (YY_PLUS);
        return expr();

    case YY_MINUS:
        match (YY_MINUS);
        return -expr();

    default:
        error("Invalid expression");
        break;
    }

    return 0;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// match                                                                    ³
//                                                                          ³
// Matches input token again target; if it failes, then it prints an error. ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void match (int tok)
{
    if (tok != CurrentToken)
    {
        switch (tok)
        {
        case YY_LBRACKET:   error ("Expected a '['");
            break;
        case YY_RBRACKET:   error ("Expected a ']'");
            break;
        case YY_LBRACE:     error ("Expected a '{'");
            break;
        case YY_RBRACE:     error ("Expected a '}'");
            break;
        case YY_LPAREN:     error ("Expected a '('");
            break;
        case YY_RPAREN:     error ("Expected a ')'");
            break;
        default:            error ("Unexpected token in source file");
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
STATIC void error (const char *str)
{
   cout << " Error(" << YY_lineno << "): " << str << "\n";
   exit (1);
}


//°±² End of module - xuiffcp.cpp ²±°

