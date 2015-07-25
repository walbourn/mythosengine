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
// GState.cpp
//
//  This file contains the member functions for the class that describes
//  the current game state.  This class also "runs" the game, but must
//  be driven by an outside program.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define WIN32_LEAN_AND_MEAN
#include "global.hpp"
#include "GFrame.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

const int COLORS = 256;

const int MAXPAGES = 3;

extern MaxDevices Devs;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
GameState::GameState (MaxDevices &d):
    devs (d),
    evt (0),
    hpal (0),
    active (FALSE),
    pick_test(FALSE),
    collide_test(FALSE),
    fire_test(FALSE),
    cam(0),
    light(0),
    draws(0),
    scene(0),
    terrain(0),
    prtsystem(0),
    starfield(0),
    sprite(0),
    curmesh(0),
    fire(0),
    drawexts(0),
    RotateDegrees(1),
    ScriptRotateDegrees(3),
    kind_of_particles(0),
    backgrnd (0),
    ticks (0),
    frames (0)
{
    hdc = GetDC (hWndClient);

    bmi = (LPBITMAPINFO)ivory_alloc (sizeof (BITMAPINFOHEADER) + COLORS*sizeof(WORD));
    if (bmi)
    {
        memset (bmi, 0, sizeof (*bmi));
        bmi->bmiHeader.biSize        = sizeof (BITMAPINFOHEADER);
        bmi->bmiHeader.biWidth       = MAP_XSIZE;
        bmi->bmiHeader.biHeight      = -MAP_YSIZE;
        bmi->bmiHeader.biPlanes      = 1;
        bmi->bmiHeader.biBitCount    = 8;
        bmi->bmiHeader.biCompression = BI_RGB;
        bmi->bmiHeader.biClrUsed     = COLORS;
        bmi->bmiHeader.biClrImportant= COLORS;

        gmap = new BYTE [MAP_XSIZE * MAP_YSIZE];
        // Init viewport?
        mypal = new VngoPal8;
        if (mypal)
        {
            if (mypal->init(0,".\\default.pal") != 0)
            {
                delete mypal;
                mypal = NULL;
            }
        }
        if (mypal)
        {
            VngoPal8 *t=(VngoPal8 *)mypal;
            LOGPALETTE *lpal = (LOGPALETTE *)ivory_alloc(sizeof(LOGPALETTE)+256*sizeof(PALETTEENTRY));
            lpal->palVersion = 0x300;
            lpal->palNumEntries = 256;

            for (int i=0; i < COLORS; i++)
            {
                ((WORD *)bmi->bmiColors)[i] = i;
                lpal->palPalEntry[i].peRed  = t->hw_pal.p[i].r;
                lpal->palPalEntry[i].peGreen= t->hw_pal.p[i].g;
                lpal->palPalEntry[i].peBlue = t->hw_pal.p[i].b;
                lpal->palPalEntry[i].peFlags= PC_NOCOLLAPSE;
            }

            // Force our palette into Windows

            // This should be a global; free it with DeleteObject (hpal);
            hpal = CreatePalette (lpal);

            SelectPalette (hdc, hpal, FALSE);
            RealizePalette (hdc);

            ivory_free ((void **)&lpal);

            gvp = new VngoVportDB8(MAP_XSIZE,MAP_YSIZE,gmap,NULL,mypal,
                                   VNGO_ZBUFFER_DEV);

            exts_color = mypal->get_index(VngoColor24bit(0,0,0));

            gberg_color(gvp->vbuff.pal->get_index(VngoColor24bit(255,255,255)),
                        VNGO_TRANSPARENT);
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
GameState::~GameState ()
{
    char    buff[128];

    if (hpal)
        DeleteObject(hpal);

    if (ticks > 0)
    {
        double frate  = (double)frames * 1000.0 / (double)ticks;

        sprintf(buff,"%d frames in %d ms, rate=%f",
               frames,ticks,frate);
        MessageBox(0,
                   buff,
                   "Escher Benchmark Information",
                   MB_OK | MB_ICONINFORMATION | MB_SYSTEMMODAL);
    }

    // Clean up our event source
    if (evt)
    {
        evt->uninstall();
        delete evt;
    }

    if (fire)
        delete fire;

    if (backgrnd)
        delete backgrnd;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::LoadEvents
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::LoadEvents (LPCSTR lpszFile)
{
    // remember the filename
    strcpy (szFileName, lpszFile);

    // If we have an old event system, kill it
    if (evt)
    {
        evt->uninstall();
        delete evt;
    }

    // Create a new system
    evt = new MaxEventUser (devs, szFileName, "gframe");

    // Verify the event system matches our set of events?

    // Now, let 'er rip!
    evt->install();
    active = TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::LoadScene
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL GameState::LoadScene(char *fn)
{
    int err;

    if (scene)
        return FALSE;

    scene = new EschScene;
    if (!scene)
        return FALSE;

    if ((err=scene->load(fn,0,mypal))!=0)
    {
        char buff[256];
        MessageBeep (0);
        sprintf(buff,"Could not load a scene from file '%s', error %d",fn,err);
        MessageBox(hWndClient,
                   buff,
                   "Fatal Error",
                   MB_OK);
        return FALSE;
    }

    if (!cam && scene->cameras)
    {
        cam = new EschCameraEx(*scene->cameras);
        cam->attach(gvp);
        cam->set_flags(cam->flags | ESCH_CAM_SHADE_SMOOTH
                                | ESCH_CAM_SHADE_FLAT
                                | ESCH_CAM_SHADE_SOLID
                                | ESCH_CAM_SHADE_WIRE
                                | ESCH_CAM_BACKCULL
                                | ESCH_CAM_MODELSPACE
                                | ESCH_CAM_TEXTURED);

        cam->set_bcolor(mypal->get_index(VngoColor24bit(0,0,128)));
        cam->set_yon(500);
        cam->set_bg_bitmap(backgrnd);
    }

    if (!light)
        light=scene->lights;

    if (scene->meshes)
    {
        curmesh=scene->meshes;

        if (fire_test)
        {
            fire = new EschFireTexture(128,128,mypal);
            if (!fire)
            {
                MessageBeep (0);
                MessageBox(hWndClient,
                        "Couldn't create fire texture",
                        "Fatal Error",
                        MB_OK);
                return FALSE;
            }

            if (curmesh && curmesh->txt)
            {
                curmesh->txt[0] = fire;
            }
            else
            {
                MessageBox(hWndClient,
                        "Couldn't put fire texture on first object",
                        "Error",
                        MB_OK);
            }
        }

        if (draws)
            ((EschDrawable*)scene->meshes)->sibling(draws);
        else
            draws = scene->meshes;
    }

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::LoadTerrain
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL GameState::LoadTerrain(char *fn)
{
    int err;

    if (terrain)
        return FALSE;

    terrain = new EschTerrain;
    if (!terrain)
        return FALSE;

    if ((err=terrain->load(fn,0))!=0)
    {
        char buff[256];
        MessageBeep (0);
        sprintf(buff,"Could not load a terrain from file '%s', error %d",fn,err);
        MessageBox(hWndClient,
                   buff,
                   "Fatal Error",
                   MB_OK);
        return FALSE;
    }
    terrain->set_lod(500,800);

    if (!cam)
    {
        cam = new EschCameraEx(gvp);
        cam->set_position(0,terrain->get_height(0,0) + Flx16(2),0);
        cam->set_flags(cam->flags | ESCH_CAM_SHADE_SMOOTH
                                | ESCH_CAM_SHADE_FLAT
                                | ESCH_CAM_SHADE_SOLID
                                | ESCH_CAM_SHADE_WIRE
                                | ESCH_CAM_BACKCULL
                                | ESCH_CAM_MODELSPACE
                                | ESCH_CAM_TEXTURED);
        cam->set_bcolor(mypal->get_index(VngoColor24bit(0,0,128)));
        cam->set_bg_bitmap(backgrnd);
    }
    cam->set_yon(2000);

    if (!light)
        light = new EschVectorLight(-1,-1,-1);

    terrain->compute_shades(cam, light);

    if (draws)
        terrain->sibling(draws);
    else
        draws = terrain;

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GameState - SetupParticleSystem
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL GameState::SetupParticleSystem(const char *name)
{
    if (prtsystem)
        return FALSE;

    prtsystem = new EschParticleSystem;
    if (!prtsystem
        || prtsystem->init(0xff))
    {
        MessageBeep (0);
        MessageBox(hWndClient,
                   "Could not create particle system",
                   "Fatal Error",
                   MB_OK);
        return FALSE;
    }

    prtsystem->set_acceleration(0,-8,0);
    prtsystem->set_interval(0.1);

    if (!cam)
    {
        cam = new EschCameraEx(gvp);
        cam->set_position(0,0,-100);
        cam->set_flags(cam->flags | ESCH_CAM_SHADE_SMOOTH
                                | ESCH_CAM_SHADE_FLAT
                                | ESCH_CAM_SHADE_SOLID
                                | ESCH_CAM_SHADE_WIRE
                                | ESCH_CAM_BACKCULL
                                | ESCH_CAM_MODELSPACE
                                | ESCH_CAM_TEXTURED);
        cam->set_bcolor(mypal->get_index(VngoColor24bit(0,0,128)));
        cam->set_bg_bitmap(backgrnd);
    }

    if (!light)
        light = new EschVectorLight(-1,-1,-1);

    if (strstr(name,"pyramids"))
        kind_of_particles=1;

    if (draws)
        prtsystem->sibling(draws);
    else
        draws = prtsystem;

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GameState - SetupStarfield
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL GameState::SetupStarfield(BOOL fixed, BOOL brights)
{
    if (starfield)
        return FALSE;

    starfield = new EschStarfield;
    if (!starfield
        || starfield->create_stars(1000,(brights) ? 1 : 0))
    {
        MessageBeep (0);
        MessageBox(hWndClient,
                   "Could not create starfield",
                   "Fatal Error",
                   MB_OK);
        return FALSE;
    }

    starfield->set_color(mypal->get_index(VngoColor24bit(255,255,255)));

    if (fixed)
        starfield->set_flags(starfield->flags | ESCH_SFLD_FTL);

    if (!cam)
    {
        cam = new EschCameraEx(gvp);
        cam->set_position(0,0,-300);
        cam->set_flags(cam->flags | ESCH_CAM_SHADE_SMOOTH
                                | ESCH_CAM_SHADE_FLAT
                                | ESCH_CAM_SHADE_SOLID
                                | ESCH_CAM_SHADE_WIRE
                                | ESCH_CAM_BACKCULL
                                | ESCH_CAM_MODELSPACE
                                | ESCH_CAM_TEXTURED);
        cam->set_bg_bitmap(backgrnd);
    }

    cam->set_bcolor(mypal->get_index(VngoColor24bit(0,0,0)));

    if (draws)
        starfield->sibling(draws);
    else
        draws = starfield;

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// GameState - SetupSprite
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL GameState::SetupSprite(const char *name)
{
    if (sprite)
        return FALSE;

    XFParseBMP bmp;
    if (bmp.nameread((strstr(name,",")) ? strstr(name,",")+1 : name))
    {
        MessageBeep (0);
        MessageBox(hWndClient,
                   (strstr(name,",")) ? strstr(name,",")+1 : name,
                   "Fatal Error",
                   MB_OK);
        return FALSE;
    }

    sprite = new EschSprite;
    if (!sprite
        || sprite->create(bmp.bm,10,10))
    {
        MessageBeep (0);
        MessageBox(hWndClient,
                   "Could not create sprite",
                   "Fatal Error",
                   MB_OK);
        return FALSE;
    }

    if (strstr(name,"infinite"))
    {
        sprite->set_position(0,0,100);
        sprite->set_flags(sprite->flags | ESCH_SPRITE_INFINITE);
    }

    if (!cam)
    {
        cam = new EschCameraEx(gvp);
        cam->set_position(0,0,-100);
        cam->set_flags(cam->flags | ESCH_CAM_SHADE_SMOOTH
                                | ESCH_CAM_SHADE_FLAT
                                | ESCH_CAM_SHADE_SOLID
                                | ESCH_CAM_SHADE_WIRE
                                | ESCH_CAM_BACKCULL
                                | ESCH_CAM_MODELSPACE
                                | ESCH_CAM_TEXTURED);
        cam->set_bg_bitmap(backgrnd);
    }

    cam->set_bcolor(mypal->get_index(VngoColor24bit(0,0,128)));

    if (draws)
        sprite->sibling(draws);
    else
        draws = sprite;

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::GetEvents
//
//      Get the events, and perform any internal processing based on their
//  presence.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::GetEvents()
{
    if (!evt)
    {
        events = MaxEventList (0);
        return;
    }

    // Otherwise, strobe the devices and get our events (and oneshots)
    events = evt->process ();
    single_events = oneshot.process (events);
    toggle_events = toggles.process (events);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::PumpWindows
//
//  Runs one cycle of the windows message pump.
//  Returns whether or not we should still be alive.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL GameState::PumpWindows ()
{
    MSG msg;

    Devs.wm_clear();
    while (PeekMessage (&msg, NULL, 0, 0, PM_NOREMOVE))
    {
    	if (GetMessage (&msg, 0, 0, 0) == 0)
            return FALSE;

        TranslateMessage (&msg);
        DispatchMessage (&msg);
    }
    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::ProcessEvents
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::ProcessEvents()
{
    int                 doreshade=0;
    short               dx, dy;
    dword               cam_flags;

    evt->get_mouse_movement (&dx, &dy);

    if (events.check (DONE))
        DestroyWindow (hWndClient);

    if (events.check (FASTER))
    {
        if (ScriptRotateDegrees < 180)
            ScriptRotateDegrees = ScriptRotateDegrees + (Flx16)1;
    }
    else if (events.check (SLOWER))
    {
        if (ScriptRotateDegrees > 1)
            ScriptRotateDegrees = ScriptRotateDegrees - (Flx16)1;
    }

    if (curmesh && scene)
    {
        if (single_events.check(OBJECT_NEXT))
        {
            if (curmesh->next() != NULL)
                curmesh = (EschMeshDraw*) curmesh->next();
        }
        if (single_events.check(OBJECT_PREV))
        {
             if (curmesh->prev() != NULL)
                 curmesh = (EschMeshDraw*) curmesh->prev();
        }
        if (single_events.check(OBJECT_CHILD))
        {
            if (curmesh->child() != NULL)
                curmesh = (EschMeshDraw*) curmesh->child();
            else
                curmesh = scene->meshes;
        }

        if (events.check(OBJECT_ROTATE))
        {
            if (events.check (MOVEXY))
            {
                curmesh->rotatex (-dy);
                curmesh->rotatey (-dx);
            }

            if (events.check (MOVEZ))
                curmesh->rotatez (-dx);

            if (events.check (UP))
                curmesh->rotatex (RotateDegrees);

            if (events.check (DOWN))
                curmesh->rotatex (-RotateDegrees);

            if (events.check (LEFT))
                curmesh->rotatey (RotateDegrees);

            if (events.check (RIGHT))
                curmesh->rotatey (-RotateDegrees);
        }

        if (events.check (OBJECT_MOVE))
        {
            if (events.check (MOVEXY))
            {
                EschVector v(dx, -dy, FLX16_ZERO);

                v.transform(&cam->eye.orient);

                curmesh->translate (&v);
            }

            if (events.check (MOVEZ))
            {
                EschVector v(FLX16_ZERO, FLX16_ZERO, -dy);

                v.transform(&cam->eye.orient);

                curmesh->translate (&v);
            }

            if (events.check (UP))
            {
                EschVector v(FLX16_ZERO, 1, FLX16_ZERO);

                v.transform(&cam->eye.orient);

                curmesh->translate (&v);
            }

            if (events.check (DOWN))
            {
                EschVector v(FLX16_ZERO, -1, FLX16_ZERO);

                v.transform(&cam->eye.orient);

                curmesh->translate (&v);
            }

            if (events.check (LEFT))
            {
                EschVector v(-1, FLX16_ZERO, FLX16_ZERO);

                v.transform(&cam->eye.orient);

                curmesh->translate (&v);
            }

            if (events.check (RIGHT))
            {
                EschVector v(1, FLX16_ZERO, FLX16_ZERO);

                v.transform(&cam->eye.orient);

                curmesh->translate (&v);
            }
        }
    }

    if (events.check (CAMERA_ROTATE))
    {
        if (events.check (MOVEXY))
        {
            cam->yaw (-dx);
            cam->pitch (-dy);
        }
        
        if (events.check (MOVEZ))
            cam->roll (-dx);

        if (events.check (UP))
            cam->pitch (RotateDegrees);

        if (events.check (DOWN))
            cam->pitch (-RotateDegrees);

        if (events.check (LEFT))
            cam->yaw (RotateDegrees);

        if (events.check (RIGHT))
            cam->yaw (-RotateDegrees);
    }

    // Check the camera translation options
    if (events.check (CAMERA_MOVE))
    {
        if (events.check (MOVEXY))
        {
            cam->move(-dx, dy, FLX16_ZERO);
        }

        if (events.check (MOVEZ))
        {
            cam->move(FLX16_ZERO, FLX16_ZERO, dy);
        }

        if (events.check (UP))
        {
            cam->move(FLX16_ZERO, 1, FLX16_ZERO);
        }

        if (events.check (DOWN))
        {
            cam->move(FLX16_ZERO, -1, FLX16_ZERO);
        }

        if (events.check (LEFT))
        {
            cam->move(-1, FLX16_ZERO, FLX16_ZERO);
        }

        if (events.check (RIGHT))
        {
            cam->move(1, FLX16_ZERO, FLX16_ZERO);
        }
    }

    if (events.check (ADJUST_FOV))
    {
        if (events.check (MOVEXY))
        {
            Flx16 fov = cam->fov;

            fov.flx += dy << 16;

            if (fov < Flx16(1))
                fov = Flx16(1);

            if (fov > Flx16(175))
                fov = Flx16(175);

            cam->set_fov(fov);
        }
    }

    if (events.check (ADJUST_FACTOR))
    {
        if (events.check (MOVEXY))
        {
            Flx16 factor = cam->factor;

            factor.flx += dy << 16;

            if (factor < Flx16(1))
                factor = Flx16(1);

            if (factor > Flx16(12))
                factor = Flx16(12);

            cam->set_factor(factor);
        }
    }

    if (backgrnd && events.check (ADJUST_BM_OFFSET))
    {
        if (events.check (MOVEXY))
        {
            long offx = cam->bg_offx;
            long offy = cam->bg_offy;

            offx -= dx;
            offy -= dy;
            
            if (offx < -(backgrnd->width+cam->vport->vbuff.width))
                offx = -((short)backgrnd->width+cam->vport->vbuff.width);

            if (offx > backgrnd->width)
                offx = backgrnd->width;

            if (offy < -(backgrnd->height+cam->vport->vbuff.height))
                offy = -((short)backgrnd->height+cam->vport->vbuff.height);

            if (offy > backgrnd->height)
                offy = backgrnd->height;

            cam->set_bg_offset((short)offx, (short)offy);
        }
    }

    // Get the camera flags so we can change 'em!
    cam_flags = cam->flags;

    // These SHADE events are meant to be mutually exclusive.
    if (single_events.check (SHADE_SOLID)) 
    {
        cam_flags &= ~(ESCH_CAM_SHADE_FLAT
                       |ESCH_CAM_SHADE_SMOOTH
                       |ESCH_CAM_SHADE_SPECULAR);
        cam_flags |= ESCH_CAM_SHADE_SOLID
                     | ESCH_CAM_SHADE_WIRE;
        doreshade=1;
    }

    if (single_events.check (SHADE_FLAT))
    {
        cam_flags &= ~(ESCH_CAM_SHADE_SMOOTH
                       |ESCH_CAM_SHADE_SPECULAR);
        cam_flags |= ESCH_CAM_SHADE_FLAT
                     | ESCH_CAM_SHADE_SOLID
                     | ESCH_CAM_SHADE_WIRE;
        doreshade=1;
    }

    if (single_events.check (SHADE_SMOOTH))
    {
        cam_flags &= ~ESCH_CAM_SHADE_SPECULAR;
        cam_flags |= ESCH_CAM_SHADE_SMOOTH
                     | ESCH_CAM_SHADE_FLAT
                     | ESCH_CAM_SHADE_SOLID
                     | ESCH_CAM_SHADE_WIRE;
        doreshade=1;
    }

    if (single_events.check (SHADE_SPECULAR))
    {
        cam_flags |= ESCH_CAM_SHADE_SPECULAR
                     | ESCH_CAM_SHADE_SMOOTH
                     | ESCH_CAM_SHADE_FLAT
                     | ESCH_CAM_SHADE_SOLID
                     | ESCH_CAM_SHADE_WIRE;
        doreshade=1;
    }

    if (single_events.check (SHADE_WIRE))
    {
        cam_flags &= ~(ESCH_CAM_SHADE_SOLID
                       |ESCH_CAM_SHADE_FLAT
                       |ESCH_CAM_SHADE_SPECULAR
                       |ESCH_CAM_SHADE_SMOOTH);
        cam_flags |= ESCH_CAM_SHADE_WIRE;
        doreshade=1;
    }

    if (single_events.check (BACKCULL))
        cam_flags ^= ESCH_CAM_BACKCULL;

    if (single_events.check (ALL_LINES))
        cam_flags ^= ESCH_CAM_SHOW_ALL_LINES;

    if (single_events.check (MODEL_SPACE))
        cam_flags ^= ESCH_CAM_MODELSPACE;

    if (single_events.check (TEXTURE_MAP))
        cam_flags ^= ESCH_CAM_TEXTURED;

    if (single_events.check (BITMAP_BACKGROUND))
        cam_flags ^= ESCH_CAM_IGNORE_BMAP;

    if (single_events.check (SHADE_PERSPECTIVE))
        cam_flags ^= ESCH_CAM_PERSPECTIVE;

    // Now, set those flags!
    cam->set_flags (cam_flags);

    if (single_events.check (TERRAIN_DOTS) && terrain)
        terrain->flags ^= ESCH_TRN_DOTS;
    if (single_events.check (TERRAIN_LOD) && terrain)
        terrain->flags ^= ESCH_TRN_LOD;

    if (single_events.check (SHOW_EXTENTS))
    {
        drawexts++;
        if (drawexts > 3)
            drawexts=0;
    }

    if (single_events.check (HAZING))
    {
        if (cam->flags & ESCH_CAM_HAZE)
        {
            cam->set_haze(0);
        }
        else
        {
            cam->create_haze(64, 16, 48, Flx16(0.5), VngoColor24bit(0,0,128));
        }
    }

    if (light)
    {
        EschLight   *l;

        // Can't move 'ambients'
        for(l=light; l != NULL; l = l->next())
        {
            if (l->get_type() != ESCH_LGTT_AMBIENT)
                break;
        }
        if (l == NULL)
            l = light;

        if (events.check (LIGHT_IN_BRIGHTER))
        {
            if (l->get_intensity() < 255-16)
                l->set_intensity((byte)( l->get_intensity() + 16) );
            doreshade=1;
        }
        else if (events.check (LIGHT_IN_DIMMER))
        {
            if (l->get_intensity() > 16)
                l->set_intensity( (byte)( l->get_intensity() - 16) );
            doreshade=1;
        }

        if (events.check (LIGHT_POSITION))
        {
            if (l->get_type() == ESCH_LGTT_VECTOR)
            {
            
                if (events.check (MOVEXY))
                {
                    ((EschVectorLight*)l)->rotatey (dx);
                    ((EschVectorLight*)l)->rotatex (dy);
                }

                if (events.check (UP))
                    ((EschVectorLight*)l)->rotatex (RotateDegrees);

                if (events.check (DOWN))
                    ((EschVectorLight*)l)->rotatex (-RotateDegrees);

                if (events.check (LEFT))
                    ((EschVectorLight*)l)->rotatey (RotateDegrees);

                if (events.check (RIGHT))
                    ((EschVectorLight*)l)->rotatey (-RotateDegrees);
            }
            else if (l->get_type() == ESCH_LGTT_FPOINT
                     || l->get_type() == ESCH_LGTT_FATTEN
                     || l->get_type() == ESCH_LGTT_FSPOT)
            {
                
                if (events.check (MOVEXY))
                    ((EschFastPointLight*)l)->translate (dx, -dy, FLX16_ZERO);

                if (events.check (MOVEZ))
                    ((EschFastPointLight*)l)->translate (FLX16_ZERO, FLX16_ZERO, -dx);

                if (events.check (UP))
                    ((EschFastPointLight*)l)->translate (FLX16_ZERO, 1, FLX16_ZERO);

                if (events.check (DOWN))
                    ((EschFastPointLight*)l)->translate (FLX16_ZERO, -1, FLX16_ZERO);

                if (events.check (LEFT))
                    ((EschFastPointLight*)l)->translate (-1, FLX16_ZERO, FLX16_ZERO);

                if (events.check (RIGHT))
                    ((EschFastPointLight*)l)->translate (1, FLX16_ZERO, FLX16_ZERO);

            }
            else if (l->get_type() == ESCH_LGTT_POINT
                     || l->get_type() == ESCH_LGTT_ATTEN
                     || l->get_type() == ESCH_LGTT_SPOT)
            {
                
                if (events.check (MOVEXY))
                    ((EschPointLight*)l)->translate (dx, -dy, FLX16_ZERO);

                if (events.check (MOVEZ))
                    ((EschPointLight*)l)->translate (FLX16_ZERO, FLX16_ZERO, -dx);

                if (events.check (UP))
                    ((EschPointLight*)l)->translate (FLX16_ZERO, 1, FLX16_ZERO);

                if (events.check (DOWN))
                    ((EschPointLight*)l)->translate (FLX16_ZERO, -1, FLX16_ZERO);

                if (events.check (LEFT))
                    ((EschPointLight*)l)->translate (-1, FLX16_ZERO, FLX16_ZERO);

                if (events.check (RIGHT))
                    ((EschPointLight*)l)->translate (1, FLX16_ZERO, FLX16_ZERO);

            }
            doreshade=1;
        }
    }

    if (scene)
    {
        for(EschGeometry *g=scene->meshes; g != NULL; g = g->next())
        {
            if (toggle_events.check(ALLI))
            {
                g->rotatex(ScriptRotateDegrees);
            }
            if (toggle_events.check(ALLJ))
            {
                g->rotatey(ScriptRotateDegrees);
            }
            if (toggle_events.check(ALLK))
            {
                g->rotatez(ScriptRotateDegrees);
            }

        }
    }

    if (terrain)
    {
        if (doreshade)
            terrain->compute_shades(cam, light);
    }

    if (prtsystem)
    {
        ulong num;

        if (kind_of_particles)
            num = flx_rand().flx & 0x7;
        else
            num = flx_rand().flx & 0x7f;

        for(ulong c=0; c < num; c++)
        {
            EschParticle    *particle;

            if (kind_of_particles)
            {
                particle = new EschParticlePyramid(1 + (flx_rand().flx & 0x3),
                                                   0,0,0,
                                                   mypal->get_index(VngoColor24bit((byte)(255 - (c*2)),0,0)),
                                                   10 + (flx_rand().flx & 0x4f));

                ((EschParticlePyramid*)particle)->set_rotate_i(Flx16(flx_rand().flx >> 24));
                ((EschParticlePyramid*)particle)->set_rotate_j(Flx16(flx_rand().flx >> 24));
                ((EschParticlePyramid*)particle)->set_rotate_k(Flx16(flx_rand().flx >> 24));
            }
            else
            {
                particle = new EschParticle(0,0,0,
                                            mypal->get_index(VngoColor24bit((byte)(255 - (c*2)),0,0)),
                                            20 + (flx_rand().flx & 0x4f));
            }

            particle->set_velocity(Flx16(flx_rand().flx >> 12,0),
                                   Flx16(flx_rand().flx & 0x1fffff,0),
                                   Flx16(flx_rand().flx >> 12,0));

            if (particle)
                prtsystem->add(particle);
        }
    }

    if (fire)
    {
        if (events.check(FIRE_INCREASE))
            fire->increase();
        else if (events.check(FIRE_DECREASE))
            fire->decrease();

        if (events.check(FIRE_DOUSE))
            fire->douse();

        if (toggle_events.check(FIRE_FIREBALL))
            fire->fireball();
    }
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::Render
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::Render()
{
    render_timer.clear();

    if (!cam || !draws)
        return;

    char        buff[256];
    GBergText   gt(gvp);

    EschContext ec(EschCurrent);
    ec.camera = cam;
    ec.lights = light;
    ec.eschs = draws;
    ec.push();

    cam->render();

    if (scene)
    {
        if (drawexts)
        {
            for(EschMeshDraw *ptr=scene->meshes;
                ptr != NULL;
                ptr = (EschMeshDraw*)ptr->next())
            {
                if (!(ptr->flags & ESCH_DRW_SKIP))
                {
                    if (drawexts & 0x2)
                    {
                        ptr->mesh->box.draw(&ptr->world,exts_color);
                    }
                    if (drawexts & 0x1)
                    {
                        ptr->draw_extents(exts_color);
                    }
                }
            }
        }
    }

    if (pick_test)
    {
        //ÄÄÄ Pick Test
        short x, y;
        evt->get_mouse_pos(&x,&y);

        wsprintf(buff,"Mouse: %d, %d\n",(int)x,(int)y);
        gt.out(buff);

        EschPicking pick(cam, x, y, draws, 16);

        esch_error_codes err;
        err=draws->pick(&pick);
        if (err)
        {
            wsprintf(buff,"Pick returned error %d\n",(int)err);
            gt.out(buff);
        }
        if (pick.count)
        {
            wsprintf(buff,"Picks: %d (of %d max)\n",pick.count,pick.maxcount);
            gt.out(buff);

            if (!pick.result)
                gt.out("Error, no result pointer\n");
            else
            {
                int c=1;
                for(EschDrawList *r = pick.result;
                    r != 0;
                    r = r->next, c++)
                {
                    if (!r->item)
                        wsprintf(buff,"(%d) = No item pointer!\n",c);
                    else
                        sprintf(buff,"(%d) = '%s' @ %6.2f\n",c,
                                (r->item->name) ? r->item->name : "NoName",
                                (float)r->dist);
                    gt.out(buff);
                }
            }
        }
        else
        {
            gt.out("No Picks\n");
        }
    }

    if (collide_test)
    {
        //ÄÄÄ Collision Test
        EschCollision collide(draws, 16);

        esch_error_codes err;
        err=draws->collide(&collide);
        if (err)
        {
            wsprintf(buff,"Collide returned error %d\n",(int)err);
            gt.out(buff);
        }
        if (collide.count)
        {
            wsprintf(buff,"Collisions:\n"
                        "'%s' hit %d (of %d max)\n",draws->name,
                                                    collide.count,
                                                    collide.maxcount);
            gt.out(buff);

            if (!collide.result)
                gt.out("Error, no result pointer\n");
            else
            {
                int c=1;
                for(EschDrawList *r = collide.result;
                    r != 0;
                    r = r->next, c++)
                {
                    if (!r->item)
                        wsprintf(buff,"(%d) = No item pointer!\n",c);
                    else
                        wsprintf(buff,"(%d) = '%s'\n",c,
                                (r->item->name) ? r->item->name : "NoName");
                    gt.out(buff);
                }
            }
        }
        else
        {
            gt.out("No collides\n");
        }
    }

    ec.pop();

    for(EschDrawable *dptr = draws; dptr != NULL; dptr = dptr->next())
        dptr->animate();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::Display
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::Display()
{
    SetDIBitsToDevice (hdc, 0, 0, MAP_XSIZE, MAP_YSIZE, 0, 0, 0, MAP_YSIZE,
                       gmap, bmi, DIB_PAL_COLORS);

    ticks += render_timer.check();
    frames++;
}

//°±² eof - GState.cpp ²±°

