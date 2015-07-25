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
// bachsraw.cpp
//
// Bach static sample load of .RAW files
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "bach.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  I/O Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - load_wav
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachStaticSample::load_wav(const char *fname)
{
    if (!fname)
        return BACH_ERR_INVALIDPARAMS;

    XFParseIFF  iff(XF_IFF_RIFF);

    if (iff.open (fname, XF_OPEN_DENYWRITE | XF_OPEN_READ) != 0)
        return BACH_ERR_FILENOTFOUND;

    if (iff.seekform (iff.makeid ('W','A','V','E')) != 0)
        return BACH_ERR_NOTSUPPORTED;

    return load_wav (iff);
}

bach_err_codes BachStaticSample::load_wav(XFParseIFF &iff)
{
    WAVEFORMATEX    wfmt;

    assertMyth("BachStaticSample::load_wav needs DirectSound instance",
               dsound != 0);

    release();

//ÄÄÄ Find and load the WAVE form
    if ( iff.chunkid != iff.makeid('R','I','F','F') != 0
         || iff.formid != iff.makeid('W','A','V','E')  != 0
         || iff.enterform() != 0)
        return BACH_ERR_FILEERROR;

//ÄÄÄ Find the header chunk
    if ( iff.seekchunk (iff.makeid ('f','m','t',' ')) != 0
         || iff.chunkSize != sizeof (PCMWAVEFORMAT)
         || iff.read (&wfmt) != 0)
    {
        iff.leaveform();
        return BACH_ERR_FILEERROR;
    }

    if (wfmt.wFormatTag != WAVE_FORMAT_PCM
        || (wfmt.wBitsPerSample != 8
            && wfmt.wBitsPerSample != 16)
        || (wfmt.nChannels != 1
            && wfmt.nChannels != 2))
    {
        iff.leaveform();
        return BACH_ERR_NOTSUPPORTED;
    }

//ÄÄÄ Find the sample data
    if (iff.seekchunk (iff.makeid ('d','a','t','a')) != 0)
    {
        iff.leaveform();
        return BACH_ERR_FILEERROR;
    }

//ÄÄÄ Setup

    // Record the length of this chunk
    length = iff.chunkSize;

    // Allocate a handle to hold the data
    handle = ivory_halloc (length);
    if (!handle)
        return BACH_ERR_OUTOFMEMORY;

    flags |= BACH_SMP_OWNSDATA;

    void *ptr = ivory_hlock (handle);
    if (!ptr)
    {
        release();
        return BACH_ERR_LOCKFAILED;
    }

//ÄÄÄ Read the data into the local buffer
    if (iff.read (ptr) != XF_ERR_NONE)
        return BACH_ERR_FILEERROR;

//ÄÄÄ Setup sound buffer
    DSBUFFERDESC    bd;
    memset (&bd,0,sizeof (bd));

    bd.dwSize           = sizeof (DSBUFFERDESC);
    bd.dwFlags          = DSBCAPS_CTRLALL | DSBCAPS_STATIC;
    bd.dwBufferBytes    = length;
    bd.lpwfxFormat      = &wfmt;

    if (dsound->CreateSoundBuffer (&bd, &sbuffer, NULL) != DS_OK)
    {
        release();
        return BACH_ERR_DSSECCREATFAIL;
    }

    assertMyth("BachStaticSample::load_wav expected valid sound buffer",
               sbuffer != 0);

//ÄÄÄ Copy data
    DWORD   len;
    void    *dsptr;

    if (sbuffer->Lock (0, length, &dsptr, &len, NULL, 0, 0) != DS_OK)
    {
        release();
        return BACH_ERR_DSLOCKFAILED;
    }

    memcpy (dsptr,ptr, len);
    sbuffer->Unlock (dsptr, len, NULL, 0);

    ivory_hunlock (handle);

//ÄÄÄ Extract some format information
    rate = wfmt.nSamplesPerSec;

    if (wfmt.wBitsPerSample == 8)
        fmt = (wfmt.nChannels == 1)
              ? BACH_DIGI_MONO_8 : BACH_DIGI_STEREO_8;
    else
        fmt = (wfmt.nChannels == 1)
              ? BACH_DIGI_MONO_16 : BACH_DIGI_STEREO_16;

///ÄÄÄ Cleanup and exit
    iff.leaveform();

    return BACH_ERR_NONE;
}

//°±² End of module - bachswav.cpp ²±°
