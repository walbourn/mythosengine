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
// esbuild.hpp
//
// Contains the EschBuild class definitions.
//
// EschBuildTexture is used to create materials manually and save them
// into an IFF file.
//
// EschBuildMesh is used to create MeshDraws manually and save them
// into an IFF file.
//
//���������������������������������������������������������������������������

#ifndef __ESBUILD_HPP
#define __ESBUILD_HPP   1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//             
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <portable.h>
#include <ivory.hpp>

#include "esgeom.hpp"

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

class XFBitmap;

//�������������������������������������������������������������������������Ŀ
// EschBuildTexture - Texture builder class.                                �
//���������������������������������������������������������������������������
class EschBuildTexture {
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    char            name[ESCH_MAX_NAME];

    dword           tflags;
    
    ulong           nframes;
    ulong           maxframes;
    XFBitmap        **bms;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschBuildTexture();
    EschBuildTexture(ulong mf);

    ~EschBuildTexture();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    esch_error_codes init(ulong mf=1);
    void release(int freebms=0);

    esch_error_codes save(const char *fname, dword ctrlfl=ESCH_TBLD_8BIT, VngoPal *pal=0);
    esch_error_codes save(XFParseIFF *iff, dword ctrlfl=ESCH_TBLD_8BIT, VngoPal *pal=0);

    //���������������������������������������������������������������������Ŀ
    // Utility routines.                                                    �
    //�����������������������������������������������������������������������
    void set_texture_flags(dword f)
    {
        tflags=f & ~(ESCH_TXT_LOCKED|ESCH_TXT_OWNSDATA|ESCH_TXT_SHARED);
    }

    esch_error_codes add_frame(XFBitmap *bm);
    esch_error_codes set_frame(ulong i, XFBitmap *bm, int freeold=0);
};


//�������������������������������������������������������������������������Ŀ
// EschBuildMesh - Mesh builder class.                                      �
//���������������������������������������������������������������������������
class EschBuildMesh {
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    char                name[ESCH_MAX_NAME];

    dword               mflags;
    dword               fflags;

    EschFrameRef        orient;

    ulong               nverts;
    ulong               maxverts;
    EschVertex          *v;

    ulong               nfaces;
    ulong               maxfaces;
    EschFace            *f;

    ulong               ntxts;
    ulong               maxtxts;
    EschBuildTexture    **txt;

    EschSphereExtents   sphere;
    EschBoxExtents      box;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschBuildMesh();
    EschBuildMesh(ulong mv, ulong mf, ulong mt=256);

    ~EschBuildMesh();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    esch_error_codes init(ulong mv, ulong mf, ulong mt=256);
    void release(int freetxts=0);

    esch_error_codes save(const char *fname, dword ctrlfl=ESCH_MBLD_ALL,
                          dword tcfl=ESCH_TBLD_8BIT, VngoPal *pal=0);
    esch_error_codes save(XFParseIFF *iff, dword ctrlfl=ESCH_MBLD_ALL,
                          dword tcfl=ESCH_TBLD_8BIT, VngoPal *pal=0);

    //���������������������������������������������������������������������Ŀ
    // Utility routines.                                                    �
    //�����������������������������������������������������������������������
    void set_mesh_flags(dword f)
    {
        mflags=f & ~(ESCH_MSH_OWNSDATA|ESCH_MSH_OWNSTEXTURE);
    }
    void set_face_flags(dword f)
    {
        fflags=f & ~ESCH_FACE_TEXTURED;
    }

    void set_extents(const EschSphereExtents *s) { sphere=*s; }
    void set_extents(const EschBoxExtents *b) { box=*b; }

    esch_error_codes add_vertex(const EschVertex *vtx);
    esch_error_codes add_vertex(const EschPoint *pnt)
    {
        EschVertex vtx(pnt,0,0,0);
        return add_vertex(&vtx);
    }
    esch_error_codes add_vertex(Flx16 ix, Flx16 iy, Flx16 iz)
    {
        EschVertex vtx(ix,iy,iz,0,0,0);
        return add_vertex (&vtx);
    }

    esch_error_codes set_vertex(ulong i, const EschVertex *vtx);
    esch_error_codes set_vertex(ulong i, const EschPoint *pnt)
    {
        EschVertex vtx(pnt,0,0,0);
        return set_vertex(i,&vtx);
    }
    esch_error_codes set_vertex(ulong i, Flx16 ix, Flx16 iy, Flx16 iz)
    {
        EschVertex vtx(ix,iy,iz,0,0,0);
        return set_vertex(i,&vtx);
    }

    esch_error_codes add_face(const EschFace *face);
    esch_error_codes add_face(word a, word b, word c, dword color)
    {
        EschFace   face(fflags,
                        a,b,c,
                        0,0,0,0,0,0,0,
                        color,0,0,0);
        return add_face(&face);
    }
    esch_error_codes add_face(word a, word b, word c, dword color,
                              word txt, Flx16 u[], Flx16 v[])
    {
        EschFace   face(fflags | ESCH_FACE_TEXTURED,
                        a,b,c,
                        txt, u[0], u[1], u[2], v[0], v[1], v[2],
                        color,0,0,0);
        return add_face(&face);
    }

    esch_error_codes set_face(ulong i, const EschFace *face);
    esch_error_codes set_face(ulong i, word a, word b, word c, dword color)
    {
        EschFace   face(fflags,
                        a,b,c,
                        0,0,0,0,0,0,0,
                        color,0,0,0);
        return set_face(i, &face);
    }
    esch_error_codes set_face(ulong i, word a, word b, word c, dword color,
                                       word txt, Flx16 u[], Flx16 v[])
    {
        EschFace   face(fflags | ESCH_FACE_TEXTURED,
                        a,b,c,
                        txt, u[0], u[1], u[2], v[0], v[1], v[2],
                        color,0,0,0);
        return set_face(i, &face);
    }

    esch_error_codes add_texture(EschBuildTexture *t);

    esch_error_codes set_texture(ulong i, EschBuildTexture *t, int freeold=0);

    esch_error_codes compute_extents(int optimal=1, int sph_only=0);

    esch_error_codes compute_normals(int vtx_only=0);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - esbuild.hpp ���
