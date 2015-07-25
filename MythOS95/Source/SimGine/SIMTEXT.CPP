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
// simtext.cpp
//
// This module contains the gutenberg text output class.
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
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimText - outr
//���������������������������������������������������������������������������
void SimText::outr(ulong id)
{
    char    buff[1024];

    assertMyth("SimText::outr needs SimApp w/ instance",
               SimApp != 0 && SimApp->hInstance);

    LoadString(SimApp->hInstance, id, buff, sizeof(buff));

    GBergText::out(buff);
}

void SimText::outr(long x, long y, ulong id)
{
    char    buff[1024];

    assertMyth("SimText::outr needs SimApp w/ instance",
               SimApp != 0 && SimApp->hInstance);

    LoadString(SimApp->hInstance, id, buff, sizeof(buff));

    GBergText::out(x, y, buff);
}


//���������������������������������������������������������������������������
// SimText - outrf
//���������������������������������������������������������������������������
void SimText::outrf(ulong id, ...)
{
    char fmt[512];
    char buff[1024];

    assertMyth("SimText::outr needs SimApp w/ instance",
               SimApp != 0 && SimApp->hInstance);

    if (LoadString(SimApp->hInstance, id, fmt, sizeof(fmt)))
    {
        // Perform a printf
        va_list parms;
        va_start (parms, id);
        int len = wvsprintf (buff, fmt, parms);
        va_end (parms);

        assert (len <= sizeof (buff));

        GBergText::out (buff);
    }
}

//��� End of module - simtext.cpp ���
