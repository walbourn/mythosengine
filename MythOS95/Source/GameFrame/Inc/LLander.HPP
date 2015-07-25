//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//            LLander -- A Lunar Lander game based on GameFrame
//
//                        For Microsoft Windows '95
//
//               Copyright (c) 1995 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
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
// llander.hpp
//
// Lunar Lander example header file.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __LLANDER_HPP
#define __LLANDER_HPP    1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//             
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <global.hpp>


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                 Data
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

// {1E6E9FA3-1200-11cf-887E-00400516ED44}
const GUID LANDER_GUID = 
{ 0x1e6e9fa3, 0x1200, 0x11cf, { 0x88, 0x7e, 0x0, 0x40, 0x5, 0x16, 0xed, 0x44 } };

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  LanderNetwork
//  The custom version of TurnerNetwork for Lunar Lander.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class LanderNetwork: public TurnerNetwork
{
public:
        LanderNetwork (int players = 2);

        int     handle_msg (DPID, DPID, void *, size_t);
        int     sys_newplayer (DPID, LPCSTR, LPCSTR);
        int     sys_delplayer (DPID);
};



class Lander;
class Terrain;
class LunarLander;

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Lander class
//
// The Lander is the actual vehicle moving under the player's control.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class Lander: public BozoTask
{
    MaxEventSource  *evt;

public:

    Lander  (MaxEventSource *, BOOL remote = FALSE,
             VngoColor24bit = VngoColor24bit (128, 128, 128));
    ~Lander ();

public:
    void        run ();

    void        reset (Flx16 x = 0, Flx16 y = 10);

    void        process_events ();
    void        update_model ();
    BOOL        load_images (const char *fname);
    void        draw    (VngoVport *);

public:
    BYTE        lander_color;
    BYTE        flame_color;
    BYTE        *lander_image;
    BYTE        *lander_image_lowburn;
    BYTE        *lander_image_highburn;
    BYTE        *lander_image_leftburn;
    BYTE        *lander_image_rightburn;

    time_t      start_time;
    time_t      last_update;
    DWORD       jcenterx;
    DWORD       jcentery;
    Flx16       gravity;
    Flx16       xacceleration;
    Flx16       yacceleration;
    Flx16       xvelocity;
    Flx16       yvelocity;
    Flx16       xpos;
    Flx16       ypos;
    BOOL        remote;
    BOOL        active;
    DPID        player_id;
    RECT        damage;

    Flx16       get_thrust () const
                { return flx_abs (yacceleration) + flx_abs (xacceleration); }

    BOOL        too_fast () const
                { return xvelocity < -15 || yvelocity > 15 ||
                         xvelocity < -5  || xvelocity > 5; }

    BOOL        collided (Terrain *);
    BOOL        landed (Terrain *);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Terrain class
//
// The terrain is the moon's surface.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class Terrain
{
public:
    Terrain (int num);
    ~Terrain ();

public:
    WORD        *aHeights;
    WORD        cHeights;

    void        draw     (VngoVport *) const;
    WORD        col_size (int wid) const { return wid / cHeights; }
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LunarLander class
//
// This the GameState class for the simulation mode.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class LunarLander: public GameState
{
private:
    BYTE        *backbits;
    VngoVportDD8    *gvpb;

    MaxEventSource  *evt;           // Source of our events

    UINT        frame;
    Chronometer timer;

public:
    enum        { NUM_LANDERS = 4 };
    Lander      *aLanders[NUM_LANDERS];
    Terrain     terrain;

    Lander      *get_lander (DPID player);
    Lander      *init_lander (DPID player);
    void        kill_lander (DPID player);

    void        restore (LPRECT);

public:
    LunarLander ();
    ~LunarLander ();

    int     init (const char *fname, const char *cname);

    void    draw_terrain ();

    virtual void    render();
    virtual void    process_events();

    virtual void    activate();
    virtual void    deactivate();
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderTitle class
//
// This the GameState class for the title mode.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class LanderTitle: public GameState
{
private:
    MaxEventSource  *evt;           // Source of our events
    MaxEventListOneshot oneshot;    // Track events for single_events
    MaxEventList    events;         // Most current event set
    MaxEventList    single_events;  // Most current event set, momentary

    EschScene       *scene;

public:
    LanderTitle ();
    ~LanderTitle ();

    int         init (const char *fname, const char *cname);

    virtual void    render();
    virtual void    process_events();
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderLanded class
//
// This the GameState class for the crash mode.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class LanderLanded: public GameState
{
private:
    MaxEventSource  *evt;           // Source of our events

public:
    int         crashed;
    int         lander_dx;
    int         lander_dy;
    int         frame_rate;

    LanderLanded ();
    ~LanderLanded ();

    int         init (const char *fname, const char *cname);

    virtual void    render();
    virtual void    process_events();

    virtual void    activate();
};

#endif

//°±² end of header - llander.hpp ²±°

