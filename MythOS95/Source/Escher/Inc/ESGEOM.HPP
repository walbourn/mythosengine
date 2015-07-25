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

    virtual Flx16 ray(const EschPoint *pt, const EschVector *v, int coarse=0) const;

    virtual int hit(const EschPoint *pt, const Flx16 r, int coarse=0) const;

    virtual esch_error_codes pick(EschPicking *data) const;
    virtual esch_error_codes collide(EschCollision *data) const;

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
    void set_position(const Flx16 ix, const Flx16 iy, const Flx16 iz, dword update=ESCH_UPD_ALL)
    {
        local.set_position(ix,iy,iz,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    
    void rotatex(const Flx16 degrees, dword update=ESCH_UPD_ALL)
    {
        local.rotatex(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void rotatey(const Flx16 degrees, dword update=ESCH_UPD_ALL)
    {
        local.rotatey(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void rotatez(const Flx16 degrees, dword update=ESCH_UPD_ALL)
    {
        local.rotatez(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    
    void rotate(const EschVector *v, const Flx16 degrees, dword update=ESCH_UPD_ALL)
    {
        local.rotate(v,degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    
    void pitch(const Flx16 degrees, dword update=ESCH_UPD_ALL)
    {
        local.pitch(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void roll(const Flx16 degrees, dword update=ESCH_UPD_ALL)
    {
        local.roll(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void yaw(const Flx16 degrees, dword update=ESCH_UPD_ALL)
    {
        local.yaw(degrees,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    
    void translate(const Flx16 idx, const Flx16 idy, const Flx16 idz, dword update=ESCH_UPD_ALL)
    {
        local.translate(idx,idy,idz,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void translate(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        local.translate(v,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    
    void move(const Flx16 idx, const Flx16 idy, const Flx16 idz, dword update=ESCH_UPD_ALL)
    {
        local.move(idx,idy,idz,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    void move(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        local.move(v,update);
        if (update & ESCH_UPD_WORLD)  compute_world(update);
    }
    
    void scale(const Flx16 is, dword update=ESCH_UPD_ALL)
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
    Flx16           u[3];                   // Texture map coords.
    Flx16           v[3];
    dword           color;                  // Base-color
    EschVector      normal;                 // Face normal.

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschFace() {}
    EschFace(dword _f, word _a, word _b, word _c, word _txt,
             Flx16 _u0, Flx16 _u1, Flx16 _u2,
             Flx16 _v0, Flx16 _v1, Flx16 _v2,
             dword _clr, Flx16 _i, Flx16 _j, Flx16 _k) :
        flags(_f),
        a(_a), b(_b), c(_c),
        txt(_txt),
        color(_clr),
        normal(_i,_j,_k)

    {
        u[0] = _u0;
        u[1] = _u1;
        u[2] = _u2;
        v[0] = _v0;
        v[1] = _v1;
        v[2] = _v2;
    }

    ~EschFace() {}
};


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
    EschMesh(const char *fname=0, const char *oname=0,
             VngoPal *pal=0, EschMatrix *m=0, char *pn=0);

    virtual ~EschMesh();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual esch_error_codes release();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility routines.                                                    ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void set_flags(dword f) { flags = f; }

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // I/O Routines.                                                        ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual esch_error_codes load(const char *fname, const char *oname=0,
                                  VngoPal *pal=0, EschMatrix *m=0, char *pn=0);
    virtual esch_error_codes load(XFParseIFF *iff, const char *oname=0,
                                  VngoPal *pal=0, EschMatrix *m=0, char *pn=0);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMeshDraw - Drawing instance attached to a mesh object.               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschMeshDraw : public EschGeometry {

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
                 VngoPal *pal=0, EschMesh *msh=0, char *pn=0);
    EschMeshDraw(const EschMeshDraw &msdh);

    virtual ~EschMeshDraw();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    const EschMeshDraw &operator = (const EschMeshDraw &mshd);

    virtual void draw();
    
    virtual Flx16 ray(const EschPoint *pt, const EschVector *v, int coarse=0) const;

    virtual int hit(const EschPoint *pt, const Flx16 r, int coarse=0) const;

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

    virtual esch_error_codes load(const char *fname, const char *oname=0,
                                  VngoPal *pal=0, EschMesh *msh=0, char *pn=0);
    virtual esch_error_codes load(XFParseIFF *iff, const char *oname=0,
                                  VngoPal *pal=0, EschMesh *msh=0, char *pn=0);
};

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern "C" void esch_clipdraw_face(ulong ind, dword ctrlfl=ESCH_CDF_CLIP);
extern "C" void esch_clip_poly(VngoVbuffer *vport,VngoPoint *points, ulong *n_vertices);
extern "C" void esch_zclip_poly(Flx16 hither, Flx16 yon,VngoPoint *points, ulong *n_vertices);
extern "C" void esch_clip_x_line(long p,VngoPoint *s, VngoPoint *f, VngoPoint *out_put);
extern "C" void esch_clip_y_line(long p,VngoPoint *s, VngoPoint *f, VngoPoint *out_put);
extern "C" void esch_clip_z_line(long p,VngoPoint *s, VngoPoint *f, VngoPoint *out_put);
extern "C" int esch_rotate_check(ulong count,VngoPoint *pts);

#ifdef __WATCOMC__
#pragma aux (_ASMSTKCALL_) esch_clipdraw_face;
#pragma aux (_ASMSTKCALL_) esch_clip_poly;
#pragma aux (_ASMSTKCALL_) esch_clip_x_line;
#pragma aux (_ASMSTKCALL_) esch_clip_y_line;
#pragma aux (_ASMSTKCALL_) esch_clip_z_line;
#pragma aux (_ASMSTKCALL_) esch_rotate_check;

#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - esgeom.hpp ²±°

