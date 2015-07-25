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
// simstate.cpp
//
// This module contains the state management class.
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
// SimState - Constructor
//���������������������������������������������������������������������������
SimState::SimState()
{
}


//���������������������������������������������������������������������������
// SimState - Destructor
//���������������������������������������������������������������������������
SimState::~SimState()
{
    deactivate();
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimState - pump_windows
//���������������������������������������������������������������������������
BOOL SimState::pump_windows ()
{
    assertMyth("SimState::pump_windows needs valid devices", Devs != 0);

    Devs->wm_clear();

    MSG msg;
    while (PeekMessage (&msg, NULL, 0, 0, PM_NOREMOVE))
    {
        if (GetMessage (&msg, 0, 0, 0) == 0)
            return FALSE;

        TranslateMessage (&msg);
        DispatchMessage (&msg);
    }

    return TRUE;
}


//���������������������������������������������������������������������������
// SimState - display
//���������������������������������������������������������������������������
void SimState::display()
{
    assertMyth ("SimState::display needs valid Screen instance", Screen != 0);

    Screen->flip();
}


//���������������������������������������������������������������������������
// SimState - activate
//���������������������������������������������������������������������������
void SimState::activate ()
{
}


//���������������������������������������������������������������������������
// SimState - deactivate
//���������������������������������������������������������������������������
void SimState::deactivate ()
{
}


//���������������������������������������������������������������������������
// SimState - panic
//���������������������������������������������������������������������������
void SimState::panic (ulong id, const char *str)
{
    char    buff[1024];

    if (Screen)
    {
        Screen->unlock();
    }

    assertMyth("SimState::panic needs valid SimGine instance",
               SimApp != 0 && SimApp->hInstance != 0);

    load_string(id, buff, sizeof(buff) - 128);

//��� Add any additional comments.
    assertMyth("SimState::panic comment string too long.",
               !str || (strlen(str) < 128));

    if (str)
    {
        strcat(buff,"\n\n");
        strcat(buff,str);
    }

    message_box (buff, MB_OK | MB_ICONEXCLAMATION);

    SimApp->exit();
}

void SimState::panic (const char *msg)
{
    if (Screen)
    {
        Screen->unlock();
    }

    message_box (msg, MB_OK | MB_ICONEXCLAMATION);

    SimApp->exit();
}


//���������������������������������������������������������������������������
//���������������������������  Network Routines  ����������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimState - process_msg
//���������������������������������������������������������������������������
void SimState::process_msg (void *p, ulong psize, ulong pid, ulong stamp)
{
}


//���������������������������������������������������������������������������
// SimState - process_sys
//���������������������������������������������������������������������������
void SimState::process_sys (void *p, ulong psize, ulong pid, ulong stamp)
{
}


//���������������������������������������������������������������������������
// SimState - process_chat
//���������������������������������������������������������������������������
void SimState::process_chat (void *p, ulong psize, ulong pid, ulong stamp)
{
}


//���������������������������������������������������������������������������
//���������������������������  Utility Routines  ����������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimState - load_string
//���������������������������������������������������������������������������
char *SimState::load_string(ulong id)
{
    assertMyth("SimState::load_string needs valid SimGine instance",
               SimApp != 0 && SimApp->hInstance != 0);

    HRSRC rh = FindResource(SimApp->hInstance,
                            MAKEINTRESOURCE((id>>4)+1),
                            RT_STRING);
    if (rh == NULL)
        return 0;

    ulong len = SizeofResource(SimApp->hInstance, rh)+1;
    if (len <= 1)
        return 0;

    len = (len + 3) & ~0x3;
    char *buff = new char[len];
    if (!buff)
        return 0;

    if (LoadString(SimApp->hInstance, id, buff, len))
        return buff;

    return 0;
}

char *SimState::load_string(ulong id, char *buff, ulong len)
{
    assertMyth("SimState::load_string needs valid SimGine instance",
               SimApp != 0 && SimApp->hInstance != 0);

    if (LoadString(SimApp->hInstance, id, buff, len))
        return buff;

    return 0;
}


//���������������������������������������������������������������������������
// SimState - message_box
//���������������������������������������������������������������������������
int SimState::message_box(const char *str, UINT type)
{
    assertMyth("SimState::message_box needs valid SimGine", SimApp != 0);

    return ::MessageBox(SimApp->hWndClient,
                        str,
                        SimApp->appName,
                        type);
}

int SimState::message_box(ulong id, UINT type)
{
    char    buff[1024];

    load_string(id, buff, sizeof(buff));

    return message_box(buff, type);
}

//��� End of module - simstate.cpp ���