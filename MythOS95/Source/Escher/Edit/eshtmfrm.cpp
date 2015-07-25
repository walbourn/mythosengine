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
// eshtmfrm.cpp
//
// Main window frame class.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "stdafx.h"
#include "eshtedit.h"

#include "eshtmfrm.h"
#include "eshtdoc.h"
#include "eshtview.h"
#include "eshtdlg.h"
#include "eshtdlgt.h"

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
// TerrMainFrame                                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

IMPLEMENT_DYNCREATE(TerrMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(TerrMainFrame, CFrameWnd)
        //{{AFX_MSG_MAP(TerrMainFrame)
        ON_WM_CREATE()
        ON_COMMAND(ID_TERR_PROP, OnTerrProperties)
        ON_COMMAND(ID_TERR_IMPORT, OnTerrImport)
        ON_COMMAND(ID_SURF_PALETTE, OnSurfPalette)
        ON_COMMAND(ID_SURF_IMPORT, OnSurfImport)
        ON_COMMAND(ID_FILE_EXPORT, OnFileExport)
        ON_COMMAND(ID_SURF_DEFINETXT, OnSurfDefineTexture)
        ON_COMMAND(ID_SURF_EDITTXT, OnSurfEditTexture)
        ON_COMMAND(ID_SURF_DELETETXT, OnSurfDeleteTexture)
        ON_COMMAND(ID_APP_HELP, OnAppHelp)
        ON_COMMAND(ID_SURF_SAVETXT, OnSurfSaveTextures)
        ON_UPDATE_COMMAND_UI(ID_SURF_SAVETXT, OnUpdateSurfSaveTextures)
        ON_UPDATE_COMMAND_UI(ID_SURF_DELETETXT, OnUpdateSurfDeleteTexture)
        ON_UPDATE_COMMAND_UI(ID_SURF_EDITTXT, OnUpdateSurfEditTexture)
        ON_COMMAND(ID_SURF_LOADTXT, OnSurfLoadTextures)
        ON_COMMAND(ID_SURF_DEFCLR, OnSurfDefineColor)
        ON_COMMAND(ID_SURF_DELETECLR, OnSurfDeleteColor)
        ON_UPDATE_COMMAND_UI(ID_SURF_DELETECLR, OnUpdateSurfDeleteColor)
        ON_COMMAND(ID_SURF_EDITCLR, OnSurfEditColor)
        ON_UPDATE_COMMAND_UI(ID_SURF_EDITCLR, OnUpdateSurfEditColor)
        ON_COMMAND(ID_SURF_LOADCLR, OnSurfLoadColors)
        ON_COMMAND(ID_SURF_SAVECLR, OnSurfSaveColors)
        ON_UPDATE_COMMAND_UI(ID_SURF_SAVECLR, OnUpdateSurfSaveColors)
        ON_COMMAND(ID_TERR_SETBASE, OnTerrSetBaseElevation)
        ON_COMMAND(ID_SURF_REMTXT, OnSurfRemoveUnusedTxts)
        ON_UPDATE_COMMAND_UI(ID_SURF_REMTXT, OnUpdateSurfRemoveUnusedTxts)
        ON_COMMAND(IDS_FILE_FLOATING, OnFileFloating)
        ON_UPDATE_COMMAND_UI(IDS_FILE_FLOATING, OnUpdateFileFloating)
        ON_COMMAND(IDS_FILE_COMPRESS, OnFileCompress)
        ON_UPDATE_COMMAND_UI(IDS_FILE_COMPRESS, OnUpdateFileCompress)
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Arrays of IDs used to initialize control bars                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

// toolbar buttons - IDs are command buttons
static UINT BASED_CODE buttons[] =
{
        // same order as in the bitmap 'toolbar.bmp'
        ID_FILE_NEW,
        ID_FILE_OPEN,
        ID_FILE_SAVE,
                ID_SEPARATOR,
    ID_TERR_IMPORT,
    ID_SURF_IMPORT,
    ID_SURF_PALETTE,
                ID_SEPARATOR,
    ID_VIEW_RENDER,
                ID_SEPARATOR,
    ID_VIEW_ROTXY,
    ID_VIEW_MOVEXY,
    ID_VIEW_ROTMOVEZ,
    ID_LGT_ADJUSTXY,
    ID_LGT_ABRIGHT,
                ID_SEPARATOR,
    ID_SURF_DEFINETXT,
    ID_SURF_EDITTXT,
    ID_SURF_DELETETXT,
                ID_SEPARATOR,
    ID_SURF_DEFCLR,
    ID_SURF_EDITCLR,
    ID_SURF_DELETECLR,
                ID_SEPARATOR,
        ID_APP_ABOUT,
};

static UINT BASED_CODE indicators[] =
{
        ID_SEPARATOR,           // status line indicator
    ID_INDICATOR_CAPS,
        ID_INDICATOR_NUM,
    ID_INDICATOR_SCRL,
};

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°° Constructor/Destructor °°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - Constructor                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
TerrMainFrame::TerrMainFrame()
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - Destructor                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
TerrMainFrame::~TerrMainFrame()
{
}


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Diagnostics °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#ifdef _DEBUG
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - AssertValid                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::AssertValid() const
{
        CFrameWnd::AssertValid();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - Dump                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::Dump(CDumpContext& dc) const
{
        CFrameWnd::Dump(dc);
}
#endif //_DEBUG



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Message Handlers °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - OnCreate                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int TerrMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
        if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
                return -1;

        if (!m_wndToolBar.Create(this) ||
                !m_wndToolBar.LoadBitmap(IDR_MAINFRAME) ||
                !m_wndToolBar.SetButtons(buttons,
                  sizeof(buttons)/sizeof(UINT)))
        {
                TRACE0("Failed to create toolbar\n");
                return -1;      // fail to create
        }

        if (!m_wndStatusBar.Create(this) ||
                !m_wndStatusBar.SetIndicators(indicators,
                  sizeof(indicators)/sizeof(UINT)))
        {
                TRACE0("Failed to create status bar\n");
                return -1;      // fail to create
        }

        // TODO: Delete these three lines if you don't want the toolbar to
        //  be dockable
        m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
        EnableDocking(CBRS_ALIGN_ANY);
        DockControlBar(&m_wndToolBar);

        // TODO: Remove this if you don't want tool tips
        m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
                CBRS_TOOLTIPS | CBRS_FLYBY);

        return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - OnFileExport                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnFileExport()
{
    CFileDialog dlg(FALSE,
                    "IFF", "EXPORT.IFF",
                    OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST,
                    "Escher Terrain File (*.iff)|*.IFF|All files (*.*)|*.*||",
                    this);

    dlg.m_ofn.lpstrTitle = "Escher Terrain Export File";

    if (dlg.DoModal() == IDOK)
    {
        TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
        ASSERT_VALID(pDoc);

        pDoc->ExportToIFF(dlg.GetPathName());
    }
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - OnFileCompress                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnFileCompress()
{
        TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
        pDoc->ctrlfl ^= TerrEditDoc::COMPRESS;
}

void TerrMainFrame::OnUpdateFileCompress(CCmdUI* pCmdUI)
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();

    pCmdUI->Enable((pDoc) ? TRUE : FALSE);
    if (pDoc)
    {
        pCmdUI->SetCheck((pDoc->ctrlfl & TerrEditDoc::COMPRESS) ? 1 : 0);
    }
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - OnFileFloating                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnFileFloating()
{
        TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
        pDoc->ctrlfl ^= TerrEditDoc::FLOATING;
}

void TerrMainFrame::OnUpdateFileFloating(CCmdUI* pCmdUI)
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();

    pCmdUI->Enable((pDoc) ? TRUE : FALSE);
    if (pDoc)
    {
        pCmdUI->SetCheck((pDoc->ctrlfl & TerrEditDoc::FLOATING) ? 1 : 0);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - OnTerrSetBaseElevation                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnTerrSetBaseElevation()
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    SetBaseElvDlg   dlg;

    float elvmin, elvmax;
    pDoc->GetMinMaxElevations(elvmin,elvmax);

    dlg.m_elvmin = elvmin;
    dlg.m_elvmax = elvmax;

    if (dlg.DoModal() == IDCANCEL)
        return;

    pDoc->SetBaseElevation(dlg.m_setbase_elv);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - OnTerrProperties                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnTerrProperties()
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    pDoc->UITerrainProperities(NULL,0);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - OnTerrImport                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnTerrImport()
{
    CFileDialog dlg(TRUE,
                    NULL, NULL,
                    OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
                    "Terrain import files (*.dem;*.pcx)|*.DEM;*.PCX|"
                    "Digital Elevation Model files (*.dem)|*.DEM|"
                    "Bitmap files (*.pcx)|*.PCX|"
                    "All files (*.*)|*.*||",
                    this);

    dlg.m_ofn.lpstrTitle = "Terrain Import File";

    if (dlg.DoModal() == IDOK)
    {
        TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
        ASSERT_VALID(pDoc);

        pDoc->ImportTerrain((LPCSTR)dlg.GetPathName(),1);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - OnSurfImport                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnSurfImport()
{
    CFileDialog dlg(TRUE,
                    NULL, NULL,
                    OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
                    "Bitmap files (*.pcx)|*.PCX|All files (*.*)|*.*||",
                    this);

    dlg.m_ofn.lpstrTitle = "Terrain Surface Color Import File";

    if (dlg.DoModal() == IDOK)
    {
        TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
        ASSERT_VALID(pDoc);

        pDoc->ImportSurface((LPCSTR)dlg.GetPathName(),1);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - OnSurfDefineTexture                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnSurfDefineTexture()
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    if (pDoc->txtNumb >= 255)
    {
        MessageBox("No more texture definitions may be added.\n\n"
                   "(There may be at most 255 texture definitions in a terrain data set)\n",
                   "Define Texture Error",
                   MB_OK | MB_ICONEXCLAMATION);
        return;
    }


//ÄÄÄ General
    TxtPropGenPage gdlg;
    gdlg.setup(pDoc);

    // Generate unique 'default' name.
    char name[16];
    for(int c=1; ; c++)
    {
        sprintf(name,"Texture%02d",c);

        if (pDoc->FindTexture(name) == -1)
            break;
    }
    gdlg.m_name = name;

//ÄÄÄ Surface Flags
    TxtPropSFlagsPage fdlg;
    fdlg.setup(pDoc);
    fdlg.m_isnew=1;

//ÄÄÄ Handle Display
    CPropertySheet sh("Texture Properties",this);
    sh.AddPage(&gdlg);      // General
    sh.AddPage(&fdlg);      // Surface Flags

//ÄÄÄ Store results, if OK
    if (sh.DoModal() == IDOK)
    {
        //ÄÄÄ Surface Flags
        assert(ESCH_SURF_TILE1 == 0x10 && ESCH_SURF_TILE2 == 0x20 && ESCH_SURF_TILE3 == 0x40);
        dword flags = ((fdlg.m_flipu) ? ESCH_SURF_FLIPU : 0)
                      | ((fdlg.m_flipv) ? ESCH_SURF_FLIPV : 0)
                      | ((fdlg.m_tile << 4) & 0x70)
                      | ((fdlg.m_notile) ? ESCH_SURF_NOTILE : 0)
                      | ((fdlg.m_highonly) ? ESCH_SURF_HIGHONLY : 0)
                      | ((fdlg.m_app0) ? ESCH_SURF_APP0 : 0)
                      | ((fdlg.m_app1) ? ESCH_SURF_APP1 : 0)
                      | ((fdlg.m_app2) ? ESCH_SURF_APP2 : 0)
                      | ((fdlg.m_app3) ? ESCH_SURF_APP3 : 0);

        //ÄÄÄ General
        pDoc->AddTexture(gdlg.m_name, gdlg.m_fname, gdlg.m_color, flags);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - On(Update)SurfEditTexture                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnSurfEditTexture()
{
    TerrEditView *pView = (TerrEditView*)GetActiveView();
    ASSERT_VALID(pView);

    int i = pView->GetCurrentTextureSel();

    if (i == LB_ERR)
    {
        MessageBox("Please highlight the texture definition to edit\n"
                   "in the Texture Definitions window.",
                   "Edit Texture Error",
                   MB_OK | MB_ICONSTOP);
        return;
    }

    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    ASSERT(i < pDoc->txtNumb);

//ÄÄÄ General
    TxtPropGenPage gdlg;
    gdlg.setup(pDoc,i);

    gdlg.m_name = pDoc->txtName[i];
    gdlg.m_fname = pDoc->txtFName[i];
    gdlg.m_color = pDoc->txtColr[i];

//ÄÄÄ Surface Flags
    TxtPropSFlagsPage fdlg;
    fdlg.setup(pDoc,i);

    dword flags = pDoc->txtDFlags[i];

    fdlg.m_flipu = (flags & ESCH_SURF_FLIPU) ? 1 : 0;
    fdlg.m_flipv = (flags & ESCH_SURF_FLIPV) ? 1 : 0;

    assert(ESCH_SURF_TILE1 == 0x10 && ESCH_SURF_TILE2 == 0x20 && ESCH_SURF_TILE3 == 0x40);
    fdlg.m_tile  = (flags >> 4) & 0x7;

    fdlg.m_notile = (flags & ESCH_SURF_NOTILE) ? 1 : 0;
    fdlg.m_highonly = (flags & ESCH_SURF_HIGHONLY) ? 1 : 0;

    fdlg.m_app0 = (flags & ESCH_SURF_APP0) ? 1 : 0;
    fdlg.m_app1 = (flags & ESCH_SURF_APP1) ? 1 : 0;
    fdlg.m_app2 = (flags & ESCH_SURF_APP2) ? 1 : 0;
    fdlg.m_app3 = (flags & ESCH_SURF_APP3) ? 1 : 0;

//ÄÄÄ Handle Display
    CPropertySheet sh("Texture Properties",this);
    sh.AddPage(&gdlg);      // General
    sh.AddPage(&fdlg);      // Surface Flags

//ÄÄÄ Store results, if OK
    if (sh.DoModal() == IDOK)
    {
        //ÄÄÄ Surface Flags
        flags = ((fdlg.m_flipu) ? ESCH_SURF_FLIPU : 0)
                | ((fdlg.m_flipv) ? ESCH_SURF_FLIPV : 0)
                | ((fdlg.m_tile << 4) & 0x70)
                | ((fdlg.m_notile) ? ESCH_SURF_NOTILE : 0)
                | ((fdlg.m_highonly) ? ESCH_SURF_HIGHONLY : 0)
                | ((fdlg.m_app0) ? ESCH_SURF_APP0 : 0)
                | ((fdlg.m_app1) ? ESCH_SURF_APP1 : 0)
                | ((fdlg.m_app2) ? ESCH_SURF_APP2 : 0)
                | ((fdlg.m_app3) ? ESCH_SURF_APP3 : 0);

        //ÄÄÄ General
        pDoc->SetTexture(i,gdlg.m_name,gdlg.m_fname, gdlg.m_color, flags);
    }
}

void TerrMainFrame::OnUpdateSurfEditTexture(CCmdUI* pCmdUI)
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable( (pDoc->txtNumb > 0) ? 1 : 0 );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - On(Update)SurfDeleteTexture                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnSurfDeleteTexture()
{
    TerrEditView *pView = (TerrEditView*)GetActiveView();
    ASSERT_VALID(pView);

    int i = pView->GetCurrentTextureSel();

    if (i == LB_ERR)
    {
        MessageBox("Please highlight the texture definition to delete\n"
                   "in the Texture Definitions window.",
                   "Delete Texture Error",
                   MB_OK | MB_ICONSTOP);
        return;
    }

    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    ASSERT(i < pDoc->txtNumb);

    char    str[128];

    sprintf(str,"Are you sure you wish to delete '%s'?",pDoc->txtName[i]);
    if (MessageBox(str,"Delete Texture",MB_YESNO | MB_ICONQUESTION) == IDYES)
    {
        pDoc->DeleteTexture(i);
    }
}

void TerrMainFrame::OnUpdateSurfDeleteTexture(CCmdUI* pCmdUI)
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable( (pDoc->txtNumb > 0) ? 1 : 0 );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - OnSurfRemoveUnusedTxts                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnSurfRemoveUnusedTxts()
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    if (MessageBox("Are you sure you wish to delete unused texture definitions?",
                   "Delete Texture",MB_YESNO | MB_ICONQUESTION) == IDYES)
    {
        pDoc->RemoveUnusedTxts();
    }
}

void TerrMainFrame::OnUpdateSurfRemoveUnusedTxts(CCmdUI* pCmdUI)
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable( (pDoc->txtNumb > 0) ? 1 : 0 );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - OnSurfLoadTextures                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnSurfLoadTextures()
{
    CFileDialog dlg(TRUE,
                    NULL, NULL,
                    OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
                    "Escher Edit Texture Sets (*.ts)|*.TS|All files (*.*)|*.*||",
                    this);

    dlg.m_ofn.lpstrTitle = "Load Textures";

    if (dlg.DoModal() == IDOK)
    {
        TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
        ASSERT_VALID(pDoc);

        pDoc->LoadTextures((LPCSTR)dlg.GetPathName());
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - On(Update)SurfSaveTextures                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnSurfSaveTextures()
{
    CFileDialog dlg(FALSE,
                    "TS", "TxtSet",
                    OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST,
                    "Escher Edit Texture Sets (*.ts)|*.TS|All files (*.*)|*.*||",
                    this);

    dlg.m_ofn.lpstrTitle = "Save Textures";

    if (dlg.DoModal() == IDOK)
    {
        TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
        ASSERT_VALID(pDoc);

        pDoc->SaveTextures((LPCSTR)dlg.GetPathName());
    }
}

void TerrMainFrame::OnUpdateSurfSaveTextures(CCmdUI* pCmdUI)
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable( (pDoc->txtNumb > 0) ? 1 : 0 );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - On(Update)DefineColor                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnSurfDefineColor()
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    if (pDoc->colorNumb >= 255)
    {
        MessageBox("No more color definitions may be added.\n\n"
                   "(There may be at most 255 color definitions in a terrain data set)\n",
                   "Define Color Error",
                   MB_OK | MB_ICONEXCLAMATION);
        return;
    }

    ColorGenPropPage dlga;
    ColorSelectPropPage dlgb;
    ShadeReviewPropPage dlgc;

    // Generate unique 'default' name.
    char name[16];
    for(int c=1; ; c++)
    {
        sprintf(name,"Color%02d",c);

        if (pDoc->FindColor(name) == -1)
            break;
    }
    dlga.m_name = name;
    dlga.setup(pDoc);
    dlga.m_isnew=1;
    dlga.colorIndx = (byte)pDoc->palette.get_index(VngoColor24bit(0,0,0));

    dlgb.palette = &pDoc->palette;
    dlgb.color = 0;

    dlgc.palette = dlgb.palette;
    dlgc.color = dlgb.color;

    CPropertySheet sh("Color Select");

    dlgb.setup(&dlga,&dlgc);

    sh.AddPage(&dlga);      // General
    sh.AddPage(&dlgb);      // Select COlor
    sh.AddPage(&dlgc);      // Review Shade

    if (sh.DoModal() == IDOK)
    {
        VngoColor24bit tclr = dlgb.palette->get_RGB(dlgb.color);

        dword flags = ((dlga.m_highonly) ? ESCH_SURF_HIGHONLY : 0)
                      | ((dlga.m_app0) ? ESCH_SURF_APP0 : 0)
                      | ((dlga.m_app1) ? ESCH_SURF_APP1 : 0)
                      | ((dlga.m_app2) ? ESCH_SURF_APP2 : 0)
                      | ((dlga.m_app3) ? ESCH_SURF_APP3 : 0);

        pDoc->AddColor(dlga.m_name, ((dword)tclr.b << 16)
                                    | ((dword)tclr.g << 8)
                                    | (dword)tclr.r, flags);
    }

}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - On(Update)SurfEditColor                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnSurfEditColor()
{
    TerrEditView *pView = (TerrEditView*)GetActiveView();
    ASSERT_VALID(pView);

    int i = pView->GetCurrentColorSel();

    if (i == LB_ERR)
    {
        MessageBox("Please highlight the color definition to edit\n"
                   "in the Color Definitions window.",
                   "Edit Color Error",
                   MB_OK | MB_ICONSTOP);
        return;
    }

    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    ASSERT(i < pDoc->colorNumb);

    ColorGenPropPage dlga;
    ColorSelectPropPage dlgb;
    ShadeReviewPropPage dlgc;

    dlga.colorIndx = pDoc->colorColrIndx[i];
    dlga.m_name = pDoc->colorName[i];
    dlga.setup(pDoc);

    dword flags = pDoc->colorDFlags[i];
    dlga.m_highonly = (flags & ESCH_SURF_HIGHONLY) ? 1 : 0;
    dlga.m_app0 = (flags & ESCH_SURF_APP0) ? 1 : 0;
    dlga.m_app1 = (flags & ESCH_SURF_APP1) ? 1 : 0;
    dlga.m_app2 = (flags & ESCH_SURF_APP2) ? 1 : 0;
    dlga.m_app3 = (flags & ESCH_SURF_APP3) ? 1 : 0;

    dlgb.palette = &pDoc->palette;
    dlgb.color = pDoc->colorColrIndx[i];

    dlgc.palette = dlgb.palette;
    dlgc.color = dlgb.color;

    CPropertySheet sh("Color Select");

    // Save the pointer to the Sheet for use in sharing data between the pages
    dlgb.setup(&dlga,&dlgc);

    sh.AddPage(&dlga);      // General
    sh.AddPage(&dlgb);      // Select Color
    sh.AddPage(&dlgc);      // Shade Review

    if (sh.DoModal() == IDOK)
    {
        VngoColor24bit tclr = dlgb.palette->get_RGB(dlgb.color);

        dword flags = ((dlga.m_highonly) ? ESCH_SURF_HIGHONLY : 0)
                      | ((dlga.m_app0) ? ESCH_SURF_APP0 : 0)
                      | ((dlga.m_app1) ? ESCH_SURF_APP1 : 0)
                      | ((dlga.m_app2) ? ESCH_SURF_APP2 : 0)
                      | ((dlga.m_app3) ? ESCH_SURF_APP3 : 0);

        pDoc->SetColor(i, dlga.m_name, ((dword)tclr.b << 16)
                                       | ((dword)tclr.g << 8)
                                       | (dword)tclr.r, flags);
    }

}

void TerrMainFrame::OnUpdateSurfEditColor(CCmdUI* pCmdUI)
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable( (pDoc->colorNumb > 0) ? 1 : 0 );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - On(Update)DeleteColor                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnSurfDeleteColor()
{
    TerrEditView *pView = (TerrEditView*)GetActiveView();
    ASSERT_VALID(pView);

    int i = pView->GetCurrentColorSel();

    if (i == LB_ERR)
    {
        MessageBox("Please highlight the color definition to delete\n"
                   "in the Color Definitions window.",
                   "Delete Color Error",
                   MB_OK | MB_ICONSTOP);
        return;
    }

    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    ASSERT(i < pDoc->colorNumb);

    char    str[128];

    sprintf(str,"Are you sure you wish to delete '%s'?",pDoc->colorName[i]);
    if (MessageBox(str,"Delete Color",MB_YESNO | MB_ICONQUESTION) == IDYES)
    {
        pDoc->DeleteColor(i);
    }

}

void TerrMainFrame::OnUpdateSurfDeleteColor(CCmdUI* pCmdUI)
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable( (pDoc->colorNumb > 0) ? 1 : 0 );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - OnSurfLoadColors                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnSurfLoadColors()
{
    CFileDialog dlg(TRUE,
                    NULL, NULL,
                    OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
                    "Escher Edit Color Sets (*.cs)|*.CS|All files (*.*)|*.*||",
                    this);

    dlg.m_ofn.lpstrTitle = "Load Colors";

    if (dlg.DoModal() == IDOK)
    {
        TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
        ASSERT_VALID(pDoc);

        pDoc->LoadColors((LPCSTR)dlg.GetPathName());
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - On(Update)SurfSaveColors                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnSurfSaveColors()
{
    CFileDialog dlg(FALSE,
                    "CS", "ClrSet",
                    OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST,
                    "Escher Edit Color Sets (*.cs)|*.CS|All files (*.*)|*.*||",
                    this);

    dlg.m_ofn.lpstrTitle = "Save Colors";

    if (dlg.DoModal() == IDOK)
    {
        TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
        ASSERT_VALID(pDoc);

        pDoc->SaveColors((LPCSTR)dlg.GetPathName());
    }
}

void TerrMainFrame::OnUpdateSurfSaveColors(CCmdUI* pCmdUI)
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable( (pDoc->colorNumb > 0) ? 1 : 0 );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - OnSurfPalette                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnSurfPalette()
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    CFileDialog dlg(TRUE,
                    "VGP", pDoc->pfname,
                    OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
                    "Van Gogh palette file (*.vgp;*.pal)|*.VGP;*.PAL|All files (*.*)|*.*||",
                    this);

    dlg.m_ofn.lpstrTitle = "Van Gogh Palette File";

    if (dlg.DoModal() == IDOK)
    {
        if (!pDoc->LoadPalette(dlg.GetPathName()))
        {
            MessageBox("Reverting to previous palette file","Information",MB_OK);
            pDoc->LoadPalette(pDoc->pfname);
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrMainFrame - OnAppHelp                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrMainFrame::OnAppHelp()
{
    int     i;
    char    *c;
    char    fname[256];

    GetModuleFileName(NULL, fname, 256);

    for (i=strlen(fname), c = &fname[i-1]; i > 0; i--, c--)
    {
        if (*c == '\\')
        {
            strcpy(c+1,"MythOS.HLP");

            if (xf_exist(fname))
                break;
        }
    }
    if (!i)
        strcpy(fname,"MythOS.HLP");

    ::WinHelp(GetSafeHwnd(),
              fname,
              HELP_CONTEXT, 1001);
}

//°±² eof - eshtmfrm.cpp ²±°
