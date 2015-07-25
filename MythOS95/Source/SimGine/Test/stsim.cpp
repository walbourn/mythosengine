//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                              S I M   G I N E
//
//             __               ___   ______,-------
//           __==__,------------/|\--|      | .-.-.|    ___________
//         (|     |--------------|---|------| '-`-`|  _/___________\_
//         (|_____|      _       _   |   _  | 6000 | |               |
//          |__\\_|`-._/___\___/___\_|_/___\|      | |               |
//         __/ |===|--|_____|_|_____|_|___  |\_____|=|_______________|
//      |=|[_]==[_]    \ _ /   \ _ /   \ _ /          [_]   [_]   [_]
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                     A Simluator Framework for MythOS(tm)
//
//                      Microsoft Windows 95/NT Version
//
//            Copyright (c) 1997-1998 by Charybdis Enterprises, Inc.
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
// MythOS is a trademark of Charybdis Enterprises, Inc.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                               *** Tester ***
//
// stsim.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "st.hpp"

#include "stevt.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Tester Views  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// TesterView1
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
TesterView1::TesterView1(TesterUI *_parent) :
    SimView(_parent)
{
}

TesterView1::~TesterView1()
{
}

void TesterView1::activate()
{
    gberg_color(Screen->find(VngoColor24bit(255,0,0)), VNGO_TRANSPARENT);
}

void TesterView1::deactivate()
{
}

void TesterView1::process_events()
{
    if (((TesterUI*)parent)->events.check (VIEW2))
        switch_to(((TesterUI*)parent)->view2);
}

void TesterView1::render()
{
    Screen->clear();

    int waslocked=Screen->lock();

    SimText st(Screen);

    st.out(100,100,"View 1");

    if (!waslocked)
        Screen->unlock();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// TesterView2
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
TesterView2::TesterView2(TesterUI *_parent) :
    SimView(_parent)
{
}

TesterView2::~TesterView2()
{
}

void TesterView2::activate()
{
    gberg_color(Screen->find(VngoColor24bit(0,255,0)), VNGO_TRANSPARENT);
}

void TesterView2::deactivate()
{
}

void TesterView2::process_events()
{
    if (((TesterUI*)parent)->events.check (VIEW1))
        switch_to(((TesterUI*)parent)->view1);
}

void TesterView2::render()
{
    Screen->clear();

    int waslocked=Screen->lock();

    SimText st(Screen);

    st.out(100,100,"View 2");

    if (!waslocked)
        Screen->unlock();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Tester UIs  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// TesterUI
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
TesterUI::TesterUI(TesterSim *_parent) :
    SimUI (_parent),
    evt (0),
    view1 (0),
    view2 (0)
{
}
 
TesterUI::~TesterUI()
{
    deactivate();
}

void TesterUI::activate()
{
//ÄÄÄ Load palette and set color
    if (!Screen->load_palette("Default.VGP", 0))
        parent->panic("TesterState::activate failed to load palette");

//ÄÄÄ Create views
    view1 = new TesterView1(this);
    view2 = new TesterView2(this);

    if (!view1 || !view2)
        return;

    view = view1;

//ÄÄÄ Create event system
    evt = new MaxEventUser (*Devs);

    if (!evt
        || evt->load ("stevt.iff",0) != 0)
        parent->panic("TesterState::activate fail for event");

    evt->install();
    
    SimUI::activate();
}
 
void TesterUI::deactivate()
{
    if (evt)
    {
        delete evt;
        evt = 0;
    }
    if (view1)
    {
        delete view1;
        view1 = 0;
    }
    if (view2)
    {
        delete view2;
        view2 = 0;
    }
}

void TesterUI::process_events()
{
    events = evt->process();

    if (events.check (QUIT))
        theSim.exit();

    SimUI::process_events();
}

void TesterUI::render()
{
    SimUI::render();
}


 
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°± Tester Simulator ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// TesterSim - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
TesterSim::TesterSim() :
    SimulatorState()
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// TesterSim - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
TesterSim::~TesterSim()
{
    deactivate();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// TesterSim - activate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void TesterSim::activate()
{
    ui = new TesterUI(this);
    if (!ui)
        return;

    SimulatorState::activate();
}
 

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// TesterSim - deactivate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void TesterSim::deactivate()
{
    SimulatorState::deactivate();

    if (ui)
    {
        delete ui;
        ui = 0;
    }
}

//°±² End of module - stsim.cpp ²±°

