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
//ùùùùùùùùùùùùùùùùù Microsoft Windows 95/98/NT Version ùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùCopyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbournùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
// Created by Tim Little & Chuck Walbourn
//
// estxfire.cpp
//
// EschFireTexture is an animated procedural texture for flame.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define PI                  3.14157f
#define RADIAN_2_DEGREES    57.29577f
#define SMOOTH              1
#define FIRE_INCREASE       3
#define MAX_COLOR           110
#define MIN_FIRE            50
#define ROOT_RAND           20

#define RAND_TABLE_SIZE     43

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

static byte  rand_table[RAND_TABLE_SIZE];
static int   table_loc = 0;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°± Non-Class related services ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFireTexture - Random                                                 ³
//                                                                          ³
// Go through the random number table and then clip it to the range.        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
inline int Random(int range)
{
    if (table_loc < RAND_TABLE_SIZE-1)
    {
        table_loc++;
    }
    else
    {
        table_loc=0;
    }
    return ((unsigned int)rand_table[table_loc] % range);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFireTexture - Rand                                                   ³
//                                                                          ³
// Get a random clipped to a positive-negative range.                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
inline int Rand(int range)
{
    return (Random((range << 1) + 1) - range);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFireTexture - Constructor                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschFireTexture::EschFireTexture() :
    EschProceduralTexture(),
    flame_bytes(0),
    flames(0),
    write_lut(0)
{
    ttyp = ESCH_TXTT_PRCFIRE;
}

EschFireTexture::EschFireTexture(ushort w, ushort h, VngoPal *pal, int dogen) :
    EschProceduralTexture(),
    flame_bytes(0),
    flames(0),
    write_lut(0)
{
    ttyp = ESCH_TXTT_PRCFIRE;

    init(w,h,pal,dogen);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFireTexture - Destructor                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschFireTexture::~EschFireTexture()
{
    release();
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°±  Public Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFireTexture - release                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFireTexture::release()
{
    if (write_lut)
    {
        delete write_lut;
        write_lut=0;
    }

    if (flames)
    {
        delete flames;
        flames=0;
    }

    if (flame_bytes)
    {
        delete flame_bytes;
        flame_bytes=0;
    }

    EschProceduralTexture::release();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFireTexture - init                                                   ³
//                                                                          ³
// Sets up the buffers and performs other initialization for use.           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschFireTexture::init(ushort w, ushort h,
                                       VngoPal *pal, int dogen)
{
//ÄÄÄ Perform base initialization
    esch_error_codes err=EschProceduralTexture::init(w,h,pal,0);
    if (err)
        return err;

//ÄÄÄ Setup random table
    for (int i=0; i < RAND_TABLE_SIZE; i++)
    {
        rand_table[i] = (byte)flx_abs(flx_rand()).flx;
    }

//ÄÄÄ Compute shift
    txt.flags |= VNGO_TEXTURE_TRANSPARENT;
    switch (txt.width)
    {
        case 16:
            u_shift = 4;
            break;
        case 32:
            u_shift = 5;
            break;
        case 64:
            u_shift = 6;
            break;
        case 128:
            u_shift = 7;
            break;
        case 256:
            u_shift = 8;
            break;
        default:
            return ESCH_ERR_INVALIDSIZE;
    }

    switch (txt.height)
    {
        case 16:
            decay = 20;
            break;
        case 32:
            decay = 15;
            break;
        case 64:
            decay = 12;
            break;
        case 128:
            decay = 8;
            break;
        case 256:
            decay = 5;
            break;
        default:
            return ESCH_ERR_INVALIDSIZE;
    }

//ÄÄÄ  Finish init
    fb_control=0;

    for (int i=0; i < (txt.height << u_shift); i++)
    {
        ((byte*)txt.tex)[i] = 255;
    }

    memset(txt.tex,255,txt.height << u_shift);

    more_fire = 2;

    err=setup_local_tables();
    if (err)
        return err;

    make_lut(pal);

    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFireTexture - generate                                               ³
//                                                                          ³
// Generates the next frame.                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFireTexture::generate()
{
    // Call the base up front!
    EschProceduralTexture::generate();

    // Dump the bases for the flame on the screen.

    for (int i = 0; i < txt.width; i++)
    {
        put (i,txt.height-1,flame_bytes[i]);
    }

    // Now do the Magick!
    for (int x=0; x < txt.width; x++)
    {
        for (int y = 1; y < txt.height; y++)
        {
            int V = get(x,y);
            if ((V < decay) ||
                (x == 0) ||
                (x == txt.width-1))
            {
                put(x,y-1,0);
            }
            else
            {
                put(x - Rand(1),y-1,V-Random(decay));
            }
        }
    }

    if (Random(150) == 0)
    {
        int t = Random( txt.width - 10) + 5;

        flame_bytes[t-2] = 255;
        flame_bytes[t-1] = 255;
        flame_bytes[t]   = 255;
        flame_bytes[t+1] = 255;
        flame_bytes[t+2] = 255;
    }

    for (int i = 0; i < txt.width; i++)
    {
        int x = flame_bytes[i];
        if (x < MIN_FIRE)
        {
            if ( x > 10 )
                x += Random(FIRE_INCREASE);
        }
        else
        {
            x += Rand(ROOT_RAND) + more_fire;
        }

        if ( x > 255)
            x = 255;
        else if ( x < 0)
            x = 0;

        flame_bytes[i] = x;
    }

    // Pour a little water on the edges to make it look good.
    for (int i = 0;i < (txt.width >> 3);i++)
    {
        flame_bytes[0] = 0;
        flame_bytes[txt.width - 1] = 0;
    }

    if (fb_control)
        fireball(0);

    smooth_baseline();

    // Always reset the more_fire member!
    if (more_fire > 2)
        more_fire--;
    else if (more_fire <= 0)
        more_fire++;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFireTexture - ignite                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFireTexture::ignite()
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFireTexture - douse                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFireTexture::douse(int do_smooth)
{
    // Dump some nice cold water on it!
    for (int i=0;i < (txt.width >> 3); i++)
    {
        flame_bytes [Random(txt.width-1)] = 0;
    }

    if (do_smooth)
    {
        smooth_baseline();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschFireTexture - fireball                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFireTexture::fireball(int start_fireball)
{
    // if there is already a fireball going, don't start
    // a new one yet!
    if (!fb_control && start_fireball)
    {
        for (int i = 0; i < txt.width; i++)
        {
            int x = flame_bytes[i];
            if (x < MIN_FIRE)
            {
                if (x > 10)
                    x += Random(FIRE_INCREASE);
            }
            else
            {
                x += Random(ROOT_RAND * 2);
            }

            if (x > 255)
                x = 255;
            else if (x < 0)
                x = 0;

            flame_bytes[i] = x;
        }

        fb_control = 30;
    }
    else if (!start_fireball)
    {
        fb_control--;
    }

}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°±  Private Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                           °°° Private °°°                                ³
// EschFireTexture - smooth_baseline                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFireTexture::smooth_baseline()
{
    // Now round it back out!
    for (int i = SMOOTH;i <= txt.width-SMOOTH;i++)
    {
        int x = 0;
        for (int j=-SMOOTH; j <= SMOOTH; j++)
        {
            x += flame_bytes[i+j];
        }
        flame_bytes[i] = x / ((SMOOTH << 1) + 1);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                           °°° Private °°°                                ³
// EschFireTexture - setup_local_tables                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschFireTexture::setup_local_tables()
{
    write_lut = new byte [256];
    if (!write_lut)
        return (ESCH_ERR_NOMEMORY);

    flames = new byte[txt.height << u_shift];
    if (!flames)
        return (ESCH_ERR_NOMEMORY);
    memset(flames, 0, sizeof(byte)*(txt.height << u_shift));

    flame_bytes = new byte [txt.width];

    if (!flame_bytes)
        return (ESCH_ERR_NOMEMORY);

    for (int i=0;i < txt.width;i++)
        flame_bytes[i] = 0;

    // Spark the initial flame!   Always put it in the middle.
    {
        int t = txt.width >> 3;
        int i = (txt.width >> 1) - (t >> 1);
        for (int j = 0; j < t; j++)
        {
            flame_bytes[i+j] = 255;
        }

        for (int i = 0; i < txt.width; i++)
        {
            int x = flame_bytes[i];
            if (x < MIN_FIRE)
            {
                if ( x > 10 )
                    x += Random(FIRE_INCREASE);
            }
            else
            {
                x += Rand(ROOT_RAND) + more_fire;
            }

            if ( x > 255)
                x = 255;
            else if (x < 0)
                x = 0;

            flame_bytes[i] = x;
        }

        for (int i = SMOOTH;i < txt.width-SMOOTH;i++)
        {
            int x = 0;
            for (int j=-SMOOTH; j <= SMOOTH; j++)
            {
                x += flame_bytes[i+j];
            }
            flame_bytes[i] = x / ((SMOOTH << 1) + 1);
        }
    }

    return (ESCH_ERR_NONE);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                           °°° Private °°°                                ³
// EschFireTexture - make_lut                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschFireTexture::make_lut(VngoPal *vpal)
{
    VngoColor24bit  pal[256];

    for (int i = 0; i < 256; i++)
    {
        pal[i].r = 0;
        pal[i].g = 0;
        pal[i].b = 0;
    }
    int i=0;
    for (i = 0; i < MAX_COLOR; i++)
    {
        pal[i] = to_RGB( 4.6f - 1.5f*float(i) / float(MAX_COLOR),
                         float(i)/float(MAX_COLOR),
                         float(i)/float(MAX_COLOR) );
    }

    // Ramp up to maximum Red, almost maximum Green, and maximum Blue.
    for (; i < 256; i++)
    {
        pal[i] = pal[i-1];

        if (pal[i].r < 63)
            pal[i].r++;

        if (pal[i].r < 63)
            pal[i].r++;

        if ((i % 2 == 0) && ( pal[i].g < 53 ))
            pal[i].g++;

        if ((i % 2 == 0) && ( pal[i].b < 63 ))
            pal[i].b++;
    }

    for (i = 0; i < 256; i++)
    {
        pal[i].r = pal[i].r << 2;
        pal[i].g = pal[i].g << 2;
        pal[i].b = pal[i].b << 2;
        write_lut[i] = (byte)vpal->get_index(pal[i]);
    }

    for (i=0; i < 16;i++)
    {
        write_lut[i] = 255;         // if it is real dim, make it transparent!
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                           °°° Private °°°                                ³
// EschFireTexture - to_RGB                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
VngoColor24bit EschFireTexture::to_RGB(float h, float s, float i)
{
   float Rv = 1.0f + s * esch_sin ((h - 2.0f * PI / 3.0f) * RADIAN_2_DEGREES);
   float Gv = 1.0f + s * esch_sin (h * RADIAN_2_DEGREES);
   float Bv = 1.0f + s * esch_sin ((h + 2.0f * PI / 3.0f) * RADIAN_2_DEGREES);

   float t = 63.999f * i / 2.0f;
   return VngoColor24bit ( (byte)(int)(Rv * t),
                           (byte)(int)(Gv * t),
                           (byte)(int)(Bv * t) );
}

//°±² End of module - estxfire.cpp ²±°

