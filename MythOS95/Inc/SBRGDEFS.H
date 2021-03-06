//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//                                                      _o######ooooooo-_
//     Spielberg -- Animation player library          o#####o_o#####~~~~~~
//                                                   ################o__o
//      Microsoft Windows 95/98/NT Version        _o###########~~~~~###~
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
//  Copyright (c) 1996-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// Created by Tim Little & Chuck Walbourn
//
// sbrgdefs.h
//
// Defines and constants for Spielberg.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __SBRGDEFS_H
#define __SBRGDEFS_H    1

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Error values                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
typedef enum _sberg_err_codes
{
    //陳� General error codes
    SBERG_ERR_NONE                  =0,     // No error
    SBERG_ERR_INVALIDPARMS          =1,     // Invalid parameters
    SBERG_ERR_NOMEMORY              =2,     // Not enough memory
    SBERG_ERR_NOTSUPPORTED          =3,     // Operation not supported
    SBERG_ERR_UNINITIALIZED         =4,     // Uninitalized instance

    //陳� General player error codes
    SBERG_ERR_ALREADYOPEN           =10,    // Already open, close first
    SBERG_ERR_FILENOTFOUND          =11,    // File not found
    SBERG_ERR_OPENFAILED            =12,    // File open failed.
    SBERG_ERR_NOTPLAYING            =13,    // Not playing
    SBERG_ERR_MISSINGDATA           =14,    // Missing needed data
    SBERG_ERR_VIDEOFAILED           =15,    // Failed video renderer
    SBERG_ERR_AUDIOFAILED           =16,    // Failed audio renderer

    //陳� ActiveMovie(TM) error codes
    SBERG_ERR_AMCONNECTFAILED       =20,    // Failed to connect to AM
    SBERG_ERR_AMQUERYIFAILED        =21,    // Failed to get interface to AM
    SBERG_ERR_AMEVENTFAILED         =22,    // Failed to get AM event handle
    SBERG_ERR_AMFSFAILED            =23,    // Failed to set full screen mode
    SBERG_ERR_AMFAILED              =24,    // Failed AM operation

} sberg_err_codes;


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Player flags                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

//陳� Control flags
#define SBERG_CTRL_FULLSCREEN       0x1     // Playback in full-screen mode

//陳� State flags

#define SBERG_PLAYER_PLAYING        0x1     // Player is playing
#define SBERG_PLAYER_PAUSED         0x2     // Player is paused

#define SBERG_PLAYER_APP0           0x1000000   // Application bits
#define SBERG_PLAYER_APP1           0x2000000
#define SBERG_PLAYER_APP2           0x4000000
#define SBERG_PLAYER_APP3           0x8000000
#define SBERG_PLAYER_APP4           0x10000000
#define SBERG_PLAYER_APP5           0x20000000
#define SBERG_PLAYER_APP6           0x40000000
#define SBERG_PLAYER_APP7           0x80000000

#endif

//葦� End of header - sbrgdefs.h 憶�

