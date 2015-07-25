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
// Created by Tim Little & Chuck Walbourn
//
// escamex.cpp
//
// The EschCameraEx class is an extended camera which handles
// bitmap backgrounds and hazing.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - Constructor                                               ³
//                                                                          ³
// Initializes the camera object                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschCameraEx::EschCameraEx(VngoVport *vp) :
    EschCamera(vp),
    bg_bitmap(0),
    hz_pal(0),
    grd_pal(0)
{
};

EschCameraEx::EschCameraEx(const char *fname, const char *cname) :
    EschCamera(fname,cname),
    bg_bitmap(0),
    hz_pal(0),
    grd_pal(0)
{
};

EschCameraEx::EschCameraEx(const EschCamera &cam) :
    EschCamera(cam),
    bg_bitmap(0),
    hz_pal(0),
    grd_pal(0)
{
};

EschCameraEx::EschCameraEx(const EschCameraEx &cam) :
    EschCamera(cam),
    bg_bitmap(cam.bg_bitmap),
    hz_pal(cam.hz_pal),
    grd_pal(cam.grd_pal)
{
    flags &= ~(ESCH_CAM_OWNSBITMAP
               | ESCH_CAM_OWNSHAZE
               | ESCH_CAM_OWNSGRADIENT);
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - Destructor                                                ³
//                                                                          ³
// Releases any associated data for the camera object.                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschCameraEx::~EschCameraEx()
{
    release();
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - operator =                                                ³
//                                                                          ³
// Copies the data from another camera.                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
const EschCameraEx &EschCameraEx::operator = (const EschCamera &cam)
{
    if (this != &cam)
    {
        release();

        EschCamera::operator = (cam);
    }
    return *this;
}

const EschCameraEx &EschCameraEx::operator = (const EschCameraEx &cam)
{
    if (this != &cam)
    {
        release();

        EschCamera::operator = (cam);

        bg_bitmap = cam.bg_bitmap;
        hz_pal = cam.hz_pal;
        grd_pal = cam.grd_pal;
        flags &= ~(ESCH_CAM_OWNSBITMAP
                   | ESCH_CAM_OWNSHAZE
                   | ESCH_CAM_OWNSGRADIENT);
    }
    return *this;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - release                                                   ³
//                                                                          ³
// Release any data owned by the camera.                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCameraEx::release()
{
//ÄÄÄ Release bitmap background
    if ((flags & ESCH_CAM_OWNSBITMAP) && bg_bitmap)
    {
        bg_bitmap->release();
        delete bg_bitmap;
    }
    bg_bitmap=0;

//ÄÄÄ Release haze palette
    if ((flags & ESCH_CAM_OWNSHAZE) && hz_pal)
    {
        delete hz_pal;
    }
    hz_pal=0;

//ÄÄÄ Release gradient palette
    if ((flags & ESCH_CAM_OWNSGRADIENT) && grd_pal)
    {
        delete grd_pal;
    }
    grd_pal=0;

//ÄÄÄ Clear any owns bits
    flags &= ~(ESCH_CAM_OWNSBITMAP
               | ESCH_CAM_OWNSHAZE
               | ESCH_CAM_OWNSGRADIENT);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - pre_rend                                                  ³
//                                                                          ³
// Prepares a render, returning a 0 on success or non-zero otherwise.       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschCameraEx::pre_rend()
{
    flags &= ~ESCH_CAM_VPWASLOCKED;

    if (!vport)
        return 1;

//ÄÄÄ Lock viewport (save old state)
    int waslocked = vport->lock();

        if (waslocked == -1)
                return 1;

    if (waslocked)
        flags |= ESCH_CAM_VPWASLOCKED;

//ÄÄÄ Clear viewport/reset z-buffer
    if (!(flags & ESCH_CAM_NOCLEAR))
    {
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Bitmap Background
        if ( (!(flags & ESCH_CAM_IGNORE_BMAP)) && bg_bitmap)
        {
            VngoRect rect(-bg_offx,
                          -bg_offy,
                          bg_bitmap->width,
                          bg_bitmap->height);

            bg_bitmap->lock();
            assert(bg_bitmap->data != 0 && bg_bitmap->bpp == 1);

            VngoTexture txt((short)rect.dx,
                            (short)rect.dy,
                            bg_bitmap->data,
                            VNGO_TEXTURE_8BIT);

            //ÄÄÄ Don't clear screen if the image covers entire viewport
            if (bg_offx < 0
                || bg_offy < 0
                || (rect.dx-bg_offx) < vport->vbuff.width
                || (rect.dy-bg_offy) < vport->vbuff.height)
                vport->clear_screen_on();
            else
                vport->clear_screen_off();

            vport->reset(bcolor);

            vport->image_trans(&rect,&txt);

            bg_bitmap->unlock();
        }
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Gradient Background
        else if ((flags & ESCH_CAM_GRADIENT) && grd_pal)
        {
            //ÄÄÄ Just clear Z-buffer
            vport->clear_screen_off();
            vport->reset();
#if 0
#if 0
            float pitch_sin = eye.dir.j;

            float pitch = esch_asin(pitch_sin);

            if (top.j.flx < 0)
            {
                pitch = pitch-180.0f;
            }

            float c_pitch = esch_cos(pitch);

            float roll_sin = top.i;


            float c_roll = 1.0f;

            float c_tilt = c_roll;
            float c = c_pitch;

#else
            //ÄÄÄ Compute view angle
            float ti = top.i;
            float tj = top.j;
            float tk = top.k;

            float c = tj / esch_sqrt(ti*ti + tj*tj);
            if (c > float(1))
                c = float(1);
            if (c < float(-1))
                c = float(-1);

            float c_tilt = tk / esch_sqrt(tj*tj + tk*tk);
            if (c_tilt > float(1))
                c_tilt = float(1);
            if (c_tilt < float(-1))
                c_tilt = float(-1);
#endif
#else
            EschVector rv1;
            EschVector rv2 = top;
            rv1.i = 1.0f;
            rv1.j = 0;
            rv1.k = 0;
            rv1.transform(&eye.orient);

            float roll = esch_asin(rv2.i);

            if (rv2.j < 0)
            {
                if (rv2.i < 0)
                {
                    roll = (-180.0f - roll);
                }
                else
                {
                    roll = (180.0f - roll);
                }
            }
            float c_roll = esch_cos(roll);
            float s_roll = esch_sin(roll);


            EschVector pv1 = top;
            EschVector pv2 = eye.dir;

            float pitch = esch_asin(pv2.j);

            if (pv1.j < 0)
                pitch = 180.0f-pitch;

            if (pitch > 180.0f)
            {
                pitch = -(180.0f - (pitch - 180.0f));
            }

            float c_pitch = esch_cos(pitch);
            float s_pitch = esch_sin(pitch);

#endif
            //ÄÄÄ Compute shades for gradient polygon
#if 1
            long sh_top = 0;
            long sh_bottom = 255;

            if (pitch < 0)
            {
                sh_top = long(255.0f * (-s_pitch));
            }
            else
            {
                sh_bottom = long(255.0f * (1.0f - s_pitch));
            }
/*
            long sh_top = (pitch < 0)
                          ? long(float(255)*(float(1)-c_pitch)) : 0;

            long sh_bottom = (pitch > 0)
                             ? long(float(255)*c_pitch)
                             : 255;
*/
#else
            long sh_top = 0;
            long sh_bottom = 255;


#endif

            if (sh_top > 250)
                sh_top = 250;
            if (sh_bottom > 250)
                sh_bottom = 250;

            VngoPoint vpt[4];
            vpt[0].x = 0;
            vpt[0].y = 0;
            vpt[0].z = 0xfffeffff;
            vpt[0].clr = bcolor;
            if (top.i >= 0)
            {
                vpt[0].shade = (c_roll > 0)
                               ? sh_top
                               : (long(float(sh_bottom-sh_top)*(-c_roll))
                                  + sh_top);
            }
            else
            {
                vpt[0].shade = (c_roll < 0)
                               ? sh_bottom
                               : (long(float(sh_bottom-sh_top)*(float(1)-c_roll))
                                  + sh_top);
            }

            vpt[1].x = vport->vbuff.width - 1;
            vpt[1].y = 0;
            vpt[1].z = 0xfffeffff;
            vpt[1].clr = bcolor;
            if (top.i >= 0)
            {
                vpt[1].shade = (c_roll > 0)
                               ? (long(float(sh_bottom-sh_top)*(float(1)-c_roll))
                                  + sh_top)
                               : sh_bottom;
            }
            else
            {
                vpt[1].shade = (c_roll < 0)
                               ? (long(float(sh_bottom-sh_top)*(-c_roll))
                                  + sh_top)
                               : sh_top;
            }

            vpt[2].x = vport->vbuff.width - 1;
            vpt[2].y = vport->vbuff.height - 1;
            vpt[2].z = 0xfffeffff;
            vpt[2].clr = bcolor;
            if (top.i >= 0)
            {
                vpt[2].shade = (c_roll > 0)
                               ? sh_bottom
                               : (long(float(sh_bottom-sh_top)*(float(1)+c_roll))
                                  + sh_top);
            }
            else
            {
                vpt[2].shade = (c_roll < 0)
                               ? sh_top
                               : (long(float(sh_bottom-sh_top)*c_roll)
                                  + sh_top);
            }

            vpt[3].x = 0;
            vpt[3].y = vport->vbuff.height - 1;
            vpt[3].z = 0xfffeffff;
            vpt[3].clr = bcolor;
            if (top.i >= 0)
            {
                vpt[3].shade = (c_roll > 0)
                               ? (long(float(sh_bottom-sh_top)*c_roll)
                                  + sh_top)
                               : sh_top;
            }
            else
            {
                vpt[3].shade = (c_roll < 0)
                               ? (long(float(sh_bottom-sh_top)*(float(1)+c_roll))
                                  + sh_top)
                               : sh_bottom;
            }

            //ÄÄÄ Draw gradient polygon
            assertMyth("EschCameraEx::pre_rend() needs palette in current context's vport",
                       vport->vbuff.pal != 0);

            VngoShadePal *orig = vport->vbuff.pal->shd_pal;
            vport->vbuff.pal->shd_pal = grd_pal;
#if 0
            dword tval = vpt[0].shade;
            vpt[0].clr = (tval << 16) | (tval << 8) | 250 | VNGO_COLOR_24BIT;
            tval = vpt[1].shade;
            vpt[1].clr = (tval << 16) | (tval << 8) | 250 | VNGO_COLOR_24BIT;
            tval = vpt[2].shade;
            vpt[2].clr = (tval << 16) | (tval << 8) | 250 | VNGO_COLOR_24BIT;
            tval = vpt[3].shade;
            vpt[3].clr = (tval << 16) | (tval << 8) | 250 | VNGO_COLOR_24BIT;

            if (vport->get_zmap())
            {
                vport->grpoly(4, vpt);
            }
            else
            {
                vport->zbuffer_off();
                vport->grpoly(4, vpt);
                vport->zbuffer_on();
            }
#else
            if (vport->get_zmap())
            {
                vport->gpoly(4, vpt);
            }
            else
            {
                vport->zbuffer_off();
                vport->gpoly(4, vpt);
                vport->zbuffer_on();
            }
#endif
            vport->vbuff.pal->shd_pal = orig;
        }
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Solid Color Background
        else
        {
            vport->clear_screen_on();
            vport->reset(bcolor);
        }
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - post_rend                                                 ³
//                                                                          ³
// Performs post render processing.                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCameraEx::post_rend()
{
//ÄÄÄ Handle hazing postprocessing
    if ((flags & ESCH_CAM_HAZE) && hz_pal)
    {
        assertMyth("EschCameraEx::post_rend needs screen and zbuffer pointers to haze",
                   vport->get_vbuff()->zbuff_ptr && vport->get_vbuff()->scrn_ptr);

        long h = vport->get_vbuff()->height;
        long w = vport->get_vbuff()->width;

        assert(hz_pal->num_shd_lvl_bits <= 16);
        int lvl_bits = 16 - hz_pal->num_shd_lvl_bits;

        for(long y=0; y < h; y++)
        {
            byte *cptr = vport->get_vbuff()->scrn_ptr
                         + vport->get_vbuff()->ytable[y];

            // 16-bit Zbuffer
            ushort *zptr = (ushort*)((byte*)vport->get_vbuff()->zbuff_ptr
                                     + vport->get_vbuff()->ztable[y]);

            for(long x=0; x < w; x++, cptr++)
            {
                // 16-bit Zbuffer
                ushort r = *(zptr++);

                if (r >= hz_startz && r < 0xfffe)
                {
                    *cptr = (*((VngoShadePal8*)hz_pal))[*cptr].shl[r >> lvl_bits];
                }
            }
        }
    }

//ÄÄÄ Unlock (if old state was unlocked)
    if (!(flags & ESCH_CAM_VPWASLOCKED))
        vport->unlock();

    flags &= ~ESCH_CAM_VPWASLOCKED;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - set_bg_bitmap                                             ³
//                                                                          ³
// Sets up the bitmap background, freeing the old one if owned by the camera³
// returning 0 on success, or 1 if setting the bitmap failed.               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschCameraEx::set_bg_bitmap(XFBitmap *bm, int owns)
{
//ÄÄÄ Free old bitmap, if owned by Camera
    if ((flags & ESCH_CAM_OWNSBITMAP) && bg_bitmap)
    {
        bg_bitmap->release();
        delete bg_bitmap;
    }
    bg_bitmap=0;

//ÄÄÄ Clear flag & reset offset.
    flags &= ~ESCH_CAM_OWNSBITMAP;

    bg_offx=bg_offy=0;

//ÄÄÄ Test for valid bitmap
    if (!bm || !bm->handle || (bm->bpp != 1))
        return 1;

//ÄÄÄ Setup bitmap, if valid.
    bg_bitmap = bm;
    if (owns)
        flags |= ESCH_CAM_OWNSBITMAP;

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - set_haze                                                  ³
//                                                                          ³
// Sets up the haze palette, freeing the old one if owned by the camera,    ³
// returning 0 on success, or 1 if setting the palette failed.              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschCameraEx::set_haze(VngoShadePal *hzp, int owns, long startz)
{
//ÄÄÄ Free old haze palette, if owned by Camera
    if ((flags & ESCH_CAM_OWNSHAZE) && hz_pal)
    {
        delete hz_pal;
    }
    hz_pal=0;

    flags &= ~(ESCH_CAM_OWNSHAZE|ESCH_CAM_HAZE);

//ÄÄÄ Test for valid palette
    if (!hzp)
        return 1;

//ÄÄÄ Setup palette, if valid
    hz_pal = hzp;
    if (owns)
        flags |= ESCH_CAM_OWNSHAZE;

    flags |= ESCH_CAM_HAZE;

    hz_startz = startz;

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - create_haze                                               ³
//                                                                          ³
// Generates a new hazing shade palette given shade levels, number of       ³
// 'pristine' levels, break-point level, break-point percentage, and        ³
// target color.                                                            ³
//                                                                          ³
// Note: This ramps in RGB space which gives better results that ramping in ³
//       HLS space, which results in 'strange' changes in hues.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschCameraEx::create_haze(ushort levels, ushort slevel,
                                           ushort blevel, float bpercent,
                                           VngoColor24bit tcolor)
{
//ÄÄÄ Verify input
    if (!vport || !vport->vbuff.pal)
        return ESCH_ERR_NEEDVPORT;

    switch (levels)
    {
        case 8:
        case 16:
        case 32:
        case 64:
        case 128:
        case 256:
            break;
        return ESCH_ERR_INVALIDPARMS;
    }

    if (slevel >= levels
        || blevel >= levels
        || blevel <= slevel
        || bpercent <= 0
        || bpercent >= float(1.0))
        return ESCH_ERR_INVALIDPARMS;

//ÄÄÄ Free old haze palette, if owned by Camera
    if ((flags & ESCH_CAM_OWNSHAZE) && hz_pal)
    {
        delete hz_pal;
    }
    hz_pal=0;

    flags &= ~(ESCH_CAM_OWNSHAZE|ESCH_CAM_HAZE);

//ÄÄÄ Create new haze table
    hz_pal = new VngoShadePal8 (levels);
    if (!hz_pal)
        return ESCH_ERR_NOMEMORY;

    hz_startz = (slevel << hz_pal->num_shd_lvl_bits);

    flags |= ESCH_CAM_OWNSHAZE | ESCH_CAM_HAZE;

    //ÄÄÄ Setup each color
    VngoPal *pal = vport->vbuff.pal;

    for (ulong qt=0; qt < VNGO_PAL_SIZE; qt++)
    {
        byte *shl = &(*((VngoShadePal8*)hz_pal))[qt].shl[0];

        //ÄÄÄ Unaffected haze range
        for(int lvl = 0; lvl < slevel; lvl++)
        {
            shl[lvl] = (byte)qt;
        }

        VngoColor24bit color = pal->get_RGB(qt);
        float colorr = float(color.r);
        float colorg = float(color.g);
        float colorb = float(color.b);

        VngoColor24bit bcolor
            ((byte)(long)(colorr + (float(tcolor.r - color.r) * bpercent)),
             (byte)(long)(colorg + (float(tcolor.g - color.g) * bpercent)),
             (byte)(long)(colorb + (float(tcolor.b - color.b) * bpercent)));

        //ÄÄÄ Haze out to break point
        {
            float rstep = float(bcolor.r - color.r) / float(blevel - slevel);
            float gstep = float(bcolor.g - color.g) / float(blevel - slevel);
            float bstep = float(bcolor.b - color.b) / float(blevel - slevel);

            for(; lvl < blevel; lvl++)
            {
                shl[lvl] = (byte)pal->get_index(VngoColor24bit
                                                 ((byte)(long)colorr,
                                                  (byte)(long)colorg,
                                                  (byte)(long)colorb));

                colorr += rstep;
                colorg += gstep;
                colorb += bstep;
            }
        }

        //ÄÄÄ Haze out to target color
        {
            float rstep = float(tcolor.r - bcolor.r) / float(levels - blevel);
            float gstep = float(tcolor.g - bcolor.g) / float(levels - blevel);
            float bstep = float(tcolor.b - bcolor.b) / float(levels - blevel);

            for(; lvl < levels; lvl++)
            {
                shl[lvl] = (byte)pal->get_index(VngoColor24bit
                                                 ((byte)(long)colorr,
                                                  (byte)(long)colorg,
                                                  (byte)(long)colorb));

                colorr += rstep;
                colorg += gstep;
                colorb += bstep;
            }
        }
    }

    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - set_gradient                                              ³
//                                                                          ³
// Sets up the gradient background palette, freeing the old one if owned by ³
// the camera, returning 0 on success, or 1 if setting the palette failed.  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschCameraEx::set_gradient(VngoShadePal *grdp, int owns)
{
//ÄÄÄ Free old gradient palette, if owned by Camera
    if ((flags & ESCH_CAM_OWNSGRADIENT) && grd_pal)
    {
        delete grd_pal;
    }
    grd_pal=0;

    flags &= ~(ESCH_CAM_OWNSGRADIENT|ESCH_CAM_GRADIENT);

//ÄÄÄ Test for valid palette
    if (!grdp)
        return 1;

//ÄÄÄ Setup palette, if valid
    grd_pal = grdp;
    if (owns)
        flags |= ESCH_CAM_OWNSGRADIENT;

    flags |= ESCH_CAM_GRADIENT;

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - create_gradient                                           ³
//                                                                          ³
// Generates a new gradient background shade palette given shade levels,    ³
// break-point level, break-point percentage, and start and end colors.     ³
//                                                                          ³
// Note: This ramps in RGB space which gives better results that ramping in ³
//       HLS space, which results in 'strange' changes in hues.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschCameraEx::create_gradient(ushort levels,
                                               ushort blevel, float bpercent,
                                               VngoColor24bit color1,
                                               VngoColor24bit color2)
{
//ÄÄÄ Verify input
    if (!vport || !vport->vbuff.pal)
        return ESCH_ERR_NEEDVPORT;

    switch (levels)
    {
        case 8:
        case 16:
        case 32:
        case 64:
        case 128:
        case 256:
            break;
        return ESCH_ERR_INVALIDPARMS;
    }

//ÄÄÄ Free old gradient palette, if owned by Camera
    if ((flags & ESCH_CAM_OWNSGRADIENT) && grd_pal)
    {
        delete grd_pal;
    }
    grd_pal=0;

    flags &= ~(ESCH_CAM_OWNSGRADIENT|ESCH_CAM_GRADIENT);

//ÄÄÄ Create new gradient table
    grd_pal = new VngoShadePal8 (levels);
    if (!grd_pal)
        return ESCH_ERR_NOMEMORY;

    flags |= ESCH_CAM_OWNSGRADIENT | ESCH_CAM_GRADIENT;

    //ÄÄÄ Setup each color (for gradient, all colors map to same for now...)
    VngoPal *pal = vport->vbuff.pal;

    for (ulong qt=0; qt < VNGO_PAL_SIZE; qt++)
    {
        byte *shl = &(*((VngoShadePal8*)grd_pal))[qt].shl[0];

        float colorr = float(color1.r);
        float colorg = float(color1.g);
        float colorb = float(color1.b);

        VngoColor24bit bcolor
            ((byte)(long)(colorr + (float(color2.r - color1.r) * bpercent)),
             (byte)(long)(colorg + (float(color2.g - color1.g) * bpercent)),
             (byte)(long)(colorb + (float(color2.b - color1.b) * bpercent)));

        int lvl=0;

        //ÄÄÄ Linear from color 1 to break point
        {
            float rstep = float(bcolor.r - color1.r) / float(blevel);
            float gstep = float(bcolor.g - color1.g) / float(blevel);
            float bstep = float(bcolor.b - color1.b) / float(blevel);

            for(; lvl < blevel; lvl++)
            {
                shl[lvl] = (byte)pal->get_index(VngoColor24bit
                                                ((byte)(long)colorr,
                                                 (byte)(long)colorg,
                                                 (byte)(long)colorb));

                colorr += rstep;
                colorg += gstep;
                colorb += bstep;
            }
        }

        //ÄÄÄ Linear from break point to color 2
        {
            float rstep = float(color2.r - bcolor.r) / float(levels - blevel);
            float gstep = float(color2.g - bcolor.g) / float(levels - blevel);
            float bstep = float(color2.b - bcolor.b) / float(levels - blevel);

            for(; lvl < levels; lvl++)
            {
                shl[lvl] = (byte)pal->get_index(VngoColor24bit
                                                ((byte)(long)colorr,
                                                 (byte)(long)colorg,
                                                 (byte)(long)colorb));

                colorr += rstep;
                colorg += gstep;
                colorb += bstep;
            }
        }
    }

    return ESCH_ERR_NONE;
}

//°±² End of module - escamex.cpp ²±°
