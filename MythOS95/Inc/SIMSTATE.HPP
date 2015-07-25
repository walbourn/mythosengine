//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
//
//                     A Simluator Framework for MythOS(tm)
//
//                      Microsoft Windows 95/NT Version
//
//            Copyright (c) 1997-1998 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
//
// MythOS is a trademark of Charybdis Enterprises, Inc.
//
//���������������������������������������������������������������������������
//
// simstate.hpp
//
// SimState - state-management base interface class
//
// SimView - view class for SimUI
//
// SimUI - user-interface class for SimulatorState
//
// SimulatorState - simulator specific state-management class
//
//���������������������������������������������������������������������������

#ifndef __SIMSTATE_HPP
#define __SIMSTATE_HPP  1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//������������������������������� General �����������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimState - state management class
//
// This class handles the flow of control between modules of the program,
// with each module defined by its SimState-derived class.
//���������������������������������������������������������������������������
class SimState
{
public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimState();
    virtual ~SimState();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual BOOL pump_windows ();
    virtual void display();

    virtual void activate ();
    virtual void deactivate ();

    virtual void process_events() = 0;
    virtual void render() = 0;

    virtual void panic (ulong id, const char *str=0);
    virtual void panic (const char *msg);

    //���������������������������������������������������������������������Ŀ
    // Networking functions                                                 �
    //�����������������������������������������������������������������������
    virtual void process_msg  (void *p, ulong psize, ulong pid, ulong stamp);
    virtual void process_sys  (void *p, ulong psize, ulong pid, ulong stamp);
    virtual void process_chat (void *p, ulong psize, ulong pid, ulong stamp);

    //���������������������������������������������������������������������Ŀ
    // Utility functions                                                    �
    //�����������������������������������������������������������������������
    void switch_to (SimState *next);

    static char *load_string(ulong id);
    static char *load_string(ulong id, char *buff, ulong len);

    static int message_box(const char *str, UINT type);
    static int message_box(ulong id, UINT type);
};


//���������������������������������������������������������������������������
//������������������������������ Simulator ����������������������������������
//���������������������������������������������������������������������������

class SimUI;
class SimUnit;
class SimulatorState;

class SimObject;
class SimUnit;
class SimTemp;
class SimOffield;

//���������������������������������������������������������������������������
// SimView - view base class
//
// A view is a single screen or interface element that the user interacts
// with, where only a single view can be active at a given time.  Views
// are contained with UIs, which are contained within the Simulator state.
//���������������������������������������������������������������������������
class SimView
{
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    SimUI       *parent;                // SimUI which contains the view

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimView(SimUI *_parent);
    virtual ~SimView();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void activate ();
    virtual void deactivate ();

    virtual void process_events() = 0;
    virtual void render() = 0;

    //���������������������������������������������������������������������Ŀ
    // Utility functions                                                    �
    //�����������������������������������������������������������������������
    void switch_to (SimView *next);
};


//���������������������������������������������������������������������������
// SimUI - user-interface base class
//
// A UI contains one or more view class instances and manages the shared
// user-interface elements.  UIs are contained within the Simulator state.
// Associated with a SimUI is the current SimView and the SimUnit which
// the user is interacting with in the simulation.
//���������������������������������������������������������������������������
class SimUI
{
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    SimulatorState  *parent;            // SimulatorState which contains UI
    SimView         *view;              // Current SimView
    SimUnit         *unit;              // Current SimUnit

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimUI(SimulatorState *_parent);
    virtual ~SimUI();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void activate ();
    virtual void deactivate ();

    virtual void process_events();
    virtual void render();

    //���������������������������������������������������������������������Ŀ
    // Utility functions                                                    �
    //�����������������������������������������������������������������������
    void switch_to (SimUI *next);
};


//���������������������������������������������������������������������������
// SimulatorState - simulator-specific state management class
//
// This state represents the simulation portion of the application, where
// all other states form the game flow into, out, and around the simulation
// (or simulations) itself, where the simulation is defined by its
// SimulatorState-derived class.
//���������������������������������������������������������������������������
class SimulatorState : public SimState
{
public:
    //���������������������������������������������������������������������Ŀ
    // Equates                                                              �
    //�����������������������������������������������������������������������
    enum
    {
        MODEL_FROZEN    = 0x1,
    };

    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    dword       flags;                  // Control flags

    SimUI       *ui;                    // Current SimUI

    float       timebase;               // Model time variables
    ulong       timeshift;
    ulong       time_now;
    Chronometer clock;

    ushort      obj_hi;                 // SimObject array
    ushort      obj_max;
    SimObject   **objects;

    ushort      temp_hi;                // SimTemp array
    ushort      temp_max;
    SimTemp     **temps;

    struct sim_team_t
    {
        ushort      unit_hi;            // SimUnit array
        ushort      unit_max;
        SimUnit     **units;

        ushort      ofld_hi;            // SimOffield array
        ushort      ofld_max;
        SimOffield  **offields;
    };

    sim_team_t  teams[SIM_MAX_TEAMS];

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimulatorState();
    virtual ~SimulatorState();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void activate ();
    virtual void deactivate ();

    virtual void process_events();
    virtual void render();

    //���������������������������������������������������������������������Ŀ
    // Utility functions                                                    �
    //�����������������������������������������������������������������������
};

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

extern SimState         *Mode;              // Current state

//���������������������������������������������������������������������������
//
//                          Inline Functions
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimView - switch_to
//���������������������������������������������������������������������������
inline void SimView::switch_to (SimView *next)
{
    assertMyth("SimView::switch_to needs parent and valid next",
               parent != 0 && next != 0);
    deactivate();
    parent->view = next;
    next->activate();
}


//���������������������������������������������������������������������������
// SimUI - switch_to
//���������������������������������������������������������������������������
inline void SimUI::switch_to (SimUI *next)
{
    assertMyth("SimUI::switch_to needs parent and valid next",
               parent != 0 && next != 0);
    deactivate();
    parent->ui = next;
    next->activate();
}


//���������������������������������������������������������������������������
// SimState - switch_to
//���������������������������������������������������������������������������
inline void SimState::switch_to (SimState *next)
{
    assertMyth("SimState::switch_to needs valid next state", next != 0);
    deactivate();
    Mode = next;
    next->activate();
}

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - simstate.hpp ���