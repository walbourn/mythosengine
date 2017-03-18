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
// Created by Chuck Walbourn
//
// gbrgoutc.cpp
//
// Contains the character output routine.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <assert.h>

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
// gberg_outc                                                               ³
//                                                                          ³
// Outputs a single character to the given x,y location using the currently ³
// active font.  It returns the character width unless vert is set which    ³
// then causes the height to be returned.                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
long gberg_outc(VngoVport *vp, long x, long y, char c, BOOL vert)
{
    GBergFontInfo   *fnt;
    VngoRect        r;
    VngoTexture     txt;

    assertMyth("Gutenberg must be initialized",GBergInstance);

    assertMyth("gberg_outc assumes viewport is given",vp);

    fnt=GBergInstance->font_active;

    assertMyth("gberg_outc needs a valid (and locked) active font",
               fnt && fnt->ptr);

//ÄÄ Draw character
    r.x = x;
    r.y = y;
    r.dy = txt.height = fnt->height;

    switch (fnt->type)
    {
        case GBERG_FNT_MONOFIXED:               //ÄÄ Monochrome fixed
            if (c >= 0)
            {
                r.dx = txt.width = fnt->width;
                txt.flags = VNGO_TEXTURE_MONO;
                txt.tex = (byte *)((byte *)fnt->ptr + (c*fnt->bpc));

                int waslocked = vp->lock();
                vp->image_trans_mono(&r,&txt,GBergInstance->fcol,GBergInstance->bcol);
                if (!waslocked)
                    vp->unlock();
            }
            break;

        case GBERG_FNT_MONOFIXEDEX:             //ÄÄ Monochrome fixed extended
            {
                r.dx = txt.width = fnt->width;

                txt.flags = VNGO_TEXTURE_MONO;
                txt.tex = (byte *)((byte *)fnt->ptr + ((byte)c*fnt->bpc));

                int waslocked = vp->lock();
                vp->image_trans_mono(&r,&txt,GBergInstance->fcol,GBergInstance->bcol);
                if (!waslocked)
                    vp->unlock();
            }
            break;

        case GBERG_FNT_MONOVARIABLE:            //ÄÄ Monochrome variable
            if (c >= 0)
            {
                // First byte is character width
                byte *ptr = (byte *)((byte *)fnt->ptr + (c*fnt->bpc));

                r.dx = txt.width = *(ptr++);
                txt.flags = VNGO_TEXTURE_MONO;
                txt.tex = ptr;

                int waslocked = vp->lock();
                vp->image_trans_mono(&r,&txt,GBergInstance->fcol,GBergInstance->bcol);
                if (!waslocked)
                    vp->unlock();
            }
            break;

        case GBERG_FNT_MONOVARIABLEEX:          //ÄÄ Monochrome variable extended
            {
                // First byte is character width
                byte *ptr = (byte *)((byte *)fnt->ptr + ((byte)c*fnt->bpc));

                r.dx = txt.width = *(ptr++);
                txt.flags = VNGO_TEXTURE_MONO;
                txt.tex = ptr;

                int waslocked = vp->lock();
                vp->image_trans_mono(&r,&txt,GBergInstance->fcol,GBergInstance->bcol);
                if (!waslocked)
                    vp->unlock();
            }
            break;
    }

    return (vert) ? r.dy : r.dx;
}

//°±² End of module - gbrgoutc.cpp ²±°

