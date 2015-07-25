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
// Created by Tim Little & Chuck Walbourn
//
// esgpartn.cpp
//
// Contains the code for the EschGridPartition class which implements
// a simple partitioning scheme.  World coordinate space is broken
// into 'n' fixed sized regions starting at a given origin along the XZ
// plane and all other drawables are placed into a 'global' region.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define UNKNOWN     0
#define DISCOVERED  1
#define EXPLORED    2

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

struct queue_entry
{
    queue_entry *next;
    long        w;
    long        d;
    float       dist;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    queue_entry(long _w, long _d, float _dist) :
        next(0),
        w(_w),
        d(_d),
        dist(_dist) {}
};

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschGridPartition - Constructor                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschGridPartition::EschGridPartition() :
    EschPartition(),
    regions(0)
{
    dtyp=ESCH_DRWT_PRTN_GRID;
}

EschGridPartition::EschGridPartition(ushort w, ushort d, float s,
                                     const EschPoint *o) :
    EschPartition(),
    regions(0)
{
    dtyp=ESCH_DRWT_PRTN_GRID;

    esch_error_codes err = init(w,d,s,o);
    assertMyth("EschGridPartition init failed", err == ESCH_ERR_NONE);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschGridPartition - Destructor                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschGridPartition::~EschGridPartition()
{
    release();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschGridPartition - find                                                 ³
//                                                                          ³
// Performs a search for a drawable with a given name.                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschDrawable *EschGridPartition::find(const char *dname) const
{
    if (!regions)
        return 0;

    if (!strncmp(dname,name,ESCH_MAX_NAME))
        return (EschDrawable*)this;

    for(ulong i=0; i < nregions; i++)
    {
        for(EschPartitionList *ptr=regions[i]; ptr != 0; ptr = ptr->next)
        {
            assertMyth("EschGridPartition::find found entry without item",
                       ptr->item != 0);

            EschDrawable *drw = ptr->item->find(dname);
            if (drw)
                return drw;
        }
    }

    if (!inext)
        return 0;

    return inext->find(dname);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschGridPartition - draw                                                 ³
//                                                                          ³
// Performs a draw for drawables within the partitioning.                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschGridPartition::draw()
{
    if (!regions)
        return;

//ÄÄÄ Handle 'dumb' draw
    if (flags & ESCH_PARTN_OFF)
    {
        for(ulong i=0; i < nregions; i++)
        {
            for(EschPartitionList *ptr=regions[i]; ptr != 0; ptr = ptr->next)
            {
                EschDrawable *item = ptr->item;

                assertMyth("EschGridPartition::draw found entry without item",
                           item != 0);

                if (!(item->flags & ESCH_DRW_SKIP))
                    item->draw();
            }
        }
        return;
    }

    EschPoint   pos;
    float       minx;
    float       minz;
    float       maxx;
    float       maxz;
    float       tx, ty;
    EschCamera  *cam;

//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschGridPartition::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam = EschCurrent->camera;

    assertMyth("EschGridPartition::draw needs a viewport in current context's camera",
               cam->vport != NULL);

//ÄÄÄ Transform view volume into world coords and project onto XZ plane,
//ÄÄÄ forming min/max bound.

    //ÄÄÄ Camera Position
    cam->get_position(&pos);

    minx = pos.x;
    minz = pos.z;
    maxx = pos.x;
    maxz = pos.z;

    //ÄÄÄ Far points
    if (cam->flags & ESCH_CAM_ORTHO)
    {
        tx = cam->xsize;
        ty = cam->ysize;
    }
    else
    {
        tx = cam->yon * cam->xsize;
        ty = cam->yon * cam->ysize;
    }

    // -tx, ty
    pos.x = -tx;
    pos.y = ty;
    pos.z = cam->yon;
    pos.transform(&cam->eye.orient);
    if (minx > pos.x)  minx = pos.x;
    if (minz > pos.z)  minz = pos.z;
    if (maxx < pos.x)  maxx = pos.x;
    if (maxz < pos.z)  maxz = pos.z;

    // tx, ty
    pos.x = tx;
    pos.y = ty;
    pos.z = cam->yon;
    pos.transform(&cam->eye.orient);
    if (minx > pos.x)  minx = pos.x;
    if (minz > pos.z)  minz = pos.z;
    if (maxx < pos.x)  maxx = pos.x;
    if (maxz < pos.z)  maxz = pos.z;

    // -tx, -ty
    pos.x = -tx;
    pos.y = -ty;
    pos.z = cam->yon;
    pos.transform(&cam->eye.orient);
    if (minx > pos.x)  minx = pos.x;
    if (minz > pos.z)  minz = pos.z;
    if (maxx < pos.x)  maxx = pos.x;
    if (maxz < pos.z)  maxz = pos.z;

    // tx, -ty
    pos.x = tx;
    pos.y = -ty;
    pos.z = cam->yon;
    pos.transform(&cam->eye.orient);
    if (minx > pos.x)  minx = pos.x;
    if (minz > pos.z)  minz = pos.z;
    if (maxx < pos.x)  maxx = pos.x;
    if (maxz < pos.z)  maxz = pos.z;

    // minx,minz to maxx, maxz is now the bounding area on the XZ plane

//ÄÄÄ Compute min/max points for region grid.
    long sw = long(minx - origin.x) >> sizeshift;
    long d = long(minz - origin.z) >> sizeshift;
    long ew = long(maxx - origin.x) >> sizeshift;
    long ed = long(maxz - origin.z) >> sizeshift;

//ÄÄÄ Draw all regions within min/max
    if (sw < width && d < depth && ew >= 0 && ed >= 0)
    {
        flags |= ESCH_DRW_VISIBLE;

        if (sw < 0)  sw = 0;
        if (d < 0)  d = 0;
        if (ew >= width)  ew = width - 1;
        if (ed >= depth)  ed = depth - 1;

        for(; d <= ed; d++)
        {
            long n = (d*width) + sw + 1;
            for(long w=sw; w <= ew; w++)
            {
                for(EschPartitionList *ptr=regions[n]; ptr != 0; ptr = ptr->next)
                {
                    EschDrawable *item = ptr->item;

                    assertMyth("EschGridPartition::draw found entry without item",
                               item != 0);

                    if (!(item->flags & ESCH_DRW_SKIP))
                        item->draw();
                }

                n++;
            }
        }
    }

//ÄÄÄ Draw global list
    for(EschPartitionList *ptr=regions[0]; ptr != 0; ptr = ptr->next)
    {
        EschDrawable *item = ptr->item;

        assertMyth("EschGridPartition::draw found entry without item",
                   item != 0);

        if (!(item->flags & ESCH_DRW_SKIP))
            item->draw();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschGridPartition - pick                                                 ³
//                                                                          ³
// Performs a pick for drawables in the partitioning.                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschGridPartition::pick(EschPicking *data) const
{
    if (!data)
        return ESCH_ERR_INVALIDPARMS;

//ÄÄÄ We want to intercept test self case only...
    if (data->flags & ESCH_PICK_TESTSELF)
    {
        if (!regions)
            return ESCH_ERR_NONE;

        //ÄÄÄ Handle 'dumb' pick
        if (flags & ESCH_PARTN_OFF)
        {
            for(ulong i=0; i < nregions; i++)
            {
                for(EschPartitionList *ptr=regions[i]; ptr != 0; ptr = ptr->next)
                {
                    EschDrawable *item = ptr->item;

                    assertMyth("EschGridPartition::pick found entry without item",
                               item != 0);

                    if (!(item->flags & ESCH_DRW_SKIPTEST))
                    {
                        esch_error_codes err=item->pick(data);
                        if (err)
                            return err;
                    }
                }
            }
            return ESCH_ERR_NONE;
        }

        //ÄÄÄ Perform DDA through grid for pick vector
        float x = data->start.x - origin.x;
        float z = data->start.z - origin.z;

        // DDA doesn't work if start point is outside the grid
        if (x < 0 || z < 0)
            return ESCH_ERR_NOTSUPPORTED;

        long w = long(x) >> sizeshift;
        long d = long(z) >> sizeshift;

        if (w >= width || d >= depth)
            return ESCH_ERR_NOTSUPPORTED;

        float dist = (data->flags & ESCH_PICK_MAXDIST)
                     ? (data->maxdist
                        + EschVector (x - float(w)*size,
                                      0,
                                      z - float(d)*size).magnitude())
                     : (EschVector(float(width)*size,
                                   0,
                                   float(depth)*size).magnitude());

        float ex = x + (dist * data->direction.i);
        float ez = z + (dist * data->direction.k);

        long ew = long(ex) >> sizeshift;
        long ed = long(ez) >> sizeshift;

        long dw = ew - w;
        long dd = ed - d;

        long wstep = (dw >= 0) ? 1 : -1;
        long dstep = (dd >= 0) ? 1 : -1;

        dw = abs(dw);
        dd = abs(dd);

        //ÄÄÄ Width major
        if (dw > dd)
        {
            Flx16 step = Flx16(dd) / Flx16(dw);

            Flx16 daccum = 0;

            for(long i=0; i <= dw; i++)
            {
                if (w >= 0 && w < width
                    && d >= 0 && d < depth)
                {
                    ulong n = (d*width) + w + 1;
                    assert(n < nregions);
                    for(EschPartitionList *ptr=regions[n]; ptr != 0; ptr = ptr->next)
                    {
                        EschDrawable *item = ptr->item;

                        assertMyth("EschGridPartition::pick found entry without item",
                                   item != 0);

                        if (!(item->flags & ESCH_DRW_SKIPTEST))
                        {
                            esch_error_codes err=item->pick(data);
                            if (err)
                                return err;
                        }
                    }
                }
                if (w >= 0 && w < width
                    && (d+1) >= 0 && (d+1) < depth)
                {
                    ulong n = ((d+1)*width) + w + 1;
                    assert(n < nregions);
                    for(EschPartitionList *ptr=regions[n]; ptr != 0; ptr = ptr->next)
                    {
                        EschDrawable *item = ptr->item;

                        assertMyth("EschGridPartition::pick found entry without item",
                                item != 0);

                        if (!(item->flags & ESCH_DRW_SKIPTEST))
                        {
                            esch_error_codes err=item->pick(data);
                            if (err)
                                return err;
                        }
                    }
                }
                if (w >= 0 && w < width
                    && (d-1) >= 0 && (d-1) < depth)
                {
                    ulong n = ((d-1)*width) + w + 1;
                    assert(n < nregions);
                    for(EschPartitionList *ptr=regions[n]; ptr != 0; ptr = ptr->next)
                    {
                        EschDrawable *item = ptr->item;

                        assertMyth("EschGridPartition::pick found entry without item",
                                item != 0);

                        if (!(item->flags & ESCH_DRW_SKIPTEST))
                        {
                            esch_error_codes err=item->pick(data);
                            if (err)
                                return err;
                        }
                    }
                }

                w += wstep;
                daccum += step;
                while (daccum >= Flx16(1))
                {
                    d += dstep;
                    daccum -= Flx16(1);
                }
            }
        }
        //ÄÄÄ Depth major
        else
        {
            Flx16 step = Flx16(dw) / Flx16(dd);

            Flx16 waccum = 0;

            for(long i=0; i <= dd; i++)
            {
                if (w >= 0 && w < width
                    && d >= 0 && d < depth)
                {
                    ulong n = (d*width) + w + 1;
                    assert(n < nregions);
                    for(EschPartitionList *ptr=regions[n]; ptr != 0; ptr = ptr->next)
                    {
                        EschDrawable *item = ptr->item;

                        assertMyth("EschGridPartition::pick found entry without item",
                                item != 0);

                        if (!(item->flags & ESCH_DRW_SKIPTEST))
                        {
                            esch_error_codes err=item->pick(data);
                            if (err)
                                return err;
                        }
                    }
                }
                if ((w+1) >= 0 && (w+1) < width
                    && d >= 0 && d < depth)
                {
                    ulong n = (d*width) + (w+1) + 1;
                    assert(n < nregions);
                    for(EschPartitionList *ptr=regions[n]; ptr != 0; ptr = ptr->next)
                    {
                        EschDrawable *item = ptr->item;

                        assertMyth("EschGridPartition::pick found entry without item",
                                item != 0);

                        if (!(item->flags & ESCH_DRW_SKIPTEST))
                        {
                            esch_error_codes err=item->pick(data);
                            if (err)
                                return err;
                        }
                    }
                }
                if ((w-1) >= 0 && (w-1) < width
                    && d >= 0 && d < depth)
                {
                    ulong n = (d*width) + (w-1) + 1;
                    assert(n < nregions);
                    for(EschPartitionList *ptr=regions[n]; ptr != 0; ptr = ptr->next)
                    {
                        EschDrawable *item = ptr->item;

                        assertMyth("EschGridPartition::pick found entry without item",
                                item != 0);

                        if (!(item->flags & ESCH_DRW_SKIPTEST))
                        {
                            esch_error_codes err=item->pick(data);
                            if (err)
                                return err;
                        }
                    }
                }

                d += dstep;
                waccum += step;
                while (waccum >= Flx16(1))
                {
                    w += wstep;
                    waccum -= Flx16(1);
                }
            }
        }

        //ÄÄÄ Pick on each global list entry...
        for(EschPartitionList *ptr=regions[0]; ptr != 0; ptr = ptr->next)
        {
            EschDrawable *item = ptr->item;

            assertMyth("EschGridPartition::pick found entry without item",
                       item != 0);

            if (!(item->flags & ESCH_DRW_SKIPTEST))
            {
                esch_error_codes err=item->pick(data);
                if (err)
                    return err;
            }
        }

        return ESCH_ERR_NONE;
    }

//ÄÄÄ Otherwise use base implementation
    return EschDrawable::pick(data);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschGridPartition - collide                                              ³
//                                                                          ³
// Performs a collision for drawables in the partitioning.                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschGridPartition::collide(EschCollision *data) const
{
    if (!data)
        return ESCH_ERR_INVALIDPARMS;

//ÄÄÄ We want to intercept test self case only...
    if (data->flags & ESCH_CLSN_TESTSELF)
    {
        if (!regions)
            return ESCH_ERR_NONE;

        //ÄÄÄ Handle 'dumb' collide
        if (flags & ESCH_PARTN_OFF)
        {
            for(ulong i=0; i < nregions; i++)
            {
                for(EschPartitionList *ptr=regions[i]; ptr != 0; ptr = ptr->next)
                {
                    EschDrawable *item = ptr->item;

                    assertMyth("EschGridPartition::collide found entry without item",
                               item != 0);

                    if (item != data->orig
                        && !(item->flags & ESCH_DRW_SKIPTEST))
                    {
                        esch_error_codes err=item->collide(data);
                        if (err)
                            return err;
                    }
                }
            }
            return ESCH_ERR_NONE;
        }

        //ÄÄÄ Check only those regions the target sphere touches
        float radius = data->sphere.radius;

        if (data->sphere.center.x + radius >= origin.x
            && data->sphere.center.z + radius >= origin.z)
        {
            float x = data->sphere.center.x - origin.x;
            float z = data->sphere.center.z - origin.z;

            long w = long(x) >> sizeshift;
            long d = long(z) >> sizeshift;

            long x1 = long(x - radius) >> sizeshift;
            long x2 = long(x + radius) >> sizeshift;
            long z1 = long(z - radius) >> sizeshift;
            long z2 = long(z + radius) >> sizeshift;

            long sw = (x1 < w) ? x1 : w;
            if (sw < 0)  sw = 0;
            long ew = (x2 > w) ? x2 : w;
            if (ew >= width)  ew = width-1;

            long sd = (z1 < d) ? z1 : d;
            if (sd < 0)  sd = 0;
            long ed = (z2 > d) ? z2 : d;
            if (ed >= depth)  ed = depth-1;

            for(d=sd; d <= ed; d++)
            {
                long n = (d*width) + sw + 1;
                assert(n < nregions);
                for(w=sw; w <= ew; w++, n++)
                {
                    for(EschPartitionList *ptr=regions[n]; ptr != 0; ptr = ptr->next)
                    {
                        EschDrawable *item = ptr->item;

                        assertMyth("EschGridPartition::collide found entry without item",
                                item != 0);

                        if (item != data->orig
                            && !(item->flags & ESCH_DRW_SKIPTEST))
                        {
                            esch_error_codes err=item->collide(data);
                            if (err)
                                return err;
                        }
                    }
                }
            }
        }

        //ÄÄÄ Check global list
        for(EschPartitionList *ptr=regions[0]; ptr != 0; ptr = ptr->next)
        {
            EschDrawable *item = ptr->item;

            assertMyth("EschGridPartition::collide found entry without item",
                        item != 0);

            if (item != data->orig && !(item->flags & ESCH_DRW_SKIPTEST))
            {
                esch_error_codes err=item->collide(data);
                if (err)
                    return err;
            }
        }

        return ESCH_ERR_NONE;
    }

//ÄÄÄ Otherwise use base implementation
    return EschDrawable::collide(data);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschGridPartition - animate                                              ³
//                                                                          ³
// Calls animate for each drawable in the partitioning (subject to          ³
// the SKIPANIMATE bit).                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschGridPartition::animate()
{
    if (!regions)
        return;

    for(ulong i=0; i < nregions; i++)
    {
        for(EschPartitionList *ptr=regions[i]; ptr != 0; ptr = ptr->next)
        {
            EschDrawable *item = ptr->item;

            assertMyth("EschGridPartition::animate found entry without item",
                       item != 0);

            if (!(item->flags & ESCH_DRW_SKIPANIMATE))
                item->animate();
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschGridPartition - release                                              ³
//                                                                          ³
// Releases all drawables owned by the partition and clears the partition   ³
// lists.                                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschGridPartition::release()
{
    if (flags & ESCH_DRW_OWNSDATA && regions)
    {
        for(ulong i=0; i < nregions; i++)
        {
            for(EschPartitionList *ptr=regions[i]; ptr != 0;)
            {
                EschPartitionList *t = ptr;
                ptr = ptr->next;

                if ((flags & ESCH_PARTN_OWNSDRAWS) && t->item)
                    delete t->item;

                delete t;
            }
        }

        delete [] regions;
    }

    regions=0;
    flags &= ~(ESCH_DRW_OWNSDATA|ESCH_PARTN_OWNSDRAWS);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschGridPartition - insert                                               ³
//                                                                          ³
// Inserts a drawable into the partitioning.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschGridPartition::insert(EschDrawable *drw)
{
    if (!regions || !drw)
        return ESCH_ERR_INVALIDPARMS;

//ÄÄÄ Get world sphere of drawable
    EschSphereExtents sphere;
    if (drw->get_extents(&sphere) == -1)
        return ESCH_ERR_NOTSUPPORTED;

//ÄÄÄ Figure out region (0 is global region)
    ulong n=0;

    if (sphere.center.x >= origin.x && sphere.center.z >= origin.z)
    {
        float x = sphere.center.x - origin.x;
        float z = sphere.center.z - origin.z;

        long w = long(x) >> sizeshift;
        long d = long(z) >> sizeshift;

        if (w < width && d < depth)
        {
            //ÄÄÄ Check to see if it crosses a region boundary
            if ( (long(x + sphere.radius) >> sizeshift) > w
                 || (long(x - sphere.radius) >> sizeshift) < w
                 || (long(z + sphere.radius) >> sizeshift) > d
                 || (long(z - sphere.radius) >> sizeshift) < d )
            {
                // For now, put in global list...
                n = 0;
            }
            else
            {
                n = (d * width) + w + 1;
            }
        }
    }

//ÄÄÄ Insert into region list
    EschPartitionList *ptr = new EschPartitionList(drw);

    assert(n < nregions);
    if (regions[n])
    {
        ptr->next = regions[n];
        regions[n]->prev = ptr;
    }

    regions[n] = ptr;

    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschGridPartition - remove                                               ³
//                                                                          ³
// Removes a given drawable from the partitioning                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschGridPartition::remove(EschDrawable *drw)
{
    if (!regions || !drw)
        return;

    int found = 0;

    for(ulong i=0; i < nregions; i++)
    {
        for(EschPartitionList *ptr=regions[i]; ptr != 0; ptr = ptr->next)
        {
            if (ptr->item == drw)
            {
                found = 1;

                if (ptr->prev)
                    ptr->prev->next = ptr->next;
                else
                    regions[i] = ptr->next;

                if (ptr->next)
                    ptr->next->prev = ptr->prev;

                delete ptr;
                break;
            }
        }

        if (ptr)
            break;
    }

    if (found && flags & ESCH_PARTN_OWNSDRAWS)
        delete drw;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschGridPartition - traverse                                             ³
//                                                                          ³
// Performs a controlled walk of the drawables within the partitioning,     ³
// calling a supplied function for each item.                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschGridPartition::traverse(EschTraverse *data) const
{
    if (!data || !data->func)
        return ESCH_ERR_INVALIDPARMS;

//ÄÄÄ Handle 'dumb' traverse
    if (flags & ESCH_PARTN_OFF)
    {
        for(ulong i=0; i < nregions; i++)
        {
            for(EschPartitionList *ptr=regions[i]; ptr != 0; ptr = ptr->next)
            {
                EschDrawable *item = ptr->item;

                assertMyth("EschGridPartition::traverse found entry without item",
                           item != 0);

                if (!(item->flags & ESCH_DRW_SKIPTRAVERSE))
                {
                    if (data->func(data->data,item))
                        return ESCH_ERR_STOPPED;
                }
            }
        }
        return ESCH_ERR_NONE;
    }

//ÄÄÄ Determine starting grid location
    float x = data->pos.x - origin.x;
    float z = data->pos.z - origin.z;

    if (x < 0 || z < 0)
        return ESCH_ERR_NOTSUPPORTED;

    long w = long(x) >> sizeshift;
    long d = long(z) >> sizeshift;

    if (w >= width || d >= depth)
        return ESCH_ERR_NOTSUPPORTED;

//ÄÄÄ Directed walk
    if (data->flags & ESCH_TRAV_DIRECTION)
    {
        float dist = (data->flags & ESCH_TRAV_DIST)
                     ? (data->dist
                        + EschVector (x - float(w)*size,
                                      0,
                                      z - float(d)*size).magnitude())
                     : (EschVector(float(width)*size,
                                   0,
                                   float(depth)*size).magnitude());

        float ex = x + (dist * data->dir.i);
        float ez = z + (dist * data->dir.k);

        long ew = long(ex) >> sizeshift;
        long ed = long(ez) >> sizeshift;

        long dw = ew - w;
        long dd = ed - d;

        long wstep = (dw >= 0) ? 1 : -1;
        long dstep = (dd >= 0) ? 1 : -1;

        dw = abs(dw);
        dd = abs(dd);

        //ÄÄÄ Width major
        if (dw > dd)
        {
            Flx16 step = Flx16(dd) / Flx16(dw);

            Flx16 daccum = 0;

            for(long i=0; i <= dw; i++)
            {
                if (w >= 0 && w < width
                    && d >= 0 && d < depth)
                {
                    ulong n = (d*width) + w + 1;
                    assert(n < nregions);
                    for(EschPartitionList *ptr=regions[n]; ptr != 0; ptr = ptr->next)
                    {
                        EschDrawable *item = ptr->item;

                        assertMyth("EschGridPartition::traverse found entry without item",
                                   item != 0);

                        if (!(item->flags & ESCH_DRW_SKIPTRAVERSE))
                        {
                            if (data->func(data->data,item))
                                return ESCH_ERR_STOPPED;
                        }
                    }
                }
                if (w >= 0 && w < width
                    && (d+1) >= 0 && (d+1) < depth)
                {
                    ulong n = ((d+1)*width) + w + 1;
                    assert(n < nregions);
                    for(EschPartitionList *ptr=regions[n]; ptr != 0; ptr = ptr->next)
                    {
                        EschDrawable *item = ptr->item;

                        assertMyth("EschGridPartition::traverse found entry without item",
                                   item != 0);

                        if (!(item->flags & ESCH_DRW_SKIPTRAVERSE))
                        {
                            if (data->func(data->data,item))
                                return ESCH_ERR_STOPPED;
                        }
                    }
                }
                if (w >= 0 && w < width
                    && (d-1) >= 0 && (d-1) < depth)
                {
                    ulong n = ((d-1)*width) + w + 1;
                    assert(n < nregions);
                    for(EschPartitionList *ptr=regions[n]; ptr != 0; ptr = ptr->next)
                    {
                        EschDrawable *item = ptr->item;

                        assertMyth("EschGridPartition::traverse found entry without item",
                                   item != 0);

                        if (!(item->flags & ESCH_DRW_SKIPTRAVERSE))
                        {
                            if (data->func(data->data,item))
                                return ESCH_ERR_STOPPED;
                        }
                    }
                }

                w += wstep;
                daccum += step;
                while (daccum >= Flx16(1))
                {
                    d += dstep;
                    daccum -= Flx16(1);
                }
            }
        }
        //ÄÄÄ Depth major
        else
        {
            Flx16 step = Flx16(dw) / Flx16(dd);

            Flx16 waccum = 0;

            for(long i=0; i <= dd; i++)
            {
                if (w >= 0 && w < width
                    && d >= 0 && d < depth)
                {
                    ulong n = (d*width) + w + 1;
                    assert(n < nregions);
                    for(EschPartitionList *ptr=regions[n]; ptr != 0; ptr = ptr->next)
                    {
                        EschDrawable *item = ptr->item;

                        assertMyth("EschGridPartition::traverse found entry without item",
                                   item != 0);

                        if (!(item->flags & ESCH_DRW_SKIPTRAVERSE))
                        {
                            if (data->func(data->data,item))
                                return ESCH_ERR_STOPPED;
                        }
                    }
                }
                if ((w+1) >= 0 && (w+1) < width
                    && d >= 0 && d < depth)
                {
                    ulong n = (d*width) + (w+1) + 1;
                    assert(n < nregions);
                    for(EschPartitionList *ptr=regions[n]; ptr != 0; ptr = ptr->next)
                    {
                        EschDrawable *item = ptr->item;

                        assertMyth("EschGridPartition::traverse found entry without item",
                                   item != 0);

                        if (!(item->flags & ESCH_DRW_SKIPTRAVERSE))
                        {
                            if (data->func(data->data,item))
                                return ESCH_ERR_STOPPED;
                        }
                    }
                }
                if ((w-1) >= 0 && (w-1) < width
                    && d >= 0 && d < depth)
                {
                    ulong n = (d*width) + (w-1) + 1;
                    assert(n < nregions);
                    for(EschPartitionList *ptr=regions[n]; ptr != 0; ptr = ptr->next)
                    {
                        EschDrawable *item = ptr->item;

                        assertMyth("EschGridPartition::traverse found entry without item",
                                   item != 0);

                        if (!(item->flags & ESCH_DRW_SKIPTRAVERSE))
                        {
                            if (data->func(data->data,item))
                                return ESCH_ERR_STOPPED;
                        }
                    }
                }

                d += dstep;
                waccum += step;
                while (waccum >= Flx16(1))
                {
                    w += wstep;
                    waccum -= Flx16(1);
                }
            }
        }
    }
//ÄÄÄ Area walk
    else
    {
        //ÄÄÄ Use arena for workspace
        if (!(data->flags & ESCH_TRAV_ARENA))
        {
            data->arena = (EschSysInstance) ? EschSysInstance->wspace : 0;
            if (data->arena)
                ivory_arena_clear(data->arena);
        }
        if (!data->arena)
            return ESCH_ERR_NEEDARENA;

        //ÄÄÄ Need status for all regions
        byte *status = new (data->arena) byte[nregions];
        if (!status)
            return ESCH_ERR_NOMEMORY;
        memset(status,UNKNOWN,nregions);

        //ÄÄÄ Setup queue with starting node
        queue_entry *head = new (data->arena) queue_entry(w,d,0);
        if (!head)
            return ESCH_ERR_NOMEMORY;

        queue_entry *tail = head;

        //ÄÄÄ Breadth-first search loop
        while (head != 0)
        {
            d = head->d;
            w = head->w;

            ulong n = (d*width) + w + 1;
            assert(n < nregions);

            if (status[n] != EXPLORED)
            {
                status[n] = EXPLORED;

                //ÄÄÄ Check objects in this region
                for(EschPartitionList *ptr=regions[n]; ptr != 0; ptr = ptr->next)
                {
                    EschDrawable *item = ptr->item;

                    assertMyth("EschGridPartition::traverse found entry without item",
                                item != 0);

                    if (!(item->flags & ESCH_DRW_SKIPTRAVERSE))
                    {
                        if (data->func(data->data,item))
                            return ESCH_ERR_STOPPED;
                    }
                }

                //ÄÄÄ Add undiscovered adjacent regions
                //   +---+---+---+
                //   | 2 | 3 | 4 |
                //   +---+---+---+
                //   | 1 | X | 5 |
                //   +---+---+---+
                //   | 8 | 7 | 6 |
                //   +---+---+---+

                //ÄÄÄ 1
                if ((w-1) >= 0)
                {
                    if (!(data->flags & ESCH_TRAV_DIST)
                        || (head->dist < data->dist))
                    {
                        n = (d*width) + (w-1) + 1;
                        assert(n < nregions);
                        if (status[n] == UNKNOWN)
                        {
                            status[n] = DISCOVERED;

                            queue_entry *q = new (data->arena)
                                          queue_entry(w-1,d,head->dist+size);
                            if (!q)
                                return ESCH_ERR_NOMEMORY;

                            tail->next = q;
                            tail = q;
                        }
                    }
                }

                //ÄÄÄ 2
                if ((w-1) >= 0 && (d-1) >= 0)
                {
                    if (!(data->flags & ESCH_TRAV_DIST)
                        || (head->dist < data->dist))
                    {
                        n = ((d-1)*width) + (w-1) + 1;
                        assert(n < nregions);
                        if (status[n] == UNKNOWN)
                        {
                            status[n] = DISCOVERED;

                            queue_entry *q = new (data->arena)
                                        queue_entry(w-1,d-1,head->dist+size);
                            if (!q)
                                return ESCH_ERR_NOMEMORY;

                            tail->next = q;
                            tail = q;
                        }
                    }
                }

                //ÄÄÄ 3
                if ((d-1) >= 0)
                {
                    if (!(data->flags & ESCH_TRAV_DIST)
                        || (head->dist < data->dist))
                    {
                        n = ((d-1)*width) + w + 1;
                        assert(n < nregions);
                        if (status[n] == UNKNOWN)
                        {
                            status[n] = DISCOVERED;

                            queue_entry *q = new (data->arena)
                                        queue_entry(w,d-1,head->dist+size);
                            if (!q)
                                return ESCH_ERR_NOMEMORY;

                            tail->next = q;
                            tail = q;
                        }
                    }
                }

                //ÄÄÄ 4
                if ((w+1) < width && (d-1) >= 0)
                {
                    if (!(data->flags & ESCH_TRAV_DIST)
                        || (head->dist < data->dist))
                    {
                        n = ((d-1)*width) + (w+1) + 1;
                        assert(n < nregions);
                        if (status[n] == UNKNOWN)
                        {
                            status[n] = DISCOVERED;

                            queue_entry *q = new (data->arena)
                                        queue_entry(w+1,d-1,head->dist+size);
                            if (!q)
                                return ESCH_ERR_NOMEMORY;

                            tail->next = q;
                            tail = q;
                        }
                    }
                }

                //ÄÄÄ 5
                if ((w+1) < width)
                {
                    if (!(data->flags & ESCH_TRAV_DIST)
                        || (head->dist < data->dist))
                    {
                        n = (d*width) + (w+1) + 1;
                        assert(n < nregions);
                        if (status[n] == UNKNOWN)
                        {
                            status[n] = DISCOVERED;

                            queue_entry *q = new (data->arena)
                                        queue_entry(w+1,d,head->dist+size);
                            if (!q)
                                return ESCH_ERR_NOMEMORY;

                            tail->next = q;
                            tail = q;
                        }
                    }
                }

                //ÄÄÄ 6
                if ((w+1) < width && (d+1) < depth)
                {
                    if (!(data->flags & ESCH_TRAV_DIST)
                        || (head->dist < data->dist))
                    {
                        n = ((d+1)*width) + (w+1) + 1;
                        assert(n < nregions);
                        if (status[n] == UNKNOWN)
                        {
                            status[n] = DISCOVERED;

                            queue_entry *q = new (data->arena)
                                        queue_entry(w+1,d+1,head->dist+size);
                            if (!q)
                                return ESCH_ERR_NOMEMORY;

                            tail->next = q;
                            tail = q;
                        }
                    }
                }

                //ÄÄÄ 7
                if ((d+1) < depth)
                {
                    if (!(data->flags & ESCH_TRAV_DIST)
                        || (head->dist < data->dist))
                    {
                        n = ((d+1)*width) + w + 1;
                        assert(n < nregions);
                        if (status[n] == UNKNOWN)
                        {
                            status[n] = DISCOVERED;

                            queue_entry *q = new (data->arena)
                                        queue_entry(w,d+1,head->dist+size);
                            if (!q)
                                return ESCH_ERR_NOMEMORY;

                            tail->next = q;
                            tail = q;
                        }
                    }
                }

                //ÄÄÄ 8
                if ((w-1) >= 0 && (d+1) < depth)
                {
                    if (!(data->flags & ESCH_TRAV_DIST)
                        || (head->dist < data->dist))
                    {
                        n = ((d+1)*width) + (w-1) + 1;
                        assert(n < nregions);
                        if (status[n] == UNKNOWN)
                        {
                            status[n] = DISCOVERED;

                            queue_entry *q = new (data->arena)
                                        queue_entry(w-1,d+1,head->dist+size);
                            if (!q)
                                return ESCH_ERR_NOMEMORY;

                            tail->next = q;
                            tail = q;
                        }
                    }
                }
            }

            //ÄÄÄ Dequeue our head item and continue
            head = head->next;
        }
    }

//ÄÄÄ Walk global
    for(EschPartitionList *ptr=regions[0]; ptr != 0; ptr = ptr->next)
    {
        EschDrawable *item = ptr->item;

        assertMyth("EschGridPartition::traverse found entry without item",
                    item != 0);

        if (!(item->flags & ESCH_DRW_SKIPTRAVERSE))
        {
            if (data->func(data->data,item))
                return ESCH_ERR_STOPPED;
        }
    }

    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschGridPartition - update                                               ³
//                                                                          ³
// Performs an update of the position of a drawable within the partitioning ³
// or all drawables if drw is 0.                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschGridPartition::update(EschDrawable *drw)
{
    if (!regions)
        return ESCH_ERR_INVALIDPARMS;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Update a single drawable
    if (drw)
    {
        if (drw->flags & ESCH_DRW_PARTNSTATIC)
            return ESCH_ERR_NONE;

        //ÄÄÄ Determine 'new' sphere
        EschSphereExtents sphere;
        if (drw->get_extents(&sphere) == -1)
            return ESCH_ERR_NOTSUPPORTED;

        //ÄÄÄ Determine 'new' region
        ulong n=0;

        if (sphere.center.x >= origin.x && sphere.center.z >= origin.z)
        {
            float x = sphere.center.x - origin.x;
            float z = sphere.center.z - origin.z;

            long w = long(x) >> sizeshift;
            long d = long(z) >> sizeshift;

            if (w >= 0 && w < width
                && d >= 0 && d < depth)
            {
                //ÄÄÄ Check to see if it crosses a region boundary
                if ( (long(x + sphere.radius) >> sizeshift) > w
                    || (long(x - sphere.radius) >> sizeshift) < w
                    || (long(z + sphere.radius) >> sizeshift) > d
                    || (long(z - sphere.radius) >> sizeshift) < d )
                {
                    // For now, put in global list...
                    n = 0;
                }
                else
                {
                    n = (d * width) + w + 1;
                }
            }
        }

        //ÄÄÄ First check 'new' region to see if it already in correct place
        assert(n < nregions);
        for(EschPartitionList *optr = regions[n]; optr != 0; optr = optr->next)
        {
            if (optr->item == drw)
                return ESCH_ERR_NONE;
        }

        //ÄÄÄ Otherwise scan and remove current instance
        for(ulong i=0; i < nregions; i++)
        {
            if (i == n)
                continue;

            for(EschPartitionList *ptr = regions[i]; ptr != 0; ptr = ptr->next)
            {
                assertMyth("EschGridPartition::update found entry without item",
                           ptr->item != 0);

                if (ptr->item == drw)
                {
                    optr = ptr;
                    if (ptr->prev)
                        ptr->prev->next = ptr->next;
                    else
                        regions[i] = ptr->next;

                    if (ptr->next)
                        ptr->next->prev = ptr->prev;
                    break;
                }
            }
        }

        if (!optr)
            return ESCH_ERR_NOTFOUND;

        //ÄÄÄ Then insert into new region
        optr->prev = 0;
        optr->next = 0;

        assert(n < nregions);
        if (regions[n])
        {
            optr->next = regions[n];
            regions[n]->prev = optr;
        }

        regions[n] = optr;
    }
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Update all drawables that aren't static
    else
    {
        //ÄÄÄ Process each drawable that isn't static and not already processed
        for(ulong i=0; i < nregions; i++)
        {
            for(EschPartitionList *ptr = regions[i]; ptr != 0; ptr = ptr->next)
            {
                assertMyth("EschGridPartition::update found entry without item",
                           ptr->item != 0);

                if (ptr->item->flags & ESCH_DRW_PARTNSTATIC)
                    continue;

                //ÄÄÄ Determine 'new' sphere
                EschSphereExtents sphere;
                if (ptr->item->get_extents(&sphere) == -1)
                    return ESCH_ERR_NOTSUPPORTED;

                //ÄÄÄ Determine 'new' region
                ulong n=0;

                if (sphere.center.x >= origin.x && sphere.center.z >= origin.z)
                {
                    float x = sphere.center.x - origin.x;
                    float z = sphere.center.z - origin.z;

                    long w = long(x) >> sizeshift;
                    long d = long(z) >> sizeshift;

                    if (w < width && d < depth)
                    {
                        //ÄÄÄ Check to see if it crosses a region boundary
                        if ( (long(x + sphere.radius) >> sizeshift) > w
                            || (long(x - sphere.radius) >> sizeshift) < w
                            || (long(z + sphere.radius) >> sizeshift) > d
                            || (long(z - sphere.radius) >> sizeshift) < d )
                        {
                            // For now, put in global list...
                            n = 0;
                        }
                        else
                        {
                            n = (d * width) + w + 1;
                        }
                    }
                }

                //ÄÄÄ If not already in correct region, move it
                if (i != n)
                {
                    //ÄÄÄ Remove from current region
                    if (ptr->prev)
                        ptr->prev->next = ptr->next;
                    else
                        regions[i] = ptr->next;

                    if (ptr->next)
                        ptr->next->prev = ptr->prev;

                    //ÄÄÄ Insert into new region
                    ptr->next = 0;
                    ptr->prev = 0;

                    assert(n < nregions);
                    if (regions[n])
                    {
                        ptr->next = regions[n];
                        regions[n]->prev = ptr;
                    }

                    regions[n] = ptr;
                }
            }
        }
    }

    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschGridPartition - init                                                 ³
//                                                                          ³
// Initializes the partitioning.                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschGridPartition::init(ushort w, ushort d, float s,
                                         const EschPoint *o)
{
    release();

//ÄÄÄ Verify inputs
    if (!w || !d || !o || s <= 0)
        return ESCH_ERR_INVALIDPARMS;

//ÄÄÄ Determine scale shift for region size
    {
        long msk = 0x1;

        for(ulong i=0; i < 16; i++, msk <<= 1)
        {
            if (msk == long(s))
            {
                size = s;
                sizeshift = i;
                break;
            }
        }

        if (i >= 16)
            return ESCH_ERR_INVALIDPARMS;
    }

//ÄÄÄ Save values
    width = w;
    depth = d;

    origin = *o;

//ÄÄÄ Initialize region lists (plus one for 'global' region)
    nregions = width*depth + 1;

    regions = new EschPartitionList *[nregions];
    if (!regions)
        return ESCH_ERR_NOMEMORY;

    flags |= ESCH_DRW_OWNSDATA;

    memset(regions, 0, sizeof(EschPartitionList*) * nregions);

    return ESCH_ERR_NONE;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschGridPartition - draw_grid                                            ³
//                                                                          ³
// Draws the outline of the grid itself.  Needs the current context to be   ³
// valid.                                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschGridPartition::draw_grid(dword clr) const
{
    EschPoint           p;
    VngoPoint           vpt[8];

//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschGridPartition::draw_grid needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    EschCamera *cam=EschCurrent->camera;

    assertMyth("EschGridPartition::draw_grid needs a viewport in current context's camera",
               cam->vport != NULL);
    VngoVport *vp=cam->vport;

//ÄÄÄ Setup for compare
    float yon = cam->yon;
    float hither = cam->hither;

    int mp = vp->vbuff.pal->shd_pal->mid_point;

//ÄÄÄ Process in loop
    float z = origin.z;
    for(long d = 0; d < depth; d++, z += size)
    {
        float x = origin.x;
        for(long w = 0; w < width; w++, x += size)
        {
            //ÄÄÄ For each of the eight points of the cell
            for(int i=0; i < 8; i++)
            {
                switch (i)
                {
                    case 0:
                        p.x = x;
                        p.y = -size;
                        p.z = z;
                        break;
                    case 1:
                        p.x = x+size;
                        p.y = -size;
                        p.z = z;
                        break;
                    case 2:
                        p.x = x;
                        p.y = size;
                        p.z = z;
                        break;
                    case 3:
                        p.x = x+size;
                        p.y = size;
                        p.z = z;
                        break;
                    case 4:
                        p.x = x;
                        p.y = -size;
                        p.z = z+size;
                        break;
                    case 5:
                        p.x = x+size;
                        p.y = -size;
                        p.z = z+size;
                        break;
                    case 6:
                        p.x = x;
                        p.y = size;
                        p.z = z+size;
                        break;
                    default: /* 7 */
                        p.x = x+size;
                        p.y = size;
                        p.z = z+size;
                        break;
                }
                p.transform(&cam->eye.iorient);

                // If we cross near or far plane, abort draw of extents
                if (p.z < hither || p.z > yon)
                    break;

                vpt[i].x = long((p.x * cam->xscalar) / p.z)
                           + (cam->vport->vbuff.width >> 1);
                vpt[i].y = (cam->vport->vbuff.height >> 1)
                           - long((p.y * cam->yscalar) / p.z);
                vpt[i].z = dword(p.z * cam->z_factor * float(0xffffffff));
                vpt[i].clr = clr;
                vpt[i].shade = mp;
            }

            //ÄÄÄ Draw cell
            if (i >= 8)
            {
                vp->clip_line(&vpt[0],&vpt[1]);
                vp->clip_line(&vpt[1],&vpt[5]);
                vp->clip_line(&vpt[5],&vpt[4]);
                vp->clip_line(&vpt[4],&vpt[0]);
                vp->clip_line(&vpt[2],&vpt[3]);
                vp->clip_line(&vpt[3],&vpt[7]);
                vp->clip_line(&vpt[7],&vpt[6]);
                vp->clip_line(&vpt[6],&vpt[2]);
                vp->clip_line(&vpt[0],&vpt[2]);
                vp->clip_line(&vpt[1],&vpt[3]);
                vp->clip_line(&vpt[5],&vpt[7]);
                vp->clip_line(&vpt[4],&vpt[6]);
            }
        }
    }
}

//°±² End of module - esgpartn.cpp ²±°

