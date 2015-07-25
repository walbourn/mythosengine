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
//ùùùùùùùùùùùCopyrightù(c)ù1994-1996ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
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
    hz_pal(0)
{
};

EschCameraEx::EschCameraEx(const char *fname, const char *cname) :
    EschCamera(fname,cname),
    bg_bitmap(0),
    hz_pal(0)
{
};

EschCameraEx::EschCameraEx(const EschCamera &cam) :
    EschCamera(cam),
    bg_bitmap(0),
    hz_pal(0)
{
};

EschCameraEx::EschCameraEx(const EschCameraEx &cam) :
    EschCamera(cam),
    bg_bitmap(cam.bg_bitmap),
    hz_pal(cam.hz_pal)

{
    flags &= ~(ESCH_CAM_OWNSBITMAP | ESCH_CAM_OWNSHAZE);
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
        flags &= ~(ESCH_CAM_OWNSBITMAP | ESCH_CAM_OWNSHAZE);
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

//ÄÄÄ Clear any owns bits
    flags &= ~(ESCH_CAM_OWNSBITMAP | ESCH_CAM_OWNSHAZE);
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
                
                if (r < 0xfffe)
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
// returning 0 on success, or 1 if setting the bitmap failed.               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschCameraEx::set_haze(VngoShadePal *hzp, int owns)
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

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - set_haze                                                  ³
//                                                                          ³
// Generates a new hazing shade palette given shade levels, number of       ³
// 'pristine' levels, break-point level, break-point percentage, and        ³
// target color.                                                            ³
//                                                                          ³
// Note: This ramps in RGB space which gives better results that ramping in ³
//       HLS space, which results in 'strange' changes in hues.             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschCameraEx::create_haze(ushort levels, ushort slevel,
                                           ushort blevel, Flx16 bpercent,
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
        || bpercent >= Flx16(1.0))
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
        Flx16 colorr = Flx16(color.r);
        Flx16 colorg = Flx16(color.g);
        Flx16 colorb = Flx16(color.b);

        VngoColor24bit bcolor
            ((byte)(long)(colorr + (Flx16(tcolor.r - color.r) * bpercent)),
             (byte)(long)(colorg + (Flx16(tcolor.g - color.g) * bpercent)),
             (byte)(long)(colorb + (Flx16(tcolor.b - color.b) * bpercent)));

        //ÄÄÄ Haze out to break point
        {
            Flx16 rstep = Flx16(bcolor.r - color.r) / Flx16(blevel - slevel);
            Flx16 gstep = Flx16(bcolor.g - color.g) / Flx16(blevel - slevel);
            Flx16 bstep = Flx16(bcolor.b - color.b) / Flx16(blevel - slevel);

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
            Flx16 rstep = Flx16(tcolor.r - bcolor.r) / Flx16(levels - blevel);
            Flx16 gstep = Flx16(tcolor.g - bcolor.g) / Flx16(levels - blevel);
            Flx16 bstep = Flx16(tcolor.b - bcolor.b) / Flx16(levels - blevel);

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
