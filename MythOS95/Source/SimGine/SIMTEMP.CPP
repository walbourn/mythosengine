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
// simtemp.cpp
//
// This module contains the temporary object representation class for the
// simulator.
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
// SimTemp - Constructor
//���������������������������������������������������������������������������
SimTemp::SimTemp(SimulatorState *_parent) :
    SimBase(_parent)
{
}


//���������������������������������������������������������������������������
// SimTemp - Destructor
//���������������������������������������������������������������������������
SimTemp::~SimTemp()
{
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimTemp - insert
//���������������������������������������������������������������������������
BOOL SimTemp::insert(ushort t)
{
    assertMyth("SimTemp::insert needs parent",
               parent != 0 && parent->temps != 0);

    if (index != ushort(-1))
        remove();

    team = t;

//��� Find empty slot
    for (int i=0; i < parent->temp_max; i++)
    {
        if (!parent->temps[i])
            break;
    }
    //��� Expand array
    if (i >= parent->temp_max)
    {
        ushort nsize = parent->temp_max + SIM_INIT_OBJECTS;

        SimTemp **tmp = new SimTemp *[nsize];
        if (!tmp)
            return FALSE;

        memset(tmp, 0, sizeof(SimTemp*) * nsize);

        memcpy(tmp, parent->temps, sizeof(SimTemp*) * parent->temp_max);

        delete [] parent->temps;

        parent->temps = tmp;
        parent->temp_max = nsize;
    }

//��� Insert into slot
    parent->temps[i] = this;
    index = i;

    if (i >= parent->temp_hi)
        parent->temp_hi = i + 1;

    return TRUE;
}


//���������������������������������������������������������������������������
// SimTemp - remove
//���������������������������������������������������������������������������
void SimTemp::remove()
{
    if (!parent || !parent->temps)
        return;

    if (index == ushort(-1))
        return;

    if (index < parent->temp_max)
        parent->temps[index] = 0;

    index = ushort(-1);
}



//���������������������������������������������������������������������������
//���������������������������  Utility Routines  ����������������������������
//���������������������������������������������������������������������������

//��� End of module - simtemp.cpp ���
