//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                 PalTool
//
//                   A Palette extraction/definition tool
//
//           Copyright (c) 1995-1998 by Charybdis Enterprises, Inc.
//                           All Rights Reserved
//
//                      Microsoft Windows '95 Version
//
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
// Dan Higdon & Chuck Walbourn
//
// dialog.cpp
//
// PalTool dialog classes.
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
//°°°°°°°°°°°°°°°°°°°°°°°°°° Properties Dialog °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPropertiesDlgA
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
IMPLEMENT_DYNCREATE(CPropertiesDlgA, CPropertyPage)

BEGIN_MESSAGE_MAP(CPropertiesDlgA, CPropertyPage)
        //{{AFX_MSG_MAP(CPropertiesDlgA)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CPropertiesDlgA::CPropertiesDlgA() : CPropertyPage(CPropertiesDlgA::IDD)
{
        //{{AFX_DATA_INIT(CPropertiesDlgA)
        m_name = _T("");
        m_8bit = FALSE;
        m_15bit = FALSE;
        m_16bit = FALSE;
        m_24bit = FALSE;
        m_midpoint = 0;
        m_slevels = 0;
        //}}AFX_DATA_INIT
}

CPropertiesDlgA::~CPropertiesDlgA()
{
}

void CPropertiesDlgA::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CPropertiesDlgA)
        DDX_Text(pDX, IDC_PROP_NAME, m_name);
        DDV_MaxChars(pDX, m_name, 16);
        DDX_Check(pDX, IDC_PROP_8BIT, m_8bit);
        DDX_Check(pDX, IDC_PROP_15BIT, m_15bit);
        DDX_Check(pDX, IDC_PROP_16BIT, m_16bit);
        DDX_Check(pDX, IDC_PROP_24BIT, m_24bit);
        DDX_Text(pDX, IDC_PROP_MIDPOINT, m_midpoint);
        DDV_MinMaxLong(pDX, m_midpoint, 2, 255);
        DDX_Text(pDX, IDC_PROP_SHDLVLS, m_slevels);
        //}}AFX_DATA_MAP


    if (pDX->m_bSaveAndValidate)
    {
        if (m_name.IsEmpty())
        {
            pDX->PrepareCtrl(IDC_PROP_NAME);
            AfxMessageBox("A name is required",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        if (!m_8bit && !m_15bit && !m_16bit && !m_24bit)
        {
            pDX->PrepareCtrl(IDC_PROP_8BIT);
            AfxMessageBox("Must select at least one color-depth",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPropertiesDlgB
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
IMPLEMENT_DYNCREATE(CPropertiesDlgB, CPropertyPage)

BEGIN_MESSAGE_MAP(CPropertiesDlgB, CPropertyPage)
        //{{AFX_MSG_MAP(CPropertiesDlgB)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CPropertiesDlgB::CPropertiesDlgB() : CPropertyPage(CPropertiesDlgB::IDD)
{
        //{{AFX_DATA_INIT(CPropertiesDlgB)
                // NOTE: the ClassWizard will add member initialization here
        //}}AFX_DATA_INIT
}

CPropertiesDlgB::~CPropertiesDlgB()
{
}

void CPropertiesDlgB::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CPropertiesDlgB)
                // NOTE: the ClassWizard will add DDX and DDV calls here
        //}}AFX_DATA_MAP
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPropertiesDlgC
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
IMPLEMENT_DYNCREATE(CPropertiesDlgC, CPropertyPage)

BEGIN_MESSAGE_MAP(CPropertiesDlgC, CPropertyPage)
        //{{AFX_MSG_MAP(CPropertiesDlgC)
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CPropertiesDlgC::CPropertiesDlgC() : CPropertyPage(CPropertiesDlgC::IDD)
{
        //{{AFX_DATA_INIT(CPropertiesDlgC)
        m_auth = _T("");
        m_copy = _T("");
        m_desc = _T("");
        //}}AFX_DATA_INIT
}

CPropertiesDlgC::~CPropertiesDlgC()
{
}

void CPropertiesDlgC::DoDataExchange(CDataExchange* pDX)
{
        CPropertyPage::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CPropertiesDlgC)
        DDX_Text(pDX, IDC_PROP_AUTH, m_auth);
        DDV_MaxChars(pDX, m_auth, 255);
        DDX_Text(pDX, IDC_PROP_COPY, m_copy);
        DDV_MaxChars(pDX, m_copy, 255);
        DDX_Text(pDX, IDC_PROP_DESC, m_desc);
        DDV_MaxChars(pDX, m_desc, 255);
        //}}AFX_DATA_MAP
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Palette Dialog °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPaletteDlg
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BEGIN_MESSAGE_MAP(CPaletteDlg, CDialog)
        //{{AFX_MSG_MAP(CPaletteDlg)
        ON_BN_CLICKED(IDC_COLOR, OnColor)
        ON_CBN_SELCHANGE(IDC_PAL_INDEX, OnIndexSelectChange)
        ON_WM_HSCROLL()
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CPaletteDlg::CPaletteDlg(dword i, VngoPal *p, CWnd* pParent)
        : CDialog(CPaletteDlg::IDD, pParent)
{
        //{{AFX_DATA_INIT(CPaletteDlg)
        m_red = 0;
        m_green = 0;
        m_blue = 0;
        //}}AFX_DATA_INIT

    if (i >= VNGO_PAL_SIZE)
        i = (VNGO_PAL_SIZE-1);
    index = i;

    for(i = 0; i < VNGO_PAL_SIZE; i++)
    {
        pal[i] = ((VngoPal8*)p)->hw_pal.p[i];
    }
}

void CPaletteDlg::DoDataExchange(CDataExchange* pDX)
{
    assert(index < VNGO_PAL_SIZE);

    if (!pDX->m_bSaveAndValidate)
    {
        // Get color values for current index
        m_red = pal[index].r;
        m_green = pal[index].g;
        m_blue = pal[index].b;
    }

        CDialog::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CPaletteDlg)
        DDX_Control(pDX, IDC_PAL_SBLUE, m_bluescroll);
        DDX_Control(pDX, IDC_PAL_SGREEN, m_greenscroll);
        DDX_Control(pDX, IDC_PAL_SRED, m_redscroll);
        DDX_Control(pDX, IDC_PAL_INDEX, m_indlist);
        DDX_Text(pDX, IDC_PAL_RED, m_red);
        DDV_MinMaxByte(pDX, m_red, 0, 255);
        DDX_Text(pDX, IDC_PAL_GREEN, m_green);
        DDV_MinMaxByte(pDX, m_green, 0, 255);
        DDX_Text(pDX, IDC_PAL_BLUE, m_blue);
        //}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        // Setup index combobox
        char    buff[32];
        m_indlist.ResetContent();
        for(dword i=0; i < VNGO_PAL_SIZE; i++)
        {
            wsprintf(buff,"%i",i);
            m_indlist.AddString(buff);
        }
        m_indlist.SetCurSel(index);

        // Setup color values
        m_redscroll.SetScrollRange(0,255,FALSE);
        m_redscroll.SetScrollPos(m_red);

        m_greenscroll.SetScrollRange(0,255,FALSE);
        m_greenscroll.SetScrollPos(m_green);

        m_bluescroll.SetScrollRange(0,255,FALSE);
        m_bluescroll.SetScrollPos(m_blue);
    }
    else
    {
        pal[index].r = m_red;
        pal[index].g = m_green;
        pal[index].b = m_blue;
    }
}

void CPaletteDlg::OnColor()
{
    UpdateData(TRUE);

    CColorDialog dlg(m_red | (m_green << 8) | (m_blue << 16), CC_RGBINIT | CC_FULLOPEN, this);

    if (dlg.DoModal() == IDOK)
    {
        pal[index] = dlg.GetColor();
        UpdateData(FALSE);
    }
}

void CPaletteDlg::OnIndexSelectChange()
{
    dword newind = m_indlist.GetCurSel();

    UpdateData(TRUE);
    index = newind;
    UpdateData(FALSE);
}

void CPaletteDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    UINT val = pScrollBar->GetScrollPos();

    switch (nSBCode)
    {
        case SB_LINELEFT:
            if (val > 0)
                val--;
            break;
        case SB_PAGELEFT:
            if (val < 16)
                val = 0;
            else
                val -= 16;
            break;
        case SB_LINERIGHT:
            if (val < 255)
                val++;
            break;
        case SB_PAGERIGHT:
            if (val > 239)
                val = 255;
            else
                val += 16;
            break;
        case SB_THUMBPOSITION:
            val = nPos;
            break;
        default:
            return;
    }

    if (pScrollBar == &m_redscroll)
        pal[index].r = (byte)val;
    else if (pScrollBar == &m_greenscroll)
        pal[index].g = (byte)val;
    else if (pScrollBar == &m_bluescroll)
        pal[index].b = (byte)val;

    UpdateData(FALSE);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Progress Dialog °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CProgressDlg
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BEGIN_MESSAGE_MAP(CProgressDlg, CDialog)
        //{{AFX_MSG_MAP(CProgressDlg)
                // NOTE: the ClassWizard will add message map macros here
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CProgressDlg::CProgressDlg(CWnd* pParent /*=NULL*/)
        : CDialog(CProgressDlg::IDD, pParent)
{
        //{{AFX_DATA_INIT(CProgressDlg)
                // NOTE: the ClassWizard will add member initialization here
        //}}AFX_DATA_INIT

        Create (CProgressDlg::IDD);
}

void CProgressDlg::DoDataExchange(CDataExchange* pDX)
{
        CDialog::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CProgressDlg)
        DDX_Control(pDX, IDC_PROGRESSBAR, m_pbar);
        //}}AFX_DATA_MAP
}

//°±² eof - dialog.cpp ²±°
