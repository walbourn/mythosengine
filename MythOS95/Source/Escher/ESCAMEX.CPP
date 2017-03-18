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

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define ES_MAX_VERTS    9

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
    bg_bitmap(0)
{
};

EschCameraEx::EschCameraEx(const char *fname, const char *cname) :
    EschCamera(fname,cname),
    bg_bitmap(0)
{
};

EschCameraEx::EschCameraEx(const EschCamera &cam) :
    EschCamera(cam),
    bg_bitmap(0)
{
};

EschCameraEx::EschCameraEx(const EschCameraEx &cam) :
    EschCamera(cam),
    bg_bitmap(cam.bg_bitmap)
{
    flags &= ~(ESCH_CAM_OWNSBITMAP);
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
        flags &= ~(ESCH_CAM_OWNSBITMAP);
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
        if (bg_bitmap->tex)
            delete [] bg_bitmap->tex;
        delete bg_bitmap;
    }
    bg_bitmap=0;

//ÄÄÄ Clear any owns bits
    flags &= ~(ESCH_CAM_OWNSBITMAP);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - pre_rend                                                  ³
//                                                                          ³
// Prepares a render, returning a 0 on success or non-zero otherwise.       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschCameraEx::pre_rend()
{
    static VngoPointF   vpt[ES_MAX_VERTS];
    static VngoPointF3  ivpt[ES_MAX_VERTS];
    static VngoPointF3  ovpt[ES_MAX_VERTS];
    static VngoPointF3  cvpt[10];

    assertMyth("EschCameraEx::pre_rend needs viewport & palette",
               vport != 0 && vport->vbuff.pal != 0);

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

            //ÄÄÄ Don't clear screen if the image covers entire viewport
            if (bg_offx < 0
                || bg_offy < 0
                || (rect.dx-bg_offx) < vport->vbuff.width
                || (rect.dy-bg_offy) < vport->vbuff.height)
                vport->clear_screen_on();
            else
                vport->clear_screen_off();

            vport->reset(bcolor);

            assert(bg_bitmap->tex != 0);
            vport->image_trans(&rect,bg_bitmap);
        }
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Gradient Background
        else if (flags & ESCH_CAM_GRADIENT)
        {
            int     turnonz=0, turnonhaze=0, edge_adj, swidth, sheight;
            float   tx, ty, tv, width, height;

            //ÄÄÄ Just clear Z-buffer
            vport->clear_screen_off();
            vport->reset();
            if (vport->vflags & VNGO_ZBUFFER_ACTIVE)
            {
                turnonz = 1;
                vport->zbuffer_off();
            }
            if (vport->vflags & VNGO_HAZE_ON)
            {
                turnonhaze = 1;
                vport->haze_off();
            }

            //ÄÄÄ Determine position of 'level-line'
            EschVector tdir(eye.dir.i, 0, eye.dir.k);
            float mag = tdir.magnitude();
            if (mag <= 0)
            {
                if (eye.dir.j > 0)
                {
                    VngoRect    rect(0,0,vport->vbuff.width,vport->vbuff.height);
                    vport->frect(&rect, grd_top);
                }
                else
                {
                    VngoRect    rect(0,0,vport->vbuff.width,vport->vbuff.height);
                    vport->frect(&rect, grd_bottom);
                }
            }
            else
            {
                // Don't think this is right for ORTHO cameras...

                tdir /= mag;

                tdir *= (((yon-hither) * 0.25f) + hither);

                EschVector left = tdir;
                left.rotatey(88);

                EschVector right = tdir;
                right.rotatey(-88);

                // 0  grd_top       1
                // 2                3
                // 4  grd_mid       5
                // 6                7
                // 8  grd_bottom    9

                tv = grd_topy;
                if (flags & ESCH_CAM_GRADIENT_FIXED)
                    tv -= eye.orient.mtx[ESCH_MTX_K];

                cvpt[0].wx = left.i;
                cvpt[0].wy = left.j + ((tv > yon) ? tv : yon);
                cvpt[0].wz = left.k;
                cvpt[0].clr = grd_top;

                cvpt[1].wx = right.i;
                cvpt[1].wy = right.j + ((tv > yon) ? tv : yon);
                cvpt[1].wz = right.k;
                cvpt[1].clr = grd_top;

                cvpt[2].wx = left.i;
                cvpt[2].wy = left.j + tv;
                cvpt[2].wz = left.k;
                cvpt[2].clr = grd_top;

                cvpt[3].wx = right.i;
                cvpt[3].wy = right.j + tv;
                cvpt[3].wz = right.k;
                cvpt[3].clr = grd_top;

                tv = grd_midy;
                if (flags & ESCH_CAM_GRADIENT_FIXED)
                    tv -= eye.orient.mtx[ESCH_MTX_K];

                cvpt[4].wx = left.i;
                cvpt[4].wy = left.j + tv;
                cvpt[4].wz = left.k;
                cvpt[4].clr = grd_mid;

                cvpt[5].wx = right.i;
                cvpt[5].wy = right.j + tv;
                cvpt[5].wz = right.k;
                cvpt[5].clr = grd_mid;

                tv = grd_bottomy;
                if (flags & ESCH_CAM_GRADIENT_FIXED)
                    tv -= eye.orient.mtx[ESCH_MTX_K];

                cvpt[6].wx = left.i;
                cvpt[6].wy = left.j + tv;
                cvpt[6].wz = left.k;
                cvpt[6].clr = grd_bottom;

                cvpt[7].wx = right.i;
                cvpt[7].wy = right.j + tv;
                cvpt[7].wz = right.k;
                cvpt[7].clr = grd_bottom;

                cvpt[8].wx = left.i;
                cvpt[8].wy = left.j + ((tv < -yon) ? tv : -yon);
                cvpt[8].wz = left.k;
                cvpt[8].clr = grd_bottom;

                cvpt[9].wx = right.i;
                cvpt[9].wy = right.j + ((tv < -yon) ? tv : -yon);
                cvpt[9].wz = right.k;
                cvpt[9].clr = grd_bottom;

                for(int i=0; i < 10; i++)
                {
                    ((EschVector*)&cvpt[i])->transform(&eye.iorient);
                }

                tx = xscalar;
                ty = yscalar;

                edge_adj = vport->skips_last_pix();
                swidth = vport->vbuff.width + edge_adj;
                sheight = vport->vbuff.height + edge_adj;

                height = float(vport->vbuff.height >> 1);
                width = float(vport->vbuff.width >> 1);

                for(int i=0; i < 8; i++)
                {
                    ulong count=3;
                    for(int j=0; j < 3; j++)
                        ivpt[j] = cvpt[i+j];

                    int clip = esch_clip_to_frustrum(&count, ivpt, ovpt, this, 0);

                    if (clip != 0)
                    {
                        if (clip == -1)
                        {
                            count = 3;
                            for(ulong j=0; j < 3; j++)
                            {
                                tv = (ivpt[j].wx * tx) / ivpt[j].wz;

                                vpt[j].x = float(floor(tv + width + 0.5f));

                                tv = (ivpt[j].wy * ty) / ivpt[j].wz;

                                vpt[j].y = float(floor(height - tv + 0.5f));

                                vpt[j].z = 0.99998f;

                                vpt[j].clr = ivpt[j].clr;

                                if (vpt[j].x < 0.f)
                                    vpt[j].x = 0.f;
                                else if (vpt[j].x >= swidth)
                                    vpt[j].x = float(swidth-1);
                                if (vpt[j].y < 0.f)
                                    vpt[j].y = 0.f;
                                else if (vpt[j].y >= sheight)
                                    vpt[j].y = float(sheight - 1);
                            }
                        }
                        else
                        {
                            for(ulong j=0; j < count; j++)
                            {
                                tv = (ovpt[j].wx * tx) / ovpt[j].wz;

                                vpt[j].x = float(floor(tv + width + 0.5f));

                                tv = (ovpt[j].wy * ty) / ovpt[j].wz;

                                vpt[j].y = float(floor(height - tv + 0.5f));

                                vpt[j].z = 0.99998f;

                                vpt[j].clr = ovpt[j].clr;

                                if (vpt[j].x < 0.f)
                                    vpt[j].x = 0.f;
                                else if (vpt[j].x >= swidth)
                                    vpt[j].x = float(swidth-1);
                                if (vpt[j].y < 0.f)
                                    vpt[j].y = 0.f;
                                else if (vpt[j].y >= sheight)
                                    vpt[j].y = float(sheight - 1);
                            }
                        }

                        if (count >= 3)
                            vport->grpoly(count, vpt);
                    }
                }
            }

            //ÄÄÄ Cleanup
            if (turnonz)
                vport->zbuffer_on();
            if (turnonhaze)
                vport->haze_on();
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
    assertMyth("EschCameraEx::post_rend needs viewport & palette",
               vport != 0 && vport->vbuff.pal != 0);

//ÄÄÄ Flush element buffer (if not forcing skip of this step)
    if (!(flags & ESCH_CAM_NOFLUSH))
        EschElement::flush();

//ÄÄÄ Handle hazing
    vport->haze();

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
int EschCameraEx::set_bg_bitmap(VngoTexture *tex, int owns)
{
//ÄÄÄ Free old bitmap, if owned by Camera
    if ((flags & ESCH_CAM_OWNSBITMAP) && bg_bitmap)
    {
        if (bg_bitmap->tex)
            delete [] bg_bitmap->tex;
        delete bg_bitmap;
    }
    bg_bitmap=0;

//ÄÄÄ Clear flag & reset offset.
    flags &= ~ESCH_CAM_OWNSBITMAP;

    bg_offx=bg_offy=0;

//ÄÄÄ Test for valid bitmap
    if (!tex)
        return 1;

//ÄÄÄ Setup bitmap, if valid.
    bg_bitmap = tex;
    if (owns)
        flags |= ESCH_CAM_OWNSBITMAP;

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - create_bg_bitmap                                          ³
//                                                                          ³
// Creates a bitmap background from the input XFBitmap instance and sets it ³
// as the new current bitmap owned by the camera.  Any previous owned       ³
// instance is freed.  Returns 0 on success, 1 if failed.                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschCameraEx::create_bg_bitmap(XFBitmap *bm)
{
    assertMyth("EschCameraEx::create_bg_bitmap needs viewport & palette",
               vport != 0 && vport->vbuff.pal != 0);

    if (!bm)
        return 1;

    VngoTexture *tex = new VngoTexture;
    if (!tex)
        return 1;

    VngoPal *pal = vport->vbuff.pal;
    if (pal->flags & VNGO_16BIT)
    {
        if ((tex->create(bm->width, bm->height, 16, 0) != VNGO_NO_ERROR)
            || (tex->convert(bm,pal) != VNGO_NO_ERROR))
        {
            if (tex->tex)
                delete [] tex->tex;
            delete tex;
            return 1;
        }
    }
    else if (pal->flags & VNGO_15BIT)
    {
        if ((tex->create(bm->width, bm->height, 15, 0) != VNGO_NO_ERROR)
            || (tex->convert(bm,pal) != VNGO_NO_ERROR))
        {
            if (tex->tex)
                delete [] tex->tex;
            delete tex;
            return 1;
        }
    }
    else
    {
        if ((tex->create(bm->width, bm->height, 8, 0) != VNGO_NO_ERROR)
            || (tex->convert(bm,pal) != VNGO_NO_ERROR))
        {
            if (tex->tex)
                delete [] tex->tex;
            delete tex;
            return 1;
        }
    }

    if (set_bg_bitmap(tex,1))
    {
        if (tex->tex)
            delete [] tex->tex;
        delete tex;
        return 1;
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - set_haze                                                  ³
//                                                                          ³
// Sets up hazing information in viewport.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschCameraEx::set_haze(float start, float mid)
{
    assertMyth("EschCameraEx::set_haze needs viewport & palette",
               vport != 0 && vport->vbuff.pal != 0);

    VngoHazeInfo hinfo;
    hinfo.start_depth = start;
    hinfo.mid_depth = mid;
    hinfo.target_color = vport->vbuff.pal->get_RGB(bcolor);
    if (vport->set_haze(&hinfo) != VNGO_NO_ERROR)
        return 1;

    vport->haze_on();

    return 0;
}

int EschCameraEx::set_haze(float start, float mid, VngoColor24bit tcolor)
{
    assertMyth("EschCameraEx::set_haze(2) needs viewport & palette",
               vport != 0 && vport->vbuff.pal != 0);

    VngoHazeInfo hinfo;
    hinfo.start_depth = start;
    hinfo.mid_depth = mid;
    hinfo.target_color = tcolor;
    if (vport->set_haze(&hinfo) != VNGO_NO_ERROR)
        return 1;

    vport->haze_on();

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschCameraEx - set_haze                                                  ³
//                                                                          ³
// Sets up hazing information in viewport.                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschCameraEx::set_gradient(VngoColor24bit top, float topy,
                                VngoColor24bit mid, float midy,
                                VngoColor24bit bottom, float bottomy,
                                int fixed)
{
    grd_top = top.b | (top.g << 8) | (top.r << 16) | VNGO_COLOR_24BIT;
    grd_mid = mid.b | (mid.g << 8) | (mid.r << 16) | VNGO_COLOR_24BIT;
    grd_bottom = bottom.b | (bottom.g << 8) | (bottom.r << 16)
                 | VNGO_COLOR_24BIT;

    grd_topy = topy;
    grd_midy = midy;
    grd_bottomy = bottomy;

    flags |= ESCH_CAM_GRADIENT;
    if (fixed)
        flags |= ESCH_CAM_GRADIENT_FIXED;
    else
        flags &= ~ESCH_CAM_GRADIENT_FIXED;
}

//°±² End of module - escamex.cpp ²±°
