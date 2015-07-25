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
// bachsamp.cpp
//
// Bach Sample container class implementation.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "bach.hpp"

#include <ivory.hpp>
#include <xfile.hpp>

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// db_table - a table converting numbers 0-127 into dBV values for DSound   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
const int db_table_size = 128;

static short db_table[db_table_size] =
{
      0,     16,     32,     48,     65,     82,     98,    115,
    133,    150,    167,    185,    202,    220,    238,    256,
    275,    293,    312,    331,    350,    369,    388,    408,
    427,    447,    467,    488,    508,    529,    550,    571,
    592,    614,    636,    658,    680,    703,    725,    748,
    772,    795,    819,    843,    868,    892,    917,    943,
    968,    994,   1020,   1047,   1074,   1101,   1129,   1157,
   1185,   1214,   1243,   1273,   1303,   1334,   1365,   1396,
   1428,   1461,   1494,   1527,   1561,   1596,   1631,   1667,
   1703,   1740,   1778,   1817,   1856,   1896,   1937,   1978,
   2021,   2064,   2109,   2154,   2200,   2248,   2296,   2346,
   2397,   2449,   2502,   2557,   2614,   2672,   2732,   2793,
   2857,   2922,   2990,   3060,   3132,   3207,   3285,   3365,
   3450,   3537,   3629,   3725,   3825,   3931,   4042,   4160,
   4285,   4418,   4560,   4713,   4878,   5057,   5254,   5471,
   5714,   5989,   6307,   6682,   7142,   7735,   8571,  10000
};


//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// A simple binary chop utility for db_table                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
static short db_table_find (int i)
{
    int lo = 0;
    int hi = db_table_size;

    for (;;)
    {
        // Catch the case where the value is not found
        int midp = (lo + hi) / 2;

        if (lo == midp)
            return midp;

        // See which partition the value lies in
        int midv = db_table[midp];

        if (i == midv)
            return midp;

        else if (i > midv)
            lo = midp;

        else // (i < midv)
            hi = midp;
    }
}


//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//±±±±±±±±±±±±±±±±±±±±±±±±±±±  BachSample  ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - constructor                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BachSample::BachSample (const BachDigital &bdig):
    dSound      (bdig.dSound),
    pdsb        (0),
    dsbHandle   (0),
    flags       (0),
    length      (0),
    fmt         (BACH_DIGI_MONO_8),
    rate        (0),
    ptr         (0)
{
    assert (dSound != 0);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - destructor                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BachSample::~BachSample()
{
    stop();
    release();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - copy constructor                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BachSample::BachSample (BachSample const &b):
    dSound      (b.dSound),
    pdsb        (0),
    dsbHandle   (b.dsbHandle),
    flags       (0),
    length      (b.length),
    fmt         (b.fmt),
    rate        (b.rate),
    ptr         (0)
{
    if (b.pdsb)
    {
        if (dSound->DuplicateSoundBuffer (b.pdsb, &pdsb) != DS_OK)
        {
            dsbHandle = 0;
            pdsb    = 0;
            length  = 0;
            fmt     = BACH_DIGI_MONO_8;
            rate    = 0;
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - operator =                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BachSample &BachSample::operator = (BachSample const &b)
{
    // Guard against overwriting yourself
    if (&b != this)
    {
        stop();
        release ();

        dSound    = b.dSound;
        dsbHandle = b.dsbHandle;
        flags     = 0;
        length    = b.length;
        fmt       = b.fmt;
        rate      = b.rate;
        ptr       = 0;

        if (b.pdsb)
        {
            if (dSound->DuplicateSoundBuffer (b.pdsb, &pdsb) != DS_OK)
            {
                dsbHandle = 0;
                pdsb    = 0;
                length  = 0;
                fmt     = BACH_DIGI_MONO_8;
                rate    = 0;
            }
        }
    }

    return *this;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - release                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void BachSample::release ()
{
    if (flags & BACH_SMP_OWNSDATA)
    {
        if (flags & BACH_SMP_LOCKED)
            unlock();

        if (dsbHandle)
        {
            ivory_hfree (&dsbHandle);
        }
    }

    dsbHandle = 0;

    if (pdsb)
    {
        pdsb->Release();
        pdsb = 0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - lock                                                        ³
//                                                                          ³
// Locks the sample.                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
bach_err_codes BachSample::lock ()
{
    if (!pdsb)
        return BACH_ERR_UNINITIALIZED;

    return BACH_ERR_LOCKFAILED;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - unlock                                                      ³
//                                                                          ³
// Unlocks the sample.                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void BachSample::unlock ()
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - restore                                                     ³
//                                                                          ³
// Restore the DSound buffer if it was lost.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
HRESULT BachSample::restore ()
{
    assert (pdsb && dsbHandle && length > 0);

    if (dsbHandle)
    {
        HRESULT res = pdsb->Restore();

        // Recover the DSound buffer
        if (res == DS_OK)
        {
            void *pdata = ivory_hlock (dsbHandle);

            // Copy the data into the buffer
            DWORD   dwLen;
            void    *pbdata;

            res = pdsb->Lock (0, length,
                              &pbdata, &dwLen,
                              NULL, 0,
                              0);

            if (res == DS_OK)
            {
                memcpy (pbdata, pdata, dwLen);
                pdsb->Unlock (pbdata, dwLen, NULL, 0);
            }

            ivory_hunlock (dsbHandle);
        }

        return res;
    }

    return DSERR_BUFFERLOST;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - play                                                        ³
//                                                                          ³
// Play the sample, optionally looping                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
bach_err_codes BachSample::play (BOOL loop)
{
    if (!pdsb)
        return BACH_ERR_UNINITIALIZED;

    for (;;)
    {
        HRESULT res = pdsb->Play (0, 0, loop ? DSBPLAY_LOOPING: 0);
        switch (res)
        {
            case DS_OK:
                flags |= BACH_SMP_PLAYING;
                return BACH_ERR_NONE;

            case DSERR_BUFFERLOST:
                // Try to restore the buffer; fail if we can't
                if (restore() == DS_OK)
                    break;

            // We don't handle any other special cases for now, just fail them
            default:
                return BACH_ERR_PLAYFAIL;
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - stop                                                        ³
//                                                                          ³
// Stop the sample.                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
bach_err_codes BachSample::stop (BOOL rewind)
{
    if (!pdsb)
        return BACH_ERR_UNINITIALIZED;

    pdsb->Stop();

    if (rewind)
        pdsb->SetCurrentPosition (0);

    flags &= ~BACH_SMP_PLAYING;

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - set_volume                                                  ³
//                                                                          ³
// Set the playback volume                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
bach_err_codes BachSample::set_volume (long vol)
{
    assert (pdsb);

    // Convert the volume to the 127 == full volume, 0 == no volume range
    if (vol < 0)
        vol = 0;
    else if (vol > 127)
        vol = 127;

    // Now, use the db_table to make this number into an attenuation value.
    pdsb->SetVolume (-db_table[(db_table_size - 1) - vol]);

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - get_volume                                                  ³
//                                                                          ³
// Get the playback volume                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
long BachSample::get_volume ()
{
    long res;

    pdsb->GetVolume (&res);

    return db_table_find (10000 + res);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - set_pan                                                     ³
//                                                                          ³
// Set the pan position, with -127 being hard left, and 127 being hard rt.  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
bach_err_codes BachSample::set_pan (long heading)
{
    // Ensure that the direction is the in -179..180 range
    while (heading > 180)
        heading -= 360;
    while (heading < -179)
        heading += 360;

    // Since we are only stereo, wrap the heading into the forward field.
    if (heading > 90)
        heading = 180 - heading;
    else if (heading < -90)
        heading = -(180 + heading);

    // Now, scale the number into DirectSound's range
    long pan = heading * (db_table_size-1) / 90;

    // Set the pan appropriately
    if (pan < 0)
        pdsb->SetPan (-db_table[-pan]);

    else if (pan > 0)
        pdsb->SetPan (db_table[pan]);

    else
        pdsb->SetPan (0);

    return BACH_ERR_NONE;
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - get_pan                                                     ³
//                                                                          ³
// Get the pan position, -127 == hard left, and 127 == hard right           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
long BachSample::get_pan ()
{
    long pan;

    pdsb->GetPan (&pan);

    if (pan < 0)
        return -db_table_find (-pan);

    else if (pan > 0)
        return db_table_find (pan);

    else
        return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - set_playrate                                                ³
//                                                                          ³
// Sets the rate of sample playback (affects the pitch/duration)            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
bach_err_codes BachSample::set_playrate (ulong playrate)
{
    assert (pdsb);

    if (playrate == 0)
        playrate;   // resets the play frequency

    else if (playrate < 100)
        playrate = 100;

    else if (playrate > 100000)
        playrate = 100000;

    pdsb->SetFrequency (playrate);

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - get_flags                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
dword BachSample::get_flags ()
{
    // If we actuall have a buffer, better check our flags with it
    if (pdsb)
    {
        // Update the flags with the most current information
        DWORD status;
        pdsb->GetStatus (&status);

        // So far, only the PLAYING status needs constant attention
        if (status & (DSBSTATUS_PLAYING | DSBSTATUS_LOOPING))
            flags |= BACH_SMP_PLAYING;
        else
            flags &= ~BACH_SMP_PLAYING;
    }

    return flags;
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - get_playtime                                                ³
//                                                                          ³
// Calculate the time to play the complete sample, in milliseconds.         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
dword BachSample::get_playtime () const
{
    if (rate != 0)
    {
        ulong sample_count = 0;

        switch (fmt)
        {
        case BACH_DIGI_MONO_8:
            sample_count = length;
            break;

        case BACH_DIGI_MONO_16:
        case BACH_DIGI_STEREO_8:
            sample_count = length / 2;
            break;

        case BACH_DIGI_STEREO_16:
            sample_count = length / 4;
            break;

        default:
            // This assert will fail and give a clue to the reason.
            assert (fmt == BACH_DIGI_MONO_8
                    || fmt == BACH_DIGI_MONO_16
                    || fmt == BACH_DIGI_STEREO_8
                    || fmt == BACH_DIGI_STEREO_16);
            break;
        }

        return sample_count * 1000 / rate;
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachSample - load                                                        ³
//                                                                          ³
// Loads a sample from disk.  Currently only supports WAV.                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
bach_err_codes BachSample::load (const char *fname)
{
    XFParseIFF  iff(XF_IFF_RIFF);

    if (iff.open (fname, XF_OPEN_READ) != 0)
        return BACH_ERR_FILENOTFOUND;

    if (iff.seekform (iff.makeid ('W','A','V','E')) != 0)
        return BACH_ERR_UNSUPPORTEDFORMAT;

    return load (&iff);
}


bach_err_codes BachSample::load (XFParseIFF *iff)
{
    DSBUFFERDESC    bd;
    WAVEFORMATEX    wfmt;

    // Find and load the WAVE form
    if ( iff->chunkid != iff->makeid('R','I','F','F') != 0
         || iff->formid != iff->makeid('W','A','V','E')  != 0
         || iff->enterform() != 0)
        return BACH_ERR_UNSUPPORTEDFORMAT;

    // Find the header chunk
    if (  iff->seekchunk (iff->makeid ('f','m','t',' ')) != 0
       || iff->chunkSize != sizeof (PCMWAVEFORMAT)
       || iff->read (&wfmt) != 0
       || wfmt.wFormatTag != WAVE_FORMAT_PCM)
    {
        iff->leaveform();
        return BACH_ERR_UNSUPPORTEDFORMAT;
    }

    // Find the sample data
    if (iff->seekchunk (iff->makeid ('d','a','t','a')) == 0)
    {
        // Record the length of this chunk
        length = iff->chunkSize;

        // Clean up the old buffer, where applicable
        if (pdsb)
            pdsb->Release();

        if (dsbHandle)
            ivory_hfree (&dsbHandle);

        // Allocate a handle to hold the data
        dsbHandle = ivory_halloc (length);
        if (dsbHandle == 0)
            return BACH_ERR_OUTOFMEMORY;

        // Create a new DSound buffer and read the data into it
        memset (&bd, 0, sizeof (DSBUFFERDESC));
        bd.dwSize       = sizeof (DSBUFFERDESC);
        bd.dwFlags      = DSBCAPS_CTRLALL | DSBCAPS_STATIC;
        bd.dwBufferBytes= length;
        bd.lpwfxFormat  = &wfmt;

        if (dSound->CreateSoundBuffer (&bd, &pdsb, NULL) != DS_OK)
        {
            iff->leaveform();
            ivory_hfree (&dsbHandle);

            return BACH_ERR_DSCHACREATFAIL;
        }

        // Read the data into the local buffer (error checking, anyone?)
        void *pdata = ivory_hlock (dsbHandle);
        iff->read (pdata);

        // Copy the data into the buffer
        DWORD   dwLen;
        void    *pbdata;

        if (pdsb->Lock (0, length,
                        &pbdata, &dwLen,
                        NULL, 0,    // No wrap-around, so we don't need the extra pointer
                        0) != DS_OK)
        {
            iff->leaveform();
            ivory_hunlock (dsbHandle);
            ivory_hfree (&dsbHandle);

            return BACH_ERR_OUTOFMEMORY;
        }

        memcpy (pbdata, pdata, dwLen);

        pdsb->Unlock (pbdata, dwLen, NULL, 0);
        ivory_hunlock (dsbHandle);

        // Extract some format information
        rate = wfmt.nSamplesPerSec;
        if (wfmt.wBitsPerSample == 8)
            fmt = (wfmt.nChannels == 1) ? BACH_DIGI_MONO_8: BACH_DIGI_STEREO_8;
        else
            fmt = (wfmt.nChannels == 1) ? BACH_DIGI_MONO_16: BACH_DIGI_STEREO_16;
    }

    iff->leaveform();

    flags |= BACH_SMP_OWNSDATA;

    return BACH_ERR_NONE;
}


#if 0

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//±±±±±±±±±±±±±±±±±±±±±±±±  BachStreamSample  ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachStreamSample - constructor                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BachStreamSample::BachStreamSample (const class BachDigital &bd, int _buf_len):
    BachStreamSample (bd),
    xf (0),
    buf_len (_buf_len)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachStreamSample - release                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void BachStreamSample::release ()
{
    if (xf)
    {
        xf->close();
        delete xf;
        xf = 0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachStreamSample - load                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
bach_err_codes BachStreamSample::load (XFParseIFF *iff)
{
    DSBUFFERDESC    bd;
    WAVEFORMATEX    wfmt;

    // Find and load the WAVE form
    if ( iff->chunkid != iff->makeid('R','I','F','F') != 0
         || iff->formid != iff->makeid('W','A','V','E')  != 0
         || iff->enterform() != 0)
        return BACH_ERR_UNSUPPORTEDFORMAT;

    // Find the header chunk
    if (  iff->seekchunk (iff->makeid ('f','m','t',' ')) != 0
       || iff->chunkSize != sizeof (PCMWAVEFORMAT)
       || iff->read (&wfmt) != 0
       || wfmt.wFormatTag != WAVE_FORMAT_PCM)
    {
        iff->leaveform();
        return BACH_ERR_UNSUPPORTEDFORMAT;
    }

    // Find the sample data
    if (iff->seekchunk (iff->makeid ('d','a','t','a')) == 0)
    {
        // Record the length of this chunk
        length = iff->chunkSize;

        // Create a file pointer that points to this chunk's data
        xf = new XFileDisk ();
        xf->open (iff->xf->getname, XF_OPEN_READ);

        // Clean up the old buffer, where applicable
        if (pdsb)
            pdsb->Release();

        // Create a new DSound buffer (reading is deferred until play)
        memset (&bd, 0, sizeof (DSBUFFERDESC));
        bd.dwSize       = sizeof (DSBUFFERDESC);
        bd.dwFlags      = DSBCAPS_CTRLALL | DSBCAPS_STATIC;
        bd.dwBufferBytes= buf_len;
        bd.lpwfxFormat  = &wfmt;

        if (dSound->CreateSoundBuffer (&bd, &pdsb, NULL) != DS_OK)
        {
            iff->leaveform();
            return BACH_ERR_DSCHACREATFAIL;
        }

        // Extract some format information
        rate = wfmt.nSamplesPerSec;
        if (wfmt.wBitsPerSample == 8)
            fmt = (wfmt.nChannels == 1) ? BACH_DIGI_MONO_8: BACH_DIGI_STEREO_8;
        else
            fmt = (wfmt.nChannels == 1) ? BACH_DIGI_MONO_16: BACH_DIGI_STEREO_16;
    }

    iff->leaveform();

    flags |= BACH_SMP_OWNSDATA;

    return BACH_ERR_NONE;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachStreamSample - play                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
bach_err_codes BachStreamSample::play (BOOL loop)
{
    // Load the first part of the wave
    // Set up the buffer and the timer
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// BachStreamSample - stop                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
bach_err_codes BachStreamSample::stop ()
{
}
#endif

//°±² End of module - bachsamp.cpp ²±°
