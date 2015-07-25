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
//ùùùùùùùùùùùùùùùùù Microsoft Windows 95/98/NT Version ùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùCopyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbournùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                        http://www.mythos-engine.org/
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                             *** Escher Tool ***
//
// Chuck Walbourn
//
// eshtdoc.cpp
//
// Escher Tool Document class.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "stdafx.h"
#include "eshtool.h"
#include "eshtdoc.h"

#include "esfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

struct hier_type
{
    char            pname[ESCH_MAX_NAME];
    EschMeshDraw    *m;
};

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

class CXFile: public XFileDOS
{

public:
                CXFile (CFile *cf)
                {
                        fHandle = (void *)cf->m_hFile;
                        sFlags = XF_OPEN_READ | XF_OPEN_WRITE | XF_STATUS_OPEN;
                }

                ~CXFile ()
                {
                        fHandle = INVALID_HANDLE_VALUE;
                }

                // DON'T CALL THESE!  They are here to prevent the unwary caller from
                // hosing the file handes (owned by MFC, in this case).
        xf_error_codes close ()
                {
                        return XF_ERR_NONE;
                }

                xf_error_codes open (const char *fname, int mode)
                {
                        return XF_ERR_NONE;
                }
};

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

extern ulong BitDepth;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolDoc                                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

IMPLEMENT_DYNCREATE(ToolDoc, CDocument)

BEGIN_MESSAGE_MAP(ToolDoc, CDocument)
        //{{AFX_MSG_MAP(ToolDoc)
        //}}AFX_MSG_MAP
        ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
        ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
END_MESSAGE_MAP()

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°° Constructor/Destructor °°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolDoc - Constructor                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ToolDoc::ToolDoc() :
    ncameras(0),
    cameras(0),
    nlights(0),
    lights(0),
    nmeshes(0),
    meshes(0),
    hpal(0),
    flags(COMPRESS | FLOATING | TRUECOLOR)
{
    int     i;
    char    *c;

    GetModuleFileName(NULL, pfname, 256);

    for (i=strlen(pfname), c = &pfname[i-1]; i > 0; i--, c--)
    {
        if (*c == '\\')
        {
            strcpy(c+1,"DEFAULT.VGP");

            if (xf_exist(pfname))
                break;

            strcpy(c+1,"DEFAULT.PAL");

            if (xf_exist(pfname))
                break;
        }
    }

    switch (BitDepth)
    {
        case 15:
            palette = new VngoPal15;
            break;
        default:
            palette = new VngoPal8;
            break;
    }

    ASSERT(palette);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolDoc - Destructor                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ToolDoc::~ToolDoc()
{
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Diagnostics °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#ifdef _DEBUG
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolDoc - AssertValid                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolDoc::AssertValid() const
{
        CDocument::AssertValid();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolDoc - Dump                                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolDoc::Dump(CDumpContext& dc) const
{
        CDocument::Dump(dc);
}
#endif //_DEBUG



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Operations °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolDoc - DeleteContents                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolDoc::DeleteContents()
{
    memset(name,0,sizeof(name));
    memset(desc,0,sizeof(desc));
    memset(auth,0,sizeof(auth));
    memset(copy,0,sizeof(copy));

    for (EschLight *lptr=lights; lptr;)
    {
        EschLight   *t=lptr;
        lptr = lptr->next();
        delete t;
    }

    for (EschCameraEx *cptr=cameras; cptr;)
    {
        EschCameraEx  *t=cptr;
        cptr = (EschCameraEx*)cptr->next();
        delete t;
    }

    for (EschMeshDraw *mptr=meshes; mptr;)
    {
        EschMeshDraw    *t=mptr;
        mptr = (EschMeshDraw*) mptr->next();

        for(ulong i=0; i < t->tmax; i++)
        {
            EschTexture *txptr=t->txt[i];
            if (txptr && txptr->app_data)
            {
                switch (txptr->get_type() & ESCH_TXTT_BASEMASK)
                {
                    case ESCH_TXTT_STATIC:
                        delete (XFBitmap*)(txptr->app_data);
                        break;
                    case ESCH_TXTT_MFRAME:
                        delete [] (XFBitmap*)(txptr->app_data);
                        break;
                }
                txptr->app_data=0;
            }
        }
        t->remove(1);
        delete t;
    }

    cameras=0;
    lights=0;
    meshes=0;
    ncameras=nlights=nmeshes=0;

    if (hpal)
    {
        DeleteObject(hpal);
        hpal=0;
    }

    CDocument::DeleteContents();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                             ±±± Protected ±±±                            ³
// ToolDoc - count_mesh                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int ToolDoc::count_mesh(EschMeshDraw *msh)
{
    int i=0;

    for(; msh; msh = (EschMeshDraw*)msh->next(), i++)
    {
        if (msh->child())
            i += count_mesh((EschMeshDraw*)msh->child());
    }

    return i;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolDoc - GetCounts                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolDoc::GetCounts(ulong *ncams,
                        ulong *nvlgts,
                        ushort *nfplgts, ushort *nfalgts, ushort *nfslgts,
                        ulong *nplgts, ushort *nalgts, ushort *nslgts,
                        ulong *nobjs)
{
    if (ncams)
    {
        *ncams=0;
        for(EschCameraEx *cam=cameras; cam; cam = (EschCameraEx*)cam->next())
            (*ncams)++;
    }

    if (nvlgts)  *nvlgts=0;
    if (nfplgts) *nfplgts=0;
    if (nfalgts) *nfalgts=0;
    if (nfslgts) *nfslgts=0;
    if (nplgts)  *nplgts=0;
    if (nalgts)  *nalgts=0;
    if (nslgts)  *nslgts=0;
    for(EschLight *lgt=lights; lgt; lgt = lgt->next())
    {
        if (lgt->get_type() == ESCH_LGTT_VECTOR && nvlgts)
            (*nvlgts)++;
        else if (lgt->get_type() == ESCH_LGTT_FPOINT && nfplgts)
            (*nfplgts)++;
        else if (lgt->get_type() == ESCH_LGTT_FATTEN && nfalgts)
            (*nfalgts)++;
        else if (lgt->get_type() == ESCH_LGTT_FSPOT && nfslgts)
            (*nfslgts)++;
        else if (lgt->get_type() == ESCH_LGTT_POINT && nplgts)
            (*nplgts)++;
        else if (lgt->get_type() == ESCH_LGTT_ATTEN && nalgts)
            (*nalgts)++;
        else if (lgt->get_type() == ESCH_LGTT_SPOT && nslgts)
            (*nslgts)++;
        // ambients are not counted... supposedly only one.
    }

    if (nobjs)
    {
        *nobjs = count_mesh(meshes);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                             ±±± Protected ±±±                            ³
// ToolDoc - serialize_store_mesh                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes ToolDoc::serialize_store_mesh(XFParseIFF *iff, EschMeshDraw *msh)
{
    int                 i;
    EschFileMeshHDR     header;

    for(; msh; msh = (EschMeshDraw*)msh->next())
    {
        if (!msh->mesh)
            continue;

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Create a EMSH form
        if (iff->newform(iff->makeid('E','M','S','H')))
        {
            return ESCH_ERR_FILEERROR;
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Header
        memset(&header,0,sizeof(header));

        strncpy(header.name,msh->mesh->name,ESCH_MAX_NAME);
        header.nverts=msh->mesh->nverts;
        header.nfaces=msh->mesh->nfaces;
        header.flags = msh->mesh->flags & ~ESCH_MSH_OWNSDATA;
        header.nmtls = (msh->mesh->txt) ? msh->mesh->tmax : 0;

        if (iff->write(iff->makeid('H','D','R',' '),
                       &header,sizeof(EschFileSceneHDR)))
        {
            iff->leaveform();
            return ESCH_ERR_FILEERROR;
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Matrix
        if (flags & FLOATING)
        {
            if (iff->write(iff->makeid('M','T','R','1'),
                           &msh->local.orient.mtx,sizeof(EschMatrix)))
            {
                iff->leaveform();
                return ESCH_ERR_FILEERROR;
            }
        }
        else
        {
            EschMatrixV1 mtx;

            for(int i=0; i < ESCH_MTX_NUM; i++)
                mtx.mtx[i] = long(msh->local.orient.mtx[i] * 65536.0f);

            if (iff->write(iff->makeid('M','T','R','X'),
                           &mtx,sizeof(mtx)))
            {
                iff->leaveform();
                return ESCH_ERR_FILEERROR;
            }
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Hierarchy
        if (msh->parent())
        {
            EschFileMeshHIER hier;
            memset(&hier,0,sizeof(hier));
            strncpy(hier.parent,msh->parent()->name,ESCH_MAX_NAME);

            if (iff->write(iff->makeid('H','I','E','R'),
                           &hier,sizeof(EschFileMeshHIER)))
            {
                iff->leaveform();
                return ESCH_ERR_FILEERROR;
            }
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Extent
        if (flags & FLOATING)
        {
            EschFileMeshEXNT    extent;
            memset(&extent,0,sizeof(extent));

            extent.cenx          = msh->mesh->sphere.center.x;
            extent.ceny          = msh->mesh->sphere.center.y;
            extent.cenz          = msh->mesh->sphere.center.z;
            extent.extent_radius = msh->mesh->sphere.radius;
            extent.minx          = msh->mesh->box.mins[0];
            extent.miny          = msh->mesh->box.mins[1];
            extent.minz          = msh->mesh->box.mins[2];
            extent.maxx          = msh->mesh->box.maxs[0];
            extent.maxy          = msh->mesh->box.maxs[1];
            extent.maxz          = msh->mesh->box.maxs[2];

            if (iff->write(iff->makeid('E','X','N','1'),
                           &extent,sizeof(extent)))
            {
                iff->leaveform();
                return ESCH_ERR_FILEERROR;
            }
        }
        else
        {
            EschFileMeshEXNTV1    extent;
            memset(&extent,0,sizeof(extent));

            extent.cenx          = long(msh->mesh->sphere.center.x * 65536.0f);
            extent.ceny          = long(msh->mesh->sphere.center.y * 65536.0f);
            extent.cenz          = long(msh->mesh->sphere.center.z * 65536.0f);
            extent.extent_radius = long(msh->mesh->sphere.radius * 65536.0f);
            extent.minx          = long(msh->mesh->box.mins[0] * 65536.0f);
            extent.miny          = long(msh->mesh->box.mins[1] * 65536.0f);
            extent.minz          = long(msh->mesh->box.mins[2] * 65536.0f);
            extent.maxx          = long(msh->mesh->box.maxs[0] * 65536.0f);
            extent.maxy          = long(msh->mesh->box.maxs[1] * 65536.0f);
            extent.maxz          = long(msh->mesh->box.maxs[2] * 65536.0f);

            if (iff->write(iff->makeid('E','X','N','T'),
                           &extent,sizeof(extent)))
            {
                iff->leaveform();
                return ESCH_ERR_FILEERROR;
            }
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Material
        if (header.nmtls)
        {
            EschFileMeshMTL     *emtl;

            emtl = new EschFileMeshMTL[header.nmtls];
            if (!emtl)
            {
                iff->leaveform();
                return ESCH_ERR_NOMEMORY;
            }

            for(i=0; i < (int)header.nmtls; i++)
                strncpy(emtl[i].name,msh->mesh->txt[i]->name,ESCH_MAX_NAME);

            if (iff->write(iff->makeid('M','T','L',' '),
                           emtl,sizeof(EschFileMeshMTL)*header.nmtls))
            {
                iff->leaveform();
                delete [] emtl;
                return ESCH_ERR_FILEERROR;
            }

            delete [] emtl;
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Verticies
        EschVertex *vptr = (EschVertex*)ivory_hlock(msh->mesh->v);
        if (!vptr)
        {
            iff->leaveform();
            return ESCH_ERR_LOCKFAILED;
        }

        if (flags & FLOATING)
        {
            if (iff->write(iff->makeid('V','E','R','1'),
                           vptr,msh->mesh->nverts * sizeof(EschVertex)))
            {
                iff->leaveform();
                ivory_hunlock(msh->mesh->v);
                return ESCH_ERR_FILEERROR;
            }
        }
        else
        {
            EschVertexV1 *vtemp = new EschVertexV1[msh->mesh->nverts];
            if (!vtemp)
            {
                iff->leaveform();
                ivory_hunlock(msh->mesh->v);
                return ESCH_ERR_NOMEMORY;
            }

            EschVertex *tptr = vptr;
            EschVertexV1 *tmpptr = vtemp;
            for(ulong i=0; i < msh->mesh->nverts; i++, tptr++, tmpptr++)
            {
                tmpptr->x = long(tptr->x * 65536.0f);
                tmpptr->y = long(tptr->y * 65536.0f);
                tmpptr->z = long(tptr->z * 65536.0f);
                tmpptr->normal.i = long(tptr->normal.i * 65536.0f);
                tmpptr->normal.j = long(tptr->normal.j * 65536.0f);
                tmpptr->normal.k = long(tptr->normal.k * 65536.0f);
            }

            if (iff->write(iff->makeid('V','E','R','T'),
                           vtemp,msh->mesh->nverts * sizeof(EschVertexV1)))
            {
                iff->leaveform();
                delete [] vtemp;
                ivory_hunlock(msh->mesh->v);
                return ESCH_ERR_FILEERROR;
            }

            delete [] vtemp;
        }

        ivory_hunlock(msh->mesh->v);

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Faces
        EschFace *fptr = (EschFace*)ivory_hlock(msh->mesh->f);
        if (!fptr)
        {
            iff->leaveform();
            return ESCH_ERR_LOCKFAILED;
        }

        // Convert face color to RGB
        for(i=0; i < (int)msh->mesh->nfaces; i++)
        {
            VngoColor24bit clr = palette->hw_pal.p[(byte)fptr[i].color];
            fptr[i].color = (clr.r | (clr.g << 8) | (clr.b << 16));
        }

        if (flags & FLOATING)
        {
            if (iff->write(iff->makeid('F','A','C','2'),
                           fptr,msh->mesh->nfaces * sizeof(EschFace)))
            {
                iff->leaveform();
                // Convert face color back to index
                for(i=0; i < (int)msh->mesh->nfaces; i++)
                    fptr[i].color = (byte)palette->get_index((VngoColor24bit)fptr[i].color);
                ivory_hunlock(msh->mesh->f);
                return ESCH_ERR_FILEERROR;
            }
        }
        else
        {
            EschFaceV1 *ftemp = new EschFaceV1[msh->mesh->nfaces];
            if (!ftemp)
            {
                iff->leaveform();
                // Convert face color back to index
                for(i=0; i < (int)msh->mesh->nfaces; i++)
                    fptr[i].color = (byte)palette->get_index((VngoColor24bit)fptr[i].color);
                ivory_hunlock(msh->mesh->f);
                return ESCH_ERR_NOMEMORY;
            }

            EschFace *tptr = fptr;
            EschFaceV1 *tmpptr = ftemp;
            for(ulong i=0; i < msh->mesh->nfaces; i++, tptr++, tmpptr++)
            {
                dword flags = tptr->flags;
                if (tptr->self_illum)
                    flags |= (tptr->self_illum << 16) & ESCH_FACEV1_SILLUM_MASK;
                if (flags & ESCH_FACE_ALPHA)
                    flags |= (tptr->alpha_a << 20) & ESCH_FACEV1_ALPHA_MASK;
                tmpptr->flags = flags;

                tmpptr->a = tptr->a;
                tmpptr->b = tptr->b;
                tmpptr->c = tptr->c;
                tmpptr->txt = tptr->txt;
                tmpptr->u[0] = long(tptr->u[0] * 65536.0f);
                tmpptr->u[1] = long(tptr->u[1] * 65536.0f);
                tmpptr->u[2] = long(tptr->u[2] * 65536.0f);
                tmpptr->v[0] = long(tptr->v[0] * 65536.0f);
                tmpptr->v[1] = long(tptr->v[1] * 65536.0f);
                tmpptr->v[2] = long(tptr->v[2] * 65536.0f);
                tmpptr->color = tptr->color;
                tmpptr->normal.i = long(tptr->normal.i * 65536.0f);
                tmpptr->normal.j = long(tptr->normal.j * 65536.0f);
                tmpptr->normal.k = long(tptr->normal.k * 65536.0f);
            }

            if (iff->write(iff->makeid('F','A','C','E'),
                           ftemp,msh->mesh->nfaces * sizeof(EschFaceV1)))
            {
                iff->leaveform();
                // Convert face color back to index
                for(i=0; i < (int)msh->mesh->nfaces; i++)
                    fptr[i].color = (byte)palette->get_index((VngoColor24bit)fptr[i].color);
                delete [] ftemp;
                ivory_hunlock(msh->mesh->f);
                return ESCH_ERR_FILEERROR;
            }

            delete [] ftemp;
        }

        // Convert face color back to index
        for(i=0; i < (int)msh->mesh->nfaces; i++)
            fptr[i].color = (byte)palette->get_index((VngoColor24bit)fptr[i].color);
        ivory_hunlock(msh->mesh->f);

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Texture Data
        if (header.nmtls)
        {
            for(i=0; i < (int)header.nmtls; i++)
            {
                EschFileMtlMHDR mheader;

                EschTexture *t=msh->mesh->txt[i];

                // Make sure it is frame 0.
                if (t->get_type() == ESCH_TXTT_MFRAME)
                    ((EschMultiFrameTexture*)t)->reset();

                // Must lock texture to output data
                t->lock();
                if (!t->ptr)
                {
                    iff->leaveform();
                    return ESCH_ERR_LOCKFAILED;
                }

                ASSERT(t->ptr->tex);

                // Determine if transparent
                BOOL transp = (t->flags & ESCH_TXT_TRANSP) ? TRUE : FALSE;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Create EMTL form
                if (iff->newform((t->get_type() == ESCH_TXTT_MFRAME)
                                 ? iff->makeid('E','M','T','1')
                                 : iff->makeid('E','M','T','L')))
                {
                    iff->leaveform();
                    t->unlock();
                    return ESCH_ERR_FILEERROR;
                }

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Header
                memset(&mheader,0,sizeof(mheader));

                strncpy(mheader.name,t->name,ESCH_MAX_NAME);

                strncpy(mheader.pname,"Default",16);

                mheader.nframes = (t->get_type() == ESCH_TXTT_MFRAME)
                                  ? ((EschMultiFrameTexture*)t)->max
                                  : 1;

                if (flags & TRUECOLOR)
                {
                    if (transp)
                    {
                        mheader.type = (flags & USE15BIT)
                                       ? ESCH_MTL_TYPE_15BIT_TRANSP
                                       : ESCH_MTL_TYPE_32BIT;
                    }
                    else
                    {
                        mheader.type = (flags & USE15BIT)
                                       ? ESCH_MTL_TYPE_15BIT
                                       : ESCH_MTL_TYPE_24BIT;
                    }
                }
                else
                {
                    mheader.type = (transp)
                                   ? ESCH_MTL_TYPE_8BIT_TRANSP
                                   : ESCH_MTL_TYPE_8BIT;
                }
                mheader.compress = (flags & COMPRESS)
                                   ? ESCH_MTL_COMPRESS_RLE
                                   : ESCH_MTL_COMPRESS_NONE;

                mheader.flags = t->flags & ~(ESCH_TXT_LOCKED
                                             | ESCH_TXT_OWNSDATA
                                             | ESCH_TXT_SHARED);

                mheader.xsize = t->ptr->width;
                mheader.ysize = t->ptr->height;

                ASSERT((mheader.xsize * mheader.ysize) > 0);

                if (iff->write(iff->makeid('M','H','D','R'),
                               &mheader,sizeof(mheader)))
                {
                    iff->leaveform();
                    t->unlock();
                    return ESCH_ERR_FILEERROR;
                }

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Body
                int bpp;
                switch (mheader.type)
                {
                    case ESCH_MTL_TYPE_8BIT:            bpp=1;  break;
                    case ESCH_MTL_TYPE_8BIT_TRANSP:     bpp=1;  break;
                    case ESCH_MTL_TYPE_15BIT:           bpp=2;  break;
                    case ESCH_MTL_TYPE_15BIT_TRANSP:    bpp=2;  break;
                    case ESCH_MTL_TYPE_24BIT:           bpp=3;  break;
                    case ESCH_MTL_TYPE_32BIT:           bpp=4;  break;
                    default:
                        ASSERT(FALSE);
                        iff->leaveform();
                        t->unlock();
                        return ESCH_ERR_NOTSUPPORTED;
                }

                byte *tptr = (byte*)t->ptr->tex;
                for(int j=0; j < (int)mheader.nframes; j++)
                {
                    byte *body=tptr;

                    if (bpp != 1)
                    {
                        body=new byte[mheader.xsize*mheader.ysize*bpp];
                        if (!body)
                        {
                            iff->leaveform();
                            t->unlock();
                            return ESCH_ERR_NOMEMORY;
                        }

                        if (t->app_data)
                        {
                            //ÄÄÄÄ Loaded XFBitmap instance, use that to
                            //ÄÄÄÄ get texture data instead of VngoTexture
                            XFBitmap *bm = (t->get_type() == ESCH_TXTT_MFRAME)
                                           ? &((XFBitmap*)t->app_data)[j]
                                           : (XFBitmap*)t->app_data;

                            bm->lock();

                            ASSERT(bm != 0);

                            switch (bm->bpp)
                            {
                                case XFBM_BPP_15BIT:
                                    switch (bpp)
                                    {
                                        case 2:
                                            {
                                                byte *sptr=bm->data;
                                                byte *dptr=body;
                                                for(int k=0;
                                                    k < (int)(mheader.xsize*mheader.ysize);
                                                    k++)
                                                {
                                                    word pcolor = *sptr | (*(sptr+1) << 8);

                                                    if (transp && (pcolor & 0x8000))
                                                    {
                                                        *(dptr++) = *(sptr++);
                                                        *(dptr++) = *(sptr++);
                                                    }
                                                    else
                                                    {
                                                        pcolor &= ~0x8000;
                                                        VngoColor24bit clr((pcolor >> 7) & 0xf8,
                                                                           (pcolor >> 2) & 0xf8,
                                                                           (pcolor << 3) & 0xf8);

                                                        if (transp
                                                            && (clr.r == 248)
                                                            && (clr.b == 248)
                                                            && (clr.g == 0))
                                                        {
                                                            pcolor = ((255 >> 3) << 10)
                                                                      + ((255) >> 3);

                                                            pcolor |= 0x8000;

                                                            *(dptr++) = byte(pcolor & 0xff);
                                                            *(dptr++) = byte((pcolor & 0xff00) >> 8);
                                                        }
                                                        else
                                                        {
                                                            *(dptr++) = *(sptr++);
                                                            *(dptr++) = *(sptr++);
                                                        }
                                                    }
                                                }
                                            }
                                            break;
                                        case 3:
                                        case 4:
                                            {
                                                byte *sptr=bm->data;
                                                byte *dptr=body;
                                                for(int k=0;
                                                    k < (int)(mheader.xsize*mheader.ysize);
                                                    k++)
                                                {
                                                    word pcolor = *sptr | (*(sptr+1) << 8);

                                                    sptr += 2;

                                                    if ((bpp == 4)
                                                        && (pcolor & 0x8000))
                                                    {
                                                        *(dptr++) = 255;
                                                        *(dptr++) = 0;
                                                        *(dptr++) = 255;
                                                        *(dptr++) = 0;
                                                    }
                                                    else
                                                    {
                                                        pcolor &= ~0x8000;

                                                        VngoColor24bit clr((pcolor >> 7) & 0xf8,
                                                                           (pcolor >> 2) & 0xf8,
                                                                           (pcolor << 3) & 0xf8);

                                                        *(dptr++) = clr.r;
                                                        *(dptr++) = clr.g;
                                                        *(dptr++) = clr.b;

                                                        if (bpp == 4)
                                                        {
                                                            if (transp
                                                                && (clr.r == 248)
                                                                && (clr.b == 248)
                                                                && (clr.g == 0))
                                                            {
                                                                *(dptr++) = 0;
                                                            }
                                                            else
                                                            {
                                                                *(dptr++) = 255;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            break;
                                    }
                                    break;
                                case XFBM_BPP_24BIT:
                                    switch (bpp)
                                    {
                                        case 2:
                                            {
                                                byte *sptr=bm->data;
                                                byte *dptr=body;
                                                for(int k=0;
                                                    k < (int)(mheader.xsize*mheader.ysize);
                                                    k++)
                                                {
                                                    word pcolor = (((*sptr) >> 3) << 10)
                                                                    + (((*(sptr+1)) >> 3) << 5)
                                                                    + ((*(sptr+2)) >> 3);

                                                    if (transp
                                                        && (*sptr == 255)
                                                        && (*(sptr+2) == 255)
                                                        && (*(sptr+1) == 0))
                                                    {
                                                        pcolor |= 0x8000;
                                                    }

                                                    *(dptr++) = byte(pcolor & 0xff);
                                                    *(dptr++) = byte((pcolor & 0xff00) >> 8);

                                                    sptr += 3;
                                                }
                                            }
                                            break;
                                        case 3:
                                            memcpy(body,bm->data,
                                                   mheader.xsize*mheader.ysize*3);
                                            break;
                                        case 4:
                                            {
                                                byte *sptr=bm->data;
                                                byte *dptr=body;
                                                for(int k=0;
                                                    k < (int)(mheader.xsize*mheader.ysize);
                                                    k++)
                                                {
                                                    *(dptr++) = *sptr;
                                                    *(dptr++) = *(sptr+1);
                                                    *(dptr++) = *(sptr+2);

                                                    if (transp
                                                        && (*sptr == 255)
                                                        && (*(sptr+2) == 255)
                                                        && (*(sptr+1) == 255))
                                                    {
                                                        *(dptr++) = 0;
                                                    }
                                                    else
                                                    {
                                                        *(dptr++) = 255;
                                                    }

                                                    sptr += 3;
                                                }
                                            }
                                            break;
                                    }
                                    break;
                                case XFBM_BPP_32BIT:
                                    switch (bpp)
                                    {
                                        case 2:
                                            {
                                                byte *sptr=bm->data;
                                                byte *dptr=body;
                                                for(int k=0;
                                                    k < (int)(mheader.xsize*mheader.ysize);
                                                    k++)
                                                {
                                                    word pcolor = (((*sptr) >> 3) << 10)
                                                                    + (((*(sptr+1)) >> 3) << 5)
                                                                    + ((*(sptr+2)) >> 3);

                                                    if (*(sptr+3) < ESCH_ALPHA_TRANSP)
                                                    {
                                                        pcolor |= 0x8000;
                                                    }

                                                    *(dptr++) = byte(pcolor & 0xff);
                                                    *(dptr++) = byte((pcolor & 0xff00) >> 8);

                                                    sptr += 4;
                                                }
                                            }
                                            break;
                                        case 3:
                                            {
                                                byte *sptr=bm->data;
                                                byte *dptr=body;
                                                for(int k=0;
                                                    k < (int)(mheader.xsize*mheader.ysize);
                                                    k++)
                                                {
                                                    *(dptr++) = *(sptr++);
                                                    *(dptr++) = *(sptr++);
                                                    *(dptr++) = *(sptr++);
                                                    sptr++;
                                                }
                                            }
                                            break;
                                        case 4:
                                            memcpy(body,bm->data,
                                                   mheader.xsize*mheader.ysize*4);
                                            break;
                                    }
                                    break;
                            }

                            bm->unlock();
                        }
                        else
                        {
                            //ÄÄÄÄ Don't have XFBitmap, use VngoTexture...
                            byte *sptr=tptr;
                            byte *dptr=body;
                            for(int k=0; k < (int)(mheader.xsize*mheader.ysize); k++)
                            {
                                VngoColor24bit clr = palette->hw_pal.p[*sptr];

                                switch (bpp)
                                {
                                    case 2:
                                        {
                                            word pcolor = ((clr.r >> 3) << 10)
                                                           + ((clr.g >> 3) << 5)
                                                           + (clr.b >> 3);

                                            if (transp
                                                && (*sptr == VNGO_TRANSPARENT_COLOR))
                                            {
                                                pcolor |= 0x8000;
                                            }

                                            *(dptr++) = byte(pcolor & 0xff);
                                            *(dptr++) = byte((pcolor & 0xff00) >> 8);
                                        }
                                        break;
                                    case 3:
                                        *(dptr++) = clr.r;
                                        *(dptr++) = clr.g;
                                        *(dptr++) = clr.b;
                                        break;
                                    case 4:
                                        if (*sptr == VNGO_TRANSPARENT_COLOR)
                                        {
                                            *(dptr++) = 255;
                                            *(dptr++) = 0;
                                            *(dptr++) = 255;
                                            *(dptr++) = 0;
                                        }
                                        else
                                        {
                                            *(dptr++) = clr.r;
                                            *(dptr++) = clr.g;
                                            *(dptr++) = clr.b;
                                            *(dptr++) = 255;
                                        }
                                        break;
                                    default:
                                        ASSERT(FALSE);
                                        iff->leaveform();
                                        t->unlock();
                                        return ESCH_ERR_NOTSUPPORTED;
                                }

                                sptr++;
                            }
                        }
                    }

                    byte *work = new byte[mheader.xsize*mheader.ysize*bpp];
                    if (!work)
                    {
                        if (bpp != 1)
                            delete [] body;
                        iff->leaveform();
                        t->unlock();
                        return ESCH_ERR_NOMEMORY;
                    }

                    dword size=0;
                    if (mheader.compress == ESCH_MTL_COMPRESS_RLE)
                    {
                        switch (bpp)
                        {
                            case 1:
                                size=XFParseXEB::compress_rle_8bpp(mheader.xsize,
                                                                   mheader.ysize,
                                                                   body,work);
                                break;
                            case 2:
                                size=XFParseXEB::compress_rle_16bpp(mheader.xsize,
                                                                    mheader.ysize,
                                                                    body,work);
                                break;
                            case 3:
                                size=XFParseXEB::compress_rle_24bpp(mheader.xsize,
                                                                    mheader.ysize,
                                                                    body,work);
                                break;
                            case 4:
                                size=XFParseXEB::compress_rle_32bpp(mheader.xsize,
                                                                    mheader.ysize,
                                                                    body,work);
                                break;
                            default:
                                ASSERT(FALSE);
                                iff->leaveform();
                                t->unlock();
                                return ESCH_ERR_NOTSUPPORTED;
                        }
                    }

                    if (size)
                    {
                        if (bpp != 1)
                            delete [] body;

                        if (iff->write(iff->makeid('B','O','D','Y'),work,size))
                        {
                            iff->leaveform();
                            t->unlock();
                            return ESCH_ERR_FILEERROR;
                        }
                    }
                    else
                    {
                        delete [] work;
                        if (iff->write(iff->makeid('B','O','D','Y'), body,
                                       (ulong)(mheader.xsize*mheader.ysize*bpp)))
                        {
                            if (bpp != 1)
                                delete [] body;
                            iff->leaveform();
                            t->unlock();
                            return ESCH_ERR_FILEERROR;
                        }

                        if (bpp != 1)
                            delete [] body;
                    }

                    tptr += (mheader.xsize*mheader.ysize);
                }

                iff->leaveform();

                t->unlock();
            }
        }

        iff->leaveform();

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Store Children
        if (msh->child())
        {
            esch_error_codes err=serialize_store_mesh(iff,(EschMeshDraw*)msh->child());
            if (err)
                return err;
        }
    }

    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolDoc - Serialize                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void ToolDoc::Serialize(CArchive& ar)
{
    CXFile      f(ar.GetFile());
    XFParseIFF  iff(&f);

    iff.begin();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Saving
        if (ar.IsStoring())
        {
        esch_error_codes    err;
        EschFileSceneHDR    sdata;
        EschCameraEx        *cam;
        EschLight           *lgt;

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Create a ESEN form
        if (iff.newform(iff.makeid('E','S','E','N')))
        {
            err=ESCH_ERR_FILEERROR;
            goto save_error_exit;
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Header
        memset(&sdata,0,sizeof(sdata));
        strcpy(sdata.name,name);

        GetCounts(&sdata.ncameras,
                  &sdata.nvectorlights,
                  &sdata.nfpointlights,
                  &sdata.nfattenlights,
                  &sdata.nfspotlights,
                  &sdata.npointlights,
                  &sdata.nattenlights,
                  &sdata.nspotlights,
                  &sdata.nobjects);

        if (iff.write(iff.makeid('H','D','R',' '),
                      &sdata,sizeof(sdata)))
        {
            err=ESCH_ERR_FILEERROR;
            goto save_error_exit;
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Description
        if (*desc)
        {
            if (iff.write(iff.makeid('D','E','S','C'),
                          desc,strlen(desc)))
            {
                err=ESCH_ERR_FILEERROR;
                goto save_error_exit;
            }
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Author
        if (*auth)
        {
            if (iff.write(iff.makeid('A','U','T','H'),
                          auth,strlen(auth)))
            {
                err=ESCH_ERR_FILEERROR;
                goto save_error_exit;
            }
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Copyright
        if (*copy)
        {
            if (iff.write(iff.makeid('(','C',')',' '),
                          copy,strlen(copy)))
            {
                err=ESCH_ERR_FILEERROR;
                goto save_error_exit;
            }
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Cameras
        for(cam=cameras; cam; cam = (EschCameraEx*)cam->next())
        {
            if (flags & FLOATING)
            {
                EschFileCamera  cdata;
                memset(&cdata,0,sizeof(cdata));

                strncpy(cdata.name,cam->name,ESCH_MAX_NAME);
                cdata.flags = cam->flags & ~ESCH_CAM_OWNSBITMAP;

                EschPoint  pos;
                cam->get_position(&pos);
                cdata.x = pos.x;
                cdata.y = pos.y;
                cdata.z = pos.z;

                cdata.fov = cam->fov;

                cdata.diri = cam->eye.dir.i;
                cdata.dirj = cam->eye.dir.j;
                cdata.dirk = cam->eye.dir.k;

                cdata.topi = cam->top.i;
                cdata.topj = cam->top.j;
                cdata.topk = cam->top.k;

                if (iff.write(iff.makeid('E','C','A','1'),
                              &cdata,sizeof(cdata)))
                {
                    err=ESCH_ERR_FILEERROR;
                    goto save_error_exit;
                }
            }
            else
            {
                EschFileCameraV1  cdata;
                memset(&cdata,0,sizeof(cdata));

                strncpy(cdata.name,cam->name,ESCH_MAX_NAME);
                cdata.flags = cam->flags & ~ESCH_CAM_OWNSBITMAP;

                EschPoint  pos;
                cam->get_position(&pos);
                cdata.x = long(pos.x * 65536.0f);
                cdata.y = long(pos.y * 65536.0f);
                cdata.z = long(pos.z * 65536.0f);

                cdata.fov = long(cam->fov * 65536.0f);

                cdata.diri = long(cam->eye.dir.i * 65536.0f);
                cdata.dirj = long(cam->eye.dir.j * 65536.0f);
                cdata.dirk = long(cam->eye.dir.k * 65536.0f);

                cdata.topi = long(cam->top.i * 65536.0f);
                cdata.topj = long(cam->top.j * 65536.0f);
                cdata.topk = long(cam->top.k * 65536.0f);

                if (iff.write(iff.makeid('E','C','A','M'),
                              &cdata,sizeof(cdata)))
                {
                    err=ESCH_ERR_FILEERROR;
                    goto save_error_exit;
                }
            }
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Lights
        for(lgt=lights; lgt; lgt = lgt->next())
        {
            if (lgt->get_type() == ESCH_LGTT_VECTOR)
            {
                if (flags & FLOATING)
                {
                    EschFileLightVect   vec;
                    memset(&vec,0,sizeof(vec));

                    strncpy(vec.name,lgt->name,ESCH_MAX_NAME);
                    vec.flags = lgt->flags;

                    byte i = lgt->get_intensity();
                    vec.color = i << 16 | i << 8 | i;

                    vec.i = ((EschVectorLight*)lgt)->dir.i;
                    vec.j = ((EschVectorLight*)lgt)->dir.j;
                    vec.k = ((EschVectorLight*)lgt)->dir.k;

                    if (iff.write(iff.makeid('E','V','E','1'),
                                  &vec,sizeof(vec)))
                    {
                        err=ESCH_ERR_FILEERROR;
                        goto save_error_exit;
                    }
                }
                else
                {
                    EschFileLightVectV1   vec;
                    memset(&vec,0,sizeof(vec));

                    strncpy(vec.name,lgt->name,ESCH_MAX_NAME);
                    vec.flags = lgt->flags;

                    byte i = lgt->get_intensity();
                    vec.color = i << 16 | i << 8 | i;

                    vec.i = long(((EschVectorLight*)lgt)->dir.i * 65536.0f);
                    vec.j = long(((EschVectorLight*)lgt)->dir.j * 65536.0f);
                    vec.k = long(((EschVectorLight*)lgt)->dir.k * 65536.0f);

                    if (iff.write(iff.makeid('E','V','E','C'),
                                  &vec,sizeof(vec)))
                    {
                        err=ESCH_ERR_FILEERROR;
                        goto save_error_exit;
                    }
                }
            }
            else if (lgt->get_type() == ESCH_LGTT_FPOINT
                     || lgt->get_type() == ESCH_LGTT_POINT)
            {
                if (flags & FLOATING)
                {
                    EschFileLightPoint   pnt;
                    memset(&pnt,0,sizeof(pnt));

                    strncpy(pnt.name,lgt->name,ESCH_MAX_NAME);
                    pnt.flags = lgt->flags;

                    byte i = lgt->get_intensity();
                    pnt.color = i << 16 | i << 8 | i;

                    if (lgt->get_type() == ESCH_LGTT_FPOINT)
                    {
                        pnt.x = ((EschFastPointLight*)lgt)->pos.x;
                        pnt.y = ((EschFastPointLight*)lgt)->pos.y;
                        pnt.z = ((EschFastPointLight*)lgt)->pos.z;
                    }
                    else
                    {
                        pnt.x = ((EschPointLight*)lgt)->pos.x;
                        pnt.y = ((EschPointLight*)lgt)->pos.y;
                        pnt.z = ((EschPointLight*)lgt)->pos.z;
                    }

                    if (iff.write((lgt->get_type() == ESCH_LGTT_FPOINT)
                                  ? iff.makeid('E','F','P','1')
                                  : iff.makeid('E','P','N','1'),
                                  &pnt,sizeof(pnt)))
                    {
                        err=ESCH_ERR_FILEERROR;
                        goto save_error_exit;
                    }
                }
                else
                {
                    EschFileLightPointV1   pnt;
                    memset(&pnt,0,sizeof(pnt));

                    strncpy(pnt.name,lgt->name,ESCH_MAX_NAME);
                    pnt.flags = lgt->flags;

                    byte i = lgt->get_intensity();
                    pnt.color = i << 16 | i << 8 | i;

                    if (lgt->get_type() == ESCH_LGTT_FPOINT)
                    {
                        pnt.x = long(((EschFastPointLight*)lgt)->pos.x * 65536.0f);
                        pnt.y = long(((EschFastPointLight*)lgt)->pos.y * 65536.0f);
                        pnt.z = long(((EschFastPointLight*)lgt)->pos.z * 65536.0f);
                    }
                    else
                    {
                        pnt.x = long(((EschPointLight*)lgt)->pos.x * 65536.0f);
                        pnt.y = long(((EschPointLight*)lgt)->pos.y * 65536.0f);
                        pnt.z = long(((EschPointLight*)lgt)->pos.z * 65536.0f);
                    }

                    if (iff.write((lgt->get_type() == ESCH_LGTT_FPOINT)
                                  ? iff.makeid('E','F','P','T')
                                  : iff.makeid('E','P','N','T'),
                                  &pnt,sizeof(pnt)))
                    {
                        err=ESCH_ERR_FILEERROR;
                        goto save_error_exit;
                    }
                }
            }
            else if (lgt->get_type() == ESCH_LGTT_FATTEN
                     || lgt->get_type() == ESCH_LGTT_ATTEN)
            {
                if (flags & FLOATING)
                {
                    EschFileLightAtten atn;
                    memset(&atn,0,sizeof(atn));

                    strncpy(atn.name,lgt->name,ESCH_MAX_NAME);
                    atn.flags = lgt->flags;

                    byte i = lgt->get_intensity();
                    atn.color = i << 16 | i << 8 | i;

                    if (lgt->get_type() == ESCH_LGTT_FATTEN)
                    {
                        atn.x = ((EschFastAttenLight*)lgt)->pos.x;
                        atn.y = ((EschFastAttenLight*)lgt)->pos.y;
                        atn.z = ((EschFastAttenLight*)lgt)->pos.z;
                        atn.inner = ((EschFastAttenLight*)lgt)->inner;
                        atn.outer = ((EschFastAttenLight*)lgt)->outer;
                    }
                    else
                    {
                        atn.x = ((EschAttenLight*)lgt)->pos.x;
                        atn.y = ((EschAttenLight*)lgt)->pos.y;
                        atn.z = ((EschAttenLight*)lgt)->pos.z;
                        atn.inner = ((EschAttenLight*)lgt)->inner;
                        atn.outer = ((EschAttenLight*)lgt)->outer;
                    }

                    if (iff.write((lgt->get_type() == ESCH_LGTT_FATTEN)
                                  ? iff.makeid('E','F','A','1')
                                  : iff.makeid('E','A','T','1'),
                                  &atn,sizeof(atn)))
                    {
                        err=ESCH_ERR_FILEERROR;
                        goto save_error_exit;
                    }
                }
                else
                {
                    EschFileLightAttenV1 atn;
                    memset(&atn,0,sizeof(atn));

                    strncpy(atn.name,lgt->name,ESCH_MAX_NAME);
                    atn.flags = lgt->flags;

                    byte i = lgt->get_intensity();
                    atn.color = i << 16 | i << 8 | i;

                    if (lgt->get_type() == ESCH_LGTT_FATTEN)
                    {
                        atn.x = long(((EschFastAttenLight*)lgt)->pos.x * 65536.0f);
                        atn.y = long(((EschFastAttenLight*)lgt)->pos.y * 65536.0f);
                        atn.z = long(((EschFastAttenLight*)lgt)->pos.z * 65536.0f);
                        atn.inner = long(((EschFastAttenLight*)lgt)->inner * 65536.0f);
                        atn.outer = long(((EschFastAttenLight*)lgt)->outer * 65536.0f);
                    }
                    else
                    {
                        atn.x = long(((EschAttenLight*)lgt)->pos.x * 65536.0f);
                        atn.y = long(((EschAttenLight*)lgt)->pos.y * 65536.0f);
                        atn.z = long(((EschAttenLight*)lgt)->pos.z * 65536.0f);
                        atn.inner = long(((EschAttenLight*)lgt)->inner * 65536.0f);
                        atn.outer = long(((EschAttenLight*)lgt)->outer * 65536.0f);
                    }

                    if (iff.write((lgt->get_type() == ESCH_LGTT_FATTEN)
                                  ? iff.makeid('E','F','A','T')
                                  : iff.makeid('E','A','T','N'),
                                  &atn,sizeof(atn)))
                    {
                        err=ESCH_ERR_FILEERROR;
                        goto save_error_exit;
                    }
                }
            }
            else if (lgt->get_type() == ESCH_LGTT_FSPOT
                     || lgt->get_type() == ESCH_LGTT_SPOT)
            {
                if (flags & FLOATING)
                {
                    EschFileLightSpot   spot;
                    memset(&spot,0,sizeof(spot));

                    strncpy(spot.name,lgt->name,ESCH_MAX_NAME);
                    spot.flags = lgt->flags;

                    byte i = lgt->get_intensity();
                    spot.color = i << 16 | i << 8 | i;

                    if (lgt->get_type() == ESCH_LGTT_FSPOT)
                    {
                        spot.x = ((EschFastSpotLight*)lgt)->pos.x;
                        spot.y = ((EschFastSpotLight*)lgt)->pos.y;
                        spot.z = ((EschFastSpotLight*)lgt)->pos.z;
                        spot.i = ((EschFastSpotLight*)lgt)->dir.i;
                        spot.j = ((EschFastSpotLight*)lgt)->dir.j;
                        spot.k = ((EschFastSpotLight*)lgt)->dir.k;
                        spot.hotspot = ((EschFastSpotLight*)lgt)->hotspot;
                        spot.falloff = ((EschFastSpotLight*)lgt)->falloff;
                        spot.inner = ((EschFastSpotLight*)lgt)->inner;
                        spot.outer = ((EschFastSpotLight*)lgt)->outer;
                    }
                    else
                    {
                        spot.x = ((EschSpotLight*)lgt)->pos.x;
                        spot.y = ((EschSpotLight*)lgt)->pos.y;
                        spot.z = ((EschSpotLight*)lgt)->pos.z;
                        spot.i = ((EschSpotLight*)lgt)->dir.i;
                        spot.j = ((EschSpotLight*)lgt)->dir.j;
                        spot.k = ((EschSpotLight*)lgt)->dir.k;
                        spot.hotspot = ((EschSpotLight*)lgt)->hotspot;
                        spot.falloff = ((EschSpotLight*)lgt)->falloff;
                        spot.inner = ((EschSpotLight*)lgt)->inner;
                        spot.outer = ((EschSpotLight*)lgt)->outer;
                    }

                    if (iff.write((lgt->get_type() == ESCH_LGTT_FSPOT)
                                  ? iff.makeid('E','F','S','1')
                                  : iff.makeid('E','S','P','1'),
                                  &spot,sizeof(spot)))
                    {
                        err=ESCH_ERR_FILEERROR;
                        goto save_error_exit;
                    }
                }
                else
                {
                    EschFileLightSpotV1   spot;
                    memset(&spot,0,sizeof(spot));

                    strncpy(spot.name,lgt->name,ESCH_MAX_NAME);
                    spot.flags = lgt->flags;

                    byte i = lgt->get_intensity();
                    spot.color = i << 16 | i << 8 | i;

                    if (lgt->get_type() == ESCH_LGTT_FSPOT)
                    {
                        spot.x = long(((EschFastSpotLight*)lgt)->pos.x * 65536.0f);
                        spot.y = long(((EschFastSpotLight*)lgt)->pos.y * 65536.0f);
                        spot.z = long(((EschFastSpotLight*)lgt)->pos.z * 65536.0f);
                        spot.i = long(((EschFastSpotLight*)lgt)->dir.i * 65536.0f);
                        spot.j = long(((EschFastSpotLight*)lgt)->dir.j * 65536.0f);
                        spot.k = long(((EschFastSpotLight*)lgt)->dir.k * 65536.0f);
                        spot.hotspot = long(((EschFastSpotLight*)lgt)->hotspot * 65536.0f);
                        spot.falloff = long(((EschFastSpotLight*)lgt)->falloff * 65536.0f);
                        spot.inner = long(((EschFastSpotLight*)lgt)->inner * 65536.0f);
                        spot.outer = long(((EschFastSpotLight*)lgt)->outer * 65536.0f);
                    }
                    else
                    {
                        spot.x = long(((EschSpotLight*)lgt)->pos.x * 65536.0f);
                        spot.y = long(((EschSpotLight*)lgt)->pos.y * 65536.0f);
                        spot.z = long(((EschSpotLight*)lgt)->pos.z * 65536.0f);
                        spot.i = long(((EschSpotLight*)lgt)->dir.i * 65536.0f);
                        spot.j = long(((EschSpotLight*)lgt)->dir.j * 65536.0f);
                        spot.k = long(((EschSpotLight*)lgt)->dir.k * 65536.0f);
                        spot.hotspot = long(((EschSpotLight*)lgt)->hotspot * 65536.0f);
                        spot.falloff = long(((EschSpotLight*)lgt)->falloff * 65536.0f);
                        spot.inner = long(((EschSpotLight*)lgt)->inner * 65536.0f);
                        spot.outer = long(((EschSpotLight*)lgt)->outer * 65536.0f);
                    }

                    if (iff.write((lgt->get_type() == ESCH_LGTT_FSPOT)
                                  ? iff.makeid('E','F','S','P')
                                  : iff.makeid('E','S','P','T'),
                                  &spot,sizeof(spot)))
                    {
                        err=ESCH_ERR_FILEERROR;
                        goto save_error_exit;
                    }
                }
            }
            else // ESCH_LGTT_AMBIENT
            {
                EschFileLightAmbi   amb;
                memset(&amb,0,sizeof(EschFileLightAmbi));

                strncpy(amb.name,lgt->name,ESCH_MAX_NAME);
                amb.flags = lgt->flags;

                byte i = lgt->get_intensity();
                amb.color = i << 16 | i << 8 | i;

                if (iff.write(iff.makeid('E','A','M','B'),
                              &amb,sizeof(EschFileLightAmbi)))
                {
                    err=ESCH_ERR_FILEERROR;
                    goto save_error_exit;
                }
            }
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Meshes
        err=serialize_store_mesh(&iff,meshes);
        if (err)
            goto save_error_exit;

        //ÄÄ Return OK
        iff.leaveform();
        return;

         //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Save Error
         // Handle error return during save
save_error_exit: ;

        iff.leaveform();

        char    str[512];

        sprintf(str,"Error error 0x%x saving file.",(int)err);

        MessageBox(NULL,
                   str,"Escher Tool",MB_OK | MB_ICONEXCLAMATION);

        AfxThrowArchiveException(CArchiveException::generic);
        return;
        }
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Loading
        else
        {
        ulong               i;
        esch_error_codes    err;
        ulong               ncams=0;
        ulong               nmshs=0;
        ulong               nlgts=0;
        struct hier_type    *hier=0;
        EschFileSceneHDR    header;
        char                pname[ESCH_MAX_NAME];

        // Eventually should make a list of all scenes within the file and
        // user to select.  For now, we just take the first scene form.

        // See if there is a corresponding palette file for this
        // scene...

        char tmp[256], *c;
        strncpy(tmp,ar.GetFile()->GetFilePath(),256);
        for (i=strlen(tmp), c = &tmp[i-1]; c > 0; i--, c--)
        {
            if (*c == '.')
            {
                strcpy(c+1,"VGP");

                if (xf_exist(tmp))
                {
                    strcpy(pfname,tmp);
                    break;
                }

                strcpy(c+1,"PAL");

                if (xf_exist(tmp))
                {
                    strcpy(pfname,tmp);
                    break;
                }

                break;
            }
        }

        //ÄÄÄ Load palette (required)
        if (!LoadPalette(pfname))
        {
            MessageBox(NULL,
                       "Must have a valid Van Gogh palette","Fatal Error",MB_OK | MB_ICONEXCLAMATION);
            AfxThrowArchiveException(CArchiveException::generic);
        }

        for(;;)
        {
            if (iff.next() != XF_ERR_NONE)
            {
                AfxThrowArchiveException(CArchiveException::endOfFile);
                return;
            }

            if (iff.chunkid != iff.makeid('F','O','R','M')
                || iff.formid != iff.makeid('E','S','E','N'))
                continue;

            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Found an ESEN form

            iff.enterform();

            //ÄÄÄ Handle header
            if (iff.seekchunk(iff.makeid('H','D','R',' '))
                || iff.chunkSize != sizeof(EschFileSceneHDR))
            {
                AfxThrowArchiveException(CArchiveException::badIndex);
                return;
            }

            if (iff.read(&header))
            {
                AfxThrowArchiveException(CArchiveException::generic);
                return;
            }

            //ÄÄÄ Copy data

            strcpy(name,header.name);
            nmeshes = header.nobjects;
            ncameras = header.ncameras;
            nlights = header.nvectorlights
                      + header.nfpointlights
                      + header.nfattenlights
                      + header.nfspotlights
                      + header.npointlights
                      + header.nattenlights
                      + header.nspotlights;

            // Allocate memory for hiearchy patchup
            if (header.nobjects)
            {
                hier = new hier_type[nmeshes];
                if (!hier)
                {
                    AfxThrowMemoryException();
                    return;
                }
                memset(hier,0,sizeof(hier_type)*nmeshes);
            }

            //ÄÄ Scan and load chunks in form
            while (iff.next() == XF_ERR_NONE)
            {
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Description
                if (iff.chunkid == iff.makeid('D','E','S','C')
                    && iff.chunkSize < 256)
                {
                    if (iff.read(desc))
                    {
                        AfxThrowArchiveException(CArchiveException::generic);
                        return;
                    }
                }
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Author
                else if (iff.chunkid == iff.makeid('A','U','T','H')
                         && iff.chunkSize < 256)
                {
                    if (iff.read(auth))
                    {
                        AfxThrowArchiveException(CArchiveException::generic);
                        return;
                    }
                }
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Copyright
                else if (iff.chunkid == iff.makeid('(','C',')',' ')
                          && iff.chunkSize < 256)
                {
                    if (iff.read(copy))
                    {
                        AfxThrowArchiveException(CArchiveException::generic);
                        return;
                    }
                }
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Meshes
                else if (iff.chunkid == iff.makeid('F','O','R','M')
                         && iff.formid == iff.makeid('E','M','S','H'))
                {
                    EschMeshDraw    *m;

                    m = new EschMeshDraw;
                    if (!m)
                    {
                        AfxThrowMemoryException();
                        return;
                    }

                    err=m->load(&iff,0,palette,0,pname,ESCH_MSHLD_USEMFTXT
                                                       | ESCH_MSHLD_TXTTCBM);
                    if (err!=ESCH_ERR_NONE)
                    {
                        delete m;
                        goto load_error_exit;
                    }

                    if (!*pname)
                    {
                        // Root object or not using hierarchies

                        if (meshes)
                            m->sibling(meshes);
                        else
                            meshes=m;
                    }
                    else
                    {
                        // Need to save for later patchup

                        strncpy(hier[nmshs].pname,pname,ESCH_MAX_NAME);
                        hier[nmshs].m = m;
                    }
                    nmshs++;
                }

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Cameras
                else if (iff.chunkid == iff.makeid('E','C','A','M')
                         || iff.chunkid == iff.makeid('E','C','A','1'))
                {
                    EschCameraEx *c;

                    c = new EschCameraEx;
                    if (!c)
                    {
                        AfxThrowMemoryException();
                        return;
                    }

                    if ((err=c->load(&iff))!=0)
                    {
                        delete c;
                        goto load_error_exit;
                    }

                    if (cameras)
                        c->sibling(cameras);
                    else
                        cameras=c;

                    c->set_bcolor(palette->get_index(VngoColor24bit(20,20,32)));

                    ncams++;
                }

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Lights
                else if (iff.chunkid == iff.makeid('E','A','M','B')
                         || iff.chunkid == iff.makeid('E','V','E','C')
                         || iff.chunkid == iff.makeid('E','V','E','1')
                         || iff.chunkid == iff.makeid('E','F','P','T')
                         || iff.chunkid == iff.makeid('E','F','P','1')
                         || iff.chunkid == iff.makeid('E','F','A','T')
                         || iff.chunkid == iff.makeid('E','F','A','1')
                         || iff.chunkid == iff.makeid('E','F','S','P')
                         || iff.chunkid == iff.makeid('E','F','S','1')
                         || iff.chunkid == iff.makeid('E','P','N','T')
                         || iff.chunkid == iff.makeid('E','P','N','1')
                         || iff.chunkid == iff.makeid('E','A','T','N')
                         || iff.chunkid == iff.makeid('E','A','T','1')
                         || iff.chunkid == iff.makeid('E','S','P','T')
                         || iff.chunkid == iff.makeid('E','S','P','1') )
                {
                    EschLight   *l;

                    if (iff.chunkid == iff.makeid('E','A','M','B'))
                    {
                        l = new EschLight;
                    }
                    else if (iff.chunkid == iff.makeid('E','V','E','C')
                             || iff.chunkid == iff.makeid('E','V','E','1'))
                    {
                        l = (EschLight*)new EschVectorLight;
                    }
                    else if (iff.chunkid == iff.makeid('E','F','P','T')
                             || iff.chunkid == iff.makeid('E','F','P','1'))
                    {
                        l = (EschLight*)new EschFastPointLight;
                    }
                    else if (iff.chunkid == iff.makeid('E','F','A','T')
                             || iff.chunkid == iff.makeid('E','F','A','1'))
                    {
                        l = (EschLight*)new EschFastAttenLight;
                    }
                    else if (iff.chunkid == iff.makeid('E','F','S','P')
                             || iff.chunkid == iff.makeid('E','F','S','1'))
                    {
                        l = (EschLight*)new EschFastSpotLight;
                    }
                    else if (iff.chunkid == iff.makeid('E','P','N','T')
                             || iff.chunkid == iff.makeid('E','P','N','1'))
                    {
                        l = (EschLight*)new EschPointLight;
                    }
                    else if (iff.chunkid == iff.makeid('E','A','T','N')
                             || iff.chunkid == iff.makeid('E','A','T','1'))
                    {
                        l = (EschLight*)new EschAttenLight;
                    }
                    else if (iff.chunkid == iff.makeid('E','S','P','T')
                             || iff.chunkid == iff.makeid('E','S','P','1'))
                    {
                        l = (EschLight*)new EschSpotLight;
                    }

                    if (!l)
                    {
                        AfxThrowMemoryException();
                        return;
                    }

                    if ((err=l->load(&iff))!=0)
                    {
                        delete l;
                        goto load_error_exit;
                    }

                    if (lights)
                        l->sibling(lights);
                    else
                        lights = l;

                    if (iff.chunkid != iff.makeid('E','A','M','B'))
                        nlgts++;
                }
            }

            //ÄÄ Handle hierarchy patchup
            int             changed;
            EschMeshDraw    *m;

            // Looping, inserting objects that have parents already in drawable
            // tree.
            for(;;)
            {
                changed=0;
                for(i=0; i < nmeshes; i++)
                {
                    if (hier[i].m)
                    {
                        m=(EschMeshDraw*)meshes->find(hier[i].pname);
                        if (m)
                        {
                            changed=1;
                            hier[i].m->adopt(m);
                            hier[i].m=0;
                        }
                    }
                }

                if (!changed)
                    break;
            }

            // See if any objects are still not attached
            for(err=ESCH_ERR_NONE, i=0; i < nmeshes; i++)
            {
                if (hier[i].m)
                {
                    delete hier[i].m;
                    err=ESCH_ERR_INVALIDHIER;
                }
            }

            delete [] hier;

            if (err)
                goto load_error_exit;

            //ÄÄ Verify counts are as expected
            if (ncams != ncameras || nmshs != nmeshes || nlgts != nlights)
            {
                err=ESCH_ERR_MISSINGITEMS;
                goto load_error_exit;
            }

            //ÄÄ Return OK
            iff.leaveform();
            return;

            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Load Error
            // Handle error return during load, must free partial data
load_error_exit: ;

            if (hier)
                delete [] hier;
            iff.leaveform();

            char    str[512];

            sprintf(str,"Escher error 0x%x loading file.",(int)err);

            MessageBox(NULL,
                       str,"Escher Tool",MB_OK | MB_ICONEXCLAMATION);

            AfxThrowArchiveException(CArchiveException::generic);
            return;
        }
        }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolDoc - LoadPalette                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL ToolDoc::LoadPalette(const char *fname)
{
    int             err;

    switch (BitDepth)
    {
        case 15:
            {
                VngoPalIFF15 loadpal(palette);
                ((VngoPal15*)palette)->init(0);
                err=loadpal.load(fname);
            }
            break;
        default:
            {
                VngoPalIFF8 loadpal(palette);
                ((VngoPal8*)palette)->init(0);
                err=loadpal.load(fname);
            }
            break;
    }

    if (err)
    {
        char    str[512];

        sprintf(str,"Error #%x loading Van Gogh palette file:\n\n%s",(int)err,fname);

        MessageBox(NULL,
                   str,"Error",MB_OK | MB_ICONEXCLAMATION);

        return FALSE;
    }

    if (fname != pfname)
        strcpy(pfname,fname);

    LOGPALETTE *lpal = (LOGPALETTE *) ivory_alloc(sizeof(LOGPALETTE)
                                                  + 256*sizeof(PALETTEENTRY));

    lpal->palVersion = 0x300;
    lpal->palNumEntries = 256;

    for (int i=0; i < 256; i++)
    {
        lpal->palPalEntry[i].peRed  = palette->hw_pal.p[i].r;
        lpal->palPalEntry[i].peGreen= palette->hw_pal.p[i].g;
        lpal->palPalEntry[i].peBlue = palette->hw_pal.p[i].b;
        lpal->palPalEntry[i].peFlags= PC_NOCOLLAPSE;
    }

    if (hpal)
        DeleteObject(hpal);

    hpal = CreatePalette(lpal);

    ivory_free( (void**)&lpal );

    if (!hpal)
    {
        MessageBox(NULL,
                   "Failed to create a palette from Van Gogh palette file","Error",MB_OK | MB_ICONEXCLAMATION);

        return FALSE;
    }

    return TRUE;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Message Handlers °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ToolDoc - OnNewDocument                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL ToolDoc::OnNewDocument()
{
        if (!CDocument::OnNewDocument())
                return FALSE;

    strcpy(name,"NoName");
    *desc = 0;
    SetTitle(name);

    flags = COMPRESS | FLOATING | TRUECOLOR;

//ÄÄÄ Load default palette (required)
    if (!LoadPalette(pfname))
    {
        MessageBox(NULL,
                   "Must have a valid default Van Gogh palette","Fatal Error",MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }

        return TRUE;
}

//°±² eof - eshtdoc.cpp ²±°
