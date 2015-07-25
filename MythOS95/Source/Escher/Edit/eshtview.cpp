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
// eshtview.cpp
//
// Terrain View and supporting classes.
//
// The view class handles the display of the data contained in an
// TerrEditDoc class.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//                                
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "stdafx.h"
#include "eshtedit.h"

#include "eshtdoc.h"
#include "eshtview.h"
#include "eshtmfrm.h"
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
// TerrEditList                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BEGIN_MESSAGE_MAP(TerrEditList, CListBox)
	//{{AFX_MSG_MAP(TerrEditList)
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditGrid                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BEGIN_MESSAGE_MAP(TerrEditGrid, CWnd)
	//{{AFX_MSG_MAP(TerrEditGrid)
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditRender                                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BEGIN_MESSAGE_MAP(TerrEditRender, CWnd)
	//{{AFX_MSG_MAP(TerrEditRender)
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_SIZE()
	ON_WM_NCRBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭� Texture ListBox Class 旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditList - Constructor                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
TerrEditList::TerrEditList()
{
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditList - Destructor                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
TerrEditList::~TerrEditList()
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditList - OnLButtonDblClk                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditList::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
    CWnd *w = AfxGetMainWnd();

    if ((GetCurSel() == LB_ERR) || nFlags & MK_CONTROL)
        w->SendMessage(WM_COMMAND, ID_SURF_DEFINETXT, NULL);
    else
        w->SendMessage(WM_COMMAND, ID_SURF_EDITTXT, NULL);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditList - OnRButtonDown                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditList::OnRButtonDown(UINT nFlags, CPoint point) 
{
    CRect   rct;
    GetWindowRect (&rct);

    point.x += rct.left;
    point.y += rct.top;

    CMenu   rMenu;

    rMenu.CreatePopupMenu();
    rMenu.AppendMenu(MF_STRING, ID_SURF_DEFINETXT, "Define Texture...");
    rMenu.AppendMenu(MF_STRING, ID_SURF_EDITTXT, "Edit Texture...");
    rMenu.AppendMenu(MF_STRING, ID_SURF_DELETETXT, "Delete Texture");

    ASSERT(AfxGetMainWnd());
    rMenu.TrackPopupMenu( TPM_RIGHTBUTTON | TPM_RIGHTALIGN,
                          point.x, point.y,
                          AfxGetMainWnd());
    rMenu.DestroyMenu();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditList - OnMouseMove                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditList::OnMouseMove(UINT nFlags, CPoint point) 
{
    ((TerrMainFrame *) AfxGetMainWnd())->SetMessageText("Ready");
    
	CListBox::OnMouseMove(nFlags, point);
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭� Terrain Grid Display class 旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditGrid - Constructor                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
TerrEditGrid::TerrEditGrid()
{
    bmi = 0;
    gmap = 0;
    pal = 0;

    zoomshift = 0;
    xpos = ypos = 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditGrid - Destructor                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
TerrEditGrid::~TerrEditGrid()
{
    release_vport();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                            臆� Protected 臆�                             �
// TerrEditGrid - setup_vport                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditGrid::setup_vport(int width, int height)
{
    release_vport();

    if (!width || !height || !pal)
        return;

    bmi = (LPBITMAPINFO) ivory_alloc (sizeof(BITMAPINFOHEADER) + 256*sizeof(WORD));
    ASSERT(bmi);

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
    ASSERT(gmap);

    for(int i=0; i < 256; i++)
    {
        ((WORD *)bmi->bmiColors)[i] = (WORD)i;

    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                            臆� Protected 臆�                             �
// TerrEditGrid - release_vport                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditGrid::release_vport()
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
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditGrid - SetSurfaceSize                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditGrid::SetSurfaceSize(int w, int d)
{
    if (w == width && d == depth)
        return;

    setup_vport(w, d);

    width = w;
    depth = d;

    SetPosition(0,0);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditGrid - UpdateSurfaceColors                                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditGrid::UpdateSurfaceColors()
{
    int             x, y, i;
    esch_surf_type  *sptr;
    byte            *dptr;

    if (!width || !depth || !gmap)
        return;

    TerrEditDoc* pDoc = ((TerrEditView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

    if (!pDoc->surfinfo)
        return;

    if ((width != (pDoc->width >> pDoc->surfshift)) || (depth != (pDoc->depth >> pDoc->surfshift)))
        return;

    ASSERT(pDoc->surfinfo);

    for(y=0, sptr=pDoc->surfinfo, dptr=gmap;
        y < depth; y++)
    {
        for(x=0; x < width; x++)
        {
            if ((sptr->flags & ESCH_SURF_CINDISTXT) && sptr->cind)
            {
                ASSERT((sptr->cind-1) < pDoc->txtNumb);

                *(dptr++) = pDoc->txtColrIndx[(sptr++)->cind-1];
            }
            else
            {
                *(dptr++) = (sptr++)->cind;
            }
        }
        
        i = (width & 0x3);
        if (i)
            dptr += (4 - i);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditGrid - SetZoomLevel                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditGrid::SetZoomLevel(dword zshft)
{
    if (zoomshift != zshft)
    {
        char *str = "Surface Information Grid";
        switch(zshft)
        {
            case 0:
                 break;
            case 1:
                str = "Surface Information Grid - Zoom x 2";
                break;
            case 2:
                str = "Surface Information Grid - Zoom x 4";
                break;
            case 3:
                str = "Surface Information Grid - Zoom x 8";
                break;
            case 4:
                str = "Surface Information Grid - Zoom x 16";
                break;
            default:
                str = "Surface Information Grid - Zoom x ?";
                break;
        }
        SetWindowText(str);
    }

    zoomshift = zshft;

    CRect   rect;
    GetClientRect(&rect);

    int w = ((width << zshft) - rect.right);
    if (w < 0)
        w = 0;
    SetScrollRange(SB_HORZ, 0, w, FALSE);
    if (xpos > w)
        xpos = w;
    SetScrollPos(SB_HORZ, xpos);

    int h = ((depth << zshft) - rect.bottom);
    if (h < 0)
        h = 0;
    SetScrollRange(SB_VERT, 0, h, FALSE);
    if (ypos > h)
        ypos = h;
    SetScrollPos(SB_VERT, ypos);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditGrid - SetPosition                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditGrid::SetPosition(int x, int y, int upscroll)
{
    CRect   rect;
    GetClientRect(&rect);

    if (x < 0)
        x = 0;
    if (y < 0)
        y = 0;

    if (xpos == x && ypos ==y)
        return;

    if (xpos != x)
    {
        int w = ((width << zoomshift) - rect.right);

        if (w < 0)
            w = 0;
        if (x > w)
            x = w;
        if (upscroll)
            SetScrollPos(SB_HORZ, x);
        xpos = x;
    }

    if (ypos != y)
    {   
        int h = ((depth << zoomshift) - rect.bottom);
        if (h < 0)
            h = 0;
        if (y > h)
            y = h;
        if (upscroll)
            SetScrollPos(SB_VERT, y);
        ypos = y;
    }

    RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditGrid - OnPaint                                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditGrid::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

    if (!depth || !gmap || !bmi)
        return;

    TerrEditDoc* pDoc = ((TerrEditView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

//陳� Copy bitmap to window
    SelectPalette(dc.m_hDC,pDoc->hpal,0);
    dc.RealizePalette();
	
    CRect   rect;
    GetClientRect(&rect);

    if ( (((width << zoomshift) - xpos) < rect.left)
        || (((depth << zoomshift) - ypos) < rect.bottom))
        dc.Rectangle(rect.left-1, rect.top-1, rect.right+1, rect.bottom+1);

    if (zoomshift)
    {
        StretchDIBits(dc.m_hDC, -xpos, -ypos, width << zoomshift, depth << zoomshift,
                      0, 0, width, depth,
                      gmap, bmi, DIB_PAL_COLORS, SRCCOPY); 
    }
    else
    {
        SetDIBitsToDevice(dc.m_hDC, -xpos, -ypos, width, depth,
                          0, 0, 0, depth,
                          gmap, bmi, DIB_PAL_COLORS);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditGrid - OnHScroll                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditGrid::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
    switch (nSBCode)
    {
        case SB_LINELEFT:
            SetPosition(xpos-1, ypos);
            break;
        case SB_PAGELEFT:
            SetPosition(xpos-16, ypos);
            break;
        case SB_LINERIGHT:
            SetPosition(xpos+1, ypos);
            break;
        case SB_PAGERIGHT:
            SetPosition(xpos+16, ypos);
            break;
        case SB_THUMBTRACK:
            SetPosition((int)nPos, ypos);
            break;
        case SB_ENDSCROLL:
            SetScrollPos(SB_HORZ, xpos);
            break;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditGrid - OnVScroll                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditGrid::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
    switch (nSBCode)
    {
        case SB_LINEUP:
            SetPosition(xpos, ypos-1);
            break;
        case SB_PAGEUP:
            SetPosition(xpos, ypos-16);
            break;
        case SB_LINEDOWN:
            SetPosition(xpos, ypos+1);
            break;
        case SB_PAGEDOWN:
            SetPosition(xpos, ypos+16);
            break;
        case SB_THUMBTRACK:
            SetPosition(xpos, (int)nPos);
            break;
        case SB_ENDSCROLL:
            SetScrollPos(SB_VERT, ypos);
            break;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditGrid - OnSize                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditGrid::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	
    SetZoomLevel(zoomshift);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditGrid - OnLButtonDown                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditGrid::OnLButtonDown(UINT nFlags, CPoint point) 
{
    int xspos = (point.x + xpos) >> zoomshift;
    int dspos = (point.y + ypos) >> zoomshift;
    
    if (xspos >= width || dspos >= depth)
    {
    	CWnd::OnLButtonDown(nFlags, point);
        return;
    }
	
    TerrEditDoc* pDoc = ((TerrEditView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

    if (nFlags & MK_CONTROL)
    {
        pDoc->UISurfColor(NULL,xspos,dspos);
    }
    else if (nFlags & MK_SHIFT)
    {
        TerrEditView *pView = (TerrEditView*)GetParent();
        ASSERT_VALID(pView);

        int i = pView->GetCurrentTextureSel();

        if (i == LB_ERR)
        {
            MessageBox("Please highlight the texture definition to use in the Texture Definitions window.",
                       "Assign Texture Error",
                       MB_OK | MB_ICONSTOP);
        }
        else if (pDoc->width && pDoc->depth)
        {
            if (xspos >= pDoc->width)
                xspos = pDoc->width-1;
            if (dspos >= pDoc->depth)
                dspos = pDoc->depth-1;

            ASSERT(pDoc->surfinfo);

            esch_surf_type *surf = pDoc->surfinfo + ((dspos*width) + xspos);
         
            surf->flags |= ESCH_SURF_CINDISTXT;
            surf->cind = i+1;

            pDoc->SetModifiedFlag();
            pDoc->UpdateAllViews(NULL,HINT_UPDATECOLR,NULL);
        }
    }
    else
        pDoc->UISurfProperties(NULL,xspos,dspos);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditGrid - OnRButtonDown                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditGrid::OnRButtonDown(UINT nFlags, CPoint point) 
{
    CRect   rct;
    GetWindowRect (&rct);

    point.x += rct.left;
    point.y += rct.top;

//陳� Create menu(s)

    //陳� Zoom Submenu
    CMenu   zoomMenu;
    zoomMenu.CreatePopupMenu();

    zoomMenu.AppendMenu(MF_STRING | ((zoomshift == 0) ? MF_CHECKED : MF_UNCHECKED), ID_VIEW_ZOOM_NORM, "Normal Size");
    zoomMenu.AppendMenu(MF_STRING | ((zoomshift == 1) ? MF_CHECKED : MF_UNCHECKED), ID_VIEW_ZOOM_MED, "Medium Size");
    zoomMenu.AppendMenu(MF_STRING | ((zoomshift == 2) ? MF_CHECKED : MF_UNCHECKED), ID_VIEW_ZOOM_LARGE, "Large Size");
    zoomMenu.AppendMenu(MF_STRING | ((zoomshift == 3) ? MF_CHECKED : MF_UNCHECKED), ID_VIEW_ZOOM_XLARGE, "Extra Large Size");
    zoomMenu.AppendMenu(MF_STRING | ((zoomshift == 4) ? MF_CHECKED : MF_UNCHECKED), ID_VIEW_ZOOM_MEGA, "Mega Size");
        
    //陳� Menu
    CMenu   rMenu;
    rMenu.CreatePopupMenu();
    rMenu.AppendMenu(MF_STRING | MF_POPUP, (unsigned int) zoomMenu.m_hMenu, "Zoom");
    rMenu.AppendMenu(MF_SEPARATOR);
    rMenu.AppendMenu(MF_STRING, ID_TERR_PROP, "Properties...");

//陳� Display and perform action
    ASSERT(AfxGetMainWnd());
    rMenu.TrackPopupMenu( TPM_RIGHTBUTTON | TPM_RIGHTALIGN,
                          point.x, point.y,
                          AfxGetMainWnd());
    rMenu.DestroyMenu();
    zoomMenu.DestroyMenu();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditGrid - OnMouseMove                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditGrid::OnMouseMove(UINT nFlags, CPoint point) 
{  
    char str[32];

    int xspos = (point.x + xpos) >> zoomshift;
    int dspos = (point.y + ypos) >> zoomshift;
    
    if (xspos >= width || dspos >= depth)
    {
        strcpy(str,"Ready");
    }
    else
    {
        sprintf(str,"%d by %d",xspos,dspos);
    }
   
    ((TerrMainFrame *) AfxGetMainWnd())->SetMessageText(str);

	CWnd::OnMouseMove(nFlags, point);
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭� Render Display class 旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditRender - Constructor                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
TerrEditRender::TerrEditRender()
{
    bmi = 0;
    gmap = 0;
    gvp = 0;
    pal = 0;
    bcolor = 0xc0c0c0;
    
    mode = RNDCTRL_NONE;
    mustlight = 1;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditRender - Destructor                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
TerrEditRender::~TerrEditRender()
{
    release_vport();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                            臆� Protected 臆�                             �
// TerrEditRender - setup_vport                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditRender::setup_vport(int width, int height)
{
    release_vport();

    if (!width || !height || !pal)
        return;

    ASSERT(!(width & 0x3));

    bmi = (LPBITMAPINFO) ivory_alloc (sizeof(BITMAPINFOHEADER) + 256*sizeof(WORD));
    ASSERT(bmi);

    memset(bmi, 0, sizeof(*bmi));
    bmi->bmiHeader.biSize         = sizeof (BITMAPINFOHEADER);
    bmi->bmiHeader.biWidth        = width;
    bmi->bmiHeader.biHeight       = -height;
    bmi->bmiHeader.biPlanes       = 1;
    bmi->bmiHeader.biBitCount     = 8;
    bmi->bmiHeader.biCompression  = BI_RGB;
    bmi->bmiHeader.biClrUsed      = 256;
    bmi->bmiHeader.biClrImportant = 256;

    gmap = new BYTE [width * height];
    ASSERT(gmap);

    for(int i=0; i < 256; i++)
    {
        ((WORD *)bmi->bmiColors)[i] = (WORD)i;

    }

    gvp = new VngoVportDD8(width,height,gmap,NULL,pal,
                           VNGO_PHYSICAL_DEV |VNGO_ZBUFFER_DEV | VNGO_BACKBUFFER);
    ASSERT(gvp);

    cam.attach(gvp);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                            臆� Protected 臆�                             �
// TerrEditRender - release_vport                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditRender::release_vport()
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

    if (gvp)
    {
        delete gvp;
        gvp = 0;

        cam.attach(0);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditRender - UpdateRender                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditRender::UpdateRender()
{
    if (!cam.vport)
        return;

    if (mustlight)
    {
        if ((terr.flags & ESCH_TRN_DOTS)
            || cam.flags & (ESCH_CAM_SHADE_FLAT|ESCH_CAM_SHADE_SMOOTH|ESCH_CAM_SHADE_SPECULAR))
            terr.compute_shades(&cam,&light);
        else
            terr.compute_shades(&cam,NULL);

        mustlight=0;
    }

    cam.render(&terr,&light);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditRender - SetMode                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditRender::UpdateBColor()
{
    if (pal)
        cam.set_bcolor(pal->get_index((VngoColor24bit)bcolor));
}

   
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditRender - SetMode                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditRender::SetMode(rnd_ctrl_mode_type m)
{
    if (m == mode)
        return;

    mode = m;

    char *str = "Render View - ?";

    switch (m)
    {
        case RNDCTRL_ROTATEXY:
        case RNDCTRL_LIGHTXY:
            if (m == RNDCTRL_ROTATEXY)
                str = "Render View - Rotate X/Y";
            else
                str = "Render View - Light X/Y";
            SetScrollRange(SB_VERT,-180,180,FALSE);         // Rotate Y
            SetScrollPos(SB_VERT,0);
            SetScrollRange(SB_HORZ,-180,180,FALSE);         // Rotate X
            SetScrollPos(SB_HORZ,0);
            break;
        case RNDCTRL_MOVEXY:
            str = "Render View - Move X/Y";
            SetScrollRange(SB_VERT,-32768,+32768,FALSE);    // Move Y
            SetScrollPos(SB_VERT,0);
            SetScrollRange(SB_HORZ,-32768,+32768,FALSE);    // Move X
            SetScrollPos(SB_HORZ,0);
            break;
        case RNDCTRL_ROTMOVEZ:
            str = "Render View - Rotate/Move Z";
            SetScrollRange(SB_VERT,-32768,+32768,FALSE);    // Move Z
            SetScrollPos(SB_VERT,0);
            SetScrollRange(SB_HORZ,-180,180,FALSE);         // Rotate Z
            SetScrollPos(SB_HORZ,0);
            break;
        case RNDCTRL_LIGHTBRIGHT:
            str = "Render View - Light Intensity";
                                                            // Adjust light brightness
            SetScrollRange(SB_VERT,0,255,FALSE);
            SetScrollPos(SB_VERT,light.get_intensity());
            SetScrollRange(SB_HORZ,0,255,FALSE);
            SetScrollPos(SB_HORZ,light.get_intensity());
            break;
        default:
            EnableScrollBarCtrl(SB_VERT,FALSE);
            EnableScrollBarCtrl(SB_HORZ,FALSE);
            break;
    }

    SetWindowText(str);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditRender - UICameraProperties                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditRender::UICameraProperties()
{
    CameraPropDlg   dlg;

//陳� Setup values
    EschPoint       pt;
    cam.get_position(&pt);    
    dlg.m_xpos = pt.x;
    dlg.m_ypos = pt.y;
    dlg.m_zpos = pt.z;

    dlg.m_bcolor = bcolor;
    dlg.m_fov = cam.fov;
    dlg.m_hither = cam.hither;
    dlg.m_yon = cam.yon;

//陳� Handle Display
    if (dlg.DoModal() == IDOK)
    {
        //陳� Save values
        cam.set_position((Flx16)dlg.m_xpos,(Flx16)dlg.m_ypos,(Flx16)dlg.m_zpos);
        cam.set_fov((Flx16)dlg.m_fov);
        cam.set_hither((Flx16)dlg.m_hither);
        cam.set_yon((Flx16)dlg.m_yon);
        bcolor = dlg.m_bcolor;

        UpdateBColor();
        UpdateRender();
        RedrawWindow();
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditRender - OnPaint                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditRender::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

    TerrEditDoc* pDoc = ((TerrEditView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

//陳� Copy bitmap to window

    SelectPalette(dc.m_hDC,pDoc->hpal,0);
    dc.RealizePalette();
	
    CRect   rect;
    GetClientRect(&rect);

    SetDIBitsToDevice(dc.m_hDC, 0, 0, rect.right, rect.bottom,
                      0, 0, 0, rect.bottom,
                      gmap, bmi, DIB_PAL_COLORS);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditRender - OnHScroll                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditRender::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
    int     t, pos, render=0;
    Flx16   f;
    static  lastpos=0;

    TerrEditDoc* pDoc = ((TerrEditView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

    pos = (int)nPos;

    switch (mode)
    {
        case RNDCTRL_ROTATEXY:                  // Rotate X
            switch (nSBCode)
            {
                case SB_LINELEFT:
                    cam.yaw(-1);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    cam.yaw((Flx16)(-11.25));
                    render=1;
                    break;
                case SB_LINERIGHT:
                    cam.yaw(1);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    cam.yaw((Flx16)(11.25));
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    cam.yaw(pos - lastpos);
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_MOVEXY:                    // Move X
            switch (nSBCode)
            {
                case SB_LINELEFT:
                    cam.move(-pDoc->wscale,0,0);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    cam.move(-pDoc->wscale * (Flx16)3,0,0);
                    render=1;
                    break;
                case SB_LINERIGHT:
                    cam.move(pDoc->wscale,0,0);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    cam.move(pDoc->wscale * (Flx16)3,0,0);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    f = (Flx16)(pos-lastpos) / pDoc->wscale * (Flx16)3;
                    cam.move(f,0,0);
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_ROTMOVEZ:                  // Rotate Z
            switch (nSBCode)
            {
                case SB_LINERIGHT:
                    cam.roll(-1);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    cam.roll((Flx16)(-11.25));
                    render=1;
                    break;
                case SB_LINELEFT:
                    cam.roll(1);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    cam.roll((Flx16)(11.25));
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    cam.roll(lastpos - pos);
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_LIGHTXY:                   // Rotate X
            switch (nSBCode)
            {
                case SB_LINELEFT:
                    light.rotatex(-1);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    light.rotatex((Flx16)(-11.25));
                    render=1;
                    break;
                case SB_LINERIGHT:
                    light.rotatex(1);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    light.rotatex((Flx16)(11.25));
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    light.rotatex(pos - lastpos);
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            if (render)
                MustRelight();
            break;
        case RNDCTRL_LIGHTBRIGHT:               // Intensity
            t=light.get_intensity();
            switch (nSBCode)
            {
                case SB_LINERIGHT:
                    if (t < 255)
                    {
                        t++;
                        render=1;
                        SetScrollPos(SB_HORZ,t);
                        SetScrollPos(SB_VERT,t);
                    }
                    break;
                case SB_PAGERIGHT:
                    if (t < 255)
                    {
                        t += 16;
                        if (t > 255)
                            t = 255;
                        render=1;
                        SetScrollPos(SB_HORZ,t);
                        SetScrollPos(SB_VERT,t);
                    }
                    break;
                case SB_LINELEFT:
                    if (t > 0)
                    {
                        t--;
                        render=1;
                        SetScrollPos(SB_HORZ,t);
                        SetScrollPos(SB_VERT,t);
                    }
                    break;
                case SB_PAGELEFT:
                    if (t > 0)
                    {
                        t -= 16;
                        if (t < 0)
                            t = 0;
                        render=1;
                        SetScrollPos(SB_HORZ,t);
                        SetScrollPos(SB_VERT,t);
                    }
                    break;
                case SB_THUMBTRACK:
                    t = pos;
                    SetScrollPos(SB_HORZ,t);
                    SetScrollPos(SB_VERT,t);
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            if (render)
            {
                light.set_intensity(t);
                MustRelight();
            }
            break;
    }

	CWnd::OnHScroll(nSBCode, nPos, pScrollBar);

    if (render)
    {
        UpdateRender();
        RedrawWindow();
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditRender - OnVScroll                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditRender::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
    int     t, pos, render=0;
    Flx16   f;
    static  lastpos=0;

    TerrEditDoc* pDoc = ((TerrEditView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

    pos = (int)nPos;

    switch (mode)
    {
        case RNDCTRL_ROTATEXY:                  // Rotate Y
            switch (nSBCode)
            {
                case SB_LINEUP:
                    cam.pitch(-1);
                    render=1;
                    break;
                case SB_PAGEUP:
                    cam.pitch((Flx16)(-11.25));
                    render=1;
                    break;
                case SB_LINEDOWN:
                    cam.pitch(1);
                    render=1;
                    break;
                case SB_PAGEDOWN:
                    cam.pitch((Flx16)(11.25));
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    cam.pitch(pos - lastpos);
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_MOVEXY:                    // Move Y
            switch (nSBCode)
            {
                case SB_LINEUP:
                    cam.move(0,pDoc->hscale,0);
                    render=1;
                    break;
                case SB_PAGEUP:
                    cam.move(0,pDoc->hscale * (Flx16)3,0);
                    render=1;
                    break;
                case SB_LINEDOWN:
                    cam.move(0,-pDoc->hscale,0);
                    render=1;
                    break;
                case SB_PAGEDOWN:
                    cam.move(0,-pDoc->hscale * (Flx16)3,0);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    f = (Flx16)(lastpos-pos) / pDoc->hscale * (Flx16)3;
                    cam.move(0,f,0);
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_ROTMOVEZ:                  // Move Z
            switch (nSBCode)
            {
                case SB_LINEUP:
                    cam.move(0,0,pDoc->dscale);
                    render=1;
                    break;
                case SB_PAGEUP:
                    cam.move(0,0,pDoc->dscale * (Flx16)3);
                    render=1;
                    break;
                case SB_LINEDOWN:
                    cam.move(0,0,-pDoc->dscale);
                    render=1;
                    break;
                case SB_PAGEDOWN:
                    cam.move(0,0,-pDoc->dscale * (Flx16)3);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    f = (Flx16)(lastpos-pos) / pDoc->dscale * (Flx16)3;
                    cam.move(0,0,f);
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_LIGHTXY:                   // Rotate Y
            switch (nSBCode)
            {
                case SB_LINEUP:
                    light.rotatey(-1);
                    render=1;
                    break;
                case SB_PAGEUP:
                    light.rotatey((Flx16)(-11.25));
                    render=1;
                    break;
                case SB_LINEDOWN:
                    light.rotatey(1);
                    render=1;
                    break;
                case SB_PAGEDOWN:
                    light.rotatey((Flx16)(11.25));
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    light.rotatey(pos - lastpos);
                    lastpos=pos;
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            if (render)
                MustRelight();
            break;
        case RNDCTRL_LIGHTBRIGHT:               // Intensity
            t=light.get_intensity();
            switch (nSBCode)
            {
                case SB_LINEDOWN:
                    if (t < 255)
                    {
                        t++;
                        render=1;
                        SetScrollPos(SB_VERT,t);
                        SetScrollPos(SB_HORZ,t);
                    }
                    break;
                case SB_PAGEDOWN:
                    if (t < 255)
                    {
                        t += 16;
                        if (t > 255)
                            t = 255;
                        render=1;
                        SetScrollPos(SB_VERT,t);
                        SetScrollPos(SB_HORZ,t);
                    }
                    break;
                case SB_LINEUP:
                    if (t > 0)
                    {
                        t--;
                        render=1;
                        SetScrollPos(SB_VERT,t);
                        SetScrollPos(SB_HORZ,t);
                    }
                    break;
                case SB_PAGEUP:
                    if (t > 0)
                    {
                        t -= 16;
                        if (t < 0)
                            t = 0;
                        render=1;
                        SetScrollPos(SB_VERT,t);
                        SetScrollPos(SB_HORZ,t);
                    }
                    break;
                case SB_THUMBTRACK:
                    t = pos;
                    SetScrollPos(SB_VERT,t);
                    SetScrollPos(SB_HORZ,t);
                    render=1;
                    break;
                case SB_ENDSCROLL:
                    lastpos=0;
                    break;
            }
            if (render)
            {
                light.set_intensity(t);
                MustRelight();
            }
            break;
    }

	CWnd::OnVScroll(nSBCode, nPos, pScrollBar);

    if (render)
    {
        UpdateRender();
        RedrawWindow();
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditRender - OnMouseMove                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditRender::OnMouseMove(UINT nFlags, CPoint point) 
{
    ((TerrMainFrame *) AfxGetMainWnd())->SetMessageText("Ready");

	CWnd::OnMouseMove(nFlags, point);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditRender - OnRButtonDown                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditRender::OnRButtonDown(UINT nFlags, CPoint point) 
{
    int     m;
    CRect   rct;
    GetWindowRect (&rct);

    point.x += rct.left;
    point.y += rct.top;

//陳� Create menu(s)

    //陳� Render Submenu
    CMenu   modeMenu;
    modeMenu.CreatePopupMenu();

    if (terr.flags & ESCH_TRN_DOTS)
        m = 0;
    else if (cam.flags & ESCH_CAM_SHADE_SPECULAR)
        m = 5;
    else if (cam.flags & ESCH_CAM_SHADE_SMOOTH)
        m = 4;
    else if (cam.flags & ESCH_CAM_SHADE_FLAT)
        m = 3;
    else if (cam.flags & ESCH_CAM_SHADE_SOLID)
        m = 2;
    else if (cam.flags & ESCH_CAM_SHADE_WIRE)
        m = 1;

    modeMenu.AppendMenu(MF_STRING | ((m == 0) ? MF_CHECKED : MF_UNCHECKED), ID_VIEW_RND_DOTS, "Dots");
    modeMenu.AppendMenu(MF_STRING | ((m == 1) ? MF_CHECKED : MF_UNCHECKED), ID_VIEW_RND_WIREFRAME, "Wireframe");
    modeMenu.AppendMenu(MF_STRING | ((m == 2) ? MF_CHECKED : MF_UNCHECKED), ID_VIEW_RND_SOLID, "Solid");
    modeMenu.AppendMenu(MF_STRING | ((m == 3) ? MF_CHECKED : MF_UNCHECKED), ID_VIEW_RND_FLAT, "Flat");
    modeMenu.AppendMenu(MF_STRING | ((m == 4) ? MF_CHECKED : MF_UNCHECKED), ID_VIEW_RND_SMOOTH, "Smooth");
    modeMenu.AppendMenu(MF_STRING | ((m == 5) ? MF_CHECKED : MF_UNCHECKED), ID_VIEW_RND_SPECULAR, "Specular");
    modeMenu.AppendMenu(MF_STRING | ((cam.flags & ESCH_CAM_BACKCULL) ? MF_CHECKED : MF_UNCHECKED), ID_VIEW_RND_BACKFACE, "Backface");
    modeMenu.AppendMenu(MF_STRING | ((cam.flags & ESCH_CAM_TEXTURED) ? MF_CHECKED : MF_UNCHECKED), ID_VIEW_RND_TEXTURES, "Textures");
    modeMenu.AppendMenu(MF_STRING | ((cam.flags & ESCH_CAM_PERSPECTIVE) ? MF_CHECKED : MF_UNCHECKED)
                                  | ((cam.flags & ESCH_CAM_TEXTURED) ? MF_ENABLED : (MF_GRAYED)), ID_VIEW_RND_PERSPECTIVE, "Perspective");
        
    //陳� Menu
    CMenu   rMenu;
    rMenu.CreatePopupMenu();
    rMenu.AppendMenu(MF_STRING, ID_VIEW_REFRESH, "Refresh");
    rMenu.AppendMenu(MF_STRING | MF_POPUP, (unsigned int) modeMenu.m_hMenu, "Render");
    rMenu.AppendMenu(MF_SEPARATOR);
    rMenu.AppendMenu(MF_STRING | (mode == RNDCTRL_ROTATEXY) ? MF_CHECKED : MF_UNCHECKED, ID_VIEW_ROTXY, "Rotate X/Y");
    rMenu.AppendMenu(MF_STRING | (mode == RNDCTRL_MOVEXY) ? MF_CHECKED : MF_UNCHECKED, ID_VIEW_MOVEXY, "Move X/Y");
    rMenu.AppendMenu(MF_STRING | (mode == RNDCTRL_ROTMOVEZ) ? MF_CHECKED : MF_UNCHECKED, ID_VIEW_ROTMOVEZ, "Rotate Z/Move Z");
    rMenu.AppendMenu(MF_STRING | (mode == RNDCTRL_LIGHTXY) ? MF_CHECKED : MF_UNCHECKED, ID_LGT_ADJUSTXY, "Adjust X/Y");
    rMenu.AppendMenu(MF_STRING | (mode == RNDCTRL_LIGHTBRIGHT) ? MF_CHECKED : MF_UNCHECKED, ID_LGT_ABRIGHT, "Adjust Intensity");
    rMenu.AppendMenu(MF_SEPARATOR);
    rMenu.AppendMenu(MF_STRING, ID_VIEW_PROP, "Properties...");

//陳� Display and perform action
    ASSERT(AfxGetMainWnd());
    rMenu.TrackPopupMenu( TPM_RIGHTBUTTON | TPM_RIGHTALIGN,
                          point.x, point.y,
                          AfxGetMainWnd());
    rMenu.DestroyMenu();
    modeMenu.DestroyMenu();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditRender - OnNcRButtonDown                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditRender::OnNcRButtonDown(UINT nHitTest, CPoint point) 
{
    if (nHitTest & HTCAPTION)
    {
        CMenu   rMenu;

        rMenu.CreatePopupMenu();
        rMenu.AppendMenu(MF_STRING | MF_CHECKED, ID_VIEW_RENDER, "Render View");

        ASSERT(AfxGetMainWnd());
        rMenu.TrackPopupMenu( TPM_RIGHTBUTTON | TPM_RIGHTALIGN,
                              point.x, point.y,
                              AfxGetMainWnd());
        rMenu.DestroyMenu();
        return;
    }

	CWnd::OnNcRButtonDown(nHitTest, point);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditRender - OnSize                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditRender::OnSize(UINT nType, int cx, int cy) 
{
    setup_vport(cx, cy);

    UpdateRender();

	CWnd::OnSize(nType, cx, cy);
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭  Main View Class 旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - Constructor                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
TerrEditView::TerrEditView()
{
    gridright=0;
    rendertop=0;
    displayrender=1;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - Destructor                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
TerrEditView::~TerrEditView()
{
    if (txtList.m_hWnd)
        txtList.DestroyWindow();
    if (grid.m_hWnd)
        grid.DestroyWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - UpdateMenuStatus                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::UpdateMenuStatus()
{
    int mode;

    if (!AfxGetMainWnd())
        return;

    CMenu *mnu = ((TerrMainFrame *) AfxGetMainWnd())->GetMenu();
    ASSERT(mnu);

//陳� View Menu
    mnu->CheckMenuItem(ID_VIEW_RENDER, MF_BYCOMMAND | ((displayrender) ? MF_CHECKED : MF_UNCHECKED));

    mnu->CheckMenuItem(ID_VIEW_ROTXY, MF_BYCOMMAND | ((rend.GetMode() == RNDCTRL_ROTATEXY) ? MF_CHECKED : MF_UNCHECKED));
    mnu->CheckMenuItem(ID_VIEW_MOVEXY, MF_BYCOMMAND | ((rend.GetMode() == RNDCTRL_MOVEXY) ? MF_CHECKED : MF_UNCHECKED));
    mnu->CheckMenuItem(ID_VIEW_ROTMOVEZ, MF_BYCOMMAND | ((rend.GetMode() == RNDCTRL_ROTMOVEZ) ? MF_CHECKED : MF_UNCHECKED));

    mnu->EnableMenuItem(ID_VIEW_ROTXY, MF_BYCOMMAND | ((displayrender) ? MF_ENABLED : MF_GRAYED));
    mnu->EnableMenuItem(ID_VIEW_MOVEXY, MF_BYCOMMAND | ((displayrender) ? MF_ENABLED : MF_GRAYED));
    mnu->EnableMenuItem(ID_VIEW_ROTMOVEZ, MF_BYCOMMAND | ((displayrender) ? MF_ENABLED : MF_GRAYED));
    mnu->EnableMenuItem(ID_VIEW_PROP, MF_BYCOMMAND | ((displayrender) ? MF_ENABLED : MF_GRAYED));
    
    //陳� Zoom Submenu
    mnu->CheckMenuItem(ID_VIEW_ZOOM_NORM, MF_BYCOMMAND | ((grid.GetZoomLevel() == 0) ? MF_CHECKED : MF_UNCHECKED));
    mnu->CheckMenuItem(ID_VIEW_ZOOM_MED, MF_BYCOMMAND | ((grid.GetZoomLevel() == 1) ? MF_CHECKED : MF_UNCHECKED));
    mnu->CheckMenuItem(ID_VIEW_ZOOM_LARGE, MF_BYCOMMAND | ((grid.GetZoomLevel() == 2) ? MF_CHECKED : MF_UNCHECKED));
    mnu->CheckMenuItem(ID_VIEW_ZOOM_XLARGE, MF_BYCOMMAND | ((grid.GetZoomLevel() == 3) ? MF_CHECKED : MF_UNCHECKED));
    mnu->CheckMenuItem(ID_VIEW_ZOOM_MEGA, MF_BYCOMMAND | ((grid.GetZoomLevel() == 4) ? MF_CHECKED : MF_UNCHECKED));

    //陳� Render Submenu
    mnu->EnableMenuItem(ID_VIEW_RND_DOTS, MF_BYCOMMAND | ((displayrender) ? MF_ENABLED : MF_GRAYED));
    mnu->EnableMenuItem(ID_VIEW_RND_WIREFRAME, MF_BYCOMMAND | ((displayrender) ? MF_ENABLED : MF_GRAYED));
    mnu->EnableMenuItem(ID_VIEW_RND_SOLID, MF_BYCOMMAND | ((displayrender) ? MF_ENABLED : MF_GRAYED));
    mnu->EnableMenuItem(ID_VIEW_RND_FLAT, MF_BYCOMMAND | ((displayrender) ? MF_ENABLED : MF_GRAYED));
    mnu->EnableMenuItem(ID_VIEW_RND_SMOOTH, MF_BYCOMMAND | ((displayrender) ? MF_ENABLED : MF_GRAYED));
    mnu->EnableMenuItem(ID_VIEW_RND_SPECULAR, MF_BYCOMMAND | ((displayrender) ? MF_ENABLED : MF_GRAYED));
    mnu->EnableMenuItem(ID_VIEW_RND_BACKFACE, MF_BYCOMMAND | ((displayrender) ? MF_ENABLED : MF_GRAYED));
    mnu->EnableMenuItem(ID_VIEW_RND_TEXTURES, MF_BYCOMMAND | ((displayrender) ? MF_ENABLED : MF_GRAYED));
    mnu->EnableMenuItem(ID_VIEW_RND_PERSPECTIVE, MF_BYCOMMAND | ((displayrender && (rend.cam.flags & ESCH_CAM_TEXTURED))
                                                 ? MF_ENABLED : MF_GRAYED));

    if (rend.terr.flags & ESCH_TRN_DOTS)
        mode = 0;
    else if (rend.cam.flags & ESCH_CAM_SHADE_SPECULAR)
        mode = 5;
    else if (rend.cam.flags & ESCH_CAM_SHADE_SMOOTH)
        mode = 4;
    else if (rend.cam.flags & ESCH_CAM_SHADE_FLAT)
        mode = 3;
    else if (rend.cam.flags & ESCH_CAM_SHADE_SOLID)
        mode = 2;
    else if (rend.cam.flags & ESCH_CAM_SHADE_WIRE)
        mode = 1;
    mnu->CheckMenuItem(ID_VIEW_RND_DOTS, MF_BYCOMMAND | ((mode == 0) ? MF_CHECKED : MF_UNCHECKED));
    mnu->CheckMenuItem(ID_VIEW_RND_WIREFRAME, MF_BYCOMMAND | ((mode == 1) ? MF_CHECKED : MF_UNCHECKED));    
    mnu->CheckMenuItem(ID_VIEW_RND_SOLID, MF_BYCOMMAND | ((mode == 2) ? MF_CHECKED : MF_UNCHECKED));    
    mnu->CheckMenuItem(ID_VIEW_RND_FLAT, MF_BYCOMMAND | ((mode == 3) ? MF_CHECKED : MF_UNCHECKED));    
    mnu->CheckMenuItem(ID_VIEW_RND_SMOOTH, MF_BYCOMMAND | ((mode == 4) ? MF_CHECKED : MF_UNCHECKED));    
    mnu->CheckMenuItem(ID_VIEW_RND_SPECULAR, MF_BYCOMMAND | ((mode == 5) ? MF_CHECKED : MF_UNCHECKED));    

    mnu->CheckMenuItem(ID_VIEW_RND_BACKFACE, MF_BYCOMMAND | ((rend.cam.flags & ESCH_CAM_BACKCULL) ? MF_CHECKED : MF_UNCHECKED));
    mnu->CheckMenuItem(ID_VIEW_RND_TEXTURES, MF_BYCOMMAND | ((rend.cam.flags & ESCH_CAM_TEXTURED) ? MF_CHECKED : MF_UNCHECKED));
    mnu->CheckMenuItem(ID_VIEW_RND_PERSPECTIVE, MF_BYCOMMAND | ((rend.cam.flags & ESCH_CAM_PERSPECTIVE) ? MF_CHECKED : MF_UNCHECKED));

//陳� Lighting Menu
    mnu->EnableMenuItem(ID_LGT_ADJUSTXY, MF_BYCOMMAND | ((displayrender) ? MF_ENABLED : MF_GRAYED));
    mnu->EnableMenuItem(ID_LGT_ABRIGHT, MF_BYCOMMAND | ((displayrender) ? MF_ENABLED : MF_GRAYED));

    mnu->CheckMenuItem(ID_LGT_ADJUSTXY, MF_BYCOMMAND | ((rend.GetMode() == RNDCTRL_LIGHTXY) ? MF_CHECKED : MF_UNCHECKED));
    mnu->CheckMenuItem(ID_LGT_ABRIGHT, MF_BYCOMMAND | ((rend.GetMode() == RNDCTRL_LIGHTBRIGHT) ? MF_CHECKED : MF_UNCHECKED));
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - Create                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BOOL TerrEditView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
                          DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
//陳� Create base window
    if (!CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext))
        return FALSE;

    CRect rectT;
    rectT.SetRectEmpty();

//陳� Create listbox for textures
    if (!txtList.Create( WS_CHILD
                         | WS_CAPTION
                         | WS_BORDER
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

//陳� Create child window for terrain grid 
    if (!grid.Create(NULL,
                     "Surface Information Grid",
                     WS_CHILD
                     | WS_BORDER
                     | WS_CAPTION
                     | WS_VISIBLE
                     | WS_HSCROLL
                     | WS_VSCROLL,
                     rectT,
                     this,
                     2))
    {
        txtList.DestroyWindow();
        DestroyWindow();
        return FALSE;
    }

//陳� Create child window for render view
    if (!rend.Create(NULL,
                     "Render View",
                     WS_CHILD
                     | WS_BORDER
                     | WS_CAPTION
                     | WS_VISIBLE
                     | WS_HSCROLL
                     | WS_VSCROLL,
                     rectT,
                     this,
                     2))
    {
        txtList.DestroyWindow();
        grid.DestroyWindow();
        DestroyWindow();
        return FALSE;
    }
    rend.SetMode(RNDCTRL_ROTATEXY);

    return TRUE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnDraw                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnDraw(CDC* pDC)
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - AssertValid                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
#ifdef _DEBUG
void TerrEditView::AssertValid() const
{
	CView::AssertValid();
}


void TerrEditView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}


TerrEditDoc* TerrEditView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(TerrEditDoc)));
	return (TerrEditDoc*)m_pDocument;
}
#endif //_DEBUG


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnInitialUpdate                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnInitialUpdate() 
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    grid.pal = &pDoc->palette;
    grid.SetZoomLevel(0);

    rend.pal = &pDoc->palette;
    rend.terr.set_origin(0,0,0);
    rend.terr.flags = ESCH_TRN_DOTS;

    rend.cam.reset();
    rend.cam.set_position( (Flx16)(pDoc->width/2)*pDoc->wscale,
                           0,
                           (Flx16)(pDoc->depth/2)*pDoc->dscale);
    rend.cam.set_flags(ESCH_CAM_TEXTURED | ESCH_CAM_BACKCULL);

	CView::OnInitialUpdate();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnUpdate                                                  �
//                                                                          �
// Hit values: 0 - update all data                                          �
//             otherwise bitmask of sections to update                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
    int i;

    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    UpdateMenuStatus();

//陳� Update terrain info
    if (!lHint || (lHint & HINT_UPDATETERR))
    {
        rend.terr.width = pDoc->width;
        rend.terr.depth = pDoc->depth;
        rend.terr.surfratio = pDoc->surfratio;
        rend.terr.surfshift = pDoc->surfshift;
        rend.terr.wscale = pDoc->wscale;
        rend.terr.dscale = pDoc->dscale;
        rend.terr.hscale = pDoc->hscale;
        rend.terr.hfield = pDoc->hfield;
        rend.terr.surfinfo = pDoc->surfinfo;
        rend.terr.hsurfnorml = pDoc->hsurfnorml;

        grid.SetSurfaceSize(pDoc->width >> pDoc->surfshift, pDoc->depth >> pDoc->surfshift);
        rend.MustRelight();
    }

 //陳� Update terrain surface colors
    if (!lHint || (lHint & HINT_UPDATECOLR))
    {
        grid.UpdateSurfaceColors();
        rend.UpdateBColor();
            
        if (grid.m_hWnd)
            grid.Invalidate();
    }

//陳� Update texture list
    if ((!lHint || (lHint & HINT_UPDATETXTS)) && txtList.m_hWnd)
    {
        txtList.ResetContent();
        for(i=0; i < pDoc->txtNumb; i++)
            txtList.AddString(pDoc->txtName[i]);

        rend.terr.tmax = pDoc->txtNumb;
        rend.terr.txtcolor = pDoc->txtColrIndx;
        rend.terr.txt = pDoc->txtEsch;
    }

//陳� Handle update of render view
    if (rend.m_hWnd && displayrender)
    {
        rend.UpdateRender();
        rend.Invalidate();
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnSize                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnSize(UINT nType, int cx, int cy) 
{
    cx &= ~0x3;

    rendertop = cy / 2;
    gridright = cx - ((rendertop * 4) / 3);
    gridright &= ~0x3;
    gridright += GetSystemMetrics(SM_CXBORDER)*2;

    if (txtList.m_hWnd)
        txtList.MoveWindow(gridright, 0, cx - gridright, (displayrender) ? rendertop : cy);

    if (grid.m_hWnd)
        grid.MoveWindow(0, 0, gridright, cy);

    if (rend.m_hWnd)
        rend.MoveWindow(gridright, rendertop, cx - gridright, cy - rendertop);
       
	CView::OnSize(nType, cx, cy);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewRefresh                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewRefresh() 
{
    txtList.RedrawWindow();

    grid.UpdateSurfaceColors();
    grid.RedrawWindow();

    if (displayrender)
    {
        rend.UpdateRender();
        rend.RedrawWindow();
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewRender                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewRender() 
{
    CMenu *mnu = ((TerrMainFrame *) AfxGetMainWnd())->GetMenu();

    if (mnu->GetMenuState(ID_VIEW_RENDER,MF_CHECKED))
    {
        displayrender=0;
    }
    else
    {
        displayrender=1;
    }

    UpdateMenuStatus();

    if (displayrender)
        rend.UpdateRender();
    rend.ShowWindow((displayrender) ? SW_SHOW : SW_HIDE);

    CRect rect;
    GetClientRect(&rect);
    txtList.MoveWindow(gridright, 0, rect.right - gridright, (displayrender) ? rendertop : rect.bottom);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewRotateXY                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewRotateXY() 
{
    rend.SetMode(RNDCTRL_ROTATEXY);
    UpdateMenuStatus();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewMoveXY                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewMoveXY() 
{
    rend.SetMode(RNDCTRL_MOVEXY);
    UpdateMenuStatus();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewRotateMoveZ                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewRotateMoveZ() 
{
    rend.SetMode(RNDCTRL_ROTMOVEZ);
    UpdateMenuStatus();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewProperties                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewProperties() 
{
    rend.UICameraProperties();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewZoomNormal                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewZoomNormal() 
{
    grid.SetZoomLevel(0);
    UpdateMenuStatus();
    grid.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewZoomMedium                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewZoomMedium() 
{
    grid.SetZoomLevel(1);
    UpdateMenuStatus();
    grid.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewZoomLarge                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewZoomLarge() 
{
    grid.SetZoomLevel(2);
    UpdateMenuStatus();
    grid.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewZoomExLarge                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewZoomExLarge() 
{
    grid.SetZoomLevel(3);
    UpdateMenuStatus();
    grid.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewZoomMega                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewZoomMega() 
{
    grid.SetZoomLevel(4);
    UpdateMenuStatus();
    grid.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewRndDots                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewRndDots() 
{
    rend.terr.flags |= ESCH_TRN_DOTS;

    UpdateMenuStatus();
    rend.UpdateRender();
    rend.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewRndWireframe                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewRndWireframe() 
{
    rend.terr.flags &= ~ESCH_TRN_DOTS;
    rend.cam.flags &= ~(ESCH_CAM_SHADE_SPECULAR
                        | ESCH_CAM_SHADE_SMOOTH
                        | ESCH_CAM_SHADE_FLAT
                        | ESCH_CAM_SHADE_SOLID);
    rend.cam.flags |= ESCH_CAM_SHADE_WIRE;

    UpdateMenuStatus();
    rend.UpdateRender();
    rend.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewRndSolid                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewRndSolid() 
{
    rend.terr.flags &= ~ESCH_TRN_DOTS;
    rend.cam.flags &= ~(ESCH_CAM_SHADE_SPECULAR
                        | ESCH_CAM_SHADE_SMOOTH
                        | ESCH_CAM_SHADE_FLAT);
    rend.cam.flags |= ESCH_CAM_SHADE_WIRE 
                      | ESCH_CAM_SHADE_SOLID;

    UpdateMenuStatus();
    rend.UpdateRender();
    rend.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewRndFlat                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewRndFlat() 
{
    rend.terr.flags &= ~ESCH_TRN_DOTS;
    rend.cam.flags &= ~(ESCH_CAM_SHADE_SPECULAR
                        | ESCH_CAM_SHADE_SMOOTH);
    rend.cam.flags |= ESCH_CAM_SHADE_WIRE
                      | ESCH_CAM_SHADE_SOLID
                      | ESCH_CAM_SHADE_FLAT;
    
    UpdateMenuStatus();
    rend.MustRelight();
    rend.UpdateRender();
    rend.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewRndSmooth                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewRndSmooth() 
{
    rend.terr.flags &= ~ESCH_TRN_DOTS;
    rend.cam.flags &= ~ESCH_CAM_SHADE_SPECULAR;
    rend.cam.flags |= ESCH_CAM_SHADE_WIRE
                      | ESCH_CAM_SHADE_SOLID
                      | ESCH_CAM_SHADE_FLAT
                      | ESCH_CAM_SHADE_SMOOTH;

    UpdateMenuStatus();
    rend.MustRelight();
    rend.UpdateRender();
    rend.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewRndSpecular                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewRndSpecular() 
{
    rend.terr.flags &= ~ESCH_TRN_DOTS;
    rend.cam.flags |= ESCH_CAM_SHADE_WIRE
                      | ESCH_CAM_SHADE_SOLID
                      | ESCH_CAM_SHADE_FLAT
                      | ESCH_CAM_SHADE_SMOOTH
                      | ESCH_CAM_SHADE_SPECULAR;

    UpdateMenuStatus();
    rend.MustRelight();
    rend.UpdateRender();
    rend.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewRndBackface                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewRndBackface() 
{
    rend.cam.flags ^= ESCH_CAM_BACKCULL;

    UpdateMenuStatus();
    rend.UpdateRender();
    rend.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewRndTextures                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewRndTextures() 
{
    rend.cam.flags ^= ESCH_CAM_TEXTURED;

    UpdateMenuStatus();
    rend.UpdateRender();
    rend.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewRndPerspective                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewRndPerspective() 
{
    rend.cam.flags ^= ESCH_CAM_PERSPECTIVE;

    UpdateMenuStatus();
    rend.UpdateRender();
    rend.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnLightAdjustXY                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnLightAdjustXY() 
{
    rend.SetMode(RNDCTRL_LIGHTXY);
    UpdateMenuStatus();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnLightAdjustIntensity                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnLightAdjustIntensity() 
{
    rend.SetMode(RNDCTRL_LIGHTBRIGHT);
    UpdateMenuStatus();
}

//葦� eof - eshtview.cpp 憶�
