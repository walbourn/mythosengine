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
// esgeom.hpp
//
// Contains the EschGeometry, derived, and support classes for drawing 3D
// objects.
//
// EschGeometry is the abstract base class for the 3D objects which includes 
// the tree connections, frame of reference, extents, and various object
// operations.
//
// EschFace is the container type for triangular face data.
//
// EschMesh is the container type for polygonal mesh data used by the
// EschMeshDraw class.
//
// EschMeshDraw is the drawable type which displays polygonal mesh objects.
// It includes the EschGeometry interface.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __ESGEOM_HPP
#define __ESGEOM_HPP    1

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

#include <xfile.hpp>

#include "esdefs.h"
#include "esdraw.hpp"
#include "esexts.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschGeometry - Abstract base class for 3D drawable objects.              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschGeometry : public EschDrawable {

protected:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Protected data members                                               ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschGeometry    *iparent;               // Geometry tree pointers
    EschGeometry    *ichild;

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschFrameRef    local;                  // Local to parent frame-of-ref
    EschFrameRef    world;                  // Local to world frame-of-ref

    EschSphereExtents   *sphere;            // Object extents
    EschSphereExtents   exts;               // Extents inclusive of children

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschGeometry();
    EschGeometry(const EschGeometry &g);

    virtual ~EschGeometry();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Accessor functions                                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschGeometry *next() const { return (EschGeometry*)inext; }
    EschGeometry *prev() const { return (EschGeometry*)iprev; }
    EschGeometry *parent() const { return iparent; }
    EschGeometry *child() const { return ichild; }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    const EschGeometry &operator = (const EschGeometry &geom);

    virtual void draw();

    virtual void sibling(EschGeometry *myprev, dword update=ESCH_UPD_ALL);
    virtual void adopt(EschGeometry *myparent, dword update=ESCH_UPD_ALL);
    virtual void remove(int delchild=0, dword update=ESCH_UPD_ALL);

    virtual EschDrawable *find(const char *dname) const;

    virtual int get_extents(EschSphereExtents *sp) const;

    virtual float ray(const EschPoint *pt, const EschVector *v, int coarse=0) const;

    virtual int hit(const EschPoint *pt, const float r, int coarse=0) const;

    virtual esch_error_codes pick(EschPicking *data) const;
    virtual esch_error_codes collide(EschCollision *data) const;

    virtual void animate();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility functions                                                    ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void draw_extents(dword clr) const
    {
        exts.draw(&world,clr);
    }

    void get_position(EschPoint *pt) const
    {
        local.get_position(pt);
    }

    void set_position(const EschPoint *pt, dword update=ESCH_UPD_ALL)
    {
        local.set_position(pt,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void set_position(const float ix, const float iy, const float iz, dword update=ESCH_UPD_ALL)
    {
        local.set_position(ix,iy,iz,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void set_top(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        local.set_top(v,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void set_top(float ii, float ij, float ik, dword update=ESCH_UPD_ALL)
    {
        local.set_top(ii,ij,ik,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void set_direction(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        local.set_direction(v,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void set_direction(float ii, float ij, float ik, dword update=ESCH_UPD_ALL)
    {
        local.set_direction(ii,ij,ik,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void rotatex(const float degrees, dword update=ESCH_UPD_ALL)
    {
        local.rotatex(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void rotatey(const float degrees, dword update=ESCH_UPD_ALL)
    {
        local.rotatey(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void rotatez(const float degrees, dword update=ESCH_UPD_ALL)
    {
        local.rotatez(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void rotate(const EschVector *v, const float degrees, dword update=ESCH_UPD_ALL)
    {
        local.rotate(v,degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void pitch(const float degrees, dword update=ESCH_UPD_ALL)
    {
        local.pitch(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void roll(const float degrees, dword update=ESCH_UPD_ALL)
    {
        local.roll(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void yaw(const float degrees, dword update=ESCH_UPD_ALL)
    {
        local.yaw(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void translate(const float idx, const float idy, const float idz, dword update=ESCH_UPD_ALL)
    {
        local.translate(idx,idy,idz,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void translate(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        local.translate(v,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void move(const float idx, const float idy, const float idz, dword update=ESCH_UPD_ALL)
    {
        local.move(idx,idy,idz,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void move(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        local.move(v,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void scale(const float is, dword update=ESCH_UPD_ALL)
    {
        local.scale(is,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void orthogonalize(dword update=ESCH_UPD_ALL)
    {
        local.orthogonalize(update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void orthogonalize_top(dword update=ESCH_UPD_ALL)
    {
        local.orthogonalize_top(update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void orthogonalize_right(dword update=ESCH_UPD_ALL)
    {
        local.orthogonalize_right(update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    void reset(dword update=ESCH_UPD_ALL)
    {
        local.reset();
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Compute functions                                                    ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void compute_world(dword update=ESCH_UPD_ALL);
    void compute_extents(int partialfix=0, int doparent=1);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFace - Support object contains the definition of a triangular face   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschFace {

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    dword           flags;                  // Face flags
    word            a;                      // Triangle verticies.
    word            b;
    word            c;
    word            txt;                    // Texture index (0 for none).
    float           u[3];                   // Texture map coords.
    float           v[3];
    dword           color;                  // Base-color
    EschVector      normal;                 // Face normal.
    byte            self_illum;             // Self-illumination value (0=off)
    byte            alpha_a;                // Triangle alpha values
    byte            alpha_b;
    byte            alpha_c;
    void            *app_data;              // Application data pointer

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschFace() : app_data(0) {}
    EschFace(dword _f, word _a, word _b, word _c, word _txt,
             float _u0, float _u1, float _u2,
             float _v0, float _v1, float _v2,
             dword _clr, float _i, float _j, float _k,
             byte _si=0,
             byte _aa=255, byte _ab=255, byte _ac=255, void *_app=0) :
        flags(_f),
        a(_a), b(_b), c(_c),
        txt(_txt),
        color(_clr),
        normal(_i,_j,_k),
        self_illum(_si),
        alpha_a(_aa),
        alpha_b(_ab),
        alpha_c(_ac),
        app_data(_app)
    {
        u[0] = _u0;
        u[1] = _u1;
        u[2] = _u2;
        v[0] = _v0;
        v[1] = _v1;
        v[2] = _v2;
    }

    ~EschFace() {}

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility routines.                                                    ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void set_flags(dword f) { flags = f; }

    void set_app_data(void *p) { app_data = p; }

    long get_alpha() const { return alpha_a; }
    void set_alpha(long alpha) { alpha_a = (byte)alpha; }
};


class EschTexture;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMesh - Container object for a mesh of triangular faces.              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschMesh {

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    ulong           ref_count;              // Reference count for attachments

    dword           flags;
    char            name[ESCH_MAX_NAME];

    EschSphereExtents   sphere;             // Object extents.
    EschBoxExtents      box;

    ulong           nverts;                 // Vertex data.
    IvoryHandle     v;

    ulong           nfaces;                 // Face data.
    IvoryHandle     f;

    ulong           tmax;                   // Original texture data.
    EschTexture     **txt;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschMesh();
    EschMesh(const char *fname, const char *oname=0,
             VngoPal *pal=0, EschMatrix *m=0, char *pn=0,
             dword ctrlfl=ESCH_MSHLD_ALL);
    EschMesh(const EschMesh &msh);

    virtual ~EschMesh();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    const EschMesh &operator = (const EschMesh &msh);

    virtual esch_error_codes release();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility routines.                                                    ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void set_flags(dword f) { flags = f; }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // I/O Routines.                                                        ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual esch_error_codes load(const char *fname, const char *oname=0,
                                  VngoPal *pal=0, EschMatrix *m=0, char *pn=0,
                                  dword ctrlfl=ESCH_MSHLD_ALL);
    virtual esch_error_codes load(XFParseIFF *iff, const char *oname=0,
                                  VngoPal *pal=0, EschMatrix *m=0, char *pn=0,
                                  dword ctrlfl=ESCH_MSHLD_ALL);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMeshDraw - Drawing instance attached to a mesh object.               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschMeshDraw : public EschGeometry {

    static EschMeshDraw *clone_helper(EschMeshDraw *_parent,
                                      const EschMeshDraw *_refmsh, int dupmf);

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschMesh        *mesh;                  // Attached EschMesh object

    ulong           tmax;                   // Instance texture data.
    EschTexture     **txt;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschMeshDraw(EschMesh *mdata=0);
    EschMeshDraw(const char *fname, const char *oname=0,
                 VngoPal *pal=0, EschMesh *msh=0, char *pn=0,
                 dword ctrlfl=ESCH_MSHLD_ALL);
    EschMeshDraw(const EschMeshDraw &msdh);

    virtual ~EschMeshDraw();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    const EschMeshDraw &operator = (const EschMeshDraw &mshd);

    virtual void draw();

    virtual float ray(const EschPoint *pt, const EschVector *v, int coarse=0) const;

    virtual int hit(const EschPoint *pt, const float r, int coarse=0) const;

    virtual void animate();

    // Attaches/detatches an EschMesh object to the mesh
    esch_error_codes attach(EschMesh *mdata, dword update=ESCH_UPD_ALL);
    void detach();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility functions                                                    ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void draw_extents(dword clr, int box=0) const
    {
        if (box)
        {
#ifdef assertMyth
            assertMyth("EschMeshDraw::draw_extents assumes attached mesh",
                       mesh != 0 && mesh->ref_count);
#endif
            if (mesh)
                mesh->box.draw(&world,clr);
        }
        else
            exts.draw(&world,clr);
    }

    EschMeshDraw *clone(int dupmf=1) const { return clone_helper(0, this, dupmf); }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // I/O Routines.                                                        ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual esch_error_codes load(const char *fname, const char *oname=0,
                                  VngoPal *pal=0, EschMesh *msh=0, char *pn=0,
                                  dword ctrlfl=ESCH_MSHLD_ALL);
    virtual esch_error_codes load(XFParseIFF *iff, const char *oname=0,
                                  VngoPal *pal=0, EschMesh *msh=0, char *pn=0,
                                  dword ctrlfl=ESCH_MSHLD_ALL);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - esgeom.hpp ²±°

