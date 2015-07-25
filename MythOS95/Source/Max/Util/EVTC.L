/*ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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
 *                       Microsoft Windows 95/98/NT Version
 *
 *  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
 *
 *ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
 *
 * This file and all associated files are subject to the terms of the
 * GNU Lesser General Public License version 2 as published by the
 * Free Software Foundation (http://www.gnu.org).   They remain the
 * property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
 * See LICENSE.TXT in the distribution for a copy of this license.
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
 * Created by Dan Higdon
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

#include   <string.h>
#include   <stdio.h>

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

/* Lifted from DINPUT.H - had to remove #include because of wierd compiler bug */

/****************************************************************************
 *
 *      DirectInput keyboard scan codes
 *
 ****************************************************************************/

#define DIK_ESCAPE          0x01
#define DIK_1               0x02
#define DIK_2               0x03
#define DIK_3               0x04
#define DIK_4               0x05
#define DIK_5               0x06
#define DIK_6               0x07
#define DIK_7               0x08
#define DIK_8               0x09
#define DIK_9               0x0A
#define DIK_0               0x0B
#define DIK_MINUS           0x0C    /* - on main keyboard */
#define DIK_EQUALS          0x0D
#define DIK_BACK            0x0E    /* backspace */
#define DIK_TAB             0x0F
#define DIK_Q               0x10
#define DIK_W               0x11
#define DIK_E               0x12
#define DIK_R               0x13
#define DIK_T               0x14
#define DIK_Y               0x15
#define DIK_U               0x16
#define DIK_I               0x17
#define DIK_O               0x18
#define DIK_P               0x19
#define DIK_LBRACKET        0x1A
#define DIK_RBRACKET        0x1B
#define DIK_RETURN          0x1C    /* Enter on main keyboard */
#define DIK_LCONTROL        0x1D
#define DIK_A               0x1E
#define DIK_S               0x1F
#define DIK_D               0x20
#define DIK_F               0x21
#define DIK_G               0x22
#define DIK_H               0x23
#define DIK_J               0x24
#define DIK_K               0x25
#define DIK_L               0x26
#define DIK_SEMICOLON       0x27
#define DIK_APOSTROPHE      0x28
#define DIK_GRAVE           0x29    /* accent grave */
#define DIK_LSHIFT          0x2A
#define DIK_BACKSLASH       0x2B
#define DIK_Z               0x2C
#define DIK_X               0x2D
#define DIK_C               0x2E
#define DIK_V               0x2F
#define DIK_B               0x30
#define DIK_N               0x31
#define DIK_M               0x32
#define DIK_COMMA           0x33
#define DIK_PERIOD          0x34    /* . on main keyboard */
#define DIK_SLASH           0x35    /* / on main keyboard */
#define DIK_RSHIFT          0x36
#define DIK_MULTIPLY        0x37    /* * on numeric keypad */
#define DIK_LMENU           0x38    /* left Alt */
#define DIK_SPACE           0x39
#define DIK_CAPITAL         0x3A
#define DIK_F1              0x3B
#define DIK_F2              0x3C
#define DIK_F3              0x3D
#define DIK_F4              0x3E
#define DIK_F5              0x3F
#define DIK_F6              0x40
#define DIK_F7              0x41
#define DIK_F8              0x42
#define DIK_F9              0x43
#define DIK_F10             0x44
#define DIK_NUMLOCK         0x45
#define DIK_SCROLL          0x46    /* Scroll Lock */
#define DIK_NUMPAD7         0x47
#define DIK_NUMPAD8         0x48
#define DIK_NUMPAD9         0x49
#define DIK_SUBTRACT        0x4A    /* - on numeric keypad */
#define DIK_NUMPAD4         0x4B
#define DIK_NUMPAD5         0x4C
#define DIK_NUMPAD6         0x4D
#define DIK_ADD             0x4E    /* + on numeric keypad */
#define DIK_NUMPAD1         0x4F
#define DIK_NUMPAD2         0x50
#define DIK_NUMPAD3         0x51
#define DIK_NUMPAD0         0x52
#define DIK_DECIMAL         0x53    /* . on numeric keypad */
#define DIK_F11             0x57
#define DIK_F12             0x58

#define DIK_F13             0x64    /*                     (NEC PC98) */
#define DIK_F14             0x65    /*                     (NEC PC98) */
#define DIK_F15             0x66    /*                     (NEC PC98) */

#define DIK_KANA            0x70    /* (Japanese keyboard)            */
#define DIK_CONVERT         0x79    /* (Japanese keyboard)            */
#define DIK_NOCONVERT       0x7B    /* (Japanese keyboard)            */
#define DIK_YEN             0x7D    /* (Japanese keyboard)            */
#define DIK_NUMPADEQUALS    0x8D    /* = on numeric keypad (NEC PC98) */
#define DIK_CIRCUMFLEX      0x90    /* (Japanese keyboard)            */
#define DIK_AT              0x91    /*                     (NEC PC98) */
#define DIK_COLON           0x92    /*                     (NEC PC98) */
#define DIK_UNDERLINE       0x93    /*                     (NEC PC98) */
#define DIK_KANJI           0x94    /* (Japanese keyboard)            */
#define DIK_STOP            0x95    /*                     (NEC PC98) */
#define DIK_AX              0x96    /*                     (Japan AX) */
#define DIK_UNLABELED       0x97    /*                        (J3100) */
#define DIK_NUMPADENTER     0x9C    /* Enter on numeric keypad */
#define DIK_RCONTROL        0x9D
#define DIK_NUMPADCOMMA     0xB3    /* , on numeric keypad (NEC PC98) */
#define DIK_DIVIDE          0xB5    /* / on numeric keypad */
#define DIK_SYSRQ           0xB7
#define DIK_RMENU           0xB8    /* right Alt */
#define DIK_HOME            0xC7    /* Home on arrow keypad */
#define DIK_UP              0xC8    /* UpArrow on arrow keypad */
#define DIK_PRIOR           0xC9    /* PgUp on arrow keypad */
#define DIK_LEFT            0xCB    /* LeftArrow on arrow keypad */
#define DIK_RIGHT           0xCD    /* RightArrow on arrow keypad */
#define DIK_END             0xCF    /* End on arrow keypad */
#define DIK_DOWN            0xD0    /* DownArrow on arrow keypad */
#define DIK_NEXT            0xD1    /* PgDn on arrow keypad */
#define DIK_INSERT          0xD2    /* Insert on arrow keypad */
#define DIK_DELETE          0xD3    /* Delete on arrow keypad */
#define DIK_LWIN            0xDB    /* Left Windows key */
#define DIK_RWIN            0xDC    /* Right Windows key */
#define DIK_APPS            0xDD    /* AppMenu key */

/*
 *  Alternate names for keys, to facilitate transition from DOS.
 */
#define DIK_BACKSPACE       DIK_BACK            /* backspace */
#define DIK_NUMPADSTAR      DIK_MULTIPLY        /* * on numeric keypad */
#define DIK_LALT            DIK_LMENU           /* left Alt */
#define DIK_CAPSLOCK        DIK_CAPITAL         /* CapsLock */
#define DIK_NUMPADMINUS     DIK_SUBTRACT        /* - on numeric keypad */
#define DIK_NUMPADPLUS      DIK_ADD             /* + on numeric keypad */
#define DIK_NUMPADPERIOD    DIK_DECIMAL         /* . on numeric keypad */
#define DIK_NUMPADSLASH     DIK_DIVIDE          /* / on numeric keypad */
#define DIK_RALT            DIK_RMENU           /* right Alt */
#define DIK_UPARROW         DIK_UP              /* UpArrow on arrow keypad */
#define DIK_PGUP            DIK_PRIOR           /* PgUp on arrow keypad */
#define DIK_LEFTARROW       DIK_LEFT            /* LeftArrow on arrow keypad */
#define DIK_RIGHTARROW      DIK_RIGHT           /* RightArrow on arrow keypad */
#define DIK_DOWNARROW       DIK_DOWN            /* DownArrow on arrow keypad */
#define DIK_PGDN            DIK_NEXT            /* PgDn on arrow keypad */


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

#f1             { YY_integer = DIK_F1;          return(YY_INTEGER); }
#f2             { YY_integer = DIK_F2;          return(YY_INTEGER); }
#f3             { YY_integer = DIK_F3;          return(YY_INTEGER); }
#f4             { YY_integer = DIK_F4;          return(YY_INTEGER); }
#f5             { YY_integer = DIK_F5;          return(YY_INTEGER); }
#f6             { YY_integer = DIK_F6;          return(YY_INTEGER); }
#f7             { YY_integer = DIK_F7;          return(YY_INTEGER); }
#f8             { YY_integer = DIK_F8;          return(YY_INTEGER); }
#f9             { YY_integer = DIK_F9;          return(YY_INTEGER); }
#f10            { YY_integer = DIK_F10;         return(YY_INTEGER); }
#f11            { YY_integer = DIK_F11;         return(YY_INTEGER); }
#f12            { YY_integer = DIK_F12;         return(YY_INTEGER); }
#f13            { YY_integer = DIK_F13;         return(YY_INTEGER); }
#f14            { YY_integer = DIK_F14;         return(YY_INTEGER); }
#f15            { YY_integer = DIK_F15;         return(YY_INTEGER); }

#alt            { YY_integer = 0x401;           return(YY_INTEGER); }   // Special "fake" code
#lalt           { YY_integer = DIK_LMENU;       return(YY_INTEGER); }
#ralt           { YY_integer = DIK_RMENU;       return(YY_INTEGER); }
#ctrl           { YY_integer = 0x402;           return(YY_INTEGER); }   // Special "fake" code
#lctrl          { YY_integer = DIK_LCONTROL;    return(YY_INTEGER); }
#rctrl          { YY_integer = DIK_RCONTROL;    return(YY_INTEGER); }
#shift          { YY_integer = 0x403;           return(YY_INTEGER); }   // Special "fake" code
#lshift         { YY_integer = DIK_LSHIFT;      return(YY_INTEGER); }
#rshift         { YY_integer = DIK_RSHIFT;      return(YY_INTEGER); }

#esc            { YY_integer = DIK_ESCAPE;      return(YY_INTEGER); }
#tab            { YY_integer = DIK_TAB;         return(YY_INTEGER); }
#caps           { YY_integer = DIK_CAPITAL;     return(YY_INTEGER); }
#prtscr         { YY_integer = 0x12a; return(YY_INTEGER); }
#numlock        { YY_integer = DIK_NUMLOCK;     return(YY_INTEGER); }
#scroll         { YY_integer = DIK_SCROLL;      return(YY_INTEGER); }
#pause          { YY_integer = 0x11d; return(YY_INTEGER); }
#sysreq         { YY_integer = DIK_SYSRQ;       return(YY_INTEGER); }

#space          { YY_integer = DIK_SPACE;       return(YY_INTEGER); }
#enter          { YY_integer = DIK_RETURN;      return(YY_INTEGER); }
#backspace      { YY_integer = DIK_BACK;        return(YY_INTEGER); }

#end            { YY_integer = DIK_NUMPAD1;     return(YY_INTEGER); }
#down           { YY_integer = DIK_NUMPAD2;     return(YY_INTEGER); }
#pgdn           { YY_integer = DIK_NUMPAD3;     return(YY_INTEGER); }
#left           { YY_integer = DIK_NUMPAD4;     return(YY_INTEGER); }
#center         { YY_integer = DIK_NUMPAD5;     return(YY_INTEGER); }
#right          { YY_integer = DIK_NUMPAD6;     return(YY_INTEGER); }
#home           { YY_integer = DIK_NUMPAD7;     return(YY_INTEGER); }
#up             { YY_integer = DIK_NUMPAD8;     return(YY_INTEGER); }
#pgup           { YY_integer = DIK_NUMPAD9;     return(YY_INTEGER); }
#insert         { YY_integer = DIK_NUMPAD0;     return(YY_INTEGER); }
#del            { YY_integer = DIK_DECIMAL;     return(YY_INTEGER); }

#grayminus      { YY_integer = DIK_SUBTRACT;    return(YY_INTEGER); }
#grayplus       { YY_integer = DIK_ADD;         return(YY_INTEGER); }
#grayenter      { YY_integer = DIK_NUMPADENTER; return(YY_INTEGER); }
#graymul        { YY_integer = DIK_MULTIPLY;    return(YY_INTEGER); }
#graydiv        { YY_integer = DIK_DIVIDE;      return(YY_INTEGER); }

#grayend        { YY_integer = DIK_END;         return(YY_INTEGER); }
#graydown       { YY_integer = DIK_DOWN;        return(YY_INTEGER); }
#graypgdn       { YY_integer = DIK_PGDN;        return(YY_INTEGER); }
#grayleft       { YY_integer = DIK_LEFT;        return(YY_INTEGER); }
#grayright      { YY_integer = DIK_RIGHT;       return(YY_INTEGER); }
#grayhome       { YY_integer = DIK_HOME;        return(YY_INTEGER); }
#grayup         { YY_integer = DIK_UP;          return(YY_INTEGER); }
#graypgup       { YY_integer = DIK_PGUP;        return(YY_INTEGER); }
#grayinsert     { YY_integer = DIK_INSERT;      return(YY_INTEGER); }
#graydel        { YY_integer = DIK_DELETE;      return(YY_INTEGER); }

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
