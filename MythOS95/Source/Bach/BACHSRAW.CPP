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
//                               Microsoft Windows 95/NT Version
//
//           Copyright (c) 1995-1998 by Charybdis Enterprises, Inc.
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
// BachStaticSample - load_raw
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachStaticSample::load_raw(const char *fname,
                                    bach_digi_fmt f, ulong r)
{
    if (!fname)
        return BACH_ERR_INVALIDPARAMS;

    XFileDisk  xf;

    if (xf.open (fname, XF_OPEN_DENYWRITE | XF_OPEN_READ) != 0)
        return BACH_ERR_FILENOTFOUND;

    return load_raw(xf,f,r);
}

bach_err_codes BachStaticSample::load_raw(XFile &xf,
                                    bach_digi_fmt f, ulong r)
{
    assertMyth("BachStaticSample::load_raw needs DirectSound instance",
               dsound != 0);

//ÄÄÄ Setup
    release();

    length = xf.getsize();
    if (length == dword (-1))
        return BACH_ERR_FILEERROR;

    fmt = f;
    rate = r;

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
    if (xf.read (ptr,length) != length)
        return BACH_ERR_FILEERROR;

//ÄÄ Setup format
    WAVEFORMATEX    wfmt;
    memset(&wfmt,0,sizeof(wfmt));
    
    switch (f)
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
            release();
            return BACH_ERR_NOTSUPPORTED;
    }

    wfmt.wFormatTag      = WAVE_FORMAT_PCM;
    wfmt.nSamplesPerSec  = r;
    wfmt.cbSize			 = 0;
	wfmt.nAvgBytesPerSec = r * wfmt.nBlockAlign;

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

    assertMyth("BachStaticSample::load_raw expected valid sound buffer",
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

    return BACH_ERR_NONE;
}

//°±² End of module - bachsraw.cpp ²±°
