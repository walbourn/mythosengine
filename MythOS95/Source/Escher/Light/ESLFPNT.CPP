//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//�����������Copyright�(c)�1994-1997�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//��������������������� Microsoft Windows '95 Version �����������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
//
// Created by Tim Little & Chuck Walbourn
//
// eslfpnt.cpp
//
// The EschLight and associated classes are used for implementing the
// lighting model.  EschLights affect objects by controlling the
// shade level and potentially color of a vertex.  EschLight objects
// are maintained in a linked list.
//
// An EschFastPointLight is an approximation of point sources in
// 3-space using the target frame-reference to form a 'local' vector source.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "escher.hpp"
#include "esfile.hpp"

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

#define max(a,b)  (((a) > (b)) ? (a) : (b))

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschFastPointLight - Constructor                                         �
//                                                                          �
// Initializes the light object with full intesity and sets type.           �
//���������������������������������������������������������������������������
EschFastPointLight::EschFastPointLight(const char *fname, const char *lname) :
    EschLight(),
    pos(0,0,0)
{
    ltyp = ESCH_LGTT_FPOINT;
    intensity = 255;

    if (fname)
    {
        load(fname,lname);
    }
};

EschFastPointLight::EschFastPointLight(const EschPoint *pnt) :
    EschLight(),
    pos(*pnt)
{
    ltyp = ESCH_LGTT_FPOINT;
    intensity = 255;
};

EschFastPointLight::EschFastPointLight(Flx16 ix, Flx16 iy, Flx16 iz) : 
    EschLight(),
    pos(ix,iy,iz)
{
    ltyp = ESCH_LGTT_FPOINT;
    intensity = 255;
};



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschFastPointLight - setup                                               �
//                                                                          �
// Performs the setup of the light on an object by object basis.            �
//���������������������������������������������������������������������������
void EschFastPointLight::setup(const EschFrameRef *fr)
{
    if (fr)
    {
        EschPoint   tpnt;

        if (EschCurrent
            && EschCurrent->camera
            && EschCurrent->camera->flags & ESCH_CAM_MODELSPACE)
        {
            pos.transform(&fr->iorient,&tpnt);
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
        }
    }
    else
    {
        // If there is no reference, we assume the object is at 0,0,0
        // since we have no other valid interpretation

        tdir.i = pos.x;
        tdir.j = pos.y;
        tdir.k = pos.z;
    }
    tdir.normalize();

    EschLight::setup(fr);
}


//�������������������������������������������������������������������������Ŀ
// EschFastPointLight - shine                                               �
//                                                                          �
// Sets the shade level in the Van Gogh FastPoint based on the intesity of  �
// the light and the given vertex information.                              �
//                                                                          �
// The vector light source computes a dot product.                          �
//���������������������������������������������������������������������������
void EschFastPointLight::shine(const EschVertex *v, VngoPoint *vpt, int revnrml) const 
{                                                          
    if (!(flags & ESCH_LGT_OFF) && _intensity.flx > 0)
    {
        // Compute dot product
        Flx16 dot = v->normal DOT tdir;

        if (dot.flx < 0)
        {
            dot.flx = (revnrml) ? -dot.flx : 0;
        }

        if (dot.flx > (1<<16))
            dot.flx = (1<<16);
        
        // Compute shade value
        long i = (dot.flx * (_intensity.flx >> 16)) >> 16;
        if (vpt->shade < i)
            vpt->shade = i;
    }

//��� Chain for true multiple lights
    if (inext)
        inext->shine(v,vpt,revnrml);
}


//�������������������������������������������������������������������������Ŀ
// EschFastPointLight - hishine                                             �
//                                                                          �
// Sets the shade level, allowing specular highlights to overdrive the      �
// color based on the intensity of the light and the given vertex info.     �
//                                                                          �
// The vector light source computes a dot product.                          �
//���������������������������������������������������������������������������
void EschFastPointLight::hishine(const EschVertex *v, VngoPoint *vpt, int revnrml) const 
{
    if (!(flags & ESCH_LGT_OFF) && _hintensity.flx > 0)
    {
        // Compute dot product
        Flx16 dot = v->normal DOT tdir;

        if (dot.flx < 0)
        {
            dot.flx = (revnrml) ? -dot.flx : 0;
        }

        if (dot.flx > (1<<16))
            dot.flx = (1<<16);
        
        // Compute shade value
        long i = (dot.flx * (_hintensity.flx >> 16)) >> 16;
        if (vpt->shade < i)
            vpt->shade = i;
    }

//��� Chain for true multiple lights
    if (inext)
        inext->hishine(v,vpt,revnrml);
}



//���������������������������������������������������������������������������
//�����������������������������  I/O Routines  ������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschFastPointLight - load                                                �
//                                                                          �
// Loads the position and other data of the fast point light from an IFF    �
// file.                                                                    �
//                                                                          �
// The IFF version assumes that the IFF is open and pointing at the proper  �
// chunk.  If a 'lname' is given and the name doesn't match that in the     �
// chunk, an error is returned.                                             �
//���������������������������������������������������������������������������
esch_error_codes EschFastPointLight::load(const char *fname, const char *lname)
{
    esch_error_codes    err;
    XFParseIFF          iff;

//�� Open file
    if (iff.open(fname,XF_OPEN_READ))
        return ESCH_ERR_FILEERROR;

//�� Loop until a header with the correct name is found
    err=ESCH_ERR_NONE;

    for(;;)
    {
        if (iff.next() != XF_ERR_NONE)
        {
            if (!iff.depth)
                return ESCH_ERR_NOTFOUND;
            iff.leaveform();
        }

        if (iff.chunkid == iff.makeid('E','F','P','T'))
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

//�� Return ok
    iff.close();
    return err;
}

esch_error_codes EschFastPointLight::load(XFParseIFF *iff, const char *lname)
{
    EschFileLightPoint fpnt;

    assertMyth("EschFastPointLight::load requries iff pointer",
               iff);

//�� Verify correct chunk name and size
    if (iff->chunkid != iff->makeid('E','F','P','T'))
        return ESCH_ERR_NOTFOUND;

    if (iff->chunkSize != sizeof(EschFileLightPoint))
        return ESCH_ERR_INVALIDDATA;

//�� Read chunk and verify name, if given.
    if (iff->read(&fpnt))
        return ESCH_ERR_FILEERROR;

    if (lname && strcmp(lname,fpnt.name))
        return ESCH_ERR_NOTFOUND;

//�� Found, so setup Fast Point Light

    strcpy(name,fpnt.name);
    flags = fpnt.flags;

    VngoColor24bit  c(fpnt.color);
    set_intensity( max( max(c.r, c.g), c.b ) );

    set_position( fpnt.x, fpnt.y, fpnt.z );

//�� Return ok
    return ESCH_ERR_NONE;
}

//��� End of module - eslfpnt.cpp ���
