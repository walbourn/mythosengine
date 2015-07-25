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
//                       *** IPAS Mesh Data Exporter ***
//
// export.cpp
//
// Contains the data download & output code.  Uses XFile.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <float.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "xfiff.hpp"

#include "felix.hpp"

#include <vngdefs.h>
#include <vngstrct.hpp>

#include <esdefs.h>
#include <esmath.hpp>
#include <estxture.hpp>
#include <esgeom.hpp>
#include <esfile.hpp>

extern "C" {
#include "pxp.h"
#include "keys.h"
}

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

struct FloatPoint { double x, y, z; };

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern "C" int capture_setup();
extern "C" void capture_terminate();
extern "C" int capture_get(ItemData **item, XVData **verts, XFData **faces);
extern "C" int capture_gethier(ItemData *idata, char *name, float *m);
extern "C" int capture_getpivot(ItemData *idata, float *px, float *py, float *pz);
extern "C" MtlData *capture_mtlget(int ind, ushort *selfi);
extern "C" int capture_mtlfile(int ind, char *fname, char *tfname);

extern "C" BXPColor *capture_mtlbitmap(char *fname, ushort *xs, ushort *ys, int forcesize);

STATIC void compute_box_extents( ItemData *idata,
                                 XVData *verts,
                                 EschFileMeshEXNT *mextents );
STATIC void compute_quick_extents( ItemData *idata,
                                   XVData *verts,
                                   EschFileMeshEXNT *mextents );
STATIC int compute_optimal_extents( ItemData *idata,
                                    XVData *verts,
                                    EschFileMeshEXNT *mextents );
STATIC int load_pal(VngoPal *pal,char *infile);
STATIC int check_abort();

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern "C" char output_path[];
extern "C" char output_name[];
extern "C" char scene_name[];

extern "C" dword  object_flags;

extern "C" float  scale_3ds2esch;

extern "C" int source_mode;
extern "C" int coord_mode;
extern "C" int extent_mode;
extern "C" int material_mode;
extern "C" int hierarchy_mode;
extern "C" int orientation_mode;

extern "C" int count_camera;
extern "C" int count_vectlights;
extern "C" int count_fpointlights;
extern "C" int count_fattenlights;
extern "C" int count_fspotlights;
extern "C" int count_pointlights;
extern "C" int count_attenlights;
extern "C" int count_spotlights;
extern "C" int count_objects;

// Material export information

extern "C" char mtl_palpath[];
extern "C" char mtl_palname[];

// Light export information

extern "C" int lgt_omnias;
extern "C" int lgt_spotas;
extern "C" int lgt_ambient;
extern "C" int lgt_atten;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// export                                                                   ³
//                                                                          ³
// Initates data download and outputs to the file.                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void export()
{
    int                 i, j, k;
    int                 nmtls;
    int                 steps;
    float               tx, ty, tz;
    float               cx, cy, cz;
    float               cs, sn, dot;
    ItemData            *idata;
    XVData              *verts;
    XFData              *faces;
    MtlData             *mtl;
    EschVertex          *everts;
    EschFace            *efaces;
    EschFileMeshMTL     *emtls;
    char                *mtlfnames;
    VngoPal             *pal=0;
    EschFileMeshHDR     mheader;
    EschFileMeshEXNT    mextents;
    EschFileSceneHDR    sdata;
    EschFileMeshHIER    ehier;
    EschMatrix          mtx;
    XFParseIFF          iff;
    ushort              selfi;
    char                fname[13];
    char                tfname[13];
    char                buff[128];

    float               v1[3],v2[3],vr[3], mag;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Get initial data information, check for outputable data.
    switch(capture_setup())
    {
        case 1:
            gfx_continu_line("No objects to export");
            return;
        case 2:
            gfx_continu_line("ERROR:  Failed during pxp_get_item() in setup");
            return;
        default:
            break;
    }

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Open output file
    strcpy(buff,output_path);
    if (output_path[strlen(output_path)-1] != '\\')
        strcat(buff,"\\");
    strcat(buff,output_name);
 
    if (iff.create(buff,0))
    {
        sprintf(buff,"ERROR:  Cannot create output file, error #%d",
                iff.error());
        gfx_continu_line(buff);
        capture_terminate();
        return;
    }
 
    gfx_stand_by("Exporting...");
 
    if (iff.newform(iff.makeid('E','S','E','N')))
    {
        sprintf(buff,"ERROR:  Cannot create scene form, error #%d",
                iff.error());
        gfx_continu_line(buff);
        goto error_exit;
    }
 
    memset(&sdata,0,sizeof(EschFileSceneHDR));
    strcpy(sdata.name,scene_name);
 
    sdata.ncameras = count_camera;
    sdata.nobjects = count_objects;
    sdata.nvectorlights = count_vectlights;
    sdata.nfpointlights = (ushort) count_fpointlights;
    sdata.nfattenlights = (ushort) count_fattenlights;
    sdata.nfspotlights = (ushort) count_fspotlights;
    sdata.npointlights = count_pointlights;
    sdata.nattenlights = (ushort) count_attenlights;
    sdata.nspotlights = (ushort) count_spotlights;
 
    if (iff.write(iff.makeid('H','D','R',' '),
                  &sdata,sizeof(EschFileSceneHDR)))
    {
         sprintf(buff,"Error writing HDR chunk, error #%d",
                 iff.error());
         gfx_continu_line(buff);
         goto error_exit;
    }
 
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Loop through captureable objects, exporting FORM for each
    while (!capture_get(&idata,&verts,&faces))
    {
        gfx_put_hole();
        gfx_report("");

        if (check_abort())
            goto error_exit;
 
        switch(idata->type)
        {
 
//ÄÄÄ Cameras ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
            case PXPCAMERA:
                {
                    EschFileCamera      cdata;
                    sprintf(buff,"Exporting Camera: %s",idata->name);
                    gfx_stand_by(buff);
                    gfx_report(buff);
             
                    memset(&cdata,0,sizeof(EschFileCamera));
                    strcpy(cdata.name,idata->name);
                    cdata.x = (Flx16) (idata->item.c.x * scale_3ds2esch);
                    cdata.y = (Flx16) (idata->item.c.z * scale_3ds2esch);
                    cdata.z = (Flx16) (idata->item.c.y * scale_3ds2esch);
                    cdata.fov = (Flx16) (2400.0 / idata->item.c.focal);

                    // Z rotate a [0 1 0] top vector for bank angle
                    tx=0;
                    ty=1;
                    tz=0;

                    cs = cos(idata->item.c.bank);
                    sn = sin(idata->item.c.bank);

                    tx = tx*cs + ty*sn;
                    ty = tx*sn + ty*cs;

                    // Normalize top vector
                    mag = sqrt(tx*tx + ty*ty + tz*tz);
                    tx /= mag;
                    ty /= mag;
                    tz /= mag;

                    // Create direction vector
                    vr[0] = idata->item.c.tx - idata->item.c.x;
                    vr[1] = idata->item.c.tz - idata->item.c.z;
                    vr[2] = idata->item.c.ty - idata->item.c.y;

                    // Normalize direction vector
                    mag = sqrt(vr[0]*vr[0] + vr[1]*vr[1] + vr[2]*vr[2]);
                    vr[0] /= mag;
                    vr[1] /= mag;
                    vr[2] /= mag;

                    // Ortho top vs. the direction vector
                    //
                    //     top = top - dir*(top DOT dir)
                    //
                    dot = (tx*vr[0]) + (ty*vr[1]) + (tz*vr[2]);
                    tx -= vr[0]*dot;
                    ty -= vr[1]*dot;
                    tz -= vr[2]*dot;

                    // Normalize top vector again
                    mag = sqrt(tx*tx + ty*ty + tz*tz);
                    tx /= mag;
                    ty /= mag;
                    tz /= mag;

                    // Store into struct
                    cdata.diri = (Flx16) vr[0];
                    cdata.dirj = (Flx16) vr[1];
                    cdata.dirk = (Flx16) vr[2];

                    cdata.topi = (Flx16) tx;
                    cdata.topj = (Flx16) ty;
                    cdata.topk = (Flx16) tz;
             
                    // Write chunk
                    if (iff.write(iff.makeid('E','C','A','M'),
                                &cdata,sizeof(EschFileCamera)))
                    {
                        sprintf(buff,"ERROR:  Writing ECAM chunk, error #%d",
                            iff.error());
                        gfx_continu_line(buff);
                        goto error_exit;
                    }
                }

                break;

//ÄÄÄ Lights ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ  
           case PXPAMBIENT:
                if (lgt_ambient)
                {
                    EschFileLightAmbi   adata;

                    sprintf(buff,"Exporting Ambient: %s",idata->name);
                    gfx_stand_by(buff);
                    gfx_report(buff);

                    memset(&adata,0,sizeof(EschFileLightAmbi));
                    strcpy(adata.name,idata->name);
                    ((VngoColor24bit*)&adata.color)->r = (byte)(idata->item.a.color.r*255.0);
                    ((VngoColor24bit*)&adata.color)->g = (byte)(idata->item.a.color.g*255.0);
                    ((VngoColor24bit*)&adata.color)->b = (byte)(idata->item.a.color.b*255.0);
            
                    if (iff.write(iff.makeid('E','A','M','B'),
                                &adata,sizeof(EschFileLightAmbi)))
                    {
                        sprintf(buff,"ERROR:  Writing EAMB chunk, error #%d",
                            iff.error());
                        gfx_continu_line(buff);
                        goto error_exit;
                    }
                }

                break;

           case PXPLIGHT:
                sprintf(buff,"Exporting Light: %s",idata->name);
                gfx_stand_by(buff);
                gfx_report(buff);

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Spot
                if (idata->item.l.hotsize != 360.0
                    || idata->item.l.fallsize != 360.0)
                {
                    //ÄÄÄ Vector
                    if (lgt_spotas == 3)
                    {
                        EschFileLightVect   vdata;
                        memset(&vdata,0,sizeof(EschFileLightVect));
                        strcpy(vdata.name,idata->name);

                        if (!(idata->item.l.flags & LIGHT_ON))
                            vdata.flags |= ESCH_LGT_OFF;

                        vr[0] = idata->item.l.tx - idata->item.l.x;
                        vr[1] = idata->item.l.tz - idata->item.l.z;
                        vr[2] = idata->item.l.ty - idata->item.l.y;
                        mag = sqrt(vr[0]*vr[0] + vr[1]*vr[1] + vr[2]*vr[2]);

                        vdata.i = (Flx16) (vr[0] / mag);
                        vdata.j = (Flx16) (vr[1] / mag);
                        vdata.k = (Flx16) (vr[2] / mag);

                        ((VngoColor24bit*)&vdata.color)->r = (byte)(idata->item.l.color.r
                                                                * idata->item.l.mult * 255.0);
                        ((VngoColor24bit*)&vdata.color)->g = (byte)(idata->item.l.color.g
                                                                * idata->item.l.mult * 255.0);
                        ((VngoColor24bit*)&vdata.color)->b = (byte)(idata->item.l.color.b
                                                                * idata->item.l.mult * 255.0);
                   
                        if (iff.write(iff.makeid('E','V','E','C'),
                                    &vdata,sizeof(EschFileLightVect)))
                        {
                            sprintf(buff,"ERROR:  Writing EVEC chunk, error #%d",
                                iff.error());
                            gfx_continu_line(buff);
                            goto error_exit;
                        }
                    }
                    //ÄÄÄ Fast or Spot
                    else // lgt_spot == 1 or lgt_spotas == 2
                    {
                        EschFileLightSpot  sdata;
                        memset(&sdata,0,sizeof(EschFileLightSpot));
                        strcpy(sdata.name,idata->name);

                        if (!(idata->item.l.flags & LIGHT_ON))
                            sdata.flags |= ESCH_LGT_OFF;

                        sdata.x = (Flx16) (idata->item.l.x * scale_3ds2esch);
                        sdata.y = (Flx16) (idata->item.l.z * scale_3ds2esch);
                        sdata.z = (Flx16) (idata->item.l.y * scale_3ds2esch);

                        vr[0] = idata->item.l.tx - idata->item.l.x;
                        vr[1] = idata->item.l.tz - idata->item.l.z;
                        vr[2] = idata->item.l.ty - idata->item.l.y;
                        mag = sqrt(vr[0]*vr[0] + vr[1]*vr[1] + vr[2]*vr[2]);

                        sdata.i = (Flx16) (vr[0] / mag);
                        sdata.j = (Flx16) (vr[1] / mag);
                        sdata.k = (Flx16) (vr[2] / mag);

                        sdata.hotspot = (Flx16) idata->item.l.hotsize;
                        sdata.falloff = (Flx16) idata->item.l.fallsize;

                        ((VngoColor24bit*)&sdata.color)->r = (byte)(idata->item.l.color.r
                                                                * idata->item.l.mult * 255.0);
                        ((VngoColor24bit*)&sdata.color)->g = (byte)(idata->item.l.color.g
                                                                * idata->item.l.mult * 255.0);
                        ((VngoColor24bit*)&sdata.color)->b = (byte)(idata->item.l.color.b
                                                                * idata->item.l.mult * 255.0);

                        if (lgt_atten
                            && idata->item.l.flags & LIGHT_ATTEN)
                        {
                            sdata.flags |= ESCH_LGT_ATTEN;
                            sdata.inner = (Flx16) (idata->item.l.in_range * scale_3ds2esch);
                            sdata.outer = (Flx16) (idata->item.l.out_range * scale_3ds2esch);
                        }
                        else
                            sdata.outer = Flx16(0x1000);

                        if (lgt_spotas == 2)
                        {
                            if (iff.write(iff.makeid('E','S','P','T'),
                                        &sdata,sizeof(EschFileLightSpot)))
                            {
                                sprintf(buff,"ERROR:  Writing ESPT chunk, error #%d",
                                    iff.error());
                                gfx_continu_line(buff);
                                goto error_exit;
                            }
                        }
                        else
                        {
                            if (iff.write(iff.makeid('E','F','S','P'),
                                        &sdata,sizeof(EschFileLightSpot)))
                            {
                                sprintf(buff,"ERROR:  Writing EFSP chunk, error #%d",
                                    iff.error());
                                gfx_continu_line(buff);
                                goto error_exit;
                            }
                        }
                    }
                }
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Omni
                else
                {
                    //ÄÄÄ Attenuated version
                    if (lgt_atten
                        && idata->item.l.flags & LIGHT_ATTEN)
                    {
                        EschFileLightAtten  adata;
                        memset(&adata,0,sizeof(EschFileLightAtten));
                        strcpy(adata.name,idata->name);

                        adata.flags |= ESCH_LGT_ATTEN;
                        if (!(idata->item.l.flags & LIGHT_ON))
                            adata.flags |= ESCH_LGT_OFF;

                        adata.x = (Flx16) (idata->item.l.x * scale_3ds2esch);
                        adata.y = (Flx16) (idata->item.l.z * scale_3ds2esch);
                        adata.z = (Flx16) (idata->item.l.y * scale_3ds2esch);

                        adata.inner = (Flx16) (idata->item.l.in_range * scale_3ds2esch);
                        adata.outer = (Flx16) (idata->item.l.out_range * scale_3ds2esch);

                        ((VngoColor24bit*)&adata.color)->r = (byte)(idata->item.l.color.r
                                                                * idata->item.l.mult * 255.0);
                        ((VngoColor24bit*)&adata.color)->g = (byte)(idata->item.l.color.g
                                                                * idata->item.l.mult * 255.0);
                        ((VngoColor24bit*)&adata.color)->b = (byte)(idata->item.l.color.b
                                                                * idata->item.l.mult * 255.0);

                        if (lgt_omnias == 2)
                        {
                            if (iff.write(iff.makeid('E','A','T','N'),
                                        &adata,sizeof(EschFileLightAtten)))
                            {
                                sprintf(buff,"ERROR:  Writing EATN chunk, error #%d",
                                    iff.error());
                                gfx_continu_line(buff);
                                goto error_exit;
                            }
                        }
                        else // lgt_omnias == 1
                        {
                            if (iff.write(iff.makeid('E','F','A','T'),
                                        &adata,sizeof(EschFileLightAtten)))
                            {
                                sprintf(buff,"ERROR:  Writing EFAT chunk, error #%d",
                                    iff.error());
                                gfx_continu_line(buff);
                                goto error_exit;
                            }
                        }
                    }
                    //ÄÄÄ Nonattenuated version
                    else
                    {
                        EschFileLightPoint  pdata;
                        memset(&pdata,0,sizeof(EschFileLightPoint));
                        strcpy(pdata.name,idata->name);

                        if (!(idata->item.l.flags & LIGHT_ON))
                            pdata.flags |= ESCH_LGT_OFF;

                        pdata.x = (Flx16) (idata->item.l.x * scale_3ds2esch);
                        pdata.y = (Flx16) (idata->item.l.z * scale_3ds2esch);
                        pdata.z = (Flx16) (idata->item.l.y * scale_3ds2esch);

                        ((VngoColor24bit*)&pdata.color)->r = (byte)(idata->item.l.color.r
                                                                * idata->item.l.mult * 255.0);
                        ((VngoColor24bit*)&pdata.color)->g = (byte)(idata->item.l.color.g
                                                                * idata->item.l.mult * 255.0);
                        ((VngoColor24bit*)&pdata.color)->b = (byte)(idata->item.l.color.b
                                                                * idata->item.l.mult * 255.0);

                        if (lgt_omnias == 2)
                        {
                            if (iff.write(iff.makeid('E','P','N','T'),
                                        &pdata,sizeof(EschFileLightPoint)))
                            {
                                sprintf(buff,"ERROR:  Writing EPNT chunk, error #%d",
                                    iff.error());
                                gfx_continu_line(buff);
                                goto error_exit;
                            }
                        }
                        else // lgt_omnias == 1
                        {
                            if (iff.write(iff.makeid('E','F','P','T'),
                                        &pdata,sizeof(EschFileLightPoint)))
                            {
                                sprintf(buff,"ERROR:  Writing EFPT chunk, error #%d",
                                    iff.error());
                                gfx_continu_line(buff);
                                goto error_exit;
                            }
                        }
                    }
                }
                break;

//ÄÄÄ Meshs ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ 
           case PXPMESH:
                sprintf(buff,"Exporting Object: %s",idata->name);
                gfx_show_gasgauge(buff);
                gfx_report(buff);

                steps = idata->item.m.verts + idata->item.m.faces;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Create mesh form
                if (iff.newform(iff.makeid('E','M','S','H')))
                {
                    sprintf(buff,"ERROR:  Cannot create FORM, error #%d",
                            iff.error());
                    gfx_continu_line(buff);
                    goto error_exit;
                }
            
                // Create Header
                memset(&mheader,0,sizeof(EschFileMeshHDR));
                strcpy(mheader.name,idata->name);
                mheader.flags = object_flags;
                mheader.nverts = idata->item.m.verts;
                mheader.nfaces = idata->item.m.faces;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Compute extents
                memset(&mextents,0,sizeof(EschFileMeshEXNT));

                // Box extents
                sprintf(buff,"Object '%s': Computing box extents...",idata->name);
                gfx_set_gasgauge(buff,0,1);

                compute_box_extents( idata, verts, &mextents);

                // Radial extents
                sprintf(buff,"Object '%s': Computing radial extents...",idata->name);
                gfx_set_gasgauge(buff,0,1);
                if (extent_mode==2)
                {
                    // Optimal
                    if (compute_optimal_extents( idata, verts,
                                                 &mextents ))
                        goto error_exit;
                }
                else
                {
                    // Quick
                    compute_quick_extents( idata,
                                           verts,
                                           &mextents );
                }

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Compute matrix
                if (orientation_mode == 2)
                {
                    sprintf(buff,"Object '%s': Computing matrix...",idata->name);
                    gfx_set_gasgauge(buff,0,1);

                    if (hierarchy_mode == 2)
                    {
                        float m[4][3];

                        capture_gethier(idata,ehier.parent,&m[0][0]);

                        cx = m[3][0];
                        cy = m[3][1];
                        cz = m[3][2];

                        // Rest of matrix has already been applied to all
                        // verticies as captured in get_verts
                    }
                    else
                    {
                        cx = idata->item.m.matrix[3][0];
                        cy = idata->item.m.matrix[3][1];
                        cz = idata->item.m.matrix[3][2];

                        if (coord_mode == 1
                            && capture_getpivot(idata, &tx, &ty, &tz))
                        {
                            cx += tx;
                            cy += ty;
                            cz += tz;
                        }

                        // Rest of matrix has already been applied to all
                        // verticies as captured in get_verts
                    }

                    mtx.mtx[ESCH_MTX_J] = (Flx16) (cx * scale_3ds2esch);
                    mtx.mtx[ESCH_MTX_K] = (Flx16) (cz * scale_3ds2esch);
                    mtx.mtx[ESCH_MTX_L] = (Flx16) (cy * scale_3ds2esch);
                }

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Compute Faces/Verts
                // Allocate space for EschVerts & Eschfaces
                everts = new EschVertex[idata->item.m.verts];
                if (!everts)
                {
                    gfx_continu_line("Out of Memory!");
                    goto error_exit;
                }
                memset(everts,0,idata->item.m.verts*sizeof(EschVertex));

                efaces = new EschFace[idata->item.m.faces];
                if (!efaces)
                {
                    gfx_continu_line("Out of Memory!");
                    goto error_exit;
                }
                memset(efaces,0,idata->item.m.faces*sizeof(EschFace));

                emtls = new EschFileMeshMTL[256];
                if (!emtls)
                {
                    gfx_continu_line("Out of Memory!");
                    goto error_exit;
                }

                mtlfnames = new char[256*14*2];
                if (!mtlfnames)
                {
                    gfx_continu_line("Out of Memory!");
                    goto error_exit;
                }
               
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Compute Faces
                sprintf(buff,"Object '%s': Computing faces...",idata->name);
                gfx_set_gasgauge(buff,0,steps);

                nmtls=0;

                for(i=0; i < idata->item.m.faces; i++)
                {
                    gfx_set_gasgauge("",i,steps);

                    if (check_abort())
                        goto error_exit;

                    // Setup line visiblity flags
                    if (faces[i].flags & XF_ABLINE)
                        efaces[i].flags |= ESCH_FACE_ABLINE;
                    if (faces[i].flags & XF_BCLINE)
                        efaces[i].flags |= ESCH_FACE_BCLINE;
                    if (faces[i].flags & XF_CALINE)
                        efaces[i].flags |= ESCH_FACE_CALINE;
            
                    // Fill out vertex indecies.
                    efaces[i].a = faces[i].a;
                    efaces[i].b = faces[i].b;
                    efaces[i].c = faces[i].c;
            
                    // Compute face normal (ABC is in counter-clockwise order)
                    v1[0] = verts[faces[i].a].x - verts[faces[i].b].x; 
                    v1[1] = verts[faces[i].a].z - verts[faces[i].b].z;
                    v1[2] = verts[faces[i].a].y - verts[faces[i].b].y;
            
                    v2[0] = verts[faces[i].c].x - verts[faces[i].b].x; 
                    v2[1] = verts[faces[i].c].z - verts[faces[i].b].z;
                    v2[2] = verts[faces[i].c].y - verts[faces[i].b].y;
            
                    // Cross-product
                    vr[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
                    vr[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
                    vr[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
            
                    mag = sqrt(vr[0]*vr[0] + vr[1]*vr[1] + vr[2]*vr[2]);
            
                    efaces[i].normal.i = (Flx16) (vr[0] / mag);
                    efaces[i].normal.j = (Flx16) (vr[1] / mag);
                    efaces[i].normal.k = (Flx16) (vr[2] / mag);
            
                    // Fill out vertex mapping parameters
                    if (idata->item.m.tverts)
                    {
                        efaces[i].u[0] = (Flx16) (verts[faces[i].a].u);
                        efaces[i].u[1] = (Flx16) (verts[faces[i].b].u);
                        efaces[i].u[2] = (Flx16) (verts[faces[i].c].u);

                        // 3DS Uses the opposite definition of v, so we
                        // have to negate it to result in right-side up
                        // images.

                        efaces[i].v[0] = (Flx16) (-verts[faces[i].a].v);
                        efaces[i].v[1] = (Flx16) (-verts[faces[i].b].v);
                        efaces[i].v[2] = (Flx16) (-verts[faces[i].c].v);
                    }   
            
                    efaces[i].flags |= ESCH_FACE_WIRE
                                       | ESCH_FACE_SOLID
                                       | ESCH_FACE_ALLOWPERSP;

                    // Fill out material information
                    mtl = capture_mtlget(faces[i].material,&selfi);
                    if (mtl)
                    {
                        // Fill out face associated information
                        efaces[i].color=0;
                        ((VngoColor24bit*)&efaces[i].color)->r = mtl->diff.r;
                        ((VngoColor24bit*)&efaces[i].color)->g = mtl->diff.g;
                        ((VngoColor24bit*)&efaces[i].color)->b = mtl->diff.b;

                        if (!(mtl->flags & MTL_TWOSIDE))
                            efaces[i].flags |= ESCH_FACE_ONESIDED;

                        if (selfi)
                        {
                            dword slevel = (dword)( ((float)selfi * 15.0) / 100.0);

                            efaces[i].flags |= (slevel << 20)
                                               & ESCH_FACE_SELFILUM_MASK;
                        }

                        if (!(mtl->flags & MTL_WIRE))
                        {
                            switch (mtl->shading)
                            {
                                case 1:
                                    efaces[i].flags |= ESCH_FACE_FLAT;
                                    break;
                                case 2:
                                    efaces[i].flags |= ESCH_FACE_SMOOTH
                                                       | ESCH_FACE_FLAT;
                                    break;
                                case 3:
                                case 4:
                                    efaces[i].flags |= ESCH_FACE_SPECULAR
                                                       | ESCH_FACE_SMOOTH
                                                       | ESCH_FACE_FLAT;
                                    break;
                            }
                        }

                        // Check for maps
                        j=capture_mtlfile(faces[i].material,fname,tfname);

                        // Warning if ignored maps
                        if (j==2)
                        {
                            char name[ESCH_MAX_NAME+1];
                            strncpy(name,mtl->name,ESCH_MAX_NAME);
                            name[ESCH_MAX_NAME] = 0;

                            sprintf(buff,"%s: non-Texture1/Opacity maps ignored",
                                    name);
                            gfx_prompt(buff);
                        }

                        if (!*fname && *tfname)
                        {
                            char name[ESCH_MAX_NAME+1];
                            strncpy(name,mtl->name,ESCH_MAX_NAME);
                            name[ESCH_MAX_NAME] = 0;
                        
                            sprintf(buff,"%s: Opacity maps without Texture1 maps ignored",
                                    name);
                            gfx_prompt(buff);
                        }

                        // Handle valid map definition
                        if (*fname && (j==1 || j ==2))
                        {
                            if (!strstr(fname,".SXP") && !strstr(tfname,".SXP")
                                && !strstr(fname,".IFL") && !strstr(tfname,".IFL"))
                            {
                                // Add to local mtl's list for object.
                                for(j=0; j < nmtls; j++)
                                {
                                    if (!strncmp(mtl->name,emtls[j].name,ESCH_MAX_NAME))
                                    {
                                        efaces[i].txt=(word)(j+1);
                                        efaces[i].flags |= ESCH_FACE_TEXTURED;
                                        memset(&mtlfnames[14*2*j],0,14*2);
                                        strncpy(&mtlfnames[14*2*j],fname,13);
                                        strncpy(&mtlfnames[14*2*j+14],tfname,13);
                                        break;
                                    }
                                }
                                
                                if (!nmtls || (j >= nmtls))
                                {
                                    strncpy(emtls[nmtls].name,mtl->name,ESCH_MAX_NAME);
                                    efaces[i].txt=(word)(nmtls+1);
                                    efaces[i].flags |= ESCH_FACE_TEXTURED;
                                    memset(&mtlfnames[14*2*nmtls],0,14*2);
                                    strncpy(&mtlfnames[14*2*nmtls],fname,13);
                                    strncpy(&mtlfnames[14*2*nmtls+14],tfname,13);
                                    nmtls++;
                                }
                            }
                            else
                            {
                                char name[ESCH_MAX_NAME+1];
                                strncpy(name,mtl->name,ESCH_MAX_NAME);
                                name[ESCH_MAX_NAME] = 0;
                                sprintf(buff,"ERROR: %s: .SXP/.IFL not supported, texture skipped",
                                        name);
                                gfx_continu_line(buff);
                                goto error_exit;
                            }
                        }
                    }
                    else
                    {
                        // If no material, then assume smoothable specular
                        // single-sided material with grey color

                        efaces[i].color=0;
                        ((VngoColor24bit*)&efaces[i].color)->r = 128;
                        ((VngoColor24bit*)&efaces[i].color)->g = 128;
                        ((VngoColor24bit*)&efaces[i].color)->b = 128;

                        efaces[i].flags |= ESCH_FACE_SPECULAR
                                           | ESCH_FACE_SMOOTH
                                           | ESCH_FACE_FLAT
                                           | ESCH_FACE_ONESIDED;
                    }
                }
                mheader.nmtls = nmtls;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Compute Verticies
                sprintf(buff,"Object '%s': Computing vertices...",idata->name);
                gfx_set_gasgauge(buff,idata->item.m.faces+i,steps);

                // Get center of object from orientation matrix
                cx = idata->item.m.matrix[3][0];
                cy = idata->item.m.matrix[3][1];
                cz = idata->item.m.matrix[3][2];

                // Adjust center for pivot points, if any
                if (coord_mode == 1
                    && capture_getpivot(idata, &tx, &ty, &tz))
                {
                    cx += tx;
                    cy += ty;
                    cz += tz;
                }
            
                // Compute EschVerts
                for(i=0; i < idata->item.m.verts; i++)
                {
                    gfx_set_gasgauge("",idata->item.m.faces+i,steps);

                    if (check_abort())
                        goto error_exit;

                    tx = verts[i].x;
                    ty = verts[i].y;
                    tz = verts[i].z;
            
                    // Handle adjustment to center, if not exporting world coords.
                    if (coord_mode == 1)
                    {
                        tx -= cx;
                        ty -= cy;
                        tz -= cz;
                    }
            
                    everts[i].x = (Flx16) (tx * scale_3ds2esch);
                    everts[i].y = (Flx16) (tz * scale_3ds2esch);
                    everts[i].z = (Flx16) (ty * scale_3ds2esch);

                    vr[0]=vr[1]=vr[2]=0.0;
                    for(j=0; j < idata->item.m.faces; j++)
                    {
                        if (efaces[j].a == i
                            || efaces[j].b == i
                            || efaces[j].c == i)
                        {
                            vr[0] += efaces[j].normal.i;
                            vr[1] += efaces[j].normal.j;
                            vr[2] += efaces[j].normal.k;
                        }
                    }

                    mag = sqrt(vr[0]*vr[0] + vr[1]*vr[1] + vr[2]*vr[2]);
            
                    everts[i].normal.i = (Flx16) (vr[0] / mag);
                    everts[i].normal.j = (Flx16) (vr[1] / mag);
                    everts[i].normal.k = (Flx16) (vr[2] / mag);
                }

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Output Data
                sprintf(buff,"Object '%s': Writing...",idata->name);
                gfx_set_gasgauge(buff,steps,steps);

                // Output header
                if (iff.write(iff.makeid('H','D','R',' '),
                            &mheader,sizeof(EschFileMeshHDR)))
                {
                    sprintf(buff,"ERROR:  Writing HDR chunk, error #%d",
                           iff.error());
                    gfx_continu_line(buff);
                    goto error_exit;
                }

                // Matrix
                if ((orientation_mode == 2) &&
                    iff.write(iff.makeid('M','T','R','X'),
                             &mtx,sizeof(EschMatrix)))
                {
                    sprintf(buff,"ERROR:  Writing MTRX chunk, error #%d",
                           iff.error());
                    gfx_continu_line(buff);
                    goto error_exit;
                }

                // Hierarchy
                if (hierarchy_mode == 2)
                {
                    memset(&ehier,0,sizeof(EschFileMeshHIER));
                    if (capture_gethier(idata,ehier.parent,0)
                        && iff.write(iff.makeid('H','I','E','R'),
                             &ehier,sizeof(EschFileMeshHIER)))
                    {
                        sprintf(buff,"ERROR:  Writing HIER chunk, error #%d",
                                iff.error());
                        gfx_continu_line(buff);
                        goto error_exit;
                    }
                }

                // Output Extents/Face/Vert blocks
                if (iff.write(iff.makeid('E','X','N','T'),
                         &mextents,sizeof(EschFileMeshEXNT)))
                {
                    sprintf(buff,"ERROR:  Writing EXNT chunk, error #%d",
                            iff.error());
                    gfx_continu_line(buff);
                    goto error_exit;
                }
                if (iff.write(iff.makeid('V','E','R','T'),
                         everts,idata->item.m.verts * sizeof(EschVertex)))
                {
                    sprintf(buff,"ERROR:  Writing VERT chunk, error #%d",
                           iff.error());
                    gfx_continu_line(buff);
                    goto error_exit;
                }
                if (nmtls && iff.write(iff.makeid('M','T','L',' '),
                                      emtls,nmtls * sizeof(EschFileMeshMTL)))
                {
                    sprintf(buff,"ERROR:  Writing MTL chunk, error #%d",
                           iff.error());
                    gfx_continu_line(buff);
                    goto error_exit;
                }
                if (iff.write(iff.makeid('F','A','C','E'),
                         efaces,idata->item.m.faces * sizeof(EschFace)))
                {
                    sprintf(buff,"ERROR:  Writing FACE chunk, error #%d",
                           iff.error());
                    gfx_continu_line(buff);
                    goto error_exit;
                }

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Materials
                if (nmtls && material_mode == 2)
                {
                    char        pname[256];
                    BXPColor    *bm, *tbm;
                    EschFileMtlMHDR mtlhdr;

                    sprintf(buff,"Object '%s': Outputing materials...",idata->name);
                    gfx_set_gasgauge(buff,0,nmtls);

                    //ÄÄÄ Load palette, if not already loaded once
                    if (!pal)
                    {
                        pal = new VngoPal8;
                        if (!pal)
                        {
                            gfx_continu_line("Out of Memory!");
                            goto error_exit;
                        }

                        strcpy(pname,mtl_palpath);
                        if (mtl_palpath[strlen(mtl_palpath)-1] != '\\')
                            strcat(pname,"\\");
                        strcat(pname,mtl_palname);
                        
                        sprintf(buff,"Loading Van Gogh palette %s...",
                                pname);
                        gfx_prompt(buff);

                        if ((j=load_pal(pal,pname))!=0)
                        {
                            sprintf(buff,"ERROR:  Error %d loading palette",j);
                            gfx_continu_line(buff);
                            goto error_exit;
                        }
                    }

                    //ÄÄÄ Output each material
                    for(j=0; j < nmtls; j++)
                    {
                        gfx_set_gasgauge("",j,nmtls);

                        char *fname=&mtlfnames[14*2*j];
                        char *tfname=&mtlfnames[14*2*j+14];

                        char name[ESCH_MAX_NAME+1];
                        strncpy(name,emtls[j].name,ESCH_MAX_NAME);
                        name[ESCH_MAX_NAME] = 0;

                        if (*tfname)
                        {
                            sprintf(buff,"%s <= T1: %s, O: %s...",
                                    name,fname,tfname);
                        }
                        else
                        {
                            sprintf(buff,"%s <= T1: %s...",
                                    name,fname);
                        }
                        gfx_prompt(buff);

                        if (check_abort())
                            goto error_exit;

                        memset(&mtlhdr,0,sizeof(EschFileMtlMHDR));
                        strncpy(mtlhdr.name,emtls[j].name,ESCH_MAX_NAME);
                        strncpy(mtlhdr.pname,pal->name,16);

                        if (strstr(fname,".FLI") || strstr(fname,".FLC")
                            || strstr(tfname,".FLI") || strstr(tfname,".FLC"))
                        {
                            sprintf(buff,"%s: FLI/FLC not yet supported, skipped",
                                    name);
                            gfx_continu_line(buff);
                            goto error_exit;
                        }
                        else
                        {
                            //ÄÄÄ Handle single-frame Texture 1 (and optionally Opacity)
                            mtlhdr.type = 1;
                            mtlhdr.nframes = 1;
                            if ((bm=capture_mtlbitmap(fname,
                                                      &mtlhdr.xsize,
                                                      &mtlhdr.ysize,
                                                      0))==0)
                            {
                                sprintf(buff,"ERROR:  Error loading Texture 1 bitmap %s",fname);
                                gfx_continu_line(buff);
                                goto error_exit;
                            }
                            else
                            {
                                byte            *b;
                                VngoColor24bit  clr;

                                // Load Opacity
                                tbm=0;
                                if (*tfname)
                                {
                                    if ((tbm=capture_mtlbitmap(tfname,
                                                               &mtlhdr.xsize,
                                                               &mtlhdr.ysize,
                                                               1))==0)
                                    {
                                        sprintf(buff,"ERROR:  Error loading Opacity bitmap %s",tfname);
                                        gfx_continu_line(buff);
                                        goto error_exit;
                                    }
                                    else
                                    {
                                        mtlhdr.type = 2;
                                    }
                                }
                    
                                // Recolor with VnGo Palette
                                b = new byte[mtlhdr.xsize * mtlhdr.ysize];
                                if (b)
                                {
                                    for(k=0; k < mtlhdr.xsize * mtlhdr.ysize; k++)
                                    {
                                        if (tbm
                                            && tbm[k].r == 0
                                            && tbm[k].g == 0
                                            && tbm[k].b == 0)
                                        {
                                            b[k] = (byte)VNGO_TRANSPARENT_COLOR;
                                        }
                                        else
                                        {
                                            clr.r = bm[k].r;
                                            clr.g = bm[k].g;
                                            clr.b = bm[k].b;

                                            b[k] = (byte)pal->get_index(clr);
                                        }
                                    }

                                    if (iff.newform(iff.makeid('E','M','T','L')))
                                    {
                                        sprintf(buff,"ERROR:  Cannot create FORM, error #%d",
                                                iff.error());
                                        gfx_continu_line(buff);
                                        goto error_exit;     
                                    }

                                    // Output header
                                    if (iff.write(iff.makeid('M','H','D','R'),
                                                  &mtlhdr,sizeof(EschFileMtlMHDR)))
                                    {
                                        sprintf(buff,"ERROR:  Writing MHDR chunk, error #%d",
                                            iff.error());
                                        gfx_continu_line(buff);
                                        goto error_exit;     
                                    }

                                    // Output body
                                    if (iff.write(iff.makeid('B','O','D','Y'),
                                                  b,mtlhdr.xsize * mtlhdr.ysize))
                                    {
                                        sprintf(buff,"ERROR:  Writing BODY chunk, error #%d",
                                            iff.error());
                                        gfx_continu_line(buff);
                                        goto error_exit;     
                                    }

                                    iff.leaveform();

                                    delete [] b;
                                }
                                else
                                {
                                    sprintf("ERROR:  Converting bitmap %s, skipped",fname);
                                    gfx_continu_line(buff);
                                    goto error_exit;
                                }

                                free(bm);
                                if (tbm)
                                    free(tbm);
                            }
                        }
                    }
                }

                sprintf(buff,"Object '%s': Export Complete",idata->name);
                gfx_set_gasgauge(buff,1,1);

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Free efaces, everts, and emtls
                delete [] everts;
                delete [] efaces;
                delete [] emtls;
                delete [] mtlfnames;

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ End mesh form
                iff.leaveform();

                break;
        }
    }

    iff.leaveform();

//ÄÄ Close output file
    if (iff.close())
    {
        sprintf(buff,"ERROR:  Cannot close output file, error #%d",
                     iff.error());
        gfx_continu_line(buff);
    }

//ÄÄ Cleanup
error_exit:;

    if (pal)
        delete pal;

    capture_terminate();

    gfx_report("");

    gfx_put_hole();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// compute_box_extents                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void compute_box_extents( ItemData *idata,
                                 XVData *verts,
                                 EschFileMeshEXNT *mextents )
{
    int     i;
    float   cx, cy, cz;
    float   tx, ty, tz;
    float   xmin, ymin, zmin;
    float   xmax, ymax, zmax;

    xmin=ymin=zmin=FLT_MAX;
    xmax=ymax=zmax=-FLT_MAX;

    cx = idata->item.m.matrix[3][0];
    cy = idata->item.m.matrix[3][1];
    cz = idata->item.m.matrix[3][2];
            
    // Adjust center for pivot points, if any
    if (coord_mode == 1
        && capture_getpivot(idata, &tx, &ty, &tz))
    {
        cx += tx;
        cy += ty;
        cz += tz;
    }

    long nverts = idata->item.m.verts;
            
    for(i=0; i < nverts; i++)
    {
        tx = verts[i].x;
        ty = verts[i].y;
        tz = verts[i].z;
        
         // Handle adjustment to center, if not exporting world coords.
        if (coord_mode == 1)
        {
            tx -= cx;
            ty -= cy;
            tz -= cz;
        }
            
        if (tx < xmin)
        {
            xmin = tx;
        }
        if (tx > xmax)
        {
            xmax = tx;
        }
        if (ty < ymin)
        {
            ymin = ty;
        }
        if (ty > ymax)
        {
            ymax = ty;
        }
        if (tz < zmin)
        {
            zmin = tz;
        }
        if (tz > zmax)
        {
            zmax = tz;
        }
    }

//ÄÄÄ Convert result to mextent structure
    mextents->minx = (Flx16) (xmin * scale_3ds2esch);
    mextents->miny = (Flx16) (zmin * scale_3ds2esch);
    mextents->minz = (Flx16) (ymin * scale_3ds2esch);
    mextents->maxx = (Flx16) (xmax * scale_3ds2esch);
    mextents->maxy = (Flx16) (zmax * scale_3ds2esch);
    mextents->maxz = (Flx16) (ymax * scale_3ds2esch);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// compute_quick_extents                                                    ³
//                                                                          ³
// Borrowed from Graphics Gems I, "An Efficient Bounding Sphere"            ³
//                                                                          ³
// Assumes at least two vertices                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC void compute_quick_extents(  ItemData *idata,
                                    XVData *verts,
                                    EschFileMeshEXNT *mextents)
{
    int i;
    XVData *v;
    double  dx, dy, dz;
    double rad, rad_sq;
    double xspan, yspan, zspan, maxspan;
    double old_to_p, old_to_p_sq, old_to_new;
    struct FloatPoint   xmin, xmax, 
                        ymin, ymax,
                        zmin, zmax,
                        dia1, dia2,
                        cen;

    xmin.x=ymin.x=zmin.x=FLT_MAX;
    xmin.y=ymin.y=zmin.y=FLT_MAX;
    xmin.z=ymin.z=zmin.z=FLT_MAX;

    xmax.x=ymax.x=zmax.x=-FLT_MAX;
    xmax.y=ymax.y=zmax.y=-FLT_MAX;
    xmax.z=ymax.z=zmax.z=-FLT_MAX;

    long nverts = idata->item.m.verts;

//ÄÄÄ Pass 1
    gfx_set_gasgauge("",0,2);

    for(i=0; i < nverts; i++)
    {
        v=&verts[i];    

        if (v->x < xmin.x)
        {
            xmin.x = v->x;
            xmin.y = v->z;
            xmin.z = v->y;
        }
        if (v->x > xmax.x)
        {
            xmax.x = v->x;
            xmax.y = v->z;
            xmax.z = v->y;
        }

        if (v->z < ymin.y)
        {
            ymin.x = v->x;
            ymin.y = v->z;
            ymin.z = v->y;
        }
        if (v->z > ymax.y)
        {
            ymax.x = v->x;
            ymax.y = v->z;
            ymax.z = v->y;
        }
        
        if (v->y < zmin.z)
        {
            zmin.x = v->x;
            zmin.y = v->z;
            zmin.z = v->y;
        }
        if (v->y > zmax.z)
        {
            zmax.x = v->x;
            zmax.y = v->z;
            zmax.z = v->y;
        }

    }

    // Set Spans as distance between min & max points (square)
    dx = xmax.x - xmin.x;
    dy = xmax.y - xmin.y;
    dz = xmax.z - xmin.z;
    xspan = dx*dx + dy*dy + dz*dz;

    dx = ymax.x - ymin.x;
    dy = ymax.y - ymin.y;
    dz = ymax.z - ymin.z;
    yspan = dx*dx + dy*dy + dz*dz;

    dx = zmax.x - zmin.x;
    dy = zmax.y - zmin.y;
    dz = zmax.z - zmin.z;
    zspan = dx*dx + dy*dy + dz*dz;

    // Set dia1 & dia2 to maximally seperate pair

    dia1 = xmin; dia2 = xmax;
    maxspan = xspan;
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
    cen.x = (dia1.x + dia2.x) / 2.0;
    cen.y = (dia1.y + dia2.y) / 2.0;
    cen.z = (dia1.z + dia2.z) / 2.0;

    dx = dia2.x - cen.x;
    dy = dia2.y - cen.y;
    dz = dia2.z - cen.z;
    rad_sq = dx*dx + dy*dy + dz*dz;
    rad = sqrt(rad_sq);

//ÄÄÄ Pass 2
    gfx_set_gasgauge("",1,2);

    for(i=0; i < idata->item.m.verts; i++)
    {
        v=&verts[i];    

        dx = v->x - cen.x;
        dy = v->z - cen.y;
        dz = v->y - cen.z;

        old_to_p_sq = dx*dx + dy*dy + dz*dz;

        // See if out of sphere
        if (old_to_p_sq > rad_sq)
        {
            old_to_p = sqrt(old_to_p_sq);

            // Calc new radius
            rad = (rad + old_to_p) / 2.0;
            rad_sq = rad*rad;
            old_to_new = old_to_p - rad;

            // Calc new center
            cen.x = (rad*cen.x + old_to_new*v->x) / old_to_p;
            cen.y = (rad*cen.y + old_to_new*v->z) / old_to_p;
            cen.z = (rad*cen.z + old_to_new*v->y) / old_to_p;
        }

    }

    // Adjust center to local coords if not doing world coords export
    if (coord_mode == 1)
    {
        float cx, cy, cz;
        float tx, ty, tz;

        cx = idata->item.m.matrix[3][0];
        cy = idata->item.m.matrix[3][1];
        cz = idata->item.m.matrix[3][2];
            
        // Adjust center for pivot points, if any
        if (capture_getpivot(idata, &tx, &ty, &tz))
        {
            cx += tx;
            cy += ty;
            cz += tz;
        }

        cen.x -= cx;
        cen.y -= cz;
        cen.z -= cy;
    }
   
//ÄÄÄ Convert result to mextent structure
    mextents->cenx = (Flx16) (cen.x * scale_3ds2esch);
    mextents->ceny = (Flx16) (cen.y * scale_3ds2esch);
    mextents->cenz = (Flx16) (cen.z * scale_3ds2esch);
    mextents->extent_radius = (Flx16) (rad * scale_3ds2esch);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// compute_optimal_extents                                                  ³
//                                                                          ³
// Brute-force computation of optimal extents (essentially a "Bubblesort")  ³
//                                                                          ³
// Assumes at least two vertices                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC int compute_optimal_extents(  ItemData *idata,
                                      XVData *verts,
                                      EschFileMeshEXNT *mextents)
{
    int                 i, j;
    XVData              *v, *v2;
    double              dx, dy, dz;
    double              dist_sq, max_sq;
    struct FloatPoint   dia1, dia2,
                        cen;

    max_sq=-FLT_MAX;

    long nverts = idata->item.m.verts;

//ÄÄÄ Loop through all looking for maximal distance
    for(i=0; i < nverts; i++)
    {
        if (check_abort())
            return 1;

        gfx_set_gasgauge("",i,nverts);
        v=&verts[i];    

        for(j=i+1; j < nverts; j++)
        {
            v2=&verts[j];

            dx = v->x - v2->x;
            dy = v->z - v2->z;
            dz = v->y - v2->y;
            dist_sq = dx*dx + dy*dy + dz*dz;

            if (dist_sq > max_sq)
            {
                max_sq = dist_sq;

                dia1.x = v->x;
                dia1.y = v->z;
                dia1.z = v->y;

                dia2.x = v2->x;
                dia2.y = v2->z;
                dia2.z = v2->y;
            }

        }
    }

    gfx_set_gasgauge("",1,1);

    // Compute values
    cen.x = (dia1.x + dia2.x) / 2.0;
    cen.y = (dia1.y + dia2.y) / 2.0;
    cen.z = (dia1.z + dia2.z) / 2.0;

    // Adjust center to local coords if not doing world coords export
    if (coord_mode == 1)
    {
        float cx, cy, cz;
        float tx, ty, tz;

        cx = idata->item.m.matrix[3][0];
        cy = idata->item.m.matrix[3][1];
        cz = idata->item.m.matrix[3][2];
        
        // Adjust center for pivot points, if any
        if (capture_getpivot(idata, &tx, &ty, &tz))
        {
            cx += tx;
            cy += ty;
            cz += tz;
        }

        cen.x -= cx;
        cen.y -= cz;
        cen.z -= cy;
    }
   
//ÄÄÄ Convert result to mextent structure
    mextents->cenx = (Flx16) (cen.x * scale_3ds2esch);
    mextents->ceny = (Flx16) (cen.y * scale_3ds2esch);
    mextents->cenz = (Flx16) (cen.z * scale_3ds2esch);
    mextents->extent_radius = (Flx16) ((sqrt(max_sq) / 2.0) * scale_3ds2esch);

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// load_pal                                                                 ³
//                                                                          ³
//     Palette loader...                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC int load_pal(VngoPal *pal,char *infile)
{
    int err;
   
    err=pal->init(0,infile);
   
    return(err);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// check_abort                                                              ³
//                                                                          ³
// Checks to see if ESC was pressed and "Abort Export" answered yes         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC int check_abort()
{
    int status;

    gfx_key_hit(status);
    if (status)
    {
        gfx_get_key(status);
        if (status==ESC)
        {
            gfx_yes_no_line("Abort export?", status);
            if (status)
                return 1;
        }
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Empty ivory functions                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
#pragma off(unreferenced);

IvoryArena *ivory_arena_initialize (IvoryArena *arena, size_t arena_size)
{
    return 0;
}

void ivory_arena_clear (IvoryArena *arena)
{
}

void *ivory_arena_zalloc (IvoryArena *arena, size_t size)
{
    return 0;
}

void *ivory_alloc (size_t size)
{
    return malloc(size);
}

void ivory_free (void **ptr)
{
    free(*ptr);
    *ptr=0;
}

IvoryHandle ivory_halloc (size_t size)
{
    return (IvoryHandle)malloc(size);
}

void ivory_hfree (IvoryHandle *ptr)
{
    free((void*)*ptr);
    *ptr=0;
}

void *ivory_hlock (IvoryHandle ptr)
{
    return (void *)ptr;
}

void ivory_hunlock (IvoryHandle ptr)
{
}

//°±² End of module - export.cpp ²±°

