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
//                 http://www.charybdis.com/products/mythos.html
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

#define __VNGVPDD8_HPP 1
#define __VNGSCRN_HPP  1
#define __ESTERRAN_HPP    1
#define __VNGTXTR_HPP 1
#define __ESCH_EXPORT 1

#define assert(a)

#include <float.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "xfbitmap.hpp"
#include "xfiff.hpp"

#include "felix.hpp"

#include <vngdefs.h>
#include <vngpal.hpp>
#include <vngstrct.hpp>

#include <esdefs.h>
#include <esmath.hpp>
#include <esgeom.hpp>
#include <esfile.hpp>

extern "C"
{
#include <pjbasics.h>

#include "pxp.h"
#include "keys.h"
}

#include "estoken.hpp"


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Defines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define MTX_A       0
#define MTX_B       1
#define MTX_C       2
#define MTX_D       3
#define MTX_E       4
#define MTX_F       5
#define MTX_G       6
#define MTX_H       7
#define MTX_I       8
#define MTX_J       9
#define MTX_K       10
#define MTX_L       11

#define PI  3.1415926539
#define RADS_2_DEGS(rad) ((180.0*rad)/PI)
#define DEGS_2_RADS(deg) (PI*deg)/180.0

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

extern "C" void write_to_log(char *str);
extern "C" void report_and_log(char *str);
extern "C" void prompt_and_log(char *str);

extern "C" int capture_setup();
extern "C" void capture_terminate();
extern "C" int capture_get(ItemData **item, XVData **verts, XFData **faces);
extern "C" int capture_gethier(ItemData *idata, char *name, float *m);
extern "C" int capture_getpivot(ItemData *idata, float *px, float *py, float *pz);
extern "C" MtlData *capture_mtlget(int ind, short *selfi, short *transp);
extern "C" int capture_mtlfile(int ind, char *fname, char *tfname);

extern "C" BXPColor *capture_mtlbitmap(char *fname, int locate,
                                       ushort *xs, ushort *ys, int forcesize);
extern "C" BXPColor *capture_flcframe(char *fname, Flic *flic,
                                      FlicRaster *raster, byte *pix,
                                      ushort *xs, ushort *ys, int forcesize);

extern "C" char *locate_map(char *fname, char *fullname);
extern "C" char *get_root_from_fullname(char *fullname);
extern "C" ulong locate_sequential_maps(char *fname, char **seq_names);

STATIC int export_camera(XFParseIFF &iff, ItemData *idata);
STATIC int export_ambient(XFParseIFF &iff, ItemData *idata);
STATIC int export_spot_light(XFParseIFF &iff, ItemData *idata);
STATIC int export_omni_light(XFParseIFF &iff, ItemData *idata);
STATIC int export_mesh(XFParseIFF &iff, ItemData *idata,
                       XVData *verts, XFData *faces, VngoPal *pal);
STATIC int export_keyframes();

STATIC int merge_verticies( ItemData *idata,
XVData *verts, XFData *faces);
STATIC void compute_box_extents( ItemData *idata,
                                 XVData *verts,
                                 EschFileMeshEXNT *mextents );
STATIC void compute_quick_extents( ItemData *idata,
                                   XVData *verts,
                                   EschFileMeshEXNT *mextents );
STATIC int compute_optimal_extents( ItemData *idata,
                                    XVData *verts,
                                    EschFileMeshEXNT *mextents );

STATIC ulong compress_rle_8bpp(ushort w, ushort h, byte *data, byte *cdata);
STATIC ulong compress_rle_24bpp(ushort w, ushort h, byte *data, byte *cdata);
STATIC ulong compress_rle_32bpp(ushort w, ushort h, byte *data, byte *cdata);

STATIC void init_key_data();
STATIC void capture_hierarchy_rotations();
STATIC void process_child (int parent, int this_node, int this_keyframe);
STATIC esch_limb_type get_token (char name[22]);
STATIC void str_to_upper (char name[22]);

STATIC int load_pal(VngoPal *pal,char *infile);

STATIC int check_abort();

STATIC float det_mtx(float *m);
STATIC int inverse_mtx(float *m, float *inv);
STATIC void concat_mtx(float *ina, float *b, float *res);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern "C" char output_path[];
extern "C" char output_name[];
extern "C" char scene_name[];

extern "C" char key_output_path[];
extern "C" char key_output_name[];
extern "C" long key_apnd;
extern "C" long key_flags;
extern "C" char key_mtyp[M_TYPE_LEN];
extern "C" char key_ctyp[M_TYPE_LEN];

extern "C" dword  object_flags;

extern "C" float  scale_3ds2esch;

extern "C" int source_mode;
extern "C" int coord_mode;
extern "C" int extent_mode;
extern "C" int material_mode;
extern "C" int hierarchy_mode;
extern "C" int orientation_mode;
extern "C" int format_mode;
extern "C" int vertex_mode;

extern "C" int keys_flag;

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

extern "C" int mtl_format;
extern "C" int mtl_compress;
extern "C" int mtl_animatedtxt;
extern "C" int mtl_perspmode;

extern "C" char mtl_palpath[];
extern "C" char mtl_palname[];

// Light export information

extern "C" int lgt_omnias;
extern "C" int lgt_spotas;
extern "C" int lgt_ambient;
extern "C" int lgt_atten;


// Global to this file
struct keyframe
{
    char name[22];
    char m_type[M_TYPE_LEN];
    esch_limb_type l_type;
    long frame_num;
    float rotation[3];
};

struct delta
{
    float dx;
    float dy;
    float dz;
};

struct morph_keyframe
{
    char name[22];
    char m_type[M_TYPE_LEN];
    ulong k_type;
    int frame_num;
    int vert_count;
    struct delta *deltas;
};

struct keyframe *key=0;
struct morph_keyframe *morph_key=0;
int actual_key_count;
int actual_morph_count;
int actual_morph_key_count;
char dump[80];
int next_key = 0;

// Log file for prompt window
extern "C" int log_mode;
extern "C" char log_fname[256];
XFile *log_file=0;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// logging routines                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void write_to_log(char *str)
{
    static char buff[2] = { '\r', '\n' };

    if (!log_file)
        return;

    log_file->write(str,strlen(str));
    log_file->write(buff,2);
}

extern "C" void report_and_log(char *str)
{
    static char buff[2] = { '\r', '\n' };

    gfx_report(str);

    if (log_file)
    {
        log_file->write(str,strlen(str));
        log_file->write(buff,2);
    }
}

extern "C" void prompt_and_log(char *str)
{
    static char buff[2] = { '\r', '\n' };

    gfx_prompt(str);

    if (log_file)
    {
        log_file->write(str,strlen(str));
        log_file->write(buff,2);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// export                                                                   ³
//                                                                          ³
// Initates data download and outputs to the file.                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
extern "C" void export()
{
    ItemData            *idata;
    XVData              *verts;
    XFData              *faces;
    VngoPal             *pal=0;
    XFParseIFF          iff;
    char                buff[256];
    int i;
    int keys_only = 0;

    if (log_mode)
    {
        if (log_file)
            delete log_file;

        log_file = new XFileDisk;
        if (!log_file)
        {
            gfx_continu_line("Out of Memory!");
            return;
        }

        if (log_file->create(log_fname,0))
        {
            gfx_continu_line("Failed to open log file");
            return;
        }
    }

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Get initial data information, check for outputable data.
    switch(capture_setup())
    {
        case 1:
            gfx_continu_line("No objects to export");
            return;
        case 2:
            gfx_continu_line("ERROR:  Failed during pxp_get_item() in setup");
            return;
        case 3:
            keys_only = 1;
            break;
        default:
            break;
    }

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Open output file
    strcpy(buff,output_path);
    if (output_path[strlen(output_path)-1] != '\\')
        strcat(buff,"\\");
    strcat(buff,output_name);

    write_to_log(buff);

    if (!keys_only)
    {
        if (iff.create(buff,0))
        {
            sprintf(buff,"ERROR:  Cannot create output file, error #%d",
                    iff.error());
            gfx_continu_line(buff);
            capture_terminate();
            return;
        }
    }

    gfx_stand_by("Exporting...");

    if (!keys_only)
    {
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Create Scene
        if (iff.newform(iff.makeid('E','S','E','N')))
        {
            sprintf(buff,"ERROR:  Cannot create scene form, error #%d",
                    iff.error());
            gfx_continu_line(buff);
            goto error_exit;
        }

        {
            EschFileSceneHDR    sdata;
            memset(&sdata,0,sizeof(EschFileSceneHDR));

            strncpy(sdata.name,scene_name,ESCH_MAX_NAME);
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
                          &sdata,sizeof(sdata)))
            {
                sprintf(buff,"Error writing HDR chunk, error #%d",
                        iff.error());
                gfx_continu_line(buff);
                goto error_exit;
            }
        }
    }

    if (keys_flag)
    {
        init_key_data();

        if (key)
        {
            capture_hierarchy_rotations();
        }
    }

    if (!keys_only)
    {
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
                    //ÄÄÄ Export camera
                    if (export_camera(iff,idata))
                        goto error_exit;
                    break;

    //ÄÄÄ Lights ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
               case PXPAMBIENT:
                    //ÄÄÄ Export ambient light
                    if (lgt_ambient)
                    {
                        if (export_ambient(iff,idata))
                            goto error_exit;
                    }
                    break;

               case PXPLIGHT:
                    //ÄÄÄ Export light
                    if (idata->item.l.hotsize != 360.0
                        || idata->item.l.fallsize != 360.0)
                    {
                        if (export_spot_light(iff,idata))
                            goto error_exit;
                    }
                    else
                    {
                        if (export_omni_light(iff,idata))
                            goto error_exit;
                    }
                    break;

    //ÄÄÄ Meshs ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
               case PXPMESH:
                    //ÄÄÄ Load palette, if not already loaded once
                    if (material_mode == 2 && mtl_format == 1 && !pal)
                    {
                        char pname[256];
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
                        prompt_and_log(buff);

                        int j;
                        if ((j=load_pal(pal,pname))!=0)
                        {
                            sprintf(buff,"ERROR:  Error %d loading palette",j);
                            gfx_continu_line(buff);
                            goto error_exit;
                        }
                    }

                    //ÄÄÄ Export mesh
                    if (export_mesh(iff,idata,verts,faces,pal))
                        goto error_exit;
            }
        }
    }

    //ÄÄÄ Export keyframes
    if (keys_flag && key)
    {
        if (export_keyframes())
            goto error_exit;
    }

    gfx_put_hole();

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

    if (log_file)
    {
        log_file->close();
        delete log_file;
        log_file=0;
    }

    gfx_report("");

    gfx_put_hole();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Cameras °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// export_camera                                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC int export_camera(XFParseIFF &iff, ItemData *idata)
{
    char    buff[128];

    sprintf(buff,"Exporting Camera: %s",idata->name);
    gfx_stand_by(buff);
    report_and_log(buff);

//ÄÄÄ Compute look-at vector from bank and target point

    // Z rotate a [0 1 0] top vector for bank angle
    float tx=0;
    float ty=1;
    float tz=0;

    float cs = esch_cos(idata->item.c.bank);
    float sn = esch_sin(idata->item.c.bank);

    tx = tx*cs + ty*sn;
    ty = tx*sn + ty*cs;

    // Normalize top vector
    float sumsq = tx*tx + ty*ty + tz*tz;
    if (sumsq > 0)
    {
        float mag = esch_sqrt(sumsq);
        tx /= mag;
        ty /= mag;
        tz /= mag;
    }
    else
    {
        prompt_and_log("!!! Error during normalize in camera");
        tx = 0;  ty = 1;  tz = 0;
    }

    // Create direction vector
    float vr[3];
    vr[0] = idata->item.c.tx - idata->item.c.x;
    vr[1] = idata->item.c.tz - idata->item.c.z;
    vr[2] = idata->item.c.ty - idata->item.c.y;

    // Normalize direction vector
    sumsq = vr[0]*vr[0] + vr[1]*vr[1] + vr[2]*vr[2];
    if (sumsq > 0)
    {
        float mag = esch_sqrt(sumsq);
        vr[0] /= mag;
        vr[1] /= mag;
        vr[2] /= mag;
    }
    else
    {
        prompt_and_log("!!! Error during normalize in camera");
        vr[0] = 0;  vr[1] = 0;  vr[2] = 1;
    }

    // Ortho top vs. the direction vector
    //
    //     top = top - dir*(top DOT dir)
    //

    float dot = (tx*vr[0]) + (ty*vr[1]) + (tz*vr[2]);
    tx -= vr[0]*dot;
    ty -= vr[1]*dot;
    tz -= vr[2]*dot;

    // Normalize top vector again
    sumsq = tx*tx + ty*ty + tz*tz;
    if (sumsq > 0)
    {
        float mag = esch_sqrt(sumsq);
        tx /= mag;
        ty /= mag;
        tz /= mag;
    }
    else
    {
        prompt_and_log("!!! Error during normalize in camera");
        tx = 1;  ty = 0;  tz = 0;
    }

//ÄÄÄ Output
    if (format_mode == 1)
    {
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Floating-point
        EschFileCamera      cdata;

        memset(&cdata,0,sizeof(cdata));
        strncpy(cdata.name,idata->name,ESCH_MAX_NAME);
        cdata.x = idata->item.c.x * scale_3ds2esch;
        cdata.y = idata->item.c.z * scale_3ds2esch;
        cdata.z = idata->item.c.y * scale_3ds2esch;
        cdata.fov = 2400.0f / idata->item.c.focal;

        cdata.diri = vr[0];
        cdata.dirj = vr[1];
        cdata.dirk = vr[2];

        cdata.topi = tx;
        cdata.topj = ty;
        cdata.topk = tz;

        // Write chunk
        if (iff.write(iff.makeid('E','C','A','1'),
                      &cdata,sizeof(cdata)))
        {
            sprintf(buff,"ERROR:  Writing ECA1 (camera) chunk, error #%d",
                    iff.error());
            gfx_continu_line(buff);
            return 1;
        }

    }
    else
    {
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Fixed-point
        EschFileCameraV1    cdata;

        memset(&cdata,0,sizeof(cdata));
        strncpy(cdata.name,idata->name,ESCH_MAX_NAME);
        cdata.x = long(idata->item.c.x * scale_3ds2esch * 65536.0f);
        cdata.y = long(idata->item.c.z * scale_3ds2esch * 65536.0f);
        cdata.z = long(idata->item.c.y * scale_3ds2esch * 65536.0f);
        cdata.fov = long((2400.0f / idata->item.c.focal) * 65536.0f);

        cdata.diri = long(vr[0] * 65536.0f);
        cdata.dirj = long(vr[1] * 65536.0f);
        cdata.dirk = long(vr[2] * 65536.0f);

        cdata.topi = long(tx * 65536.0f);
        cdata.topj = long(ty * 65536.0f);
        cdata.topk = long(tz * 65536.0f);

        // Write chunk
        if (iff.write(iff.makeid('E','C','A','M'),
                      &cdata,sizeof(cdata)))
        {
            sprintf(buff,"ERROR:  Writing ECAM (camera) chunk, error #%d",
                    iff.error());
            gfx_continu_line(buff);
            return 1;
        }
    }

    return 0;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Lights  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// export_ambient                                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC int export_ambient(XFParseIFF &iff, ItemData *idata)
{
    EschFileLightAmbi   adata;
    char                buff[128];

    sprintf(buff,"Exporting Ambient: %s",idata->name);
    gfx_stand_by(buff);
    report_and_log(buff);

    memset(&adata,0,sizeof(adata));
    strncpy(adata.name,idata->name,ESCH_MAX_NAME);
    ((VngoColor24bit*)&adata.color)->r = (byte)(idata->item.a.color.r*255.0);
    ((VngoColor24bit*)&adata.color)->g = (byte)(idata->item.a.color.g*255.0);
    ((VngoColor24bit*)&adata.color)->b = (byte)(idata->item.a.color.b*255.0);

    if (iff.write(iff.makeid('E','A','M','B'),
                  &adata,sizeof(adata)))
    {
        sprintf(buff,"ERROR:  Writing EAMB (ambient light) chunk, error #%d",
                iff.error());
        gfx_continu_line(buff);
        return 1;
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// export_spot_light                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC int export_spot_light(XFParseIFF &iff, ItemData *idata)
{
    char    buff[128];
    float   vr[3];
    float   mag, sumsq;

    sprintf(buff,"Exporting Spot Light: %s",idata->name);
    gfx_stand_by(buff);
    report_and_log(buff);

//ÄÄÄ Vector
    if (lgt_spotas == 3)
    {
        vr[0] = idata->item.l.tx - idata->item.l.x;
        vr[1] = idata->item.l.tz - idata->item.l.z;
        vr[2] = idata->item.l.ty - idata->item.l.y;

        sumsq = vr[0]*vr[0] + vr[1]*vr[1] + vr[2]*vr[2];
        if (sumsq > 0)
        {
            mag = esch_sqrt(sumsq);
            vr[0] /= mag;
            vr[1] /= mag;
            vr[2] /= mag;
        }
        else
        {
            prompt_and_log("!!! Error during normalize in light");
            vr[0] = 0;  vr[1] = 0;  vr[2] = 1;
        }

        if (format_mode == 1)
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Floating-point
            EschFileLightVect   vdata;

            memset(&vdata,0,sizeof(vdata));
            strncpy(vdata.name,idata->name,ESCH_MAX_NAME);

            if (!(idata->item.l.flags & LIGHT_ON))
                vdata.flags |= ESCH_LGT_OFF;

            vdata.i = vr[0];
            vdata.j = vr[1];
            vdata.k = vr[2];

            float mult = idata->item.l.mult;
            if (mult < 0)
            {
                mult = -mult;
                vdata.flags |= ESCH_LGT_DARK;
            }

            ((VngoColor24bit*)&vdata.color)->r = (byte)(idata->item.l.color.r
                                                        * mult * 255.0);
            ((VngoColor24bit*)&vdata.color)->g = (byte)(idata->item.l.color.g
                                                        * mult * 255.0);
            ((VngoColor24bit*)&vdata.color)->b = (byte)(idata->item.l.color.b
                                                        * mult * 255.0);

            if (iff.write(iff.makeid('E','V','E','1'),
                          &vdata,sizeof(vdata)))
            {
                sprintf(buff,"ERROR:  Writing EVE1 (vector light) chunk, error #%d",
                        iff.error());
                gfx_continu_line(buff);
                return 1;
            }
        }
        else
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Fixed-point
            EschFileLightVectV1 vdata;

            memset(&vdata,0,sizeof(vdata));
            strncpy(vdata.name,idata->name,ESCH_MAX_NAME);

            if (!(idata->item.l.flags & LIGHT_ON))
                vdata.flags |= ESCH_LGT_OFF;

            vdata.i = long(vr[0] * 65536.0f);
            vdata.j = long(vr[1] * 65536.0f);
            vdata.k = long(vr[2] * 65536.0f);

            float mult = idata->item.l.mult;
            if (mult < 0)
            {
                mult = -mult;
                vdata.flags |= ESCH_LGT_DARK;
            }

            ((VngoColor24bit*)&vdata.color)->r = (byte)(idata->item.l.color.r
                                                        * mult * 255.0);
            ((VngoColor24bit*)&vdata.color)->g = (byte)(idata->item.l.color.g
                                                        * mult * 255.0);
            ((VngoColor24bit*)&vdata.color)->b = (byte)(idata->item.l.color.b
                                                        * mult * 255.0);

            if (iff.write(iff.makeid('E','V','E','C'),
                          &vdata,sizeof(vdata)))
            {
                sprintf(buff,"ERROR:  Writing EVEC (vector light) chunk, error #%d",
                        iff.error());
                gfx_continu_line(buff);
                return 1;
            }
        }
    }
//ÄÄÄ Fast or Spot
    else // lgt_spot == 1 or lgt_spotas == 2
    {
        vr[0] = idata->item.l.tx - idata->item.l.x;
        vr[1] = idata->item.l.tz - idata->item.l.z;
        vr[2] = idata->item.l.ty - idata->item.l.y;

        sumsq = vr[0]*vr[0] + vr[1]*vr[1] + vr[2]*vr[2];
        if (sumsq > 0)
        {
            mag = esch_sqrt(sumsq);
            vr[0] /= mag;
            vr[1] /= mag;
            vr[2] /= mag;
        }
        else
        {
            prompt_and_log("!!! Error during normalize in light");
            vr[0] = 0;  vr[1] = 0;  vr[2] = 1;
        }

        if (format_mode == 1)
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Floating-point
            EschFileLightSpot  sdata;

            memset(&sdata,0,sizeof(sdata));
            strncpy(sdata.name,idata->name,ESCH_MAX_NAME);

            if (!(idata->item.l.flags & LIGHT_ON))
                sdata.flags |= ESCH_LGT_OFF;

            sdata.x = idata->item.l.x * scale_3ds2esch;
            sdata.y = idata->item.l.z * scale_3ds2esch;
            sdata.z = idata->item.l.y * scale_3ds2esch;

            sdata.i = vr[0];
            sdata.j = vr[1];
            sdata.k = vr[2];

            float mult = idata->item.l.mult;
            if (mult < 0)
            {
                mult = -mult;
                sdata.flags |= ESCH_LGT_DARK;
            }

            ((VngoColor24bit*)&sdata.color)->r = (byte)(idata->item.l.color.r
                                                        * mult * 255.0);
            ((VngoColor24bit*)&sdata.color)->g = (byte)(idata->item.l.color.g
                                                        * mult * 255.0);
            ((VngoColor24bit*)&sdata.color)->b = (byte)(idata->item.l.color.b
                                                        * mult * 255.0);

            sdata.hotspot = idata->item.l.hotsize;
            sdata.falloff = idata->item.l.fallsize;

            if (lgt_atten
                && (idata->item.l.flags & LIGHT_ATTEN))
            {
                sdata.flags |= ESCH_LGT_ATTEN;
                sdata.inner = idata->item.l.in_range * scale_3ds2esch;
                sdata.outer = idata->item.l.out_range * scale_3ds2esch;
            }
            else
                sdata.outer = float(0x1000);

            if (iff.write((lgt_spotas == 2) ? iff.makeid('E','S','P','1')
                                            : iff.makeid('E','F','S','1'),
                          &sdata,sizeof(sdata)))
            {
                sprintf(buff,"ERROR:  Writing %s (spot light) chunk, error #%d",
                        (lgt_spotas == 2) ? "ESP1" : "EFS1",
                        iff.error());
                gfx_continu_line(buff);
                return 1;
            }
        }
        else
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Fixed-point
            EschFileLightSpotV1 sdata;

            memset(&sdata,0,sizeof(sdata));
            strncpy(sdata.name,idata->name,ESCH_MAX_NAME);

            if (!(idata->item.l.flags & LIGHT_ON))
                sdata.flags |= ESCH_LGT_OFF;

            sdata.x = long(idata->item.l.x * scale_3ds2esch * 65536.0f);
            sdata.y = long(idata->item.l.z * scale_3ds2esch * 65536.0f);
            sdata.z = long(idata->item.l.y * scale_3ds2esch * 65536.0f);

            sdata.i = long(vr[0] * 65536.0f);
            sdata.j = long(vr[1] * 65536.0f);
            sdata.k = long(vr[2] * 65536.0f);

            float mult = idata->item.l.mult;
            if (mult < 0)
            {
                mult = -mult;
                sdata.flags |= ESCH_LGT_DARK;
            }

            ((VngoColor24bit*)&sdata.color)->r = (byte)(idata->item.l.color.r
                                                        * mult * 255.0);
            ((VngoColor24bit*)&sdata.color)->g = (byte)(idata->item.l.color.g
                                                        * mult * 255.0);
            ((VngoColor24bit*)&sdata.color)->b = (byte)(idata->item.l.color.b
                                                        * mult * 255.0);

            sdata.hotspot = long(idata->item.l.hotsize * 65536.0f);
            sdata.falloff = long(idata->item.l.fallsize * 65536.0f);

            if (lgt_atten
                && (idata->item.l.flags & LIGHT_ATTEN))
            {
                sdata.flags |= ESCH_LGT_ATTEN;
                sdata.inner = long(idata->item.l.in_range * scale_3ds2esch * 65536.0f);
                sdata.outer = long(idata->item.l.out_range * scale_3ds2esch * 65536.0f);
            }
            else
                sdata.outer = 0x1000 << 16;

            if (iff.write((lgt_spotas == 2) ? iff.makeid('E','S','P','T')
                                            : iff.makeid('E','F','S','P'),
                          &sdata,sizeof(sdata)))
            {
                sprintf(buff,"ERROR:  Writing %s (spot light) chunk, error #%d",
                    (lgt_spotas == 2) ? "ESPT" : "EFSP",
                    iff.error());
                gfx_continu_line(buff);
                return 1;
            }
        }
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// export_omni_light                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC int export_omni_light(XFParseIFF &iff, ItemData *idata)
{
    char    buff[128];

    sprintf(buff,"Exporting Omni Light: %s",idata->name);
    gfx_stand_by(buff);
    report_and_log(buff);

    //ÄÄÄ Attenuated version
    if (lgt_atten
        && (idata->item.l.flags & LIGHT_ATTEN))
    {
        if (format_mode == 1)
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Floating-point
            EschFileLightAtten  adata;

            memset(&adata,0,sizeof(adata));
            strncpy(adata.name,idata->name,ESCH_MAX_NAME);

            adata.flags |= ESCH_LGT_ATTEN;
            if (!(idata->item.l.flags & LIGHT_ON))
                adata.flags |= ESCH_LGT_OFF;

            adata.x = idata->item.l.x * scale_3ds2esch;
            adata.y = idata->item.l.z * scale_3ds2esch;
            adata.z = idata->item.l.y * scale_3ds2esch;

            adata.inner = idata->item.l.in_range * scale_3ds2esch;
            adata.outer = idata->item.l.out_range * scale_3ds2esch;

            float mult = idata->item.l.mult;
            if (mult < 0)
            {
                mult = -mult;
                adata.flags |= ESCH_LGT_DARK;
            }

            ((VngoColor24bit*)&adata.color)->r = (byte)(idata->item.l.color.r
                                                        * mult * 255.0);
            ((VngoColor24bit*)&adata.color)->g = (byte)(idata->item.l.color.g
                                                        * mult * 255.0);
            ((VngoColor24bit*)&adata.color)->b = (byte)(idata->item.l.color.b
                                                        * mult * 255.0);

            if (iff.write((lgt_omnias == 2) ? iff.makeid('E','A','T','1')
                                            : iff.makeid('E','F','A','1'),
                          &adata,sizeof(adata)))
            {
                sprintf(buff,"ERROR:  Writing %s (atten light) chunk, error #%d",
                        (lgt_omnias == 2) ? "EAT1" : "EFA1",
                        iff.error());
                gfx_continu_line(buff);
                return 1;
            }
        }
        else
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Fixed-point
            EschFileLightAttenV1    adata;

            memset(&adata,0,sizeof(adata));
            strncpy(adata.name,idata->name,ESCH_MAX_NAME);

            adata.flags |= ESCH_LGT_ATTEN;
            if (!(idata->item.l.flags & LIGHT_ON))
                adata.flags |= ESCH_LGT_OFF;

            adata.x = long(idata->item.l.x * scale_3ds2esch * 65536.0f);
            adata.y = long(idata->item.l.z * scale_3ds2esch * 65536.0f);
            adata.z = long(idata->item.l.y * scale_3ds2esch * 65536.0f);

            adata.inner = long(idata->item.l.in_range * scale_3ds2esch * 65536.0f);
            adata.outer = long(idata->item.l.out_range * scale_3ds2esch * 65536.0f);

            float mult = idata->item.l.mult;
            if (mult < 0)
            {
                mult = -mult;
                adata.flags |= ESCH_LGT_DARK;
            }

            ((VngoColor24bit*)&adata.color)->r = (byte)(idata->item.l.color.r
                                                        * mult * 255.0);
            ((VngoColor24bit*)&adata.color)->g = (byte)(idata->item.l.color.g
                                                        * mult * 255.0);
            ((VngoColor24bit*)&adata.color)->b = (byte)(idata->item.l.color.b
                                                        * mult * 255.0);

            if (iff.write((lgt_omnias == 2) ? iff.makeid('E','A','T','N')
                                            : iff.makeid('E','F','A','T'),
                          &adata,sizeof(adata)))
            {
                sprintf(buff,"ERROR:  Writing %s (atten light) chunk, error #%d",
                        (lgt_omnias == 2) ? "EATN" : "EFAT",
                        iff.error());
                gfx_continu_line(buff);
                return 1;
            }
        }
    }
    //ÄÄÄ Nonattenuated version
    else
    {
        if (format_mode == 1)
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Floating-point
            EschFileLightPoint  pdata;

            memset(&pdata,0,sizeof(pdata));
            strncpy(pdata.name,idata->name,ESCH_MAX_NAME);

            if (!(idata->item.l.flags & LIGHT_ON))
                pdata.flags |= ESCH_LGT_OFF;

            pdata.x = idata->item.l.x * scale_3ds2esch;
            pdata.y = idata->item.l.z * scale_3ds2esch;
            pdata.z = idata->item.l.y * scale_3ds2esch;

            float mult = idata->item.l.mult;
            if (mult < 0)
            {
                mult = -mult;
                pdata.flags |= ESCH_LGT_DARK;
            }

            ((VngoColor24bit*)&pdata.color)->r = (byte)(idata->item.l.color.r
                                                        * mult * 255.0);
            ((VngoColor24bit*)&pdata.color)->g = (byte)(idata->item.l.color.g
                                                        * mult * 255.0);
            ((VngoColor24bit*)&pdata.color)->b = (byte)(idata->item.l.color.b
                                                        * mult * 255.0);

            if (iff.write((lgt_omnias == 2) ? iff.makeid('E','P','N','1')
                                            : iff.makeid('E','F','P','1'),
                          &pdata,sizeof(pdata)))
            {
                sprintf(buff,"ERROR:  Writing %s (point light) chunk, error #%d",
                        (lgt_omnias == 2) ? "EPN1" : "EFP1",
                        iff.error());
                gfx_continu_line(buff);
                return 1;
            }
        }
        else
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Fixed-point
            EschFileLightPointV1    pdata;

            memset(&pdata,0,sizeof(pdata));
            strncpy(pdata.name,idata->name,ESCH_MAX_NAME);

            if (!(idata->item.l.flags & LIGHT_ON))
                pdata.flags |= ESCH_LGT_OFF;

            pdata.x = long(idata->item.l.x * scale_3ds2esch * 65536.0f);
            pdata.y = long(idata->item.l.z * scale_3ds2esch * 65536.0f);
            pdata.z = long(idata->item.l.y * scale_3ds2esch * 65536.0f);

            float mult = idata->item.l.mult;
            if (mult < 0)
            {
                mult = -mult;
                pdata.flags |= ESCH_LGT_DARK;
            }

            ((VngoColor24bit*)&pdata.color)->r = (byte)(idata->item.l.color.r
                                                        * mult * 255.0);
            ((VngoColor24bit*)&pdata.color)->g = (byte)(idata->item.l.color.g
                                                        * mult * 255.0);
            ((VngoColor24bit*)&pdata.color)->b = (byte)(idata->item.l.color.b
                                                        * mult * 255.0);

            if (iff.write((lgt_omnias == 2) ? iff.makeid('E','P','N','T')
                                            : iff.makeid('E','F','P','T'),
                          &pdata,sizeof(pdata)))
            {
                sprintf(buff,"ERROR:  Writing %s (point light) chunk, error #%d",
                        (lgt_omnias == 2) ? "EPNT" : "EFPT",
                        iff.error());
                gfx_continu_line(buff);
                return 1;
            }
        }
    }

    return 0;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Meshes °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// export_mesh                                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC int export_mesh(XFParseIFF &iff, ItemData *idata,
                       XVData *verts, XFData *faces, VngoPal *pal)
{
    float   cx, cy, cz;
    float   v1[3],v2[3],vr[3];
    char    buff[256];

    sprintf(buff,"Exporting Object: %s",idata->name);
    gfx_show_gasgauge(buff);
    report_and_log(buff);

    int steps = idata->item.m.verts + idata->item.m.faces;

//ÄÄÄ Create mesh form
    if (iff.newform(iff.makeid('E','M','S','H')))
    {
        sprintf(buff,"ERROR:  Cannot create EMSH, error #%d",
                iff.error());
        gfx_continu_line(buff);
        return 1;
    }

//ÄÄÄ Save original u,v since these might change in merge...
    EschFace *efaces = new EschFace[idata->item.m.faces];
    if (!efaces)
    {
        gfx_continu_line("Out of Memory!");
        return 1;
    }
    memset(efaces,0,idata->item.m.faces*sizeof(EschFace));

    // Fill out vertex mapping parameters
    for(int i=0; i < idata->item.m.faces; i++)
    {
        if (idata->item.m.tverts)
        {
            float u[3] = { verts[faces[i].a].u,
                           verts[faces[i].b].u,
                           verts[faces[i].c].u };
            float v[3] = { verts[faces[i].a].v,
                           verts[faces[i].b].v,
                           verts[faces[i].c].v };

            if (faces[i].flags & XF_UWRAP)
            {
                int max = 0;

                for(int j=1; j < 3; j++)
                {
                    if (u[j] > u[max])
                        max = j;
                }

                float nextu = ceil(u[max]);

                for(j=0; j < 3; j++)
                {
                    if (max == j)
                        continue;

                    if (fabs(u[max] - (u[j]+nextu)) < fabs(u[max] - u[j]))
                    {
                        u[j] += nextu;
                    }
                }
            }

            efaces[i].u[0] = u[0];
            efaces[i].u[1] = u[1];
            efaces[i].u[2] = u[2];

            // 3DS Uses the opposite definition of v, so we
            // have to negate it to result in right-side up
            // images.
            if (faces[i].flags & XF_VWRAP)
            {
                int max = 0;

                for(int j=1; j < 3; j++)
                {
                    if (v[j] > v[max])
                        max = j;
                }

                float nextv = ceil(v[max]);

                for(j=0; j < 3; j++)
                {
                    if (max == j)
                        continue;

                    if (fabs(v[max] - (v[j]+nextv)) < fabs(v[max] - v[j]))
                    {
                        v[j] += nextv;
                    }
                }
            }

            efaces[i].v[0] = -v[0];
            efaces[i].v[1] = -v[1];
            efaces[i].v[2] = -v[2];
        }
    }

//ÄÄÄ Merge verticies if requested (only changes nverts)
    if (vertex_mode == 2)
    {
        sprintf(buff,"Object '%s': Merging verticies...",idata->name);
        gfx_set_gasgauge(buff,0,1);
        if (merge_verticies(idata,verts,faces))
            return 1;
    }

//ÄÄÄ Create Header
    EschFileMeshHDR mheader;
    memset(&mheader,0,sizeof(mheader));

    strncpy(mheader.name,idata->name,ESCH_MAX_NAME);
    mheader.flags = object_flags;
    mheader.nverts = idata->item.m.verts;
    mheader.nfaces = idata->item.m.faces;

//ÄÄÄÄ Compute extents
    EschFileMeshEXNT    mextents;
    memset(&mextents,0,sizeof(mextents));

    //ÄÄÄÄ Box extents
    sprintf(buff,"Object '%s': Computing box extents...",idata->name);
    gfx_set_gasgauge(buff,0,1);

    compute_box_extents( idata, verts, &mextents);

    //ÄÄÄÄ Radial extents
    sprintf(buff,"Object '%s': Computing radial extents...",idata->name);
    gfx_set_gasgauge(buff,0,1);
    if (extent_mode==2)
    {
        // Optimal
        if (compute_optimal_extents( idata, verts, &mextents ))
            return 1;
    }
    else
    {
        // Quick
        compute_quick_extents( idata, verts, &mextents );
    }

//ÄÄÄ Compute matrix/heirachy
    EschMatrix          mtx;

    EschFileMeshHIER    ehier;
    memset(&ehier,0,sizeof(ehier));

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

            float tx, ty, tz;
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

        mtx.mtx[ESCH_MTX_J] = cx * scale_3ds2esch;
        mtx.mtx[ESCH_MTX_K] = cz * scale_3ds2esch;
        mtx.mtx[ESCH_MTX_L] = cy * scale_3ds2esch;
    }
    else if (hierarchy_mode == 2)
    {
        capture_gethier(idata,ehier.parent,0);
    }

//ÄÄÄ Allocate Space
    EschVertex *everts = new EschVertex[idata->item.m.verts];
    if (!everts)
    {
        gfx_continu_line("Out of Memory!");
        return 1;
    }
    memset(everts,0,idata->item.m.verts*sizeof(EschVertex));

    EschFileMeshMTL *emtls = new EschFileMeshMTL[256];
    if (!emtls)
    {
        gfx_continu_line("Out of Memory!");
        return 1;
    }

    char *mtlfnames = new char[256*14*2];
    if (!mtlfnames)
    {
        gfx_continu_line("Out of Memory!");
        return 1;
    }

//ÄÄÄ Compute Faces
    sprintf(buff,"Object '%s': Computing faces...",idata->name);
    gfx_set_gasgauge(buff,0,steps);

    int nmtls=0;
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

        float sumsq = vr[0]*vr[0] + vr[1]*vr[1] + vr[2]*vr[2];
        if (sumsq > 0)
        {
            float mag = esch_sqrt(sumsq);
            vr[0] /= mag;
            vr[1] /= mag;
            vr[2] /= mag;
        }
        else
        {
            prompt_and_log("!!! Error during normalize in mesh face");
            vr[0] = 0;  vr[1] = 1;  vr[2] = 0;
        }

        efaces[i].normal.i = vr[0];
        efaces[i].normal.j = vr[1];
        efaces[i].normal.k = vr[2];

        efaces[i].flags |= ESCH_FACE_WIRE
                           | ESCH_FACE_SOLID;

        if (mtl_perspmode == 3)
            efaces[i].flags |= ESCH_FACE_ALLOWPERSP;

        efaces[i].alpha_a =
        efaces[i].alpha_b =
        efaces[i].alpha_c = 255;

        // Fill out material information
        short selfi, transp;
        MtlData *mtl = capture_mtlget(faces[i].material,&selfi,&transp);
        if (mtl)
        {
            // Fill out face associated information
            efaces[i].color=0;
            ((VngoColor24bit*)&efaces[i].color)->r = mtl->diff.r;
            ((VngoColor24bit*)&efaces[i].color)->g = mtl->diff.g;
            ((VngoColor24bit*)&efaces[i].color)->b = mtl->diff.b;

            if (!(mtl->flags & MTL_TWOSIDE))
                efaces[i].flags |= ESCH_FACE_ONESIDED;

            if (mtl_perspmode == 2 && *(mtl->name) == '^')
                efaces[i].flags |= ESCH_FACE_ALLOWPERSP;

            efaces[i].self_illum = byte((selfi * 255) / 100);

            efaces[i].alpha_a =
            efaces[i].alpha_b =
            efaces[i].alpha_c = byte(255 - ((transp * 255) / 100));
            if (transp)
                efaces[i].flags |= ESCH_FACE_ALPHA;

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
            char fname[13];
            char tfname[13];
            int j=capture_mtlfile(faces[i].material,fname,tfname);

            // Warning if ignored maps
            if (j==2)
            {
                char name[ESCH_MAX_NAME+1];
                strncpy(name,mtl->name,ESCH_MAX_NAME);
                name[ESCH_MAX_NAME] = 0;

                sprintf(buff,"%s: non-Texture1/Opacity maps ignored",
                        name);
                prompt_and_log(buff);
            }

            if (!*fname && *tfname)
            {
                char name[ESCH_MAX_NAME+1];
                strncpy(name,mtl->name,ESCH_MAX_NAME);
                name[ESCH_MAX_NAME] = 0;

                sprintf(buff,"%s: Opacity maps without Texture1 maps ignored",
                        name);
                prompt_and_log(buff);
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

//ÄÄÄ Compute Vertices
    sprintf(buff,"Object '%s': Computing vertices...",idata->name);
    gfx_set_gasgauge(buff,idata->item.m.faces+i,steps);

    // Get center of object from orientation matrix
    cx = idata->item.m.matrix[3][0];
    cy = idata->item.m.matrix[3][1];
    cz = idata->item.m.matrix[3][2];

    // Adjust center for pivot points, if any
    float tx, ty, tz;
    if (coord_mode == 1
        && capture_getpivot(idata, &tx, &ty, &tz))
    {
        cx += tx;
        cy += ty;
        cz += tz;
    }

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

        everts[i].x = tx * scale_3ds2esch;
        everts[i].y = tz * scale_3ds2esch;
        everts[i].z = ty * scale_3ds2esch;

        vr[0]=vr[1]=vr[2]=0.0;
        for(int j=0; j < idata->item.m.faces; j++)
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

        float sumsq = vr[0]*vr[0] + vr[1]*vr[1] + vr[2]*vr[2];
        if (sumsq > 0)
        {
            float mag = esch_sqrt(sumsq);
            vr[0] /= mag;
            vr[1] /= mag;
            vr[2] /= mag;
        }
        else
        {
            prompt_and_log("!!! Error during normalize in mesh vertex");
            vr[0] = 0;  vr[1] = 1;  vr[2] = 0;
        }
        everts[i].normal.i = vr[0];
        everts[i].normal.j = vr[1];
        everts[i].normal.k = vr[2];
    }

//ÄÄÄ Output Data
    sprintf(buff,"Object '%s': Writing...",idata->name);
    gfx_set_gasgauge(buff,steps,steps);

    // Output header
    if (iff.write(iff.makeid('H','D','R',' '),&mheader,sizeof(mheader)))
    {
        sprintf(buff,"ERROR:  Writing HDR chunk, error #%d", iff.error());
        gfx_continu_line(buff);
        goto error_exit;
    }

    // Matrix
    if (orientation_mode == 2)
    {
        if (format_mode == 1)
        {
            if (iff.write(iff.makeid('M','T','R','1'),&mtx,sizeof(mtx)))
            {
                sprintf(buff,"ERROR:  Writing MTR1 (matrix) chunk, error #%d", iff.error());
                gfx_continu_line(buff);
                goto error_exit;
            }
        }
        else
        {
            EschMatrixV1    v1;

            for(int i=0; i < ESCH_MTX_NUM; i++)
                v1.mtx[i] = long(mtx.mtx[i] * 65536.0f);

            if (iff.write(iff.makeid('M','T','R','X'),&v1,sizeof(v1)))
            {
                sprintf(buff,"ERROR:  Writing MTRX (matrix) chunk, error #%d", iff.error());
                gfx_continu_line(buff);
                goto error_exit;
            }
        }
    }

    // Hierarchy
    if (hierarchy_mode == 2
        && *ehier.parent
        && iff.write(iff.makeid('H','I','E','R'),&ehier,sizeof(ehier)))
    {
        sprintf(buff,"ERROR:  Writing HIER chunk, error #%d", iff.error());
        gfx_continu_line(buff);
        goto error_exit;
    }

    // Extents
    if (format_mode == 1)
    {
        if (iff.write(iff.makeid('E','X','N','1'),&mextents,sizeof(mextents)))
        {
            sprintf(buff,"ERROR:  Writing EXN1 (extents) chunk, error #%d", iff.error());
            gfx_continu_line(buff);
            goto error_exit;
        }
    }
    else
    {
        EschFileMeshEXNTV1  v1;

        memset(&v1,0,sizeof(v1));
        v1.cenx          = long(mextents.cenx * 65536.0f);
        v1.ceny          = long(mextents.ceny * 65536.0f);
        v1.cenz          = long(mextents.cenz * 65536.0f);
        v1.extent_radius = long(mextents.extent_radius * 65536.0f);
        v1.minx          = long(mextents.minx * 65536.0f);
        v1.miny          = long(mextents.miny * 65536.0f);
        v1.minz          = long(mextents.minz * 65536.0f);
        v1.maxx          = long(mextents.maxx * 65536.0f);
        v1.maxy          = long(mextents.maxy * 65536.0f);
        v1.maxz          = long(mextents.maxz * 65536.0f);

        if (iff.write(iff.makeid('E','X','N','T'),&v1,sizeof(v1)))
        {
            sprintf(buff,"ERROR:  Writing EXNT (extents) chunk, error #%d", iff.error());
            gfx_continu_line(buff);
            goto error_exit;
        }
    }

    // Verticies
    if (format_mode == 1)
    {
        if (iff.write(iff.makeid('V','E','R','1'),everts,
                      idata->item.m.verts * sizeof(EschVertex)))
        {
            sprintf(buff,"ERROR:  Writing VER1 (vertex) chunk, error #%d", iff.error());
            gfx_continu_line(buff);
            goto error_exit;
        }
    }
    else
    {
        EschVertexV1 *temp = new EschVertexV1[idata->item.m.verts];
        if (!temp)
        {
            gfx_continu_line("Out of Memory!");
            return 1;
        }

        EschVertex *tptr = everts;
        EschVertexV1 *tmpptr = temp;
        for(ulong i=0; i < idata->item.m.verts; i++, tptr++, tmpptr++)
        {
            tmpptr->x = long(tptr->x * 65536.0f);
            tmpptr->y = long(tptr->y * 65536.0f);
            tmpptr->z = long(tptr->z * 65536.0f);
            tmpptr->normal.i = long(tptr->normal.i * 65536.0f);
            tmpptr->normal.j = long(tptr->normal.j * 65536.0f);
            tmpptr->normal.k = long(tptr->normal.k * 65536.0f);
        }

        if (iff.write(iff.makeid('V','E','R','T'),temp,
                      idata->item.m.verts * sizeof(EschVertexV1)))
        {
            sprintf(buff,"ERROR:  Writing VERT (vertex) chunk, error #%d", iff.error());
            gfx_continu_line(buff);
            delete [] temp;
            goto error_exit;
        }

        delete [] temp;
    }

    // Material names
    if (nmtls && iff.write(iff.makeid('M','T','L',' '),
                           emtls,nmtls * sizeof(EschFileMeshMTL)))
    {
        sprintf(buff,"ERROR:  Writing MTL chunk, error #%d", iff.error());
        gfx_continu_line(buff);
        goto error_exit;
    }

    // Faces
    if (format_mode == 1)
    {
        if (iff.write(iff.makeid('F','A','C','2'), efaces,
                      idata->item.m.faces * sizeof(EschFace)))
        {
            sprintf(buff,"ERROR:  Writing FAC2 (face) chunk, error #%d", iff.error());
            gfx_continu_line(buff);
            goto error_exit;
        }
    }
    else
    {
        EschFaceV1 *temp = new EschFaceV1[idata->item.m.faces];
        if (!temp)
        {
            gfx_continu_line("Out of Memory!");
            return 1;
        }

        EschFace *tptr = efaces;
        EschFaceV1 *tmpptr = temp;
        for(ulong i=0; i < idata->item.m.faces; i++, tptr++, tmpptr++)
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

        if (iff.write(iff.makeid('F','A','C','E'), temp,
                      idata->item.m.faces * sizeof(EschFaceV1)))
        {
            sprintf(buff,"ERROR:  Writing FACE (face) chunk, error #%d", iff.error());
            gfx_continu_line(buff);
            delete [] temp;
            goto error_exit;
        }

        delete [] temp;
    }

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Materials
    if (nmtls && material_mode == 2)
    {
        sprintf(buff,"Object '%s': Outputing materials...",idata->name);
        gfx_set_gasgauge(buff,0,nmtls);

        //ÄÄÄ Output each material
        for(int j=0; j < nmtls; j++)
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
            prompt_and_log(buff);

            if (check_abort())
                goto error_exit;

            //ÄÄÄ Setup header
            EschFileMtlMHDR mtlhdr;
            memset(&mtlhdr,0,sizeof(EschFileMtlMHDR));

            strncpy(mtlhdr.name,emtls[j].name,ESCH_MAX_NAME);
            mtlhdr.nframes = 1;

            if (pal)
                strncpy(mtlhdr.pname,pal->name,16);

            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Texture 1
            BXPColor *bm=0;
            Flic flc;
            FlicRaster *raster=0;
            byte *raster_pix=0;
            ulong seq_count=0;
            char *seq_names=0;

            if (mtl_animatedtxt
                && strstr(fname,".FLI") || strstr(fname,".FLC"))
            {
                AnimInfo info;
                char     path[256];

                if (!locate_map(fname,path)
                    || pj_flic_open_info(path,&flc,&info)
                    || pj_flic_rewind(&flc))
                {
                    sprintf(buff,"ERROR:  Could not open Texture 1 flic '%s'",
                                 fname);
                    gfx_continu_line(buff);
                    goto error_exit;
                }

                raster_pix = (byte*)malloc(info.width * info.height);
                if (!raster_pix
                    || pj_raster_bind_ram(&raster, info.width, info.height, raster_pix))
                {
                    gfx_continu_line("Out of Memory!");
                    goto error_exit;
                }

                mtlhdr.nframes = (ushort)info.num_frames;

                bm=capture_flcframe(fname, &flc, raster, raster_pix,
                                    &mtlhdr.xsize, &mtlhdr.ysize, 0);
                if (!bm)
                {
                    sprintf(buff,"ERROR:  Error loading Texture 1 flic '%s'",
                                 fname);
                    gfx_continu_line(buff);
                    goto error_exit;
                }
            }
            else if (strchr(fname,'*'))
            {
                seq_count = locate_sequential_maps(fname,&seq_names);
                if (!seq_count)
                {
                    sprintf(buff,"ERROR:  Could not open Texture 1 sequential bitmap '%s'",
                                 fname);
                    gfx_continu_line(buff);
                    goto error_exit;
                }

                write_to_log("T1: Sequential sorted maps");
                for(int k=0; k < seq_count; k++)
                    write_to_log(&seq_names[256*k]);

                mtlhdr.nframes = ushort((mtl_animatedtxt) ? seq_count : 1);

                bm=capture_mtlbitmap(seq_names, 0,
                                     &mtlhdr.xsize, &mtlhdr.ysize, 0);
                if (!bm)
                {
                    sprintf(buff,"ERROR:  Error loading Texture 1 sequential bitmap %s",
                                 get_root_from_fullname(seq_names));
                    gfx_continu_line(buff);
                    goto error_exit;
                }
            }
            else
            {
                bm=capture_mtlbitmap(fname, 1,
                                     &mtlhdr.xsize, &mtlhdr.ysize, 0);
                if (!bm)
                {
                    sprintf(buff,"ERROR:  Error loading Texture 1 bitmap %s",fname);
                    gfx_continu_line(buff);
                    goto error_exit;
                }
            }

            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Opacity
            BXPColor *tbm=0;
            Flic tflc;
            FlicRaster *traster=0;
            byte *traster_pix=0;
            ulong tseq_count=0;
            char *tseq_names=0;

            if (*tfname)
            {
                if (mtl_animatedtxt
                    && strstr(tfname,".FLI") || strstr(tfname,".FLC"))
                {
                    AnimInfo info;
                    char     path[256];

                    if (!locate_map(tfname,path)
                        || pj_flic_open_info(path,&tflc,&info)
                        || pj_flic_rewind(&tflc))
                    {
                        sprintf(buff,"ERROR:  Could not open Opacity flic '%s'",
                                     tfname);
                        gfx_continu_line(buff);
                        goto error_exit;
                    }

                    traster_pix = (byte*)malloc(info.width * info.height);
                    if (!traster_pix
                        || pj_raster_bind_ram(&traster, info.width, info.height, traster_pix))
                    {
                        gfx_continu_line("Out of Memory!");
                        goto error_exit;
                    }

                    if (info.num_frames > (long)mtlhdr.nframes)
                        mtlhdr.nframes = (ushort)info.num_frames;

                    tbm=capture_flcframe(tfname, &tflc, traster, traster_pix,
                                         &mtlhdr.xsize, &mtlhdr.ysize, 1);
                    if (!tbm)
                    {
                        sprintf(buff,"ERROR:  Error loading Opacity flic '%s'",
                                     tfname);
                        gfx_continu_line(buff);
                        goto error_exit;
                    }
                }
                else if (strchr(tfname,'*'))
                {
                    tseq_count = locate_sequential_maps(tfname,&tseq_names);
                    if (!tseq_count)
                    {
                        sprintf(buff,"ERROR:  Could not open Opacity sequential bitmap '%s'",
                                     tfname);
                        gfx_continu_line(buff);
                        goto error_exit;
                    }

                    write_to_log("O: Sequential sorted maps");
                    for(int k=0; k < tseq_count; k++)
                        write_to_log(&tseq_names[256*k]);

                    if (mtl_animatedtxt
                        && (tseq_count > (ulong)mtlhdr.nframes))
                        mtlhdr.nframes = (ushort)tseq_count;

                    tbm=capture_mtlbitmap(tseq_names, 0,
                                          &mtlhdr.xsize, &mtlhdr.ysize, 1);
                    if (!tbm)
                    {
                        sprintf(buff,"ERROR:  Error loading Opacity sequential bitmap %s",
                                     get_root_from_fullname(tseq_names));
                        gfx_continu_line(buff);
                        goto error_exit;
                    }
                }
                else
                {
                    tbm=capture_mtlbitmap(tfname, 1,
                                          &mtlhdr.xsize, &mtlhdr.ysize, 1);
                    if (!tbm)
                    {
                        sprintf(buff,"ERROR:  Error loading Opacity bitmap %s",
                                     tfname);
                        gfx_continu_line(buff);
                        goto error_exit;
                    }
                }
            }

            int bpp=1;

            //ÄÄÄ Finish header
            if (mtl_format == 2)
            {
                mtlhdr.type = (tbm) ? ESCH_MTL_TYPE_32BIT
                                    : ESCH_MTL_TYPE_24BIT;
                bpp = (tbm) ? 4 : 3;
            }
            else
            {
                mtlhdr.type = (tbm) ? ESCH_MTL_TYPE_8BIT_TRANSP
                                    : ESCH_MTL_TYPE_8BIT;
            }
            mtlhdr.compress = (mtl_compress)
                              ? ESCH_MTL_COMPRESS_RLE
                              : ESCH_MTL_COMPRESS_NONE;

            //ÄÄÄ Generate material form
            if (iff.newform((mtlhdr.nframes > 1)
                            ? iff.makeid('E','M','T','1')
                            : iff.makeid('E','M','T','L')))
            {
                sprintf(buff,"ERROR:  Cannot create EMTL/EMT1, error #%d", iff.error());
                gfx_continu_line(buff);
                goto error_exit;
            }

            //ÄÄÄ Output header
            if (iff.write(iff.makeid('M','H','D','R'),&mtlhdr,sizeof(mtlhdr)))
            {
                sprintf(buff,"ERROR:  Writing MHDR chunk, error #%d", iff.error());
                gfx_continu_line(buff);
                goto error_exit;
            }

            //ÄÄÄ Create body
            byte *body = new byte[mtlhdr.xsize * mtlhdr.ysize * bpp];
            if (!body)
            {
                gfx_continu_line("Out of memory!");
                goto error_exit;
            }

            byte *work = new byte[mtlhdr.xsize * mtlhdr.ysize * bpp];
            if (!work)
            {
                gfx_continu_line("Out of memory!");
                goto error_exit;
            }

            ushort fnumber=0, tfnumber=0;
            for(ushort frame=0;;)
            {
                switch (bpp)
                {
                    case 3:
                        {
                            BXPColor *bptr = bm;
                            byte *ptr = body;
                            for(int k=0; k < mtlhdr.xsize*mtlhdr.ysize; k++)
                            {
                                *(ptr++) = bptr->r;
                                *(ptr++) = bptr->g;
                                *(ptr++) = bptr->b;
                                bptr++;
                            }
                        }
                        break;
                    case 4:
                        {
                            BXPColor *bptr = bm, *tptr = tbm;
                            byte *ptr = body;
                            for(int k=0; k < mtlhdr.xsize*mtlhdr.ysize; k++)
                            {
                                *(ptr++) = bptr->r;
                                *(ptr++) = bptr->g;
                                *(ptr++) = bptr->b;

                                byte alpha = tptr->r;
                                if (alpha > tptr->g)
                                    alpha = tptr->g;
                                if (alpha > tptr->b)
                                    alpha = tptr->b;

                                *(ptr++) = alpha;
                                bptr++;
                                tptr++;
                            }
                        }
                        break;
                    default:
                        if (!pal)
                        {
                            gfx_continu_line("Need Palette!");
                            goto error_exit;
                        }
                        if (tbm)
                        {
                            BXPColor *bptr = bm, *tptr = tbm;
                            byte *ptr = body;
                            for(int k=0; k < mtlhdr.xsize*mtlhdr.ysize; k++)
                            {
                                if (tptr->r <= 10
                                    && tptr->g <= 10
                                    && tptr->b <= 10)
                                {
                                    *(ptr++) = (byte)VNGO_TRANSPARENT_COLOR;
                                }
                                else
                                {
                                    *(ptr++) = (byte)pal->get_index(
                                                        VngoColor24bit(bptr->r,
                                                                    bptr->g,
                                                                    bptr->b));
                                }
                                bptr++;
                                tptr++;
                            }
                        }
                        else
                        {
                            BXPColor *bptr = bm;
                            byte *ptr = body;
                            for(int k=0; k < mtlhdr.xsize*mtlhdr.ysize; k++)
                            {
                                *(ptr++) = (byte)pal->get_index(
                                                    VngoColor24bit(bptr->r,
                                                                bptr->g,
                                                                bptr->b));
                                bptr++;
                            }
                        }
                        break;
                }

                //ÄÄÄ Compress
                dword size=0;
                if (mtl_compress)
                {
                    switch (bpp)
                    {
                        case 3:
                            size = compress_rle_24bpp(mtlhdr.xsize, mtlhdr.ysize,
                                                    body, work);
                            break;
                        case 4:
                            size = compress_rle_32bpp(mtlhdr.xsize, mtlhdr.ysize,
                                                    body, work);
                            break;
                        default:
                            size = compress_rle_8bpp(mtlhdr.xsize, mtlhdr.ysize,
                                                    body, work);
                            break;
                    }
                }

                //ÄÄÄ Output body
                if (size)
                {
                    if (iff.write(iff.makeid('B','O','D','Y'),work,size))
                    {
                        sprintf(buff,"ERROR:  Writing BODY chunk, error #%d",
                                iff.error());
                        gfx_continu_line(buff);
                        goto error_exit;
                    }
                }
                else
                {
                    if (iff.write(iff.makeid('B','O','D','Y'),
                                body,mtlhdr.xsize * mtlhdr.ysize * bpp))
                    {
                        sprintf(buff,"ERROR:  Writing BODY chunk, error #%d",
                                iff.error());
                        gfx_continu_line(buff);
                        goto error_exit;
                    }
                }

                //ÄÄÄ Progress
                sprintf(buff,"%s [%d/%d]",
                             name,frame+1,mtlhdr.nframes);
                prompt_and_log(buff);

                //ÄÄÄ Advance frame
                frame++;
                if (frame >= mtlhdr.nframes)
                    break;

                //ÄÄÄ Load next Texture 1 frame in sequence
                if (raster)
                {
                    free(bm);
                    bm = capture_flcframe(fname, &flc, raster, raster_pix,
                                          &mtlhdr.xsize, &mtlhdr.ysize, 1);
                    if (!bm)
                    {
                        sprintf(buff,"ERROR:  Error loading Texture 1 flic %s",
                                     fname);
                        gfx_continu_line(buff);
                        goto error_exit;
                    }

                    fnumber++;
                }
                else if (seq_names)
                {
                    if (fnumber >= seq_count)
                        fnumber=0;
                    else
                        fnumber++;

                    free(bm);
                    bm=capture_mtlbitmap(&seq_names[256*fnumber], 0,
                                         &mtlhdr.xsize, &mtlhdr.ysize, 1);
                    if (!bm)
                    {
                        sprintf(buff,"ERROR:  Error loading Texture 1 sequential bitmap %s",
                                     get_root_from_fullname(&seq_names[256*fnumber]));
                        gfx_continu_line(buff);
                        goto error_exit;
                    }
                }

                //ÄÄÄ Load next Opacity frame in sequence
                if (traster)
                {
                    free(tbm);
                    tbm = capture_flcframe(tfname, &tflc, traster, traster_pix,
                                           &mtlhdr.xsize, &mtlhdr.ysize, 1);
                    if (!tbm)
                    {
                        sprintf(buff,"ERROR:  Error loading Opacity flic '%s'",
                                     tfname);
                        gfx_continu_line(buff);
                        goto error_exit;
                    }

                    tfnumber++;
                }
                else if (tseq_names)
                {
                    if (tfnumber >= tseq_count)
                        tfnumber=0;
                    else
                        tfnumber++;

                    free(tbm);
                    tbm=capture_mtlbitmap(&tseq_names[256*tfnumber], 0,
                                          &mtlhdr.xsize, &mtlhdr.ysize, 1);
                    if (!tbm)
                    {
                        sprintf(buff,"ERROR:  Error loading Opacity sequential bitmap %s",
                                     get_root_from_fullname(&tseq_names[256*tfnumber]));
                        gfx_continu_line(buff);
                        goto error_exit;
                    }
                }
            }

            //ÄÄÄ Finish form and cleanup
            if (work)
                delete [] work;

            if (body)
                delete [] body;

            if (raster)
            {
                pj_raster_unbind_ram(&raster);
                free(raster_pix);
                pj_flic_close(&flc);
            }
            if (traster)
            {
                pj_raster_unbind_ram(&traster);
                free(traster_pix);
                pj_flic_close(&tflc);
            }

            iff.leaveform();

            if (bm)
                free(bm);

            if (tbm)
                free(tbm);

            if (seq_names)
                free(seq_names);

            if (tseq_names)
                free(tseq_names);

            sprintf(buff,"%s written (%d by %d, %d frames) as ",
                         name,mtlhdr.xsize,mtlhdr.ysize,mtlhdr.nframes);
            switch(mtlhdr.type)
            {
                case ESCH_MTL_TYPE_32BIT:
                    strcat(buff,"32-bit");
                    break;
                case ESCH_MTL_TYPE_24BIT:
                    strcat(buff,"24-bit");
                    break;
                case ESCH_MTL_TYPE_8BIT_TRANSP:
                    strcat(buff,"8-bit xparent");
                    break;
                case ESCH_MTL_TYPE_8BIT:
                    strcat(buff,"8-bit");
                    break;
                default:
                    strcat(buff,"*unknown*");
            }

            if (mtlhdr.compress)
                strcat(buff," compressed");

            prompt_and_log(buff);
        }
    }

//ÄÄÄ Clean up and Return OK
    sprintf(buff,"Object '%s': Export Complete",idata->name);
    gfx_set_gasgauge(buff,1,1);

    if (everts)
        delete [] everts;

    if (efaces)
        delete [] efaces;

    if (emtls)
        delete [] emtls;

    if (mtlfnames)
        delete [] mtlfnames;

    iff.leaveform();

    return 0;

//ÄÄÄ Error Exit
error_exit:;

    if (everts)
        delete [] everts;

    if (efaces)
        delete [] efaces;

    if (emtls)
        delete [] emtls;

    if (mtlfnames)
        delete [] mtlfnames;

    return 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// merge_verticies                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC int merge_verticies( ItemData *idata, XVData *verts, XFData *faces )
{
    long nverts = idata->item.m.verts;

    XVData *vert = verts;
    for(int v=0; v < nverts; v++, vert++)
    {
        if (check_abort())
            return 1;

        gfx_set_gasgauge("",v,nverts);

        // Scam against all other verticies (we've already scanned below)
        XVData *vert2 = vert+1;
        for(int v2=v+1; v2 < nverts;)
        {
            if (vert->x == vert2->x
                && vert->y == vert2->y
                && vert->z == vert2->z)
            {
                // Remove references to merged vertex
                XFData *face = faces;
                for(int f=0; f < idata->item.m.faces; f++, face++)
                {
                    if (face->a == v2)
                        face->a = v;
                    else if (face->a > v2)
                        face->a--;

                    if (face->b == v2)
                        face->b = v;
                    else if (face->b > v2)
                        face->b--;

                    if (face->c == v2)
                        face->c = v;
                    else if (face->c > v2)
                        face->c--;
                }

                // Shift down by one (slow, but easy)
                if (v2 < (nverts-1))
                {
                    memcpy(vert2,vert2+1,
                           (nverts-v2-1) * sizeof(XVData));
                }

                nverts--;
            }
            else
            {
              v2++;
              vert2++;
            }
        }
    }

    idata->item.m.verts = nverts;

    return 0;
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
    mextents->minx = xmin * scale_3ds2esch;
    mextents->miny = zmin * scale_3ds2esch;
    mextents->minz = ymin * scale_3ds2esch;
    mextents->maxx = xmax * scale_3ds2esch;
    mextents->maxy = zmax * scale_3ds2esch;
    mextents->maxz = ymax * scale_3ds2esch;
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
    if (rad_sq > 0)
    {
        rad = sqrt(rad_sq);
    }
    else
    {
        prompt_and_log("!!! Error during quick extents computation");
        rad_sq = 1;  rad = 1;
    }

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
    mextents->cenx = cen.x * scale_3ds2esch;
    mextents->ceny = cen.y * scale_3ds2esch;
    mextents->cenz = cen.z * scale_3ds2esch;
    mextents->extent_radius = rad * scale_3ds2esch;
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
    double              dist_sq, max_sq=1.0;
    struct FloatPoint   dia1, dia2,
                        cen;

    max_sq=-FLT_MAX;

    long nverts = idata->item.m.verts;
    if (nverts <= 1)
    {
        return 1;
    }

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
    mextents->cenx = cen.x * scale_3ds2esch;
    mextents->ceny = cen.y * scale_3ds2esch;
    mextents->cenz = cen.z * scale_3ds2esch;

    if (max_sq > 0)
        mextents->extent_radius = (esch_sqrt(max_sq) / 2.0) * scale_3ds2esch;
    else
    {
        prompt_and_log("!!! Error during optimal extents computation");
        mextents->extent_radius = 1;
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// compress_rle_8bpp                                                        ³
//                                                                          ³
// Compresses a 8bpp pixel data set into a compressed worked buffer.        ³
// Returns the number of bytes in the compressed result or 0 if the         ³
// compressed version would take more than the original image size in bytes.³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC ulong compress_rle_8bpp(ushort w, ushort h, byte *data, byte *cdata)
{
    ulong   size = w*h;
    ulong   count = 0;

    byte *wptr = cdata;
    byte *ptr = data;

    for(int y=0; y < h; y++)
    {
        byte *lptr = 0;
        for(int i=0; i < w; ptr++)
        {
            //ÄÄÄ Scan for run
            byte *s=ptr;
            for(int j=0;
                (j < 127) && ((j+i+1) < w) && (*s == *(ptr+1));
                j++)
            {
                ptr++;
            }

            //ÄÄÄ Found run
            if (j > 0)
            {
                // Close last literal
                lptr=0;

                // Add rep run
                count += 2;
                if (count >= size)
                    return 0;

                *(wptr++) = (byte) (-(char)j);
                *(wptr++) = *ptr;

                i += j+1;
            }
            //ÄÄÄ Store literal
            else
            {
                if (lptr && *lptr < 127)
                {
                    // Add to literal
                    (*lptr)++;
                }
                else
                {
                    // Create new literal
                    if (++count >= size)
                        return 0;

                    lptr=wptr++;
                    *lptr = 0;
                }

                if (++count >= size)
                    return 0;

                *(wptr++) = *ptr;
                i++;
            }
        }
    }

    return count;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// compress_rle_24bpp                                                       ³
//                                                                          ³
// Compresses a 24bpp pixel data set into a compressed worked buffer.       ³
// Returns the number of bytes in the compressed result or 0 if the         ³
// compressed version would take more than the original image size in bytes.³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC ulong compress_rle_24bpp(ushort w, ushort h, byte *data, byte *cdata)
{
    ulong   size = w*h*3;
    ulong   count = 0;

    byte *wptr = cdata;
    byte *ptr = data;

    for(int y=0; y < h; y++)
    {
        byte *lptr = 0;
        for(int i=0; i < w; ptr += 3)
        {
            //ÄÄÄ Scan for run
            byte *s=ptr;
            for(int j=0;
                (j < 127) && ((j+i+1) < w)
                && (*s == *(ptr+3))
                && (*(s+1) == *(ptr+4))
                && (*(s+2) == *(ptr+5));
                j++)
            {
                ptr += 3;
            }

            //ÄÄÄ Found run
            if (j > 0)
            {
                // Close last literal
                lptr=0;

                // Add rep run
                count += 4;
                if (count >= size)
                    return 0;

                *(wptr++) = (byte) (-(char)j);
                *(wptr++) = *ptr;
                *(wptr++) = *(ptr+1);
                *(wptr++) = *(ptr+2);

                i += j+1;
            }
            //ÄÄÄ Store literal
            else
            {
                if (lptr && *lptr < 127)
                {
                    // Add to literal
                    (*lptr)++;
                }
                else
                {
                    // Create new literal
                    if (++count >= size)
                        return 0;

                    lptr=wptr++;
                    *lptr = 0;
                }

                count += 3;
                if (count >= size)
                    return 0;

                *(wptr++) = *ptr;
                *(wptr++) = *(ptr+1);
                *(wptr++) = *(ptr+2);
                i++;
            }
        }
    }

    return count;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// compress_rle_32bpp                                                       ³
//                                                                          ³
// Compresses a 32bpp pixel data set into a compressed worked buffer.       ³
// Returns the number of bytes in the compressed result or 0 if the         ³
// compressed version would take more than the original image size in bytes.³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC ulong compress_rle_32bpp(ushort w, ushort h, byte *data, byte *cdata)
{
    ulong   size = w*h*4;
    ulong   count = 0;

    byte *wptr = cdata;
    dword *ptr = (dword*)data;

    for(int y=0; y < h; y++)
    {
        byte *lptr = 0;
        for(int i=0; i < w; ptr++)
        {
            //ÄÄÄ Scan for run
            dword *s=ptr;
            for(int j=0;
                (j < 127) && ((j+i+1) < w)
                && (*s == *(ptr+1));
                j++)
            {
                ptr++;
            }

            //ÄÄÄ Found run
            if (j > 0)
            {
                // Close last literal
                lptr=0;

                // Add rep run
                count += 5;
                if (count >= size)
                    return 0;

                *(wptr++) = (byte) (-(char)j);
                *(wptr++) = *((byte*)ptr);
                *(wptr++) = *(((byte*)ptr)+1);
                *(wptr++) = *(((byte*)ptr)+2);
                *(wptr++) = *(((byte*)ptr)+3);

                i += j+1;
            }
            //ÄÄÄ Store literal
            else
            {
                if (lptr && *lptr < 127)
                {
                    // Add to literal
                    (*lptr)++;
                }
                else
                {
                    // Create new literal
                    if (++count >= size)
                        return 0;

                    lptr=wptr++;
                    *lptr = 0;
                }

                count += 4;
                if (count >= size)
                    return 0;

                *(wptr++) = *((byte*)ptr);
                *(wptr++) = *(((byte*)ptr)+1);
                *(wptr++) = *(((byte*)ptr)+2);
                *(wptr++) = *(((byte*)ptr)+3);
                i++;
            }
        }
    }

    return count;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° KeyFrames °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// export_keyframes                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
STATIC int export_keyframes()
{
    int         i;
    char        buff[256];
    XFParseIFF  iff;

    sprintf(buff,"Exporting All Keyframes");
    gfx_show_gasgauge(buff);
    report_and_log(buff);

//ÄÄÄ Open the key_output file
    strcpy (buff,key_output_path);
    if (key_output_path[strlen(key_output_path)-1] != '\\')
    {
        strcat(buff,"\\");
    }
    strcpy (buff, key_output_name);

    if (key_apnd)
    {
        if (iff.open(buff,XF_OPEN_WRITE))
        {
            sprintf (buff, "ERROR: Cannot open output file, error #%d",
                     iff.error());
            gfx_continu_line(buff);
            capture_terminate();
            return 1;
        }
        // this "should" put the file pointer to the end of the file
        iff.seekchunk(0);
    }
    else
    {
        if (iff.create(buff,0))
        {
            sprintf (buff, "ERROR: Cannot create output file, error #%d",
                     iff.error());
            gfx_continu_line(buff);
            capture_terminate();
            return 1;
        }
    }

    if (iff.newform(iff.makeid('K','E','Y','F')))
    {
        sprintf(buff,"ERROR:  Cannot create form KEYF, error #%d",
                iff.error());
        gfx_continu_line(buff);
        return 1;
    }

//ÄÄÄ Create keyframe form
    EschFileKeyframeHeader header;
    memset(&header,0,sizeof(header));

    strncpy ((char *)&header.m_type, (char *)&key[0].m_type, M_TYPE_LEN);
    header.flags = key_flags;

    // find the largest keyframe number
    header.key_depth = -1;
    for (i=0; i<actual_key_count; i++)
    {
        if ((long)key[i].frame_num > (long)header.key_depth)
        {
            header.key_depth = key[i].frame_num;
        }
    }
    // increment for the 0 frame.
    header.key_depth ++;


    if (header.flags & ESCH_KEYFRAME_CHAINING)
    {
        strcpy (header.chain, key_ctyp);
    }
    else
    {
        memset (header.chain,2,ESCH_MAX_NAME);
    }

    if (iff.write(iff.makeid('H','D','R',' '),&header, sizeof (header)))
    {
        sprintf(buff,"ERROR:  Writing HDR chunk, error #%d", iff.error());
        gfx_continu_line(buff);
        return 1;
    }

//ÄÄÄ Write keyframe chunks
    for (i=0; i < actual_key_count; i++)
    {
        if (format_mode == 1)
        {
            // rotations are in float
            EschFileKeyframe    out_key;

            str_to_upper(key[i].name);
            out_key.k_type = get_token(key[i].name);
            out_key.frame_num = key[i].frame_num;

// Following is for debug output.  Uncomment to view data at export time.
//            sprintf (buff, "k_type %d pit %f roll %f yaw %f", out_key.k_type,
//                                                              out_key.rotation[0],
//                                                              out_key.rotation[1],
//                                                              out_key.rotation[2]);
//            gfx_continu_line(buff);

            for (int j=0; j<3; j++)
            {
                if (key[i].rotation[j] > -0.0001 && key[i].rotation[j] < 0.0001)
                {
                    out_key.rotation[j] = 0.0f;
                }
                else
                {
                    out_key.rotation[j] = (float)key[i].rotation[j];
                }
            }

            if (iff.write(iff.makeid('K','E','Y','1'),&out_key,sizeof(out_key)))
            {
                sprintf(buff,"ERROR:  Writing KEY1 chunk %d, error #%d", i,
                        iff.error());
                gfx_continu_line(buff);
                return 1;
            }
        }
        else
        {
            EschFileKeyframeV1  out_key;

            str_to_upper(key[i].name);
            out_key.k_type = get_token(key[i].name);
            out_key.frame_num = key[i].frame_num;
            for (int j=0; j<3; j++)
            {
                out_key.rotation[j] = long(key[i].rotation[j] * 65536.0f);
            }

            if (iff.write(iff.makeid('K','E','Y',' '),&out_key,sizeof (out_key)))
            {
                sprintf(buff,"ERROR:  Writing KEY chunk %d, error #%d", i,
                        iff.error());
                gfx_continu_line(buff);
                return 1;
            }
        }
    }

    iff.leaveform();

    return 0;
}

esch_token esch_token_list[ESCH_KEYFRAME_TOKEN_COUNT] =
{
    "NONE",ESCH_KEYFRAME_NONE,
    "FOOTL",(ESCH_KEYFRAME_FOOT|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_LEFT)  ,
    "FOOTR",(ESCH_KEYFRAME_FOOT|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_RIGHT),
    "CALFL",(ESCH_KEYFRAME_SHIN|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_LEFT) ,
    "CALFR",(ESCH_KEYFRAME_SHIN|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_RIGHT),
    "SHINL",(ESCH_KEYFRAME_SHIN|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_LEFT) ,
    "SHINR",(ESCH_KEYFRAME_SHIN|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_RIGHT),
    "THIGHL",(ESCH_KEYFRAME_THIGH|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_LEFT) ,
    "THIGHR",(ESCH_KEYFRAME_THIGH|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_RIGHT),
    // UPLEG-L through ARM-R1 are leading/trailing swapped for a Panzer related problem...
    "UPLEG-L",(ESCH_KEYFRAME_THIGH|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_LEFT),
    "UPLEG-R",(ESCH_KEYFRAME_THIGH|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_RIGHT) ,
    "LOLEG-L",(ESCH_KEYFRAME_SHIN|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_LEFT) ,
    "LOLEG-R",(ESCH_KEYFRAME_SHIN|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_RIGHT),
    "FOOT-L",(ESCH_KEYFRAME_FOOT|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_LEFT)  ,
    "FOOT-R",(ESCH_KEYFRAME_FOOT|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_RIGHT),
    "ARM-L",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "ARM-R",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "ARM-L1",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "ARM-R1",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "ARMWEAP1",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_WEAP1),
    "ARMWEAPF1",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_WEAP1F),
    "ARMWEAP2",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_WEAP2),
    "ARMWEAPF2",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_WEAP2F),
    "ARMWEAP3",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_WEAP3),
    "ARMWEAPF3",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_WEAP3F),
    "U_ARML",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "U_ARMR",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "F_ARML",(ESCH_KEYFRAME_FOREARM|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "F_ARMR",(ESCH_KEYFRAME_FOREARM|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "UARML",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "UARMR",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "FARML",(ESCH_KEYFRAME_FOREARM|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "FARMR",(ESCH_KEYFRAME_FOREARM|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "UPARML",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "UPARMR",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "HANDL",(ESCH_KEYFRAME_HAND|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "HANDR",(ESCH_KEYFRAME_HAND|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "BODY",ESCH_KEYFRAME_TORSOM,
    "TORSO",ESCH_KEYFRAME_TORSOM,
    "HEAD",ESCH_KEYFRAME_HEADM,
    "DOME",ESCH_KEYFRAME_DOMEM,
    "WAIST",ESCH_KEYFRAME_WAISTM,
    "HIPL",(ESCH_KEYFRAME_HIP|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_LEFT)  ,
    "HIPR",(ESCH_KEYFRAME_HIP|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_RIGHT),
    "SHLDRL",(ESCH_KEYFRAME_SHLDR|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "SHLDRR",(ESCH_KEYFRAME_SHLDR|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "MISC",ESCH_KEYFRAME_MISC,
    "ALL",ESCH_KEYFRAME_ALL,
    "ATG",0x41000,
    "AMMO",0x42000,
    "BARREL",0x40800,
    "GUNNER",0x40200,
    "SHELL",0x40400
};


void init_key_data()
{
    int status;
    int count;
    int key_count;
    int morph_key_count;

    actual_key_count = 0;

    kxp_init_keyframer ();
    kxp_get_node_count (count);
    for (int i=0; i<count; i++)
    {
        kxp_get_key_count(i, KT_ROTATE, key_count, status);
        kxp_get_key_count (i, KT_MORPH, morph_key_count, status);
        if (key_count > 0)
        {
            actual_key_count += key_count;
        }
        else if (morph_key_count > 0)
        {
            actual_morph_count += morph_key_count;
        }
    }

    if (actual_key_count)
    {
        morph_key = 0;
        key = new struct keyframe[actual_key_count];
        memset (key[i].name, 0, sizeof (key[i].name));
    }
    else if (actual_morph_count)
    {
        key = 0;
        morph_key = new struct morph_keyframe[actual_morph_count];
        for (i=0; i<actual_morph_count; i++)
        {
            morph_key[i].name[0] = '\0';
            morph_key[i].deltas = 0;
        }
    }
    else
    {
        key = 0;
        morph_key = 0;
    }
}


void capture_hierarchy_rotations()
{
    // start with the ultimate parent OBJECT_NODE
    // calculate the matrix for said parent
    // step through all of this object's children and
    // calculate the child matrix and concatenate it to
    //  the parent matrix to get the child rotation
    float matrix[4][3];
    float z_vec[3];
    float refv[3];
    float rot[3];
    int the_parent;
    int node_type;
    int child_count;
    int this_node;
    int status;
    int key_count;
    int count;
    int child_node;
    char dump[80];
    char name[22];

    next_key = 0;

    kxp_get_node_count(count);
    for (int i=0; i<count; i++)
    {
        kxp_get_parent (i, the_parent);
        kxp_get_node_name (i,name,node_type);
        if ((the_parent == -1) && (node_type == OBJECT_NODE))
        {
            this_node = i;
            break;
        }
    }

    kxp_get_key_count(this_node,KT_ROTATE,key_count,status);
    for (int j=0; j<key_count; j++)
    {
        key[next_key].frame_num = j;
        kxp_get_xform(this_node,j,&matrix[0][0]);

        if (!inverse_mtx(&matrix[0][0], &matrix[0][0]))
        {
            sprintf (dump, "Determinant is 0");
            gfx_continu_line(dump);
            return;
        }

        refv[0] = 0;
        refv[1] = 1;
        refv[2] = 0;

        z_vec[0] = 0;
        z_vec[1] = matrix[1][0]*refv[0] +
                   matrix[1][1]*refv[1] +
                   matrix[1][2]*refv[2];
        z_vec[2] = matrix[2][0]*refv[0] +
                   matrix[2][1]*refv[1] +
                   matrix[2][2]*refv[2];

        // normalize z_vec
        float mag = sqrt(z_vec[0]*z_vec[0] + z_vec[1]*z_vec[1] + z_vec[2]*z_vec[2]);
        for (i=0; i<3; i++)
        {
            z_vec[i] /= mag;
        }

        // take DOT PRODUCT of i and z_vec
        rot[0] = refv[0]*z_vec[0] + refv[1]*z_vec[1] + refv[2]*z_vec[2];
        if (z_vec[1] < 0)
        {
            rot[0] *= (-1);
        }
                rot[0] = RADS_2_DEGS(acos(rot[0]));
        if (z_vec[1] < 0)
        {
            rot[0] -= 180;
        }


        refv[0] = 1;
        refv[1] = 0;
        refv[2] = 0;

        z_vec[0] = matrix[0][0]*refv[0] +
                   matrix[0][1]*refv[1] +
                   matrix[0][2]*refv[2];
        z_vec[1] = 0;
        z_vec[2] = matrix[2][0]*refv[0] +
                   matrix[2][1]*refv[1] +
                   matrix[2][2]*refv[2];

        // normalize z_vec
        mag = sqrt(z_vec[0]*z_vec[0] + z_vec[1]*z_vec[1] + z_vec[2]*z_vec[2]);
        for (i=0; i<3; i++)
        {
            z_vec[i] /= mag;
        }

        // take DOT PRODUCT of j and z_vec
        rot[1] = refv[0]*z_vec[0] + refv[1]*z_vec[1] + refv[2]*z_vec[2];
        if (z_vec[0] < 0)
        {
            rot[1] *= (-1);
        }
                rot[1] = RADS_2_DEGS(acos(rot[1]));
        if (z_vec[0] < 0)
        {
            rot[1] -= 180;
        }

        refv[0] = 1;
        refv[1] = 0;
        refv[2] = 0;

        z_vec[0] = matrix[0][0]*refv[0] +
                   matrix[0][1]*refv[1] +
                   matrix[0][2]*refv[2];
        z_vec[1] = matrix[1][0]*refv[0] +
                   matrix[1][1]*refv[1] +
                   matrix[1][2]*refv[2];
        z_vec[2] = 0;

        // normalize z_vec
        mag = sqrt(z_vec[0]*z_vec[0] + z_vec[1]*z_vec[1] + z_vec[2]*z_vec[2]);
        for (i=0; i<3; i++)
        {
            z_vec[i] /= mag;
        }

        // take DOT PRODUCT of k and z_vec
        rot[2] = refv[0]*z_vec[0] + refv[1]*z_vec[1] + refv[2]*z_vec[2];
        if (z_vec[0] < 0)
        {
            rot[2] *= (-1);
        }
        rot[2] = RADS_2_DEGS(acos(rot[2]));
        if (z_vec[0] < 0)
        {
            rot[2] -= 180;
        }

        for (i=0; i<3; i++)
        {
            key[next_key].rotation[i] = rot[i];
        }
        strcpy (key[next_key].m_type, key_mtyp);
        strcpy (key[next_key].name, name);

        next_key ++;
    }

    kxp_get_num_children(this_node,child_count);

    for (i=0; i<child_count; i++)
    {
        kxp_get_child(this_node,i,child_node);
        kxp_get_key_count(child_node,KT_ROTATE,key_count,status);
        for (int j=0; j<key_count; j++)
        {
            process_child(this_node, child_node, j);
        }
    }
}


void process_child (int parent, int this_node, int this_keyframe)
{
    float matrix_par[4][3];
    float matrix_new[4][3];
    float matrix[4][3];
    float z_vec[3];
    float refv[3];
    float rot[3];
    int node_type;
    int child_count;
    int key_count;
    int child_node;
    int status;
    int i;
    char dump[80];
    char name[22];

    // check to see if this keyframe has already been processed
    for (i=0; i<actual_key_count; i++)
    {
        if (key[i].frame_num == this_keyframe)
        {
            kxp_get_node_name(this_node,name,status);
            if (!strcmp(name,key[i].name))
            {
                // name and keyframe match, so return
                return;
            }
        }
    }

    kxp_get_xform(parent,this_keyframe,&matrix_par[0][0]);
    kxp_get_xform(this_node,this_keyframe,&matrix_new[0][0]);

    if (!inverse_mtx(&matrix_par[0][0], &matrix_par[0][0]))
    {
        sprintf (dump, "Determinant is 0");
        gfx_continu_line(dump);
        return;
    }
    concat_mtx(&matrix_par[0][0], &matrix_new[0][0], &matrix[0][0]);

    refv[0] = 0;
    refv[1] = 1;
    refv[2] = 0;

    z_vec[0] = 0;
    z_vec[1] = matrix[1][0]*refv[0] +
               matrix[1][1]*refv[1] +
               matrix[1][2]*refv[2];
    z_vec[2] = matrix[2][0]*refv[0] +
               matrix[2][1]*refv[1] +
               matrix[2][2]*refv[2];

    // normalize z_vec
    float mag = sqrt(z_vec[0]*z_vec[0] + z_vec[1]*z_vec[1] + z_vec[2]*z_vec[2]);
    for (i=0; i<3; i++)
    {
        z_vec[i] /= mag;
    }

    // take DOT PRODUCT of i and z_vec

    rot[0] = refv[0]*z_vec[0] + refv[1]*z_vec[1] + refv[2]*z_vec[2];
    if (z_vec[2] < 0)
    {
        rot[0] *= (-1);
    }
    rot[0] = RADS_2_DEGS(acos(rot[0]));
    if (z_vec[2] < 0)
    {
        rot[0] -= 180;
    }

    refv[0] = 1;
    refv[1] = 0;
    refv[2] = 0;

    z_vec[0] = matrix[0][0]*refv[0] +
               matrix[0][1]*refv[1] +
               matrix[0][2]*refv[2];
    z_vec[1] = 0;
    z_vec[2] = matrix[2][0]*refv[0] +
               matrix[2][1]*refv[1] +
               matrix[2][2]*refv[2];

    // normalize z_vec
    mag = sqrt(z_vec[0]*z_vec[0] + z_vec[1]*z_vec[1] + z_vec[2]*z_vec[2]);
    for (i=0; i<3; i++)
    {
        z_vec[i] /= mag;
    }

    // take DOT PRODUCT of j and z_vec
    rot[1] = refv[0]*z_vec[0] + refv[1]*z_vec[1] + refv[2]*z_vec[2];
    if (z_vec[2] < 0)
    {
        rot[1] *= (-1);
    }
    rot[1] = RADS_2_DEGS(acos(rot[1]));
    if (z_vec[2] < 0)
    {
        rot[1] -= 180;
    }

    refv[0] = 1;
    refv[1] = 0;
    refv[2] = 0;

    z_vec[0] = matrix[0][0]*refv[0] +
               matrix[0][1]*refv[1] +
               matrix[0][2]*refv[2];
    z_vec[1] = matrix[1][0]*refv[0] +
               matrix[1][1]*refv[1] +
               matrix[1][2]*refv[2];
    z_vec[2] = 0;

    // normalize z_vec
    mag = sqrt(z_vec[0]*z_vec[0] + z_vec[1]*z_vec[1] + z_vec[2]*z_vec[2]);
    for (i=0; i<3; i++)
    {
        z_vec[i] /= mag;
    }

    // take DOT PRODUCT of k and z_vec
    rot[2] = refv[0]*z_vec[0] + refv[1]*z_vec[1] + refv[2]*z_vec[2];
    if (z_vec[1] < 0)
    {
        rot[2] *= (-1);
    }
    rot[2] = RADS_2_DEGS(acos(rot[2]));
    if (z_vec[1] < 0)
    {
        rot[2] -= 180;
    }

    kxp_get_node_name(this_node,name,node_type);
    strcpy(key[next_key].name, name);
    key[next_key].frame_num = this_keyframe;

    strcpy (key[next_key].m_type, key_mtyp);
    for (i=0; i<3; i++)
    {
        key[next_key].rotation[i] = rot[i];
    }

    next_key ++;

    kxp_get_num_children(this_node,child_count);
    for (i=0; i<child_count; i++)
    {
        kxp_get_child(this_node,i,child_node);
        kxp_get_key_count(child_node,KT_ROTATE,key_count,status);
        for (int j=0; j<key_count; j++)
        {
            process_child(this_node, child_node, j);
        }
    }
}


esch_limb_type get_token (char name[22])
{
    char buff[256];
    for (int i=0; i<ESCH_KEYFRAME_TOKEN_COUNT; i++)
    {
        if (strstr(esch_token_list[i].name, &name[0]))
        {
            return esch_token_list[i].type;
        }
    }
    return ESCH_KEYFRAME_NONE;
}

void str_to_upper (char str[22])
{
    char *ptr = str;
    for (int i=0; i<22; i++)
    {
        if (ptr == '\0')
        {
            return;
        }
        else
        {
            *ptr = toupper(*ptr);
        }
        ptr ++;
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Misc °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// det_mtx                                                                  ³
//                                                                          ³
// Computes the determinment of a matrix.                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
float det_mtx(float *m)
{
    double  r;

//     [A B C 0]
// det [D E F 0] =  A |E F 0|  - B |D F 0|  + C |D E 0|   - 0 |D E F|
//     [G H I 0]      |H I 0|      |G I 0|      |G H 0|       |G H I|
//     [J K L 1]      |K L 1|      |J L 1|      |J K 1|       |H K L|
//
//
//               =  A(                )
//                   ( E|I 0| - F|H 0|)
//                   (  |L 1|    |K 1|)
//
//                 -B(                )
//                   ( D|I 0| - F|G 0|)
//                   (  |L 1|    |J 1|)
//
//                 +C(                )
//                   ( D|H 0| - E|G 0|)
//                   (  |K 1|    |J 1|)
//
//               =  A(EI - FH) - B(DI - FG) + C(DH - EG)

// A |E F 0|
//   |H I 0| = A (EI - FH)
//   |K L 1|

    r = m[MTX_A] * ( m[MTX_E]*m[MTX_I] - m[MTX_F]*m[MTX_H] );

// - B |D F 0|
//     |G I 0| = - B (DI - FG)
//     |J L 1|

    r = r - m[MTX_B] * ( m[MTX_D]*m[MTX_I] - m[MTX_F]*m[MTX_G] );

// C |D E 0|
//   |G H 0| = C (DH - EG)
//   |J K 1|

    return (r + m[MTX_C] * ( m[MTX_D]*m[MTX_H] - m[MTX_E]*m[MTX_G] ));
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// inverse_mtx                                                              ³
//                                                                          ³
// Computes the inverse of a 4x3 matrix, returning it in 'inv' and a value  ³
// of 1.  If no inverse exists, 0 is returned.                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int inverse_mtx(float *m, float *inv)
{
    double  det;
    double  iv1, iv2, iv3;
    float   tm[12];

    det = det_mtx(m);

    if (det == 0.0)
        return 0;

    memcpy(tm,m,sizeof(float)*12);

// [A B C 0]      det is A(EI - FH) - B(DI - FG) + C(DH - EG)
// [D E F 0]
// [G H I 0]
// [J K L 1]      The inverse is :-
//
//
//                [ |E F 0|   |B C 0|   |B C 0|   |B C 0| ]
//                [ |H I 0|  -|H I 0|   |E F 0|  -|E F 0| ]
//                [ |K L 1|   |K L 1|   |K L 1|   |H I 0| ]
//                [                                       ]
//                [ |D F 0|   |A C 0|   |A C 0|   |A C 0| ]
//          1     [-|G I 0|   |G I 0|  -|D F 0|   |D F 0| ]
//        ----- * [ |J L 1|   |J L 1|   |J L 1|   |G I 0| ]
//         det    [                                       ]
//                [ |D E 0|   |A B 0|   |A B 0|   |A B 0| ]
//                [ |G H 0|  -|G H 0|   |D E 0|  -|D E 0| ]
//                [ |J K 1|   |J K 1|   |J K 1|   |G H 0| ]
//                [                                       ]
//                [ |D E F|   |A B C|   |A B C|   |A B C| ]
//                [-|G H I|   |G H I|  -|D E F|   |D E F| ]
//                [ |J K L|   |J K L|   |J K L|   |G H I| ]
//

// <A>
//     1      |E F 0|
//   ----- *  |H I 0| = ( EI - FH ) / det
//    det     |K L 1|

    inv[MTX_A] = (tm[MTX_E]*tm[MTX_I] - tm[MTX_F]*tm[MTX_H]) / det;

// <D>
//     1      |D F 0|
//   ----- * -|G I 0| = ( FG - DI ) / det
//    det     |J L 1|

    inv[MTX_D] = (tm[MTX_F]*tm[MTX_G] - tm[MTX_D]*tm[MTX_I]) / det;

// <G>
//     1      |D E 0|
//   ----- *  |G H 0| = ( DH - EG ) / det
//    det     |J K 1|

    inv[MTX_G] = (tm[MTX_D]*tm[MTX_H] - tm[MTX_E]*tm[MTX_G]) / det;

// <J>
//     1      |D E F|       <IV1>      <IV2>      <IV3>
//   ----- * -|G H I| = ( E(GL-IJ) - D(HL-KI) - F(GK-JH) ) / det
//    det     |J K L|

    iv1 = tm[MTX_G]*tm[MTX_L] - tm[MTX_I]*tm[MTX_J];
    iv2 = tm[MTX_H]*tm[MTX_L] - tm[MTX_K]*tm[MTX_I];
    iv3 = tm[MTX_G]*tm[MTX_K] - tm[MTX_J]*tm[MTX_H];

    inv[MTX_J] = (tm[MTX_E]*iv1 - tm[MTX_D]*iv2 - tm[MTX_F]*iv3) / det;

// <B>
//     1      |B C 0|
//   ----- * -|H I 0| = ( CH - BI ) / det
//    det     |K L 1|

    inv[MTX_B] = (tm[MTX_C]*tm[MTX_H] - tm[MTX_B]*tm[MTX_I]) / det;

// <E>
//     1      |A C 0|
//   ----- *  |G I 0| = ( AI - CG ) / det
//    det     |J L 1|

    inv[MTX_E] = (tm[MTX_A]*tm[MTX_I] - tm[MTX_C]*tm[MTX_G]) / det;

// <H>
//     1      |A B 0|
//   ----- * -|G H 0| = ( BG - AH ) / det
//    det     |J K 1|

    inv[MTX_H] = (tm[MTX_B]*tm[MTX_G] - tm[MTX_A]*tm[MTX_H]) / det;

// <K>
//     1      |A B C|       <IV2>      <IV1>      <IV3>
//   ----- *  |G H I| = ( A(HL-KI) - B(GL-JI) + C(GK-JH) ) / det
//    det     |J K L|

    inv[MTX_K] = (tm[MTX_A]*iv2 - tm[MTX_B]*iv1 + tm[MTX_C]*iv3) / det;

// <C>
//     1      |B C 0|
//   ----- *  |E F 0| = ( BF - CE ) / det
//    det     |K L 1|

    inv[MTX_C] = (tm[MTX_B]*tm[MTX_F] - tm[MTX_C]*tm[MTX_E]) / det;

// <F>
//     1      |A C 0|
//   ----- * -|D F 0| = ( CD - AF ) / det
//    det     |J L 1|

    inv[MTX_F] = (tm[MTX_C]*tm[MTX_D] - tm[MTX_A]*tm[MTX_F]) / det;

// <I>
//     1      |A B 0|
//   ----- *  |D E 0| = ( AE - BD ) / det
//    det     |J K 1|

    inv[MTX_I] = (tm[MTX_A]*tm[MTX_E] - tm[MTX_B]*tm[MTX_D]) / det;

// <L>
//     1      |A B C|
//   ----- * -|D E F| = ( B(DL-JF) - A(EL-KF) - C(DK-JE) ) / det
//    det     |J K L|

    inv[MTX_L] = ( tm[MTX_B]*( tm[MTX_D]*tm[MTX_L] - tm[MTX_J]*tm[MTX_F] )
                   - tm[MTX_A]*( tm[MTX_E]*tm[MTX_L] - tm[MTX_K]*tm[MTX_F] )
                   - tm[MTX_C]*( tm[MTX_D]*tm[MTX_K] - tm[MTX_J]*tm[MTX_E] )
                 ) / det;

    return 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// concat_mtx                                                               ³
//                                                                          ³
// Concats two matricies by multiplying them.                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void concat_mtx(float *ina, float *b, float *res)
{
    float   a[12];

    memcpy(a,ina,sizeof(float)*12);

// [A B C 0]      [a b c 0]    [Aa+Bd+Cg   Ab+Be+Ch   Ac+Bf+Ci   0]
// [D E F 0]      [d e f 0]    [Da+Ed+Fg   Db+Ee+Fh   Dc+Ef+Fi   0]
// [G H I 0]  *   [g h i 0] =  [Ga+Hd+Ig   Gb+He+Ih   Gc+Hf+Ii   0]
// [J K L 1]      [j k l 1]    [Ja+Kd+Lg+j Jb+Ke+Lh+k Jc+Kf+Li+l 1]

// Calculate the new a: Aa+Bd+Cg

    res[MTX_A] = a[MTX_A]*b[MTX_A] + a[MTX_B]*b[MTX_D] + a[MTX_C]*b[MTX_G];

// Calculate the new b: Ab+Be+Ch

    res[MTX_B] = a[MTX_A]*b[MTX_B] + a[MTX_B]*b[MTX_E] + a[MTX_C]*b[MTX_H];

// Calculate the new c: Ac+Bf+Ci

    res[MTX_C] = a[MTX_A]*b[MTX_C] + a[MTX_B]*b[MTX_F] + a[MTX_C]*b[MTX_I];

// Calculate the new d: Da+Ed+Fg

    res[MTX_D] = a[MTX_D]*b[MTX_A] + a[MTX_E]*b[MTX_D] + a[MTX_F]*b[MTX_G];

// Calculate the new e: Db+Ee+Fh

    res[MTX_E] = a[MTX_D]*b[MTX_B] + a[MTX_E]*b[MTX_E] + a[MTX_F]*b[MTX_H];

// Calculate the new f: Dc+Ef+Fi

    res[MTX_F] = a[MTX_D]*b[MTX_C] + a[MTX_E]*b[MTX_F] + a[MTX_F]*b[MTX_I];

// Calculate the new g: Ga+Hd+Ig

    res[MTX_G] = a[MTX_G]*b[MTX_A] + a[MTX_H]*b[MTX_D] + a[MTX_I]*b[MTX_G];

// Calculate the new h: Gb+He+Ih

    res[MTX_H] = a[MTX_G]*b[MTX_B] + a[MTX_H]*b[MTX_E] + a[MTX_I]*b[MTX_H];

// Calculate the new i: Gc+Hf+Ii

    res[MTX_I] = a[MTX_G]*b[MTX_C] + a[MTX_H]*b[MTX_F] + a[MTX_I]*b[MTX_I];

// Calculate the new j: Ja+Kd+Lg+j

    res[MTX_J] = a[MTX_J]*b[MTX_A] + a[MTX_K]*b[MTX_D] + a[MTX_L]*b[MTX_G] + b[MTX_J];

// Calculate the new k: Jb+Ke+Lh+k

    res[MTX_K] = a[MTX_J]*b[MTX_B] + a[MTX_K]*b[MTX_E] + a[MTX_L]*b[MTX_H] + b[MTX_K];

// Calculate the new l: Jc+Kf+Li+l

    res[MTX_L] = a[MTX_J]*b[MTX_C] + a[MTX_K]*b[MTX_F] + a[MTX_L]*b[MTX_I] + b[MTX_L];
}

//°±² End of module - export.cpp ²±°

