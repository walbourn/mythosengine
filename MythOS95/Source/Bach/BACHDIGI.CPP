//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                        ÜÜÜÜÜÜÜÜÜÜ                       ÜÜÜÜ        
//     ÚÄÄ¿                ÛÛÛ     ÛÛÜ                     ÞÛÛÛ        
//     ³  ³       ÚÄÄ¿     ÛÛÛ     ÛÛÛ   ÜÜÜÜ      ÜÜÜÜÜ    ÛÛÛ ÜÜÜ    
//     ³  ³ ÚÄÄ¿  ³  ³     ÛÛÛÜÜÜÜÛÛÛß  ß  ÞÛÝ    ÛÛß   ßÛ  ÛÛÛÛÛßÛÛ   
//     ³  ³ ³  ³  ³  ³     ÛÛÛ     ÛÛÜ  ÜÛÛÛÛÛÝ  ÛÛÛ        ÛÛÛ   ÛÛÛ  
//    OÙ OÙ ³  ³  ³  ³     ÛÛÛ     ÛÛÛ ÞÛÝ  ÛÛÛ  ÛÛÛ    ÜÛ  ÛÛÛ   ÛÛÛ  
//          ³  ³ OÙ OÙ    ÜÛÛÛÜÜÜÛÛÛß   ÛÛÛÛÝßÛÜ  ßÛÛÜÜÛÛ  ÜÛÛÛÜ ÜÛÛÛÜ 
//         OÙ OÙ  
//                            C++ Music, Sound, and Effects Library
//                                Microsoft Windows '95 Version
//
//           Copyright (c) 1995-1997 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Dan Higdon & Chuck Walbourn
//
// bachdigi.cpp
//
// Digitial sound source implementation
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <stdlib.h>
#include <string.h>

#include "bach.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachDigital - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BachDigital::BachDigital (ulong drate, bach_digi_fmt fmt):
    dsound (0),
    primary (0),
    driverRate (drate),
    driverFmt (fmt)
{
    assertMyth ("BachDigital needs valid driver rate", drate != 0);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachDigital - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BachDigital::~BachDigital()
{
    close ();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachDigital - init 
//
// Initializes the digital driver.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachDigital::init (HWND hWnd, DWORD coop_level, int cont_play)
{
    if (dsound)
        return BACH_ERR_NONE;

    if (!hWnd)
        return BACH_ERR_INVALIDPARAMS;

    switch (coop_level)
    {
        case DSSCL_WRITEPRIMARY:
        case DSSCL_EXCLUSIVE:
        case DSSCL_PRIORITY:
        case DSSCL_NORMAL:
            break;
        default:
            return BACH_ERR_INVALIDPARAMS;
    }

//ÄÄ Create Direct Sound Object
    if (DirectSoundCreate (NULL, &dsound, NULL) != DS_OK)
        return BACH_ERR_DSCONNECTFAIL;

    assertMyth("BachDigital::init has invalid DSound create result",
               dsound != 0);

//ÄÄ Let Direct Sound know how much control we need
    if (dsound->SetCooperativeLevel (hWnd, coop_level) != DS_OK)
    {
        close();
        return BACH_ERR_DSSETCOOPFAIL;
    }

//ÄÄ Create Primary Direct Sound Buffer
    DSBUFFERDESC    bd;
    memset (&bd, 0, sizeof (bd));

    bd.dwSize = sizeof (bd);
    bd.dwFlags = DSBCAPS_PRIMARYBUFFER;

    if (dsound->CreateSoundBuffer (&bd, &primary, NULL) != DS_OK)
    {
        close();
        return BACH_ERR_DSPRICREATFAIL;
    }

    assertMyth("BachDigital::init failed DSound buffer create",
                primary != 0);

//ÄÄ Get caps of primary buffer
    DSBCAPS     caps;
    caps.dwSize = sizeof(caps);

    primary->GetCaps(&caps);

    assertMyth("BachDigital::init has invalid caps for primary buffer",
               (caps.dwFlags & DSBCAPS_PRIMARYBUFFER)
               && (caps.dwBufferBytes > 0));

//ÄÄ Setup format
    WAVEFORMATEX    wfmt;
    memset(&wfmt,0,sizeof(wfmt));
    
    switch (driverFmt)
    {
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Mono 8-bit
        case BACH_DIGI_MONO_8:
            wfmt.nChannels		= 1;
            wfmt.wBitsPerSample = 8;
		    wfmt.nBlockAlign    = 1;
            break;
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Mono 16-bit
        case BACH_DIGI_MONO_16:
            wfmt.nChannels		= 1;
            wfmt.wBitsPerSample = 16;
		    wfmt.nBlockAlign    = 2;
            break;
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Stereo 8-bit
        case BACH_DIGI_STEREO_8:
            wfmt.nChannels		= 2;
            wfmt.wBitsPerSample = 8;
		    wfmt.nBlockAlign    = 2;
            break;
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Stereo 16-bit
        case BACH_DIGI_STEREO_16:
            wfmt.nChannels		= 2;
            wfmt.wBitsPerSample = 16;
		    wfmt.nBlockAlign    = 4;
            break;
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Unknown
        default:
            close();
            return BACH_ERR_NOTSUPPORTED;
    }

    wfmt.wFormatTag      = WAVE_FORMAT_PCM;
    wfmt.nSamplesPerSec  = driverRate;
    wfmt.cbSize			 = 0;
	wfmt.nAvgBytesPerSec = driverRate * wfmt.nBlockAlign;

//ÄÄ Set format for primaray buffer
    if (coop_level == DSSCL_WRITEPRIMARY)
    {
        if (primary->SetFormat (&wfmt) != DS_OK)
        {
            close();
            return BACH_ERR_DSFORMATFAILED;
        }
    }
    else
    {
        if (primary->SetFormat (&wfmt) != DS_OK
            && coop_level != DSSCL_NORMAL)
        {
            close();
            return BACH_ERR_DSFORMATFAILED;
        }
    }

//ÄÄ Begin primary buffer play
    if (cont_play)
    {
        if (primary->Play (0, 0, DSBPLAY_LOOPING) != DS_OK)
        {
            close();
            return BACH_ERR_DSFAILED;
        }
    }

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachDigital - close
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void BachDigital::close()
{
//ÄÄ Release Direct Sound Buffer and Object
    if (primary)
    {
        primary->Stop();
        primary->Release();
        primary = 0;
    }

    if (dsound)
    {
        dsound->Release();
        dsound = 0;
    }
}

//°±² End of module - bachdigi.cpp ²±°

