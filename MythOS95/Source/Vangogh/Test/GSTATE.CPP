//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  |
//                                                           |_|_|_._._.|
// Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
//              All rights reserved.                        %\__________/%
//                                                           %          %
//
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
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define WIN32_LEAN_AND_MEAN
#include "global.hpp"
#include "GFrame.hpp"
#include "vngd3d.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

void MakePal16fromPal8(VngoPal16 *p16, VngoPal8 *p8);

const int MAXPAGES = 3;

extern MaxDevices *Devs;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

LRESULT CALLBACK ClientWndProc (HWND, UINT, WPARAM, LPARAM);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
GameState::GameState (MaxDevices *d):
    devs (d),
    evt (0),
    screen (NULL),
    active (FALSE),
    map_xsize(MAP_XSIZE),
    map_ysize(MAP_YSIZE),
    PixTest(FALSE),
    PolyTest(FALSE),
    GPolyTest(FALSE),
    GRPolyTest(FALSE),
    TPolyTest(FALSE),
    GTPolyTest(FALSE),
    TPolyTestPersp(FALSE),
    GTPolyTestPersp(FALSE),
    LineTest(FALSE),
    GLineTest(FALSE),
    ITransTest(FALSE),
    BackGroundFill(FALSE),
    Reset(FALSE),
    ZBuffer(FALSE),
    ticks (0),
    frames (0)
{

    int         use_fullscreen = 0;
    XFParseINI  ini;
    char        buff[128];
    char        palname[128];

    strcpy(palname,".\\default.pal");

    if (ini.open(".\\VT.INI",XF_OPEN_READ) == XF_ERR_NONE)
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
#ifdef _OEMS
#ifdef _MSI
        if (!ini.read("UseMSI",buff))
        {
            strlwr(buff);
            if (strstr(buff,"yes") || strstr(buff,"on"))
            {
                screen = new VngoMSI (ClientWndProc);
            }
        }
#endif
#ifdef _3DFX
        if (!ini.read("Use3DFX",buff))
        {
            strlwr(buff);
            if (strstr(buff,"yes") || strstr(buff,"on"))
            {
                screen = new Vngo3Dfx ();
            }
        }
#endif
#endif
#ifdef _D3D
        if (!ini.read("UseD3D",buff))
        {
            strlwr(buff);
            if (strstr(buff,"yes") || strstr(buff,"on"))
            {
                screen = new VngoDirect3D (hWndClient);
                use_fullscreen |= VNGO_3DDEVICE | VNGO_ALLOC_ZBUFFER;
            }
        }
#endif
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

        if (!ini.read("Palette",palname))
        {
            strlwr(palname);
        }

        ini.close();
        // If we did not want a DDraw screen then use a DIB.
        if (screen == NULL)
        {
            screen = new VngoDIB (hWndClient);
        }
        else if (screen->get_initstate() == FALSE)
        {
            delete screen;
            screen = new VngoDIB (hWndClient);
        }
    }
    else
    {
        screen = new VngoDIB (hWndClient);
    }

// Use Direct Draw first then DIB.


    if (screen->get_type() == VngoScreenManager::SCREENTYPE_DIB)
        mypal = new VngoPal15;
    else if ((screen->get_type() == VngoScreenManager::SCREENTYPE_DDRAW)
             || (screen->get_type() == VngoScreenManager::SCREENTYPE_D3D))
        mypal = new VngoPal16;
    else
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
        if (
           (screen->get_type() == VngoScreenManager::SCREENTYPE_3DFX)
           || (screen->get_type() == VngoScreenManager::SCREENTYPE_MSI)
           || (screen->get_type() == VngoScreenManager::SCREENTYPE_DIB)
           || (screen->get_type() == VngoScreenManager::SCREENTYPE_D3D)
           || (screen->get_type() == VngoScreenManager::SCREENTYPE_DDRAW)
           )
        {
            screen->set_mode (map_xsize, map_ysize, 16 , mypal, use_fullscreen);
        }
        else
            screen->set_mode (map_xsize, map_ysize, 8 , mypal, use_fullscreen);


        if (screen->get_type() == VngoScreenManager::SCREENTYPE_DDRAW)
        {
            VngoDirectDraw *ldd = (VngoDirectDraw *)screen;
            gvp = new VngoVportDD16(ldd->SurfaceManager, NULL, mypal,VNGO_ZBUFFER_DEV);
//            gvp = new VngoVportDD8(ldd->SurfaceManager, NULL, mypal,VNGO_ZBUFFER_DEV);
        }
        else if (screen->get_type() == VngoScreenManager::SCREENTYPE_DIB)
        {
            VngoDIB *ldib = (VngoDIB *)screen;
            gvp = new VngoVportDB16(map_xsize,map_ysize,ldib->gmap,NULL,mypal,VNGO_ZBUFFER_DEV);
//            gvp = new VngoVportDB8(map_xsize,map_ysize,ldib->gmap,NULL,mypal,VNGO_ZBUFFER_DEV);
        }
#ifdef _OEMS
#ifdef _3DFX
        else if (screen->get_type() == VngoScreenManager::SCREENTYPE_3DFX)
        {
            gvp = new VngoVport3Dfx(map_xsize,map_ysize,0,0,mypal,VNGO_ZBUFFER_DEV);
        }
#endif
#ifdef _MSI
        else if (screen->get_type() == VngoScreenManager::SCREENTYPE_MSI)
        {
            VngoMSI *msi = (VngoMSI *)screen;
            gvp = new VngoVportMSI(map_xsize,map_ysize,0,0,mypal,VNGO_ZBUFFER_DEV,msi);
              gvp = NULL;
        }
#endif
#endif
        else if (screen->get_type() == VngoScreenManager::SCREENTYPE_D3D)
        {
            gvp = new VngoVportD3D(0,0,map_xsize,map_ysize,mypal,VNGO_ZBUFFER_DEV,screen);
        }
        else
        {
            gvp = new VngoVVport8(0,0,map_xsize,map_ysize,mypal,VNGO_ZBUFFER_DEV);
        }


        gberg_color(gvp->vbuff.pal->get_index(VngoColor24bit(255,255,255)),
                    VNGO_TRANSPARENT);


    }

    XFParseBMP  bmp;
    xf_error_codes  err;

    if (bmp.nameread("samp1.bmp"))
    {
        err =bmp.error();
    }
    else
    {
        tex[0].width = bmp.bm->width;
        tex[0].height = bmp.bm->height;
        tex[0].flags = VNGO_TEXTURE_8BIT;
        int t = tex[0].width * tex[0].height;
        tex[0].tex = (byte *)ivory_alloc(sizeof(byte) * t);
        memcpy (tex[0].tex, ivory_hlock(bmp.bm->handle),t);
        ivory_hunlock(bmp.bm->handle);
    }

    if (bmp.nameread("samp2.bmp"))
    {
        err =bmp.error();
    }
    else
    {
        tex[1].width = bmp.bm->width;
        tex[1].height = bmp.bm->height;
        tex[1].flags = VNGO_TEXTURE_8BIT;
        int t = tex[1].width * tex[1].height;
        tex[1].tex = (byte *)ivory_alloc(sizeof(byte) * t);
        memcpy (tex[1].tex, ivory_hlock(bmp.bm->handle),t);
        ivory_hunlock(bmp.bm->handle);
    }
    if (bmp.nameread("samp3.bmp"))
    {
        err =bmp.error();
    }
    else
    {
        tex[2].width = bmp.bm->width;
        tex[2].height = bmp.bm->height;
        tex[2].flags = VNGO_TEXTURE_8BIT;
        int t = tex[2].width * tex[2].height;
        tex[2].tex = (byte *)ivory_alloc(sizeof(byte) * t);
        memcpy (tex[2].tex, ivory_hlock(bmp.bm->handle),t);
        ivory_hunlock(bmp.bm->handle);
    }
    if (bmp.nameread("samp4.bmp"))
    {
        err =bmp.error();
    }
    else
    {
        tex[3].width = bmp.bm->width;
        tex[3].height = bmp.bm->height;
        tex[3].flags = VNGO_TEXTURE_8BIT;
        int t = tex[3].width * tex[3].height;
        tex[3].tex = (byte *)ivory_alloc(sizeof(byte) * t);
        memcpy (tex[3].tex, ivory_hlock(bmp.bm->handle),t);
        ivory_hunlock(bmp.bm->handle);
    }
    if (bmp.nameread("pattern.bmp"))
    {
        err =bmp.error();
    }
    else
    {
        tex[4].width = bmp.bm->width;
        tex[4].height = bmp.bm->height;
        tex[4].flags = VNGO_TEXTURE_8BIT;
        int t = tex[4].width * tex[4].height;
        tex[4].tex = (byte *)ivory_alloc(sizeof(byte) * t);
        memcpy (tex[4].tex, ivory_hlock(bmp.bm->handle),t);
        ivory_hunlock(bmp.bm->handle);
    }
    if (bmp.nameread("fsml0.bmp"))
    {
        err =bmp.error();
    }
    else
    {
        tex[5].width = bmp.bm->width;
        tex[5].height = bmp.bm->height;
        tex[5].flags = VNGO_TEXTURE_8BIT;
        int t = tex[5].width * tex[5].height;
        tex[5].tex = (byte *)ivory_alloc(sizeof(byte) * t);
        memcpy (tex[5].tex, ivory_hlock(bmp.bm->handle),t);
        ivory_hunlock(bmp.bm->handle);
    }
    if (bmp.nameread("fsml1.bmp"))
    {
        err =bmp.error();
    }
    else
    {
        tex[6].width = bmp.bm->width;
        tex[6].height = bmp.bm->height;
        tex[6].flags = VNGO_TEXTURE_8BIT;
        int t = tex[6].width * tex[6].height;
        tex[6].tex = (byte *)ivory_alloc(sizeof(byte) * t);
        memcpy (tex[6].tex, ivory_hlock(bmp.bm->handle),t);
        ivory_hunlock(bmp.bm->handle);
    }
    if (bmp.nameread("fsml2.bmp"))
    {
        err =bmp.error();
    }
    else
    {
        tex[7].width = bmp.bm->width;
        tex[7].height = bmp.bm->height;
        tex[7].flags = VNGO_TEXTURE_8BIT;
        int t = tex[7].width * tex[7].height;
        tex[7].tex = (byte *)ivory_alloc(sizeof(byte) * t);
        memcpy (tex[7].tex, ivory_hlock(bmp.bm->handle),t);
        ivory_hunlock(bmp.bm->handle);
    }
    if (bmp.nameread("fsml3.bmp"))
    {
        err =bmp.error();
    }
    else
    {
        tex[8].width = bmp.bm->width;
        tex[8].height = bmp.bm->height;
        tex[8].flags = VNGO_TEXTURE_8BIT;
        int t = tex[8].width * tex[8].height;
        tex[8].tex = (byte *)ivory_alloc(sizeof(byte) * t);
        memcpy (tex[8].tex, ivory_hlock(bmp.bm->handle),t);
        ivory_hunlock(bmp.bm->handle);
    }
    if (bmp.nameread("fsml4.bmp"))
    {
        err =bmp.error();
    }
    else
    {
        tex[9].width = bmp.bm->width;
        tex[9].height = bmp.bm->height;
        tex[9].flags = VNGO_TEXTURE_8BIT;
        int t = tex[9].width * tex[9].height;
        tex[9].tex = (byte *)ivory_alloc(sizeof(byte) * t);
        memcpy (tex[9].tex, ivory_hlock(bmp.bm->handle),t);
        ivory_hunlock(bmp.bm->handle);
    }
    if (bmp.nameread("cockpit1.bmp"))
    {
        err =bmp.error();
    }
    else
    {
        tex[10].width = bmp.bm->width;
        tex[10].height = bmp.bm->height;
        int t = tex[10].width * tex[10].height;
        if (mypal->flags & VNGO_8BIT)
        {
            tex[10].flags = VNGO_TEXTURE_8BIT;
            tex[10].tex = (byte *)ivory_alloc(sizeof(byte) * t);
            memcpy (tex[10].tex, ivory_hlock(bmp.bm->handle),t);
        }
        else
        {
            tex[10].flags &= ~VNGO_TEXTURE_8BIT;

            if (mypal->flags & VNGO_16BIT)
                tex[10].flags |= VNGO_TEXTURE_16BIT;
            else
                tex[10].flags |= VNGO_TEXTURE_15BIT;

            tex[10].tex = (byte *)ivory_alloc(sizeof(word) * t);
            byte    *sptr = (byte*)ivory_hlock(bmp.bm->handle);
            word    *dptr = (word*)tex[10].tex;
            for (int i=0;i < bmp.bm->height;i++)
            {
                for (int j=0;j < bmp.bm->width;j++)
                {
                    int t = *sptr;
                    sptr++;
                    if (t == 255)
                    {
                        if (mypal->flags & VNGO_15BIT)
                            *dptr = 0x7c1f; // Transparent Color for 15bpp.
                        else
                            *dptr = 0xf81f; // Transparent Color for 16bpp.
                    }
                    else
                    {
                        VngoColor24bit  tclr = mypal->get_RGB(t);
                        if (mypal->flags & VNGO_15BIT)
                            *dptr = tclr.compress();
                        else
                            *dptr = tclr.compress16();
                    }
                    dptr++;
                }
            }

        }
        ivory_hunlock(bmp.bm->handle);
        testtex = new VngoCTexture;
        testtex->init(&tex[10]);
    }


}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
GameState::~GameState ()
{

    char    buff[255];
    char    scrname[12];

    int bpp = 8;
    strcpy(scrname,"No Screen");

    if (screen)
    {
        bpp = screen->bit_depth;
        strcpy(scrname,screen->hwName);
        delete screen;
    }



    for (int i=0;i < 4;i++)
    {
        if (tex[i].tex)
            ivory_free((void **)&(tex[i].tex));
    }
    if (ticks > 0)
    {
        double frate  = (double)frames * 1000.0 / (double)ticks;
        double flip_ms = flip_timer.check_elapsed() / (double)frames;
        double draw_ms = draw_timer.check_elapsed() / (double)frames;
        double reset_ms = reset_timer.check_elapsed() / (double)frames;


        sprintf(buff,"Device is %s BPP = %d\n"
                     "Frame Rate %f\n"
                     "Flip averages %f ms,\n"
                     "Draw averages %f ms,\n"
                     "Reset averages %f ms.",
                     scrname,bpp,frate,flip_ms,draw_ms,reset_ms);
        MessageBox(0,
                   buff,
                   "VanGogh Benchmark Information",
                   MB_OK | MB_ICONINFORMATION | MB_SYSTEMMODAL);
    }


    // Clean up our event source
    if (evt)
    {
        evt->uninstall();
        delete evt;
    }

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
    evt = new MaxEventUser (*devs, szFileName, "gframe");

    // Verify the event system matches our set of events?

    // Now, let 'er rip!
    evt->install();
    active = TRUE;
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

    Devs->wm_clear();
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
    short               dx, dy;

    evt->get_mouse_movement (&dx, &dy);

    if (events.check (DONE))
        DestroyWindow (hWndClient);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::Render
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::Render()
{
    static int count=0;
    static int smoke_count=5;
    static int current_alpha=255;
    render_timer.clear();

    if (!ZBuffer)
        gvp->zbuffer_off();

    reset_timer.start();
    if (Reset)
    {
        if (gvp->lock() != -1)
        {
            gvp->reset(gvp->vbuff.pal->get_index(VngoColor24bit(32,32,64)));
            gvp->unlock();
        }
    }
    reset_timer.stop();


    draw_timer.start();

    if (PixTest)
    {
        if (gvp->lock() != -1)
        {
            VngoPoint       pt;

            dword tx = flx_rand().flx;
            dword ty = flx_rand().flx;

            tx &= 0x7fffffff;
            ty &= 0x7fffffff;

            pt.z = 0x50000000;
            pt.x = (int)tx % (gvp->vbuff.width - 1);
            pt.y = (int)ty % (gvp->vbuff.height - 1);

            VngoColor24bit  tclr(flx_rand().flx % 255,
                                 flx_rand().flx % 255,
                                 flx_rand().flx % 255);

            gvp->pixel(&pt,&tclr);

            gvp->unlock();
        }
    }

    if (LineTest)
    {
        if (gvp->lock() != -1)
        {
            VngoPoint   pts[2];
            VngoColor24bit  tclr(flx_rand().flx % 255,
                                 flx_rand().flx % 255,
                                 flx_rand().flx % 255);

            for (int i=0; i < 2;i++)
            {
                dword tx = flx_rand().flx;
                dword ty = flx_rand().flx;
                dword ts = flx_rand().flx;

                tx &= 0x7fffffff;
                ty &= 0x7fffffff;
                ts &= 0xff;
                pts[i].z = 0x50000000;
                pts[i].x = (int)tx % (gvp->vbuff.width - 1);
                pts[i].y = (int)ty % (gvp->vbuff.height - 1);
                pts[i].clr = gvp->vbuff.pal->get_index(tclr);
                pts[i].shade = ts;
            }
            gvp->line(&pts[0],&pts[1]);
            gvp->unlock();
        }
    }

    if (GLineTest)
    {
        if (gvp->lock() != -1)
        {
            VngoPoint   pts[2];
            VngoColor24bit  tclr(flx_rand().flx % 255,
                                 flx_rand().flx % 255,
                                 flx_rand().flx % 255);

            for (int i=0; i < 2;i++)
            {
                dword tx = flx_rand().flx;
                dword ty = flx_rand().flx;
                dword ts = flx_rand().flx;

                tx &= 0x7fffffff;
                ty &= 0x7fffffff;
                ts &= 0xff;
                pts[i].z = 0x50000000;
                pts[i].x = (int)tx % (gvp->vbuff.width - 1);
                pts[i].y = (int)ty % (gvp->vbuff.height - 1);
                pts[i].clr = gvp->vbuff.pal->get_index(tclr);
                pts[i].shade = ts;
            }
            gvp->gline(&pts[0],&pts[1]);
            gvp->unlock();
        }
    }

    if (PolyTest)
    {
        if (gvp->lock() != -1)
        {
            VngoPoint   pts[3];
            VngoColor24bit  tclr(flx_rand().flx % 255,
                                 flx_rand().flx % 255,
                                 flx_rand().flx % 255);

            for (int i=0; i < 3;i++)
            {
                dword tx = flx_rand().flx;
                dword ty = flx_rand().flx;
                dword ts = flx_rand().flx;

                tx &= 0x7fffffff;
                ty &= 0x7fffffff;
                ts &= 0xff;
                pts[i].z = 0x50000000;
                pts[i].x = (int)tx % (gvp->vbuff.width - 1);
                pts[i].y = (int)ty % (gvp->vbuff.height - 1);
                pts[i].clr = gvp->vbuff.pal->get_index(tclr);
                pts[i].shade = ts;
            }
            gvp->poly(3,pts);
            gvp->unlock();
        }

    }

    if (GPolyTest)
    {
#if 1
        if (gvp->lock() != -1)
        {
            VngoPoint   pts[3];
            VngoColor24bit  tclr(flx_rand().flx % 255,
                                 flx_rand().flx % 255,
                                 flx_rand().flx % 255);

            for (int i=0; i < 3;i++)
            {
                dword tx = flx_rand().flx;
                dword ty = flx_rand().flx;
                dword ts = flx_rand().flx;

                tx &= 0x7fffffff;
                ty &= 0x7fffffff;
                ts &= 0xff;
                pts[i].z = 0x50000000;
                pts[i].x = (int)tx % (gvp->vbuff.width - 1);
                pts[i].y = (int)ty % (gvp->vbuff.height - 1);
                pts[i].clr = gvp->vbuff.pal->get_index(tclr);
                pts[i].shade = ts;
            }
            gvp->gpoly(3,pts);
            gvp->unlock();
        }
#else
        if (gvp->lock() != -1)
        {
            VngoPoint   pts[4];
            VngoColor24bit  tclr(255,
                                 255,
                                 255);

            pts[0].x = 0;
            pts[0].y = 0;
            pts[1].x = map_xsize - 1;
            pts[1].y = 0;
            pts[2].x = map_xsize - 1;
            pts[2].y = map_ysize - 1;
            pts[3].x = 0;
            pts[3].y = map_ysize - 1;
            pts[0].shade = 128;
            pts[1].shade = 32;
            pts[2].shade = 96;
            pts[3].shade = 255;
            pts[0].z = 0x50000;
            pts[1].z = 0x50000;
            pts[2].z = 0x50000;
            pts[3].z = 0x50000;
            pts[0].clr = gvp->vbuff.pal->get_index(tclr);
            pts[1].clr = pts[0].clr;
            pts[2].clr = pts[0].clr;
            pts[3].clr = pts[0].clr;

            gvp->gpoly(4,pts);
            gvp->unlock();
        }
#endif
    }


    if (TPolyTest)
    {
        if (gvp->lock() != -1)
        {
            VngoPoint   pts[3];
            VngoColor24bit  tclr(flx_rand().flx % 255,
                                 flx_rand().flx % 255,
                                 flx_rand().flx % 255);

            for (int i=0; i < 3;i++)
            {
                dword tx = flx_rand().flx;
                dword ty = flx_rand().flx;
                dword ts = flx_rand().flx;

                tx &= 0x7fffffff;
                ty &= 0x7fffffff;
                ts &= 0xff;
                pts[i].z = 0x50000000;
                pts[i].x = (int)tx % (gvp->vbuff.width - 1);
                pts[i].y = (int)ty % (gvp->vbuff.height - 1);
                pts[i].clr = gvp->vbuff.pal->get_index(tclr);
                pts[i].shade = ts;
            }
            pts[0].u = 0;
            pts[0].v = 0;
            pts[1].u = 0x10000;
            pts[1].v = 0;
            pts[2].u = 0x10000;
            pts[2].v = 0x10000;

            gvp->tpoly(3,pts,&tex[count]);
            gvp->unlock();
        }
        count++;
        count &= 0x3;
    }

    if (GTPolyTest)
    {
        if (gvp->lock() != -1)
        {
            VngoPoint   pts[3];
            VngoColor24bit  tclr(flx_rand().flx % 255,
                                 flx_rand().flx % 255,
                                 flx_rand().flx % 255);

            for (int i=0; i < 3;i++)
            {
                dword tx = flx_rand().flx;
                dword ty = flx_rand().flx;
                dword ts = flx_rand().flx;

                tx &= 0x7fffffff;
                ty &= 0x7fffffff;
                ts &= 0xff;
                pts[i].z = 0x50000000;
                pts[i].x = (int)tx % (gvp->vbuff.width - 1);
                pts[i].y = (int)ty % (gvp->vbuff.height - 1);
                pts[i].clr = gvp->vbuff.pal->get_index(tclr);
                pts[i].shade = ts;
            }
            pts[0].u = 0;
            pts[0].v = 0;
            pts[1].u = 0x10000;
            pts[1].v = 0;
            pts[2].u = 0x10000;
            pts[2].v = 0x10000;

            gvp->gtpoly(3,pts,&tex[count]);
            gvp->unlock();
        }
        count++;
        count &= 0x3;
    }

    if (TPolyTestPersp)
    {
        if (gvp->lock() != -1)
        {
            VngoPoint   pts[4];

            pts[0].x = int(Flx16(map_xsize) * Flx16(.19375));
            pts[0].y = int(Flx16(map_ysize) * Flx16(.00833));
            pts[0].shade = 0x77;
            pts[0].z = 388968558;
            pts[0].w = 2963775;

            pts[1].x = int(Flx16(map_xsize) * Flx16(.85625));
            pts[1].y = int(Flx16(map_ysize) * Flx16(.28333));
            pts[1].shade = 0xf7;
            pts[1].z = 478476596;
            pts[1].w = 2409345;

            pts[2].x = int(Flx16(map_xsize) * Flx16(.91562));
            pts[2].y = int(Flx16(map_ysize) * Flx16(.98125));
            pts[2].shade = 0x10;
            pts[2].z = 382753696;
            pts[2].w = 3011898;

            pts[3].x = int(Flx16(map_xsize) * Flx16(.05468));
            pts[3].y = int(Flx16(map_ysize) * Flx16(.82916));
            pts[3].shade = 0x4f;
            pts[3].z = 293245656;
            pts[3].w = 3931227;

            pts[0].u = Flx16(0.01).flx;
            pts[0].v = Flx16(0.01).flx;
            pts[1].u = Flx16(0.99).flx;
            pts[1].v = Flx16(0.01).flx;
            pts[2].u = Flx16(0.99).flx;
            pts[2].v = Flx16(0.99).flx;
            pts[3].u = Flx16(0.01).flx;
            pts[3].v = Flx16(0.99).flx;
            pts[0].clr = 173;
            pts[1].clr = 173;
            pts[2].clr = 173;
            pts[3].clr = 173;

            gvp->tpoly_persp(4,pts,&tex[4]);
            gvp->unlock();
        }
    }

    if (GTPolyTestPersp)
    {
        if (gvp->lock() != -1)
        {
            VngoPoint   pts[4];

            pts[0].x = int(Flx16(map_xsize) * Flx16(.19375));
            pts[0].y = int(Flx16(map_ysize) * Flx16(.00833));
            pts[0].shade = 0x77;
            pts[0].z = 388968558;
            pts[0].w = 2963775;

            pts[1].x = int(Flx16(map_xsize) * Flx16(.85625));
            pts[1].y = int(Flx16(map_ysize) * Flx16(.28333));
            pts[1].shade = 0xf7;
            pts[1].z = 478476596;
            pts[1].w = 2409345;

            pts[2].x = int(Flx16(map_xsize) * Flx16(.91562));
            pts[2].y = int(Flx16(map_ysize) * Flx16(.98125));
            pts[2].shade = 0x10;
            pts[2].z = 382753696;
            pts[2].w = 3011898;

            pts[3].x = int(Flx16(map_xsize) * Flx16(.05468));
            pts[3].y = int(Flx16(map_ysize) * Flx16(.82916));
            pts[3].shade = 0x4f;
            pts[3].z = 293245656;
            pts[3].w = 3931227;

            pts[0].u = Flx16(0.01).flx;
            pts[0].v = Flx16(0.01).flx;
            pts[1].u = Flx16(0.99).flx;
            pts[1].v = Flx16(0.01).flx;
            pts[2].u = Flx16(0.99).flx;
            pts[2].v = Flx16(0.99).flx;
            pts[3].u = Flx16(0.01).flx;
            pts[3].v = Flx16(0.99).flx;
            pts[0].clr = 173;
            pts[1].clr = 173;
            pts[2].clr = 173;
            pts[3].clr = 173;

            gvp->gtpoly_persp(4,pts,&tex[4]);
            gvp->unlock();
        }
    }

    if (GRPolyTest)
    {
        if (gvp->lock() != -1)
        {
            VngoPoint   pts[4];
            VngoColor24bit tclr(255,0,0);

            pts[0].x = int(Flx16(map_xsize) * Flx16(.19375));
            pts[0].y = int(Flx16(map_ysize) * Flx16(.00833));
            pts[0].clr = (tclr.r << 16) | (tclr.g << 8) | tclr.b | VNGO_COLOR_24BIT;
            pts[0].z = 388968558;
            pts[0].w = 2963775;

            pts[1].x = int(Flx16(map_xsize) * Flx16(.85625));
            pts[1].y = int(Flx16(map_ysize) * Flx16(.28333));
            tclr.r = 0;
            tclr.g = 255;
            tclr.b = 0;
            pts[1].clr = (tclr.r << 16) | (tclr.g << 8) | tclr.b | VNGO_COLOR_24BIT;
            pts[1].z = 478476596;
            pts[1].w = 2409345;

            pts[2].x = int(Flx16(map_xsize) * Flx16(.91562));
            pts[2].y = int(Flx16(map_ysize) * Flx16(.98125));
            tclr.r = 0;
            tclr.g = 0;
            tclr.b = 255;
            pts[2].clr = (tclr.r << 16) | (tclr.g << 8) | tclr.b | VNGO_COLOR_24BIT;
            pts[2].z = 382753696;
            pts[2].w = 3011898;

            pts[3].x = int(Flx16(map_xsize) * Flx16(.05468));
            pts[3].y = int(Flx16(map_ysize) * Flx16(.82916));
            tclr.r = 255;
            tclr.g = 255;
            tclr.b = 255;
            pts[3].clr = (tclr.r << 16) | (tclr.g << 8) | tclr.b | VNGO_COLOR_24BIT;
            pts[3].z = 293245656;
            pts[3].w = 3931227;


            gvp->grpoly(4,pts);
            gvp->unlock();
        }
    }

    if (0)
    {
        VngoRect        trect(0,0,gvp->vbuff.width,gvp->vbuff.height);
        if (gvp->lock() != -1)
        {
            gvp->image_trans(&trect,testtex,VNGO_TRANSPARENT);
            gvp->unlock();
        }

    }

    if (ITransTest)
    {
        if (gvp->lock() != -1)
        {
            VngoRect    trect(flx_rand().flx % gvp->vbuff.width,
                              flx_rand().flx % gvp->vbuff.height,
                              tex[count].width,
                              tex[count].height);

            gvp->image_trans(&trect,&tex[count]);
            count++;
            count &= 0x3;
            gvp->unlock();
        }
    }
    draw_timer.stop();

    screen->invalidate();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  GameState::Display
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void GameState::Display()
{
    flip_timer.start();
    screen->flip();
    flip_timer.stop();
    ticks += render_timer.check();
    frames++;
}

//°±² eof - GState.cpp ²±°

