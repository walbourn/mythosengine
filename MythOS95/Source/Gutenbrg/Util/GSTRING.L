/*ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
 *           __ ,                                                  
 *            ,-| ~           ,               ,,                      
 *           ('||/__,        ||               ||                  _   
 *          (( |||  | \\ \\ =||=   _-_  \\/\\ ||/|,  _-_  ,._-_  / \\ 
 *          (( |||==| || ||  ||   || \\ || || || || || \\  ||   || || 
 *           ( / |  , || ||  ||   ||/   || || || |' ||/    ||   || || 
 *            -____/  \\/\\  \\,  \\,/  \\ \\ \\/   \\,/   \\,  \\_-| 
 *                                                               /  \ 
 *                                                              '----`
 *                     Text Output and Font Management System
 *                        Microsoft Windows 95/NT Version
 *
 *            Copyright (c) 1995-1998 by Charybdis Enterprises, Inc.
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
 * Created by Chuck Walbourn
 *
 * gstring.l
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

#ifdef __WATCOMC__
#pragma off(unreferenced);
#endif

#if ( _MSC_VER >= 800 )
#pragma warning(disable:4028)
#endif

#include    <string.h>
#include    <io.h>

#include    "gstring.h"

long        YY_integer;
int         YY_lineno=1;
int         YY_esc_allowed=1;

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

ws          ([ \t\r])*

letter      [A-Za-z]

digit       [0-9]

hexdig      [0-9A-Fa-f]

id          {letter}({letter}|{digit}|[_])*

integer     {digit}+

/*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
 *
 *                            Tokens and Actions
 *
 *°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
 */

%%

"\n"                            { YY_lineno++; }

{ws}                            { /* Skip */ }
                            
";".*$                          { /* Comments, skip */ }

"{"                             return(YY_LBRACE);
"}"                             return(YY_RBRACE);

"("                             return(YY_LPAREN);
")"                             return(YY_RPAREN);

"+"                             return(YY_PLUS);

"-"                             return(YY_MINUS);

"*"                             return(YY_MULTIPLY);

"/"                             return(YY_DIVIDE);

"="                             return(YY_EQUAL);

"author"                        return(YY_AUTHOR);

"copyright"                     return(YY_COPYRIGHT);

"description"                   return(YY_DESCRIPTION);

"include"                       return(YY_INCLUDE);

"name"                          return(YY_NAME);

"stringtable"                   return(YY_STRINGTABLE);

0x{hexdig}+                     { 
                                    YY_integer = strtoul((char *) &yytext[2],NULL,16);
                                    return(YY_INTEGER);
                                }

{integer}                       { 
                                    YY_integer = atol(yytext);
                                    return(YY_INTEGER);
                                }

\"[^"]*\"                       {
                                    if (!YY_esc_allowed)
                                    {
                                        strncpy((char *) yytext,(char *) &yytext[1],--yyleng);
                                        yytext[--yyleng]='\0';
                                        return(YY_STRING);
                                    }

                                    /* Handles C escape sequences */
                                    if (yytext[yyleng-2] == '\\' && yytext[yyleng-3] != '\\')
                                    {
                                        yyless(yyleng-1);
                                        yymore();
                                    }
                                    else
                                    {
                                        char *s, *d, *t, c;

                                        yyleng--;
                                        for(s=(char *) &yytext[1], d=(char *) yytext;;)
                                        {
                                            if (*s == 0)
                                                break;

                                            if (*s == '\\')
                                            {
                                                switch (*(s+1))
                                                {
                                                    case '\n':
                                                        s+=2; yyleng--; break;
                                                    case '\\':
                                                        *(d++) = '\\'; s+=2; yyleng--; break;
                                                    case '\'':
                                                        *(d++) = '\''; s+=2; yyleng--; break;
                                                    case '"':
                                                        *(d++) = '"'; s+=2; yyleng--; break;
                                                    case '?':
                                                        *(d++) = '\?'; s+=2; yyleng--; break;
                                                    case 'a':
                                                        *(d++) = '\a'; s+=2; yyleng--; break;
                                                    case 'b':
                                                        *(d++) = '\b'; s+=2; yyleng--; break;
                                                    case 'f':
                                                        *(d++) = '\f'; s+=2; yyleng--; break;
                                                    case 'n':
                                                        *(d++) = '\n'; s+=2; yyleng--; break;
                                                    case 'r':
                                                        *(d++) = '\r'; s+=2; yyleng--; break;
                                                    case 't':
                                                        *(d++) = '\t'; s+=2; yyleng--; break;
                                                    case 'v':
                                                        *(d++) = '\v'; s+=2; yyleng--; break;
                                                    case 'x':
                                                        /* Escape hex */
                                                        s++; s++; t=s; yyleng--;
                                                        while ((*s >= '0' && *s <= '9')
                                                               || (*s >= 'A' && *s <= 'F')
                                                               || (*s >= 'a' && *s <= 'f')) { s++; yyleng--; }
                                                        c=*s; *s=0;
                                                        *(d++) = (char) strtoul(t,NULL,16);
                                                        *s=c;
                                                        break;
                                                    case '0':
                                                    case '1':
                                                    case '2':
                                                    case '3':
                                                    case '4':
                                                    case '5':
                                                    case '6':
                                                    case '7':
                                                        /* Escape octal */
                                                        s++; t=(s++); yyleng--;
                                                        while (*s >= '0' && *s <= '7' && (s-t < 3)) { s++; yyleng--; }
                                                        c=*s; *s=0;
                                                        *(d++) = (char) strtoul(t,NULL,8);
                                                        *s=c;
                                                        break;
                                                    default:
                                                        *(d++) = *(s++); break;
                                                }
                                            }
                                            else *(d++) = *(s++);
                                        }
                                        *(d-1)=0;       // Always end with a '"' in the string!
                                        yyleng--;

                                        return(YY_STRING);
                                    }
                                }

{id}                            {
                                    return YY_ID;
                                }
   
.                               { /* Skip */
                                }


%%

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

int yywrap()
{
    if (YY_depth < 1)
        return 1;    

    yy_switch_to_buffer(YY_stack[YY_depth-1]);

    yy_delete_buffer(YY_stack[YY_depth]);
    fclose(YY_filestack[YY_depth]);

    YY_depth--;

    return 0;
}

/*°±² End of file - gstring.l ²±° */
