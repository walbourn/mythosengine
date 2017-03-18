//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//        Microsoft Windows 95/98/NT Version                 | / \   .  |
//                                                           |_|_|_._._.|
//                                                           |.-.-.-.-..|
//                                                          %\__________/%
//                                                           %          %
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
// Created by Tim Little
//
// vngserv.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <assert.h>
#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"
#include <math.h>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                 Macros
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

// The SAME_SIGNS macro assumes arithmetic where the exclusive-or
// operation will work on sign bits.  This works for twos-complement,
// and most other machine arithmetic.
#define SAME_SIGNS( a, b ) \
        (((long) ((unsigned long) a ^ (unsigned long) b)) >= 0 )
#define MAX(a,b) (a>b)?a:b

#define ABS(a) (a<0)?(a*=(-1)):a

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

STATIC  dword invert_table[2048];

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// vngo_get_invert
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
dword * vngo_get_invert()
{
    static  int needs_init = 1;

    if (needs_init)
    {
        invert_table[0] = 1;
        for (int i=1;i < 2048;i++)
        {
            dword t;
            _asm {
                mov     eax,080000000h
                xor     edx,edx
                div     i
                shr     eax,1
                adc     eax,0
                mov     t,eax
            }
            invert_table[i] = t;        // 1 in 16.16 divided by i gives a value
                                        // to multiply by to get an effective
                                        // divide by i in 16.16.
        }
        needs_init=0;
    }
    return (&invert_table[0]);
}


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° VngoRect °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoRect - clip_to
//
//      Clip the rect to the passed in rectangle.  It will return the
//      resulting rectangle.  If the rect is completely clipped, it will
//      return a rectangle with all elements = 0.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VNGError VngoRect::clip_to(VngoRect &crect)
{
    VngoRect trect = *this;
    if ((trect.x >= crect.x + crect.dx) ||
        (trect.x + trect.dx < crect.x) ||
        (trect.y >= crect.y + crect.dy) ||
        (trect.y + trect.dy < crect.y))
    {
        return (VNGO_FULLY_CLIPPED);
    }
    if (trect.x < crect.x)
    {
        int t = crect.x - trect.x;
        if (trect.dx > t)
            trect.dx -= t;
        else
        {
            return (VNGO_FULLY_CLIPPED);
        }
        trect.x = crect.x;
    }
    if (trect.y < crect.y)
    {
        int t = crect.y - trect.y;
        if (trect.dy > t)
            trect.dy -= t;
        else
        {
            return (VNGO_FULLY_CLIPPED);
        }
        trect.y = crect.y;
    }
    if ((trect.x + trect.dx) > (crect.x + crect.dx))
    {
        trect.dx = (crect.x + crect.dx) - trect.x;
    }
    if ((trect.y + trect.dy) > (crect.y + crect.dy))
    {
        trect.dy = (crect.y + crect.dy) - trect.y;
    }
    *this = trect;
    return (VNGO_NO_ERROR);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoRect - clip_to
//
//      Clip the passed in line to the rect.  It will return the
//      resulting line.  If the line is completely clipped, it will
//      return VNGO_FULLY_CLIPPED, and no parameters will be modified.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VNGError VngoRect::clip_to(VngoPoint *p1,VngoPoint *p2,dword flags)
{                     \
    if ((p1->x >= x && p1->x < (x + dx) && p2->x >= x && p2->x < (x + dx))
        && (p1->y >= y && p1->y < (y + dy) && p2->y >= y && p2->y < (y + dy)))
    {   // It doesn't need to be clipped.
        if (flags & VNGO_CLIP_VERBOSE)
            return VNGO_FULLY_INSIDE;
        else
            return VNGO_NO_ERROR;
    }


    int top = y;
    int bottom = y + dy;
    int left = x;
    int right = x + dx;

    VngoPoint   tp1 = *p1;
    VngoPoint   tp2 = *p2;

    if (p1->x > p2->x)
    {
        tp1 = *p2;
        tp2 = *p1;
    }

    if ((tp2.x < left) || (tp1.x > right))
    {
        return VNGO_FULLY_CLIPPED;
    }
    if (tp1.y < tp2.y)
    {
        if ((tp2.y < top) || (tp1.y > bottom))
            return VNGO_FULLY_CLIPPED;

        if (tp1.y < top)
        {
            // clip to the top.
            Flx16   dy1 = Flx16(tp2.y - tp1.y);
            Flx16   dy2 = Flx16(tp2.y - top);
            Flx16   dx  = Flx16(tp2.x - tp1.x);
            Flx16   scale = flx_16div16(dy2,dy1);
            dx = flx_16mul16(dx,scale);
            tp1.y = top;
            tp1.x = tp2.x - (int) dx;

            if (flags & VNGO_CLIP_SHADE)
            {
                Flx16   ds  = Flx16(tp2.shade - tp1.shade);
                ds = flx_16mul16(ds,scale);
                tp1.shade = tp2.shade - (int)ds;
            }
            if (flags & VNGO_CLIP_Z)
            {
                Flx16   dz  = Flx16(tp2.z - tp1.z,0);
                dz = flx_16mul16(dz,scale);
                tp1.z += dz.flx;
            }


        }
        if (tp2.y > bottom)
        {
            // clip to the bottom.
            Flx16   dy1 = Flx16(tp2.y - tp1.y);
            Flx16   dy2 = Flx16(tp2.y - bottom);
            Flx16   dx  = Flx16(tp2.x - tp1.x);
            Flx16 scale = flx_16div16(dy2,dy1);
            dx = flx_16mul16(dx,scale);
            tp2.y = bottom;
            tp2.x = tp2.x - (int) dx;

            if (flags & VNGO_CLIP_SHADE)
            {
                Flx16   ds  = Flx16(tp2.shade - tp2.shade);
                ds = flx_16mul16(ds,scale);
                tp2.shade = tp2.shade - (int) ds;
            }
            if (flags & VNGO_CLIP_Z)
            {
                Flx16   dz  = Flx16(tp2.z - tp1.z,0);
                dz = flx_16mul16(dz,scale);
                tp2.z = tp2.z + dz.flx;
            }
        }
    }
    else
    {
        if ((tp1.y < top) || (tp2.y > bottom))
            return VNGO_FULLY_CLIPPED;

        if (tp2.y < top)
        {
            // clip to the top.
            Flx16   dy1 = Flx16(tp1.y - tp2.y);
            Flx16   dy2 = Flx16(tp1.y - top);
            Flx16   dx  = Flx16(tp1.x - tp2.x);
            Flx16   scale = flx_16div16(dy2,dy1);
            dx = flx_16mul16(dx,scale);
            tp2.y = top;
            tp2.x = tp1.x - (int) dx;

            if (flags & VNGO_CLIP_SHADE)
            {
                Flx16   ds  = Flx16(tp1.shade - tp2.shade);
                ds = flx_16mul16(ds,scale);
                tp2.shade = tp1.shade - (int) ds;
            }

            if (flags & VNGO_CLIP_Z)
            {
                Flx16   dz  = Flx16(tp1.z - tp2.z,0);
                dz = flx_16mul16(dz,scale);
                tp2.z += dz.flx;
            }
        }
        if (tp1.y > bottom)
        {
            // clip to the bottom.
            Flx16   dy1 = Flx16(tp1.y - tp2.y);
            Flx16   dy2 = Flx16(tp1.y - bottom);
            Flx16   dx  = Flx16(tp1.x - tp2.x);
            Flx16   scale = flx_16div16(dy2,dy1);
            dx = flx_16mul16(dx,scale);
            tp1.y = bottom;
            tp1.x = tp1.x - (int) dx;

            if (flags & VNGO_CLIP_SHADE)
            {
                Flx16   ds  = Flx16(tp1.shade - tp2.shade);
                ds = flx_16mul16(ds,scale);
                tp1.shade = tp1.shade - (int) ds;
            }

            if (flags & VNGO_CLIP_Z)
            {
                Flx16   dz  = Flx16(tp1.z - tp2.z,0);
                dz = flx_16mul16(dz,scale);
                tp1.z += dz.flx;
            }
        }
    }

    if (tp1.x < left)
    {
        // clip to the left.
        Flx16   dx1 = Flx16(tp2.x - tp1.x);
        Flx16   dx2 = Flx16(tp2.x - left);
        Flx16   dy  = Flx16(tp2.y - tp1.y);
        Flx16   scale = flx_16div16(dx2,dx1);
        dy = flx_16mul16(dy, scale);
        tp1.x = left;
        tp1.y = tp2.y - (int) dy;

        if (flags & VNGO_CLIP_SHADE)
        {
            Flx16   ds  = Flx16(tp2.shade - tp1.shade);
            ds = flx_16mul16(ds, scale);
            tp1.shade = tp2.shade - (int) ds;
        }

        if (flags & VNGO_CLIP_Z)
        {
            Flx16   dz  = Flx16(tp2.z - tp1.z,0);
            dz = flx_16mul16(dz, scale);
            tp1.z += dz.flx;
        }
    }
    if (tp2.x > right)
    {
        // clip to the right.
        Flx16   dx1 = Flx16(tp2.x - tp1.x);
        Flx16   dx2 = Flx16(tp2.x - right);
        Flx16   dy  = Flx16(tp2.y - tp1.y);

        Flx16   scale = flx_16div16(dx2,dx1);
        dy = flx_16mul16(dy, scale);
        tp2.x = right;
        tp2.y = tp2.y - (int) dy;

        if (flags & VNGO_CLIP_SHADE)
        {
            Flx16   ds  = Flx16(tp2.shade - tp1.shade);
            ds = flx_16mul16(ds, scale);
            tp2.shade = tp2.shade - (int) ds;
        }
        if (flags & VNGO_CLIP_Z)
        {
            Flx16   dz  = Flx16(tp2.z - tp1.z,0);
            dz = flx_16mul16(dz, scale);
            tp2.z += dz.flx;
        }
    }


    // Now that the line has been clipped, do a second
    // trivial rejection test.

    if ((tp1.x >= right) || (tp2.x < left)
        || ((tp1.y >= bottom) && (tp2.y >= bottom))
        || ((tp1.y < top) && (tp2.y < top)))
    {
        return VNGO_FULLY_CLIPPED;
    }
    *p1 = tp1;
    *p2 = tp2;

    return VNGO_NO_ERROR;
}

VNGError VngoRect::clip_to(VngoPointF *p1,VngoPointF *p2,dword flags)
{
    VngoPoint   tp1,tp2;
    tp1.x = int(p1->x);
    tp1.y = int(p1->y);

    tp2.x = int(p2->x);
    tp2.y = int(p2->y);

    if (flags & VNGO_CLIP_SHADE)
    {
        tp1.shade = int(p1->shade);
        tp2.shade = int(p2->shade);
    }
    if (flags & VNGO_CLIP_Z)
    {
        tp1.z = int(p1->z * float(0xffffffff));
        tp2.z = int(p2->z * float(0xffffffff));
    }
    VNGError tret = clip_to(&tp1,&tp2,flags | VNGO_CLIP_VERBOSE);
    if (tret != VNGO_NO_ERROR)
    {
        if (flags & VNGO_CLIP_VERBOSE)
            return tret;
        else if (tret == VNGO_FULLY_CLIPPED)
            return VNGO_FULLY_CLIPPED;
        else
            return VNGO_NO_ERROR;
    }
    p1->x = float(tp1.x);
    p1->y = float(tp1.y);
    p2->x = float(tp2.x);
    p2->y = float(tp2.y);
    if (flags & VNGO_CLIP_Z)
    {
        p1->z = float(tp1.z) / float(0xffffffff);
        p2->z = float(tp2.z) / float(0xffffffff);
    }
    if (flags & VNGO_CLIP_SHADE)
    {
        p1->shade = float(tp1.shade);
        p2->shade = float(tp2.shade);
    }

    return VNGO_NO_ERROR;
}




//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°° VngoHazeInfoVVP16 °°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoHazeInfoVVP16 - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VngoHazeInfoVVP16::~VngoHazeInfoVVP16()
{
    release();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoHazeInfoVVP16 - setup
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void VngoHazeInfoVVP16::setup(VngoHazeInfo *info)
{
    if (rtable == NULL)
        rtable = (byte*)ivory_alloc(256*32*sizeof(byte));
    if (gtable == NULL)
        gtable = (byte*)ivory_alloc(256*32*sizeof(byte));
    if (btable == NULL)
        btable = (byte*)ivory_alloc(256*32*sizeof(byte));

    start_depth = dword(info->start_depth * float(0xffff));
    dword tstart_depth = start_depth >> 8;
    float tdist = float(256 - tstart_depth);

    for (dword d = 0;d < 256;d++)
    {
        dword offset= d << 5;
        for (byte r = 0;r < 32;r++)
        {
            if (d >= tstart_depth)
            {   // We haze it.
                float   tr = float((info->target_color.r >> 3) - r);
                float   td = float(d - tstart_depth);
                float   scalar = td / tdist;
                rtable[offset+r]=r+byte(tr*scalar);
            }
            else
            {   // We don't!  Theoreticaly we will never touch this.
                rtable[offset+r]=r;
            }
        }
        for (byte g = 0;g < 32;g++)
        {
            if (d >= tstart_depth)
            {   // We haze it.
                float   tg = float((info->target_color.g >> 3) - g);
                float   td = float(d - tstart_depth);
                float   scalar = td / tdist;
                gtable[offset+g]=g+byte(tg*scalar);
            }
            else
            {   // We don't!  Theoreticaly we will never touch this.
                gtable[offset+g]=g;
            }
        }
        for (byte b = 0;b < 32;b++)
        {
            if (d >= tstart_depth)
            {   // We haze it.
                float   tb = float((info->target_color.b >> 3) - b);
                float   td = float(d - tstart_depth);
                float   scalar = td / tdist;
                btable[offset+b]=b+byte(tb*scalar);
            }
            else
            {   // We don't!  Theoreticaly we will never touch this.
                btable[offset+b]=b;
            }
        }
    }

}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoHazeInfoVVP16 - release
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void VngoHazeInfoVVP16::release()
{
    if (rtable != NULL)
        ivory_free((void**)&rtable);
    if (gtable != NULL)
        ivory_free((void**)&gtable);
    if (btable != NULL)
        ivory_free((void**)&btable);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°° VngoHazeInfoVVP8 °°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoHazeInfoVVP8 - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
VngoHazeInfoVVP8::~VngoHazeInfoVVP8()
{
    release();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoHazeInfoVVP8 - setup
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void VngoHazeInfoVVP8::setup(VngoHazeInfo *info,VngoPal *pal)
{
    if (htable == NULL)
        htable = (byte*)ivory_alloc(128*256*sizeof(byte));

    start_depth = dword(info->start_depth * float(0xffff));
    dword tstart_depth = start_depth >> 9;
    float tdist = float(128 - tstart_depth);

    for (dword d = 0;d < 128;d++)
    {
        dword offset= d << 8;
        for (int i = 0;i < 256;i++)
        {
            if (d >= tstart_depth)
            {   // We haze it.
                VngoColor24bit sclr = pal->get_RGB(i);
                float   tr = float(info->target_color.r  - sclr.r);
                float   tg = float(info->target_color.g  - sclr.g);
                float   tb = float(info->target_color.b  - sclr.b);

                float   td = float(d - tstart_depth);
                float   scalar = td / tdist;
                sclr.r = sclr.r + byte(tr*scalar);
                sclr.g = sclr.g + byte(tg*scalar);
                sclr.b = sclr.b + byte(tb*scalar);
                htable[offset+i]=byte(pal->get_index(sclr));
            }
            else
            {   // We don't!  Theoreticaly we will never touch this.
                htable[offset+i]=i;
            }
        }
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// VngoHazeInfoVVP8 - release
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void VngoHazeInfoVVP8::release()
{
    if (htable != NULL)
        ivory_free((void**)&htable);
}

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°° VngoSystem °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void VngoSystem::set_gamma(float gamma)
{
    gamma_correct = gamma;
    float k = (255.f / powf(255.f,(1.f/gamma)));
    for (int i=0;i < 256;i++)
    {
        float t = k * powf(float(i),(1.f/gamma));
        if (t > 255.f)
            t = 255.f;
        if (t < 0.f)
            t = 0.f;

        gtable[i] = byte(t);
    }
}

void VngoSystem::init_alpha()
{
    float   astep = 1.f/256.f;
    float   cur_a = 0;
    byte    *ptr = alpha_table;

    for (int j=0;j < 256; j++)
    {
        for (int i=0;i < 32;i++)
        {
            *ptr = byte(float(i) * cur_a);
            ptr++;
        }
        cur_a+=astep;
    }
}
//°±² End of module - vngserv.cpp ²±°

