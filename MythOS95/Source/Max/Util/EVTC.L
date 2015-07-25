/*ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
 *
 *                  ooo        ooooo                       
 *                  `88.       .888'                       
 *                   888b     d'888   .oooo.   oooo    ooo 
 *                   8 Y88. .P  888  `P  )88b   `88b..8P'  
 *                   8  `888'   888   .oP"888     Y888'    
 *                   8    Y     888  d8(  888   .o8"'88b   
 *                  o8o        o888o `Y888""8o o88'   888o 
 *
 *                          Across the event horizon...
 *
 *          Copyright (c) 1994 - 1997 by Charybdis Enterprises, Inc.
 *                           All Rights Reserved.
 *
 *ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
 *
 *           *** Charybdis Enterprises, Inc. Company Confidential ***
 *
 *  This file and all associated files are the company proprietary property
 *        of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
 *
 * CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
 * TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
 * IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
 * AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
 * INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
 *
 *ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
 *
 *                              *** Utilities ***
 *
 * FLEX scanner language description for IFF Event Complier
 *
 *ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
 */

/*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
 *
 *                             Startup Block
 *                               
 *°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
 */

%{

#if ( _MSC_VER >= 800 )
#pragma warning(disable:4028)
#endif

#include   <ctype.h>
#include   <string.h>
#include   <io.h>

#include   "evttok.h"

long       YY_integer;
int        YY_lineno=1;

/* This is a table that converts a-z into scan codes */
static int scan_cnv[128] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0e, 0x0f, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,

    0x39, 0x02, 0x28, 0x04, 0x05, 0x06, 0x08, 0x28,
    0x0a, 0x0b, 0x09, 0x0d, 0x33, 0x0c, 0x34, 0x35,
    0x0b, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
    0x09, 0x0a, 0x27, 0x27, 0x33, 0x0d, 0x34, 0x35,

    // Uppercase letters, etc
    0x00, 0x1e, 0x30, 0x2e, 0x20, 0x12, 0x21, 0x22,
    0x23, 0x17, 0x24, 0x25, 0x26, 0x32, 0x31, 0x18,
    0x19, 0x10, 0x13, 0x1f, 0x14, 0x16, 0x2f, 0x11,
    0x2d, 0x15, 0x2c, 0x1a, 0x2b, 0x1b, 0x07, 0x1c,

    // Lowercase letters, etc.
    0x29, 0x1e, 0x30, 0x2e, 0x20, 0x12, 0x21, 0x22,
    0x23, 0x17, 0x24, 0x25, 0x26, 0x32, 0x31, 0x18,
    0x19, 0x10, 0x13, 0x1f, 0x14, 0x16, 0x2f, 0x11,
    0x2d, 0x15, 0x2c, 0x1a, 0x2b, 0x1b, 0x29, 0x0e
};

/*ÄÄÄ Include handling */
#undef yywrap

#define YY_MAX_DEPTH    16

static int              YY_depth=0;
static FILE             *YY_filestack[YY_MAX_DEPTH];
static YY_BUFFER_STATE  YY_stack[YY_MAX_DEPTH];

%}

/*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
 *
 *                                Equates
 *
 *°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
 */

ws         ([ \t\r])*

letter     [A-Za-z]

digit      [0-9]

hexdig     [0-9A-Fa-f]

id         {letter}({letter}|{digit}|[_-])*

integer    {digit}+

/*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
 *
 *                            Tokens and Actions
 *
 *°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
 */
                                
%%

"\n"            { YY_lineno++; }
{ws}            { /* Skip */ }
";".*$          { /* Comments, skip */ }
"["             return(YY_LBRACKET);
"]"             return(YY_RBRACKET);
"("             return(YY_LPAREN);
")"             return(YY_RPAREN);
"{"             return(YY_LBRACE);
"}"             return(YY_RBRACE);
"+"             return(YY_PLUS);
"-"             return(YY_MINUS);
"*"             return(YY_MULTIPLY);
"/"             return(YY_DIVIDE);
","             return(YY_COMMA);
not             return(YY_NOT);
event           return(YY_EVENT);
key             return(YY_KEY);
joyb            return(YY_JOYB);
mouseb          return(YY_MOUSEB);
mousedelta      return(YY_MOUSEDELTA);
mouserange      return(YY_MOUSERANGE);

#f1             { YY_integer = 0x3b; return(YY_INTEGER); }
#f2             { YY_integer = 0x3c; return(YY_INTEGER); }
#f3             { YY_integer = 0x3d; return(YY_INTEGER); }
#f4             { YY_integer = 0x3e; return(YY_INTEGER); }
#f5             { YY_integer = 0x3f; return(YY_INTEGER); }
#f6             { YY_integer = 0x40; return(YY_INTEGER); }
#f7             { YY_integer = 0x41; return(YY_INTEGER); }
#f8             { YY_integer = 0x42; return(YY_INTEGER); }
#f9             { YY_integer = 0x43; return(YY_INTEGER); }
#f10            { YY_integer = 0x44; return(YY_INTEGER); }
#f11            { YY_integer = 0x57; return(YY_INTEGER); }
#f12            { YY_integer = 0x58; return(YY_INTEGER); }

#alt            { YY_integer = 0x38; return(YY_INTEGER); }
#lalt           { YY_integer = 0x38; return(YY_INTEGER); }
#ralt           { YY_integer = 0x138;return(YY_INTEGER); }
#ctrl           { YY_integer = 0x1d; return(YY_INTEGER); }
#lctrl          { YY_integer = 0x1d; return(YY_INTEGER); }
#rctrl          { YY_integer = 0x11d;return(YY_INTEGER); }
#shift          { YY_integer = 0x2a; return(YY_INTEGER); }
#lshift         { YY_integer = 0x2a; return(YY_INTEGER); }
#rshift         { YY_integer = 0x36; return(YY_INTEGER); }

#esc            { YY_integer = 0x01; return(YY_INTEGER); }
#tab            { YY_integer = 0x0f; return(YY_INTEGER); }
#caps           { YY_integer = 0x3a; return(YY_INTEGER); }
#prtscr         { YY_integer = 0x12a;return(YY_INTEGER); }
#numlock        { YY_integer = 0x45; return(YY_INTEGER); }
#scroll         { YY_integer = 0x46; return(YY_INTEGER); }
#pause          { YY_integer = 0x11d;return(YY_INTEGER); }
#sysreq         { YY_integer = 0x84; return(YY_INTEGER); }

#space          { YY_integer = 0x39; return(YY_INTEGER); }
#enter          { YY_integer = 0x1c; return(YY_INTEGER); }
#backspace      { YY_integer = 0x0e; return(YY_INTEGER); }

#end            { YY_integer = 0x4f; return(YY_INTEGER); }
#down           { YY_integer = 0x50; return(YY_INTEGER); }
#pgdn           { YY_integer = 0x51; return(YY_INTEGER); }
#left           { YY_integer = 0x4b; return(YY_INTEGER); }
#center         { YY_integer = 0x4c; return(YY_INTEGER); }
#right          { YY_integer = 0x4d; return(YY_INTEGER); }
#home           { YY_integer = 0x47; return(YY_INTEGER); }
#up             { YY_integer = 0x48; return(YY_INTEGER); }
#pgup           { YY_integer = 0x49; return(YY_INTEGER); }
#insert         { YY_integer = 0x52; return(YY_INTEGER); }
#del            { YY_integer = 0x53; return(YY_INTEGER); }

#grayminus      { YY_integer = 0x4a; return(YY_INTEGER); }
#grayplus       { YY_integer = 0x4e; return(YY_INTEGER); }
#grayenter      { YY_integer = 0x11c;return(YY_INTEGER); }
#graymul        { YY_integer = 0x37; return(YY_INTEGER); }
#graydiv        { YY_integer = 0x135;return(YY_INTEGER); }

#grayend        { YY_integer = 0x14f;return(YY_INTEGER); }
#graydown       { YY_integer = 0x150;return(YY_INTEGER); }
#graypgdn       { YY_integer = 0x151;return(YY_INTEGER); }
#grayleft       { YY_integer = 0x14b;return(YY_INTEGER); }
#grayright      { YY_integer = 0x14d;return(YY_INTEGER); }
#grayhome       { YY_integer = 0x147;return(YY_INTEGER); }
#grayup         { YY_integer = 0x148;return(YY_INTEGER); }
#graypgup       { YY_integer = 0x149;return(YY_INTEGER); }
#grayinsert     { YY_integer = 0x152;return(YY_INTEGER); }
#graydel        { YY_integer = 0x153;return(YY_INTEGER); }

0x{hexdig}+     {   YY_integer = strtoul ((char *) &yytext[2],NULL,16);
                    return(YY_INTEGER);
                }

{integer}       {   YY_integer = atol(yytext);
                    return(YY_INTEGER);
                }

include         return(YY_INCLUDE);

\"[^"]*\"       {   /* String */
                    strncpy((char *) yytext, (char *)&yytext[1], --yyleng);
                    yytext[--yyleng] = '\0';
                    return(YY_STRING);
                }

{id}            return(YY_ID);

\'.\'           {   YY_integer = scan_cnv[yytext[1]];
                    return(YY_INTEGER);
                }

.               { /* Unexpected character.  Drop it */
                }

%%

#if 0
#endif

/*ÄÄÄ Include handling routines */
int yy_pushfile(const char *fname)
{
    if (YY_depth++ >= YY_MAX_DEPTH)
        return 1;   /* Include too deep */

    // Handle first include
    if (YY_depth == 1)
    {   
        YY_stack[0] = yy_current_buffer;
    }

    if ((YY_filestack[YY_depth] = fopen(fname,"r"))==NULL)
    {
        YY_depth--;
        return 2;   /* Could not open file */
    }

    YY_stack[YY_depth]=yy_create_buffer(YY_filestack[YY_depth],YY_BUF_SIZE);
    if (!YY_stack)
    {
        fclose(YY_filestack[YY_depth--]);
        return 3;   /* Not enough memory */
    }

    yy_switch_to_buffer(YY_stack[YY_depth]);
    
    return 0;
}

int yywrap (void)
{
    if (YY_depth < 1)
        return 1;    

    yy_switch_to_buffer(YY_stack[YY_depth-1]);

    yy_delete_buffer(YY_stack[YY_depth]);
    fclose(YY_filestack[YY_depth]);

    YY_depth--;

    return 0;
}

/*°±² End of file - evtc.l ²±° */
