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
//              Copyright (c) 1995 by Charybdis Enterprises, Inc.
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
// main.cpp
//
// This module contains the WinMain function which is the application
// entry point.  This should perform the highest level flow control and
// process any command line switches.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define WIN32_LEAN_AND_MEAN
#include "llander.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

BOOL InitApplication (HINSTANCE, int, int, int);
STATIC int load_font(char *f);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

HINSTANCE       hInst;
HWND            hWndClient;
const char      szAppName[] = "LunarLander";

MythosSystem    *MythOS = 0;
MaxDevices      *Devs   = 0;
GFScreen        *Screen = 0;

LanderTitle     *TitleMode  = 0;
LunarLander     *SimMode    = 0;
LanderLanded    *LandMode   = 0;

GameState       *Mode       = 0;
TurnerNetwork   *net        = 0;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// WinMain
//
// Primary Application Entry Point
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int APIENTRY WinMain (HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPSTR     lpCmdLine,
                      int       nCmdShow)
{
    // This is a special hack initialization of Ivory so that we can
    // create the stackspace that Bozo needs to be initialized.
    // This needs to be revisited.

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Initialize

    // Set up desired screen size
    int width  = GetSystemMetrics (SM_CXSCREEN);
    int height = GetSystemMetrics (SM_CYSCREEN);

#ifdef DEBUG
    width /= 4;
    height /= 4;
#endif

    // If we are already running, this routine will reactivate the older
    // application and return failure.
	if (!InitApplication (hInstance, nCmdShow, width, height))
		return 1;

    // Initialize the MythOS system
    MythOS = new MythosSystem (4*1024*1024);

    // Create the devices, etc.
    Devs   = new MaxDevices;
    if (MythOS == 0 || Devs == 0)
    {
        MessageBox (NULL, "Unable to allocate memory for MythOS, exiting", "Error", MB_OK);
        return 1;
    }

    // Create a stack space for Bozo (so tasks can call Win32 APIs)
    char    bozo_stackspace[16*1024];
    IvorySubAlloc *bozo_alloc = (IvorySubAlloc *)bozo_stackspace;
    ivory_sub_initialize (bozo_alloc, sizeof (bozo_stackspace));

    // Finish MythOS initialization
    if (MythOS->init (128*1024, bozo_alloc))
    {
        MessageBox (NULL, "Unable to initialize MythOS, exiting", "Error", MB_OK);
        return 1;
    }

    // Install Gutenberg Fonts
    if (load_font("9X15.IFF")
        || load_font("12X24.IFF"))
        return 1;

    // Initialize the Screen object
    Screen = new GFScreen;
    if (Screen == 0 ||
        Screen->init (width, height) != 0 ||
        Screen->load_palette ("Default.VGP") != 0)
    {
        MessageBox (NULL, "Unable to initialize GFScreen module, exiting", "Error", MB_OK);
        return 1;
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Initialize Game Specifics
    TitleMode = new LanderTitle ();
    if (TitleMode == 0 ||
        TitleMode->init ("llander.iff", "landevt") != 0)
    {
        MessageBox (NULL, "Unable to start Lunar Lander Title, exiting", "Error", MB_OK);
        return 1;
    }

    SimMode = new LunarLander;
    if (SimMode == 0 ||
        SimMode->init ("llander.iff", "landevt") != 0)
    {
        MessageBox (NULL, "Unable to start Lunar Lander Simulator, exiting", "Error", MB_OK);
        return 1;
    }

    LandMode = new LanderLanded;
    if (LandMode == 0 ||
        LandMode->init ("llander.iff", "landevt") != 0)
    {
        MessageBox (NULL, "Unable to start Lunar Lander Landed Mode, exiting", "Error", MB_OK);
        return 1;
    }

    // Now, get the first mode preped and ready to roll.
    Mode = TitleMode;
    Mode->activate();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Main Loop
    assertMyth ("WinMain needs a valid Start Mode", Mode != 0);
    while (Mode->pump_windows ())
    {
        assertMyth ("WinMain needs a valid Mode", Mode != 0);

        Devs->update();
        Mode->process_events();
        Mode->render();
        Mode->display();
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Termination

    // Clean up the game here
    // (destructors get most of it)
    delete TitleMode;
    delete SimMode;
    delete LandMode;

    delete Screen;
    delete Devs;
    delete MythOS;

	return 0;

    // This shuts up the compiler
    lpCmdLine;
}

STATIC int load_font(char *f)
{
    int err;

    err=gberg_install_font(f,0);
    if (err)
    {
        char    buff[128];
        wsprintf (buff,"Failed to load font %s, error %d",f,(int)err);
        MessageBox(hWndClient,
                   buff,"Error",MB_OK);
        return 1;
    }
    return 0;
}

//°±² eof - main.cpp ²±°
