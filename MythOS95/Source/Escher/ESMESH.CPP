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
//ùùùùùùùùùùCopyrightù(c)ù1994,ù1995ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
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
// esmesh.cpp
//
//      Contains the code for the EschMesh container object.  This object
//      is used to contain the original polygonal object data and is referred
//      to and used by one ore more EschMeshDraw objects, thus reducing
//      memory usage for multiple copies of the same mesh display
//      simultaneously.
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
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMesh - Constructor                                                   ³
//                                                                          ³
// Initializes the internal data pointers to empty values.                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschMesh::EschMesh(const char *fname, const char *oname,
                   VngoPal *pal, EschMatrix *m, char *pn)
{
    ref_count=0;
    flags=0;
    nverts=nfaces=tmax=0;
    v=0;
    f=0;
    txt=0;

    if (fname)
        load(fname,oname,pal,m, pn);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMesh - Destructor                                                    ³
//                                                                          ³
// Calls the release function.                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschMesh::~EschMesh()
{
    assertMyth("~EschMesh expects that there are no references active",
               !ref_count);

    release();
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMesh - release                                                       ³
//                                                                          ³
// Frees associated data, if owned by the mesh.  Returns an error if the    ³
// object is referenced.                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschMesh::release(void)
{
    if (ref_count)
        return ESCH_ERR_REFERENCED;

    if (flags & ESCH_MSH_OWNSDATA)
    {
        if (v)
        {
            ivory_hfree(&v);
        }

        if (f)
        {
            ivory_hfree(&f);
        }

        //ÄÄ Update diags
        EschSysInstance->diag_faces -= nfaces;
        EschSysInstance->diag_verts -= nverts;

        nverts=nfaces=0;
    }

    if (flags & ESCH_MSH_OWNSTEXTURE)
    {
        delete [] txt;
        txt=0;

        tmax=0;
    }

    return ESCH_ERR_NONE;
}


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  I/O Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschMesh - load                                                          ³
//                                                                          ³
// This loads data for the EschMesh object from an IFF file, optionally     ³
// returning any orientation matrix contained within the mesh record.       ³
//                                                                          ³
// The IFF version assumes that the IFF is open and pointing at the proper  ³
// chunk.  If a 'oname' is given and the name doesn't match that in the     ³
// form, an error is returned.                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschMesh::load(const char *fname, const char *oname,
                                VngoPal *pal, EschMatrix *m, char *pn)
{
    esch_error_codes    err;
    XFParseIFF          iff;

    assertMyth("EschMesh::load expects that there are no references active",
               !ref_count);

//ÄÄ Open file
    if (iff.open(fname,XF_OPEN_READ))
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
        }

        if (iff.chunkid == iff.makeid('F','O','R','M'))
        {
            if (iff.formid == iff.makeid('E','M','S','H'))
            {
                err=load(&iff,oname,pal,m,pn);
                if (!err
                    || err != ESCH_ERR_NOTFOUND)
                    break;
            }

            // Must scan inside any ESEN Scene forms.
            else if (iff.formid == iff.makeid('E','S','E','N'))
            {
                iff.enterform();
            }
        }
    }

//ÄÄ Return ok
    iff.close();
    return err;
}

esch_error_codes EschMesh::load(XFParseIFF *iff,
                                const char *oname,
                                VngoPal *pal,
                                EschMatrix *m, char *pn)
{
    ulong               i;
    esch_error_codes    err;
    EschFileMeshHDR     header;
    EschFileMeshEXNT    extent;
    EschFileMeshMTL     *emtl=0;

    assertMyth("EschMesh::load expects that there are no references active",
               !ref_count);

    assertMyth("EschMesh::load needs a valid iff pointer",
               iff);

//ÄÄ Verify correct form name
    if (iff->chunkid != iff->makeid('F','O','R','M')
        || iff->formid != iff->makeid('E','M','S','H'))
        return ESCH_ERR_NOTFOUND;

//ÄÄ Enter FORM, find header, verify name if any.
    iff->enterform();

    if (iff->seekchunk(iff->makeid('H','D','R',' '))
        || iff->chunkSize != sizeof(EschFileMeshHDR))
    {
        iff->leaveform();
        return ESCH_ERR_INVALIDDATA;
    }

    if (iff->read(&header))
    {
        iff->leaveform();
        return ESCH_ERR_FILEERROR;
    }

    if (oname && strncmp(oname,header.name,ESCH_MAX_NAME))
    {
        iff->leaveform();
        return ESCH_ERR_NOTFOUND;
    }

    if (!header.nverts || !header.nfaces)
    {
        iff->leaveform();
        return ESCH_ERR_INVALIDDATA;
    }

//ÄÄ Found, so setup mesh

    strncpy(name,header.name,ESCH_MAX_NAME);
    flags = header.flags | ESCH_MSH_OWNSDATA;

    nverts = header.nverts;
    v=0;
    nfaces = header.nfaces;
    f=0;
    txt=0;

    if (pn)
        *pn=0;

    //ÄÄ Scan and load chunks in form
    while (!iff->next())
    {

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Verticies
        if (iff->chunkid == iff->makeid('V','E','R','T'))
        {
            if (iff->chunkSize != (nverts * sizeof(EschVertex)))
            {
                err=ESCH_ERR_INVALIDVDATA;
                goto error_exit;
            }
            v = ivory_halloc( sizeof(EschVertex) * nverts );
            if (!v)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            EschVertex *ptr = (EschVertex*)ivory_hlock(v);
            if (!ptr)
            {
                err=ESCH_ERR_LOCKFAILED;
                goto error_exit;
            }
            if (iff->read(ptr))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }
            ivory_hunlock(v);
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Faces
        else if (iff->chunkid == iff->makeid('F','A','C','E'))
        {
            if (iff->chunkSize != (nfaces * sizeof(EschFace)))
            {
                err=ESCH_ERR_INVALIDFDATA;
                goto error_exit;
            }
            f = ivory_halloc( sizeof(EschFace) * nfaces );
            if (!f)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            EschFace *ptr = (EschFace*)ivory_hlock(f);
            if (!ptr)
            {
                err=ESCH_ERR_LOCKFAILED;
                goto error_exit;
            }
            if (iff->read(ptr))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }
            ivory_hunlock(f);
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Extents
        else if (iff->chunkid == iff->makeid('E','X','N','T'))
        {
            if (iff->chunkSize != sizeof(EschFileMeshEXNT))
            {
                err=ESCH_ERR_INVALIDDATA;
                goto error_exit;
            }
            if (iff->read(&extent))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }
         
            exts.flags=0;
            exts.center.x=extent.cenx;
            exts.center.y=extent.ceny;
            exts.center.z=extent.cenz;
            exts.radius=extent.extent_radius;
            exts.mins[0]=extent.minx;
            exts.mins[1]=extent.miny;
            exts.mins[2]=extent.minz;
            exts.maxs[0]=extent.maxx;
            exts.maxs[1]=extent.maxy;
            exts.maxs[2]=extent.maxz;
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Orientation Matrix
        else if (m && iff->chunkid == iff->makeid('M','T','R','X'))
        {
            if (iff->chunkSize != sizeof(EschMatrix))
            {
                err=ESCH_ERR_INVALIDDATA;
                goto error_exit;
            }
            if (iff->read(m)) 
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Hiearchy
        else if (pn && iff->chunkid == iff->makeid('H','I','E','R'))
        {
            if (iff->chunkSize != sizeof(EschFileMeshHIER))
            {
                err=ESCH_ERR_INVALIDHIER;
                goto error_exit;
            }
            if (iff->read(pn))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Materials
        else if (header.nmtls
                 && (iff->chunkid == iff->makeid('M','T','L',' ')))
        {
            if (iff->chunkSize != (sizeof(EschFileMeshMTL)*header.nmtls))
            {
                err=ESCH_ERR_INVALIDDATA;
                goto error_exit;
            }
            emtl = new EschFileMeshMTL[header.nmtls];
            if (!emtl)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }
            if (iff->read(emtl))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Material Form
        else if (header.nmtls
                 && (iff->chunkid == iff->makeid('F','O','R','M'))
                 && (iff->formid == iff->makeid('E','M','T','L')))
        {
            if (!f || !emtl)
            {
                err=ESCH_ERR_INVALIDDATA;
                goto error_exit;
            }

            // Allocate texture memory, if not already allocated.
            if (!txt)
            {
                txt = new EschTexture[header.nmtls];
                if (!txt)
                {
                    err=ESCH_ERR_NOMEMORY;
                    goto error_exit;
                }
                tmax = header.nmtls;
                flags |= ESCH_MSH_OWNSTEXTURE;
            }

            EschTexture t;

            if (err=t.load(iff))
            {
                goto error_exit;
            }

            for(i=0; i < header.nmtls; i++)
            {
                if (!strncmp(t.name,emtl[i].name,ESCH_MAX_NAME))
                {
                    txt[i] = t;
                    t.flags &= ~ESCH_TXT_OWNSDATA;
                    break;
                }
            }

            if (i >= header.nmtls)
            {
                t.release();
            }
        }
    }

    if (txt)
    {
        for(i=0; i < header.nmtls; i++)
        {
            if (!txt[i].handle)
            {
                err=ESCH_ERR_MISSINGDATA;
                goto error_exit;
            }
        }
    }
    else
    {

#if 1
//ÄÄ Process texture/materials
        
        EschFace *ptr = (EschFace*)ivory_hlock(f);
        if (!ptr)
        {
            err=ESCH_ERR_LOCKFAILED;
            goto error_exit;
        }

        for(i=0; i < nfaces; i++)
        {
            ptr[i].txt=0;
        }
        ivory_hunlock(f);
#endif

    }

    if (emtl)
        delete emtl;

//ÄÄ Update diags
    EschSysInstance->diag_faces += nfaces;
    EschSysInstance->diag_verts += nverts;

//ÄÄ Translate colors if a palette is given.
    if (pal)
    {
        EschFace *ptr = (EschFace*)ivory_hlock(f);
        if (!ptr)
        {
            err=ESCH_ERR_LOCKFAILED;
            goto error_exit;
        }

        for(i=0; i < nfaces; i++)
        {
            ptr[i].color = pal->get_index(*((VngoColor24bit*)&ptr[i].color));
        }
        ivory_hunlock(f);
    }

//ÄÄ Return ok
    iff->leaveform();
    return ESCH_ERR_NONE;

//ÄÄ Return error
error_exit : ;
    if (v)
        ivory_hfree(&v);
    if (f)
        ivory_hfree(&f);
    delete [] txt;
    txt=0;

    iff->leaveform();
    return err;
}

//°±² End of module - esmesh.cpp ²±°

