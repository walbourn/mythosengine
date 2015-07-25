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
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
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
// bachcd.cpp
//
// CD audio control implementation
//
//ммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммммм

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//
//                                Includes
//
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

#include <stdlib.h>
#include <string.h>

#include "bach.hpp"

//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠
//
//                                 Code
//
//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠

//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╠  Constructors/Destructors  ╠╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - Constructor
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
BachCD::BachCD () :
    devid(0),
    flags(BACH_CD_STOPONCLOSE)
{
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - Destructor
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
BachCD::~BachCD()
{
    close();
}



//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╠  Operations  ╠╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟
//╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟╟

//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - init
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
bach_err_codes BachCD::init(ulong id)
{
    if (devid)
        return BACH_ERR_ALREADYOPEN;

//ддд Try to open device
    MCI_OPEN_PARMS  oparams;
    memset(&oparams, 0, sizeof(oparams));
    oparams.lpstrDeviceType = (const char*)(MCI_DEVTYPE_CD_AUDIO | (id << 16));

    switch (mciSendCommand(NULL, MCI_OPEN,
                           MCI_OPEN_TYPE
                           | MCI_OPEN_TYPE_ID
                           | MCI_OPEN_SHAREABLE,
                           (DWORD) &oparams))
    {
        case 0:
            break;

        case MCIERR_OUT_OF_MEMORY:
            return BACH_ERR_OUTOFMEMORY;
        case MCIERR_DEVICE_OPEN:
            return BACH_ERR_MCIDEVOPEN;
        default:
            return BACH_ERR_MCIFAILED;
    }

    devid = oparams.wDeviceID;
    assertMyth("BachCD::init() expected valid device ID", devid != 0);

//ддд Set the time format to milliseconds
    MCI_SET_PARMS   sparams;
    memset(&sparams, 0, sizeof(sparams));

    sparams.dwTimeFormat = MCI_FORMAT_MILLISECONDS;

    bach_err_codes err = BACH_ERR_NONE;

    switch (mciSendCommand(devid, MCI_SET,
                           MCI_WAIT | MCI_SET_TIME_FORMAT,
                           (DWORD) &sparams))
    {
        case 0:
            break;

        default:
            return BACH_ERR_MCIFAILED;
    }

    if (err)
        close();

    return err;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - close
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
void BachCD::close()
{
    if (devid)
    {
        if (flags & BACH_CD_STOPONCLOSE)
            stop();

        mciSendCommand(devid, MCI_CLOSE, 0, NULL);
        devid=0;
    }
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - play
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
bach_err_codes BachCD::play (ulong sms, ulong ems)
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

    if (ems && (ems < sms))
        return BACH_ERR_INVALIDPARAMS;

    MCI_PLAY_PARMS pparams;
    memset(&pparams, 0, sizeof(pparams));

//ддд If we have 0 for both sms and ems, use full length of cd
    if (!sms)
    {
        //дд Get length
        MCI_STATUS_PARMS sparams;
        memset(&sparams,0,sizeof(sparams));

        sparams.dwItem = MCI_STATUS_POSITION;
        sparams.dwTrack = 1;

        if (mciSendCommand(devid, MCI_STATUS,
                            MCI_WAIT | MCI_STATUS_ITEM | MCI_TRACK,
                            (DWORD) &sparams) != 0)
            return BACH_ERR_MCIFAILED;

        pparams.dwFrom = sparams.dwReturn;

        if (!ems)
        {
            //дд Get length
            sparams.dwItem = MCI_STATUS_LENGTH;

            if (mciSendCommand(devid, MCI_STATUS,
                               MCI_WAIT | MCI_STATUS_ITEM,
                               (DWORD) &sparams) != 0)
                return BACH_ERR_MCIFAILED;

            pparams.dwTo = sparams.dwReturn;
        }
    }
    else
    {
        pparams.dwFrom = sms;
        pparams.dwTo = ems;
    }


//ддд Start playback
    switch (mciSendCommand(devid, MCI_PLAY,
                           MCI_FROM | MCI_TO,
                           (DWORD) &pparams))
    {
        case 0:
            break;

        case MCIERR_OUTOFRANGE:
            return BACH_ERR_MCIOUTOFRANGE;

        default:
            return BACH_ERR_MCIFAILED;
    }

    return BACH_ERR_NONE;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - stop
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
bach_err_codes BachCD::stop ()
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

//дд Stop playback
    switch (mciSendCommand(devid, MCI_STOP,
                           (flags & BACH_CD_WAITONSTOP) ? MCI_WAIT : 0,
                           NULL))
    {
        case 0:
            break;

        default:
            return BACH_ERR_MCIFAILED;
    }

    return BACH_ERR_NONE;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - pause
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
bach_err_codes BachCD::pause()
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

//дд Pause playback
    switch (mciSendCommand(devid, MCI_PAUSE,
                           (flags & BACH_CD_WAITONPAUSE) ? MCI_WAIT : 0,
                           NULL))
    {
        case 0:
            break;

        default:
            return BACH_ERR_MCIFAILED;
    }

    return BACH_ERR_NONE;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - resume
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
bach_err_codes BachCD::resume()
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

//дд Resume playback
    switch (mciSendCommand(devid, MCI_RESUME,
                           (flags & BACH_CD_WAITONRESUME) ? MCI_WAIT : 0,
                           NULL))
    {
        case 0:
            break;

        default:
            return BACH_ERR_MCIFAILED;
    }

    return BACH_ERR_NONE;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - status
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
dword BachCD::status() const
{
    if (!devid)
        return 0;

    dword stat = 0;

    MCI_STATUS_PARMS sparams;
    memset(&sparams,0,sizeof(sparams));

//ддд Get mode
    sparams.dwItem = MCI_STATUS_MODE;

    if (mciSendCommand(devid, MCI_STATUS,
                       MCI_WAIT | MCI_STATUS_ITEM,
                       (DWORD) &sparams) != 0)
        return 0;

    switch (sparams.dwReturn)
    {
        case MCI_MODE_PLAY:
            stat |= BACH_CDSTAT_PLAYING;
            break;

        case MCI_MODE_PAUSE:
            stat |= BACH_CDSTAT_PAUSED;
            break;

        case MCI_MODE_OPEN:
            stat |= BACH_CDSTAT_DOOROPEN;
            break;

        case MCI_MODE_NOT_READY:
            stat |= MCI_STATUS_POSITION;
            break;
    }

    return stat;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - eject
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
bach_err_codes BachCD::eject()
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

//ддд Open media door
    switch (mciSendCommand(devid, MCI_SET,
                           (flags & BACH_CD_WAITONEJECT)
                           ? (MCI_WAIT | MCI_SET_DOOR_OPEN)
                           : MCI_SET_DOOR_OPEN,
                           NULL))
    {
        case 0:
            break;

        default:
            return BACH_ERR_MCIFAILED;
    }

    return BACH_ERR_NONE;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - retract
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
bach_err_codes BachCD::retract()
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

//ддд Close media door
    switch (mciSendCommand(devid, MCI_SET,
                           (flags & BACH_CD_WAITONRETRACT)
                           ? (MCI_WAIT | MCI_SET_DOOR_CLOSED)
                           : MCI_SET_DOOR_CLOSED,
                           NULL))
    {
        case 0:
            break;

        default:
            return BACH_ERR_MCIFAILED;
    }

    return BACH_ERR_NONE;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - set_track
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
bach_err_codes BachCD::set_track(ulong ntrack)
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

    if (!ntrack)
        return BACH_ERR_INVALIDPARAMS;

//ддд Get start of track in ms
    MCI_STATUS_PARMS    sparams;
    memset(&sparams, 0, sizeof(sparams));

    sparams.dwItem = MCI_STATUS_POSITION;
    sparams.dwTrack = ntrack;

    switch (mciSendCommand(devid, MCI_STATUS,
                           MCI_WAIT | MCI_STATUS_ITEM | MCI_TRACK,
                           (DWORD) &sparams))
    {
        case 0:
            break;

        case MCIERR_OUTOFRANGE:
            return BACH_ERR_MCIOUTOFRANGE;
        default:
            return BACH_ERR_MCIFAILED;
    }

//ддд Seek to start of track
    MCI_SEEK_PARMS   skparams;
    memset(&skparams, 0, sizeof(skparams));

    skparams.dwTo = sparams.dwReturn;

    switch (mciSendCommand(devid, MCI_SEEK,
                           (flags & BACH_CD_WAITONSEEK)
                           ? (MCI_WAIT | MCI_TO)
                           : MCI_TO,
                           (DWORD) &skparams))
    {
        case 0:
            break;

        case MCIERR_OUTOFRANGE:
            return BACH_ERR_MCIOUTOFRANGE;
        default:
            return BACH_ERR_MCIFAILED;
    }

    return BACH_ERR_NONE;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - set_position
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
bach_err_codes BachCD::set_position(ulong ms)
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

    MCI_SEEK_PARMS   sparams;
    memset(&sparams, 0, sizeof(sparams));

//дд Set play position
    sparams.dwTo = ms;

    switch (mciSendCommand(devid, MCI_SEEK,
                           (flags & BACH_CD_WAITONSEEK)
                           ? (MCI_WAIT | MCI_TO)
                           : MCI_TO,
                           (DWORD) &sparams))
    {
        case 0:
            break;

        case MCIERR_OUTOFRANGE:
            return BACH_ERR_MCIOUTOFRANGE;
        default:
            return BACH_ERR_MCIFAILED;
    }

    return BACH_ERR_NONE;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - get_track
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
ulong BachCD::get_track() const
{
    if (!devid)
        return 0;

//дд Get current track
    MCI_STATUS_PARMS sparams;
    memset(&sparams,0,sizeof(sparams));

    sparams.dwItem = MCI_STATUS_CURRENT_TRACK;

    if (mciSendCommand(devid, MCI_STATUS,
                       MCI_WAIT | MCI_STATUS_ITEM,
                       (DWORD) &sparams) != 0)
        return 0;

    return sparams.dwReturn;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - get_position
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
ulong BachCD::get_position() const
{
    if (!devid)
        return 0;

//дд Get current position (in ms)
    MCI_STATUS_PARMS sparams;
    memset(&sparams,0,sizeof(sparams));

    sparams.dwItem = MCI_STATUS_POSITION;

    if (mciSendCommand(devid, MCI_STATUS,
                       MCI_WAIT | MCI_STATUS_ITEM,
                       (DWORD) &sparams) != 0)
        return 0;

    return sparams.dwReturn;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - get_num_tracks
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
ulong BachCD::get_num_tracks() const
{
    if (!devid)
        return 0;

//ддд Get number of tracks
    MCI_STATUS_PARMS sparams;
    memset(&sparams,0,sizeof(sparams));

    sparams.dwItem = MCI_STATUS_NUMBER_OF_TRACKS;

    if (mciSendCommand(devid, MCI_STATUS,
                       MCI_WAIT | MCI_STATUS_ITEM,
                       (DWORD) &sparams) != 0)
        return 0;

    return sparams.dwReturn;
}


//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
// BachCD - get_track_info
//ддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд
bach_err_codes BachCD::get_track_info(ulong ntrack,
                                      ulong &sms, ulong &ems) const
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

    if (!ntrack)
        return BACH_ERR_INVALIDPARAMS;

    MCI_STATUS_PARMS sparams;
    memset(&sparams,0,sizeof(sparams));

//ддд Get start position of track
    sparams.dwItem = MCI_STATUS_POSITION;
    sparams.dwTrack = ntrack;

    switch (mciSendCommand(devid, MCI_STATUS,
                           MCI_WAIT | MCI_STATUS_ITEM | MCI_TRACK,
                           (DWORD) &sparams))
    {
        case 0:
            break;

        case MCIERR_OUTOFRANGE:
            return BACH_ERR_MCIOUTOFRANGE;
        default:
            return BACH_ERR_MCIFAILED;
    }

    sms = sparams.dwReturn;

//ддд Get length of track
    sparams.dwItem = MCI_STATUS_LENGTH;
    sparams.dwTrack = ntrack;

    switch (mciSendCommand(devid, MCI_STATUS,
                           MCI_WAIT | MCI_STATUS_ITEM | MCI_TRACK,
                           (DWORD) &sparams))
    {
        case 0:
            break;

        case MCIERR_OUTOFRANGE:
            return BACH_ERR_MCIOUTOFRANGE;
        default:
            return BACH_ERR_MCIFAILED;
    }

    ems = sms + sparams.dwReturn;

    return BACH_ERR_NONE;
}

//╟╠╡ End of module - bachcd.cpp ╡╠╟
