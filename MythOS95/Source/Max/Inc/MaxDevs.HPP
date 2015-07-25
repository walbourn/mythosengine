//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
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
//            Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.
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
// Event Devices
//
//      This module defines the physical devices used by the event
//  system.  Each device has a unique interface, suited to the device.
//  Only three devices are currently supported.
//
//  Keyboard -- The keyboard device.  This is not a serial device, but
//          rather a matrix of on/off switches corresponding to the
//          individual keys.  Key indexes are scan codes, and "extended"
//          keys are the same as their scan codes + 256.
//  Mouse -- The mouse is a multi-button positional device.  The mouse
//          can be queried for its button's states, as well as its current
//          position, and delta movement.
//  Joystick -- The standard IBM Joystick.  Like the mouse, this device
//          can only be queried for its current state.
//
//  Additionally, a new class has been added to "contain" those devices, and
//  maintain a "current state", so that multiple event systems can query
//  the devices, and devices (such as the mouse) whose states depend
//  on how recently they were queried will return meaningful values.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __MAXDEVS_HPP
#define __MAXDEVS_HPP    1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//             
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <portable.h>
#include <mmsystem.h>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Pragmas
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// The Keyboard class is used to manage the keyboad, it mantains
// a list of all the keys on the keyboard and has their state.
// Any given key can be either up or down.  A Zero value for that
// key will represent the UP position of the key, any other value
// will represent the DOWN position of the key.  There should be
// no reason to ever use this class seperate from the EventSystem.
// However, there is nothing keeping you from doing it.
//
// Not Yet Implemented:
// It is also the responsibility of the Keyboard class to hook the
// <CTRL><ALT><DEL> & <CTRL>(<BREAK>/<C>) key sequences.  If you
// wish for them to be handled in a special manner.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class MaxKeyboard
{
private:
        dword   KeyStat[8];         // The Up/Down Status of the keys.
        dword   KeyStatHold[8];     // The Up/Down Status of the keys.
        int     KeyStatCount;

        // And now, for the MaxKbBuffer support.
        // The MaxKbBuffer objects modify this link pointer themselves.
        // Consequently, we should only read it.
friend  class MaxKbBuffer;
        MaxKbBuffer *BuffList;

public:
        MaxKeyboard ();
        ~MaxKeyboard ();
        void    init ();
        void    uninit ();
        void    clear ();

        int     check_key (int key) const;

        // Some members to change the state of the "lock" keys.
        void    num_lock (int state);
        void    caps_lock (int state);
        void    scroll_lock (int state);

        // These members allows a Windows application to avoid loosing
        // characters when the frame rate drops too low for "normal"
        // responsiveness.  Simply call these members with the WindowProc
        // on WM_KEYDOWN and WM_KEYUP messages respectively.
        void    wm_keydown (int);
        void    wm_keyup (int);
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Mouse Class:
//  The Mouse class interfaces with the mouse and retrives data
//  about the button status and which type of mouse is actualy in
//  use on the system.  (ie. 2 button or 3 button)
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class MaxMouse
{
private:
        short   last_x;
        short   last_y;

public:
        int     NumButtons;
        int     MouseSupported;

public:
        int     init ();
        void    uninit();
        void    clear();

        void    hide();
        void    show();

        void    get_pos (short *mx, short *my) const;
        void    set_pos (short _mx, short _my);
        void    get_movement (short *dx, short *dy);
        byte    get_buttons() const;    // bits 0,1,2 button up/down
                                        // bits 4,5,6 button dblclick status.
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// MaxJoystick
//  Supports the standard IBM joystick device.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class MaxJoystick
{
        // Controls the access method for the joystick
        short   auto_polled;
        MMRESULT timer_id;

public:
        // Tells which axes are active; bit 1 == Joy1, etc.
        short   joy_present;

        // Store capabilities and current snapshot
        JOYCAPS     caps;
        JOYINFOEX   info;

        MaxJoystick();
        ~MaxJoystick();

        short   init ();
        void    uninit ();
        void    clear();

        // Return the entire "joystick gestalt"
        void    get_stat (JOYINFOEX *) const;

        // The polling interface (turns on automatic polling, which increases accuracy)
        int     auto_poll (BOOL = TRUE, UINT rate = 50);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// MaxDevices:
//  The set of devices currently supported by Max.
//  Each devices may be enabled/disabled individually
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

class MaxDevices
{
public:
        // Actual devices, made public for special access.
        MaxMouse    theMouse;
        MaxKeyboard theKeyboard;
        MaxJoystick theJoystick;

private:
        // Enabled states
        short   keyboard_enabled;
        short   mouse_enabled;
        short   joystick_enabled;

        // Keyboard state info
        // None required!

        // Mouse state info
        short   snapshot_mx;
        short   snapshot_my;
        short   snapshot_mdx;
        short   snapshot_mdy;
        byte    snapshot_mbuttons;

        // Joystick state info
        JOYINFOEX   snapshot_jstat;

public:
        MaxDevices();
        ~MaxDevices();

int     enable_keyboard (int);
int     enable_mouse    (int);
int     enable_joystick (int);

        // Update the internal values for the various devices
void    update ();

        // Used to clear any special states when using the WM_* pump
        // Must be called if an wm_ device members are used.
void    wm_clear ();

        // Values for the devices
void    get_mouse_movement (short *, short *) const;
void    get_mouse_pos (short *, short *) const;
void    set_mouse_pos (short, short);
byte    get_mouse_buttons () const;

        // Keyboard device
int     check_keyboard_key (int) const;

        // Joystick device
void    get_joystick (JOYINFOEX *) const;
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// MaxKbBuffer
//  This class provides a character buffer for MaxKeyboard.  This key
//  buffer can be queried with "C" conio-like routines.  It is a little
//  magic, since the keyboard interrupt routine knows about it.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class MaxKbBuffer
{
// This is actually a linked list node.  MaxKeyboard is given direct
// access so that it alone can walk the list.
friend  class MaxKeyboard; 
        MaxKbBuffer *next;
        MaxKeyboard *kb;

// The actual KbBuff stuff
        enum    { BuffSize = 16 };
        ushort  buff[BuffSize];
        int     head;
        int     tail;

public:
        MaxKbBuffer (MaxKeyboard *);
        ~MaxKbBuffer();

        // The "serial" interface to emulate the standard C console routines
        int     getch ();
        int     getscan();
        int     kbhit () const  { return tail != head; }
        void    clear ()        { head = tail = 0; }

        // Translation services
        byte    get_ascii (byte scan) const;

        // Add a key to the keypress buffer
        void    AddKey (ushort);

        // For link support
        void        set_next (MaxKbBuffer *n)   { next = n; }
        MaxKbBuffer *get_next () const          { return next; }
};

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - maxdevs.hpp ²±°

