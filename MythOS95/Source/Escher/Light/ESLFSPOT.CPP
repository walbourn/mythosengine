//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùù°°°°°°°°°°ù°°°°°°°°ùùù°°°°°°°°ùù°°°ùùùù°°°ù°°°°°°°°°°ù°°°°°°°°°ùù
//ùùùùùùùùù°±°ùùùùùùù°±°ùùùù°±°ù°±°ùùùù°±°ù°±°ùùùù°±°ù°±°ùùùùùùùù°±°ùùùù°±°ùù
//ùùùùùùùù±°±ùùùùùùù±°±ùùùùùùùù±°±ùùùùùùùù±°±ùùùù±°±ù±°±ùùùùùùùù±°±ùùùù±°±ùùù
//ùùùùùùù±²±±°±±²ùù±²±±°±±²±±ù±²±ùùùùùùùù±²±±°±±²±±ù±²±±°±±²ùùù±²±±°±±²°ùùùùù
//ùùùùùù±²±ùùùùùùùùùùùùùù±²±ù±²±ùùùùùùùù±²±ùùùù±²±ù±²±ùùùùùùùù±²±ùùùù±²±ùùùùù
//ùùùùù²±²ùùùùùùù²±²ùùùù²±²ù²±²ùùùù²±²ù²±²ùùùù²±²ù²±²ùùùùùùùù²±²ùùùù²±²ùùùùùù
//ùùùù²²²²²²²²²²ù²²²²²²²²ùùù²²²²²²²²ùù²²²ùùùù²²²ù²²²²²²²²²²ù²²²ùùùù²²²ùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùCopyrightù(c)ù1994-1997ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùAllùRightsùReserved.ùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùù Microsoft Windows '95 Version ùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
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
// Created by Tim Little & Chuck Walbourn
//
// eslfspot.cpp
//
// The EschLight and associated classes are used for implementing the
// lighting model.  EschLights affect objects by controlling the
// shade level and potentially color of a vertex.  EschLight objects
// are maintained in a linked list.
//
// An EschFastSpotLight is an approximation of point sources in
// 3-space using the target frame-reference to form a 'local' vector source
// with intensity attenuated by fall-off from a direction vector and
// distance.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"
#include "esfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define max(a,b)  (((a) > (b)) ? (a) : (b))

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFastSpotLight - Constructor                                          ³
//                                                                          ³
// Initializes the light object with full intesity and sets type.           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschFastSpotLight::EschFastSpotLight(const char *fname, const char *lname) :
    EschFastAttenLight(),
    dir(0.0,0.0,1.0),
    hotspot(44.0),
    falloff(45.0)
{
    ltyp = ESCH_LGTT_FSPOT;

    if (fname)
    {
        load(fname,lname);
    }
};

EschFastSpotLight::EschFastSpotLight(const EschPoint *pnt,
                                     const EschVector *d,
                                     float h, float f, float i, float o) :
    EschFastAttenLight(pnt,i,o),
    dir(*d),
    hotspot(h),
    falloff(f)
{
    ltyp = ESCH_LGTT_FSPOT;
};

EschFastSpotLight::EschFastSpotLight(float ix, float iy, float iz,
                                     float ii, float ij, float ik,
                                     float h, float f, float i, float o) : 
    EschFastAttenLight(ix,iy,iz,i,o),
    dir(ii,ij,ik),
    hotspot(h),
    falloff(f)
{
    ltyp = ESCH_LGTT_FSPOT;
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFastSpotLight - setup                                                ³
//                                                                          ³
// Performs the setup of the light on an object by object basis.            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFastSpotLight::setup(const EschFrameRef *fr)
{
    EschVector  ldir;

    if (fr)
    {
        EschPoint   tpnt;

        if (EschCurrent
            && EschCurrent->camera
            && EschCurrent->camera->flags & ESCH_CAM_MODELSPACE)
        {
            pos.transform(&fr->iorient,&tpnt);
            dir.transform(&fr->iorient,&ldir);
            ldir = -ldir;

            tdir.i = tpnt.x;
            tdir.j = tpnt.y;
            tdir.k = tpnt.z;
        }
        else
        {
            fr->get_position(&tpnt);
            tdir.i = pos.x - tpnt.x;
            tdir.j = pos.y - tpnt.y;
            tdir.k = pos.z - tpnt.z;

            ldir = -dir;
        }
    }
    else
    {
        // If there is no reference, we assume the object is at 0,0,0
        // since we have no other valid interpretation

        tdir.i = pos.x;
        tdir.j = pos.y;
        tdir.k = pos.z;

        ldir = -dir;
    }

    EschLight::setup(fr);

    float mag = tdir.magnitude();
    if (mag >= outer)
    {
        _intensity = 0;
        _hintensity = 0;
    }
    else
    {
        // Complete normalization
        if (mag > 0)
        {
            tdir.i /= mag;
            tdir.j /= mag;
            tdir.k /= mag;
        }

        // Use dot product with light to determine fall-off
        float dotcone = tdir DOT ldir;

        // Check to see if we are inside fall-off cone
        float fallcos = esch_cos(falloff);

        if (dotcone <= fallcos)
        {
            _intensity = 0;
            _hintensity = 0;
        }
        else
        {
            float orig_inten = _intensity;
            float orig_hinten = _hintensity;

            // Compute intensity output (including attenuation)
            float hotcos = esch_cos(hotspot);

            if (dotcone < hotcos)
            {
                _intensity -= ((hotcos - dotcone) * orig_inten)
                                            / (hotcos - fallcos);
                _hintensity -= ((hotcos - dotcone) * orig_hinten)
                                            / (hotcos - fallcos);
            }

            if ((flags & ESCH_LGT_ATTEN)
                && (outer-inner) > 0
                && (mag > inner))
            {
                _intensity -= ((mag - inner) * orig_inten) / (outer - inner);
                _hintensity -= ((mag - inner) * orig_hinten) / (outer - inner);
            }
        }
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  I/O Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFastSpotLight - load                                                 ³
//                                                                          ³
// Loads the position and other data of the fast spot light from an IFF     ³
// file.                                                                    ³
//                                                                          ³
// The IFF version assumes that the IFF is open and pointing at the proper  ³
// chunk.  If a 'lname' is given and the name doesn't match that in the     ³
// chunk, an error is returned.                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschFastSpotLight::load(const char *fname, const char *lname)
{
    esch_error_codes    err;
    XFParseIFF          iff;

//ÄÄ Open file
    if (iff.open(fname,XF_OPEN_READ | XF_OPEN_DENYWRITE))
        return ESCH_ERR_FILEERROR;

//ÄÄ Loop until a header with the correct name is found
    err=ESCH_ERR_NONE;

    for(;;)
    {
        if (iff.next() != XF_ERR_NONE)
        {
            if (!iff.depth)
                return ESCH_ERR_NOTFOUND;
            iff.leaveform();
            continue;
        }

        if (iff.chunkid == iff.makeid('E','F','S','P')
            || iff.chunkid == iff.makeid('E','F','S','1'))
        {
            err=load(&iff,lname);
            if (!err
                || err != ESCH_ERR_NOTFOUND)
                break;
        }

        // Must scan inside any ESEN Scene forms.
        else if (iff.chunkid == iff.makeid('F','O','R','M')
                 && iff.formid == iff.makeid('E','S','E','N'))
        {
            iff.enterform();
        }
    }

//ÄÄ Return ok
    iff.close();
    return err;
}

esch_error_codes EschFastSpotLight::load(XFParseIFF *iff, const char *lname)
{
    assertMyth("EschFastSpotLight::load requries iff pointer",
               iff);

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Floating-point format
    if (iff->chunkid == iff->makeid('E','F','S','1'))
    {
        EschFileLightSpot fspot;

        if (iff->chunkSize != sizeof(fspot))
            return ESCH_ERR_INVALIDDATA;

        //ÄÄ Read chunk and verify name, if given.
        if (iff->read(&fspot))
            return ESCH_ERR_FILEERROR;

        if (lname && strcmp(lname,fspot.name))
            return ESCH_ERR_NOTFOUND;

        //ÄÄ Found, so setup Fast Spot Light
        strcpy(name,fspot.name);
        flags = fspot.flags;

        VngoColor24bit  c(fspot.color);
        set_intensity( max( max(c.r, c.g), c.b ) );

        set_position( fspot.x, fspot.y, fspot.z );
        set_direction( fspot.i, fspot.j, fspot.k );

        set_inner( fspot.inner );
        set_outer( fspot.outer );

        set_hotspot( fspot.hotspot );
        set_falloff( fspot.falloff );
    }
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Fixed-point format
    else if (iff->chunkid == iff->makeid('E','F','S','P'))
    {
        EschFileLightSpotV1 fspot;

        if (iff->chunkSize != sizeof(fspot))
            return ESCH_ERR_INVALIDDATA;

        //ÄÄ Read chunk and verify name, if given.
        if (iff->read(&fspot))
            return ESCH_ERR_FILEERROR;

        if (lname && strcmp(lname,fspot.name))
            return ESCH_ERR_NOTFOUND;

        //ÄÄ Found, so setup Fast Spot Light
        strcpy(name,fspot.name);
        flags = fspot.flags;

        VngoColor24bit  c(fspot.color);
        set_intensity( max( max(c.r, c.g), c.b ) );

        set_position(fspot.x / 65536.0f, fspot.y / 65536.0f, fspot.z / 65536.0f);
        set_direction(fspot.i / 65536.0f, fspot.j / 65536.0f, fspot.k / 65536.0f);

        set_inner( fspot.inner / 65536.0f );
        set_outer( fspot.outer / 65536.0f );

        set_hotspot( fspot.hotspot / 65536.0f );
        set_falloff( fspot.falloff / 65536.0f );
    }
    else
    {
        return ESCH_ERR_NOTFOUND;
    }

//ÄÄ Return ok
    return ESCH_ERR_NONE;
}

//°±² End of module - eslfspot.cpp ²±°

