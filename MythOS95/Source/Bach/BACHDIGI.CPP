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
//                                Microsoft Windows '95 Version
//
//           Copyright (c) 1995-1997 by Charybdis Enterprises, Inc.
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
// Created by Dan Higdon & Chuck Walbourn
//
// bachdigi.cpp
//
// Digital interface object core implementation.
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

#include <xfile.hpp>

//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠
//
//                                 Code
//
//╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠╠

//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachDigital - Constructor                                                Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
BachDigital::BachDigital (dword drate):
    BachDigitalInterface(),
    driverRate  (drate),
    dsPrimary   (0),
    dSound      (0)
{
    assert (drate != 0);

//дд Setup default values
    memset (smpPtr, 0, sizeof (smpPtr));
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachDigital - Destructor                                                 Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
BachDigital::~BachDigital()
{
    close ();
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachDigital - init                                                       Ё
//                                                                          Ё
// Initializes the digital driver.                                          Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
bach_err_codes BachDigital::init (HWND hWnd, DWORD coop_level)
{
//дд Create Direct Sound Object
    if (DirectSoundCreate (NULL, &dSound, NULL) != DS_OK)
        return errorn = BACH_ERR_DSCONNECTFAIL;

    assert (dSound != 0);

//дд Let Direct Sound know how much control we need
    if (dSound->SetCooperativeLevel (hWnd, coop_level) != DS_OK)
    {
        dSound->Release();
        dSound = 0;
        return errorn = BACH_ERR_SETCOOPFAIL;
    }

//дд Create Primary Direct Sound Buffer
    if (coop_level != DSSCL_NORMAL)
    {
        DSBUFFERDESC    bd;
        memset (&bd, 0, sizeof (bd));
        bd.dwSize = sizeof (bd);
        bd.dwFlags = DSBCAPS_PRIMARYBUFFER;

        if (dSound->CreateSoundBuffer (&bd, &dsPrimary, NULL) != DS_OK)
        {
            dSound->Release();
            dSound = 0;
            return errorn = BACH_ERR_DSPRICREATFAIL;
        }

        assert (dsPrimary != 0);

    //дд Set the primary buffer format and other parameters
        WAVEFORMATEX        fmt;
        fmt.wFormatTag      = WAVE_FORMAT_PCM;
        fmt.nChannels       = 2;
        fmt.nSamplesPerSec  = driverRate;
        fmt.nBlockAlign     = 4;
        fmt.nAvgBytesPerSec = driverRate * fmt.nBlockAlign;
        fmt.wBitsPerSample  = 16;
        fmt.cbSize          = 0;

        dsPrimary->SetFormat (&fmt);
        dsPrimary->SetFrequency (driverRate);
        dsPrimary->SetVolume (BACH_DIGI_DEFAULT_VOLUME);
        dsPrimary->SetPan (BACH_DIGI_DEFAULT_PAN);

    //дд Begin primary buffer play
        dsPrimary->Play (0, 0, DSBPLAY_LOOPING);
    }

    return errorn = BACH_ERR_NONE;
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachDigital - close                                                      Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
void BachDigital::close()
{
//дд Release all channels
    for (byte i = 0; i < BACH_DIGI_CHANNELS; i++)
    {
        if (smpPtr[i] != 0)
            release (i);
    }

//дд Release Direct Sound Primary Buffer and Object
    if (dsPrimary)
    {
        dsPrimary->Stop();
        dsPrimary->Release();
        dsPrimary = 0;
    }

    if (dSound)
    {
        dSound->Release();
        dSound = 0;
    }
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachDigital - setup                                                      Ё
//                                                                          Ё
// Setups up a digital sample for playback.  Either takes a filename or     Ё
// a BachSample object.  The input 'chan' is -1 by default, which indicates Ё
// to use the first available channel.  The channel used is returned or -1  Ё
// if an error occurs.                                                      Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
byte BachDigital::setup (BachSample *s, byte chan)
{
//дд Safeguard
    assert (dSound);
    assert (s && s->length && s->rate);

//ддд Find empty channel
    if (chan == byte (-1))
    {
        assert (BACH_DIGI_CHANNELS > 0);
        for (chan = 0; smpPtr[chan] != 0; chan++)
        {
            if (chan + 1 == BACH_DIGI_CHANNELS)
            {
                errorn = BACH_ERR_ALLCHANNELSBUSY;
                return byte (-1);
            }
        }
    }
    else
        chan = byte (int (chan) % BACH_DIGI_CHANNELS);

//ддд Release any previous sample
    release (chan);

//ддд Setup sample
    smpPtr[chan] = s;

    return chan;
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachDigital - release                                                    Ё
//                                                                          Ё
// Releases a sample on the given channel.                                  Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
void BachDigital::release (byte chan)
{
    BachSample **ptr = &smpPtr[chan % BACH_DIGI_CHANNELS];

    if (*ptr != 0)
    {
        (*ptr)->stop ();
        *ptr = 0;
    }
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachDigital - play                                                       Ё
//                                                                          Ё
// Begins play of a sample on the given channel.                            Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
void BachDigital::play (byte chan, ulong loop)
{
    assert (dSound);

    smpPtr[chan % BACH_DIGI_CHANNELS]->play (loop);
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachDigital - stop                                                       Ё
//                                                                          Ё
// Ends the play of a sample on the given channel.                          Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
void BachDigital::stop (byte chan)
{
    assert (dSound);

    smpPtr[chan % BACH_DIGI_CHANNELS]->stop();
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachDigital - pause                                                      Ё
//                                                                          Ё
// Pauses the play of a sample on the given channel.                        Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
void BachDigital::pause(byte chan)
{
    assert (dSound);
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachDigital - resume                                                     Ё
//                                                                          Ё
// Resumes a paused sample on the given channel.                            Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
void BachDigital::resume(byte chan)
{
    assert (dSound);
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachDigital - status                                                     Ё
//                                                                          Ё
// Returns status word for digital object.                                  Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
dword BachDigital::status(byte chan)
{
    dword flags=0;


    return flags;
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachDigital - set_volume                                                 Ё
//                                                                          Ё
// Sets the current play volume for the specified channel.                  Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
byte BachDigital::set_volume(byte chan, byte vol)
{
    smpPtr[chan % BACH_DIGI_CHANNELS]->set_volume (vol);

    return 0;
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachDigital - get_volume                                                 Ё
//                                                                          Ё
// Returns the chanel's volume.                                             Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
byte BachDigital::get_volume(byte chan)
{
    return byte (smpPtr[chan % BACH_DIGI_CHANNELS]->get_volume ());
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachDigital - set_pan                                                    Ё
//                                                                          Ё
// Sets the pan location for the given channel.                             Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
byte BachDigital::set_pan(byte chan, byte pan)
{
    smpPtr[chan % BACH_DIGI_CHANNELS]->set_pan (pan);
    return 0;
}


//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддд©
// BachDigital - get_pan                                                    Ё
//                                                                          Ё
// Returns the given channel's pan location.                                Ё
//дддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддддды
byte BachDigital::get_pan(byte chan)
{
    return byte (smpPtr[chan % BACH_DIGI_CHANNELS]->get_pan ());
}


//╟╠╡ End of module - bachdigi.cpp ╡╠╟

