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
//שששששששששששCopyrightש(c)ש1994-1997שbyשCharybdisשEnterprises,שInc.שששששששששש
//ששששששששששששששששששששששששששAllשRightsשReserved.ששששששששששששששששששששששששששששש
//ששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששש
//ששששששששששששששששששששש Microsoft Windows '95 Version ששששששששששששששששששששששש
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
// eshtgrid.h
//
// Terrain View support class.
//
// The Grid class handles the surface information overhead window.
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

typedef enum _surfdisp_mode_type
{
    SURFDSP_NONE        =0,
    SURFDSP_COLORS      =1,
    SURFDSP_SHADED      =2,
    SURFDSP_HGT         =3,
    SURFDSP_TXTONLY     =4,
    SURFDSP_APPBITS     =5,
} surfdisp_mode_type;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// TerrEditGrid                                                             ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ

class TerrEditGrid : public CWnd
{
// Construction
public:
	TerrEditGrid();

// Attributes
public:
    VngoPal             *pal;
    ushort              width, depth;

// Operations
public:
    void SetSurfaceSize(int w, int d);
    void UpdateSurfaceColors();

    void SetZoomLevel(dword zshft);
    dword GetZoomLevel() { return zoomshift; };

    void SetPosition(int x, int y, int upscroll=1);
    void GetPosition(int *x, int *y) { if (x) *x=xpos; if (y) *y=ypos; }

    void SetMode(surfdisp_mode_type m);
    surfdisp_mode_type GetMode() { return mode; }

    void AssignByHeight(ulong count,
                        ushort *tc, ushort *istxt, float *heights,
                        float hstop, BOOL area, BOOL preserve);

    void AssignByRandomRoll(ulong count,
                            ushort *tc, ushort *istxt, UINT *chances,
                            BOOL elvcutoff, float elvlow, float elvhigh,
                            BOOL area, BOOL preserve);

    void AssignByAngle(ulong count,
                       ushort *tc, ushort *istxt, float *angles,
                       float astop, 
                       BOOL elvcutoff, float elvlow, float elvhigh,
                       BOOL area, BOOL preserve);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TerrEditGrid)
	//}}AFX_VIRTUAL

// Implementation
public:  
	virtual ~TerrEditGrid();

protected:
    surfdisp_mode_type  mode;
    int                 xpos, ypos;
    dword               zoomshift;
    BITMAPINFO          *bmi;
    BYTE                *gmap;
    BOOL                rectactive;
    CRect               rect;
    CRect               lastrect;

    void setup_vport(int width, int height);
    void release_vport();

    enum
    {
        NONE        =0,
        ALL         =1,
        BYHEIGHT    =2,
        BYRANDOMROLL=3,
        BYANGLE     =4,
    };

    ushort  a_method;
    ulong   a_count;
    ushort  a_tc[8];
    ushort  a_istxt[8];
    float   a_values[8];
    int     a_values_int[8];
    float   a_stop;
    BOOL    a_preserve;
    BOOL    a_elvcutoff;
    float   a_elvlow;
    float   a_elvhigh;

    void randomize();
    void assign_by_height(TerrEditDoc* pDoc, int xspos, int dspos, BOOL &changed);
    void assign_by_random_roll(TerrEditDoc* pDoc, int xspos, int dspos, BOOL &changed);
    void assign_by_angle(TerrEditDoc* pDoc, int xspos, int dspos, BOOL &changed);
    void assign(CRect r);

	// Generated message map functions
protected:
	//{{AFX_MSG(TerrEditGrid)
	afx_msg void OnPaint();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//°±² eof - eshtgrid.h ²±°
