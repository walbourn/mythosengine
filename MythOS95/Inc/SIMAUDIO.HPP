//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм
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
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
//                     A Simluator Framework for MythOS(tm)
//
//                      Microsoft Windows 95/NT Version
//
//            Copyright (c) 1997-1998 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
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
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
// MythOS is a trademark of Charybdis Enterprises, Inc.
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
// simaudio.hpp
//
// SimAudio - Audio management class
//
//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм

#ifndef __SIMAUDIO_HPP
#define __SIMAUDIO_HPP   1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                Classes
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// SimAudio - audio management class
//
// This class manages the sound source, sample caching, and sample timing
// needed by the application.
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
class SimAudio: public BachDigital
{
public:
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Equates                                                              Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    enum error_codes
    {
        ERROR_NONE      = 0,
        ERROR_INIT      = 1,
    };

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Public data members                                                  Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Constructor/Destructors                                              Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    SimAudio();
    virtual ~SimAudio();

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Operations                                                           Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    virtual error_codes init ();
};


//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                 Data
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

extern SimAudio         *Audio;             // Audio control instance

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//╟╠╡ End of header - simaudio.hpp ╡╠╟
