//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//���������������������������������������������������������������������������
//����������旭旭旭旭旭�旭旭旭旭���旭旭旭旭��旭姻���旭姻旭旭旭旭旭�旭旭旭旭姻�
//���������葦姻������葦姻���葦姻葦姻���葦姻葦姻���葦姻葦姻�������葦姻���葦姻�
//��������碓甥������碓甥�������碓甥�������碓甥���碓甥碓甥�������碓甥���碓甥��
//�������渦臼葦渦��渦臼葦渦臼�渦甥�������渦臼葦渦臼�渦臼葦渦���渦臼葦渦姻����
//������渦甥�������������渦甥渦甥�������渦甥���渦甥渦甥�������渦甥���渦甥����
//�����憶悔������憶悔���憶悔憶悔���憶悔憶悔���憶悔憶悔�������憶悔���憶悔�����
//����臆臆臆臆臆�臆臆臆臆���臆臆臆臆��臆悔���臆悔臆臆臆臆臆�臆悔���臆悔������
//���������������������������������������������������������������������������
//����������Copyright�(c)�1994,�1995�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//��������������������� Microsoft Windows '95 Version �����������������������
//���������������������������������������������������������������������������
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        *** Escher Terrain Editor ***
//
// Chuck Walbourn
//
// eshtmfrm.cpp
//
// Main window frame class.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//                                
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "stdafx.h"
#include "eshtedit.h"

#include "eshtmfrm.h"
#include "eshtdoc.h"
#include "eshtview.h"
#include "eshtdlg.h"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrMainFrame                                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Arrays of IDs used to initialize control bars                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

// toolbar buttons - IDs are command buttons
static UINT BASED_CODE buttons[] =
{
	// same order as in the bitmap 'toolbar.bmp'
	ID_FILE_NEW,
	ID_FILE_OPEN,
	ID_FILE_SAVE,
		ID_SEPARATOR,
	ID_EDIT_CUT,
	ID_EDIT_COPY,
	ID_EDIT_PASTE,
		ID_SEPARATOR,
	ID_FILE_PRINT,
	ID_APP_ABOUT,
};

static UINT BASED_CODE indicators[] =
{
	ID_SEPARATOR,           // status line indicator
    ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
    ID_INDICATOR_SCRL,
};

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭� Constructor/Destructor 旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrMainFrame - Constructor                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
TerrMainFrame::TerrMainFrame()
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrMainFrame - Destructor                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
TerrMainFrame::~TerrMainFrame()
{
}


//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭 Message Handlers 旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrMainFrame - OnCreate                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrMainFrame - AssertValid                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
#ifdef _DEBUG
void TerrMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void TerrMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrMainFrame - OnFileExport                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrMainFrame::OnFileExport() 
{
    CFileDialog dlg(FALSE,
                    "IFF", "EXPORT.IFF",
                    OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST,
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrMainFrame - OnTerrProperties                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrMainFrame::OnTerrProperties() 
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    pDoc->UITerrainProperities(NULL,0);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrMainFrame - OnTerrImport                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrMainFrame::OnTerrImport() 
{
    CFileDialog dlg(TRUE,
                    NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
                    "Digital Elevation Model files (*.dem)|*.DEM|Bitmap files (*.pcx)|*.PCX|All files (*.*)|*.*||",
                    this);

    dlg.m_ofn.lpstrTitle = "Terrain Import File";

    if (dlg.DoModal() == IDOK)
    {
        TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
        ASSERT_VALID(pDoc);

        pDoc->ImportTerrain((LPCSTR)dlg.GetPathName(),1);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrMainFrame - OnSurfImport                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrMainFrame::OnSurfImport() 
{
    CFileDialog dlg(TRUE,
                    NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrMainFrame - OnSurfDefineTexture                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrMainFrame::OnSurfDefineTexture() 
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    if (pDoc->txtNumb >= 255)
    {
        MessageBox("No more texture definitions may be added.\n\n(The may be at most 255 texture definitions in a terrain data set)\n",
                   "Define Texture Error",
                   MB_OK | MB_ICONEXCLAMATION);
        return;
    }

    TexturePropDlg dlg(pDoc);

    if (dlg.DoModal() == IDOK)
    {
        pDoc->AddTexture(dlg.m_name,dlg.m_fname,dlg.m_color);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrMainFrame - OnSurfEditTexture                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrMainFrame::OnSurfEditTexture() 
{
    TerrEditView *pView = (TerrEditView*)GetActiveView();
    ASSERT_VALID(pView);

    int i = pView->GetCurrentTextureSel();

    if (i == LB_ERR)
    {
        MessageBox("Please highlight the texture definition to edit in the Texture Definitions window.",
                   "Edit Texture Error",
                   MB_OK | MB_ICONSTOP);
        return;
    }

    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    ASSERT(i < pDoc->txtNumb);

    TexturePropDlg dlg(pDoc,i);

    dlg.m_name = pDoc->txtName[i];
    dlg.m_fname = pDoc->txtFName[i];
    dlg.m_color = pDoc->txtColr[i];

    if (dlg.DoModal() == IDOK)
    {
        pDoc->SetTexture(i,dlg.m_name,dlg.m_fname,dlg.m_color);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrMainFrame - OnSurfDeleteTexture                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrMainFrame::OnSurfDeleteTexture() 
{
    TerrEditView *pView = (TerrEditView*)GetActiveView();
    ASSERT_VALID(pView);

    int i = pView->GetCurrentTextureSel();

    if (i == LB_ERR)
    {
        MessageBox("Please highlight the texture definition to delete in the Texture Definitions window.",
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrMainFrame - OnSurfPalette                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrMainFrame::OnSurfPalette() 
{
    TerrEditDoc *pDoc = (TerrEditDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    CFileDialog dlg(TRUE,
                    "PAL", pDoc->pfname,
                    OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
                    "Van Gogh palette file (*.pal)|*.PAL|All files (*.*)|*.*||",
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

//葦� eof - eshtmfrm.cpp 憶�
