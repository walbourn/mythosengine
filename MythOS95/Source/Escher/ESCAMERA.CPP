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
//ùùùùùùùùùùCopyrightù(c)ù1994,ù1995ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
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
// escamera.cpp
//
//      The EschCamera object is the control object for the viewing of
//      the drawable objects.  The EschCamera has associated viewing
//      parameters to provide the needed transformation information.
//      EschCameras can be linked into lists and loaded from files.
//
//      A Van Gogh viewport is required for the camera to operate, so
//      one should be created and attached to the camera.  The camera
//      can only be attached to a single Van Gogh viewport at any given
//      time.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"
#include "esfile.hpp"

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
// EschCamera - Constructor                                                 ³
//                                                                          ³
// Initializes the camera object, attaching the Van Gogh viewport, if       ³
// given -or- loads the camera from the given file/name.                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschCamera::EschCamera(VngoVport *vp)
{
    vport=0;

    aspect_ratio = 1;
    iprev=inext=0;
    flags=0;

    bcolor=0;

    strcpy(name,EschNoName);

//ÄÄÄ Default camera parameters ÄÄÄ
    reset();

    if (vp)
    {
        attach(vp);
    }
    else
        vport = 0;

};

EschCamera::EschCamera(const char *fname, const char *cname)
{
    vport=0;

    aspect_ratio = 1;
    iprev=inext=0;
    flags=0;

    bcolor=0;

    hither=1;                               // Arbitrary start values.
    yon=0x3fff;
    factor=1;                               // No user zoom factor by default.

    strcpy(name,cname ? cname : EschNoName);

    if (load(fname,cname))
        reset();
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - Destructor                                                  ³
//                                                                          ³
// Unlinks the camera from the the list.                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschCamera::~EschCamera()
{
    remove();
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - attach                                                      ³
//                                                                          ³
// Attaches the camera to a Van Gogh viewport.  This recompute the aspect   ³
// ratio and sets the internal viewport pointer.                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::attach(VngoVport *vp)
{
    Flx16  max_z_size=1;
    vport=vp;

    if (!vp)
        return;

    // Aspect ratio should result in 4:3 X to Y pixels
    //
    //  ( 4 * height ) / ( 3 * width )
    //
    aspect_ratio.flx = flx_16div16( Flx16(vport->get_vbuff()->height<<18,0),
                                    flx_16mul16( (Flx16)3, 
                                         (Flx16)vport->get_vbuff()->width)).flx;

    compute_scalar();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - sibling                                                     ³
//                                                                          ³
// Makes the camera a sibling of the 'myprev.' object.  This assumes that   ³
// the object is not currently attached to anything.                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::sibling(EschCamera *myprev)
{
    assertMyth("EschCamera::sibling must have myprev",
               myprev);

    assertMyth("EschCamera::sibling requires that object not already be in a list",
               inext == 0 && iprev == 0);

    iprev=myprev;
    inext=myprev->inext;

    myprev->inext = this;
    if (inext)
        inext->iprev = this;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - remove                                                      ³
//                                                                          ³
// Removes the camera from the list of cameras.                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::remove(void)
{
    if (iprev)
    {
        iprev->inext = inext;
    }

    if (inext)
    {
        inext->iprev = iprev;
    }

    inext=0;
    iprev=0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - find                                                        ³
//                                                                          ³
// Searches the siblings of the given camera and returns the camera object  ³
// with the given name, or 0 if not found.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschCamera *EschCamera::find(const char *cname)
{
    EschCamera *ptr;

    if (!cname)
        return 0;

//ÄÄÄ First scan up previous chain to find first camera in list.
    for(ptr=iprev; ptr != 0 && ptr->iprev; ptr = ptr->iprev);

    if (!ptr)
        ptr=this;

//ÄÄÄ Now scan all cameras searching for first camera that matches the
//ÄÄÄ given name.
    for(; ptr != 0; ptr = ptr->inext)
    {
        if (!strncmp(cname,ptr->name,ESCH_MAX_NAME))
            return ptr;
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - rend                                                        ³
//                                                                          ³
// Renders the current context to the camera.                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::rend(void)
{
    EschDrawable    *ptr;

    if (!vport)
        return;

//ÄÄÄ Clear viewport/reset background bitmap
    if (!(flags & ESCH_CAM_NOCLEAR))
    {
        vport->clear_screen_on();
        vport->reset(bcolor);
    }

//ÄÄÄ Draw list of EschDrawables
    for(ptr=EschCurrent->eschs; ptr != NULL; ptr = ptr->next())
    {
        if (!(ptr->flags & ESCH_DRW_SKIP))
            ptr->draw();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - reset                                                       ³
//                                                                          ³
// Sets the camera up to default parameters.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::reset(void)
{
//ÄÄÄ Default camera parameters ÄÄÄ
    eye.set_position(0,0,0);

    eye.dir.i = 0;                          // Looking down positive Z.
    eye.dir.j = 0;
    eye.dir.k = 1;

    top.i=0;                                // Head is positive Y.
    top.j=1;
    top.k=0;

    hither=1;                               // Arbitrary start values.
    yon=0x3fff;

    fov=48;                                 // Default used by 3DS, so why not?

    factor=1;                               // No user zoom factor by default.


//ÄÄÄ Call computation functions
    compute_scalar();
    compute_eye();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - set_vects                                                   ³
//                                                                          ³
// Sets the camera up based on direction and top vectors.                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::set_vects(const EschVector *t, const EschVector *d)
{
    top=*t;
    top.normalize();

    eye.dir=*d;
    eye.dir.normalize();

//ÄÄÄ Call computation function
    compute_eye();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - set_lookat                                                  ³
//                                                                          ³
// Sets the direction and top vector based on a look-at point.              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::set_lookat(const EschPoint  *pt)
{
    EschPoint   pos;

    get_position(&pos);

//ÄÄÄ Determine direction from lookat point and position
    eye.dir.i.flx = pt->x.flx - pos.x.flx;
    eye.dir.j.flx = pt->y.flx - pos.y.flx;
    eye.dir.k.flx = pt->z.flx - pos.z.flx;

    orthogonalize();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - rotatex                                                     ³
//                                                                          ³
// Addes a rotation of 'degrees' degrees to the frame of reference about the³
// X-axis.                                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::rotatex(const Flx16 degrees)
{
    if (eye.ortho_count+1 > ESCH_MAX_ORTHOCOUNT)
    {
        eye.ortho_count=0;
        eye.rotatex(degrees);
        orthogonalize();
    }
    else
        eye.rotatex(degrees);

//ÄÄÄ Update top vector
    top.i.flx = eye.orient.mtx[ESCH_MTX_D].flx;
    top.j.flx = eye.orient.mtx[ESCH_MTX_E].flx;
    top.k.flx = eye.orient.mtx[ESCH_MTX_F].flx;
    top.normalize();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - rotatey                                                     ³
//                                                                          ³
// Addes a rotation of 'degrees' degrees to the frame of reference about the³
// Y-axis.                                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::rotatey(const Flx16 degrees)
{
    if (eye.ortho_count+1 > ESCH_MAX_ORTHOCOUNT)
    {
        eye.ortho_count=0;
        eye.rotatey(degrees);
        orthogonalize();
    }
    else
        eye.rotatey(degrees);

//ÄÄÄ Update top vector
    top.i.flx = eye.orient.mtx[ESCH_MTX_D].flx;
    top.j.flx = eye.orient.mtx[ESCH_MTX_E].flx;
    top.k.flx = eye.orient.mtx[ESCH_MTX_F].flx;
    top.normalize();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - rotatez                                                     ³
//                                                                          ³
// Addes a rotation of 'degrees' degrees to the frame of reference about the³
// Z-axis.                                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::rotatez(const Flx16 degrees)
{
    if (eye.ortho_count+1 > ESCH_MAX_ORTHOCOUNT)
    {
        eye.ortho_count=0;
        eye.rotatez(degrees);
        orthogonalize();
    }
    else
        eye.rotatez(degrees);

//ÄÄÄ Update top vector
    top.i.flx = eye.orient.mtx[ESCH_MTX_D].flx;
    top.j.flx = eye.orient.mtx[ESCH_MTX_E].flx;
    top.k.flx = eye.orient.mtx[ESCH_MTX_F].flx;
    top.normalize();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - pitch                                                       ³
//                                                                          ³
// Addes a rotation of 'degrees' degrees to the frame of reference about the³
// relative X-axis.                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::pitch(const Flx16 degrees)
{
    if (eye.ortho_count+1 > ESCH_MAX_ORTHOCOUNT)
    {
        eye.ortho_count=0;
        eye.pitch(degrees);
        orthogonalize();
    }
    else
        eye.pitch(degrees);

//ÄÄÄ Update top vector
    top.i.flx = eye.orient.mtx[ESCH_MTX_D].flx;
    top.j.flx = eye.orient.mtx[ESCH_MTX_E].flx;
    top.k.flx = eye.orient.mtx[ESCH_MTX_F].flx;
    top.normalize();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - yaw                                                         ³
//                                                                          ³
// Addes a rotation of 'degrees' degrees to the frame of reference about the³
// relative Y-axis.                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::yaw(const Flx16 degrees)
{
    if (eye.ortho_count+1 > ESCH_MAX_ORTHOCOUNT)
    {
        eye.ortho_count=0;
        eye.yaw(degrees);
        orthogonalize();
    }
    else
        eye.yaw(degrees);

//ÄÄÄ Update top vector
    top.i.flx = eye.orient.mtx[ESCH_MTX_D].flx;
    top.j.flx = eye.orient.mtx[ESCH_MTX_E].flx;
    top.k.flx = eye.orient.mtx[ESCH_MTX_F].flx;
    top.normalize();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - roll                                                        ³
//                                                                          ³
// Addes a rotation of 'degrees' degrees to the frame of reference about the³
// relative Z-axis.                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::roll(const Flx16 degrees)
{
    if (eye.ortho_count+1 > ESCH_MAX_ORTHOCOUNT)
    {
        eye.ortho_count=0;
        eye.roll(degrees);
        orthogonalize();
    }
    else
        eye.roll(degrees);

//ÄÄÄ Update top vector
    top.i.flx = eye.orient.mtx[ESCH_MTX_D].flx;
    top.j.flx = eye.orient.mtx[ESCH_MTX_E].flx;
    top.k.flx = eye.orient.mtx[ESCH_MTX_F].flx;
    top.normalize();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - orthogonalize                                               ³
//                                                                          ³
// Ensures that the matrix is an orthonormal basis, ensuring that no        ³
// undesired scaling or shearing occurrs due to accumulated error in updates³
// from rotations.                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::orthogonalize(void)
{
    eye.dir.normalize();

    Flx16 dot = top DOT eye.dir;

    top.i.flx = top.i.flx - flx_16mul16(eye.dir.i,dot).flx;
    top.j.flx = top.j.flx - flx_16mul16(eye.dir.j,dot).flx;
    top.k.flx = top.k.flx - flx_16mul16(eye.dir.k,dot).flx;
    top.normalize();

    compute_eye();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Compute Functions  ±°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - compute_scalar                                              ³
//                                                                          ³
// Recomputes the xsize, ysize, xscalar, and yscalar values from the fov    ³
// and hither values.                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::compute_scalar(void)
{
    Flx16   size;
    Flx16   angle;

    assertMyth("EschCamera::compute_scalar only allows 1 <= fov <= 175 and hither > 0",
               ((fov >= 1) && (fov <= 175)) && (hither > 0));

    // angle is fov / 2
    angle.flx = fov.flx >> 1;

    // Save off radius factor.
    radius_factor.flx = flx_16div16( factor, angle.cos()).flx;

//ÄÄÄ Compute 1/2 size of projection-plane from FOV angle

    size.flx = flx_muldiv( hither, angle.sin(), angle.cos() ).flx;
    assertMyth("EschCamera::compute_scalar requires FOV and hither to result in non-zero size",
               size.flx != 0);

//ÄÄÄ Save 1/2 size of projection-plane in X and compute Y.
    xsize.flx = size.flx;
   
    // Aspect-ratio should result in 4:3 X to Y pixels, so this is valid.
    ysize.flx = flx_muldiv(size, 3, 4).flx;

//ÄÄÄ Compute scalar values for X and Y to get pixel locations.
    if (vport)
    {
        xscalar.flx = flx_muldiv( hither, (Flx16)(vport->get_vbuff()->width>>1), size).flx;
        yscalar.flx = flx_16mul16(xscalar,aspect_ratio).flx;
    }
    compute_z_factor();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - compute_z_factor                                            ³
//                                                                          ³
// Recompute the scale factor for Z to get maximum resolution in the        ³
// Z-Buffer.                                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::compute_z_factor(void)
{
    Flx16  max_z_size;
    max_z_size.flx = 0x7fffffff;
    z_factor = flx_16div16(max_z_size,Flx16((yon.flx-hither.flx + 0x10000),1));
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - compute_eye                                                 ³
//                                                                          ³
// Recomputes the matrix based on the current eye.dir and top vectors for   ³
// the rotation component of the matrix.  This will destroy any scales or   ³
// rotations in the eye transform matrix, but will include the user-set     ³
// factor.                                                                  ³
//                                                                          ³
// Assumes that the eye.dir and top vectors are normalized.                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::compute_eye(void)
{
    EschVector  right;

    eye.ortho_count=0;

    assertMyth("EschCamera::compute_eye requires factor > 0",
               factor > 0);

//ÄÄÄ Create right vector 
    right = top CROSS eye.dir;

//ÄÄÄ Fill in matrix for ortho rotation

    //ÄÄÄ Transform
    eye.orient.mtx[ESCH_MTX_A].flx = flx_16div16(right.i,factor).flx;
    eye.orient.mtx[ESCH_MTX_D].flx = flx_16div16(top.i,factor).flx;
    eye.orient.mtx[ESCH_MTX_G].flx = flx_16div16(eye.dir.i,factor).flx;

    eye.orient.mtx[ESCH_MTX_B].flx = flx_16div16(right.j,factor).flx;
    eye.orient.mtx[ESCH_MTX_E].flx = flx_16div16(top.j,factor).flx;
    eye.orient.mtx[ESCH_MTX_H].flx = flx_16div16(eye.dir.j,factor).flx;

    eye.orient.mtx[ESCH_MTX_C].flx = right.k.flx;
    eye.orient.mtx[ESCH_MTX_F].flx = top.k.flx;
    eye.orient.mtx[ESCH_MTX_I].flx = eye.dir.k.flx;

    //ÄÄÄ Inverse Transform
    eye.orient.inverse(&eye.iorient);
}


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  I/O Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - load                                                        ³
//                                                                          ³
// Loads the position and other data of the camera from an IFF file.        ³
//                                                                          ³
// The IFF version assumes that the IFF is open and pointing at the proper  ³
// chunk.  If a 'cname' is given and the name doesn't match that in the     ³
// chunk, an error is returned.                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschCamera::load(const char *fname, const char *cname)
{
    esch_error_codes    err;
    XFParseIFF          iff;

//ÄÄ Open file
    if (iff.open(fname,XF_OPEN_READ))
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
        }

        if (iff.chunkid == iff.makeid('E','C','A','M'))
        {
            err=load(&iff,cname);
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

esch_error_codes EschCamera::load(XFParseIFF *iff, const char *cname)
{
    EschFileCamera  cam;

    assertMyth("EschCamera::load requries iff pointer",
               iff);

//ÄÄ Verify correct chunk name and size
    if (iff->chunkid != iff->makeid('E','C','A','M'))
        return ESCH_ERR_NOTFOUND;

    if (iff->chunkSize != sizeof(EschFileCamera))
        return ESCH_ERR_INVALIDDATA;

//ÄÄ Read chunk and verify name, if given.
    if (iff->read(&cam))
        return ESCH_ERR_FILEERROR;

    if (cname && strcmp(cname,cam.name))
        return ESCH_ERR_NOTFOUND;

//ÄÄ Found, so setup camera
    strcpy(name,cam.name);
    flags = cam.flags;

    set_position(cam.x,cam.y,cam.z);

    fov=cam.fov;

    factor=1;

    eye.dir.i.flx = cam.diri.flx;
    eye.dir.j.flx = cam.dirj.flx;
    eye.dir.k.flx = cam.dirk.flx;
    
    top.i.flx = cam.topi.flx;
    top.j.flx = cam.topj.flx;
    top.k.flx = cam.topk.flx;

//ÄÄÄ Call computation functions
    compute_scalar();
    compute_eye();
   
//ÄÄ Return ok
    return ESCH_ERR_NONE;
}

//°±² End of module - escamera.cpp ²±°

