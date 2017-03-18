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
//ùùùùùùùùùùùùùùùùù Microsoft Windows 95/98/NT Version ùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùCopyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbournùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
// Created by Tim Little & Chuck Walbourn
//
// eslspot.cpp
//
// The EschLight and associated classes are used for implementing the
// lighting model.  EschLights affect objects by controlling the
// shade level and potentially color of a vertex.  EschLight objects
// are maintained in a linked list.
//
// An EschSpotLight shines in a given direction from a location in 3-space,
// with the intensity dropping off towords the edge of the cone defined
// for the spot.  It also supports distance attenuation.
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
// EschSpotLight - Constructor                                              ³
//                                                                          ³
// Initializes the light object with full intesity and sets type.           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschSpotLight::EschSpotLight(const char *fname, const char *lname) :
    EschAttenLight(),
    dir(0,0,1),
    hotspot(44),
    falloff(45)
{
    ltyp = ESCH_LGTT_SPOT;

    if (fname)
    {
        load(fname,lname);
    }
};

EschSpotLight::EschSpotLight(const EschPoint *pnt,
                             const EschVector *d,
                             float h, float f, float i, float o) :
    EschAttenLight(pnt,i,o),
    dir(*d),
    hotspot(h),
    falloff(f)
{
    ltyp = ESCH_LGTT_SPOT;

    dir.normalize();
};

EschSpotLight::EschSpotLight(float ix, float iy, float iz,
                             float ii, float ij, float ik,
                             float h, float f, float i, float o) :
    EschAttenLight(ix,iy,iz,i,o),
    dir(ii,ij,ik),
    hotspot(h),
    falloff(f)
{
    ltyp = ESCH_LGTT_SPOT;

    dir.normalize();
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschSpotLight - setup                                                    ³
//                                                                          ³
// Performs the setup of the light on an object by object basis.            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschSpotLight::setup(const EschFrameRef *fr)
{
    if (fr
        && EschCurrent
        && EschCurrent->camera
        && EschCurrent->camera->flags & ESCH_CAM_MODELSPACE)
    {
        pos.transform(&fr->iorient,&tpos);
        dir.transform(&fr->iorient,&tdir);
        tdir = -tdir;

        tinner = inner / fr->scalef;
        touter = outer / fr->scalef;
    }
    else
    {
        tpos = pos;
        tdir = -dir;

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

    hotcos = esch_cos(hotspot);
    fallcos = esch_cos(falloff);

    frate=hfrate=0;
    if ((hotcos-fallcos) > 0)
    {
        frate = _intensity / (hotcos-fallcos);
        hfrate = _hintensity / (hotcos-fallcos);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschSpotLight - shine                                                    ³
//                                                                          ³
// Sets the shade level in the Van Gogh point based on the intesity of the  ³
// light and the given vertex information.                                  ³
//                                                                          ³
// The point light source computes a direction vector relative to the       ³
// vertex and then computes a dot product.  The distance and angle away from³
// the spot's direction is used to attenuate the intensity.                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschSpotLight::shine(const EschVertex *v, VngoPoint *vpt, int revnrml) const
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

            // Use dot product with light to determine fall-off
            float dotcone = vtx DOT tdir;

            // Check to see if we are inside fall-off cone
            if (dotcone > fallcos)
            {
                // Compute dot product
                float dot = v->normal DOT vtx;

                if (dot < 0)
                {
                    dot = (revnrml) ? -dot : 0;
                }

                // Compute intensity output (including attenuation)
                float inten = _intensity;

                if (dotcone < hotcos)
                {
                    inten -= (hotcos - dotcone) * frate;
                }

                if ((flags & ESCH_LGT_ATTEN) && (mag > inner))
                {
                    inten -= (mag - inner) * arate;
                }

                // Compute shade value
                vpt->shade += long(dot * inten);
            }
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
// EschSpotLight - hishine                                                  ³
//                                                                          ³
// Sets the shade level, allowing specular highlights to overdrive the      ³
// color based on the intensity of the light and the given vertex info.     ³
//                                                                          ³
// The point light source computes a direction vector relative to the       ³
// vertex and then computes a dot product.  The distance and angle away from³
// the spot's direction is used to attenuate the intensity.                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschSpotLight::hishine(const EschVertex *v, VngoPoint *vpt, int revnrml) const
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

            // Use dot product with light to determine fall-off
            float dotcone = vtx DOT tdir;

            // Check to see if we are inside fall-off cone
            if (dotcone > fallcos)
            {
                // Compute dot product
                float dot = v->normal DOT vtx;

                if (dot < 0)
                {
                    dot = (revnrml) ? -dot : 0;
                }

                // Compute intensity output (including attenuation)
                float inten = _hintensity;

                if (dotcone < hotcos)
                {
                    inten -= (hotcos - dotcone) * hfrate;
                }

                if ((flags & ESCH_LGT_ATTEN) && (mag > inner))
                {
                    inten -= (mag - inner) * harate;
                }

                // Compute shade value
                vpt->shade += long(dot * inten);
            }
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
// EschSpotLight - load                                                     ³
//                                                                          ³
// Loads the position and other data of the attenuated light from an IFF    ³
// file.                                                                    ³
//                                                                          ³
// The IFF version assumes that the IFF is open and pointing at the proper  ³
// chunk.  If a 'lname' is given and the name doesn't match that in the     ³
// chunk, an error is returned.                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschSpotLight::load(const char *fname, const char *lname)
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

        if (iff.chunkid == iff.makeid('E','S','P','T')
            || iff.chunkid == iff.makeid('E','S','P','1'))
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

esch_error_codes EschSpotLight::load(XFParseIFF *iff, const char *lname)
{
    assertMyth("EschSpotLight::load requries iff pointer",
               iff);

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Floating-point format
    if (iff->chunkid == iff->makeid('E','S','P','1'))
    {
        EschFileLightSpot   spot;

        if (iff->chunkSize != sizeof(spot))
            return ESCH_ERR_INVALIDDATA;

        //ÄÄ Read chunk and verify name, if given.
        if (iff->read(&spot))
            return ESCH_ERR_FILEERROR;

        if (lname && strcmp(lname,spot.name))
            return ESCH_ERR_NOTFOUND;

        //ÄÄ Found, so setup Spot Light
        strcpy(name,spot.name);
        flags = spot.flags;

        VngoColor24bit  c(spot.color);
        set_intensity( max( max(c.r, c.g), c.b ) );

        set_position( spot.x, spot.y, spot.z );
        set_direction( spot.i, spot.j, spot.k );

        set_inner( spot.inner );
        set_outer( spot.outer );

        set_hotspot( spot.hotspot );
        set_falloff( spot.falloff );
    }
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Fixed-point format
    else if (iff->chunkid == iff->makeid('E','S','P','T'))
    {
        EschFileLightSpotV1   spot;

        if (iff->chunkSize != sizeof(spot))
            return ESCH_ERR_INVALIDDATA;

        //ÄÄ Read chunk and verify name, if given.
        if (iff->read(&spot))
            return ESCH_ERR_FILEERROR;

        if (lname && strcmp(lname,spot.name))
            return ESCH_ERR_NOTFOUND;

        //ÄÄ Found, so setup Spot Light
        strcpy(name,spot.name);
        flags = spot.flags;

        VngoColor24bit  c(spot.color);
        set_intensity( max( max(c.r, c.g), c.b ) );

        set_position(spot.x / 65536.0f, spot.y / 65536.0f, spot.z / 65536.0f);
        set_direction(spot.i / 65536.0f, spot.j / 65536.0f, spot.k / 65536.0f);

        set_inner( spot.inner / 65536.0f );
        set_outer( spot.outer / 65536.0f );

        set_hotspot( spot.hotspot / 65536.0f );
        set_falloff( spot.falloff / 65536.0f );
    }
    else
    {
        return ESCH_ERR_NOTFOUND;
    }

//ÄÄ Return ok
    return ESCH_ERR_NONE;
}

//°±² End of module - eslspot.cpp ²±°

