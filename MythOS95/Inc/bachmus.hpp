//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм
//
//                        ээээээээээ                       ээээ
//     здд©                шшш     шшэ                     чшшш
//     Ё  Ё       здд©     шшш     шшш   ээээ      эээээ    шшш эээ
//     Ё  Ё здд©  Ё  Ё     шшшээээшшшъ  ъ  чшщ    шшъ   ъш  шшшшшъшш
//     Ё  Ё Ё  Ё  Ё  Ё     шшш     шшэ  эшшшшшщ  шшш        шшш   шшш
//    Oы Oы Ё  Ё  Ё  Ё     шшш     шшш чшщ  шшш  шшш    эш  шшш   шшш
//          Ё  Ё Oы Oы    эшшшэээшшшъ   шшшшщъшэ  ъшшээшш  эшшшэ эшшшэ
//         Oы Oы
//                            C++ Music, Sound, and Effects Library
//                               Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
//                        http://www.mythos-engine.org/
//
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
//
// Created by Dan Higdon & Chuck Walbourn
//
// bachmus.hpp
//
// BachSequence - Music container class
//
// BachMusic - Music sound source class
//
//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм

#ifndef __BACHMUS_HPP
#define __BACHMUS_HPP    1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                Includes
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

#include <dmusicc.h>
#include <dmusici.h>

//ддд Charybdis headers
#include <debug.h>
#include <portable.h>
#include <ivory.hpp>
#include <xfile.hpp>

//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// Bach Library Includes                                                    Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
#include "bachdefs.h"

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                Classes
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

class BachMusic;
class BachDigital;

//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachSequence - Music container class.                                    Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
class BachSequence
{
public:
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Public data members.                                                 Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    IDirectMusicPerformance *perf;          // DirectMusic performance object
    IDirectMusicLoader      *loader;        // DirectMusic loader object
    IDirectMusicSegment     *segment;       // DirectMusic segement object

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Constructor/Destructor                                               Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    BachSequence(BachMusic *mus);
    virtual ~BachSequence();

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Operations                                                           Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    virtual void release();

    virtual bach_err_codes play (long start=0);
    virtual bach_err_codes queue (long start=0);
    virtual bach_err_codes stop ();
    virtual dword status() const;

    bach_err_codes set_repeats(ulong count=0);
    bach_err_codes set_loop_points(long start, long end);

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Utility functions.                                                   Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    long get_length() const;

    bach_err_codes load_mid(const char *fname);
};


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachMusic - Music sound source class.                                    Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
class BachMusic
{
public:
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Public data members.                                                 Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    IDirectMusic            *dmusic;        // DirectMusic object
    IDirectMusicPort        *port;          // DirectMusic port object
    IDirectMusicPerformance *perf;          // DirectMusic performance object
    IDirectMusicLoader      *loader;        // DirectMusic loader object

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Constructor/Destructor                                               Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    BachMusic();
    virtual ~BachMusic();

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Operations                                                           Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    virtual bach_err_codes init (BachDigital *digi, HWND hwnd,
                                 DWORD effects=DMUS_EFFECT_NONE);
    virtual void close ();

    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
    // Utility functions.                                                   Ё
    //дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
    bach_err_codes activate();
    bach_err_codes deactivate();
};

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//╟╠╡ End of header - bachmus.hpp ╡╠╟

