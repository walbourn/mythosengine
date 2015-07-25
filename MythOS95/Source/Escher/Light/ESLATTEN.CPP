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
//ùùùùùùùùùùùùùùùùùùù Microsoft Windows 95/NT Version ùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùCopyrightù(c)ù1994-1998ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùAllùRightsùReserved.ùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
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
// eslatten.cpp
//
// The EschLight and associated classes are used for implementing the
// lighting model.  EschLights affect objects by controlling the
// shade level and potentially color of a vertex.  EschLight objects
// are maintained in a linked list.
//
// An EschAttenLight shines in all directions equally, but has a specific
// location in 3-space, and has a fall-off for distance from the light
// source.
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
// EschAttenLight - Constructor                                             ³
//                                                                          ³
// Initializes the light object with full intesity and sets type.           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschAttenLight::EschAttenLight(const char *fname, const char *lname) :
    EschPointLight(),
    inner(0),
    outer(0x1000)
{
    ltyp = ESCH_LGTT_ATTEN;
    flags |= ESCH_LGT_ATTEN;

    if (fname)
    {
        load(fname,lname);
    }
};

EschAttenLight::EschAttenLight(const EschPoint *pnt, float i, float o) :
    EschPointLight(pnt),
    inner(i),
    outer(o)
{
    ltyp = ESCH_LGTT_ATTEN;
    flags |= ESCH_LGT_ATTEN;
};

EschAttenLight::EschAttenLight(float ix, float iy, float iz, float i, float o) : 
    EschPointLight(ix,iy,iz),
    inner(i),
    outer(o)
{
    ltyp = ESCH_LGTT_ATTEN;
    flags |= ESCH_LGT_ATTEN;
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschAttenLight - setup                                                   ³
//                                                                          ³
// Performs the setup of the light on an object by object basis.            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschAttenLight::setup(const EschFrameRef *fr)
{
    if (fr
        && EschCurrent
        && EschCurrent->camera
        && EschCurrent->camera->flags & ESCH_CAM_MODELSPACE)
    {
        pos.transform(&fr->iorient,&tpos);
        tinner = inner / fr->scalef;
        touter = outer / fr->scalef;
    }
    else
    {
        tpos = pos;
        tinner = inner;
        touter = outer;
    }
    if (tinner > touter)
        tinner = touter;

    EschLight::setup(fr);

    arate=harate=0;
    if ((outer-inner) > 0)
    {
        arate = _intensity / (outer - inner);
        harate = _hintensity / (outer - inner);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschAttenLight - shine                                                   ³
//                                                                          ³
// Sets the shade level in the Van Gogh point based on the intesity of the  ³
// light and the given vertex information.                                  ³
//                                                                          ³
// The point light source computes a direction vector relative to the       ³
// vertex and then computes a dot product.  The distance is used to         ³
// attenuate the intensity.                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschAttenLight::shine(const EschVertex *v, VngoPoint *vpt, int revnrml) const 
{
    if (!(flags & ESCH_LGT_OFF))
    {
        // Compute point source lighting vector
        EschVector vtx(tpos.x - v->x,
                       tpos.y - v->y,
                       tpos.z - v->z);

        float mag = vtx.magnitude();

        // Check for point beyond outer range before
        // continuing
        if (mag < outer)
        {
            // Complete normalization
            if (mag > 0)
            {
                vtx.i /= mag;
                vtx.j /= mag;
                vtx.k /= mag;
            }

            // Compute dot product
            float dot = v->normal DOT vtx;

            if (dot < 0)
            {
                dot = (revnrml) ? -dot : 0;
            }
        
            // Compute intensity output (including attenuation)
            float inten = _intensity;

            if ((flags & ESCH_LGT_ATTEN) && (mag > inner))
            {
                inten -= (mag - inner) * arate;
            }

            // Compute final shade value
            vpt->shade += long(dot * inten);
        }
    }

//ÄÄÄ Chain for true multiple lights
    if (inext)
    {
        inext->shine(v,vpt,revnrml);
    }
//ÄÄÄ Clamp shade value
    else
    {
        if (vpt->shade > mp)
            vpt->shade = mp;
        else if (vpt->shade < 0)
            vpt->shade = 0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschAttenLight - hishine                                                 ³
//                                                                          ³
// Sets the shade level, allowing specular highlights to overdrive the      ³
// color based on the intensity of the light and the given vertex info.     ³
//                                                                          ³
// The point light source computes a direction vector relative to the       ³
// vertex and then computes a dot product.  The distance is used to         ³
// attenuate the intensity.                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschAttenLight::hishine(const EschVertex *v, VngoPoint *vpt, int revnrml) const 
{                                                           
    if (!(flags & ESCH_LGT_OFF))
    {
        // Compute point source lighting vector
        EschVector vtx(tpos.x - v->x,
                       tpos.y - v->y,
                       tpos.z - v->z);

        float mag = vtx.magnitude();

        // Check for point beyond outer range before
        // continuing
        if (mag < outer)
        {
            // Complete normalization
            if (mag > 0)
            {
                vtx.i /= mag;
                vtx.j /= mag;
                vtx.k /= mag;
            }

            // Compute dot product
            float dot = v->normal DOT vtx;

            if (dot < 0)
            {
                dot = (revnrml) ? -dot : 0;
            }
        
            // Compute intensity output (including attenuation)
            float inten = _hintensity;

            if ((flags & ESCH_LGT_ATTEN) && (mag > inner))
            {
                inten -= (mag - inner) * harate;
            }

            // Compute final shade value
            vpt->shade += long(dot * inten);
        }
    }

//ÄÄÄ Chain for true multiple lights
    if (inext)
    {
        inext->hishine(v,vpt,revnrml);
    }
//ÄÄÄ Clamp shade value
    else
    {
        if (vpt->shade > VNGO_SHADE_FULL)
            vpt->shade = VNGO_SHADE_FULL;
        else if (vpt->shade < 0)
            vpt->shade = 0;
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  I/O Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschAttenLight - load                                                    ³
//                                                                          ³
// Loads the position and other data of the attenuated light from an IFF    ³
// file.                                                                    ³
//                                                                          ³
// The IFF version assumes that the IFF is open and pointing at the proper  ³
// chunk.  If a 'lname' is given and the name doesn't match that in the     ³
// chunk, an error is returned.                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschAttenLight::load(const char *fname, const char *lname)
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

        if (iff.chunkid == iff.makeid('E','A','T','N')
            || iff.chunkid == iff.makeid('E','A','T','1'))
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

esch_error_codes EschAttenLight::load(XFParseIFF *iff, const char *lname)
{
    assertMyth("EschAttenLight::load requries iff pointer",
               iff);

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Floating-point format
    if (iff->chunkid == iff->makeid('E','A','T','1'))
    {
        EschFileLightAtten  atn;

        if (iff->chunkSize != sizeof(atn))
            return ESCH_ERR_INVALIDDATA;

        //ÄÄ Read chunk and verify name, if given.
        if (iff->read(&atn))
            return ESCH_ERR_FILEERROR;

        if (lname && strcmp(lname,atn.name))
            return ESCH_ERR_NOTFOUND;

        //ÄÄ Found, so setup Atten Light
        strcpy(name,atn.name);
        flags = atn.flags;

        VngoColor24bit  c(atn.color);
        set_intensity( max( max(c.r, c.g), c.b ) );

        set_position( atn.x, atn.y, atn.z );

        set_inner( atn.inner );
        set_outer( atn.outer );
    }
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Fixed-point format
    else if (iff->chunkid == iff->makeid('E','A','T','N'))
    {
        EschFileLightAttenV1  atn;

        if (iff->chunkSize != sizeof(atn))
            return ESCH_ERR_INVALIDDATA;

        //ÄÄ Read chunk and verify name, if given.
        if (iff->read(&atn))
            return ESCH_ERR_FILEERROR;

        if (lname && strcmp(lname,atn.name))
            return ESCH_ERR_NOTFOUND;

        //ÄÄ Found, so setup Atten Light
        strcpy(name,atn.name);
        flags = atn.flags;

        VngoColor24bit  c(atn.color);
        set_intensity( max( max(c.r, c.g), c.b ) );

        set_position(atn.x / 65536.0f, atn.y / 65536.0f, atn.z / 65536.0f);

        set_inner( atn.inner / 65536.0f );
        set_outer( atn.outer / 65536.0f );
    }
    else
    {
        return ESCH_ERR_NOTFOUND;
    }

//ÄÄ Return ok
    return ESCH_ERR_NONE;
}

//°±² End of module - eslatten.cpp ²±°

