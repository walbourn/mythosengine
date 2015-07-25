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

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState Constructor
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
GameState::GameState (MaxDevices &d):
    devs (d), evt (0), active (FALSE)
{
    cam=0;
    light=0;
    scene=0;
    curmesh=0;
    terrain=0;
    hpal=0;

    ticks=frames=0;

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

            gvp = new VngoVportDD8(MAP_XSIZE,MAP_YSIZE,gmap,NULL,mypal,
                                   VNGO_ZBUFFER_DEV | VNGO_BACKBUFFER);
        }
    }

    RotateDegrees=1;
    ScriptRotateDegrees=3;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState Destructor
//
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

    if (terrain)
        delete terrain;

    if (scene)
        delete scene;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::LoadEvents
//
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

    if (scene || terrain)
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

    for(cam=scene->cameras; cam != NULL; cam = cam->next())
    {
        VngoColor24bit c(0,0,128);
        
        cam->attach(gvp);
        cam->set_flags(cam->flags | ESCH_CAM_SHADE_SPECULAR
                                  | ESCH_CAM_SHADE_SMOOTH
                                  | ESCH_CAM_SHADE_FLAT
                                  | ESCH_CAM_SHADE_WIRE
                                  | ESCH_CAM_TEXTURED
                                  | ESCH_CAM_BACKCULL
                                  | ESCH_CAM_MODELSPACE);
        cam->set_bcolor(mypal->get_index(c));
        cam->set_yon(500);
    }

    cam=scene->cameras;

    light=scene->lights;

    curmesh=scene->meshes;

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::LoadTerrain
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL GameState::LoadTerrain(char *fn)
{
    int err;

    if (scene || terrain)
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
    terrain->set_origin(-(Flx16)(terrain->width/2+10)*terrain->wscale,
                        -(Flx16)4*terrain->hscale - (Flx16)20,
                        -(Flx16)(terrain->depth/2-40)*terrain->dscale);
    terrain->set_lod(500,1000);

    cam = new EschCamera(gvp);

    cam->set_position(0,0,0);
    cam->set_yon(2000);
    cam->rotatey(-90);

    cam->set_flags(cam->flags | ESCH_CAM_SHADE_SMOOTH
                              | ESCH_CAM_SHADE_FLAT
                              | ESCH_CAM_SHADE_SOLID
                              | ESCH_CAM_SHADE_WIRE
                              | ESCH_CAM_BACKCULL
                              | ESCH_CAM_MODELSPACE);

    VngoColor24bit c(0,0,128);
    cam->set_bcolor(mypal->get_index(c));

    light = new EschVectorLight(-1,-1,-1);

    terrain->compute_shades(cam, light);

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

    if (light)
    {
        EschLight   *l;

        // Moving a Point or Vector source is more interesting...
        for(l=light; l != NULL; l = l->next())
        {
            if (l->ltyp == ESCH_LGTT_VECTOR || l->ltyp == ESCH_LGTT_POINT)
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
            if (l->ltyp == ESCH_LGTT_VECTOR)
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
            else if (l->ltyp == ESCH_LGTT_POINT)
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
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::Render
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::Render()
{
    Chronometer render_timer;

    if (!cam)
        return;

    render_timer.clear();

    if (terrain)
    {
        cam->render(terrain,light);
    }
    else if (scene)
    {
        cam->render(scene->meshes,light);
    }

    ticks += render_timer.check();
    frames++;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::Display
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::Display()
{
    SetDIBitsToDevice (hdc, 0, 0, MAP_XSIZE, MAP_YSIZE, 0, 0, 0, MAP_YSIZE,
                       gmap, bmi, DIB_PAL_COLORS);
}


//°±² eof - GState.cpp ²±°

