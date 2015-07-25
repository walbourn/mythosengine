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
// esgeom.cpp
//
// Contains the code for the EschGeometry class which forms the basic
// opertional code and data for the 3D objects in the environment.
//
// EschGeometry is the abstract base class for the 3D objects which includes 
// the tree connections, frame of reference, extents, and various object
// operations.
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
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschGeometry - Constructor                                               �
//                                                                          �
// Initializes the data.                                                    �
//���������������������������������������������������������������������������
EschGeometry::EschGeometry() :
    EschDrawable(ESCH_DRWT_GEOM),
    iparent (0),
    ichild (0)
{
}

EschGeometry::EschGeometry(const EschGeometry &g) :
    EschDrawable(g),
    iparent (0),
    ichild (0),
    local (g.local),
    world (g.local),
    sphere (g.sphere),
    exts (g.exts)
{
}


//�������������������������������������������������������������������������Ŀ
// EschGemoetry - Destructor                                                �
//                                                                          �
// Removes the geometry from any list it resides in.                        �
//���������������������������������������������������������������������������
EschGeometry::~EschGeometry()
{
    remove(0);
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschGeometry - operator =                                                �
//                                                                          �
// Copies the data from another geometry.                                   �
//���������������������������������������������������������������������������
const EschGeometry &EschGeometry::operator = (const EschGeometry &geom)
{
    if (this != &geom)
    {
        EschDrawable::operator = (geom);

        local = geom.local;
        sphere = geom.sphere;
        exts = geom.exts;

        compute_world();
    }
    return *this;
}


//�������������������������������������������������������������������������Ŀ
// EschGeometry - draw                                                      �
//                                                                          �
// This routine performs a draw of the child of this instance.  This routine�
// should be called at the end of the inherited draw handlers.              �
//���������������������������������������������������������������������������
void EschGeometry::draw()
{
    EschGeometry    *ptr;

    for(ptr=ichild; ptr != 0; ptr = (EschGeometry *)ptr->inext)
    {
        if (!(ptr->flags & ESCH_DRW_SKIP))
            ptr->draw();
    }
}


//�������������������������������������������������������������������������Ŀ
// EschGeometry - sibling                                                   �
//                                                                          �
// This routine inserts the object into the geometry tree as the sibling of �
// the given object.                                                        �
//���������������������������������������������������������������������������
void EschGeometry::sibling(EschGeometry *myprev, dword update)
{
    assertMyth("EschGeometry::sibling must have myprev",
               myprev);

    assertMyth("EschGeometry::sibling requires that object not already be in a list",
               iparent == 0 && inext == 0 && iprev == 0);

    iprev=myprev;
    inext=myprev->inext;

    myprev->inext = this;
    if (inext)
        ((EschGeometry*)inext)->iprev = (EschDrawable*)this;

    iparent = myprev->iparent;

//��� Parent's extents are now invalid, update if requested
    if (iparent && (update & ESCH_UPD_EXTENTS))
    {
        iparent->compute_extents(1);
    }
}


//�������������������������������������������������������������������������Ŀ
// EschGeometry - adopt                                                     �
//                                                                          �
// This routine inserts the object into the geometry tree as the child of   �
// the given object.                                                        �
//���������������������������������������������������������������������������
void EschGeometry::adopt(EschGeometry *myparent, dword update)
{
    EschDrawable    *ptr;

    assertMyth("EschGeometry::adopt must have myparent",
               myparent);

    assertMyth("EschGeometry::adopt requires that object not already be in a list",
               iparent == 0 && inext == 0 && iprev == 0);
   
    iparent = myparent;

    if (iparent->ichild)
    {
        for(ptr=(EschDrawable*) iparent->ichild;
            ptr != 0;
            ptr = ((EschGeometry*)ptr)->inext)
        {
            if (((EschGeometry*)ptr)->inext == 0)
            {
                ((EschGeometry*)ptr)->inext = this;
                iprev = ptr;
                break;
            }
        }
    }
    else
    {
        iparent->ichild = this;
    }

    if (update & ESCH_UPD_WORLD)
        compute_world(update);
}


//�������������������������������������������������������������������������Ŀ
// EschGeometry - remove                                                    �
//                                                                          �
// Remove object from tree.  If delchild is set, then the children are      �
// deleted.                                                                 �
//���������������������������������������������������������������������������
void EschGeometry::remove(int delchild, dword update)
{
    EschGeometry    *parent=iparent;

    if (iparent)
    {
        if (iparent->ichild == this)
        {
            if (iprev)
                iparent->ichild = (EschGeometry*)iprev;
            else
                iparent->ichild = (EschGeometry*)inext;
        }

        iparent=0;
    }

    EschDrawable::remove();

//��� Parent's extents are now invalid, update if requested
    if (parent && (update & ESCH_UPD_EXTENTS))
    {
        parent->compute_extents(1);
    }

//��� Delete children, if requested
    if (delchild)
    {
        for (EschGeometry *ptr=ichild; ptr;)
        {
            EschGeometry *t=ptr;
            ptr = (EschGeometry*) ptr->next();
            t->remove(1);
            delete t;
        }
        ichild=0;
    }

//��� Update world, if requested
    if (update & ESCH_UPD_WORLD)
        compute_world(update);
}


//�������������������������������������������������������������������������Ŀ
// EschGeometry - find                                                      �
//                                                                          �
// Searches the siblings and child of the current geometry object for the   �
// given name, or 0 if not found.                                           �
//���������������������������������������������������������������������������
EschDrawable *EschGeometry::find(const char *dname) const
{
    if (!dname)
        return 0;

    if (!strncmp(dname,name,ESCH_MAX_NAME))
        return (EschDrawable*)this;

    if (ichild)
    {
        EschDrawable *t = ichild->find(dname);
        if (t)
            return t;
    }

    if (!inext)
        return 0;

    return inext->find(dname);
}


//�������������������������������������������������������������������������Ŀ
// EschGeometry - get_extents                                               �
//                                                                          �
// Returns the extent of the geometry in world coordinates and 0.           �
//���������������������������������������������������������������������������
int EschGeometry::get_extents(EschSphereExtents *sp) const
{
    assertMyth("EschGeometry::get_extents assumes original extents in 'sphere'",
               sphere != 0 && sphere->radius >= 0);

    assertMyth("EschGeometry::get_extents needs return sphere extents",
               sp != 0);

    sphere->center.transform(&world.orient,&sp->center);
    sp->radius = flx_16mul16(sphere->radius,world.scalef);

    assertMyth("EschGeometry::get_extents transformed to invalid radius",
               sp->radius >= 0);

    return 0;
}


//�������������������������������������������������������������������������Ŀ
// EschGeometry - ray                                                       �
//                                                                          �
// Performs a ray intersection test with the object (or its extents),       �
// returning the distance along the ray for the intersection.               �
// It returns a zero if it missed the object, a positive distance along the �
// ray if it hit, or -1 if the intersection is not supported.               �
//���������������������������������������������������������������������������
Flx16 EschGeometry::ray(const EschPoint *pt, const EschVector *v, int coarse) const
{
    assertMyth("EschGeometry::ray needs point and vector",
               pt != 0 && v != 0);

    assertMyth("EschGeometry::ray assumes original extents in 'sphere'",
               sphere != 0 && sphere->radius >= 0);

//��� Transform ray into local coordinates
    EschPoint   point;
    pt->transform(&world.iorient,&point);

    EschVector  ray;
    v->transform(&world.iorient,&ray);

// Adds more error not doing this, but probably OK...
//  ray.normalize();

//��� Perform intersection check (Ray/Sphere intersection)
    Flx16 dist=sphere->ray(&point,&ray);
    
    if (dist.flx <= 0)
        return 0;

    return ((world.scalef == 1) ? dist : (dist * world.scalef));
}


//�������������������������������������������������������������������������Ŀ
// EschGeometry - hit                                                       �
//                                                                          �
// Performs a sphere intersection test with the object (or its extents),    �
// returning 1 if it hit, 0 if it missed, -1 if not supported.              �
//���������������������������������������������������������������������������
int EschGeometry::hit(const EschPoint *pt, const Flx16 r, int coarse) const
{
    assertMyth("EschGeometry::hit needs point and radius",
               pt != 0 && r >= 0);

    assertMyth("EschGeometry::hit assumes original extents in 'sphere'",
               sphere != 0 && sphere->radius >= 0);

    EschPoint   center;
    pt->transform(&world.iorient,&center);

    return sphere->hit(&center,(world.scalef == 1)
                               ? r : flx_16div16(r,world.scalef));
}


//�������������������������������������������������������������������������Ŀ
// EschGeometry - pick                                                      �
//                                                                          �
// Tests the object against other objects using the parameters in the       �
// communication structure, for picking selection.                          �
//���������������������������������������������������������������������������
esch_error_codes EschGeometry::pick(EschPicking *data) const
{
    if (!data)
        return ESCH_ERR_INVALIDPARMS;

//��� We want to intercept test self case only...
    if (data->flags & ESCH_PICK_TESTSELF)
    {
        if ((data->flags & (ESCH_PICK_NOWALK|ESCH_PICK_NOSETUP))
            != (ESCH_PICK_NOWALK|ESCH_PICK_NOSETUP))
            return ESCH_ERR_INVALIDPARMS;

        //��� Test to see if ray hit our expanded extent first to 
        //��� see if this object or any of its children should be checked

        // Transform ray into local coords
        EschPoint   point;
        data->start.transform(&world.iorient,&point);

        EschVector  ray;
        data->direction.transform(&world.iorient,&ray);
        ray.normalize();

        // Test
        if (exts.ray(&point,&ray) <= 0)
            return ESCH_ERR_NONE;

        //��� Do standard operation on 'this'
        esch_error_codes err=ESCH_ERR_NONE;

        err=EschDrawable::pick(data);
        if (err)
            return err;

        //��� Call for children
        if (ichild)
        {
            for (EschGeometry *ptr=ichild; ptr != 0; ptr = ptr->next())
            {
                err=ptr->pick(data);
                if (err)
                    return err;
            }
        }

        return ESCH_ERR_NONE;
    }

//��� Otherwise use base implementation
    return EschDrawable::pick(data);
}


//�������������������������������������������������������������������������Ŀ
// EschGeometry - collide                                                   �
//                                                                          �
// Tests the object against other objects using the parameters in the       �
// communication structure, for collision.                                  �
//���������������������������������������������������������������������������
esch_error_codes EschGeometry::collide(EschCollision *data) const
{
    if (!data)
        return ESCH_ERR_INVALIDPARMS;

//��� We want to intercept test self case only...
    if (data->flags & ESCH_CLSN_TESTSELF)
    {
        if ((data->flags & (ESCH_CLSN_NOWALK|ESCH_CLSN_NOSETUP))
            != (ESCH_CLSN_NOWALK|ESCH_CLSN_NOSETUP))
            return ESCH_ERR_INVALIDPARMS;

        //��� Test to see if we hit our expanded extent first to 
        //��� see if this object or any of its children should be checked

        // Transform test sphere into local coords
        EschPoint   center;
        data->sphere.center.transform(&world.iorient,&center);

        // Test
        if (exts.hit(&center,
                     flx_16div16(data->sphere.radius,world.scalef)) != 1)
            return ESCH_ERR_NONE;

        //��� Do standard operation on 'this'
        esch_error_codes err=ESCH_ERR_NONE;

        err=EschDrawable::collide(data);
        if (err)
            return err;

        //��� Call for children
        if (ichild)
        {
            for (EschGeometry *ptr=ichild; ptr != 0; ptr = ptr->next())
            {
                err=ptr->collide(data);
                if (err)
                    return err;
            }
        }

        return ESCH_ERR_NONE;
    }

//��� Otherwise use base implementation
    return EschDrawable::collide(data);
}


//�������������������������������������������������������������������������Ŀ
// EschGeometry - animate                                                   �
//                                                                          �
// This routine passes the animate calls down to the children objects.      �
//���������������������������������������������������������������������������
void EschGeometry::animate()
{
    for (EschGeometry *ptr=ichild; ptr; ptr = (EschGeometry*) ptr->next())
    {                                   
        if (!(ptr->flags & ESCH_DRW_SKIPANIMATE))
            ptr->animate();
    }
}



//���������������������������������������������������������������������������
//���������������������������  Compute Functions  ���������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschGeometry - compute_world                                             �
//                                                                          �
// This routine computes the local to world transform for the object.       �
//���������������������������������������������������������������������������
void EschGeometry::compute_world(dword update)
{
    EschGeometry    *ptr;

//��� Compute based on parent
    if (iparent)
    {
        if (update & ESCH_UPD_INVERSE)
            local.concat(&iparent->world,&world);
        else
            local.orient.concat(&iparent->world.orient,&world.orient);

        world.ortho_count=0;
    }
    else
    {
        world = local;
    }

//��� If there are children, must compute them as well since our
//��� world changed.

    for(ptr=ichild; ptr != 0; ptr = (EschGeometry*) ptr->inext)
    {
        ptr->compute_world(update & ~ESCH_UPD_EXTENTS);
    }

//��� Parent's extents are now invalid, update if requested
    if (iparent && (update & ESCH_UPD_EXTENTS))
    {
        iparent->compute_extents(1);
    }
}


//�������������������������������������������������������������������������Ŀ
// EschGeometry - compute_extents                                           �
//                                                                          �
// This routine computes the spherical extents such that they include the   �
// children of geometry objects (this ensure that trivial rejection applies �
// to the entire subtree).  If partialfix is 0, then the entire sub-tree,   �
// starting at the current object, will be recomputed.  If partialfix is    �
// non-zero, then the spherical extents will be recomputed from the         �
// immediate children (assumes children are up-to-date).                    �
//���������������������������������������������������������������������������
void EschGeometry::compute_extents(int partialfix, int doparent)
{
    EschGeometry    *ptr;
    Flx16           diff;
    Flx16           maxdiff;
    EschPoint       pt;
    Flx16           r;

//��� Redo children, if not doing a partial fix (don't have children
//��� call parent or we'll loop infinetly).
    if (ichild && !partialfix)
    {
        ichild->compute_extents(0,0);
    }

//��� Recompute spherical extents from 'original' and children
    assertMyth("EschGeometry::compute_extents assumes original extents in 'sphere'",
               sphere != 0);

    if (!sphere)
        return;

    exts = *sphere;

    //��� Expand for each child
    for(ptr=ichild; ptr != 0; ptr = (EschGeometry*) ptr->inext)
    {
        // Transform child's extents into its parent's coordinates
        // (since we are its parent, it will be in our local coordinates
        // after the transform).

        ptr->exts.center.transform(&ptr->local,&pt);
        r = flx_16mul16( ptr->exts.radius, ptr->local.scalef );

        // Extend our extents to include child, if needed
        // (for simplicity, we won't allow our center to move).

        EschVector  v(pt.x - exts.center.x,
                      pt.y - exts.center.y,
                      pt.z - exts.center.z);

        Flx16 m = v.magnitude() + r;

        if (m > exts.radius)
            exts.radius = m;
    }

//��� Since our extents have changed, must update our parent
    if (iparent && doparent)
        iparent->compute_extents(1);
}

//��� End of module - esgeom.cpp ���
