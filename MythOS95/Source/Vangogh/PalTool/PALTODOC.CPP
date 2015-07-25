//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//        Microsoft Windows 95/98/NT Version                 | / \   .  |
//                                                           |_|_|_._._.|
//                                                           |.-.-.-.-..|
//                                                          %\__________/%
//                                                           %          %
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
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
// Created by Dan Higdon & Chuck Walbourn
//
// paltodoc.cpp
//
// PalTool document class.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "stdafx.h"
#include "paltool.h"
#include "dialog.h"
#include "paltodoc.h"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

IMPLEMENT_DYNCREATE(CPalToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CPalToolDoc, CDocument)
        //{{AFX_MSG_MAP(CPalToolDoc)
        ON_COMMAND(IDM_FILE_IMPORT, OnFileImport)
        //}}AFX_MSG_MAP
        ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
        ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
END_MESSAGE_MAP()

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°° Constructor/Destructor °°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
CPalToolDoc::CPalToolDoc():
        base_pal (0),
        curve_mode (LINEAR)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
CPalToolDoc::~CPalToolDoc()
{
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Diagnostics °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#ifdef _DEBUG
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - AssertValid
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::AssertValid() const
{
        CDocument::AssertValid();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - Dump
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::Dump(CDumpContext& dc) const
{
        CDocument::Dump(dc);
}
#endif //_DEBUG



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Operations °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - DeleteContents
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::DeleteContents()
{
    if (base_pal)
    {
        delete base_pal;
        base_pal=0;
    }

    memset(name,0,sizeof(name));
    memset(desc,0,sizeof(desc));
    memset(auth,0,sizeof(auth));
    memset(copy,0,sizeof(copy));

        CDocument::DeleteContents();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - Serialize
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::Serialize(CArchive& ar)
{
    int         i;
    dword       id;
        CXFile          f (ar.GetFile ());
        XFParseIFF      iff (&f);
        iff.begin ();

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Saving
        if (ar.IsStoring ())
        {
        int err;

        assert(base_pal != 0);
        VngoShadePal8   *tpal = (VngoShadePal8 *)base_pal->shd_pal;
        assert(tpal != 0);

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Create a VPAL form
        err=iff.newform(iff.makeid('V','P','A','L'));
        if (err)
            goto save_error_exit;

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Name
        err=iff.write(iff.makeid('n','a','m','e'),
                      name,16);
        if (err)
            goto save_error_exit;

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Description
        if (*desc)
        {
            err=iff.write(iff.makeid('D','E','S','C'),
                          desc,strlen(desc));
            if (err)
                goto save_error_exit;
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Author
        if (*auth)
        {
            err=iff.write(iff.makeid('A','U','T','H'),
                          auth,strlen(auth));

            if (err)
                goto save_error_exit;
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Copyright
        if (*copy)
        {
            err=iff.write(iff.makeid('(','C',')',' '),
                          copy,strlen(copy));
            if (err)
                goto save_error_exit;
        }

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Shade Palette
        err = iff.newform (iff.makeid('s','h','d','P'));
        if (err)
            goto save_error_exit;

        VngoShadePal::HDR hdr;
        hdr.type = VNGO_8BIT;
        hdr.num_levels = tpal->num_shd_lvl;
        hdr.level_bits = tpal->num_shd_lvl_bits;
        hdr.mid_point  = tpal->mid_point;

        err = iff.write(iff.makeid ('H','D','R',' '), &hdr, sizeof(hdr));
        if (err)
        {
            iff.leaveform();
            goto save_error_exit;
        }

        id = iff.makeid('s','h','d','L');
        for (i=0; i < VNGO_PAL_SIZE;i++)
        {
            err = iff.write (id, &(*tpal)[i], tpal->num_shd_lvl * sizeof (byte));
            if (err)
            {
                iff.leaveform();
                goto save_error_exit;
            }
        }

        iff.leaveform();

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Hardware Palette
        err = iff.write(iff.makeid('h','w','d','P'),
                        &((VngoPal8 *)base_pal)->hw_pal,
                        sizeof(VngoHwPal));
        if (err)
            goto save_error_exit;

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Color Conversion Table
        err = iff.write(iff.makeid('c','n','v','t'),
                        &((VngoPal8 *)base_pal)->convert,
                        sizeof(VngoClrConvert));
        if (err)
            goto save_error_exit;

        //ÄÄ Return OK
        iff.leaveform();
        return;

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Save Error
        // Handle error return during save
save_error_exit: ;

        iff.leaveform();

        char    str[512];

        sprintf(str,"Error 0x%x saving file.",err);

        MessageBox(NULL,
                   str,"Palette Tool",MB_OK | MB_ICONEXCLAMATION);

        AfxThrowArchiveException(CArchiveException::generic);
        return;
        }
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Loading
        else
        {
        int err;
        int shade_found=0;
        int hw_found=0;
        int cnvrt_found=0;

        strcpy(name,"Default");

        if (!base_pal)
        {
            base_pal = new VngoPal8;
            assert(base_pal != 0);
                base_pal->shd_pal = new VngoShadePal8 (32);
            base_pal->flags |= VNGO_MYMEM_SHADE;
        }
        assert(base_pal->shd_pal != 0);

        for(;;)
        {
            if (iff.next() != XF_ERR_NONE)
            {
                AfxThrowArchiveException(CArchiveException::endOfFile);
                return;
             }

            if (iff.chunkid != iff.makeid('F','O','R','M')
                || iff.formid != iff.makeid('V','P','A','L'))
                continue;

            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Found an VPAL form

            iff.enterform();

            //ÄÄ Scan and load chunks in form
            while (iff.next() == XF_ERR_NONE)
            {
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Name
                if (iff.chunkid == iff.makeid('n','a','m','e'))
                {
                    if (iff.chunkSize != 16)
                    {
                        err=XF_ERR_CHUNKNOTFOUND;
                        goto load_error_exit;
                    }

                    if (iff.read(name))
                    {
                        AfxThrowArchiveException(CArchiveException::generic);
                        return;
                    }
                }

                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Description
                if (iff.chunkid == iff.makeid('D','E','S','C')
                    && iff.chunkSize < 256)
                {
                    if (iff.read(desc))
                    {
                        AfxThrowArchiveException(CArchiveException::generic);
                        return;
                    }
                }
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Author
                else if (iff.chunkid == iff.makeid('A','U','T','H')
                         && iff.chunkSize < 256)
                {
                    if (iff.read(auth))
                    {
                        AfxThrowArchiveException(CArchiveException::generic);
                        return;
                    }
                }
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Copyright
                else if (iff.chunkid == iff.makeid('(','C',')',' ')
                          && iff.chunkSize < 256)
                {
                    if (iff.read(copy))
                    {
                        AfxThrowArchiveException(CArchiveException::generic);
                        return;
                    }
                }
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Shade Palette
                else if (iff.chunkid == iff.makeid('F','O','R','M')
                         && iff.formid == iff.makeid('s','h','d','P'))
                {
                    VngoShadePal8   *tpal = (VngoShadePal8 *)base_pal->shd_pal;

                    err = iff.enterform();
                    if (err)
                    {
                        iff.leaveform();
                        goto load_error_exit;
                    }

                    VngoShadePal::HDR hdr;
                    err = iff.seekchunk (iff.makeid ('H','D','R',' '));
                    if (err)
                    {
                        iff.leaveform();
                        goto load_error_exit;
                    }

                    if (sizeof (hdr) != iff.chunkSize)
                    {
                        err=XF_ERR_CHUNKNOTFOUND;
                        iff.leaveform();
                        goto load_error_exit;
                    }

                    err = iff.read (&hdr);
                    if (err)
                    {
                        iff.leaveform();
                        goto load_error_exit;
                    }

                    if (hdr.type != VNGO_8BIT)
                    {
                        err=XF_ERR_CHUNKNOTFOUND;
                        iff.leaveform();
                        goto load_error_exit;
                    }

                    tpal->num_shd_lvl = hdr.num_levels;
                    tpal->num_shd_lvl_bits = hdr.level_bits;
                    tpal->mid_point = hdr.mid_point;

                    id = iff.makeid('s','h','d','L');
                    for (i=0; i < VNGO_PAL_SIZE; i++)
                    {
                        err = iff.seekchunk (id);
                        if (err)
                        {
                            iff.leaveform();
                            goto load_error_exit;
                        }

                        if (tpal->num_shd_lvl * sizeof (byte) != iff.chunkSize)
                        {
                            err=XF_ERR_CHUNKNOTFOUND;
                            iff.leaveform();
                            goto load_error_exit;
                        }

                        err = iff.read (&(*tpal)[i]);
                        if (err)
                        {
                            iff.leaveform();
                            goto load_error_exit;
                        }
                    }
                    iff.leaveform();

                    shade_found=1;
                }
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Hardware Palette
                else if (iff.chunkid == iff.makeid('h','w','d','P'))
                {
                    if (sizeof (VngoHwPal) != iff.chunkSize)
                    {
                        err=XF_ERR_CHUNKNOTFOUND;
                        goto load_error_exit;
                    }

                    err = iff.read(&((VngoPal8 *)base_pal)->hw_pal);
                    if (err)
                        goto load_error_exit;

                    hw_found=1;
                }
                //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Color Conversion Table
                else if (iff.chunkid == iff.makeid('c','n','v','t'))
                {
                    if (sizeof (VngoClrConvert) != iff.chunkSize)
                    {
                        err=XF_ERR_CHUNKNOTFOUND;
                        goto load_error_exit;
                    }

                    err = iff.read(&((VngoPal8 *)base_pal)->convert);
                    if (err)
                        goto load_error_exit;

                    cnvrt_found=1;
                }
            }

            iff.leaveform();

            if (!shade_found
                || !hw_found
                || !cnvrt_found)
            {
                MessageBox(NULL,
                           "Needed data missing",
                           "Palette Tool",MB_OK | MB_ICONEXCLAMATION);

                AfxThrowArchiveException(CArchiveException::generic);
            }

            //ÄÄ Return OK
            return;

            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Load Error
            // Handle error return during load, must free partial data
    load_error_exit: ;

            iff.leaveform();

            char    str[512];

            sprintf(str,"Error 0x%x loading file.",(int)err);

            MessageBox(NULL,
                       str,"Palette Tool",MB_OK | MB_ICONEXCLAMATION);

            AfxThrowArchiveException(CArchiveException::generic);
            return;
        }
        }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                             ±±± Protected ±±±
// CPalToolDoc - gen_rampHLS
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::gen_rampHLS(VngoColor24bit base, VngoColor24bit *colors, int steps)
{
    VngoColorHLS    hlst = base;

    Flx16 step = hlst.l / Flx16(steps);

    for(int i=steps-2; i >= 0; i--)
    {
        hlst.l -= step;
        colors[i] = hlst;
    }
    colors[steps-1] = base;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                             ±±± Protected ±±±
// CPalToolDoc - gen_rampRGB
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::gen_rampRGB(VngoColor24bit base, VngoColor24bit *colors, int steps)
{
    Flx16 r = Flx16(base.r);
    Flx16 g = Flx16(base.g);
    Flx16 b = Flx16(base.b);

    Flx16 stepr = r / Flx16(steps);
    Flx16 stepg = g / Flx16(steps);
    Flx16 stepb = b / Flx16(steps);

    for(int i=steps-2; i >= 0; i--)
    {
        r -= stepr;
        g -= stepg;
        b -= stepb;
        colors[i] = VngoColor24bit((byte)(long)r,(byte)(long)g,(byte)(long)b);
    }

    colors[steps-1] = base;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - Generate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::Generate (genpal_type typ)
{
    VngoColor24bit  pclrs[256];
    int             r,g,b,i,j;
    Flx16           d6;
    Flx16           d255;

    assert(base_pal != 0);

    d255 = 255;

    switch (typ)
    {
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
        // Original color ramp
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
        case PAL_ORIGGEN:
            d6 = d255 / (Flx16)6;

            i=0;
            for (r = 0; r < 6; r++)
            {
                for (g = 0; g < 6; g++)
                {
                    for ( b = 0; b < 6; b++,i++)
                    {
                        pclrs[i].r = (byte)((long)((Flx16)r * d6));
                        pclrs[i].g = (byte)((long)((Flx16)g * d6));
                        pclrs[i].b = (byte)((long)((Flx16)b * d6));
                    }
                }
            }

            for (j=0;j < 24;j++,i++)
            {
                pclrs[i].r = (byte)((long)(j * 10)+8);
                pclrs[i].g = (byte)((long)(j * 10)+8);
                pclrs[i].b = (byte)((long)(j * 10)+8);
            }

            for (r = 0;r < 5;r++,i++)
            {
                pclrs[i].r = (byte)((long)((Flx16)r * d6)+21);
                pclrs[i].g = (byte)0;
                pclrs[i].b = (byte)0;
            }
            for (g = 0;g < 5;g++,i++)
            {
                pclrs[i].r = (byte)0;
                pclrs[i].g = (byte)((long)((Flx16)g * d6)+21);
                pclrs[i].b = (byte)0;
            }
            for (b = 0;b < 5;b++,i++)
            {
                pclrs[i].r = (byte)0;
                pclrs[i].g = (byte)0;
                pclrs[i].b = (byte)((long)((Flx16)b * d6)+21);
            }

            for (;i<256;i++)
            {
                pclrs[i].r = 0;
                pclrs[i].g = 0;
                pclrs[i].b = 0;
            }
            assert (i <= 256);
            break;
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
        // General color palette
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
        case PAL_GEN:
            i=0;
            for (r=0;r < 16;r++)
            {
                pclrs[i].r = (byte)(r << 4);
                pclrs[i].g = 0;
                pclrs[i].b = 0;
                i++;
            }
            for (g=0;g < 16;g++)
            {
                pclrs[i].r = 0;
                pclrs[i].g = (byte)(g << 4);
                pclrs[i].b = 0;
                i++;
            }
            for (b=0;b < 16;b++)
            {
                pclrs[i].r = 0;
                pclrs[i].g = 0;
                pclrs[i].b = (byte)(b << 4);
                i++;
            }
            for (r=0,g=0,b=0;r < 16;r++,g++,b++)
            {
                pclrs[i].r = (byte)(r << 4);
                pclrs[i].g = (byte)(g << 4);
                pclrs[i].b = (byte)(b << 4);
                i++;
            }
            for (r=0,g=0,b=0;r < 16;r++,g++)
            {
                pclrs[i].r = (byte)(r << 4);
                pclrs[i].g = (byte)(g << 4);
                pclrs[i].b = (byte)(b << 4);
                i++;
            }
            for (r=0,g=0,b=0;r < 16;r++,b++)
            {
                pclrs[i].r = (byte)(r << 4);
                pclrs[i].g = (byte)(g << 4);
                pclrs[i].b = (byte)(b << 4);
                i++;
            }
            for (r=0,g=0,b=0;g < 16;g++,b++)
            {
                pclrs[i].r = (byte)(r << 4);
                pclrs[i].g = (byte)(g << 4);
                pclrs[i].b = (byte)(b << 4);
                i++;
            }
            for (r=0,g=0,b=0;b < 16;b++)
            {
                pclrs[i].r = (byte)(r << 4);
                pclrs[i].g = (byte)(g << 4);
                pclrs[i].b = (byte)(b << 4);
                i++;
                if ((b%3))
                {
                    r++;
                    g++;
                }
            }
            for (r=0,g=0,b=0;g < 16;g++)
            {
                pclrs[i].r = (byte)(r << 4);
                pclrs[i].g = (byte)(g << 4);
                pclrs[i].b = (byte)(b << 4);
                i++;
                if ((g%3))
                {
                    r++;
                    b++;
                }
            }
            for (r=0,g=0,b=0;r < 16;r++)
            {
                pclrs[i].r = (byte)(r << 4);
                pclrs[i].g = (byte)(g << 4);
                pclrs[i].b = (byte)(b << 4);
                i++;
                if ((r%3))
                {
                    b++;
                    g++;
                }
            }
            for (r=0,g=0,b=0;b < 16;b++)
            {
                pclrs[i].r = (byte)(r << 4);
                pclrs[i].g = (byte)(g << 4);
                pclrs[i].b = (byte)(b << 4);
                i++;
                if (!(b%3))
                {
                    r++;
                    g++;
                }
            }
            for (r=0,g=0,b=0;g < 16;g++)
            {
                pclrs[i].r = (byte)(r << 4);
                pclrs[i].g = (byte)(g << 4);
                pclrs[i].b = (byte)(b << 4);
                i++;
                if (!(g%3))
                {
                    r++;
                    b++;
                }
            }
            for (r=0,g=0,b=0;r < 16;r++)
            {
                pclrs[i].r = (byte)(r << 4);
                pclrs[i].g = (byte)(g << 4);
                pclrs[i].b = (byte)(b << 4);
                i++;
                if (!(r%3))
                {
                    b++;
                    g++;
                }
            }
            for (r=0,g=0,b=0;b < 16;b++,g++)
            {
                pclrs[i].r = (byte)(r << 4);
                pclrs[i].g = (byte)(g << 4);
                pclrs[i].b = (byte)(b << 4);
                i++;
                if ((b%3))
                {
                    r++;
                }
            }
            assert (i <= 256);
            for (r=0,g=0,b=0;g < 16;g++,r++)
            {
                pclrs[i].r = (byte)(r << 4);
                pclrs[i].g = (byte)(g << 4);
                pclrs[i].b = (byte)(b << 4);
                i++;
                if ((g%3))
                {
                    b++;
                }
            }
            assert (i <= 256);
            for (r=0,g=0,b=0;r < 16;r++,b++)
            {
                pclrs[i].r = (byte)(r << 4);
                pclrs[i].g = (byte)(g << 4);
                pclrs[i].b = (byte)(b << 4);
                i++;
                if ((r%3))
                {
                    g++;
                }
            }
            assert (i <= 256);

            for (;i<256;i++)
            {
                pclrs[i].r = 0;
                pclrs[i].g = 0;
                pclrs[i].b = 0;
            }

            assert (i <= 256);
            break;
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
        // Grey ramp
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
        case PAL_GREY:
            for (r=0;r < 256;r+=4)
            {
                pclrs[(r>>2)].r = (byte)r;
                pclrs[(r>>2)].g = (byte)r;
                pclrs[(r>>2)].b = (byte)r;
                pclrs[(r>>2)+64].r = (byte)(r+1);
                pclrs[(r>>2)+64].g = (byte)r;
                pclrs[(r>>2)+64].b = (byte)r;
                pclrs[(r>>2)+128].r = (byte)r;
                pclrs[(r>>2)+128].g = (byte)(r+1);
                pclrs[(r>>2)+128].b = (byte)r;
                pclrs[(r>>2)+192].r = (byte)r;
                pclrs[(r>>2)+192].g = (byte)r;
                pclrs[(r>>2)+192].b = (byte)(r+1);
            }
            break;
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
        // 3-3-2 palette
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
        case PAL_332:
            for (r=0;r < 8;r++)
            {
                for(g=0;g < 8;g++)
                {
                    for(b=0;b < 4;b++)
                    {
                        pclrs[(r<<5)+(g<<2)+b].r=(byte)(r<<5);
                        pclrs[(r<<5)+(g<<2)+b].g=(byte)(g<<5);
                        pclrs[(r<<5)+(g<<2)+b].b=(byte)(b<<6);
                    }
                }
            }
            break;
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
        // Red,Green,Blue,Gray ramps
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
        case PAL_RGBG:
            i=0;
            for (r=0; r < 256;r+=4)
            {
                pclrs[i].r = (byte)r;
                pclrs[i].g = (byte)0;
                pclrs[i].b = (byte)0;
                ++i;
            }
            for (r=0; r < 256;r+=4)
            {
                pclrs[i].r = (byte)0;
                pclrs[i].g = (byte)r;
                pclrs[i].b = (byte)0;
                ++i;
            }
            for (r=0; r < 256;r+=4)
            {
                pclrs[i].r = (byte)0;
                pclrs[i].g = (byte)0;
                pclrs[i].b = (byte)r;
                ++i;
            }
            for (r=0; r < 256;r+=4)
            {
                pclrs[i].r = (byte)r;
                pclrs[i].g = (byte)r;
                pclrs[i].b = (byte)r;
                ++i;
            }
            for (;i<256;i++)
            {
                pclrs[i].r = 0;
                pclrs[i].g = 0;
                pclrs[i].b = 0;
            }
            assert (i <= 256);
            break;
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
        // Special purpose palette 1:  Contour map colors
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
        case PAL_SPC1:
            i=0;
            pclrs[i].r = 0;
            pclrs[i].g = 0;
            pclrs[i].b = 0;
            i++;

            gen_rampHLS(VngoColor24bit(128, 0, 255),&pclrs[i],19);
            i += 19;

            gen_rampHLS(VngoColor24bit(128, 0, 254),&pclrs[i],19);
            i += 19;

            gen_rampHLS(VngoColor24bit(0, 0, 255),&pclrs[i],19);
            i += 19;

            gen_rampHLS(VngoColor24bit(0, 100, 255),&pclrs[i],19);
            i += 19;

            gen_rampRGB(VngoColor24bit(255, 255, 255),&pclrs[i],26);
            i += 26;

            gen_rampHLS(VngoColor24bit(0, 120, 0),&pclrs[i],19);
            i += 19;

            gen_rampHLS(VngoColor24bit(0, 185, 0),&pclrs[i],19);
            i += 19;

            gen_rampRGB(VngoColor24bit(255, 255, 0),&pclrs[i],19);
            i += 19;

            gen_rampHLS(VngoColor24bit(254, 185, 0),&pclrs[i],19);
            i += 19;

            gen_rampHLS(VngoColor24bit(255, 128, 0),&pclrs[i],19);
            i += 19;

            gen_rampHLS(VngoColor24bit(178, 122, 0),&pclrs[i],19);
            i += 19;

            gen_rampHLS(VngoColor24bit(107, 68, 0),&pclrs[i],19);
            i += 19;

            gen_rampRGB(VngoColor24bit(255, 0, 0),&pclrs[i],19);
            i += 19;

            pclrs[i].r = 255;
            pclrs[i].g = 255;
            pclrs[i].b = 255;
            i++;

            assert (i <= 256);
            break;

        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
        // Otherwise, set to all black
        //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
        default:
            for (i=0;i<256;i++)
            {
                pclrs[i].r = 0;
                pclrs[i].g = 0;
                pclrs[i].b = 0;
            }
            break;
    }

    ((VngoPal8 *)base_pal)->set_hwpal(pclrs,256);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - CalcConvert
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::CalcConvert ()
{
    assert(base_pal != 0);

    ((VngoPal8 *)base_pal)->convert.init (base_pal, VNGO_PAL_CALC);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                             ±±± Protected ±±±
// CPalToolDoc - use_color8
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::use_colors8 (VngoColor24bit *colors, int steps, int color_index)
{
    VngoShadePal8 &tp = *(VngoShadePal8 *)base_pal->shd_pal;

        for (int i = 0; i < steps; i++)
        {
            tp[color_index].shl[i] = (byte)base_pal->get_index (colors[i]);
        }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                             ±±± Protected ±±±
// CPalToolDoc - use_colors15
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::use_colors15 (VngoColor24bit *colors, int steps, int color_index)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                             ±±± Protected ±±±
// CPalToolDoc - use_colors16
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::use_colors16 (VngoColor24bit *colors, int steps, int color_index)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                             ±±± Protected ±±±
// CPalToolDoc - use_colors24
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::use_colors24 (VngoColor24bit *colors, int steps, int color_index)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                             ±±± Protected ±±±
// CPalToolDoc - calc_linear_colors
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::calc_linear_colors (VngoColor24bit *colors, int steps,
                                                                          VngoColor24bit color, int break_point)
{
    VngoColorHLS    hlst;
    Flx16           t1;
    Flx16           base,mean,step,step2,max;

    hlst = color;
    mean = hlst.l;
    base = hlst.l * (Flx16)0.2;

    t1 = hlst.l - base;
    step = t1 / Flx16 (break_point);

        break_point--;  // Convert to 0 based value

    for (int i = break_point-1; i >= 0; i--)
    {
        hlst.l -= step;
        colors[i] = hlst;
    }

    colors[break_point] = color;

    hlst.l = mean;

    t1 = (Flx16)1 - hlst.l;
    max = t1 * (Flx16) 0.75;
    step = max / Flx16 (steps - break_point);

    for (i = break_point + 1; i < steps; i++)
    {
        hlst.l += step;
        colors[i] = hlst.to_RGB();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                             ±±± Protected ±±±
// CPalToolDoc - calc_bez_colors
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::calc_bez_colors (VngoColor24bit *colors, int steps,
                                                                   VngoColor24bit color, int break_point)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                             ±±± Protected ±±±
// CPalToolDoc - calc_quad_colors
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::calc_quad_colors (VngoColor24bit *colors, int steps,
                                                                        VngoColor24bit color, int break_point)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - CalcShades
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::CalcShades ()
{
    int i;
        const int shade_count = 32;
        VngoColor24bit  shades[shade_count];

    assert(base_pal != 0);

    // If all values are 0,0,0, then don't compute shades
    for(i=0; i < 256; i++)
    {
        VngoColor24bit *c = &((VngoPal8*)base_pal)->hw_pal.p[i];
        if (c->r || c->g || c->b)
            break;
    }

    if (i >= 256)
        return;

    // Determine interpoloation mode
        void (CPalToolDoc:: *calc) (VngoColor24bit *, int, VngoColor24bit, int);

        switch (curve_mode)
        {
        case LINEAR:
            calc = calc_linear_colors;
                    break;
            case BEZIER:
            calc = calc_bez_colors;
                break;
        case QUADRATIC:
            calc = calc_quad_colors;
                    break;
        }

    // Compute for each palette indexl
        for (i = 0; i < 256; i++)
        {
                (this->*calc) (shades, shade_count, base_pal->get_RGB (i), (shade_env_break()+7) >> 3);
                use_colors8 (shades, shade_count, i);
        }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - ImportVGPalette
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int CPalToolDoc::ImportVGPalette (LPCSTR filename)
{
    VngoShadePal8   *tpal = (VngoShadePal8 *)base_pal->shd_pal;
        XFParseIFF  iffp;
        int         err=0;

        // Assert that there is memory allocated to load into.
        assert(base_pal != NULL);
        assert(base_pal->shd_pal != NULL);
//    assert(base_pal->hz_pal != NULL);

        err = iffp.open (filename,XF_OPEN_READ);
        if (err)
                return err;

        err = iffp.seekform (iffp.makeid('V','P','A','L'));
        if (err)
                return err;

        err = iffp.enterform();
        if (err)
                return err;

        // ---- Find and read the shade palette.
        err = iffp.seekchunk (iffp.makeid('s','h','d','P'));
        if (err)
                return err;

        // ---- Read the old shade palette format
        err = iffp.read (&(*tpal)[0]);
        if (err)
                return err;


#if 0
        // ---- Find and read the haze palette.
        err = iffp.seekchunk (iffp.makeid ('h','a','z','P'));
        if (err)
                return err;

        err = iffp.read (base_pal->hz_pal);
        if (err)
                return err;
#endif

        // ---- Find and read the hardware palette.
        err = iffp.seekchunk (iffp.makeid('h','w','d','P'));
        if (err)
                return err;

        err = iffp.read (&((VngoPal8 *)base_pal)->hw_pal);
        if (err)
                return err;

        // ---- Find and read the color conversion table.
        err = iffp.seekchunk (iffp.makeid ('c','n','v','t'));
        if (err)
                return err;

        err = iffp.read (&((VngoPal8 *)base_pal)->convert);
        if (err)
                return err;

        // ---- Clean up and close down.
        err = iffp.leaveform();
        if (err)
                return err;

        err = iffp.close();
        if (err)
                return err;

        // Initialize the palette header
        tpal->num_shd_lvl = 32;
        tpal->num_shd_lvl_bits = 5;
        tpal->mid_point = 192;

        // ---- Since no error occured return zero.
        return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - ImportWindowsPalette
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int CPalToolDoc::ImportWindowsPalette (LPCSTR filename)
{
        return 1;

}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - UIPalette
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::UIPalette(CWnd *parent, UINT ind)
{
    CPaletteDlg dlg(ind, base_pal, parent);

//ÄÄÄ Handle Display
    if (dlg.DoModal() == IDOK)
    {
        //ÄÄÄ Save values and recompute
                CProgressDlg    prog;

                prog.m_pbar.SetRange (0, 2);
                prog.m_pbar.SetPos (0);
                prog.SetWindowText ("Recomputing");
                prog.ShowWindow (SW_SHOW);

                ((VngoPal8 *)base_pal)->set_hwpal ((VngoColor24bit *)dlg.pal, 256);
                prog.m_pbar.SetPos (1);
        CalcConvert();
                prog.m_pbar.SetPos (2);
                CalcShades ();

        SetModifiedFlag();
        UpdateAllViews(NULL);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - UIProperties
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::UIProperties(CWnd *parent, UINT ipage)
{
    assert(base_pal != 0 && base_pal->shd_pal != 0);

//ÄÄÄ General
    CPropertiesDlgA dlga;
    dlga.m_name = name;
    dlga.m_midpoint = base_pal->shd_pal->mid_point;
    dlga.m_slevels = base_pal->shd_pal->num_shd_lvl;
    dlga.m_8bit = TRUE;

//ÄÄÄ Colors
    CPropertiesDlgB dlgb;

//ÄÄÄ Misc
    CPropertiesDlgC dlgc;

    dlgc.m_desc = desc;
    dlgc.m_auth = auth;
    dlgc.m_copy = copy;

//ÄÄÄ Handle Display
    CPropertySheet sh("Properties",parent,ipage);

    sh.AddPage(&dlga);      // General
    sh.AddPage(&dlgb);      // Colors
    sh.AddPage(&dlgc);      // Misc

    if (sh.DoModal() == IDOK)
    {
        //ÄÄÄ Save values from General
        strncpy(name,dlga.m_name,sizeof(name));
        base_pal->shd_pal->mid_point = dlga.m_midpoint;

        //ÄÄÄ Save values from Colors

        //ÄÄÄ Save values from Misc
        memset(desc,0,sizeof(desc));
        strncpy(desc,dlgc.m_desc,255);

        memset(auth,0,sizeof(auth));
        strncpy(auth,dlgc.m_auth,255);

        memset(copy,0,sizeof(copy));
        strncpy(copy,dlgc.m_copy,255);

        CalcShades();
        SetModifiedFlag();
        UpdateAllViews(NULL);
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Message Handlers °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - OnNewDocument
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL CPalToolDoc::OnNewDocument()
{
        if (!CDocument::OnNewDocument())
                return FALSE;

    VngoPal8 *tpal = new VngoPal8;
    if (!tpal)
        return FALSE;

        base_pal = tpal;
        tpal->shd_pal = new VngoShadePal8 (32);
    if (!tpal->shd_pal)
        return FALSE;
    base_pal->flags |= VNGO_MYMEM_SHADE;

        tpal->shd_pal->mid_point = 192;
        Generate (PAL_EMPTY);

    strcpy(name,"Default");
    *desc = 0;
    *auth = 0;
    *copy = 0;

        return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - OnFileImport
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::OnFileImport()
{
        // Import the BMP file.
        CFileDialog     fdlg (TRUE, ".pal", NULL, OFN_HIDEREADONLY | OFN_FILEMUSTEXIST,
"Bitmap Files (*.bmp;*.pcx;*.lbm;*.cel)|*.bmp;*.pcx;*.lbm;*.cel|Palette Files (*.pal)|*.pal|All Files (*.*)|*.*||");

        fdlg.m_ofn.lpstrTitle = "Import Picture's Palette";

        if (fdlg.DoModal() == IDOK)
        {
                CString pathname  = fdlg.GetPathName();
                CString extension = fdlg.GetFileExt();

                if (extension.CompareNoCase ("pal") == 0)
                {
                        // This is either a windows palette or an old-style Vangogh palette.
                        // Let's try the old-style palette first:
                        if (ImportVGPalette (pathname) == 0)
                        {
                                // Successful import
                        }
                        else if (ImportWindowsPalette (pathname) == 0)
                        {
                                // Successful import
                        }
                        else
                        {
                                MessageBox (NULL, fdlg.GetFileTitle() + " has an unrecongnized format.  Aborting import.",
                                                        "Error", MB_OK | MB_ICONEXCLAMATION);
                        }
                }
                else
                {
                        // It must be one of our bitmap formats
                        XFParseBitmap   *bm;

                        if (extension.CompareNoCase ("bmp") == 0)
                        {
                                bm = new XFParseBMP ();
                        }
                        else if (extension.CompareNoCase ("pcx") == 0)
                        {
                                bm = new XFParsePCX ();
                        }
                        else if (extension.CompareNoCase ("lbm") == 0)
                        {
                                bm = new XFParseLBM ();
                        }
                        else if (extension.CompareNoCase ("cel") == 0)
                        {
                                bm = new XFParseCEL ();
                        }
                        else
                        {
                                MessageBox (NULL, "Unable to load file: '" + pathname + "'.  Canceling import.",
                                                        "Error", MB_OK | MB_ICONEXCLAMATION);
                                return;
                        }

                        if (bm->nameread(pathname) != 0 || bm->bm->bpp != 1)
                        {
                                MessageBox (NULL, "File not supported: '" + pathname + "'.  Canceling import.",
                                                        "Error", MB_OK | MB_ICONEXCLAMATION);
                                return;
                        }

                        CProgressDlg    prog;

                        prog.m_pbar.SetRange (0, 2);
                        prog.m_pbar.SetPos (0);
                        prog.SetWindowText ("Computing Import Palette");
                        prog.ShowWindow (SW_SHOW);

                        ((VngoPal8 *)base_pal)->set_hwpal ((VngoColor24bit *)bm->bm->pal, 256);
                        prog.m_pbar.SetPos (1);
            CalcConvert();
                        prog.m_pbar.SetPos (2);
                        CalcShades ();

                        delete bm;
                }

                // Update our internal values, and redisplay everything
                UpdateAllViews (NULL);
        }
}


#if 0
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - OnFileExport
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::OnFileExport()
{
        // Export the palette to some "public" format.
        CFileDialog     fdlg (FALSE, ".pal", NULL, OFN_HIDEREADONLY,
                                                "Windows Palette Files (*.pal)|*.pal||");

        fdlg.m_ofn.lpstrTitle = "Export Palette";

        if (fdlg.DoModal() == IDOK)
        {
                switch (fdlg.m_ofn.nFilterIndex)
                {
                case 0: // User-specified file extension (assume Windows Palette)
                case 1: // Windows Palette Files
                        MessageBox (NULL, "Windows Format export not yet implemented",
                                                "Note", MB_OK | MB_ICONEXCLAMATION);
                        break;

                default:
                        MessageBox (NULL, "Invalid Export Format selected",
                                                "Error", MB_OK | MB_ICONEXCLAMATION);
                        break;
                }
        }
}
#endif

//°±² eof - paltodoc.cpp ²±°
