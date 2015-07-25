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
// eshtdlgx.cpp
//
// Terrain Editor Tool Dialog Classes
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "stdafx.h"
#include "eshtedit.h"
#include "eshtdlgx.h"
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

extern TerrEditApp  theApp;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°° Texture/Coloring Tool Dialogs °°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// HeightToolDlg                                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BEGIN_MESSAGE_MAP(HeightToolDlg, CDialog)
	//{{AFX_MSG_MAP(HeightToolDlg)
	ON_CBN_SELCHANGE(IDC_TOOL_TC0, OnSelchangeToolTc0)
	ON_CBN_SELCHANGE(IDC_TOOL_TC1, OnSelchangeToolTc1)
	ON_CBN_SELCHANGE(IDC_TOOL_TC2, OnSelchangeToolTc2)
	ON_CBN_SELCHANGE(IDC_TOOL_TC3, OnSelchangeToolTc3)
	ON_CBN_SELCHANGE(IDC_TOOL_TC4, OnSelchangeToolTc4)
	ON_CBN_SELCHANGE(IDC_TOOL_TC5, OnSelchangeToolTc5)
	ON_CBN_SELCHANGE(IDC_TOOL_TC6, OnSelchangeToolTc6)
	ON_CBN_SELCHANGE(IDC_TOOL_TC7, OnSelchangeToolTc7)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

HeightToolDlg::HeightToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(HeightToolDlg::IDD, pParent),
    pDoc(0),
    count(0)
{
	//{{AFX_DATA_INIT(HeightToolDlg)
	m_height0 = 0.0f;
	m_height1 = 0.0f;
	m_height2 = 0.0f;
	m_height3 = 0.0f;
	m_height4 = 0.0f;
	m_height5 = 0.0f;
	m_height6 = 0.0f;
	m_height7 = 0.0f;
	m_height_stop = 0.0f;
	m_preserve = FALSE;
	//}}AFX_DATA_INIT

    area = FALSE;
}

void HeightToolDlg::DoDataExchange(CDataExchange* pDX)
{
    ASSERT(pDoc);

	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(HeightToolDlg)
	DDX_Control(pDX, IDC_TOOL_HEIGHT7, m_height7Ctl);
	DDX_Control(pDX, IDC_TOOL_HEIGHT6, m_height6Ctl);
	DDX_Control(pDX, IDC_TOOL_HEIGHT5, m_height5Ctl);
	DDX_Control(pDX, IDC_TOOL_HEIGHT4, m_height4Ctl);
	DDX_Control(pDX, IDC_TOOL_HEIGHT3, m_height3Ctl);
	DDX_Control(pDX, IDC_TOOL_HEIGHT2, m_height2Ctl);
	DDX_Control(pDX, IDC_TOOL_HEIGHT1, m_height1Ctl);
	DDX_Control(pDX, IDC_TOOL_HEIGHT0, m_height0Ctl);
	DDX_Control(pDX, IDC_TOOL_TC7, m_tc7);
	DDX_Control(pDX, IDC_TOOL_TC6, m_tc6);
	DDX_Control(pDX, IDC_TOOL_TC5, m_tc5);
	DDX_Control(pDX, IDC_TOOL_TC4, m_tc4);
	DDX_Control(pDX, IDC_TOOL_TC3, m_tc3);
	DDX_Control(pDX, IDC_TOOL_TC2, m_tc2);
	DDX_Control(pDX, IDC_TOOL_TC1, m_tc1);
	DDX_Control(pDX, IDC_TOOL_TC0, m_tc0);
	DDX_Text(pDX, IDC_TOOL_HEIGHT0, m_height0);
	DDV_MinMaxFloat(pDX, m_height0, -32768.f, 32768.f);
	DDX_Text(pDX, IDC_TOOL_HEIGHT1, m_height1);
	DDV_MinMaxFloat(pDX, m_height1, -32768.f, 32768.f);
	DDX_Text(pDX, IDC_TOOL_HEIGHT2, m_height2);
	DDV_MinMaxFloat(pDX, m_height2, -32768.f, 32768.f);
	DDX_Text(pDX, IDC_TOOL_HEIGHT3, m_height3);
	DDV_MinMaxFloat(pDX, m_height3, -32768.f, 32768.f);
	DDX_Text(pDX, IDC_TOOL_HEIGHT4, m_height4);
	DDV_MinMaxFloat(pDX, m_height4, -32768.f, 32768.f);
	DDX_Text(pDX, IDC_TOOL_HEIGHT5, m_height5);
	DDV_MinMaxFloat(pDX, m_height5, -32768.f, 32768.f);
	DDX_Text(pDX, IDC_TOOL_HEIGHT6, m_height6);
	DDV_MinMaxFloat(pDX, m_height6, -32768.f, 32768.f);
	DDX_Text(pDX, IDC_TOOL_HEIGHT7, m_height7);
	DDV_MinMaxFloat(pDX, m_height7, -32768.f, 32768.f);
	DDX_Text(pDX, IDC_TOOL_HEIGHT_STOP, m_height_stop);
	DDV_MinMaxFloat(pDX, m_height_stop, -32768.f, 32768.f);
	DDX_Check(pDX, IDC_TOOL_PRESERVE, m_preserve);
	//}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        long i;

        //ÄÄ Setup all vs. selected
        CheckRadioButton( IDC_TOOL_ALL, IDC_TOOL_SELECTED,
                          (area == FALSE) ? IDC_TOOL_ALL : IDC_TOOL_SELECTED);

        //ÄÄ Setup edit fields
        m_height0Ctl.EnableWindow(FALSE);
        m_height1Ctl.EnableWindow(FALSE);
        m_height2Ctl.EnableWindow(FALSE);
        m_height3Ctl.EnableWindow(FALSE);
        m_height4Ctl.EnableWindow(FALSE);
        m_height5Ctl.EnableWindow(FALSE);
        m_height6Ctl.EnableWindow(FALSE);
        m_height7Ctl.EnableWindow(FALSE);

        //ÄÄ Setup combo boxes
        m_tc0.ResetContent();
        m_tc0.AddString("<None>");
        m_tc0.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc0.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc0.AddString(pDoc->colorName[i]);

        m_tc1.ResetContent();
        m_tc1.AddString("<None>");
        m_tc1.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc1.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc1.AddString(pDoc->colorName[i]);

        m_tc2.ResetContent();
        m_tc2.AddString("<None>");
        m_tc2.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc2.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc2.AddString(pDoc->colorName[i]);

        m_tc3.ResetContent();
        m_tc3.AddString("<None>");
        m_tc3.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc3.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc3.AddString(pDoc->colorName[i]);

        m_tc4.ResetContent();
        m_tc4.AddString("<None>");
        m_tc4.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc4.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc4.AddString(pDoc->colorName[i]);

        m_tc5.ResetContent();
        m_tc5.AddString("<None>");
        m_tc5.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc5.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc5.AddString(pDoc->colorName[i]);

        m_tc6.ResetContent();
        m_tc6.AddString("<None>");
        m_tc6.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc6.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc6.AddString(pDoc->colorName[i]);

        m_tc7.ResetContent();
        m_tc7.AddString("<None>");
        m_tc7.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc7.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc7.AddString(pDoc->colorName[i]);
    }
    else
    {
        switch (GetCheckedRadioButton(IDC_TOOL_ALL, IDC_TOOL_SELECTED))
        {
            case IDC_TOOL_ALL:  area=FALSE;  break;
            case IDC_TOOL_SELECTED:  area=TRUE;  break;
        }

        //ÄÄ Verify/Save settings
        float prev_value = -32768.0f;
        count = 0;

        if (m_tc0.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_HEIGHT0);
            if (m_height_stop < m_height0)
            {
                AfxMessageBox("Value must be less than the stop value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_height0;
            heights[count] = Flx16(m_height0);
            istxt[count] = (m_tc0.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc0.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc1.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_HEIGHT1);
            if (m_height_stop < m_height1)
            {
                AfxMessageBox("Value must be less than the stop value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            if (prev_value > m_height1)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_height1;
            heights[count] = Flx16(m_height1);
            istxt[count] = (m_tc1.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc1.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc2.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_HEIGHT2);
            if (m_height_stop < m_height2)
            {
                AfxMessageBox("Value must be less than the stop value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            if (prev_value > m_height2)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_height2;
            heights[count] = Flx16(m_height2);
            istxt[count] = (m_tc2.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc2.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc3.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_HEIGHT3);
            if (m_height_stop < m_height3)
            {
                AfxMessageBox("Value must be less than the stop value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            if (prev_value > m_height3)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_height3;
            heights[count] = Flx16(m_height3);
            istxt[count] = (m_tc3.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc3.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc4.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_HEIGHT4);
            if (m_height_stop < m_height4)
            {
                AfxMessageBox("Value must be less than the stop value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            if (prev_value > m_height4)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_height4;
            heights[count] = Flx16(m_height4);
            istxt[count] = (m_tc4.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc4.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc5.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_HEIGHT5);
            if (m_height_stop < m_height5)
            {
                AfxMessageBox("Value must be less than the stop value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            if (prev_value > m_height5)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_height5;
            heights[count] = Flx16(m_height5);
            istxt[count] = (m_tc5.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc5.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc6.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_HEIGHT6);
            if (m_height_stop < m_height6)
            {
                AfxMessageBox("Value must be less than the stop value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            if (prev_value > m_height6)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_height6;
            heights[count] = Flx16(m_height6);
            istxt[count] = (m_tc6.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc6.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc7.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_HEIGHT7);
            if (m_height_stop < m_height7)
            {
                AfxMessageBox("Value must be less than the stop value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            if (prev_value > m_height7)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_height7;
            heights[count] = Flx16(m_height7);
            istxt[count] = (m_tc7.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc7.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (!count)
        {
            pDX->PrepareCtrl(IDC_TOOL_TC0);
            AfxMessageBox("At least one texture/color must be selected.",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        if (m_height_stop == prev_value)
        {
            pDX->PrepareEditCtrl(IDC_TOOL_HEIGHT_STOP);
            AfxMessageBox("Stop value must be greater than last height.",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
    }
}

void HeightToolDlg::OnSelchangeToolTc0() 
{
    m_height0Ctl.EnableWindow((m_tc0.GetCurSel() == 0) ? FALSE : TRUE);
}

void HeightToolDlg::OnSelchangeToolTc1() 
{
    m_height1Ctl.EnableWindow((m_tc1.GetCurSel() == 0) ? FALSE : TRUE);
}

void HeightToolDlg::OnSelchangeToolTc2() 
{
    m_height2Ctl.EnableWindow((m_tc2.GetCurSel() == 0) ? FALSE : TRUE);
}

void HeightToolDlg::OnSelchangeToolTc3() 
{
    m_height3Ctl.EnableWindow((m_tc3.GetCurSel() == 0) ? FALSE : TRUE);
}

void HeightToolDlg::OnSelchangeToolTc4() 
{
    m_height4Ctl.EnableWindow((m_tc4.GetCurSel() == 0) ? FALSE : TRUE);
}

void HeightToolDlg::OnSelchangeToolTc5() 
{
    m_height5Ctl.EnableWindow((m_tc5.GetCurSel() == 0) ? FALSE : TRUE);
}

void HeightToolDlg::OnSelchangeToolTc6() 
{
    m_height6Ctl.EnableWindow((m_tc6.GetCurSel() == 0) ? FALSE : TRUE);
}

void HeightToolDlg::OnSelchangeToolTc7() 
{
    m_height7Ctl.EnableWindow((m_tc7.GetCurSel() == 0) ? FALSE : TRUE);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// RandomToolDlg                                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BEGIN_MESSAGE_MAP(RandomToolDlg, CDialog)
	//{{AFX_MSG_MAP(RandomToolDlg)
	ON_CBN_SELCHANGE(IDC_TOOL_TC0, OnSelchangeToolTc0)
	ON_CBN_SELCHANGE(IDC_TOOL_TC1, OnSelchangeToolTc1)
	ON_CBN_SELCHANGE(IDC_TOOL_TC2, OnSelchangeToolTc2)
	ON_CBN_SELCHANGE(IDC_TOOL_TC3, OnSelchangeToolTc3)
	ON_CBN_SELCHANGE(IDC_TOOL_TC4, OnSelchangeToolTc4)
	ON_CBN_SELCHANGE(IDC_TOOL_TC5, OnSelchangeToolTc5)
	ON_CBN_SELCHANGE(IDC_TOOL_TC6, OnSelchangeToolTc6)
	ON_CBN_SELCHANGE(IDC_TOOL_TC7, OnSelchangeToolTc7)
	ON_BN_CLICKED(IDC_TOOL_ELVCUTOFF, OnToolElvCutoffActive)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

RandomToolDlg::RandomToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(RandomToolDlg::IDD, pParent),
    pDoc(0),
    count(0)
{
	//{{AFX_DATA_INIT(RandomToolDlg)
	m_range0 = 0;
	m_range1 = 0;
	m_range2 = 0;
	m_range3 = 0;
	m_range4 = 0;
	m_range5 = 0;
	m_range6 = 0;
	m_range7 = 0;
	m_preserve = FALSE;
	m_elvcutoff = FALSE;
	m_elvhigh = 0.0f;
	m_elvlow = 0.0f;
	//}}AFX_DATA_INIT

    area = FALSE;
}

void RandomToolDlg::DoDataExchange(CDataExchange* pDX)
{
    ASSERT(pDoc);

	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(RandomToolDlg)
	DDX_Control(pDX, IDC_TOOL_ELVCUTOFF, m_elvcutoffCtl);
	DDX_Control(pDX, IDC_TOOL_ELVLOW, m_elvlowCtl);
	DDX_Control(pDX, IDC_TOOL_ELVHIGH, m_elvhighCtl);
	DDX_Control(pDX, IDC_TOOL_RANGE7, m_range7Ctl);
	DDX_Control(pDX, IDC_TOOL_RANGE6, m_range6Ctl);
	DDX_Control(pDX, IDC_TOOL_RANGE5, m_range5Ctl);
	DDX_Control(pDX, IDC_TOOL_RANGE4, m_range4Ctl);
	DDX_Control(pDX, IDC_TOOL_RANGE3, m_range3Ctl);
	DDX_Control(pDX, IDC_TOOL_RANGE2, m_range2Ctl);
	DDX_Control(pDX, IDC_TOOL_RANGE1, m_range1Ctl);
	DDX_Control(pDX, IDC_TOOL_RANGE0, m_range0Ctl);
	DDX_Control(pDX, IDC_TOOL_TC7, m_tc7);
	DDX_Control(pDX, IDC_TOOL_TC6, m_tc6);
	DDX_Control(pDX, IDC_TOOL_TC5, m_tc5);
	DDX_Control(pDX, IDC_TOOL_TC4, m_tc4);
	DDX_Control(pDX, IDC_TOOL_TC3, m_tc3);
	DDX_Control(pDX, IDC_TOOL_TC2, m_tc2);
	DDX_Control(pDX, IDC_TOOL_TC1, m_tc1);
	DDX_Control(pDX, IDC_TOOL_TC0, m_tc0);
	DDX_Text(pDX, IDC_TOOL_RANGE0, m_range0);
	DDV_MinMaxUInt(pDX, m_range0, 0, 100);
	DDX_Text(pDX, IDC_TOOL_RANGE1, m_range1);
	DDV_MinMaxUInt(pDX, m_range1, 0, 100);
	DDX_Text(pDX, IDC_TOOL_RANGE2, m_range2);
	DDV_MinMaxUInt(pDX, m_range2, 0, 100);
	DDX_Text(pDX, IDC_TOOL_RANGE3, m_range3);
	DDV_MinMaxUInt(pDX, m_range3, 0, 100);
	DDX_Text(pDX, IDC_TOOL_RANGE4, m_range4);
	DDV_MinMaxUInt(pDX, m_range4, 0, 100);
	DDX_Text(pDX, IDC_TOOL_RANGE5, m_range5);
	DDV_MinMaxUInt(pDX, m_range5, 0, 100);
	DDX_Text(pDX, IDC_TOOL_RANGE6, m_range6);
	DDV_MinMaxUInt(pDX, m_range6, 0, 100);
	DDX_Text(pDX, IDC_TOOL_RANGE7, m_range7);
	DDV_MinMaxUInt(pDX, m_range7, 0, 100);
	DDX_Check(pDX, IDC_TOOL_PRESERVE, m_preserve);
	DDX_Check(pDX, IDC_TOOL_ELVCUTOFF, m_elvcutoff);
	DDX_Text(pDX, IDC_TOOL_ELVHIGH, m_elvhigh);
	DDV_MinMaxFloat(pDX, m_elvhigh, -32768.f, 32768.f);
	DDX_Text(pDX, IDC_TOOL_ELVLOW, m_elvlow);
	DDV_MinMaxFloat(pDX, m_elvlow, -32768.f, 32768.f);
	//}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        long i;

        //ÄÄ Setup all vs. selected
        CheckRadioButton( IDC_TOOL_ALL, IDC_TOOL_SELECTED,
                          (area == FALSE) ? IDC_TOOL_ALL : IDC_TOOL_SELECTED);

        //ÄÄ Setup edit fields
        m_range0Ctl.EnableWindow(FALSE);
        m_range1Ctl.EnableWindow(FALSE);
        m_range2Ctl.EnableWindow(FALSE);
        m_range3Ctl.EnableWindow(FALSE);
        m_range4Ctl.EnableWindow(FALSE);
        m_range5Ctl.EnableWindow(FALSE);
        m_range6Ctl.EnableWindow(FALSE);
        m_range7Ctl.EnableWindow(FALSE);

        //ÄÄ Setup combo boxes
        m_tc0.ResetContent();
        m_tc0.AddString("<None>");
        m_tc0.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc0.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc0.AddString(pDoc->colorName[i]);

        m_tc1.ResetContent();
        m_tc1.AddString("<None>");
        m_tc1.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc1.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc1.AddString(pDoc->colorName[i]);

        m_tc2.ResetContent();
        m_tc2.AddString("<None>");
        m_tc2.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc2.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc2.AddString(pDoc->colorName[i]);

        m_tc3.ResetContent();
        m_tc3.AddString("<None>");
        m_tc3.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc3.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc3.AddString(pDoc->colorName[i]);

        m_tc4.ResetContent();
        m_tc4.AddString("<None>");
        m_tc4.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc4.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc4.AddString(pDoc->colorName[i]);

        m_tc5.ResetContent();
        m_tc5.AddString("<None>");
        m_tc5.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc5.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc5.AddString(pDoc->colorName[i]);

        m_tc6.ResetContent();
        m_tc6.AddString("<None>");
        m_tc6.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc6.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc6.AddString(pDoc->colorName[i]);

        m_tc7.ResetContent();
        m_tc7.AddString("<None>");
        m_tc7.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc7.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc7.AddString(pDoc->colorName[i]);

        //ÄÄ Setup elvation cutoff
        m_elvlowCtl.EnableWindow(m_elvcutoff);
        m_elvhighCtl.EnableWindow(m_elvcutoff);
    }
    else
    {
        switch (GetCheckedRadioButton(IDC_TOOL_ALL, IDC_TOOL_SELECTED))
        {
            case IDC_TOOL_ALL:  area=FALSE;  break;
            case IDC_TOOL_SELECTED:  area=TRUE;  break;
        }

        //ÄÄ Verify settings
        UINT prev_value=0;
        count = 0;
            
        if (m_tc0.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_RANGE0);
            prev_value = m_range0;
            chances[count] = m_range0;
            istxt[count] = (m_tc0.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc0.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc1.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_RANGE1);
            if (prev_value > m_range1)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_range1;
            chances[count] = m_range1;
            istxt[count] = (m_tc1.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc1.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc2.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_RANGE2);
            if (prev_value > m_range2)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_range2;
            chances[count] = m_range2;
            istxt[count] = (m_tc2.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc2.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc3.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_RANGE3);
            if (prev_value > m_range3)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_range3;
            chances[count] = m_range3;
            istxt[count] = (m_tc3.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc3.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc4.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_RANGE4);
            if (prev_value > m_range4)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_range4;
            chances[count] = m_range4;
            istxt[count] = (m_tc4.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc4.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc5.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_RANGE5);
            if (prev_value > m_range5)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_range5;
            chances[count] = m_range5;
            istxt[count] = (m_tc5.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc5.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc6.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_RANGE6);
            if (prev_value > m_range6)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_range6;
            chances[count] = m_range6;
            istxt[count] = (m_tc6.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc6.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc7.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_RANGE7);
            if (prev_value > m_range7)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_range7;
            chances[count] = m_range7;
            istxt[count] = (m_tc7.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc7.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (!count)
        {
            pDX->PrepareCtrl(IDC_TOOL_TC0);
            AfxMessageBox("At least one texture/color must be selected.",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        if (m_elvcutoff && m_elvhigh <= m_elvlow)
        {
            pDX->PrepareEditCtrl(IDC_TOOL_ELVLOW);
            AfxMessageBox("Value must be less than high value",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
    }
}

void RandomToolDlg::OnSelchangeToolTc0() 
{
    m_range0Ctl.EnableWindow((m_tc0.GetCurSel() == 0) ? FALSE : TRUE);
}

void RandomToolDlg::OnSelchangeToolTc1() 
{
    m_range1Ctl.EnableWindow((m_tc1.GetCurSel() == 0) ? FALSE : TRUE);
}

void RandomToolDlg::OnSelchangeToolTc2() 
{
    m_range2Ctl.EnableWindow((m_tc2.GetCurSel() == 0) ? FALSE : TRUE);
}

void RandomToolDlg::OnSelchangeToolTc3() 
{
    m_range3Ctl.EnableWindow((m_tc3.GetCurSel() == 0) ? FALSE : TRUE);
}

void RandomToolDlg::OnSelchangeToolTc4() 
{
    m_range4Ctl.EnableWindow((m_tc4.GetCurSel() == 0) ? FALSE : TRUE);
}

void RandomToolDlg::OnSelchangeToolTc5() 
{
    m_range5Ctl.EnableWindow((m_tc5.GetCurSel() == 0) ? FALSE : TRUE);
}

void RandomToolDlg::OnSelchangeToolTc6() 
{
    m_range6Ctl.EnableWindow((m_tc6.GetCurSel() == 0) ? FALSE : TRUE);
}

void RandomToolDlg::OnSelchangeToolTc7() 
{
    m_range7Ctl.EnableWindow((m_tc7.GetCurSel() == 0) ? FALSE : TRUE);
}

void RandomToolDlg::OnToolElvCutoffActive() 
{
    int state=m_elvcutoffCtl.GetCheck();
    
    m_elvlowCtl.EnableWindow(state);
    m_elvhighCtl.EnableWindow(state);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// AngleToolDlg                                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BEGIN_MESSAGE_MAP(AngleToolDlg, CDialog)
	//{{AFX_MSG_MAP(AngleToolDlg)
	ON_CBN_SELCHANGE(IDC_TOOL_TC0, OnSelchangeToolTc0)
	ON_CBN_SELCHANGE(IDC_TOOL_TC1, OnSelchangeToolTc1)
	ON_CBN_SELCHANGE(IDC_TOOL_TC2, OnSelchangeToolTc2)
	ON_CBN_SELCHANGE(IDC_TOOL_TC3, OnSelchangeToolTc3)
	ON_CBN_SELCHANGE(IDC_TOOL_TC4, OnSelchangeToolTc4)
	ON_CBN_SELCHANGE(IDC_TOOL_TC5, OnSelchangeToolTc5)
	ON_CBN_SELCHANGE(IDC_TOOL_TC6, OnSelchangeToolTc6)
	ON_CBN_SELCHANGE(IDC_TOOL_TC7, OnSelchangeToolTc7)
	ON_BN_CLICKED(IDC_TOOL_ELVCUTOFF, OnToolElvCutoff)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

AngleToolDlg::AngleToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(AngleToolDlg::IDD, pParent),
    pDoc(0),
    count(0)
{
	//{{AFX_DATA_INIT(AngleToolDlg)
	m_angle_stop = 0.0f;
	m_angle0 = 0.0f;
	m_angle1 = 0.0f;
	m_angle2 = 0.0f;
	m_angle3 = 0.0f;
	m_angle4 = 0.0f;
	m_angle5 = 0.0f;
	m_angle6 = 0.0f;
	m_angle7 = 0.0f;
	m_preserve = FALSE;
	m_elvcutoff = FALSE;
	m_elvhigh = 0.0f;
	m_elvlow = 0.0f;
	//}}AFX_DATA_INIT

    area = FALSE;
}

void AngleToolDlg::DoDataExchange(CDataExchange* pDX)
{
    ASSERT(pDoc);

	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AngleToolDlg)
	DDX_Control(pDX, IDC_TOOL_ELVLOW, m_elvlowCtl);
	DDX_Control(pDX, IDC_TOOL_ELVHIGH, m_elvhighCtl);
	DDX_Control(pDX, IDC_TOOL_ELVCUTOFF, m_elvcutoffCtl);
	DDX_Control(pDX, IDC_TOOL_ANGLE7, m_angle7Ctl);
	DDX_Control(pDX, IDC_TOOL_ANGLE6, m_angle6Ctl);
	DDX_Control(pDX, IDC_TOOL_ANGLE5, m_angle5Ctl);
	DDX_Control(pDX, IDC_TOOL_ANGLE4, m_angle4Ctl);
	DDX_Control(pDX, IDC_TOOL_ANGLE3, m_angle3Ctl);
	DDX_Control(pDX, IDC_TOOL_ANGLE2, m_angle2Ctl);
	DDX_Control(pDX, IDC_TOOL_ANGLE1, m_angle1Ctl);
	DDX_Control(pDX, IDC_TOOL_ANGLE0, m_angle0Ctl);
	DDX_Control(pDX, IDC_TOOL_TC7, m_tc7);
	DDX_Control(pDX, IDC_TOOL_TC6, m_tc6);
	DDX_Control(pDX, IDC_TOOL_TC5, m_tc5);
	DDX_Control(pDX, IDC_TOOL_TC4, m_tc4);
	DDX_Control(pDX, IDC_TOOL_TC3, m_tc3);
	DDX_Control(pDX, IDC_TOOL_TC2, m_tc2);
	DDX_Control(pDX, IDC_TOOL_TC1, m_tc1);
	DDX_Control(pDX, IDC_TOOL_TC0, m_tc0);
	DDX_Text(pDX, IDC_TOOL_ANGLE_STOP, m_angle_stop);
	DDV_MinMaxFloat(pDX, m_angle_stop, 0.f, 90.f);
	DDX_Text(pDX, IDC_TOOL_ANGLE0, m_angle0);
	DDV_MinMaxFloat(pDX, m_angle0, 0.f, 90.f);
	DDX_Text(pDX, IDC_TOOL_ANGLE1, m_angle1);
	DDV_MinMaxFloat(pDX, m_angle1, 0.f, 90.f);
	DDX_Text(pDX, IDC_TOOL_ANGLE2, m_angle2);
	DDV_MinMaxFloat(pDX, m_angle2, 0.f, 90.f);
	DDX_Text(pDX, IDC_TOOL_ANGLE3, m_angle3);
	DDV_MinMaxFloat(pDX, m_angle3, 0.f, 90.f);
	DDX_Text(pDX, IDC_TOOL_ANGLE4, m_angle4);
	DDV_MinMaxFloat(pDX, m_angle4, 0.f, 90.f);
	DDX_Text(pDX, IDC_TOOL_ANGLE5, m_angle5);
	DDV_MinMaxFloat(pDX, m_angle5, 0.f, 90.f);
	DDX_Text(pDX, IDC_TOOL_ANGLE6, m_angle6);
	DDV_MinMaxFloat(pDX, m_angle6, 0.f, 90.f);
	DDX_Text(pDX, IDC_TOOL_ANGLE7, m_angle7);
	DDV_MinMaxFloat(pDX, m_angle7, 0.f, 90.f);
	DDX_Check(pDX, IDC_TOOL_PRESERVE, m_preserve);
	DDX_Check(pDX, IDC_TOOL_ELVCUTOFF, m_elvcutoff);
	DDX_Text(pDX, IDC_TOOL_ELVHIGH, m_elvhigh);
	DDV_MinMaxFloat(pDX, m_elvhigh, -32768.f, 32768.f);
	DDX_Text(pDX, IDC_TOOL_ELVLOW, m_elvlow);
	DDV_MinMaxFloat(pDX, m_elvlow, -32768.f, 32768.f);
	//}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        long i;

        //ÄÄ Setup all vs. selected
        CheckRadioButton( IDC_TOOL_ALL, IDC_TOOL_SELECTED,
                          (area == FALSE) ? IDC_TOOL_ALL : IDC_TOOL_SELECTED);

        //ÄÄ Setup edit fields
        m_angle0Ctl.EnableWindow(FALSE);
        m_angle1Ctl.EnableWindow(FALSE);
        m_angle2Ctl.EnableWindow(FALSE);
        m_angle3Ctl.EnableWindow(FALSE);
        m_angle4Ctl.EnableWindow(FALSE);
        m_angle5Ctl.EnableWindow(FALSE);
        m_angle6Ctl.EnableWindow(FALSE);
        m_angle7Ctl.EnableWindow(FALSE);

        //ÄÄ Setup combo boxes
        m_tc0.ResetContent();
        m_tc0.AddString("<None>");
        m_tc0.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc0.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc0.AddString(pDoc->colorName[i]);

        m_tc1.ResetContent();
        m_tc1.AddString("<None>");
        m_tc1.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc1.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc1.AddString(pDoc->colorName[i]);

        m_tc2.ResetContent();
        m_tc2.AddString("<None>");
        m_tc2.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc2.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc2.AddString(pDoc->colorName[i]);

        m_tc3.ResetContent();
        m_tc3.AddString("<None>");
        m_tc3.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc3.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc3.AddString(pDoc->colorName[i]);

        m_tc4.ResetContent();
        m_tc4.AddString("<None>");
        m_tc4.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc4.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc4.AddString(pDoc->colorName[i]);

        m_tc5.ResetContent();
        m_tc5.AddString("<None>");
        m_tc5.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc5.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc5.AddString(pDoc->colorName[i]);

        m_tc6.ResetContent();
        m_tc6.AddString("<None>");
        m_tc6.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc6.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc6.AddString(pDoc->colorName[i]);

        m_tc7.ResetContent();
        m_tc7.AddString("<None>");
        m_tc7.SetCurSel(0);
        for(i=0; i < pDoc->txtNumb; i++)
            m_tc7.AddString(pDoc->txtName[i]);
        for(i=0; i < pDoc->colorNumb; i++)
            m_tc7.AddString(pDoc->colorName[i]);

        //ÄÄ Setup elvation cutoff
        m_elvlowCtl.EnableWindow(m_elvcutoff);
        m_elvhighCtl.EnableWindow(m_elvcutoff);
    }
    else
    {
        switch (GetCheckedRadioButton(IDC_TOOL_ALL, IDC_TOOL_SELECTED))
        {
            case IDC_TOOL_ALL:  area=FALSE;  break;
            case IDC_TOOL_SELECTED:  area=TRUE;  break;
        }

        //ÄÄ Verify/Save settings
        float prev_value = 0.0f;
        count = 0;

        if (m_tc0.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_ANGLE0);
            if (m_angle_stop < m_angle0)
            {
                AfxMessageBox("Value must be less than the stop value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_angle0;
            angles[count] = Flx16(m_angle0);
            istxt[count] = (m_tc0.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc0.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc1.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_ANGLE1);
            if (m_angle_stop < m_angle1)
            {
                AfxMessageBox("Value must be less than the stop value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            if (prev_value > m_angle1)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_angle1;
            angles[count] = Flx16(m_angle1);
            istxt[count] = (m_tc1.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc1.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc2.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_ANGLE2);
            if (m_angle_stop < m_angle2)
            {
                AfxMessageBox("Value must be less than the stop value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            if (prev_value > m_angle2)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_angle2;
            angles[count] = Flx16(m_angle2);
            istxt[count] = (m_tc2.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc2.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc3.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_ANGLE3);
            if (m_angle_stop < m_angle3)
            {
                AfxMessageBox("Value must be less than the stop value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            if (prev_value > m_angle3)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_angle3;
            angles[count] = Flx16(m_angle3);
            istxt[count] = (m_tc3.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc3.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc4.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_ANGLE4);
            if (m_angle_stop < m_angle4)
            {
                AfxMessageBox("Value must be less than the stop value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            if (prev_value > m_angle4)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_angle4;
            angles[count] = Flx16(m_angle4);
            istxt[count] = (m_tc4.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc4.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc5.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_ANGLE5);
            if (m_angle_stop < m_angle5)
            {
                AfxMessageBox("Value must be less than the stop value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            if (prev_value > m_angle5)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_angle5;
            angles[count] = Flx16(m_angle5);
            istxt[count] = (m_tc5.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc5.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc6.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_ANGLE6);
            if (m_angle_stop < m_angle6)
            {
                AfxMessageBox("Value must be less than the stop value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            if (prev_value > m_angle6)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_angle6;
            angles[count] = Flx16(m_angle6);
            istxt[count] = (m_tc6.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc6.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (m_tc7.GetCurSel())
        {
            pDX->PrepareEditCtrl(IDC_TOOL_ANGLE7);
            if (m_angle_stop < m_angle7)
            {
                AfxMessageBox("Value must be less than the stop value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            if (prev_value > m_angle7)
            {
                AfxMessageBox("Value must be greater than or equal to the previous value",
                              MB_OK | MB_ICONEXCLAMATION);
                pDX->Fail();
            }
            prev_value = m_angle7;
            angles[count] = Flx16(m_angle7);
            istxt[count] = (m_tc7.GetCurSel() > pDoc->txtNumb) ? 0 : 1;
            tc[count] = m_tc7.GetCurSel()-1-(istxt[count] ? 0 : pDoc->txtNumb);
            count++;
        }

        if (!count)
        {
            pDX->PrepareCtrl(IDC_TOOL_TC0);
            AfxMessageBox("At least one texture/color must be selected.",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        if (m_angle_stop == prev_value)
        {
            pDX->PrepareEditCtrl(IDC_TOOL_ANGLE_STOP);
            AfxMessageBox("Stop value must be greater than last angle.",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }

        if (m_elvcutoff && m_elvhigh <= m_elvlow)
        {
            pDX->PrepareEditCtrl(IDC_TOOL_ELVLOW);
            AfxMessageBox("Value must be less than high value",
                          MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
    }
}

void AngleToolDlg::OnSelchangeToolTc0() 
{
    m_angle0Ctl.EnableWindow((m_tc0.GetCurSel() == 0) ? FALSE : TRUE);
}

void AngleToolDlg::OnSelchangeToolTc1() 
{
    m_angle1Ctl.EnableWindow((m_tc1.GetCurSel() == 0) ? FALSE : TRUE);
}

void AngleToolDlg::OnSelchangeToolTc2() 
{
    m_angle2Ctl.EnableWindow((m_tc2.GetCurSel() == 0) ? FALSE : TRUE);
}

void AngleToolDlg::OnSelchangeToolTc3() 
{
    m_angle3Ctl.EnableWindow((m_tc3.GetCurSel() == 0) ? FALSE : TRUE);
}

void AngleToolDlg::OnSelchangeToolTc4() 
{
    m_angle4Ctl.EnableWindow((m_tc4.GetCurSel() == 0) ? FALSE : TRUE);
}

void AngleToolDlg::OnSelchangeToolTc5() 
{
    m_angle5Ctl.EnableWindow((m_tc5.GetCurSel() == 0) ? FALSE : TRUE);
}

void AngleToolDlg::OnSelchangeToolTc6() 
{
    m_angle6Ctl.EnableWindow((m_tc6.GetCurSel() == 0) ? FALSE : TRUE);
}

void AngleToolDlg::OnSelchangeToolTc7()
{
    m_angle7Ctl.EnableWindow((m_tc7.GetCurSel() == 0) ? FALSE : TRUE);
}

void AngleToolDlg::OnToolElvCutoff() 
{
    int state=m_elvcutoffCtl.GetCheck();
    
    m_elvlowCtl.EnableWindow(state);
    m_elvhighCtl.EnableWindow(state);
}

//°±² eof - eshtdlgx.cpp ²±°
