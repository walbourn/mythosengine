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
// bachsfil.cpp
//
// Bach file sample implementation which streams .WAV and .RAW files
// during playback
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "bach.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define min(a,b)  (((a) < (b)) ? (a) : (b))

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// A handy utility class to make sure critical sections are done right      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class section_lock
{
    CRITICAL_SECTION    *psect;

public:
    section_lock (CRITICAL_SECTION *ps): psect (ps)
    { EnterCriticalSection (psect); }

    ~section_lock ()
    { LeaveCriticalSection (psect); }
};

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachFileSample - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BachFileSample::BachFileSample (BachDigital *digi, ulong bsize):
    BachSample(digi),
    sbuffer_next (0),
    thread_handle (0),
    buffer_size (bsize),
    xfile (0),
    xfile_next (0)
{
    assertMyth("BachFileSample needs valid buffer size",
               bsize > 0);

    for(int i=0; i < MAX; i++)
    {
        thread_event[i] = 0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachFileSample - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BachFileSample::~BachFileSample ()
{
    release();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachFileSample - release
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void BachFileSample::release()
{
    if (thread_handle)
        EnterCriticalSection (&critical_section);

    if (sbuffer_next)
    {
        sbuffer_next->Release();
        sbuffer_next = 0;
    }

    if (flags & BACH_SMP_OWNSDATA)
    {
        if (xfile)
        {
            xfile->close();
            delete xfile;
        }
        if (xfile_next)
        {
            xfile_next->close();
            delete xfile_next;
        }
    }
    xfile = 0;
    xfile_next = 0;
    flags &= ~BACH_SMP_OWNSDATA;

    if (thread_handle)
    {
        TerminateThread(thread_handle, 0);
        WaitForSingleObject (thread_handle, INFINITE);
        CloseHandle (thread_handle);
        thread_handle = 0;
        LeaveCriticalSection (&critical_section);
        DeleteCriticalSection (&critical_section);
    }

    for(int i=0; i < MAX; i++)
    {
        if (thread_event[i])
        {
            CloseHandle (thread_event[i]);
            thread_event[i] = 0;
        }
    }

    BachSample::release();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachFileSample - play
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachFileSample::play (int loop)
{
    if (!thread_handle)
        return BACH_ERR_UNINITIALIZED;

    section_lock lock (&critical_section);

    if (!xfile)
    {
        if (xfile_next)
        {
            xfile = xfile_next;
            xfile_next = 0;

            playrate = playrate_next;
            start = start_next;
            offset = 0;
            length = length_next;

            if (sbuffer_next)
            {
                assert(sbuffer_next != sbuffer);

                if (sbuffer)
                {
                    sbuffer->Stop();
                    sbuffer->Release();
                }

                sbuffer = sbuffer_next;
                sbuffer_next = 0;

                fmt = fmt_next;
                rate = rate_next;
            }
        }
        else
             return BACH_ERR_NOTFOUND;
    }

    xfile->seek_set(start);
    offset = 0;

    if (loop)
        flags |= BACH_SMP_LOOP;
    else
        flags &= ~BACH_SMP_LOOP;

    assertMyth("BachFileSample::play needs sbuffer", sbuffer != 0);

//ÄÄÄ Startup playback
    ResumeThread (thread_handle);
    SetEvent (thread_event[START]);

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachFileSample - stop
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachFileSample::stop ()
{
    if (!thread_handle)
        return BACH_ERR_UNINITIALIZED;

    section_lock lock (&critical_section);

//ÄÄÄ Kill any pending file
    if (flags & BACH_SMP_OWNSDATA)
    {
        if (xfile_next)
        {
            xfile_next->close();
            delete xfile_next;
        }
    }
    xfile_next = 0;

    if (sbuffer_next)
    {
        sbuffer_next->Release();
        sbuffer_next = 0;
    }

//ÄÄÄ Tell thread to stop current
    SetEvent (thread_event[STOP]);

    flags &= ~BACH_SMP_LOOP;

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachFileSample - pause
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachFileSample::pause()
{
    if (!thread_handle)
        return BACH_ERR_UNINITIALIZED;

    return BACH_ERR_NOTSUPPORTED;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachFileSample - resume
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachFileSample::resume()
{
    if (!thread_handle)
        return BACH_ERR_UNINITIALIZED;

    return BACH_ERR_NOTSUPPORTED;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachFileSample - status
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
dword BachFileSample::status() const
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

        if (flags & BACH_SMP_LOOP)
            status |= BACH_SMPSTAT_LOOPING;
    }

    return status;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachFileSample - init
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachFileSample::init()
{
    if (thread_handle)
        return BACH_ERR_NONE;

    DWORD thread_id;
    thread_handle = CreateThread (NULL, 0, thread_proc, (LPVOID)this,
                                  CREATE_SUSPENDED, &thread_id);
    if (!thread_handle)
        return BACH_ERR_THREADFAILED;

    thread_event[START] = CreateEvent(NULL, FALSE, FALSE, NULL);
    thread_event[STOP] = CreateEvent(NULL, FALSE, FALSE, NULL);

    if (!thread_event[START]
        || !thread_event[STOP])
    {
        TerminateThread(thread_handle, 0);
        thread_handle = 0;

        for(int i=0; i < MAX; i++)
        {
            if (thread_event[i])
            {
                CloseHandle(thread_event[i]);
                thread_event[i] = 0;
            }
        }
        return BACH_ERR_EVENTFAILED;
    }

    InitializeCriticalSection (&critical_section);

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachFileSample - ready_raw
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachFileSample::ready_raw (const char *fname,
                                          bach_digi_fmt f, ulong r)
{
    if (!fname)
        return BACH_ERR_INVALIDPARAMS;

    if (!thread_handle)
    {
        bach_err_codes err = init();
        if (err)
            return err;
    }

    if (xfile_next)
        return BACH_ERR_BUSY;

//ÄÄÄ Open file
    XFile *xf = new XFileDisk;
    if (!xf)
        return BACH_ERR_OUTOFMEMORY;

    if (xf->open (fname, XF_OPEN_DENYWRITE | XF_OPEN_READ) != XF_ERR_NONE)
    {
        delete xf;
        return BACH_ERR_FILENOTFOUND;
    }

//ÄÄÄ Ready wave file
    bach_err_codes err = ready_raw(xf,f,r,0,1);

    if (err)
        delete xf;

    return err;
}

bach_err_codes BachFileSample::ready_raw (XFile *xf, bach_digi_fmt f, ulong r,
                                          ulong l, int owns)
{
    if (!xf)
        return BACH_ERR_INVALIDPARAMS;

    if (!thread_handle)
    {
        bach_err_codes err = init();
        if (err)
            return err;
    }

    if (xfile_next)
        return BACH_ERR_BUSY;

    section_lock lock (&critical_section);

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
            return BACH_ERR_NOTSUPPORTED;
    }

    wfmt.wFormatTag      = WAVE_FORMAT_PCM;
    wfmt.nSamplesPerSec  = r;
    wfmt.cbSize			 = 0;
	wfmt.nAvgBytesPerSec = r * wfmt.nBlockAlign;

//ÄÄÄ Try to create sound buffer if we need one
    if (!sbuffer
        || (rate != r)
        || (fmt != f))
    {
        if (sbuffer_next)
        {
            sbuffer_next->Release();
            sbuffer_next = 0;
        }

        DSBUFFERDESC bd;
        memset (&bd, 0, sizeof (DSBUFFERDESC));

        bd.dwSize = sizeof (DSBUFFERDESC);
        bd.dwFlags = DSBCAPS_CTRLDEFAULT;
        bd.dwBufferBytes = buffer_size;
        bd.lpwfxFormat = &wfmt;

        if (dsound->CreateSoundBuffer (&bd, &sbuffer_next, NULL) != DS_OK)
        {
            return BACH_ERR_DSSECCREATFAIL;
        }

        assertMyth("BachFileSample::ready_wav needs valid sbuffer",
                   sbuffer_next != 0);

        rate_next = r;
        fmt_next = f;
    }

//ÄÄÄ We are grabbing the xfile instance to use in our thread
    start_next = xf->tell();
    length_next = (l) ? l : (xf->getsize() - start_next + 1);
    xfile_next = xf;

    if (owns)
        flags |= BACH_SMP_OWNSDATA;

    flags &= ~BACH_SMP_OVERRUN;

    // Record relevant data about this sample data
    // (In this implementation, leave the file w/data ready to read)

    playrate_next = wfmt.nAvgBytesPerSec;

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachFileSample - ready_wav
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachFileSample::ready_wav (const char *fname)
{
    if (!fname)
        return BACH_ERR_INVALIDPARAMS;

    if (!thread_handle)
    {
        bach_err_codes err = init();
        if (err)
            return err;
    }

    if (xfile_next)
        return BACH_ERR_BUSY;

//ÄÄÄ Open file
    XFile *xf = new XFileDisk;
    if (!xf)
        return BACH_ERR_OUTOFMEMORY;

    if (xf->open (fname, XF_OPEN_DENYWRITE | XF_OPEN_READ) != XF_ERR_NONE)
    {
        delete xf;
        return BACH_ERR_FILENOTFOUND;
    }

    XFParseIFF iff (xf, XF_IFF_RIFF);
    if (iff.begin() != XF_ERR_NONE)
    {
        delete xf;
        return BACH_ERR_FILEERROR;
    }

    if (iff.seekform (iff.makeid ('W','A','V','E')) != XF_ERR_NONE)
    {
        iff.attach (0);
        delete xf;
        return BACH_ERR_NOTFOUND;
    }

//ÄÄÄ Ready wave file
    bach_err_codes err = ready_wav(xf,&iff,1);

    iff.attach (0);

    if (err)
        delete xf;

    return err;
}

bach_err_codes BachFileSample::ready_wav (XFile *xf, XFParseIFF *iff,
                                          int owns)
{
    if (!iff)
        return BACH_ERR_INVALIDPARAMS;

    if (!thread_handle)
    {
        bach_err_codes err = init();
        if (err)
            return err;
    }

    if (xfile_next)
        return BACH_ERR_BUSY;

    section_lock lock (&critical_section);

//ÄÄÄ Verify this is correct form
    if ( iff->chunkid != iff->makeid('R','I','F','F')
         || iff->formid != iff->makeid('W','A','V','E') )
        return BACH_ERR_NOTFOUND;

    if (iff->enterform() != XF_ERR_NONE)
        return BACH_ERR_FILEERROR;

//ÄÄÄ Find and read header
    WAVEFORMATEX    wfmt;
    memset(&wfmt,0,sizeof(wfmt));

    if ( iff->seekchunk (iff->makeid ('f','m','t',' ')) != XF_ERR_NONE
         || iff->chunkSize != sizeof (PCMWAVEFORMAT)
         || iff->read (&wfmt) != 0)
    {
        iff->leaveform();
        return BACH_ERR_FILEERROR;
    }

    if (wfmt.wFormatTag != WAVE_FORMAT_PCM
        || (wfmt.wBitsPerSample != 8
            && wfmt.wBitsPerSample != 16)
        || (wfmt.nChannels != 1
            && wfmt.nChannels != 2))
    {
        iff->leaveform();
        return BACH_ERR_NOTSUPPORTED;
    }

//ÄÄÄ Find sample data
    if (iff->seekchunk (iff->makeid ('d','a','t','a')) != XF_ERR_NONE)
    {
        iff->leaveform();
        return BACH_ERR_FILEERROR;
    }

//ÄÄÄ Try to create sound buffer if we need one
    if (!sbuffer
        || (rate != wfmt.nSamplesPerSec)
        || (fmt == BACH_DIGI_MONO_8 && (wfmt.wBitsPerSample != 8
                                        || wfmt.nChannels != 1))
        || (fmt == BACH_DIGI_MONO_16 && (wfmt.wBitsPerSample != 16
                                         || wfmt.nChannels != 1))
        || (fmt == BACH_DIGI_STEREO_8 && (wfmt.wBitsPerSample != 8
                                          || wfmt.nChannels != 2))
        || (fmt == BACH_DIGI_STEREO_16 && (wfmt.wBitsPerSample != 16
                                           || wfmt.nChannels != 2)) )
    {
        if (sbuffer_next)
        {
            sbuffer_next->Release();
            sbuffer_next = 0;
        }

        DSBUFFERDESC bd;
        memset (&bd, 0, sizeof (DSBUFFERDESC));

        bd.dwSize = sizeof (DSBUFFERDESC);
        bd.dwFlags = DSBCAPS_CTRLDEFAULT;
        bd.dwBufferBytes = buffer_size;
        bd.lpwfxFormat = &wfmt;

        if (dsound->CreateSoundBuffer (&bd, &sbuffer_next, NULL) != DS_OK)
        {
            iff->leaveform();
            return BACH_ERR_DSSECCREATFAIL;
        }

        assertMyth("BachFileSample::ready_wav needs valid sbuffer",
                   sbuffer_next != 0);

        rate_next = wfmt.nSamplesPerSec;
        if (wfmt.nChannels == 2)
        {
            fmt_next = (wfmt.wBitsPerSample == 16) ? BACH_DIGI_STEREO_16
                                                   : BACH_DIGI_STEREO_8;
        }
        else
        {
            fmt_next = (wfmt.wBitsPerSample == 16) ? BACH_DIGI_MONO_16
                                                   : BACH_DIGI_MONO_8;
        }
    }

//ÄÄÄ We are grabbing the xfile instance to use in our thread
    start_next = xf->tell();
    length_next = iff->chunkSize;

    xfile_next = xf;
    iff->attach (0);

    if (owns)
        flags |= BACH_SMP_OWNSDATA;

    flags &= ~BACH_SMP_OVERRUN;

    // Record relevant data about this sample data
    // (In this implementation, leave the file w/data ready to read)

    playrate_next = wfmt.nAvgBytesPerSec;

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachFileSample - next
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachFileSample::next ()
{
    if (!thread_handle)
        return BACH_ERR_UNINITIALIZED;

    section_lock lock (&critical_section);

    if (xfile_next)
    {
        if (xfile
            && (flags & BACH_SMP_OWNSDATA))
        {
            xfile->close();
            delete xfile;
        }
        xfile = xfile_next;
        xfile_next = 0;

        playrate = playrate_next;
        start = start_next;
        offset = 0;
        length = length_next;

        if (sbuffer_next)
        {
            assert(sbuffer_next != sbuffer);

            if (sbuffer)
            {
                sbuffer->Stop();
                sbuffer->Release();
            }

            sbuffer = sbuffer_next;
            sbuffer_next = 0;

            fmt = fmt_next;
            rate = rate_next;
        }

        ResumeThread (thread_handle);
        SetEvent (thread_event[START]);
    }
    else
    {
        SetEvent (thread_event[STOP]);
    }

    // Callback function to application?

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                            °° Protected °°
// BachFileSampe - thread_proc
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
DWORD WINAPI BachFileSample::thread_proc (LPVOID lpUser)
{
    BachFileSample *that = (BachFileSample*)lpUser;

    assertMyth("BachFileSample::thread_proc needs valid lpUser",
               lpUser != 0);

    DWORD           res, pos;
    DWORD           size1, size2, size, tsize;
    LPBYTE          ptr1, ptr2;
    BOOL            first_half;
    DWORD           sleep_time=INFINITE;

    for(;;)
    {
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Wait for event or timeout
        res = WaitForMultipleObjects (MAX, that->thread_event, FALSE,
                                      sleep_time);

        switch (res)
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Start Event
            case WAIT_OBJECT_0+START:
                EnterCriticalSection (&that->critical_section);

                assertMyth("BachFileSample::thread_proc START event needs xfile",
                           that->xfile != 0);

                assertMyth("BachFileSample::thread_proc START event needs sbuffer",
                           that->sbuffer != 0);

                //ÄÄÄ Reset playback buffer
                that->sbuffer->Stop();

                res=that->sbuffer->SetCurrentPosition(0);
                assertMyth("BachFileSample::thread_proc START event DS set failed",
                           res == DS_OK);

                //ÄÄÄ Lock entire buffer
                size1=0;
                ptr1=0;
                for(;;)
                {
                    res = that->sbuffer->Lock(0, 0, (void**)&ptr1, &size1,
                                                0, 0, DSBLOCK_ENTIREBUFFER);
                    if (res == DSERR_BUFFERLOST)
                    {
                        res = that->sbuffer->Restore();

                        assertMyth("BachFileSample::thread_proc failed DS Restore",
                                   res == DS_OK);
                    }
                    else
                    {
                        assertMyth("BachFileSample::thread_proc failed DS Lock",
                                   res == DS_OK);
                        break;
                    }
                }
                assert(ptr1 != 0 && that->buffer_size == size1);

                //ÄÄÄ Read data bytes into buffer
                tsize = min(size1,that->length - that->offset + 1);

                size = that->xfile->read (ptr1, tsize);
                if ((size < tsize) || (tsize < size1))
                {
                    if (that->xfile_next || !(that->flags & BACH_SMP_LOOP))
                    {
                        if (that->flags & BACH_SMP_OWNSDATA)
                        {
                            that->xfile->close();
                            delete that->xfile;
                        }
                        that->xfile=0;
                    }
                    else
                    {
                        that->xfile->seek_set(that->start);
                        that->offset = 0;
                    }

                    if (size < size1)
                    {
                        memset (ptr1 + size, (that->fmt == BACH_DIGI_MONO_16
                                              || that->fmt == BACH_DIGI_STEREO_16) 
                                             ? 0 : 127, size1 - size);
                    }
                }
                else
                {
                    that->offset += size;
                }

                //ÄÄÄ Unlock buffer
                res=that->sbuffer->Unlock(ptr1,size1,0,0);
                assertMyth("BachFileSample::thread_proc START event DS unlock failed",
                           res == DS_OK);

                //ÄÄÄ Start playback buffer
                res=that->sbuffer->Play(0, 0, DSBPLAY_LOOPING);
                assertMyth("BachFileSample::thread_proc START event DS play failed",
                           res == DS_OK);

                //ÄÄÄ Setup sleep time
                first_half = TRUE;
                sleep_time = ((that->buffer_size >> 1) * 1000) / that->playrate;
                LeaveCriticalSection (&that->critical_section);
                break;
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Stop Event
            case WAIT_OBJECT_0+STOP:
                EnterCriticalSection (&that->critical_section);

                //ÄÄÄ Free current file
                if (that->xfile)
                {
                    if (that->flags & BACH_SMP_OWNSDATA)
                    {
                        that->xfile->close();
                        delete that->xfile;
                    }
                    that->xfile=0;
                }

                //ÄÄÄ Free current playback buffer
                if (that->sbuffer)
                {
                    assert(that->xfile_next == 0);

                    that->sbuffer->Stop();
                    that->sbuffer->Release();
                    that->sbuffer = 0;
                }

                //ÄÄÄ Setup for suspend
                sleep_time=INFINITE;
                LeaveCriticalSection (&that->critical_section);
                SuspendThread(GetCurrentThread());
                break;
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Timeout
            case WAIT_TIMEOUT:
                EnterCriticalSection (&that->critical_section);

                //ÄÄÄ Verify correct buffer playback position
                res=that->sbuffer->GetCurrentPosition(&pos,NULL);
                assertMyth("BachFileSample::thread_proc DS get failed",
                           res == DS_OK);

                if (first_half)
                {
                    if (pos < (that->buffer_size >> 1))
                    {
                        Sleep((((that->buffer_size >> 1) - pos) * 1000)
                                                           / that->playrate);
                    }
                }
                else
                {
                    if (pos >= (that->buffer_size >> 1))
                    {
                        Sleep(((that->buffer_size - pos) * 1000)
                                                           / that->playrate);
                    }
                }

                //ÄÄÄ Handle no more file
                if (!that->xfile)
                {
                    LeaveCriticalSection (&that->critical_section);
                    if (that->sbuffer)
                        that->sbuffer->Stop();
                    that->next();
                    break;
                }

                //ÄÄÄ Lock half of buffer
                size1=size2=0;
                ptr1=ptr2=0;
                for(;;)
                {
                    res = that->sbuffer->Lock((first_half)
                                                ? 0 : (that->buffer_size >> 1),
                                                that->buffer_size >> 1,
                                                (void**)&ptr1, &size1,
                                                (void**)&ptr2, &size2, 0);
                    if (res == DSERR_BUFFERLOST)
                    {
                        res = that->sbuffer->Restore();

                        assertMyth("BachFileSample::thread_proc failed DS Restore",
                                    res == DS_OK);
                    }
                    else
                    {
                        assertMyth("BachFileSample::thread_proc failed DS Lock",
                                    res == DS_OK);
                        break;
                    }
                }
                assert(ptr1 != 0);

                //ÄÄÄ Read first part of buffer
                tsize = min(size1,that->length - that->offset + 1);

                size = that->xfile->read (ptr1, tsize);
                if ((size < tsize) || (tsize < size1))
                {
                    if (that->xfile_next
                        || !(that->flags & BACH_SMP_LOOP))
                    {
                        if (that->flags & BACH_SMP_OWNSDATA)
                        {
                            that->xfile->close();
                            delete that->xfile;
                        }
                        that->xfile=0;
                    }
                    else
                    {
                        that->xfile->seek_set(that->start);
                        that->offset = 0;
                    }

                    if (size < size1)
                    {
                        memset (ptr1 + size, (that->fmt == BACH_DIGI_MONO_16
                                              || that->fmt == BACH_DIGI_STEREO_16) 
                                             ? 0 : 127, size1 - size);
                    }
                }
                else
                {
                    that->offset += size;
                }

                //ÄÄÄ Read second part of buffer
                if (ptr2)
                {
                    if (!that->xfile)
                    {
                        memset (ptr2, (that->fmt == BACH_DIGI_MONO_16
                                       || that->fmt == BACH_DIGI_STEREO_16) 
                                      ? 0 : 127, size2);
                    }
                    else
                    {
                        tsize = min(size2,that->length - that->offset + 1);

                        size = that->xfile->read (ptr2, tsize);
                        if ((size < tsize) || (tsize < size2))
                        {
                            if (that->xfile_next
                                || !(that->flags & BACH_SMP_LOOP))
                            {
                                if (that->flags & BACH_SMP_OWNSDATA)
                                {
                                    that->xfile->close();
                                    delete that->xfile;
                                }
                                that->xfile=0;
                            }
                            else
                            {
                                that->xfile->seek_set(that->start);
                                that->offset = 0;
                            }

                            if (size < size2)
                            {
                                memset (ptr2 + size, (that->fmt == BACH_DIGI_MONO_16
                                                      || that->fmt == BACH_DIGI_STEREO_16) 
                                                     ? 0 : 127, size2 - size);
                            }
                        }
                        else
                        {
                            that->offset += size;
                        }
                    }
                }

                //ÄÄÄ Unlock buffer
                res=that->sbuffer->Unlock(ptr1,size1,ptr2,size2);
                assertMyth("BachFileSample::thread_proc DS unlock failed",
                           res == DS_OK);

                //ÄÄÄ Setup sleep time
                res=that->sbuffer->GetCurrentPosition(&pos,NULL);
                assertMyth("BachFileSample::thread_proc DS get failed",
                           res == DS_OK);

                if (first_half)
                {
                    if (pos < (that->buffer_size >> 1))
                    {
                        //ÄÄÄ We are already playing data we just read...
                        sleep_time = 0;
                        that->flags |= BACH_SMP_OVERRUN;
                    }
                    else
                    {
                        sleep_time = ((that->buffer_size - pos) * 1000)
                                                            / that->playrate;
                    }
                }
                else
                {
                    if (pos >= (that->buffer_size >> 1))
                    {
                        //ÄÄÄ We are already playing data we just read...
                        sleep_time = 0;
                        that->flags |= BACH_SMP_OVERRUN;
                    }
                    else
                    {
                        sleep_time = (((that->buffer_size>>1) - pos) * 1000)
                                                            / that->playrate;
                    }
                }

                assertMyth("BachFileSample::threadProc computed invalid sleep",
                           (sleep_time >= 0)
                           && (sleep_time <= (((that->buffer_size >> 1) * 1000) / that->playrate)));

                //ÄÄÄ Setup for next half
                first_half = !first_half;
                LeaveCriticalSection (&that->critical_section);
                break;
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Unknown
            default:
                assertMyth("BachFileSample::thread_proc failed wait",0);
                break;
        }
    }

    return 0;
}

//°±² End of module - bachsfil.cpp ²±°
