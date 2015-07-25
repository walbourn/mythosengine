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
//                             *** Escher Tool ***
//
// Chuck Walbourn
//
// eshtdlg.cpp
//
// Escher Tool dialog classes.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "stdafx.h"
#include "eshtool.h"
#include "eshtdoc.h"
#include "eshtdlg.h"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Scene Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ScenePropGeneralPage                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(ScenePropGeneralPage, CPropertyPage)

BEGIN_MESSAGE_MAP(ScenePropGeneralPage, CPropertyPage)
        //{{AFX_MSG_MAP(ScenePropGeneralPage)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

ScenePropGeneralPage::ScenePropGeneralPage() : CPropertyPage(ScenePropGeneralPage::IDD)
{
        //{{AFX_DATA_INIT(ScenePropGeneralPage)
        m_name = _T("");
        m_ncameras = 0;
        m_nmeshes = 0;
        m_nplights = 0;
        m_nvlights = 0;
        m_nfplights = 0;
        m_nalights = 0;
        m_nslights = 0;
        m_nfalights = 0;
        m_nfslights = 0;
        //}}AFX_DATA_INIT
}

ScenePropGeneralPage::~ScenePropGeneralPage()
{
}

void ScenePropGeneralPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(ScenePropGeneralPage)
        DDX_Text(pDX, IDC_SPROP_NAME, m_name);
        DDV_MaxChars(pDX, m_name, 16);
        DDX_Text(pDX, IDC_SPROP_NCAMERAS, m_ncameras);
        DDV_MinMaxUInt(pDX, m_ncameras, 0, 65535);
        DDX_Text(pDX, IDC_SPROP_NMESHES, m_nmeshes);
        DDV_MinMaxUInt(pDX, m_nmeshes, 0, 65535);
        DDX_Text(pDX, IDC_SPROP_NPLIGHTS, m_nplights);
        DDV_MinMaxUInt(pDX, m_nplights, 0, 65535);
        DDX_Text(pDX, IDC_SPROP_NVLIGHTS, m_nvlights);
        DDV_MinMaxUInt(pDX, m_nvlights, 0, 65535);
        DDX_Text(pDX, IDC_SPROP_NFPLIGHTS, m_nfplights);
        DDV_MinMaxUInt(pDX, m_nfplights, 0, 65535);
        DDX_Text(pDX, IDC_SPROP_NALIGHTS, m_nalights);
        DDV_MinMaxUInt(pDX, m_nalights, 0, 65535);
        DDX_Text(pDX, IDC_SPROP_NSLIGHTS, m_nslights);
        DDV_MinMaxUInt(pDX, m_nslights, 0, 65535);
        DDX_Text(pDX, IDC_SPROP_NFALIGHTS, m_nfalights);
        DDV_MinMaxUInt(pDX, m_nfalights, 0, 65535);
        DDX_Text(pDX, IDC_SPROP_NFSLIGHTS, m_nfslights);
        DDV_MinMaxUInt(pDX, m_nfslights, 0, 65535);
        //}}AFX_DATA_MAP
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ScenePropMiscPage                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(ScenePropMiscPage, CPropertyPage)

BEGIN_MESSAGE_MAP(ScenePropMiscPage, CPropertyPage)
        //{{AFX_MSG_MAP(ScenePropMiscPage)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

ScenePropMiscPage::ScenePropMiscPage() : CPropertyPage(ScenePropMiscPage::IDD)
{
        //{{AFX_DATA_INIT(ScenePropMiscPage)
        m_auth = _T("");
        m_copy = _T("");
        m_desc = _T("");
        //}}AFX_DATA_INIT
}

ScenePropMiscPage::~ScenePropMiscPage()
{
}

void ScenePropMiscPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(ScenePropMiscPage)
        DDX_Text(pDX, IDC_SPROP_AUTH, m_auth);
        DDV_MaxChars(pDX, m_auth, 256);
        DDX_Text(pDX, IDC_SPROP_COPY, m_copy);
        DDV_MaxChars(pDX, m_copy, 256);
        DDX_Text(pDX, IDC_SPROP_DESC, m_desc);
        DDV_MaxChars(pDX, m_desc, 256);
        //}}AFX_DATA_MAP
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°° Camera Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// CameraPropGeneralPage                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(CameraPropGeneralPage, CPropertyPage)

BEGIN_MESSAGE_MAP(CameraPropGeneralPage, CPropertyPage)
        //{{AFX_MSG_MAP(CameraPropGeneralPage)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CameraPropGeneralPage::CameraPropGeneralPage() : CPropertyPage(CameraPropGeneralPage::IDD)
{
        //{{AFX_DATA_INIT(CameraPropGeneralPage)
        m_name = _T("");
        m_xpos = 0.0f;
        m_ypos = 0.0f;
        m_zpos = 0.0f;
        m_idir = 0.0f;
        m_jdir = 0.0f;
        m_kdir = 0.0f;
        m_itop = 0.0f;
        m_jtop = 0.0f;
        m_ktop = 0.0f;
        m_fov = 0.0f;
        m_height = 0.0f;
        m_width = 0.0f;
        //}}AFX_DATA_INIT
}

CameraPropGeneralPage::~CameraPropGeneralPage()
{
}

void CameraPropGeneralPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CameraPropGeneralPage)
        DDX_Text(pDX, IDC_CPROP_NAME, m_name);
        DDV_MaxChars(pDX, m_name, 16);
        DDX_Text(pDX, IDC_CPROP_XPOS, m_xpos);
        DDV_MinMaxFloat(pDX, m_xpos, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_CPROP_YPOS, m_ypos);
        DDV_MinMaxFloat(pDX, m_ypos, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_CPROP_ZPOS, m_zpos);
        DDV_MinMaxFloat(pDX, m_zpos, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_CPROP_IDIR, m_idir);
        DDV_MinMaxFloat(pDX, m_idir, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_CPROP_JDIR, m_jdir);
        DDV_MinMaxFloat(pDX, m_jdir, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_CPROP_KDIR, m_kdir);
        DDV_MinMaxFloat(pDX, m_kdir, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_CPROP_ITOP, m_itop);
        DDV_MinMaxFloat(pDX, m_itop, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_CPROP_JTOP, m_jtop);
        DDV_MinMaxFloat(pDX, m_jtop, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_CPROP_KTOP, m_ktop);
        DDV_MinMaxFloat(pDX, m_ktop, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_CPROP_FOV, m_fov);
        DDV_MinMaxFloat(pDX, m_fov, 1.f, 127.f);
        DDX_Text(pDX, IDC_CPROP_HEIGHT, m_height);
        DDV_MinMaxFloat(pDX, m_height, 0.f, 32768.f);
        DDX_Text(pDX, IDC_CPROP_WIDTH, m_width);
        DDV_MinMaxFloat(pDX, m_width, 0.1f, 32768.f);
        //}}AFX_DATA_MAP

    if (pDX->m_bSaveAndValidate)
    {
        pDX->PrepareEditCtrl(IDC_CPROP_NAME);

/////////////////////////////////////////////////////////////////////
// ADD CHECK FOR UNIQUE CAMERA NAME!!!
/////////////////////////////////////////////////////////////////////

    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// CameraPropAppFlagsPage                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(CameraPropAppFlagsPage, CPropertyPage)

BEGIN_MESSAGE_MAP(CameraPropAppFlagsPage, CPropertyPage)
        //{{AFX_MSG_MAP(CameraPropAppFlagsPage)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CameraPropAppFlagsPage::CameraPropAppFlagsPage() : CPropertyPage(CameraPropAppFlagsPage::IDD)
{
        //{{AFX_DATA_INIT(CameraPropAppFlagsPage)
        m_app1 = FALSE;
        m_app2 = FALSE;
        m_app3 = FALSE;
        m_app4 = FALSE;
        m_app5 = FALSE;
        m_app6 = FALSE;
        m_app7 = FALSE;
        m_app0 = FALSE;
        //}}AFX_DATA_INIT
}

CameraPropAppFlagsPage::~CameraPropAppFlagsPage()
{
}

void CameraPropAppFlagsPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CameraPropAppFlagsPage)
        DDX_Check(pDX, IDC_CPROP_FLAGS_APP1, m_app1);
        DDX_Check(pDX, IDC_CPROP_FLAGS_APP2, m_app2);
        DDX_Check(pDX, IDC_CPROP_FLAGS_APP3, m_app3);
        DDX_Check(pDX, IDC_CPROP_FLAGS_APP4, m_app4);
        DDX_Check(pDX, IDC_CPROP_FLAGS_APP5, m_app5);
        DDX_Check(pDX, IDC_CPROP_FLAGS_APP6, m_app6);
        DDX_Check(pDX, IDC_CPROP_FLAGS_APP7, m_app7);
        DDX_Check(pDX, IDC_CPROP_FLAGS_APP0, m_app0);
        //}}AFX_DATA_MAP
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// CameraPropMiscPage                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(CameraPropMiscPage, CPropertyPage)

BEGIN_MESSAGE_MAP(CameraPropMiscPage, CPropertyPage)
        //{{AFX_MSG_MAP(CameraPropMiscPage)
        ON_BN_CLICKED(IDC_CPROP_BCOLR, OnBackgroundColor)
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CameraPropMiscPage::CameraPropMiscPage() : CPropertyPage(CameraPropMiscPage::IDD)
{
        //{{AFX_DATA_INIT(CameraPropMiscPage)
        m_hither = 0.0f;
        m_yon = 0.0f;
        m_scalef = 0.0f;
        //}}AFX_DATA_INIT
}

CameraPropMiscPage::~CameraPropMiscPage()
{
}

void CameraPropMiscPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CameraPropMiscPage)
        DDX_Text(pDX, IDC_CPROP_HITHER, m_hither);
        DDV_MinMaxFloat(pDX, m_hither, 0.f, 32768.f);
        DDX_Text(pDX, IDC_CPROP_YON, m_yon);
        DDV_MinMaxFloat(pDX, m_yon, 0.f, 32768.f);
        DDX_Text(pDX, IDC_CPROP_SCALEF, m_scalef);
        DDV_MinMaxFloat(pDX, m_scalef, 0.f, 32768.f);
        //}}AFX_DATA_MAP

    if (pDX->m_bSaveAndValidate)
    {
        pDX->PrepareEditCtrl(IDC_CPROP_YON);
        if (m_yon <= m_hither)
        {
            AfxMessageBox("Yon must be larger than hither.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
    }
}

void CameraPropMiscPage::OnBackgroundColor()
{
    CColorDialog dlg(m_bcolor, CC_RGBINIT | CC_FULLOPEN, this);

    if (dlg.DoModal() == IDOK)
    {
        m_bcolor = dlg.GetColor();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// CameraPropExPage                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(CameraPropExPage, CPropertyPage)

BEGIN_MESSAGE_MAP(CameraPropExPage, CPropertyPage)
        //{{AFX_MSG_MAP(CameraPropExPage)
        ON_BN_CLICKED(IDC_CPROP_BITMAP, OnSelectBitmap)
        ON_BN_CLICKED(IDC_CPROP_HCOLR, OnHazeColor)
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CameraPropExPage::CameraPropExPage() : CPropertyPage(CameraPropExPage::IDD),
    bg_bm (0),
    haze_color (0),
    haze_change (FALSE)
{
        //{{AFX_DATA_INIT(CameraPropExPage)
        m_bg_active = FALSE;
        m_haze_active = FALSE;
        m_startz = 0.0f;
        m_midz = 0.0f;
        //}}AFX_DATA_INIT

    m_startz = 0.5f;
    m_midz = 0.85f;
}

CameraPropExPage::~CameraPropExPage()
{
}

void CameraPropExPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CameraPropExPage)
        DDX_Control(pDX, IDC_CPROP_BMBACK, m_bg_activeCtl);
        DDX_Control(pDX, IDC_CPROP_HAZE, m_haze_activeCtl);
        DDX_Check(pDX, IDC_CPROP_BMBACK, m_bg_active);
        DDX_Check(pDX, IDC_CPROP_HAZE, m_haze_active);
        DDX_Text(pDX, IDC_CPROP_STARTZ, m_startz);
        DDV_MinMaxFloat(pDX, m_startz, 0.f, 1.f);
        DDX_Text(pDX, IDC_CPROP_MIDZ, m_midz);
        DDV_MinMaxFloat(pDX, m_midz, 0.f, 1.f);
        //}}AFX_DATA_MAP

    if (pDX->m_bSaveAndValidate)
    {
        pDX->PrepareCtrl(IDC_CPROP_BITMAP);
        if (m_bg_active && !bg_bm)
        {
            AfxMessageBox("Must select bitmap.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        pDX->PrepareEditCtrl(IDC_CPROP_MIDZ);
        if (m_midz < m_startz)
        {
            AfxMessageBox("Must be greater than the Start Z.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
    }
}

void CameraPropExPage::OnSelectBitmap()
{
    CFileDialog dlg(TRUE,
                    NULL, NULL,
                    OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
                    "Bitmap files (*.bmp;*.cel;*.lbm;*.pcx;*.xeb)"
                    "|*.BMP;*.CEL;*.LBM;*.PCX;*.XEB|All files (*.*)|*.*||",
                    this);

    dlg.m_ofn.lpstrTitle = "Bitmap background file";

    if (dlg.DoModal() == IDOK)
    {
        CString name = dlg.GetPathName();

        XFBitmap *bm = new XFBitmap;
        if (!bm)
        {
            MessageBox("No memory",
                       "Escher Tool",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        XFParseBitmap   *b=0;
        if (name.Find(".bmp") != -1)
        {
                    b = new XFParseBMP (bm);
        }
        else if (name.Find(".cel") != -1)
        {
                    b = new XFParseCEL (bm);
        }
        else if (name.Find(".lbm") != -1)
        {
                    b = new XFParseLBM (bm);
        }
        else if (name.Find(".pcx") != -1)
        {
                    b = new XFParsePCX (bm);
        }
        else if (name.Find(".xeb") != -1)
        {
                    b = new XFParseXEB (bm);
        }
        else
        {
            delete bm;
            MessageBox("Unsupported file type",
                       "Escher Tool",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        if (!b)
        {
            delete bm;
            MessageBox("No memory",
                       "Escher Tool",MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        int err=b->nameread((LPCSTR)name);

        if (b)
            delete b;

        // Display error, if one encountered
        if (err)
        {
            delete bm;

            char    str[128];

            wsprintf(str,
                     "Error %d during read of file",
                     err);
            MessageBox(str,
                       "Escher Tool",
                       MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        if (bm->bpp != 1 && bm->bpp != 2 && bm->bpp != 3)
        {
            delete bm;
            MessageBox("Must be an 8-bit, 15-bit, or 24-bit image",
                       "Escher Tool",
                       MB_OK | MB_ICONEXCLAMATION);
            return;
        }

        if (bg_bm)
            delete bg_bm;

        m_bg_activeCtl.SetCheck(1);
        bg_bm=bm;
    }
}

void CameraPropExPage::OnHazeColor()
{
    CColorDialog dlg(haze_color, CC_RGBINIT | CC_FULLOPEN, this);

    if (dlg.DoModal() == IDOK)
    {
        haze_color = dlg.GetColor();
        m_haze_activeCtl.SetCheck(1);
        haze_change=TRUE;
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Light Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// LightPropGeneralPage                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(LightPropGeneralPage, CPropertyPage)

BEGIN_MESSAGE_MAP(LightPropGeneralPage, CPropertyPage)
        //{{AFX_MSG_MAP(LightPropGeneralPage)
        ON_CBN_SELCHANGE(IDC_LPROP_TYPE, OnTypeSelectChange)
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

LightPropGeneralPage::LightPropGeneralPage() : CPropertyPage(LightPropGeneralPage::IDD)
{
        //{{AFX_DATA_INIT(LightPropGeneralPage)
        m_name = _T("");
        m_active = FALSE;
        m_xiValue = 0.0f;
        m_yjValue = 0.0f;
        m_zkValue = 0.0f;
        m_atten = FALSE;
        m_dark = FALSE;
        //}}AFX_DATA_INIT

    m_type = 0;
    m_edit = 1;
}

LightPropGeneralPage::~LightPropGeneralPage()
{
}

void LightPropGeneralPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(LightPropGeneralPage)
        DDX_Control(pDX, IDC_LPROP_INTENSITY, m_iSlider);
        DDX_Control(pDX, IDC_LPROP_ZK, m_zkCtrl);
        DDX_Control(pDX, IDC_LPROP_YJ, m_yjCtrl);
        DDX_Control(pDX, IDC_LPROP_XI, m_xiCtrl);
        DDX_Control(pDX, IDC_LPROP_TYPE, m_typeList);
        DDX_Text(pDX, IDC_LPROP_NAME, m_name);
        DDV_MaxChars(pDX, m_name, 16);
        DDX_Check(pDX, IDC_LPROP_ON, m_active);
        DDX_Text(pDX, IDC_LPROP_XI, m_xiValue);
        DDV_MinMaxFloat(pDX, m_xiValue, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_LPROP_YJ, m_yjValue);
        DDV_MinMaxFloat(pDX, m_yjValue, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_LPROP_ZK, m_zkValue);
        DDV_MinMaxFloat(pDX, m_zkValue, -32768.f, 32768.f);
        DDX_Check(pDX, IDC_LPROP_ATTEN, m_atten);
        DDX_Check(pDX, IDC_LPROP_DARK, m_dark);
        //}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        m_typeList.SetCurSel(m_type);
        m_typeList.EnableWindow(m_edit);

        m_xiCtrl.EnableWindow(m_type ? 1 : 0);
        m_yjCtrl.EnableWindow(m_type ? 1 : 0);
        m_zkCtrl.EnableWindow(m_type ? 1 : 0);

        m_iSlider.SetRange(0,255);
        m_iSlider.SetPos(m_intensity);
    }
    else
    {
        m_intensity = (byte)m_iSlider.GetPos();
        m_type = m_typeList.GetCurSel();

        pDX->PrepareEditCtrl(IDC_LPROP_NAME);

/////////////////////////////////////////////////////////////////////
// ADD CHECK FOR UNIQUE LIGHT NAME!!!
/////////////////////////////////////////////////////////////////////

    }
}

void LightPropGeneralPage::OnTypeSelectChange()
{
    m_xiCtrl.EnableWindow( (m_typeList.GetCurSel()) ? 1 : 0);
    m_yjCtrl.EnableWindow( (m_typeList.GetCurSel()) ? 1 : 0);
    m_zkCtrl.EnableWindow( (m_typeList.GetCurSel()) ? 1 : 0);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// LightPropExtraPage                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(LightPropExtraPage, CPropertyPage)

BEGIN_MESSAGE_MAP(LightPropExtraPage, CPropertyPage)
        //{{AFX_MSG_MAP(LightPropExtraPage)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

LightPropExtraPage::LightPropExtraPage() : CPropertyPage(LightPropExtraPage::IDD)
{
        //{{AFX_DATA_INIT(LightPropExtraPage)
        m_inner = 0.0f;
        m_outer = 0.0f;
        m_falloff = 0.0f;
        m_hotspot = 0.0f;
        m_diri = 0.0f;
        m_dirj = 0.0f;
        m_dirk = 0.0f;
        //}}AFX_DATA_INIT

    m_outer = 4096.0f;
    m_hotspot = 44.0f;
    m_falloff = 45.0f;
    m_dirk = 1.0f;
}

LightPropExtraPage::~LightPropExtraPage()
{
}

void LightPropExtraPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(LightPropExtraPage)
        DDX_Text(pDX, IDC_LPROP_INNER, m_inner);
        DDV_MinMaxFloat(pDX, m_inner, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_LPROP_OUTER, m_outer);
        DDV_MinMaxFloat(pDX, m_outer, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_LPROP_FALLOFF, m_falloff);
        DDV_MinMaxFloat(pDX, m_falloff, 0.f, 175.f);
        DDX_Text(pDX, IDC_LPROP_HOTSPOT, m_hotspot);
        DDV_MinMaxFloat(pDX, m_hotspot, 0.f, 175.f);
        DDX_Text(pDX, IDC_LPROP_XI, m_diri);
        DDV_MinMaxFloat(pDX, m_diri, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_LPROP_YJ, m_dirj);
        DDV_MinMaxFloat(pDX, m_dirj, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_LPROP_ZK, m_dirk);
        DDV_MinMaxFloat(pDX, m_dirk, -32768.f, 32768.f);
        //}}AFX_DATA_MAP
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// LightPropAppFlagsPage                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(LightPropAppFlagsPage, CPropertyPage)

BEGIN_MESSAGE_MAP(LightPropAppFlagsPage, CPropertyPage)
        //{{AFX_MSG_MAP(LightPropAppFlagsPage)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

LightPropAppFlagsPage::LightPropAppFlagsPage() : CPropertyPage(LightPropAppFlagsPage::IDD)
{
        //{{AFX_DATA_INIT(LightPropAppFlagsPage)
        m_app1 = FALSE;
        m_app2 = FALSE;
        m_app3 = FALSE;
        m_app4 = FALSE;
        m_app5 = FALSE;
        m_app6 = FALSE;
        m_app7 = FALSE;
        m_app0 = FALSE;
        //}}AFX_DATA_INIT
}

LightPropAppFlagsPage::~LightPropAppFlagsPage()
{
}

void LightPropAppFlagsPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(LightPropAppFlagsPage)
        DDX_Check(pDX, IDC_LPROP_FLAGS_APP1, m_app1);
        DDX_Check(pDX, IDC_LPROP_FLAGS_APP2, m_app2);
        DDX_Check(pDX, IDC_LPROP_FLAGS_APP3, m_app3);
        DDX_Check(pDX, IDC_LPROP_FLAGS_APP4, m_app4);
        DDX_Check(pDX, IDC_LPROP_FLAGS_APP5, m_app5);
        DDX_Check(pDX, IDC_LPROP_FLAGS_APP6, m_app6);
        DDX_Check(pDX, IDC_LPROP_FLAGS_APP7, m_app7);
        DDX_Check(pDX, IDC_LPROP_FLAGS_APP0, m_app0);
        //}}AFX_DATA_MAP
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Face Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// FacePropGeneralPage                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(FacePropGeneralPage, CPropertyPage)

BEGIN_MESSAGE_MAP(FacePropGeneralPage, CPropertyPage)
        //{{AFX_MSG_MAP(FacePropGeneralPage)
        ON_CBN_SELCHANGE(IDC_FPROP_TXT, OnTextureChange)
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

FacePropGeneralPage::FacePropGeneralPage() :
    CPropertyPage(FacePropGeneralPage::IDD),
    tmax(0),
    txt(0),
    tind(0)
{
        //{{AFX_DATA_INIT(FacePropGeneralPage)
        m_a = 0;
        m_b = 0;
        m_c = 0;
        m_i = 0.0f;
        m_k = 0.0f;
        m_j = 0.0f;
        m_u0 = 0.0f;
        m_u1 = 0.0f;
        m_u2 = 0.0f;
        m_v0 = 0.0f;
        m_v1 = 0.0f;
        m_v2 = 0.0f;
        //}}AFX_DATA_INIT
}

FacePropGeneralPage::~FacePropGeneralPage()
{
}

void FacePropGeneralPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(FacePropGeneralPage)
        DDX_Control(pDX, IDC_FPROP_V2, m_v2Ctl);
        DDX_Control(pDX, IDC_FPROP_V1, m_v1Ctl);
        DDX_Control(pDX, IDC_FPROP_V0, m_v0Ctl);
        DDX_Control(pDX, IDC_FPROP_U2, m_u2Ctl);
        DDX_Control(pDX, IDC_FPROP_U1, m_u1Ctl);
        DDX_Control(pDX, IDC_FPROP_U0, m_u0Ctl);
        DDX_Control(pDX, IDC_FPROP_TXT, m_txtList);
        DDX_Text(pDX, IDC_FPROP_A, m_a);
        DDX_Text(pDX, IDC_FPROP_B, m_b);
        DDX_Text(pDX, IDC_FPROP_C, m_c);
        DDX_Text(pDX, IDC_FPROP_I, m_i);
        DDV_MinMaxFloat(pDX, m_i, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_FPROP_K, m_k);
        DDV_MinMaxFloat(pDX, m_k, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_FPROP_J, m_j);
        DDV_MinMaxFloat(pDX, m_j, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_FPROP_U0, m_u0);
        DDV_MinMaxFloat(pDX, m_u0, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_FPROP_U1, m_u1);
        DDV_MinMaxFloat(pDX, m_u1, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_FPROP_U2, m_u2);
        DDV_MinMaxFloat(pDX, m_u2, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_FPROP_V0, m_v0);
        DDV_MinMaxFloat(pDX, m_v0, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_FPROP_V1, m_v1);
        DDV_MinMaxFloat(pDX, m_v1, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_FPROP_V2, m_v2);
        DDV_MinMaxFloat(pDX, m_v2, -32768.f, 32768.f);
        //}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        m_txtList.ResetContent();
        m_txtList.AddString("None");
        m_txtList.SetCurSel(0);

        if (txt)
        {
            for(ulong i=0; i < tmax; i++)
            {
                CString name = (txt[i]) ? txt[i]->name : "?";
                name = name.Left(ESCH_MAX_NAME);
                m_txtList.AddString(name);
            }

            if (tind < (int)tmax+1)
                m_txtList.SetCurSel(tind);
        }

        m_u0Ctl.EnableWindow(tind > 0 ? 1 : 0);
        m_u1Ctl.EnableWindow(tind > 0 ? 1 : 0);
        m_u2Ctl.EnableWindow(tind > 0 ? 1 : 0);
        m_v0Ctl.EnableWindow(tind > 0 ? 1 : 0);
        m_v1Ctl.EnableWindow(tind > 0 ? 1 : 0);
        m_v2Ctl.EnableWindow(tind > 0 ? 1 : 0);
    }
    else
    {
        int s= m_txtList.GetCurSel();

        if (s < (int)tmax+1)
            tind = s;
    }
}

void FacePropGeneralPage::OnTextureChange()
{
    int s = m_txtList.GetCurSel();

    m_u0Ctl.EnableWindow(s > 0 ? 1 : 0);
    m_u1Ctl.EnableWindow(s > 0 ? 1 : 0);
    m_u2Ctl.EnableWindow(s > 0 ? 1 : 0);
    m_v0Ctl.EnableWindow(s > 0 ? 1 : 0);
    m_v1Ctl.EnableWindow(s > 0 ? 1 : 0);
    m_v2Ctl.EnableWindow(s > 0 ? 1 : 0);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// FacePropFlagsPage                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(FacePropFlagsPage, CPropertyPage)

BEGIN_MESSAGE_MAP(FacePropFlagsPage, CPropertyPage)
        //{{AFX_MSG_MAP(FacePropFlagsPage)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

FacePropFlagsPage::FacePropFlagsPage() : CPropertyPage(FacePropFlagsPage::IDD)
{
        //{{AFX_DATA_INIT(FacePropFlagsPage)
        m_1sided = FALSE;
        m_abline = FALSE;
        m_allow_persp = FALSE;
        m_bcline = FALSE;
        m_caline = FALSE;
        m_flat = FALSE;
        m_smooth = FALSE;
        m_solid = FALSE;
        m_specular = FALSE;
        m_wire = FALSE;
        m_alpha = FALSE;
        m_alpha_a = 0;
        m_alpha_b = 0;
        m_alpha_c = 0;
        m_selfillum = 0;
        //}}AFX_DATA_INIT
}

FacePropFlagsPage::~FacePropFlagsPage()
{
}

void FacePropFlagsPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(FacePropFlagsPage)
        DDX_Check(pDX, IDC_FPROP_1SIDED, m_1sided);
        DDX_Check(pDX, IDC_FPROP_ABLINE, m_abline);
        DDX_Check(pDX, IDC_FPROP_APERSP, m_allow_persp);
        DDX_Check(pDX, IDC_FPROP_BCLINE, m_bcline);
        DDX_Check(pDX, IDC_FPROP_CALINE, m_caline);
        DDX_Check(pDX, IDC_FPROP_FLAT, m_flat);
        DDX_Check(pDX, IDC_FPROP_SMOOTH, m_smooth);
        DDX_Check(pDX, IDC_FPROP_SOLID, m_solid);
        DDX_Check(pDX, IDC_FPROP_SPECULAR, m_specular);
        DDX_Check(pDX, IDC_FPROP_WIRE, m_wire);
        DDX_Check(pDX, IDC_FPROP_ALPHA, m_alpha);
        DDX_Text(pDX, IDC_FPROP_ALPHAA, m_alpha_a);
        DDV_MinMaxUInt(pDX, m_alpha_a, 0, 255);
        DDX_Text(pDX, IDC_FPROP_ALPHAB, m_alpha_b);
        DDV_MinMaxUInt(pDX, m_alpha_b, 0, 255);
        DDX_Text(pDX, IDC_FPROP_ALPHAC, m_alpha_c);
        DDV_MinMaxUInt(pDX, m_alpha_c, 0, 255);
        DDX_Text(pDX, IDC_FPROP_SELFILLUM, m_selfillum);
        DDV_MinMaxUInt(pDX, m_selfillum, 0, 255);
        //}}AFX_DATA_MAP
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// FacePropAppFlagsPage                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(FacePropAppFlagsPage, CPropertyPage)

BEGIN_MESSAGE_MAP(FacePropAppFlagsPage, CPropertyPage)
        //{{AFX_MSG_MAP(FacePropAppFlagsPage)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

FacePropAppFlagsPage::FacePropAppFlagsPage() : CPropertyPage(FacePropAppFlagsPage::IDD)
{
        //{{AFX_DATA_INIT(FacePropAppFlagsPage)
        m_app0 = FALSE;
        m_app1 = FALSE;
        m_app2 = FALSE;
        m_app3 = FALSE;
        //}}AFX_DATA_INIT
}

FacePropAppFlagsPage::~FacePropAppFlagsPage()
{
}

void FacePropAppFlagsPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(FacePropAppFlagsPage)
        DDX_Check(pDX, IDC_FPROP_FLAGS_APP0, m_app0);
        DDX_Check(pDX, IDC_FPROP_FLAGS_APP1, m_app1);
        DDX_Check(pDX, IDC_FPROP_FLAGS_APP2, m_app2);
        DDX_Check(pDX, IDC_FPROP_FLAGS_APP3, m_app3);
        //}}AFX_DATA_MAP
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°° Texture Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TexturePropGenPage                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(TexturePropGenPage, CPropertyPage)

BEGIN_MESSAGE_MAP(TexturePropGenPage, CPropertyPage)
        //{{AFX_MSG_MAP(TexturePropGenPage)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

TexturePropGenPage::TexturePropGenPage() : CPropertyPage(TexturePropGenPage::IDD)
{
        //{{AFX_DATA_INIT(TexturePropGenPage)
        m_animate = FALSE;
        m_height = 0;
        m_name = _T("");
        m_nframes = 0;
        m_type = -1;
        m_width = 0;
        //}}AFX_DATA_INIT
}

TexturePropGenPage::~TexturePropGenPage()
{
}

void TexturePropGenPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(TexturePropGenPage)
        DDX_Check(pDX, IDC_TPROP_ANIMATE, m_animate);
        DDX_Text(pDX, IDC_TPROP_HEIGHT, m_height);
        DDX_Text(pDX, IDC_TPROP_NAME, m_name);
        DDV_MaxChars(pDX, m_name, 16);
        DDX_Text(pDX, IDC_TPROP_NFRAMES, m_nframes);
        DDX_CBIndex(pDX, IDC_TPROP_TYPE, m_type);
        DDX_Text(pDX, IDC_TPROP_WIDTH, m_width);
        //}}AFX_DATA_MAP

    if (pDX->m_bSaveAndValidate)
    {
        pDX->PrepareEditCtrl(IDC_TPROP_NAME);

/////////////////////////////////////////////////////////////////////
// ADD CHECK FOR UNIQUE TEXTURE NAME!!!
/////////////////////////////////////////////////////////////////////

    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TexturePropAppFlagsPage                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(TexturePropAppFlagsPage, CPropertyPage)

BEGIN_MESSAGE_MAP(TexturePropAppFlagsPage, CPropertyPage)
        //{{AFX_MSG_MAP(TexturePropAppFlagsPage)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

TexturePropAppFlagsPage::TexturePropAppFlagsPage() : CPropertyPage(TexturePropAppFlagsPage::IDD)
{
        //{{AFX_DATA_INIT(TexturePropAppFlagsPage)
        m_app0 = FALSE;
        m_app1 = FALSE;
        m_app2 = FALSE;
        m_app3 = FALSE;
        m_app4 = FALSE;
        m_app5 = FALSE;
        m_app6 = FALSE;
        m_app7 = FALSE;
        //}}AFX_DATA_INIT
}

TexturePropAppFlagsPage::~TexturePropAppFlagsPage()
{
}

void TexturePropAppFlagsPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(TexturePropAppFlagsPage)
        DDX_Check(pDX, IDC_LPROP_FLAGS_APP0, m_app0);
        DDX_Check(pDX, IDC_LPROP_FLAGS_APP1, m_app1);
        DDX_Check(pDX, IDC_LPROP_FLAGS_APP2, m_app2);
        DDX_Check(pDX, IDC_LPROP_FLAGS_APP3, m_app3);
        DDX_Check(pDX, IDC_LPROP_FLAGS_APP4, m_app4);
        DDX_Check(pDX, IDC_LPROP_FLAGS_APP5, m_app5);
        DDX_Check(pDX, IDC_LPROP_FLAGS_APP6, m_app6);
        DDX_Check(pDX, IDC_LPROP_FLAGS_APP7, m_app7);
        //}}AFX_DATA_MAP
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Mesh Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropGeneralPage                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

IMPLEMENT_DYNCREATE(MeshPropGeneralPage, CPropertyPage)

BEGIN_MESSAGE_MAP(MeshPropGeneralPage, CPropertyPage)
        //{{AFX_MSG_MAP(MeshPropGeneralPage)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

MeshPropGeneralPage::MeshPropGeneralPage() : CPropertyPage(MeshPropGeneralPage::IDD)
{
        //{{AFX_DATA_INIT(MeshPropGeneralPage)
        m_name = _T("");
        m_parent = _T("");
        m_child = _T("");
        m_xpos = 0.0f;
        m_ypos = 0.0f;
        m_zpos = 0.0f;
        m_visible = FALSE;
        m_chkext = FALSE;
        m_nfaces = 0;
        m_nverts = 0;
        //}}AFX_DATA_INIT
}

MeshPropGeneralPage::~MeshPropGeneralPage()
{
}

void MeshPropGeneralPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(MeshPropGeneralPage)
        DDX_Text(pDX, IDC_MPROP_NAME, m_name);
        DDV_MaxChars(pDX, m_name, 16);
        DDX_Text(pDX, IDC_MPROP_PARENT, m_parent);
        DDV_MaxChars(pDX, m_parent, 16);
        DDX_Text(pDX, IDC_MPROP_CHILD, m_child);
        DDV_MaxChars(pDX, m_child, 16);
        DDX_Text(pDX, IDC_MPROP_XPOS, m_xpos);
        DDV_MinMaxFloat(pDX, m_xpos, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_YPOS, m_ypos);
        DDV_MinMaxFloat(pDX, m_ypos, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_ZPOS, m_zpos);
        DDV_MinMaxFloat(pDX, m_zpos, -32768.f, 32768.f);
        DDX_Check(pDX, IDC_MPROP_VISIBLE, m_visible);
        DDX_Check(pDX, IDC_MPROP_CHKEXT, m_chkext);
        DDX_Text(pDX, IDC_MPROP_NFACES, m_nfaces);
        DDX_Text(pDX, IDC_MPROP_NVERTS, m_nverts);
        //}}AFX_DATA_MAP

    if (pDX->m_bSaveAndValidate)
    {
        pDX->PrepareEditCtrl(IDC_MPROP_NAME);

/////////////////////////////////////////////////////////////////////
// ADD CHECK FOR UNIQUE MESH NAME!!!
/////////////////////////////////////////////////////////////////////

    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropOrientPage                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(MeshPropOrientPage, CPropertyPage)

BEGIN_MESSAGE_MAP(MeshPropOrientPage, CPropertyPage)
        //{{AFX_MSG_MAP(MeshPropOrientPage)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

MeshPropOrientPage::MeshPropOrientPage() : CPropertyPage(MeshPropOrientPage::IDD)
{
        //{{AFX_DATA_INIT(MeshPropOrientPage)
        m_mtxa = 0.0f;
        m_mtxb = 0.0f;
        m_mtxc = 0.0f;
        m_mtxd = 0.0f;
        m_mtxe = 0.0f;
        m_mtxf = 0.0f;
        m_mtxg = 0.0f;
        m_mtxh = 0.0f;
        m_mtxi = 0.0f;
        //}}AFX_DATA_INIT
}

MeshPropOrientPage::~MeshPropOrientPage()
{
}

void MeshPropOrientPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(MeshPropOrientPage)
        DDX_Text(pDX, IDC_MPROP_MTXA, m_mtxa);
        DDV_MinMaxFloat(pDX, m_mtxa, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_MTXB, m_mtxb);
        DDV_MinMaxFloat(pDX, m_mtxb, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_MTXC, m_mtxc);
        DDV_MinMaxFloat(pDX, m_mtxc, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_MTXD, m_mtxd);
        DDV_MinMaxFloat(pDX, m_mtxd, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_MTXE, m_mtxe);
        DDV_MinMaxFloat(pDX, m_mtxe, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_MTXF, m_mtxf);
        DDV_MinMaxFloat(pDX, m_mtxf, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_MTXG, m_mtxg);
        DDV_MinMaxFloat(pDX, m_mtxg, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_MTXH, m_mtxh);
        DDV_MinMaxFloat(pDX, m_mtxh, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_MTXI, m_mtxi);
        DDV_MinMaxFloat(pDX, m_mtxi, -32768.f, 32768.f);
        //}}AFX_DATA_MAP
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropExtPage                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(MeshPropExtPage, CPropertyPage)

BEGIN_MESSAGE_MAP(MeshPropExtPage, CPropertyPage)
        //{{AFX_MSG_MAP(MeshPropExtPage)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

MeshPropExtPage::MeshPropExtPage() : CPropertyPage(MeshPropExtPage::IDD)
{
        //{{AFX_DATA_INIT(MeshPropExtPage)
        m_xcen = 0.0f;
        m_ycen = 0.0f;
        m_zcen = 0.0f;
        m_xmin = 0.0f;
        m_ymin = 0.0f;
        m_zmin = 0.0f;
        m_xmax = 0.0f;
        m_ymax = 0.0f;
        m_zmax = 0.0f;
        m_radius = 0.0f;
        //}}AFX_DATA_INIT
}

MeshPropExtPage::~MeshPropExtPage()
{
}

void MeshPropExtPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(MeshPropExtPage)
        DDX_Text(pDX, IDC_MPROP_XCEN, m_xcen);
        DDV_MinMaxFloat(pDX, m_xcen, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_YCEN, m_ycen);
        DDV_MinMaxFloat(pDX, m_ycen, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_ZCEN, m_zcen);
        DDV_MinMaxFloat(pDX, m_zcen, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_XMIN, m_xmin);
        DDV_MinMaxFloat(pDX, m_xmin, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_YMIN, m_ymin);
        DDV_MinMaxFloat(pDX, m_ymin, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_ZMIN, m_zmin);
        DDV_MinMaxFloat(pDX, m_zmin, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_XMAX, m_xmax);
        DDV_MinMaxFloat(pDX, m_xmax, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_YMAX, m_ymax);
        DDV_MinMaxFloat(pDX, m_ymax, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_ZMAX, m_zmax);
        DDV_MinMaxFloat(pDX, m_zmax, -32768.f, 32768.f);
        DDX_Text(pDX, IDC_MPROP_RADIUS, m_radius);
        DDV_MinMaxFloat(pDX, m_radius, 0.f, 32768.f);
        //}}AFX_DATA_MAP
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropVertsPage                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(MeshPropVertsPage, CPropertyPage)

BEGIN_MESSAGE_MAP(MeshPropVertsPage, CPropertyPage)
        //{{AFX_MSG_MAP(MeshPropVertsPage)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

MeshPropVertsPage::MeshPropVertsPage() :
    CPropertyPage(MeshPropVertsPage::IDD),
    nverts(0),
    v(0)
{
        //{{AFX_DATA_INIT(MeshPropVertsPage)
                // NOTE: the ClassWizard will add member initialization here
        //}}AFX_DATA_INIT
}

MeshPropVertsPage::~MeshPropVertsPage()
{
}

void MeshPropVertsPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(MeshPropVertsPage)
        DDX_Control(pDX, IDC_MPROP_VLIST, m_vList);
        //}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        m_vList.ResetContent();

        ASSERT(v);
        EschVertex *vtx = (EschVertex*) ivory_hlock(v);
        if (!vtx)
            m_vList.AddString("Lock Failed!");
        else
        {
            for(ulong i=0; i < nverts; i++)
            {
                char buff[128];
                sprintf(buff,
                        "[%03d]   X: %8.2f  Y: %8.2f  Z: %8.2f    Nrml: (%5.3f,%5.3f,%5.3f)",
                        i,
                        float(vtx[i].x),
                        float(vtx[i].y),
                        float(vtx[i].z),
                        float(vtx[i].normal.i),
                        float(vtx[i].normal.j),
                        float(vtx[i].normal.k));
                m_vList.AddString(buff);
            }

            ivory_hunlock(v);
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropFacePage                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(MeshPropFacePage, CPropertyPage)

BEGIN_MESSAGE_MAP(MeshPropFacePage, CPropertyPage)
        //{{AFX_MSG_MAP(MeshPropFacePage)
        ON_BN_CLICKED(IDC_MPROP_FPROP, OnProperties)
        ON_LBN_DBLCLK(IDC_MPROP_FLIST, OnDblClick)
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

MeshPropFacePage::MeshPropFacePage() :
    CPropertyPage(MeshPropFacePage::IDD),
    nfaces(0),
    f(0),
    nverts(0),
    tmax(0),
    txt(0),
    cursel(0),
    pDoc(0)
{
        //{{AFX_DATA_INIT(MeshPropFacePage)
        //}}AFX_DATA_INIT
}

MeshPropFacePage::~MeshPropFacePage()
{
}

void MeshPropFacePage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(MeshPropFacePage)
        DDX_Control(pDX, IDC_MPROP_FPROP, m_fProp);
        DDX_Control(pDX, IDC_MPROP_FLIST, m_fList);
        //}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        if (cursel < 0 || cursel > (int)nfaces)
            cursel = 0;

        m_fList.ResetContent();

        ASSERT(f);
        EschFace *face = (EschFace*) ivory_hlock(f);
        if (!face)
            m_fList.AddString("Lock Failed!");
        else
        {
            for(ulong i=0; i < nfaces; i++)
            {
                char buff[128];
                sprintf(buff,
                        "[%03d]   A: %4d  B: %4d  C: %4d  TXT: %4d      Nrml: (%5.3f,%5.3f,%5.3f)",
                        i,
                        face[i].a,
                        face[i].b,
                        face[i].c,
                        face[i].txt,
                        float(face[i].normal.i),
                        float(face[i].normal.j),
                        float(face[i].normal.k));
                m_fList.AddString(buff);
            }
            if (i > 0)
            {
                m_fProp.EnableWindow(1);
                m_fList.SetCurSel(cursel);
            }
            else
            {
                m_fProp.EnableWindow(0);
            }

            ivory_hunlock(f);
        }
    }
}

void MeshPropFacePage::ui_face_properties()
{
    if (cursel != LB_ERR && cursel < (int)nfaces)
    {
        assert(f);

        EschFace *face = (EschFace*)ivory_hlock(f);
        face = &face[cursel];
        if (f)
        {
            //ÄÄÄ General
            FacePropGeneralPage gdlg;

            gdlg.m_a = face->a;
            gdlg.m_b = face->b;
            gdlg.m_c = face->c;

            gdlg.m_i = face->normal.i;
            gdlg.m_j = face->normal.j;
            gdlg.m_k = face->normal.k;

            gdlg.tind = (face->flags & ESCH_FACE_TEXTURED) ? face->txt : 0;

            gdlg.m_u0 = face->u[0];
            gdlg.m_u1 = face->u[1];
            gdlg.m_u2 = face->u[2];

            gdlg.m_v0 = face->v[0];
            gdlg.m_v1 = face->v[1];
            gdlg.m_v2 = face->v[2];

            gdlg.tmax = tmax;
            gdlg.txt = txt;

            //ÄÄÄ Flags
            FacePropFlagsPage   fdlg;

            fdlg.m_wire = (face->flags & ESCH_FACE_WIRE) ? 1 : 0;
            fdlg.m_solid = (face->flags & ESCH_FACE_SOLID) ? 1 : 0;
            fdlg.m_flat = (face->flags & ESCH_FACE_FLAT) ? 1 : 0;
            fdlg.m_smooth = (face->flags & ESCH_FACE_SMOOTH) ? 1 : 0;
            fdlg.m_specular = (face->flags & ESCH_FACE_SPECULAR) ? 1 : 0;
            fdlg.m_alpha = (face->flags & ESCH_FACE_ALPHA) ? 1 : 0;

            fdlg.m_abline = (face->flags & ESCH_FACE_ABLINE) ? 1 : 0;
            fdlg.m_bcline = (face->flags & ESCH_FACE_BCLINE) ? 1 : 0;
            fdlg.m_caline = (face->flags & ESCH_FACE_CALINE) ? 1 : 0;

            fdlg.m_1sided = (face->flags & ESCH_FACE_ONESIDED) ? 1 : 0;

            fdlg.m_allow_persp = (face->flags & ESCH_FACE_ALLOWPERSP) ? 1 : 0;

            fdlg.m_selfillum = face->self_illum;

            fdlg.m_alpha_a = face->alpha_a;
            fdlg.m_alpha_b = face->alpha_b;
            fdlg.m_alpha_c = face->alpha_c;

            //ÄÄÄ Application Flags
            FacePropAppFlagsPage   afdlg;

            afdlg.m_app0 = (face->flags & ESCH_FACE_APP0) ? 1 : 0;
            afdlg.m_app1 = (face->flags & ESCH_FACE_APP1) ? 1 : 0;
            afdlg.m_app2 = (face->flags & ESCH_FACE_APP2) ? 1 : 0;
            afdlg.m_app3 = (face->flags & ESCH_FACE_APP3) ? 1 : 0;

            //ÄÄÄ Interact
            CPropertySheet  sh("Face Properties");
            sh.AddPage(&gdlg);
            sh.AddPage(&fdlg);
            sh.AddPage(&afdlg);

            //ÄÄÄ Store results, if OK
            if (sh.DoModal() == IDOK)
            {
                //ÄÄÄ General
                face->normal.i = gdlg.m_i;
                face->normal.j = gdlg.m_j;
                face->normal.k = gdlg.m_k;
                face->normal.normalize();

                if (gdlg.tind)
                {
                    face->flags |= ESCH_FACE_TEXTURED;
                    face->txt = gdlg.tind;
                }
                else
                {
                    face->flags &= ~ESCH_FACE_TEXTURED;
                    face->txt = 0;
                }

                face->u[0] = gdlg.m_u0;
                face->u[1] = gdlg.m_u1;
                face->u[2] = gdlg.m_u2;

                face->v[0] = gdlg.m_v0;
                face->v[1] = gdlg.m_v1;
                face->v[2] = gdlg.m_v2;

                dword flags = face->flags;

                //ÄÄÄ Flags
                flags &= ~(ESCH_FACE_WIRE
                           | ESCH_FACE_SOLID
                           | ESCH_FACE_FLAT
                           | ESCH_FACE_SMOOTH
                           | ESCH_FACE_SPECULAR
                           | ESCH_FACE_ALPHA
                           | ESCH_FACE_ABLINE
                           | ESCH_FACE_BCLINE
                           | ESCH_FACE_ABLINE);

                if (fdlg.m_wire)
                    flags |= ESCH_FACE_WIRE;
                if (fdlg.m_solid)
                    flags |= ESCH_FACE_SOLID;
                if (fdlg.m_flat)
                    flags |= ESCH_FACE_FLAT;
                if (fdlg.m_smooth)
                    flags |= ESCH_FACE_SMOOTH;
                if (fdlg.m_specular)
                    flags |= ESCH_FACE_SPECULAR;
                if (fdlg.m_alpha)
                    flags |= ESCH_FACE_ALPHA;

                if (fdlg.m_abline)
                    flags |= ESCH_FACE_ABLINE;
                if (fdlg.m_bcline)
                    flags |= ESCH_FACE_BCLINE;
                if (fdlg.m_caline)
                    flags |= ESCH_FACE_CALINE;

                if (fdlg.m_1sided)
                    flags |= ESCH_FACE_ONESIDED;

                if (fdlg.m_allow_persp)
                    flags |= ESCH_FACE_ALLOWPERSP;

                face->self_illum = byte(fdlg.m_selfillum);

                face->alpha_a = byte(fdlg.m_alpha_a);
                face->alpha_b = byte(fdlg.m_alpha_b);
                face->alpha_c = byte(fdlg.m_alpha_c);

                //ÄÄÄ Application Flags
                flags &= ~(ESCH_FACE_APP0
                           | ESCH_FACE_APP1
                           | ESCH_FACE_APP2
                           | ESCH_FACE_APP3);

                if (afdlg.m_app0)
                    flags |= ESCH_FACE_APP0;
                if (afdlg.m_app1)
                    flags |= ESCH_FACE_APP1;
                if (afdlg.m_app2)
                    flags |= ESCH_FACE_APP2;
                if (afdlg.m_app3)
                    flags |= ESCH_FACE_APP3;

                face->flags = flags;

                assert(pDoc);
                pDoc->SetModifiedFlag();

                UpdateData(FALSE);
            }

            ivory_hunlock(f);
        }
        else
        {
            AfxMessageBox("Face Locked Failed",MB_OK | MB_ICONEXCLAMATION);
        }
    }
}


void MeshPropFacePage::OnDblClick()
{
    cursel = m_fList.GetCurSel();
    ui_face_properties();
}

void MeshPropFacePage::OnProperties()
{
    cursel = m_fList.GetCurSel();
    ui_face_properties();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropTexturePage                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(MeshPropTexturePage, CPropertyPage)

BEGIN_MESSAGE_MAP(MeshPropTexturePage, CPropertyPage)
        //{{AFX_MSG_MAP(MeshPropTexturePage)
        ON_BN_CLICKED(IDC_MPROP_TXTPROP, OnProperties)
        ON_LBN_DBLCLK(IDC_MPROP_TXTLIST, OnDblClick)
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

MeshPropTexturePage::MeshPropTexturePage() :
     CPropertyPage(MeshPropTexturePage::IDD),
     tmax(0),
     txt(0),
     cursel(0),
     pDoc(0)
{
        //{{AFX_DATA_INIT(MeshPropTexturePage)
                // NOTE: the ClassWizard will add member initialization here
        //}}AFX_DATA_INIT
}

MeshPropTexturePage::~MeshPropTexturePage()
{
}

void MeshPropTexturePage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(MeshPropTexturePage)
        DDX_Control(pDX, IDC_MPROP_TXTPROP, m_txtProp);
        DDX_Control(pDX, IDC_MPROP_TXTLIST, m_txtList);
        //}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        if (cursel < 0 || cursel > (int)tmax)
            cursel = 0;

        m_txtList.ResetContent();
        if (txt)
        {
            for(ulong i=0; i < tmax; i++)
            {
                char buff[32];
                wsprintf(buff,"[%03d]   %16s",i,(txt[i]) ? txt[i]->name : "?");
                m_txtList.AddString(buff);
            }
            if (i > 0)
            {
                m_txtProp.EnableWindow(1);
                m_txtList.SetCurSel(cursel);
            }
            else
            {
                m_txtProp.EnableWindow(0);
            }
        }
    }
}

void MeshPropTexturePage::ui_texture_properties()
{
    if (cursel != LB_ERR && cursel < (int)tmax)
    {
        assert(txt);

        EschTexture *t=txt[cursel];

        if (t)
        {
            //ÄÄÄ General
            TexturePropGenPage gdlg;
            gdlg.m_name = t->name;
            gdlg.m_name = gdlg.m_name.Left(ESCH_MAX_NAME);

            switch (t->get_type())
            {
                case ESCH_TXTT_STATIC:
                    gdlg.m_type = 1;
                    break;
                case ESCH_TXTT_MFRAME:
                    gdlg.m_type = 2;
                    break;
                default:
                    gdlg.m_type = 0;
                    break;
            }

            t->lock();
            if (t->ptr)
            {
                gdlg.m_width = t->ptr->width;
                gdlg.m_height = t->ptr->height;
            }
            t->unlock();

            gdlg.m_nframes = (t->get_type() == ESCH_TXTT_MFRAME)
                             ? ((EschMultiFrameTexture*)t)->max
                             : 1;

            gdlg.m_animate = (t->flags & ESCH_TXT_SKIPANIMATE) ? 0 : 1;

            //ÄÄÄ Application Flags
            TexturePropAppFlagsPage  afdlg;
            afdlg.m_app0 = (t->flags & ESCH_TXT_APP0) ? 1 : 0;
            afdlg.m_app1 = (t->flags & ESCH_TXT_APP1) ? 1 : 0;
            afdlg.m_app2 = (t->flags & ESCH_TXT_APP2) ? 1 : 0;
            afdlg.m_app3 = (t->flags & ESCH_TXT_APP3) ? 1 : 0;
            afdlg.m_app4 = (t->flags & ESCH_TXT_APP4) ? 1 : 0;
            afdlg.m_app5 = (t->flags & ESCH_TXT_APP5) ? 1 : 0;
            afdlg.m_app6 = (t->flags & ESCH_TXT_APP6) ? 1 : 0;
            afdlg.m_app7 = (t->flags & ESCH_TXT_APP7) ? 1 : 0;

            //ÄÄÄ Interact
            CPropertySheet  sh("Texture Properties");
            sh.AddPage(&gdlg);
            sh.AddPage(&afdlg);

            //ÄÄÄ Store results, if OK
            if (sh.DoModal() == IDOK)
            {
                //ÄÄÄ General
                strncpy(t->name,gdlg.m_name,ESCH_MAX_NAME);

                if (gdlg.m_animate)
                    t->flags &= ~ESCH_TXT_SKIPANIMATE;
                else
                    t->flags |= ESCH_TXT_SKIPANIMATE;

                //ÄÄÄ Application Flags
                dword flags = t->flags;
                flags &= ~(ESCH_TXT_APP0
                           | ESCH_TXT_APP1
                           | ESCH_TXT_APP2
                           | ESCH_TXT_APP3
                           | ESCH_TXT_APP4
                           | ESCH_TXT_APP5
                           | ESCH_TXT_APP6
                           | ESCH_TXT_APP7);

                if (afdlg.m_app0)
                    flags |= ESCH_TXT_APP0;
                if (afdlg.m_app1)
                    flags |= ESCH_TXT_APP1;
                if (afdlg.m_app2)
                    flags |= ESCH_TXT_APP2;
                if (afdlg.m_app3)
                    flags |= ESCH_TXT_APP3;
                if (afdlg.m_app4)
                    flags |= ESCH_TXT_APP4;
                if (afdlg.m_app5)
                    flags |= ESCH_TXT_APP5;
                if (afdlg.m_app6)
                    flags |= ESCH_TXT_APP6;
                if (afdlg.m_app7)
                    flags |= ESCH_TXT_APP7;

                t->set_flags(flags);

                assert(pDoc);
                pDoc->SetModifiedFlag();

                UpdateData(FALSE);
            }
        }
        else
        {
            AfxMessageBox("No Texture Data",MB_OK | MB_ICONEXCLAMATION);
        }
    }
}

void MeshPropTexturePage::OnDblClick()
{
    cursel = m_txtList.GetCurSel();
    ui_texture_properties();
}

void MeshPropTexturePage::OnProperties()
{
    cursel = m_txtList.GetCurSel();
    ui_texture_properties();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropAppFlagsPage                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(MeshPropAppFlagsPage, CPropertyPage)

BEGIN_MESSAGE_MAP(MeshPropAppFlagsPage, CPropertyPage)
        //{{AFX_MSG_MAP(MeshPropAppFlagsPage)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

MeshPropAppFlagsPage::MeshPropAppFlagsPage() : CPropertyPage(MeshPropAppFlagsPage::IDD)
{
        //{{AFX_DATA_INIT(MeshPropAppFlagsPage)
        m_app0 = FALSE;
        m_app1 = FALSE;
        m_app2 = FALSE;
        m_app3 = FALSE;
        m_app4 = FALSE;
        m_app5 = FALSE;
        m_app6 = FALSE;
        m_app7 = FALSE;
        m_app8 = FALSE;
        m_app9 = FALSE;
        m_appa = FALSE;
        m_appb = FALSE;
        m_appc = FALSE;
        m_appd = FALSE;
        m_appe = FALSE;
        m_appf = FALSE;
        //}}AFX_DATA_INIT
}

MeshPropAppFlagsPage::~MeshPropAppFlagsPage()
{
}

void MeshPropAppFlagsPage::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(MeshPropAppFlagsPage)
        DDX_Check(pDX, IDC_MPROP_FLAGS_APP0, m_app0);
        DDX_Check(pDX, IDC_MPROP_FLAGS_APP1, m_app1);
        DDX_Check(pDX, IDC_MPROP_FLAGS_APP2, m_app2);
        DDX_Check(pDX, IDC_MPROP_FLAGS_APP3, m_app3);
        DDX_Check(pDX, IDC_MPROP_FLAGS_APP4, m_app4);
        DDX_Check(pDX, IDC_MPROP_FLAGS_APP5, m_app5);
        DDX_Check(pDX, IDC_MPROP_FLAGS_APP6, m_app6);
        DDX_Check(pDX, IDC_MPROP_FLAGS_APP7, m_app7);
        DDX_Check(pDX, IDC_MPROP_FLAGS_APP8, m_app8);
        DDX_Check(pDX, IDC_MPROP_FLAGS_APP9, m_app9);
        DDX_Check(pDX, IDC_MPROP_FLAGS_APPA, m_appa);
        DDX_Check(pDX, IDC_MPROP_FLAGS_APPB, m_appb);
        DDX_Check(pDX, IDC_MPROP_FLAGS_APPC, m_appc);
        DDX_Check(pDX, IDC_MPROP_FLAGS_APPD, m_appd);
        DDX_Check(pDX, IDC_MPROP_FLAGS_APPE, m_appe);
        DDX_Check(pDX, IDC_MPROP_FLAGS_APPF, m_appf);
        //}}AFX_DATA_MAP
}

//°±² eof - eshtdlg.cpp ²±°

