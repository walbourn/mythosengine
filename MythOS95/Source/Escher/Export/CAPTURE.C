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
// capture.c
//
// Contains the code for capturing data from 3D Studio.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <io.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include <i86.h>
#include <float.h>
#include <ctype.h>

#include "portable.h"
#include "debug.h"

#include "xfio.h"

#include <pjbasics.h>

#include "exprtn.h"
#include "pxp.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define NMAPTYPES   8

#define NTEX1       0
#define NTEX2       1
#define NOPAC       2
#define NBUMP       3
#define NSPEC       4
#define NSHIN       5
#define NSELFI      6
#define NRELF       7

typedef struct {
        uchar       type;
        ushort      texflags;
        void        *sxp_data;
        void        *bm;
        float       texblur;
        float       uscale, vscale;
        float       uoffset, voffset;
        float       ang_sin, ang_cos;
        Color_24    col1, col2;
        Color_24    rcol, gcol, bcol;
} MapParams;

typedef struct {
        uchar       ok;
        uchar       kind;
        char        name[13];
        MapParams   tex;
} MapData;

typedef struct {
        uchar                       use;
        union { float f; int pct; } amt;
        MapData                     map;
        MapData                     mask;
} Mapping;

typedef struct mtl
{
    char name[17];      /* Material's 16-char name */
    BXPColor amb;       /* 0-255 triplets */
    BXPColor diff;      /* 0-255 triplets */
    BXPColor spec;      /* 0-255 triplets */
    short transparency; /* 0-100 */
    short shading;      /* 0=WIRE 1=FLAT 2=GOURAUD 3=PHONG 4=METAL */
    unsigned long flags; /* Material flags */
    unsigned short use; /* Use flags */
    short shininess;    /* 0-100 */
    short shin2pct;     /* 0-100 */
    short shin3pct;     /* 0-100 - Not Used  */
    short xpfall;       /* 0-100 */
    short refblur;      /* 0-100 */
    short selfipct;     /* 0-100 */
    float wiresize;     /* size of wire frame */

    Mapping *map[NMAPTYPES];
    void *appdata;
} Mtl;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

int inverse_mtx(float *m, float *inv);
void concat_mtx(float *ina, float *b, float *res);

void do_query(char *image, int orgxsize, int orgysize, int orgframes);

char *locate_map(char *fname, char *fullname);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern int source_mode;
extern int coord_mode;
extern int extent_mode;
extern int material_mode;
extern int hierarchy_mode;

extern int cameras_flag;
extern int lights_flag;

extern int mtl_sizemode;                    // 1=just to power of 2,
                                            // 2=force to mtl_sizex/y
                                            // 3=query for size
extern int mtl_sizex;
extern int mtl_sizey;

extern int query_xsize;                     // Query dialog
extern int query_ysize;

int count_camera=0;
int count_vectlights=0;
int count_fpointlights=0;
int count_fattenlights=0;
int count_fspotlights=0;
int count_pointlights=0;
int count_attenlights=0;
int count_spotlights=0;
int count_objects=0;

STATIC int         capture_numb=0;
STATIC int         capture_cur=0;

STATIC ItemData    *capture_idata=NULL;

STATIC struct MtlCapture
{
    MtlData     mtl;
    Mtl _far    *ptr;
} *capture_mtl=NULL;

// Light export information

extern int lgt_omnias;
extern int lgt_spotas;
extern int lgt_ambient;
extern int lgt_atten;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// capture_setup                                                            ³
//                                                                          ³
// This sets up to perform capture operations.  Returns 0 if ok, non-zero   ³
// for error conditions.                                                    ³
// 0=ok, 1=no objects to capture, 2=error during capture                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int capture_setup()
{
    int         i;
    int         status;
    int         count;
    ItemData    idata;

    kxp_init_keyframer();

//ÄÄ Get object information
    pxp_get_item_count(count);

    if (source_mode == 3)
        return 3;

    // Always have an ambient light in the system
    if (count <= 1)
        return 1;

    count_camera=0;
    count_vectlights=0;
    count_fpointlights=0;
    count_fattenlights=0;
    count_fspotlights=0;
    count_pointlights=0;
    count_attenlights=0;
    count_spotlights=0;
    count_objects=0;

//ÄÄ Count numbers of desired tri-mesh objects
    for(i=0, capture_numb=0; i < count; i++)
    {
        pxp_get_item(i,&idata,status);
        if (!status)
            return 2;
        switch (idata.type)
        {
            case PXPCAMERA:
                if (cameras_flag)
                {
                    capture_numb++;
                    count_camera++;
                }
                break;

            case PXPAMBIENT:
                if (lights_flag)
                {
                    capture_numb++;
                }
                break;

            case PXPLIGHT:
                if (lights_flag)
                {
                    capture_numb++;
                    if (idata.item.l.hotsize != 360.0
                        || idata.item.l.fallsize != 360.0 )
                    {
                        if (lgt_spotas == 3)
                            count_vectlights++;
                        else if (lgt_spotas == 2)
                            count_spotlights++;
                        else
                            count_fspotlights++;
                    }
                    else
                    {
                        if (lgt_atten
                            && idata.item.l.flags & LIGHT_ATTEN)
                        {
                            if (lgt_omnias == 2)
                                count_attenlights++;
                            else
                                count_fattenlights++;
                        }
                        else
                        {
                            if (lgt_omnias == 2)
                                count_pointlights++;
                            else // lgt_omnias == 1
                               count_fpointlights++;
                        }
                    }
                }
                break;

            case PXPMESH:
                if ((idata.item.m.flags & MESH_HIDDEN)
                   || (source_mode==2
                       && !(idata.item.m.flags & MESH_SELECTED)))
                {
                    break;
                }
                count_objects++;
                capture_numb++;
                break;
        }
    }

    if (!capture_numb)
        return 1;

//ÄÄ Get ItemData for valid objects
    if (capture_idata)
    {
        free(capture_idata);
        capture_idata=NULL;
    }

    capture_idata = malloc(capture_numb * sizeof(ItemData));
    if (!capture_idata)
        return 2;

    for(i=0, capture_numb=0; i < count; i++)
    {
        pxp_get_item(i,&idata,status);
        if (status)
        {
            switch (idata.type)
            {
                case PXPCAMERA:
                    if (cameras_flag)
                    {
                        memcpy(&capture_idata[capture_numb++],&idata,sizeof(ItemData));
                    }
                    break;

                case PXPAMBIENT:
                    if (lights_flag)
                    {
                        memcpy(&capture_idata[capture_numb++],&idata,sizeof(ItemData));
                    }
                    break;

                case PXPLIGHT:
                    if (lights_flag)
                    {
                        memcpy(&capture_idata[capture_numb++],&idata,sizeof(ItemData));
                    }
                    break;

                case PXPMESH:
                    if ((idata.item.m.flags & MESH_HIDDEN)
                        || (source_mode==2
                           && !(idata.item.m.flags & MESH_SELECTED)))
                    {
                        break;
                    }

                    memcpy(&capture_idata[capture_numb++],&idata,sizeof(ItemData));
                    break;
            }
        }
    }

    capture_cur=0;

//ÄÄ Get Material data
    if (capture_mtl)
    {
        free(capture_mtl);
        capture_mtl=NULL;
    }

    capture_mtl = malloc(256 * sizeof(struct MtlCapture));
    if (!capture_mtl)
        return 2;

    memset(capture_mtl,0,256 * sizeof(struct MtlCapture));

    pxp_material_count(count);

    for(i=0; i < count; i++)
    {
        pxp_get_material(i,&capture_mtl[i].mtl,status);
        capture_mtl[i].ptr = (Mtl _far *)PC->ptr1;
    }

    strcpy(capture_mtl[255].mtl.name,"default");
    capture_mtl[255].mtl.diff.r=128;
    capture_mtl[255].mtl.diff.g=128;
    capture_mtl[255].mtl.diff.b=128;
    capture_mtl[255].mtl.shading=4;

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// capture_get                                                              ³
//                                                                          ³
// Downloads data for the current data object, then increments the data     ³
// object index.  Returns 0 for ok, non-zero for error.  verts & faces is   ³
// unaffected for PXPLIGHT, PXPCAMERA, and PXPAMBIENT objects.              ³
// 0=ok, 1=no more, 2=error during download.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void set_to_NaN(float *a)
{
    *a = FLT_MAX;
}

int is_NaN(float a)
{
    return ((a == FLT_MAX) ? 1 : 0);
}

int capture_get(ItemData **item, XVData **verts, XFData **faces)
{
    int     status;
    int     nverts;
    int     nfaces;

    *verts = 0;
    *faces = 0;

    if (capture_cur >= capture_numb)
        return 1;

    *item = &capture_idata[capture_cur++];

    if ((*item)->type != PXPMESH)
        return 0;

    nverts = (*item)->item.m.verts;
    nfaces = (*item)->item.m.faces;

    *verts = malloc(nverts * sizeof(XVData));
    if (!*verts)
        goto error_exit;

    *faces = malloc(nfaces * sizeof(XFData));
    if (!*faces)
        goto error_exit;

    pxp_get_verts((*item)->name, 0, nverts, *verts, status);

    if (!status)
        goto error_exit;

    pxp_get_faces((*item)->name, 0, nfaces, *faces, status);

    if (!status)
        goto error_exit;

    return 0;

error_exit :;
    if (*verts)
    {
        free (*verts);
        *verts=0;
    }
    if (*faces)
    {
        free (*faces);
        *faces=0;
    }

    return 2;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// capture_getpivot                                                         ³
//                                                                          ³
// Returns the pivot point, if there is one defined or 0 if no pivot.       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int capture_getpivot(ItemData *idata, float *px, float *py, float *pz)
{
    int     i, t;
    Pivot   p;
    float   mtx[4][3];

//ÄÄÄ Get node ID for object
    kxp_get_node_number(idata->name,i,t);

    if (t != OBJECT_NODE)
        return 0;

//ÄÄÄ Get pivot for ID
    kxp_get_pivot(i, p, t);
    if (t < 0)
        return 0;

//ÄÄÄ Return values
    *px = p.x;
    *py = p.y;
    *pz = p.z;

//ÄÄÄ Convert to world coords (no translation)
//
//                0 1 2
//
//             0 [A B C 0]   [ Ai+Dj+Gk ]   [ 0,0*x + 1,0*y + 2,0*z ]
// [x y z 1] * 1 [D E F 0] = [ Bi+Ej+Hk ] = [ 0,1*x + 1,1*y + 2,1*z ]
//             2 [G H I 0]   [ Ci+Fj+Ik ]   [ 0,2*x + 1,2*y + 2,2*z ]
//             3 [0 0 0 1]   [      1   ]   [          1            ]
//
    kxp_get_xform(i, 0, mtx);

    *px = mtx[0][0]*p.x
          + mtx[1][0]*p.y
          + mtx[2][0]*p.z;

    *py = mtx[0][1]*p.x
          + mtx[1][1]*p.y
          + mtx[2][1]*p.z;

    *pz = mtx[0][2]*p.x
          + mtx[1][2]*p.y
          + mtx[2][2]*p.z;

    return 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// capture_gethier                                                          ³
//                                                                          ³
// Returns information on parent of object in hiearchy, if any.             ³
// If desired, the orientation matrix for the object, relative to the       ³
// hierarchy, may be returned in 'm'.                                       ³
// 0 if no parent.                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int capture_gethier(ItemData *idata, char *name, float *m)
{
    int     i, t;
    float   tx, ty, tz;
    float   pm[4][3];
    float   mtx[4][3];

//ÄÄÄ Get node ID for object
    kxp_get_node_number(idata->name,i,t);

    if (t != OBJECT_NODE)
        return 0;

    memcpy(mtx,idata->item.m.matrix,12*sizeof(float));
    mtx[0][0] = 1.0;                    // Already captured in get_verts, but
    mtx[0][1] = 0.0;                    // Needs to be I for computation to
    mtx[0][2] = 0.0;                    // work below
    mtx[1][0] = 0.0;
    mtx[1][1] = 1.0;
    mtx[1][2] = 0.0;
    mtx[2][0] = 0.0;
    mtx[2][1] = 0.0;
    mtx[2][2] = 1.0;

    if (coord_mode == 1
        && capture_getpivot(idata, &tx, &ty, &tz))
    {
        mtx[3][0] += tx;
        mtx[3][1] += ty;
        mtx[3][2] += tz;
    }

//ÄÄÄ Get node ID for parent of object
    kxp_get_parent(i,t);

    if (t <= -1)
    {
        if (m)
        {
            memcpy(m,mtx,sizeof(float)*12);
        }
        return 0;
    }

    kxp_get_node_name(t,name,t);

    if (t != OBJECT_NODE)
    {
        if (m)
        {
            memcpy(m,mtx,sizeof(float)*12);
        }
        return 0;
    }

//ÄÄÄ Get parent matrix
    for(i=0; i < capture_numb; i++)
    {
        if (capture_idata[i].type == PXPMESH
            && !strcmp(name,capture_idata[i].name))
        {
            memcpy(pm,capture_idata[i].item.m.matrix,12*sizeof(float));
            pm[0][0] = 1.0;                 // Already captured in get_verts, but
            pm[0][1] = 0.0;                 // Needs to be I for computation to
            pm[0][2] = 0.0;                 // work below
            pm[1][0] = 0.0;
            pm[1][1] = 1.0;
            pm[1][2] = 0.0;
            pm[2][0] = 0.0;
            pm[2][1] = 0.0;
            pm[2][2] = 1.0;

            if (coord_mode == 1
                && capture_getpivot(&capture_idata[i], &tx, &ty, &tz))
            {
                pm[3][0] += tx;
                pm[3][1] += ty;
                pm[3][2] += tz;
            }
            break;
        }
    }
    if (i >= capture_numb)
    {
        if (m)
        {
            memcpy(m,mtx,sizeof(float)*12);
        }
        return 0;
    }

//ÄÄÄ Need to compute relative transform from objects' and parent's
//ÄÄÄ xform, if requested
    if (m)
    {
        // O(R->P) = O(R->W) * Pi(W->P)

        inverse_mtx(pm,pm);
        concat_mtx(mtx,pm,m);
    }

    return 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// capture_mtlget                                                           ³
//                                                                          ³
// Returns information on materials captureb before.                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
MtlData *capture_mtlget(int ind, short *selfi, short *transp)
{
    if (!capture_mtl || ind < 0 || ind >= 255)
        return NULL;

    if (selfi)
        *selfi = capture_mtl[ind].ptr->selfipct;

    if (transp)
        *transp = capture_mtl[ind].ptr->transparency;

    return &capture_mtl[ind].mtl;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// capture_mtlfile                                                          ³
//                                                                          ³
// Returns the texture1 name, if any, associated with the material.         ³
// The opacity name is also returned if set.                                ³
// The int result is 0 if no map exists, 1 if ok, greater if has unknown    ³
// maps.                                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int capture_mtlfile(int ind, char *fname, char *tfname)
{
    int             i;
    int             ret=0;
    Mapping _far    *map;

    if (!capture_mtl || ind < 0 || ind >= 255)
        return 0;

    if (fname)
        *fname=0;
    if (tfname)
        *tfname=0;

//ÄÄ Use material's backdoor...
    if (capture_mtl[ind].ptr)
    {
        //ÄÄ See if there is a Texture1 defined and set it.
        if (capture_mtl[ind].ptr->map[NTEX1])
        {
            map = MK_FP( FP_SEG(capture_mtl[ind].ptr), capture_mtl[ind].ptr->map[NTEX1]);
            if (map && map->use)
            {
                ret=1;
                if (fname)
                {
                    fnstrcpy(fname,map->map.name);
                    strupr(fname);
                }
            }
        }

        //ÄÄ See if there is a Opacity defined and set it.
        if (tfname && capture_mtl[ind].ptr->map[NOPAC])
        {
            map = MK_FP( FP_SEG(capture_mtl[ind].ptr), capture_mtl[ind].ptr->map[NOPAC]);
            if (map && map->use)
            {
                if (tfname)
                {
                    fnstrcpy(tfname,map->map.name);
                    strupr(tfname);
                }
            }
        }

        //ÄÄ Check to see if other maps are in use for material.
        for(i=0; i < NMAPTYPES; i++)
        {
            if (i == NTEX1 || i == NOPAC)
                    continue;

            if (capture_mtl[ind].ptr->map[i])
            {
                map = MK_FP( FP_SEG(capture_mtl[ind].ptr), capture_mtl[ind].ptr->map[i]);

                if (map && map->use)
                {
                    ret=2;
                    break;
                }
            }
        }
    }

    return ret;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// locate_map                                                               ³
//                                                                          ³
// Attempts to locate a map file.                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
char *locate_map(char *fname, char *fullname)
{
    int     i;
    char    path[256];

    if (!fname || !fullname)
        return 0;

    // Search map paths
    for(i=0; i < 250; i++)
    {
        gfx_get_paths(GFX_MAP_PATH,i,path,fullname);
        if (!*path)
            continue;

        strcpy(fullname,path);
        strcat(fullname,"\\");
        strcat(fullname,fname);

        if (access(fullname,0) == 0)
            return fullname;
    }

    // Search image path
    gfx_get_paths(GFX_IMG_PATH,0,path,fullname);
    strcpy(fullname,path);
    strcat(fullname,"\\");
    strcat(fullname,fname);

    if (access(fullname,0) == 0)
        return fullname;

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// get_root_from_fullname                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
char *get_root_from_fullname(char *fullname)
{
    char *c;

    // Find first lead character in fullname
    for(c = fullname + strlen(fullname) - 1; c > fullname; c--)
    {
        if (*c == '\\')
        {
            c++;
            break;
        }
    }

    return c;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// isvalid_sequential_name                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC int isvalid_sequential_name(char *fname, char *fullname)
{
    char *c, *t;
    
    c = get_root_from_fullname(fullname);
    if (!*c)
        return 0;

    // Compare with root name until we hit the '*' symbol
    for(t = fname; *t != 0; t++, c++)
    {
        if (*t == '*')
            break;

        if (*t != *c)
            return 0;
    }

    if (!isdigit(*c))
        return 0;

    // Verify all remaining characters until '.' or end are numbers
    for(; *c != 0; c++)
    {
        if (*c == '.')
            return 1;

        if (!isdigit(*c))
            return 0;
    }
    
    return 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// locate_sequential_maps                                                   ³
//                                                                          ³
// Attempts to locate and sort sequential maps.                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ulong locate_sequential_maps(char *fname, char **seq_names)
{
    int                 i, status;
    int                 changed;
    char                *c, *t;
    int                 value1, value2;
    ulong               count;
    struct find_t       find;
    char                path[256];
    char                full[256];

    if (!fname || !seq_names)
        return 0;

//ÄÄÄ Search for files that match mask and are of correct numbering format

    // Search map paths
    for(i=0; i < 250; i++)
    {
        gfx_get_paths(GFX_MAP_PATH,i,path,full);
        if (!*path)
            continue;

        strcpy(full,path);
        strcat(full,"\\");
        strcat(full,fname);

        gfx_findfirst(full,0,&find,status);
        if (!status)
        {
            if (isvalid_sequential_name(fname,find.name))
                goto found;

            for(;;)
            {
                gfx_findnext(&find,status);
                if (status)
                    break;

                if (isvalid_sequential_name(fname,find.name))
                    goto found;
            }
        }
    }

    // Search image path
    gfx_get_paths(GFX_IMG_PATH,0,path,full);
    strcpy(full,path);
    strcat(full,"\\");
    strcat(full,fname);

    gfx_findfirst(full,0,&find,status);
    if (status)
        return 0;

    if (isvalid_sequential_name(fname,find.name))
        goto found;

    for(;;)
    {
        gfx_findnext(&find,status);
        if (status)
            break;

        if (isvalid_sequential_name(fname,find.name))
            goto found;
    }

    return 0;

//ÄÄÄ Load names and attempt to sort
found:; 

    // Count number of matches
    count=1;

    for(;;)
    {
        gfx_findnext(&find,status);
        if (status)
            break;

        if (isvalid_sequential_name(fname,find.name))
            count++;
    }

    // Store all matches
    gfx_findfirst(full,0,&find,status);
    if (status)
        return 0;

    *seq_names = malloc(256*count);
    if (!*seq_names)
        return 0;
    memset(*seq_names,0,256*count);

    if (isvalid_sequential_name(fname,find.name))
    {
        strcpy(full,path);
        strcat(full,"\\");
        strcat(full,find.name);
        strncpy(*seq_names,full,255);
        count=1;
    }
    else
    {
        count = 0;
    }

    for(;;)
    {
        gfx_findnext(&find,status);
        if (status)
            break;

        if (isvalid_sequential_name(fname,find.name))
        {
            strcpy(full,path);
            strcat(full,"\\");
            strcat(full,find.name);
            strncpy(&(*seq_names)[256*count],full,255);
            count++;
        }
    }

    // Sort names to get frame sequence (Bubblesort)
    for(;;)
    {
        changed=0;
        for(i=0; i < count-1; i++)
        {
            // Get value 1
            c = get_root_from_fullname(&(*seq_names)[256*i]);
            for(t = fname; *t != 0; t++, c++)
            {
                if (*t == '*')
                    break;
            }
            value1 = atoi(c);

            // Get value 2
            c = get_root_from_fullname(&(*seq_names)[256*(i+1)]);
            for(t = fname; *t != 0; t++, c++)
            {
                if (*t == '*')
                    break;
            }
            value2 = atoi(c);

            // Compare and swap if needed
            if (value2 < value1)
            {
                char temp[256];
                strncpy(temp,&(*seq_names)[256*i],255);
                strncpy(&(*seq_names)[256*i],
                        &(*seq_names)[256*(i+1)], 255);
                strncpy(&(*seq_names)[256*(i+1)],temp,255);
                changed=1;
            }
        }
        if (!changed)
            break;
    }

    return count;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// capture_mtlbitmap                                                        ³
//                                                                          ³
// Attempts to locate and load the map bitmap file given.                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BXPColor *capture_mtlbitmap(char *fname, int locate, ushort *xs, ushort *ys, int forcesize)
{
    int         i;
    int         desirex;
    int         desirey;
    BXPColor    *bm;
    BXPColor    *tbm;
    BitmapInfo  binfo;
    char        fullname[256];

    if (!locate)
        strcpy(fullname,fname);
    else if (!locate_map(fname,fullname))
        return NULL;

//ÄÄÄ Load image
    gfx_bitmap_info(fullname,&binfo, i);
    if (i != 1)
        return NULL;

    if ((bm=malloc(binfo.width * binfo.height * sizeof(BXPColor)))==0)
        return NULL;

    gfx_load_bitmap(fullname, binfo.width, binfo.height, bm, i);

    if (i < 1)
    {
        free(bm);
        return NULL;
    }

//ÄÄÄ Check for resize
    if (forcesize)
    {
        desirex = *xs;
        desirey = *ys;
    }
    else if (mtl_sizemode == 3)
    {
        do_query(fname,binfo.width,binfo.height,1);

        desirex = query_xsize;
        desirey = query_ysize;
    }
    else if (mtl_sizemode == 2)
    {
        desirex = mtl_sizex;
        desirey = mtl_sizey;
    }
    else
    {

        // Must set size to 16, 32, 64, 128, or 256
        desirex=16;
        desirey=16;

        if (binfo.width > desirex)
            desirex=32;
        if (binfo.height > desirey)
            desirey=32;

        if (binfo.width > desirex)
            desirex=64;
        if (binfo.height > desirey)
            desirey=64;

        if (binfo.width > desirex)
            desirex=128;
        if (binfo.height > desirey)
            desirey=128;

        if (binfo.width > desirex)
            desirex=256;
        if (binfo.height > desirey)
            desirey=256;
    }

//ÄÄÄ Perform resize
    if (desirex != binfo.width
        || desirey != binfo.height)
    {
        tbm = bm;

        if ((bm = malloc(desirex * desirey * sizeof(BXPColor)))==0)
        {
            free(tbm);
            return 0;
        }

        gfx_resize_bitmap(tbm, binfo.width, binfo.height,
                          bm, desirex, desirey, i);

        free(tbm);

        if (i < 1)
        {
            free(bm);
            return 0;
        }
    }

//ÄÄÄ Return final image
    *xs = desirex;
    *ys = desirey;

    return bm;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// capture_flcframe                                                         ³
//                                                                          ³
// Loads the next frame in the flic as a bitmap.                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BXPColor *capture_flcframe(char *fname, Flic *flic,
                           FlicRaster *raster, byte *pix,
                           ushort *xs, ushort *ys, int forcesize)
{
    int         i;
    int         desirex;
    int         desirey;
    BXPColor    *bm=0;

//ÄÄÄ Load frame
    pj_flic_play_next(flic,raster);

//ÄÄÄ Expand into RGB bitmap buffer
    bm=malloc(raster->width * raster->height * sizeof(BXPColor));
    if (!bm)
        goto error_exit;

    {
        BXPColor *dptr=bm;
        byte *sptr=pix;
        PjRgb *rgb = &raster->cmap->ctab;
        for(i=0; i < raster->width*raster->height; i++)
        {
            dptr->r = rgb[*sptr].r;
            dptr->g = rgb[*sptr].g;
            dptr->b = rgb[*sptr].b;
            dptr++;
            sptr++;
        }
    }

//ÄÄÄ Check for resize
    if (forcesize)
    {
        desirex = *xs;
        desirey = *ys;
    }
    else if (mtl_sizemode == 3)
    {
        AnimInfo info;
        pj_flic_info(flic,&info);

        do_query(fname,info.width,info.height,info.num_frames);

        desirex = query_xsize;
        desirey = query_ysize;
    }
    else if (mtl_sizemode == 2)
    {
        desirex = mtl_sizex;
        desirey = mtl_sizey;
    }
    else
    {
        // Must set size to 16, 32, 64, 128, or 256
        desirex=16;
        desirey=16;

        if (raster->width > desirex)
            desirex=32;
        if (raster->height > desirey)
            desirey=32;

        if (raster->width > desirex)
            desirex=64;
        if (raster->height > desirey)
            desirey=64;

        if (raster->width > desirex)
            desirex=128;
        if (raster->height > desirey)
            desirey=128;

        if (raster->width > desirex)
            desirex=256;
        if (raster->height > desirey)
            desirey=256;
    }

//ÄÄÄ Perform resize
    if (desirex != raster->width
        || desirey != raster->height)
    {
        BXPColor *tbm = bm;

        if ((bm = malloc(desirex * desirey * sizeof(BXPColor)))==0)
        {
            free(tbm);
            goto error_exit;
        }

        gfx_resize_bitmap(tbm, raster->width, raster->height,
                          bm, desirex, desirey, i);

        free(tbm);

        if (i < 1)
        {
            goto error_exit;
        }
    }

//ÄÄÄ Return final image
    *xs = desirex;
    *ys = desirey;

    return bm;

error_exit:;
    if (bm)
        free(bm);

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// capture_terminate                                                        ³
//                                                                          ³
// Terminates capture process by freeing any allocated memory.              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void capture_terminate()
{
    if (capture_idata)
    {
        free(capture_idata);
        capture_idata=NULL;
    }

    if (capture_mtl)
    {
        free(capture_mtl);
        capture_mtl=NULL;
    }

    capture_numb=0;
}

//°±² End of module - capture.c ²±°

