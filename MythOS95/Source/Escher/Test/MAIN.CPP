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
//ששששששששששששששששש Microsoft Windows 95/98/NT Version שששששששששששששששששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//שששCopyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbournששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
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
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
//
//                        http://www.mythos-engine.org/
//
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
//
// main.cpp
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define WIN32_LEAN_AND_MEAN
#include <stdlib.h>
#include "global.hpp"

#include "resource.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

STATIC int load_font(char *f);

// Imported from INIT.CPP
BOOL    InitApplication (HINSTANCE, int);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

HINSTANCE   hInst;
HWND        hWndClient;
const char  szAppName[] = "Escher";
EscherTest  *mode;

MaxDevices  *Devs=0;

extern ulong EschProposedTris;
extern ulong EschDrawnTris;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
// WinMain
//
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
int APIENTRY WinMain (HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPSTR     lpCmdLine,
                      int       nCmdShow)
{
        // Perform initializations.
    // If we are already running, this routine will reactivate the older
    // application and return FALSE.
        if (!InitApplication (hInstance, nCmdShow))
                return FALSE;

    // Initialize here.
    IvorySystem ivory (8*1024*1024);
    ChronosSystem   chronos;
    GBergSystem     gberg;
    EschSystem      *esys;
    VngoSystem      *vsys;

    if (load_font("8X13.IFF"))
        return FALSE;

    gberg_select_font("8x13");

    vsys=new VngoSystem;
    if (!vsys)
    {
        MessageBeep(0);
        MessageBox(hWndClient,
                   "Failed to initalize Van Gogh",
                   "Fatal Error",
                   MB_OK);
        return FALSE;
    }

    esys=new EschSystem;
    if (!esys
        || esys->init(262144,65536))
    {
        MessageBeep(0);
        MessageBox(hWndClient,
                   "Failed to initalize Escher",
                   "Fatal Error",
                   MB_OK);
        return FALSE;
    }

    Devs = new MaxDevicesWin32(hWndClient);
    if (!Devs)
    {
        MessageBeep(0);
        MessageBox(hWndClient,
                   "Failed to create max devices",
                   "Fatal Error",
                   MB_OK);
        return FALSE;
    }

    mode = new EscherTest (Devs);

    if (mode->screen == NULL)
    {
        MessageBeep(0);
        MessageBox(hWndClient,
                   "Failed to create the Screen",
                   "Fatal Error",
                   MB_OK);
        return FALSE;
    }

    mode->LoadEvents ("etevt.iff");
    if (!mode->active)
    {
        MessageBeep (0);
        MessageBox(hWndClient,
                   "Could not load event file",
                   "Fatal Error",
                   MB_OK);
        return FALSE;
    }

    XFParseINI  ini;
    char        buff[128];

    ini.open(".\\ET.INI",XF_OPEN_READ);

    ini.section("Screen");
    if (!ini.read("Gamma",buff))
    {
        float gamma = float(atof(buff));
        if (gamma < 0.5f)
             gamma = 0.5f;
        else if (gamma > 2.0f)
             gamma = 2.0f;

        vsys->set_gamma(gamma);
    }

    ini.section("Startup");

    if (!ini.read("AllowAMD3D",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
        {
            esys->enable_amd3d();
        }
    }

    if (!ini.read("BackgroundBMP",buff))
    {
        mode->backgrnd = new XFBitmap;
        if (!mode->backgrnd)
            return FALSE;

        XFParseBMP  bm(mode->backgrnd);

        if (bm.nameread(buff))
        {
            MessageBeep(0);
            MessageBox(hWndClient,
                       "Could not load bitmap background",
                       "Fatal Error",
                       MB_OK);
            return FALSE;
        }
    }

    if (!ini.read("TerrainSystem",buff))
    {
        strlwr(buff);
        if (strstr(buff,"new"))
            mode->use_new_terrain = TRUE;
    }


    if (!ini.read("PartitionTest",buff))
    {
        strlwr(buff);
        if (!mode->SetupPartitionTest(buff))
            return FALSE;
    }

    if (!ini.read("FireTest",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
        {
            if (!mode->SetupFireTest())
                return FALSE;
        }
    }

    if (!ini.read("MultiTest",buff))
    {
        strlwr(buff);
        if (!mode->SetupMultiTest(buff))
            return FALSE;
    }

    if (!ini.read("Sprite",buff))
    {
        strlwr(buff);
        if (!mode->SetupSprite(buff))
            return FALSE;
    }

    if (!ini.read("TextureFile",buff))
    {
        if (EschTexture::file_register(buff))
            return FALSE;
    }

    if (!ini.read("SceneFile",buff))
    {
        if (!mode->LoadScene(buff))
            return FALSE;
    }

    if (!ini.read("TreeTops",buff))
    {
        if (!mode->LoadTreeTops(buff))
            return FALSE;
    }
    if (!ini.read("TerrainFile",buff))
    {
        if (!mode->LoadTerrain(buff))
            return FALSE;
    }

    if (!ini.read("ParticleCount",buff))
    {
        mode->part_count = atoi(buff);
    }
    if (!ini.read("PartitionSpeed",buff))
    {
        mode->part_speed = float(atof(buff));
    }
    if (!ini.read("ParticleLife",buff))
    {
        mode->part_life = float(atof(buff));
    }
    if (!ini.read("ParticleAccel",buff))
    {
        strlwr(buff);
        if (strstr(buff,"nonlinear"))
            mode->part_linear=0;
    }
    if (!ini.read("ParticleAlpha",buff))
    {
        mode->part_alpha = atoi(buff);
    }
    if (!ini.read("ParticleRotRate",buff))
    {
        mode->part_rotrate = float(atof(buff));
    }
    if (!ini.read("ParticleRotRateLow",buff))
    {
        mode->part_rotrate_low = float(atof(buff));
    }
    if (!ini.read("ParticleRotRateHigh",buff))
    {
        mode->part_rotrate_high = float(atof(buff));
    }
    if (!ini.read("ParticleSystem",buff))
    {
        strlwr(buff);
        if (!mode->SetupParticleSystem(buff))
            return FALSE;
    }

    if (!ini.read("Starfield",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            if (!mode->SetupStarfield((strstr(buff,"ftl")) ? TRUE : FALSE,
                                      (strstr(buff,"brights")) ? TRUE : FALSE))
                return FALSE;
    }

    if (!ini.read("Explosion",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
        {
            if (!mode->SetupExplosion(buff))
                return FALSE;
        }
    }

    if (!ini.read("Metabox",buff))
    {
        strlwr(buff);
        if (!mode->SetupMetabox(buff))
            return FALSE;
    }

    if (!ini.read("Plane",buff))
    {
        strlwr(buff);
        if (!mode->SetupPlane(buff))
            return FALSE;
    }

    if (!ini.read("PickTest",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            mode->pick_test = TRUE;
    }

    if (!ini.read("CollideTest",buff))
    {
        strlwr(buff);
        if (strstr(buff,"yes") || strstr(buff,"on"))
            mode->collide_test = TRUE;
    }

    if (!ini.read("SkeletonFile",buff))
    {
        if (!mode->LoadScene(buff,(ESCH_SCENELD_ALL & ~ESCH_SCENELD_MESHES) |
                                  ESCH_SCENELD_SKELETON))
            return FALSE;
        mode->anim_root = (EschKeyframeDraw *)mode->scene->meshes;
    }

    if (!ini.read("AnimationTime",buff))
    {
        mode->anim_time = float(atof (buff));
    }

    if (!ini.read("AnimationStepTime",buff))
    {
        mode->anim_step_time = float(atof (buff));
    }

    if (!ini.read ("AnimationMaxCompress",buff))
    {
        mode->anim_max_compress = float(atof(buff));
    }

    if (!ini.read("AnimationTest",buff))
    {
        strlwr(buff);
        if (!mode->SetupAnimation(buff))
            return FALSE;
        mode->keyframe_animation = TRUE;
    }
    ini.close();

    if (!mode->cam)
    {
        MessageBeep(0);
        MessageBox(hWndClient,
                   "There is no camera defined",
                   "Fatal Error",
                   MB_OK);
        return FALSE;
    }

    mode->Begin();

        // Acquire and dispatch messages until a WM_QUIT message is received.
    while (mode->PumpWindows())
    {
        // Do per-frame processing here
        Devs->update ();
        mode->Animate();
        mode->GetEvents();
        mode->ProcessEvents();
        EschProposedTris = 0;
        EschDrawnTris = 0;
        mode->Render();
        mode->Display();
    }

//    char buff[128];
    mode->End(buff);

    if (esys->flags & ESCH_SYS_AMD3D)
        strcat(buff," AMD-3D Enabled\n");
    else if (esys->flags & ESCH_SYS_AMD3D_FOUND)
        strcat(buff," AMD-3D Disabled\n");

    // Clean up the mode here
    // (destructors get most of it)
    delete mode;

    MessageBox(hWndClient, buff,szAppName,
               MB_OK | MB_ICONINFORMATION);

    delete Devs;
    Devs=0;

    delete esys;
    delete vsys;

    return 0;

    // This shuts up the compiler
    lpCmdLine;
}

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
// load_font
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
STATIC int load_font(char *f)
{
    int err;

    err=gberg_install_font(f,0);
    if (err)
    {
        char    buff[128];
        sprintf(buff,"Failed to load font %s, error %d",f,(int)err);
        MessageBox(hWndClient,
                   buff,"Error",MB_OK);
        return 1;
    }
    return 0;
}

//°±² eof - main.cpp ²±°
