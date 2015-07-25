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
//ùùùùùùùùùùùCopyrightù(c)ù1994-1996ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
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
	m_slevels = 0;
	m_levels = 0;
	m_bpercent = 0.0f;
	m_blevels = 0;
	//}}AFX_DATA_INIT

    m_levels = 64;
    m_slevels = 24;
    m_blevels = 48;
    m_bpercent = 50.0f;
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
	DDX_Text(pDX, IDC_CPROP_SLEVEL, m_slevels);
	DDX_Text(pDX, IDC_CPROP_LEVEL, m_levels);
	DDX_Text(pDX, IDC_CPROP_BPERC, m_bpercent);
	DDV_MinMaxFloat(pDX, m_bpercent, 1.f, 99.f);
	DDX_Text(pDX, IDC_CPROP_BLEVEL, m_blevels);
	//}}AFX_DATA_MAP

    if (pDX->m_bSaveAndValidate)
    {
        pDX->PrepareCtrl(IDC_CPROP_BITMAP);
        if (m_bg_active && !bg_bm)
        {
            AfxMessageBox("Must select bitmap.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        pDX->PrepareEditCtrl(IDC_CPROP_LEVEL);
        switch(m_levels)
        {
            case 8:
            case 16:
            case 32:
            case 64:
            case 128:
            case 256:
                break;
            default:
                AfxMessageBox("Must be 8, 16, 32, 64, 128, or 256.",MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
        }

        pDX->PrepareEditCtrl(IDC_CPROP_SLEVEL);
        if (m_slevels >= m_levels)
        {
            AfxMessageBox("Must be less than the number of levels.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        pDX->PrepareEditCtrl(IDC_CPROP_BLEVEL);
        if (m_blevels >= m_levels)
        {
            AfxMessageBox("Must be less than the number of levels.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
        if (m_blevels <= m_slevels)
        {
            AfxMessageBox("Must be greater than the number of unaffected levels.",MB_OK | MB_ICONEXCLAMATION);
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

        XFParseBitmap	*b=0;
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

        if (bm->bpp != 1)
        {
            delete bm;
            MessageBox("Must be an 8-bit image",
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

LightPropGeneralPage::LightPropGeneralPage() : CPropertyPage(LightPropGeneralPage::IDD)
{
	//{{AFX_DATA_INIT(LightPropGeneralPage)
	m_name = _T("");
	m_active = FALSE;
	m_xiValue = 0.0f;
	m_yjValue = 0.0f;
	m_zkValue = 0.0f;
	m_atten = FALSE;
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

BEGIN_MESSAGE_MAP(LightPropGeneralPage, CPropertyPage)
	//{{AFX_MSG_MAP(LightPropGeneralPage)
	ON_CBN_SELCHANGE(IDC_LPROP_TYPE, OnTypeSelectChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

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

BEGIN_MESSAGE_MAP(LightPropExtraPage, CPropertyPage)
	//{{AFX_MSG_MAP(LightPropExtraPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// LightPropAppFlagsPage                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(LightPropAppFlagsPage, CPropertyPage)

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

BEGIN_MESSAGE_MAP(LightPropAppFlagsPage, CPropertyPage)
	//{{AFX_MSG_MAP(LightPropAppFlagsPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Mesh Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropGeneralPage                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

IMPLEMENT_DYNCREATE(MeshPropGeneralPage, CPropertyPage)

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

BEGIN_MESSAGE_MAP(MeshPropGeneralPage, CPropertyPage)
	//{{AFX_MSG_MAP(MeshPropGeneralPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropOrientPage                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(MeshPropOrientPage, CPropertyPage)

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

BEGIN_MESSAGE_MAP(MeshPropOrientPage, CPropertyPage)
	//{{AFX_MSG_MAP(MeshPropOrientPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropExtPage                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(MeshPropExtPage, CPropertyPage)

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

BEGIN_MESSAGE_MAP(MeshPropExtPage, CPropertyPage)
	//{{AFX_MSG_MAP(MeshPropExtPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// MeshPropAppFlagsPage                                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(MeshPropAppFlagsPage, CPropertyPage)

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

BEGIN_MESSAGE_MAP(MeshPropAppFlagsPage, CPropertyPage)
	//{{AFX_MSG_MAP(MeshPropAppFlagsPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//°±² eof - eshtdlg.cpp ²±°
