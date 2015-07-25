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
#include "eshtusgs.h"

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

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°° Terrain Properies Dialog °°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrPropGenPage                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(TerrPropGenPage, CPropertyPage)

BEGIN_MESSAGE_MAP(TerrPropGenPage, CPropertyPage)
    //{{AFX_MSG_MAP(TerrPropGenPage)
    ON_BN_CLICKED(IDC_TPROP_AUTOORG, OnAutoCenter)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

TerrPropGenPage::TerrPropGenPage() : CPropertyPage(TerrPropGenPage::IDD),
    m_edit(1)
{
    //{{AFX_DATA_INIT(TerrPropGenPage)
    m_width = 0;
    m_depth = 0;
    m_name = _T("");
    m_scale = 0;
    m_orgx = 0.0f;
    m_orgy = 0.0f;
    m_orgz = 0.0f;
    m_autoCenterOrg = FALSE;
	//}}AFX_DATA_INIT
}

TerrPropGenPage::~TerrPropGenPage()
{
}

void TerrPropGenPage::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(TerrPropGenPage)
    DDX_Control(pDX, IDC_TPROP_AUTOORG, m_autoCenterCtl);
    DDX_Control(pDX, IDC_TPROP_ORGZ, m_orgzCtl);
    DDX_Control(pDX, IDC_TPROP_ORGY, m_orgyCtl);
    DDX_Control(pDX, IDC_TPROP_ORGX, m_orgxCtl);
    DDX_Control(pDX, IDC_TPROP_SURFRATIO, m_surfratioCtl);
    DDX_Control(pDX, IDC_TPROP_DEPTH, m_depthCtl);
    DDX_Control(pDX, IDC_TPROP_WIDTH, m_widthCtl);
    DDX_Text(pDX, IDC_TPROP_WIDTH, m_width);
    DDV_MinMaxUInt(pDX, m_width, 0, 32768);
    DDX_Text(pDX, IDC_TPROP_DEPTH, m_depth);
    DDV_MinMaxUInt(pDX, m_depth, 0, 32768);
    DDX_Text(pDX, IDC_TPROP_NAME, m_name);
    DDV_MaxChars(pDX, m_name, 15);
    DDX_Text(pDX, IDC_TPROP_SCALE, m_scale);
    DDV_MinMaxUInt(pDX, m_scale, 1, 65536);
    DDX_Text(pDX, IDC_TPROP_ORGX, m_orgx);
    DDV_MinMaxFloat(pDX, m_orgx, -32768.f, 32768.f);
    DDX_Text(pDX, IDC_TPROP_ORGY, m_orgy);
    DDV_MinMaxFloat(pDX, m_orgy, -32768.f, 32768.f);
    DDX_Text(pDX, IDC_TPROP_ORGZ, m_orgz);
    DDV_MinMaxFloat(pDX, m_orgz, -32768.f, 32768.f);
    DDX_Check(pDX, IDC_TPROP_AUTOORG, m_autoCenterOrg);
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

        m_orgxCtl.EnableWindow(!m_autoCenterOrg);
        m_orgyCtl.EnableWindow(!m_autoCenterOrg);
        m_orgzCtl.EnableWindow(!m_autoCenterOrg);
    }
    else
    {
        pDX->PrepareEditCtrl(IDC_TPROP_NAME);
        if (!*m_name)
        {
            AfxMessageBox("Name must be given",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
        m_name.TrimRight();

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

        pDX->PrepareEditCtrl(IDC_TPROP_WIDTH);
        if (m_width & 0x1)
        {
            AfxMessageBox("Please enter an even number.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
        if ((m_width % m_surfratio) != 0)
        {
            AfxMessageBox("Must be a multiple of the surface ratio.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        pDX->PrepareEditCtrl(IDC_TPROP_DEPTH);
        if (m_depth & 0x1)
        {
            AfxMessageBox("Please enter an even number.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
        if ((m_depth % m_surfratio) != 0)
        {
            AfxMessageBox("Must be a multiple of the surface ratio.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        pDX->PrepareEditCtrl(IDC_TPROP_SCALE);

        UINT msk=0x1;
        for(int i=0; i < 16; i++, msk <<= 1)
        {
            if (m_scale == msk)
                break;
        }
        if (m_scale != msk)
        {
            AfxMessageBox("Width/Depth scale must be a power of 2",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
    }
}

void TerrPropGenPage::OnAutoCenter() 
{
    int state=m_autoCenterCtl.GetCheck();

    m_orgxCtl.EnableWindow(!state);
    m_orgyCtl.EnableWindow(!state);
    m_orgzCtl.EnableWindow(!state);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrPropHColrPage                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(TerrPropHColrPage, CPropertyPage)

BEGIN_MESSAGE_MAP(TerrPropHColrPage, CPropertyPage)
    //{{AFX_MSG_MAP(TerrPropHColrPage)
            // NOTE: the ClassWizard will add message map macros here
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

TerrPropHColrPage::TerrPropHColrPage() : CPropertyPage(TerrPropHColrPage::IDD)
{
    //{{AFX_DATA_INIT(TerrPropHColrPage)
    m_blue = 0;
    m_brown = 0;
    m_green = 0;
    m_lblue = 0;
    m_lbrown = 0;
    m_lgreen = 0;
    m_lorange = 0;
    m_orange = 0;
    m_red = 0;
    m_white = 0;
    m_yellow = 0;
    //}}AFX_DATA_INIT
}

TerrPropHColrPage::~TerrPropHColrPage()
{
}

void TerrPropHColrPage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(TerrPropHColrPage)
    DDX_Text(pDX, IDC_TPROP_BLUE, m_blue);
    DDV_MinMaxUInt(pDX, m_blue, 0, 32768);
    DDX_Text(pDX, IDC_TPROP_BROWN, m_brown);
    DDV_MinMaxUInt(pDX, m_brown, 0, 32768);
    DDX_Text(pDX, IDC_TPROP_GREEN, m_green);
    DDV_MinMaxUInt(pDX, m_green, 0, 32768);
    DDX_Text(pDX, IDC_TPROP_LBLUE, m_lblue);
    DDV_MinMaxUInt(pDX, m_lblue, 0, 32768);
    DDX_Text(pDX, IDC_TPROP_LBROWN, m_lbrown);
    DDV_MinMaxUInt(pDX, m_lbrown, 0, 32768);
    DDX_Text(pDX, IDC_TPROP_LGREEN, m_lgreen);
    DDV_MinMaxUInt(pDX, m_lgreen, 0, 32768);
    DDX_Text(pDX, IDC_TPROP_LORANGE, m_lorange);
    DDV_MinMaxUInt(pDX, m_lorange, 0, 32768);
    DDX_Text(pDX, IDC_TPROP_ORANGE, m_orange);
    DDV_MinMaxUInt(pDX, m_orange, 0, 32768);
    DDX_Text(pDX, IDC_TPROP_RED, m_red);
    DDV_MinMaxUInt(pDX, m_red, 0, 32768);
    DDX_Text(pDX, IDC_TPROP_WHITE, m_white);
    DDV_MinMaxUInt(pDX, m_white, 0, 32768);
    DDX_Text(pDX, IDC_TPROP_YELLOW, m_yellow);
    DDV_MinMaxUInt(pDX, m_yellow, 0, 32768);
    //}}AFX_DATA_MAP

    if (pDX->m_bSaveAndValidate)
    {
        pDX->PrepareEditCtrl(IDC_TPROP_LBLUE);
        if (m_lblue < m_blue)
        {
            AfxMessageBox("Value must be greater than or equal to previous",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        pDX->PrepareEditCtrl(IDC_TPROP_WHITE);
        if (m_white < m_lblue)
        {
            AfxMessageBox("Value must be greater than or equal to previous",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        pDX->PrepareEditCtrl(IDC_TPROP_GREEN);
        if (m_green < m_white)
        {
            AfxMessageBox("Value must be greater than or equal to previous",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        pDX->PrepareEditCtrl(IDC_TPROP_LGREEN);
        if (m_lgreen < m_green)
        {
            AfxMessageBox("Value must be greater than or equal to previous",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        pDX->PrepareEditCtrl(IDC_TPROP_YELLOW);
        if (m_yellow < m_lgreen)
        {
            AfxMessageBox("Value must be greater than or equal to previous",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        pDX->PrepareEditCtrl(IDC_TPROP_LORANGE);
        if (m_lorange < m_yellow)
        {
            AfxMessageBox("Value must be greater than or equal to previous",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        pDX->PrepareEditCtrl(IDC_TPROP_ORANGE);
        if (m_orange < m_lorange)
        {
            AfxMessageBox("Value must be greater than or equal to previous",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        pDX->PrepareEditCtrl(IDC_TPROP_LBROWN);
        if (m_lbrown < m_orange)
        {
            AfxMessageBox("Value must be greater than or equal to previous",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        pDX->PrepareEditCtrl(IDC_TPROP_BROWN);
        if (m_brown < m_lbrown)
        {
            AfxMessageBox("Value must be greater than or equal to previous",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        pDX->PrepareEditCtrl(IDC_TPROP_RED);
        if (m_red < m_brown)
        {
            AfxMessageBox("Value must be greater than or equal to previous",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrPropHTablePage                                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(TerrPropHTablePage, CPropertyPage)

BEGIN_MESSAGE_MAP(TerrPropHTablePage, CPropertyPage)
	//{{AFX_MSG_MAP(TerrPropHTablePage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

TerrPropHTablePage::TerrPropHTablePage() : CPropertyPage(TerrPropHTablePage::IDD)
{
	//{{AFX_DATA_INIT(TerrPropHTablePage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

    for(long i=0; i < 256; i++)
        htable[i] = 0;
}

TerrPropHTablePage::~TerrPropHTablePage()
{
}

void TerrPropHTablePage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TerrPropHTablePage)
	DDX_Control(pDX, IDC_TROP_HGTS, m_list);
	//}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        char   buff[32];

        m_list.ResetContent();
        for(long i=0; i < 256; i++)
        {
            sprintf(buff,"[%d]  %6.2f",i,(float)htable[i]);
            m_list.AddString(buff);
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrPropMiscPage                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(TerrPropMiscPage, CPropertyPage)

BEGIN_MESSAGE_MAP(TerrPropMiscPage, CPropertyPage)
    //{{AFX_MSG_MAP(TerrPropMiscPage)
            // NOTE: the ClassWizard will add message map macros here
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

TerrPropMiscPage::TerrPropMiscPage() : CPropertyPage(TerrPropMiscPage::IDD)
{
    //{{AFX_DATA_INIT(TerrPropMiscPage)
    m_copy = _T("");
    m_auth = _T("");
    m_desc = _T("");
    //}}AFX_DATA_INIT
}

TerrPropMiscPage::~TerrPropMiscPage()
{
}

void TerrPropMiscPage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(TerrPropMiscPage)
    DDX_Text(pDX, IDC_TPROP_COPY, m_copy);
    DDV_MaxChars(pDX, m_copy, 255);
    DDX_Text(pDX, IDC_TPROP_AUTH, m_auth);
    DDV_MaxChars(pDX, m_auth, 255);
    DDX_Text(pDX, IDC_TPROP_DESC, m_desc);
    DDV_MaxChars(pDX, m_desc, 255);
    //}}AFX_DATA_MAP

    if (pDX->m_bSaveAndValidate)
    {
        m_copy.TrimRight();
        m_auth.TrimRight();
        m_desc.TrimRight();
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Light Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// LightPropGenPage                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(LightPropGenPage, CPropertyPage)

BEGIN_MESSAGE_MAP(LightPropGenPage, CPropertyPage)
    //{{AFX_MSG_MAP(LightPropGenPage)
            // NOTE: the ClassWizard will add message map macros here
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

LightPropGenPage::LightPropGenPage() : CPropertyPage(LightPropGenPage::IDD),
    m_type(0)
{
    //{{AFX_DATA_INIT(LightPropGenPage)
    m_atten = FALSE;
    m_xiValue = 0.0f;
    m_yjValue = 0.0f;
    m_zkValue = 0.0f;
    //}}AFX_DATA_INIT
}

LightPropGenPage::~LightPropGenPage()
{
}

void LightPropGenPage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(LightPropGenPage)
    DDX_Control(pDX, IDC_LPROP_TYPE, m_typeList);
    DDX_Control(pDX, IDC_LPROP_INTENSITY, m_iSlider);
    DDX_Check(pDX, IDC_LPROP_ATTEN, m_atten);
    DDX_Text(pDX, IDC_LPROP_XI, m_xiValue);
    DDV_MinMaxFloat(pDX, m_xiValue, -32768.f, 32768.f);
    DDX_Text(pDX, IDC_LPROP_YJ, m_yjValue);
    DDV_MinMaxFloat(pDX, m_yjValue, -32768.f, 32768.f);
    DDX_Text(pDX, IDC_LPROP_ZK, m_zkValue);
    DDV_MinMaxFloat(pDX, m_zkValue, -32768.f, 32768.f);
    //}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        m_typeList.SetCurSel(m_type);
        m_iSlider.SetRange(0,255);
        m_iSlider.SetPos(m_intensity);
    }
    else
    {
        m_intensity = (byte)m_iSlider.GetPos();
        m_type = m_typeList.GetCurSel();
    }
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
    m_hotspot = 0.0f;
    m_diri = 0.0f;
    m_dirj = 0.0f;
    m_dirk = 0.0f;
    m_falloff = 0.0f;
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
    DDV_MinMaxFloat(pDX, m_inner, 0.f, 32768.f);
    DDX_Text(pDX, IDC_LPROP_OUTER, m_outer);
    DDV_MinMaxFloat(pDX, m_outer, 0.f, 32768.f);
    DDX_Text(pDX, IDC_LPROP_HOTSPOT, m_hotspot);
    DDV_MinMaxFloat(pDX, m_hotspot, 0.f, 175.f);
    DDX_Text(pDX, IDC_LPROP_XI, m_diri);
    DDV_MinMaxFloat(pDX, m_diri, -32768.f, 32768.f);
    DDX_Text(pDX, IDC_LPROP_YJ, m_dirj);
    DDV_MinMaxFloat(pDX, m_dirj, -32768.f, 32768.f);
    DDX_Text(pDX, IDC_LPROP_ZK, m_dirk);
    DDV_MinMaxFloat(pDX, m_dirk, -32768.f, 32768.f);
    DDX_Text(pDX, IDC_LPROP_FALLOFF, m_falloff);
    DDV_MinMaxFloat(pDX, m_falloff, 0.f, 175.f);
    //}}AFX_DATA_MAP
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Camera Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// CameraPropGenPage                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(CameraPropGenPage, CPropertyPage)

BEGIN_MESSAGE_MAP(CameraPropGenPage, CPropertyPage)
    //{{AFX_MSG_MAP(CameraPropGenPage)
            // NOTE: the ClassWizard will add message map macros here
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CameraPropGenPage::CameraPropGenPage() : CPropertyPage(CameraPropGenPage::IDD)
{
    //{{AFX_DATA_INIT(CameraPropGenPage)
    m_fov = 0.0f;
    m_diri = 0.0f;
    m_topi = 0.0f;
    m_dirj = 0.0f;
    m_topj = 0.0f;
    m_dirk = 0.0f;
    m_topk = 0.0f;
    m_xpos = 0.0f;
    m_ypos = 0.0f;
    m_zpos = 0.0f;
    //}}AFX_DATA_INIT
}

CameraPropGenPage::~CameraPropGenPage()
{
}

void CameraPropGenPage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CameraPropGenPage)
    DDX_Text(pDX, IDC_CPROP_FOV, m_fov);
    DDV_MinMaxFloat(pDX, m_fov, 1.f, 127.f);
    DDX_Text(pDX, IDC_CPROP_IDIR, m_diri);
    DDV_MinMaxFloat(pDX, m_diri, -32768.f, 32768.f);
    DDX_Text(pDX, IDC_CPROP_ITOP, m_topi);
    DDV_MinMaxFloat(pDX, m_topi, -32768.f, 32768.f);
    DDX_Text(pDX, IDC_CPROP_JDIR, m_dirj);
    DDV_MinMaxFloat(pDX, m_dirj, -32768.f, 32768.f);
    DDX_Text(pDX, IDC_CPROP_JTOP, m_topj);
    DDV_MinMaxFloat(pDX, m_topj, -32768.f, 32768.f);
    DDX_Text(pDX, IDC_CPROP_KDIR, m_dirk);
    DDV_MinMaxFloat(pDX, m_dirk, -32768.f, 32768.f);
    DDX_Text(pDX, IDC_CPROP_KTOP, m_topk);
    DDV_MinMaxFloat(pDX, m_topk, -32768.f, 32768.f);
    DDX_Text(pDX, IDC_CPROP_XPOS, m_xpos);
    DDV_MinMaxFloat(pDX, m_xpos, -32768.f, 32768.f);
    DDX_Text(pDX, IDC_CPROP_YPOS, m_ypos);
    DDV_MinMaxFloat(pDX, m_ypos, -32768.f, 32768.f);
    DDX_Text(pDX, IDC_CPROP_ZPOS, m_zpos);
    DDV_MinMaxFloat(pDX, m_zpos, -32768.f, 32768.f);
    //}}AFX_DATA_MAP
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// CameraPropLODPage                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(CameraPropLODPage, CPropertyPage)

BEGIN_MESSAGE_MAP(CameraPropLODPage, CPropertyPage)
    //{{AFX_MSG_MAP(CameraPropLODPage)
    ON_BN_CLICKED(IDC_LOD, OnLevelOfDetail)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CameraPropLODPage::CameraPropLODPage() : CPropertyPage(CameraPropLODPage::IDD)
{
    //{{AFX_DATA_INIT(CameraPropLODPage)
    m_low = 0.0f;
    m_med = 0.0f;
    m_lod = FALSE;
    //}}AFX_DATA_INIT
}

CameraPropLODPage::~CameraPropLODPage()
{
}

void CameraPropLODPage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CameraPropLODPage)
    DDX_Control(pDX, IDC_CPROP_MED, m_medCtl);
    DDX_Control(pDX, IDC_CPROP_LOW, m_lowCtl);
    DDX_Text(pDX, IDC_CPROP_LOW, m_low);
    DDV_MinMaxFloat(pDX, m_low, 0.f, 32768.f);
    DDX_Text(pDX, IDC_CPROP_MED, m_med);
    DDV_MinMaxFloat(pDX, m_med, 0.f, 32768.f);
    DDX_Check(pDX, IDC_LOD, m_lod);
    //}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        m_medCtl.EnableWindow(m_lod);
        m_lowCtl.EnableWindow(m_lod);
    }
    else
    {
        pDX->PrepareEditCtrl(IDC_CPROP_LOW);
        if (m_low < m_med)
        {
            AfxMessageBox("The low detail value should be greater than the medium value",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
    }
}

void CameraPropLODPage::OnLevelOfDetail() 
{
    m_lod = !m_lod;
    m_medCtl.EnableWindow(m_lod);
    m_lowCtl.EnableWindow(m_lod);
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

CameraPropMiscPage::CameraPropMiscPage() : CPropertyPage(CameraPropMiscPage::IDD),
    pDoc(0)
{
    //{{AFX_DATA_INIT(CameraPropMiscPage)
    m_hither = 0.0f;
    m_yon = 0.0f;
    m_scalef = 0.0f;
    m_hover = 0.0f;
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
    DDV_MinMaxFloat(pDX, m_hither, 1.f, 32768.f);
    DDX_Text(pDX, IDC_CPROP_YON, m_yon);
    DDV_MinMaxFloat(pDX, m_yon, 1.f, 32768.f);
    DDX_Text(pDX, IDC_CPROP_SCALEF, m_scalef);
    DDV_MinMaxFloat(pDX, m_scalef, 0.f, 32768.f);
    DDX_Text(pDX, IDC_CPROP_HOVER, m_hover);
    DDV_MinMaxFloat(pDX, m_hover, 0.f, 16384.f);
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
    ASSERT(pDoc);

    ColorSelectPropPage dlg;

    dlg.palette = &pDoc->palette;
    dlg.color = pDoc->palette.get_index(m_bcolor);

    CPropertySheet sh("Color Select");

    sh.AddPage(&dlg);       // Select Color

    if (sh.DoModal() == IDOK)
    {
        VngoColor24bit tclr = dlg.palette->get_RGB(dlg.color);
        m_bcolor = ((dword)tclr.b << 16) | ((dword)tclr.g << 8) | (dword)tclr.r;
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

void CameraPropExPage::setup(TerrEditDoc *pd)
{
    pDoc = pd;
    ASSERT(pDoc);
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
    ASSERT(pDoc);

    ColorSelectPropPage dlg;

    dlg.palette = &pDoc->palette;
    dlg.color = pDoc->palette.get_index(haze_color);

    CPropertySheet sh("Color Select");

    sh.AddPage(&dlg);       // Select Color

    if (sh.DoModal() == IDOK)
    {
        VngoColor24bit tclr = dlg.palette->get_RGB(dlg.color);
        haze_color = ((dword)tclr.b << 16) | ((dword)tclr.g << 8) | (dword)tclr.r;
        m_haze_activeCtl.SetCheck(1);
        haze_change=TRUE;
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Surface Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// SurfPropGenPage                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(SurfPropGenPage, CPropertyPage)

BEGIN_MESSAGE_MAP(SurfPropGenPage, CPropertyPage)
    //{{AFX_MSG_MAP(SurfPropGenPage)
    ON_BN_CLICKED(IDC_SPROP_COLR, OnColor)
    ON_CBN_SELCHANGE(IDC_SPROP_TXT, OnTextureSelectChange)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

SurfPropGenPage::SurfPropGenPage()
    : CPropertyPage(SurfPropGenPage::IDD),
    pDoc(0),
    m_txt(0)
{
    //{{AFX_DATA_INIT(SurfPropGenPage)
    m_cbit4 = FALSE;
    m_dloc = 0;
    m_xloc = 0;
    m_flipu = FALSE;
    m_flipv = FALSE;
    m_indistxt = FALSE;
	m_cbit11 = FALSE;
	m_cbit12 = FALSE;
	m_hidden = FALSE;
	m_highonly = FALSE;
	m_notile = FALSE;
	m_app0 = FALSE;
	m_app1 = FALSE;
	m_app2 = FALSE;
	m_app3 = FALSE;
	//}}AFX_DATA_INIT
}

SurfPropGenPage::~SurfPropGenPage()
{
}

void SurfPropGenPage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(SurfPropGenPage)
	DDX_Control(pDX, IDC_SPROP_NOTILE, m_notileCtl);
    DDX_Control(pDX, IDC_SPROP_TILE, m_tileCtl);
    DDX_Control(pDX, IDC_SPROP_TXT, m_txtList);
    DDX_Control(pDX, IDC_SPROP_COLR, m_colorbutton);
    DDX_Control(pDX, IDC_SPROP_FLIPV, m_flipvCtl);
    DDX_Control(pDX, IDC_SPROP_FLIPU, m_flipuCtl);
    DDX_Check(pDX, IDC_SPROP_CBIT4, m_cbit4);
    DDX_Text(pDX, IDC_SPROP_DLOC, m_dloc);
    DDV_MinMaxUInt(pDX, m_dloc, 0, 65535);
    DDX_Text(pDX, IDC_SPROP_XLOC, m_xloc);
    DDV_MinMaxUInt(pDX, m_xloc, 0, 65535);
    DDX_Check(pDX, IDC_SPROP_FLIPU, m_flipu);
    DDX_Check(pDX, IDC_SPROP_FLIPV, m_flipv);
    DDX_Check(pDX, IDC_SPROP_INDISTXT, m_indistxt);
    DDX_CBIndex(pDX, IDC_SPROP_TILE, m_tile);
	DDX_Check(pDX, IDC_SPROP_CBIT11, m_cbit11);
	DDX_Check(pDX, IDC_SPROP_CBIT12, m_cbit12);
	DDX_Check(pDX, IDC_SPROP_HIDDEN, m_hidden);
	DDX_Check(pDX, IDC_SPROP_HIGHONLY, m_highonly);
	DDX_Check(pDX, IDC_SPROP_NOTILE, m_notile);
	DDX_Check(pDX, IDC_SPROP_APP0, m_app0);
	DDX_Check(pDX, IDC_SPROP_APP1, m_app1);
	DDX_Check(pDX, IDC_SPROP_APP2, m_app2);
	DDX_Check(pDX, IDC_SPROP_APP3, m_app3);
	//}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        m_colorbutton.EnableWindow(!m_indistxt);
        m_flipuCtl.EnableWindow(m_indistxt);
        m_flipvCtl.EnableWindow(m_indistxt);
        m_tileCtl.EnableWindow(m_indistxt);
        m_notileCtl.EnableWindow(m_indistxt);

        m_txtList.ResetContent();
        m_txtList.AddString("None");
        assert(pDoc != NULL);
        for(int i=0; i < pDoc->txtNumb; i++)
        {
            m_txtList.AddString(pDoc->txtName[i]);
        }
        m_txtList.SetCurSel(m_txt);
    }
    else
    {
        m_txt = m_txtList.GetCurSel();
    }
}

void SurfPropGenPage::OnTextureSelectChange() 
{
    int i = m_txtList.GetCurSel();

    m_colorbutton.EnableWindow( (i) ? 0 : 1);
    m_flipuCtl.EnableWindow( (i) ? 1 : 0);
    m_flipvCtl.EnableWindow( (i) ? 1 : 0);
    m_tileCtl.EnableWindow( (i) ? 1 : 0);
    m_notileCtl.EnableWindow( (i) ? 1 : 0);

    HWND    hwnd;

    hwnd = ::GetDlgItem(GetSafeHwnd(),IDC_SPROP_INDISTXT);
    ::SendMessage(hwnd, BM_SETCHECK, ((i) ? 1 : 0), 0L);

    if (i)
    {
        assert(pDoc != NULL);

        hwnd = ::GetDlgItem(GetSafeHwnd(),IDC_SPROP_FLIPU);
        ::SendMessage(hwnd, BM_SETCHECK, ((pDoc->txtDFlags[i-1] & ESCH_SURF_FLIPU) ? 1 : 0), 0L);

        hwnd = ::GetDlgItem(GetSafeHwnd(),IDC_SPROP_FLIPV);
        ::SendMessage(hwnd, BM_SETCHECK, ((pDoc->txtDFlags[i-1] & ESCH_SURF_FLIPV) ? 1 : 0), 0L);

        assert(ESCH_SURF_TILE1 == 0x10 && ESCH_SURF_TILE2 == 0x20 && ESCH_SURF_TILE3 == 0x40);
        m_tileCtl.SetCurSel((pDoc->txtDFlags[i-1] >> 4) & 0x7);
    }
}

void SurfPropGenPage::OnColor() 
{
    ASSERT(pDoc);

    ColorSelectPropPage dlga;

    dlga.palette = &pDoc->palette;
    dlga.color = pDoc->palette.get_index(m_color);

    ShadeReviewPropPage dlgb;
    dlgb.palette = dlga.palette;
    dlgb.color = dlga.color;

    dlga.setup(0,&dlgb);

    CPropertySheet sh("Color Select");

    sh.AddPage(&dlga);      // Select Color
    sh.AddPage(&dlgb);      // Shade Review

    if (sh.DoModal() == IDOK)
    {
        VngoColor24bit tclr = dlga.palette->get_RGB(dlga.color);
        m_color = ((dword)tclr.b << 16) | ((dword)tclr.g << 8) | (dword)tclr.r;
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°° Color Properties Dialog °°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ColorGenPropPage                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(ColorGenPropPage, CPropertyPage)

BEGIN_MESSAGE_MAP(ColorGenPropPage, CPropertyPage)
    //{{AFX_MSG_MAP(ColorGenPropPage)
	ON_BN_CLICKED(IDC_CLRPRP_RESETUSAGE, OnResetUsage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

ColorGenPropPage::ColorGenPropPage() : CPropertyPage(ColorGenPropPage::IDD),
    m_isnew(0),
    colorIndx(-1)
{
    //{{AFX_DATA_INIT(ColorGenPropPage)
    m_name = _T("");
	m_app0 = FALSE;
	m_app1 = FALSE;
	m_app2 = FALSE;
	m_app3 = FALSE;
	m_highonly = FALSE;
	//}}AFX_DATA_INIT
}

ColorGenPropPage::~ColorGenPropPage()
{
}

void ColorGenPropPage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(ColorGenPropPage)
	DDX_Control(pDX, IDC_CLRPRP_RESETUSAGE, m_resetCtl);
    DDX_Text(pDX, IDC_CLRPRP_NAME, m_name);
    DDV_MaxChars(pDX, m_name, 16);
	DDX_Check(pDX, IDC_CLRPRP_APP0, m_app0);
	DDX_Check(pDX, IDC_CLRPRP_APP1, m_app1);
	DDX_Check(pDX, IDC_CLRPRP_APP2, m_app2);
	DDX_Check(pDX, IDC_CLRPRP_APP3, m_app3);
	DDX_Check(pDX, IDC_CLRPRP_HIGHONLY, m_highonly);
	//}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        m_resetCtl.EnableWindow((m_isnew) ? 0 : 1);
    }
}

void ColorGenPropPage::OnResetUsage() 
{
    if (!UpdateData(TRUE))
        return;

    if (MessageBox("This will scan the surface information data and reset\n"
                   "the flags to the current settings on this\n"
                   "sheet for any surface point using this color.\n\n"
                   "Are you sure you wish to proceed?",
                   "Texture Properities",
                   MB_YESNO) != IDYES)
        return;

    assert(pDoc != NULL && pDoc->surfinfo != NULL);

    BOOL changed=FALSE;

    esch_surf_type *surf = pDoc->surfinfo;
    for(long d=0; d < (pDoc->depth >> pDoc->surfshift); d++)
    {
        for( long w=0; w < (pDoc->width >> pDoc->surfshift); w++)
        {
            if (!(surf->flags & ESCH_SURF_CINDISTXT) && surf->cind == colorIndx)
            {
                if (!changed)
                {
                    pDoc->SetModifiedFlag();
                    changed=TRUE;
                }

                assert(ESCH_SURF_TILE1 == 0x10 && ESCH_SURF_TILE2 == 0x20 && ESCH_SURF_TILE3 == 0x40);

                ushort flags = surf->flags;

                flags &= ~(ESCH_SURF_FLIPU
                           | ESCH_SURF_FLIPV
                           | ESCH_SURF_TILE1
                           | ESCH_SURF_TILE2
                           | ESCH_SURF_TILE3
                           | ESCH_SURF_NOTILE
                           | ESCH_SURF_HIGHONLY
                           | ESCH_SURF_APP0
                           | ESCH_SURF_APP1
                           | ESCH_SURF_APP2
                           | ESCH_SURF_APP3);

                flags |= ((m_highonly) ? ESCH_SURF_HIGHONLY : 0)
                         | ((m_app0) ? ESCH_SURF_APP0 : 0)
                         | ((m_app1) ? ESCH_SURF_APP1 : 0)
                         | ((m_app2) ? ESCH_SURF_APP2 : 0)
                         | ((m_app3) ? ESCH_SURF_APP3 : 0);

                surf->flags = flags;
            }
            surf++;
        }
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°° Color Select Dialog °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ColorSelectPropPage                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(ColorSelectPropPage, CPropertyPage)

BEGIN_MESSAGE_MAP(ColorSelectPropPage, CPropertyPage)
    //{{AFX_MSG_MAP(ColorSelectPropPage)
    ON_WM_PAINT()
    ON_WM_LBUTTONDOWN()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

ColorSelectPropPage::ColorSelectPropPage() : 
    CPropertyPage(ColorSelectPropPage::IDD),
    palette(0),
    color(0),
    hpal(0),
    bmi(0),
    gmap(0),
    gvport(0),
    wid(0),
    hgt(0),
    x_spacing(0),
    y_spacing(0),
    pCGPage(0),
    pSRPage(0)
{
    //{{AFX_DATA_INIT(ColorSelectPropPage)
            // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
}

ColorSelectPropPage::~ColorSelectPropPage()
{
    release_vport();

    if (hpal)
    {
        DeleteObject(hpal);
        hpal=0;
    }
}

void ColorSelectPropPage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(ColorSelectPropPage)
            // NOTE: the ClassWizard will add DDX and DDV calls here
    //}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        // Construct a Windows palette from Van Gogh palette
        LOGPALETTE *lpal = (LOGPALETTE *) ivory_alloc(sizeof(LOGPALETTE)
                                                    + 256*sizeof(PALETTEENTRY));

        ASSERT(lpal != 0);

        lpal->palVersion = 0x300;
        lpal->palNumEntries = 256;

        for (int i=0; i < 256; i++)
        {
            lpal->palPalEntry[i].peRed  = palette->hw_pal.p[i].r;
            lpal->palPalEntry[i].peGreen= palette->hw_pal.p[i].g;
            lpal->palPalEntry[i].peBlue = palette->hw_pal.p[i].b;
            lpal->palPalEntry[i].peFlags= PC_NOCOLLAPSE;
        }

        if (hpal)
        {
            DeleteObject(hpal);
        }

        hpal = CreatePalette(lpal);

        ivory_free( (void**)&lpal );
    }
}

void ColorSelectPropPage::setup_vport(int width, int height)
{
    release_vport();

    if (!width || !height)
        return;

    bmi = (LPBITMAPINFO) ivory_alloc (sizeof(BITMAPINFOHEADER) + 256*sizeof(WORD));
    ASSERT(bmi != 0);

    memset(bmi, 0, sizeof(*bmi));
    bmi->bmiHeader.biSize         = sizeof (BITMAPINFOHEADER);
    bmi->bmiHeader.biWidth        = width;
    bmi->bmiHeader.biHeight       = -height;
    bmi->bmiHeader.biPlanes       = 1;
    bmi->bmiHeader.biBitCount     = 8;
    bmi->bmiHeader.biCompression  = BI_RGB;
    bmi->bmiHeader.biClrUsed      = 256;
    bmi->bmiHeader.biClrImportant = 256;

    gmap = new BYTE [((width+3) & ~0x3)*height];
    ASSERT(gmap != 0);

    for(int i=0; i < 256; i++)
    {
        ((WORD *)bmi->bmiColors)[i] = (WORD)i;
    }

    gvport = new VngoVportDB8 (((width+3) & ~0x3), height, 
                               gmap, NULL, palette, 0);
    ASSERT(gvport != 0);
}

void ColorSelectPropPage::release_vport()
{
    if (bmi)
    {
        ivory_free((void**)&bmi);
    }
    if (gmap)
    {
        delete [] gmap;
        gmap = 0;
    }
    if (gvport)
    {
        delete gvport;
        gvport = 0;
    }
}

void ColorSelectPropPage::OnPaint() 
{
    CPaintDC dc(this); // device context for painting

    ASSERT(gvport != 0 && gmap != 0);

    if (hpal)
    {
        SelectPalette(dc.m_hDC,hpal,0);
        dc.RealizePalette();
    }

    gvport->lock();

    VngoRect bg(0,0,wid,hgt);
    gvport->frect(&bg,palette->get_index(VngoColor24bit(192,192,192)));
    VngoRect vrc(0,0,x_spacing,y_spacing);

    int clr = 0;
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            vrc.x = j*x_spacing;
            vrc.y = i*y_spacing;
            gvport->frect(&vrc, clr);
            clr++;
        }
    }

    // Draw the currently selected color!
    gvport->frect(&sel_rect, color);

    gvport->unlock();

    SetDIBitsToDevice (dc.m_hDC, 0, 0, ((wid+3) & ~0x3), hgt,
                                        0, 0, 0, hgt,
                                        gmap, bmi, DIB_PAL_COLORS);
}

void ColorSelectPropPage::OnLButtonDown(UINT nFlags, CPoint point) 
{
    int x = point.x;
    int y = point.y;

    if (x > (wid-50) || (y>hgt) || (y<0) || (x<0) )   
        return;

    int x_index = x / x_spacing;
    int y_index = y / y_spacing;

    color = y_index*16 + x_index;

    RedrawWindow();

    if (pCGPage)
        pCGPage->colorIndx = color;
    if (pSRPage)
        pSRPage->color = color;

    CPropertyPage::OnLButtonDown(nFlags, point);
}

void ColorSelectPropPage::OnSize(UINT nType, int cx, int cy) 
{
	CPropertyPage::OnSize(nType, cx, cy);

    wid = cx;
    hgt = cy;

    x_spacing = (wid - 50) / 16;
    y_spacing = hgt / 16;

    sel_rect.x = (wid - 50) + (x_spacing/2);
    sel_rect.y = (hgt/2) - (y_spacing/2);
    sel_rect.dx = x_spacing;
    sel_rect.dy = y_spacing;

    setup_vport(wid, hgt);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ShadeReviewPropPage                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(ShadeReviewPropPage, CPropertyPage)

BEGIN_MESSAGE_MAP(ShadeReviewPropPage, CPropertyPage)
	//{{AFX_MSG_MAP(ShadeReviewPropPage)
	ON_WM_PAINT()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

ShadeReviewPropPage::ShadeReviewPropPage() :
    CPropertyPage(ShadeReviewPropPage::IDD),
    palette(0),
    color(0),
    hpal(0),
    bmi(0),
    gmap(0),
    gvport(0),
    wid(0),
    hgt(0),
    x_spacing(0),
    y_spacing(0)
{
	//{{AFX_DATA_INIT(ShadeReviewPropPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

ShadeReviewPropPage::~ShadeReviewPropPage()
{
    release_vport();

    if (hpal)
    {
        DeleteObject(hpal);
        hpal=0;
    }
}

void ShadeReviewPropPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ShadeReviewPropPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        // Construct a Windows palette from Van Gogh palette
        LOGPALETTE *lpal = (LOGPALETTE *) ivory_alloc(sizeof(LOGPALETTE)
                                                    + 256*sizeof(PALETTEENTRY));

        ASSERT(lpal != 0);

        lpal->palVersion = 0x300;
        lpal->palNumEntries = 256;

        for (int i=0; i < 256; i++)
        {
            lpal->palPalEntry[i].peRed  = palette->hw_pal.p[i].r;
            lpal->palPalEntry[i].peGreen= palette->hw_pal.p[i].g;
            lpal->palPalEntry[i].peBlue = palette->hw_pal.p[i].b;
            lpal->palPalEntry[i].peFlags= PC_NOCOLLAPSE;
        }

        if (hpal)
        {
            DeleteObject(hpal);
        }

        hpal = CreatePalette(lpal);

        ivory_free( (void**)&lpal );
    }
}

void ShadeReviewPropPage::setup_vport(int width, int height)
{
    release_vport();

    if (!width || !height)
        return;

    bmi = (LPBITMAPINFO) ivory_alloc (sizeof(BITMAPINFOHEADER) + 256*sizeof(WORD));
    ASSERT(bmi != 0);

    memset(bmi, 0, sizeof(*bmi));
    bmi->bmiHeader.biSize         = sizeof (BITMAPINFOHEADER);
    bmi->bmiHeader.biWidth        = width;
    bmi->bmiHeader.biHeight       = -height;
    bmi->bmiHeader.biPlanes       = 1;
    bmi->bmiHeader.biBitCount     = 8;
    bmi->bmiHeader.biCompression  = BI_RGB;
    bmi->bmiHeader.biClrUsed      = 256;
    bmi->bmiHeader.biClrImportant = 256;

    gmap = new BYTE [((width+3) & ~0x3)*height];
    ASSERT(gmap != 0);

    for(int i=0; i < 256; i++)
    {
        ((WORD *)bmi->bmiColors)[i] = (WORD)i;
    }

    gvport = new VngoVportDB8 (((width+3) & ~0x3), height, 
                               gmap, NULL, palette, 0);
    ASSERT(gvport != 0);
}

void ShadeReviewPropPage::release_vport()
{
    if (bmi)
    {
        ivory_free((void**)&bmi);
    }
    if (gmap)
    {
        delete [] gmap;
        gmap = 0;
    }
    if (gvport)
    {
        delete gvport;
        gvport = 0;
    }
}

void ShadeReviewPropPage::OnPaint() 
{
    CPaintDC dc(this); // device context for painting

    ASSERT(gvport != 0 && gmap != 0);

    if (hpal)
    {
        SelectPalette(dc.m_hDC,hpal,0);
        dc.RealizePalette();
    }

    gvport->lock();

    VngoRect bg(0,0,wid,hgt);
    gvport->frect(&bg,palette->get_index(VngoColor24bit(192,192,192)));

    VngoShadePal8 *shade=(VngoShadePal8*)palette->shd_pal;

    VngoRect vrc(0,0,x_spacing,y_spacing);

    byte mp = (byte) ((shade->num_shd_lvl * (shade->mid_point-1)) / 256);

    for (int i = 0; i < shade->num_shd_lvl; i++)
    {
        if (i == mp)
            vrc.y += y_spacing;

        gvport->frect(&vrc,
                      shade->get_shaded_index(color,
                                              (byte)(i << (8-shade->num_shd_lvl_bits))));

        if (i == mp)
            vrc.y += y_spacing;

        vrc.y += y_spacing;
    }

    gvport->unlock();

    SetDIBitsToDevice (dc.m_hDC, 0, 0, ((wid+3) & ~0x3), hgt,
                                        0, 0, 0, hgt,
                                        gmap, bmi, DIB_PAL_COLORS);
}

void ShadeReviewPropPage::OnSize(UINT nType, int cx, int cy) 
{
	CPropertyPage::OnSize(nType, cx, cy);

    wid = cx;
    hgt = cy;

    x_spacing = cx;

    VngoShadePal8 *shade=(VngoShadePal8*)palette->shd_pal;
    y_spacing = hgt / (shade->num_shd_lvl+2);

    setup_vport(wid,hgt);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Progress Dialog °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// ProgressDlg                                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BEGIN_MESSAGE_MAP(ProgressDlg, CDialog)
        //{{AFX_MSG_MAP(ProgressDlg)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

ProgressDlg::ProgressDlg(CWnd* pParent /*=NULL*/)
        : CDialog(ProgressDlg::IDD, pParent)
{
        //{{AFX_DATA_INIT(ProgressDlg)
                // NOTE: the ClassWizard will add member initialization here
        //}}AFX_DATA_INIT

    Create(ProgressDlg::IDD);
    CenterWindow();
}

void ProgressDlg::DoDataExchange(CDataExchange* pDX)
{
        CDialog::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(ProgressDlg)
        DDX_Control(pDX, IDC_CSURF_PROG, m_pbar);
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
        : CDialog(TerrExpStatDlg::IDD, pParent),
    sflags(0)
{
        //{{AFX_DATA_INIT(TerrExpStatDlg)
                // NOTE: the ClassWizard will add member initialization here
        //}}AFX_DATA_INIT
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
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Import Dialogs °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// DemImportDlg                                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BEGIN_MESSAGE_MAP(DEMImportDlg, CDialog)
	//{{AFX_MSG_MAP(DEMImportDlg)
	ON_BN_CLICKED(IDC_DEM_AVERAGE, OnDemAverage)
	ON_BN_CLICKED(IDC_DEM_STD, OnDemStd)
	ON_BN_CLICKED(IDC_DEM_UNIFORM, OnDemUniform)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

DEMImportDlg::DEMImportDlg(CWnd* pParent /*=NULL*/)
	: CDialog(DEMImportDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(DEMImportDlg)
	m_avg_maxd = 0.0f;
	m_lat_degrees = 0;
	m_lat_minutes = 0;
	m_lat_seconds = 0;
	m_lng_degrees = 0;
	m_lng_minutes = 0;
	m_lng_seconds = 0;
	m_normalize = FALSE;
	//}}AFX_DATA_INIT

    option=0;
    m_avg_maxd=16.0f;
    m_normalize=TRUE;
    isusgs=FALSE;
    longitude=0;
    latitude=0;
}

void DEMImportDlg::DoDataExchange(CDataExchange* pDX)
{
    if (isusgs
        && !pDX->m_bSaveAndValidate)
    {
        long d, m, l;

        l=longitude;
        if (l < 0)
            l = -l;
        for(d=0; l >= 3600; d++, l -= 3600);
        for(m=0; l >= 60; m++, l -= 60);
        m_lng_degrees = d;
        m_lng_minutes = m;
        m_lng_seconds = l;

        l=latitude;
        if (l < 0)
            l = -l;
        for(d=0; l >= 3600; d++, l -= 3600);
        for(m=0; l >= 60; m++, l -= 60);
        m_lat_degrees = d;
        m_lat_minutes = m;
        m_lat_seconds = l;
    }

	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DEMImportDlg)
	DDX_Control(pDX, IDC_DEM_LNG_SECONDS, m_lng_secondsCtl);
	DDX_Control(pDX, IDC_DEM_LNG_MINUTES, m_lng_minutesCtl);
	DDX_Control(pDX, IDC_DEM_LNG_DEGREES, m_lng_degreesCtl);
	DDX_Control(pDX, IDC_DEM_LAT_SECONDS, m_lat_secondsCtl);
	DDX_Control(pDX, IDC_DEM_LAT_MINUTES, m_lat_minutesCtl);
	DDX_Control(pDX, IDC_DEM_LAT_DEGREES, m_lat_degreesCtl);
    DDX_Control(pDX, IDC_DEM_STD, m_stdCtl);
    DDX_Control(pDX, IDC_DEM_UNIFORM, m_uniformCtl);
    DDX_Control(pDX, IDC_DEM_AVERAGE, m_avgCtl);
	DDX_Control(pDX, IDC_DEM_AVGMAXD, m_avg_maxdCtl);
	DDX_Text(pDX, IDC_DEM_AVGMAXD, m_avg_maxd);
	DDV_MinMaxFloat(pDX, m_avg_maxd, 1.f, 32768.f);
	DDX_Text(pDX, IDC_DEM_LAT_DEGREES, m_lat_degrees);
	DDV_MinMaxUInt(pDX, m_lat_degrees, 0, 90);
	DDX_Text(pDX, IDC_DEM_LAT_MINUTES, m_lat_minutes);
	DDV_MinMaxUInt(pDX, m_lat_minutes, 0, 59);
	DDX_Text(pDX, IDC_DEM_LAT_SECONDS, m_lat_seconds);
	DDV_MinMaxUInt(pDX, m_lat_seconds, 0, 59);
	DDX_Text(pDX, IDC_DEM_LNG_DEGREES, m_lng_degrees);
	DDV_MinMaxUInt(pDX, m_lng_degrees, 0, 180);
	DDX_Text(pDX, IDC_DEM_LNG_MINUTES, m_lng_minutes);
	DDV_MinMaxUInt(pDX, m_lng_minutes, 0, 59);
	DDX_Text(pDX, IDC_DEM_LNG_SECONDS, m_lng_seconds);
	DDV_MinMaxUInt(pDX, m_lng_seconds, 0, 59);
    DDX_Control(pDX, IDC_LNG_EAST, m_lng_east);
    DDX_Control(pDX, IDC_LNG_WEST, m_lng_west);
    DDX_Control(pDX, IDC_LAT_NORTH, m_lat_north);
    DDX_Control(pDX, IDC_LAT_SOUTH, m_lat_south);
	DDX_Check(pDX, IDC_DEM_NORMALIZE, m_normalize);
	//}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        CheckRadioButton(IDC_DEM_STD, IDC_DEM_AVERAGE, IDC_DEM_STD + option);
        m_avg_maxdCtl.EnableWindow((option == 2) ? TRUE : FALSE);

        m_lng_degreesCtl.EnableWindow(isusgs);
        m_lng_minutesCtl.EnableWindow(isusgs);
        m_lng_secondsCtl.EnableWindow(isusgs);
        m_lat_degreesCtl.EnableWindow(isusgs);
        m_lat_minutesCtl.EnableWindow(isusgs);
        m_lat_secondsCtl.EnableWindow(isusgs);
        m_lng_east.EnableWindow(isusgs);
        m_lng_west.EnableWindow(isusgs);
        m_lat_north.EnableWindow(isusgs);
        m_lat_south.EnableWindow(isusgs);

        CheckRadioButton(IDC_LNG_WEST, IDC_LNG_EAST, IDC_LNG_WEST + ((longitude <= 0) ? 0 : 1));
        CheckRadioButton(IDC_LAT_NORTH, IDC_LAT_SOUTH, IDC_LAT_NORTH + ((latitude < 0) ? 1 : 0));
    }
    else
    {
        switch (GetCheckedRadioButton(IDC_DEM_STD, IDC_DEM_AVERAGE))
        {
            case IDC_DEM_STD:       option = 0;  break;
            case IDC_DEM_UNIFORM:   option = 1;  break;
            case IDC_DEM_AVERAGE:   option = 2;  break;
        }

        if (isusgs)
        {
            longitude = m_lng_degrees*3600 + m_lng_minutes*60 + m_lng_seconds;
            if (GetCheckedRadioButton(IDC_LNG_WEST, IDC_LNG_EAST) == IDC_LNG_WEST)
                longitude = -longitude;

            latitude = m_lat_degrees*3600 + m_lat_minutes*60 + m_lat_seconds;
            if (GetCheckedRadioButton(IDC_LAT_NORTH, IDC_LAT_SOUTH) == IDC_LAT_SOUTH)
                latitude = -latitude;
        }
    }
}

void DEMImportDlg::OnDemStd() 
{
    int state=m_stdCtl.GetCheck();

    m_avg_maxdCtl.EnableWindow(!state);
}

void DEMImportDlg::OnDemUniform() 
{
    int state=m_uniformCtl.GetCheck();

    m_avg_maxdCtl.EnableWindow(!state);
}

void DEMImportDlg::OnDemAverage() 
{
    int state=m_avgCtl.GetCheck();

    m_avg_maxdCtl.EnableWindow(state);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// DEMProgressDlg                                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BEGIN_MESSAGE_MAP(DEMProgressDlg, CDialog)
	//{{AFX_MSG_MAP(DEMProgressDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

DEMProgressDlg::DEMProgressDlg(USGSFileParseDEM *d, CWnd* pParent /*=NULL*/)
	: CDialog(DEMProgressDlg::IDD, pParent),
    dem(d),
    okon(FALSE)
{
	//{{AFX_DATA_INIT(DEMProgressDlg)
	m_comments = _T("");
	m_elv_units = _T("");
	m_fname = _T("");
	m_grnd_units = _T("");
	m_name = _T("");
	m_profile_cols = 0;
	m_profile_rows = 0;
	m_quality = 0;
	m_status = _T("");
	m_axisx = 0.0f;
	m_axisy = 0.0f;
	m_axisz = 0.0f;
	//}}AFX_DATA_INIT

    ASSERT(dem);

    Create(DEMProgressDlg::IDD);
    CenterWindow();
}

void DEMProgressDlg::DoDataExchange(CDataExchange* pDX)
{
    if (!pDX->m_bSaveAndValidate)
    {
        m_quality = dem->level_code;

        switch (dem->ground_units)
        {
            case USGSFileParseDEM::UNITS_RADIANS:
                m_grnd_units = "Radians";  break;
            case USGSFileParseDEM::UNITS_FEET:
                m_grnd_units = "Feet";  break;
            case USGSFileParseDEM::UNITS_METERS:
                m_grnd_units = "Meters";  break;
            case USGSFileParseDEM::UNITS_ARCSECONDS:
                m_grnd_units = "Arc-seconds";  break;
        }

        switch (dem->elev_units)
        {
            case USGSFileParseDEM::UNITS_FEET:  m_elv_units = "Feet";  break;
            case USGSFileParseDEM::UNITS_METERS:  m_elv_units = "Meters";  break;
        }

        m_axisx = (float)dem->axis[0];
        m_axisy = (float)dem->axis[1];
        m_axisz = (float)dem->axis[2];

        m_profile_rows = dem->profile_rows;
        m_profile_cols = dem->profile_columns;

        m_name = dem->name;  m_name.TrimRight();  m_name.TrimLeft();
        m_comments = dem->comment;  m_comments.TrimRight();  m_comments.TrimLeft();
    }

	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DEMProgressDlg)
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Control(pDX, IDC_DPRG_BAR, m_pbar);
	DDX_Text(pDX, IDC_DPRG_COMMENT, m_comments);
	DDX_Text(pDX, IDC_DPRG_EUNITS, m_elv_units);
	DDX_Text(pDX, IDC_DPRG_FNAME, m_fname);
	DDX_Text(pDX, IDC_DPRG_GUNITS, m_grnd_units);
	DDX_Text(pDX, IDC_DPRG_NAME, m_name);
	DDX_Text(pDX, IDC_DPRG_PCOLS, m_profile_cols);
	DDX_Text(pDX, IDC_DPRG_PROWS, m_profile_rows);
	DDX_Text(pDX, IDC_DPRG_QUALITY, m_quality);
	DDX_Text(pDX, IDC_STATUS, m_status);
	DDX_Text(pDX, IDC_DPRG_AXISX, m_axisx);
	DDX_Text(pDX, IDC_DPRG_AXISY, m_axisy);
	DDX_Text(pDX, IDC_DPRG_AXISZ, m_axisz);
	//}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        m_ok.EnableWindow(okon);
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Misc Dialogs °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// LocateDlg                                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BEGIN_MESSAGE_MAP(LocateDlg, CDialog)
	//{{AFX_MSG_MAP(LocateDlg)
	ON_BN_CLICKED(IDC_LOCATE_BROWSE, OnBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

LocateDlg::LocateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(LocateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(LocateDlg)
	m_fname = _T("");
	//}}AFX_DATA_INIT

    typestr = _T("");
    title = _T("Locate File");
}

void LocateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LocateDlg)
	DDX_Text(pDX, IDC_LOCATE_FILE, m_fname);
	DDV_MaxChars(pDX, m_fname, 256);
	//}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        SetWindowText(title);
    }
    else
    {
        pDX->PrepareEditCtrl(IDC_LOCATE_FILE);
        if (!*m_fname)
        {
            AfxMessageBox("Filename must be given.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
        else if (!xf_exist(m_fname))
        {
            AfxMessageBox("File must exist.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
    }
}

void LocateDlg::OnBrowse() 
{
    CString str = typestr + "All files (*.*)|*.*||";

    CFileDialog dlg(TRUE,
                    NULL, m_fname, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
                    str,
                    this);

    dlg.m_ofn.lpstrTitle = title;

    if (dlg.DoModal() == IDOK)
    {
        m_fname = dlg.GetPathName();
        UpdateData(FALSE);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// SetBaseElvDlg                                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BEGIN_MESSAGE_MAP(SetBaseElvDlg, CDialog)
	//{{AFX_MSG_MAP(SetBaseElvDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

SetBaseElvDlg::SetBaseElvDlg(CWnd* pParent /*=NULL*/)
	: CDialog(SetBaseElvDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(SetBaseElvDlg)
	m_setbase_elv = 0.0f;
	m_elvmin = 0.0f;
	m_elvmax = 0.0f;
	//}}AFX_DATA_INIT
}

void SetBaseElvDlg::DoDataExchange(CDataExchange* pDX)
{
    if (!pDX->m_bSaveAndValidate)
    {
        m_setbase_elv = m_elvmin;
    }

	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SetBaseElvDlg)
	DDX_Text(pDX, IDC_SETBASE_ELV, m_setbase_elv);
	DDV_MinMaxFloat(pDX, m_setbase_elv, -32768.f, 32768.f);
	DDX_Text(pDX, IDC_SETBASE_MIN, m_elvmin);
	DDX_Text(pDX, IDC_SETBASE_MAX, m_elvmax);
	//}}AFX_DATA_MAP

    if (pDX->m_bSaveAndValidate)
    {
        pDX->PrepareEditCtrl(IDC_SETBASE_ELV);

        float f = m_elvmax - (m_elvmin - m_setbase_elv);

        if (f < -32768.f || f > 32768.f)
        {
            AfxMessageBox("Value would result in out-of-range height-values.",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
    }
}

//°±² eof - eshtdlg.cpp ²±°
