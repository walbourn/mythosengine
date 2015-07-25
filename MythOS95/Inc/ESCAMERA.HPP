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
// escamera.hpp
//
// The EschCamera class provides the viewing parameters for rendering
// the object database.  EschCameras can be linked into lists, as
// well as loaded from files.
//
// EschCameraEx class extends the basic camera to include support for bitmap
// backgrounds and special-effects like hazing.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __ESCAMERA_HPP
#define __ESCAMERA_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//             
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <portable.h>
#include <felix.hpp>
#include <vangogh.hpp>
#include <xfile.hpp>

#include "esmath.hpp"
#include "escontxt.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

class EschLight;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCamera - Viewpoint within world space.                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschCamera {

protected:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Protected data members                                               ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschCamera  *inext;                     // Linked-list pointers
    EschCamera  *iprev;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Internal render functions which are overlayed by derived EschCameras.³
    // These functions will assume that the currently active context        ³
    // contains the required data for drawing.                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual int pre_rend();
    virtual void rend();
    virtual void post_rend();

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members (should be changed only by utility functions).   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschFrameRef    eye;                    // Eye <=> World transformation
    EschVector      top;                    // Top of head vector
    dword           flags;                  // Camera flags
    VngoVport       *vport;                 // VanGogh viewport for output
    Flx16           xscalar;                // 2D scale factor in X
    Flx16           yscalar;                // 2D scale factor in Y
    Flx16           xsize;                  // Projection-plane size in X
    Flx16           ysize;                  // Projection-plane size in Y
    Flx16           aspect_ratio;           // Aspect ratio (X:Y)
    Flx16           factor;                 // User scale factor
    Flx16           hither;                 // Distance to near clip plane
    Flx16           yon;                    // Distance to far clip plane
    Flx16           fov;                    // Field of view (degrees)
    dword           bcolor;                 // Background color for clear
    Flx16           radius_factor;          // Extent radius factor
    Flx16           z_factor;               // scale to appropriate z range
    EschPlane       frustrum[6];            // View frustrum planes
    char            name[ESCH_MAX_NAME];    // Camera name

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschCamera(VngoVport *vport=0);
    EschCamera(const char *fname, const char *cname=0);
    EschCamera(const EschCamera &cam);

    virtual ~EschCamera();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Accessor functions                                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschCamera *next() const { return inext; }
    EschCamera *prev() const { return iprev; }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    const EschCamera &operator = (const EschCamera &cam);

    virtual void attach(VngoVport *vp);

    virtual void sibling(EschCamera *myprev);
    virtual void remove();

    virtual EschCamera *find(const char *cname) const;

    virtual void reset();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Renders the view starting with the olist as the parent EschDrawable. ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void render(dword ctrl=ESCH_REND_ALL)
    {
        EschContext ec(EschCurrent);
        ec.camera = this;
        ec.push();
        if (ctrl & ESCH_REND_PRE)
            if (pre_rend())
                return;
        if (ctrl & ESCH_REND_DRAW)
            rend();
        if (ctrl & ESCH_REND_POST)
            post_rend();
        ec.pop();
    }
    void render(EschDrawable *olist, dword ctrl=ESCH_REND_ALL)
    {
        EschContext ec(EschCurrent);
        ec.eschs = olist;
        ec.camera = this;
        ec.push();
        if (ctrl & ESCH_REND_PRE)
            if (pre_rend())
                return;
        if (ctrl & ESCH_REND_DRAW)
            rend();
        if (ctrl & ESCH_REND_POST)
            post_rend();
        ec.pop();
    }
    void render(EschLight *llist, dword ctrl=ESCH_REND_ALL)
    {
        EschContext ec(EschCurrent);
        ec.camera = this;
        ec.lights = llist;
        ec.push();
        if (ctrl & ESCH_REND_PRE)
            if (pre_rend())
                return;
        if (ctrl & ESCH_REND_DRAW)
            rend();
        if (ctrl & ESCH_REND_POST)
            post_rend();
        ec.pop();
    }
    void render(EschDrawable *olist, EschLight *llist, dword ctrl=ESCH_REND_ALL)
    {
        EschContext ec(EschCurrent);
        ec.eschs = olist;
        ec.lights = llist;
        ec.camera = this;
        ec.push();
        if (ctrl & ESCH_REND_PRE)
            if (pre_rend())
                return;
        if (ctrl & ESCH_REND_DRAW)
            rend();
        if (ctrl & ESCH_REND_POST)
            post_rend();
        ec.pop();
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility functions.                                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void set_top(const EschVector *t, dword update=ESCH_UPD_ALL);
    void set_top(const Flx16 ii, const Flx16 ij, const Flx16 ik,
                 dword update=ESCH_UPD_ALL);

    void set_dir(const EschVector *d, dword update=ESCH_UPD_ALL);
    void set_dir(const Flx16 ii, const Flx16 ij, const Flx16 ik,
                 dword update=ESCH_UPD_ALL);

    void set_vects(const EschVector *t,const EschVector *d,
                   dword update=ESCH_UPD_ALL);
    void set_vects(const Flx16 ti, const Flx16 tj, const Flx16 tk,
                   const Flx16 di, const Flx16 dj, const Flx16 dk,
                   dword update=ESCH_UPD_ALL);

    void get_position(EschPoint *pt) const
    {
        pt->x.flx = eye.orient.mtx[ESCH_MTX_J].flx;
        pt->y.flx = eye.orient.mtx[ESCH_MTX_K].flx;
        pt->z.flx = eye.orient.mtx[ESCH_MTX_L].flx;
    }

    void set_position(const EschPoint *pt, dword update=ESCH_UPD_ALL)
         { eye.set_position(pt,update); }
    void set_position(const Flx16 ix, const Flx16 iy, const Flx16 iz, dword update=ESCH_UPD_ALL)
         { eye.set_position(ix,iy,iz,update); }

    void set_lookat(const EschPoint *pt, dword update=ESCH_UPD_ALL);
    void set_lookat(const Flx16 ix, const Flx16 iy, const Flx16 iz,
                    dword update=ESCH_UPD_ALL);

    void rotatex(const Flx16 degrees, dword update=ESCH_UPD_ALL);
    void rotatey(const Flx16 degrees, dword update=ESCH_UPD_ALL);
    void rotatez(const Flx16 degrees, dword update=ESCH_UPD_ALL);

    void pitch(const Flx16 degrees, dword update=ESCH_UPD_ALL);
    void yaw(const Flx16 degrees, dword update=ESCH_UPD_ALL);
    void roll(const Flx16 degrees, dword update=ESCH_UPD_ALL);

    void translate(const EschVector *v, dword update=ESCH_UPD_ALL)
         { eye.translate(v->i,v->j,v->k,update); }
    void translate(const Flx16 ii, const Flx16 ij, const Flx16 ik,
                   dword update=ESCH_UPD_ALL)
         { eye.translate(ii,ij,ik,update); }

    void move(const EschVector *v, dword update=ESCH_UPD_ALL)
         { eye.move(v->i,v->j,v->k,update); }
    void move(const Flx16 ii, const Flx16 ij, const Flx16 ik,
              dword update=ESCH_UPD_ALL)
         { eye.move(ii,ij,ik,update); }

    void orthogonalize(dword update=ESCH_UPD_ALL);
    void orthogonalize_top(dword update=ESCH_UPD_ALL);

    void set_factor(const Flx16 f, dword update=ESCH_UPD_ALL)
    {
        factor=f;
        if (update & ESCH_UPD_SCALAR)
        {
            compute_scalar();
            compute_frustrum();
        }
    }

    void zoom(const Flx16 f, dword update=ESCH_UPD_ALL)
    {
        factor=factor * f;
        if (update & ESCH_UPD_SCALAR)
        {
            compute_scalar();
            compute_frustrum();
        }
    }

    void set_fov(const Flx16 f, dword update=ESCH_UPD_ALL)
    {
        fov=f;
        if (update & ESCH_UPD_SCALAR)
        {
            compute_scalar();
            compute_frustrum();
        }
    }

    void set_hither(const Flx16 h, dword update=ESCH_UPD_ALL)
    {
        hither=h;
        if (update & ESCH_UPD_SCALAR)
        {
            compute_frustrum();
            compute_z_factor();
        }
    }

    void set_yon(const Flx16 y, dword update=ESCH_UPD_ALL) 
    { 
        yon=y; 
        if (update & ESCH_UPD_SCALAR)
        {
            compute_frustrum();
            compute_z_factor();
        }
    }

    void set_bcolor(const dword c=0) { bcolor=c; }

    void set_flags(const dword f) { flags=f; }

    void set_aspect_ratio(const Flx16 ar, dword update=ESCH_UPD_ALL)
    {
        aspect_ratio=ar;
        if (update & ESCH_UPD_SCALAR)
        {
            compute_scalar();
            compute_frustrum();
        }
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Compute functions to calculate viewing constants.                    ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void compute_scalar();
    void compute_z_factor();
    void compute_frustrum();
    void compute_eye(dword update=ESCH_UPD_ALL);
    void compute_inverse() { eye.compute_inverse(); }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // I/O routines.                                                        ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual esch_error_codes load(const char *fname, const char *cname=0);
    virtual esch_error_codes load(XFParseIFF *iff, const char *cname=0);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - Extended camera class.                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschCameraEx : public EschCamera {

protected:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Internal render functions                                            ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual int pre_rend();
    virtual void post_rend();

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members (should be changed only by utility functions).   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    short           bg_offx;                // Bitmap Background window offset
    short           bg_offy;
    XFBitmap        *bg_bitmap;             // Bitmap background
    VngoShadePal    *hz_pal;                // Haze shade palette
    long            hz_startz;              // Haze near cut-off (scaled)
    VngoShadePal    *grd_pal;               // Gradient shade palette

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschCameraEx(VngoVport *vport=0);
    EschCameraEx(const char *fname, const char *cname=0);
    EschCameraEx(const EschCamera &cam);
    EschCameraEx(const EschCameraEx &cam);

    virtual ~EschCameraEx();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    const EschCameraEx &operator = (const EschCamera &cam);
    const EschCameraEx &operator = (const EschCameraEx &cam);

    virtual void release();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility functions.                                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void set_bg_offset(short x, short y) { bg_offx=x; bg_offy=y; }
    int set_bg_bitmap(XFBitmap *bm, int owns=1);

    int set_haze(VngoShadePal *hzp, int owns=1, long startz=0);
    esch_error_codes create_haze(ushort levels,
                                 ushort slevel,
                                 ushort blevel, Flx16 bpercent,
                                 VngoColor24bit tcolor);

    int set_gradient(VngoShadePal *grdp, int owns=1);
    esch_error_codes create_gradient(ushort levels,
                                     ushort blevel, Flx16 bpercent,
                                     VngoColor24bit color1,
                                     VngoColor24bit color2);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - escamera.hpp ²±°

