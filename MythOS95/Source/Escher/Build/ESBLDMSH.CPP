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
// esbldmsh.cpp
//
// The EschBuildMesh class provides a method for creating polygonal
// meshes manually.  The class can write a data file for later use.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "escher.hpp"
#include "esfile.hpp"

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

extern char EschNoName[];

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschBuildMesh - Constructor                                              �
//                                                                          �
// Intializes the instance                                                  �
//���������������������������������������������������������������������������
EschBuildMesh::EschBuildMesh() :
    mflags(0),
    fflags(ESCH_FACE_ABLINE
           | ESCH_FACE_BCLINE
           | ESCH_FACE_CALINE
           | ESCH_FACE_WIRE
           | ESCH_FACE_SOLID
           | ESCH_FACE_ALLOWPERSP
           | ESCH_FACE_ONESIDED
           | ESCH_FACE_SPECULAR
           | ESCH_FACE_SMOOTH
           | ESCH_FACE_FLAT),
    v(0),
    f(0),
    txt(0)
{
    strcpy(name,EschNoName);
}

EschBuildMesh::EschBuildMesh(ulong mv, ulong mf, ulong mt) :
    mflags(0),
    fflags(ESCH_FACE_ABLINE
           | ESCH_FACE_BCLINE
           | ESCH_FACE_CALINE
           | ESCH_FACE_WIRE
           | ESCH_FACE_SOLID
           | ESCH_FACE_ALLOWPERSP
           | ESCH_FACE_ONESIDED
           | ESCH_FACE_SPECULAR
           | ESCH_FACE_SMOOTH
           | ESCH_FACE_FLAT),
    v(0),
    f(0),
    txt(0)
{
    strcpy(name,EschNoName);

    init(mv,mf,mt);
}


//�������������������������������������������������������������������������Ŀ
// EschBuildMesh - Destructor                                               �
//                                                                          �
// Ensures data is released.                                                �
//���������������������������������������������������������������������������
EschBuildMesh::~EschBuildMesh()
{
    release();
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschBuildMesh - init                                                     �
//                                                                          �
// Initializes the instance, creating needed memory pools.                  �
//���������������������������������������������������������������������������
esch_error_codes EschBuildMesh::init(ulong mv, ulong mf, ulong mt)
{
    if (!mv || !mf)
        return ESCH_ERR_INVALIDPARMS;

    release();

//��� Verticies
    nverts = 0;
    maxverts = mv;
    v = new EschVertex[mv];
    if (!v)
        return ESCH_ERR_NOMEMORY;

//��� Faces
    nfaces = 0;
    maxfaces = mf;
    f = new EschFace[mf];
    if (!f)
        return ESCH_ERR_NOMEMORY;

//��� Textures
    ntxts = 0;
    maxtxts = mt;
    if (mt > 0)
    {
        txt = new EschBuildTexture *[mt];
        if (!txt)
            return ESCH_ERR_NOMEMORY;
    }

    return ESCH_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// EschBuildMesh - release                                                  �
//                                                                          �
// Frees all used memory.                                                   �
//���������������������������������������������������������������������������
void EschBuildMesh::release(int freetxts)
{
    if (v)
    {
        delete [] v;
        v=0;
    }
    if (f)
    {
        delete [] f;
        f=0;
    }
    if (txt)
    {
        for(ulong i=0; i < ntxts; i++)
        {
            if (freetxts && txt[i])
                delete txt[i];
        }
        delete [] txt;
        txt=0;
    }
}


//�������������������������������������������������������������������������Ŀ
// EschBuildMesh - save                                                     �
//                                                                          �
// Saves data to a data file base on data in builder.                       �
//���������������������������������������������������������������������������
esch_error_codes EschBuildMesh::save(const char *fname, dword ctrlfl,
                                     dword tcfl, VngoPal *pal)
{
    XFParseIFF  iff;

    if (iff.create(fname,0))
    {
        return ESCH_ERR_FILEERROR;
    }

    esch_error_codes err = save(&iff,ctrlfl,tcfl,pal);
    if (err)
        return err;

    iff.close();

    return ESCH_ERR_NONE;
}

esch_error_codes EschBuildMesh::save(XFParseIFF *iff, dword ctrlfl,
                                     dword tcfl, VngoPal *pal)
{
    if (!v || !f || !nverts || !nfaces)
        return ESCH_ERR_MISSINGDATA;

    if (ctrlfl & ESCH_MBLD_INSCENE)
    {
        if (iff->newform(iff->makeid('E','S','E','N')))
            return ESCH_ERR_FILEERROR;

        EschFileSceneHDR    header;
        memset(&header,0,sizeof(header));
        strncpy(header.name,name,sizeof(header.name));
        header.nobjects = 1;

        if (iff->write(iff->makeid('H','D','R',' '),
                       &header,sizeof(header)))
            return ESCH_ERR_FILEERROR;
    }

//��� Create form
    if (iff->newform(iff->makeid('E','M','S','H')))
        return ESCH_ERR_FILEERROR;

//��� Write header
    {
        EschFileMeshHDR     header;
        memset(&header,0,sizeof(header));

        strncpy(header.name,name,sizeof(header.name));
        header.flags = mflags;
        header.nverts = nverts;
        header.nfaces = nfaces;

        if (iff->write(iff->makeid('H','D','R',' '),
                       &header,sizeof(header)))
            return ESCH_ERR_FILEERROR;
    }

//��� Write matrix
    if (ctrlfl & ESCH_MBLD_MATRIX)
    {
        if (iff->write(iff->makeid('M','T','R','X'),
                       &orient.orient.mtx,sizeof(orient.orient.mtx)))
            return ESCH_ERR_FILEERROR;
    }

//��� Write extents
    if (ctrlfl & ESCH_MBLD_EXTENTS)
    {
        EschFileMeshEXNT    exts;
        memset(&exts,0,sizeof(exts));

        exts.cenx = sphere.center.x;
        exts.ceny = sphere.center.y;
        exts.cenz = sphere.center.z;
        exts.extent_radius = sphere.radius;
        exts.minx = box.mins[0];
        exts.miny = box.mins[1];
        exts.minz = box.mins[2];
        exts.maxx = box.maxs[0];
        exts.maxy = box.maxs[1];
        exts.maxz = box.maxs[2];

        if (iff->write(iff->makeid('E','X','N','T'),
                       &exts,sizeof(exts)))
            return ESCH_ERR_FILEERROR;
    }

//��� Write heirarchy

//��� Write verticies
    if (iff->write(iff->makeid('V','E','R','T'),
                   v,sizeof(EschVertex) * nverts))
        return ESCH_ERR_FILEERROR;

//��� Write material names
    if (txt && ntxts)
    {
        EschFileMeshMTL *mtl = new EschFileMeshMTL[ntxts];
        if (!mtl)
            return ESCH_ERR_NOMEMORY;

        for(ulong i=0; i < ntxts; i++)
        {
            strncpy(mtl[i].name,
                    (txt[i]) ? txt[i]->name : EschNoName, ESCH_MAX_NAME);
        }

        if (iff->write(iff->makeid('M','T','L',' '),
                       mtl,sizeof(EschFileMeshMTL)*ntxts))
        {
            delete mtl;
            return ESCH_ERR_FILEERROR;
        }

        delete mtl;
    }

//��� Write faces
    if (iff->write(iff->makeid('F','A','C','E'),
                   f,sizeof(EschFace) * nfaces))
        return ESCH_ERR_FILEERROR;

//��� Write materials
    if (txt && ntxts)
    {
        for(ulong i=0; i < ntxts; i++)
        {
            if (txt[i])
            {
                esch_error_codes err=txt[i]->save(iff,tcfl,pal);
                if (err)
                    return err;
            }
        }
    }

    iff->leaveform();

    if (ctrlfl & ESCH_MBLD_INSCENE)
        iff->leaveform();

    return ESCH_ERR_NONE;
}



//���������������������������������������������������������������������������
//���������������������������  Utility Routines  ����������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschBuildMesh - add_vertex                                               �
//                                                                          �
// Addes a new vertex to the mesh.                                          �
//���������������������������������������������������������������������������
esch_error_codes EschBuildMesh::add_vertex(const EschVertex *vtx)
{
    assertMyth("EschBuildMesh::add_vertex must be called after init",v != 0);

    if (nverts >= maxverts)
        return ESCH_ERR_NOMORE;

    v[nverts++] = *vtx;

    return ESCH_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// EschBuildMesh - set_vertex                                               �
//                                                                          �
// Changes a vertex for the mesh.                                           �
//���������������������������������������������������������������������������
esch_error_codes EschBuildMesh::set_vertex(ulong i, const EschVertex *vtx)
{
    assertMyth("EschBuildMesh::set_vertex must be called after init",v != 0);

    if (i >= nverts)
        return ESCH_ERR_INVALIDPARMS;

    v[i] = *vtx;

    return ESCH_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// EschBuildMesh - add_face                                                 �
//                                                                          �
// Addes a new face to the mesh.                                            �
//���������������������������������������������������������������������������
esch_error_codes EschBuildMesh::add_face(const EschFace *face)
{
    assertMyth("EschBuildMesh::add_face must be called after init",f != 0);

    if (nfaces >= maxfaces)
        return ESCH_ERR_NOMORE;

    if (face->a >= nverts
        || face->b >= nverts
        || face->c >= nverts
        || (face->flags & ESCH_FACE_TEXTURED
            && face->txt >= ntxts))
        return ESCH_ERR_INVALIDPARMS;

    f[nfaces++] = *face;

    return ESCH_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// EschBuildMesh - set_face                                                 �
//                                                                          �
// Changes a face for the mesh.                                             �
//���������������������������������������������������������������������������
esch_error_codes EschBuildMesh::set_face(ulong i, const EschFace *face)
{
    assertMyth("EschBuildMesh::set_face must be called after init",f != 0);

    if (i >= nfaces
        || face->a >= nverts
        || face->b >= nverts
        || face->c >= nverts
        || (face->flags & ESCH_FACE_TEXTURED
            && face->txt >= ntxts))
        return ESCH_ERR_INVALIDPARMS;

    f[i] = *face;

    return ESCH_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// EschBuildMesh - add_texture                                              �
//                                                                          �
// Adds a texture to the mesh.                                              �
//���������������������������������������������������������������������������
esch_error_codes EschBuildMesh::add_texture(EschBuildTexture *t)
{
    if (!txt || ntxts >= maxtxts)
        return ESCH_ERR_NOMORE;

    if (!t)
        return ESCH_ERR_INVALIDPARMS;

    txt[ntxts++] = t;

    return ESCH_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// EschBuildMesh - set_texture                                              �
//                                                                          �
// Changes a texture for the mesh.                                          �
//���������������������������������������������������������������������������
esch_error_codes EschBuildMesh::set_texture(ulong i,
                                            EschBuildTexture *t, int freeold)
{
    if (!t || i >= ntxts)
        return ESCH_ERR_INVALIDPARMS;

    if (freeold && txt[i])
        delete txt[i];

    txt[i] = t;

    return ESCH_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// EschBuildMesh - compute_extents                                          �
//���������������������������������������������������������������������������
esch_error_codes EschBuildMesh::compute_extents(int optimal, int sph_only)
{
    if (!v || !f || !nverts || !nfaces)
        return ESCH_ERR_MISSINGDATA;

//��� Compute spherical extent
    if (optimal)
    {
        // Loop through all looking for maximal distance
        
        EschPoint dia1(0,0,0);
        EschPoint dia2(0,0,0);

        Flx16 maxd = -Flx16(0x7ffffff,0);
        for(ulong i=0; i < nverts; i++)
        {
            EschVertex *vtx = &v[i];

            for(ulong j=i+1; j < nverts; j++)
            {
                EschVertex *vtx2 = &v[j];

                Flx16 dist = EschVector( vtx->x - vtx2->x,
                                         vtx->y - vtx2->y,
                                         vtx->z - vtx2->z ).magnitude();
                if (dist > maxd)
                {
                    maxd = dist;

                    dia1.x = vtx->x;
                    dia1.y = vtx->y;
                    dia1.z = vtx->z;

                    dia2.x = vtx2->x;
                    dia2.y = vtx2->y;
                    dia2.z = vtx2->z;
                }
            }
        }

        EschPoint center( Flx16((dia1.x + dia2.x).flx >> 1,0),
                          Flx16((dia1.y + dia2.y).flx >> 1,0),
                          Flx16((dia1.z + dia2.z).flx >> 1,0) );

        sphere.center = center;
        sphere.radius = Flx16(maxd.flx >> 1,0);
    }
    else
    {
        EschPoint   xmin(Flx16(0x7ffffff,0),
                         Flx16(0x7ffffff,0),
                         Flx16(0x7ffffff,0));
        EschPoint   ymin(xmin);
        EschPoint   zmin(xmin);

        EschPoint   xmax(-Flx16(0x7ffffff,0),
                         -Flx16(0x7ffffff,0),
                         -Flx16(0x7ffffff,0));
        EschPoint   ymax(xmax);
        EschPoint   zmax(xmax);
    
        // Pass 1 (find minimums/maximums in each axis
        for(ulong i=0; i < nverts; i++)
        {
            EschVertex *vtx = &v[i];

            if (vtx->x < xmin.x)
            {
                xmin.x = vtx->x;
                xmin.y = vtx->y;
                xmin.z = vtx->z;
            }
            if (vtx->x > xmax.x)
            {
                xmax.x = vtx->x;
                xmax.y = vtx->y;
                xmax.z = vtx->z;
            }

            if (vtx->y < ymin.y)
            {
                ymin.x = vtx->x;
                ymin.y = vtx->y;
                ymin.z = vtx->z;
            }
            if (vtx->y > ymax.y)
            {
                ymax.x = vtx->x;
                ymax.y = vtx->y;
                ymax.z = vtx->z;
            }
        
            if (vtx->z < zmin.z)
            {
                zmin.x = vtx->x;
                zmin.y = vtx->y;
                zmin.z = vtx->z;
            }
            if (vtx->z > zmax.z)
            {
                zmax.x = vtx->x;
                zmax.y = vtx->y;
                zmax.z = vtx->z;
            }
        }

        // Compute spans
        Flx16 xspan = (xmax.x - xmin.x)*(xmax.x - xmin.x)
                      + (xmax.y - xmin.y)*(xmax.y - xmin.y)
                      + (xmax.z - xmin.z)*(xmax.z - xmin.z);
        Flx16 yspan = (ymax.x - ymin.x)*(ymax.x - ymin.x)
                      + (ymax.y - ymin.y)*(ymax.y - ymin.y)
                      + (ymax.z - ymin.z)*(ymax.z - ymin.z);
        Flx16 zspan = (zmax.x - zmin.x)*(zmax.x - zmin.x)
                      + (zmax.y - zmin.y)*(zmax.y - zmin.y)
                      + (zmax.z - zmin.z)*(zmax.z - zmin.z);

        // Set dia1 & dia2 to maximally seperate pair
        EschPoint dia1(xmin);
        EschPoint dia2(xmax);

        Flx16 maxspan = xspan;
        if (yspan > maxspan)
        {
            maxspan = yspan;
            dia1 = ymin; dia2 = ymax;
        }
        if (zspan > maxspan)
        {
            dia1 = zmin; dia2 = zmax;
        }

        // Compute values from initial diameter guess
        EschPoint center( Flx16((dia1.x + dia2.x).flx >> 1,0),
                          Flx16((dia1.y + dia2.y).flx >> 1,0),
                          Flx16((dia1.z + dia2.z).flx >> 1,0) );

        Flx16 radius = EschVector( (dia2.x - center.x),
                                   (dia2.y - center.y),
                                   (dia2.z - center.z) ).magnitude();

        //��� Pass 2 (ensure all points fit within sphere)
        for(i=0; i < nverts; i++)
        {
            EschVertex *vtx = &v[i];

            Flx16 old_to_p = EschVector( vtx->x - center.x,
                                         vtx->y - center.y,
                                         vtx->z - center.z ).magnitude();
            
            if (old_to_p > radius)
            {
                // Calc new radius
                radius = Flx16((radius + old_to_p).flx >> 1,0);

                Flx16 old_to_new = old_to_p - radius;

                // Calc new center
                center.x = (radius*center.x + old_to_new*vtx->x) / old_to_p;
                center.y = (radius*center.y + old_to_new*vtx->y) / old_to_p;
                center.z = (radius*center.z + old_to_new*vtx->z) / old_to_p;
            }
        }

        sphere.radius = radius;
        sphere.center = center;
    }

//��� Compute box extent
    if (!sph_only)
    {
        box.mins[0] =
        box.mins[1] =
        box.mins[2] = Flx16(0x7ffffff,0);

        box.maxs[0] =
        box.maxs[1] =
        box.maxs[2] = -Flx16(0x7ffffff,0);

        for(ulong i=0; i < nverts; i++)
        {
            Flx16 x = v[i].x;
            if (x < box.mins[0])
                box.mins[0] = x;
            if (x > box.maxs[0])
                box.maxs[0] = x;

            Flx16 y = v[i].y;
            if (y < box.mins[1])
                box.mins[1] = y;
            if (y > box.maxs[1])
                box.maxs[1] = y;

            Flx16 z = v[i].z;
            if (z < box.mins[2])
                box.mins[2] = z;
            if (z > box.maxs[2])
                box.maxs[2] = z;
        }
    }

    return ESCH_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// EschBuildMesh - compute_normals                                          �
//                                                                          �
// Computes the face normals (unless vtx_only is set) and then computes     �
// the vertex normals based on the face normals assuming faces are given    �
// in clockwise order.                                                      �
//���������������������������������������������������������������������������
esch_error_codes EschBuildMesh::compute_normals(int vtx_only)
{
    if (!v || !f || !nverts || !nfaces)
        return ESCH_ERR_MISSINGDATA;

//��� Compute face normals
    if (!vtx_only)
    {
        for(ulong i=0; i < nfaces; i++)
        {
            EschFace *face = &f[i];

            EschVector v1(v[face->a].x - v[face->b].x,
                          v[face->a].y - v[face->b].y,
                          v[face->a].z - v[face->b].z);

            EschVector v2(v[face->c].x - v[face->b].x,
                          v[face->c].y - v[face->b].y,
                          v[face->c].z - v[face->b].z);
            
            EschVector v = v2 CROSS v1;
            v.normalize();

            face->normal = v;
        }
    }

//��� Compute vertex normals
    {
        ulong count=0;

        for(ulong i=0; i < nverts; i++)
        {
            EschVector  normal(0,0,0);

            for(ulong j=0; j < nfaces; j++)
            {
                EschFace *face = &f[j];
                if (face->a == i
                    || face->b == i
                    || face->c == i)
                {
                    normal.i += face->normal.i;
                    normal.j += face->normal.j;
                    normal.k += face->normal.k;

                    if (++count > 1024)
                    {
                        count=0;
                        normal.normalize();
                    }
                }
            }

            if (count)
                normal.normalize();

            v[i].normal = normal;
        }
    }

    return ESCH_ERR_NONE;
}

//��� End of module - esbldmsh.cpp ���
