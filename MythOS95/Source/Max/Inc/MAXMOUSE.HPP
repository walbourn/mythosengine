//���������������������������������������������������������������������������
//                  ooo        ooooo
//                  `88.       .888'
//                   888b     d'888   .oooo.   oooo    ooo
//                   8 Y88. .P  888  `P  )88b   `88b..8P'
//                   8  `888'   888   .oP"888     Y888'
//                   8    Y     888  d8(  888   .o8"'88b
//                  o8o        o888o `Y888""8o o88'   888o
//
//                          Across the event horizon...
//
//           Copyright (c) 1994 - 1997 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
//
// Event Devices
//
//      This module defines the physical devices used by the event
//  system.  Each device has a unique interface, suited to the device.
//  This module supports the following device:
//
//  Mouse -- The mouse is a multi-button positional device.  The mouse
//          can be queried for its button's states, as well as its current
//          position, and delta movement.
//
//���������������������������������������������������������������������������

#ifndef __MAXMOUSE_HPP
#define __MAXMOUSE_HPP    1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif


//���������������������������������������������������������������������������
//
//                                Includes
//
//���������������������������������������������������������������������������

#include <portable.h>
#include <mmsystem.h>

//���������������������������������������������������������������������������
//
//                                Pragmas
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                               Structures
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// Mouse Class:
//  The Mouse class interfaces with the mouse and retrieves data
//  about the button status and which type of mouse is actualy in
//  use on the system.  (ie. 2 button or 3 button)
//���������������������������������������������������������������������������
class MaxMouse
{
protected:
    //�����������������������������������������������������������������������
    // Private Data
    //�����������������������������������������������������������������������
    short   last_x;
    short   last_y;
    bool    initialized;

public:
    //�����������������������������������������������������������������������
    // Public Data
    //�����������������������������������������������������������������������
    int     NumButtons;
    int     MouseSupported;

    //�����������������������������������������������������������������������
    // Construtor/Destructor
    //�����������������������������������������������������������������������
    MaxMouse();
    virtual ~MaxMouse();

    //�����������������������������������������������������������������������
    // Operations
    //�����������������������������������������������������������������������
    virtual int  init () = 0;
    virtual void uninit();
    virtual void clear();
    virtual void update();

    virtual void show_cursor (bool) = 0;
    virtual void get_pos (short *mx, short *my) const = 0;
    virtual void set_pos (short _mx, short _my) = 0;
    virtual void get_movement (short *dx, short *dy) = 0;
    virtual byte get_buttons() const = 0;   // bits 0,1,2 button up/down
                                            // bits 4,5,6 button dblclick status.
    virtual bool is_present () const;

    bool is_initialized () const { return initialized; }
};


//���������������������������������������������������������������������������
// MaxMouseWin32
//���������������������������������������������������������������������������
class MaxMouseWin32: public MaxMouse
{
public:
    //�����������������������������������������������������������������������
    // Construtor/Destructor
    //�����������������������������������������������������������������������
    MaxMouseWin32();
    virtual ~MaxMouseWin32();

    //�����������������������������������������������������������������������
    // Operations
    //�����������������������������������������������������������������������
    virtual int  init ();

    virtual void show_cursor (bool);
    virtual void get_pos (short *mx, short *my) const;
    virtual void set_pos (short _mx, short _my);
    virtual void get_movement (short *dx, short *dy);
    virtual byte get_buttons() const;    // bits 0,1,2 button up/down
                                         // bits 4,5,6 button dblclick status.
};


//���������������������������������������������������������������������������
// MaxMouseDirectX
//���������������������������������������������������������������������������
class MaxMouseDirectX: public MaxMouse
{
private:
    //�����������������������������������������������������������������������
    // Implementation Data
    //�����������������������������������������������������������������������
    enum { DIDATA_SIZE = 32 };
    IDirectInputDevice  *pdid;
    DIDEVCAPS           dicaps;
    DIMOUSESTATE        state;
    char                old_buttons[4];


    bool                cursor_on;
    LONG                xpos;
    LONG                ypos;
    RECT                wnd_rect;

public:
    //�����������������������������������������������������������������������
    // Construtor/Destructor
    //�����������������������������������������������������������������������
    MaxMouseDirectX (IDirectInput *, HWND);
    ~MaxMouseDirectX ();

    //�����������������������������������������������������������������������
    // Operations
    //�����������������������������������������������������������������������
    virtual int  init ();
    virtual void uninit();
    virtual void clear();
    virtual void update();

    virtual void show_cursor (bool);
    virtual void get_pos (short *mx, short *my) const;
    virtual void set_pos (short _mx, short _my);
    virtual void get_movement (short *dx, short *dy);
    virtual byte get_buttons() const;    // bits 0,1,2 button up/down
                                         // bits 4,5,6 button dblclick status.
    virtual bool is_present () const;
};


//���������������������������������������������������������������������������
//
//                               Prototypes
//
//���������������������������������������������������������������������������

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - maxmouse.hpp ���