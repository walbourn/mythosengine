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
// PalTovw.cpp
//
// PalTool view class.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "stdafx.h"
#include "paltool.h"

#include "paltodoc.h"
#include "paltovw.h"
#include "bezier.h"
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

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

IMPLEMENT_DYNCREATE(CPalToolView, CView)

BEGIN_MESSAGE_MAP(CPalToolView, CView)
        //{{AFX_MSG_MAP(CPalToolView)
        ON_WM_LBUTTONDOWN()
        ON_WM_LBUTTONUP()
        ON_WM_MOUSEMOVE()
        ON_COMMAND(IDM_OPTIONS_BEZIER, OnOptionsBezier)
        ON_UPDATE_COMMAND_UI(IDM_OPTIONS_BEZIER, OnUpdateOptionsBezier)
        ON_COMMAND(IDM_OPTIONS_LINEAR, OnOptionsLinear)
        ON_UPDATE_COMMAND_UI(IDM_OPTIONS_LINEAR, OnUpdateOptionsLinear)
        ON_COMMAND(IDM_OPTIONS_QUADRATIC, OnOptionsQuadratic)
        ON_UPDATE_COMMAND_UI(IDM_OPTIONS_QUADRATIC, OnUpdateOptionsQuadratic)
        ON_COMMAND(ID_EDIT_NEW_EMPTY, OnEditNewEmpty)
        ON_COMMAND(ID_EDIT_NEW_GEN, OnEditNewGeneral)
        ON_COMMAND(ID_EDIT_NEW_ORIGGEN, OnEditNewGeneralOld)
        ON_COMMAND(ID_EDIT_NEW_GREYSCALE, OnEditNewGreyscale)
        ON_COMMAND(ID_EDIT_NEW_332, OnEditNew332)
        ON_COMMAND(ID_EDIT_NEW_RGBG, OnEditNewRGBG)
        ON_COMMAND(ID_EDIT_PALETTE, OnEditPalette)
        ON_COMMAND(ID_EDIT_PROP, OnEditProperties)
        ON_WM_RBUTTONDOWN()
        ON_COMMAND(ID_EDIT_NEW_SPC1, OnEditNewSpecial1)
        ON_COMMAND(ID_VIEW_REFRESH, OnViewRefresh)
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// clip_to
//
// utility to restrict a number to an inclusive range
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
inline int clip_to (int x, int low, int high)
{
        ASSERT (low <= high);

        if (x < low)
                return low;
        else if (x > high)
                return high;
        else
                return x;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// draw_bezier
//
// This is a function closure for use with the bezier()
// function, which will use this particular closure to
// draw the bezier on the supplied CDC.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
class draw_bezier: public BezierClosure
{
        CDC     *pDC;

public:
        draw_bezier (CDC *_pDC): pDC (_pDC) { }

        void operator () (int x, int y)
        {
                pDC->SetPixel (x, y, RGB (0, 0, 0));
        }
};


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// draw_quadratic
//
// This function iterates a quadratic
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
static void draw_quadratic (CDC *pDC,
                            const int x1,   const int x2,
                                            const Flx16 u0, const Flx16 v0,
                                            const Flx16 u1, const Flx16 v1,
                                        const Flx16 u2, const Flx16 v2)
{
        const Flx16 flx_2       (2);
        const Flx16 flx_4       (4);
        const Flx16 flx_n3      (-3);
        const Flx16 dx          (x2 - x1);

        // Calculate the horizontal step values
        const Flx16 a1  = (flx_n3 * u0 + flx_4 * u1 - u2) / dx;
        const Flx16 a2  = flx_2 * (u0 - flx_2 * u1 + u2) / (dx * dx);
        const Flx16 UD2 = flx_2 * a2;
        Flx16 UD1 = a1 + a2;

        // Calculate the vertical step values
        const Flx16 b1  = (flx_n3 * v0 + flx_4 * v1 - v2) / dx;
        const Flx16 b2  = flx_2 * (v0 - flx_2 * v1 + v2) / (dx * dx);
        const Flx16 VD2 = flx_2 * b2;
        Flx16 VD1 = b1 + b2;

        // Now, run the steps
        Flx16 u = u0;
        Flx16 v = v0;
        for (int x = x1; x < x2; x++)
        {
                pDC->SetPixel (u, v, RGB(0,0,0));
                u += UD1;
                v += VD1;
                UD1 += UD2;
                VD1 += VD2;
        }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°° Constructor/Destructor °°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
CPalToolView::CPalToolView():
        drag_mode (DRAG_NONE),
        shade_env_divisions (256),
        shade_env (shade_env_divisions / 3 * 2, shade_env_divisions / 2)
{
        dotted.CreatePen (PS_DOT, 1, RGB(0,0,0));
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
CPalToolView::~CPalToolView()
{
        if (shade_bits)
                free (shade_bits);
        if (bmi)
                free (bmi);
        if (shade_vp)
                delete shade_vp;
#if 0
        if (haze_bits)
                free (haze_bits);
        if (haze_vp)
                delete haze_vp;
#endif
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Diagnostics °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#ifdef _DEBUG
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - AssertValid
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::AssertValid() const
{
        CView::AssertValid();
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - Dump
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::Dump(CDumpContext& dc) const
{
        CView::Dump(dc);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - GetDocument
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
CPalToolDoc* CPalToolView::GetDocument() // non-debug version is inline
{
        ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPalToolDoc)));
        return (CPalToolDoc*)m_pDocument;
}
#endif //_DEBUG



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Operations °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - ShadePoint
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
CRect CPalToolView::ShadePoint () const
{
        CPoint  midpt  (shade_env.x * ENV_WIDTH / shade_env_divisions,
                                        shade_env.y * ENV_HEIGHT / shade_env_divisions);

        return CRect (midpt.x - 2, midpt.y - 2, midpt.x + 3, midpt.y + 3);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - DrawShadeEnv
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::DrawShadeEnv (CDC *pDC)
{
        const CPalToolDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        POINT pts[4];

        // Create a function closure for drawing bezier functions
        draw_bezier bez (pDC);

        // Draw the shade envelope box
        CSize   env_height (0, ENV_HEIGHT);
        CRect   rct (0, 0, ENV_WIDTH + 2, ENV_HEIGHT + 2);
        CPoint  midpt  (pDoc->shade_env_break() * ENV_WIDTH / shade_env_divisions,
                                        pDoc->shade_env_break() * ENV_HEIGHT / shade_env_divisions);

        // Draw the shade envelope
        pDC->Rectangle (&rct);

        // Draw the "color divider"
        CPen *old_pen = pDC->SelectObject (&dotted);
        pDC->MoveTo (midpt.x, rct.top);
        pDC->LineTo (midpt.x, rct.bottom);
        pDC->SelectObject (old_pen);

        // Draw the curve (based on quadratic equation:
        // y = ax^2 + bx + c
        CPoint envp (shade_env.x * ENV_WIDTH / shade_env_divisions,
                                 shade_env.y * ENV_HEIGHT / shade_env_divisions);

        switch (pDoc->curve_mode)
        {
        case CPalToolDoc::QUADRATIC:

                    // Draw the control point
                    pDC->Rectangle (ShadePoint ());

                    draw_quadratic (pDC, 0, ENV_WIDTH,

                                                    0,
                                                    ENV_HEIGHT,

                                                    envp.x,
                                                    envp.y,

                                                    midpt.x,
                                                    ENV_HEIGHT/2 /* - midpt.y*/);
                    break;

            case CPalToolDoc::BEZIER:
                // Draw the control point
                    pDC->Rectangle (ShadePoint ());

                    pts[0].x = 0;
                    pts[0].y = ENV_HEIGHT;
                    pts[1].x = envp.x;
                    pts[1].y = envp.y;
                    pts[2].x = envp.x;
                    pts[2].y = envp.y;
                    pts[3].x = midpt.x;
                    pts[3].y = ENV_HEIGHT/2;

                    bezier (bez, pts);
                    //::PolyBezier (pDC->m_hDC, pts, 4);
                    break;

        case CPalToolDoc::LINEAR:
                    // Draw the control point
                    //pDC->Rectangle ();
                    pDC->MoveTo (0, ENV_HEIGHT);
                    pDC->LineTo (pDoc->shade_env_break() * ENV_HEIGHT / shade_env_divisions, envp.y);
                    break;
        }

        // below split
        if (midpt.x == 0)
                envp.x = ENV_WIDTH - 1;
        else
                envp.x = ENV_WIDTH - (envp.x * (ENV_WIDTH - midpt.x) / midpt.x);
        //envp.y = (ENV_HEIGHT - envp.y) * (ENV_WIDTH - midpt.x) / (midpt.x);
        envp.y = ENV_HEIGHT - envp.y;

        switch (pDoc->curve_mode)
        {
            case CPalToolDoc::QUADRATIC:
                    draw_quadratic (pDC, 0, ENV_WIDTH,

                                                    ENV_WIDTH,
                                                    0,

                                                    envp.x,
                                                    envp.y,

                                                    midpt.x,
                                                    ENV_HEIGHT/2);
                    pDC->Rectangle (envp.x + 2,
                                                    envp.y + 2,
                                                    envp.x - 2,
                                                    envp.y - 2);
                    break;

            case CPalToolDoc::BEZIER:
                    pts[0].x= ENV_WIDTH;
                    pts[0].y= 0;
                    pts[1].x= envp.x;
                    pts[1].y= envp.y;
                    pts[2].x= envp.x;
                    pts[2].y= envp.y;
                    pts[3].x= midpt.x;
                    pts[3].y= ENV_HEIGHT/2;

                    bezier (bez, pts);
                    //::PolyBezier (pDC->m_hDC, pts, 4);

                    pDC->Rectangle (envp.x + 2,
                                                    envp.y + 2,
                                                    envp.x - 2,
                                                    envp.y - 2);
                    break;

            case CPalToolDoc::LINEAR:
                    pDC->LineTo (ENV_WIDTH, 0);
                    break;
        }

        // Display the shade midpoint position
        CString str;
        str.Format ("%d", pDoc->shade_env_break());
        pDC->TextOut (rct.left + 1, rct.top + 1, str);

        // Draw the endpoint data
        str.Format ("Bk+%d%%", 10);
        pDC->SetTextAlign (TA_LEFT);
        pDC->TextOut (rct.left, rct.bottom+1, str);

        str.Format ("Wt-%d%%", 10);
        pDC->SetTextAlign (TA_RIGHT);
        pDC->TextOut (rct.right-1, rct.bottom+1, str);
}


#if 0
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - DrawHazeEnv
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::DrawHazeEnv (CDC *pDC)
{
}
#endif


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - DrawShades
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::DrawShades ()
{
        const CPalToolDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        int     i, j;

        shade_vp->reset (pDoc->base_pal->get_index (VngoColor24bit (0,0,0)));

        // Fill the image with color bands
        VngoPoint       pt;

        int height = pDoc->shade_env_break() * ENV_HEIGHT / shade_env_divisions;
        Flx16 shade_scaler = Flx16 (shade_env_divisions) / Flx16 (ENV_HEIGHT);

        // Draw down shades
        for (j = 0; j < height; j++)
        {
                for (i = 0; i < 256;i++)
                {
                        pt.clr = i;
                        pt.shade = Flx16 (j) * shade_scaler;
                        pt.x = i;
                        pt.y = j;

                        shade_vp->pixel(&pt);
                }
        }

        // Draw center band (the "real" colors)
        for (i = 0; i < 256;i++)
        {
                pt.clr = i;
                pt.shade = pDoc->shade_env_break();
                pt.x = i;
                pt.y = height + 1;

                shade_vp->pixel(&pt);
        }

        // Draw speculars
        for (j = height + 3; j < ENV_HEIGHT + 2; j++)
        {
                for (i = 0; i < 256;i++)
                {
                        pt.clr = i;
                        pt.shade = Flx16 (j) * shade_scaler;
                        pt.x = i;
                        pt.y = j;

                        shade_vp->pixel(&pt);
                }
        }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Message Handlers °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnDraw
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnDraw(CDC* pDC)
{
        const CPalToolDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

    // Force palette
        pDC->SelectPalette (&pal, this != GetFocus());
        pDC->RealizePalette ();

        // Draw the shade envelope box
        DrawShadeEnv (pDC);

        // Draw the shade palette image
    SetDIBitsToDevice (pDC->m_hDC,
                                   ENV_WIDTH + 2, 0,
                                   shade_vp->vbuff.width, shade_vp->vbuff.height,
                       0, 0, 0, shade_vp->vbuff.height,
                       shade_bits, bmi, DIB_PAL_COLORS);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnInitialUpdate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnInitialUpdate()
{
        //CView::OnInitialUpdate();

        const CPalToolDoc       *pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        const VngoHwPal *hw_pal = &((const VngoPal8 *)pDoc->base_pal)->hw_pal;
        int     i;

        shade_bits = (BYTE *)malloc (VP_WIDTH * (ENV_HEIGHT+2));

        bmi  = (LPBITMAPINFO)malloc (sizeof (BITMAPINFOHEADER) + 256*sizeof (WORD));
        bmi->bmiHeader.biSize        = sizeof (BITMAPINFOHEADER);
        bmi->bmiHeader.biWidth       = VP_WIDTH;
        bmi->bmiHeader.biHeight      = -(ENV_HEIGHT+2);
        bmi->bmiHeader.biPlanes      = 1;
        bmi->bmiHeader.biBitCount    = 8;
        bmi->bmiHeader.biCompression = BI_RGB;
        bmi->bmiHeader.biClrUsed     = 256;
        bmi->bmiHeader.biClrImportant= 256;

        // Each entry maps onto the same entry in the logical palette
        for (i = 0; i < 256; i++)
                LPWORD (bmi->bmiColors)[i]  = i;

        LOGPALETTE *lpal = (LOGPALETTE *)malloc (sizeof (LOGPALETTE) + 256 * sizeof (PALETTEENTRY));
        lpal->palVersion = 0x300;
        lpal->palNumEntries = 256;
        for (i = 0; i < 256; i++)
        {
                lpal->palPalEntry[i].peRed  = hw_pal->p[i].r;
                lpal->palPalEntry[i].peGreen= hw_pal->p[i].g;
                lpal->palPalEntry[i].peBlue = hw_pal->p[i].b;
                lpal->palPalEntry[i].peFlags= PC_NOCOLLAPSE;
        }

        // Create a palette and make it our own
        pal.CreatePalette (lpal);
        free (lpal);

        shade_vp = new VngoVportDB8 (VP_WIDTH, ENV_HEIGHT+2, shade_bits, NULL, pDoc->base_pal, 0);

        DrawShades ();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnLButtonDown
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnLButtonDown(UINT nFlags, CPoint point)
{
        CRect   shade_rct (0, 0, ENV_WIDTH, ENV_HEIGHT);

    CPalToolDoc *pDoc = GetDocument();
    ASSERT_VALID(pDoc);

        if (shade_rct.PtInRect (point))
        {
                if (pDoc->curve_mode != CPalToolDoc::LINEAR && ShadePoint().PtInRect (point))
                {
                        // click in shade envelope
                        drag_mode = DRAG_SHADE;
                        SetCapture ();
                }
                else if (abs (point.x - pDoc->shade_env_break() * ENV_WIDTH / shade_env_divisions) < 2)
                {
                        drag_mode = DRAG_SHADE_BREAK;
                        SetCapture ();
                }
        }
    else if (point.x < (ENV_WIDTH+2+VP_WIDTH) && point.y < ENV_HEIGHT+2)
    {
        pDoc->UIPalette(this, (point.x - (ENV_WIDTH+2)));
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnLButtonUp
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnLButtonUp(UINT nFlags, CPoint point)
{
        const CPalToolDoc       *pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        if (GetCapture() == this)
        {
                ReleaseCapture();
                switch (pDoc->curve_mode)
                {
                    case CPalToolDoc::LINEAR:
                            OnOptionsLinear();
                            break;

                    case CPalToolDoc::QUADRATIC:
                            OnOptionsQuadratic();
                            break;

                    case CPalToolDoc::BEZIER:
                            OnOptionsBezier();
                            break;
                }
        }
        drag_mode = DRAG_NONE;

        CView::OnLButtonUp (nFlags, point);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnRButtonDown
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnRButtonDown(UINT nFlags, CPoint point)
{
        if (GetCapture() == this)
        return;

        CRect   shade_rct (0, 0, ENV_WIDTH, ENV_HEIGHT);
    int is_in_shade = shade_rct.PtInRect (point);

//ÄÄÄ Create menu(s)

    CRect   rct;
    GetWindowRect (&rct);

    point.x += rct.left;
    point.y += rct.top;

//ÄÄÄ Create menu(s)

    //ÄÄÄ Menu
    CMenu   rMenu;
    rMenu.CreatePopupMenu();

        if (is_in_shade)
        {
        rMenu.AppendMenu(MF_STRING, IDM_OPTIONS_LINEAR, "Linear");
        rMenu.AppendMenu(MF_STRING, IDM_OPTIONS_BEZIER, "Bezier");
        rMenu.AppendMenu(MF_STRING, IDM_OPTIONS_QUADRATIC, "Quadratic");
        rMenu.AppendMenu(MF_SEPARATOR);
    }
    rMenu.AppendMenu(MF_STRING, ID_EDIT_PALETTE, "Palette");
    rMenu.AppendMenu(MF_SEPARATOR);
    rMenu.AppendMenu(MF_STRING, ID_EDIT_PROP, "Properties");


//ÄÄÄ Display and perform action
    ASSERT(AfxGetMainWnd());
    rMenu.TrackPopupMenu( TPM_RIGHTBUTTON | TPM_LEFTALIGN,
                          point.x, point.y,
                          AfxGetMainWnd());
    rMenu.DestroyMenu();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnMouseMove
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnMouseMove(UINT nFlags, CPoint point)
{
        CPalToolDoc* pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        if (GetCapture() == this)
        {
                CClientDC dc (this);

                // Redraw the envelope
                switch (drag_mode)
                {
                    case DRAG_SHADE:
                            shade_env.x = clip_to (point.x * shade_env_divisions / ENV_WIDTH,
                                                                       1, pDoc->shade_env_break() - 1);
                            shade_env.y = clip_to (point.y * shade_env_divisions / ENV_WIDTH,
                                                                       shade_env_divisions / 2, shade_env_divisions -1);

                            DrawShadeEnv (&dc);
                            break;

                    case DRAG_SHADE_BREAK:
                            // You must leave space for at least 1 downshade color!
                            pDoc->shade_env_break() = clip_to (point.x * shade_env_divisions / ENV_WIDTH,
                                                                                                    2, shade_env_divisions -1);
                            shade_env.x = clip_to (shade_env.x,
                                                                       1, pDoc->shade_env_break() - 1);
                            DrawShadeEnv (&dc);
                            break;
                }
        }

        CView::OnMouseMove(nFlags, point);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnActivateView
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
        //if (bActivate)
        {
                CClientDC dc (this);

                dc.SelectPalette (&pal, !bActivate);
                dc.RealizePalette ();
        }

        CView::OnActivateView(bActivate, pActivateView, pDeactiveView);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnUpdate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnUpdate (CView* pSender, LPARAM lHint, CObject* pHint)
{
        const CPalToolDoc       *pDoc = GetDocument();
        ASSERT_VALID(pDoc);
        const VngoHwPal         *hw_pal = &((const VngoPal8 *)pDoc->base_pal)->hw_pal;

        // Each entry maps onto the same entry in the logical palette
        PALETTEENTRY *lpal = new PALETTEENTRY[256];
        for (int i = 0; i < 256; i++)
        {
                lpal[i].peRed  = hw_pal->p[i].r;
                lpal[i].peGreen= hw_pal->p[i].g;
                lpal[i].peBlue = hw_pal->p[i].b;
                lpal[i].peFlags= PC_NOCOLLAPSE;
        }

        // Create a palette and make it our own
        pal.SetPaletteEntries (0, 256, lpal);
        delete lpal;

        DrawShades ();

        CView::OnUpdate (pSender, lHint, pHint);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnEditPalette
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnEditPalette()
{
        CPalToolDoc     *pDoc = GetDocument();
        ASSERT_VALID(pDoc);

    pDoc->UIPalette(this);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - EditNew
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::EditNew(CPalToolDoc::genpal_type typ)
{
        CPalToolDoc     *pDoc = GetDocument();
        ASSERT_VALID(pDoc);

    if (MessageBox("This option will overwrite all palette entries.\n\n"
                   "Are you sure you wish to proceed?",
                   "Palette Tool",
                   MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
    {
                CProgressDlg    prog(this);

                prog.m_pbar.SetRange (0, 2);
                prog.m_pbar.SetPos (0);
                prog.SetWindowText ("Computing Palette");
        if (typ != CPalToolDoc::PAL_EMPTY)
                prog.ShowWindow (SW_SHOW);

        pDoc->Generate (typ);

        if (typ != CPalToolDoc::PAL_EMPTY)
        {
                    prog.m_pbar.SetPos (1);
            pDoc->CalcConvert();
                    prog.m_pbar.SetPos (2);
                    pDoc->CalcShades ();
        }
                pDoc->UpdateAllViews (NULL);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnEditNewEmpty
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnEditNewEmpty()
{
    EditNew(CPalToolDoc::PAL_EMPTY);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnEditNewGeneral
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnEditNewGeneral()
{
    EditNew(CPalToolDoc::PAL_GEN);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnEditNewGeneralOld
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnEditNewGeneralOld()
{
    EditNew(CPalToolDoc::PAL_ORIGGEN);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnEditNewGreyscale
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnEditNewGreyscale()
{
    EditNew(CPalToolDoc::PAL_GREY);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnEditNew332
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnEditNew332()
{
    EditNew(CPalToolDoc::PAL_332);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnEditNewRGBG
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnEditNewRGBG()
{
    EditNew(CPalToolDoc::PAL_RGBG);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnEditNewSpecial1
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnEditNewSpecial1()
{
    EditNew(CPalToolDoc::PAL_SPC1);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnEditProperties
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnEditProperties()
{
        CPalToolDoc     *pDoc = GetDocument();
        ASSERT_VALID(pDoc);

    pDoc->UIProperties(this);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - OnViewRefresh
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnViewRefresh()
{
    RedrawWindow();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - On(Update)OptionsBezier
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnOptionsBezier()
{
        HCURSOR old_cursor = ::SetCursor (::LoadCursor (NULL, IDC_WAIT));

        CPalToolDoc     *pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->curve_mode = CPalToolDoc::BEZIER;
        pDoc->CalcShades();
        DrawShades ();

        ::SetCursor (old_cursor);
        pDoc->UpdateAllViews (NULL);
}

void CPalToolView::OnUpdateOptionsBezier(CCmdUI* pCmdUI)
{
        const CPalToolDoc       *pDoc = GetDocument();
    ASSERT_VALID(pDoc);

        pCmdUI->Enable (FALSE);
        //pCmdUI->SetCheck (pDoc->curve_mode == CPalToolDoc::BEZIER);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - On(Update)OptionsLinear
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnOptionsLinear()
{
        HCURSOR old_cursor = ::SetCursor (::LoadCursor (NULL, IDC_WAIT));

        CPalToolDoc     *pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->curve_mode = CPalToolDoc::LINEAR;
        pDoc->CalcShades();
        DrawShades ();

        ::SetCursor (old_cursor);
        pDoc->UpdateAllViews (NULL);
}

void CPalToolView::OnUpdateOptionsLinear(CCmdUI* pCmdUI)
{
        const CPalToolDoc       *pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pCmdUI->Enable (TRUE);
        pCmdUI->SetCheck (pDoc->curve_mode == CPalToolDoc::LINEAR);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolView - On(Update)OptionsQuadratic
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolView::OnOptionsQuadratic()
{
        HCURSOR old_cursor = ::SetCursor (::LoadCursor (NULL, IDC_WAIT));

        CPalToolDoc     *pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->curve_mode = CPalToolDoc::QUADRATIC;
        pDoc->CalcShades();
        DrawShades ();

        ::SetCursor (old_cursor);
        pDoc->UpdateAllViews (NULL);
}

void CPalToolView::OnUpdateOptionsQuadratic(CCmdUI* pCmdUI)
{
        const CPalToolDoc       *pDoc = GetDocument();
        ASSERT_VALID(pDoc);

        pCmdUI->Enable (FALSE);
        //pCmdUI->SetCheck (pDoc->curve_mode == CPalToolDoc::QUADRATIC);
}

//°±² eof - paltovw.cpp ²±°
