//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
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
//                  Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                          LUNAR LANDER EXAMPLE
//
// Created by Chuck Walbourn and Dan Higdon
//
// llapp.cpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "llander.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

LanderApp theSim;

char      szINI[] = "LLANDER.INI";
char      szIFF[] = "LLANDER.IFF";

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// LanderApp - Constructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
LanderApp::LanderApp() :
    SimGine(),
    title(0),
    game(0),
    end(0)
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// LanderApp - Destructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
LanderApp::~LanderApp()
{
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// LanderApp - init_instance
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BOOL LanderApp::init_instance()
{
    float gamma=1.0f;

//陳� Load settings from .INI file
    {
        XFParseINI ini;
        char buff[256];

        ini.open(szINI, XF_OPEN_READ | XF_OPEN_DENYWRITE);

        //陳� Screen parameters
        if (!ini.section("Screen"))
        {
            if (!ini.read("Device",buff))
            {
                strlwr(buff);

                startup &= ~(STARTUP_DDRAW
                             | STARTUP_D3D);

                if (strstr(buff,"d3d"))
                    startup |= STARTUP_D3D;
                else

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

            if (!ini.read("Gamma",buff))
            {
                gamma = float(atof(buff));
                if (gamma < 0.5f)
                    gamma = 0.5f;
                else if (gamma > 2.0f)
                    gamma = 2.0f;
            }
        }

        //陳� Startup parameters
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

//陳� Perform base init
    if (!SimGine::init_instance())
    {
        MessageBox(NULL, "SimGine Failed to Initialize Instance",
                   appName, MB_ICONEXCLAMATION | MB_OK);
        return FALSE;
    }

    MythOS->Vangogh.set_gamma(gamma);

//陳� Install fonts
    if (gberg_install_font(szIFF, "9x15")
        || gberg_install_font(szIFF, "12x24"))
    {
        MessageBox(NULL, "Failed to load fonts",
                   appName, MB_ICONEXCLAMATION | MB_OK);
        return FALSE;
    }

//陳� Create states
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// LanderApp - exit_instance
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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

//葦� eof - llapp.cpp 憶�
