//���������������������������������������������������������������������������
//                                                      _o######ooooooo-_
//     Spielberg -- Animation player library          o#####o_o#####~~~~~~
//                                                   ################o__o
//       Microsoft Windows 95/NT Version           _o###########~~~~~###~
//                                               o##############
//                                            _o###############~
//                                          _o#########~ooo~##~
//                                     _o############# ##o::___
//                                   _o#################oo:~~~~~
//                                 _o#####################~
//                               _####~_oooooooo:~~######~
//                             _##### o###########_:~##~
//                            o#####_##################
//                           _#######_~#################_
//                           ##########o:~###############o
//                         _##############o~##############_
//                       o#############~~     ~~~~~~~######_
//                   __o##########~::o_             o#######
//              _oo##########~~::o#####            o###########o___
//          o##########~~~~    ~~~##########       ~~~~#############o
//         #####~~~~~~                ~~~
//
//           Copyright (c) 1996-1998 by Charybdis Enterprises, Inc.
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
// Created by Tim Little & Chuck Walbourn
//
// sbrgbase.hpp
//
// Base interface class definitions for Spielberg
//
//���������������������������������������������������������������������������

#ifndef __SBRGBASE_HPP
#define __SBRGBASE_HPP  1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//             
//                                Includes
//                                
//���������������������������������������������������������������������������

//��� Spielberg headers
#include "sbrgdefs.h"

//���������������������������������������������������������������������������
//
//                               Structures
//
//���������������������������������������������������������������������������

struct SpielbergInfo
{
    ushort  width;                      // Width and height of image
    ushort  height;
    ulong   duration;                   // Duration (ms);
};

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SpielbergPlayer - Base player interface class
//���������������������������������������������������������������������������
class SpielbergPlayer
{
public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    dword   flags;

    SpielbergPlayer();
    virtual ~SpielbergPlayer();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������

    //��� Open file for playback
    virtual sberg_err_codes open(const char *name, dword ctrlfl=0)=0;

    //��� Close file
    virtual sberg_err_codes close()=0;

    //��� Play, stop, pause, and resume playback
    virtual sberg_err_codes play()=0;
    virtual sberg_err_codes stop()=0;
    virtual sberg_err_codes pause()=0;
    virtual sberg_err_codes resume()=0;

    //��� Set/get playback position (in ms from start)
    virtual sberg_err_codes set_position(ulong ms)=0;
    virtual ulong get_position() const=0;

    //��� Get information about file
    virtual sberg_err_codes get_info(SpielbergInfo *info) const=0;

    //��� Get status flags
    virtual dword get_flags();

    //��� Display
    virtual void display()=0;
};

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - sbrgbase.hpp ���
