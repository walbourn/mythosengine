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
//                          Microsoft Windows '95 Version
//
//            Copyright (c) 1995, 1996 by Charybdis Enterprises, Inc.
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
// Created by Chuck Walbourn
//
// gbrgtext.cpp
//
// Text output class code.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <assert.h>
#include <stdio.h>

#include <gutenbrg.hpp>

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern "C" GBergIData   *GBergInstance;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// GBergText - outc                                                         ³
//                                                                          ³
// Outputs a character.                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void GBergText::outc(char c)
{
    assertMyth("GBergText assumes Gutenberg is initalized and has an active font",
               GBergInstance && GBergInstance->font_active);

//ÄÄ Skip single character returns
    if (c == '\r')
        return;

//ÄÄ Perform CR/LF on newline
    if (c == '\n')
    {
        cury += GBergInstance->font_active->height;
        curx = 0;
        return;
    }

//ÄÄ Output character and update cursor position

    curx += gberg_outc(vport, curx, cury, c);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// GBergText - out                                                          ³
//                                                                          ³
// Outputs a string or long value as string.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void GBergText::out(const char *str)
{
    assertMyth("GBergText assumes Gutenberg is initalized and has an active font",
               GBergInstance && GBergInstance->font_active);

    while (*str != 0)
    {
        outc(*(str++));
    }
}

void GBergText::out(long num)
{
    char    buff[16];

#ifdef WIN32
    wsprintf(buff,"%li",num);
#else
    sprintf(buff,"%li",num);
#endif
    out(buff);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// GBergText - outf                                                         ³
//                                                                          ³
// Outputs a string formatted with wsprintf.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void GBergText::outf (const char *fmt, ...)
{
    char buff[256];

    // Perform a printf
    va_list parms;
    va_start (parms, fmt);
#ifdef WIN32
    int len = wvsprintf (buff, fmt, parms);
#else
    int len = vsprintf (buff, fmt, parms);
#endif
    va_end (parms);

    assert (len < sizeof (buff));
    out (buff);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// GBergText - out_wrap                                                     ³
//                                                                          ³
// Outputs a string wrapped to the given rectangle.                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void GBergText::out_wrap (const char *text, const VngoRect *rct)
{
    VngoRect trct;

    // If we have no rectangle, default to the viewport rectangle
    if (rct == 0)
    {
        trct.x  = vport->vbuff.left;
        trct.y  = vport->vbuff.top;
        trct.dx = vport->vbuff.width;
        trct.dy = vport->vbuff.height;
        rct = &trct;
    }

    // Some parameter validation
    assert (rct != 0);
    assert (rct->dx > 0);
    assert (rct->dy > 0);

    // Calculate some bounds information
    const int right  = rct->x + rct->dx;
    const int bottom = rct->y + rct->dy;

    // Clip cursor to the rectangle
    if (cury < rct->y)
        cury = rct->y;

    if (curx < rct->x)
        curx = rct->x;

    // Define loop variables
    const char *last_word = text;
    int col = rct->x;

    while (*text != '\0' && cury < bottom)
    {
        // The proposed character
        const char ch = *text;

        // Advance the proposed point by one character
        col += gberg_widthc (ch);

        // If we have left the rectangle, move to the next line
        if (col >= right)
        {
            if (curx == rct->x)
            {
                // If the word is too long for one line, write
                // as much as we can on this line, splitting the word
                for (; last_word != text; ++last_word)
                    outc (*last_word);
            }

            col = curx = rct->x;
            cury += GBergInstance->font_active->height;
        }

        // If we have reached a space, it is now safe to
        // write the current word (including the trailing space)
        if (isspace (ch))
        {
            for (; last_word != text; ++last_word)
                outc (*last_word);
            outc (ch);
            last_word = text + 1;
        }

        ++text;
    }

    // Output the trailer of the string
    while (last_word != text)
        outc (*last_word++);
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// GBergText - setpos                                                       ³
//                                                                          ³
// Sets the position of the curx, cury cursor using the size of the         ³
// font to determine rows and columns.                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void GBergText::setpos(byte row, byte col)
{
    assertMyth("GBergText assumes Gutenberg is initalized and has an active font",
               GBergInstance && GBergInstance->font_active);

    curx = col * GBergInstance->font_active->width;
    cury = row * GBergInstance->font_active->height;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// GBergText - getpos                                                       ³
//                                                                          ³
// Gets the position of the curx, cury cursor using the size of the         ³
// font to determine rows and columns.                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void GBergText::getpos(byte *row, byte *col) const
{
    assertMyth("GBergText assumes Gutenberg is initalized and has an active font",
               GBergInstance && GBergInstance->font_active);

    assertMyth("GBergText assumes active font has non-zero width and height",
               GBergInstance->font_active->width
               && GBergInstance->font_active->height);

    *col = byte (curx / GBergInstance->font_active->width);
    *row = byte (cury / GBergInstance->font_active->height);
}

//°±² End of module - gbrgtext.cpp ²±°

