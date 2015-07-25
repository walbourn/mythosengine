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
// sbrgam.hpp
//
// Microsoft ActiveMovie(TM) Spielberg class implementations
//
// SpielbergAMPlayer - ActiveMovie(TM) player class
//
// SpielbergAMStreamPlayer - ActiveMovie(TM) Streaming Interface player class
//
//���������������������������������������������������������������������������

#ifndef __SBRGAM_HPP
#define __SBRGAM_HPP    1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//             
//                                Includes
//                                
//���������������������������������������������������������������������������

//��� DirectX headers
#include <ddraw.h>

//��� ActiveMovie headers
#include <vfwmsgs.h>
#include <objbase.h>
#include <strmif.h>
#include <control.h>
#include <evcode.h>
#include <uuids.h>
#include <amvideo.h>
#include <mmstream.h>
#include <amstream.h>
#include <ddstream.h>

//��� Spielberg headers
#include "sbrgdefs.h"
#include "sbrgbase.hpp"

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SpielbergAMPlayer - ActiveMovie(TM) player implementation
//���������������������������������������������������������������������������
class SpielbergAMPlayer : public SpielbergPlayer
{
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    HWND            parent;
    IGraphBuilder   *am_graph;
    HANDLE          am_event;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SpielbergAMPlayer(HWND _parent);
    virtual ~SpielbergAMPlayer();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual sberg_err_codes open(const char *name, dword ctrlfl=0);
    virtual sberg_err_codes close();
    virtual sberg_err_codes play();
    virtual sberg_err_codes stop();
    virtual sberg_err_codes pause();
    virtual sberg_err_codes resume();
    virtual sberg_err_codes set_position(ulong ms);
    virtual ulong get_position() const;
    virtual sberg_err_codes get_info(SpielbergInfo *info) const;
    virtual dword get_flags();
    virtual void display();

    //���������������������������������������������������������������������Ŀ
    // Utility functions.                                                   �
    //�����������������������������������������������������������������������

    //��� Control render window
    sberg_err_codes get_window_styles(long *style, long *styleex);
    sberg_err_codes set_window_styles(long style, long styleex);

    sberg_err_codes get_window_pos(long *x, long *y);
    sberg_err_codes set_window_pos(long x, long y);

    //��� Setup playback rectangles
    sberg_err_codes set_source_rect(long x, long y, long w, long h);
    sberg_err_codes set_dest_rect(long x, long y, long w, long h);
};


//���������������������������������������������������������������������������
// SpielbergAMStreamPLayer - ActiveMovie(TM) stream player implementation
//���������������������������������������������������������������������������
class SpielbergAMStreamPlayer : public SpielbergPlayer
{
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    LPDIRECTDRAW            ddraw;          // DirectDraw instance
    LPDIRECTDRAWSURFACE     dsurf;          // DirectDraw target surface
    IAMMultiMediaStream     *am_stream;     // Stream instance
    IMediaStream            *am_vidstream;
    IDirectDrawMediaStream  *am_ddstream;
    IDirectDrawStreamSample *am_ddsample;
    LPDIRECTDRAWSURFACE     am_ddsurf;      // AM update surface
    RECT                    am_srect;       // Source rectangle
    RECT                    am_drect;       // Destination rectangle
    ushort                  am_swidth;      // Source size
    ushort                  am_sheight;
    HANDLE                  am_event;       // EOS handle

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    SpielbergAMStreamPlayer(LPDIRECTDRAW _ddraw, LPDIRECTDRAWSURFACE dsurf);
    virtual ~SpielbergAMStreamPlayer();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual sberg_err_codes open(const char *name, dword ctrlfl=0);
    virtual sberg_err_codes close();
    virtual sberg_err_codes play();
    virtual sberg_err_codes stop();
    virtual sberg_err_codes pause();
    virtual sberg_err_codes resume();
    virtual sberg_err_codes set_position(ulong ms);
    virtual ulong get_position() const;
    virtual sberg_err_codes get_info(SpielbergInfo *info) const;
    virtual dword get_flags();
    virtual void display();

    //���������������������������������������������������������������������Ŀ
    // Utility functions.                                                   �
    //�����������������������������������������������������������������������

    //��� Setup playback rectangles
    sberg_err_codes set_source_rect(long x, long y, long w, long h);
    sberg_err_codes set_dest_rect(long x, long y, long w, long h);
};

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - sbrgam.hpp ���
