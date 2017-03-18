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
// global.hpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __GLOBAL_HPP
#define __GLOBAL_HPP    1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

// NOTE: the including file must define any Windows control defines

#include <windows.h>
#include <stdio.h>
#include <ddraw.h>

#include "portable.h"
#include "debug.h"

#include <chronos.hpp>
#include <ivory.hpp>
#include <max.hpp>
#include <vangogh.hpp>
#include <gutenbrg.hpp>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#if defined (WIN32)
        #define IS_WIN32 TRUE
#else
        #define IS_WIN32 FALSE
#endif
#define IS_NT      IS_WIN32 && (BOOL)(GetVersion() < 0x80000000)
#define IS_WIN32S  IS_WIN32 && (BOOL)(!(IS_NT) && (LOBYTE(LOWORD(GetVersion()))<4))
#define IS_CHICAGO (BOOL)(!(IS_NT) && !(IS_WIN32S)) && IS_WIN32

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


// The game class
class GameState
{
protected:
    TCHAR   szFileName[MAX_PATH];

    MaxDevices          *devs;
    MaxEventSource      *evt;           // Source of our events
    MaxEventListOneshot oneshot;        // Track events for single_events
    MaxEventListToggle  toggles;
    MaxEventList        events;         // Most current event set
    MaxEventList        single_events;  // Most current event set, momentary
    MaxEventList        toggle_events;
    VngoTexture         tex[11];
    VngoCTexture        *testtex;
    int                 map_xsize;
    int                 map_ysize;

public:     // Construction/Destruction
//    enum { MAP_XSIZE = 320, MAP_YSIZE = 240};
    enum { MAP_XSIZE = 640, MAP_YSIZE = 480};
//    enum { MAP_XSIZE = 512, MAP_YSIZE = 384};
//    enum { MAP_XSIZE = 400, MAP_YSIZE = 300};

    VngoVport           *gvp;
    VngoVport           *gvp2;
    VngoPal             *mypal;

    GameState (MaxDevices *);
    ~GameState ();

    BOOL                active;
    BOOL                PixTest;
    BOOL                PolyTest;
    BOOL                GPolyTest;
    BOOL                GRPolyTest;
    BOOL                TPolyTest;
    BOOL                GTPolyTest;
    BOOL                TPolyTestPersp;
    BOOL                GTPolyTestPersp;
    BOOL                LineTest;
    BOOL                GLineTest;
    BOOL                ITransTest;
    BOOL                BackGroundFill;
    BOOL                Reset;
    BOOL                ZBuffer;

    Chronometer         render_timer;
    ulong               frames;
    ulong               ticks;

    AtomicChronometer   reset_timer;
    AtomicChronometer   draw_timer;
    AtomicChronometer   flip_timer;

    VngoScreenManager  *screen;


            // Per-Frame Members
    virtual BOOL    PumpWindows ();
    virtual void    LoadEvents (LPCSTR lpszFile);
    virtual void    GetEvents ();
    virtual void    ProcessEvents();
    virtual void    Render();
    virtual void    Display();
};


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                 Data
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern HINSTANCE   hInst;         // current instance
extern HWND        hWndClient;    // Main window handle
extern const char  szAppName[];
extern GameState   *game;

#endif

//°±² End of header - global.hpp ²±°

