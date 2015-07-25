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
// eshtview.cpp
//
// Terrain View class
//
// The view class handles the display of the data contained in an
// TerrEditDoc class.
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
#include "eshtmfrm.h"
#include "eshtdlgx.h"

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
// TerrEditView                                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(TerrEditView, CView)

BEGIN_MESSAGE_MAP(TerrEditView, CView)
	//{{AFX_MSG_MAP(TerrEditView)
	ON_WM_SIZE()
	ON_COMMAND(ID_VIEW_RENDER, OnViewRender)
	ON_COMMAND(ID_VIEW_RND_DOTS, OnViewRndDots)
	ON_COMMAND(ID_VIEW_RND_WIREFRAME, OnViewRndWireframe)
	ON_COMMAND(ID_VIEW_RND_SOLID, OnViewRndSolid)
	ON_COMMAND(ID_VIEW_RND_FLAT, OnViewRndFlat)
	ON_COMMAND(ID_VIEW_RND_SMOOTH, OnViewRndSmooth)
	ON_COMMAND(ID_VIEW_RND_SPECULAR, OnViewRndSpecular)
	ON_COMMAND(ID_VIEW_RND_BACKFACE, OnViewRndBackface)
	ON_COMMAND(ID_VIEW_RND_TEXTURES, OnViewRndTextures)
	ON_COMMAND(ID_VIEW_REFRESH, OnViewRefresh)
	ON_COMMAND(ID_VIEW_RND_PERSPECTIVE, OnViewRndPerspective)
	ON_COMMAND(ID_VIEW_ROTXY, OnViewRotateXY)
	ON_COMMAND(ID_VIEW_MOVEXY, OnViewMoveXY)
	ON_COMMAND(ID_VIEW_ROTMOVEZ, OnViewRotateMoveZ)
	ON_COMMAND(ID_LGT_ADJUSTXY, OnLightAdjustXY)
	ON_COMMAND(ID_LGT_ABRIGHT, OnLightAdjustIntensity)
	ON_COMMAND(ID_VIEW_ZOOM_NORM, OnViewZoomNormal)
	ON_COMMAND(ID_VIEW_ZOOM_LARGE, OnViewZoomLarge)
	ON_COMMAND(ID_VIEW_ZOOM_MED, OnViewZoomMedium)
	ON_COMMAND(ID_VIEW_ZOOM_XLARGE, OnViewZoomExLarge)
	ON_COMMAND(ID_VIEW_PROP, OnViewProperties)
	ON_COMMAND(ID_VIEW_ZOOM_MEGA, OnViewZoomMega)
	ON_UPDATE_COMMAND_UI(ID_VIEW_RENDER, OnUpdateViewRender)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ROTXY, OnUpdateViewRotateXY)
	ON_UPDATE_COMMAND_UI(ID_VIEW_MOVEXY, OnUpdateViewMoveXY)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ROTMOVEZ, OnUpdateViewRotateMoveZ)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PROP, OnUpdateViewProperties)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM_NORM, OnUpdateViewZoomNormal)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM_MED, OnUpdateViewZoomMedium)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM_LARGE, OnUpdateViewZoomLarge)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM_XLARGE, OnUpdateViewZoomExLarge)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM_MEGA, OnUpdateViewZoomMega)
	ON_UPDATE_COMMAND_UI(ID_VIEW_RND_DOTS, OnUpdateViewRndDots)
	ON_UPDATE_COMMAND_UI(ID_VIEW_RND_WIREFRAME, OnUpdateViewRndWireframe)
	ON_UPDATE_COMMAND_UI(ID_VIEW_RND_SOLID, OnUpdateViewRndSolid)
	ON_UPDATE_COMMAND_UI(ID_VIEW_RND_FLAT, OnUpdateViewRndFlat)
	ON_UPDATE_COMMAND_UI(ID_VIEW_RND_SMOOTH, OnUpdateViewRndSmooth)
	ON_UPDATE_COMMAND_UI(ID_VIEW_RND_SPECULAR, OnUpdateViewRndSpecular)
	ON_UPDATE_COMMAND_UI(ID_VIEW_RND_BACKFACE, OnUpdateViewRndBackface)
	ON_UPDATE_COMMAND_UI(ID_VIEW_RND_TEXTURES, OnUpdateViewRndTextures)
	ON_UPDATE_COMMAND_UI(ID_VIEW_RND_PERSPECTIVE, OnUpdateViewRndPerspective)
	ON_UPDATE_COMMAND_UI(ID_LGT_ABRIGHT, OnUpdateLightAdjustIntensity)
	ON_UPDATE_COMMAND_UI(ID_LGT_ADJUSTXY, OnUpdateLightAdjustXY)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, OnUpdateEditUndo)
	ON_COMMAND(ID_VIEW_HOVER, OnViewHover)
	ON_UPDATE_COMMAND_UI(ID_VIEW_HOVER, OnUpdateViewHover)
	ON_COMMAND(ID_LGT_PROP, OnLightProperties)
	ON_UPDATE_COMMAND_UI(ID_LGT_PROP, OnUpdateLightProperties)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SHOW_COLORS, OnUpdateViewShowColors)
	ON_COMMAND(ID_VIEW_SHOW_COLORS, OnViewShowColors)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SHOW_SHADED, OnUpdateViewShowShaded)
	ON_COMMAND(ID_VIEW_SHOW_SHADED, OnViewShowShaded)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SHOW_TXTONLY, OnUpdateViewShowTexturesOnly)
	ON_COMMAND(ID_VIEW_SHOW_TXTONLY, OnViewShowTexturesOnly)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SHOW_HGT, OnUpdateViewShowHeight)
	ON_COMMAND(ID_VIEW_SHOW_HGT, OnViewShowHeight)
	ON_COMMAND(ID_EDIT_FLIPH, OnEditFlipHorizontal)
	ON_COMMAND(ID_EDIT_FLIPV, OnEditFlipVertical)
	ON_COMMAND(ID_EDIT_ROT90, OnEditRotate90)
	ON_COMMAND(ID_EDIT_ROTN90, OnEditRotateNegative90)
	ON_COMMAND(ID_EDIT_ASSIGN_HEIGHT, OnEditAssignByHeight)
	ON_UPDATE_COMMAND_UI(ID_EDIT_ASSIGN_HEIGHT, OnUpdateEditAssignByHeight)
	ON_COMMAND(ID_EDIT_ASSIGN_ROLL, OnEditAssignByRandomRoll)
	ON_UPDATE_COMMAND_UI(ID_EDIT_ASSIGN_ROLL, OnUpdateEditAssignByRandomRoll)
	ON_COMMAND(ID_VIEW_SHOW_APP, OnViewShowAppBits)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SHOW_APP, OnUpdateViewShowAppBits)
	ON_COMMAND(ID_EDIT_ASSIGN_ANGLE, OnEditAssignByAngle)
	ON_UPDATE_COMMAND_UI(ID_EDIT_ASSIGN_ANGLE, OnUpdateEditAssignByAngle)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°° Constructor/Destructor °°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - Constructor                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
TerrEditView::TerrEditView() :
    gridright(0),
    rendertop(0),
    displayrender(1)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - Destructor                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
TerrEditView::~TerrEditView()
{
    if (txtList.m_hWnd)
        txtList.DestroyWindow();
    if (colorList.m_hWnd)
        colorList.DestroyWindow();
    if (grid.m_hWnd)
        grid.DestroyWindow();
    if (rend.m_hWnd)
        rend.DestroyWindow();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Diagnostics °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - AssertValid                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
#ifdef _DEBUG
void TerrEditView::AssertValid() const
{
	CView::AssertValid();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - Dump                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - GetDocument                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
TerrEditDoc* TerrEditView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(TerrEditDoc)));
	return (TerrEditDoc*)m_pDocument;
}
#endif //_DEBUG



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Operations °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - Create                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BOOL TerrEditView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
                          DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
//ÄÄÄ Create base window
    if (!CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext))
        return FALSE;

    CRect rectT;
    rectT.SetRectEmpty();

//ÄÄÄ Create listbox for textures
    if (!txtList.Create( WS_CHILD
                         | WS_CAPTION
                         | WS_BORDER
                         | WS_CLIPSIBLINGS
                         | WS_VSCROLL
                         | LBS_NOINTEGRALHEIGHT
                         | LBS_DISABLENOSCROLL
                         | LBS_USETABSTOPS, rectT,
                         this,
                         1))
    {
        DestroyWindow();
        return FALSE;
    }
    txtList.SetWindowText("Texture Definitions");
    txtList.ShowWindow(SW_SHOW);



//ÄÄÄ Create listbox for textures
    if (!colorList.Create( WS_CHILD
                         | WS_CAPTION
                         | WS_BORDER
                         | WS_CLIPSIBLINGS
                         | WS_VSCROLL
                         | LBS_NOINTEGRALHEIGHT
                         | LBS_DISABLENOSCROLL
                         | LBS_USETABSTOPS, rectT,
                         this,
                         1))
    {
        DestroyWindow();
        return FALSE;
    }
    colorList.SetWindowText("Color Definitions");
    colorList.ShowWindow(SW_SHOW);




//ÄÄÄ Create child window for terrain grid 
    if (!grid.Create(NULL,
                     "Surface Information Grid",
                     WS_CHILD
                     | WS_BORDER
                     | WS_CAPTION
                     | WS_CLIPSIBLINGS
                     | WS_VISIBLE
                     | WS_HSCROLL
                     | WS_VSCROLL,
                     rectT,
                     this,
                     2))
    {
        txtList.DestroyWindow();
        colorList.DestroyWindow();
        DestroyWindow();
        return FALSE;
    }

//ÄÄÄ Create child window for render view
    if (!rend.Create(NULL,
                     "Render View",
                     WS_CHILD
                     | WS_BORDER
                     | WS_CAPTION
                     | WS_CLIPSIBLINGS
                     | WS_VISIBLE
                     | WS_HSCROLL
                     | WS_VSCROLL,
                     rectT,
                     this,
                     2))
    {
        txtList.DestroyWindow();
        colorList.DestroyWindow();
        grid.DestroyWindow();
        DestroyWindow();
        return FALSE;
    }

    return TRUE;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Message Handlers °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - OnDraw                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnDraw(CDC* pDC)
{
    // This window is just a parent for the data windows
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - OnInitialUpdate                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnInitialUpdate() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

//ÄÄÄ Setup grid window
    grid.pal = &pDoc->palette;
    grid.SetZoomLevel(0);
    grid.SetMode(SURFDSP_COLORS);

//ÄÄÄ Setup render window
    rend.pal = &pDoc->palette;
    rend.terr.flags = ESCH_TRN_DOTS;
    rend.SetMode(RNDCTRL_ROTATEXY);

	CView::OnInitialUpdate();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - OnUpdate                                                  ³
//                                                                          ³
// Hit values: 0 - update all data                                          ³
//             otherwise bitmask of sections to update                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

//ÄÄÄ Update terrain info
    if (!lHint || (lHint & HINT_UPDATETERR))
    {
        rend.terr.width = pDoc->width;
        rend.terr.depth = pDoc->depth;
        rend.terr.surfratio = pDoc->surfratio;
        rend.terr.surfshift = pDoc->surfshift;
        rend.terr.set_scale(pDoc->scale);
        rend.terr.hfield = pDoc->hfield;
        rend.terr.htable = pDoc->htable;
        rend.terr.surfinfo = pDoc->surfinfo;
        rend.terr.hsurfnorml = pDoc->hsurfnorml;
        rend.terr.set_origin(pDoc->orgx, pDoc->orgy, pDoc->orgz);
        rend.terr.set_lod(pDoc->lod_medium, pDoc->lod_low);
        rend.terr.flags &= ~ESCH_TRN_LOD;
        if (pDoc->lod_active)
            rend.terr.flags |= ESCH_TRN_LOD;

        grid.SetSurfaceSize(pDoc->width >> pDoc->surfshift, pDoc->depth >> pDoc->surfshift);
    }

//ÄÄÄ Update texture list
    if (!lHint || (lHint & HINT_UPDATETXTS))
    {
        txtList.UpdateContents();
        colorList.UpdateContents();

        rend.terr.tmax = pDoc->txtNumb;
        rend.terr.txtcolor = pDoc->txtColrIndx;
        rend.terr.txt = pDoc->txtEsch;
    }

//ÄÄÄ If lights changed, reset camera mode
    if (!lHint || (lHint & HINT_UPDATELIGHTS))
    {
        rend.SetMode(rend.GetMode());
    }

//ÄÄÄ Update terrain surface colors
    if (!lHint || (lHint & (HINT_UPDATECOLR|HINT_UPDATELIGHTS)))
    {
        grid.UpdateSurfaceColors();
            
        if (grid.m_hWnd)
            grid.Invalidate();
    }

    if (!lHint || (lHint & (HINT_UPDATECLRLIST)))
    {
        txtList.SetCurSel(-1);
    }

    if (!lHint || (lHint & (HINT_UPDATETXTLIST)))
    {
        colorList.SetCurSel(-1);
    }


//ÄÄÄ Handle update of render view
    if (rend.m_hWnd && displayrender)
    {
        rend.UpdateRender();
        rend.Invalidate();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - OnSize                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnSize(UINT nType, int cx, int cy) 
{
    cx &= ~0x3;

    rendertop = cy / 2;
    gridright = cx - ((rendertop * 4) / 3);
    gridright &= ~0x3;
    gridright += GetSystemMetrics(SM_CXBORDER)*2;
    textureright = gridright + ((cx - gridright)/2);

    if (txtList.m_hWnd)
        txtList.MoveWindow(gridright, 0, (cx - gridright)/2, (displayrender) ? rendertop : cy);

    if (colorList.m_hWnd)
        colorList.MoveWindow(textureright, 0, (cx - gridright)/2, (displayrender) ? rendertop : cy);

    if (grid.m_hWnd)
        grid.MoveWindow(0, 0, gridright, cy);

    if (rend.m_hWnd)
        rend.MoveWindow(gridright, rendertop, cx - gridright, cy - rendertop);
       
	CView::OnSize(nType, cx, cy);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)EditUndo                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnEditUndo() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->PopUndo();
}

void TerrEditView::OnUpdateEditUndo(CCmdUI* pCmdUI) 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable(pDoc->undo_valid ? 1 : 0);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - OnEditFlipHorizontal                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnEditFlipHorizontal() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->Flip(TRUE);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - OnEditFlipVertical                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnEditFlipVertical() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->Flip(FALSE);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - OnEditRotate90                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnEditRotate90() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->Rotate(TRUE);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - OnEditRotateNegative90                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnEditRotateNegative90() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->Rotate(FALSE);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)EditAssignByHeight                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnEditAssignByHeight() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    HeightToolDlg   dlg;
    dlg.setup(pDoc);

    if (dlg.DoModal()==IDCANCEL)
        return;

    ASSERT(dlg.count > 0);
    grid.AssignByHeight(dlg.count,
                        dlg.tc, dlg.istxt, dlg.heights,
                        Flx16(dlg.m_height_stop),
                        dlg.area, dlg.m_preserve);
}

void TerrEditView::OnUpdateEditAssignByHeight(CCmdUI* pCmdUI) 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable( (pDoc->txtNumb+pDoc->colorNumb > 0) ? 1 : 0 );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)EditAssignByRandomRoll                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnEditAssignByRandomRoll() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    RandomToolDlg   dlg;
    dlg.setup(pDoc);

    if (dlg.DoModal()==IDCANCEL)
        return;

    ASSERT(dlg.count > 0);
    grid.AssignByRandomRoll(dlg.count,
                            dlg.tc, dlg.istxt, dlg.chances,
                            dlg.m_elvcutoff,
                            Flx16(dlg.m_elvlow), Flx16(dlg.m_elvhigh),
                            dlg.area, dlg.m_preserve);
}

void TerrEditView::OnUpdateEditAssignByRandomRoll(CCmdUI* pCmdUI) 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable( (pDoc->txtNumb+pDoc->colorNumb > 0) ? 1 : 0 );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)EditAssignByAngle                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnEditAssignByAngle() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    AngleToolDlg   dlg;
    dlg.setup(pDoc);

    if (dlg.DoModal()==IDCANCEL)
        return;

    ASSERT(dlg.count > 0);
    grid.AssignByAngle(dlg.count,
                       dlg.tc, dlg.istxt, dlg.angles,
                       Flx16(dlg.m_angle_stop),
                       dlg.m_elvcutoff,
                       Flx16(dlg.m_elvlow), Flx16(dlg.m_elvhigh),
                       dlg.area, dlg.m_preserve);
}

void TerrEditView::OnUpdateEditAssignByAngle(CCmdUI* pCmdUI) 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable( (pDoc->txtNumb+pDoc->colorNumb > 0) ? 1 : 0 );
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - OnViewRefresh                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnViewRefresh() 
{
    txtList.RedrawWindow();
    colorList.RedrawWindow();

    grid.UpdateSurfaceColors();
    grid.RedrawWindow();

    if (displayrender)
    {
        rend.UpdateRender();
        rend.RedrawWindow();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewRender                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewRender(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck(displayrender);
}

void TerrEditView::OnViewRender() 
{
    displayrender = !displayrender;

    if (displayrender)
        rend.UpdateRender();
    rend.ShowWindow((displayrender) ? SW_SHOW : SW_HIDE);

    CRect rect;
    GetClientRect(&rect);
    int cx = rect.right - rect.left + 1;
    int cy = rect.bottom - rect.top + 1;

//    txtList.MoveWindow(gridright, 0, rect.right - gridright, (displayrender) ? rendertop : rect.bottom);
    txtList.MoveWindow(gridright, 0, (cx - gridright)/2, (displayrender) ? rendertop : cy);

    colorList.MoveWindow(textureright, 0, (cx - gridright)/2, (displayrender) ? rendertop : cy);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewHover                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewHover(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck((rend.GetMode() == RNDCTRL_HOVER) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewHover() 
{
    rend.SetMode(RNDCTRL_HOVER);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewRotateXY                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewRotateXY(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck((rend.GetMode() == RNDCTRL_ROTATEXY) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRotateXY() 
{
    rend.SetMode(RNDCTRL_ROTATEXY);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewMoveXY                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewMoveXY(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck((rend.GetMode() == RNDCTRL_MOVEXY) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewMoveXY() 
{
    rend.SetMode(RNDCTRL_MOVEXY);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewRotateMoveZ                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewRotateMoveZ(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck((rend.GetMode() == RNDCTRL_ROTMOVEZ) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRotateMoveZ() 
{
    rend.SetMode(RNDCTRL_ROTMOVEZ);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewProperties                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewProperties(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewProperties() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->UICameraProperties(this);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewZoomNormal                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewZoomNormal(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck((grid.GetZoomLevel() == 0) ? 1 : 0);
}

void TerrEditView::OnViewZoomNormal() 
{
    grid.SetZoomLevel(0);
    grid.RedrawWindow();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewZoomMedium                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewZoomMedium(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck((grid.GetZoomLevel() == 1) ? 1 : 0);
}

void TerrEditView::OnViewZoomMedium() 
{
    grid.SetZoomLevel(1);
    grid.RedrawWindow();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewZoomLarge                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewZoomLarge(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck((grid.GetZoomLevel() == 2) ? 1 : 0);
}

void TerrEditView::OnViewZoomLarge() 
{
    grid.SetZoomLevel(2);
    grid.RedrawWindow();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewZoomExLarge                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewZoomExLarge(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck((grid.GetZoomLevel() == 3) ? 1 : 0);
}

void TerrEditView::OnViewZoomExLarge() 
{
    grid.SetZoomLevel(3);
    grid.RedrawWindow();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewZoomMega                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewZoomMega(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck((grid.GetZoomLevel() == 4) ? 1 : 0);
}

void TerrEditView::OnViewZoomMega() 
{
    grid.SetZoomLevel(4);
    grid.RedrawWindow();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewShowColors                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewShowColors(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck((grid.GetMode() == SURFDSP_COLORS) ? 1 : 0);
}

void TerrEditView::OnViewShowColors() 
{
    grid.SetMode(SURFDSP_COLORS);	
    grid.RedrawWindow();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewShowShaded                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewShowShaded(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck((grid.GetMode() == SURFDSP_SHADED) ? 1 : 0);
}

void TerrEditView::OnViewShowShaded() 
{
    grid.SetMode(SURFDSP_SHADED);	
    grid.RedrawWindow();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewShowHeight                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewShowHeight(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck((grid.GetMode() == SURFDSP_HGT) ? 1 : 0);
}

void TerrEditView::OnViewShowHeight() 
{
    grid.SetMode(SURFDSP_HGT);	
    grid.RedrawWindow();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewShowTexturesOnly                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewShowTexturesOnly(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck((grid.GetMode() == SURFDSP_TXTONLY) ? 1 : 0);
}

void TerrEditView::OnViewShowTexturesOnly() 
{
    grid.SetMode(SURFDSP_TXTONLY);	
    grid.RedrawWindow();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewShowAppBits                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewShowAppBits(CCmdUI* pCmdUI) 
{
    pCmdUI->SetCheck((grid.GetMode() == SURFDSP_APPBITS) ? 1 : 0);
}

void TerrEditView::OnViewShowAppBits() 
{
    grid.SetMode(SURFDSP_APPBITS);	
    grid.RedrawWindow();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewRndDots                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewRndDots(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck((rend.terr.flags & ESCH_TRN_DOTS) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRndDots() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    rend.terr.flags |= ESCH_TRN_DOTS;

    pDoc->cam.flags &= ~(ESCH_CAM_SHADE_SPECULAR
                         | ESCH_CAM_SHADE_SMOOTH);
    pDoc->cam.flags |= ESCH_CAM_SHADE_WIRE
                       | ESCH_CAM_SHADE_SOLID
                       | ESCH_CAM_SHADE_FLAT;

    pDoc->SetModifiedFlag();
    pDoc->SetLightsModifiedFlag();
    pDoc->UpdateAllViews(NULL, HINT_UPDATELIGHTS, NULL);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewRndWireframe                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewRndWireframe(CCmdUI* pCmdUI) 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

   	pCmdUI->SetCheck( (!(rend.terr.flags & ESCH_TRN_DOTS)
	                   && (pDoc->cam.flags & (ESCH_CAM_SHADE_WIRE
                                              | ESCH_CAM_SHADE_SOLID
                                              | ESCH_CAM_SHADE_FLAT
                                              | ESCH_CAM_SHADE_SMOOTH
                                              | ESCH_CAM_SHADE_SPECULAR))==ESCH_CAM_SHADE_WIRE) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRndWireframe() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    rend.terr.flags &= ~ESCH_TRN_DOTS;
    pDoc->cam.flags &= ~(ESCH_CAM_SHADE_SPECULAR
                         | ESCH_CAM_SHADE_SMOOTH
                         | ESCH_CAM_SHADE_FLAT
                         | ESCH_CAM_SHADE_SOLID);
    pDoc->cam.flags |= ESCH_CAM_SHADE_WIRE;

    pDoc->SetModifiedFlag();
    pDoc->SetLightsModifiedFlag();
    pDoc->UpdateAllViews(NULL, HINT_UPDATELIGHTS, NULL);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewRndSolid                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewRndSolid(CCmdUI* pCmdUI) 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

   	pCmdUI->SetCheck( (!(rend.terr.flags & ESCH_TRN_DOTS)
	                   && (pDoc->cam.flags & (ESCH_CAM_SHADE_SOLID
                                              | ESCH_CAM_SHADE_FLAT
                                              | ESCH_CAM_SHADE_SMOOTH
                                              | ESCH_CAM_SHADE_SPECULAR))==ESCH_CAM_SHADE_SOLID) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRndSolid() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    rend.terr.flags &= ~ESCH_TRN_DOTS;
    pDoc->cam.flags &= ~(ESCH_CAM_SHADE_SPECULAR
                         | ESCH_CAM_SHADE_SMOOTH
                         | ESCH_CAM_SHADE_FLAT);
    pDoc->cam.flags |= ESCH_CAM_SHADE_WIRE 
                       | ESCH_CAM_SHADE_SOLID;
                  
    pDoc->SetModifiedFlag();
    pDoc->SetLightsModifiedFlag();
    pDoc->UpdateAllViews(NULL, HINT_UPDATELIGHTS, NULL);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewRndFlat                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewRndFlat(CCmdUI* pCmdUI) 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

   	pCmdUI->SetCheck( (!(rend.terr.flags & ESCH_TRN_DOTS)
	                   && (pDoc->cam.flags & (ESCH_CAM_SHADE_FLAT
                                              | ESCH_CAM_SHADE_SMOOTH
                                              | ESCH_CAM_SHADE_SPECULAR))==ESCH_CAM_SHADE_FLAT) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRndFlat() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    rend.terr.flags &= ~ESCH_TRN_DOTS;
    pDoc->cam.flags &= ~(ESCH_CAM_SHADE_SPECULAR
                         | ESCH_CAM_SHADE_SMOOTH);
    pDoc->cam.flags |= ESCH_CAM_SHADE_WIRE
                       | ESCH_CAM_SHADE_SOLID
                       | ESCH_CAM_SHADE_FLAT;
    
    pDoc->SetModifiedFlag();
    pDoc->SetLightsModifiedFlag();
    pDoc->UpdateAllViews(NULL, HINT_UPDATELIGHTS, NULL);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewRndSmooth                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewRndSmooth(CCmdUI* pCmdUI) 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

   	pCmdUI->SetCheck( (!(rend.terr.flags & ESCH_TRN_DOTS)
	                   && (pDoc->cam.flags & (ESCH_CAM_SHADE_SMOOTH
                                              | ESCH_CAM_SHADE_SPECULAR))==ESCH_CAM_SHADE_SMOOTH) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRndSmooth() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    rend.terr.flags &= ~ESCH_TRN_DOTS;
    pDoc->cam.flags &= ~ESCH_CAM_SHADE_SPECULAR;
    pDoc->cam.flags |= ESCH_CAM_SHADE_WIRE
                       | ESCH_CAM_SHADE_SOLID
                       | ESCH_CAM_SHADE_FLAT
                       | ESCH_CAM_SHADE_SMOOTH;

    pDoc->SetModifiedFlag();
    pDoc->SetLightsModifiedFlag();
    pDoc->UpdateAllViews(NULL, HINT_UPDATELIGHTS, NULL);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewRndSpecular                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewRndSpecular(CCmdUI* pCmdUI) 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

   	pCmdUI->SetCheck( (!(rend.terr.flags & ESCH_TRN_DOTS)
	                   && (pDoc->cam.flags & ESCH_CAM_SHADE_SPECULAR)) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRndSpecular() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    rend.terr.flags &= ~ESCH_TRN_DOTS;
    pDoc->cam.flags |= ESCH_CAM_SHADE_WIRE
                       | ESCH_CAM_SHADE_SOLID
                       | ESCH_CAM_SHADE_FLAT
                       | ESCH_CAM_SHADE_SMOOTH
                       | ESCH_CAM_SHADE_SPECULAR;

    pDoc->SetModifiedFlag();
    pDoc->SetLightsModifiedFlag();
    pDoc->UpdateAllViews(NULL, HINT_UPDATELIGHTS, NULL);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewRndBackface                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewRndBackface(CCmdUI* pCmdUI) 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

   	pCmdUI->SetCheck( (pDoc->cam.flags & ESCH_CAM_BACKCULL) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRndBackface() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->cam.flags ^= ESCH_CAM_BACKCULL;

    rend.UpdateRender();
    rend.RedrawWindow();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewRndTextures                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewRndTextures(CCmdUI* pCmdUI) 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

   	pCmdUI->SetCheck( (pDoc->cam.flags & ESCH_CAM_TEXTURED) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRndTextures() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->cam.flags ^= ESCH_CAM_TEXTURED;

    rend.UpdateRender();
    rend.RedrawWindow();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)ViewRndPerspective                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateViewRndPerspective(CCmdUI* pCmdUI) 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

   	pCmdUI->SetCheck( (pDoc->cam.flags & ESCH_CAM_PERSPECTIVE) ? 1 : 0);
    pCmdUI->Enable( (displayrender && (pDoc->cam.flags & ESCH_CAM_TEXTURED)) ? TRUE : FALSE);
}

void TerrEditView::OnViewRndPerspective() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->cam.flags ^= ESCH_CAM_PERSPECTIVE;

    rend.UpdateRender();
    rend.RedrawWindow();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)LightAdjustXY                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateLightAdjustXY(CCmdUI* pCmdUI) 
{
   	pCmdUI->SetCheck( (rend.GetMode() == RNDCTRL_LIGHTXY) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnLightAdjustXY() 
{
    rend.SetMode(RNDCTRL_LIGHTXY);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)LightAdjustIntensity                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateLightAdjustIntensity(CCmdUI* pCmdUI) 
{
   	pCmdUI->SetCheck( (rend.GetMode() == RNDCTRL_LIGHTBRIGHT) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnLightAdjustIntensity() 
{
    rend.SetMode(RNDCTRL_LIGHTBRIGHT);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditView - On(Update)LightProperties                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditView::OnUpdateLightProperties(CCmdUI* pCmdUI) 
{
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnLightProperties() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->UILightProperties(this);
}

//°±² eof - eshtview.cpp ²±°
