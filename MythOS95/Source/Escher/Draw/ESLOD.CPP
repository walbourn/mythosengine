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
// esdraw.cpp
//
// The EschLevelOfDetail class provides a handler for detail with multiple
// levels of detail.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "escher.hpp"

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

extern EschPoint EschTempPoint;
extern VngoPoint EschTempVPoint;

Flx16 EschLevelOfDetail::dist[ESCH_LOD_MAX_LEVELS];

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschLevelOfDetail - Constructor                                          �
//���������������������������������������������������������������������������
EschLevelOfDetail::EschLevelOfDetail() :
    EschDrawable(ESCH_DRWT_LOD),
    nlevels(0),
    current(0),
    change(0),
    color(0)
{
    for(int i=0; i < ESCH_LOD_MAX_LEVELS; i++)
        geom[i]=0;
}


//�������������������������������������������������������������������������Ŀ
// EschLevelOfDetail - Destructor                                           �
//���������������������������������������������������������������������������
EschLevelOfDetail::~EschLevelOfDetail()
{
    release();
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschLevelOfDetail - operator =                                           �
//                                                                          �
// Copies the data from another drawable.                                   �
//���������������������������������������������������������������������������
const EschLevelOfDetail &EschLevelOfDetail::operator =
                                             (const EschLevelOfDetail &that)
{
    if (this != &that)
    {
        release();

        EschDrawable::operator = (that);

        nlevels = that.nlevels;
        current = that.current;
        change = that.change;
        color = that.color;

        memcpy(geom,that.geom,sizeof(geom));
    }
    return *this;
}


//�������������������������������������������������������������������������Ŀ
// EschLevelOfDetail - draw                                                 �
//���������������������������������������������������������������������������
void EschLevelOfDetail::draw()
{
    if (current >= nlevels)
        return;

    EschGeometry *g = geom[current];
    if (!g)
        return;

//��� Determine what detail-level to draw...
    assertMyth("EschLevelOfDetail::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    EschCamera *cam=EschCurrent->camera;

    assertMyth("EschLevelOfDetail::draw needs a viewport in current context's camera",
               cam->vport != NULL);

    g->exts.center.transform(&g->world,&EschTempPoint);
    EschTempPoint.transform(&cam->eye.iorient);

    for(int i=0; i < nlevels; i++)
    {
        if (EschTempPoint.z < dist[i])
        {
            flags |= ESCH_DRW_VISIBLE;

            //��� Handle auto-change
            if (flags & ESCH_LOD_AUTOSWITCH)
            {
                current = change = i;
                geom[i]->draw();
            }
            //��� Just store result and draw current
            else
            {
                change = i;
                g->draw();
            }
            return;
        }
    }

//��� If beyond highest level, draw as a colored dot...
    if (EschTempPoint.z.flx > cam->yon.flx
        || EschTempPoint.z.flx < cam->hither.flx)
        return;
    
    // Left/right/top/bottom plane clipping
    Flx16 zx = flx_16mul16(EschTempPoint.z,cam->xsize);
    Flx16 zy = flx_16mul16(EschTempPoint.z,cam->ysize);

    if (EschTempPoint.x.flx < -zx.flx 
        || EschTempPoint.x.flx > zx.flx
        || EschTempPoint.y.flx < -zy.flx
        || EschTempPoint.y.flx > zy.flx)
        return;

    flags |= ESCH_DRW_VISIBLE;

    //��� Project pixel
    EschTempVPoint.x = (flx_muldiv(EschTempPoint.x,
                                   cam->xscalar,
                                   EschTempPoint.z).flx
                                   + (cam->vport->vbuff.width<<15)) >> 16;
    EschTempVPoint.y = ((cam->vport->vbuff.height<<15)
                                   - flx_muldiv(EschTempPoint.y,
                                   cam->yscalar,
                                   EschTempPoint.z).flx) >> 16;
    EschTempVPoint.z = flx_16mul16(EschTempPoint.z,cam->z_factor).flx << 1;
    EschTempVPoint.clr = color;

    VngoVport *vport = cam->vport;

    assertMyth("EschLevelOfDetail::draw needs palette in viewport",
                vport->vbuff.pal != 0);
    EschTempVPoint.shade = vport->vbuff.pal->shd_pal->mid_point;

    //��� Draw pixel
    vport->pixel(&EschTempVPoint);
}


//�������������������������������������������������������������������������Ŀ
// EschLevelOfDetail - find                                                 �
//���������������������������������������������������������������������������
EschDrawable *EschLevelOfDetail::find(const char *dname) const
{
    if (!dname)
        return 0;

    for(int i=0; i < ESCH_LOD_MAX_LEVELS; i++)
    {
        if (!geom[i])
            continue;

        EschDrawable *result = geom[i]->find(dname);
        if (result)
            return result;
    }

    if (!strncmp(dname,name,ESCH_MAX_NAME))
        return (EschDrawable*)this;

    if (!inext)
        return 0;

    return inext->find(dname);
}


//�������������������������������������������������������������������������Ŀ
// EschLevelOfDetail - get_extents                                          �
//���������������������������������������������������������������������������
int EschLevelOfDetail::get_extents(EschSphereExtents *sp) const
{
    if (current >= nlevels || !geom[current])
        return -1;

    return geom[current]->get_extents(sp);
}


//�������������������������������������������������������������������������Ŀ
// EschLevelOfDetail - ray                                                  �
//���������������������������������������������������������������������������
Flx16 EschLevelOfDetail::ray(const EschPoint *pt, const EschVector *v, int coarse) const
{
    if (current >= nlevels || !geom[current])
        return Flx16(-1);

    return geom[current]->ray(pt,v,coarse);
}


//�������������������������������������������������������������������������Ŀ
// EschLevelOfDetail - hit                                                  �
//���������������������������������������������������������������������������
int EschLevelOfDetail::hit(const EschPoint *pt, const Flx16 r, int coarse) const
{
    if (current >= nlevels || !geom[current])
        return -1;

    return geom[current]->hit(pt,r,coarse);
}


//�������������������������������������������������������������������������Ŀ
// EschLevelOfDetail - pick                                                 �
//���������������������������������������������������������������������������
esch_error_codes EschLevelOfDetail::pick(EschPicking *data) const
{
    if (current >= nlevels || !geom[current])
        return ESCH_ERR_NONE;

    return geom[current]->pick(data);
}


//�������������������������������������������������������������������������Ŀ
// EschLevelOfDetail - collide                                              �
//���������������������������������������������������������������������������
esch_error_codes EschLevelOfDetail::collide(EschCollision *data) const
{
    if (current >= nlevels || !geom[current])
        return ESCH_ERR_NONE;

    if (!data)
        return ESCH_ERR_INVALIDPARMS;

//��� We want to intercept test self case only...
    if (data->flags & ESCH_CLSN_TESTSELF)
    {
        dword oflags = data->flags & (ESCH_CLSN_NOWALK
                                      | ESCH_CLSN_NOSETUP);

        data->flags |= ESCH_CLSN_NOWALK | ESCH_CLSN_NOSETUP;
        
        esch_error_codes err = geom[current]->collide(data);

        data->flags &= ~(ESCH_CLSN_NOWALK | ESCH_CLSN_NOSETUP);
        data->flags |= oflags;

        if (err)
            return err;

        return ESCH_ERR_NONE;
    }

//��� Otherwise use base implementation
    return EschDrawable::collide(data);
}


//�������������������������������������������������������������������������Ŀ
// EschLevelOfDetail - animate                                              �
//���������������������������������������������������������������������������
void EschLevelOfDetail::animate()
{
    if (current >= nlevels || !geom[current])
        return;

    geom[current]->animate();
}


//�������������������������������������������������������������������������Ŀ
// EschLevelOfDetail - release                                              �
//���������������������������������������������������������������������������
void EschLevelOfDetail::release()
{
    if (flags & ESCH_DRW_OWNSDATA)
    {
        for(int i=0; i < ESCH_LOD_MAX_LEVELS; i++)
        {
            if (geom[i])
            {
                geom[i]->remove(1);
                delete geom[i];
                geom[i]=0;
            }
        }
    }
}



//���������������������������������������������������������������������������
//���������������������������  Utility Routines  ����������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschLevelOfDetail - add                                                  �
//���������������������������������������������������������������������������
int EschLevelOfDetail::add(EschGeometry *g)
{
    if (nlevels >= ESCH_LOD_MAX_LEVELS)
        return 1;

    geom[nlevels] = g;
    nlevels++;

    return 0;
}


//�������������������������������������������������������������������������Ŀ
// EschLevelOfDetail - set_dist                                             �
//���������������������������������������������������������������������������
void EschLevelOfDetail::set_dist(ushort lvl, Flx16 d)
{
    if (lvl >= ESCH_LOD_MAX_LEVELS)
        return;

    dist[lvl] = d;
}

//��� End of module - eslod.cpp ���
