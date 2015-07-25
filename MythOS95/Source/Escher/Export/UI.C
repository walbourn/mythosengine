//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//שששששששששש°°°°°°°°°°ש°°°°°°°°ששש°°°°°°°°שש°°°שששש°°°ש°°°°°°°°°°ש°°°°°°°°°שש
//ששששששששש°±°ששששששש°±°שששש°±°ש°±°שששש°±°ש°±°שששש°±°ש°±°שששששששש°±°שששש°±°שש
//שששששששש±°±ששששששש±°±שששששששש±°±שששששששש±°±שששש±°±ש±°±שששששששש±°±שששש±°±ששש
//ששששששש±²±±°±±²שש±²±±°±±²±±ש±²±שששששששש±²±±°±±²±±ש±²±±°±±²ששש±²±±°±±²°ששששש
//שששששש±²±שששששששששששששש±²±ש±²±שששששששש±²±שששש±²±ש±²±שששששששש±²±שששש±²±ששששש
//ששששש²±²ששששששש²±²שששש²±²ש²±²שששש²±²ש²±²שששש²±²ש²±²שששששששש²±²שששש²±²שששששש
//שששש²²²²²²²²²²ש²²²²²²²²ששש²²²²²²²²שש²²²שששש²²²ש²²²²²²²²²²ש²²²שששש²²²ששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//שששששששששששCopyrightש(c)ש1994-1997שbyשCharybdisשEnterprises,שInc.שששששששששש
//ששששששששששששששששששששששששששAllשRightsשReserved.ששששששששששששששששששששששששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
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
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
//
// Created by Tim Little & Chuck Walbourn
//
//                       *** IPAS Mesh Data Exporter ***
//
// ui.c
//
// Contains the user-interface and control code for the object exporter.
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <debug.h>

#include "xfdefs.h"
#include "esdefs.h"

#include "pxp.h"
#include "dialog.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define VERSION "2.01"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ִִִ Feel functions
static void feel_ok(Dialog *d, int mouse);
static void feel_cancel(Dialog *d, int mouse);
static void feel_about(Dialog *d, int mouse);
static void feel_target(Dialog *d, int mouse);
static void feel_lights(Dialog *d, int mouse);
static void feel_keyframes(Dialog *d, int mouse);
static void feel_complete(Dialog *d, int mouse);
//static void feel_nyi(Dialog *d, int mouse);

//ִִִ Functions in other modules
void do_light();
void do_mtl();
void do_key();
void export();
void load_from_ini(char *inifname);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

static int do_export;
static int loop_done;

char output_path[128] = "C:\\";
char output_name[13] = "EXPORT.IFF";

char scene_name[17] = "EXPORT";

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// Make sure that 'empty' strings in .3DE file are filled with dummy values,³
// otherwise the compiler makes them all point to the same string, assuming ³
// it is static.  This is wrong and results in editables pointing to the    ³
// string.                                                                  ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
#include "escher.3de"

static FeelSub Escher_feel[] =
{
    OK,         feel_ok,
    CANCEL,     feel_cancel,
    ABOUT,      feel_about,
    TARGET,     feel_target,
    INC_LGTS,   feel_lights,
    KEYFRAME,   feel_keyframes,

    -1, FNULL
};

int source_mode=1;
int coord_mode=1;
int extent_mode=1;
int material_mode=1;
int hierarchy_mode=1;
int orientation_mode=1;
int format_mode=1;

dword  object_flags=0;

int    cameras_flag=0;
int    lights_flag=0;
int    keys_flag=0;

float  scale_3ds2esch=1.0;

float  scale_3ds=1.0;
float  scale_esh=1.0;

static RadSub Escher_rad[] =
{
    SOUR_ALL, feel_radio, &source_mode, 1,
    SOUR_SEL, feel_radio, &source_mode, 2,
    KEY_ONLY, feel_radio, &source_mode, 3,

    CORD_LOC, feel_radio, &coord_mode, 1,
    CORD_WRD, feel_radio, &coord_mode, 2,

    EXT_QUIK, feel_radio, &extent_mode, 1,
    EXT_OPT, feel_radio, &extent_mode, 2,

    MAT_PART, feel_radio, &material_mode, 1,
    MAT_COMP, feel_complete, &material_mode, 2,

    HIER_NON, feel_radio, &hierarchy_mode, 1,
    HIER_LNK, feel_radio, &hierarchy_mode, 2,

    ORI_DEF, feel_radio, &orientation_mode, 1,
    ORI_MTX, feel_radio, &orientation_mode, 2,

    FMT_FLT, feel_radio, &format_mode, 1,
    FMT_FIX, feel_radio, &format_mode, 2,

    -1, FNULL, NULL, -1
};

extern char mtl_palpath[];
extern char mtl_palname[];

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// about                                                                    ³
//                                                                          ³
// Display product's about information.                                     ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
void about(void)
{
    int x;

    gfx_alert(0,
       "[           Escher Data Exporter|"
       "             for 3D Studio R4|"
       "|"
       " (C) 1994-7 by Charybdis Enterprises, Inc.|"
       "        Version " VERSION "   " __DATE__ "]"
       "[ OK ]", x);
}


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// do_user_interaction                                                      ³
//                                                                          ³
// Entry point from client module called on startup operation.              ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
void do_user_interaction()
{
    int         cursor;
    float       t1, t2;
    Editable    *e;
    static int  inited = 0;

    char        file[16];
    char        path[128];
    char        buff[32];

    gfx_get_mform(cursor);
    gfx_set_mform(C_ARROW,0);

    gfx_report("");
    gfx_prompt("");
    gfx_prompt("");

    // Force mtl_pathname to point to process directory with ESPORT.VGP
    // as the filename.

    gfx_get_paths(GFX_PROCESS_PATH,0,path,file);

    strcpy(mtl_palpath,path);
    strcpy(mtl_palname,"ESPORT.VGP");

    if (! inited)
    {
        char buff[256];
        strcpy(buff,path);
        strcat(buff,"\\");
        strcat(buff,"ESPORT.INI");

        load_from_ini(buff);

        init_dialog(Escher, Escher_edit, NULL);
        inited = 1;
    }
    do_export=loop_done=0;

    gfx_get_paths(GFX_3DS_PATH,0,path,file);
    if (strstr(file,".3DS"))
    {
        *strstr(file,".3DS")=0;
        strcpy(scene_name,file);
        strcat(file,".IFF");
        strcpy(output_name,file);
        strcpy(output_path,path);
    }

    Escher[TARGET].text=output_name;

    ready_dialog(Escher, Escher_edit, NULL, Escher_feel, Escher_rad,
                NULL, NULL);

        init_editable(&Escher[SCN_NAME], scene_name);

    sprintf(buff,"%f",scale_3ds);
        init_editable(&Escher[SCAL_3DS], buff);

    sprintf(buff,"%f",scale_esh);
        init_editable(&Escher[SCAL_ESH], buff);

    Escher[INC_CAMS].radio = (cameras_flag) ? 1 : 0;
    Escher[INC_LGTS].radio = (lights_flag) ? 1 : 0;
    Escher[KEYFRAME].radio = (keys_flag) ? 1 : 0;

    Escher[FLAGS_0].radio = (object_flags & ESCH_MSH_APP0) ? 1 : 0;
    Escher[FLAGS_1].radio = (object_flags & ESCH_MSH_APP1) ? 1 : 0;
    Escher[FLAGS_2].radio = (object_flags & ESCH_MSH_APP2) ? 1 : 0;
    Escher[FLAGS_3].radio = (object_flags & ESCH_MSH_APP3) ? 1 : 0;
    Escher[FLAGS_4].radio = (object_flags & ESCH_MSH_APP4) ? 1 : 0;
    Escher[FLAGS_5].radio = (object_flags & ESCH_MSH_APP5) ? 1 : 0;
    Escher[FLAGS_6].radio = (object_flags & ESCH_MSH_APP6) ? 1 : 0;
    Escher[FLAGS_7].radio = (object_flags & ESCH_MSH_APP7) ? 1 : 0;
    Escher[FLAGS_8].radio = (object_flags & ESCH_MSH_APP8) ? 1 : 0;
    Escher[FLAGS_9].radio = (object_flags & ESCH_MSH_APP9) ? 1 : 0;
    Escher[FLAGS_A].radio = (object_flags & ESCH_MSH_APPA) ? 1 : 0;
    Escher[FLAGS_B].radio = (object_flags & ESCH_MSH_APPB) ? 1 : 0;
    Escher[FLAGS_C].radio = (object_flags & ESCH_MSH_APPC) ? 1 : 0;
    Escher[FLAGS_D].radio = (object_flags & ESCH_MSH_APPD) ? 1 : 0;
    Escher[FLAGS_E].radio = (object_flags & ESCH_MSH_APPE) ? 1 : 0;
    Escher[FLAGS_F].radio = (object_flags & ESCH_MSH_APPF) ? 1 : 0;

startover: ;

    while (!loop_done)
    {
        center_dialog(Escher);
        save_under_dialog(Escher);
        draw_dialog(Escher);
        do_dialog(Escher, -1);
    }

    if (do_export)
    {

        e=(Editable*)Escher[SCAL_3DS].text;
        t1=atof(e->string);
        if (t1 <= 0.0)
        {
            gfx_continu_line("Scale values must be positive and non-zero");
            loop_done=0;
            goto startover;
        }

        e=(Editable*)Escher[SCAL_ESH].text;
        t2=atof(e->string);
        if (t2 <= 0.0)
        {
            gfx_continu_line("Scale values must be positive and non-zero");
            loop_done=0;
            goto startover;
        }
        scale_3ds = t1;
        scale_esh = t2;
        scale_3ds2esch = t2 / t1;

        e=(Editable*)Escher[SCN_NAME].text;
        strncpy(scene_name,e->string,16);

        object_flags=0;
        if (Escher[FLAGS_0].radio)
            object_flags |= ESCH_MSH_APP0;
        if (Escher[FLAGS_1].radio)
            object_flags |= ESCH_MSH_APP1;
        if (Escher[FLAGS_2].radio)
            object_flags |= ESCH_MSH_APP2;
        if (Escher[FLAGS_3].radio)
            object_flags |= ESCH_MSH_APP3;
        if (Escher[FLAGS_4].radio)
            object_flags |= ESCH_MSH_APP4;
        if (Escher[FLAGS_5].radio)
            object_flags |= ESCH_MSH_APP5;
        if (Escher[FLAGS_6].radio)
            object_flags |= ESCH_MSH_APP6;
        if (Escher[FLAGS_7].radio)
            object_flags |= ESCH_MSH_APP7;
        if (Escher[FLAGS_8].radio)
            object_flags |= ESCH_MSH_APP8;
        if (Escher[FLAGS_9].radio)
            object_flags |= ESCH_MSH_APP9;
        if (Escher[FLAGS_A].radio)
            object_flags |= ESCH_MSH_APPA;
        if (Escher[FLAGS_B].radio)
            object_flags |= ESCH_MSH_APPB;
        if (Escher[FLAGS_C].radio)
            object_flags |= ESCH_MSH_APPC;
        if (Escher[FLAGS_D].radio)
            object_flags |= ESCH_MSH_APPD;
        if (Escher[FLAGS_E].radio)
            object_flags |= ESCH_MSH_APPE;
        if (Escher[FLAGS_F].radio)
            object_flags |= ESCH_MSH_APPF;

        cameras_flag = (Escher[INC_CAMS].radio) ? 1 : 0;
        lights_flag = (Escher[INC_LGTS].radio) ? 1 : 0;
        keys_flag = (Escher[KEYFRAME].radio) ? 1 : 0;

        export();
    }

    gfx_report("");
    gfx_prompt("");
    gfx_prompt("");
    gfx_set_mform(cursor,0);
}


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
//                            °°° static °°°                                ³
// Feel functions                                                           ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
static void feel_ok(Dialog *d, int mouse)
{
    if(mouse)
        if(!(press_button(d)))
            return;

    dialog_done=1;
    restore_under_dialog();

    loop_done=1;
    do_export=1;
}

static void feel_cancel(Dialog *d, int mouse)
{
    int status;

    if(mouse)
        if(!(press_button(d)))
            return;

    dialog_done=1;
    restore_under_dialog();

    gfx_yes_no_line("Exit without exporting?", status);
    if(status)
    {
        loop_done=1;
        do_export=0;
    }
}

static void feel_about(Dialog *d, int mouse)
{
    if(mouse)
        if(!(press_button(d)))
            return;

    dialog_done=1;
    restore_under_dialog();

    about();
}

static void feel_target(Dialog *d, int mouse)
{
    int     status;
    char    buff[128];
    char    extenders[11][4] = { "IFF", "",  "",  "",  "",  "",
                                "",  "",  "",  "",  "", };

    char    drive[XF_MAX_DRIVE];
    char    dir[XF_MAX_DIR];
    char    fname[XF_MAX_FNAME];
    char    ext[XF_MAX_EXT];

    if(mouse)
        if(!(press_button(d)))
            return;

    dialog_done=1;
    restore_under_dialog();

    for(;;)
    {
        if (output_path[strlen(output_path)-1]=='\\')
            output_path[strlen(output_path)-1]=0;

        gfx_file_selector("Escher Output File",
                         output_path,
                         output_name,
                         extenders,
                         buff);

        if (!*buff)
            return;

        if (access(buff,0)==0)
        {
            gfx_yes_no_line("File exists, overwrite?",status);
            if (status)
                break;
        }
        else
            break;
    }

    _splitpath(buff,drive,dir,fname,ext);

    strcpy(output_path,drive);
    strcat(output_path,dir);

    strcpy(output_name,fname);
    strcat(output_name,ext);
}

static void feel_lights(Dialog *d, int mouse)
{
    dialog_done=1;
    restore_under_dialog();
    do_light();
    d->radio = (lights_flag) ? 1 : 0;
}

static void feel_keyframes(Dialog *d, int mouse)
{
    dialog_done=1;
    restore_under_dialog();
    do_key();
    d->radio = (keys_flag) ? 1 : 0;
}

static void feel_complete(Dialog *d, int mouse)
{
    feel_radio(d,mouse);

    if (d->radio)
    {
        dialog_done=1;
        restore_under_dialog();
        do_mtl();
    }
}

//°±² End of module - ui.c ²±°
