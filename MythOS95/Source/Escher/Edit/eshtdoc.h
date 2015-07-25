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
// eshtdoc.h
//
// Terrain Editor Document class
//
// The document class owns the terrain height field, surface array, and
// the texture information.  The data may be manipulated or exported into
// an Escher IFF file.
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

class TerrEditDoc : public CDocument
{
protected: // create from serialization only
        TerrEditDoc();
        DECLARE_DYNCREATE(TerrEditDoc)

// Attributes
public:
    enum
    {
        NORMALS_SMOOTH  = 0x1,
        NORMALS_FLAT    = 0x2
    };

    enum
    {
        FLOATING    = 0x1,
        COMPRESS    = 0x2,
    };

    dword           ctrlfl;

    ushort          width;                  // Width of height field
    ushort          depth;                  // Depth of height field
    ushort          surfratio;              // Surface ratio (height : surface)
    ushort          surfshift;              // Shift value for surf ratio

    float           scale;                  // Scale factor

    int             autocenter;             // Autocenter terrain in XZ plane
    float           orgx, orgy, orgz;       // Terrain origin

    byte            *hfield;                // Height field array
    float           *htable;                // Height table
    esch_surf_type  *surfinfo;              // Surface array
    dword           *surfcolr;              // Surface RGB color array
    IvoryHandle     hsurfnorml;             // Lighting normal array
    IvoryHandle     hsurfnormlflat;         // Flat shading normal array.

    BOOL            undo_valid;
    esch_surf_type  *undo_surfinfo;         // Undo buffers
    dword           *undo_surfcolr;

    char            name[ESCH_MAX_NAME];    // Name, etc.
    char            desc[256];
    char            auth[256];
    char            copy[256];

    int             txtNumb;                // Texture information
    CString         txtName[256];
    CString         txtFName[256];
    EschTexture     *txtEsch[256];
    dword           txtColr[256];
    byte            txtColrIndx[256];
    dword           txtDFlags[256];


    int             colorNumb;              // Color information
    CString         colorName[256];
    dword           colorColr[256];
    byte            colorColrIndx[256];
    dword           colorDFlags[256];

    char            pfname[256];            // Van Gogh palette
    VngoPal8        palette;
    HPALETTE        hpal;

    EschCameraEx    cam;                    // Render view camera
    dword           cam_bcolor;
    EschLight       *lights;                // Light list

    ushort          color_bands[11];        // Height-colors

    float           hover_offset;           // Misc Properties
    BOOL            lod_active;
    float           lod_medium;
    float           lod_low;

    void SetLightsModifiedFlag() { lightsdirty = TRUE; }

// Operations
public:
    BOOL LoadPalette(const char *fname, int doupdate=1);
    void ImportTerrain(const char *fname, int losswarn=0);
    void ImportSurface(const char *fname, int losswarn=0);

    int FindTexture(const char *name);
    BOOL AddTexture(const char *name, const char *fname, dword color,
                    dword flags);
    BOOL SetTexture(int ind, const char *name, const char *fname,
                    dword color, dword flags);
    void DeleteTexture(int ind);

    void RemoveUnusedTxts();

    void SaveTextures(const char *fname);
    void LoadTextures(const char *fname);

    int FindColor(const char *name);
    BOOL AddColor(const char *name, dword color, dword flags);
    BOOL SetColor(int ind, const char *name, dword color, dword flags);
    void DeleteColor(int ind);
    void ExportToIFF(const char *fname);

    void SaveColors(const char *fname);
    void LoadColors(const char *fname);

    void ComputeNormals(dword flags = NORMALS_SMOOTH);
    void LightTerrain();

    void GetMinMaxElevations(float &min, float &max);
    void SetBaseElevation(float newbase);

    void PushUndo();
    void PopUndo();

    void Flip(BOOL horz);
    void Rotate(BOOL right);

    void UITerrainProperities(CWnd *parent, UINT ipage=0, int edit=0);
    void UISurfProperties(CWnd *parent, UINT xpos, UINT dpos, UINT ipage=0);
    void UISurfColor(CWnd *parent, UINT xpos, UINT dpos);
    void UICameraProperties(CWnd *parent, UINT ipage=0);
    void UILightProperties(CWnd *parent, UINT ipage=0);

// Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(TerrEditDoc)
        public:
        virtual BOOL OnNewDocument();
        virtual void DeleteContents();
        //}}AFX_VIRTUAL

// Implementation
public:
        virtual ~TerrEditDoc();
        virtual void Serialize(CArchive& ar);   // overridden for document i/o
#ifdef _DEBUG
        virtual void AssertValid() const;
        virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    // Display helper routines
    BOOL lightsdirty;
    void map_surfcolor_to_palette();
    BOOL load_and_recolor_texture(int ind, const char *fname);

    // Import helper routines
    long find_closest_htable_entry(float h, long start, long end);
    long find_entry(float *heights, float h, long start, long end);

    void compress_heights_standard(long xs, long ys, long w, long h,
                                   ushort *data, BOOL normalize);
    void compress_heights_uniform(long xs, long ys, long w, long h,
                                  ushort *data, BOOL normalize);
    void compress_heights_averaged(float threshold,
                                   long xs, long ys, long w, long h,
                                   ushort *data, BOOL normalize);

    // Import routines
    BOOL import_heights_from_vpdem(const char *fname, BOOL *isvpdem);
    BOOL import_heights_from_usgsdem(const char *fname);
    BOOL import_heights_from_pcx(const char *fname);

// Generated message map functions
protected:
        //{{AFX_MSG(TerrEditDoc)
                // NOTE - the ClassWizard will add and remove member functions here.
                //    DO NOT EDIT what you see in these blocks of generated code !
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};

//°±² eof - eshtdoc.h ²±°

