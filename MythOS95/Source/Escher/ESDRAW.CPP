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
//ùùùùùùùùùùùCopyrightù(c)ù1994-1996ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
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
// esdraw.cpp
//
// The EschDrawable class provides the basic functionality and interface 
// for all drawable objects.  Since it is an abstract class, more 
// functionality must be derived before the object may be used.
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
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern char EschNoName[];

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschDrawable - Constructor                                               ³
//                                                                          ³
// Initializes the drawable to have no flags, siblings, and 'NoName'.  The  ³
// constructing object should pass a type identifier to this constructor.   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
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
           | ESCH_CAM_SHOW_ALL_LINES),
    flags(0),
    name(EschNoName)
{
}

EschDrawable::EschDrawable(const EschDrawable &drw) :
    inext(0),
    iprev(0),
    dtyp(drw.dtyp),
    limits(drw.limits),
    flags(drw.flags & ~ESCH_DRW_OWNSDATA),
    name(drw.name)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschDrawable - Destructor                                                ³
//                                                                          ³
// Ensures the drawable is removed from any list it resides in.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschDrawable::~EschDrawable()
{
    remove();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschDrawable - operator =                                                ³
//                                                                          ³
// Copies the data from another drawable.                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
const EschDrawable &EschDrawable::operator = (const EschDrawable &drw)
{
    if (this != &drw)
    {
        limits = drw.limits;
        flags = drw.flags & ~ESCH_DRW_OWNSDATA;
        name = drw.name;
    }
    return *this;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschDrawable - sibling                                                   ³
//                                                                          ³
// Makes the drawable a sibling of the 'myprev.' object.  This assumes that ³
// the object is not currently attached to anything.                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschDrawable - remove                                                    ³
//                                                                          ³
// Removes the drawable from the list.                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschDrawable - find                                                      ³
//                                                                          ³
// Searches the siblings of the given drawable and returns the Drawable     ³
// with the given name, or 0 if not found.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschDrawable *EschDrawable::find(const char *dname) const
{
    const EschDrawable *ptr;

    if (!dname)
        return 0;

//ÄÄÄ First scan up previous chain to find first Drawable in list.
    for(ptr=iprev; ptr != 0 && ptr->iprev; ptr = ptr->iprev);

    if (!ptr)
        ptr=this;

//ÄÄÄ Now scan all Drawables searching for first Drawable that matches the
//ÄÄÄ given name.
    for(; ptr != 0; ptr = ptr->inext)
    {
        if (ptr->name && !strncmp(dname,ptr->name,ESCH_MAX_NAME))
            return (EschDrawable*)ptr;
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschDrawable - get_extents                                               ³
//                                                                          ³
// Returns the extent of the drawable in world coordinates and 0, or -1 if  ³
// the drawable doesn't support extents.                                    ³
//                                                                          ³
// The base drawable doesn't support this operation.                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschDrawable::get_extents(EschSphereExtents *sp) const
{
    return -1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschDrawable - ray                                                       ³
//                                                                          ³
// Performs a ray intersection test with the object (or its extents),       ³
// returning the distance along the ray for the intersection.               ³
// It returns a zero if it missed the object, a positive distance along the ³
// ray if it hit, or -1 if the intersection is not supported.               ³
//                                                                          ³
// The base drawable does a ray/sphere intersection if the drawable         ³
// supports get_extents.                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
Flx16 EschDrawable::ray(const EschPoint *pt, const EschVector *v, int coarse) const
{
    assertMyth("EschDrawable::ray needs point and vector",
               pt != 0 && v != 0);

    EschSphereExtents   sphere;

    if (get_extents(&sphere) != 0)
        return Flx16(-1);

    return sphere.ray(pt,v);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschDrawable - hit                                                       ³
//                                                                          ³
// Performs a sphere intersection test with the object (or its extents),    ³
// returning 1 if it hit, 0 if it missed, -1 if not supported.              ³
//                                                                          ³
// The base drawable does a sphere hit test if the drawable supports        ³
// get_extents.                                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschDrawable::hit(const EschPoint *pt, const Flx16 r, int coarse) const
{
    assertMyth("EschDrawable::hit needs point and radius",
               pt != 0 && r >= 0);

    EschSphereExtents   sphere;

    if (get_extents(&sphere) != 0)
        return -1;

    return sphere.hit(pt,r);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschDrawable - pick                                                      ³
//                                                                          ³
// Tests the object against other objects using the parameters in the       ³
// communication structure, for picking selection.                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschDrawable::pick(EschPicking *data) const
{
    if (!data)
        return ESCH_ERR_INVALIDPARMS;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Setup structure, if needed
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

            //ÄÄÄ Start ray at camera's position
            cam->get_position(&data->start);

            //ÄÄÄ Assume point is on projection-plane (1),
            //ÄÄÄ reverse project, and transform form eye to world

            EschPoint point( flx_16div16( Flx16(data->sx)
                                          - Flx16(cam->vport->vbuff.width >> 1),
                                          cam->xscalar),
                             flx_16div16( Flx16(cam->vport->vbuff.height >> 1)
                                          - Flx16(data->sy),
                                          cam->yscalar),
                             1);
            point.transform(&cam->eye.orient);
            
            //ÄÄÄ Form vector from point on projection-plane and 
            //ÄÄÄ start position
            data->direction.i = point.x - data->start.x;
            data->direction.j = point.y - data->start.y;
            data->direction.k = point.z - data->start.z;
            data->direction.normalize();
        }
        else if (!(data->flags & ESCH_PICK_WORLD))
            return ESCH_ERR_INVALIDPARMS;

        if (!(data->flags & ESCH_PICK_MAXDIST))
            data->maxdist = Flx16(0x7fffffff,0);
    }

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Walk list
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

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Test
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

        //ÄÄÄÄ If at maxcount, then remove last item and take space if
        //ÄÄÄÄ this is closer
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
        //ÄÄÄÄ Otherwise allocate new list entry
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

        //ÄÄÄÄ Scan list, if any, for correct sort position
        for(prev=0, ptr=data->result; ptr != 0; prev=ptr, ptr = ptr->next)
        {
            if (ptr->dist > dist)
                break;
        }

        //ÄÄÄÄ Insert into list
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschDrawable - collide                                                   ³
//                                                                          ³
// Tests the object against other objects using the parameters in the       ³
// communication structure, for collision.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschDrawable::collide(EschCollision *data) const
{
    if (!data)
        return ESCH_ERR_INVALIDPARMS;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Setup structure, if needed
    if (!(data->flags & ESCH_CLSN_NOSETUP))
    {
        data->count = 0;
        data->result = 0;

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
        }
    }

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Walk list
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

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Test
    if (data->flags & ESCH_CLSN_TESTSELF)
    {
        int h = hit(&data->sphere.center,
                    data->sphere.radius,
                    (data->flags & ESCH_CLSN_COARSE) ? 1 : 0);

        if (h != 1)
            return ESCH_ERR_NONE;

        //ÄÄÄÄ If at maxcount, stop
        if (data->count >= data->maxcount)
        {
            return ESCH_ERR_NONE;
        }

        EschDrawList *ptr, *prev, *nptr;

        //ÄÄÄÄ Otherwise allocate new list entry
        assert(data->arena != 0);

        nptr = (EschDrawList*) ivory_arena_alloc(data->arena,
                                                 sizeof(EschDrawList));
        if (!nptr)
            return ESCH_ERR_NOMEMORY;
        data->count++;

        nptr->item = (EschDrawable*)this;
        nptr->next = 0;

        //ÄÄÄÄ Scan list insert at end of list
        for(prev=0, ptr=data->result; ptr != 0; prev=ptr, ptr = ptr->next);

        //ÄÄÄÄ Insert into list
        if (!prev)
            data->result = nptr;
        else
            prev->next = nptr;
    }

    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschDrawable - animate                                                   ³
//                                                                          ³
// This call is used to inform the drawable to animate itself for the next  ³
// frame.  This is called directly by the application when needed.          ³
//                                                                          ³
// The base drawable does nothing on this call.                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschDrawable::animate()
{
}

//°±² End of module - esdraw.cpp ²±°

