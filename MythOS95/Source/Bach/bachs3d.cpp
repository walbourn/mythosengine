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
//                               Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                        http://www.mythos-engine.org/
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Dan Higdon & Chuck Walbourn
//
// bachs3d.cpp
//
// Bach 3D static sample implementation
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
// BachSample3D - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BachSample3D::BachSample3D(BachDigital3D *digi) :
    BachStaticSample(digi),
    listener(0),
    sbuffer3d(0)
{
    assertMyth("BachSample3D needs initialized BachDigital3D object",
               digi && digi->listener != 0);

    listener = digi->listener;
    if (listener)
        listener->AddRef();

    flags |= BACH_SMP_3D | BACH_SMP_3DMUTEATMAX;
}

BachSample3D::BachSample3D (BachSample3D const &b) :
    BachStaticSample(b),
    sbuffer3d(0)
{
    if (sbuffer
        && SUCCEEDED(sbuffer->QueryInterface(IID_IDirectSound3DBuffer,
                                             (LPVOID *)&sbuffer3d)))
    {
        assertMyth("BachSample3D::BachSample3D() failed to get 3d interface to buffer",
                   sbuffer3d != 0);

        DS3DBUFFER settings;
        b.get(settings);
        set(settings);
    }

    listener = b.listener;
    if (b.listener)
        listener->AddRef();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BachSample3D::~BachSample3D()
{
    release();

    if (listener)
    {
        listener->Release();
        listener=0;
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                            °° Protected °°
// BachSample3D - createbuffer
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachSample3D::createbuffer(WAVEFORMATEX *wfmt)
{
    if (!dsound)
        return BACH_ERR_UNINITIALIZED;

    if (!wfmt)
        return BACH_ERR_INVALIDPARAMS;

//ÄÄÄ Create sound buffer
    DSBUFFERDESC    bd;
    memset (&bd,0,sizeof (bd));

    bd.dwSize           = sizeof (DSBUFFERDESC);
    bd.dwFlags          = DSBCAPS_CTRL3D | DSBCAPS_STATIC;
    bd.dwBufferBytes    = length;
    bd.lpwfxFormat      = wfmt;

    if (flags & BACH_SMP_3DMUTEATMAX)
        bd.dwFlags |= DSBCAPS_MUTE3DATMAXDISTANCE;

    if (flags & BACH_SMP_3DVOLUMECTRL)
        bd.dwFlags |= DSBCAPS_CTRLVOLUME;

    if (flags & BACH_SMP_3DFREQCTRL)
        bd.dwFlags |= DSBCAPS_CTRLFREQUENCY;

    if (dsound->CreateSoundBuffer (&bd, &sbuffer, NULL) != DS_OK)
    {
        return BACH_ERR_DSSECCREATFAIL;
    }

    assertMyth("BachSample3D::createbuffer() failed to create sound buffer",
                sbuffer != 0);

//ÄÄÄ Query secondary interface
    if (FAILED(sbuffer->QueryInterface(IID_IDirectSound3DBuffer,
                                       (LPVOID *)&sbuffer3d)))
    {
        return BACH_ERR_DSFAILED;
    }

    assertMyth("BachSample3D::createbuffer() failed DSound 3D buffer interface query",
                sbuffer3d != 0);

//ÄÄÄ Set to known reference frame
    DS3DBUFFER  settings;
    memset(&settings,0,sizeof(settings));
    settings.dwInsideConeAngle = 90;
    settings.dwOutsideConeAngle = 120;
    settings.vConeOrientation.x = 0.0f;
    settings.vConeOrientation.y = 0.0f;
    settings.vConeOrientation.z = -1.0f;
    settings.flMinDistance = 1.0f;
    settings.flMaxDistance = 50.0f;
    settings.dwMode = DS3DMODE_NORMAL;

    bach_err_codes err = set(settings);
    if (err)
    {
        return err;
    }

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - operator =
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BachSample3D &BachSample3D::operator = (BachSample3D const &that)
{
    if (&that != this)
    {
        BachStaticSample::operator = (that);

        listener = that.listener;
        if (listener)
            listener->AddRef();

        if (sbuffer
            && SUCCEEDED(sbuffer->QueryInterface(IID_IDirectSound3DBuffer,
                                                 (LPVOID *)&sbuffer3d)))
        {
            assertMyth("BachSample3D::BachSample3D() failed to get 3d interface to buffer",
                       sbuffer3d != 0);

            DS3DBUFFER settings;
            that.get(settings);
            set(settings);
        }
    }

    return *this;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - release
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void BachSample3D::release ()
{
    if (sbuffer3d)
    {
        sbuffer3d->Release();
        sbuffer3d=0;
    }

    BachStaticSample::release();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - set
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachSample3D::set(DS3DBUFFER &settings, int recalc)
{
    if (!sbuffer3d)
        return BACH_ERR_UNINITIALIZED;

    settings.dwSize = sizeof(DS3DBUFFER);

    if (sbuffer3d->SetAllParameters(&settings, DS3D_DEFERRED) != DS_OK)
        return BACH_ERR_DSFAILED;

    if (recalc)
    {
        assertMyth("BachSample3D::set() needs valid listener", listener != 0);

        if (listener->CommitDeferredSettings() != DS_OK)
            return BACH_ERR_DSFAILED;
    }

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - set_mode
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachSample3D::set_mode(DWORD mode, int recalc)
{
    if (!sbuffer3d)
        return BACH_ERR_UNINITIALIZED;

    if (sbuffer3d->SetMode(mode, DS3D_DEFERRED) != DS_OK)
        return BACH_ERR_DSFAILED;

    if (recalc)
    {
        assertMyth("BachSample3D::set_mode() needs valid listener", listener != 0);

        if (listener->CommitDeferredSettings() != DS_OK)
            return BACH_ERR_DSFAILED;
    }

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - set_cone
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachSample3D::set_cone(ulong ia, ulong oa, int recalc)
{
    if (!sbuffer3d)
        return BACH_ERR_UNINITIALIZED;

    if (sbuffer3d->SetConeAngles(ia, oa, DS3D_DEFERRED) != DS_OK)
        return BACH_ERR_DSFAILED;

    if (recalc)
    {
        assertMyth("BachSample3D::set_cone() needs valid listener", listener != 0);

        if (listener->CommitDeferredSettings() != DS_OK)
            return BACH_ERR_DSFAILED;
    }

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - set_cone_orient
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachSample3D::set_cone_orient(float i, float j, float k, int recalc)
{
    if (!sbuffer3d)
        return BACH_ERR_UNINITIALIZED;

    if (sbuffer3d->SetConeOrientation(i, j, k, DS3D_DEFERRED) != DS_OK)
        return BACH_ERR_DSFAILED;

    if (recalc)
    {
        assertMyth("BachSample3D::set_cone_orient() needs valid listener", listener != 0);

        if (listener->CommitDeferredSettings() != DS_OK)
            return BACH_ERR_DSFAILED;
    }

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - set_cone_volume
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachSample3D::set_cone_volume(long vol, int recalc)
{
    if (!sbuffer3d)
        return BACH_ERR_UNINITIALIZED;

//ÄÄÄ Convert the volume to the 127 == full volume, 0 == no volume range
    if (vol < 0)
        vol = 0;
    else if (vol > 127)
        vol = 127;

    if (sbuffer3d->SetConeOutsideVolume(-db_table[(db_table_size - 1) - vol], DS3D_DEFERRED) != DS_OK)
        return BACH_ERR_DSFAILED;

    if (recalc)
    {
        assertMyth("BachSample3D::set_cone_volume() needs valid listener", listener != 0);

        if (listener->CommitDeferredSettings() != DS_OK)
            return BACH_ERR_DSFAILED;
    }

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - set_min_distance
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachSample3D::set_min_distance(float dist, int recalc)
{
    if (!sbuffer3d)
        return BACH_ERR_UNINITIALIZED;

    if (sbuffer3d->SetMinDistance(dist, DS3D_DEFERRED) != DS_OK)
        return BACH_ERR_DSFAILED;

    if (recalc)
    {
        assertMyth("BachSample3D::set_min_distance() needs valid listener", listener != 0);

        if (listener->CommitDeferredSettings() != DS_OK)
            return BACH_ERR_DSFAILED;
    }

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - set_max_distance
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachSample3D::set_max_distance(float dist, int recalc)
{
    if (!sbuffer3d)
        return BACH_ERR_UNINITIALIZED;

    if (sbuffer3d->SetMaxDistance(dist, DS3D_DEFERRED) != DS_OK)
        return BACH_ERR_DSFAILED;

    if (recalc)
    {
        assertMyth("BachSample3D::set_max_distance() needs valid listener", listener != 0);

        if (listener->CommitDeferredSettings() != DS_OK)
            return BACH_ERR_DSFAILED;
    }

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - set_position
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachSample3D::set_position(float x, float y, float z, int recalc)
{
    if (!sbuffer3d)
        return BACH_ERR_UNINITIALIZED;

    if (sbuffer3d->SetPosition(x, y, z, DS3D_DEFERRED) != DS_OK)
        return BACH_ERR_DSFAILED;

    if (recalc)
    {
        assertMyth("BachSample3D::set_position() needs valid listener", listener != 0);

        if (listener->CommitDeferredSettings() != DS_OK)
            return BACH_ERR_DSFAILED;
    }

    return BACH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - set_velocity
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
bach_err_codes BachSample3D::set_velocity(float i, float j, float k, int recalc)
{
    if (!sbuffer3d)
        return BACH_ERR_UNINITIALIZED;

    if (sbuffer3d->SetVelocity(i, j, k, DS3D_DEFERRED) != DS_OK)
        return BACH_ERR_DSFAILED;

    if (recalc)
    {
        assertMyth("BachSample3D::set_velocity() needs valid listener", listener != 0);

        if (listener->CommitDeferredSettings() != DS_OK)
            return BACH_ERR_DSFAILED;
    }

    return BACH_ERR_NONE;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - get
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void BachSample3D::get(DS3DBUFFER &settings) const
{
    if (!sbuffer3d)
        return;

    memset(&settings,0,sizeof(DS3DBUFFER));
    settings.dwSize = sizeof(DS3DBUFFER);

    sbuffer3d->GetAllParameters(&settings);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - get_mode
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
DWORD BachSample3D::get_mode() const
{
    if (!sbuffer3d)
        return 0;

    DWORD mode;

    if (sbuffer3d->GetMode(&mode) != DS_OK)
        return 0;

    return mode;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - get_cone
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void BachSample3D::get_cone(ulong &ia, ulong &oa) const
{
    if (!sbuffer3d)
        return;

    sbuffer3d->GetConeAngles(&ia,&oa);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - get_cone_orient
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void BachSample3D::get_cone_orient(float &i, float &j, float &k) const
{
    if (!sbuffer3d)
        return;

    D3DVECTOR   result;

    if (sbuffer3d->GetConeOrientation(&result) != DS_OK)
        return;

    i = result.x;
    j = result.y;
    k = result.z;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - get_cone_volume
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
long BachSample3D::get_cone_volume() const
{
    if (!sbuffer3d)
        return 0;

    long res;

    if (sbuffer3d->GetConeOutsideVolume(&res) != DS_OK)
        return 0;

    return db_table_find (10000 + res);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - get_min_distance
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
float BachSample3D::get_min_distance() const
{
    if (!sbuffer3d)
        return 0;

    float dist;

    if (sbuffer3d->GetMinDistance(&dist) != DS_OK)
        return 0;

    return dist;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - get_max_distance
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
float BachSample3D::get_max_distance() const
{
    if (!sbuffer3d)
        return 0;

    float dist;

    if (sbuffer3d->GetMaxDistance(&dist) != DS_OK)
        return 0;

    return dist;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - get_position
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void BachSample3D::get_position(float &x, float &y, float &z) const
{
    if (!sbuffer3d)
        return;

    D3DVECTOR pos;

    if (sbuffer3d->GetPosition(&pos) != DS_OK)
        return;

    x = pos.x;
    y = pos.y;
    z = pos.z;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// BachSample3D - get_velocity
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void BachSample3D::get_velocity(float &i, float &j, float &k) const
{
    if (!sbuffer3d)
        return;

    D3DVECTOR vel;

    if (sbuffer3d->GetVelocity(&vel) != DS_OK)
        return;

    i = vel.x;
    j = vel.y;
    k = vel.z;
}

//°±² End of module - bachs3d.cpp ²±°
