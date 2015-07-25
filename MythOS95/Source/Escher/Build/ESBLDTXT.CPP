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
// esbldtxt.cpp
//
// The EschBuildTexture class provides a method for creating materials
// manually and is used by the EschBuildMesh class.  The class can write
// a data file for later use.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"
#include "esfile.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

extern char EschNoName[];

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschBuildTexture - Constructor                                           ³
//                                                                          ³
// Intializes the instance                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschBuildTexture::EschBuildTexture() :
    tflags(0),
    bms(0)
{
    strcpy(name,EschNoName);
}

EschBuildTexture::EschBuildTexture(ulong mf) :
    tflags(0),
    bms(0)
{
    strcpy(name,EschNoName);

    init(mf);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschBuildTexture - Destructor                                            ³
//                                                                          ³
// Ensures data is released.                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschBuildTexture::~EschBuildTexture()
{
    release();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschBuildTexture - init                                                  ³
//                                                                          ³
// Initializes the instance, create the needed array of pointers.           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschBuildTexture::init(ulong mf)
{
    if (!mf)
        return ESCH_ERR_INVALIDPARMS;

    release();

//ÄÄÄ Bitmaps
    nframes = 0;
    maxframes = mf;
    bms = new XFBitmap *[mf];
    if (!bms)
        return ESCH_ERR_NOMEMORY;

    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschBuildTexture - release                                               ³
//                                                                          ³
// Frees all used memory.                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschBuildTexture::release(int freebms)
{
    if (bms)
    {
        for(ulong i=0; i < nframes; i++)
        {
            if (freebms && bms[i])
                delete bms[i];
        }
        delete [] bms;
        bms=0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschBuildTexture - save                                                  ³
//                                                                          ³
// Saves data to a data file base on data in builder.                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschBuildTexture::save(const char *fname, dword ctrlfl, VngoPal *pal)
{
    XFParseIFF  iff;

    if (iff.create(fname,0))
    {
        return ESCH_ERR_FILEERROR;
    }

    esch_error_codes err = save(&iff,ctrlfl,pal);
    if (err)
        return err;

    iff.close();

    return ESCH_ERR_NONE;
}

esch_error_codes EschBuildTexture::save(XFParseIFF *iff,
                                        dword ctrlfl, VngoPal *pal)
{
    if (!bms || !nframes)
        return ESCH_ERR_MISSINGDATA;

    switch (ctrlfl & (ESCH_TBLD_8BIT|ESCH_TBLD_TC))
    {
        case ESCH_TBLD_8BIT:
            if (!pal && bms[0]->bpp != 1)
                return ESCH_ERR_INVALIDPARMS;
            break;
        case ESCH_TBLD_TC:
            if (bms[0]->bpp != 3 && bms[0]->bpp != 4)
                return ESCH_ERR_INVALIDPARMS;
            break;
        default:
            return ESCH_ERR_INVALIDPARMS;
    }

//ÄÄÄ Create form
    if (iff->newform((nframes > 1) ? iff->makeid('E','M','T','1') 
                                   : iff->makeid('E','M','T','L')))
        return ESCH_ERR_FILEERROR;

//ÄÄÄ Write header
    {
        EschFileMtlMHDR     header;
        memset(&header,0,sizeof(header));

        strncpy(header.name,name,sizeof(header.name));
        header.xsize = bms[0]->width;
        header.ysize = bms[0]->height;
        header.nframes = (ushort)nframes;

        if (ctrlfl & ESCH_TBLD_TC)
        {
            header.type = (bms[0]->bpp == 4)
                          ? ESCH_MTL_TYPE_32BIT
                          : ESCH_MTL_TYPE_24BIT;
        }
        else
        {
            header.type = (ctrlfl & ESCH_TBLD_TRANSP)
                          ? ESCH_MTL_TYPE_8BIT_TRANSP
                          : ESCH_MTL_TYPE_8BIT;
        }

        header.compress = (ctrlfl & ESCH_TBLD_COMPRESS)
                          ? ESCH_MTL_COMPRESS_RLE
                          : ESCH_MTL_COMPRESS_NONE;

        header.flags = tflags;

        if (iff->write(iff->makeid('M','H','D','R'),
                       &header,sizeof(header)))
            return ESCH_ERR_FILEERROR;
    }

//ÄÄÄ Write body
    for(ulong i=0; i < nframes; i++)
    {
        XFBitmap *bm = bms[i];

        //ÄÄÄ Lock bitmap
        int locked=0;
        if (bm->pal || bm->data)
        {
            locked=1;
        }
        else
        {
            if (bm->lock() || !bm->data)
                return ESCH_ERR_LOCKFAILED;
        }

        int bpp = bm->bpp;
        int freedata=0;
        byte *data = bm->data;

        //ÄÄÄ Recolor
        if (ctrlfl & ESCH_TBLD_8BIT && bm->bpp != 1)
        {
            assert(pal != 0);

            data=new byte [bm->width*bm->height];
            if (!data)
                return ESCH_ERR_NOMEMORY;

            freedata=1;
            bpp=1;

            if (bm->bpp == 4)
            {
                byte *sptr = bm->data;
                byte *dptr = data;
                for(long i=0; i < bm->width*bm->height; i++)
                {
                    if ((*(sptr+3)) == 0)
                    {
                        *(dptr++) = (byte)VNGO_TRANSPARENT_COLOR;
                    }
                    else
                    {
                        *(dptr++) = (byte)pal->get_index(VngoColor24bit(
                                                            *sptr,
                                                            *(sptr+1),
                                                            *(sptr+2)));
                    }
                    sptr += 4;
                }
            }
            else
            {
                assert(bm->bpp == 3);
                byte *sptr = bm->data;
                byte *dptr = data;
                for(long i=0; i < bm->width*bm->height; i++)
                {
                    *(dptr++) = (byte)pal->get_index(VngoColor24bit(
                                                    *sptr,
                                                    *(sptr+1),
                                                    *(sptr+2)));
                    sptr += 3;
                }
            }
        }

        //ÄÄÄ Write
        byte *work=new byte [bm->width*bm->height*bpp];
        if (!work)
        {
            if (freedata)
                delete [] data;
            return ESCH_ERR_NOMEMORY;
        }

        dword size=0;
        if (ctrlfl & ESCH_TBLD_COMPRESS)
        {
            switch (bpp)
            {
                case 3:
                    size=XFParseXEB::compress_rle_24bpp(bm->width,bm->height,
                                                        data,work);
                    break;
                case 4:
                    size=XFParseXEB::compress_rle_32bpp(bm->width,bm->height,
                                                        data,work);
                    break;
                default:
                    assert(bpp == 1);
                    size=XFParseXEB::compress_rle_8bpp(bm->width,bm->height,
                                                       data,work);
                    break;
            }
        }

        if (size)
        {
            if (iff->write(iff->makeid('B','O','D','Y'),work,size))
            {
                if (freedata)
                    delete [] data;
                delete [] work;
                return ESCH_ERR_FILEERROR;
            }

            delete [] work;
        }
        else
        {
            delete [] work;

            if (iff->write(iff->makeid('B','O','D','Y'),
                           data,bm->width*bm->height*bpp))
            {
                if (freedata)
                    delete [] data;
                return ESCH_ERR_FILEERROR;
            }
        }

        if (freedata)
            delete [] data;

        //ÄÄÄ Unlock bitmap
        if (!locked)
            bm->unlock();
    }

    iff->leaveform();

    if (ctrlfl & ESCH_MBLD_INSCENE)
        iff->leaveform();

    return ESCH_ERR_NONE;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschBuildTexture - add_frame                                             ³
//                                                                          ³
// Adds a new frame to the texture.                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschBuildTexture::add_frame(XFBitmap *bm)
{
    assertMyth("EschBuildTexture::add_frame must be called after init",
               bms != 0);

    if (!bm
        || (bm->bpp != 1 && bm->bpp != 3 && bm->bpp != 4))
        return ESCH_ERR_INVALIDPARMS;

    if (nframes >= maxframes)
        return ESCH_ERR_NOMORE;

    if (!nframes)
    {
        switch (bm->width)
        {
            case 16:
            case 32:
            case 64:
            case 128:
            case 256:
                break;
            default:
                return ESCH_ERR_INVALIDSIZE;
        }

        switch (bm->height)
        {
            case 16:
            case 32:
            case 64:
            case 128:
            case 256:
                break;
            default:
                return ESCH_ERR_INVALIDSIZE;
        }
    }
    else if (bms[0]->width != bm->width
             || bms[0]->height != bm->height)
        return ESCH_ERR_INVALIDSIZE;

    bms[nframes++] = bm;

    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschBuildTexture - set_frame                                             ³
//                                                                          ³
// Changes a frame for the mesh.                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschBuildTexture::set_frame(ulong i, XFBitmap *bm,
                                             int freeold)
{
    assertMyth("EschBuildTexture::set_frame must be called after init",
               bms != 0);

    if (!bm
        || (bm->bpp != 1 && bm->bpp != 3 && bm->bpp != 4)
        || i >= nframes)
        return ESCH_ERR_INVALIDPARMS;

    if (bms[0]->width != bm->width
        || bms[0]->height != bm->height
        || bms[0]->bpp != bm->bpp)
        return ESCH_ERR_INVALIDSIZE;

    if (freeold && bms[i])
        delete bms[i];

    bms[i] = bm;

    return ESCH_ERR_NONE;
}

//°±² End of module - esbldtxt.cpp ²±°

