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
// simgine.hpp
//
// Primary include header for the SimGine framework.
//
//���������������������������������������������������������������������������

#ifndef __SIMGINE_HPP
#define __SIMGINE_HPP    1

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

//��� Windows header switches
#define VC_EXTRALEAN

//��� Standard headers
#include <windows.h>
#include <stdlib.h>
#include <ddraw.h>
#include <dplay.h>

//��� Charybdis headers
#include <assert.h>
#include <portable.h>
#include <debug.h>
#include <mythos.hpp>

#include <turner.hpp>
#include <newton.hpp>
#include <bach.hpp>

//��� SimGine headers
#include "simdefs.h"
#include "simscrn.hpp"
#include "simaudio.hpp"
#include "simstate.hpp"
#include "simmodel.hpp"
#include "simmisc.hpp"
#include "simttabl.hpp"

//���������������������������������������������������������������������������
//
//                               Structures
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

#define SIM_MAX_APPNAME                 16

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimGine - main application class
//
// This class handles the startup and termination of the application as
// a whole.
//���������������������������������������������������������������������������
class SimGine
{
public:
    //���������������������������������������������������������������������Ŀ
    // Equates                                                              �
    //�����������������������������������������������������������������������
    enum
    {
        STARTUP_DDRAW               = 0x1,
        STARTUP_D3D                 = 0x2,
        STARTUP_CLEAR3D             = 0x4,
        STARTUP_FULLSCREEN          = 0x1000,
        STARTUP_TRUEFLIP            = 0x2000,
        STARTUP_AUDIO               = 0x4000,
        STARTUP_DX5                 = 0x8000,
    };

    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    HINSTANCE   hInstance;                  // Current instance
    HWND        hWndClient;                 // Client window
    char        appName[SIM_MAX_APPNAME];   // Application name
    LPSTR       cmdLine;                    // Command line
    int         cmdShow;                    // Command show bits
    dword       startup;                    // Control startup flags
    ushort      startup_width;              // Starting window size
    ushort      startup_height;
    ushort      startup_bitdepth;           // Starting bit-depth
    ushort      na;
    dword       startup_memsize;            // Ivory static memory size
    dword       startup_arenasize;          // Escher arena memory space
    dword       startup_sortsize;           // Escher sort memory space

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SimGine();
    virtual ~SimGine();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual BOOL init_instance();
    virtual int run();
    virtual int exit_instance();
    virtual void step();

    //���������������������������������������������������������������������Ŀ
    // Utility functions                                                    �
    //�����������������������������������������������������������������������
    void exit();
};

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

extern SimGine          *SimApp;            // Application instance
extern MythosSystem     *MythOS;            // MythOS instance
extern MaxDevices       *Devs;              // Max Devices instance

#ifdef LOG
extern SimLogFile       *Log;               // Logging support
#endif

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - simgine.hpp ���