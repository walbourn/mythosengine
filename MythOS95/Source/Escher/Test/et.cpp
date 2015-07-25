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
// et.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define WIN32_LEAN_AND_MEAN
#include "global.hpp"

#include "etevt.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

const int COLORS = 256;

const int MAXPAGES = 3;

extern MaxDevices Devs;
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
// EscherTest - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
EscherTest::EscherTest (MaxDevices &d):
    devs (d),
    evt (0),
    hpal (0),
    active (FALSE),
    show_fps (FALSE),
    pick_test(FALSE),
    collide_test(FALSE),
    use_new_terrain(FALSE),
    cam(0),
    light(0),
    draws(0),
    scene(0),
    terrain(0),
    prtsystem(0),
    starfield(0),
    explosion(0),
    sprite(0),
    metabox(0),
    curmesh(0),
    fire(0),
    partn(0),
    mtxt(0),
    drawexts(0),
    RotateDegrees(1),
    ScriptRotateDegrees(3),
    kind_of_particles(POINTS),
    backgrnd (0),
    frames (0),
    screen (0),
    total_frames (0),
    map_xsize (MAP_XSIZE),
    map_ysize (MAP_YSIZE),
    total_time (0),
    alpha (255)
{
    int use_fullscreen = 0;
    int use_zbuffer=TRUE;
    char buff[128];
    char palname[128];
    XFParseINI  ini;

    if (ini.open(".\\ET.INI",XF_OPEN_READ) == XF_ERR_NONE)
    {
        ini.section("Screen");
        if (!ini.read("FullScreen",buff))
        {
            strlwr(buff);
            if (strstr(buff,"yes") || strstr(buff,"on"))
            {
                use_fullscreen |= VNGO_SET_RESOLUTION;
            }
        }

        if (!ini.read("TrueFlip",buff))
        {
            strlwr(buff);
            if (strstr(buff,"yes") || strstr(buff,"on"))
            {
                use_fullscreen |= VNGO_TRUE_FLIP;
            }
        }

        if (!ini.read("UseDirectDraw",buff))
        {
            strlwr(buff);
            if (strstr(buff,"yes") || strstr(buff,"on"))
            {
                screen = new VngoDirectDraw (hWndClient);
            }
        }

        if (!ini.read("Resolution",buff))
        {
            strlwr(buff);
            if (strstr(buff,"640x480"))
            {
                map_xsize = 640;
                map_ysize = 480;
            }
            if (strstr(buff,"320x240"))
            {
                map_xsize = 320;
                map_ysize = 240;
            }
            if (strstr(buff,"320x200"))
            {
                map_xsize = 320;
                map_ysize = 200;
            }
            if (strstr(buff,"800x600"))
            {
                map_xsize = 800;
                map_ysize = 600;
            }
            if (strstr(buff,"1024x768"))
            {
                map_xsize = 1024;
                map_ysize = 768;
            }
        }
        if (!ini.read("ZBuffer",buff))
        {
            strlwr(buff);
            if (strstr(buff,"yes") || strstr(buff,"on"))
            {
                use_zbuffer = TRUE;
            }
            else
            {
                use_zbuffer = FALSE;
            }
        }

        if (!ini.read("Palette",palname))
        {
            strlwr(buff);
        }
        else
        {
            strcpy(palname,"default.pal");
        }

        ini.close();
        // If we did not want a DDraw screen then use a DIB.
        if (screen == NULL)
        {
            screen = new VngoDIB8 (hWndClient);
        }
        else if (screen->get_initstate() == FALSE)
        {
            delete screen;
            screen = new VngoDIB8 (hWndClient);
        }
    }
    else
    {
        screen = new VngoDIB8 (hWndClient);
    }

    assert(screen != NULL);
    assert(screen->get_initstate() != FALSE);
    mypal = new VngoPal8;

    if (mypal)
    {
        if (mypal->init(0,palname) != 0)
        {
            delete mypal;
            mypal = NULL;
        }
    }
    if (mypal)
    {
        screen->set_mode (map_xsize, map_ysize, 8 , mypal, use_fullscreen);


        if (screen->get_type() == VngoScreenManager::SCREENTYPE_DDRAW)
        {
            VngoDirectDraw *ldd = (VngoDirectDraw *)screen;
            gvp = new VngoVportDD8(ldd->SurfaceManager, NULL, mypal,
                                   VNGO_ZBUFFER_DEV);
        }
        else if (screen->get_type() == VngoScreenManager::SCREENTYPE_DIB)
        {
            VngoDIB8 *ldib = (VngoDIB8 *)screen;
            gvp = new VngoVportDB8(map_xsize,map_ysize,ldib->gmap,NULL,mypal,
                                   VNGO_ZBUFFER_DEV);
        }

        if (!use_zbuffer)
        {
            gvp->zbuffer_off();
        }

        gberg_color(gvp->vbuff.pal->get_index(VngoColor24bit(255,255,255)),
                    VNGO_TRANSPARENT);
    }

#if 0
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
//                                   0);
                                   VNGO_ZBUFFER_DEV);

            exts_color = mypal->get_index(VngoColor24bit(0,0,0));

            gberg_color(gvp->vbuff.pal->get_index(VngoColor24bit(255,255,255)),
                        VNGO_TRANSPARENT);
        }
    }
#endif
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EscherTest - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
EscherTest::~EscherTest ()
{
    if (screen)
        delete screen;

    if (hpal)
        DeleteObject(hpal);

    // Clean up our event source
    if (evt)
    {
        evt->uninstall();
        delete evt;
    }

    if (fire)
        delete fire;

    if (partn)
        delete partn;

    if (mtxt)
        delete mtxt;

    if (backgrnd)
        delete backgrnd;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EscherTest - LoadEvents
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EscherTest::LoadEvents (LPCSTR lpszFile)
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
    evt = new MaxEventUser (devs, szFileName);

    // Verify the event system matches our set of events?

    // Now, let 'er rip!
    evt->install();
    active = TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EscherTest - SetupFireTest
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL EscherTest::SetupFireTest()
{
    if (fire)
        return TRUE;

    fire = new EschFireTexture(128,128,mypal);
    if (!fire)
    {
        MessageBox("Couldn't create fire texture", MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }
    fire->set_flags(fire->flags | ESCH_TXT_SKIPANIMATE);

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EscherTest - SetupPartitionTest
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL EscherTest::SetupPartitionTest()
{

    partn = new EschGridPartition;
    if (!partn
        || ((EschGridPartition*)partn)->init(4,4,128,&EschPoint(-256,0,-256)))
    {
        MessageBox("Couldn't create partitioning", MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }

    if (draws)
        return FALSE;

    draws = partn;

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EscherTest - SetupMultiTest
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL EscherTest::SetupMultiTest(const char *name)
{
    XFBitmap    bm[16];

    ushort count=0;
    Flx16 rate=0;
    for (const char *s=name, *c=name; ; c++)
    {
        if (!*c || *c == ',')
        {
            if (s == name)
            {
                char value[128];
                memset(value,0,sizeof(value));
                strncpy(value,s,c-s);
                rate = Flx16(atof(value));
            }
            else
            {
                if (count >= 16)
                {
                    MessageBox("Too many MultiTest bitmaps found",
                            MB_OK | MB_ICONEXCLAMATION);
                    return FALSE;
                }

                char fname[128];
                memset(fname,0,sizeof(fname));
                strncpy(fname,s,c-s);

                XFParseBMP bmp(&bm[count]);
                if (bmp.nameread(fname))
                {
                    MessageBox(fname, MB_OK | MB_ICONEXCLAMATION);
                    return FALSE;
                }

                count++;
            }

            if (!*c)
                break;

            s=c+1;
        }
    }

    if (!count)
    {
        MessageBox("No MultiTest bitmaps found",
                   MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }

    mtxt = new EschMultiFrameTexture;
    if (!mtxt
        || mtxt->create(count,bm))
    {
        MessageBox("Couldn't create multi-frame texture",
                   MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }
    if (rate > 0)
        mtxt->set_rate(rate);

    mtxt->set_flags(mtxt->flags | ESCH_TXT_SKIPANIMATE);

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EscherTest - SetupSprite
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL EscherTest::SetupSprite(const char *name)
{
    if (sprite)
        return FALSE;

    XFParseBMP bmp;
    if (bmp.nameread((strstr(name,",")) ? strstr(name,",")+1 : name))
    {
        MessageBox((strstr(name,",")) ? strstr(name,",")+1 : name,
                   MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }

    sprite = new EschSprite;
    if (!sprite
        || sprite->create(bmp.bm,10,10))
    {
        MessageBox("Could not create sprite",MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }

    if (strstr(name,"infinite"))
    {
        sprite->set_position(0,0,100);
        sprite->set_flags(sprite->flags | ESCH_SPRITE_INFINITE);
    }
    else
    {
        sprite->set_position(0,0,0);
    }

    sprite->set_alpha(alpha);

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
                                | ESCH_CAM_ALPHA
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
// EscherTest - LoadScene
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL EscherTest::LoadScene(char *fn)
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
        sprintf(buff,"Could not load a scene from file '%s', error %d",fn,err);
        MessageBox(buff,MB_OK| MB_ICONEXCLAMATION);
        return FALSE;
    }

    if (!cam && scene->cameras)
    {
        cam = new EschCameraEx(*scene->cameras);
        cam->attach(gvp);
        cam->set_flags(cam->flags
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

        cam->set_bcolor(mypal->get_index(VngoColor24bit(0,0,128)));
        cam->set_yon(2500);
        cam->set_bg_bitmap(backgrnd);
    }

    if (!light)
        light=scene->lights;

    if (scene->meshes)
    {
        curmesh=scene->meshes;

        if (fire)
        {
            if (curmesh && curmesh->txt)
            {
                curmesh->txt[0] = fire;
            }
            else
            {
                MessageBox("Couldn't put fire texture on first object",
                           MB_OK | MB_ICONEXCLAMATION);
            }
        }
        else if (mtxt)
        {
            if (curmesh && curmesh->txt)
            {
                curmesh->txt[0] = mtxt;
            }
            else
            {
                MessageBox("Couldn't put multi-frame texture on first object",
                           MB_OK | MB_ICONEXCLAMATION);
            }
        }

        if (partn)
        {
            for(EschMeshDraw *ptr = scene->meshes; ptr != 0; ptr = (EschMeshDraw*)ptr->next())
            {
                if (partn->insert(ptr))
                {
                    char buff[64];
                    wsprintf(buff,"Couldn't put drawable '%s' into partition",ptr->name);
                    MessageBox(buff,
                               MB_OK | MB_ICONEXCLAMATION);
                }
            }
        }
        else
        {
            if (draws)
                ((EschDrawable*)scene->meshes)->sibling(draws);
            else
                draws = scene->meshes;
        }
    }

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EscherTest - LoadTerrain
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL EscherTest::LoadTerrain(char *fn)
{
    int err;

    if (terrain)
        return FALSE;

    if (!use_new_terrain)
        terrain = new EschTerrain;
    else
        terrain = new EschTerrainEx;

    if (!terrain)
        return FALSE;

    if ((err=terrain->load(fn,0))!=0)
    {
        char buff[256];
        sprintf(buff,"Could not load a terrain from file '%s', error %d",fn,err);
        MessageBox(buff, MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }

    if (!cam)
    {
        cam = new EschCameraEx(gvp);
        cam->set_position(0,terrain->get_height(0,0) + Flx16(2),0);  // only two meters above the ground.
        cam->set_flags(cam->flags | ESCH_CAM_SHADE_SMOOTH
                                | ESCH_CAM_SHADE_FLAT
                                | ESCH_CAM_SHADE_SOLID
                                | ESCH_CAM_SHADE_WIRE
                                | ESCH_CAM_BACKCULL
                                | ESCH_CAM_MODELSPACE
                                | ESCH_CAM_PERSPECTIVE
                                | ESCH_CAM_TEXTURED
                                | ESCH_CAM_ALPHA
                                );
        cam->set_bcolor(mypal->get_index(VngoColor24bit(0,0,128)));
        cam->set_bg_bitmap(backgrnd);
    }
//    cam->set_fov(27);
//    cam->set_factor(Flx16(7.5));
    cam->set_yon(2500);

    if (!use_new_terrain)
    {
        terrain->set_lod(250,500);
    }
    else
    {
        EschTerrainEx   *tt=(EschTerrainEx*)terrain;
        tt->set_lod(3,Flx16(350),Flx16(750));
        tt->set_perspective_lod(0);
        tt->set_texture_lod(5);
        tt->set_smooth_lod(5);
    }

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
// EscherTest - SetupParticleSystem
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL EscherTest::SetupParticleSystem(const char *name)
{
    if (prtsystem)
        return FALSE;

    prtsystem = new EschParticleSystem;
    if (!prtsystem
        || prtsystem->init(0xff))
    {
        MessageBox("Could not create particle system",
                   MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }

    prtsystem->set_acceleration(0,-8,0);

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
                                | ESCH_CAM_TEXTURED
                                | ESCH_CAM_ALPHA
                                );
        cam->set_bcolor(mypal->get_index(VngoColor24bit(0,0,128)));
        cam->set_bg_bitmap(backgrnd);
    }

    if (!light)
        light = new EschVectorLight(-1,-1,-1);

    if (strstr(name,"pyramids"))
        kind_of_particles=PYRAMIDS;
    else if (strstr(name,"sprites"))
    {
        if (!sprite)
        {
            MessageBox("Must have Sprite Test enabled",
                       MB_OK | MB_ICONEXCLAMATION);
        }
        kind_of_particles=SPRITES;
    }

    if (draws)
        prtsystem->sibling(draws);
    else
        draws = prtsystem;

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EscherTest - SetupStarfield
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL EscherTest::SetupStarfield(BOOL fixed, BOOL brights)
{
    if (starfield)
        return FALSE;

    starfield = new EschStarfield;
    if (!starfield
        || starfield->create_stars(1000,(brights) ? 1 : 0))
    {
        MessageBox("Could not create starfield", MB_OK | MB_ICONEXCLAMATION);
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
                                | ESCH_CAM_TEXTURED
                                | ESCH_CAM_ALPHA
                                );
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
// EscherTest - SetupExplosion
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL EscherTest::SetupExplosion(const char *buff)
{
    if (explosion)
        return FALSE;

    if (!fire)
    {
        fire = new EschFireTexture(128,128,mypal);
        if (!fire)
        {
            MessageBox("Couldn't create fire texture", MB_OK | MB_ICONEXCLAMATION);
            return FALSE;
        }
        fire->set_flags(fire->flags | ESCH_TXT_SKIPANIMATE);
    }

    explosion = new EschPlosion(40,40,fire);
    if (!explosion)
    {
        MessageBox("Could not create explosion", MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }

    if (strstr(buff,"circular"))
        explosion->set_flags(explosion->flags | ESCH_PLSN_CIRCULAR);
    else if (strstr(buff,"triangular"))
        explosion->set_flags(explosion->flags | ESCH_PLSN_TRIANGULAR);

    explosion->set_step(Flx16(0.02));
    explosion->set_alpha(alpha);

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
                                | ESCH_CAM_TEXTURED
                                | ESCH_CAM_ALPHA
                                );
        cam->set_bg_bitmap(backgrnd);
    }

    if (draws)
        explosion->sibling(draws);
    else
        draws = explosion;

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EscherTest - SetupMetabox
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL EscherTest::SetupMetabox(const char *buff)
{
    if (metabox)
        return FALSE;

    metabox = new EschMetabox;
    if (!metabox)
    {
        MessageBox("Could not create metabox",MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }
    metabox->set_position(0,0,0);

    metabox->set_color(mypal->get_index(VngoColor24bit(255,0,0)),
                       ESCH_MBOX_FACE_TOP);
    metabox->set_color(mypal->get_index(VngoColor24bit(255,0,0)),
                       ESCH_MBOX_FACE_BOTTOM);
    metabox->set_color(mypal->get_index(VngoColor24bit(0,255,0)),
                       ESCH_MBOX_FACE_FRONT);
    metabox->set_color(mypal->get_index(VngoColor24bit(0,255,0)),
                       ESCH_MBOX_FACE_BACK);
    metabox->set_color(mypal->get_index(VngoColor24bit(0,0,255)),
                       ESCH_MBOX_FACE_LEFT);
    metabox->set_color(mypal->get_index(VngoColor24bit(0,0,255)),
                       ESCH_MBOX_FACE_RIGHT);
    metabox->create_cube(10);
    mbox_size = 10;

    if (mtxt)
        metabox->set_texture(mtxt);

    metabox->set_alpha(alpha);

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
                                  | ESCH_CAM_ALPHA
                                  | ESCH_CAM_TEXTURED);
        cam->set_bg_bitmap(backgrnd);
    }

    cam->set_bcolor(mypal->get_index(VngoColor24bit(0,0,128)));

    if (draws)
        metabox->sibling(draws);
    else
        draws = metabox;

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EscherTest - GetEvents
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EscherTest::GetEvents()
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
// EscherTest - Begin
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EscherTest::Begin ()
{
    clock.clear();
    fps_clock.clear();
    frames=0;
    total_frames=0;
    total_time=0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EscherTest - End
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EscherTest::End (char *buff)
{
    total_frames += frames;
    total_time += fps_clock.check();

//    char buff[128];

    sprintf(buff,"%d frames in %d ms, rate=%f",
                 total_frames, total_time,
                 (float)( (total_time)
                          ? ((double)total_frames / (double)total_time) * double(1000)
                          : 0) );

//    MessageBox(buff,
//               MB_OK | MB_ICONINFORMATION);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EscherTest - PumpWindows
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL EscherTest::PumpWindows ()
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
// EscherTest - ProcessEvents
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EscherTest::ProcessEvents()
{
    int                 doreshade=0;
    short               dx, dy;
    dword               cam_flags;

    // The shift has the effect of simultaneously
    // converting the number to a Flx16 and dividing by 1024,
    Flx16 interval(clock.check() << 6,0);
    clock.clear();

    evt->get_mouse_movement (&dx, &dy);

    if (events.check (DONE))
    {
        PostQuitMessage(0);
    }

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

            if (partn)
                partn->update(curmesh);
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
        if ((cam->flags & ESCH_CAM_APP0) && terrain)
        {
            EschPoint tp;
            cam->get_position(&tp);
            cam->set_position(tp.x,terrain->get_height(tp.x,tp.z) + Flx16(2.5),tp.z);  // only two meters above the ground.

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

    if (events.check (ADJUST_ALPHA))
    {
        if (events.check (MOVEXY))
        {
            alpha += dy;

            if (alpha < 0)
                alpha = 0;

            if (alpha > 255)
                alpha = 255;

            if (explosion)
                explosion->set_alpha(alpha);
            if (sprite)
                sprite->set_alpha(alpha);
            if (metabox)
                metabox->set_alpha(alpha);
        }
    }

    if (events.check (ADJUST_MBOX_SIZE) && metabox)
    {
        if (events.check (MOVEXY))
        {
            mbox_size.flx -= dy << 12;

            if (mbox_size < Flx16(1))
                mbox_size = Flx16(1);

            if (mbox_size > Flx16(500))
                mbox_size = Flx16(500);

            metabox->create_cube(mbox_size);
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
    if (single_events.check (TERRAIN_DEBUG) && terrain)
        terrain->flags ^= ESCH_TRN_DEBUG;

    if (single_events.check (CAM_HOVER) && terrain)
        cam->flags ^= ESCH_CAM_APP0;

    if (single_events.check (SHOW_EXTENTS))
    {
        drawexts++;
        if (drawexts > 3)
            drawexts=0;
    }

    if (single_events.check (ZBUFFER))
    {
        if (cam->vport->vflags & VNGO_ZBUFFER_DEV)
        {
            if (cam->vport->vflags & VNGO_ZBUFFER_ACTIVE)
                cam->vport->zbuffer_off();
            else
                cam->vport->zbuffer_on();
        }
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

    if (single_events.check (GRADIENT))
    {
        if (cam->flags & ESCH_CAM_GRADIENT)
        {
            cam->set_gradient(0);
        }
        else
        {
            cam->create_gradient(32,
                                 24, Flx16(0.5),
                                 VngoColor24bit(0,0,128),
                                 VngoColor24bit(255,255,255));
        }
    }

    if (single_events.check (PARTN_LIST) && partn)
    {
        EschGridPartition *gpartn = (EschGridPartition*)partn;

        for(ulong i=0; i < gpartn->nregions; i++)
        {
            for(EschPartitionList *ptr = gpartn->regions[i]; ptr != 0; ptr = ptr->next)
            {
                char buff[128];
                if (!ptr->item)
                {
                    wsprintf(buff,"Region #%i\n\n Invalid Entry!", i);
                }
                else
                {
                    wsprintf(buff,"Region #%i\n\nDrawables '%s'",
                                i,
                                ptr->item->name);
                }
                MessageBox(buff, MB_OK);
            }
        }
    }

    if (explosion)
    {
        if (single_events.check(EXPLOSION_RESET))
            explosion->reset();
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

        prtsystem->set_interval(interval);

        if (kind_of_particles)
            num = flx_rand().flx & 0x7;
        else
            num = flx_rand().flx & 0x7f;

        for(ulong c=0; c < num; c++)
        {
            EschParticle    *particle;

            switch (kind_of_particles)
            {
                case SPRITES:
                    {
                        EschSprite *ps = new EschSprite(*sprite);
                        particle = new EschParticleSprite(ps,
                                                        10 + (flx_rand().flx & 0x4f));
                    }
                    break;
                case PYRAMIDS:
                    particle = new EschParticlePyramid(1 + (flx_rand().flx & 0x3),
                                                    0,0,0,
                                                    mypal->get_index(VngoColor24bit((byte)(255 - (c*2)),0,0)),
                                                    10 + (flx_rand().flx & 0x4f));

                    ((EschParticlePyramid*)particle)->set_rotate_i(Flx16(flx_rand().flx >> 24));
                    ((EschParticlePyramid*)particle)->set_rotate_j(Flx16(flx_rand().flx >> 24));
                    ((EschParticlePyramid*)particle)->set_rotate_k(Flx16(flx_rand().flx >> 24));
                    break;
                default:
                    particle = new EschParticle(0,0,0,
                                                mypal->get_index(VngoColor24bit((byte)(255 - (c*2)),0,0)),
                                                20 + (flx_rand().flx & 0x4f));
                    break;
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

        if (single_events.check(FIRE_FIREBALL))
            fire->fireball();

        fire->animate();
    }

    if (mtxt)
    {
        mtxt->set_interval(interval);
        mtxt->animate();
    }

    if (single_events.check(SHOW_FPS))
    {
        show_fps = !show_fps;
    }

    if (single_events.check(PARTN_TOGGLE) && partn)
    {
        partn->set_flags(partn->flags ^ ESCH_PARTN_OFF);
    }

    // Perform animation of all drawables!
    for(EschDrawable *dptr = draws; dptr != NULL; dptr = dptr->next())
        dptr->animate();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EscherTest - Render
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EscherTest::Render()
{
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

    frames++;

    if (show_fps)
    {
        clock_t clk = fps_clock.check();

        sprintf (buff, "FPS:%5.2f\n\n", (float)( (clk)
                                                ? ((Flx16)frames / (Flx16)clk) * Flx16(1000)
                                                : 0) );

        gt.out (buff);
        sprintf (buff, "Proposed %d tris, %d drawn\n", EschProposedTris,EschDrawnTris);
        gt.out (buff);

        sprintf (buff, "FOV: %5.3f\n",float(cam->fov));
        gt.out (buff);


#if 0
        EschVector v;

        v.i = 1;
        v.j = 0;
        v.k = 0;
        v.transform(&cam->eye.orient);

        sprintf(buff,"(%5.3f %5.3f %5.3f)\n", float(v.i), float(v.j), float(v.k));
        gt.out(buff);

        v.k=0;
        v.normalize();

        Flx16 c_roll = v.i;

        sprintf(buff," C_roll: %5.3f",float(c_roll));
        gt.out(buff);

        Flx16 roll = c_roll.acos();
        if (v.j < 0)
            roll = -roll;

        sprintf(buff," (angle %5.3f)\n",float(roll));
        gt.out(buff);

        v.i = 0;
        v.j = 0;
        v.k = 1;
        v.transform(&cam->eye.orient);
        EschVector v2 = v;

        v.i=0;
        v.normalize();

        Flx16 c_pitch = v.k;

        sprintf(buff," C_pitch: %5.3f",float(c_pitch));
        gt.out(buff);

        Flx16 pitch = c_pitch.acos();
        if (v.j < 0)
            pitch = -pitch;

        sprintf(buff," (angle %5.3f)\n",float(pitch));
        gt.out(buff);

        v2.j=0;
        v2.normalize();

        Flx16 c_yaw = v2.k;

        sprintf(buff," C_yaw: %5.3f",float(c_yaw));
        gt.out(buff);

        Flx16 yaw = c_yaw.acos();
        if (v2.i < 0)
            yaw = -yaw;

        sprintf(buff," (angle %5.3f)\n",float(yaw));
        gt.out(buff);

        gt.outc('\n');
        sprintf(buff,"%5.3f %5.3f %5.3f\n",
                     float(cam->eye.orient.mtx[ESCH_MTX_A]),
                     float(cam->eye.orient.mtx[ESCH_MTX_B]),
                     float(cam->eye.orient.mtx[ESCH_MTX_C]));
        gt.out(buff);
        sprintf(buff,"%5.3f %5.3f %5.3f\n",
                     float(cam->eye.orient.mtx[ESCH_MTX_D]),
                     float(cam->eye.orient.mtx[ESCH_MTX_E]),
                     float(cam->eye.orient.mtx[ESCH_MTX_F]));
        gt.out(buff);
        sprintf(buff,"%5.3f %5.3f %5.3f\n",
                     float(cam->eye.orient.mtx[ESCH_MTX_G]),
                     float(cam->eye.orient.mtx[ESCH_MTX_H]),
                     float(cam->eye.orient.mtx[ESCH_MTX_I]));
        gt.out(buff);
#endif
    }

    if (frames > 100)
    {
        total_frames += frames;
        frames=0;
        total_time += fps_clock.check();
        fps_clock.clear();
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

        EschDrawable *drw = (curmesh) ? curmesh : draws;

        esch_error_codes err;
        err = drw->collide(&collide);
        if (err)
        {
            wsprintf(buff,"Collide returned error %d\n",(int)err);
            gt.out(buff);
        }
        if (collide.count)
        {
            wsprintf(buff,"Collisions:\n"
                        "'%s' hit %d (of %d max)\n",drw->name,
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
    screen->invalidate();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EscherTest - Display
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void EscherTest::Display()
{
#if 1
    screen->flip();
#else
    SetDIBitsToDevice (hdc, 0, 0, MAP_XSIZE, MAP_YSIZE, 0, 0, 0, MAP_YSIZE,
                       gmap, bmi, DIB_PAL_COLORS);
#endif
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// EscherTest - MessageBox
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int EscherTest::MessageBox(LPCSTR lpText, UINT nType)
{
    return ::MessageBox(hWndClient,lpText,szAppName,nType);
}

//°±² eof - GState.cpp ²±°

