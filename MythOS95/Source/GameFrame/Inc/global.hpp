//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                        _/_/_/           _/_/_/_/
//                      _/                _/
//                     _/  _/_/          _/_/_/
//                    _/    _/  A M E   _/      R A M  E
//                     _/_/_/          _/
//
// A Framework for Microsoft Windows '95 Entertainment Software Using MythOS
//
//              Copyright (c) 1995 by Charybdis Enterprises, Inc.
//                           All Rights Reserved
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// global.hpp
//
// This the global includes, external references, and class definitions
// for the GameFrame.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __GLOBAL_HPP
#define __GLOBAL_HPP    1

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//             
//                                Includes
//                                
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳� Standard headers
// NOTE: the including file must define any Windows control defines
#include <windows.h>
#include <stdlib.h>
#include "resource.h"

#include "dplay.h"

//陳� Charybdis headers
#include <assert.h>
#include <portable.h>
#include <debug.h>
#include <mythos.hpp>
#include <turner.hpp>


//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// GFScreen
//
// This class is the basic screen management class.  Since games typically
// have a single 'screen', this manages a single window with a memory
// DIB which is used for all drawing operations.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class GFScreen
{
public:
    HDC             hdc;
    LPBITMAPINFO    bmi;
    HPALETTE        hpal;

    BYTE            *bits;
    VngoVportDD8    *gvport;
    VngoPal8        *pal;

    int             height;
    int             width;

    GFScreen ();
    ~GFScreen ();

    int init(int w, int h);
    int load_palette(const char *);
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// GameState
//
// This class is used to encapsulate the state of a controlling mode.
// Most games have a number of modes, such as title/demo, options screens,
// and simulation mode.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class GameState
{
public:
    GameState ()    { }
    virtual ~GameState () { }

    // These members control the "grungy windows code", and won't generally
    // need to be overridden.
    virtual BOOL    pump_windows ();
    virtual void    display();

    // These members are app-specific, and must always be overridden.
    virtual void    process_events() = 0;
    virtual void    render() = 0;

    // Members that notify each game state when it is being activated
    virtual void    activate ()     { }
    virtual void    deactivate ()   { }

    // A utility member to make mode switching easier
    void switch_to (GameState *);
};

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                 Data
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳� Standard Windows data
extern HINSTANCE    hInst;          // current instance
extern HWND         hWndClient;     // Main window handle
extern const char   szAppName[];

//陳� GameFrame and MythOS data
extern GFScreen     *Screen;
extern MythosSystem *MythOS;
extern MaxDevices   *Devs;
extern GameState    *Mode;
extern TurnerNetwork *net;

//陳� Lander example data
class LunarLander;
class LanderTitle;
class LanderLanded;
extern LanderTitle  *TitleMode;
extern LunarLander  *SimMode;
extern LanderLanded *LandMode;

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                          Inline Functions
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// This function is used to switch to a new GameState as the controlling
// mode.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
inline void GameState::switch_to (GameState *next)
{
    assertMyth ("Switch_to can switch to NULL", next != 0);
    deactivate();
    next->activate();
    Mode = next;
}

#endif

//葦� End of header - global.hpp 憶�

