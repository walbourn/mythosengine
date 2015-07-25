//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//שששששששששששששששששש°°°°°°ששששש°°°°°°°שששש°°ששששש°°°ש°°°°°°°°°°שששששששששששששש
//ששששששששששששששששש°±°שששש°שש°±°שששש°±ששש°±°שששש°±°ש°±°שששששששששששששששששששששש
//שששששששששששששששש±°±שששש±שש±°±ששששש±±שש±°±°ששש±°±ש±°±ששששששששששששששששששששששש
//ששששששששששששששש±²±±°±±²שש±²±±°±±²±±שש±²±±°שש²±±ש±²±±°±±²ששששששששששששששששששש
//שששששששששששששש±²±ששששששש²±ששששש±²±שש±²±שש²ש±²±ש±²±ששששששששששששששששששששששששש
//ששששששששששששש²±²ששששששש²±²שששש²±²שש²±²ששש²²±²ש²±²שששששששששששששששששששששששששש
//שששששששששששש²²²ששששששש²²²שששש²²²שש²²²שששש²²²ש²²²²²²²²²²שששששששששששששששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//ששששששששששששששששש Microsoft Windows 95/98/NT Version שששששששששששששששששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//שששCopyright (c) 1996-1999 by Dan Higdon, Tim Little, and Chuck Walbournששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
//
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
//
//                        http://www.mythos-engine.org/
//
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
//
// Created by Sean Gallagher
//
// pnimgscr.cpp
//
// An image scrolling class.
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define WIN32_LEAN_AND_MEAN
#include <stdlib.h>
#include <assert.h>

#include <pane.hpp>

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
// PaneImageScroll - Constructor
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
PaneImageScroll::PaneImageScroll(   VngoVport *gvp,
                                    VngoTexture *img,
                                    int vp_x,
                                    int vp_y,
                                    int delta):
    gvport(gvp),
    image(img),
    img_x(0),
    img_y(0),
    map_x(0),
    map_y(0)
{
    assertMyth("PaneImageScroll requires a valid VngoVport",gvp);
    assertMyth("PaneImageScroll requires a valid VngoTexture",img);

    vp_anchor_x = vp_x;
    vp_anchor_y = vp_y;

    scroll_delta = delta;
}

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
// PaneImageScroll - render
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
void PaneImageScroll::render()
{
    if (gvport && image)
    {
        int was_locked = gvport->lock();

        VngoRect    vis_rect;

        vis_rect.x = img_x;
        vis_rect.y = img_y;
        vis_rect.dx = image->width;
        vis_rect.dy = image->height;

        gvport->image_trans(&vis_rect, image, 0);

        if (!was_locked)
            gvport->unlock();
    }
}

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
// PaneImageScroll - scroll()
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
void PaneImageScroll::scroll(int direction)
{
    if (gvport && image)
    {
        switch (direction)
        {
            case IMAGE_SCROLL_LEFT:
                {
                    img_x += scroll_delta;
                    if (img_x > 0)
                        img_x = 0;
                }
                break;
            case IMAGE_SCROLL_RIGHT:
                {
                    img_x -= scroll_delta;
                    if (abs(img_x) > abs(image->width - gvport->vbuff.width))
                        img_x = -(image->width - gvport->vbuff.width);
                }
                break;
            case IMAGE_SCROLL_UP:
                {
                    img_y += scroll_delta;
                    if (img_y > 0)
                        img_y = 0;
                }
                break;

            case IMAGE_SCROLL_DOWN:
                {
                    img_y -= scroll_delta;
                    if (abs(img_y) > abs(image->height - gvport->vbuff.height))
                        img_y = -(image->height - gvport->vbuff.height);
                }
                break;

            default:
                break;
        }

        render();
    }
}


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
// PaneImageScroll - screen_to_image
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
void PaneImageScroll::screen_to_image(short &x, short &y)
{
    x -= vp_anchor_x;
    y -= vp_anchor_y;

    x += abs(img_x);
    y += abs(img_y);
}


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
// PaneImageScroll - drag_image
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
void PaneImageScroll::drag_image(int ax, int ay, int x, int y)
{
    if (gvport && image)
    {
        img_x += x - ax;
        img_y += y - ay;

        if (img_x > 0)
            img_x = 0;

        if (img_y > 0)
            img_y = 0;

        if (abs(img_x) > abs(image->width - gvport->vbuff.width))
            img_x = -(image->width - gvport->vbuff.width);

        if (abs(img_y) > abs(image->height - gvport->vbuff.height))
            img_y = -(image->height - gvport->vbuff.height);

        render();
    }
}


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
// PaneImageScroll - center_image
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
void PaneImageScroll::center_image(int x, int y)
{
    if (gvport && image)
    {
        long new_x = 0;
        long new_y = 0;

        if (x < 0)
        {
            new_x = long((gvport->vbuff.width>>1) - (image->width>>1));
        }
        else
        {
            new_x = x - (gvport->vbuff.width>>1);
            if (new_x < 0)
                new_x = 0;

            if (long(new_x + gvport->vbuff.width) > image->width)
                new_x = (image->width - gvport->vbuff.width);
        }

        if (y < 0)
        {
            new_y = long((gvport->vbuff.height>>1) - (image->height>>1));
        }
        else
        {
            new_y = y - (gvport->vbuff.height>>1);

            if (new_y < 0)
                new_y = 0;

            if (long(new_y + gvport->vbuff.height) > image->height)
                new_y = image->height - gvport->vbuff.height;
        }

        set_image_pos(new_x, new_y);
    }
}

//°±² eof - pnimgscr.cpp ²±°
