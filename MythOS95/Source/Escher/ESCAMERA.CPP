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
// escamera.cpp
//
// The EschCamera class is the information class for the viewing of
// the drawable objects.  The EschCamera has associated viewing
// parameters to provide the needed transformation information.
// EschCameras can be linked into lists and loaded from files.
//
// A Van Gogh viewport is required for the camera to operate, so
// one should be created and attached to the camera.  The camera
// can only be attached to a single Van Gogh viewport at any given
// time.
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
EschCamera::EschCamera(VngoVport *vp) :
    iprev(0),
    inext(0),
    flags(0),
    vport(0),
    aspect_ratio(1.0),
    bcolor(0),
    app_data(0)
{
    strcpy(name,EschNoName);

//ÄÄÄ Default camera parameters ÄÄÄ
    reset();

    if (vp)
        attach(vp);
};

EschCamera::EschCamera(const char *fname, const char *cname) :
    iprev(0),
    inext(0),
    flags(0),
    vport(0),
    aspect_ratio(1.0),
    factor(1.0),
    hither(1.0),
    yon(4096.0),
    width(100.0),
    height(0),
    bcolor(0),
    app_data(0)
{
    strncpy(name,cname ? cname : EschNoName,ESCH_MAX_NAME);

    if (load(fname,cname))
        reset();
};

EschCamera::EschCamera(const EschCamera &cam) :
    iprev(0),
    inext(0),
    eye(cam.eye),
    top(cam.top),
    flags(cam.flags),
    vport(cam.vport),
    xscalar(cam.xscalar),
    yscalar(cam.yscalar),
    xsize(cam.xsize),
    ysize(cam.ysize),
    aspect_ratio(cam.aspect_ratio),
    factor(cam.factor),
    hither(cam.hither),
    yon(cam.yon),
    fov(cam.fov),
    width(cam.width),
    height(cam.height),
    bcolor(cam.bcolor),
    radius_factor(cam.radius_factor),
    z_factor(cam.z_factor),
    app_data(cam.app_data)
{
    strncpy(name,cam.name,ESCH_MAX_NAME);
    memcpy(&frustrum,&cam.frustrum,sizeof(frustrum));
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - Destructor                                                  ³
//                                                                          ³
// Ensure the camera is removed from any list it is linked into.            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschCamera::~EschCamera()
{
    remove();
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - operator =                                                  ³
//                                                                          ³
// Copies the data from another camera.                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
const EschCamera &EschCamera::operator = (const EschCamera &cam)
{
    if (this != &cam)
    {
        eye = cam.eye;
        top = cam.top;
        flags = cam.flags;
        vport = cam.vport;
        xscalar = cam.xscalar;
        yscalar = cam.yscalar;
        xsize = cam.xsize;
        ysize = cam.ysize;
        aspect_ratio = cam.aspect_ratio;
        factor = cam.factor;
        hither = cam.hither;
        yon = cam.yon;
        fov = cam.fov;
        width = cam.width;
        height = cam.height;
        bcolor = cam.bcolor;
        radius_factor = cam.radius_factor;
        z_factor = cam.z_factor;
        strncpy(name,cam.name,ESCH_MAX_NAME);
        memcpy(&frustrum,&cam.frustrum,sizeof(frustrum));
        app_data = cam.app_data;
    }
    return *this;
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - attach                                                      ³
//                                                                          ³
// Attaches the camera to a Van Gogh viewport.  This sets the internal      ³
// viewport pointer and calls the scalar compute function.                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::attach(VngoVport *vp)
{
    vport=vp;

    if (!vp)
        return;

    if (vp->vflags & VNGO_ZBUFFER_DEV)
        flags &= ~ESCH_CAM_SORT;
    else
        flags |= ESCH_CAM_SORT;

    compute_scalar();
    compute_frustrum();
    compute_z_factor();
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
void EschCamera::remove()
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
EschCamera *EschCamera::find(const char *cname) const
{
    if (!cname)
        return 0;

    if (!strncmp(cname,name,ESCH_MAX_NAME))
        return (EschCamera*)this;

    if (!inext)
        return 0;

    return inext->find(cname);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - pre_rend                                                    ³
//                                                                          ³
// Prepares a render, returning a 0 on success or non-zero otherwise.       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschCamera::pre_rend()
{
    flags &= ~ESCH_CAM_VPWASLOCKED;

    if (!vport)
        return 1;

//ÄÄÄ Lock viewport (save old state)
    int waslocked = vport->lock();

        if (waslocked == -1)
                return 1;

    if (waslocked)
        flags |= ESCH_CAM_VPWASLOCKED;

//ÄÄÄ Clear viewport/reset z-buffer
    if (!(flags & ESCH_CAM_NOCLEAR))
    {
        vport->clear_screen_on();
        vport->reset(bcolor);
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - rend                                                        ³
//                                                                          ³
// Renders the current context to the camera, assuming a successful pre_rend³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::rend()
{
    EschDrawable    *ptr;

//ÄÄÄ Draw list of EschDrawables
    for(ptr=EschCurrent->eschs; ptr != NULL; ptr = ptr->next())
    {
        if (!(ptr->flags & ESCH_DRW_SKIP))
            ptr->draw();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - post_rend                                                   ³
//                                                                          ³
// Performs post render processing.                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::post_rend()
{
//ÄÄÄ Flush element buffer (if not forcing skip of this step)
    if (!(flags & ESCH_CAM_NOFLUSH))
    {
        if (flags & ESCH_CAM_TRUESORT)
            EschElement::flush_truesort();
        else
            EschElement::flush();
    }

//ÄÄÄ Unlock (if old state was unlocked)
    if (!(flags & ESCH_CAM_VPWASLOCKED))
        vport->unlock();

    flags &= ~ESCH_CAM_VPWASLOCKED;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - reset                                                       ³
//                                                                          ³
// Sets the camera up to default parameters.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::reset()
{
//ÄÄÄ Default camera parameters ÄÄÄ
    eye.set_position(0.0,0.0,0.0);

    eye.dir.i = 0.0;                        // Looking down positive Z.
    eye.dir.j = 0.0;
    eye.dir.k = 1.0;

    top.i=0.0;                              // Head is positive Y.
    top.j=1.0;
    top.k=0.0;

    hither=1.0;                             // Arbitrary start values.
    yon=4096.0;

    fov=48.0;                               // Default used by 3DS, so why not?

    width=100.0;
    height=0;

    factor=1.0;                             // No user zoom factor by default.


//ÄÄÄ Call computation functions
    compute_scalar();
    compute_frustrum();
    compute_z_factor();
    compute_eye();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - set_top                                                     ³
//                                                                          ³
// Sets the camera based on a new top vector.                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::set_top(const EschVector *t, dword update)
{
    top=*t;
    top.normalize();

//ÄÄÄ Call computation function
    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_EYE)
        compute_eye(update);
}

void EschCamera::set_top(const float ii, const float ij, const float ik,
                         dword update)
{
    top.i=ii;
    top.j=ij;
    top.k=ik;
    top.normalize();

//ÄÄÄ Call computation function
    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_EYE)
        compute_eye(update);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - set_top                                                     ³
//                                                                          ³
// Sets the camera based on a new direction vector.                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::set_dir(const EschVector *d, dword update)
{
    eye.dir=*d;
    eye.dir.normalize();

//ÄÄÄ Call computation function
    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_EYE)
        compute_eye(update);
}

void EschCamera::set_dir(const float ii, const float ij, const float ik,
                         dword update)
{
    eye.dir.i=ii;
    eye.dir.j=ij;
    eye.dir.k=ik;
    eye.dir.normalize();

//ÄÄÄ Call computation function
    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_EYE)
        compute_eye(update);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - set_vects                                                   ³
//                                                                          ³
// Sets the camera based on new direction and top vectors.                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::set_vects(const EschVector *t, const EschVector *d,
                           dword update)
{
    top=*t;
    top.normalize();

    eye.dir=*d;
    eye.dir.normalize();

//ÄÄÄ Call computation function
    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_EYE)
        compute_eye(update);
}

void EschCamera::set_vects(const float ti, const float tj, const float tk,
                           const float di, const float dj, const float dk,
                           dword update)
{
    top.i = ti;
    top.j = tj;
    top.k = tk;
    top.normalize();

    eye.dir.i = di;
    eye.dir.j = dj;
    eye.dir.k = dk;
    eye.dir.normalize();

//ÄÄÄ Call computation function
    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_EYE)
        compute_eye(update);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - set_lookat                                                  ³
//                                                                          ³
// Sets the direction and top vector based on a look-at point.              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::set_lookat(const EschPoint *pt, dword update)
{
    EschPoint   pos;

    get_position(&pos);

//ÄÄÄ Determine direction from lookat point and position
    eye.dir.i = pt->x - pos.x;
    eye.dir.j = pt->y - pos.y;
    eye.dir.k = pt->z - pos.z;
    eye.dir.normalize();

//ÄÄÄ Call orthogonalize function
    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_EYE)
        compute_eye(update);
}

void EschCamera::set_lookat(const float ix, const float iy, const float iz,
                            dword update)
{
    EschPoint   pos;

    get_position(&pos);

//ÄÄÄ Determine direction from lookat point and position
    eye.dir.i = ix - pos.x;
    eye.dir.j = iy - pos.y;
    eye.dir.k = iz - pos.z;
    eye.dir.normalize();

//ÄÄÄ Call orthogonalize function
    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_EYE)
        compute_eye(update);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - rotatex                                                     ³
//                                                                          ³
// Addes a rotation of 'degrees' degrees to the frame of reference about the³
// X-axis.                                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::rotatex(const float degrees, dword update)
{
    eye.rotatex(degrees,update & ~ESCH_UPD_ORTHO);

    if ((update & ESCH_UPD_ORTHO) && (eye.ortho_count > ESCH_MAX_ORTHOCOUNT))
    {
        orthogonalize(update);
    }

//ÄÄÄ Update top vector
    top.i = eye.orient.mtx[ESCH_MTX_D];
    top.j = eye.orient.mtx[ESCH_MTX_E];
    top.k = eye.orient.mtx[ESCH_MTX_F];
    top.normalize();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - rotatey                                                     ³
//                                                                          ³
// Addes a rotation of 'degrees' degrees to the frame of reference about the³
// Y-axis.                                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::rotatey(const float degrees, dword update)
{
    eye.rotatey(degrees,update & ~ESCH_UPD_ORTHO);

    if ((update & ESCH_UPD_ORTHO) && (eye.ortho_count > ESCH_MAX_ORTHOCOUNT))
    {
        orthogonalize(update);
    }

//ÄÄÄ Update top vector
    top.i = eye.orient.mtx[ESCH_MTX_D];
    top.j = eye.orient.mtx[ESCH_MTX_E];
    top.k = eye.orient.mtx[ESCH_MTX_F];
    top.normalize();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - rotatez                                                     ³
//                                                                          ³
// Addes a rotation of 'degrees' degrees to the frame of reference about the³
// Z-axis.                                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::rotatez(const float degrees, dword update)
{
    eye.rotatez(degrees,update & ~ESCH_UPD_ORTHO);

    if ((update & ESCH_UPD_ORTHO) && (eye.ortho_count > ESCH_MAX_ORTHOCOUNT))
    {
        orthogonalize(update);
    }

//ÄÄÄ Update top vector
    top.i = eye.orient.mtx[ESCH_MTX_D];
    top.j = eye.orient.mtx[ESCH_MTX_E];
    top.k = eye.orient.mtx[ESCH_MTX_F];
    top.normalize();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - pitch                                                       ³
//                                                                          ³
// Addes a rotation of 'degrees' degrees to the frame of reference about the³
// relative X-axis.                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::pitch(const float degrees, dword update)
{
    eye.pitch(degrees,update & ~ESCH_UPD_ORTHO);

    if ((update & ESCH_UPD_ORTHO) && (eye.ortho_count > ESCH_MAX_ORTHOCOUNT))
    {
        orthogonalize(update);
    }

//ÄÄÄ Update top vector
    top.i = eye.orient.mtx[ESCH_MTX_D];
    top.j = eye.orient.mtx[ESCH_MTX_E];
    top.k = eye.orient.mtx[ESCH_MTX_F];
    top.normalize();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - yaw                                                         ³
//                                                                          ³
// Addes a rotation of 'degrees' degrees to the frame of reference about the³
// relative Y-axis.                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::yaw(const float degrees, dword update)
{
    eye.yaw(degrees,update & ~ESCH_UPD_ORTHO);

    if ((update & ESCH_UPD_ORTHO) && (eye.ortho_count > ESCH_MAX_ORTHOCOUNT))
    {
        orthogonalize(update);
    }

//ÄÄÄ Update top vector
    top.i = eye.orient.mtx[ESCH_MTX_D];
    top.j = eye.orient.mtx[ESCH_MTX_E];
    top.k = eye.orient.mtx[ESCH_MTX_F];
    top.normalize();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - roll                                                        ³
//                                                                          ³
// Addes a rotation of 'degrees' degrees to the frame of reference about the³
// relative Z-axis.                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::roll(const float degrees, dword update)
{
    eye.roll(degrees,update & ~ESCH_UPD_ORTHO);

    if ((update & ESCH_UPD_ORTHO) && (eye.ortho_count > ESCH_MAX_ORTHOCOUNT))
    {
        orthogonalize(update);
    }

//ÄÄÄ Update top vector
    top.i = eye.orient.mtx[ESCH_MTX_D];
    top.j = eye.orient.mtx[ESCH_MTX_E];
    top.k = eye.orient.mtx[ESCH_MTX_F];
    top.normalize();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - orthogonalize                                               ³
//                                                                          ³
// Ensures that the matrix is an orthonormal basis, ensuring that no        ³
// undesired scaling or shearing occurrs due to accumulated error in updates³
// from rotations, using the direction as the first basis.                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::orthogonalize(dword update)
{
    eye.ortho_count=0;

    eye.dir.normalize();

    float dot = top DOT eye.dir;

    top.i = top.i - (eye.dir.i * dot);
    top.j = top.j - (eye.dir.j * dot);
    top.k = top.k - (eye.dir.k * dot);
    top.normalize();

    if (update & ESCH_UPD_EYE)
        compute_eye(update);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - orthogonalize_top                                           ³
//                                                                          ³
// Ensures that the matrix is an orthonormal basis, ensuring that no        ³
// undesired scaling or shearing occurrs due to accumulated error in updates³
// from rotations, using the top vector as the first basis.                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::orthogonalize_top(dword update)
{
    eye.ortho_count=0;

    top.normalize();

    float dot = top DOT eye.dir;

    eye.dir.i = eye.dir.i - (top.i * dot);
    eye.dir.j = eye.dir.j - (top.j * dot);
    eye.dir.k = eye.dir.k - (top.k * dot);
    eye.dir.normalize();

    if (update & ESCH_UPD_EYE)
        compute_eye(update);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Compute Functions  ±°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - compute_scalar                                              ³
//                                                                          ³
// Recomputes the xsize, ysize, xscalar, yscalar, and radius_factor from    ³
// the aspect_ratio, viewport dimensions, and either the field-of-view      ³
// for perspective cameras or the width and height for orthogonal cameras.  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::compute_scalar()
{
    if (!vport)
        return;

    assertMyth("EschCamera::compute_scalar requires factor > 0",
                factor > 0);

//ÄÄÄ Orthographic projection
    if (flags & ESCH_CAM_ORTHO)
    {
        float hw, hh;

        assertMyth("EschCamera::compute_scalar needs valid width and height",
                   width > 0 && height >= 0);

        hw = float((width + vport->skips_last_pix()) / 2.0f);
        hh = float((height + vport->skips_last_pix()) / 2.0f);

        radius_factor = factor;

        //ÄÄÄ Set projection size based on factor & width/height
        //ÄÄÄ (a 0 height means set based on aspect-ratio)

        xsize = hw / factor;

        if (height > 0.0)
            ysize = hh / factor;
        else
            ysize = ((xsize * float(vport->vbuff.height + vport->skips_last_pix()))
                    / float(vport->vbuff.width + vport->skips_last_pix()))
                    * aspect_ratio;

        //ÄÄÄ Compute scalar values for X and Y to get pixel locations.
        xscalar = (float((vport->vbuff.width + vport->skips_last_pix()) / 2.f) * factor) / hw;

        if (height > 0.0)
            yscalar = (float((vport->vbuff.height + vport->skips_last_pix()) / 2.f) * factor) / hh;
        else
            yscalar = xscalar / aspect_ratio;
    }
//ÄÄÄ Perspective projection
    else
    {
        assertMyth("EschCamera::compute_scalar only allows 1 <= fov <= 175",
                   ((fov >= 1) && (fov <= 175)));

        // angle is fov / 2
        float angle = fov / 2.0f;

        // Save off radius factor.
        radius_factor = factor / esch_cos(angle);

        //ÄÄÄ Compute 1/2 size of projection-plane from FOV angle
        //
        //                         /|
        //                        / |
        //                       /  |
        //                      /   | 1/2 size projection plane (unknown)
        //                     /    |
        //        1/2 of FOV  /     |
        //         is this   *______|
        //          angle      ^
        //                     | Projection-plane distance (always 1)
        //

        float size = esch_sin(angle) / esch_cos(angle);

        assertMyth("EschCamera::compute_scalar requires FOV to result in non-zero size",
                   size != 0);

        //ÄÄÄ Save 1/2 size of projection-plane in X and compute Y.
        xsize = size / factor;
        ysize = ((xsize * float(vport->vbuff.height + vport->skips_last_pix()) )
                / float(vport->vbuff.width + vport->skips_last_pix()))
                * aspect_ratio;

        //ÄÄÄ Compute scalar values for X and Y to get pixel locations.
        xscalar = ((float(vport->vbuff.width + vport->skips_last_pix()) / 2.f) * factor) / size;
        yscalar = xscalar / aspect_ratio;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - compute_frustrum                                            ³
//                                                                          ³
// Recomputes the planes for the view frustrum, which are used for 3D       ³
// clipping.  This routine depends on xsize/ysize computed by               ³
// compute_scalar()                                                         ³
//                                                                          ³
// The distances are pre-negated for faster processing in the clipping code!³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::compute_frustrum()
{
//ÄÄÄ Orthographic projection
    if (flags & ESCH_CAM_ORTHO)
    {
        // Left
        frustrum[ESCH_CAM_FRUSTRUM_LEFT].normal.i = 1;
        frustrum[ESCH_CAM_FRUSTRUM_LEFT].normal.j = 0;
        frustrum[ESCH_CAM_FRUSTRUM_LEFT].normal.k = 0;
        frustrum[ESCH_CAM_FRUSTRUM_LEFT].dist = -xsize;

        // Right
        frustrum[ESCH_CAM_FRUSTRUM_RIGHT].normal.i = -1;
        frustrum[ESCH_CAM_FRUSTRUM_RIGHT].normal.j = 0;
        frustrum[ESCH_CAM_FRUSTRUM_RIGHT].normal.k = 0;
        frustrum[ESCH_CAM_FRUSTRUM_RIGHT].dist = -xsize;

        // Top
        frustrum[ESCH_CAM_FRUSTRUM_TOP].normal.i = 0;
        frustrum[ESCH_CAM_FRUSTRUM_TOP].normal.j = -1;
        frustrum[ESCH_CAM_FRUSTRUM_TOP].normal.k = 0;
        frustrum[ESCH_CAM_FRUSTRUM_TOP].dist = -ysize;

        // Bottom
        frustrum[ESCH_CAM_FRUSTRUM_BOTTOM].normal.i = 0;
        frustrum[ESCH_CAM_FRUSTRUM_BOTTOM].normal.j = 1;
        frustrum[ESCH_CAM_FRUSTRUM_BOTTOM].normal.k = 0;
        frustrum[ESCH_CAM_FRUSTRUM_BOTTOM].dist = -ysize;
    }
//ÄÄÄ Perspective projection
    else
    {
        float   epsilon(0.001f);
        float   xangle = esch_atan(xsize);
        float   yangle = esch_atan(ysize);

        xangle = (90.0f - xangle);  // Get the perpendicular to the frustrum.
        yangle = (90.0f - yangle);  // Get the perpendicular to the frustrum.

        float   top_cos = esch_cos(yangle);
        float   top_sin = esch_sin(yangle);
        float   left_cos = esch_cos(xangle);
        float   left_sin = esch_sin(xangle);

        // Left
        frustrum[ESCH_CAM_FRUSTRUM_LEFT].normal.i = left_sin;
        frustrum[ESCH_CAM_FRUSTRUM_LEFT].normal.j = 0;
        frustrum[ESCH_CAM_FRUSTRUM_LEFT].normal.k = left_cos;
        frustrum[ESCH_CAM_FRUSTRUM_LEFT].dist = -epsilon;

        // Right
        frustrum[ESCH_CAM_FRUSTRUM_RIGHT].normal.i = -left_sin;
        frustrum[ESCH_CAM_FRUSTRUM_RIGHT].normal.j = 0;
        frustrum[ESCH_CAM_FRUSTRUM_RIGHT].normal.k = left_cos;
        frustrum[ESCH_CAM_FRUSTRUM_RIGHT].dist = -epsilon;

        // Top
        frustrum[ESCH_CAM_FRUSTRUM_TOP].normal.i = 0;
        frustrum[ESCH_CAM_FRUSTRUM_TOP].normal.j = -top_sin;
        frustrum[ESCH_CAM_FRUSTRUM_TOP].normal.k = top_cos;
        frustrum[ESCH_CAM_FRUSTRUM_TOP].dist = -epsilon;

        // Bottom
        frustrum[ESCH_CAM_FRUSTRUM_BOTTOM].normal.i = 0;
        frustrum[ESCH_CAM_FRUSTRUM_BOTTOM].normal.j = top_sin;
        frustrum[ESCH_CAM_FRUSTRUM_BOTTOM].normal.k = top_cos;
        frustrum[ESCH_CAM_FRUSTRUM_BOTTOM].dist = -epsilon;
    }

//ÄÄÄ Near/Far planes not based on projection mode
    // Near
    frustrum[ESCH_CAM_FRUSTRUM_HITHER].normal.i = 0;
    frustrum[ESCH_CAM_FRUSTRUM_HITHER].normal.j = 0;
    frustrum[ESCH_CAM_FRUSTRUM_HITHER].normal.k = 1;
    frustrum[ESCH_CAM_FRUSTRUM_HITHER].dist = -hither;

    // Far
    frustrum[ESCH_CAM_FRUSTRUM_YON].normal.i = 0;
    frustrum[ESCH_CAM_FRUSTRUM_YON].normal.j = 0;
    frustrum[ESCH_CAM_FRUSTRUM_YON].normal.k = -1;
    frustrum[ESCH_CAM_FRUSTRUM_YON].dist = -(yon * 0.99f);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - compute_z_factor                                            ³
//                                                                          ³
// Recompute the scale factor for Z to get maximum resolution in the        ³
// Z-Buffer.                                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCamera::compute_z_factor()
{
    assertMyth("EschCamera::compute_z_factor assumes yon greater than hither",
               yon > hither);

    // go ahead and normalize Z between 0 and 1.
    z_factor = (0.9999f / (yon - hither + 1.0f));
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
void EschCamera::compute_eye(dword update)
{
    EschVector  right;

    eye.ortho_count=0;

//ÄÄÄ Create right vector
    right = top CROSS eye.dir;

//ÄÄÄ Fill in matrix for ortho rotation

    //ÄÄÄ Transform
    eye.orient.mtx[ESCH_MTX_A] = right.i;
    eye.orient.mtx[ESCH_MTX_B] = right.j;
    eye.orient.mtx[ESCH_MTX_C] = right.k;

    eye.orient.mtx[ESCH_MTX_D] = top.i;
    eye.orient.mtx[ESCH_MTX_E] = top.j;
    eye.orient.mtx[ESCH_MTX_F] = top.k;

    eye.orient.mtx[ESCH_MTX_G] = eye.dir.i;
    eye.orient.mtx[ESCH_MTX_H] = eye.dir.j;
    eye.orient.mtx[ESCH_MTX_I] = eye.dir.k;

    //ÄÄÄ Inverse Transform
    if (update & ESCH_UPD_INVERSE)
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

        if (iff.chunkid == iff.makeid('E','C','A','M')
            || iff.chunkid == iff.makeid('E','C','A','1'))
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
    assertMyth("EschCamera::load requries iff pointer",
               iff);

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Floating-point format
    if (iff->chunkid == iff->makeid('E','C','A','1'))
    {
        EschFileCamera  cam;

        if (iff->chunkSize != sizeof(cam))
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

        eye.dir.i = cam.diri;
        eye.dir.j = cam.dirj;
        eye.dir.k = cam.dirk;

        top.i = cam.topi;
        top.j = cam.topj;
        top.k = cam.topk;
    }
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Fixed-point format
    else if (iff->chunkid == iff->makeid('E','C','A','M'))
    {
        EschFileCameraV1  cam;

        if (iff->chunkSize != sizeof(cam))
            return ESCH_ERR_INVALIDDATA;

        //ÄÄ Read chunk and verify name, if given.
        if (iff->read(&cam))
            return ESCH_ERR_FILEERROR;

        if (cname && strcmp(cname,cam.name))
            return ESCH_ERR_NOTFOUND;

        //ÄÄ Found, so setup camera
        strcpy(name,cam.name);
        flags = cam.flags;

        set_position(cam.x / 65536.0f,cam.y / 65536.0f,cam.z / 65536.0f);

        fov=cam.fov / 65536.0f;

        eye.dir.i = cam.diri / 65536.0f;
        eye.dir.j = cam.dirj / 65536.0f;
        eye.dir.k = cam.dirk / 65536.0f;

        top.i = cam.topi / 65536.0f;
        top.j = cam.topj / 65536.0f;
        top.k = cam.topk / 65536.0f;
    }
    else
    {
        return ESCH_ERR_NOTFOUND;
    }

    factor=1.0;

//ÄÄÄ Call computation functions
    compute_scalar();
    compute_frustrum();
    compute_z_factor();
    compute_eye();

//ÄÄ Return ok
    return ESCH_ERR_NONE;
}

//°±² End of module - escamera.cpp ²±°

