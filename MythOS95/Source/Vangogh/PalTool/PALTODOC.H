// PalTodoc.h : interface of the CPalToolDoc class
//
/////////////////////////////////////////////////////////////////////////////

class CPalToolDoc : public CDocument
{
protected: // create from serialization only
	CPalToolDoc();
	DECLARE_DYNCREATE(CPalToolDoc)

// Attributes
public:
	VngoPal		*base_pal;
	enum { LINEAR, BEZIER, QUADRATIC } curve_mode;
	long &shade_env_break() const { return base_pal->shd_pal->mid_point; }


// Operations
public:
	void use_colors8  (VngoColor24bit *colors, int steps, int color_index);
	void use_colors15 (VngoColor24bit *colors, int steps, int color_index);
	void use_colors16 (VngoColor24bit *colors, int steps, int color_index);
	void use_colors24 (VngoColor24bit *colors, int steps, int color_index);

	void calc_shades ();

	void calc_linear_colors (VngoColor24bit *colors, int steps,
							 VngoColor24bit color, int break_point);
	void calc_bez_colors (VngoColor24bit *colors, int steps,
						 VngoColor24bit color, int break_point);
	void calc_quad_colors (VngoColor24bit *colors, int steps,
						 VngoColor24bit color, int break_point);

	int ImportWindowsPalette (LPCSTR);
	int ImportVGPalette (LPCSTR);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPalToolDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPalToolDoc();
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPalToolDoc)
	afx_msg void OnFileImport();
	afx_msg void OnFileExport();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
