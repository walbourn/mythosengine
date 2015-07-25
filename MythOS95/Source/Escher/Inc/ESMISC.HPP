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
// esmisc.hpp
//
// Contains miscellaneous classes for use with Escher.
//
// EschStarfield is a space 'starfield' drawable.
//
// EschFireTexture is an animated procedural texture for flame.
//
// EschPlosion is a 'fire-tree' drawable which uses the EschFireTexture
// to create an explosion.
//
// EschMetabox is a 'manually' built cube which can be adjusted to produce
// a variety of solids.
//
// EschLevelOfDetail is a helper drawable for handling multiple levels of
// detail.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __ESMISC_HPP
#define __ESMISC_HPP    1

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

#include "esdraw.hpp"
#include "estxture.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschStarfield - Space 'starfield' drawable.                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschStarfield : public EschDrawable
{
public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    ulong       count;
    EschPoint   *stars;
    dword       *brightness;
    dword       color;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschStarfield() :
        EschDrawable(ESCH_DRWT_STARFIELD),
        stars(0),
        brightness(0) {}

    virtual ~EschStarfield();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    const EschStarfield &operator = (const EschStarfield &sf);

    virtual void draw();

    virtual void release();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility functions.                                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void set_color(dword c) { color=c; }

    esch_error_codes create_stars(ulong c, int dobrights=1);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFireTexture - Procedural fire texture.                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschFireTexture : public EschProceduralTexture
{
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Private data members.                                                ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    int     u_shift;
    int     decay;
    int     more_fire;
    int     fb_control;
    int     taper;
    byte    *flame_bytes;
    byte    *flames;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Private color translation tables.                                    ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    byte    *write_lut;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Private utility functions.                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    esch_error_codes setup_local_tables();

    void smooth_baseline();
    byte get (int u, int v) { return (flames[(v << u_shift)+u]); }
    void put (int u, int v, int intensity)
    {
        int t = (v << u_shift) + u;
        flames[t] = intensity;
        ((byte*)txt.tex)[t] = write_lut[intensity];
    }

    void make_lut(VngoPal *vpal);
    VngoColor24bit to_RGB(float h, float s, float i);

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschFireTexture();
    EschFireTexture(ushort w, ushort h, VngoPal *pal, int dogen=1);

    virtual ~EschFireTexture();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual void release();
    virtual esch_error_codes init(ushort w, ushort h, VngoPal *pal,
                                  int dogen=1);
    virtual void generate();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility functions.                                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void increase(int amount=2)
    {
        if (more_fire + amount < 20)
           more_fire += amount;
        else
           more_fire = 20;
    }
    void decrease(int amount=2)
    {
        if (more_fire - amount > -20)
           more_fire -= amount;
        else
           more_fire = -20;
    }

    void ignite();
    void douse(int smooth_it=1);
    void fireball(int start_fireball=1);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschPlosion - A explosion effect drawable.                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschPlosion : public EschDrawable
{
protected:
    EschTexture     *fire;
    float           step;
    float           fv;

    void check_workspace();

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschFrameRef    world;
    float           width;
    float           height;
    long            alpha_level;

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschPlosion() : EschDrawable(ESCH_DRWT_EXPLOSION), fire(0), fv(0.90f),
                    alpha_level(255)                  { check_workspace(); }
    EschPlosion(float w, float h, EschFireTexture *f);

    virtual ~EschPlosion() {}

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    virtual void draw();
    virtual void animate();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility functions.                                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void get_position(EschPoint *p) const { world.get_position(p); }

    void set_position(float ix, float iy, float iz, dword update=ESCH_UPD_ALL)
    {
        world.set_position(ix, iy, iz, update);
    }
    void set_position(const EschPoint *pnt, dword update=ESCH_UPD_ALL)
    {
        world.set_position(pnt, update);
    }

    void set_top(float ii, float ij, float ik, dword update=ESCH_UPD_ALL)
    {
        world.set_top(ii,ij,ik,update);
    }
    void set_top(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        world.set_top(v, update);
    }

    void set_direction(float ii, float ij, float ik, dword update=ESCH_UPD_ALL)
    {
        world.set_direction(ii, ij, ik, update);
    }
    void set_direction(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        world.set_direction(v, update);
    }

    void rotatex(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.rotatex(degrees,update);
    }
    void rotatey(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.rotatey(degrees,update);
    }
    void rotatez(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.rotatez(degrees,update);
    }

    void rotate(const EschVector *v, const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.rotate(v,degrees,update);
    }

    void pitch(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.pitch(degrees,update);
    }
    void roll(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.roll(degrees,update);
    }
    void yaw(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.yaw(degrees,update);
    }

    void translate(const float idx, const float idy, const float idz, dword update=ESCH_UPD_ALL)
    {
        world.translate(idx,idy,idz,update);
    }
    void translate(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        world.translate(v,update);
    }

    void move(const float idx, const float idy, const float idz, dword update=ESCH_UPD_ALL)
    {
        world.move(idx,idy,idz,update);
    }
    void move(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        world.move(v,update);
    }

    void scale(const float is, dword update=ESCH_UPD_ALL)
    {
        world.scale(is,update);
    }

    void orthogonalize(dword update=ESCH_UPD_ALL)
    {
        world.orthogonalize(update);
    }
    void orthogonalize_top(dword update=ESCH_UPD_ALL)
    {
        world.orthogonalize_top(update);
    }
    void orthogonalize_right(dword update=ESCH_UPD_ALL)
    {
        world.orthogonalize_right(update);
    }

    void set_size(float w, float h)
    {
        width=w;
        height=h;
    }

    void set_fire(EschTexture *f) { fire=f; }

    void set_step(float i) { step=i; }

    void reset() { fv=float(0.90); }

    void set_alpha(long alpha) { alpha_level = alpha; }
    long get_alpha() const { return alpha_level; }
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMetabox - A controllable box drawable.                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschMetabox : public EschDrawable
{
protected:
    long            alpha_level;

    void check_workspace();

public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschFrameRef    world;
    EschPoint       corner[8];
    dword           color[6];
    EschTexture     *txt[6];
    float           u[4];
    float           v[4];

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschMetabox();
    virtual ~EschMetabox();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    const EschMetabox &operator = (const EschMetabox &that);

    virtual void draw();
    virtual void animate();
    virtual void release();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility functions.                                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    void get_position(EschPoint *p) const { world.get_position(p); }

    void set_position(float ix, float iy, float iz, dword update=ESCH_UPD_ALL)
    {
        world.set_position(ix, iy, iz, update);
    }
    void set_position(const EschPoint *pnt, dword update=ESCH_UPD_ALL)
    {
        world.set_position(pnt->x, pnt->y, pnt->z, update);
    }

    void set_top(float ii, float ij, float ik, dword update=ESCH_UPD_ALL)
    {
        world.set_top(ii,ij,ik,update);
    }
    void set_top(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        world.set_top(v,update);
    }

    void set_direction(float ii, float ij, float ik, dword update=ESCH_UPD_ALL)
    {
        world.set_direction(ii, ij, ik, update);
    }
    void set_direction(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        world.set_direction(v, update);
    }

    void rotatex(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.rotatex(degrees,update);
    }
    void rotatey(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.rotatey(degrees,update);
    }
    void rotatez(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.rotatez(degrees,update);
    }

    void rotate(const EschVector *v, const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.rotate(v,degrees,update);
    }

    void pitch(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.pitch(degrees,update);
    }
    void roll(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.roll(degrees,update);
    }
    void yaw(const float degrees, dword update=ESCH_UPD_ALL)
    {
        world.yaw(degrees,update);
    }

    void translate(const float idx, const float idy, const float idz, dword update=ESCH_UPD_ALL)
    {
        world.translate(idx,idy,idz,update);
    }
    void translate(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        world.translate(v,update);
    }

    void move(const float idx, const float idy, const float idz, dword update=ESCH_UPD_ALL)
    {
        world.move(idx,idy,idz,update);
    }
    void move(const EschVector *v, dword update=ESCH_UPD_ALL)
    {
        world.move(v,update);
    }

    void scale(const float is, dword update=ESCH_UPD_ALL)
    {
        world.scale(is,update);
    }

    void orthogonalize(dword update=ESCH_UPD_ALL)
    {
        world.orthogonalize(update);
    }
    void orthogonalize_top(dword update=ESCH_UPD_ALL)
    {
        world.orthogonalize_top(update);
    }
    void orthogonalize_right(dword update=ESCH_UPD_ALL)
    {
        world.orthogonalize_right(update);
    }

    void reset() { world.reset(); }

    void set_color(dword clr, int face = -1);
    void set_texture(EschTexture *t, int face = -1);
    void set_texture_uv(float u1, float v1,
                        float u2, float v2,
                        float u3, float v3,
                        float u4, float v4)
    {
        u[0] = u1;  u[1] = u2;  u[2] = u3;  u[3] = u4;
        v[0] = v1;  v[1] = v2;  v[2] = v3;  v[3] = v4;
    }

    void create_cube(float size);

    void set_alpha(long alpha) { alpha_level = alpha; }
    long get_alpha() const { return alpha_level; }
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschLevelOfDetail - Level of detail drawable.                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
class EschLevelOfDetail : public EschDrawable
{
public:
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Public data members                                                  ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    ushort          nlevels;
    ushort          current;
    ushort          change;
    ushort          na;
    dword           color;
    EschGeometry    *geom[ESCH_LOD_MAX_LEVELS];
    static float    dist[ESCH_LOD_MAX_LEVELS];

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Constructor/Destructors                                              ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    EschLevelOfDetail();

    virtual ~EschLevelOfDetail();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Operations                                                           ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    const EschLevelOfDetail &operator = (const EschLevelOfDetail &that);

    virtual EschDrawable *find(const char *dname) const;

    virtual void draw();

    virtual int get_extents(EschSphereExtents *sp) const;

    virtual float ray(const EschPoint *pt, const EschVector *v, int coarse=0) const;

    virtual int hit(const EschPoint *pt, const float r, int coarse=0) const;

    virtual esch_error_codes pick(EschPicking *data) const;
    virtual esch_error_codes collide(EschCollision *data) const;

    virtual void animate();

    virtual void release();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
    // Utility functions.                                                   ³
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
    int add(EschGeometry *g);

    void set_nlevels(ushort n) { nlevels=n; }
    void set_current(ushort n) { current=n; }

    void set_color(dword c) { color=c; }

    static void set_dist(ushort lvl, float d);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - esmisc.hpp ²±°

