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
//ששששששששששששששששששששש Microsoft Windows '95 Version ששששששששששששששששששששששש
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
// global.hpp
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

#ifndef __GLOBAL_HPP
#define __GLOBAL_HPP    1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

// NOTE: the including file must define any Windows control defines

#include <windows.h>
#include <stdio.h>

#include "portable.h"
#include "debug.h"

#include <chronos.hpp>
#include <ivory.hpp>
#include <max.hpp>
#include <vangogh.hpp>
#include <gutenbrg.hpp>

#include "escher.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#if defined (WIN32)
        #define IS_WIN32 TRUE
#else
        #define IS_WIN32 FALSE
#endif
#define IS_NT      IS_WIN32 && (BOOL)(GetVersion() < 0x80000000)
#define IS_WIN32S  IS_WIN32 && (BOOL)(!(IS_NT) && (LOBYTE(LOWORD(GetVersion()))<4))
#define IS_CHICAGO (BOOL)(!(IS_NT) && !(IS_WIN32S)) && IS_WIN32

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

class EscherTest
{
protected:
    TCHAR   szFileName[MAX_PATH];

    MaxDevices      *devs;
    MaxEventSource  *evt;           // Source of our events
    MaxEventListOneshot oneshot;    // Track events for single_events
    MaxEventListToggle  toggles;
    MaxEventList    events;         // Most current event set
    MaxEventList    single_events;  // Most current event set, momentary
    MaxEventList    toggle_events;

public:     // Construction/Destruction
//    enum { MAP_XSIZE = 320, MAP_YSIZE = 240 };
//    enum { MAP_XSIZE = 640, MAP_YSIZE = 480 };
    enum { MAP_XSIZE = 284, MAP_YSIZE = 256 };
//    enum { MAP_XSIZE = 144, MAP_YSIZE = 128 };
//    enum { MAP_XSIZE = 400, MAP_YSIZE = 400};

    BITMAPINFO      *bmi;
    BYTE            *gmap;
    VngoVport       *gvp;
    VngoPal         *mypal;
    HPALETTE        hpal;
    HDC             hdc;

    VngoScreenManager  *screen;
    int             map_xsize;
    int             map_ysize;

    EscherTest (MaxDevices *);
    ~EscherTest ();

    BOOL    active;

    BOOL    show_fps;
    BOOL    pick_test;
    BOOL    collide_test;
    BOOL    use_new_terrain;
    float   mbox_size;
    long    alpha;

    EschCameraEx            *cam;
    EschLight               *light;
    EschDrawable            *draws;
    EschScene               *scene;
    EschTerrain             *terrain;
    EschParticleGenerator   *prtgen;
    EschStarfield           *starfield;
    EschPlosion             *explosion;
    EschMeshDraw            *curmesh;
    EschFireTexture         *fire;
    EschPartition           *partn;
    EschSprite              *sprite;
    EschMetabox             *metabox;
    EschMultiFrameTexture   *mtxt;
    EschTerrainTreeTop      *trees;
    int                     drawexts;
    dword                   exts_color;
    float                   RotateDegrees;
    float                   ScriptRotateDegrees;

    XFBitmap                *backgrnd;

    Chronometer             fps_clock;
    long                    frames;
    long                    total_frames;
    long                    total_time;

    Chronometer             clock;

    BOOL SetupFireTest();
    BOOL SetupPartitionTest();
    BOOL SetupMultiTest(const char *name);
    BOOL SetupSprite(const char *name);

    BOOL LoadScene(char *fn);
    BOOL LoadTreeTops(const char *buff);
    BOOL LoadTerrain(char *fn);
    BOOL SetupParticleSystem(const char *name);
    BOOL SetupStarfield(BOOL fixed, BOOL brights);
    BOOL SetupExplosion(const char *buff);
    BOOL SetupMetabox(const char *buff);

    void Begin();
    void End(char *buff);

            // Per-Frame Members
    virtual BOOL    PumpWindows ();
    virtual void    LoadEvents (LPCSTR lpszFile);
    virtual void    GetEvents ();
    virtual void    ProcessEvents();
    virtual void    Render();
    virtual void    Display();

    int MessageBox(LPCSTR lpText, UINT nType);
};


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                 Data
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern HINSTANCE   hInst;         // current instance
extern HWND        hWndClient;    // Main window handle
extern const char  szAppName[];
extern EscherTest   *game;


#endif

//°±² End of header - global.hpp ²±°

