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

//ÄÄÄ Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschGridPartition::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    EschCamera *cam=EschCurrent->camera;

    assertMyth("EschGridPartition::draw needs a viewport in current context's camera",
               cam->vport != NULL);

//ÄÄÄ Transform view volume into world coords and project onto XZ plane,
//ÄÄÄ forming min/max bound.

    //ÄÄÄ Camera Position
    EschPoint   pos;
    cam->get_position(&pos);

    float minx = pos.x;
    float minz = pos.z;
    float maxx = pos.x;
    float maxz = pos.z;

    //ÄÄÄ Far points
    float tx = cam->yon * cam->xsize;
    float ty = cam->yon * cam->ysize;

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

        assertMyth("EschGridPartition::pick assumes start inside grid...",
                   x >= 0 && z >= 0);

        long w = long(x) >> sizeshift;
        long d = long(z) >> sizeshift;

        float dist = data->maxdist
                     + EschVector (x - float(w)*size,
                                   0,
                                   z - float(d)*size).magnitude();

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
//            Flx16 daccum = (x - Flx16(w)) / Flx16(size);

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
                if (daccum > Flx16(1))
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
//            Flx16 waccum = (z - Flx16(d)) / Flx16(size);

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
                if (waccum > Flx16(1))
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
    EschPartitionList *ptr = new EschPartitionList;
    ptr->item = drw;
    ptr->next = 0;
    ptr->prev = 0;

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
//
// This still needs to be implemented...
//
    return ESCH_ERR_NOTSUPPORTED;
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

//°±² End of module - esgpartn.cpp ²±°

