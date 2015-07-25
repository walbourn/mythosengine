//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                /\    /\ 
//                               /  \  /  \ 
//                              /    \/    \ 
//                             /  /\    /\  \ 
//                            /  /  \  /  Y T H O S
//                           /  /    \/    \  \ 
//                          /  /            \  \ 
//                         /__/              \__\ 
//
//                    Microsoft Windows 95/NT Version
//
//            Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.
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
//                          LUNAR LANDER EXAMPLE
//
// Created by Chuck Walbourn and Dan Higdon
//
// llapp.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "llander.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

LanderApp theSim;

char      szINI[] = "LLANDER.INI";
char      szIFF[] = "LLANDER.IFF";

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderApp - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
LanderApp::LanderApp() :
    SimGine(),
    title(0),
    game(0),
    end(0)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderApp - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
LanderApp::~LanderApp()
{
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderApp - init_instance
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL LanderApp::init_instance()
{
//ÄÄÄ Load settings from .INI file
    {
        XFParseINI ini;
        char buff[256];

        ini.open(szINI, XF_OPEN_READ | XF_OPEN_DENYWRITE);

        //ÄÄÄ Screen parameters
        if (!ini.section("Screen"))
        {
            if (!ini.read("Device",buff))
            {
                strlwr(buff);

                startup &= ~(STARTUP_DDRAW
                             | STARTUP_D3D
                             | STARTUP_CLEAR3D);

                if (strstr(buff,"d3d"))
                    startup |= STARTUP_D3D;
                else

#ifdef  _OEMS
#ifdef  _CLEAR_3D
                if (strstr(buff,"cl3d"))
                    startup |= STARTUP_CLEAR3D;
                else
#endif
#endif

                if (strstr(buff,"ddraw"))
                    startup |= STARTUP_DDRAW;
            }

            if (!ini.read("FullScreen",buff))
            {
                strlwr(buff);
                if (strstr(buff,"no"))
                    startup &= ~STARTUP_FULLSCREEN;
            }

            if (!ini.read("Resolution",buff))
            {
                strlwr(buff);
                if (strstr(buff,"320x240x8"))
                {
                    startup_width = 320;
                    startup_height = 240;
                    startup_bitdepth = 8;
                }
                else if (strstr(buff,"640x480x8"))
                {
                    startup_width = 640;
                    startup_height = 480;
                    startup_bitdepth = 8;
                }
                else if (strstr(buff,"640x480x15"))
                {
                    startup_width = 640;
                    startup_height = 480;
                    startup_bitdepth = 15;
                }
                else if (strstr(buff,"640x480x16"))
                {
                    startup_width = 640;
                    startup_height = 480;
                    startup_bitdepth = 16;
                }
            }
        }

        //ÄÄÄ Startup parameters
        if (!ini.section("Startup"))
        {
            if (!ini.read("DirectInput",buff))
            {
                strlwr(buff);
                if (strstr(buff,"yes"))
                    startup |= STARTUP_DX5;
            }
        }

        ini.close();
    }

    if (startup & STARTUP_D3D)
    {
        // Direct3D can only run in 15- or 16-bit
        if (startup_bitdepth == 8)
            startup_bitdepth = 16;
    }
    else

#ifdef  _OEMS
#ifdef  _CLEAR_3D
    if (startup & STARTUP_CLEAR3D)
    {
        // Clear3D can only run in 16-bit
        startup_bitdepth = 16;
    }
    else
#endif
#endif

    if (!(startup & STARTUP_DDRAW))
    {
        // DIB can only run in 8- or 15-bit
        if (startup_bitdepth == 16)
            startup_bitdepth = 15;
    }

//ÄÄÄ Perform base init
    if (!SimGine::init_instance())
    {
        MessageBox(NULL, "SimGine Failed to Initialize Instance",
                   appName, MB_ICONEXCLAMATION | MB_OK);
        return FALSE;
    }

//ÄÄÄ Install fonts
    if (gberg_install_font(szIFF, "9x15")
        || gberg_install_font(szIFF, "12x24"))
    {
        MessageBox(NULL, "Failed to load fonts",
                   appName, MB_ICONEXCLAMATION | MB_OK);
        return FALSE;
    }

//ÄÄÄ Create states
    title = new LanderTitle;
    game = new LanderGame;
    end = new LanderEnd;
    if (!title
        || !game
        || !end)
    {
        MessageBox(NULL, "Failed to create game states",
                   appName, MB_ICONEXCLAMATION | MB_OK);
        return FALSE;
    }

    Mode = title;

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderApp - exit_instance
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int LanderApp::exit_instance()
{
    if (title)
    {
        delete title;
        title = 0;
    }
    if (game)
    {
        delete game;
        game = 0;
    }
    if (end)
    {
        delete end;
        end = 0;
    }

    return SimGine::exit_instance();
}

//°±² eof - llapp.cpp ²±°
