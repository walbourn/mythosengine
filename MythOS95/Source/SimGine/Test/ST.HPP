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
//                               *** Tester ***
//
// st.hpp
//
//���������������������������������������������������������������������������

#ifndef __ST_HPP
#define __ST_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//             
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <simgine.hpp>

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// TesterState
//���������������������������������������������������������������������������
class TesterState : public SimState
{
    MaxEventUser    *evt;

public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    TesterState();
    virtual ~TesterState();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void activate ();
    virtual void deactivate ();

    virtual void process_events();
    virtual void render();
};

class TesterUI;
class TesterSim;

//���������������������������������������������������������������������������
// TesterView1
//���������������������������������������������������������������������������
class TesterView1 : public SimView
{
public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    TesterView1(TesterUI *_parent);
    virtual ~TesterView1();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void activate ();
    virtual void deactivate ();

    virtual void process_events();
    virtual void render();
};


//���������������������������������������������������������������������������
// TesterView2
//���������������������������������������������������������������������������
class TesterView2 : public SimView
{
public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    TesterView2(TesterUI *_parent);
    virtual ~TesterView2();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void activate ();
    virtual void deactivate ();

    virtual void process_events();
    virtual void render();
};


//���������������������������������������������������������������������������
// TesterUI
//���������������������������������������������������������������������������
class TesterUI : public SimUI
{
    MaxEventUser    *evt;

public:
    MaxEventList    events;

    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    TesterView1 *view1;
    TesterView2 *view2;
    
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    TesterUI(TesterSim *_parent);
    virtual ~TesterUI();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void activate ();
    virtual void deactivate ();

    virtual void process_events();
    virtual void render();
};


//���������������������������������������������������������������������������
// TesterSim
//���������������������������������������������������������������������������
class TesterSim : public SimulatorState
{
public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    TesterSim();
    virtual ~TesterSim();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void activate ();
    virtual void deactivate ();
};


//���������������������������������������������������������������������������
// TesterApp
//���������������������������������������������������������������������������
class TesterApp : public SimGine
{
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    TesterState *start;
    TesterSim   *sim;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    TesterApp();
    virtual ~TesterApp();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual BOOL init_instance();
    virtual int exit_instance();
};

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

extern TesterApp        theSim;

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - st.hpp ���
