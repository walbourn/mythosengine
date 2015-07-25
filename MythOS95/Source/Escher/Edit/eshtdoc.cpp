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
//                        *** Escher Terrain Editor ***
//
// Created by Chuck Walbourn
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

#include <float.h>
#include <math.h>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define MAGIC   0xffab

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

extern TerrEditApp  theApp;

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
TerrEditDoc::TerrEditDoc() :
    ctrlfl(FLOATING | COMPRESS),
    width(0),
    depth(0),
    surfratio(1),
    surfshift(0),
    autocenter(1),
    hfield(0),
    htable(0),
    surfinfo(0),
    surfcolr(0),
    hsurfnorml(0),
    hsurfnormlflat(0),
    undo_valid(FALSE),
    undo_surfinfo(0),
    undo_surfcolr(0),
    txtNumb(0),
    colorNumb(0),
    hpal(0),
    lights(0),
    lightsdirty(FALSE)
{
    for(int i=0; i < 256; i++)
        txtEsch[i] = 0;
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
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Diagnostics °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#ifdef _DEBUG
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - AssertValid                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::AssertValid() const
{
    CDocument::AssertValid();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - Dump                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::Dump(CDumpContext& dc) const
{
    CDocument::Dump(dc);
}
#endif //_DEBUG



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Operations °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - DeleteContents                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::DeleteContents()
{
    for (EschLight *lptr=lights; lptr;)
    {
        EschLight   *t=lptr;
        lptr = lptr->next();
        delete t;
    }
    lights=0;

    for(int i=0; i < txtNumb; i++)
    {
        txtName[i].Empty();
        txtFName[i].Empty();
        if (txtEsch[i])
        {
            delete txtEsch[i];
            txtEsch[i] = 0;
        }
        txtDFlags[i] = 0;
    }
    txtNumb=0;

    for(i=0; i < colorNumb; i++)
    {
        colorName[i].Empty();
        colorDFlags[i] = 0;
    }

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
    if (htable)
    {
        delete [] htable;
        htable=0;
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

    if (hsurfnormlflat)
    {
        ivory_hfree(&hsurfnormlflat);
    }

    undo_valid=FALSE;
    if (undo_surfinfo)
    {
        delete [] undo_surfinfo;
        undo_surfinfo=0;
    }
    if (undo_surfcolr)
    {
        delete [] undo_surfcolr;
        undo_surfcolr=0;
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

    undo_valid=FALSE;

    palptr->init(0);
    err=loadpal.load(fname);

    if (err)
    {
        char    str[512];
        sprintf(str,"Error #%x loading Van Gogh palette file:\n\n%s",(int)err,fname);
        MessageBox(NULL,str,"Error",MB_OK | MB_ICONEXCLAMATION);
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
    {
        DeleteObject(hpal);
    }

    hpal = CreatePalette(lpal);

    ivory_free( (void**)&lpal );

    if (!hpal)
    {
        MessageBox(NULL,
                   "Failed to create a palette from Van Gogh palette file",
                   "Error",MB_OK | MB_ICONEXCLAMATION);
        return FALSE;
    }

    map_surfcolor_to_palette();

    if (txtNumb)
    {
        ProgressDlg dlg;
        dlg.m_pbar.SetRange(0, txtNumb-1);
        dlg.m_pbar.SetPos(0);
        dlg.SetWindowText("Recoloring Texture Maps...");
        dlg.ShowWindow(SW_SHOW);

        for(int i=0; i < txtNumb; i++)
        {
            dlg.m_pbar.SetPos(i);

            if (!xf_exist(txtFName[i]))
            {
                LocateDlg   dlg;
                dlg.title = "Locate File for Texture '" + txtName[i] + "'";
                dlg.m_fname = txtFName[i];
                dlg.typestr = "Bitmap files (*.bmp;*.cel;*.lbm;*.pcx;*.tga)|"
                              "*.BMP;*.CEL;*.LBM;*.PCX;*.TGA|"
                              "Windows Bitmap files (*.bmp)|*.BMP|"
                              "Autodesk CEL files (*.cel)|*.CEL|"
                              "DPaint/EA LBM files (*.lbm)|*.LBM|"
                              "Zsoft PCX files (*.pcx)|*.PCX|"
                              "Targa files (*.tga)|*.TGA|";

                if (dlg.DoModal() == IDOK)
                {
                    txtFName[i] = dlg.m_fname;
                    SetModifiedFlag();
                }
            }

            load_and_recolor_texture(i,txtFName[i]);
        }
    }

    cam.set_bcolor(palette.get_index((VngoColor24bit)cam_bcolor));

    if (doupdate)
        UpdateAllViews(NULL,HINT_UPDATECOLR,NULL);

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - FindTexture                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int TerrEditDoc::FindTexture(const char *name)
{
    for(int i=0; i < txtNumb; i++)
    {
        if (!txtName[i].CompareNoCase(name))
            return i;
    }

    return -1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - AddTexture                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL TerrEditDoc::AddTexture(const char *name, const char *fname, dword color,
                             dword flags)
{
    //
    // Assumes name is unique
    //

    if (txtNumb >= 255)
        return FALSE;

    txtNumb++;
    return SetTexture(txtNumb-1,name,fname,color,flags);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - SetTexture                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL TerrEditDoc::SetTexture(int ind, const char *name, const char *fname,
                             dword color, dword flags)
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
    txtDFlags[ind] = flags;

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
    // Remove texture, renumbering all textures afterwards
    // (and updating surface data)
    //

    if (ind >= txtNumb)
        return;

    //
    // Remove data for current entry
    //

    if (txtEsch[ind])
    {
        delete txtEsch[ind];
        txtEsch[ind] = 0;
    }
    txtName[ind].Empty();
    txtFName[ind].Empty();
    txtDFlags[ind] = 0;

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
        txtDFlags[i-1] = txtDFlags[i];
    }
    txtNumb--;

    //
    // Must scan and decrement all references in 'surface' 2D array.
    //

    int             x, y;
    esch_surf_type  *ptr;

    if (!width || !depth || !surfinfo)
        return;

    undo_valid = FALSE;

    ProgressDlg   dlg;
    dlg.m_pbar.SetRange(0, (depth >> surfshift));
    dlg.m_pbar.SetPos(0);
    dlg.SetWindowText("Scanning Surface Information...");
    dlg.ShowWindow(SW_SHOW);

    for(y=0, ptr=surfinfo; y < (depth >> surfshift); y++)
    {
        dlg.m_pbar.SetPos(y);

        for(x=0; x < (width >> surfshift); x++)
        {
            if (ptr->flags & ESCH_SURF_CINDISTXT)
            {
                if (ptr->cind == ind+1)
                {
                    ptr->cind = (byte)palette.get_index((VngoColor24bit)
                                    surfcolr[y*(depth>>surfshift) + x]);
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
// TerrEditDoc - DeleteTexture                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::RemoveUnusedTxts()
{
    if (txtNumb < 1)
        return;

    if (!width || !depth || !surfinfo)
        return;

    ProgressDlg   dlg;
    dlg.SetWindowText("Scanning for unused textures...");
    dlg.ShowWindow(SW_SHOW);

    undo_valid = FALSE;

start_over: ;
    dlg.m_pbar.SetRange(0, txtNumb);
    dlg.m_pbar.SetPos(0);

    for(int txt=0; txt < txtNumb; txt++)
    {
        int             x, y;
        esch_surf_type  *ptr;

        for(y=0, ptr=surfinfo; y < (depth >> surfshift); y++)
        {
            for(x=0; x < (width >> surfshift); x++)
            {
                if (ptr->flags & ESCH_SURF_CINDISTXT
                    && ptr->cind == txt+1)
                {
                    goto found;
                }
                ptr++;
            }
        }

        // Not found
        DeleteTexture(txt);
        goto start_over;

found: ;
        dlg.m_pbar.SetPos(txt);
    }

    dlg.ShowWindow(SW_HIDE);

    //
    // Update view
    //

    SetModifiedFlag();
    UpdateAllViews(NULL,HINT_UPDATETXTS | HINT_UPDATECOLR,NULL);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - SaveTextures                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::SaveTextures(const char *fname)
{
    //
    // Assumes there are textures defined
    //

//ÄÄÄÄ Open output file
    FILE *fptr = fopen (fname, "w");
    if (!fptr)
    {
        MessageBox(NULL,
                   "Failed to open file",
                   "Save Textures Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

//ÄÄÄÄ Write header
    fprintf(fptr,"; Escher Terrain Editor Texture Set\n\n%d\n",txtNumb);

//ÄÄÄÄ Write each texture definition
    for(int i=0; i < txtNumb; i++)
    {
        fprintf(fptr,"\"%s\" \"%s\" 0x%x 0x%x\n",
                     txtName[i], txtFName[i], txtColr[i], txtDFlags[i]);
    }

//ÄÄÄÄ Close up file
    fprintf(fptr,"\n; eof\n");
    fclose (fptr);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - LoadTextures                                               ³
//                                                                          ³
// This will merge with the current texture definitions.  If there is a name³
// conflict, a warning box is generated to ask if the user wants the new    ³
// version used to overwrite the old.                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::LoadTextures(const char *fname)
{
    BOOL tryadd=TRUE;

//ÄÄÄÄ Open input file
    FILE *fptr = fopen (fname, "r");
    if (!fptr)
    {
        MessageBox(NULL,
                   "Failed to open file",
                   "Load Textures Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

    int i, t, numb;

//ÄÄÄÄ Read header
    if (fscanf(fptr,"; Escher Terrain Editor Texture Set\n\n%d\n",&numb) != 1)
        goto read_error;

//ÄÄÄÄ Read each texture definition
    for(i=0; i < numb; i++)
    {
        char c;
        char name[16];
        char fname[256];
        dword color;
        dword dflags;

        // Read texture name
        c=fgetc(fptr);
        while (c != EOF && c != '\"')
            c=fgetc(fptr);
        if (c == EOF)
            goto read_error;

        for(t=0; t < sizeof(name); t++)
        {
            c=fgetc(fptr);
            if (c == EOF || c == '\"')
                break;
            name[t] = c;
        }
        name[t]=0;
        if (c == EOF)
            goto read_error;

        while (c != EOF && c != '\"')
            c=fgetc(fptr);
        if (c == EOF)
            goto read_error;

        // Read texture filename
        c=fgetc(fptr);
        while (c != EOF && c != '\"')
            c=fgetc(fptr);
        if (c == EOF)
            goto read_error;

        for(t=0; t < sizeof(fname); t++)
        {
            c=fgetc(fptr);
            if (c == EOF || c == '\"')
                break;
            fname[t] = c;
        }
        fname[t]=0;
        if (c == EOF)
            goto read_error;

        while (c != EOF && c != '\"')
            c=fgetc(fptr);
        if (c == EOF)
            goto read_error;

        // Read color and flags
        if (fscanf(fptr," 0x%x 0x%x\n",
                        &color,&dflags) != 2)
            goto read_error;

        //
        // Scan current textures to see if name already in use.
        //

        int j=FindTexture(name);
        if (j != -1)
        {
            char buff[128];
            sprintf(buff,
                    "Texture '%s' already defined, overwrite?",
                    name);

            int r = MessageBox(NULL,
                               buff,
                               "Load Textures Warning",
                               MB_YESNOCANCEL | MB_ICONQUESTION);
            if (r == IDYES)
            {
                SetTexture(j,name,fname,color,dflags);
            }
            else if (r == IDCANCEL)
                goto leave;
        }
        //ÄÄÄÄ Name not in use, so add if possible
        else if (tryadd)
        {
            if (!AddTexture(name,fname,color,dflags))
            {
                MessageBox(NULL,
                           "No more textures may be defined.\n\n"
                           "Skipping all remaining new textures",
                           "Load Textures Error", MB_OK | MB_ICONEXCLAMATION);
                tryadd=FALSE;
            }
        }
    }

//ÄÄÄÄ Close up file
leave: ;
    fclose (fptr);

    return;

//ÄÄÄÄ Handle error
read_error: ;

    MessageBox(NULL,
               "Failed to read needed data",
               "Load Textures Error",MB_OK | MB_ICONEXCLAMATION);
    fclose (fptr);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - FindColor                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int TerrEditDoc::FindColor(const char *name)
{
    for(int i=0; i < colorNumb; i++)
    {
        if (!colorName[i].CompareNoCase(name))
            return i;
    }

    return -1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - AddColor                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL TerrEditDoc::AddColor(const char *name, dword color, dword flags)
{
    //
    // Assumes name is unique
    //

    if (colorNumb >= 255)
        return FALSE;

    colorNumb++;
    return SetColor(colorNumb-1,name, color, flags);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - SetColor                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL TerrEditDoc::SetColor(int ind, const char *name, dword color, dword flags)
{
    //
    // Assumes new name is unique
    //

    if (ind >= colorNumb)
        return FALSE;

    //
    // Check for change of filename
    //

    colorName[ind] = name;
    colorColr[ind] = color;
    colorColrIndx[ind] = (byte)palette.get_index((VngoColor24bit)color);
    colorDFlags[ind] = flags;

    //
    // Update view
    //

    SetModifiedFlag();

    UpdateAllViews(NULL,HINT_UPDATETXTS | HINT_UPDATECOLR,NULL);

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - DeleteColor                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::DeleteColor(int ind)
{
    //
    // Remove color definition
    //

    if (ind >= colorNumb)
        return;

    //
    // Remove data for current entry
    //

    colorName[ind].Empty();

    //
    // Compact array
    //

    for(int i=ind+1; i < colorNumb; i++)
    {
        colorName[i-1] = colorName[i];
        colorColr[i-1] = colorColr[i];
        colorColrIndx[i-1] = colorColrIndx[i];
        colorDFlags[i-1] = colorDFlags[i];
    }
    colorNumb--;

    //
    // Update view
    //

    SetModifiedFlag();
    UpdateAllViews(NULL,HINT_UPDATETXTS,NULL);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - SaveColors                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::SaveColors(const char *fname)
{
    //
    // Assumes there are colors defined
    //

//ÄÄÄÄ Open output file
    FILE *fptr = fopen (fname, "w");
    if (!fptr)
    {
        MessageBox(NULL,
                   "Failed to open file",
                   "Save Colors Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

//ÄÄÄÄ Write header
    fprintf(fptr,"; Escher Terrain Editor Color Set\n\n%d\n",colorNumb);

//ÄÄÄÄ Write each color definition
    for(int i=0; i < colorNumb; i++)
    {
        fprintf(fptr,"\"%s\" 0x%x 0x%x\n",
                     colorName[i], colorColr[i], colorDFlags[i]);
    }

//ÄÄÄÄ Close up file
    fprintf(fptr,"\n; eof\n");
    fclose (fptr);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - LoadColors                                                 ³
//                                                                          ³
// This will merge with the current color definitions.  If there is a name  ³
// conflict, a warning box is generated to ask if the user wants the new    ³
// version used to overwrite the old.                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::LoadColors(const char *fname)
{
    BOOL tryadd=TRUE;

//ÄÄÄÄ Open input file
    FILE *fptr = fopen (fname, "r");
    if (!fptr)
    {
        MessageBox(NULL,
                   "Failed to open file",
                   "Load Colors Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

    int i, t, numb;

//ÄÄÄÄ Read header
    if (fscanf(fptr,"; Escher Terrain Editor Color Set\n\n%d\n",&numb) != 1)
        goto read_error;

//ÄÄÄÄ Read each texture definition
    for(i=0; i < numb; i++)
    {
        char c;
        char name[16];
        dword color;
        dword dflags;

        // Read texture name
        c=fgetc(fptr);
        while (c != EOF && c != '\"')
            c=fgetc(fptr);
        if (c == EOF)
            goto read_error;

        for(t=0; t < sizeof(name); t++)
        {
            c=fgetc(fptr);
            if (c == EOF || c == '\"')
                break;
            name[t] = c;
        }
        name[t]=0;
        if (c == EOF)
            goto read_error;

        while (c != EOF && c != '\"')
            c=fgetc(fptr);
        if (c == EOF)
            goto read_error;

        // Read color and flags
        if (fscanf(fptr," 0x%x 0x%x\n",
                        &color,&dflags) != 2)
            goto read_error;

        //
        // Scan current colors to see if name already in use.
        //

        int j=FindColor(name);
        if (j != -1)
        {
            char buff[128];
            sprintf(buff,
                    "Color '%s' already defined, overwrite?",
                    name);

            int r = MessageBox(NULL,
                               buff,
                               "Load Colors Warning",
                               MB_YESNOCANCEL | MB_ICONQUESTION);
            if (r == IDYES)
            {
                SetColor(j,name,color,dflags);
            }
            else if (r == IDCANCEL)
                goto leave;
        }
        //ÄÄÄÄ Name not in use, so add if possible
        else if (tryadd)
        {
            if (!AddColor(name,color,dflags))
            {
                MessageBox(NULL,
                           "No more colors may be defined.\n\n"
                           "Skipping all remaining new colors",
                           "Load Colors Error", MB_OK | MB_ICONEXCLAMATION);
                tryadd=FALSE;
            }
        }
    }

//ÄÄÄÄ Close up file
leave: ;
    fclose (fptr);

    return;

//ÄÄÄÄ Handle error
read_error: ;

    MessageBox(NULL,
               "Failed to read needed data",
               "Load Colors Error",MB_OK | MB_ICONEXCLAMATION);
    fclose (fptr);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - ExportToIFF                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::ExportToIFF(const char *fname)
{
    dword               status=0;
    XFParseIFF          iff;
    EschFileTerrHCLR    hcolor;

    dword surfsize = (width * depth) >> (surfshift*2);

//ÄÄÄ Open output file
    if (iff.create(fname,0))
    {
        char    str[512];

        sprintf(str,"Error #%x while opening output file:\n\n%s",(int)iff.error(),fname);

        MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
               str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

//ÄÄÄ Create form
    if (iff.newform(iff.makeid('E','T','E','R')))
    {
        char    str[64];

        sprintf(str,"Error #%x while trying to create new form ETER",(int)iff.error());

        MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
               str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

//ÄÄÄ Write header
    if (ctrlfl & FLOATING)
    {
        EschFileTerrHDR header;
        memset(&header,0,sizeof(header));

        strncpy(header.name,name,ESCH_MAX_NAME);

        header.width = width;
        header.depth = depth;
        header.surfratio = surfratio;
        header.scale = scale;
        header.ntxts = (byte) txtNumb;
        header.origin_x = orgx;
        header.origin_y = orgy;
        header.origin_z = orgz;

        strncpy(header.palname,palette.name,16);

        if (iff.write(iff.makeid('H','D','R','1'),&header,sizeof(header)))
        {
            char    str[64];

            sprintf(str,"Error #%x while trying to write header chunk",(int)iff.error());

            MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                       str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }
    }
    else
    {
        EschFileTerrHDRV1   header;
        memset(&header,0,sizeof(header));

        strncpy(header.name,name,ESCH_MAX_NAME);

        header.width = width;
        header.depth = depth;
        header.surfratio = surfratio;
        header.scale = long(scale * 65536.0f);
        header.ntxts = (byte) txtNumb;
        header.origin_x = long(orgx * 65536.0f);
        header.origin_y = long(orgy * 65536.0f);
        header.origin_z = long(orgz * 65536.0f);

        strncpy(header.palname,palette.name,16);

        if (iff.write(iff.makeid('H','D','R',' '),&header,sizeof(header)))
        {
            char    str[64];

            sprintf(str,"Error #%x while trying to write header chunk",(int)iff.error());

            MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                       str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }
    }

    status |= EXPSTAT_HDR;

//ÄÄÄ Write description, if any
    if (*desc && iff.write(iff.makeid('D','E','S','C'),desc,strlen(desc)+1))
    {
        char    str[64];

        sprintf(str,"Error #%x while trying to write description chunk",(int)iff.error());

        MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
               str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

//ÄÄÄ Write author, if any
    if (*auth && iff.write(iff.makeid('A','U','T','H'),auth,strlen(auth)+1))
    {
        char    str[64];

        sprintf(str,"Error #%x while trying to write author chunk",(int)iff.error());

        MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
               str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

//ÄÄÄ Write copyright, if any
    if (*copy && iff.write(iff.makeid('(','C',')',' '),copy,strlen(copy)+1))
    {
        char    str[64];

        sprintf(str,"Error #%x while trying to write copyright chunk",(int)iff.error());

        MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
               str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

//ÄÄÄ Write height-based color table
    hcolor.blue = color_bands[0];
    hcolor.lblue = color_bands[1];
    hcolor.white = color_bands[2];
    hcolor.green = color_bands[3];
    hcolor.lgreen = color_bands[4];
    hcolor.yellow = color_bands[5];
    hcolor.lorange = color_bands[6];
    hcolor.orange = color_bands[7];
    hcolor.lbrown = color_bands[8];
    hcolor.brown = color_bands[9];
    hcolor.red = color_bands[10];
    if (iff.write(iff.makeid('H','C','L','R'),&hcolor,sizeof(EschFileTerrHCLR)))
    {
        char    str[64];

        sprintf(str,"Error #%x while trying to write color bands chunk",(int)iff.error());

        MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
               str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }

//ÄÄÄ Write height field
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

//ÄÄÄ Write height table
    if (htable)
    {
        if (ctrlfl & FLOATING)
        {
            if (iff.write(iff.makeid('H','T','B','1'),htable,sizeof(float)*256))
            {
                char    str[64];

                sprintf(str,"Error #%x while trying to write height table chunk",(int)iff.error());

                MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                    str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
                return;
            }
        }
        else
        {
            long v1[256];

            for(int i=0; i < 256; i++)
                v1[i] = long(htable[i] * 65536.0f);

            if (iff.write(iff.makeid('H','T','B','L'),&v1,sizeof(Flx16)*256))
            {
                char    str[64];

                sprintf(str,"Error #%x while trying to write height table chunk",(int)iff.error());

                MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                    str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
                return;
            }
        }
    }

//ÄÄÄ Write normals info
    if (hsurfnorml)
    {
        EschVector *nml = (EschVector*)ivory_hlock(hsurfnorml);
        if (!nml)
        {
            MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                      "Could not lock normals memory, skipping normals export",
                      "Export Warning",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        if (ctrlfl & COMPRESS)
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Output compressed normals
            ushort *cnrmls = new ushort[surfsize * 4];
            if (!cnrmls)
            {
                MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                           "Out of Memory","Export Error",MB_OK | MB_ICONEXCLAMATION);
                return;
            }

            ushort *sptr = cnrmls;
            EschVector *ptr = nml;
            for(ulong i=0; i < surfsize; i++, ptr++)
            {
                ushort flags=0;

                long i = long(ptr->i * 65536.0f);
                long j = long(ptr->j * 65536.0f);
                long k = long(ptr->k * 65536.0f);

                if (i < 0)
                {
                    flags |= 0x8;
                    i = -i;
                }
                if (j < 0)
                {
                    flags |= 0x10;
                    j = -j;
                }
                if (k < 0)
                {
                    flags |= 0x20;
                    k = -k;
                }

                *(sptr++) = (ushort)(i & 0xffff);
                *(sptr++) = (ushort)(j & 0xffff);
                *(sptr++) = (ushort)(k & 0xffff);

                if (i & 0x00010000)
                    flags |= 0x1;
                if (j & 0x00010000)
                    flags |= 0x2;
                if (k & 0x00010000)
                    flags |= 0x4;

                *(sptr++) = flags;
            }

            if (iff.write(iff.makeid('N','R','M','1'),
                          cnrmls,surfsize*sizeof(ushort)*4))
            {
                char    str[64];

                sprintf(str,"Error #%x while trying to write surface normals chunk",
                            (int)iff.error());

                MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                           str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
                delete [] cnrmls;
                return;
            }

            delete [] cnrmls;
        }
        else if (ctrlfl & FLOATING)
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Output uncompressed normals (floating-point)
            if (iff.write(iff.makeid('N','R','M','2'),
                          nml,surfsize*sizeof(EschVector)))
            {
                char    str[64];

                sprintf(str,"Error #%x while trying to write surface normals chunk",
                            (int)iff.error());

                MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                           str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
                return;
            }
        }
        else
        {
            //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Output uncompressed normals (fixed-point)
            EschVectorV1 *temp = new EschVectorV1[surfsize];
            ASSERT(temp);

            EschVector *tptr = nml;
            EschVectorV1 *tmpptr = temp;
            for(ulong i=0; i < surfsize; i++, tptr++, tmpptr++)
            {
                tmpptr->i = long(tptr->i * 65536.0f);
                tmpptr->j = long(tptr->j * 65536.0f);
                tmpptr->k = long(tptr->k * 65536.0f);
            }

            if (iff.write(iff.makeid('N','R','M','L'),
                          temp,surfsize*sizeof(EschVectorV1)))
            {
                char    str[64];

                sprintf(str,"Error #%x while trying to write surface normals chunk",
                            (int)iff.error());

                MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                           str,"Export Error",MB_OK | MB_ICONEXCLAMATION);

                delete [] temp;
                return;
            }

            delete [] temp;
        }

        status |= EXPSTAT_NRML;
    }

//ÄÄÄ Write materials name list
    if (txtNumb)
    {
        EschFileTerrMTL *mtl = new EschFileTerrMTL[txtNumb];
        if (!mtl)
        {
            MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                       "Out of Memory","Export Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }
        memset(mtl, 0, sizeof(EschFileTerrMTL)*txtNumb);

        for(int i=0; i < txtNumb; i++)
        {
            strncpy(mtl[i].name, txtName[i], ESCH_MAX_NAME);
        }

        if (iff.write(iff.makeid('M','T','L',' '),mtl,sizeof(EschFileTerrMTL)*txtNumb))
        {
            char    str[64];

            sprintf(str,"Error #%x while trying to write materials name chunk",
                        (int)iff.error());

            MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        delete [] mtl;
    }

//ÄÄÄ Write surface info
    if (surfinfo)
    {
        if (iff.write(iff.makeid('S','U','R','F'),surfinfo,surfsize*sizeof(esch_surf_type)))
        {
            char    str[64];

            sprintf(str,"Error #%x while trying to write surface information chunk",
                        (int)iff.error());

            MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        status |= EXPSTAT_SURF;
    }

//ÄÄÄ Texture information
    if (txtNumb)
    {
        EschFileMtlMHDR mhdr;

        if (iff.write(iff.makeid('C','O','L','R'),txtColrIndx,txtNumb*sizeof(byte)))
        {
            char    str[64];

            sprintf(str,"Error #%x while trying to write texture color information chunk",
                        (int)iff.error());

            MessageBox(NULL,
                str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
                return;
        }

        for(int i=0; i < txtNumb; i++)
        {
            if (iff.newform(iff.makeid('E','M','T','L')))
            {
                char    str[128];

                sprintf(str,"Error #%x while trying to create new texture form\n\n"
                            "Texture: %s",
                            (int)iff.error(),
                            txtName[i]);

                MessageBox(NULL,
                          str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
                return;
            }

            assert(txtEsch[i]);

            txtEsch[i]->lock();
            VngoTexture *ptr = txtEsch[i]->ptr;
            ASSERT(ptr);

            memset(&mhdr,0,sizeof(EschFileMtlMHDR));
            strncpy(mhdr.name,txtName[i],ESCH_MAX_NAME);
            mhdr.xsize = ptr->width;
            mhdr.ysize = ptr->height;
            mhdr.nframes = 1;
            mhdr.type = ESCH_MTL_TYPE_8BIT;
            mhdr.compress = ESCH_MTL_COMPRESS_RLE;

            if (iff.write(iff.makeid('M','H','D','R'),&mhdr,sizeof(EschFileMtlMHDR)))
            {
                char    str[128];

                sprintf(str,"Error #%x while trying to write texture header chunk\n\n"
                            "Texture: %s",
                            (int)iff.error(),
                            txtName[i]);

                MessageBox(NULL,
                           str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
                txtEsch[i]->unlock();
                return;
            }

            byte *work=new byte[mhdr.xsize*mhdr.ysize];
            if (!work)
            {
                MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                           "Out of Memory","Export Error",MB_OK | MB_ICONEXCLAMATION);
                return;
            }

            dword size=XFParseXEB::compress_rle_8bpp(mhdr.xsize,mhdr.ysize,
                                                     (byte*)ptr->tex,work);

            if (size)
            {
                if (iff.write(iff.makeid('B','O','D','Y'),work,size))
                {
                    char    str[128];

                    sprintf(str,"Error #%x while trying to write texture body chunk\n\n"
                                "Texture: %s",
                                (int)iff.error(),txtName[i]);

                    MessageBox(NULL,
                            str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
                    txtEsch[i]->unlock();
                    delete [] work;
                    return;
                }
            }
            else
            {
                delete [] work;

                if (iff.write(iff.makeid('B','O','D','Y'),ptr->tex,mhdr.xsize*mhdr.ysize))
                {
                    char    str[128];

                    sprintf(str,"Error #%x while trying to write texture body chunk\n\n"
                                "Texture: %s",
                                (int)iff.error(),txtName[i]);

                    MessageBox(NULL,
                            str,"Export Error",MB_OK | MB_ICONEXCLAMATION);
                    txtEsch[i]->unlock();
                    return;
                }
            }

            iff.leaveform();
            txtEsch[i]->unlock();
        }

        status |= EXPSTAT_TXTS;
    }

//ÄÄÄ End form
    iff.leaveform();
    iff.close();

    TerrExpStatDlg dlg;

    dlg.sflags = status;
    dlg.DoModal();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - ComputeNormals                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::ComputeNormals(dword flags)
{
    int             x, y, cx, cy;
    double          cenh, mag;
    double          v1[3], v2[3], sum[3];
    byte            *sptr;
    EschVector      *dptr;

    ASSERT(width && depth && hsurfnorml);
    ASSERT((flags & NORMALS_SMOOTH) || (flags & NORMALS_FLAT));

//ÄÄÄ Setup memory for normals
    dword surfsize = (width * depth) >> (surfshift*2);

    EschVector  *nml;
    if (flags & NORMALS_SMOOTH)
    {
        nml = (EschVector*)ivory_hlock(hsurfnorml);
    }
    else if (flags & NORMALS_FLAT)
    {
        nml = (EschVector*)ivory_hlock(hsurfnormlflat);
    }

    if (!nml)
    {
        MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                  "Could not lock normals memory",
                  "Compute Normals Error",MB_OK | MB_ICONEXCLAMATION);
        return;
    }
    memset(nml,0,surfsize*sizeof(EschVector));

//ÄÄÄ Compute normals
    ProgressDlg   dlg;
    dlg.m_pbar.SetRange(0,depth);
    dlg.m_pbar.SetPos(0);
    dlg.SetWindowText("Computing Surface Normals...");
    dlg.ShowWindow(SW_SHOW);

    for(y=0, cy=0; y < depth;)
    {
        dlg.m_pbar.SetPos(y);
        for(x=0, cx=0,
            sptr=hfield + (y*width),
            dptr=(nml)+(cy*(width >> surfshift));
            x < width; )
        {
            sum[0]=sum[1]=sum[2]=0.0;

            cenh = (double)(htable[*sptr]);
            double tv[3];
            if (y < depth-1 && x < width-1)
            {
                // Face 1 (N - NE)
                v1[0] = 0.0;
                v1[1] = (double)(htable[*(sptr + width)]) - cenh;
                v1[2] = (double)scale;

                v2[0] = (double)scale;
                v2[1] = (double)(htable[*(sptr + width + 1)]) - cenh;
                v2[2] = (double)scale;

                // Cross-product
                tv[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
                tv[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
                tv[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
                mag = sqrt (tv[0] * tv[0] + tv[1]*tv[1] + tv[2]*tv[2]);

                if (mag <=0)
                {
                    sum[0] += 0;
                    sum[1] += 1;
                    sum[0] += 0;
                }
                else
                {
                    sum[0] += (tv[0] / mag);
                    sum[1] += (tv[1] / mag);
                    sum[2] += (tv[2] / mag);
                }

                // Face 2 (NE - E)
                v1[0] = (double)scale;
                v1[1] = (double)(htable[*(sptr + width + 1)]) - cenh;
                v1[2] = (double)scale;

                v2[0] = (double)scale;
                v2[1] = (double)(htable[*(sptr + 1)]) - cenh;
                v2[2] = 0.0;

                // Cross-product
                tv[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
                tv[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
                tv[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
                mag = sqrt (tv[0] * tv[0] + tv[1]*tv[1] + tv[2]*tv[2]);

                if (mag <=0)
                {
                    sum[0] += 0;
                    sum[1] += 1;
                    sum[0] += 0;
                }
                else
                {
                    sum[0] += (tv[0] / mag);
                    sum[1] += (tv[1] / mag);
                    sum[2] += (tv[2] / mag);
                }
            }

            if ((y > 0 && x < width-1) && (flags & NORMALS_SMOOTH))
            {
                // Face 3 (E - SE)
                v1[0] = (double)scale;
                v1[1] = (double)(htable[*(sptr + 1)]) - cenh;
                v1[2] = 0.0;

                v2[0] = 30.0;
                v2[1] = (double)(htable[*(sptr - width + 1)]) * 16 - cenh;
                v2[2] = -(double)scale;

                // Cross-product
                tv[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
                tv[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
                tv[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
                mag = sqrt (tv[0] * tv[0] + tv[1]*tv[1] + tv[2]*tv[2]);

                if (mag <=0)
                {
                    sum[0] += 0;
                    sum[1] += 1;
                    sum[0] += 0;
                }
                else
                {
                    sum[0] += (tv[0] / mag);
                    sum[1] += (tv[1] / mag);
                    sum[2] += (tv[2] / mag);
                }

                // Face 4 (SE - S)
                v1[0] = (double)scale;
                v1[1] = (double)(htable[*(sptr - width + 1)]) - cenh;
                v1[2] = -(double)scale;

                v2[0] = 0.0;
                v2[1] = (double)(htable[*(sptr -width)]) - cenh;
                v2[2] = -(double)scale;

                // Cross-product
                tv[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
                tv[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
                tv[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
                mag = sqrt (tv[0] * tv[0] + tv[1]*tv[1] + tv[2]*tv[2]);

                if (mag <=0)
                {
                    sum[0] += 0;
                    sum[1] += 1;
                    sum[0] += 0;
                }
                else
                {
                    sum[0] += (tv[0] / mag);
                    sum[1] += (tv[1] / mag);
                    sum[2] += (tv[2] / mag);
                }
            }

            if ((y > 0 && x > 0) && (flags & NORMALS_SMOOTH))
            {
                // Face 5 (S - SW)
                v1[0] = 0.0;
                v1[1] = (double)(htable[*(sptr - width)]) - cenh;
                v1[2] = -(double)scale;

                v2[0] = -(double)scale;
                v2[1] = (float)(htable[*(sptr - width - 1)]) - cenh;
                v2[2] = -(double)scale;

                // Cross-product
                tv[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
                tv[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
                tv[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
                mag = sqrt (tv[0] * tv[0] + tv[1]*tv[1] + tv[2]*tv[2]);

                if (mag <=0)
                {
                    sum[0] += 0;
                    sum[1] += 1;
                    sum[0] += 0;
                }
                else
                {
                    sum[0] += (tv[0] / mag);
                    sum[1] += (tv[1] / mag);
                    sum[2] += (tv[2] / mag);
                }

                // Face 6 (SW - E)
                v1[0] = -(double)scale;
                v1[1] = (double)(htable[*(sptr - width - 1)]) - cenh;
                v1[2] = -(double)scale;

                v2[0] = -(double)scale;
                v2[1] = (double)(htable[*(sptr - 1)]) - cenh;
                v2[2] = 0.0;

                // Cross-product
                tv[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
                tv[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
                tv[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
                mag = sqrt (tv[0] * tv[0] + tv[1]*tv[1] + tv[2]*tv[2]);

                if (mag <=0)
                {
                    sum[0] += 0;
                    sum[1] += 1;
                    sum[0] += 0;
                }
                else
                {
                    sum[0] += (tv[0] / mag);
                    sum[1] += (tv[1] / mag);
                    sum[2] += (tv[2] / mag);
                }
            }

            if ((y < depth-1 && x > 0) && (flags & NORMALS_SMOOTH))
            {
                // Face 7 (E - NW)
                v1[0] = -(double)scale;
                v1[1] = (double)(htable[*(sptr - 1)]) - cenh;
                v1[2] = 0.0;

                v2[0] = -(double)scale;
                v2[1] = (double)(htable[*(sptr + width - 1)]) - cenh;
                v2[2] = 30.0;

                // Cross-product
                tv[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
                tv[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
                tv[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
                mag = sqrt (tv[0] * tv[0] + tv[1]*tv[1] + tv[2]*tv[2]);

                if (mag <=0)
                {
                    sum[0] += 0;
                    sum[1] += 1;
                    sum[0] += 0;
                }
                else
                {
                    sum[0] += (tv[0] / mag);
                    sum[1] += (tv[1] / mag);
                    sum[2] += (tv[2] / mag);
                }

                // Face 8 (NW - N)
                v1[0] = -(double)scale;
                v1[1] = (double)(htable[*(sptr + width - 1)]) - cenh;
                v1[2] = (double) scale;

                v2[0] = 0.0;
                v2[1] = (double)(htable[*(sptr + width)]) - cenh;
                v2[2] = (double)scale;

                // Cross-product
                tv[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
                tv[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
                tv[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);
                mag = sqrt (tv[0] * tv[0] + tv[1]*tv[1] + tv[2]*tv[2]);

                if (mag <=0)
                {
                    sum[0] += 0;
                    sum[1] += 1;
                    sum[0] += 0;
                }
                else
                {
                    sum[0] += (tv[0] / mag);
                    sum[1] += (tv[1] / mag);
                    sum[2] += (tv[2] / mag);
                }
            }

            // Compute & Store final normal
            mag = sqrt(sum[0]*sum[0] + sum[1]*sum[1] + sum[2]*sum[2]);

            if (mag <= 0)
            {
                dptr->i = 0;
                dptr->j = 1;
                dptr->k = 0;
            }
            else
            {
                dptr->i = (float)(sum[0] / mag);
                dptr->j = (float)(sum[1] / mag);
                dptr->k = (float)(sum[2] / mag);
            }

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

    if (flags & NORMALS_SMOOTH)
        ivory_hunlock(hsurfnorml);
    else if (flags & NORMALS_FLAT)
        ivory_hunlock(hsurfnormlflat);


    SetModifiedFlag();
    SetLightsModifiedFlag();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - LightTerrain                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::LightTerrain()
{
    if (!lightsdirty || !lights || !cam.vport)
        return;

    EschTerrain terr;
    terr.width = width;
    terr.depth = depth;
    terr.surfratio = surfratio;
    terr.surfshift = surfshift;
    terr.set_scale(scale);
    terr.hfield = hfield;
    terr.htable = htable;
    terr.surfinfo = surfinfo;
    terr.hsurfnorml = hsurfnorml;
    terr.set_origin(orgx, orgy, orgz);
    terr.compute_shades(&cam,lights);

    lightsdirty = FALSE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - GetMinMaxElevations                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::GetMinMaxElevations(float &min, float &max)
{
    if (!htable)
        return;

    min = FLT_MAX;
    max = -FLT_MAX;

    for(int i=0; i < 256; i++)
    {
        if (htable[i] < min)
            min = htable[i];
        if (htable[i] > max)
            max = htable[i];
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - SetBaseElevation                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::SetBaseElevation(float newbase)
{
    if (!htable)
        return;

    float base=FLT_MAX;
    for(int i=0; i < 256; i++)
    {
        if (htable[i] < base)
            base = htable[i];
    }

    if (base == newbase)
        return;

    float adjust = base - newbase;

    for(i=0; i < 256; i++)
    {
        htable[i] = htable[i] - adjust;
    }

    UpdateAllViews(NULL,HINT_UPDATECOLR,NULL);
    SetModifiedFlag();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - PushUndo                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::PushUndo()
{
    dword surfsize = (width * depth) >> (surfshift*2);

    ASSERT(surfinfo != NULL && undo_surfinfo != NULL);
    memcpy(undo_surfinfo,surfinfo,surfsize * sizeof(esch_surf_type));

    ASSERT(surfcolr != NULL && undo_surfcolr != NULL);
    memcpy(undo_surfcolr,surfcolr,surfsize * sizeof(dword));

    undo_valid=TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - PopUndo                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::PopUndo()
{
    if (!undo_valid)
        return;

    dword surfsize = (width * depth) >> (surfshift*2);

    ASSERT(surfinfo != NULL && undo_surfinfo != NULL);
    memcpy(surfinfo,undo_surfinfo,surfsize * sizeof(esch_surf_type));

    ASSERT(surfcolr != NULL && undo_surfcolr != NULL);
    memcpy(surfcolr,undo_surfcolr,surfsize * sizeof(dword));

    undo_valid=FALSE;

    UpdateAllViews(NULL,HINT_UPDATECOLR,NULL);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - Flip                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::Flip(BOOL horz)
{
    ulong i, j;

    ushort iwidth = width >> surfshift;
    ushort idepth = depth >> surfshift;

    undo_valid=FALSE;

    ASSERT(hfield && surfinfo && surfcolr && hsurfnorml && hsurfnormlflat);

//ÄÄ Flip heights
    {
        byte *sptr, *dptr;
        byte *t = new byte[(horz) ? depth : width];
        ASSERT(t);

        if (horz)
        {
            for(i=0; i < (ulong)(width >> 1); i++)
            {
                for(j=0, sptr=hfield+i, dptr=t;
                    j < depth; j++, sptr += width, dptr++)
                    *dptr = *sptr;

                for(j=0, sptr=hfield+(width-i-1), dptr=hfield+i;
                    j < depth; j++, sptr += width, dptr += width)
                    *dptr = *sptr;

                for(j=0, sptr=t, dptr=hfield+(width-i-1);
                    j < depth; j++, sptr++, dptr += width)
                    *dptr = *sptr;
            }
        }
        else
        {
            for(i=0; i < (ulong)(depth >> 1); i++)
            {
                for(j=0, sptr=hfield+(i*width), dptr=t;
                    j < width; j++, sptr++, dptr++)
                    *dptr = *sptr;

                for(j=0, sptr=hfield+((depth-i-1)*width), dptr=hfield+(i*width);
                    j < width; j++, sptr++, dptr++)
                    *dptr = *sptr;

                for(j=0, sptr=t, dptr=hfield+((depth-i-1)*width);
                    j < width; j++, sptr++, dptr++)
                    *dptr = *sptr;
            }
        }

        delete [] t;
    }

//ÄÄ Flip smooth normals
    {
        EschVector *nml = (EschVector*)ivory_hlock(hsurfnorml);
        if (!nml)
        {
            MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                      "Could not lock normals memory",
                      "Flip Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        EschVector *sptr, *dptr;
        EschVector *t = new EschVector[(horz) ? idepth : iwidth];
        ASSERT(t);

        if (horz)
        {
            for(i=0; i < (ulong)(iwidth >> 1); i++)
            {
                for(j=0, sptr=nml+i, dptr=t;
                    j < idepth; j++, sptr += iwidth, dptr++)
                    *dptr = *sptr;

                for(j=0, sptr=nml+(iwidth-i-1), dptr=nml+i;
                    j < idepth; j++, sptr += iwidth, dptr += iwidth)
                    *dptr = *sptr;

                for(j=0, sptr=t, dptr=nml+(iwidth-i-1);
                    j < idepth; j++, sptr++, dptr += iwidth)
                    *dptr = *sptr;
            }
        }
        else
        {
            for(i=0; i < (ulong)(idepth >> 1); i++)
            {
                for(j=0, sptr=nml+(i*iwidth), dptr=t;
                    j < iwidth; j++, sptr++, dptr++)
                    *dptr = *sptr;

                for(j=0, sptr=nml+((idepth-i-1)*iwidth), dptr=nml+(i*iwidth);
                    j < iwidth; j++, sptr++, dptr++)
                    *dptr = *sptr;

                for(j=0, sptr=t, dptr=nml+((idepth-i-1)*iwidth);
                    j < iwidth; j++, sptr++, dptr++)
                    *dptr = *sptr;
            }
        }

        delete [] t;

        ivory_hunlock(hsurfnorml);
    }

//ÄÄ Flip flat normals
    {
        EschVector *nml = (EschVector*)ivory_hlock(hsurfnormlflat);
        if (!nml)
        {
            MessageBox((AfxGetMainWnd()) ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
                      "Could not lock normals memory",
                      "Flip Error",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        EschVector *sptr, *dptr;
        EschVector *t = new EschVector[(horz) ? idepth : iwidth];
        ASSERT(t);

        if (horz)
        {
            for(i=0; i < (ulong)(iwidth >> 1); i++)
            {
                for(j=0, sptr=nml+i, dptr=t;
                    j < idepth; j++, sptr += iwidth, dptr++)
                    *dptr = *sptr;

                for(j=0, sptr=nml+(iwidth-i-1), dptr=nml+i;
                    j < idepth; j++, sptr += iwidth, dptr += iwidth)
                    *dptr = *sptr;

                for(j=0, sptr=t, dptr=nml+(iwidth-i-1);
                    j < idepth; j++, sptr++, dptr += iwidth)
                    *dptr = *sptr;
            }
        }
        else
        {
            for(i=0; i < (ulong)(idepth >> 1); i++)
            {
                for(j=0, sptr=nml+(i*iwidth), dptr=t;
                    j < iwidth; j++, sptr++, dptr++)
                    *dptr = *sptr;

                for(j=0, sptr=nml+((idepth-i-1)*iwidth), dptr=nml+(i*iwidth);
                    j < iwidth; j++, sptr++, dptr++)
                    *dptr = *sptr;

                for(j=0, sptr=t, dptr=nml+((idepth-i-1)*iwidth);
                    j < iwidth; j++, sptr++, dptr++)
                    *dptr = *sptr;
            }
        }

        delete [] t;

        ivory_hunlock(hsurfnormlflat);
    }


//ÄÄ Flip surface info
    {
        esch_surf_type *sptr, *dptr;
        esch_surf_type *t = new esch_surf_type[(horz) ? idepth : iwidth];
        ASSERT(t);

        if (horz)
        {
            for(i=0; i < (ulong)(iwidth >> 1); i++)
            {
                for(j=0, sptr=surfinfo+i, dptr=t;
                    j < idepth; j++, sptr += iwidth, dptr++)
                    *dptr = *sptr;

                for(j=0, sptr=surfinfo+(iwidth-i-1), dptr=surfinfo+i;
                    j < idepth; j++, sptr += iwidth, dptr += iwidth)
                    *dptr = *sptr;

                for(j=0, sptr=t, dptr=surfinfo+(iwidth-i-1);
                    j < idepth; j++, sptr++, dptr += iwidth)
                    *dptr = *sptr;
            }
        }
        else
        {
            for(i=0; i < (ulong)(idepth >> 1); i++)
            {
                for(j=0, sptr=surfinfo+(i*iwidth), dptr=t;
                    j < iwidth; j++, sptr++, dptr++)
                    *dptr = *sptr;

                for(j=0, sptr=surfinfo+((idepth-i-1)*iwidth), dptr=surfinfo+(i*iwidth);
                    j < iwidth; j++, sptr++, dptr++)
                    *dptr = *sptr;

                for(j=0, sptr=t, dptr=surfinfo+((idepth-i-1)*iwidth);
                    j < iwidth; j++, sptr++, dptr++)
                    *dptr = *sptr;
            }
        }

        delete [] t;
    }

//ÄÄ Flip surface colors
    {
        dword *sptr, *dptr;
        dword *t = new dword[(horz) ? idepth : iwidth];
        ASSERT(t);

        if (horz)
        {
            for(i=0; i < (ulong)(iwidth >> 1); i++)
            {
                for(j=0, sptr=surfcolr+i, dptr=t;
                    j < idepth; j++, sptr += iwidth, dptr++)
                    *dptr = *sptr;

                for(j=0, sptr=surfcolr+(iwidth-i-1), dptr=surfcolr+i;
                    j < idepth; j++, sptr += iwidth, dptr += iwidth)
                    *dptr = *sptr;

                for(j=0, sptr=t, dptr=surfcolr+(iwidth-i-1);
                    j < idepth; j++, sptr++, dptr += iwidth)
                    *dptr = *sptr;
            }
        }
        else
        {
            for(i=0; i < (ulong)(idepth >> 1); i++)
            {
                for(j=0, sptr=surfcolr+(i*iwidth), dptr=t;
                    j < iwidth; j++, sptr++, dptr++)
                    *dptr = *sptr;

                for(j=0, sptr=surfcolr+((idepth-i-1)*iwidth), dptr=surfcolr+(i*iwidth);
                    j < iwidth; j++, sptr++, dptr++)
                    *dptr = *sptr;

                for(j=0, sptr=t, dptr=surfcolr+((idepth-i-1)*iwidth);
                    j < iwidth; j++, sptr++, dptr++)
                    *dptr = *sptr;
            }
        }

        delete [] t;
    }

//ÄÄ Update
    SetModifiedFlag();
    SetLightsModifiedFlag();
    UpdateAllViews(NULL,HINT_UPDATETERR|HINT_UPDATECOLR,NULL);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - Rotate                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::Rotate(BOOL right)
{
    if (width != depth)
    {
        if (MessageBox(NULL,
                       "The terrain data is not square,\n"
                       "so this operation may lose data\n\n"
                       "This operation cannot be undone...\n"
                       "Do you wish to continue?",
                       "Escher Terrain Rotate Warning",
                       MB_YESNO | MB_ICONQUESTION) == IDNO)
            return;
    }

    ulong i, j;

    ushort iwidth = width >> surfshift;
    ushort idepth = depth >> surfshift;

    dword surfsize = (width * depth) >> (surfshift*2);

    undo_valid=FALSE;

    ASSERT(hfield && surfinfo && surfcolr && hsurfnorml && hsurfnormlflat);

//ÄÄ Rotate heights
    {
        byte *t = new byte[width*depth];
        ASSERT(t);
        memset(t,0,width*depth);

        for(j=0; j < (ulong)depth; j++)
        {
            byte *sptr=hfield+((depth-j-1)*width);

            if (j >= width)
                break;

            if (right)
            {
                byte *dptr=t+(width-j-1)+(depth-1)*width;
                for(i=0; i < (ulong)width;
                    i++, sptr++, dptr -= width)
                {
                    if (i >= depth)
                        break;

                    *dptr = *sptr;
                }
            }
            else
            {
                byte *dptr=t+j;
                for(i=0; i < (ulong)width;
                    i++, sptr++, dptr += width)
                {
                    if (i >= depth)
                        break;

                    *dptr = *sptr;
                }
            }
        }

        delete [] hfield;
        hfield=t;
    }

//ÄÄ Rotate smooth normals
    {
        IvoryHandle th = ivory_halloc((ulong)(surfsize * sizeof(EschVector)));
        ASSERT(th);

        EschVector *t = (EschVector*) ivory_hlock(th);
        ASSERT(t);
        memset(t,0,(ulong)(surfsize * sizeof(EschVector)));

        EschVector *nml = (EschVector*) ivory_hlock(hsurfnorml);
        ASSERT(nml);

        for(j=0; j < (ulong)idepth; j++)
        {
            EschVector *sptr=nml+((idepth-j-1)*iwidth);

            if (j >= iwidth)
                break;

            if (right)
            {
                EschVector *dptr=t+(iwidth-j-1)+(idepth-1)*iwidth;
                for(i=0; i < (ulong)iwidth;
                    i++, sptr++, dptr -= iwidth)
                {
                    if (i >= idepth)
                        break;

                    *dptr = *sptr;
                }
            }
            else
            {
                EschVector *dptr=t+j;
                for(i=0; i < (ulong)iwidth;
                    i++, sptr++, dptr += iwidth)
                {
                    if (i >= idepth)
                        break;

                    *dptr = *sptr;
                }
            }
        }

        ivory_hunlock(hsurfnorml);
        ivory_hfree(&hsurfnorml);
        hsurfnorml=th;
        ivory_hunlock(th);
    }

//ÄÄ Rotate flat normals
    {
        IvoryHandle th = ivory_halloc((ulong)(surfsize * sizeof(EschVector)));
        ASSERT(th);

        EschVector *t = (EschVector*) ivory_hlock(th);
        ASSERT(t);
        memset(t,0,(ulong)(surfsize * sizeof(EschVector)));

        EschVector *nml = (EschVector*) ivory_hlock(hsurfnormlflat);
        ASSERT(nml);

        for(j=0; j < (ulong)idepth; j++)
        {
            EschVector *sptr=nml+((idepth-j-1)*iwidth);

            if (j >= iwidth)
                break;

            if (right)
            {
                EschVector *dptr=t+(iwidth-j-1)+(idepth-1)*iwidth;
                for(i=0; i < (ulong)iwidth;
                    i++, sptr++, dptr -= iwidth)
                {
                    if (i >= idepth)
                        break;

                    *dptr = *sptr;
                }
            }
            else
            {
                EschVector *dptr=t+j;
                for(i=0; i < (ulong)iwidth;
                    i++, sptr++, dptr += iwidth)
                {
                    if (i >= idepth)
                        break;

                    *dptr = *sptr;
                }
            }
        }

        ivory_hunlock(hsurfnormlflat);
        ivory_hfree(&hsurfnormlflat);
        hsurfnormlflat=th;
        ivory_hunlock(th);
    }


//ÄÄ Rotate surface info
    {
        esch_surf_type *t = new esch_surf_type[iwidth*idepth];
        ASSERT(t);
        memset(t,0,surfsize * sizeof(esch_surf_type));

        for(j=0; j < (ulong)idepth; j++)
        {
            esch_surf_type *sptr=surfinfo+((idepth-j-1)*iwidth);

            if (j >= iwidth)
                break;

            if (right)
            {
                esch_surf_type *dptr=t+(iwidth-j-1)+(idepth-1)*iwidth;
                for(i=0; i < (ulong)iwidth;
                    i++, sptr++, dptr -= iwidth)
                {
                    if (i >= idepth)
                        break;

                    *dptr = *sptr;
                }
            }
            else
            {
                esch_surf_type *dptr=t+j;
                for(i=0; i < (ulong)iwidth;
                    i++, sptr++, dptr += iwidth)
                {
                    if (i >= idepth)
                        break;

                    *dptr = *sptr;
                }
            }
        }

        delete [] surfinfo;
        surfinfo=t;
    }

//ÄÄ Rotate surface colors
    {
        dword *t = new dword[iwidth*idepth];
        ASSERT(t);
        memset(t,0,surfsize * sizeof(dword));

        for(j=0; j < (ulong)idepth; j++)
        {
            dword *sptr=surfcolr+((idepth-j-1)*iwidth);

            if (j >= iwidth)
                break;

            if (right)
            {
                dword *dptr=t+(iwidth-j-1)+(idepth-1)*iwidth;
                for(i=0; i < (ulong)iwidth;
                    i++, sptr++, dptr -= iwidth)
                {
                    if (i >= idepth)
                        break;

                    *dptr = *sptr;
                }
            }
            else
            {
                dword *dptr=t+j;
                for(i=0; i < (ulong)iwidth;
                    i++, sptr++, dptr += iwidth)
                {
                    if (i >= idepth)
                        break;

                    *dptr = *sptr;
                }
            }
        }

        delete [] surfcolr;
        surfcolr=t;
    }

//ÄÄ Update
    SetModifiedFlag();
    SetLightsModifiedFlag();
    UpdateAllViews(NULL,HINT_UPDATETERR|HINT_UPDATECOLR,NULL);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - UITerrainProperities                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::UITerrainProperities(CWnd *parent, UINT ipage, int edit)
{
//ÄÄÄ General
    TerrPropGenPage gdlg;

    gdlg.m_edit = edit;
    gdlg.m_name = name;
    gdlg.m_width = width;
    gdlg.m_depth = depth;
    gdlg.m_surfratio = surfratio;
    gdlg.m_scale = (UINT)(int)scale;
    gdlg.m_autoCenterOrg = autocenter;
    gdlg.m_orgx = orgx;
    gdlg.m_orgy = orgy;
    gdlg.m_orgz = orgz;

//ÄÄÄ Height-colors
    TerrPropHColrPage hdlg;
    hdlg.m_blue = color_bands[0];
    hdlg.m_lblue = color_bands[1];
    hdlg.m_white = color_bands[2];
    hdlg.m_green = color_bands[3];
    hdlg.m_lgreen = color_bands[4];
    hdlg.m_yellow = color_bands[5];
    hdlg.m_lorange = color_bands[6];
    hdlg.m_orange = color_bands[7];
    hdlg.m_lbrown = color_bands[8];
    hdlg.m_brown = color_bands[9];
    hdlg.m_red = color_bands[10];

//ÄÄÄ Height-table
    TerrPropHTablePage  htdlg;
    if (htable && !edit)
    {
        for(long i=0; i < 256; i++)
            htdlg.htable[i] = htable[i];
    }

//ÄÄÄ Misc
    TerrPropMiscPage mdlg;

    mdlg.m_desc = desc;
    mdlg.m_auth = auth;
    mdlg.m_copy = copy;

//ÄÄÄ Handle Display
    CPropertySheet sh("Terrain Properties",parent,ipage);

    sh.AddPage(&gdlg);      // General
    sh.AddPage(&hdlg);      // Height-colors
    if (htable && !edit)
        sh.AddPage(&htdlg); // Height-table
    sh.AddPage(&mdlg);      // Misc

//ÄÄÄ Store results, if OK
    if (sh.DoModal() == IDOK)
    {
        //ÄÄÄ General
        memset(name,0,sizeof(name));
        strncpy(name,gdlg.m_name,ESCH_MAX_NAME-1);

        width = (ushort)gdlg.m_width;
        depth = (ushort)gdlg.m_depth;
        surfratio = (ushort)gdlg.m_surfratio;
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
        scale = (float)(int)gdlg.m_scale;

        autocenter = (gdlg.m_autoCenterOrg) ? 1 : 0;
        if (autocenter)
        {
            orgx = -(float)(width/2)*scale;
            orgy = 0;
            orgz = -(float)(depth/2)*scale;
        }
        else
        {
            orgx = gdlg.m_orgx;
            orgy = gdlg.m_orgy;
            orgz = gdlg.m_orgz;
        }

        //ÄÄÄ Height-colors
        color_bands[0] = hdlg.m_blue;
        color_bands[1] = hdlg.m_lblue;
        color_bands[2] = hdlg.m_white;
        color_bands[3] = hdlg.m_green;
        color_bands[4] = hdlg.m_lgreen;
        color_bands[5] = hdlg.m_yellow;
        color_bands[6] = hdlg.m_lorange;
        color_bands[7] = hdlg.m_orange;
        color_bands[8] = hdlg.m_lbrown;
        color_bands[9] = hdlg.m_brown;
        color_bands[10] = hdlg.m_red;

        //ÄÄÄ Height table
        if (htable && !edit && htdlg.changed)
        {
            for(long i=0; i < 256; i++)
                htable[i] = htdlg.htable[i];

            ComputeNormals(NORMALS_SMOOTH);
            ComputeNormals(NORMALS_FLAT);
        }

        //ÄÄÄ Misc
        memset(desc,0,sizeof(desc));
        strncpy(desc,mdlg.m_desc,255);

        memset(auth,0,sizeof(auth));
        strncpy(auth,mdlg.m_auth,255);

        memset(copy,0,sizeof(copy));
        strncpy(copy,mdlg.m_copy,255);

        //ÄÄÄ Update views
        SetModifiedFlag();
        SetLightsModifiedFlag();
        if (!edit)
            UpdateAllViews(NULL,HINT_UPDATETERR|HINT_UPDATECOLR|HINT_UPDATELIGHTS,NULL);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - UISurfProperities                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::UISurfProperties(CWnd *parent, UINT xpos, UINT dpos, UINT ipage)
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

//ÄÄÄ General
    SurfPropGenPage gdlg;
    gdlg.setup(this);
    gdlg.m_xloc = xpos;
    gdlg.m_dloc = dpos;

    gdlg.m_color = *colr;

    if (surf->flags & ESCH_SURF_CINDISTXT)
    {
        gdlg.m_txt = surf->cind;
    }

    gdlg.m_indistxt = (surf->flags & ESCH_SURF_CINDISTXT) ? 1 : 0;
    gdlg.m_hidden = (surf->flags & ESCH_SURF_HIDDEN) ? 1 : 0;
    gdlg.m_cbit4 = (surf->flags & ESCH_SURF_CBIT4) ? 1 : 0;
    gdlg.m_cbit11 = (surf->flags & ESCH_SURF_CBIT11) ? 1 : 0;
    gdlg.m_cbit12 = (surf->flags & ESCH_SURF_CBIT12) ? 1 : 0;

    gdlg.m_flipu = (surf->flags & ESCH_SURF_FLIPU) ? 1 : 0;
    gdlg.m_flipv = (surf->flags & ESCH_SURF_FLIPV) ? 1 : 0;

    assert(ESCH_SURF_TILE1 == 0x10 && ESCH_SURF_TILE2 == 0x20 && ESCH_SURF_TILE3 == 0x40);
    gdlg.m_tile  = (surf->flags >> 4) & 0x7;

    gdlg.m_notile = (surf->flags & ESCH_SURF_NOTILE) ? 1 : 0;
    gdlg.m_highonly = (surf->flags & ESCH_SURF_HIGHONLY) ? 1 : 0;

    gdlg.m_app0 = (surf->flags & ESCH_SURF_APP0) ? 1 : 0;
    gdlg.m_app1 = (surf->flags & ESCH_SURF_APP1) ? 1 : 0;
    gdlg.m_app2 = (surf->flags & ESCH_SURF_APP2) ? 1 : 0;
    gdlg.m_app3 = (surf->flags & ESCH_SURF_APP3) ? 1 : 0;

//ÄÄÄ Handle Display
    CPropertySheet sh("Surface Properties",parent,ipage);
    sh.AddPage(&gdlg);      // General

//ÄÄÄ Store results, if OK
    if (sh.DoModal() == IDOK)
    {
        PushUndo();

        //ÄÄÄ General
        *colr = gdlg.m_color;

        if (gdlg.m_txt)
        {
            gdlg.m_indistxt = 1;
            surf->cind = gdlg.m_txt;
        }
        else
        {
            gdlg.m_indistxt = 0;
            surf->cind = (byte)palette.get_index((VngoColor24bit)gdlg.m_color);
        }

        surf->flags = ((gdlg.m_indistxt) ? ESCH_SURF_CINDISTXT : 0)
                      | ((gdlg.m_hidden) ? ESCH_SURF_HIDDEN : 0)
                      | ((gdlg.m_cbit4) ? ESCH_SURF_CBIT4 : 0)
                      | ((gdlg.m_cbit11) ? ESCH_SURF_CBIT11 : 0)
                      | ((gdlg.m_cbit12) ? ESCH_SURF_CBIT12 : 0)
                      | ((gdlg.m_flipu) ? ESCH_SURF_FLIPU : 0)
                      | ((gdlg.m_flipv) ? ESCH_SURF_FLIPV : 0)
                      | ((gdlg.m_tile << 4) & 0x70)
                      | ((gdlg.m_notile) ? ESCH_SURF_NOTILE : 0)
                      | ((gdlg.m_highonly) ? ESCH_SURF_HIGHONLY : 0)
                      | ((gdlg.m_app0) ? ESCH_SURF_APP0 : 0)
                      | ((gdlg.m_app1) ? ESCH_SURF_APP1 : 0)
                      | ((gdlg.m_app2) ? ESCH_SURF_APP2 : 0)
                      | ((gdlg.m_app3) ? ESCH_SURF_APP3 : 0);

        //ÄÄÄ Update views
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
        PushUndo();

        //ÄÄÄ Save values
        *colr = dlg.GetColor();
        surf->cind = (byte)palette.get_index((VngoColor24bit)dlg.GetColor());

        SetModifiedFlag();
        UpdateAllViews(NULL,HINT_UPDATECOLR,NULL);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - UILightProperties                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::UILightProperties(CWnd *parent, UINT ipage)
{
    if (!lights)
        return;

    int old_type;

//ÄÄÄ General
    LightPropGenPage   gdlg;

    gdlg.m_intensity = lights->get_intensity();
    switch (lights->get_type())
    {
        case ESCH_LGTT_VECTOR:
            gdlg.m_type = 0;
            break;
        case ESCH_LGTT_POINT:
            gdlg.m_type = 1;
            break;
        case ESCH_LGTT_ATTEN:
            gdlg.m_type = 2;
            break;
        case ESCH_LGTT_SPOT:
            gdlg.m_type = 3;
            break;
        default:
            ASSERT(0);
    }
    old_type = gdlg.m_type;

    gdlg.m_atten = (lights->flags & ESCH_LGT_ATTEN) ? 1 : 0;
    switch (lights->get_type())
    {
        case ESCH_LGTT_VECTOR:
            gdlg.m_xiValue = ((EschVectorLight*)lights)->dir.i;
            gdlg.m_yjValue = ((EschVectorLight*)lights)->dir.j;
            gdlg.m_zkValue = ((EschVectorLight*)lights)->dir.k;
            break;
        case ESCH_LGTT_POINT:
        case ESCH_LGTT_ATTEN:
        case ESCH_LGTT_SPOT:
            gdlg.m_xiValue = ((EschPointLight*)lights)->pos.x;
            gdlg.m_yjValue = ((EschPointLight*)lights)->pos.y;
            gdlg.m_zkValue = ((EschPointLight*)lights)->pos.z;
            break;
    }

//ÄÄÄ Extra
    LightPropExtraPage  xdlg;

    switch (lights->get_type())
    {
        case ESCH_LGTT_ATTEN:
            xdlg.m_inner = ((EschAttenLight*)lights)->inner;
            xdlg.m_outer = ((EschAttenLight*)lights)->outer;
            break;
        case ESCH_LGTT_SPOT:
            xdlg.m_diri = ((EschSpotLight*)lights)->dir.i;
            xdlg.m_dirj = ((EschSpotLight*)lights)->dir.j;
            xdlg.m_dirk = ((EschSpotLight*)lights)->dir.k;
            xdlg.m_hotspot = ((EschSpotLight*)lights)->hotspot;
            xdlg.m_falloff = ((EschSpotLight*)lights)->falloff;
            xdlg.m_inner = ((EschSpotLight*)lights)->inner;
            xdlg.m_outer = ((EschSpotLight*)lights)->outer;
            break;
    }

//ÄÄÄ Handle Display
    CPropertySheet sh("Render Light Properties",parent,ipage);
    sh.AddPage(&gdlg);      // General
    sh.AddPage(&xdlg);      // Extra

//ÄÄÄ Store results, if OK
    if (sh.DoModal() == IDOK)
    {
        if (old_type != gdlg.m_type)
        {
            delete (lights);
            switch (gdlg.m_type)
            {
                case 0:     // Vector
                    lights = new EschVectorLight;
                    break;
                case 1:     // Point
                    lights = new EschPointLight;
                    break;
                case 2:     // Atten
                    lights = new EschAttenLight;
                    break;
                case 3:     // Spot
                    lights = new EschSpotLight;
                    break;
                default:
                    ASSERT(0);
            }
        }

        //ÄÄÄ General
        lights->set_intensity(gdlg.m_intensity);
        switch (lights->get_type())
        {
            case ESCH_LGTT_VECTOR:
                ((EschVectorLight*)lights)->set_direction(gdlg.m_xiValue,
                                                          gdlg.m_yjValue,
                                                          gdlg.m_zkValue);
                break;
            case ESCH_LGTT_POINT:
            case ESCH_LGTT_ATTEN:
            case ESCH_LGTT_SPOT:
                ((EschPointLight*)lights)->set_position(gdlg.m_xiValue,
                                                        gdlg.m_yjValue,
                                                        gdlg.m_zkValue);
                break;
        }

        dword flags = lights->flags;
        if (gdlg.m_atten)
            flags |= ESCH_LGT_ATTEN;
        else
            flags &= ~ESCH_LGT_ATTEN;
        lights->set_flags(flags);

        //ÄÄÄ Extra
        switch (lights->get_type())
        {
            case ESCH_LGTT_ATTEN:
                ((EschAttenLight*)lights)->set_inner(xdlg.m_inner);
                ((EschAttenLight*)lights)->set_outer(xdlg.m_outer);
                break;
            case ESCH_LGTT_SPOT:
                ((EschSpotLight*)lights)->set_direction(xdlg.m_diri,
                                                        xdlg.m_dirj,
                                                        xdlg.m_dirk);
                ((EschSpotLight*)lights)->set_hotspot(xdlg.m_hotspot);
                ((EschSpotLight*)lights)->set_falloff(xdlg.m_falloff);
                ((EschSpotLight*)lights)->set_inner(xdlg.m_inner);
                ((EschSpotLight*)lights)->set_outer(xdlg.m_outer);
                break;
        }

        //ÄÄÄ Update views
        SetModifiedFlag();
        SetLightsModifiedFlag();
        UpdateAllViews(NULL,HINT_UPDATELIGHTS,NULL);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditDoc - UICameraProperties                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditDoc::UICameraProperties(CWnd *parent, UINT ipage)
{
//ÄÄÄ General
    CameraPropGenPage   gdlg;

    EschPoint       pt;
    cam.get_position(&pt);
    gdlg.m_xpos = pt.x;
    gdlg.m_ypos = pt.y;
    gdlg.m_zpos = pt.z;

        gdlg.m_diri = cam.eye.dir.i;
        gdlg.m_dirj = cam.eye.dir.j;
        gdlg.m_dirk = cam.eye.dir.k;

        gdlg.m_topi = cam.top.i;
        gdlg.m_topj = cam.top.j;
        gdlg.m_topk = cam.top.k;

    gdlg.m_fov = cam.fov;

//ÄÄÄ LOD
    CameraPropLODPage   ldlg;
    ldlg.m_lod = (lod_active) ? 1 : 0;
    ldlg.m_med = lod_medium;
    ldlg.m_low = lod_low;

//ÄÄÄ Misc
    CameraPropMiscPage  mdlg;
    mdlg.setup(this);
    mdlg.m_bcolor = cam_bcolor;
    mdlg.m_hither = cam.hither;
    mdlg.m_yon = cam.yon;
        mdlg.m_scalef = cam.factor;
    mdlg.m_hover = hover_offset;

//ÄÄÄ Extended
    CameraPropExPage        xdlg;
    xdlg.setup(this);
    xdlg.m_haze_active = (cam.vport->vflags & VNGO_HAZE_ON) ? 1 : 0;
    xdlg.haze_change = FALSE;
    xdlg.haze_color = cam_bcolor;
    xdlg.m_bg_active = (cam.bg_bitmap) ? 1 : 0;
    xdlg.bg_bm = (XFBitmap*)cam.app_data;

//ÄÄÄ Handle Display
    CPropertySheet sh("Render View Properties",parent,ipage);
    sh.AddPage(&gdlg);      // General
    sh.AddPage(&ldlg);      // LOD
    sh.AddPage(&mdlg);      // Misc
    sh.AddPage(&xdlg);      // Extended

//ÄÄÄ Store results, if OK
    if (sh.DoModal() == IDOK)
    {
        //ÄÄÄ General
        cam.set_position(gdlg.m_xpos,gdlg.m_ypos,gdlg.m_zpos);
        cam.set_vects(gdlg.m_topi,gdlg.m_topj,gdlg.m_topk,
                      gdlg.m_diri,gdlg.m_dirj,gdlg.m_dirk);
        cam.set_fov(gdlg.m_fov);

        //ÄÄÄ LOD
        lod_active = ldlg.m_lod;
        lod_medium = ldlg.m_med;
        lod_low = ldlg.m_low;

        //ÄÄÄ Misc
        cam.set_hither(mdlg.m_hither);
        cam.set_yon(mdlg.m_yon);
        cam.set_factor(mdlg.m_scalef);
        cam_bcolor = mdlg.m_bcolor;
        hover_offset = mdlg.m_hover;
        cam.set_bcolor(palette.get_index((VngoColor24bit)cam_bcolor));

        //ÄÄÄ Extended
        if (xdlg.m_haze_active)
        {
            cam.set_haze(xdlg.m_startz, xdlg.m_midz,
                          VngoColor24bit(xdlg.haze_color));
        }
        else
            cam.vport->haze_off();

        if (xdlg.m_bg_active && xdlg.bg_bm)
        {
            cam.app_data = xdlg.bg_bm;
            if (cam.create_bg_bitmap(xdlg.bg_bm))
            {
                AfxMessageBox("Create of bitmap background failed",
                              MB_OK | MB_ICONEXCLAMATION);
            }
        }
        else
        {
            if (xdlg.bg_bm)
                delete xdlg.bg_bm;
            cam.app_data = 0;
            cam.set_bg_bitmap(0);
        }

        //ÄÄÄ Update views
        UpdateAllViews(NULL,HINT_UPDATETERR,NULL);
        return;
    }

    if (xdlg.bg_bm != cam.app_data)
    {
        if (xdlg.bg_bm)
            delete xdlg.bg_bm;
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

    ProgressDlg   dlg;
    dlg.m_pbar.SetRange(0, (depth >> surfshift));
    dlg.m_pbar.SetPos(0);
    dlg.SetWindowText("Mapping Surface Colors...");
    dlg.ShowWindow(SW_SHOW);

    for(y=0, sptr=surfcolr, dptr=surfinfo;
        y < (depth >> surfshift); y++)
    {
        dlg.m_pbar.SetPos(y);

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

    for(i=0; i < colorNumb; i++)
    {
        colorColrIndx[i] = (byte)palette.get_index((VngoColor24bit)colorColr[i]);
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
    XFBitmap    bm;
    if (!theApp.LoadImage(fname,&bm))
        return FALSE;

    // Check for valid size
    switch (bm.width)
    {
        case 16:
        case 32:
        case 64:
        case 128:
        case 256:
            break;
        default:
            MessageBox(NULL,
                       "Input bitmap file must be 16, 32, 64, 128, or 256 pixels in width.",
                       "Texture Load Error",
                       MB_OK | MB_ICONEXCLAMATION);
            return FALSE;
    }

    switch (bm.height)
    {
        case 16:
        case 32:
        case 64:
        case 128:
        case 256:
            break;
        default:
            MessageBox(NULL,
                       "Input bitmap file must be 16, 32, 64, 128, or 256 pixels in height.",
                       "Texture Load Error",
                       MB_OK | MB_ICONEXCLAMATION);
            return FALSE;
    }

    switch (bm.bpp)
    {
        case 1:
        case 2:
        case 3:
            break;
        default:
            MessageBox(NULL,
                       "Input bitmap file must be 8-bit, 15-bit, or 24-bit.",
                       "Texture Load Error",
                       MB_OK | MB_ICONEXCLAMATION);
            return FALSE;
    }

    //
    // Install new texture
    //

    txtFName[ind] = fname;

    EschStaticTexture *txt;

    if (txtEsch[ind])
    {
        txt = (EschStaticTexture*)txtEsch[ind];
        txt->release();
    }
    else
    {
        txt = new EschStaticTexture;
        txtEsch[ind] = txt;
    }

    assert(txt);

    // Allocate memory for texture

    if ( ((txt->handle = ivory_halloc(sizeof(VngoTexture) + (bm.width*bm.height))) == 0)
         || ((txt->ptr = (VngoTexture*)ivory_hlock(txt->handle)) == 0) )
    {
        MessageBox(NULL,"Memory problem loading texture.",
                   "Texture Load Error", MB_OK | MB_ICONEXCLAMATION);
        txt->release();
        return FALSE;
    }

    txt->flags = ESCH_TXT_LOCKED | ESCH_TXT_OWNSDATA;

    txt->ptr->VngoTexture::VngoTexture(bm.width,
                                       bm.height,
                                       (byte*)txt->ptr + sizeof(VngoTexture),
                                       VNGO_TEXTURE_8BIT);

    // Recolor image using current palette
    if (bm.bpp == 1)
    {
        int mypal[256];

        for(i=0; i < 256; i++)
        {
            mypal[i] = (byte)palette.get_index((VngoColor24bit)bm.pal[i]);
        }

        for(i=0; i < bm.width * bm.height; i++)
        {
            ((byte*)txt->ptr->tex)[i] = (byte)mypal[bm.data[i]];
        }
    }
    else if (bm.bpp == 2)
    {
        VngoColor24bit  clr;
        byte            *sptr, *dptr;

        for(i=0, sptr=bm.data, dptr=(byte*)txt->ptr->tex; i < bm.width * bm.height; i++)
        {
            word pcolor = *sptr | (*(sptr+1) << 8);

            sptr += 2;

            clr.r = (pcolor >> 7) & 0xf8;
            clr.g = (pcolor >> 2) & 0xf8;
            clr.b = (pcolor << 3) & 0xf8;

            *(dptr++) = (byte)palette.get_index(clr);
        }
    }
    else // bpp == 3
    {
        VngoColor24bit  clr;
        byte            *sptr, *dptr;

        for(i=0, sptr=bm.data, dptr=(byte*)txt->ptr->tex; i < bm.width * bm.height; i++)
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

    scale=32;

    autocenter = 1;
    orgx = -(float)(width/2)*scale;
    orgy = 0;
    orgz = -(float)(depth/2)*scale;

    strcpy(name,"NoName");
    *desc = 0;
    *auth = 0;
    *copy = 0;

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

    htable = new float[256];
    if (!htable)
        return FALSE;
    {
        float t=0;
        for(ulong i=0; i < 256; i++)
        {
            htable[i] = t;
            t += 16;
        }
    }

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

    hsurfnormlflat = ivory_halloc((ulong)(surfsize * sizeof(EschVector)));
    if (!hsurfnormlflat)
        return FALSE;

    EschVector *vptr = (EschVector*) ivory_hlock(hsurfnorml);
    if (!vptr)
        return FALSE;
    memset(vptr,0,(ulong)(surfsize * sizeof(EschVector)));
    ivory_hunlock(hsurfnorml);

    vptr = (EschVector*) ivory_hlock(hsurfnormlflat);
    if (!vptr)
        return FALSE;
    memset(vptr,0,(ulong)(surfsize * sizeof(EschVector)));
    ivory_hunlock(hsurfnormlflat);

// Allocate undo buffers
    undo_valid = FALSE;

    undo_surfinfo = new esch_surf_type[surfsize];
    if (!undo_surfinfo)
        return FALSE;

    undo_surfcolr = new dword[surfsize];
    if (!undo_surfcolr)
        return FALSE;

// Render view camera default
    cam.reset();
    cam.set_position( 0,
                      64,
                      0);
    cam.set_flags(ESCH_CAM_SHADE_WIRE
                  | ESCH_CAM_SHADE_SOLID
                  | ESCH_CAM_SHADE_FLAT
                  | ESCH_CAM_TEXTURED | ESCH_CAM_BACKCULL);
    cam_bcolor = 0x201414;

// Default light
    lights = new EschVectorLight(-1,-1,-1);
    if (!lights)
        return FALSE;

// Default color bands
    color_bands[0] = 100;
    color_bands[1] = 200;
    color_bands[2] = 300;
    color_bands[3] = 400;
    color_bands[4] = 500;
    color_bands[5] = 600;
    color_bands[6] = 700;
    color_bands[7] = 900;
    color_bands[8] = 1000;
    color_bands[9] = 1100;
    color_bands[10] = 1200;

// Misc properties.
    hover_offset = 64;
    lod_active = TRUE;
    lod_medium = 512;
    lod_low = 1024;

// Find default palette
    int     i;
    char    *c;
    char    fname[256];

    GetModuleFileName(NULL, fname, 256);

    for (i=strlen(fname), c = &fname[i-1]; i > 0; i--, c--)
    {
        if (*c == '\\')
        {
            strcpy(c+1,"DEFAULT.VGP");

            if (xf_exist(fname))
                break;

            strcpy(c+1,"DEFAULT.PAL");

            if (xf_exist(fname))
                break;
        }
    }
    if (!i)
        strcpy(fname,"DEFAULT.VGP");

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

    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Saving
    if (ar.IsStoring())
    {
        EschPoint   pnt;
        EschLight   *lgt;

        //ÄÄÄ Version tag (not in original)
        ar << (ushort)MAGIC;                // Added v1.00
        ar << (ushort)0x200;                // Current version 2.00

        //ÄÄÄ Terrain Properities
        ar << width;
        ar << depth;
        ar << surfratio;
        ar << surfshift;
        ar << scale;

        // hscale removed in v1.16

        ar << autocenter;                   // Added in v1.10
        if (!autocenter)
        {
            ar << orgx;                     // Added in v1.10
            ar << orgy;
            ar << orgz;
        }

        ar << CString(name);
        ar << CString(desc);
        ar << CString(auth);
        ar << CString(copy);
        ar << CString(pfname);

        //ÄÄÄ Height-field
        ar.Write(hfield,width*depth);

        //ÄÄÄ Height table                  // Float in v2.00
        ar.Write(htable,sizeof(float)*256);

        //ÄÄÄ Surface information
        dword surfsize = (width * depth) >> (surfshift*2);

        ar.Write(surfinfo,surfsize*sizeof(esch_surf_type));
        ar.Write(surfcolr,surfsize*sizeof(dword));

        //ÄÄÄ Write texture information
        ar << (long)txtNumb;
        for(i=0; i < txtNumb; i++)
        {
            ar << txtName[i] << txtFName[i] << txtColr[i];
            ar << txtDFlags[i];             // Added in 1.11
        }

        //ÄÄÄ Write color information
        ar << (long)colorNumb;
        for(i=0; i < colorNumb; i++)
        {
            ar << colorName[i] << colorColr[i];  // Added in 1.15
            ar << colorDFlags[i];           // Added in 1.17
        }

        //ÄÄÄ Write color bands             Added in 1.14
        for(i=0; i < sizeof(color_bands)/sizeof(ushort); i++)
            ar << color_bands[i];

        //ÄÄÄ Write camera info             Added in 1.14
        cam.get_position(&pnt);
        ar << pnt.x;
        ar << pnt.y;
        ar << pnt.z;
        ar << cam.eye.dir.i;
        ar << cam.eye.dir.j;
        ar << cam.eye.dir.k;
        ar << cam.top.i;
        ar << cam.top.j;
        ar << cam.top.k;
        ar << cam.factor;
        ar << cam.hither;
        ar << cam.yon;
        ar << cam.fov;
        ar << cam_bcolor;

        //ÄÄÄ Write lights info             Added in 1.14
        for(i=0, lgt=lights; lgt != NULL; lgt=lgt->next(), i++);
        ar << i;

        for(lgt=lights; lgt != NULL; lgt=lgt->next())
        {
            ar << lgt->get_type();
            ar << CString(lgt->name);
            ar << lgt->intensity;
            ar << lgt->flags;
            switch (lgt->get_type())
            {
                case ESCH_LGTT_VECTOR:
                    ar << ((EschVectorLight*)lgt)->dir.i;
                    ar << ((EschVectorLight*)lgt)->dir.j;
                    ar << ((EschVectorLight*)lgt)->dir.k;
                    break;
                case ESCH_LGTT_POINT:
                    ar << ((EschPointLight*)lgt)->pos.x;
                    ar << ((EschPointLight*)lgt)->pos.y;
                    ar << ((EschPointLight*)lgt)->pos.z;
                    break;
                case ESCH_LGTT_ATTEN:
                    ar << ((EschAttenLight*)lgt)->pos.x;
                    ar << ((EschAttenLight*)lgt)->pos.y;
                    ar << ((EschAttenLight*)lgt)->pos.z;
                    ar << ((EschAttenLight*)lgt)->inner;
                    ar << ((EschAttenLight*)lgt)->outer;
                    break;
                case ESCH_LGTT_SPOT:
                    ar << ((EschSpotLight*)lgt)->pos.x;
                    ar << ((EschSpotLight*)lgt)->pos.y;
                    ar << ((EschSpotLight*)lgt)->pos.z;
                    ar << ((EschSpotLight*)lgt)->inner;
                    ar << ((EschSpotLight*)lgt)->outer;
                    ar << ((EschSpotLight*)lgt)->dir.i;
                    ar << ((EschSpotLight*)lgt)->dir.j;
                    ar << ((EschSpotLight*)lgt)->dir.k;
                    ar << ((EschSpotLight*)lgt)->hotspot;
                    ar << ((EschSpotLight*)lgt)->falloff;
                    break;
                default:
                    ASSERT(0);
                    break;
            }
        }

        //ÄÄÄ Write misc info               Added in 1.14
        ar << hover_offset;
        ar << lod_active;
        ar << lod_medium;
        ar << lod_low;
    }
    //ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Loading
    else
    {
        float       f;
        ushort      magic;
        ushort      version;
        CString     str;
        EschPoint   pnt;
        EschVector  vec;
        EschLight   *lgt;
        char        palname[256];

        //ÄÄÄ Terrain Properities

        ar >> magic;
        if (magic != MAGIC)
        {
            width = magic;
            version = 0x000;
        }
        else
        {
            ar >> version;
            ar >> width;
        }

        ar >> depth;
        ar >> surfratio;
        ar >> surfshift;

        if (version < 0x100)
        {
            ar >> f;
            ar >> f;
            scale = 32;
        }
        else
        {
            ar >> scale;;
        }

        if (version < 0x116)
        {
            ar >> f;

            htable = new float[256];
            ASSERT(htable);

            float t = 0;
            for(ulong i=0; i < 256; i++)
            {
                htable[i]=t;
                t += f;
            }
        }

        if (version >= 0x110)
        {
            ar >> autocenter;
            if (autocenter)
            {
                orgx = -(float)(width/2)*scale;
                orgy = 0;
                orgz = -(float)(depth/2)*scale;
            }
            else
            {
                ar >> orgx;
                ar >> orgy;
                ar >> orgz;
            }
        }
        else
        {
            autocenter = 1;
            orgx = -(float)(width/2)*scale;
            orgy = 0;
            orgz = -(float)(depth/2)*scale;
        }

        ar >> str;  strncpy(name,str,16);
        ar >> str;  strncpy(desc,str,256);
        ar >> str;  strncpy(auth,str,256);
        ar >> str;  strncpy(copy,str,256);
        ar >> str;  strncpy(palname,str,256);

        //ÄÄÄ Height-field
        hfield = new byte[width * depth];
        ASSERT(hfield);
        ar.Read(hfield,width*depth);

        //ÄÄÄ Height table
        if (version >= 0x200)
        {
            htable = new float[256];
            ASSERT(htable);
            ar.Read(htable,sizeof(float)*256);
        }
        else if (version >= 0x116)
        {
            long v1[256];

            ar.Read(&v1,sizeof(Flx16)*256);

            htable = new float[256];
            ASSERT(htable);

            for(int i=0; i < 256; i++)
                htable[i] = v1[i] / 65536.0f;
        }

        //ÄÄÄ Surface information
        dword surfsize = (width * depth) >> (surfshift*2);

        surfinfo = new esch_surf_type[surfsize];
        ASSERT(surfinfo);
        ar.Read(surfinfo,surfsize*sizeof(esch_surf_type));

        surfcolr = new dword[surfsize];
        ASSERT(surfcolr);
        ar.Read(surfcolr,surfsize*sizeof(dword));

        //ÄÄÄ Allocate undo buffers
        undo_valid=FALSE;
        undo_surfinfo = new esch_surf_type[surfsize];
        ASSERT(undo_surfinfo);

        undo_surfcolr = new dword[surfsize];
        ASSERT(undo_surfcolr);

        //ÄÄÄ Read texture information
        long l;

        ar >> l; txtNumb = l;

        for(i=0; i < txtNumb; i++)
        {
            ar >> txtName[i] >> txtFName[i] >> txtColr[i];
            if (version >= 0x111)
            {
                ar >> txtDFlags[i];
            }
            else
                txtDFlags[i] = 0;
        }

        //ÄÄÄ Read color information
        if (version >= 0x115)
        {
            ar >> l; colorNumb = l;

            for(i=0; i < colorNumb; i++)
            {
                ar >> colorName[i] >> colorColr[i];
                if (version >= 0x117)
                {
                    ar >> colorDFlags[i];
                }
                else
                    colorDFlags[i] = 0;
            }
        }
        else
        {
            colorNumb = 0;
        }

        //ÄÄÄ Read color bands
        if (version >= 0x114)
        {
            for(i=0; i < sizeof(color_bands)/sizeof(ushort); i++)
                ar >> color_bands[i];
        }
        else
        {
            // Default color bands
            color_bands[0] = 100;
            color_bands[1] = 200;
            color_bands[2] = 300;
            color_bands[3] = 400;
            color_bands[4] = 500;
            color_bands[5] = 600;
            color_bands[6] = 700;
            color_bands[7] = 900;
            color_bands[8] = 1000;
            color_bands[9] = 1100;
            color_bands[10] = 1200;
        }

        //ÄÄÄ Read camera info
        if (version >= 0x114)
        {
            ar >> pnt.x;;
            ar >> pnt.y;;
            ar >> pnt.z;;
            cam.set_position(&pnt);

            ar >> vec.i;
            ar >> vec.j;
            ar >> vec.k;
            cam.set_dir(&vec);

            ar >> vec.i;
            ar >> vec.j;
            ar >> vec.k;
            cam.set_top(&vec);

            ar >> f;  cam.set_factor(f);
            ar >> f;  cam.set_hither(f);
            ar >> f;  cam.set_yon(f);
            ar >> f;  cam.set_fov(f);

            ar >> cam_bcolor;
        }
        else
        {
            cam.reset();
            cam.set_position( 0.0f, 64.0f, 0.0f);
            cam_bcolor = 0x201414;
        }

        //ÄÄÄ Read lights info
        if (version >= 0x114)
        {
            ar >> i;

            for(; i > 0; i--)
            {
                word    t;

                ar >> t;
                switch (t)
                {
                    case ESCH_LGTT_VECTOR:
                        lgt = new EschVectorLight;
                        break;
                    case ESCH_LGTT_POINT:
                        lgt = new EschPointLight;
                        break;
                    case ESCH_LGTT_ATTEN:
                        lgt = new EschAttenLight;
                        break;
                    case ESCH_LGTT_SPOT:
                        lgt = new EschSpotLight;
                        break;
                    default:
                        MessageBox(NULL,
                                   "Unknown light type found in CST file",
                                   "Load Error",
                                   MB_OK | MB_ICONEXCLAMATION);
                        AfxThrowArchiveException(CArchiveException::generic);
                        break;
                }
                ASSERT(lgt);

                ar >> str;  strncpy(lgt->name,str,16);

                byte inten;
                ar >> inten;  lgt->set_intensity(inten);

                dword flags;
                ar >> flags;  lgt->set_flags(flags);

                switch (t)
                {
                    case ESCH_LGTT_VECTOR:
                        ar >> vec.i;
                        ar >> vec.j;
                        ar >> vec.k;
                        ((EschVectorLight*)lgt)->set_direction(&vec);
                        break;
                    case ESCH_LGTT_POINT:
                        ar >> pnt.x;
                        ar >> pnt.y;
                        ar >> pnt.z;
                        ((EschPointLight*)lgt)->set_position(&pnt);
                        break;
                    case ESCH_LGTT_ATTEN:
                        ar >> pnt.x;
                        ar >> pnt.y;
                        ar >> pnt.z;
                        ((EschAttenLight*)lgt)->set_position(&pnt);

                        ar >> f;  ((EschAttenLight*)lgt)->set_inner(f);
                        ar >> f;  ((EschAttenLight*)lgt)->set_outer(f);
                        break;
                    case ESCH_LGTT_SPOT:
                        ar >> pnt.x;
                        ar >> pnt.y;
                        ar >> pnt.z;
                        ((EschSpotLight*)lgt)->set_position(&pnt);

                        ar >> f;  ((EschSpotLight*)lgt)->set_inner(f);
                        ar >> f;  ((EschSpotLight*)lgt)->set_outer(f);

                        ar >> vec.i;
                        ar >> vec.j;
                        ar >> vec.k;
                        ((EschSpotLight*)lgt)->set_direction(&vec);

                        ar >> f;  ((EschSpotLight*)lgt)->set_hotspot(f);
                        ar >> f;  ((EschSpotLight*)lgt)->set_falloff(f);
                        break;
                    default:
                        ASSERT(0);
                        break;
                }

                if (!lights)
                    lights = lgt;
                else
                    lgt->sibling(lights);
            }
        }
        else
        {
            lights = new EschVectorLight(-1,-1,-1);
            ASSERT(lights);
        }

        //ÄÄÄ Read misc info
        if (version >= 0x114)
        {
            ar >> hover_offset;
            ar >> lod_active;
            ar >> lod_medium;
            ar >> lod_low;
        }
        else
        {
            hover_offset = 64.0f;
            lod_active = TRUE;
            lod_medium = 512.0f;
            lod_low = 1024.0f;
        }

        //ÄÄÄ Load palette (which implicitly loads textures)
        if (!xf_exist(palname))
        {
            LocateDlg   dlg;
            dlg.title = "Locate Palette File";
            dlg.m_fname = palname;
            dlg.typestr = "Van Gogh palette file (*.vgp;*.pal)|*.VGP;*.PAL|";

            if (dlg.DoModal() == IDOK)
            {
                strcpy(palname,dlg.m_fname);
                SetModifiedFlag();
            }
        }

        if (!LoadPalette(palname,0))
        {
            MessageBox(NULL,
                       "Failed to load palette in file, retaining old palette",
                       "Load Error",MB_OK | MB_ICONEXCLAMATION);
        }

        //ÄÄÄ Compute normals

        hsurfnorml = ivory_halloc((ulong)(surfsize * sizeof(EschVector)));
        ASSERT(hsurfnorml);

        EschVector *vptr = (EschVector*) ivory_hlock(hsurfnorml);
        ASSERT(vptr);
        memset(vptr,0,(ulong)(surfsize * sizeof(EschVector)));
        ivory_hunlock(hsurfnorml);

        ComputeNormals(NORMALS_SMOOTH);

        hsurfnormlflat = ivory_halloc((ulong)(surfsize * sizeof(EschVector)));
        ASSERT(hsurfnormlflat);

        vptr = (EschVector*) ivory_hlock(hsurfnormlflat);
        ASSERT(vptr);
        memset(vptr,0,(ulong)(surfsize * sizeof(EschVector)));
        ivory_hunlock(hsurfnormlflat);

        ComputeNormals(NORMALS_FLAT);

        //ÄÄÄ Set default camera flags
        cam.set_flags(ESCH_CAM_SHADE_WIRE
                      | ESCH_CAM_SHADE_SOLID
                      | ESCH_CAM_SHADE_FLAT
                      | ESCH_CAM_TEXTURED | ESCH_CAM_BACKCULL);
        }
}

//°±² eof - eshtdoc.cpp ²±°
