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
// eshtdlg.cpp
//
// Terrain Editor Dialog Classes
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "stdafx.h"
#include "eshtedit.h"
#include "eshtdlg.h"
#include "eshtdoc.h"

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
//°°°°°°°°°°°°°°°°°°°°°°°° Terrain Properies Dialog °°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrPropDlgA                                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

IMPLEMENT_DYNCREATE(TerrPropDlgA, CPropertyPage)

BEGIN_MESSAGE_MAP(TerrPropDlgA, CPropertyPage)
	//{{AFX_MSG_MAP(TerrPropDlgA)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


TerrPropDlgA::TerrPropDlgA() : CPropertyPage(TerrPropDlgA::IDD)
{
	//{{AFX_DATA_INIT(TerrPropDlgA)
	m_width = 0;
	m_depth = 0;
	m_dscale = 0.0f;
	m_hscale = 0.0f;
	m_wscale = 0.0f;
	m_name = _T("");
	//}}AFX_DATA_INIT

    m_edit=1;
}

TerrPropDlgA::~TerrPropDlgA()
{
}

void TerrPropDlgA::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TerrPropDlgA)
	DDX_Control(pDX, IDC_TPROP_SURFRATIO, m_surfratioCtl);
	DDX_Control(pDX, IDC_TPROP_DEPTH, m_depthCtl);
	DDX_Control(pDX, IDC_TPROP_WIDTH, m_widthCtl);
	DDX_Text(pDX, IDC_TPROP_WIDTH, m_width);
	DDV_MinMaxUInt(pDX, m_width, 0, 32768);
	DDX_Text(pDX, IDC_TPROP_DEPTH, m_depth);
	DDV_MinMaxUInt(pDX, m_depth, 0, 32768);
	DDX_Text(pDX, IDC_TPROP_DSCALE, m_dscale);
	DDV_MinMaxFloat(pDX, m_dscale, 1.f, 1024.f);
	DDX_Text(pDX, IDC_TPROP_HSCALE, m_hscale);
	DDV_MinMaxFloat(pDX, m_hscale, 1.f, 1024.f);
	DDX_Text(pDX, IDC_TPROP_WSCALE, m_wscale);
	DDV_MinMaxFloat(pDX, m_wscale, 1.f, 1024.f);
	DDX_Text(pDX, IDC_TPROP_NAME, m_name);
	DDV_MaxChars(pDX, m_name, 15);
	//}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        switch (m_surfratio)
        {
            case 1:
                m_surfratioCtl.SetCurSel(0);
                break;
            case 2:
                m_surfratioCtl.SetCurSel(1);
                break;
            case 4:
                m_surfratioCtl.SetCurSel(2);
                break;
            case 8:
                m_surfratioCtl.SetCurSel(3);
                break;
            case 16:
                m_surfratioCtl.SetCurSel(4);
                break;
            default:
                m_surfratioCtl.SetCurSel(0);
                break;
        }

        m_widthCtl.EnableWindow (m_edit);
        m_depthCtl.EnableWindow (m_edit);
        m_surfratioCtl.EnableWindow (m_edit);
    }
    else
    {
        pDX->PrepareEditCtrl(IDC_TPROP_WIDTH);
        if (m_width & 0x1)
        {
            AfxMessageBox("Please enter an even number.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
        pDX->PrepareEditCtrl(IDC_TPROP_DEPTH);
        if (m_depth & 0x1)
        {
            AfxMessageBox("Please enter an even number.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        pDX->PrepareEditCtrl(IDC_TPROP_SURFRATIO);
        switch (m_surfratioCtl.GetCurSel())
        {
            case 0:
                m_surfratio = 1;
                break;
            case 1:
                m_surfratio = 2;
                break;
            case 2:
                m_surfratio = 4;
                break;
            case 3:
                m_surfratio = 8;
                break;
            case 4:
                m_surfratio = 16;
                break;
            default:
                AfxMessageBox("Must be be 1:1, 2:1, 4:1, 8:1, or 16:1.",MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
                break;
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrPropDlgB                                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

IMPLEMENT_DYNCREATE(TerrPropDlgB, CPropertyPage)

BEGIN_MESSAGE_MAP(TerrPropDlgB, CPropertyPage)
	//{{AFX_MSG_MAP(TerrPropDlgB)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

TerrPropDlgB::TerrPropDlgB() : CPropertyPage(TerrPropDlgB::IDD)
{
	//{{AFX_DATA_INIT(TerrPropDlgB)
	m_copy = _T("");
	m_auth = _T("");
	m_desc = _T("");
	//}}AFX_DATA_INIT
}

TerrPropDlgB::~TerrPropDlgB()
{
}

void TerrPropDlgB::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TerrPropDlgB)
	DDX_Text(pDX, IDC_TPROP_COPY, m_copy);
	DDV_MaxChars(pDX, m_copy, 255);
	DDX_Text(pDX, IDC_TPROP_AUTH, m_auth);
	DDV_MaxChars(pDX, m_auth, 255);
	DDX_Text(pDX, IDC_TPROP_DESC, m_desc);
	DDV_MaxChars(pDX, m_desc, 255);
	//}}AFX_DATA_MAP
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Camera Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// CameraPropDlg                                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

BEGIN_MESSAGE_MAP(CameraPropDlg, CDialog)
	//{{AFX_MSG_MAP(CameraPropDlg)
	ON_BN_CLICKED(IDC_CPROP_COLR, OnBackgroundColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CameraPropDlg::CameraPropDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CameraPropDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CameraPropDlg)
	m_fov = 0.0f;
	m_hither = 0.0f;
	m_xpos = 0.0f;
	m_yon = 0.0f;
	m_ypos = 0.0f;
	m_zpos = 0.0f;
	//}}AFX_DATA_INIT
}

void CameraPropDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CameraPropDlg)
	DDX_Text(pDX, IDC_CPROP_FOV, m_fov);
	DDV_MinMaxFloat(pDX, m_fov, 1.f, 127.f);
	DDX_Text(pDX, IDC_CPROP_HITHER, m_hither);
	DDV_MinMaxFloat(pDX, m_hither, 0.f, 32768.f);
	DDX_Text(pDX, IDC_CPROP_XPOS, m_xpos);
	DDV_MinMaxFloat(pDX, m_xpos, -32768.f, 32768.f);
	DDX_Text(pDX, IDC_CPROP_YON, m_yon);
	DDV_MinMaxFloat(pDX, m_yon, 0.f, 32768.f);
	DDX_Text(pDX, IDC_CPROP_YPOS, m_ypos);
	DDV_MinMaxFloat(pDX, m_ypos, -32768.f, 32768.f);
	DDX_Text(pDX, IDC_CPROP_ZPOS, m_zpos);
	DDV_MinMaxFloat(pDX, m_zpos, -32768.f, 32768.f);
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

void CameraPropDlg::OnBackgroundColor() 
{
    CColorDialog dlg(m_bcolor, CC_RGBINIT, this);
	
    if (dlg.DoModal() == IDOK)
    {
        m_bcolor = dlg.GetColor();
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Surface Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// SurfacePropDlg                                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

BEGIN_MESSAGE_MAP(SurfacePropDlg, CDialog)
	//{{AFX_MSG_MAP(SurfacePropDlg)
	ON_BN_CLICKED(IDC_SPROP_COLR, OnColor)
	ON_CBN_SELCHANGE(IDC_SPROP_TXT, OnTextureSelectChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

SurfacePropDlg::SurfacePropDlg(TerrEditDoc *pd, CWnd* pParent /*=NULL*/)
	: CDialog(SurfacePropDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(SurfacePropDlg)
	m_cbit1 = FALSE;
	m_cbit2 = FALSE;
	m_cbit3 = FALSE;
	m_cbit4 = FALSE;
	m_dloc = 0;
	m_xloc = 0;
	m_fire = -1;
	m_smoke = -1;
	m_water = -1;
	//}}AFX_DATA_INIT

    pDoc = pd;
    m_txt = 0;
    ASSERT(pDoc);
}

void SurfacePropDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SurfacePropDlg)
	DDX_Control(pDX, IDC_SPROP_COLR, m_colorbutn);
	DDX_Control(pDX, IDC_SPROP_TXT, m_txtlist);
	DDX_Check(pDX, IDC_SPROP_CBIT1, m_cbit1);
	DDX_Check(pDX, IDC_SPROP_CBIT2, m_cbit2);
	DDX_Check(pDX, IDC_SPROP_CBIT3, m_cbit3);
	DDX_Check(pDX, IDC_SPROP_CBIT4, m_cbit4);
	DDX_Text(pDX, IDC_SPROP_DLOC, m_dloc);
	DDV_MinMaxUInt(pDX, m_dloc, 0, 65536);
	DDX_Text(pDX, IDC_SPROP_XLOC, m_xloc);
	DDV_MinMaxUInt(pDX, m_xloc, 0, 65536);
	DDX_CBIndex(pDX, IDC_SPROP_FIRE, m_fire);
	DDX_CBIndex(pDX, IDC_SPROP_SMOKE, m_smoke);
	DDX_CBIndex(pDX, IDC_SPROP_WATER, m_water);
	//}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        m_colorbutn.EnableWindow(!m_cbit3);

        m_txtlist.AddString("None");
        for(int i=0; i < pDoc->txtNumb; i++)
        {
            m_txtlist.AddString(pDoc->txtName[i]);
        }
        m_txtlist.SetCurSel(m_txt);
    }
    else
    {
        m_txt = m_txtlist.GetCurSel();
    }
}

void SurfacePropDlg::OnTextureSelectChange() 
{
    int i = m_txtlist.GetCurSel();

    m_colorbutn.EnableWindow( (i) ? 0 : 1);

    HWND    hWndCbit3 = ::GetDlgItem(GetSafeHwnd(),IDC_SPROP_CBIT3);
    
    ::SendMessage(hWndCbit3, BM_SETCHECK, ((i) ? 1 : 0), 0L);
}

void SurfacePropDlg::OnColor() 
{
    CColorDialog dlg(m_color, CC_RGBINIT | CC_FULLOPEN, this);
	
    if (dlg.DoModal() == IDOK)
    {
        m_color = dlg.GetColor();
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Texture Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TexturePropDlg                                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

BEGIN_MESSAGE_MAP(TexturePropDlg, CDialog)
	//{{AFX_MSG_MAP(TexturePropDlg)
	ON_BN_CLICKED(IDC_TXTPRP_BROWSE, OnBrowse)
	ON_BN_CLICKED(IDC_TXTPRP_COLR, OnColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

TexturePropDlg::TexturePropDlg(TerrEditDoc *pd, int i, CWnd* pParent /*=NULL*/)
	: CDialog(TexturePropDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(TexturePropDlg)
	m_name = _T("");
	m_fname = _T("");
	//}}AFX_DATA_INIT

    pDoc = pd;
    iNDex = i;
    m_color = 0x808080;
    ASSERT(pDoc);
}

void TexturePropDlg::DoDataExchange(CDataExchange* pDX)
{
    int i;

	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TexturePropDlg)
	DDX_Text(pDX, IDC_TXPRP_NAME, m_name);
	DDV_MaxChars(pDX, m_name, 15);
	DDX_Text(pDX, IDC_TXTPRP_FILE, m_fname);
	DDV_MaxChars(pDX, m_fname, 255);
	//}}AFX_DATA_MAP

    if (pDX->m_bSaveAndValidate)
    {
        pDX->PrepareEditCtrl(IDC_TXPRP_NAME);
        if (!*m_name)
        {
            AfxMessageBox("Texture name must be given.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
        else
        {
            for(i=0; i < pDoc->txtNumb; i++)
            {
                if (iNDex == i)
                    continue;

                if (!pDoc->txtName[i].CompareNoCase(m_name))
                {
                    AfxMessageBox("Texture name must be unique.",MB_OK | MB_ICONEXCLAMATION);
                    pDX->Fail();
                    break;
                }
            }
        }

        pDX->PrepareEditCtrl(IDC_TXTPRP_FILE);
        if (!*m_fname)
        {
            AfxMessageBox("Texture filename must be given.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
        else if (!xf_exist(m_fname))
        {
            AfxMessageBox("Texture file must exist.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        // Need to check bitmap file for proper size/load support!
    }
}

void TexturePropDlg::OnBrowse() 
{
    CFileDialog dlg(TRUE,
                    NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
                    "Bitmap files (*.bmp;*.cel;*.lbm;*.pcx;*.tga)|*.BMP;*.CEL;*.LBM;*.PCX;*.TGA|"
                    "Windows Bitmap files (*.bmp)|*.BMP|"
                    "Autodesk CEL files (*.cel)|*.CEL|"
                    "DPaint/EA LBM files (*.lbm)|*.LBM|"
                    "Zsoft PCX files (*.pcx)|*.PCX|"
                    "Targa files (*.tga)|*.TGA|"
                    "All files (*.*)|*.*||",
                    this);

    dlg.m_ofn.lpstrTitle = "Texture Bitmap File";

    if (dlg.DoModal() == IDOK)
    {
        // Need to check bitmap file for proper size/load support!

        HWND    hWndName = ::GetDlgItem(GetSafeHwnd(),IDC_TXPRP_NAME);
        char    txtName[32];

        ::GetWindowText(hWndName, txtName, sizeof(txtName));

        m_fname = dlg.GetPathName();
        UpdateData(FALSE);

        ::SetWindowText(hWndName, txtName);

    }
}

void TexturePropDlg::OnColor() 
{
    CColorDialog dlg(m_color, CC_RGBINIT | CC_FULLOPEN, this);
	
    if (dlg.DoModal() == IDOK)
    {
        m_color = dlg.GetColor();
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Progress Dialogs °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrCNmPrgDlg                                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

BEGIN_MESSAGE_MAP(TerrCNmPrgDlg, CDialog)
	//{{AFX_MSG_MAP(TerrCNmPrgDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


TerrCNmPrgDlg::TerrCNmPrgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(TerrCNmPrgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(TerrCNmPrgDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

    Create(TerrCNmPrgDlg::IDD);
}


void TerrCNmPrgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TerrCNmPrgDlg)
	DDX_Control(pDX, IDC_CNRML_PROG, m_pBar);
	//}}AFX_DATA_MAP
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrCScPrgDlg                                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

BEGIN_MESSAGE_MAP(TerrCScPrgDlg, CDialog)
	//{{AFX_MSG_MAP(TerrCScPrgDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


TerrCScPrgDlg::TerrCScPrgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(TerrCScPrgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(TerrCScPrgDlg)
	//}}AFX_DATA_INIT

    Create(TerrCScPrgDlg::IDD);
}


void TerrCScPrgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TerrCScPrgDlg)
	DDX_Control(pDX, IDC_CSURF_PROG, m_pBar);
	//}}AFX_DATA_MAP
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrSurfPrgDlg                                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

BEGIN_MESSAGE_MAP(TerrSurfPrgDlg, CDialog)
	//{{AFX_MSG_MAP(TerrSurfPrgDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

TerrSurfPrgDlg::TerrSurfPrgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(TerrSurfPrgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(TerrSurfPrgDlg)
	//}}AFX_DATA_INIT

    Create(TerrSurfPrgDlg::IDD);
}


void TerrSurfPrgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TerrSurfPrgDlg)
	DDX_Control(pDX, IDC_SSCAN_PROG, m_pBar);
	//}}AFX_DATA_MAP
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Status Dialogs °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrExpStatDlg                                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

BEGIN_MESSAGE_MAP(TerrExpStatDlg, CDialog)
	//{{AFX_MSG_MAP(TerrExpStatDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


TerrExpStatDlg::TerrExpStatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(TerrExpStatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(TerrExpStatDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

    sflags=0;
}


void TerrExpStatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TerrExpStatDlg)
	DDX_Control(pDX, IDC_EST_TXTS, m_txts);
	DDX_Control(pDX, IDC_EST_SURF, m_surf);
	DDX_Control(pDX, IDC_EST_NRML, m_nrml);
	DDX_Control(pDX, IDC_EST_HGTS, m_hgts);
	DDX_Control(pDX, IDC_EST_HDR, m_hdr);
	//}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        m_hdr.EnableWindow(sflags & EXPSTAT_HDR);
        m_hgts.EnableWindow(sflags & EXPSTAT_HGTS);
        m_nrml.EnableWindow(sflags & EXPSTAT_NRML);
        m_surf.EnableWindow(sflags & EXPSTAT_SURF);
        m_txts.EnableWindow(sflags & EXPSTAT_TXTS);
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°±² eof - eshtdlg.cpp ²±°
