/*ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
 *                           
 *           ^           **   **   **** ***** *    ****     ^      Take me to
 *          (_)            * *     *      *   *    *       (_)    / your
 *     ^                    *      **     *   *    **            ^  leader...
 *    (_)       ^          * *     *      *   *    *            (_)
 *             (_)       **   **   *    ***** **** ****
 *
 *            Copyright (c) 1994,1995 by Charybdis Enterprises, Inc.
 *                              All Rights Reserved.
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
 * xuiffc.l
 *
 * FLEX scanner language description for IFF Complier
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

#include    <string.h>
#include    <io.h>

#include    "xuifftok.h"

long        YY_integer;
double      YY_real;
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

id          {letter}({letter}|{digit}|[_-])*

integer     {digit}+

real        {digit}+\.{digit}+

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

"["                             return(YY_LBRACKET);
"]"                             return(YY_RBRACKET);

"("                             return(YY_LPAREN);
")"                             return(YY_RPAREN);

"{"                             return(YY_LBRACE);
"}"                             return(YY_RBRACE);

"+"                             return(YY_PLUS);

"-"                             return(YY_MINUS);

"*"                             return(YY_MULTIPLY);

"/"                             return(YY_DIVIDE);

","                             return(YY_COMMA);

include                         return(YY_INCLUDE);

form                            return(YY_FORM);

riff                            return(YY_FORM);

chunk                           return(YY_CHUNK);

merge                           return(YY_MERGE);
                                
intel                           return(YY_INTEL);

bigendian                       return(YY_BIGENDIAN);

motorola                        return(YY_MOTOROLA);

littleendian                    return(YY_LITTLEENDIAN);

size                            return(YY_SIZE);

byte                            return(YY_BYTE);

ubyte                           return(YY_UBYTE);
 
word                            return(YY_WORD);

uword                           return(YY_UWORD);
 
long                            return(YY_LONG);

ulong                           return(YY_ULONG);
 
dword                           return(YY_DWORD);

udword                          return(YY_UDWORD);

text                            return(YY_TEXT);

binary                          return(YY_BINARY);

float                           return(YY_FLOAT);

double                          return(YY_DOUBLE);

fixed16                         return(YY_FIXED16);

0x{hexdig}+                     { 
                                    YY_integer = strtoul((char *) &yytext[2],NULL,16);
                                    return(YY_INTEGER);
                                }

{integer}                       { 
                                    YY_integer = atol(yytext);
                                    return(YY_INTEGER);
                                }

{real}                          {  
                                    YY_real = atof(yytext);
                                    return(YY_REAL);
                                }

\'\\[^\']*\'                    {
                                    if (yytext[yyleng-2] == '\\' && yytext[yyleng-3] != '\\')
                                    {
                                        yyless(yyleng-1);
                                        yymore();
                                    }
                                    else
                                    {
                                        char *s, *t, c;

                                        switch (yytext[2])
                                        {
                                            case '\\':
                                                YY_integer = (int) '\\'; break;
                                            case '\'':
                                                YY_integer = (int) '\''; break;
                                            case '"':
                                                YY_integer = (int) '"'; break;
                                            case '?':
                                                YY_integer = (int) '?'; break;
                                            case 'a':
                                                YY_integer = (int) '\a'; break;
                                            case 'b':
                                                YY_integer = (int) '\b'; break;
                                            case 'f':
                                                YY_integer = (int) '\f'; break;
                                            case 'n':
                                                YY_integer = (int) '\n'; break;
                                            case 'r':
                                                YY_integer = (int) '\r'; break;
                                            case 't':
                                                YY_integer = (int) '\t'; break;
                                            case 'v':
                                                YY_integer = (int) '\v'; break;
                                            case 'x':
                                                /* Escape hex */
                                                s=t=&yytext[3];
                                                while ((*s >= '0' && *s <= '9')
                                                       || (*s >= 'A' && *s <= 'F')
                                                       || (*s >= 'a' && *s <= 'f')) s++;
                                                c=*s; *s=0;
                                                YY_integer = (int) strtoul(t,NULL,16);
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
                                                s=t=&yytext[2];
                                                while (*s >= '0' && *s <= '7' && (s-t < 3)) s++;
                                                c=*s; *s=0;
                                                YY_integer = (int) strtoul(t,NULL,8);
                                                *s=c;
                                                break;
                                            default:
                                                YY_integer = (int) yytext[2];
                                        }
                                        return (YY_INTEGER);
                                    }
                                }

'.'                             {
                                    YY_integer = (int) yytext[1];
                                    return (YY_INTEGER);
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

.                               { /* Unexpected character */
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

/*°±² End of file - xuiffc.l ²±° */

