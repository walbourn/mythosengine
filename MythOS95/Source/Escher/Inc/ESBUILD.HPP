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
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __ESBUILD_HPP
#define __ESBUILD_HPP   1

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
#include <ivory.hpp>

#include "esgeom.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class XFBitmap;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildTexture - Texture builder class.                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschBuildTexture {
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    char            name[ESCH_MAX_NAME];

    dword           tflags;

    ulong           nframes;
    ulong           maxframes;
    XFBitmap        **bms;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschBuildTexture();
    EschBuildTexture(ulong mf);

    ~EschBuildTexture();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    esch_error_codes init(ulong mf=1);
    void release(int freebms=0);

    esch_error_codes save(const char *fname, dword ctrlfl=ESCH_TBLD_8BIT, VngoPal *pal=0);
    esch_error_codes save(XFParseIFF *iff, dword ctrlfl=ESCH_TBLD_8BIT, VngoPal *pal=0);

    esch_error_codes load(const char *fname, const char *tname=0, VngoPal *pal=0);
    esch_error_codes load(XFParseIFF *iff, const char *tname=0, VngoPal *pal=0);

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility routines.                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void set_texture_flags(dword f)
    {
        tflags=f & ~(ESCH_TXT_LOCKED|ESCH_TXT_OWNSDATA|ESCH_TXT_SHARED);
    }

    esch_error_codes add_frame(XFBitmap *bm);
    esch_error_codes set_frame(ulong i, XFBitmap *bm, int freeold=0);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildMesh - Mesh builder class.                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschBuildMesh {
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    char                name[ESCH_MAX_NAME];

    dword               mflags;
    dword               fflags;

    byte                selfi;
    byte                alpha_a;
    byte                alpha_b;
    byte                alpha_c;

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

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschBuildMesh();
    EschBuildMesh(ulong mv, ulong mf, ulong mt=256);

    ~EschBuildMesh();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    esch_error_codes init(ulong mv, ulong mf, ulong mt=256);
    void release(int freetxts=0);

    esch_error_codes save(const char *fname, dword ctrlfl=ESCH_MBLD_ALL,
                          dword tcfl=ESCH_TBLD_8BIT, VngoPal *pal=0);
    esch_error_codes save(XFParseIFF *iff, dword ctrlfl=ESCH_MBLD_ALL,
                          dword tcfl=ESCH_TBLD_8BIT, VngoPal *pal=0);

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility routines.                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void set_mesh_flags(dword f)
    {
        mflags=f & ~(ESCH_MSH_OWNSDATA|ESCH_MSH_OWNSTEXTURE);
    }
    void set_face_flags(dword f)
    {
        fflags=f & ~ESCH_FACE_TEXTURED;
    }
    void set_self_illum(byte s) { selfi = s; }
    void set_alpha(byte a) { alpha_a = alpha_b = alpha_c = a; }

    void set_extents(const EschSphereExtents *s) { sphere=*s; }
    void set_extents(const EschBoxExtents *b) { box=*b; }

    esch_error_codes add_vertex(const EschVertex *vtx);
    esch_error_codes add_vertex(const EschPoint *pnt)
    {
        EschVertex vtx(pnt,0,0,0);
        return add_vertex(&vtx);
    }
    esch_error_codes add_vertex(float ix, float iy, float iz)
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
    esch_error_codes set_vertex(ulong i, float ix, float iy, float iz)
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
                        color,0,0,0,
                        selfi,alpha_a,alpha_b,alpha_c);
        return add_face(&face);
    }
    esch_error_codes add_face(word a, word b, word c, dword color,
                              word txt, float u[], float v[])
    {
        EschFace   face(fflags | ESCH_FACE_TEXTURED,
                        a,b,c,
                        txt, u[0], u[1], u[2], v[0], v[1], v[2],
                        color,0,0,0,
                        selfi,alpha_a,alpha_b,alpha_c);
        return add_face(&face);
    }

    esch_error_codes set_face(ulong i, const EschFace *face);
    esch_error_codes set_face(ulong i, word a, word b, word c, dword color)
    {
        EschFace   face(fflags,
                        a,b,c,
                        0,0,0,0,0,0,0,
                        color,0,0,0,
                        selfi,alpha_a,alpha_b,alpha_c);
        return set_face(i, &face);
    }
    esch_error_codes set_face(ulong i, word a, word b, word c, dword color,
                                       word txt, float u[], float v[])
    {
        EschFace   face(fflags | ESCH_FACE_TEXTURED,
                        a,b,c,
                        txt, u[0], u[1], u[2], v[0], v[1], v[2],
                        color,0,0,0,
                        selfi,alpha_a,alpha_b,alpha_c);
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

//葦� End of header - esbuild.hpp 憶�

