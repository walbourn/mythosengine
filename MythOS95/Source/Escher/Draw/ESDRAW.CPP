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
// The EschDrawable class provides the basic functionality and interface 
// for all drawable objects.  Since it is an abstract class, more 
// functionality must be derived before the object may be used.
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

extern char EschNoName[];

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschDrawable - Constructor                                               �
//                                                                          �
// Initializes the drawable to have no flags, siblings, and 'NoName'.  The  �
// constructing object should pass a type identifier to this constructor.   �
//���������������������������������������������������������������������������
EschDrawable::EschDrawable(word t) :
    inext(0),
    iprev(0),
    dtyp(t),
    limits(ESCH_CAM_SHADE_WIRE
           | ESCH_CAM_SHADE_SOLID
           | ESCH_CAM_SHADE_FLAT
           | ESCH_CAM_SHADE_SMOOTH
           | ESCH_CAM_SHADE_SPECULAR
           | ESCH_CAM_BACKCULL
           | ESCH_CAM_TEXTURED
           | ESCH_CAM_PERSPECTIVE
           | ESCH_CAM_ALPHA
           | ESCH_CAM_SHOW_ALL_LINES),
    flags(0),
    name(EschNoName),
    app_data(0)
{
}

EschDrawable::EschDrawable(const EschDrawable &drw) :
    inext(0),
    iprev(0),
    dtyp(drw.dtyp),
    limits(drw.limits),
    flags(drw.flags & ~ESCH_DRW_OWNSDATA),
    name(drw.name),
    app_data(drw.app_data)
{
}


//�������������������������������������������������������������������������Ŀ
// EschDrawable - Destructor                                                �
//                                                                          �
// Ensures the drawable is removed from any list it resides in.             �
//���������������������������������������������������������������������������
EschDrawable::~EschDrawable()
{
    remove();
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschDrawable - operator =                                                �
//                                                                          �
// Copies the data from another drawable.                                   �
//���������������������������������������������������������������������������
const EschDrawable &EschDrawable::operator = (const EschDrawable &drw)
{
    if (this != &drw)
    {
        limits = drw.limits;
        flags = drw.flags & ~ESCH_DRW_OWNSDATA;
        name = drw.name;
        app_data = drw.app_data;
    }
    return *this;
}


//�������������������������������������������������������������������������Ŀ
// EschDrawable - sibling                                                   �
//                                                                          �
// Makes the drawable a sibling of the 'myprev.' object.  This assumes that �
// the object is not currently attached to anything.                        �
//���������������������������������������������������������������������������
void EschDrawable::sibling(EschDrawable *myprev)
{
    assertMyth("EschDrawable::sibling must have myprev",
               myprev);

    assertMyth("EschDrawable::sibling requires that object not already be in a list",
               inext == 0 && iprev == 0);

    iprev=myprev;
    inext=myprev->inext;

    myprev->inext = this;
    if (inext)
        inext->iprev = this;
}


//�������������������������������������������������������������������������Ŀ
// EschDrawable - remove                                                    �
//                                                                          �
// Removes the drawable from the list.                                      �
//���������������������������������������������������������������������������
void EschDrawable::remove()
{
   if (iprev)
   {
       iprev->inext = inext;
   }

   if (inext)
   {
       inext->iprev = iprev;
   }

   iprev=0;
   inext=0;
}


//�������������������������������������������������������������������������Ŀ
// EschDrawable - find                                                      �
//                                                                          �
// Searches the siblings of the given drawable and returns the Drawable     �
// with the given name, or 0 if not found.                                  �
//���������������������������������������������������������������������������
EschDrawable *EschDrawable::find(const char *dname) const
{
    if (!dname)
        return 0;

    if (!strncmp(dname,name,ESCH_MAX_NAME))
        return (EschDrawable*)this;

    if (!inext)
        return 0;

    return inext->find(dname);
}


//�������������������������������������������������������������������������Ŀ
// EschDrawable - get_extents                                               �
//                                                                          �
// Returns the extent of the drawable in world coordinates and 0, or -1 if  �
// the drawable doesn't support extents.                                    �
//                                                                          �
// The base drawable doesn't support this operation.                        �
//���������������������������������������������������������������������������
int EschDrawable::get_extents(EschSphereExtents *sp) const
{
    return -1;
}


//�������������������������������������������������������������������������Ŀ
// EschDrawable - ray                                                       �
//                                                                          �
// Performs a ray intersection test with the object (or its extents),       �
// returning the distance along the ray for the intersection.               �
// It returns a zero if it missed the object, a positive distance along the �
// ray if it hit, or -1 if the intersection is not supported.               �
//                                                                          �
// The base drawable does a ray/sphere intersection if the drawable         �
// supports get_extents.                                                    �
//���������������������������������������������������������������������������
Flx16 EschDrawable::ray(const EschPoint *pt, const EschVector *v, int coarse) const
{
    assertMyth("EschDrawable::ray needs point and vector",
               pt != 0 && v != 0);

    EschSphereExtents   sphere;

    if (get_extents(&sphere) != 0)
        return Flx16(-1);

    return sphere.ray(pt,v);
}


//�������������������������������������������������������������������������Ŀ
// EschDrawable - hit                                                       �
//                                                                          �
// Performs a sphere intersection test with the object (or its extents),    �
// returning 1 if it hit, 0 if it missed, -1 if not supported.              �
//                                                                          �
// The base drawable does a sphere hit test if the drawable supports        �
// get_extents.                                                             �
//���������������������������������������������������������������������������
int EschDrawable::hit(const EschPoint *pt, const Flx16 r, int coarse) const
{
    assertMyth("EschDrawable::hit needs point and radius",
               pt != 0 && r >= 0);

    EschSphereExtents   sphere;

    if (get_extents(&sphere) != 0)
        return -1;

    return sphere.hit(pt,r);
}


//�������������������������������������������������������������������������Ŀ
// EschDrawable - pick                                                      �
//                                                                          �
// Tests the object against other objects using the parameters in the       �
// communication structure, for picking selection.                          �
//���������������������������������������������������������������������������
esch_error_codes EschDrawable::pick(EschPicking *data) const
{
    if (!data)
        return ESCH_ERR_INVALIDPARMS;

//������������������������������������������������ Setup structure, if needed
    if (!(data->flags & ESCH_PICK_NOSETUP))
    {
        data->count = 0;
        data->result = 0;

        if (!(data->flags & ESCH_PICK_ILIST))
            data->ilist = (EschCurrent) ? EschCurrent->eschs : 0;
        if (!data->ilist)
            return ESCH_ERR_NEEDILIST;

        if (!(data->flags & ESCH_PICK_ARENA))
        {
            data->arena = (EschSysInstance) ? EschSysInstance->wspace : 0;
            if (data->arena)
                ivory_arena_clear(data->arena);
        }
        if (!data->arena)
            return ESCH_ERR_NEEDARENA;

        if (!(data->flags & ESCH_PICK_MAXCOUNT))
            data->maxcount = 1;
        if (data->maxcount < 1)
            return ESCH_ERR_INVALIDPARMS;

        if (data->flags & ESCH_PICK_VPORT)
        {
            if (!(data->flags & ESCH_PICK_CAMERA))
                data->camera = (EschCurrent) ? EschCurrent->camera : 0;

            EschCamera *cam = data->camera;
            if (!cam || !cam->vport)
                return ESCH_ERR_NEEDCAMERA;

            //��� Start ray at camera's position
            cam->get_position(&data->start);

            //��� Assume point is on projection-plane (1),
            //��� reverse project, and transform form eye to world

            EschPoint point( flx_16div16( Flx16(data->sx)
                                          - Flx16(cam->vport->vbuff.width >> 1),
                                          cam->xscalar),
                             flx_16div16( Flx16(cam->vport->vbuff.height >> 1)
                                          - Flx16(data->sy),
                                          cam->yscalar),
                             1);
            point.transform(&cam->eye.orient);
            
            //��� Form vector from point on projection-plane and 
            //��� start position
            data->direction.i = point.x - data->start.x;
            data->direction.j = point.y - data->start.y;
            data->direction.k = point.z - data->start.z;
            data->direction.normalize();
        }
        else if (!(data->flags & ESCH_PICK_WORLD))
            return ESCH_ERR_INVALIDPARMS;

        if (!(data->flags & ESCH_PICK_MAXDIST))
            data->maxdist = Flx16(0x3fffffff,0);
    }

//����������������������������������������������������������������� Walk list
    if (!(data->flags & ESCH_PICK_NOWALK))
    {
        esch_error_codes    err=ESCH_ERR_NONE;

        // Save communication structure for caller
        dword oflags = data->flags & (ESCH_PICK_TESTSELF
                                      | ESCH_PICK_NOSETUP);

        // Inform other routines they don't need to do setup or walk...
        data->flags |= ESCH_PICK_NOWALK
                       | ESCH_PICK_NOSETUP
                       | ESCH_PICK_TESTSELF;

        for(EschDrawable *ptr = data->ilist; ptr != 0; ptr=ptr->next())
        {
            if (!(ptr->flags & ESCH_DRW_SKIPTEST))
            {
                err = ptr->pick(data);
                if (err)
                    break;
            }
        }

        // Restore communication structure for caller
        data->flags &= ~(ESCH_PICK_NOWALK
                         | ESCH_PICK_TESTSELF
                         | ESCH_PICK_NOSETUP);
        data->flags |= oflags;

        return err;
    }

//��������������������������������������������������������������������� Test
    if (data->flags & ESCH_PICK_TESTSELF)
    {
        Flx16 dist = ray(&data->start,
                         &data->direction,
                         (data->flags & ESCH_PICK_COARSE) ? 1 : 0);

        if (dist <= 0)
            return ESCH_ERR_NONE;

        if (data->flags & ESCH_PICK_MAXDIST
            && dist > data->maxdist)
            return ESCH_ERR_NONE;

        EschDrawList *ptr, *prev, *nptr;

        //���� If at maxcount, then remove last item and take space if
        //���� this is closer
        if (data->count >= data->maxcount)
        {
            for(prev=0, ptr=data->result; ptr != 0; prev=ptr, ptr = ptr->next)
            {
                if (!ptr->next)
                    break;
            }

            assert(ptr != 0 && data->maxcount > 0);

            if (ptr->dist <= dist)
                return ESCH_ERR_NONE;

            if (!prev)
                data->result = ptr->next;
            else
                prev->next = 0;

            nptr = ptr;
        }
        //���� Otherwise allocate new list entry
        {
            assert(data->arena != 0);

            nptr = (EschDrawList*) ivory_arena_alloc(data->arena,
                                                        sizeof(EschDrawList));
            if (!nptr)
                return ESCH_ERR_NOMEMORY;
            data->count++;
        }
        nptr->dist = dist;
        nptr->item = (EschDrawable*)this;
        nptr->next = 0;

        //���� Scan list, if any, for correct sort position
        for(prev=0, ptr=data->result; ptr != 0; prev=ptr, ptr = ptr->next)
        {
            if (ptr->dist > dist)
                break;
        }

        //���� Insert into list
        nptr->next = ptr;
        if (!prev)
            data->result = nptr;
        else
        {
            nptr->next = prev->next;
            prev->next = nptr;
        }
    }

    return ESCH_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// EschDrawable - collide                                                   �
//                                                                          �
// Tests the object against other objects using the parameters in the       �
// communication structure, for collision.                                  �
//���������������������������������������������������������������������������
esch_error_codes EschDrawable::collide(EschCollision *data) const
{
    if (!data)
        return ESCH_ERR_INVALIDPARMS;

//������������������������������������������������ Setup structure, if needed
    if (!(data->flags & ESCH_CLSN_NOSETUP))
    {
        data->count = 0;
        data->result = 0;
        data->orig = 0;

        if (!(data->flags & ESCH_CLSN_ILIST))
            data->ilist = (EschCurrent) ? EschCurrent->eschs : 0;
        if (!data->ilist)
            return ESCH_ERR_NEEDILIST;

        if (!(data->flags & ESCH_CLSN_ARENA))
        {
            data->arena = (EschSysInstance) ? EschSysInstance->wspace : 0;
            if (data->arena)
                ivory_arena_clear(data->arena);
        }
        if (!data->arena)
            return ESCH_ERR_NEEDARENA;

        if (!(data->flags & ESCH_CLSN_MAXCOUNT))
            data->maxcount = 1;
        if (data->maxcount < 1)
            return ESCH_ERR_INVALIDPARMS;

        if (!(data->flags & ESCH_CLSN_SPHERE))
        {
            if (get_extents(&data->sphere) != 0)
                return ESCH_ERR_NOTSUPPORTED;

            data->orig = (EschDrawable*)this;
        }
    }

//����������������������������������������������������������������� Walk list
    if (!(data->flags & ESCH_CLSN_NOWALK))
    {
        esch_error_codes    err=ESCH_ERR_NONE;

        // Save communication structure for caller
        dword oflags = data->flags & (ESCH_CLSN_TESTSELF
                                      | ESCH_CLSN_NOSETUP);

        // Inform other routines they don't need to do setup or walk
        // and to test against 'this' since it is the 'target' for
        // the hit detection.

        data->flags |= ESCH_CLSN_NOWALK
                       | ESCH_CLSN_NOSETUP
                       | ESCH_CLSN_TESTSELF;

        for(EschDrawable *ptr = data->ilist; ptr != 0; ptr=ptr->next())
        {
            if (ptr != this && !(ptr->flags & ESCH_DRW_SKIPTEST))
            {
                err = ptr->collide(data);
                if (err)
                    break;
            }
        }

        // Restore communication structure for caller
        data->flags &= ~(ESCH_CLSN_NOWALK
                         | ESCH_CLSN_TESTSELF
                         | ESCH_CLSN_NOSETUP);
        data->flags |= oflags;

        return err;
    }

//��������������������������������������������������������������������� Test
    if (data->flags & ESCH_CLSN_TESTSELF)
    {
        int h = hit(&data->sphere.center,
                    data->sphere.radius,
                    (data->flags & ESCH_CLSN_COARSE) ? 1 : 0);

        if (h != 1)
            return ESCH_ERR_NONE;

        //���� If at maxcount, stop
        if (data->count >= data->maxcount)
        {
            return ESCH_ERR_NONE;
        }

        EschDrawList *ptr, *prev, *nptr;

        //���� Otherwise allocate new list entry
        assert(data->arena != 0);

        nptr = (EschDrawList*) ivory_arena_alloc(data->arena,
                                                 sizeof(EschDrawList));
        if (!nptr)
            return ESCH_ERR_NOMEMORY;
        data->count++;

        nptr->item = (EschDrawable*)this;
        nptr->next = 0;

        //���� Scan list insert at end of list
        for(prev=0, ptr=data->result; ptr != 0; prev=ptr, ptr = ptr->next);

        //���� Insert into list
        if (!prev)
            data->result = nptr;
        else
            prev->next = nptr;
    }

    return ESCH_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// EschDrawable - animate                                                   �
//                                                                          �
// This call is used to inform the drawable to animate itself for the next  �
// frame.  This is called directly by the application when needed.          �
//                                                                          �
// The base drawable does nothing on this call.                             �
//���������������������������������������������������������������������������
void EschDrawable::animate()
{
}

//��� End of module - esdraw.cpp ���
