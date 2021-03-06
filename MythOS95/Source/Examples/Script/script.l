/*様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
 *
 *                                /\    /\
 *                               /  \  /  \
 *                              /    \/    \
 *                             /  /\    /\  \
 *                            /  /  \  /  Y T H O S
 *                           /  /    \/    \  \
 *                          /  /            \  \
 *                         /__/              \__\
 *
 *                  Microsoft Windows 95/98/NT Version
 *
 *  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
 *
 *陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
 *
 * THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
 * OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
 * PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
 * LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
 * OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
 *
 *陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
 *
 *                        http://www.mythos-engine.org/
 *
 *陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
 *
 *                               3D SCRIPT EXAMPLE
 *
 * Created by Chuck Walbourn
 *
 * script.l
 *
 * FLEX scanner language description for script language
 *
 *様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
 */

/*旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
 *
 *                             Startup Block
 *
 *旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
 */

%{

#if ( _MSC_VER >= 800 )
#pragma warning(disable:4028)
#endif

#include    <string.h>
#include    <io.h>

#include    "scrtok.h"

long        YY_integer;
double      YY_real;
int         YY_lineno=1;
int         YY_esc_allowed=1;

/*陳� Error/warning routines */
void error(const char *str);
void warning(const char *str);

/*陳� Include handling */
#undef yywrap

#define YY_MAX_DEPTH    16

static int              YY_depth=0;
static FILE             *YY_filestack[YY_MAX_DEPTH];
static YY_BUFFER_STATE  YY_stack[YY_MAX_DEPTH];
static int              YY_linenostack[YY_MAX_DEPTH];

%}

/*旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
 *
 *                                Equates
 *
 *旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
 */

ws          ([ \t\r])*

letter      [A-Za-z]

digit       [0-9]

hexdig      [0-9A-Fa-f]

id          {letter}({letter}|{digit}|[_-])*

integer     {digit}+

real        {digit}+\.{digit}+

/*旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
 *
 *                            Tokens and Actions
 *
 *旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
 */

%%

"\n"                            { YY_lineno++; }

{ws}                            { /* Skip */ }

"//".*$                         { /* Comments, skip */ }

"("                             return(YY_LPAREN);
")"                             return(YY_RPAREN);

"{"                             return(YY_LBRACE);
"}"                             return(YY_RBRACE);

"+"                             return(YY_PLUS);

"-"                             return(YY_MINUS);

"*"                             return(YY_MULTIPLY);

"/"                             return(YY_DIVIDE);

","                             return(YY_COMMA);

"="                             return(YY_EQUAL);

";"                             return(YY_SEMICOLON);

acceleration                    return(YY_ACCELERATION);
activate                        return(YY_ACTIVATE);
active                          return(YY_ACTIVE);
alpha                           return(YY_ALPHA);
ambient                         return(YY_AMBIENT);
animate                         return(YY_ANIMATE);
aspect_ratio                    return(YY_ASPECT_RATIO);
atten                           return(YY_ATTEN);
attenuated                      return(YY_ATTENUATED);
bcolor                          return(YY_BCOLOR);
bfculling                       return(YY_BFCULLING);
bitmap                          return(YY_BITMAP);
camera                          return(YY_CAMERA);
circle                          return(YY_CIRCLE);
color                           return(YY_COLOR);
create                          return(YY_CREATE);
darklight                       return(YY_DARKLIGHT);
deactivate                      return(YY_DEACTIVATE);
direction                       return(YY_DIRECTION);
dots                            return(YY_DOTS);
drawable                        return(YY_DRAWABLE);
factor                          return(YY_FACTOR);
falloff                         return(YY_FALLOFF);
fastatten                       return(YY_FASTATTEN);
fastpoint                       return(YY_FASTPOINT);
fastspot                        return(YY_FASTSPOT);
file                            return(YY_FILE);
flat                            return(YY_FLAT);
fov                             return(YY_FOV);
halt                            return(YY_HALT);
haze                            return(YY_HAZE);
hide                            return(YY_HIDE);
hither                          return(YY_HITHER);
hotspot                         return(YY_HOTSPOT);
include                         return(YY_INCLUDE);
inner                           return(YY_INNER);
intensity                       return(YY_INTENSITY);
life                            return(YY_LIFE);
light                           return(YY_LIGHT);
lookat                          return(YY_LOOKAT);
maxcount                        return(YY_MAXCOUNT);
mesh                            return(YY_MESH);
modify                          return(YY_MODIFY);
move                            return(YY_MOVE);
no                              return(YY_NO);
off                             return(YY_OFF);
on                              return(YY_ON);
outer                           return(YY_OUTER);
particle                        return(YY_PARTICLE);
parts                           return(YY_PARTS);
perspective                     return(YY_PERSPECTIVE);
pitch                           return(YY_PITCH);
point                           return(YY_POINT);
position                        return(YY_POSITION);
pyramids                        return(YY_PYRAMIDS);
rectangle                       return(YY_RECTANGLE);
render                          return(YY_RENDER);
roll                            return(YY_ROLL);
rotatex                         return(YY_ROTATEX);
rotatey                         return(YY_ROTATEY);
rotatez                         return(YY_ROTATEZ);
save                            return(YY_SAVE);
shade                           return(YY_SHADE);
shape                           return(YY_SHAPE);
show                            return(YY_SHOW);
show_all_lines                  return(YY_SHOW_ALL_LINES);
size                            return(YY_SIZE);
smooth                          return(YY_SMOOTH);
solid                           return(YY_SOLID);
specular                        return(YY_SPECULAR);
speed                           return(YY_SPEED);
sphere                          return(YY_SPHERE);
spot                            return(YY_SPOT);
sprite                          return(YY_SPRITE);
textured                        return(YY_TEXTURED);
top                             return(YY_TOP);
translate                       return(YY_TRANSLATE);
type                            return(YY_TYPE);
vector                          return(YY_VECTOR);
velocity                        return(YY_VELOCITY);
viewpoint                       return(YY_VIEWPOINT);
visible                         return(YY_VISIBLE);
wait                            return(YY_WAIT);
waitkey                         return(YY_WAITKEY);
wire                            return(YY_WIRE);
yaw                             return(YY_YAW);
yes                             return(YY_YES);
yon                             return(YY_YON);

0x{hexdig}+                     {
                                    YY_integer = strtoul((char *) &yytext[2],NULL,16);
                                    return(YY_INTEGER);
                                }

{integer}                       {
                                    YY_integer = atol(yytext);
                                    return(YY_INTEGER);
                                }

{real}                          {
                                    sscanf(yytext,"%lf",&YY_real);
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

.                               {
                                  error("Unexpected character in CSF file");
                                }

%%

/*陳� Include handling routines */
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

    YY_linenostack[YY_depth] = YY_lineno;
    YY_lineno=1;

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

    YY_lineno=YY_linenostack[YY_depth];

    YY_depth--;

    return 0;
}

/*葦� End of file - script.l 憶� */

