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
// simui.cpp
//
// This module contains the SimulatorState user-interface base class.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "simgine.hpp"

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimUI - Constructor
//���������������������������������������������������������������������������
SimUI::SimUI(SimulatorState *_parent) :
     parent(_parent),
     view (0),
     unit (0)
{
    assertMyth("SimUI needs valid parent", _parent != 0);
}


//���������������������������������������������������������������������������
// SimUI - Destructor
//���������������������������������������������������������������������������
SimUI::~SimUI()
{
    deactivate();
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimUI - activate
//���������������������������������������������������������������������������
void SimUI::activate ()
{
    assertMyth("SimUI::activate needs valid starting view", view != 0);

    view->activate();
}


//���������������������������������������������������������������������������
// SimUI - deactivate
//���������������������������������������������������������������������������
void SimUI::deactivate ()
{
    if (view)
        view->deactivate();
}


//���������������������������������������������������������������������������
// SimUI - process_events
//���������������������������������������������������������������������������
void SimUI::process_events ()
{
    assertMyth("SimUI::process_events needs valid view", view != 0);

    view->process_events();
}


//���������������������������������������������������������������������������
// SimUI - render
//���������������������������������������������������������������������������
void SimUI::render ()
{
    assertMyth("SimUI::render needs valid view", view != 0);

    view->render();
}



//���������������������������������������������������������������������������
//���������������������������  Utility Routines  ����������������������������
//���������������������������������������������������������������������������

//��� End of module - simui.cpp ���
