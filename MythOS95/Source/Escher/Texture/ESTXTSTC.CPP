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
// estxtstc.cpp
//
// EschStaticTexture is a single-frame bitmap texture.
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
// EschStaticTexture - Destructor                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschStaticTexture::~EschStaticTexture()
{
    release();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschStaticTexture - release                                              ³
//                                                                          ³
// Removes the texture data from memory.                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschStaticTexture::release()
{
    if (flags & ESCH_TXT_LOCKED)
        unlock();

    if (flags & ESCH_TXT_SHARED)
    {
        if (handle)
            cache_release(handle);
        name=EschNoName;
    }
    else if (flags & ESCH_TXT_OWNSDATA)
    {
        if (handle)
        {
            VngoTexture *p = (VngoTexture*)ivory_hlock(handle);
            if (p)
            {
                p->VngoTexture::~VngoTexture();
                ivory_hunlock(handle);
            }
            ivory_hfree(&handle);
        }
        if (name && name != EschNoName)
            delete [] name;
        name=EschNoName;
    }
    handle=0;

    EschTexture::release();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschStaticTexture - lock                                                 ³
//                                                                          ³
// Locks the texture, making the 'ptr' member a valid pointer to a Van Gogh ³
// texture object.                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschStaticTexture::lock()
{
    assertMyth("EschStaticTexture::lock needs a valid handle",
               handle);

    if (flags & ESCH_TXT_LOCKED)
        return;

    ptr = (VngoTexture*) ivory_hlock(handle);

    assertMyth("EschStaticTexture::lock couldn't lock memory",
               ptr);

    if (!ptr)
        return;

    flags |= ESCH_TXT_LOCKED;

    ptr->tex = (byte*)ptr + sizeof(VngoTexture);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschStaticTexture - unlock                                               ³
//                                                                          ³
// Unlocks the texture, invalidating the 'ptr' member.                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void EschStaticTexture::unlock()
{
    if (flags & ESCH_TXT_LOCKED)
    {
        assertMyth("EschStaticTexture::unlock expects ptr to be non-zero",
                   ptr);

        ivory_hunlock(handle);

        flags &= ~ESCH_TXT_LOCKED;

        ptr=0;
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°±  Utility Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschStaticTexture - create                                               ³
//                                                                          ³
// Creates a texture from an (appropriate) XFile bitmap.                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschStaticTexture::create(XFBitmap *bm, int trans, VngoPal *pal)
{
//ÄÄÄ Verify valid input
    if (!bm)
        return ESCH_ERR_INVALIDPARMS;

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

//ÄÄÄ Prepare texture
    release();

    handle = ivory_halloc(sizeof(VngoTexture) + (bm->width*bm->height));
    if (!handle)
    {
        return ESCH_ERR_NOMEMORY;
    }

    ptr = (VngoTexture*)ivory_hlock(handle);
    if (!ptr)
    {
        ivory_hfree(&handle);
        handle=0;
        return ESCH_ERR_LOCKFAILED;
    }

    flags = ESCH_TXT_LOCKED | ESCH_TXT_OWNSDATA;

    //ÄÄÄ Create texture from input
    ptr->VngoTexture::VngoTexture(bm->width,
                                  bm->height,
                                  (byte*)ptr + sizeof(VngoTexture),
                                  VNGO_TEXTURE_8BIT
                                  | ((trans) ? VNGO_TEXTURE_TRANSPARENT : 0),
                                  pal);

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

    if (ptr->convert(bm,pal) != VNGO_NO_ERROR)
        return ESCH_ERR_NOTSUPPORTED;

    if (!locked)
        bm->unlock();

//ÄÄÄ Return OK
    unlock();

    return ESCH_ERR_NONE;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  I/O Routines  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschStaticTexture - load                                                 ³
//                                                                          ³
// Loads the data for the texture from an IFF file.                         ³
//                                                                          ³
// The IFF version assumes that the IFF is open and pointing at the proper  ³
// chunk.  If a 'tname' is given and the name doesn't match that in the     ³
// form, an error is returned.                                              ³
//                                                                          ³
// If given an animated texture to load, it will load the first frame.      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschStaticTexture::load(XFParseIFF *iff, const char *tname,
                                         dword ctrlfl, VngoPal *pal)
{
    assertMyth("EschStaticTexture::load needs iff pointer",
               iff);

    release();

//ÄÄ Verify correct form name
    if (iff->chunkid != iff->makeid('F','O','R','M')
        || (iff->formid != iff->makeid('E','M','T','L')
            && iff->formid != iff->makeid('E','M','T','1')))
        return ESCH_ERR_NOTFOUND;

//ÄÄ Enter FORM, find header, verify name if any.
    iff->enterform();

    if (iff->seekchunk(iff->makeid('M','H','D','R'))
        || iff->chunkSize != sizeof(EschFileMtlMHDR))
    {
        iff->leaveform();
        return ESCH_ERR_INVALIDDATA;
    }

    EschFileMtlMHDR header;

    if (iff->read(&header))
    {
        iff->leaveform();
        return ESCH_ERR_FILEERROR;
    }

    if (tname && strncmp(tname,header.name,ESCH_MAX_NAME))
    {
        iff->leaveform();
        return ESCH_ERR_NOTFOUND;
    }

//ÄÄ Verify header
    if (header.nframes < 1
        || (header.compress != ESCH_MTL_COMPRESS_NONE
            && header.compress != ESCH_MTL_COMPRESS_RLE))
    {
        iff->leaveform();
        return ESCH_ERR_NOTSUPPORTED;
    }

    switch (header.type)
    {
        case ESCH_MTL_TYPE_8BIT:
        case ESCH_MTL_TYPE_8BIT_TRANSP:
            break;
        case ESCH_MTL_TYPE_24BIT:
        case ESCH_MTL_TYPE_32BIT:
            if (!pal)
            {
                iff->leaveform();
                return ESCH_ERR_INVALIDPARMS;
            }
            break;
        default:
            iff->leaveform();
            return ESCH_ERR_NOTSUPPORTED;
    }

//ÄÄ Found, so load
    flags = ESCH_TXT_OWNSDATA;

    if (iff->seekchunk(iff->makeid('B','O','D','Y'))
        || !iff->chunkSize)
    {
        iff->leaveform();
        return ESCH_ERR_INVALIDDATA;
    }

//ÄÄ Allocate memory
    handle = ivory_halloc(sizeof(VngoTexture) + (header.xsize*header.ysize));
    if (!handle)
    {
        iff->leaveform();
        return ESCH_ERR_NOMEMORY;
    }

    ptr = (VngoTexture*)ivory_hlock(handle);
    if (!ptr)
    {
        ivory_hfree(&handle);
        iff->leaveform();
        return ESCH_ERR_LOCKFAILED;
    }

    flags = ESCH_TXT_LOCKED | ESCH_TXT_OWNSDATA | header.flags;

//ÄÄÄ Create texture from body chunk
    dword tflags = VNGO_TEXTURE_8BIT;

    switch (header.type)
    {
        case ESCH_MTL_TYPE_8BIT_TRANSP:
        case ESCH_MTL_TYPE_32BIT:
            tflags |= VNGO_TEXTURE_TRANSPARENT;
            break;
    }

    ptr->VngoTexture::VngoTexture(header.xsize,
                                  header.ysize,
                                  (byte*)ptr + sizeof(VngoTexture),
                                  tflags,pal);

    esch_error_codes err=load_body(iff,header,pal);
    if (err)
    {
        iff->leaveform();
        return err;
    }

    unlock();

//ÄÄÄ Handle sharing
    if (ctrlfl & ESCH_TXTLD_SHARE)
    {
        if (!cache_register(header.name, handle,
                            ESCH_TXTT_STATIC, header.flags,
                            header.xsize, header.ysize, 1,
                            &name,1))
        {
            flags &= ~ESCH_TXT_OWNSDATA;
            flags |= ESCH_TXT_SHARED;
        }
    }

//ÄÄÄ If owns data, need space for name
    if (flags & ESCH_TXT_OWNSDATA)
    {
        name = new char[ESCH_MAX_NAME];
        if (!name)
        {
            iff->leaveform();
            return ESCH_ERR_NOMEMORY;
        }
        strncpy(name,header.name,ESCH_MAX_NAME);
    }

//ÄÄÄ Return OK
    iff->leaveform();
    return ESCH_ERR_NONE;
}

//°±² End of module - estxtstc.cpp ²±°

