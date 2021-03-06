//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//���������������������������������������������������������������������������
//������������������旭旭旭�����旭旭旭姻���旭�����旭姻旭旭旭旭旭��������������
//�����������������葦姻���姻�葦姻���葦���葦姻���葦姻葦姻���������������������
//����������������碓甥���甥�碓甥����臼��碓碓���碓甥碓甥����������������������
//���������������渦臼葦渦��渦臼葦渦臼��渦臼姻�憶甥渦臼葦渦�������������������
//��������������渦甥������憶�����渦甥�渦甥�悔渦甥渦甥������������������������
//�������������憶悔������憶悔���憶悔�憶悔��臆渦�憶悔�������������������������
//������������臆悔������臆悔���臆悔�臆悔���臆悔臆臆臆臆臆��������������������
//���������������������������������������������������������������������������
//����������������� Microsoft Windows 95/98/NT Version ����������������������
//���������������������������������������������������������������������������
//���Copyright (c) 1996-1999 by Dan Higdon, Tim Little, and Chuck Walbourn���
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// Created by Sean Gallagher
//
// pnimgscr.cpp
//
// An image scrolling class.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define WIN32_LEAN_AND_MEAN
#include <stdlib.h>
#include <assert.h>

#include <pane.hpp>

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneImageScroll - Constructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneImageScroll - render
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneImageScroll - scroll()
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneImageScroll - screen_to_image
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void PaneImageScroll::screen_to_image(short &x, short &y)
{
    x -= vp_anchor_x;
    y -= vp_anchor_y;

    x += abs(img_x);
    y += abs(img_y);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneImageScroll - drag_image
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// PaneImageScroll - center_image
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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

//葦� eof - pnimgscr.cpp 憶�
