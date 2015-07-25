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
// simmodel.hpp
//
// SimBase - base class for things in the simulation
//
// SimObject - simple object representation class for the simulation
//
// SimEquip - base representation class for equipment installed in a SimUnit.
//
// SimUnit - base representation class for active elements of the simulation
//
// SimTemp - base representation class for active elements of the simulation
//           that are dynamically created and destroyed
//
// SimOffield - base representation class for elements that are located
//              off-field (beyond the simulator arena).
//
//���������������������������������������������������������������������������

#ifndef __SIMBASE_HPP
#define __SIMBASE_HPP  1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

#define SIM_MAX_EQUIP                   32

#define SIM_MAX_NAME                    16

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//������������������������������� General �����������������������������������
//���������������������������������������������������������������������������

class SimulatorState;

//���������������������������������������������������������������������������
// SimBase - base representation class for things in the simulation.
//
// In addition to providing the basic interface to objects located within
// the environment, the class also provides a unified loading and setup
// interface.
//���������������������������������������������������������������������������
class SimBase
{
public:
    //���������������������������������������������������������������������Ŀ
    // Equates                                                              �
    //�����������������������������������������������������������������������
    enum
    {
        BASE_INACTIVE       = 0x1,
    };

    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    dword           base_flags;         // Base flags
    SimulatorState  *parent;            // Simulator-state which contains instance

    ushort          index;              // Index (within array)
    ushort          team;               // Team (SIM_TEAM_ constant)

    char            name[SIM_MAX_NAME]; // Name of instance

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimBase(SimulatorState *_parent);
    virtual ~SimBase();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������

    //��� Release associated data
    virtual void release();

    //��� Time interface
    virtual void step(float interval);

    //��� Position interface
    virtual void get_position(EschPoint &pos) const;
    virtual void set_position(EschPoint &pos);

    //��� List management
    virtual BOOL insert(ushort t) = 0;
    virtual void remove() = 0;

    //���������������������������������������������������������������������Ŀ
    // Utility functions                                                    �
    //�����������������������������������������������������������������������
    void set_name(const char *_name) { strncpy(name,_name,sizeof(name)); }
};



//���������������������������������������������������������������������������
//������������������������������� Objects �����������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimObject - simple object representation class
//
// This class defines simple objects that are passive within the
// environment (trees, buildings, rocks, etc.).
//���������������������������������������������������������������������������
class SimObject : public SimBase
{
public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimObject(SimulatorState *_parent);
    virtual ~SimObject();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������

    //��� Insert into/remove from objects list
    virtual BOOL insert(ushort t);
    virtual void remove();

    //���������������������������������������������������������������������Ŀ
    // Utility functions                                                    �
    //�����������������������������������������������������������������������
};



//���������������������������������������������������������������������������
//�������������������������������� Units ������������������������������������
//���������������������������������������������������������������������������

class SimUnit;

//���������������������������������������������������������������������������
// SimEquip - base representation class for equipment in SimUnit
//
// This class contains a standard interface for equipment (weapons,
// sensors, engines, etc.) installed into SimUnits that are dynamically
// or programmatically adjustable.
//���������������������������������������������������������������������������
class SimEquip
{
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    SimUnit *parent;                    // SimUnit which contains instance

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimEquip(SimUnit *_parent);
    virtual ~SimEquip();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������

    //��� Release associated data
    virtual void release();

    //��� Time interface
    virtual void step(float interval);

    //���������������������������������������������������������������������Ŀ
    // Utility functions                                                    �
    //�����������������������������������������������������������������������
};


//���������������������������������������������������������������������������
// SimUnit - object representation class
//
// This class defines the interface for active elements within the
// universe that can be controlled by SimUIs.
//���������������������������������������������������������������������������
class SimUnit : public SimBase
{
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    SimEquip    *equip[SIM_MAX_EQUIP];

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimUnit(SimulatorState *_parent);
    virtual ~SimUnit();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������

    //��� Overloads for SimBase
    virtual void release();
    virtual void step(float interval);

    //��� Insert into/remove from units list
    virtual BOOL insert(ushort t);
    virtual void remove();

    //���������������������������������������������������������������������Ŀ
    // Utility functions                                                    �
    //�����������������������������������������������������������������������
};



//���������������������������������������������������������������������������
//�������������������������������� Temps ������������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimTemp - temporary object representation class
//
// This class defines the interface for objects that are dynamically
// create and destroyed during the simulation
//���������������������������������������������������������������������������
class SimTemp : public SimBase
{
public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimTemp(SimulatorState *_parent);
    virtual ~SimTemp();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������

    //��� Insert into/remove from temps list
    virtual BOOL insert(ushort t);
    virtual void remove();

    //���������������������������������������������������������������������Ŀ
    // Utility functions                                                    �
    //�����������������������������������������������������������������������
};



//���������������������������������������������������������������������������
//������������������������������� Off-field ���������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimOffield - off-field object representation class
//
// This class defines objects which exist outside the confines of the
// simulation arena, but can affect them through the creation of
// temporary objects.
//���������������������������������������������������������������������������
class SimOffield : public SimBase
{
public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimOffield(SimulatorState *_parent);
    virtual ~SimOffield();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������

    //��� Insert into/remove from offields list
    virtual BOOL insert(ushort t);
    virtual void remove();

    //���������������������������������������������������������������������Ŀ
    // Utility functions                                                    �
    //�����������������������������������������������������������������������
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - simmodel.hpp ���