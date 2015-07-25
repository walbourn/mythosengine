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
//           Copyright (c) 1994 - 1997 by Charybdis Enterprises, Inc.
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
//
//  Keyboard -- The keyboard device.  This is not a serial device, but
//          rather a matrix of on/off switches corresponding to the
//          individual keys.  Key indexes are scan codes, and "extended"
//          keys are the same as their scan codes + 256.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <assert.h>
#include <string.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <ivory.hpp>

#include "maxdevs.hpp"
#include "maxkb.hpp"

#include <iostream.h>

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
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                              Static Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

// Scan code coversion tables

static unsigned char scan2ascii[128] =
{
    0x00, 0x1b, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
    0x37, 0x38, 0x39, 0x30, 0x2d, 0x3d, 0x08, 0x09,

    0x71, 0x77, 0x65, 0x72, 0x74, 0x79, 0x75, 0x69,
    0x6f, 0x70, 0x5b, 0x5d, 0x0d, 0x00, 0x61, 0x73,

    0x64, 0x66, 0x67, 0x68, 0x6a, 0x6b, 0x6c, 0x3b,
    0x27, 0x60, 0x00, 0x5c, 0x7a, 0x78, 0x63, 0x76,

    0x62, 0x6e, 0x6d, 0x2c, 0x2e, 0x2f, 0x00, 0x2a,
    0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x2d, 0x00, 0x00, 0x00, 0x2b, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static unsigned char shift2ascii[128] =
{
    0x00, 0x1b, 0x21, 0x40, 0x23, 0x24, 0x25, 0x5e,
    0x26, 0x2a, 0x28, 0x29, 0x5f, 0x2b, 0x08, 0x00,

    0x51, 0x57, 0x45, 0x52, 0x54, 0x59, 0x55, 0x49,
    0x4f, 0x50, 0x7b, 0x7d, 0x0d, 0x00, 0x41, 0x53,

    0x44, 0x46, 0x47, 0x48, 0x4a, 0x4b, 0x4c, 0x3a,
    0x22, 0x7e, 0x00, 0x7c, 0x5a, 0x58, 0x43, 0x56,

    0x42, 0x4e, 0x4d, 0x3c, 0x3e, 0x3f, 0x00, 0x2a,
    0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x37,
    0x38, 0x39, 0x2d, 0x34, 0x35, 0x36, 0x2b, 0x31,

    0x32, 0x33, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static unsigned char ctrl2ascii[128] =
{
    0x00, 0x1b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e,
    0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x7f, 0x00,

    0x11, 0x17, 0x05, 0x12, 0x14, 0x19, 0x15, 0x09,
    0x0f, 0x10, 0x1b, 0x1d, 0x0a, 0x00, 0x01, 0x13,

    0x04, 0x06, 0x07, 0x08, 0x0a, 0x0b, 0x0c, 0x00,
    0x00, 0x00, 0x00, 0x1c, 0x1a, 0x18, 0x03, 0x16,

    0x02, 0x0e, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};


//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                          Keyboard Member Functions
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Create a Keyboard object.                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
MaxKeyboard::MaxKeyboard():
    BuffList (0)
{
    // Nothing to do here
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Destroy a Keyboard object.                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
MaxKeyboard::~MaxKeyboard()
{
    // Nothing to do here
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Init                                                                    ³
//      Allocate any needed resources                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int MaxKeyboard::init ()
{
    // Do any setup
    KeyStat[0] = 0;
    KeyStat[1] = 0;
    KeyStat[2] = 0;
    KeyStat[3] = 0;
    KeyStat[4] = 0;
    KeyStat[5] = 0;
    KeyStat[6] = 0;
    KeyStat[7] = 0;

    clear();

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  clear                                                                   ³
//      Clear the modal keyposition flags.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxKeyboard::clear ()
{
    KeyStatHold[0] = KeyStat[0];
    KeyStatHold[1] = KeyStat[1];
    KeyStatHold[2] = KeyStat[2];
    KeyStatHold[3] = KeyStat[3];
    KeyStatHold[4] = KeyStat[4];
    KeyStatHold[5] = KeyStat[5];
    KeyStatHold[6] = KeyStat[6];
    KeyStatHold[7] = KeyStat[7];
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Uninit                                                                  ³
//      Release any resources associated with the Keyboard object.          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxKeyboard::uninit ()
{
    // Do any cleanup
    KeyStatHold[0] = KeyStat[0] = 0;
    KeyStatHold[1] = KeyStat[1] = 0;
    KeyStatHold[2] = KeyStat[2] = 0;
    KeyStatHold[3] = KeyStat[3] = 0;
    KeyStatHold[4] = KeyStat[4] = 0;
    KeyStatHold[5] = KeyStat[5] = 0;
    KeyStatHold[6] = KeyStat[6] = 0;
    KeyStatHold[7] = KeyStat[7] = 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  wm_keydown                                                              ³
//      Notify the model that a key has been pressed.                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxKeyboard::wm_keydown (int vkey)
{
    // NOP
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  wm_keyup                                                                ³
//      Notify the model that a key has been released.                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxKeyboard::wm_keyup (int vkey)
{
    // NOP
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  process_key - utility                                                   ³
//      Run the key through the kb buffer list.                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxKeyboard::process_key (ushort cooked_key)
{
    if (BuffList)
    {
        // Check the Shift keys (0x2a and 0x36)
        if (check_key (0x2a) || check_key (0x36))
            cooked_key |= 0x100;

        // Check the ALT keys (0x38 and 0x138)
        if (check_key (0x38) || check_key (0x138))
            cooked_key |= 0x200;

        // Check the Ctrl keys (0x1d and 0x11d)
        if (check_key (0x1d) || check_key (0x11d))
            cooked_key |= 0x400;

        // Add the key to any applicable key buffers
        for (MaxKbBuffer *l = BuffList; l; l = l->next)
            l->AddKey (cooked_key);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  CheckKey                                                                ³
//      Return the up/down status of the requested key.                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int MaxKeyboard::check_key (int key) const
{
    const int offset (((key >> 5) & 0x03) + (key > 0xff ? 4: 0));
    const dword mask (1 << (key & 0x1f));

    // If the key has been marked, return true
    return (KeyStatHold[offset] & mask) != 0;
}


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Constructor                                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
MaxKeyboardWin32::MaxKeyboardWin32():
    MaxKeyboard ()
{
    // Nothing to do here
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Destroy a Keyboard object.                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
MaxKeyboardWin32::~MaxKeyboardWin32()
{
    // Nothing to do here
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Update                                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxKeyboardWin32::update ()
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  wm_keydown                                                              ³
//      Notify the model that a key has been pressed.                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxKeyboardWin32::wm_keydown (int vkey)
{
    UINT scan_code = MapVirtualKey (vkey, 0);

    const dword mask  = 1 << (scan_code & 0x1f);
    int offset = (scan_code >> 5) & 0x03;

    // Actually mark the key as present
    KeyStat[offset] |= mask;
    KeyStatHold[offset] |= mask;

    // Get the "cooked" key value, and pass it to the kb buffers.
    process_key (ushort (scan_code & 0xff));
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  wm_keyup                                                                ³
//      Notify the model that a key has been released.                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxKeyboardWin32::wm_keyup (int vkey)
{
    UINT scan_code = MapVirtualKey (vkey, 0);

    const dword mask = 1 << (scan_code & 0x1f);
    int offset = (scan_code >> 5) & 0x03;

    // Actually mark the key as present
    KeyStat[offset] &= ~mask;
}


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Constructor                                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
MaxKeyboardDirectX::MaxKeyboardDirectX (IDirectInput *pdi, HWND _hwnd):
    MaxKeyboard (),
    pdid (0)
{
    HRESULT hr = pdi->CreateDevice (GUID_SysKeyboard, &pdid, NULL);

    // Obtain an IDirectInputDevice2 interface
    if (!SUCCEEDED(hr))
        pdid = 0;

    pdid->SetCooperativeLevel (_hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Destroy a Keyboard object.                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
MaxKeyboardDirectX::~MaxKeyboardDirectX()
{
    if (pdid)
    {
        pdid->Unacquire();
        pdid->Release();
        pdid = 0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Init                                                                    ³
//      Allocate any needed resources, and set up the interrupt handler.    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int MaxKeyboardDirectX::init ()
{
    MaxKeyboard::init();

    if (pdid)
    {
        pdid->SetDataFormat (&c_dfDIKeyboard);

        // Set the keyboard up for buffered access
        DIPROPDWORD prop;
        prop.diph.dwSize = sizeof (DIPROPDWORD);
        prop.diph.dwHeaderSize = sizeof (DIPROPHEADER);
        prop.diph.dwObj = 0;
        prop.diph.dwHow = DIPH_DEVICE;
        prop.dwData = DIDATA_SIZE;
        pdid->SetProperty (DIPROP_BUFFERSIZE, &prop.diph);

        pdid->Acquire();
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Uninit                                                                  ³
//      Release any resources associated with the Keyboard object.          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxKeyboardDirectX::uninit ()
{
    MaxKeyboard::uninit();

    if (pdid)
        pdid->Unacquire();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  Update                                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxKeyboardDirectX::update ()
{
    // The buffer cannot hold more than this ammount, so we will never
    // have to iterate.  Of course, we MIGHT loose data....
    DIDEVICEOBJECTDATA didata[DIDATA_SIZE];
    dword size = DIDATA_SIZE;
    while (pdid->GetDeviceData (sizeof (DIDEVICEOBJECTDATA),
                                didata,
                                &size,
                                0) == DIERR_INPUTLOST)
    {
        HRESULT hr = pdid->Acquire();

        // We can't reacquire, so don't go any further
        if (!SUCCEEDED (hr))
            return;
    }

    for (dword i = 0; i < size; i++)
    {
        const dword scan (didata[i].dwOfs);
        const dword mask (1 << (scan & 0x1f));
        const int offset ((scan >> 5) & 0x03);

        if (didata[i].dwData & 0x80)
        {
            // Down - mark the key as present
            KeyStat[offset] |= mask;
            KeyStatHold[offset] |= mask;

            // Get the "cooked" key value, and pass it to the kb buffers.
            process_key (ushort (scan & 0xff));
        }
        else
        {
            // Up - mark the key as absent
            KeyStat[offset] &= ~mask;
        }
    }
}


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//  MaxKbBuffer
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


MaxKbBuffer::MaxKbBuffer (MaxKeyboard *_kb):
    kb (_kb), head (0), tail (0)
{
    assert (kb != 0);

    // Link us into the head of the chain.
    next = kb->BuffList;
    kb->BuffList = this;
}


MaxKbBuffer::~MaxKbBuffer()
{
    // This routine works on the assumption that we are still in the
    // buffer list.  If we aren't we're in big trouble anyway, so it's
    // OK to trap on these conditions.
    MaxKbBuffer *n = kb->BuffList;

    // First, we know that there is at least one node (us).
    assert (n);

    // Catch the special case that we are the head of the list.
    if (n == this)
    {
        // Remove the first item from the list
        kb->BuffList = next;
    }
    else
    {
        // Since the first node wasn't us, and we know we're in the
        // list, we can make this assumption.
        assert (n->next);

        // Find our item in the list and remove it.
        while (n->next != this)
        {
            // Since our node should always be in the list, we can likewise
            // assume that it will be found before we run out of nodes.
            assert (n->next);
            n = n->next;
        }

        // Here, n->next must point to our node, so let's unlink ourselves.
        n->next = next;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  getch                                                                   ³
//      Return the next key in the input buffer.  Keys may be lost from     ³
//  buffer overflow.                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int MaxKbBuffer::getch ()
{
    // Wait until a key has been pressed
    while (!kbhit ())
        ;

    // Get the key
    // (The low byte is the scan code, the high byte is modifier info)
    const ushort res = buff[tail];
    unsigned char ch = (unsigned char)(res & 0x7f);

    // Adjust the tail pointer, if necessary.
    tail = (tail == BuffSize-1) ? 0: tail + 1;

    // Convert the result into an ASCII value.

#if 1
    // ALT key modifier (in this case, just return the scan code)
    if (res & 0x200)
    {
        return 0x100 | res & 0xff;
    }

    // Control key modifier (convert chars with Control equivalent, return others as scancodes)
    if (res & 0x400)
    {
        if (ctrl2ascii[ch])
            return ctrl2ascii[ch];
        else
            return 0x100 | ch;
    }

    // Shift key modifier (convert shift chars, all others as ascii)
    if (res & 0x100)
    {
        if (shift2ascii[ch])
            return shift2ascii[ch];
    }

    // Normal keypress
    if (scan2ascii[ch])
        return scan2ascii[ch];
    else
        return 0x100 | ch;
#endif

    return ch;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  getscan                                                                 ³
//      Return the next key in the input buffer.  Keys may be lost from     ³
//  buffer overflow.  Returns the key as a scan code.                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int MaxKbBuffer::getscan ()
{
    // Wait until a key has been pressed
    while (!kbhit ())
        ;

    // Get the key
    // (The low byte is the scan code, the high byte is modifier info)
    const ushort res = buff[tail];

    // Adjust the tail pointer, if necessary.
    tail = (tail == BuffSize-1) ? 0: tail + 1;

    // Let the user have it! (so to speak).
    return 0x100 | (res & 0xff);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  get_ascii                                                               ³
//      Convert the scan code to an ascii value.  If no conversion          ³
//  is possible, return 0.                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
byte MaxKbBuffer::get_ascii (byte scan) const
{
    if (scan < 128)
        return scan2ascii[scan];
    else
        return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//  AddKey                                                                  ³
//      Adds the key to the keyboard buffer as an ASCII code.               ³
//  On overflow, the oldest key pressed is discarded.                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void MaxKbBuffer::AddKey (ushort key)
{
    // Store the key.
    buff[head] = key;

    // Keep the head pointer in the correct range
    head = (head == BuffSize-1) ? 0: head + 1;

    // Now, if we collide with the Tail pointer, loose the last character
    // and make sure the tail pointer is still valid.
    if (head == tail)
        tail = (tail == BuffSize-1) ? 0: tail + 1;
}


//°±² End of module - maxkb.cpp ²±°
