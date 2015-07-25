// PalTovw.h : interface of the CPalToolView class
//
/////////////////////////////////////////////////////////////////////////////

class CPalToolView : public CView
{
protected: // create from serialization only
	CPalToolView();
	DECLARE_DYNCREATE(CPalToolView)

// Attributes
public:
	CPalToolDoc* GetDocument();

	enum { SB_HEIGHT = 15,
		   ENV_WIDTH = 128,
		   ENV_HEIGHT = 128,
		 };

	int	shade_env_divisions;
	CPoint	shade_env;


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

protected:
	BYTE		*shade_bits;
	BYTE		*haze_bits;
	BITMAPINFO	*bmi;

	CPalette	pal;
	CPen		dotted;

	VngoVport	*shade_vp;
	VngoVport	*haze_vp;

	enum { DRAG_NONE, DRAG_SHADE, DRAG_SHADE_BREAK, DRAG_HAZE } drag_mode;


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
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PalTovw.cpp
inline CPalToolDoc* CPalToolView::GetDocument()
   { return (CPalToolDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
