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
//ùùùùùùùùùùCopyrightù(c)ù1994,ù1995ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
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
//      The EschCameraEx object is an extended camera which handles
//      bitmap backgrounds and other special effects.
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
EschCameraEx::EschCameraEx(VngoVport *vp)
                          :EschCamera(vp)
{
    bg_bitmap=0;
    hz_pal=0;

#if 0
    set_hz_range(hither,yon);
#endif
};

EschCameraEx::EschCameraEx(const char *fname, const char *cname)
                          :EschCamera(fname,cname)
{
    bg_bitmap=0;
    hz_pal=0;
#if 0
    set_hz_range(hither,yon);
#endif
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - Destructor                                                ³
//                                                                          ³
// Releases any associated data for the camera object.                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschCameraEx::~EschCameraEx()
{
    if ((flags & ESCH_CAM_OWNSBITMAP) && bg_bitmap)
    {
        bg_bitmap->release();
        delete bg_bitmap;
    }
    bg_bitmap=0;
};



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - rend                                                      ³
//                                                                          ³
// Renders the current context to the camera.                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCameraEx::rend(void)
{
    EschDrawable    *ptr;

    if (!vport)
        return;

//ÄÄÄ Clear viewport/reset background bitmap
    if (!(flags & ESCH_CAM_NOCLEAR))
    {

        if ( (!(flags & ESCH_CAM_IGNORE_BMAP)) && bg_bitmap)
        {
            VngoRect    rect;
            VngoTexture txt;

            rect.x = 0;
            rect.y = 0;
            rect.dx = vport->get_vbuff()->width;
            rect.dy = vport->get_vbuff()->height;

            if ((bg_w >= vport->get_vbuff()->width)
                && (bg_h >= vport->get_vbuff()->height))
                vport->clear_screen_off();
            else
                vport->clear_screen_on();

            flags &= ~ESCH_CAM_DIRTY_BMAP;

            vport->reset();

            bg_bitmap->lock();
            txt.width = bg_w;
            txt.height = bg_h;
            txt.tex = bg_bitmap->data;

            vport->image_trans(&rect,&txt);
            bg_bitmap->unlock();
        }
        else
        {
            vport->clear_screen_on();
            vport->reset(bcolor);
        }

    }

//ÄÄÄ Draw list of EschDrawables
    for(ptr=EschCurrent->eschs; ptr != NULL; ptr = ptr->next())
    {
        if (!(ptr->flags & ESCH_DRW_SKIP))
            ptr->draw();
    }

#if 0
//ÄÄÄ Perform hazing lookup
    if ((flags & ESCH_CAM_HAZE) && hz_pal)
    {
        long    x, y;
        dword   r;
        byte    *cptr;
        ushort  *zptr;

        assertMyth("EschCameraEx::rend needs screen and zbuffer pointers to haze",
                   vport->get_vbuff()->zbuff_ptr && vport->get_vbuff()->scrn_ptr);

        for(y=0; y < vport->get_vbuff()->height; y++)
        {
            cptr = vport->get_vbuff()->scrn_ptr 
                   + vport->get_vbuff()->ytable[y];
            zptr = (ushort*)((byte*)vport->get_vbuff()->zbuff_ptr 
                   + (vport->get_vbuff()->ytable[y]<<1));   // 16-bit Zbuffer

            for(x=0; x < vport->get_vbuff()->width; x++)
            {
                r = *(zptr++) << 16;                        // 16-bit Zbuffer
                if (r >= hz_near)
                {
                    if (r < hz_far)
                    {
                        r = (r - hz_near) / hz_factor;
                        assert(r < 24);
                        *cptr = hz_pal->p[*cptr].shl[23-r];
                    }
                    else
                    {
                        *cptr = hz_pal->p[*cptr].shl[0];
                    }
                }
                cptr++;
            }
        }
    }
#endif
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - set_bg_offset                                             ³
//                                                                          ³
// Sets the offset for the bitmap background map window.                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCameraEx::set_bg_offset(short x, short y)
{
    if (!bg_bitmap)
        return;

    flags |= ESCH_CAM_DIRTY_BMAP;

    bg_offx = x;
    bg_offy = y;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - set_bg_size                                               ³
//                                                                          ³
// Sets the size for the bitmap background map window                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCameraEx::set_bg_size(short w, short h)
{
    if (!bg_bitmap)
        return;

    flags |= ESCH_CAM_DIRTY_BMAP;

    bg_w = w;
    bg_h = h;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - set_bg_bitmap                                             ³
//                                                                          ³
// Sets up the bitmap background, freeing the old one if owned by the camera³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCameraEx::set_bg_bitmap(XFBitmap *bm, int owns)
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

    if (!bm || !bm->handle || (bm->bpp != 1))
        return;

//ÄÄÄ Setup bitmap, if valid.
    bg_bitmap = bm;
    if (owns)
        flags |= ESCH_CAM_OWNSBITMAP;

    flags |= ESCH_CAM_DIRTY_BMAP;

    bg_w = bm->width;
    bg_h = bm->height;
}


#if 0
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - set_hz_palette                                            ³
//                                                                          ³
// Sets up a hazing palette for the camera to use.                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCameraEx::set_hz_palette(VngoHazePal8 *hp, int owns)
{
    if (flags & ESCH_CAM_OWNSHAZE)
    {
        delete hz_pal;
    }
    hz_pal=0;
    flags &= ~(ESCH_CAM_HAZE|ESCH_CAM_OWNSHAZE);

    if (!hp)
        return;

    hz_pal = hp;
    flags |= ESCH_CAM_HAZE | ((owns) ? ESCH_CAM_OWNSHAZE : 0);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - set_hz_range                                              ³
//                                                                          ³
// Computes z scaling factor based on near and far ranges.                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCameraEx::set_hz_range(Flx16 n, Flx16 f)
{
    assertMyth("EschCameraEx::set_hz_range needs hither <= n and f <= yon",
               (n.flx >= hither.flx) && (f.flx <= yon.flx));
    hz_near = flx_16mul16(n,z_factor).flx << 1;
    hz_far = flx_16mul16(f,z_factor).flx << 1;
    hz_factor = (hz_far - hz_near) / 24;
}
#endif

//°±² End of module - escamex.cpp ²±°
