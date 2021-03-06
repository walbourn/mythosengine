//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//���������������������������������������������������������������������������
//����������旭旭旭旭旭�旭旭旭旭���旭旭旭旭��旭姻���旭姻旭旭旭旭旭�旭旭旭旭姻�
//���������葦姻������葦姻���葦姻葦姻���葦姻葦姻���葦姻葦姻�������葦姻���葦姻�
//��������碓甥������碓甥�������碓甥�������碓甥���碓甥碓甥�������碓甥���碓甥��
//�������渦臼葦渦��渦臼葦渦臼�渦甥�������渦臼葦渦臼�渦臼葦渦���渦臼葦渦姻����
//������渦甥�������������渦甥渦甥�������渦甥���渦甥渦甥�������渦甥���渦甥����
//�����憶悔������憶悔���憶悔憶悔���憶悔憶悔���憶悔憶悔�������憶悔���憶悔�����
//����臆臆臆臆臆�臆臆臆臆���臆臆臆臆��臆悔���臆悔臆臆臆臆臆�臆悔���臆悔������
//���������������������������������������������������������������������������
//����������������� Microsoft Windows 95/98/NT Version ����������������������
//���������������������������������������������������������������������������
//���Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn���
//���������������������������������������������������������������������������
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __ESCAMERA_HPP
#define __ESCAMERA_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <portable.h>
#include <felix.hpp>
#include <vangogh.hpp>
#include <xfile.hpp>

#include "esmath.hpp"
#include "escontxt.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class EschLight;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - Viewpoint within world space.                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschCamera {

protected:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Protected data members                                               �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschCamera  *inext;                     // Linked-list pointers
    EschCamera  *iprev;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Internal render functions which are overlayed by derived EschCameras.�
    // These functions will assume that the currently active context        �
    // contains the required data for drawing.                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual int pre_rend();
    virtual void rend();
    virtual void post_rend();

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members (should be changed only by utility functions).   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschFrameRef    eye;                    // Eye <=> World transformation
    EschVector      top;                    // Top of head vector
    dword           flags;                  // Camera flags
    VngoVport       *vport;                 // VanGogh viewport for output
    float           xscalar;                // 2D scale factor in X
    float           yscalar;                // 2D scale factor in Y
    float           xsize;                  // Projection-plane size in X
    float           ysize;                  // Projection-plane size in Y
    float           aspect_ratio;           // Aspect ratio (X:Y)
    float           factor;                 // User scale factor
    float           hither;                 // Distance to near clip plane
    float           yon;                    // Distance to far clip plane
    float           fov;                    // Field of view (degrees)
    float           width;                  // Width for Orthographic mode
    float           height;                 // Height for Orthographic mode
    dword           bcolor;                 // Background color for clear
    float           radius_factor;          // Extent radius factor
    float           z_factor;               // scale to appropriate z range
    EschPlane       frustrum[6];            // View frustrum planes
    char            name[ESCH_MAX_NAME];    // Camera name
    void            *app_data;              // Application data pointer

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschCamera(VngoVport *vport=0);
    EschCamera(const char *fname, const char *cname=0);
    EschCamera(const EschCamera &cam);

    virtual ~EschCamera();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Accessor functions                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschCamera *next() const { return inext; }
    EschCamera *prev() const { return iprev; }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    const EschCamera &operator = (const EschCamera &cam);

    virtual void attach(VngoVport *vp);

    virtual void sibling(EschCamera *myprev);
    virtual void remove();

    virtual EschCamera *find(const char *cname) const;

    virtual void reset();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Renders the view starting with the olist as the parent EschDrawable. �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions.                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void set_top(const EschVector *t, dword update=ESCH_UPD_ALL);
    void set_top(const float ii, const float ij, const float ik,
                 dword update=ESCH_UPD_ALL);

    void set_dir(const EschVector *d, dword update=ESCH_UPD_ALL);
    void set_dir(const float ii, const float ij, const float ik,
                 dword update=ESCH_UPD_ALL);

    void set_vects(const EschVector *t,const EschVector *d,
                   dword update=ESCH_UPD_ALL);
    void set_vects(const float ti, const float tj, const float tk,
                   const float di, const float dj, const float dk,
                   dword update=ESCH_UPD_ALL);

    void get_position(EschPoint *pt) const
    {
        pt->x = eye.orient.mtx[ESCH_MTX_J];
        pt->y = eye.orient.mtx[ESCH_MTX_K];
        pt->z = eye.orient.mtx[ESCH_MTX_L];
    }

    void set_position(const EschPoint *pt, dword update=ESCH_UPD_ALL)
         { eye.set_position(pt,update); }
    void set_position(const float ix, const float iy, const float iz, dword update=ESCH_UPD_ALL)
         { eye.set_position(ix,iy,iz,update); }

    void set_lookat(const EschPoint *pt, dword update=ESCH_UPD_ALL);
    void set_lookat(const float ix, const float iy, const float iz,
                    dword update=ESCH_UPD_ALL);

    void rotatex(const float degrees, dword update=ESCH_UPD_ALL);
    void rotatey(const float degrees, dword update=ESCH_UPD_ALL);
    void rotatez(const float degrees, dword update=ESCH_UPD_ALL);

    void pitch(const float degrees, dword update=ESCH_UPD_ALL);
    void yaw(const float degrees, dword update=ESCH_UPD_ALL);
    void roll(const float degrees, dword update=ESCH_UPD_ALL);

    void translate(const EschVector *v, dword update=ESCH_UPD_ALL)
         { eye.translate(v->i,v->j,v->k,update); }
    void translate(const float ii, const float ij, const float ik,
                   dword update=ESCH_UPD_ALL)
         { eye.translate(ii,ij,ik,update); }

    void move(const EschVector *v, dword update=ESCH_UPD_ALL)
         { eye.move(v->i,v->j,v->k,update); }
    void move(const float ii, const float ij, const float ik,
              dword update=ESCH_UPD_ALL)
         { eye.move(ii,ij,ik,update); }

    void orthogonalize(dword update=ESCH_UPD_ALL);
    void orthogonalize_top(dword update=ESCH_UPD_ALL);

    void set_factor(const float f, dword update=ESCH_UPD_ALL)
    {
        factor=f;
        if (update & ESCH_UPD_SCALAR)
        {
            compute_scalar();
            compute_frustrum();
        }
    }

    void zoom(const float f, dword update=ESCH_UPD_ALL)
    {
        factor=factor * f;
        if (update & ESCH_UPD_SCALAR)
        {
            compute_scalar();
            compute_frustrum();
        }
    }

    void set_fov(const float f, dword update=ESCH_UPD_ALL)
    {
        flags &= ~ESCH_CAM_ORTHO;
        fov=f;
        if (update & ESCH_UPD_SCALAR)
        {
            compute_scalar();
            compute_frustrum();
        }
    }

    void set_ortho(const float w, const float h=0, dword update=ESCH_UPD_ALL)
    {
        flags |= ESCH_CAM_ORTHO;
        width = w;
        height = h;
        if (update & ESCH_UPD_SCALAR)
        {
            compute_scalar();
            compute_frustrum();
        }
    }

    void set_hither(const float h, dword update=ESCH_UPD_ALL)
    {
        hither=h;
        if (update & ESCH_UPD_SCALAR)
        {
            compute_frustrum();
            compute_z_factor();
        }
    }

    void set_yon(const float y, dword update=ESCH_UPD_ALL)
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
    void set_flags(const dword m, const int on)
    {
        if (on)
            flags |= m;
        else
            flags &= ~m;
    }

    void set_app_data(void *p) { app_data = p; }

    void set_aspect_ratio(const float ar, dword update=ESCH_UPD_ALL)
    {
        aspect_ratio=ar;
        if (update & ESCH_UPD_SCALAR)
        {
            compute_scalar();
            compute_frustrum();
        }
    }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Compute functions to calculate viewing constants.                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void compute_scalar();
    void compute_z_factor();
    void compute_frustrum();
    void compute_eye(dword update=ESCH_UPD_ALL);
    void compute_inverse() { eye.compute_inverse(); }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // I/O routines.                                                        �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual esch_error_codes load(const char *fname, const char *cname=0);
    virtual esch_error_codes load(XFParseIFF *iff, const char *cname=0);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCameraEx - Extended camera class.                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschCameraEx : public EschCamera {

protected:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Internal render functions                                            �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual int pre_rend();
    virtual void post_rend();

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members (should be changed only by utility functions).   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    short               bg_offx;            // Bitmap Background window offset
    short               bg_offy;
    VngoTexture         *bg_bitmap;         // Bitmap background

    dword               grd_top;            // Gradient colors
    dword               grd_mid;
    dword               grd_bottom;

    float               grd_topy;           // Heights for gradient changes
    float               grd_midy;
    float               grd_bottomy;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschCameraEx(VngoVport *vport=0);
    EschCameraEx(const char *fname, const char *cname=0);
    EschCameraEx(const EschCamera &cam);
    EschCameraEx(const EschCameraEx &cam);

    virtual ~EschCameraEx();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    const EschCameraEx &operator = (const EschCamera &cam);
    const EschCameraEx &operator = (const EschCameraEx &cam);

    virtual void release();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions.                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void set_bg_offset(short x, short y) { bg_offx=x; bg_offy=y; }

    int set_bg_bitmap(VngoTexture *tex, int owns=1);
    int create_bg_bitmap(XFBitmap *bm);

    int set_haze(float start, float mid);
    int set_haze(float start, float mid, VngoColor24bit tcolor);

    void set_gradient(VngoColor24bit top, float topy,
                      VngoColor24bit mid, float midy,
                      VngoColor24bit bottom, float bottomy, int fixed=0);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - escamera.hpp 憶�

