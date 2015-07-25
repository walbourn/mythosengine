//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                        ÜÜÜÜÜÜÜÜÜÜ                       ÜÜÜÜ
//     ÚÄÄ¿                ÛÛÛ     ÛÛÜ                     ŞÛÛÛ
//     ³  ³       ÚÄÄ¿     ÛÛÛ     ÛÛÛ   ÜÜÜÜ      ÜÜÜÜÜ    ÛÛÛ ÜÜÜ
//     ³  ³ ÚÄÄ¿  ³  ³     ÛÛÛÜÜÜÜÛÛÛß  ß  ŞÛİ    ÛÛß   ßÛ  ÛÛÛÛÛßÛÛ
//     ³  ³ ³  ³  ³  ³     ÛÛÛ     ÛÛÜ  ÜÛÛÛÛÛİ  ÛÛÛ        ÛÛÛ   ÛÛÛ
//    OÙ OÙ ³  ³  ³  ³     ÛÛÛ     ÛÛÛ ŞÛİ  ÛÛÛ  ÛÛÛ    ÜÛ  ÛÛÛ   ÛÛÛ
//          ³  ³ OÙ OÙ    ÜÛÛÛÜÜÜÛÛÛß   ÛÛÛÛİßÛÜ  ßÛÛÜÜÛÛ  ÜÛÛÛÜ ÜÛÛÛÜ
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
// bachssmp.cpp
//
// Bach static sample implementation
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
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BachStaticSample::BachStaticSample(BachDigital *digi) :
    BachSample(digi),
    length (0),
    handle (0)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BachStaticSample::~BachStaticSample()
{
    release();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - release
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void BachStaticSample::release ()
{
    if (flags & BACH_SMP_OWNSDATA)
    {
        if (handle)
        {
            ivory_hfree (&handle);
        }
    }
    flags &= ~BACH_SMP_OWNSDATA;
    handle = 0;

    BachSample::release();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                            °° Protected °°
// BachStaticSample - restore
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachStaticSample::restore()
{
    assertMyth("BachStaticSample::restore needs valid data",
               sbuffer != 0 && handle != 0 && length > 0);

    if (sbuffer->Restore() == DS_OK)
    {
        void *ptr = ivory_hlock (handle);
        if (!ptr)
            return BACH_ERR_LOCKFAILED;

        DWORD   len;
        void    *data;
        if (sbuffer->Lock (0, length, &data, &len,
                            NULL, 0, 0))
        {
            memcpy (data, ptr, len);
            sbuffer->Unlock (data, len, NULL, 0);

            ivory_hunlock(handle);
            return BACH_ERR_NONE;
        }
        else
        {
            ivory_hunlock(handle);
            return BACH_ERR_DSLOCKFAILED;
        }
    }

    return BACH_ERR_DSBUFFERLOST;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - play
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachStaticSample::play (int loop)
{
    if (!sbuffer || !handle)
        return BACH_ERR_UNINITIALIZED;

    for (;;)
    {
        if (loop)
            flags |= BACH_SMP_LOOP;
        else
            flags &= BACH_SMP_LOOP;

        HRESULT res = sbuffer->Play (0, 0, loop ? DSBPLAY_LOOPING : 0);
        switch (res)
        {
            case DS_OK:
                return BACH_ERR_NONE;

            case DSERR_BUFFERLOST:
                {
                    bach_err_codes err = restore();
                    if (err != BACH_ERR_NONE)
                        return err;
                }
                break;

            default:
                return BACH_ERR_DSFAILED;
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - stop
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachStaticSample::stop ()
{
    if (!sbuffer)
        return BACH_ERR_UNINITIALIZED;

    if (sbuffer->Stop() != DS_OK)
        return BACH_ERR_DSFAILED;

    sbuffer->SetCurrentPosition(0);

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - pause
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachStaticSample::pause()
{
    if (!sbuffer)
        return BACH_ERR_UNINITIALIZED;

    if (sbuffer->Stop() != DS_OK)
        return BACH_ERR_DSFAILED;

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - resume
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachStaticSample::resume()
{
    if (!sbuffer || !handle)
        return BACH_ERR_UNINITIALIZED;

    for (;;)
    {
        HRESULT res = sbuffer->Play (0, 0,
                                     (flags & BACH_SMP_LOOP)
                                     ? DSBPLAY_LOOPING : 0);
        switch (res)
        {
            case DS_OK:
                return BACH_ERR_NONE;

            case DSERR_BUFFERLOST:
                {
                    bach_err_codes err = restore();
                    if (err != BACH_ERR_NONE)
                        return err;
                }
                break;

            default:
                return BACH_ERR_DSFAILED;
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - status
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
dword BachStaticSample::status() const
{
    if (!sbuffer)
        return 0;

    DWORD dsstat;
    if (sbuffer->GetStatus(&dsstat) != DS_OK)
        return 0;

    dword status = 0;
    if (dsstat & DSBSTATUS_PLAYING)
    {
        status |= BACH_SMPSTAT_PLAYING;

        if (dsstat & DSBSTATUS_LOOPING)
            status |= BACH_SMPSTAT_LOOPING;
    }

    return status;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - set_volume
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachStaticSample::set_volume (long vol)
{
    if (!sbuffer)
        return BACH_ERR_UNINITIALIZED;

//ÄÄÄ Convert the volume to the 127 == full volume, 0 == no volume range
    if (vol < 0)
        vol = 0;
    else if (vol > 127)
        vol = 127;

//ÄÄÄ Now, use the db_table to make this number into an attenuation value.
    if (sbuffer->SetVolume (-db_table[(db_table_size - 1) - vol]) != DS_OK)
        return BACH_ERR_DSFAILED;

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - get_volume
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
long BachStaticSample::get_volume () const
{
    if (!sbuffer)
        return 0;

    long res;
    if (sbuffer->GetVolume (&res) != DS_OK)
        return 0;

    return db_table_find (10000 + res);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - set_pan
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachStaticSample::set_pan (long heading)
{
    if (!sbuffer)
        return BACH_ERR_UNINITIALIZED;

//ÄÄÄ  Ensure that the direction is the in -179..180 range
    while (heading > 180)
        heading -= 360;
    while (heading < -179)
        heading += 360;

//ÄÄÄ  Since we are only stereo, wrap the heading into the forward field.
    if (heading > 90)
        heading = 180 - heading;
    else if (heading < -90)
        heading = -(180 + heading);

//ÄÄÄ  Now, scale the number into DirectSound's range
    long pan = heading * (db_table_size-1) / 90;

//ÄÄÄ  Set the pan appropriately
    if (pan < 0)
    {
        if (sbuffer->SetPan (-db_table[-pan]) != DS_OK)
            return BACH_ERR_DSFAILED;
    }
    else if (pan > 0)
    {
        if (sbuffer->SetPan (db_table[pan]) != DS_OK)
            return BACH_ERR_DSFAILED;
    }
    else
    {
        if (sbuffer->SetPan (0) != DS_OK)
            return BACH_ERR_DSFAILED;
    }

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - get_pan
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
long BachStaticSample::get_pan () const
{
    if (!sbuffer)
        return 0;

    long pan;
    if (sbuffer->GetPan (&pan) != DS_OK)
        return 0;

//ÄÄÄ Convert into range
    if (pan < 0)
        pan = -db_table_find (-pan);
    else if (pan > 0)
        pan = db_table_find (pan);
    else
        pan = 0;

//ÄÄÄ Scale into degrees
    return ((pan * 90) / (db_table_size - 1));
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - set_playrate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachStaticSample::set_playrate (ulong r)
{
    if (!sbuffer)
        return BACH_ERR_UNINITIALIZED;

    if (r != 0)
    {
        if (r < 100)
            r = 100;

        if (r > 100000)
            r = 100000;
    }

    if (sbuffer->SetFrequency (r) != DS_OK)
        return BACH_ERR_DSFAILED;

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - get_playrate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
ulong BachStaticSample::get_playrate() const
{
    if (!sbuffer)
        return 0;

    DWORD rate;
    if (sbuffer->GetFrequency (&rate) != DS_OK)
        return 0;

    return rate;
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - set_position
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachStaticSample::set_position (ulong p)
{
    if (!sbuffer)
        return BACH_ERR_UNINITIALIZED;

    if (p > length)
        return BACH_ERR_INVALIDPARAMS;

    if (sbuffer->SetCurrentPosition(p) != DS_OK)
        return BACH_ERR_DSFAILED;

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - get_position
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
ulong BachStaticSample::get_position() const
{
    if (!sbuffer)
        return 0;

    DWORD pos;
    if (sbuffer->GetCurrentPosition(&pos,NULL) != DS_OK)
        return 0;

    return pos;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - create
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachStaticSample::create(void *p, ulong l, bach_digi_fmt f, ulong r)
{
    if (!p || l < 1 || r < 1)
        return BACH_ERR_INVALIDPARAMS;

    release();

//ÄÄ Put a copy into handle memory
    handle = ivory_halloc (l);
    if (!handle)
        return BACH_ERR_OUTOFMEMORY;

    flags |= BACH_SMP_OWNSDATA;

    void *ptr = ivory_hlock (handle);
    if (!ptr)
    {
        release();
        return BACH_ERR_LOCKFAILED;
    }

    memcpy(ptr,p,l);

    ivory_hunlock (handle);

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
    bd.dwBufferBytes    = l;
    bd.lpwfxFormat      = &wfmt;

    if (dsound->CreateSoundBuffer (&bd, &sbuffer, NULL) != DS_OK)
    {
        release();
        return BACH_ERR_DSSECCREATFAIL;
    }

    assertMyth("BachStaticSample::create expected valid sound buffer",
               sbuffer != 0);

//ÄÄÄ Copy data
    DWORD   len;
    void    *dsptr;

    if (sbuffer->Lock (0, l, &dsptr, &len, NULL, 0, 0) != DS_OK)
    {
        release();
        return BACH_ERR_DSLOCKFAILED;
    }

    memcpy (dsptr, p, l);
    sbuffer->Unlock (dsptr, len, NULL, 0);

    return BACH_ERR_NONE;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachStaticSample - get_playtime
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
ulong BachStaticSample::get_playtime () const
{
    assertMyth("BachStaticSample::get_playtime needs valid data",
               length > 0);

    if (rate < 1)
        return 0;

    ulong pos = 0;
    if (sbuffer)
    {
        if (sbuffer->GetCurrentPosition(&pos,NULL) != DS_OK)
            pos = 0;
    }

    if (pos > length)
        return 0;

    ulong sample_count = 0;

    switch (fmt)
    {
        case BACH_DIGI_MONO_8:
            sample_count = length - pos;
            break;

        case BACH_DIGI_MONO_16:
        case BACH_DIGI_STEREO_8:
            sample_count = (length - pos) / 2;
            break;

        case BACH_DIGI_STEREO_16:
            sample_count = (length - pos) / 4;
            break;

        default:
            // This assert will fail and give a clue to the reason.
            assertMyth("BachStaticSample::get_playtime needs valid format",
                        0);
            break;
    }

    return (sample_count * 1000) / rate;
}

//°±² End of module - bachssmp.cpp ²±°
