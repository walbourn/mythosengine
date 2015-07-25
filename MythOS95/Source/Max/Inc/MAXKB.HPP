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
// Keyboard Devices
//
//      This module defines the physical devices used by the event
//  system.  Each device has a unique interface, suited to the device.
//  This module supports the following device:
//
//  Keyboard -- The keyboard device.  This is not a serial device, but
//          rather a matrix of on/off switches corresponding to the
//          individual keys.  Key indexes are scan codes, and "extended"
//          keys are the same as their scan codes + 256.
//
//���������������������������������������������������������������������������

#ifndef __MAXKB_HPP
#define __MAXKB_HPP    1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif


//���������������������������������������������������������������������������
//
//                                Includes
//
//���������������������������������������������������������������������������

#include <portable.h>
#include <dinput.h>

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
//����������������������������  MaxKeyboard  ��������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// MaxKeyboard - ABSTRACT
//
// The Keyboard class is used to manage the keyboad, it mantains
// a list of all the keys on the keyboard and has their state.
// Any given key can be either up or down.  A Zero value for that
// key will represent the UP position of the key, any other value
// will represent the DOWN position of the key.  There should be
// no reason to ever use this class seperate from the EventSystem.
// However, there is nothing keeping you from doing it.
//���������������������������������������������������������������������������
class MaxKeyboard
{
protected:
    //�����������������������������������������������������������������������
    // Implementation Data
    //�����������������������������������������������������������������������
    dword   KeyStat[16];         // The Up/Down Status of the keys.
    dword   KeyStatHold[16];     // The Up/Down Status of the keys.
    int     KeyStatCount;
    bool    initialized;

    //�����������������������������������������������������������������������
    // MaxKbBuffer support.
    //   The MaxKbBuffer objects modify this link pointer themselves.
    //   Consequently, we should only read it.
    //�����������������������������������������������������������������������
    friend class MaxKbBuffer;
    MaxKbBuffer *BuffList;
    void        process_key (ushort);

public:
    //�����������������������������������������������������������������������
    // Construtor/Destructor
    //�����������������������������������������������������������������������
    MaxKeyboard ();
    virtual ~MaxKeyboard ();

    //�����������������������������������������������������������������������
    // Operations
    //�����������������������������������������������������������������������
    virtual int  init ();
    virtual void uninit ();
    virtual void clear ();
    virtual void update () = 0;

    virtual int check_key (int key) const;

    // These members allows a Windows application to avoid loosing
    // characters when the frame rate drops too low for "normal"
    // responsiveness.  Simply call these members with the WindowProc
    // on WM_KEYDOWN and WM_KEYUP messages respectively.
    virtual void wm_keydown (int);
    virtual void wm_keyup   (int);

    //�����������������������������������������������������������������������
    // Accessors
    //�����������������������������������������������������������������������
    virtual bool is_present () const;
    bool is_initialized () const { return initialized; }
};


//���������������������������������������������������������������������������
// MaxKeyboardWin32
//���������������������������������������������������������������������������
class MaxKeyboardWin32: public MaxKeyboard
{
public:
    //�����������������������������������������������������������������������
    // Construtor/Destructor
    //�����������������������������������������������������������������������
    MaxKeyboardWin32 ();
    virtual ~MaxKeyboardWin32 ();

    //�����������������������������������������������������������������������
    // Operations
    //�����������������������������������������������������������������������
    virtual void update ();
    virtual void wm_keydown (int);
    virtual void wm_keyup   (int);
};


//���������������������������������������������������������������������������
// MaxKeyboardDirectX
//���������������������������������������������������������������������������
class MaxKeyboardDirectX: public MaxKeyboard
{
protected:
    //�����������������������������������������������������������������������
    // Implementation Data
    //�����������������������������������������������������������������������
    IDirectInputDevice  *pdid;
    enum { DIDATA_SIZE = 32 };

public:
    //�����������������������������������������������������������������������
    // Construtor/Destructor
    //�����������������������������������������������������������������������
    MaxKeyboardDirectX (IDirectInput *, HWND);
    virtual ~MaxKeyboardDirectX ();

    //�����������������������������������������������������������������������
    // Operations
    //�����������������������������������������������������������������������
    virtual int  init ();
    virtual void uninit ();
    virtual void update ();

    //�����������������������������������������������������������������������
    // Accessors
    //�����������������������������������������������������������������������
    virtual bool is_present () const;
};


//���������������������������������������������������������������������������
//����������������������������  MaxKbBuffer  ��������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// MaxKbBuffer
//  This class provides a character buffer for MaxKeyboard.  This key
//  buffer can be queried with "C" conio-like routines.  It is a little
//  magic, since the keyboard interrupt routine knows about it.
//���������������������������������������������������������������������������
class MaxKbBuffer
{
// This is actually a linked list node.  MaxKeyboard is given direct
// access so that it alone can walk the list.
    friend class MaxKeyboard;
    MaxKbBuffer *next;
    MaxKeyboard *kb;

// The actual KbBuff stuff
    enum    { BuffSize = 16 };
    ushort  buff[BuffSize];
    int     head;
    int     tail;

public:
    //�����������������������������������������������������������������������
    // Construtor/Destructor
    //�����������������������������������������������������������������������
    MaxKbBuffer (MaxKeyboard *);
    ~MaxKbBuffer();

    //�����������������������������������������������������������������������
    // Operations
    //�����������������������������������������������������������������������
    // The "serial" interface to emulate the standard C console routines
    int  getch ();
    int  getscan();
    int  kbhit () const  { return tail != head; }
    void clear ()        { head = tail = 0; }

    // Translation services
    byte get_ascii (byte scan) const;

    // Add a key to the keypress buffer
    void AddKey (ushort);

    //�����������������������������������������������������������������������
    // For link support
    //�����������������������������������������������������������������������
    void        set_next (MaxKbBuffer *n)   { next = n; }
    MaxKbBuffer *get_next () const          { return next; }
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

//��� End of header - maxkb.hpp ���