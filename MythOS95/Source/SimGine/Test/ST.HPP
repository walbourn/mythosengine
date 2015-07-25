//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм
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
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
//                     A Simluator Framework for MythOS(tm)
//
//                        Microsoft Windows '95 Version
//
//               Copyright (c) 1997 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
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
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
// MythOS is a trademark of Charybdis Enterprises, Inc.
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
//                               *** Tester ***
//
// st.hpp
//
//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм

#ifndef __ST_HPP
#define __ST_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//             
//                                Includes
//                                
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

#include <simgine.hpp>

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                Equates
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                Classes
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TesterState
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
class TesterState : public SimState
{
    MaxEventUser    *evt;

public:
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Constructor/Destructors                                              Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    TesterState();
    virtual ~TesterState();

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Operations                                                           Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    virtual void activate ();
    virtual void deactivate ();

    virtual void process_events();
    virtual void render();
};

class TesterUI;
class TesterSim;

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TesterView1
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
class TesterView1 : public SimView
{
public:
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Constructor/Destructors                                              Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    TesterView1(TesterUI *_parent);
    virtual ~TesterView1();

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Operations                                                           Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    virtual void activate ();
    virtual void deactivate ();

    virtual void process_events();
    virtual void render();
};


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TesterView2
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
class TesterView2 : public SimView
{
public:
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Constructor/Destructors                                              Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    TesterView2(TesterUI *_parent);
    virtual ~TesterView2();

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Operations                                                           Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    virtual void activate ();
    virtual void deactivate ();

    virtual void process_events();
    virtual void render();
};


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TesterUI
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
class TesterUI : public SimUI
{
    MaxEventUser    *evt;

public:
    MaxEventList    events;

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Public data members                                                  Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    TesterView1 *view1;
    TesterView2 *view2;
    
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Constructor/Destructors                                              Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    TesterUI(TesterSim *_parent);
    virtual ~TesterUI();

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Operations                                                           Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    virtual void activate ();
    virtual void deactivate ();

    virtual void process_events();
    virtual void render();
};


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TesterSim
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
class TesterSim : public SimulatorState
{
public:
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Constructor/Destructors                                              Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    TesterSim();
    virtual ~TesterSim();

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Operations                                                           Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    virtual void activate ();
    virtual void deactivate ();
};


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// TesterApp
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
class TesterApp : public SimGine
{
public:
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Public data members                                                  Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    TesterState *start;
    TesterSim   *sim;

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Constructor/Destructors                                              Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    TesterApp();
    virtual ~TesterApp();

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Operations                                                           Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    virtual BOOL init_instance();
    virtual int exit_instance();
};

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                 Data
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

extern TesterApp        theSim;

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//╟╠╡ End of header - st.hpp ╡╠╟

