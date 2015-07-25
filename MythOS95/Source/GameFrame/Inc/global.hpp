//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                        _/_/_/           _/_/_/_/
//                      _/                _/
//                     _/  _/_/          _/_/_/
//                    _/    _/  A M E   _/      R A M  E
//                     _/_/_/          _/
//
// A Framework for Microsoft Windows '95 Entertainment Software Using MythOS
//
//          Copyright (c) 1995 - 1997 by Charybdis Enterprises, Inc.
//                           All Rights Reserved
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
// global.hpp
//
// This the global includes, external references, and class definitions.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __GLOBAL_HPP
#define __GLOBAL_HPP    1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄ Standard headers
// NOTE: the including file must define any Windows control defines
#include <windows.h>
#include <stdlib.h>
#include <ddraw.h>
#include "resource.h"

#include "dplay.h"

//ÄÄÄ Charybdis headers
#include <assert.h>
#include <portable.h>
#include <debug.h>
#include <mythos.hpp>
#include <turner.hpp>

#include <newton.hpp>

//ÄÄÄ GameFrame header
#include "screen.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define MYTHOS_MEM_SIZE             4*1024*1024
#define MYTHOS_TASK_STACK_SIZE      16*1024
#define MYTHOS_ESCHER_ARENA_SIZE    256*1024

#define CMDFLAGS_DIRECTDRAW     0x1     // Use DirectDraw instead of GDI
#define CMDFLAGS_DIBSWITCH      0x2     // Allow mode switch for DIB mode
#define CMDFLAGS_JOYSTICK       0x4     // Allow joystick usage

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GameState
//
// This class is used to encapsulate the state of a controlling mode.
// Most games have a number of modes, such as title/demo, options screens,
// and simulation mode.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class GameState
{
public:
    GameState ();
    virtual ~GameState ();

    // These members control the "grungy windows code", and won't generally
    // need to be overridden.
    virtual BOOL    pump_windows ();
    virtual void    display();

    // These members are app-specific, and must always be overridden.
    virtual void    process_events() = 0;
    virtual void    render() = 0;

    // Members that notify each game state when it is being activated
    virtual void    activate ();
    virtual void    deactivate ();

    // Fatal error handler
    virtual void panic (ulong id, const char *str=0);

    // A utility member to make mode switching easier
    void switch_to (GameState *);
};

class LunarLander;
class LanderTitle;
class LanderLanded;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                 Data
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄ Standard Windows data
extern HINSTANCE        hInst;          // current instance
extern HWND             hWndClient;     // Main window handle
extern const char       szAppName[];

//ÄÄÄ Command Line Parse Results
extern dword            CmdFlags;
extern char             CmdMission[];

//ÄÄÄ GameFrame and MythOS data
extern GFScreen         *Screen;
extern MythosSystem     *MythOS;
extern MaxDevices       *Devs;
extern GameState        *Mode;
extern TurnerNetwork    *Net;

//ÄÄÄ Lander data
extern char szMasterIFF[];
extern char szINI[];

extern LanderTitle  *TitleMode;
extern LunarLander  *SimMode;
extern LanderLanded *LandMode;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                          Inline Functions
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// This function is used to switch to a new GameState as the controlling
// mode.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
inline void GameState::switch_to (GameState *next)
{
    assertMyth ("Switch_to cannot switch to NULL", next != 0);
    deactivate();
    Mode = next;
    Mode->activate();
}

#endif

//°±² End of header - global.hpp ²±°

