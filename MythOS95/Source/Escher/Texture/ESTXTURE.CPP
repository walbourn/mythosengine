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
// estxture.cpp
//
// EschTexture is the interface defining class for the texture container
// object.  The EschTexture class contains a VngoTexture pointer and a
// number of standard interface members used to control the texture
// usage.
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
// EschTexture - Constructor                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschTexture::EschTexture() :
    ttyp(ESCH_TXTT_BASE),
    flags(0),
    name(EschNoName),
    ptr(0)
{
    //ÄÄ Update diags
    assertMyth("EschTexture needs Escher initialized",EschSysInstance != 0);
    EschSysInstance->diag_ntxts++;
}

EschTexture::EschTexture(const EschTexture &txt) :
    ttyp(txt.ttyp),
    flags(txt.flags & ~ESCH_TXT_OWNSDATA),
    name(txt.name),
    ptr(txt.ptr)
{
    //ÄÄ Update diags
    assertMyth("EschTexture needs Escher initialized",EschSysInstance != 0);
    EschSysInstance->diag_ntxts++;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTexture - Destructor                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschTexture::~EschTexture()
{
    release();

    //ÄÄ Update diags
    assertMyth("EschTexture needs Escher initialized",EschSysInstance != 0);
    EschSysInstance->diag_ntxts--;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTexture - operator =                                                 ³
//                                                                          ³
// Copies the data from another texture.                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
const EschTexture &EschTexture::operator = (const EschTexture &txt)
{
    if (this != &txt)
    {
        release();

        flags = txt.flags & ~(ESCH_TXT_OWNSDATA|ESCH_TXT_SHARED);
        name = txt.name;
        ptr = txt.ptr;
    }
    return *this;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTexture - release                                                    ³
//                                                                          ³
// This first unlocks the texture, then it releases name and ptr.           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTexture::release()
{
    if (flags & ESCH_TXT_LOCKED)
        unlock();

    if (flags & ESCH_TXT_OWNSDATA)
    {
        if (name && name != EschNoName)
        {
            delete [] name;
        }
        name=EschNoName;

        if (ptr)
        {
            delete [] ptr;
        }
    }
    name=EschNoName;
    ptr=0;

    flags &= ~(ESCH_TXT_OWNSDATA | ESCH_TXT_LOCKED | ESCH_TXT_SHARED);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTexture - lock                                                       ³
//                                                                          ³
// Locks the texture, making the 'ptr' member a valid pointer to a Van Gogh ³
// texture object.                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTexture::lock()
{
    // Just ensures LOCKED bit is maintained.

    if (flags & ESCH_TXT_LOCKED)
        return;

    if (!ptr)
        return;

    flags |= ESCH_TXT_LOCKED;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTexture - unlock                                                     ³
//                                                                          ³
// Unlocks the texture.                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTexture::unlock()
{
    // Just ensures LOCKED bit is maintained.

    if (flags & ESCH_TXT_LOCKED)
    {
        assertMyth("EschTexture::unlock expects ptr to be non-zero",
                   ptr);

        flags &= ~ESCH_TXT_LOCKED;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTexture - animate                                                    ³
//                                                                          ³
// Performs per-frame updating to animate the texture.                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschTexture::animate()
{
    // Performs no action
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  I/O Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                              °°° Protected °°°                           ³
// EschTexture - load_body                                                  ³
//                                                                          ³
// Utility member for loading bitmap body frames for textures which is used ³
// by Static and Multiframe textures.                                       ³
//                                                                          ³
// Assumes that the ptr member is set to the target texture instance.       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschTexture::load_body(XFParseIFF *iff,
                                        EschFileMtlMHDR &header,
                                        VngoPal *pal)
{
    byte *work;

    assert(iff && ptr);
    assert(iff->chunkid == iff->makeid('B','O','D','Y') && iff->chunkSize);

    assert(header.type == ESCH_MTL_TYPE_8BIT
           || header.type == ESCH_MTL_TYPE_8BIT_TRANSP
           || header.type == ESCH_MTL_TYPE_24BIT
           || header.type == ESCH_MTL_TYPE_32BIT);

//ÄÄÄ Determine bytes per pixel
    int bpp=1;
    switch (header.type)
    {
        case ESCH_MTL_TYPE_24BIT:
            bpp=3;
            break;
        case ESCH_MTL_TYPE_32BIT:
            bpp=4;
            break;
    }

//ÄÄÄ Process
    if (header.compress == ESCH_MTL_COMPRESS_RLE
        && iff->chunkSize < (ulong)(header.xsize * header.ysize * bpp))
    {
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Compressed
        work = new byte[iff->chunkSize];
        if (!work)
            return ESCH_ERR_NOMEMORY;

        if (iff->read(work))
        {
            delete [] work;
            return ESCH_ERR_FILEERROR;
        }

        switch (bpp)
        {
            case 3:
                {
                    byte *dptr=(byte*)ptr->tex;
                    byte *eptr=(byte*)ptr->tex + (header.xsize*header.ysize);
                    for(byte *wptr=work; wptr < work+iff->chunkSize; )
                    {
                        int j = (char) *(wptr++);
                        if (j >= 0)
                        {
                            //ÄÄÄ Literial
                            for(int i=0; i < j+1; i++)
                            {
                                if (dptr >= eptr)
                                {
                                    delete [] work;
                                    return ESCH_ERR_INVALIDDATA;
                                }

                                *(dptr++) = (byte)pal->get_index(
                                                            VngoColor24bit(
                                                                 *wptr,
                                                                 *(wptr+1),
                                                                 *(wptr+2)));
                                wptr += 3;
                            }
                        }
                        else
                        {
                            //ÄÄÄ Run
                            j = -j+1;
                            for(int i=0; i < j; i++)
                            {
                                if (dptr >= eptr)
                                {
                                    delete [] work;
                                    return ESCH_ERR_INVALIDDATA;
                                }

                                *(dptr++) = (byte)pal->get_index(
                                                            VngoColor24bit(
                                                                 *wptr,
                                                                 *(wptr+1),
                                                                 *(wptr+2)));
                            }
                            wptr += 3;
                        }
                    }
                }
                break;
            case 4:
                {
                    byte *dptr=(byte*)ptr->tex;
                    byte *eptr=(byte*)ptr->tex + (header.xsize*header.ysize);
                    for(byte *wptr=work; wptr < work+iff->chunkSize; )
                    {
                        int j = (char) *(wptr++);
                        if (j >= 0)
                        {
                            //ÄÄÄ Literial
                            for(int i=0; i < j+1; i++)
                            {
                                if (dptr >= eptr)
                                {
                                    delete [] work;
                                    return ESCH_ERR_INVALIDDATA;
                                }

                                if (*(wptr+3) <= 10)
                                {
                                    *(dptr++) = (byte)VNGO_TRANSPARENT_COLOR;
                                }
                                else
                                {
                                    *(dptr++) = (byte)pal->get_index(
                                                            VngoColor24bit(
                                                                    *wptr,
                                                                    *(wptr+1),
                                                                    *(wptr+2)));
                                }
                                wptr += 4;
                            }
                        }
                        else
                        {
                            //ÄÄÄ Run
                            j = -j+1;
                            for(int i=0; i < j; i++)
                            {
                                if (dptr >= eptr)
                                {
                                    delete [] work;
                                    return ESCH_ERR_INVALIDDATA;
                                }

                                if (*(wptr+3) <= 10)
                                {
                                    *(dptr++) = (byte)VNGO_TRANSPARENT_COLOR;
                                }
                                else
                                {
                                    *(dptr++) = (byte)pal->get_index(
                                                            VngoColor24bit(
                                                                    *wptr,
                                                                    *(wptr+1),
                                                                    *(wptr+2)));
                                }
                            }
                            wptr += 4;
                        }
                    }
                }
                break;
            default:
                if (XFParseXEB::uncompress_rle_8bpp(header.xsize, header.ysize,
                                                    iff->chunkSize, work,
                                                    (byte*)ptr->tex))
                {
                    delete [] work;
                    return ESCH_ERR_INVALIDDATA;
                }
                break;
        }

        delete [] work;
    }
    else
    {
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Uncompressed
        if (iff->chunkSize != (ulong)(header.xsize * header.ysize * bpp))
            return ESCH_ERR_INVALIDDATA;

        //ÄÄÄ Handle 8bits directly
        if (bpp == 1)
        {
            if (iff->read(ptr->tex))
                return ESCH_ERR_FILEERROR;

            return ESCH_ERR_NONE;
        }

        //ÄÄÄ Handle 24/32-bits
        work = new byte[iff->chunkSize];
        if (!work)
            return ESCH_ERR_NOMEMORY;

        if (iff->read(work))
        {
            delete [] work;
            return ESCH_ERR_FILEERROR;
        }

        //ÄÄÄ Recolor
        assert(pal);

        if (bpp == 4)
        {
            byte *dptr = (byte*)ptr->tex;
            byte *sptr = work;
            for(ulong i=0; i < (ulong)(header.xsize * header.ysize); i++)
            {
                if ((*(sptr+3)) <= 10)
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
            assert(bpp == 3);
            byte *dptr = (byte*)ptr->tex;
            byte *sptr = work;
            for(ulong i=0; i < (ulong)(header.xsize * header.ysize); i++)
            {
                *(dptr++) = (byte)pal->get_index(VngoColor24bit(
                                                 *sptr,
                                                 *(sptr+1),
                                                 *(sptr+2)));
                sptr += 3;
            }
        }

        delete [] work;
    }

    return ESCH_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTexture - load                                                       ³
//                                                                          ³
// Loads the data for the texture from an IFF file.                         ³
//                                                                          ³
// The IFF version assumes that the IFF is open and pointing at the proper  ³
// chunk.  If a 'tname' is given and the name doesn't match that in the     ³
// form, an error is returned.                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschTexture::load(const char *fname, const char *tname,
                                   dword ctrlfl, VngoPal *pal)
{
    esch_error_codes    err;
    XFParseIFF          iff;

//ÄÄ Open file
    if (iff.open(fname,XF_OPEN_READ))
        return ESCH_ERR_FILEERROR;

//ÄÄ Loop until a header with the correct name is found
    err=ESCH_ERR_NONE;

    for(;;)
    {
        if (iff.next() != XF_ERR_NONE)
        {
            if (!iff.depth)
                return ESCH_ERR_NOTFOUND;
            iff.leaveform();
        }

        if (iff.chunkid == iff.makeid('F','O','R','M'))
        {
            if (iff.formid == iff.makeid('E','M','T','L')
                || iff.formid == iff.makeid('E','M','T','1'))
            {
                err=load(&iff,tname,ctrlfl,pal);
                if (!err
                    || err != ESCH_ERR_NOTFOUND)
                    break;
            }

            // Must scan inside any ESEN Scene forms.
            else if (iff.formid == iff.makeid('E','S','E','N'))
            {
                iff.enterform();
            }

            // Must scan inside any EMSH Scene forms.
            else if (iff.formid == iff.makeid('E','M','S','H'))
            {
                iff.enterform();
            }
        }
    }

//ÄÄ Return ok
    iff.close();
    return err;
}

esch_error_codes EschTexture::load(XFParseIFF *iff, const char *tname,
                                   dword ctrlfl, VngoPal *pal)
{
    return ESCH_ERR_NOTSUPPORTED;
}

//°±² End of module - estxture.cpp ²±°

