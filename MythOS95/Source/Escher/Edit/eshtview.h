//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//שששששששששש°°°°°°°°°°ש°°°°°°°°ששש°°°°°°°°שש°°°שששש°°°ש°°°°°°°°°°ש°°°°°°°°°שש
//ששששששששש°±°ששששששש°±°שששש°±°ש°±°שששש°±°ש°±°שששש°±°ש°±°שששששששש°±°שששש°±°שש
//שששששששש±°±ששששששש±°±שששששששש±°±שששששששש±°±שששש±°±ש±°±שששששששש±°±שששש±°±ששש
//ששששששש±²±±°±±²שש±²±±°±±²±±ש±²±שששששששש±²±±°±±²±±ש±²±±°±±²ששש±²±±°±±²°ששששש
//שששששש±²±שששששששששששששש±²±ש±²±שששששששש±²±שששש±²±ש±²±שששששששש±²±שששש±²±ששששש
//ששששש²±²ששששששש²±²שששש²±²ש²±²שששש²±²ש²±²שששש²±²ש²±²שששששששש²±²שששש²±²שששששש
//שששש²²²²²²²²²²ש²²²²²²²²ששש²²²²²²²²שש²²²שששש²²²ש²²²²²²²²²²ש²²²שששש²²²ששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//ששששששששששששששששששש Microsoft Windows 95/NT Version ששששששששששששששששששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//שששששששששששCopyrightש(c)ש1994-1998שbyשCharybdisשEnterprises,שInc.שששששששששש
//ששששששששששששששששששששששששששAllשRightsשReserved.ששששששששששששששששששששששששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
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
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
//
//                        *** Escher Terrain Editor ***
//
// Chuck Walbourn
//
// eshtview.h
//
// Terrain View class
//
// The view class handles the display of the data contained in an
// TerrEditDoc class.
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "eshtlist.h"
#include "eshtgrid.h"
#include "eshtrend.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define HINT_UPDATETXTS     0x1
#define HINT_UPDATETERR     0x2
#define HINT_UPDATECOLR     0x4
#define HINT_UPDATELIGHTS   0x8
#define HINT_UPDATECLRLIST  0x10
#define HINT_UPDATETXTLIST  0x20


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// TerrEditView                                                             ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ

class TerrEditView : public CView
{
protected: // create from serialization only
	TerrEditView();
	DECLARE_DYNCREATE(TerrEditView)

// Attributes
public:
	TerrEditDoc* GetDocument();

// Operations
public:
    int  GetCurrentTextureSel() { return txtList.GetCurSel(); }
    int  GetCurrentColorSel() { return colorList.GetCurSel(); }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TerrEditView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();
	protected:
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~TerrEditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
     
protected:
    UINT                gridright;
    UINT                rendertop;
    UINT                textureright;

    TerrColorList       colorList;
    TerrEditList        txtList;
    TerrEditGrid        grid;
    TerrEditRender      rend;

    int                 displayrender;

// Generated message map functions
protected:
	//{{AFX_MSG(TerrEditView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnViewRender();
	afx_msg void OnViewRndDots();
	afx_msg void OnViewRndWireframe();
	afx_msg void OnViewRndSolid();
	afx_msg void OnViewRndFlat();
	afx_msg void OnViewRndSmooth();
	afx_msg void OnViewRndSpecular();
	afx_msg void OnViewRndBackface();
	afx_msg void OnViewRndTextures();
	afx_msg void OnViewRefresh();
	afx_msg void OnViewRndPerspective();
	afx_msg void OnViewRotateXY();
	afx_msg void OnViewMoveXY();
	afx_msg void OnViewRotateMoveZ();
	afx_msg void OnLightAdjustXY();
	afx_msg void OnLightAdjustIntensity();
	afx_msg void OnViewZoomNormal();
	afx_msg void OnViewZoomLarge();
	afx_msg void OnViewZoomMedium();
	afx_msg void OnViewZoomExLarge();
	afx_msg void OnViewProperties();
	afx_msg void OnViewZoomMega();
	afx_msg void OnUpdateViewRender(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewRotateXY(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewMoveXY(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewRotateMoveZ(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewProperties(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewZoomNormal(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewZoomMedium(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewZoomLarge(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewZoomExLarge(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewZoomMega(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewRndDots(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewRndWireframe(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewRndSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewRndFlat(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewRndSmooth(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewRndSpecular(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewRndBackface(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewRndTextures(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewRndPerspective(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLightAdjustIntensity(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLightAdjustXY(CCmdUI* pCmdUI);
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI* pCmdUI);
	afx_msg void OnViewHover();
	afx_msg void OnUpdateViewHover(CCmdUI* pCmdUI);
	afx_msg void OnLightProperties();
	afx_msg void OnUpdateLightProperties(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewShowColors(CCmdUI* pCmdUI);
	afx_msg void OnViewShowColors();
	afx_msg void OnUpdateViewShowShaded(CCmdUI* pCmdUI);
	afx_msg void OnViewShowShaded();
	afx_msg void OnUpdateViewShowTexturesOnly(CCmdUI* pCmdUI);
	afx_msg void OnViewShowTexturesOnly();
	afx_msg void OnUpdateViewShowHeight(CCmdUI* pCmdUI);
	afx_msg void OnViewShowHeight();
	afx_msg void OnEditFlipHorizontal();
	afx_msg void OnEditFlipVertical();
	afx_msg void OnEditRotate90();
	afx_msg void OnEditRotateNegative90();
	afx_msg void OnEditAssignByHeight();
	afx_msg void OnUpdateEditAssignByHeight(CCmdUI* pCmdUI);
	afx_msg void OnEditAssignByRandomRoll();
	afx_msg void OnUpdateEditAssignByRandomRoll(CCmdUI* pCmdUI);
	afx_msg void OnViewShowAppBits();
	afx_msg void OnUpdateViewShowAppBits(CCmdUI* pCmdUI);
	afx_msg void OnEditAssignByAngle();
	afx_msg void OnUpdateEditAssignByAngle(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in eshtview.cpp
inline TerrEditDoc* TerrEditView::GetDocument()
   { return (TerrEditDoc*)m_pDocument; }
#endif

//°±² eof - eshtview.h ²±°
