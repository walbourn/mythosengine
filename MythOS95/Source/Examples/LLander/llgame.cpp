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
//                    Microsoft Windows 95/NT Version
//
//            Copyright (c) 1994-1998 by Charybdis Enterprises, Inc.
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
//                          LUNAR LANDER EXAMPLE
//
// Created by Chuck Walbourn and Dan Higdon
//
// llgame.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "llander.hpp"
#include "llevt.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define LANDER_ISIZE        16
#define LANDER_SIZE         10
#define LANDER_XOFFSET      3

#define TERRIAN_SEGMENTS    64

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
    float   xpos;
    float   ypos;
    float   xvelocity;
    float   yvelocity;
    float   xacceleration;
    float   yacceleration;
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
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

TurnerNetwork   *Net    = 0;

// {1E6E9FA3-1200-11cf-887E-00400516ED44}
const GUID LANDER_GUID =
{ 0x1e6e9fa3, 0x1200, 0x11cf, { 0x88, 0x7e, 0x0, 0x40, 0x5, 0x16, 0xed, 0x44 } };


//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°± Lander Network  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

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
            ((LanderPositionData *)msg)->stuff_into (theSim.game->get_lander (from));
            break;

        case LanderPositionData::TERRAIN_DATA:
            // Set the terrain data.
            memcpy (theSim.game->terrain.aHeights, &pkt->data, theSim.game->terrain.cHeights);
            theSim.game->draw_terrain ();
            break;
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderNetwork - sys_newplayer
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int LanderNetwork::sys_newplayer (DPID id, LPCSTR short_name, LPCSTR long_name)
{
    Lander *lander = theSim.game->init_lander (id);

    if (lander == 0)
        return 1;

    if (is_creator ())
    {
        // Inform the other player of the terrain they will be flying over
        int buf_len = sizeof (*theSim.game->terrain.aHeights) * theSim.game->terrain.cHeights
                    + sizeof (PacketData::data_types);
        void *buf = new char [buf_len];
        if (!buf)
            return 1;

        ((GenericData *)buf)->type = LanderPositionData::TERRAIN_DATA;
        memcpy (&((GenericData *)buf)->data,
                theSim.game->terrain.aHeights,
                theSim.game->terrain.cHeights);
        send (theSim.game->aLanders[0]->player_id, id, buf, buf_len);
        delete [] buf;
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderNetwork - sys_delplayer
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int LanderNetwork::sys_delplayer (DPID id)
{
    theSim.game->kill_lander (id);

    return 0;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°± Lander Vehicle Class  ±°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

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
void Lander::step ()
{
    if (!remote)
    {
        process_events ();
        update_model ();

        // If we're on the network, let everyone know our new position
        if (Net && Net->is_active())
        {
            LanderPositionData pd (*this);
            Net->broadcast (player_id, &pd, sizeof (pd));
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Lander - reset
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void Lander::reset (float x, float y)
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
        if (Devs->is_joystick_enabled())
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
        if (Devs->is_joystick_enabled())
            evt->get_joystick (&j);

        if (evts.check (UP))
            yacceleration = -25;
        else if (evts.check (DOWN))
            yacceleration = -40;
        else if (Devs->is_joystick_enabled()
                 && j.dwYpos < jcentery - 2048)
            yacceleration = float (long (j.dwYpos - jcenterx) / 512);
        else
            yacceleration = 0;

        if (evts.check (LEFT))
            xacceleration = -10;
        else if (evts.check (RIGHT))
            xacceleration = 10;
        else if (Devs->is_joystick_enabled()
                 && abs (j.dwXpos - jcenterx) > 4096)
            xacceleration = float (long (j.dwXpos - jcenterx) / 2048);
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
    float   elapsed (float(now - last_update));

    if (elapsed > 0)
    {
        last_update = now;

        // Make this a fraction of a second
        elapsed /= float (1000);

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
            xpos = float (Screen->width - LANDER_ISIZE);
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

    if (iff.open (szIFF, XF_OPEN_READ))
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

    VngoTexture mtex (VNGO_TEXTURE_MONO);
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



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Terrain Class  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

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
            Mode->panic("Terrain out of memory");
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



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°±  Lunar Lander Game State  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Constructor - LanderGame
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
LanderGame::LanderGame() :
    evt (0),
    terrain (TERRIAN_SEGMENTS),
    vport(0)
{
    for (int i = 0; i < NUM_LANDERS; i++)
        aLanders[i] = 0;
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// Destructor - LanderGame
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
LanderGame::~LanderGame()
{
    deactivate();
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderGame - activate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LanderGame::activate()
{
//ÄÄÄ Load palette and set color
    if (!Screen->load_palette(szIFF, 0))
        panic("LanderGame::activate failed to load palette");

    gberg_color(Screen->find(VngoColor24bit(255,255,0)), VNGO_TRANSPARENT);

//ÄÄÄ Create event system
    evt = new MaxEventUser (*Devs);

    if (!evt
        || evt->load (szIFF,0) != 0)
        panic("LanderGame::activate fail for event");

    evt->install();

//ÄÄÄ Create network if needed
    {
        XFParseINI ini;
        char buff[256];

        ini.open(szINI, XF_OPEN_READ | XF_OPEN_DENYWRITE);

        //ÄÄÄ Screen parameters
        if (!ini.section("Lander"))
        {
            if (!ini.read("Multiplayer",buff))
            {
                strlwr(buff);
                if (strstr(buff,"yes") || strstr(buff,"on"))
                {
                    Net = new LanderNetwork (NUM_LANDERS);

                    if (!Net)
                        panic("LanderGame::activiate network create failed");

                    // Connect to the network, where appropriate
                    TurnerNetworkUI net_ui (theSim.hWndClient, Net);

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
                        delete Net;
                        Net = 0;
                    }
                }
            }
        }
    }

//ÄÄÄ Create viewport
    assert(vport == 0);
    if (Screen->bit_depth == 8)
    {
        vport = new VngoVVport8(VngoRect(0,0,Screen->width,Screen->height),
                                Screen->pal, 0);
    }
    else
    {
        vport = new VngoVVport16(VngoRect(0,0,Screen->width,Screen->height),
                                 Screen->pal, 0);
    }
    if (!vport)
        panic("LanderGame::activiate failed viewport create");

//ÄÄÄ Create the first lander (the player's lander)
    aLanders[0] = new Lander (evt, FALSE);
    if (!aLanders[0]
        || !aLanders[0]->load_images ())
        panic("LanderGame::activiate failed to create lander");

//ÄÄÄ Initialize the terrain image
    draw_terrain ();

//ÄÄÄ Reset the landers
    for (int i = 0; i < NUM_LANDERS; i++)
        if (aLanders[i])
            aLanders[i]->reset();

//ÄÄÄ Initialize the time and frame count
    timer.clear();
    frame = 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderGame - deactivate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LanderGame::deactivate()
{
    if (evt)
    {
        delete evt;
        evt = 0;
    }
    if (vport)
    {
        delete vport;
        vport = 0;
    }

    for (int i = 0; i < NUM_LANDERS; i++)
    {
        if (aLanders[i])
        {
            delete aLanders[i];
            aLanders[i] = 0;
        }
    }

    if (Net)
    {
        Net->close();
        delete Net;
        Net = 0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderGame - process_events
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LanderGame::process_events()
{
    // No message should be larger than this!
    char    buf[4096];

    // Only network stuff needs to be processed
    if (Net && Net->is_active ())
    {
        while (Net->receive (buf, sizeof (buf)) != DPERR_NOMESSAGES)
            ;
    }

    MaxEventList events = evt->process();

    if (events.check (QUIT))
        theSim.exit();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderGame - render
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LanderGame::render()
{
    int waslocked=Screen->lock();

    char    buff[32];

    assertMyth ("LunarLander::render needs Screen instance",
                Screen != 0 && Screen->gvport != 0);

    ++frame;

    // Step all the landers
    for (int i = 0; i < NUM_LANDERS; i++)
    {
        if (aLanders[i])
            aLanders[i]->step();
    }

    // Check to see if anything interesting happened
    if (aLanders[0]->landed (&terrain))
    {
        theSim.end->crashed    = aLanders[0]->too_fast() || aLanders[0]->collided (&terrain);
        theSim.end->lander_dx  = int (aLanders[0]->xvelocity);
        theSim.end->lander_dy  = int (aLanders[0]->yvelocity);
        theSim.end->frame_rate = frame * 1000 / timer.check ();
        switch_to (theSim.end);
        return;
    }

    // Redraw the lander
    else
    {
        for (i = 0; i < NUM_LANDERS; i++)
        {
            if (aLanders[i])
            {
                restore (&aLanders[i]->damage);
                aLanders[i]->draw (Screen->gvport);
            }
        }
    }

    // Draw status
    SimText st (Screen->gvport);
    gberg_select_font("9x15");

    st.cury = 0;
    byte bgcolor = (byte)Screen->pal->get_index (VngoColor24bit (0,0,0));
    byte fgcolor = (byte)Screen->pal->get_index (VngoColor24bit (128,128,128));
    for (i = 0; i < NUM_LANDERS; i++)
    {
        if (aLanders[i])
        {
            gberg_color (aLanders[i]->lander_color, bgcolor);
            wsprintf (buff, "%2d: %5d\n", aLanders[i]->player_id, int (aLanders[i]->xvelocity));
            st.curx = Screen->width - 9*9;
            st.out (buff);

            wsprintf (buff, "DY: %5d\n", int (aLanders[i]->yvelocity));
            st.curx = Screen->width - 9*9;
            st.out (buff);
        }
        else
        {
            gberg_color (fgcolor, bgcolor);
            st.curx = Screen->width - 9*9;
            st.out ("---------\n");

            st.curx = Screen->width - 9*9;
            st.out ("---------\n");
        }
    }

    Screen->invalidate();

    if (!waslocked)
        Screen->unlock();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderGame - get_lander
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
Lander *LanderGame::get_lander (DPID player)
{
    for (int i = 0; i < NUM_LANDERS; i++)
    {
        if (aLanders[i] && aLanders[i]->player_id == player)
            return aLanders[i];
    }

    return 0;
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderGame - init_lander
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
Lander *LanderGame::init_lander (DPID player)
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

    Lander *l = 0;

    for (int i = 0; i < NUM_LANDERS; i++)
    {
        if (aLanders[i] == 0)
        {
            l = new Lander (NULL, TRUE, colors[i]);

            if (l != 0)
            {
                l->player_id = player;
                l->reset ();
                if (!l->load_images ())
                {
                    delete l;
                    l = 0;
                }
                else
                    aLanders[i] = l;
            }

            break;
        }
    }

    return l;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderGame - get_lander
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LanderGame::kill_lander (DPID player)
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
//  LanderGame - draw_terain
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LanderGame::draw_terrain ()
{
    assertMyth("LanderGame::draw_terrain needs vport", vport != 0);

    vport->reset();
    terrain.draw (vport);

    VngoRect rect(0,0,
                  Screen->width,Screen->height);

    dword tflags;
    switch (Screen->bit_depth)
    {
        case 15:
            tflags = VNGO_TEXTURE_15BIT;
            break;
        case 16:
            tflags = VNGO_TEXTURE_16BIT;
            break;
        default:
            tflags = VNGO_TEXTURE_8BIT;
            break;
    }

    VngoTexture txt(Screen->width, Screen->height,
                    vport->vbuff.scrn_ptr, tflags);

    Screen->gvport->image_trans(&rect,&txt);
    Screen->invalidate();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// LanderGame - restore
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void LanderGame::restore (LPRECT lpr)
{
    VngoRect    rect(lpr->left, lpr->top,
                     lpr->right - lpr->left + 1,
                     lpr->bottom - lpr->top + 1);

    dword tflags;
    int t;
    switch (Screen->bit_depth)
    {
        case 15:
            tflags = VNGO_TEXTURE_15BIT;
            t = 2;
            break;
        case 16:
            tflags = VNGO_TEXTURE_16BIT;
            t = 2;
            break;
        default:
            tflags = VNGO_TEXTURE_8BIT;
            t = 1;
            break;
    }

    assertMyth("LanderGame::restore needs vport", vport != 0);
    VngoTexture txt(Screen->width, short (rect.dy),
                    (byte*)vport->vbuff.scrn_ptr
                    + (rect.y * (Screen->width * t)) + (rect.x * t),
                    tflags);

    Screen->gvport->image_trans(&rect,&txt);
    Screen->invalidate(rect);
}

//°±² eof - llgame.cpp ²±°
