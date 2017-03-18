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
 *                       Microsoft Windows 95/98/NT Version
 *
 *  Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
 *
 *ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
 *
 * THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
 * OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
 * PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
 * LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
 * OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
 *
 *ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
 *
 *                        http://www.mythos-engine.org/
 *
 *ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
 *
 *                              *** Utilities ***
 *
 * Created by Chuck Walbourn
 *
 * gfont.l
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

#include   <string.h>
#include   <io.h>

#include   "gfont.h"

long       YY_integer;
int        YY_lineno=1;
int        YY_hexmode=0;
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

"\n"                           { YY_lineno++; }

{ws}                           { /* Skip */ }

"COMMENT".*$                   { /* Comments, skip */ }

"BBX"                            return(YY_BBX);

"BITMAP"                         return(YY_BITMAP);

"CHARS"                          return(YY_CHARS);

"COPYRIGHT"                      return(YY_COPYRIGHT);

"ENCODING"                       return(YY_ENCODING);

"ENDCHAR"                        return(YY_ENDCHAR);

"ENDFONT"                        return(YY_ENDFONT);

"ENDPROPERTIES"                  return(YY_ENDPROPERTIES);

"FAMILY_NAME"                    return(YY_FAMILY_NAME);

"FONTBOUNDINGBOX"                return(YY_FONTBOUNDINGBOX);

"STARTCHAR"                      return(YY_STARTCHAR);

"STARTCHAR \""                   return(YY_STARTCHAR);

"STARTFONT"                      return(YY_STARTFONT);

"STARTPROPERTIES"                return(YY_STARTPROPERTIES);

{hexdig}+                      {
                                   if (YY_hexmode)
                                       YY_integer = strtoul((char *) yytext,NULL,16);
                                   else
                                       YY_integer = atol(yytext);
                                   return(YY_INTEGER);
                               }

\"[^\"]*\"                     {
                                   /* Doesn't handle C escapes yet... */
                                   strncpy((char *) yytext,(char *) &yytext[1],--yyleng);
                                   yytext[--yyleng]='\0';
                                   return(YY_STRING);
                               }

{id}                           { /* Skip */
                               }

.                              { /* Skip */
                               }

%%

int yywrap()
{
    return 1;
}

/*°±² End of file - gfont.l ²±°
 */
