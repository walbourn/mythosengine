//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                /\    /\
//                               /  \  /  \
//                              /    \/    \
//                             /  /\    /\  \
//                            /  /  \  /  Y T H O S
//                           /  /    \/    \  \
//                          /  /            \  \
//                         /__/              \__\
//
//                  Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
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
//                              3D VIEWER EXAMPLE
//
// Created by Chuck Walbourn
//
// viewer.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <mythos.hpp>
#include <stdio.h>

#include "viewer.hpp"
#include "viewevt.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

struct ApplicationData
{
    BOOL    shift;
    short   dx;
    short   dy;
};

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄ Global Windows data
extern HINSTANCE       hInst;
extern HWND            hWndClient;
extern const char      szAppName[];

//ÄÄÄ Global data
extern MythosSystem         *MythOS;
extern MaxDevices           *Devs;
extern VngoScreenManager    *Screen;
extern VngoVport            *Vport;
extern VngoPal              *Palette;

//ÄÄÄ Diagnostic information
extern ulong EschProposedTris;
extern ulong EschDrawnTris;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Viewer - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
Viewer::Viewer() :
    evt(0),
    current(0),
    was_rotate(0),
    camera(0),
    drawlist(0),
    lights(0),
    show_info(FALSE)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Viewer - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
Viewer::~Viewer()
{
    if (evt)
    {
        evt->uninstall();
        delete evt;
    }
    if (camera)
        delete camera;
    if (drawlist)
    {
        for(EschDrawable *drw=drawlist; drw != 0;)
        {
            EschDrawable *tmp = drw;
            drw = drw->next();
            if (tmp->app_data)
                delete ((ApplicationData*)tmp->app_data);
            delete tmp;
        }
    }
    if (lights)
    {
        for(EschLight *lgt=lights; lgt != 0;)
        {
            EschLight *tmp = lgt;
            lgt = lgt->next();
            delete tmp;
        }
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Viewer - create
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL Viewer::create()
{
    ulong       i;
    XFParseINI  ini;
    char        key[128];
    char        buff[128];

    assertMyth("Viewer::create needs Vport & Palette",
               Vport != 0 && Palette != 0);

//ÄÄÄ Load setup from INI file

    if (ini.open("VIEWER.INI",XF_OPEN_READ))
        return FALSE;

    float           yon=2500;
    dword           bcolor=0;
    float           haze_start=0.5f, haze_mid=0.85f;

    if (!ini.section("Camera"))
    {
        if (!ini.read("Yon",buff))
        {
            yon=(float)atof(buff);
        }
        if (!ini.read("BackgroundColor",buff))
        {
            sscanf(buff,"0x%x",&bcolor);
        }
        if (!ini.read("HazeStart",buff))
        {
            haze_start=(float)atof(buff);
        }
        if (!ini.read("HazeMidpoint",buff))
        {
            haze_mid=(float)atof(buff);
        }
    }

    if (ini.section("View"))
        return FALSE;

    //ÄÄÄ Process any 'SceneFile' commands
    for(i=0; i < 9999; i++)
    {
        wsprintf(key,"SceneFile%d",i+1);
        if (ini.read(key,buff))
            break;

        EschScene scene;
        if (scene.load(buff,0,Palette))
            return FALSE;

        //ÄÄÄ Duplicate a camera if we don't have one...
        if (!camera && scene.cameras)
        {
            camera = new EschCameraEx(*scene.cameras);
            if (!camera)
                return FALSE;

            camera->attach(Vport);
            camera->set_flags(camera->flags
                              | ESCH_CAM_SHADE_SMOOTH
                              | ESCH_CAM_SHADE_FLAT
                              | ESCH_CAM_SHADE_SOLID
                              | ESCH_CAM_SHADE_WIRE
                              | ESCH_CAM_BACKCULL
                              | ESCH_CAM_MODELSPACE
                              | ESCH_CAM_PERSPECTIVE
                              | ESCH_CAM_TEXTURED
                              | ESCH_CAM_ALPHA
                              );

            camera->set_bcolor(Palette->get_index(bcolor));
            camera->set_yon(yon);
            camera->set_haze(haze_start, haze_mid);
            Vport->haze_off();
        }

        //ÄÄÄ Grab lights if we don't have some...
        if (!lights && scene.lights)
        {
            lights = scene.lights;
            scene.lights=0;
        }

        //ÄÄÄ Grab all meshes
        if (scene.meshes)
        {
            if (drawlist)
                ((EschDrawable*)scene.meshes)->sibling(drawlist);
            else
                drawlist = scene.meshes;

            scene.meshes=0;
        }
    }

//ÄÄÄ Must have camera, lights, and a drawlist by this point
    if (!camera || !lights || !drawlist)
        return FALSE;

//ÄÄÄ Get and start event system
    evt = new MaxEventUser (*Devs);
    if (!evt
        || ((MaxEventUser*)evt)->load("VIEWEVT.IFF"))
        return FALSE;

    evt->install();

//ÄÄÄ Clear frame-rate counter
    frames=0;
    fps_clock.clear();

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                               °° Private °°
// Viewer - update_rotates
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void Viewer::update_rotates(EschDrawable *list)
{
    for(EschDrawable *drw = list; drw != 0; drw = drw->next())
    {
        ApplicationData *ptr = (ApplicationData*)drw->app_data;

        switch (drw->get_type())
        {
            case ESCH_DRWT_MESH:
                {
                    EschMeshDraw *curmesh = (EschMeshDraw*)drw;
                    if (ptr)
                    {
                        if (ptr->shift)
                        {
                            curmesh->rotatez (float(-ptr->dx));
                        }
                        else
                        {
                            curmesh->rotatex (float(-ptr->dy));
                            curmesh->rotatey (float(-ptr->dx));
                        }
                    }

                    update_rotates(curmesh->child());
                }
                break;
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Viewer - process_events
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void Viewer::process_events()
{
//ÄÄÄ Determine events
    assertMyth("Viewer::process_events() needs event source", evt != 0);
    MaxEventList events = evt->process ();

    //ÄÄÄ Update toggle and one-shot events
    MaxEventList single_events = oneshot.process (events);

//ÄÄÄ Update any moving objects
    update_rotates(drawlist);

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Check and act on events

    //ÄÄÄ Applications events
    if (single_events.check(DONE))
    {
        PostQuitMessage(0);
        return;
    }

    if (single_events.check(SHOW_INFO))
    {
        show_info = !show_info;
    }

    //ÄÄÄ Camera controls
    assertMyth("Viewer::process_events needs camera", camera != 0);

    dword cam_flags = camera->flags;

    if (single_events.check (SHADE_SOLID))
    {
        cam_flags &= ~(ESCH_CAM_SHADE_FLAT
                       |ESCH_CAM_SHADE_SMOOTH
                       |ESCH_CAM_SHADE_SPECULAR);
        cam_flags |= ESCH_CAM_SHADE_SOLID
                     | ESCH_CAM_SHADE_WIRE;
    }
    else if (single_events.check (SHADE_FLAT))
    {
        cam_flags &= ~(ESCH_CAM_SHADE_SMOOTH
                       |ESCH_CAM_SHADE_SPECULAR);
        cam_flags |= ESCH_CAM_SHADE_FLAT
                     | ESCH_CAM_SHADE_SOLID
                     | ESCH_CAM_SHADE_WIRE;
    }
    else if (single_events.check (SHADE_SMOOTH))
    {
        cam_flags &= ~ESCH_CAM_SHADE_SPECULAR;
        cam_flags |= ESCH_CAM_SHADE_SMOOTH
                     | ESCH_CAM_SHADE_FLAT
                     | ESCH_CAM_SHADE_SOLID
                     | ESCH_CAM_SHADE_WIRE;
    }
    else if (single_events.check (SHADE_SPECULAR))
    {
        cam_flags |= ESCH_CAM_SHADE_SPECULAR
                     | ESCH_CAM_SHADE_SMOOTH
                     | ESCH_CAM_SHADE_FLAT
                     | ESCH_CAM_SHADE_SOLID
                     | ESCH_CAM_SHADE_WIRE;
    }
    else if (single_events.check (SHADE_WIRE))
    {
        cam_flags &= ~(ESCH_CAM_SHADE_SOLID
                       |ESCH_CAM_SHADE_FLAT
                       |ESCH_CAM_SHADE_SPECULAR
                       |ESCH_CAM_SHADE_SMOOTH);
        cam_flags |= ESCH_CAM_SHADE_WIRE;
    }

    if (single_events.check (BACKCULL))
        cam_flags ^= ESCH_CAM_BACKCULL;

    if (single_events.check (ALL_LINES))
        cam_flags ^= ESCH_CAM_SHOW_ALL_LINES;

    if (single_events.check (MODEL_SPACE))
        cam_flags ^= ESCH_CAM_MODELSPACE;

    if (single_events.check (TEXTURE_MAP))
        cam_flags ^= ESCH_CAM_TEXTURED;

    if (single_events.check (SHADE_PERSPECTIVE))
        cam_flags ^= ESCH_CAM_PERSPECTIVE;

    if (single_events.check (SHADE_ALPHA))
        cam_flags ^= ESCH_CAM_ALPHA;

    camera->set_flags (cam_flags);

    if (single_events.check (ZBUFFER))
    {
        if (camera->vport->vflags & VNGO_ZBUFFER_DEV)
        {
            if (camera->vport->vflags & VNGO_ZBUFFER_ACTIVE)
                camera->vport->zbuffer_off();
            else
                camera->vport->zbuffer_on();
        }
    }

    if (single_events.check (SORT))
    {
        camera->flags ^= ESCH_CAM_SORT;
        if (camera->vport->vflags & VNGO_ZBUFFER_DEV)
        {
            if (camera->flags & ESCH_CAM_SORT)
                camera->vport->zbuffer_off();
            else
                camera->vport->zbuffer_on();
        }
    }

    if (single_events.check (HAZING))
    {
        if (camera->vport->vflags & VNGO_HAZE_ON)
            camera->vport->haze_off();
        else
            camera->vport->haze_on();
    }

    //ÄÄÄ Object controls
    assertMyth("Viewer::process_events needs drawlist", drawlist != 0);

    short dx, dy;
    evt->get_mouse_movement (&dx, &dy);

    if (events.check (ROTATE) || events.check(MOVE))
    {
        if (!current)
        {
            short x, y;
            evt->get_mouse_pos(&x,&y);

            EschPicking pick(camera, x, y, drawlist);

            if (!drawlist->pick(&pick)
                && pick.count
                && pick.result)
                current = pick.result->item;
        }

        if (current)
        {
            switch (current->get_type())
            {
                case ESCH_DRWT_MESH:
                    {
                        EschMeshDraw *curmesh = (EschMeshDraw*)current;
                        if (events.check(MOVE))
                        {
                            was_rotate = FALSE;
                            if (events.check(SHIFT))
                            {
                                EschVector v(0.0f, 0.0f, float(-dy));

                                v.transform(&camera->eye.orient);

                                curmesh->translate (&v);
                            }
                            else
                            {
                                EschVector v(float(dx), float(-dy), 0.0f);

                                v.transform(&camera->eye.orient);

                                curmesh->translate (&v);
                            }
                        }
                        else
                        {
                            was_rotate = TRUE;
                            if (curmesh->app_data)
                            {
                                delete ((ApplicationData*)curmesh->app_data);
                                curmesh->set_app_data(0);
                            }

                            if (events.check (SHIFT))
                            {
                                curmesh->rotatez (float(-dx));
                            }
                            else
                            {
                                curmesh->rotatex (float(-dy));
                                curmesh->rotatey (float(-dx));
                            }
                        }
                    }
                    break;
            }
        }
    }
    else if (current)
    {
        if (was_rotate)
        {
            if (dx != 0 || dy != 0)
            {
                ApplicationData *ptr = (ApplicationData*)current->app_data;
                if (!ptr)
                {
                    ptr = new ApplicationData;
                    current->set_app_data(ptr);
                }

                ptr->dx = dx;
                ptr->dy = dy;
                ptr->shift = (events.check(SHIFT)) ? TRUE : FALSE;
            }
        }

        current=0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Viewer - render
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void Viewer::render()
{
    assertMyth("Viewer::render() needs camera, drawlist, and lights",
               camera != 0 && drawlist != 0 && lights != 0);

//ÄÄÄ Clear diagnositic counts

    EschProposedTris = 0;
    EschDrawnTris = 0;

//ÄÄÄ Render image

    camera->render(drawlist,lights);

//ÄÄÄ Handle frame counter and information display

    frames++;

    if (show_info)
    {
        GBergText   gt(Vport);
        char        buff[64];

        sprintf (buff, "Device: %s\n", Screen->hwName);
        gt.out (buff);

        ulong ms = fps_clock.check();
        float fps = (ms) ? ((float(frames) / float(ms)) * 1000.0f)
                         : 0.0f;

        sprintf (buff, "FPS:%5.2f\n\n", fps);
        gt.out (buff);

        sprintf (buff, "Proposed %d tris\n%d tris drawn\n",
                       EschProposedTris, EschDrawnTris);
        gt.out (buff);
    }

    if (frames > 100)
    {
        frames=0;
        fps_clock.clear();
    }
}

//°±² eof - viewer.cpp ²±°
