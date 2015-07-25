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
//                        *** Escher Terrain Editor ***
//
// Chuck Walbourn
//
// eshtdoc.cpp 
//
// Terrain Editor Document class.
//
// The document class owns the terrain height field, surface array, and
// the texture information.  The data may be manipulated or exported into
// an Escher IFF file.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//             
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "stdafx.h"
#include "eshtedit.h"

#include "eshtdoc.h"
#include "eshtview.h"
#include "eshtdlg.h"

#include "esfile.hpp"
#include "dem.h"

#include <math.h>

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc                                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

IMPLEMENT_DYNCREATE(TerrEditDoc, CDocument)

BEGIN_MESSAGE_MAP(TerrEditDoc, CDocument)
	//{{AFX_MSG_MAP(TerrEditDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static int FirstNew=1;                  // Hack to avoid 'New' dialog on startup

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°° Constructor/Destructor °°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - Constructor                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
TerrEditDoc::TerrEditDoc()
{
    width = depth = 0;
    surfratio = 1;
    surfshift = 0;

    hfield=0;
    surfinfo=0;
    surfcolr=0;
    hsurfnorml=0;

    txtNumb=0;

    hpal=0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - Destructor                                                 ³
//                                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
TerrEditDoc::~TerrEditDoc()
{
    DeleteContents();
}


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Operations °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - DeleteContents                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::DeleteContents() 
{
    for(int i=0; i < txtNumb; i++)
    {
        txtName[i].Empty();
        txtFName[i].Empty();
        txtEsch[i].release();
    }
    txtNumb=0;

    memset(name,0,sizeof(name));
    memset(desc,0,sizeof(desc));
    memset(auth,0,sizeof(auth));
    memset(copy,0,sizeof(copy));
    *pfname = 0;

    if (hfield)
    {
        delete [] hfield;
        hfield=0;
    }
    if (surfinfo)
    {
        delete [] surfinfo;
        surfinfo=0;
    }
    if (surfcolr)
    {
        delete [] surfcolr;
        surfcolr=0;
    }

    if (hsurfnorml)
    {
        ivory_hfree(&hsurfnorml);
    }

    if (hpal)
    {
        DeleteObject(hpal);
        hpal=0;
    }
	
	CDocument::DeleteContents();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - LoadPalette                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL TerrEditDoc::LoadPalette(const char *fname, int doupdate)
{
    int             err;
    VngoPal8        *palptr=&palette;
    VngoPalIFF8     loadpal(palptr);

    palptr->init(0);
    err=loadpal.load(fname);

    if (err)
    {
        char    str[512];

        sprintf(str,"Error #%x loading Van Gogh palette file:\n\n%s",(int)err,fname);
                                                  
        MessageBox(NULL,
                   str,"Error",MB_OK | MB_ICONEXCLAMATION);

        return FALSE;
    }  

    strcpy(pfname,fname);
 
    LOGPALETTE *lpal = (LOGPALETTE *) ivory_alloc(sizeof(LOGPALETTE)
                                                  + 256*sizeof(PALETTEENTRY));

    lpal->palVersion = 0x300;
    lpal->palNumEntries = 256;

    for (int i=0; i < 256; i++)
    {
        lpal->palPalEntry[i].peRed  = palptr->hw_pal.p[i].r;
        lpal->palPalEntry[i].peGreen= palptr->hw_pal.p[i].g;
        lpal->palPalEntry[i].peBlue = palptr->hw_pal.p[i].b;
        lpal->palPalEntry[i].peFlags= PC_NOCOLLAPSE;
    }

    if (hpal)
        DeleteObject(hpal);

    hpal = CreatePalette(lpal);

    ivory_free( (void**)&lpal );

    if (!hpal)
    {
        MessageBox(NULL,
                   "Failed to create a palette from Van Gogh palette file","Error",MB_OK | MB_ICONEXCLAMATION);

        return FALSE;       
    }

    map_surfcolor_to_palette();

    if (txtNumb)
    {
        TerrSurfPrgDlg   dlg;
        dlg.m_pBar.SetRange(0, txtNumb-1);
        dlg.m_pBar.SetPos(0);
        dlg.SetWindowText("Recoloring Texture Maps...");
        dlg.ShowWindow(SW_SHOW);

        for(int i=0; i < txtNumb; i++)
        {
            dlg.m_pBar.SetPos(i);
            load_and_recolor_texture(i,txtFName[i]);
        }
    }

    if (doupdate)
        UpdateAllViews(NULL,HINT_UPDATECOLR,NULL);

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - ImportTerrain                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::ImportTerrain(const char *fname, int losswarn)
{
    ASSERT(width && depth && hfield);

    if (losswarn)
    {
        int i;
        byte *ptr;

        for(i=0, ptr=hfield; i < (width * depth); i++)
        {
            if (*(ptr++))
                break;
        }

        if (i < (width*depth))
        {
            if (MessageBox(NULL,
                           "All current terrain height and normal data will be lost.\n\nDo you wish to continue import?",
                           "Import Terrain Warning", MB_OKCANCEL | MB_ICONEXCLAMATION) == IDCANCEL)
                return;
        }
    }

//ÄÄÄ Import VistaPro DEM File
    if (strstr(fname,".DEM") || strstr(fname,".dem"))
    {
        int                 i;
        int                 x, y, cx, cy;
        int                 iwidth, idepth;
        byte                *dptr;
        ushort              min;
        ushort              *sptr, *data=0;
        XFileDOS            xf;
        struct DEM_HEADER   demh;
    
        //ÄÄÄ Open DEM file for processing.
        if ((i=xf.open(fname,XF_OPEN_READ))!=0)
        {
            char    str[512];

            sprintf(str,"Error #%x opening input terrain file:\n\n%s",(int)i,fname);
                                                  
            MessageBox(NULL,
                       str,"Import Terrain Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        //ÄÄÄ Load header of DEM file
        if (xf.read(&demh,sizeof(struct DEM_HEADER)) != sizeof(struct DEM_HEADER))
        {
            char    str[512];

            sprintf(str,"Error #%x reading header from input terrain file:\n\n%s",(int)i,fname);
                                                  
            MessageBox(NULL,
                       str,"Import Terrain Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        //ÄÄÄ Verify header
        if (strncmp(demh.id,"Vista DEM File",32))
        {
            MessageBox(NULL,
                       "The import file is not a VistaPro DEM file",
                       "Import Terrain Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        //ÄÄÄ Check values in header
        if (demh.compression != 0)
        {
            MessageBox(NULL,
                       "The import file is a compressed VistaPro DEM file, use DECOMP first",
                       "Import Terrain Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        if (demh.header_type != 0 && demh.header_type != 16777216)
        {
            MessageBox(NULL,
                       "The import file contains an unknown series DEM, which is not supported",
                       "Import Terrain Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        //ÄÄÄ Load data from DEM
        if (demh.header_type == 16777216)
        {
            demh.ex_width = ((demh.ex_width & 0xff) << 24) |
                            ((demh.ex_width & 0xff00) << 8) |
                            ((demh.ex_width & 0xff0000) >> 8) |
                            ((demh.ex_width & 0xff000000) >> 24);
            demh.ex_depth = ((demh.ex_depth & 0xff) << 24) |
                            ((demh.ex_depth & 0xff00) << 8) |
                            ((demh.ex_depth & 0xff0000) >> 8) |
                            ((demh.ex_depth & 0xff000000) >> 24);

            if (!demh.ex_width || !demh.ex_depth)
            {
                MessageBox(NULL,
                       "The import file hsa an invalid field size",
                       "Import Terrain Error",MB_OK | MB_ICONEXCLAMATION);
                return;
            }

            if ((demh.ex_width > 65535) || (demh.ex_depth > 65535))
            {
                MessageBox(NULL,
                       "The import file is too large, it MUST be less than 64k by 64k",
                       "Import Terrain Error",MB_OK | MB_ICONEXCLAMATION);
                return;
            }

            iwidth = (ushort)demh.ex_width;
            idepth = (ushort)demh.ex_depth;
        }
        else
        {
            ASSERT(demh.header_type == 0);

            iwidth = 258;
            idepth = 258;
        }

        data = new ushort[iwidth * idepth];
        if (!data)
        {
            MessageBox(NULL,
                 "Failed to allocate enough memory for import",
                 "Import Terrain Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        if (xf.read(data,sizeof(ushort)*iwidth * idepth) != sizeof(ushort)*iwidth * idepth)
        {
            MessageBox(NULL,
                 "Could not load height field from DEM file",
                 "Import Terrain Error",MB_OK | MB_ICONEXCLAMATION);
            delete [] data;
            return;
        }

        // Find minimum value
        for(y=0, min=65535, sptr=data;
            y < idepth; y++)
        {
            for(x=0; x < iwidth; x++)
            {
                if (*sptr < min)
                    min = *sptr;

                sptr++;
            }
        }

        //ÄÄÄ Copy data from DEM

        memset(name,0,sizeof(name));
        strncpy(name,demh.name,ESCH_MAX_NAME-1);
        SetTitle(name);

        memset(desc,0,sizeof(desc));
        strcpy(desc,demh.comment);

        // Clear buffer
        memset(hfield,0,width*depth);

        // Copy data
        for(y=0, cy=0; y < idepth; y++)
        {
            for(x=0, cx=0,
                sptr=data+((depth-1-y)*iwidth), dptr=hfield+(y*width);
                x < iwidth; x++)
            {
                // Perform VistaPro's standard conversion of DEM->PCX
                // (although VistaPro arbitrarily never uses color 0 for
                //  PCX output, so we will not do this so we can represent
                //  height 0)
                *(dptr++) = (byte)(( ((*sptr++) - min + 15) >> 4 ) & 0xff);
                if (++cx >= width)
                    break;
            }

            if (++cy >= depth)
                break;
        }

        //ÄÄÄ Close
        delete [] data;
        xf.close();

        //ÄÄÄ Update application
        ComputeNormals();

        SetModifiedFlag();
        UpdateAllViews(NULL,HINT_UPDATETERR,NULL);

        return;
    }
//ÄÄÄ Import PCX File
    else if (strstr(fname,".PCX") || strstr(fname,".pcx"))
    {
        int         x, y, cx, cy;
        byte        *dptr, *sptr;
        XFParsePCX  pcx;

        //ÄÄÄ Load data from PCX

        if (pcx.nameread(fname))
        {
            char    str[512];

            sprintf(str,"Error #%x opening input terrain file:\n\n%s",(int)pcx.error(),fname);
                                                  
            MessageBox(NULL,
                       str,"Import Terrain Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        //ÄÄÄ Check values in bitmap
        if (pcx.bm->bpp != 1)
        {
            MessageBox(NULL,
                       "PCX terrain files must be have 8-bit color depth",
                       "Import Terrain Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        //ÄÄÄ Copy data from PCX
        memset(hfield,0,width*depth);

        // Copy data
        for(y=0, cy=0; y < pcx.bm->height; y++)
        {
            for(x=0, cx=0,
                sptr=pcx.bm->data+(y*(pcx.bm->width)), dptr=hfield+(y*(width));
                x < pcx.bm->width; x++)
            {
                *(dptr++) = *(sptr++);
                if (++cx >= width)
                    break;
            }

            if (++cy >= depth)
                break;
        }

        //ÄÄÄ Update application
        ComputeNormals();

        SetModifiedFlag();
        UpdateAllViews(NULL,HINT_UPDATETERR,NULL);

        return;
    }

    MessageBox(NULL,
                "Can only import terrain from DEM or PCX files","Error",MB_OK);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - ImportSurface                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::ImportSurface(const char *fname, int losswarn)
{
    int             x, y, cx, cy;
    byte            *sptr;
    dword           *dptr;
    XFParsePCX      pcx;

    ASSERT(width && depth && surfcolr);

    dword surfsize = (width * depth) >> (surfshift*2);  

    if (losswarn)
    {
        dword i;
        dword *ptr;

        for(i=0, ptr=surfcolr; i < surfsize; i++)
        {
            if (*(ptr++))
                break;
        }

        if (i < surfsize)
        {
            if (MessageBox(NULL,
                           "All current terrain surface color data will be lost.\n\nDo you wish to continue import?",
                           "Import Surface Warning", MB_OKCANCEL | MB_ICONEXCLAMATION) == IDCANCEL)
                return;
        }
    }

//ÄÄÄ Load data from PCX

    if (pcx.nameread(fname))
    {
        char    str[512];

        sprintf(str,"Error #%x opening input surface file:\n\n%s",(int)pcx.error(),fname);
                                                
        MessageBox(NULL,
                  str,"Import Surface Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

//ÄÄÄ Check values in bitmap
    if (pcx.bm->bpp != 1)
    {
        MessageBox(NULL,
                  "PCX surface color files must be have 8-bit color depth",
                  "Import Surface Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

//ÄÄÄ Copy data from PCX (converting to RGB)
    memset(surfcolr,0,surfsize*sizeof(dword));

    // Copy data
    for(y=0, cy=0; y < pcx.bm->height;)
    {
        for(x=0,
            cx=0,
            sptr=pcx.bm->data+(y*(pcx.bm->width)),
            dptr=surfcolr+(cy*(width >> surfshift));
            x < pcx.bm->width; )
        {
            *dptr = pcx.bm->pal[*sptr];

            x += (1 << surfshift);
            sptr += (1 << surfshift);

            dptr++;
            if (++cx >= (width >> surfshift))
                break;
        }

        y += (1 << surfshift);
        if (++cy >= (depth >> surfshift))
            break;
    }

    map_surfcolor_to_palette();

//ÄÄÄ Update application
    SetModifiedFlag();
    UpdateAllViews(NULL,HINT_UPDATECOLR,NULL);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - AddTexture                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL TerrEditDoc::AddTexture(const char *name, const char *fname, dword color)
{
    //
    // Assumes name is unique
    //

    if (txtNumb >= 255)
        return FALSE;

    txtNumb++;
    return SetTexture(txtNumb-1,name,fname,color);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - SetTexture                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL TerrEditDoc::SetTexture(int ind, const char *name, const char *fname, dword color)
{
    //
    // Assumes new name is unique
    //
 
    if (ind >= txtNumb)
        return FALSE;

    //
    // Check for change of filename
    //

    if (txtFName[ind].CompareNoCase(fname) != 0)
    {
        load_and_recolor_texture(ind,fname);
    }

    //
    // Set data
    //

    txtName[ind] = name;
    txtColr[ind] = color;
    txtColrIndx[ind] = (byte)palette.get_index((VngoColor24bit)color);

    //
    // Update view
    //

    SetModifiedFlag();
    UpdateAllViews(NULL,HINT_UPDATETXTS | HINT_UPDATECOLR,NULL);

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - DeleteTexture                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::DeleteTexture(int ind)
{
    //
    // Remove texture, renumbering all textures afterwards (an updating surface data)
    //

    if (ind >= txtNumb)
        return;

    //
    // Remove data for current entry
    //

    txtEsch[ind].release();
    txtName[ind].Empty();
    txtFName[ind].Empty();

    //
    // Compact array
    //

    for(int i=ind+1; i < txtNumb; i++)
    {
        txtName[i-1] = txtName[i];
        txtFName[i-1] = txtFName[i];
        txtEsch[i-1] = txtEsch[i];
        txtColr[i-1] = txtColr[i];
        txtColrIndx[i-1] = txtColrIndx[i];
    }
    txtNumb--;

    //
    // Must scan and decrement all references in 'surface' 2D array.
    //

    int             x, y;
    esch_surf_type  *ptr;

    if (!width || !depth || !surfinfo)
        return;

    TerrSurfPrgDlg   dlg;
    dlg.m_pBar.SetRange(0, (depth >> surfshift));
    dlg.m_pBar.SetPos(0);
    dlg.ShowWindow(SW_SHOW);

    for(y=0, ptr=surfinfo; y < (depth >> surfshift); y++)
    {
        dlg.m_pBar.SetPos(y);

        for(x=0; x < (width >> surfshift); x++)
        {
            if (ptr->flags & ESCH_SURF_CINDISTXT)
            {
                if (ptr->cind == ind+1)
                {
                    ptr->cind = (byte)palette.get_index((VngoColor24bit)surfcolr[y*(depth>>surfshift) + x]);
                    ptr->flags &= ~ESCH_SURF_CINDISTXT;
                }
                else if (ptr->cind > ind+1)
                {
                    (ptr->cind)--;
                }
            }

            ptr++;
        }

        dlg.ShowWindow(SW_HIDE);
    }

    //
    // Update view
    //
    
    SetModifiedFlag();
    UpdateAllViews(NULL,HINT_UPDATETXTS | HINT_UPDATECOLR,NULL);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - ExportToIFF                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::ExportToIFF(const char *fname)
{
    dword               status=0;
    XFParseIFF          iff;
    EschFileTerrHDR     header;

    dword surfsize = (width * depth) >> (surfshift*2);

//ÄÄÄ Setup header
    memset(&header,0,sizeof(EschFileTerrHDR));
    strncpy(header.name,name,ESCH_MAX_NAME);
    // flags, compression, na1, na[72] left at 0

    header.width = width;
    header.depth = depth;
    header.surfratio = surfratio;
    header.wscale = wscale;
    header.dscale = dscale;
    header.hscale = hscale;
    header.ntxts = (byte) txtNumb;

    strncpy(header.palname,"Default",16);

//ÄÄÄ Setup file

    // Open output file
    if (iff.create(fname,0))
    {
        char    str[512];

        sprintf(str,"Error #%x while opening output file:\n\n%s",(int)iff.error(),fname);
                                                  
        MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
               str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

    // Create form
    if (iff.newform(iff.makeid('E','T','E','R')))
    {
        char    str[64];

        sprintf(str,"Error #%x while trying to create new form ETER",(int)iff.error());
                                                  
        MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
               str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

    // Write header
    if (iff.write(iff.makeid('H','D','R',' '),&header,sizeof(EschFileTerrHDR)))
    {
        char    str[64];

        sprintf(str,"Error #%x while trying to write header chunk",(int)iff.error());
                                                  
        MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
               str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

    status |= EXPSTAT_HDR;

    // Write description, if any
    if (*desc && iff.write(iff.makeid('D','E','S','C'),desc,strlen(desc)+1))
    {
        char    str[64];

        sprintf(str,"Error #%x while trying to write description chunk",(int)iff.error());
                                                  
        MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
               str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

    // Write author, if any
    if (*auth && iff.write(iff.makeid('A','U','T','H'),auth,strlen(auth)+1))
    {
        char    str[64];

        sprintf(str,"Error #%x while trying to write author chunk",(int)iff.error());
                                                  
        MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
               str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

    // Write copyright, if any
    if (*copy && iff.write(iff.makeid('(','C',')',' '),copy,strlen(copy)+1))
    {
        char    str[64];

        sprintf(str,"Error #%x while trying to write copyright chunk",(int)iff.error());
                                                  
        MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
               str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

    // Write height field
    if (hfield)
    {
        if (iff.write(iff.makeid('H','G','T','S'),hfield,width*depth))
        {
            char    str[64];

            sprintf(str,"Error #%x while trying to write heights chunk",(int)iff.error());
                                                  
            MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                   str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }
        status |= EXPSTAT_HGTS;
    }
 
    // Write normals info
    if (hsurfnorml)
    {
        EschVector *nml = (EschVector*)ivory_hlock(hsurfnorml);
        if (!nml)
        {
            MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                      "Could not lock normals memory, skipping normals export",
                      "Export Warning",MB_OK | MB_ICONEXCLAMATION);
        }
        else
        {
            if (iff.write(iff.makeid('N','R','M','L'),nml,surfsize*sizeof(EschVector)))
            {
                char    str[64];

                sprintf(str,"Error #%x while trying to write surface normals chunk",(int)iff.error());
                                                  
                MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                           str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
                return;
            }

            status |= EXPSTAT_NRML;
        }
    }

    // Write surface info
    if (surfinfo)
    {
        if (iff.write(iff.makeid('S','U','R','F'),surfinfo,surfsize*sizeof(esch_surf_type)))
        {
            char    str[64];

            sprintf(str,"Error #%x while trying to write surface information chunk",(int)iff.error());
                                                  
            MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        status |= EXPSTAT_SURF;
    }

    // Texture information
    if (txtNumb)
    {
        EschFileMtlMHDR mhdr;

        if (iff.write(iff.makeid('C','O','L','R'),txtColrIndx,txtNumb*sizeof(byte)))
        {
            char    str[64];

            sprintf(str,"Error #%x while trying to write texture color information chunk",(int)iff.error());
                                                      
            MessageBox(NULL,
                str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
                return;
        }

        for(int i=0; i < txtNumb; i++)
        {
             if (iff.newform(iff.makeid('E','M','T','L')))
            {
                char    str[128];

                sprintf(str,"Error #%x while trying to create new texture form\n\nTexture: %s",(int)iff.error(),
                            txtName[i]);

                MessageBox(NULL,
                          str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
                return;
            }
            
            txtEsch[i].lock();
            VngoTexture *ptr = txtEsch[i].ptr;
            ASSERT(ptr);

            memset(&mhdr,0,sizeof(EschFileMtlMHDR));
            strncpy(mhdr.name,txtName[i],ESCH_MAX_NAME);           
            mhdr.xsize = ptr->width;
            mhdr.ysize = ptr->height;
            mhdr.nframes = 1;
            mhdr.type = 1;

            if (iff.write(iff.makeid('M','H','D','R'),&mhdr,sizeof(EschFileMtlMHDR)))
            {
                char    str[128];

                sprintf(str,"Error #%x while trying to write texture header chunk\n\nTexture: %s",(int)iff.error(),
                            txtName[i]);
                                                  
                MessageBox(NULL,
                           str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
                txtEsch[i].unlock();
                return;
            }
 
            if (iff.write(iff.makeid('B','O','D','Y'),ptr->tex,mhdr.xsize*mhdr.ysize))
            {
                char    str[128];

                sprintf(str,"Error #%x while trying to write texture body chunk\n\nTexture: %s",(int)iff.error(),txtName[i]);
                                                  
                MessageBox(NULL,
                           str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
                txtEsch[i].unlock();
                return;
            }
            
            iff.leaveform();
            txtEsch[i].unlock();
        }        
        
        status |= EXPSTAT_TXTS;
    }

    // End form
    iff.leaveform();
    iff.close();

    TerrExpStatDlg dlg;

    dlg.sflags = status;
    dlg.DoModal();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - ComputeNormals                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::ComputeNormals()
{
    int             x, y, cx, cy;
    double          cenh, mag;
    double          v1[3], v2[3], sum[3];
    byte            *sptr;
    EschVector      *dptr;

    ASSERT(width && depth && hsurfnorml);

//ÄÄÄ Setup memory for normals
    dword surfsize = (width * depth) >> (surfshift*2);

    EschVector *nml = (EschVector*)ivory_hlock(hsurfnorml);
    if (!nml)
    {
        MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                  "Could not lock normals memory",
                  "Compute Normals Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }
    memset(nml,0,surfsize*sizeof(EschVector));

//ÄÄÄ Compute normals
    TerrCNmPrgDlg   dlg;
    dlg.m_pBar.SetRange(0,depth);
    dlg.m_pBar.SetPos(0);
    dlg.ShowWindow(SW_SHOW);
       
    for(y=0, cy=0; y < depth;)
    {
        dlg.m_pBar.SetPos(y);
        for(x=0, cx=0,
            sptr=hfield + (y*width),
            dptr=(nml)+(cy*(width >> surfshift));
            x < width; )
        {
            sum[0]=sum[1]=sum[2]=0.0;

            cenh = (float)(*sptr) * 16;

            if (y < depth-1 && x < width-1)
            {
                // Face 1 (N - NE)
                v1[0] = 0.0;
                v1[1] = (float)(*(sptr + width)) * 16 - cenh;
                v1[2] = 30.0;

                v2[0] = 30.0;
                v2[1] = (float)(*(sptr + width + 1)) * 16 - cenh;
                v2[2] = 30.0;

                // Cross-product
                sum[0] += (v1[1] * v2[2]) - (v1[2] * v2[1]);
                sum[1] += (v1[2] * v2[0]) - (v1[0] * v2[2]);
                sum[2] += (v1[0] * v2[1]) - (v1[1] * v2[0]);

                // Face 2 (NE - E)
                v1[0] = 30.0;
                v1[1] = (float)(*(sptr + width + 1)) * 16 - cenh;
                v1[2] = 30.0;

                v2[0] = 30.0;
                v2[1] = (float)(*(sptr + 1)) * 16 - cenh;
                v2[2] = 0.0;

                // Cross-product
                sum[0] += (v1[1] * v2[2]) - (v1[2] * v2[1]);
                sum[1] += (v1[2] * v2[0]) - (v1[0] * v2[2]);
                sum[2] += (v1[0] * v2[1]) - (v1[1] * v2[0]);
            }

            if (y > 0 && x < width-1)
            {
                // Face 3 (E - SE)
                v1[0] = 30.0;
                v1[1] = (float)(*(sptr + 1)) * 16 - cenh;
                v1[2] = 0.0;

                v2[0] = 30.0;
                v2[1] = (float)(*(sptr - width + 1)) * 16 - cenh;
                v2[2] = -30.0;

                // Cross-product
                sum[0] += (v1[1] * v2[2]) - (v1[2] * v2[1]);
                sum[1] += (v1[2] * v2[0]) - (v1[0] * v2[2]);
                sum[2] += (v1[0] * v2[1]) - (v1[1] * v2[0]);

                // Face 4 (SE - S)
                v1[0] = 30.0;
                v1[1] = (float)(*(sptr - width + 1)) * 16 - cenh;
                v1[2] = -30.0;

                v2[0] = 0.0;
                v2[1] = (float)(*(sptr -width)) * 16 - cenh;
                v2[2] = -30.0;

                // Cross-product
                sum[0] += (v1[1] * v2[2]) - (v1[2] * v2[1]);
                sum[1] += (v1[2] * v2[0]) - (v1[0] * v2[2]);
                sum[2] += (v1[0] * v2[1]) - (v1[1] * v2[0]);
            }

            if (y > 0 && x > 0)
            {
                // Face 5 (S - SW)
                v1[0] = 0.0;
                v1[1] = (float)(*(sptr - width)) * 16 - cenh;
                v1[2] = -30.0;

                v2[0] = -30.0;
                v2[1] = (float)(*(sptr - width - 1)) * 16 - cenh;
                v2[2] = -30.0;

                // Cross-product
                sum[0] += (v1[1] * v2[2]) - (v1[2] * v2[1]);
                sum[1] += (v1[2] * v2[0]) - (v1[0] * v2[2]);
                sum[2] += (v1[0] * v2[1]) - (v1[1] * v2[0]);

                // Face 6 (SW - E)
                v1[0] = -30.0;
                v1[1] = (float)(*(sptr - width - 1)) * 16 - cenh;
                v1[2] = -30.0;

                v2[0] = -30.0;
                v2[1] = (float)(*(sptr - 1)) * 16 - cenh;
                v2[2] = 0.0;

                // Cross-product
                sum[0] += (v1[1] * v2[2]) - (v1[2] * v2[1]);
                sum[1] += (v1[2] * v2[0]) - (v1[0] * v2[2]);
                sum[2] += (v1[0] * v2[1]) - (v1[1] * v2[0]);
            }

            if (y < depth-1 && x > 0)
            {
                // Face 7 (E - NW)
                v1[0] = -30.0;
                v1[1] = (float)(*(sptr - 1)) * 16 - cenh;
                v1[2] = 0.0;

                v2[0] = -30.0;
                v2[1] = (float)(*(sptr + width - 1)) * 16 - cenh;
                v2[2] = 30.0;

                // Cross-product
                sum[0] += (v1[1] * v2[2]) - (v1[2] * v2[1]);
                sum[1] += (v1[2] * v2[0]) - (v1[0] * v2[2]);
                sum[2] += (v1[0] * v2[1]) - (v1[1] * v2[0]);

                // Face 8 (NW - N)
                v1[0] = -30.0;
                v1[1] = (float)(*(sptr + width - 1)) * 16 - cenh;
                v1[2] = 30.0;

                v2[0] = 0.0;
                v2[1] = (float)(*(sptr + width)) * 16 - cenh;
                v2[2] = 30.0;

                // Cross-product
                sum[0] += (v1[1] * v2[2]) - (v1[2] * v2[1]);
                sum[1] += (v1[2] * v2[0]) - (v1[0] * v2[2]);
                sum[2] += (v1[0] * v2[1]) - (v1[1] * v2[0]);
            }

            // Compute & Store final normal
            mag = sqrt(sum[0]*sum[0] + sum[1]*sum[1] + sum[2]*sum[2]);

            dptr->i = (Flx16) (float)(sum[0] / mag);
            dptr->j = (Flx16) (float)(sum[1] / mag);
            dptr->k = (Flx16) (float)(sum[2] / mag);

            // Update counters
            x += (1 << surfshift);
            sptr += (1 << surfshift);
            dptr++;
            if (++cx > (width >> surfshift))
                break;
        }

        y += (1 << surfshift);
        if (++cy > (depth >> surfshift))
            break;
    }

    ivory_hunlock(hsurfnorml);

    SetModifiedFlag();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - UITerrainProperities                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::UITerrainProperities(CWnd *parent, UINT ipage, int edit)
{

//ÄÄÄ General
    TerrPropDlgA dlga;

    dlga.m_edit = edit;
    dlga.m_name = name;
    dlga.m_width = width;
    dlga.m_depth = depth;
    dlga.m_surfratio = surfratio;
    dlga.m_wscale = wscale;
    dlga.m_dscale = dscale;
    dlga.m_hscale = hscale;

//ÄÄÄ Misc
    TerrPropDlgB dlgb;

    dlgb.m_desc = desc;
    dlgb.m_auth = auth;
    dlgb.m_copy = copy;

//ÄÄÄ Handle Display
    CPropertySheet sh("Terrain Properties",parent,ipage);

    sh.AddPage(&dlga);      // General
    sh.AddPage(&dlgb);      // Misc

    if (sh.DoModal() == IDOK)
    {
        //ÄÄÄ Save values from General
        memset(name,0,sizeof(name));
        strncpy(name,dlga.m_name,ESCH_MAX_NAME-1);
        SetTitle(name);

        width = (ushort)dlga.m_width;
        depth = (ushort)dlga.m_depth;
        surfratio = (ushort)dlga.m_surfratio;
        switch(surfratio)
        {
            case 1:
                surfshift = 0;
                break;
            case 2:
                surfshift = 1;
                break;
            case 4:
                surfshift = 2;
                break;
            case 8:
                surfshift = 3;
                break;
            case 16:
                surfshift = 4;
                break;
            default:
                ASSERT(0);
                break;
        }
        wscale = dlga.m_wscale;
        dscale = dlga.m_dscale;
        hscale = dlga.m_hscale;      
        
        //ÄÄÄ Save values from Misc
        memset(desc,0,sizeof(desc));
        strncpy(desc,dlgb.m_desc,255);

        memset(auth,0,sizeof(auth));
        strncpy(auth,dlgb.m_auth,255);

        memset(copy,0,sizeof(copy));
        strncpy(copy,dlgb.m_copy,255);

        SetModifiedFlag();
        if (!edit)
            UpdateAllViews(NULL,HINT_UPDATETERR,NULL);
    }  
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - UISurfProperities                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::UISurfProperties(CWnd *parent, UINT xpos, UINT dpos)
{
    SurfacePropDlg      dlg(this,parent);
    esch_surf_type      *surf;
    dword               *colr;

    if (!width || !depth)
        return;

    if (xpos >= (UINT)(width >> surfshift))
        xpos = (width >> surfshift)-1;
    if (dpos >= (UINT)(depth >> surfshift))
        dpos = (depth >> surfshift)-1;

    ASSERT(surfcolr && surfinfo);

    surf = surfinfo + ((dpos * (width >> surfshift)) + xpos);
    colr = surfcolr + ((dpos * (width >> surfshift)) + xpos);

//ÄÄÄ Setup values
    dlg.m_xloc = xpos;
    dlg.m_dloc = dpos;

    dlg.m_color = *colr;
    if (surf->flags & ESCH_SURF_CINDISTXT)
    {
        dlg.m_txt = surf->cind;
    }

    dlg.m_cbit1 = (surf->flags & ESCH_SURF_CNTRL1) ? 1 : 0;
    dlg.m_cbit2 = (surf->flags & ESCH_SURF_CNTRL2) ? 1 : 0;
    dlg.m_cbit3 = (surf->flags & ESCH_SURF_CINDISTXT) ? 1 : 0;
    dlg.m_cbit4 = (surf->flags & ESCH_SURF_CINDISBLK) ? 1 : 0;
    dlg.m_water = (surf->flags & (0xf0)) >> 4;
    dlg.m_fire = (surf->flags & 0xf00) >> 8;
    dlg.m_smoke = (surf->flags & 0xf000) >> 12;

//ÄÄÄ Handle Display
    if (dlg.DoModal() == IDOK)
    {
        //ÄÄÄ Save values
        *colr = dlg.m_color;

        if (dlg.m_txt)
        {
            dlg.m_cbit3 = 1;
            surf->cind = dlg.m_txt;
        }
        else
        {
            dlg.m_cbit3 = 0;
            surf->cind = (byte)palette.get_index((VngoColor24bit)dlg.m_color);
        }

        surf->flags = ((dlg.m_cbit1) ? ESCH_SURF_CNTRL1 : 0)
                      | ((dlg.m_cbit2) ? ESCH_SURF_CNTRL2 : 0)
                      | ((dlg.m_cbit3) ? ESCH_SURF_CINDISTXT : 0)
                      | ((dlg.m_cbit4) ? ESCH_SURF_CINDISBLK : 0)
                      | ((dlg.m_water << 4) & 0xf0)
                      | ((dlg.m_fire << 8) & 0xf00)
                      | ((dlg.m_smoke << 12) * 0xf000);

        SetModifiedFlag();
        UpdateAllViews(NULL,HINT_UPDATECOLR,NULL);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - UISurfColor                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::UISurfColor(CWnd *parent, UINT xpos, UINT dpos)
{
    esch_surf_type      *surf;
    dword               *colr;

    if (!width || !depth)
        return;

    if (xpos >= (UINT)(width >> surfshift))
        xpos = (width >> surfshift)-1;
    if (dpos >= (UINT)(depth >> surfshift))
        dpos = (depth >> surfshift)-1;

    ASSERT(surfcolr && surfinfo);

    surf = surfinfo + ((dpos * (width >> surfshift)) + xpos);
    colr = surfcolr + ((dpos * (width >> surfshift)) + xpos);

    if (surf->flags & ESCH_SURF_CINDISTXT)
    {
        MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                  "This surface point has a texture, not a color.\n",
                  "Edit Surface Color Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

//ÄÄÄ Setup values
    CColorDialog        dlg(*colr,CC_RGBINIT | CC_FULLOPEN,parent);

//ÄÄÄ Handle Display
    if (dlg.DoModal() == IDOK)
    {
        //ÄÄÄ Save values
        *colr = dlg.GetColor();
        surf->cind = (byte)palette.get_index((VngoColor24bit)dlg.GetColor());

        SetModifiedFlag();
        UpdateAllViews(NULL,HINT_UPDATECOLR,NULL);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                             °°° Protected °°°                            ³
// TerrEditDoc - map_surfcolor_to_palette                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::map_surfcolor_to_palette()
{
    int             i;
    int             x, y;
    dword           *sptr;
    esch_surf_type  *dptr;

    if (!width || !depth || !surfinfo || !surfcolr)
        return;

    TerrCScPrgDlg   dlg;
    dlg.m_pBar.SetRange(0, (depth >> surfshift));
    dlg.m_pBar.SetPos(0);
    dlg.ShowWindow(SW_SHOW);

    for(y=0, sptr=surfcolr, dptr=surfinfo;
        y < (depth >> surfshift); y++)
    {
        dlg.m_pBar.SetPos(y);

        for(x=0; x < (width >> surfshift); x++)
        {
            if (dptr->flags & ESCH_SURF_CINDISTXT)
            {
                dptr++;
                sptr++;
            }
            else
            {
                VngoColor24bit clr=(VngoColor24bit) *(sptr++);
                (dptr++)->cind = (byte)palette.get_index(clr);
            }
        }
    }

    for(i=0; i < txtNumb; i++)
    {
        txtColrIndx[i] = (byte)palette.get_index((VngoColor24bit)txtColr[i]);
    }           
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                             °°° Protected °°°                            ³
// TerrEditDoc - load_and_recolor_texture                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL TerrEditDoc::load_and_recolor_texture(int ind, const char *fname)
{
    int             i;

    // Load bitmap

    XFParseBitmap *b;

    if (strstr(fname,".bmp") || strstr(fname,".BMP"))
    {
        b = new XFParseBMP;
    }
    else if (strstr(fname,".cel") || strstr(fname,".CEL"))
    {
        b = new XFParseCEL;
    }
    else if (strstr(fname,".lbm") || strstr(fname,".LBM"))
    {
        b = new XFParseLBM;
    }
    else if (strstr(fname,".tga") || strstr(fname,".TGA"))
    {
        b = new XFParseTGA;
    }
    else if (strstr(fname,".pcx") || strstr(fname,".PCX"))
    {
        b = new XFParsePCX;
    }
    else 
    {
        char str[256];
        sprintf(str,"Cannot read given input file:\n%s",fname);
        MessageBox(NULL, str, "Texture Load Error", MB_OK | MB_ICONEXCLAMATION);
        delete b;
        return FALSE;
    }

    int err;

    if ((err=b->nameread(fname)) != 0)
    {
        char    str[256];

        sprintf(str,"Error %x reading input file:\n%s",err,fname);
        MessageBox(NULL,str, "Texture Load Error",
                   MB_OK | MB_ICONEXCLAMATION);
        delete b;
        return FALSE;                   
    }

    // Check for valid size

    switch (b->bm->width)
    {
        case 16:
        case 32:
        case 64:
        case 128:
        case 256:
            break;
        default:
            MessageBox(NULL,"Input bitmap file must be 16, 32, 64, 128, or 256 pixels in width.",
                      "Texture Load Error", MB_OK | MB_ICONEXCLAMATION);
            delete b;
            return FALSE;
    }

    switch (b->bm->height)
    {
        case 16:
        case 32:
        case 64:
        case 128:
        case 256:
            break;
        default:
            MessageBox(NULL,"Input bitmap file must be 16, 32, 64, 128, or 256 pixels in height.",
                       "Texture Load Error", MB_OK | MB_ICONEXCLAMATION);
            delete b;
            return FALSE;
    }

    //
    // Install new texture
    //

    txtFName[ind] = fname;
    EschTexture *txt = &txtEsch[ind];
    txt->release();
      
    // Allocate memory for texture

    if ( ((txt->handle = ivory_halloc(sizeof(VngoTexture) + (b->bm->width*b->bm->height))) == 0)
         || ((txt->ptr = (VngoTexture*)ivory_hlock(txt->handle)) == 0) )
    {
        MessageBox(NULL,"Memory problem loading texture.",
                   "Texture Load Error", MB_OK | MB_ICONEXCLAMATION);
        txt->release();
        delete b;
        return FALSE;
    }

    txt->flags = ESCH_TXT_LOCKED | ESCH_TXT_OWNSDATA;
    txt->max = 1;

    txt->ptr->tex = (byte*)txt->ptr + sizeof(VngoTexture);

    txt->ptr->width = b->bm->width;
    txt->ptr->height = b->bm->height;

    // Recolor image using current palette

    ASSERT(b->bm->bpp == 1 || b->bm->bpp == 3);
        
    if (b->bm->bpp == 1)
    {
        int mypal[256];

        for(i=0; i < 256; i++)
        {
            mypal[i] = (byte)palette.get_index((VngoColor24bit)b->bm->pal[i]);
        }

        for(i=0; i < b->bm->width * b->bm->height; i++)
        {
            txt->ptr->tex[i] = (byte)mypal[b->bm->data[i]];
        }
    }
    else // bpp == 3
    {
        VngoColor24bit  clr;
        byte            *sptr, *dptr;

        for(i=0, sptr=b->bm->data, dptr=txt->ptr->tex; i < b->bm->width * b->bm->height; i++)
        {
            clr.r = *(sptr++);
            clr.g = *(sptr++);
            clr.b = *(sptr++);
            *(dptr++) = (byte)palette.get_index(clr);
        }
    }

    txt->unlock();

    return TRUE;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Message Handlers °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - OnNewDocument                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL TerrEditDoc::OnNewDocument()
{
    if (!CDocument::OnNewDocument())
        return FALSE;

    width = 258;
    depth = 258;
    surfratio = 1;
    surfshift = 0;

    hscale=16;
    wscale=dscale=30;

    strcpy(name,"NoName");
    *desc = 0;
    SetTitle(name);

    if (!FirstNew)
    {
        UITerrainProperities(AfxGetMainWnd(),0,1);
    }
    else
    {
        FirstNew = 0;
    }

// Allocate memory for terrain
    hfield = new byte[width * depth];
    if (!hfield)
        return FALSE;
    memset(hfield,0,width * depth);

    dword surfsize = (width * depth) >> (surfshift*2);

    surfinfo = new esch_surf_type[surfsize];
    if (!surfinfo)
        return FALSE;
    memset(surfinfo,0,surfsize * sizeof(esch_surf_type));

    surfcolr = new dword[surfsize];
    if (!surfcolr)
        return FALSE;
    memset(surfcolr,0,surfsize * sizeof(dword));
 
    hsurfnorml = ivory_halloc((ulong)(surfsize * sizeof(EschVector)));
    if (!hsurfnorml)
        return FALSE;

    EschVector *vptr = (EschVector*) ivory_hlock(hsurfnorml);
    if (!vptr)
        return FALSE;
    memset(vptr,0,(ulong)(surfsize * sizeof(EschVector)));
    ivory_hunlock(hsurfnorml);

    int     i;
    char    *c;
    char    fname[256];
  
    GetModuleFileName(NULL, fname, 256);

    for (i=strlen(fname), c = &fname[i-1]; c > 0; i--, c--)
    {
        if (*c == '\\')
        {
            strcpy(c+1,"DEFAULT.PAL");

            if (xf_exist(fname))
                break;
        }
    }

    if (!LoadPalette(fname,0))
    {
        MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                   "Must have a valid default Van Gogh palette","Fatal Error",MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - Serialize                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::Serialize(CArchive& ar)
{
    int i;

	if (ar.IsStoring())
	{
        // Terrain Properities

        ar << width;
        ar << depth;
        ar << surfratio;
        ar << surfshift;
        ar << (float)wscale;
        ar << (float)dscale;
        ar << (float)hscale;
        ar << CString(name);
        ar << CString(desc);
        ar << CString(auth);
        ar << CString(copy);
        ar << CString(pfname);

        // Height-field

        ar.Write(hfield,width*depth);

        // Surface information

        dword surfsize = (width * depth) >> (surfshift*2);

        ar.Write(surfinfo,surfsize*sizeof(esch_surf_type));
        ar.Write(surfcolr,surfsize*sizeof(dword));

        // Write texture information

        ar << (long)txtNumb;
        for(i=0; i < txtNumb; i++)
        {
            ar << txtName[i] << txtFName[i] << txtColr[i];
        }
	}
	else
	{
        float   f;
        CString str;

        // Terrain Properities

        ar >> width;
        ar >> depth;
        ar >> surfratio;
        ar >> surfshift;

        ar >> f;  wscale = (Flx16)f;
        ar >> f;  dscale = (Flx16)f;
        ar >> f;  hscale = (Flx16)f;

        ar >> str;  strcpy(name,str);
        ar >> str;  strcpy(desc,str);
        ar >> str;  strcpy(auth,str);
        ar >> str;  strcpy(copy,str);
        ar >> str;  strcpy(pfname,str);

        // Height-field
 
        hfield = new byte[width * depth];
        ASSERT(hfield);
        ar.Read(hfield,width*depth);

        // Surface information

        dword surfsize = (width * depth) >> (surfshift*2);

        surfinfo = new esch_surf_type[surfsize];
        ASSERT(surfinfo);
        ar.Read(surfinfo,surfsize*sizeof(esch_surf_type));

        surfcolr = new dword[surfsize];
        ASSERT(surfcolr);
        ar.Read(surfcolr,surfsize*sizeof(dword));

        // Read texture information

        long l;

        ar >> l; txtNumb = l;

        for(i=0; i < txtNumb; i++)
        {
            ar >> txtName[i] >> txtFName[i] >> txtColr[i];
        }

        // Load palette

        if (!LoadPalette(pfname,0))
        {
            MessageBox(NULL,
                       "Failed to load palette in archive","Load Error",MB_OK | MB_ICONEXCLAMATION);
        }

        // Compute normals

        hsurfnorml = ivory_halloc((ulong)(surfsize * sizeof(EschVector)));
        ASSERT(hsurfnorml);

        EschVector *vptr = (EschVector*) ivory_hlock(hsurfnorml);
        ASSERT(vptr);
        memset(vptr,0,(ulong)(surfsize * sizeof(EschVector)));
        ivory_hunlock(hsurfnorml);

        ComputeNormals();

        // Load textures

        for(i=0; i < txtNumb; i++)
        {
            if (!load_and_recolor_texture(i,txtFName[i]))
            {
                MessageBox(NULL,
                       "Failed attempting to load texture " + txtFName[i],"Load Error",MB_OK | MB_ICONEXCLAMATION);
            }
        }

	}
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - AssertValid                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
#ifdef _DEBUG
void TerrEditDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void TerrEditDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

//°±² eof - eshtdoc.cpp ²±°
