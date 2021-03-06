//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//        Microsoft Windows 95/98/NT Version                 | / \   .  |
//                                                           |_|_|_._._.|
//                                                           |.-.-.-.-..|
//                                                          %\__________/%
//                                                           %          %
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// Created by Dan Higdon & Chuck Walbourn
//
// PalTovw.h
//
// PalTool view class.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class CPalToolView : public CView
{
protected: // create from serialization only
        CPalToolView();
        DECLARE_DYNCREATE(CPalToolView)

// Attributes
public:
        CPalToolDoc* GetDocument();

        enum
    {
        SB_HEIGHT = 15,
                ENV_WIDTH = 128,
                ENV_HEIGHT = 128,
        VP_WIDTH = 256,
     };

// Operations
public:

        void DrawShadeEnv (CDC *);
        void DrawHazeEnv (CDC *);
        void DrawShades ();
        CRect ShadePoint () const;
        CRect HazePoint () const;


// Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CPalToolView)
        public:
        virtual void OnDraw(CDC* pDC);  // overridden to draw this view
        virtual void OnInitialUpdate();
        protected:
        virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
        virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
        //}}AFX_VIRTUAL

// Implementation
public:
        virtual ~CPalToolView();
#ifdef _DEBUG
        virtual void AssertValid() const;
        virtual void Dump(CDumpContext& dc) const;
#endif
    void EditNew(CPalToolDoc::genpal_type typ);

protected:
        int             shade_env_divisions;
        CPoint      shade_env;

        BYTE            *shade_bits;
        BYTE            *haze_bits;
        BITMAPINFO      *bmi;

        CPalette        pal;
        CPen            dotted;

        VngoVport       *shade_vp;
        VngoVport       *haze_vp;

        enum
    {
        DRAG_NONE,
        DRAG_SHADE,
        DRAG_SHADE_BREAK,
        DRAG_HAZE
    } drag_mode;

// Generated message map functions
protected:
        //{{AFX_MSG(CPalToolView)
        afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
        afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
        afx_msg void OnMouseMove(UINT nFlags, CPoint point);
        afx_msg void OnOptionsBezier();
        afx_msg void OnUpdateOptionsBezier(CCmdUI* pCmdUI);
        afx_msg void OnOptionsLinear();
        afx_msg void OnUpdateOptionsLinear(CCmdUI* pCmdUI);
        afx_msg void OnOptionsQuadratic();
        afx_msg void OnUpdateOptionsQuadratic(CCmdUI* pCmdUI);
        afx_msg void OnEditNewEmpty();
        afx_msg void OnEditNewGeneral();
        afx_msg void OnEditNewGeneralOld();
        afx_msg void OnEditNewGreyscale();
        afx_msg void OnEditNew332();
        afx_msg void OnEditNewRGBG();
        afx_msg void OnEditPalette();
        afx_msg void OnEditProperties();
        afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
        afx_msg void OnEditNewSpecial1();
        afx_msg void OnViewRefresh();
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PalTovw.cpp
inline CPalToolDoc* CPalToolView::GetDocument()
   { return (CPalToolDoc*)m_pDocument; }
#endif

//葦� eof - paltovw.h 憶�
