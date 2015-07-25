//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//�����������Copyright�(c)�1994-1997�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//��������������������� Microsoft Windows '95 Version �����������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
//
// Created by Tim Little & Chuck Walbourn
//
// estxtmfr.cpp
//
// EschMultiFrameTexture is an animated bitmap texture with 2 or more frames.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "escher.hpp"
#include "esfile.hpp"

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

extern char EschNoName[];

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschMultiFrameTexture - Constructor                                      �
//���������������������������������������������������������������������������
EschMultiFrameTexture::EschMultiFrameTexture() :
    EschTexture(),
    index(0),
    handle(0),
    time(0)
{
    ttyp = ESCH_TXTT_MFRAME;
    max=0;
}


//�������������������������������������������������������������������������Ŀ
// EschMultiFrameTexture - Destructor                                       �
//���������������������������������������������������������������������������
EschMultiFrameTexture::~EschMultiFrameTexture()
{
    release();
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschMultiFrameTexture - release                                          �
//                                                                          �
// Removes the texture data from memory.                                    �
//���������������������������������������������������������������������������
void EschMultiFrameTexture::release()
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
            ivory_hfree(&handle);
        if (name && name != EschNoName)
            delete [] name;
        name=EschNoName;
    }
    handle=0;
    index=max=0;

    EschTexture::release();
}


//�������������������������������������������������������������������������Ŀ
// EschMultiFrameTexture - lock                                             �
//                                                                          �
// Locks the texture, making the 'ptr' member a valid pointer to a Van Gogh �
// texture object.                                                          �
//���������������������������������������������������������������������������
void EschMultiFrameTexture::lock()
{
    assertMyth("EschMultiFrameTexture::lock needs a valid handle",
               handle);

    if (flags & ESCH_TXT_LOCKED)
        return;

    VngoTexture *data = (VngoTexture*) ivory_hlock(handle);

    assertMyth("EschMultiFrameTexture::lock couldn't lock memory",
               data);

    if (!data)
        return;

    flags |= ESCH_TXT_LOCKED;

    assertMyth("EschMultiFrameTexture::lock expects index less than max",
               index < max);

    ptr = &data[index];

    assert(base == max * sizeof(VngoTexture));
    assert(size == (ulong)(ptr->width*ptr->height));

    ptr->tex = (byte*)data + base + size*index;
}


//�������������������������������������������������������������������������Ŀ
// EschMultiFrameTexture - unlock                                           �
//                                                                          �
// Unlocks the texture, invalidating the 'ptr' member.                      �
//���������������������������������������������������������������������������
void EschMultiFrameTexture::unlock()
{
    if (flags & ESCH_TXT_LOCKED)
    {
        assertMyth("EschMultiFrameTexture::unlock expects ptr to be non-zero",
                   ptr);

        ivory_hunlock(handle);

        flags &= ~ESCH_TXT_LOCKED;

        ptr=0;
    }
}


//�������������������������������������������������������������������������Ŀ
// EschMultiFrameTexture - animate                                          �
//                                                                          �
// Advances the texture to the next frame in the sequence.                  �
//���������������������������������������������������������������������������
void EschMultiFrameTexture::animate()
{
    if (flags & ESCH_MFTXT_TIMEBASED)
    {
        assertMyth("EschMultiFrameTexture::animate needs valid rate/interval",
                   interval > 0 && rate > 0);

        time += interval;
        while (time > rate)
        {
            time -= rate;
            index++;
        }
    }
    else
    {
        index++;
    }
    index %= max;
}



//���������������������������������������������������������������������������
//���������������������������  Utility Routines  ����������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschMultiFrameTexture - create                                           �
//                                                                          �
// Creates a texture from an array of (appropriate) XFile bitmaps.          �
//���������������������������������������������������������������������������
esch_error_codes EschMultiFrameTexture::create(ushort n, XFBitmap *bms, int trans)
{
    ushort  i;

//��� Verify valid input
    if (n < 2 || !bms)
        return ESCH_ERR_INVALIDPARMS;

    for(i=0; i < n; i++)
    {
        const XFBitmap *bm = &bms[i];

        if (bm->bpp != 1)
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

        if (i)
        {
            if (bm->width != bms[0].width
                || bm->height != bms[0].height)
                return ESCH_ERR_INVALIDSIZE;
        }
    }

//��� Prepare texture
    release();

    max = n;
    set_size(bms[0].width,bms[0].height);

//��� Allocate memory
    handle = ivory_halloc( base + size*n );
    if (!handle)
        return ESCH_ERR_NOMEMORY;

    VngoTexture *data = (VngoTexture*)ivory_hlock(handle);
    if (!data)
    {
        ivory_hfree(&handle);
        return ESCH_ERR_LOCKFAILED;
    }

    flags = ESCH_TXT_LOCKED | ESCH_TXT_OWNSDATA;

//��� Create texture from input
    for(i=0; i < n; i++)
    {
        ptr = &data[i];
        XFBitmap *bm = &bms[i];

        ptr->VngoTexture::VngoTexture(bm->width,
                                      bm->height,
                                      (byte*)data + base + size*i,
                                      VNGO_TEXTURE_8BIT
                                      | ((trans) ? VNGO_TEXTURE_TRANSPARENT : 0));

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

        memcpy(ptr->tex,bm->data,size);

        if (!locked)
            bm->unlock();
    }

//��� Return OK
    unlock();

    return ESCH_ERR_NONE;
}



//���������������������������������������������������������������������������
//�����������������������������  I/O Routines  ������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschMultiFrameTexture - load                                             �
//                                                                          �
// Loads the data for the texture from an IFF file.                         �
//                                                                          �
// The IFF version assumes that the IFF is open and pointing at the proper  �
// chunk.  If a 'tname' is given and the name doesn't match that in the     �
// form, an error is returned.                                              �
//���������������������������������������������������������������������������
esch_error_codes EschMultiFrameTexture::load(XFParseIFF *iff,
                                             const char *tname,
                                             dword ctrlfl, 
                                             VngoPal *pal)
{
    assertMyth("EschMultiFrameTexture::load needs iff pointer",
               iff);

    release();

//�� Verify correct form name
    if (iff->chunkid != iff->makeid('F','O','R','M')
        || iff->formid != iff->makeid('E','M','T','1'))
        return ESCH_ERR_NOTFOUND;

//�� Enter FORM, find header, verify name if any.
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

//�� Verify header
    if (header.nframes < 2
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

//�� Found, so load
    flags = ESCH_TXT_OWNSDATA;

    max = header.nframes;

    set_size(header.xsize,header.ysize);

//�� Allocate memory
    handle = ivory_halloc( base + size*header.nframes );
    if (!handle)
    {
        iff->leaveform();
        return ESCH_ERR_NOMEMORY;
    }

    VngoTexture *data = (VngoTexture*)ivory_hlock(handle);
    if (!data)
    {
        ivory_hfree(&handle);
        iff->leaveform();
        return ESCH_ERR_LOCKFAILED;
    }

    flags = ESCH_TXT_LOCKED | ESCH_TXT_OWNSDATA | header.flags;

//��� Create texture from body chunks
    for(ushort i=0; i < header.nframes; i++)
    {
        ptr = &data[i];

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
                                      (byte*)data + base + size*i,
                                      tflags);

        if (iff->seekchunk(iff->makeid('B','O','D','Y'))
            || !iff->chunkSize)
        {
            iff->leaveform();
            return ESCH_ERR_INVALIDDATA;
        }
        
        esch_error_codes err=load_body(iff,header,pal);
        if (err)
        {
            iff->leaveform();
            return err;
        }
    }

    unlock();

//��� Handle sharing
    if (ctrlfl & ESCH_TXTLD_SHARE)
    {
        if (!cache_register(header.name, handle,
                            ESCH_TXTT_MFRAME, header.flags,
                            header.xsize, header.ysize, max,
                            &name,1))
        {
            flags &= ~ESCH_TXT_OWNSDATA;
            flags |= ESCH_TXT_SHARED;
        }
    }

//��� If owns data, need space for name
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

//��� Return OK
    iff->leaveform();
    return ESCH_ERR_NONE;
}

//��� End of module - estxtmfr.cpp ���
