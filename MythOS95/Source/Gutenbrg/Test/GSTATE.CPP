//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//           __ ,                                                      
//            ,-| ~           ,               ,,                      
//           ('||/__,        ||               ||                  _   
//          (( |||  | \\ \\ =||=   _-_  \\/\\ ||/|,  _-_  ,._-_  / \\ 
//          (( |||==| || ||  ||   || \\ || || || || || \\  ||   || || 
//           ( / |  , || ||  ||   ||/   || || || |' ||/    ||   || || 
//            -____/  \\/\\  \\,  \\,/  \\ \\ \\/   \\,/   \\,  \\_-| 
//                                                               /  \ 
//                                                              '----`
//                     Text Output and Font Management System
//                          Microsoft Windows '95 Version
//
//            Copyright (c) 1995-1997 by Charybdis Enterprises, Inc.
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
// GState.cpp
//
//  This file contains the member functions for the class that describes
//  the current game state.  This class also "runs" the game, but must
//  be driven by an outside program.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define WIN32_LEAN_AND_MEAN
#include "global.hpp"
#include "GFrame.hpp"
#include "test.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

const int COLORS = 256;

const int MAXPAGES = 3;

extern MaxDevices *Devs;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState Constructor
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
GameState::GameState (MaxDevices *d):
    devs (d), evt (0), active (FALSE), page(0)
{
    bmi = (LPBITMAPINFO)ivory_alloc (sizeof (BITMAPINFOHEADER) + COLORS*sizeof (RGBQUAD));
    if (bmi)
    {
        memset (bmi, 0, sizeof (*bmi));
        bmi->bmiHeader.biSize        = sizeof (BITMAPINFOHEADER);
        bmi->bmiHeader.biWidth       = MAP_XSIZE;
        bmi->bmiHeader.biHeight      = -MAP_YSIZE;
        bmi->bmiHeader.biPlanes      = 1;
        bmi->bmiHeader.biBitCount    = 8;
        bmi->bmiHeader.biCompression = BI_RGB;
        bmi->bmiHeader.biClrUsed     = COLORS;
        bmi->bmiHeader.biClrImportant= COLORS;

        gmap = new BYTE [MAP_XSIZE * MAP_YSIZE];
        // Init viewport?
        mypal = new VngoPal8;
        if (mypal)
        {
            if (mypal->init(0,".\\default.pal") != 0)
            {
                delete mypal;
                mypal = NULL;
            }
        }
        if (mypal)
        {
            VngoPal8 *t=(VngoPal8 *)mypal;
            for (int i=0;i < COLORS; i++)
            {
                bmi->bmiColors[i].rgbBlue   = t->hw_pal.p[i].b;
                bmi->bmiColors[i].rgbGreen  = t->hw_pal.p[i].g;
                bmi->bmiColors[i].rgbRed    = t->hw_pal.p[i].r;
                bmi->bmiColors[i].rgbReserved = 0;                
            }
            gvp = new VngoVportDB8(MAP_XSIZE,MAP_YSIZE,gmap,NULL,mypal,0);
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState Destructor
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
GameState::~GameState ()
{
    // Clean up our event source
    if (evt)
    {
        evt->uninstall();
        delete evt;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::LoadEvents
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::LoadEvents (LPCSTR lpszFile)
{
    // remember the filename
    strcpy (szFileName, lpszFile);

    // If we have an old event system, kill it
    if (evt)
    {
        evt->uninstall();
        delete evt;
    }

    // Create a new system
    evt = new MaxEventUser (*devs, szFileName, "gframe");

    // Verify the event system matches our set of events?

    // Now, let 'er rip!
    evt->install();
    active = TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::GetEvents
//
//      Get the events, and perform any internal processing based on their
//  presence.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::GetEvents()
{
    if (!evt)
    {
        events = MaxEventList (0);
        return;
    }

    // Otherwise, strobe the devices and get our events (and oneshots)
    events = evt->process ();
    single_events = oneshot.process (events);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::PumpWindows
//
//  Runs one cycle of the windows message pump.
//  Returns whether or not we should still be alive.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL GameState::PumpWindows ()
{
    MSG msg;

    Devs->wm_clear();
    while (PeekMessage (&msg, NULL, 0, 0, PM_NOREMOVE))
    {
    	if (GetMessage (&msg, 0, 0, 0) == 0)
            return FALSE;

        TranslateMessage (&msg);
        DispatchMessage (&msg);
    }
    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::ProcessEvents
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::ProcessEvents()
{
    if (events.check (DONE))
        DestroyWindow (hWndClient);

    if (single_events.check(SELECT_3X6))
        gberg_select_font("3x6");
    
    if (single_events.check(SELECT_5X8))
        gberg_select_font("5x8");
    
    if (single_events.check(SELECT_7X12))
        gberg_select_font("7x12");
    
    if (single_events.check(SELECT_8X13))
        gberg_select_font("8x13");
    
    if (single_events.check(SELECT_9X15))
        gberg_select_font("9x15");

    if (single_events.check(SELECT_12X24))
        gberg_select_font("12x24");

    if (single_events.check(PAGEDN))
    {
        if (page < MAXPAGES-1)
        {
            page++;
            Sleep(250);
        }
    }
    else if (single_events.check(PAGEUP))
    {
        if (page > 0)
        {
            page--;
            Sleep(250);
        }
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::Render
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::Render()
{
    int                 c;
    int                 x, y;
    GBergFontInfo       info;
    GBergText           gt(gvp);

    VngoColor24bit c1(0,0,255);
    VngoColor24bit c2(0,255,0);

    gvp->reset();

    switch (page)
    {
        case 0:
            gberg_info_font(0,&info);

            gberg_color(gvp->vbuff.pal->get_index(c1),
                        gvp->vbuff.pal->get_index(c2));
            
            //ÄÄÄÄ Do all font test.
            c=0;
            for(x=0; x < MAP_XSIZE-info.width-1; x+=info.width+1)
            {
                for(y=0; y < MAP_YSIZE-info.height-1; y += info.height+1)
                {
                    gberg_outc(gvp, x, y, (char)c++);

                    if (info.type == GBERG_FNT_MONOFIXEDEX
                        || info.type == GBERG_FNT_MONOVARIABLEEX)
                    {
                        if (c >= 256)
                            goto stop;
                    }
                    else if (c >= 128)
                        goto stop;
                }
            }
stop:;
            break;

        case 1:
            gt.out("This is a test\r\nof the text output object\n");
            gt.out(123);
            break;

        case 2:
            int         err;
            char        buff[1024];

            err=gberg_loadstring(MYTHOS_NAME,buff,1024);
            if (err) {
                sprintf(buff,"Gutenberg load string failed with error %d\n",err);
                gt.out(buff);
            }
            else {
                gt.out("String MYTHOS_NAME:\n");
                gt.out(buff);
                gt.outc('\n');
            }
            err=gberg_loadstring(COMPANY_NAME,buff,1024);
            if (err) {
                sprintf(buff,"Gutenberg load string failed with error %d\n",err);
                gt.out(buff);
            }
            else {
                gt.out("String COMPANY_NAME:\n");
                gt.out(buff);
                gt.outc('\n');
            }
            err=gberg_loadstring(GBERG_NAME,buff,1024);
            if (err) {
                sprintf(buff,"Gutenberg load string failed with error %d\n",err);
                gt.out(buff);
            }
            else {
                gt.out("String GBERG_NAME:\n");
                gt.out(buff);
                gt.outc('\n');
            }
            break;
    }
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::Display
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::Display()
{
    HDC hdc = GetDC (hWndClient);

    SetDIBitsToDevice (hdc, 0, 0, MAP_XSIZE, MAP_YSIZE, 0, 0, 0, MAP_YSIZE,
                       gmap, bmi, DIB_RGB_COLORS);

    ReleaseDC (hWndClient, hdc);
}


//°±² eof - GState.cpp ²±°

