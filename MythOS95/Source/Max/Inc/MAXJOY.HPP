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
//  Joystick -- The standard IBM Joystick.  Like the mouse, this device
//          can only be queried for its current state.
//
//���������������������������������������������������������������������������

#ifndef __MAXJOY_HPP
#define __MAXJOY_HPP    1

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
// MaxJoystick - ABSTRACT
//  Provides the standard Joystick interface class
//���������������������������������������������������������������������������
class MaxJoystick
{
protected:
    //�����������������������������������������������������������������������
    // Protected Data
    //�����������������������������������������������������������������������

    // Controls the access method for the joystick
    short       auto_polled;
    MMRESULT    timer_id;

    // Tells which axes are active; bit 1 == Joy1, etc.
    short       joy_present;
    bool        initialized;

public:
    //�����������������������������������������������������������������������
    // Constructor/Destructor
    //�����������������������������������������������������������������������
    MaxJoystick();
    virtual ~MaxJoystick();

    //�����������������������������������������������������������������������
    // Operations
    //�����������������������������������������������������������������������
    virtual short init () = 0;
    virtual void  uninit () = 0;
    virtual void  clear ();

    virtual void get_stat (JOYINFOEX *) const = 0;
    virtual int  auto_poll (BOOL = TRUE, UINT rate = 50) = 0;

    //�����������������������������������������������������������������������
    // Accessors
    //�����������������������������������������������������������������������
    virtual IDirectInputDevice2 *get_di2() const;
//    virtual void get_caps (JOYCAPS *) const;
    bool is_present () const { return joy_present != 0; }
    bool is_initialized () const { return initialized; }
};


//���������������������������������������������������������������������������
// MaxJoystickWin32
//  Supports the standard IBM joystick device.
//���������������������������������������������������������������������������
class MaxJoystickWin32: public MaxJoystick
{
private:
    //�����������������������������������������������������������������������
    // Private Data
    //�����������������������������������������������������������������������
    JOYINFOEX   info;
    JOYCAPS     caps;

    // Callback for polling
    static void CALLBACK win32_poll_routine (UINT, UINT, DWORD, DWORD, DWORD);

public:
    //�����������������������������������������������������������������������
    // Constructor/Destructor
    //�����������������������������������������������������������������������
    MaxJoystickWin32 ();
    virtual ~MaxJoystickWin32();

    //�����������������������������������������������������������������������
    // Operations
    //�����������������������������������������������������������������������
    virtual short init ();
    virtual void  uninit ();

    virtual void get_stat (JOYINFOEX *) const;
    virtual int  auto_poll (BOOL = TRUE, UINT rate = 50);
};


//���������������������������������������������������������������������������
// MaxJoystickDirectX
//  Supports the DirectInput joystick device.
//���������������������������������������������������������������������������
class MaxJoystickDirectX: public MaxJoystick
{
    //�����������������������������������������������������������������������
    // Implementation Data
    //�����������������������������������������������������������������������
    IDirectInputDevice2 *pdid;
    DIDEVCAPS           dicaps;

    enum { DIDATA_SIZE = 32 };

    static void CALLBACK di_poll_routine (UINT, UINT, DWORD, DWORD, DWORD);

public:
    //�����������������������������������������������������������������������
    // Constructor/Destructor
    //�����������������������������������������������������������������������
    MaxJoystickDirectX (IDirectInput *, HWND);
    virtual ~MaxJoystickDirectX();

    //�����������������������������������������������������������������������
    // Operations
    //�����������������������������������������������������������������������
    virtual short init ();
    virtual void  uninit ();

    virtual void get_stat (JOYINFOEX *) const;
    virtual int  auto_poll (BOOL = TRUE, UINT rate = 50);

    //�����������������������������������������������������������������������
    // Accessors
    //�����������������������������������������������������������������������
    virtual IDirectInputDevice2 *get_di2() const;
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

//��� End of header - maxjoy.hpp ���