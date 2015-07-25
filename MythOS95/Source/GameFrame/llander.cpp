//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//            LLander -- A Lunar Lander game based on GameFrame
//      
//                        For Microsoft Windows '95
//      
//           Copyright (c) 1995, 1996 by Charybdis Enterprises, Inc.
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
// llander.cpp
//
// This file contains the Lunar Lander example code.  It has two support
// classes, in addition to two GameState modes.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define WIN32_LEAN_AND_MEAN
#include <stdlib.h>
#include <assert.h>

#include <global.hpp>

#include "llander.hpp"
#include "landevt.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

const int LANDER_ISIZE  = 16;
const int LANDER_SIZE   = 10;
const int LANDER_XOFFSET = 3;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// The basic network data packet
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
struct PacketData
{
    enum data_types
    {
        NULL_DATA,
        LANDER_POSITION,
        TERRAIN_DATA
    } type;

    PacketData (data_types t = NULL_DATA):
        type (t)
    {
    }

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Lander position packet
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
struct LanderPositionData: public PacketData
{
    Flx16   xpos;
    Flx16   ypos;
    Flx16   xvelocity;
    Flx16   yvelocity;
    Flx16   xacceleration;
    Flx16   yacceleration;
    DWORD   time;

    LanderPositionData (const Lander &l, DWORD _time=0):
        PacketData (LANDER_POSITION),
        time (_time),
        xpos (l.xpos),
        ypos (l.ypos),
        xvelocity (l.xvelocity),
        yvelocity (l.yvelocity),
        xacceleration (l.xacceleration),
        yacceleration (l.yacceleration)
    {
    }
    
    void stuff_into (Lander *l) const
    {
        l->xpos = xpos;
        l->ypos = ypos;
        l->xvelocity = xvelocity;
        l->yvelocity = yvelocity;
        l->xacceleration = xacceleration;
        l->yacceleration = yacceleration;
    }

};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Generic data packet
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
struct GenericData: public PacketData
{
    char    data;

    GenericData (data_types t = NULL_DATA):
        PacketData (t)
    {
    }
};

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderNetwork - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
LanderNetwork::LanderNetwork (int players):
    TurnerNetwork (LANDER_GUID, "Lander Mania!", players)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderNetwork - handle_msg
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int LanderNetwork::handle_msg (DPID from, DPID to, void *msg, size_t msg_len)
{
    GenericData  *pkt = (GenericData *)msg;

    switch (pkt->type)
    {
        case LanderPositionData::LANDER_POSITION:
            // there is only one other possible player, so it must be them.
            // The message is just a point (the lander location)
            ((LanderPositionData *)msg)->stuff_into (SimMode->get_lander (from));
            break;

        case LanderPositionData::TERRAIN_DATA:
            // Set the terrain data.
            memcpy (SimMode->terrain.aHeights, &pkt->data, SimMode->terrain.cHeights);
            SimMode->draw_terrain ();
            break;
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderNetwork - sys_newplayer
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int LanderNetwork::sys_newplayer (DPID id, LPCSTR short_name, LPCSTR long_name)
{
    Lander *lander = SimMode->init_lander (id);

    if (lander == 0)
        return 1;

    // Make it taskable
    lander->init ();

    if (Net->is_creator ())
    {
        // Inform the other player of the terrain they will be flying over
        int buf_len = sizeof (*SimMode->terrain.aHeights) * SimMode->terrain.cHeights
                    + sizeof (PacketData::data_types);
        void *buf = new char [buf_len];
        if (!buf)
            return 1;

        ((GenericData *)buf)->type = LanderPositionData::TERRAIN_DATA;
        memcpy (&((GenericData *)buf)->data,
                SimMode->terrain.aHeights,
                SimMode->terrain.cHeights);
        Net->send (SimMode->aLanders[0]->player_id, id, buf, buf_len);
        delete [] buf;
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderNetwork - sys_delplayer
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int LanderNetwork::sys_delplayer (DPID id)
{
    SimMode->kill_lander (id);

    return 0;
}



//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//±±±±±±±±±±±±±±±±±±±±±±±±± Lander Object Members ±±±±±±±±±±±±±±±±±±±±±±±±±±±
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Lander - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
Lander::Lander (MaxEventSource *_evt, BOOL _remote, VngoColor24bit color):
    evt (_evt),
    lander_image (0),
    lander_image_lowburn   (0),
    lander_image_highburn  (0),
    lander_image_leftburn  (0),
    lander_image_rightburn (0),
    remote (_remote)
{
    lander_color = (byte)Screen->pal->get_index (color);
    flame_color  = (byte)Screen->pal->get_index (VngoColor24bit (255,128,128));
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Lander - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
Lander::~Lander()
{
    if (lander_image)
        delete [] lander_image;
    if (lander_image_lowburn)
        delete [] lander_image_lowburn;
    if (lander_image_highburn)
        delete [] lander_image_highburn;
    if (lander_image_leftburn)
        delete [] lander_image_leftburn;
    if (lander_image_rightburn)
        delete [] lander_image_rightburn;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Lander - run
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void Lander::run ()
{
    for (;;)
    {
        if (!remote)
        {
            process_events ();
            update_model ();

            // If we're on the network, let everyone know our new position
            if (Net && Net->active())
            {
                LanderPositionData pd (*this);
                Net->broadcast (player_id, &pd, sizeof (pd));
            }
        }
        yield ();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Lander - reset
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void Lander::reset (Flx16 x, Flx16 y)
{
    xpos            = x;
    ypos            = y;

    gravity         = 10;
    xvelocity       = 50;
    yvelocity       = 0;
    xacceleration   = 0;
    yacceleration   = 0;

    damage.left     =
    damage.top      =
    damage.right    =
    damage.bottom   = 0;

	if (evt)
	{
    	// Adjust for joystick position

        if ((CmdFlags & CMDFLAGS_JOYSTICK)
            && Devs->theJoystick.joy_present)
        {
        	JOYINFOEX   j;
        	evt->get_joystick (&j);
        	jcenterx = j.dwXpos;
        	jcentery = j.dwYpos;
        }
	}

    start_time = last_update = chronos_time_now ();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Lander - process_events
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void Lander::process_events ()
{
    if (evt)
    {
        MaxEventList evts = evt->process ();

        if (evts.check (HOVER))
            gravity = 0;

        if (evts.check (DROP))
            gravity = 10;

        JOYINFOEX   j;

        // Adjust for joystick position
        if ((CmdFlags & CMDFLAGS_JOYSTICK)
            && Devs->theJoystick.joy_present)
            evt->get_joystick (&j);
        
        if (evts.check (UP))
            yacceleration = -25;
        else if (evts.check (DOWN))
            yacceleration = -40;
        else if ((CmdFlags & CMDFLAGS_JOYSTICK)
                 && Devs->theJoystick.joy_present
                 && j.dwYpos < jcentery - 2048)
            yacceleration = Flx16 (long (j.dwYpos - jcenterx) / 512);
        else
            yacceleration = 0;
        
        if (evts.check (LEFT))
            xacceleration = -10;
        else if (evts.check (RIGHT))
            xacceleration = 10;
        else if ((CmdFlags & CMDFLAGS_JOYSTICK)
                 && Devs->theJoystick.joy_present
                 && abs (j.dwXpos - jcenterx) > 4096)
            xacceleration = long (j.dwXpos - jcenterx) / 2048;
        else
            xacceleration = 0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Lander - update_model
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void Lander::update_model ()
{
    clock_t now     (chronos_time_now ());
    Flx16   elapsed (long (now - last_update));

    if (elapsed > 0)
    {
        last_update = now;

        // Make this a fraction of a second
        elapsed /= Flx16 (1000);

        // How much acceleration so far?
        xvelocity += xacceleration * elapsed;
        yvelocity += (yacceleration + gravity) * elapsed;

        // Now, how much have we moved so far?
        xpos += xvelocity * elapsed;
        ypos += yvelocity * elapsed;

        // Clip position
        if (ypos < 0)
            ypos = 0;

        if (xpos < 0)
            xpos = Flx16 (Screen->width - LANDER_ISIZE);
        else if (xpos > Screen->width - LANDER_ISIZE)
            xpos = 0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Lander - load_images
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL Lander::load_images ()
{
    byte        *data;
    XFParseIFF  iff;
    char        name[16];

    if (iff.open (szMasterIFF, XF_OPEN_READ))
        return FALSE;

    if (iff.seekform (iff.makeid ('L','L','N','D'))
        || iff.enterform ())
        return FALSE;

    while (!iff.seekform (iff.makeid ('M','I','M','G')))
    {
        if (iff.enterform ())
            return FALSE;

        if (iff.seekchunk (iff.makeid ('N','A','M','E'))
            || iff.chunkSize >= 16
            || iff.read(&name))
            return FALSE;

        if (iff.seekchunk (iff.makeid ('D','A','T','A'))
            || iff.chunkSize != (LANDER_ISIZE * (LANDER_ISIZE / 8)))
            return FALSE;

        data = new BYTE[LANDER_ISIZE * (LANDER_ISIZE / 8)];
        if (!data)
            return FALSE;

        if (iff.read (data)
            || iff.leaveform ())
        {
            delete [] data;
            return FALSE;
        }

        // Assign based on NAME of data block
        if (!strcmp (name,"Normal"))
        {
            lander_image = data;
        }
        else if (!strcmp (name,"Low"))
        {
            lander_image_lowburn = data;
        }
        else if (!strcmp (name,"High"))
        {
            lander_image_highburn = data;
        }
        else if (!strcmp (name,"Left"))
        {
            lander_image_leftburn = data;
        }
        else if (!strcmp (name,"Right"))
        {
            lander_image_rightburn = data;
        }
        else
        {
            delete [] data;
        }
    }

    // Must have all images for a successful load
    if (lander_image == 0
        || lander_image_lowburn == 0
        || lander_image_highburn == 0
        || lander_image_leftburn == 0
        || lander_image_rightburn == 0)
        return FALSE;

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Lander - draw
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void Lander::draw (VngoVport *vp)
{
    assertMyth("Must call load_images for Lander before calling draw",
               lander_image != 0
               && lander_image_lowburn != 0 && lander_image_highburn !=0 
               && lander_image_leftburn != 0 && lander_image_rightburn != 0);

    // Set up the bounding rect
    VngoRect r;
    r.x  = int (xpos);
    r.y  = int (ypos);
    r.dx = LANDER_ISIZE;
    r.dy = LANDER_ISIZE;

    VngoTexture mtex;
    mtex.width  = LANDER_ISIZE;
    mtex.height = LANDER_ISIZE;

    // Draw the basic lander
    mtex.tex = lander_image;
    vp->image_trans_mono (&r, &mtex, lander_color);

    if (xacceleration < 0)
    {
        mtex.tex = lander_image_rightburn;
        vp->image_trans_mono (&r, &mtex, flame_color);
    }
    else if (xacceleration > 0)
    {
        mtex.tex = lander_image_leftburn;
        vp->image_trans_mono (&r, &mtex, flame_color);
    }

    if (yacceleration <= -30)
    {
        mtex.tex = lander_image_highburn;
        vp->image_trans_mono (&r, &mtex, flame_color);
    }
    else if (yacceleration < 0)
    {
        mtex.tex = lander_image_lowburn;
        vp->image_trans_mono (&r, &mtex, flame_color);
    }

    // Record the damage rectangle
    damage.left   = int (xpos);
    damage.top    = int (ypos);
    damage.right  = int (xpos) + LANDER_ISIZE;
    damage.bottom = int (ypos) + LANDER_ISIZE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Lander - landed
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL Lander::landed (Terrain *terrain)
{
    // First, determine which "column" we're on
    const int colw = terrain->col_size (Screen->width);
    const int col  = (int (xpos) + LANDER_XOFFSET) / colw;

    // Now, check our altitude
    return int (ypos) + LANDER_SIZE > Screen->height - terrain->aHeights[col];
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Lander - collided
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL Lander::collided (Terrain *terrain)
{
    // Get columns we're over
    const int colw = terrain->col_size (Screen->width);
    const int lcol = (int (xpos) + LANDER_XOFFSET) / colw;
    const int rcol = (int (xpos) + LANDER_SIZE + LANDER_XOFFSET) / colw;

    // If it's the same column, we're not colliding
    if (lcol == rcol)
        return FALSE;

    // get our left/right "landing" states
    BOOL lland = int (ypos) + LANDER_SIZE > Screen->height - terrain->aHeights[lcol];
    BOOL rland = int (ypos) + LANDER_SIZE > Screen->height - terrain->aHeights[rcol];

    // If one side and not the other has landed, we have crashed!
    return lland != rland;
}



//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//±±±±±±±±±±±±±±±±±±±±±±±±±± Terrain Members ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Terrain - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
Terrain::Terrain (int num)
{
    // Allocate terrain storage
    cHeights = num;
    aHeights = new WORD[cHeights];
    if (!aHeights)
    {
        if (Mode)
            Mode->panic(IDS_ERR_NOMEMORY,"Terrain");
        return;
    }

    // Load up the terrain with values
    const int hscale = Screen->height / 4;
    aHeights[0] = hscale;
    for (int i = 1; i < cHeights; i++)
    {
        WORD h = aHeights[i-1] + (rand() % hscale) & 0xfff0;
        if (h > hscale/2)
            h -= hscale/2;
        aHeights[i] = h;
    }

    // Pick some landing sites and flatten them out
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Terrain - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
Terrain::~Terrain ()
{
    if (aHeights)
        delete aHeights;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Terrain - draw
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void Terrain::draw (VngoVport *vp) const
{
    // Calc the address of the end of screen memory
    const int   WIDTH = vp->vbuff.width / cHeights;

    // Fill in the screen background image
    for (int i = 0; i < cHeights-1; i++)
    {
        VngoRect r;

        r.x  = i * WIDTH;
        r.y  = vp->vbuff.height - aHeights[i];
        r.dx = WIDTH;
        r.dy = aHeights[i] - 1;

        vp->frect (&r, vp->vbuff.pal->get_index (VngoColor24bit (128,128,128)));
    }
}



//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//±±±±±±±±±±±±±±±±±±±±± Lunar Lander Simulation Mode ±±±±±±±±±±±±±±±±±±±±±±±±
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LunarLander - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
LunarLander::LunarLander ():
    GameState (), evt (0), terrain (64)
{
    // Allocate a back buffer
    backbits = new BYTE [Screen->width * Screen->height];
    if (!backbits)
    {
        panic(IDS_ERR_NOMEMORY,"LunarLander");
        return;
    }

    // Initialize the viewport
    gvpb = new VngoVportDB8 (Screen->width, Screen->height, backbits, NULL, 
                             Screen->pal, 0);
    if (!gvpb)
    {
        panic(IDS_ERR_CREATEVPORTFAILED,"LunarLander");
        return;
    }

    Net = new LanderNetwork (NUM_LANDERS);
    if (!Net)
    {
        panic(IDS_ERR_NOMEMORY,"LunarNetwork");
        return;
    }

    for (int i = 0; i < NUM_LANDERS; i++)
        aLanders[i] = 0;

    // Set up the Gutenbrg text color
    gberg_color (Screen->pal->get_index (VngoColor24bit (128,128,128)),
                 Screen->pal->get_index (VngoColor24bit (0,0,0)));
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LunarLander - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
LunarLander::~LunarLander()
{
    // Clean up our event source
    if (evt != 0)
    {
        evt->uninstall();
        delete evt;
    }

    for (int i = 0; i < NUM_LANDERS; i++)
        if (aLanders[i])
            delete aLanders[i];

    if (backbits)
        delete backbits;
    if (gvpb)
        delete gvpb;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LunarLander - init
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int LunarLander::init (const char *cname)
{
    assertMyth ("LunarLander can only be inited once", evt == 0);

    evt = new MaxEventUser (*Devs);

    if (evt == 0 || ((MaxEventUser *)evt)->load (szMasterIFF, cname) != 0)
        return 1;

    // Now, let 'er rip!
    evt->install();

    // Create the first lander (the player's lander)
    aLanders[0] = new Lander (evt, FALSE);
    if (!aLanders[0])
    {
        return 1;
    }

    if (!aLanders[0]->load_images ())
        return 1;

    aLanders[0]->init ();

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LunarLander - activate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LunarLander::activate ()
{
    // Connect to the network, where appropriate
    TurnerNetworkUI net_ui (hWndClient, Net);

    if (net_ui.connect ())
    {
        // We're on line!
        if (Net->is_creator ())
        {
            // OutputDebugString ("We are the creator\n");
        }
        else
        {
            // OutputDebugString ("We are joining an existing game\n");
            // Get the terrain from another session
        }

        // Lander #0 is your lander!
        aLanders[0]->player_id = Net->create_player (Net->is_creator () ? 
                                                     "Veteran": "Newbie",
                                                     "Lunar Lander Pilot");
    }
    else
    {
        // Solo play
    }

    // Initialize the terrain image
    draw_terrain ();

    // Reset the landers
    for (int i = 0; i < NUM_LANDERS; i++)
        if (aLanders[i])
            aLanders[i]->reset();

    // Initialize the time and frame count
    timer.clear();
    frame = 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LunarLander - deactivate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LunarLander::deactivate ()
{
    if (Net)
    {
        Net->close();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LunarLander - get_lander
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
Lander *LunarLander::get_lander (DPID player)
{
    for (int i = 0; i < NUM_LANDERS; i++)
    {
        if (aLanders[i] && aLanders[i]->player_id == player)
            return aLanders[i];
    }

    return 0;
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LunarLander - init_lander
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
Lander *LunarLander::init_lander (DPID player)
{
    // This is a cheezy hack for lander colors.
    // These should really be loaded from an IFF file or
    // something.
    static VngoColor24bit colors[NUM_LANDERS] = 
    {
        VngoColor24bit (128,128,128),
        VngoColor24bit (0,128,128),
        VngoColor24bit (128,0,128),
        VngoColor24bit (128,128,0)
    };

    for (int i = 0; i < NUM_LANDERS; i++)
    {
        if (aLanders[i] == 0)
        {
            Lander *l = new Lander (NULL, TRUE, colors[i]);

            if (l != 0)
            {
                l->player_id = player;
                l->init();
                l->reset ();
                if (!l->load_images ())
                    delete l;
                else
                    aLanders[i] = l;
            }

            return aLanders[i];
        }
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LunarLander - get_lander
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LunarLander::kill_lander (DPID player)
{
    for (int i = 0; i < NUM_LANDERS; i++)
    {
        if (aLanders[i] && aLanders[i]->player_id == player)
        {
            delete aLanders[i];
            aLanders[i] = 0;
            break;
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//  LunarLander - draw_terain
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LunarLander::draw_terrain ()
{
    // Initialize the terrain image
    memset (backbits, 0, Screen->width * Screen->height);
    terrain.draw (gvpb);

    VngoRect rect;
    rect.x = 0;
    rect.y = 0;
    rect.dx = Screen->width;
    rect.dy = Screen->height;

    VngoTexture txt;
    txt.width = Screen->width;
    txt.height = Screen->height;
    txt.tex = backbits;

    Screen->gvport->image_trans(&rect,&txt);
    Screen->invalidate(rect);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LunarLander - process_events
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LunarLander::process_events()
{
    // No message should be larger than this!
    char    buf[4096];

    // Only network stuff needs to be processed
    if (Net && Net->active ())
    {
        while (Net->receive (buf, sizeof (buf)) != DPERR_NOMESSAGES)
            ;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LunarLander - render
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LunarLander::render()
{
    char    buff[32];

    assertMyth ("LunarLander::render needs Screen instance",
                Screen != 0 && Screen->gvport != 0);

    ++frame;

    // Give other tasks a shot!
    bz_suspend();

    // Check to see if anything interesting happened
    if (aLanders[0]->landed (&terrain))
    {
        LandMode->crashed    = aLanders[0]->too_fast() || aLanders[0]->collided (&terrain);
        LandMode->lander_dx  = int (aLanders[0]->xvelocity);
        LandMode->lander_dy  = int (aLanders[0]->yvelocity);
        LandMode->frame_rate = frame * 1000 / timer.check ();
        switch_to (LandMode);
    }

    // Redraw the lander
    else
    {
        for (int i = 0; i < NUM_LANDERS; i++)
        {
            if (aLanders[i])
            {
                restore (&aLanders[i]->damage);
                aLanders[i]->draw (Screen->gvport);
            }
        }
    }

    // Draw status
    GBergText gt (Screen->gvport);
    gberg_select_font("9x15");

    gt.cury = 0;
    byte bgcolor = (byte)Screen->pal->get_index (VngoColor24bit (0,0,0));
    byte fgcolor = (byte)Screen->pal->get_index (VngoColor24bit (128,128,128));
    for (int i = 0; i < NUM_LANDERS; i++)
    {
        if (aLanders[i])
        {
            gberg_color (aLanders[i]->lander_color, bgcolor);
            wsprintf (buff, "%2d: %5d\n", aLanders[i]->player_id, int (aLanders[i]->xvelocity));
            gt.curx = Screen->width - 9*9;
            gt.out (buff);

            wsprintf (buff, "DY: %5d\n", int (aLanders[i]->yvelocity));
            gt.curx = Screen->width - 9*9;
            gt.out (buff);
        }
        else
        {
            gberg_color (fgcolor, bgcolor);
            gt.curx = Screen->width - 9*9;
            gt.out ("---------\n");

            gt.curx = Screen->width - 9*9;
            gt.out ("---------\n");
        }
    }

    VngoRect    rect;
    rect.x = 0;
    rect.y = 0;
    rect.dx = Screen->width;
    rect.dy = Screen->height;
    Screen->invalidate(rect);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LunarLander - restore
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LunarLander::restore (LPRECT lpr)
{
    VngoRect    rect;

    rect.x = lpr->left;
    rect.y = lpr->top;
    rect.dx = lpr->right - lpr->left + 1;
    rect.dy = lpr->bottom - lpr->top + 1;

    VngoTexture txt;
    txt.width = Screen->width;
    txt.height = short (rect.dy);
    txt.tex = backbits + rect.y * txt.width + rect.x;

    Screen->gvport->image_trans(&rect,&txt);
}



//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//±±±±±±±±±±±±±±±±±±±±±± Lunar Lander Title Mode   ±±±±±±±±±±±±±±±±±±±±±±±±±±
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderTitle - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
LanderTitle::LanderTitle ():
    GameState (), 
    evt (0),
    scene(0),
    vport (0)
{
    assertMyth("LanderTitle needs valid Screen instance",
               Screen != 0);

    vp_rect.x = 0;
    vp_rect.y = 0;
    vp_rect.dx = Screen->width;
    vp_rect.dy = Screen->height;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderTitle - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
LanderTitle::~LanderTitle()
{
    // Clean up our event source
    if (evt != 0)
    {
        evt->uninstall();
        delete evt;
    }

    if (scene)
        delete scene;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderTitle - init
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int LanderTitle::init (const char *cname)
{
    assertMyth ("LanderTitle can only be inited once", evt == 0);

    // Create a new system
    evt = new MaxEventUser (*Devs);

    if (evt == 0 ||
        ((MaxEventUser *)evt)->load (szMasterIFF, cname) != 0)
    {
        return 1;
    }

    // Now, let 'er rip!
    evt->install();

    // Get some initial values for the event system
    events = evt->process ();
    single_events = oneshot.process (events);

    scene = new EschScene;
    if (!scene)
        return 1;

    assertMyth ("LanderTitle init needs valid Screen", Screen != 0);

    if ((scene->load (szMasterIFF, 0, Screen->pal)) != 0
        || scene->cameras == 0
        || scene->meshes == 0
        || scene->lights == 0)
    {
        return 1;
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderTitle - activate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LanderTitle::activate ()
{
    assertMyth("LanderTitle::activate needs valid Screen instance",
               Screen != 0 && Screen->gvport != 0 && Screen->pal != 0);

//ÄÄ Remove cursor
    Screen->cursor_off();

//ÄÄ Create render vport
    assert(vport == 0);
    vport = new VngoVportDB8 (vp_rect.dx, vp_rect.dy,
                              Screen->gvport->vbuff.scrn_ptr + vp_rect.x + (vp_rect.y * Screen->gvport->vbuff.pitch),
                              NULL,
                              Screen->pal, 
                              VNGO_ZBUFFER_DEV,
                              Screen->gvport->vbuff.pitch);
    if (!vport || vport->get_init_state())
    {
        panic(IDS_ERR_CREATEVPORTFAILED,"Lander Title");
        return;
    }

//ÄÄ Setup cameras
    for (EschCamera *cam = scene->cameras; cam != NULL; cam = cam->next ())
    {
        cam->attach (vport);
        cam->set_flags (cam->flags | ESCH_CAM_SHADE_SPECULAR
                                   | ESCH_CAM_SHADE_SMOOTH
                                   | ESCH_CAM_SHADE_FLAT
                                   | ESCH_CAM_SHADE_WIRE
                                   | ESCH_CAM_TEXTURED
                                   | ESCH_CAM_BACKCULL
                                   | ESCH_CAM_MODELSPACE);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderTitle - deactivate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LanderTitle::deactivate ()
{
//ÄÄ Restore cursor
    Screen->cursor_on();

    if (vport)
    {
        delete vport;
        vport=0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderTitle - render
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LanderTitle::render()
{
    assertMyth ("LunarLander::render needs Screen instance",
                Screen != 0 && Screen->gvport != 0);

    GBergText gt (Screen->gvport);

    assertMyth ("LunarLander init must be called before render",
                scene != 0);
    scene->cameras->render (scene->meshes,scene->lights);

    for (EschMeshDraw *msh = scene->meshes;
         msh != 0;
         msh = (EschMeshDraw*)msh->next ())
    {
        msh->yaw (3);
    }

    gberg_select_font ("12x24");
    gt.out ("Lunar Lander\n");

    gberg_select_font ("9x15");
    gt.out ("An example of using the GameFrame with MythOS");

    VngoRect    rect;
    rect.x = 0;
    rect.y = 0;
    rect.dx = Screen->width;
    rect.dy = Screen->height;
    Screen->invalidate(rect);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderTitle - process_events
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LanderTitle::process_events()
{
    if (!evt)
    {
        events = MaxEventList (0);
        return;
    }

    // Otherwise, strobe the devices and get our events (and oneshots)
    events = evt->process ();
    single_events = oneshot.process (events);

    if (single_events.check (QUIT))
    {
        if (MessageBox(hWndClient,
                       "Are you sure you wish to exit?",
                       szAppName,
                       MB_YESNO | MB_ICONQUESTION) == IDYES)
            DestroyWindow (hWndClient);
    }

    if (single_events.check (FIRE))
        switch_to (SimMode);
}



//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//±±±±±±±±±±±±±±±±±±±±±± Lunar Lander Landed Mode ±±±±±±±±±±±±±±±±±±±±±±±±±±±
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderLanded - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
LanderLanded::LanderLanded ():
    GameState (), evt (0), crashed (0)
{
    
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderLanded - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
LanderLanded::~LanderLanded()
{
    // Clean up our event source
    if (evt != 0)
    {
        evt->uninstall();
        delete evt;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderLanded - init
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int LanderLanded::init (const char *cname)
{
    assertMyth ("LanderLanded can only be inited once", evt == 0);

    // Create a new system
    evt = new MaxEventUser (*Devs);

    if (evt == 0 || ((MaxEventUser *)evt)->load (szMasterIFF, cname) != 0)
        return 1;

    // Now, let 'er rip!
    evt->install ();

    // Get some initial values for the event system
    evt->process ();

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderLanded - activate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LanderLanded::activate ()
{
    char buf[64];

    assertMyth ("LanderLanded::render needs Screen instance",
                Screen != 0 && Screen->gvport != 0);

    GBergText gt (Screen->gvport);

    gberg_select_font ("12x24");

    if (crashed)
        wsprintf (buf, "You crashed with dx = %d, dy = %d at %d frames/sec\n",
                  lander_dx, lander_dy, frame_rate);
    else
        wsprintf (buf, "You landed with dx = %d, dy = %d at %d frames/sec\n",
                  lander_dx, lander_dy, frame_rate);

    gt.out (buf);
    gt.out ("Press <SPACE> to play again, or <ESC> to exit");

    VngoRect    rect;
    rect.x = 0;
    rect.y = 0;
    rect.dx = Screen->width;
    rect.dy = Screen->height;
    Screen->invalidate(rect);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderLanded - process_events
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LanderLanded::process_events()
{
    assertMyth ("LanderLanded::process_events needs an event system",
                evt != 0);

    MaxEventList events = evt->process();

    if (events.check (QUIT))
        DestroyWindow (hWndClient);

    if (events.check (FIRE))
        switch_to (SimMode);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderLanded - render
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LanderLanded::render()
{
    // All drawing done in the activate() call.
}

//°±² eof - llander.cpp ²±°
