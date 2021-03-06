//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                        樛樛樛樛樛                       樛樛
//     敖朕                栩�     栩�                     渟栩
//     �  �       敖朕     栩�     栩�   樛樛      樛樛�    栩� 樛�
//     �  � 敖朕  �  �     栩桀樛樂栩�  �  渟�    栩�   炳  栩栩桎栩
//     �  � �  �  �  �     栩�     栩�  樂栩栩�  栩�        栩�   栩�
//    O� O� �  �  �  �     栩�     栩� 渟�  栩�  栩�    樂  栩�   栩�
//          �  � O� O�    樂栩樛樂栩�   栩栩毯桀  炳桀樂�  樂栩� 樂栩�
//         O� O�
//                            C++ Music, Sound, and Effects Library
//                               Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
// Created by Dan Higdon & Chuck Walbourn
//
// bachcd.cpp
//
// CD audio control implementation
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <stdlib.h>
#include <string.h>

#include "bach.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - Constructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BachCD::BachCD () :
    devid(0),
    flags(BACH_CD_STOPONCLOSE)
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - Destructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BachCD::~BachCD()
{
    close();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - init
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachCD::init(ulong id)
{
    if (devid)
        return BACH_ERR_ALREADYOPEN;

//陳� Try to open device
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

//陳� Set the time format to milliseconds
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - close
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - play
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachCD::play (ulong sms, ulong ems)
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

    if (ems && (ems < sms))
        return BACH_ERR_INVALIDPARAMS;

    MCI_PLAY_PARMS pparams;
    memset(&pparams, 0, sizeof(pparams));

//陳� If we have 0 for both sms and ems, use full length of cd
    if (!sms)
    {
        //陳 Get length
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
            //陳 Get length
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


//陳� Start playback
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - stop
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachCD::stop ()
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

//陳 Stop playback
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - pause
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachCD::pause()
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

//陳 Pause playback
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - resume
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachCD::resume()
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

//陳 Resume playback
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - status
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
dword BachCD::status() const
{
    if (!devid)
        return 0;

    dword stat = 0;

    MCI_STATUS_PARMS sparams;
    memset(&sparams,0,sizeof(sparams));

//陳� Get mode
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - eject
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachCD::eject()
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

//陳� Open media door
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - retract
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachCD::retract()
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

//陳� Close media door
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - set_track
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachCD::set_track(ulong ntrack)
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

    if (!ntrack)
        return BACH_ERR_INVALIDPARAMS;

//陳� Get start of track in ms
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

//陳� Seek to start of track
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - set_position
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachCD::set_position(ulong ms)
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

    MCI_SEEK_PARMS   sparams;
    memset(&sparams, 0, sizeof(sparams));

//陳 Set play position
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - get_track
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ulong BachCD::get_track() const
{
    if (!devid)
        return 0;

//陳 Get current track
    MCI_STATUS_PARMS sparams;
    memset(&sparams,0,sizeof(sparams));

    sparams.dwItem = MCI_STATUS_CURRENT_TRACK;

    if (mciSendCommand(devid, MCI_STATUS,
                       MCI_WAIT | MCI_STATUS_ITEM,
                       (DWORD) &sparams) != 0)
        return 0;

    return sparams.dwReturn;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - get_position
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ulong BachCD::get_position() const
{
    if (!devid)
        return 0;

//陳 Get current position (in ms)
    MCI_STATUS_PARMS sparams;
    memset(&sparams,0,sizeof(sparams));

    sparams.dwItem = MCI_STATUS_POSITION;

    if (mciSendCommand(devid, MCI_STATUS,
                       MCI_WAIT | MCI_STATUS_ITEM,
                       (DWORD) &sparams) != 0)
        return 0;

    return sparams.dwReturn;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - get_num_tracks
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ulong BachCD::get_num_tracks() const
{
    if (!devid)
        return 0;

//陳� Get number of tracks
    MCI_STATUS_PARMS sparams;
    memset(&sparams,0,sizeof(sparams));

    sparams.dwItem = MCI_STATUS_NUMBER_OF_TRACKS;

    if (mciSendCommand(devid, MCI_STATUS,
                       MCI_WAIT | MCI_STATUS_ITEM,
                       (DWORD) &sparams) != 0)
        return 0;

    return sparams.dwReturn;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachCD - get_track_info
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachCD::get_track_info(ulong ntrack,
                                      ulong &sms, ulong &ems) const
{
    if (!devid)
        return BACH_ERR_UNINITIALIZED;

    if (!ntrack)
        return BACH_ERR_INVALIDPARAMS;

    MCI_STATUS_PARMS sparams;
    memset(&sparams,0,sizeof(sparams));

//陳� Get start position of track
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

//陳� Get length of track
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

//葦� End of module - bachcd.cpp 憶�
