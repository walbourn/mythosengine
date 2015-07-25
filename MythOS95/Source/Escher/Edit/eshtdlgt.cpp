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
//ùùùùùùùùùùùùùùùùùùù Microsoft Windows 95/NT Version ùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùCopyrightù(c)ù1994-1998ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùAllùRightsùReserved.ùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
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
// eshtdlgt.cpp
//
// Terrain Editor Texture Dialog Classes
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "stdafx.h"
#include "eshtedit.h"
#include "eshtdlg.h"
#include "eshtdlgt.h"
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
//°°°°°°°°°°°°°°°°°°°°°°°°°°° Texture View Dialog °°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TextureViewDlg                                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BEGIN_MESSAGE_MAP(TextureViewDlg, CDialog)
    //{{AFX_MSG_MAP(TextureViewDlg)
    ON_WM_PAINT()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

TextureViewDlg::TextureViewDlg(CWnd* pParent /*=NULL*/)
        : CDialog(TextureViewDlg::IDD, pParent),
    bmi(0),
    gmap(0),
    hpal(0)
{
    //{{AFX_DATA_INIT(TextureViewDlg)
    m_height = 0;
    m_width = 0;
    //}}AFX_DATA_INIT
}

TextureViewDlg::~TextureViewDlg()
{
}

void TextureViewDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(TextureViewDlg)
    DDX_Control(pDX, IDC_BITMAP, m_bitmap);
    DDX_Text(pDX, IDC_TVIEW_HEIGHT, m_height);
    DDV_MinMaxUInt(pDX, m_height, 0, 65535);
    DDX_Text(pDX, IDC_TVIEW_WIDTH, m_width);
    DDV_MinMaxUInt(pDX, m_width, 0, 65535);
    //}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        CRect rect;
        m_bitmap.GetClientRect(&rect);
        m_bitmap.MapWindowPoints(this,rect);

        x = rect.left + ((rect.right - rect.left + 1) - m_width) / 2;
        y = rect.top + ((rect.bottom - rect.top + 1) - m_height) / 2;
    }
}

void TextureViewDlg::OnPaint() 
{
    CPaintDC dc(this); // device context for painting

    if (hpal)
    {
        SelectPalette(dc.m_hDC,hpal,0);
        dc.RealizePalette();
    }

    if (bmi && gmap)
    {
        SetDIBitsToDevice(dc.m_hDC,
                          x, y,
                          bmi->bmiHeader.biWidth, -bmi->bmiHeader.biHeight,
                          0, 0, 0, -bmi->bmiHeader.biHeight,
                          gmap,
                          bmi,
                          DIB_PAL_COLORS);
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°° Texture Create Dialogs °°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// CreateTextureAskDlg                                                      ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BEGIN_MESSAGE_MAP(CreateTextureAskDlg, CDialog)
	//{{AFX_MSG_MAP(CreateTextureAskDlg)
	ON_BN_CLICKED(ID_CREATE_FROM_COLOR, OnCreateFromColor)
	ON_BN_CLICKED(ID_CREATE_FROM_FILE, OnCreateFromFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CreateTextureAskDlg::CreateTextureAskDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CreateTextureAskDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CreateTextureAskDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CreateTextureAskDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CreateTextureAskDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

void CreateTextureAskDlg::OnCreateFromColor() 
{
    EndDialog(CREATE_ASK_COLOR);
}

void CreateTextureAskDlg::OnCreateFromFile() 
{
    EndDialog(CREATE_ASK_FILE);	
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// CreateTextureDlg                                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BEGIN_MESSAGE_MAP(CreateTextureDlg, CDialog)
	//{{AFX_MSG_MAP(CreateTextureDlg)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_TVIEW_LOADBKTXT, OnLoadBgTexture)
	ON_BN_CLICKED(IDC_TVIEW_SAVEAS, OnSaveAs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CreateTextureDlg::CreateTextureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CreateTextureDlg::IDD, pParent),
    bmi(0),
    gmap(0),
    hpal(0),
    m_color(0),
    bg_is_dib(0)
{
	//{{AFX_DATA_INIT(CreateTextureDlg)
	m_height = 0;
	m_width = 0;
	//}}AFX_DATA_INIT
}

CreateTextureDlg::~CreateTextureDlg()
{
    bm.unlock();
}

void CreateTextureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CreateTextureDlg)
	DDX_Control(pDX, IDC_BITMAP2, m_bitmap);
	DDX_Text(pDX, IDC_TVIEW_HEIGHT, m_height);
	DDV_MinMaxUInt(pDX, m_height, 0, 65535);
	DDX_Text(pDX, IDC_TVIEW_WIDTH, m_width);
	DDV_MinMaxUInt(pDX, m_width, 0, 65535);
	//}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        CRect rect;
        m_bitmap.GetClientRect(&rect);
        m_bitmap.MapWindowPoints(this,rect);

        x = rect.left + ((rect.right - rect.left + 1) - m_width) / 2;
        y = rect.top + ((rect.bottom - rect.top + 1) - m_height) / 2;

    }
}

void CreateTextureDlg::setup(TerrEditDoc *pd)
{
    pDoc = pd;
    ASSERT(pDoc);
}

void CreateTextureDlg::release_dib()
{
    if (bmi)
    {
        delete bmi;
        bmi = 0;
    }

    if (gmap)
    {
        delete [] gmap;
        gmap = 0;
    }
}

void CreateTextureDlg::do_image_background(XFBitmap *bm, XFBitmap *bg_bm, int w, int h)
{
    VngoRect vprect(0, 0, w, h);
    VngoVVport8 *vp = new VngoVVport8(vprect, &(pDoc->palette), 0);

    if (vp) 
    {
        vp->lock();

        VngoPoint vpoints[4];

        dword t = pDoc->palette.shd_pal->mid_point + 1;

        if (bg_is_dib && bg_bm)
        {
            for (int y = 0; y < bm->height; y += bg_bm->height)
            {
                for (int x = 0;  x < bm->width; x += bg_bm->width)        
                {
                    VngoTexture texture;
            
                    texture.width = bg_bm->width;
                    texture.height = bg_bm->height;
                    texture.tex = bg_bm->data;
        
                    VngoRect vrect(x,y, bg_bm->width, bg_bm->height);
        
                    vp->image_trans(&vrect, &texture, 0);
                }
            }
        }
        else
        {
            vpoints[0].x = 0;
            vpoints[0].y = 0;
            vpoints[0].clr = colors[0];
            vpoints[0].shade = t;
    
            vpoints[1].x = w - 1;
            vpoints[1].y = 0;
            vpoints[1].clr = colors[1];
            vpoints[1].shade = t;
    
            vpoints[2].x = w - 1;
            vpoints[2].y = h - 1;
            vpoints[2].clr = colors[3];
            vpoints[2].shade = t;
    
            vpoints[3].x = 0;
            vpoints[3].y = h - 1 ;
            vpoints[3].clr = colors[2];
            vpoints[3].shade = t;
    
            vngo_smooth_rect(vp, vpoints);
        }
        
        VngoTexture texture;

        texture.width = w;
        texture.height = h;

        texture.tex = bm->data;

        VngoRect vrect(0,0, w, h);

        vp->image_trans(&vrect, &texture, VNGO_TRANSPARENT);

        memcpy (bm->data, vp->vbuff.scrn_ptr, sizeof(BYTE) * w * h);

        vp->unlock();

        delete vp;
        vp = 0;
    }
}

BOOL CreateTextureDlg::setup_dib()
{
//ÄÄÄ Load Bitmap
    XFBitmap bg_bm;

    int bitmap_width = 0;
    int bitmap_height = 0;

    // At this point we know that the foreground bitmap in dib_fname has
    // a width and height that is 16, 32, 64, 128 or 256.

    // We also know that the background bitmap, if it exists, has
    // a width and height that is 16, 32, 64, 128 or 256.

    // Note:  DIBs are guaranteed to display correctly because the bitmaps
    // are divisible by 4.

    if (!theApp.LoadImage((LPCTSTR)dib_fname, &bm))
        return FALSE;

    if (bg_is_dib)
    {
        // if we can't load the background bitmap,  then 
        // don't try to display it later...
        if (!theApp.LoadImage((LPCTSTR)bg_dib_fname, &bg_bm))
            bg_is_dib = FALSE;

        if ((bm.width * bm.height) < (bg_bm.width * bg_bm.height))
        {
            bitmap_width = bg_bm.width;
            bitmap_height = bg_bm.height;
        }
        else
        {
            bitmap_width = bm.width;
            bitmap_height = bm.height;
        }
    }
    else
    {
        bitmap_width = bm.width;
        bitmap_height = bm.height;
    }

//ÄÄÄ Create Bitmap
    bmi = (LPBITMAPINFO) new byte[sizeof(BITMAPINFOHEADER)
                                               + (256*sizeof(WORD))];
    ASSERT(bmi);
    memset(bmi, 0, sizeof(*bmi));
    bmi->bmiHeader.biSize         = sizeof (BITMAPINFOHEADER);
    bmi->bmiHeader.biWidth        = bitmap_width;
    bmi->bmiHeader.biHeight       = -bitmap_height;
    bmi->bmiHeader.biPlanes       = 1;
    bmi->bmiHeader.biBitCount     = 8;
    bmi->bmiHeader.biCompression  = BI_RGB;
    bmi->bmiHeader.biClrUsed      = 256;
    bmi->bmiHeader.biClrImportant = 256;
    for(int i=0; i < 256; i++)
        ((WORD*)bmi->bmiColors)[i] = (WORD)i;

    int sizeof_gmap = bitmap_width * bitmap_height;
    gmap = new BYTE [sizeof_gmap];
    ASSERT(gmap);

    bm.lock();

    ASSERT(bm.data != 0);
    BYTE *dptr=gmap;
    BYTE *sptr=bm.data;
    // First, we'll convert the bitmap data to a DIB
    if (bm.bpp == 1)
    {

        byte mypal[256];

        for(i=0; i < 256; i++)
        {
            mypal[i] = (byte)pDoc->palette.get_index((VngoColor24bit)bm.pal[i]);
        }
        // Force transparency to remain transparent.....
        mypal[255] = 255;

        for(int y=0; y < bitmap_height; y++)
        {
            for(int x=0; x < bitmap_width; x++)
            {
                *(dptr++) = mypal[*(sptr++)];

                ASSERT(dptr <= (gmap + bitmap_width * bitmap_height));
            }
        }
    }
    else
    {
        VngoColor24bit  clr;

        ASSERT(bm.bpp == 3);
        for(int y=0; y < bitmap_height; y++)
        {
            for(int x=0; x < bitmap_width; x++)
            {
                clr.r = *(sptr++);
                clr.g = *(sptr++);
                clr.b = *(sptr++);
                if (clr.r == 255 && clr.g == 0 & clr.b == 255)
                {   // If it is the transparent color skip it.
                    dptr++;
                }
                else
                {
                    *(dptr++) = (byte)pDoc->palette.get_index(clr);
                }
                ASSERT(dptr <= (gmap + bitmap_width * bitmap_height));
            }
        }
    }

    // copy the DIB info back into the bitmap so we can do the smoothing
    memcpy(bm.data, gmap, sizeof(BYTE) * bitmap_width * bitmap_height);

    BYTE *bgptr = 0;

    int sz_gmap = bg_bm.width * bg_bm.height;
    BYTE *bggmap = new BYTE [sz_gmap];
    ASSERT(bggmap);

    if (bg_is_dib)
    {
        bg_bm.lock();
        bgptr = bg_bm.data;
    
    
        ASSERT(bg_bm.data != 0);

        BYTE *aptr=bggmap;
        BYTE *bptr=bg_bm.data;
        // First, we'll convert the bitmap data to a DIB
        if (bg_bm.bpp == 1)
        {
            byte mypal[256];
    
            for(i=0; i < 256; i++)
            {
                mypal[i] = (byte)pDoc->palette.get_index((VngoColor24bit)bg_bm.pal[i]);
            }
            // Force transparency to remain transparent.....
            mypal[255] = 255;
    
            for(int y=0; y < bg_bm.height; y++)
            {
                for(int x=0; x < bg_bm.width; x++)
                {
                    *(aptr++) = mypal[*(bptr++)];
    
                    ASSERT(aptr <= (bggmap + bg_bm.width * bg_bm.height));
                }
            }
        }
        else
        {
            VngoColor24bit  clr;

            ASSERT(bg_bm.bpp == 3);
            for(int y=0; y < bg_bm.height; y++)
            {
                for(int x=0; x < bg_bm.width; x++)
                {
                    clr.r = *(bptr++);
                    clr.g = *(bptr++);
                    clr.b = *(bptr++);
                    *(aptr++) = (byte)pDoc->palette.get_index(clr);
                    ASSERT(aptr <= (bggmap + bg_bm.width * bg_bm.height));
                }
            }
        }

        // copy the DIB info back into the bitmap so we can do the smoothing
        memcpy(bg_bm.data, bggmap, sizeof(BYTE) * bg_bm.width * bg_bm.height);

    }

    // Modify the bitmap to have the tranparent color smoothing or the DIB for a background
    if (bg_is_dib)
        do_image_background(&bm, &bg_bm, bitmap_width, bitmap_height);
    else
        do_image_background(&bm, NULL, bitmap_width, bitmap_height);

    // copy the bitmap data back into the DIB so we can display it
    memcpy(gmap, bm.data, sizeof(BYTE) * bitmap_width * bitmap_height);

    bg_bm.unlock();

    delete [] bggmap;

    return TRUE;
}

void CreateTextureDlg::draw_selection_boxes(CPaintDC *pdc)
{
    reg[0].left = x - 15;
    reg[0].top  = y - 15;
    reg[0].right = reg[0].left + 10;
    reg[0].bottom = reg[0].top + 10;

    reg[1].left = (x+ m_width) + 5;
    reg[1].top  = y - 15;
    reg[1].right = reg[1].left + 10;
    reg[1].bottom = reg[1].top + 10;

    reg[2].left = x - 15;
    reg[2].top  = (y + m_height) + 5;
    reg[2].right = reg[2].left + 10;
    reg[2].bottom = reg[2].top + 10;

    reg[3].left = (x + m_width) + 5;
    reg[3].top  = (y + m_height) + 5;
    reg[3].right = reg[3].left + 10;
    reg[3].bottom = reg[3].top + 10;

    CBrush br;
    CBrush *old_brush;
    br.CreateSolidBrush(PALETTEINDEX(colors[0]));
    old_brush = pdc->SelectObject(&br);

    pdc->FillRect(&reg[0], &br);

    pdc->SelectObject(old_brush);
    br.DeleteObject();

    br.CreateSolidBrush(PALETTEINDEX(colors[1]));
    old_brush = pdc->SelectObject(&br);

    pdc->FillRect(&reg[1], &br);

    pdc->SelectObject(old_brush);
    br.DeleteObject();

    br.CreateSolidBrush(PALETTEINDEX(colors[2]));
    old_brush = pdc->SelectObject(&br);

    pdc->FillRect(&reg[2], &br);

    pdc->SelectObject(old_brush);
    br.DeleteObject();

    br.CreateSolidBrush(PALETTEINDEX(colors[3]));
    old_brush = pdc->SelectObject(&br);

    pdc->FillRect(&reg[3], &br);

    pdc->SelectObject(old_brush);
    br.DeleteObject();
}

void CreateTextureDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

    if (!setup_dib())
        return;

    if (hpal)
    {
        SelectPalette(dc.m_hDC,hpal,0);
        dc.RealizePalette();
    }

    if (bmi && gmap)
    {
        SetDIBitsToDevice(dc.m_hDC,
                          x, y,
                          bmi->bmiHeader.biWidth, -bmi->bmiHeader.biHeight,
                          0, 0, 0, -bmi->bmiHeader.biHeight,
                          gmap,
                          bmi,
                          DIB_PAL_COLORS);
    }

    release_dib();

    // Draw the color selection boxes
    draw_selection_boxes(&dc);
}

void CreateTextureDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
    int x1 = point.x;
    int y1 = point.y;

    int region = -1;

    if ( (x1 >= reg[0].left) && (x1 <= reg[0].right) && (y1 >= reg[0].top) && (y1 <= reg[0].bottom) )
        region = 0;
    else if ( (x1 >= reg[1].left) && (x1 <= reg[1].right) && (y1 >= reg[1].top) && (y1 <= reg[1].bottom) )
        region = 1;
    else if ( (x1 >= reg[2].left) && (x1 <= reg[2].right) && (y1 >= reg[2].top) && (y1 <= reg[2].bottom) )
        region = 2;
    else if ( (x1 >= reg[3].left) && (x1 <= reg[3].right) && (y1 >= reg[3].top) && (y1 <= reg[3].bottom) )
        region = 3;

    if (region != -1) 
    {
        ColorSelectPropPage dlga;

        dlga.palette = &pDoc->palette;
        dlga.color = colors[region];

        ShadeReviewPropPage dlgb;
        dlgb.palette = dlga.palette;
        dlgb.color = dlga.color;

        dlga.setup(0,&dlgb);

        CPropertySheet sh("Color Select");

        sh.AddPage(&dlga);      // Select Color
        sh.AddPage(&dlgb);      // Shade Review

        if (sh.DoModal() == IDOK)
        {
            colors[region] = dlga.color;
            Invalidate();
            RedrawWindow();
        }
    }

	CDialog::OnLButtonDown(nFlags, point);
}

void CreateTextureDlg::OnLoadBgTexture() 
{

    CFileDialog dlg(TRUE,
                    NULL, bg_dib_fname, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
                    "Bitmap files (*.bmp;*.cel;*.lbm;*.pcx;*.tga)|*.BMP;*.CEL;*.LBM;*.PCX;*.TGA|"
                    "Windows Bitmap files (*.bmp)|*.BMP|"
                    "Autodesk CEL files (*.cel)|*.CEL|"
                    "DPaint/EA LBM files (*.lbm)|*.LBM|"
                    "Zsoft PCX files (*.pcx)|*.PCX|"
                    "Targa files (*.tga)|*.TGA|"
                    "All files (*.*)|*.*||",
                    this);

    dlg.m_ofn.lpstrTitle = "Texture Bitmap File";

    if (dlg.DoModal() == IDOK)
    {
        CString temp;
        temp = dlg.GetPathName();

        // Make sure the bitmap has a width and height that is 16, 32, 64, 128 or 256.
        if (check_bitmap_size((LPCTSTR)temp))
        {
            bg_dib_fname = temp;
            bg_is_dib = TRUE;
            RedrawWindow();
        }
        else
            bg_is_dib = FALSE;
            
    }
}

BOOL CreateTextureDlg::check_bitmap_size(const char *fname)
{
    XFBitmap bm;
    BOOL res = FALSE;

    if (theApp.LoadImage(fname, &bm))
    {
        switch (bm.width)
        {
            case 16:
            case 32:
            case 64:
            case 128:
            case 256:
                res = TRUE;
                break;
            default:
                AfxMessageBox("Bitmap file must be 16, 32, 64, 128, or 256 pixels in width.",
                              MB_OK | MB_ICONEXCLAMATION);
                res = FALSE;
        }

        if (res)
        {    
            switch (bm.height)
            {
                case 16:
                case 32:
                case 64:
                case 128:
                case 256:
                    res = TRUE;
                    break;
                default:
                    AfxMessageBox("Bitmap file must be 16, 32, 64, 128, or 256 pixels in height.",
                                  MB_OK | MB_ICONEXCLAMATION);
                    res = FALSE;
            }
        }
    }
    return res;
}

void CreateTextureDlg::OnSaveAs() 
{

    CString newname;

    CFileDialog dlg(TRUE,
                    NULL, dib_fname, OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
                    "Bitmap files (*.bmp;*.cel;*.lbm;*.pcx;*.tga)|*.BMP;*.CEL;*.LBM;*.PCX;*.TGA|"
                    "Windows Bitmap files (*.bmp)|*.BMP|"
                    "Autodesk CEL files (*.cel)|*.CEL|"
                    "DPaint/EA LBM files (*.lbm)|*.LBM|"
                    "Zsoft PCX files (*.pcx)|*.PCX|"
                    "Targa files (*.tga)|*.TGA|"
                    "All files (*.*)|*.*||",
                    this);


    dlg.m_ofn.lpstrTitle = "Save New Texture";

    if (dlg.DoModal() == IDOK)
    {
        char buff[256];

        dib_fname = dlg.GetPathName();

        // make sure that the filename has an extension!
        strcpy(buff, (LPCSTR)dib_fname);

        if (!strstr(buff, "."))
        {
            strcat(buff,".bmp");
            dib_fname = buff;
        }

        // Save the current palette into the bitmap
        VngoColor24bit tclr;
        for(int i=0; i < 256; i++)
        {
            tclr = pDoc->palette.get_RGB(i);
            bm.pal[i] = (dword)(tclr.r | (tclr.g << 8) | (tclr.b << 16));
        }
    

        theApp.SaveImage((LPCTSTR)dib_fname, &bm);
    }

    EndDialog(IDOK);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// CreateTextureFromColorDlg                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BEGIN_MESSAGE_MAP(CreateTextureFromColorDlg, CDialog)
	//{{AFX_MSG_MAP(CreateTextureFromColorDlg)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_SAVECLR, OnSaveColorToFile)
	ON_CBN_SELCHANGE(IDC_SAVECLR_SIZELIST, OnSelectSize)
	ON_BN_CLICKED(ID_MATCH_ALL_CLRS, OnSolidColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CreateTextureFromColorDlg::CreateTextureFromColorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CreateTextureFromColorDlg::IDD, pParent),
    bmi(0),
    gmap(0),
    hpal(0),
    m_color(0),
    pDoc(0)
{
	//{{AFX_DATA_INIT(CreateTextureFromColorDlg)
	m_height = 0;
	m_width = 0;
    m_size = -1;
	//}}AFX_DATA_INIT

    m_size = 4;

    for (int i=0; i<4; i++)
        colors[i] = 0;

    bm = new XFBitmap;
}

CreateTextureFromColorDlg::~CreateTextureFromColorDlg()
{
    bm->release();
    delete bm;
}

void CreateTextureFromColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CreateTextureFromColorDlg)
	DDX_Control(pDX, IDC_SAVECLR_SIZELIST, m_listbox);
	DDX_Control(pDX, IDC_BITMAP2, m_bitmap);
	DDX_Text(pDX, IDC_TVIEW_HEIGHT, m_height);
	DDV_MinMaxUInt(pDX, m_height, 0, 65535);
	DDX_Text(pDX, IDC_TVIEW_WIDTH, m_width);
	DDV_MinMaxUInt(pDX, m_width, 0, 65535);
    DDX_CBIndex(pDX, IDC_SAVECLR_SIZELIST, m_size);
	//}}AFX_DATA_MAP

}

void CreateTextureFromColorDlg::setup(TerrEditDoc *pd)
{
    pDoc = pd;
    ASSERT(pDoc);
}

void CreateTextureFromColorDlg::release_dib()
{
    if (bmi)
    {
        delete bmi;
        bmi = 0;
    }

    if (gmap)
    {
        delete [] gmap;
        gmap = 0;
    }
}

void CreateTextureFromColorDlg::do_image_smoothing(XFBitmap *bm)
{

    int w = bm->width;
    int h = bm->height;

    VngoRect vprect(0, 0, w, h);

    VngoVVport8 *vp = new VngoVVport8(vprect, &(pDoc->palette), 0);

    if (vp) 
    {
        vp->lock();

        VngoPoint vpoints[4];

        dword t = pDoc->palette.shd_pal->mid_point + 1;

        vpoints[0].x = 0;
        vpoints[0].y = 0;
        vpoints[0].clr = colors[0];
        vpoints[0].shade = t;

        vpoints[1].x = w - 1;
        vpoints[1].y = 0;
        vpoints[1].clr = colors[1];
        vpoints[1].shade = t;

        vpoints[2].x = w - 1;
        vpoints[2].y = h - 1;
        vpoints[2].clr = colors[3];
        vpoints[2].shade = t;

        vpoints[3].x = 0;
        vpoints[3].y = h - 1 ;
        vpoints[3].clr = colors[2];
        vpoints[3].shade = t;

        vngo_smooth_rect(vp, vpoints);
        
        memcpy (bm->data, vp->vbuff.scrn_ptr, sizeof(BYTE) * w * h);

        vp->unlock();

        delete vp;
        vp = 0;
    }
}

BOOL CreateTextureFromColorDlg::create_bitmap_from_DIB(XFBitmap *bm, BYTE *gptr,
                                                        int w, int h, int bpp)
{

    bm->release();

    bm->bpp = bpp;
    bm->width = w;
    bm->height = h;
    bm->clrinuse = 255;

    // Allocate memory
    bm->palhandle = ivory_halloc(sizeof(dword)*256);
    if (!bm->palhandle)
    {
        return FALSE;
    }

    // Allocate memory
    bm->handle = ivory_halloc(bm->width * bm->height * bm->bpp);
    if (!bm->handle)
    {
        bm->release();
        return FALSE;
    }

    bm->lock();

    VngoColor24bit tclr;
    for (int i=0; i < 256; i++)
    {
        tclr = pDoc->palette.get_RGB(i);
        bm->pal[i] = (dword)(tclr.r | (tclr.g << 8) | (tclr.b << 16));
    }

    memset(bm->data, m_color, bm->bpp * h * w);

    bm->unlock();
    return TRUE;
}

void CreateTextureFromColorDlg::setup_dib()
{
    int h, w;

    switch(m_size)
    {
        case 0: 
            w = h = 16;
            break;

        case 1: 
            w = h = 32;
            break;

        case 2: 
            w = h = 64;
            break;

        case 3: 
            w = h = 128;
            break;

        case 4: 
            w = h = 256;
            break;

        default:
            w = h = 256;
    }

    m_width = w;
    m_height = h;

    UpdateData(FALSE);

//ÄÄÄ Create Bitmap
    bmi = (LPBITMAPINFO) new byte[sizeof(BITMAPINFOHEADER)
                                               + (256*sizeof(WORD))];
    ASSERT(bmi);
    memset(bmi, 0, sizeof(*bmi));
    bmi->bmiHeader.biSize         = sizeof (BITMAPINFOHEADER);
    bmi->bmiHeader.biWidth        = w;
    bmi->bmiHeader.biHeight       = -h;
    bmi->bmiHeader.biPlanes       = 1;
    bmi->bmiHeader.biBitCount     = 8;
    bmi->bmiHeader.biCompression  = BI_RGB;
    bmi->bmiHeader.biClrUsed      = 256;
    bmi->bmiHeader.biClrImportant = 256;
    for(int i=0; i < 256; i++)
        ((WORD*)bmi->bmiColors)[i] = (WORD)i;

    int sizeof_gmap = w*h;
    gmap = new BYTE [sizeof_gmap];
    ASSERT(gmap);

    memset(gmap, 0, sizeof_gmap);

    if (create_bitmap_from_DIB(bm, gmap, w, h, 1))
    {
        bm->lock();

        // Modify the bitmap to have the tranparent color smoothing
        do_image_smoothing(bm);
    
        // copy the bitmap data back into the DIB so we can display it
        memcpy(gmap, bm->data, sizeof(BYTE) * w * h);
    
        bm->unlock();
    }
    else
    {
        release_dib();
    }
}

void CreateTextureFromColorDlg::draw_selection_boxes(CPaintDC *pdc)
{
    reg[0].left = x - 15;
    reg[0].top  = y - 15;
    reg[0].right = reg[0].left + 10;
    reg[0].bottom = reg[0].top + 10;

    reg[1].left = (x+ m_width) + 5;
    reg[1].top  = y - 15;
    reg[1].right = reg[1].left + 10;
    reg[1].bottom = reg[1].top + 10;

    reg[2].left = x - 15;
    reg[2].top  = (y + m_height) + 5;
    reg[2].right = reg[2].left + 10;
    reg[2].bottom = reg[2].top + 10;

    reg[3].left = (x + m_width) + 5;
    reg[3].top  = (y + m_height) + 5;
    reg[3].right = reg[3].left + 10;
    reg[3].bottom = reg[3].top + 10;

    CBrush br;
    CBrush *old_brush;
    br.CreateSolidBrush(PALETTEINDEX(colors[0]));
    old_brush = pdc->SelectObject(&br);

    pdc->FillRect(&reg[0], &br);

    pdc->SelectObject(old_brush);
    br.DeleteObject();

    br.CreateSolidBrush(PALETTEINDEX(colors[1]));
    old_brush = pdc->SelectObject(&br);

    pdc->FillRect(&reg[1], &br);

    pdc->SelectObject(old_brush);
    br.DeleteObject();

    br.CreateSolidBrush(PALETTEINDEX(colors[2]));
    old_brush = pdc->SelectObject(&br);

    pdc->FillRect(&reg[2], &br);

    pdc->SelectObject(old_brush);
    br.DeleteObject();

    br.CreateSolidBrush(PALETTEINDEX(colors[3]));
    old_brush = pdc->SelectObject(&br);

    pdc->FillRect(&reg[3], &br);

    pdc->SelectObject(old_brush);
    br.DeleteObject();
}

void CreateTextureFromColorDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

    setup_dib();

    CRect rect;
    m_bitmap.GetClientRect(&rect);
    m_bitmap.MapWindowPoints(this,rect);

    x = rect.left + ((rect.right - rect.left + 1) - m_width) / 2;
    y = rect.top + ((rect.bottom - rect.top + 1) - m_height) / 2;

    if (hpal)
    {
        SelectPalette(dc.m_hDC,hpal,0);
        dc.RealizePalette();
    }

    if (bmi && gmap)
    {
        SetDIBitsToDevice(dc.m_hDC,
                          x, y,
                          bmi->bmiHeader.biWidth, -bmi->bmiHeader.biHeight,
                          0, 0, 0, -bmi->bmiHeader.biHeight,
                          gmap,
                          bmi,
                          DIB_PAL_COLORS);
    }
    release_dib();

    // Draw the color selection boxes
    draw_selection_boxes(&dc);
}

void CreateTextureFromColorDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
    int x1 = point.x;
    int y1 = point.y;

    int region = -1;

    if ( (x1 >= reg[0].left) && (x1 <= reg[0].right) && (y1 >= reg[0].top) && (y1 <= reg[0].bottom) )
        region = 0;
    else if ( (x1 >= reg[1].left) && (x1 <= reg[1].right) && (y1 >= reg[1].top) && (y1 <= reg[1].bottom) )
        region = 1;
    else if ( (x1 >= reg[2].left) && (x1 <= reg[2].right) && (y1 >= reg[2].top) && (y1 <= reg[2].bottom) )
        region = 2;
    else if ( (x1 >= reg[3].left) && (x1 <= reg[3].right) && (y1 >= reg[3].top) && (y1 <= reg[3].bottom) )
        region = 3;                                                  

    if (region != -1) 
    {
        ColorSelectPropPage dlga;

        dlga.palette = &pDoc->palette;
        dlga.color = colors[region];

        ShadeReviewPropPage dlgb;
        dlgb.palette = dlga.palette;
        dlgb.color = dlga.color;

        dlga.setup(0,&dlgb);

        CPropertySheet sh("Color Select");

        sh.AddPage(&dlga);      // Select Color
        sh.AddPage(&dlgb);      // Shade Review

        if (sh.DoModal() == IDOK)
        {
            colors[region] = dlga.color;
            Invalidate();
            RedrawWindow();
        }
    }

	CDialog::OnLButtonDown(nFlags, point);
}

void CreateTextureFromColorDlg::OnSelectSize() 
{
    m_size = m_listbox.GetCurSel();
    RedrawWindow();	
}

void CreateTextureFromColorDlg::OnSolidColor() 
{
    ColorSelectPropPage dlga;

    dlga.palette = &pDoc->palette;
    dlga.color = m_color;

    ShadeReviewPropPage dlgb;
    dlgb.palette = dlga.palette;
    dlgb.color = dlga.color;

    dlga.setup(0,&dlgb);

    CPropertySheet sh("Color Select");

    sh.AddPage(&dlga);      // Select Color
    sh.AddPage(&dlgb);      // Review Shade

    if (sh.DoModal() == IDOK)
    {
        for (int i=0; i < 4; i++)
            colors[i] = dlga.color;

        Invalidate();
        RedrawWindow();
    }
}

void CreateTextureFromColorDlg::OnSaveColorToFile() 
{
    CString filename;

    CFileDialog dlg(TRUE,
                    NULL, filename, OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
                    "Bitmap files (*.bmp;*.cel;*.lbm;*.pcx;*.tga)|*.BMP;*.CEL;*.LBM;*.PCX;*.TGA|"
                    "Windows Bitmap files (*.bmp)|*.BMP|"
                    "Autodesk CEL files (*.cel)|*.CEL|"
                    "DPaint/EA LBM files (*.lbm)|*.LBM|"
                    "Zsoft PCX files (*.pcx)|*.PCX|"
                    "Targa files (*.tga)|*.TGA|"
                    "All files (*.*)|*.*||",
                    this);


    dlg.m_ofn.lpstrTitle = "Save New Color as Texture";

    if (dlg.DoModal() == IDOK)
    {
        filename = dlg.GetPathName();
        
        char buff[256];
        // make sure that the filename has an extension!
        strcpy(buff, (LPCSTR)filename);

        if (!strstr(buff, "."))
        {
            strcat(buff,".bmp");
            filename = buff;
        }

        theApp.SaveImage((LPCTSTR)filename, bm);
        m_fname = filename;
    }
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Texture Properties °°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TxtPropGenPage                                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(TxtPropGenPage, CPropertyPage)

BEGIN_MESSAGE_MAP(TxtPropGenPage, CPropertyPage)
    //{{AFX_MSG_MAP(TxtPropGenPage)
    ON_BN_CLICKED(IDC_TXTPRP_BROWSE, OnBrowse)
    ON_BN_CLICKED(IDC_TXTPRP_VIEW, OnView)
    ON_BN_CLICKED(IDC_TXTPRP_COLR, OnColor)
    ON_BN_CLICKED(IDC_TXTPRP_MAKENEW, OnCreateNewTexture)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

TxtPropGenPage::TxtPropGenPage()
    : CPropertyPage(TxtPropGenPage::IDD),
    pDoc(0),
    iNDex(-1),
    m_color(0x808080)
{
    //{{AFX_DATA_INIT(TxtPropGenPage)
    m_name = _T("");
    m_fname = _T("");
	//}}AFX_DATA_INIT

    for (int i=0; i < 4; i++)
        colors[i] = 0;

}

TxtPropGenPage::~TxtPropGenPage()
{
}

void TxtPropGenPage::setup(TerrEditDoc *pd, int i)
{
    pDoc = pd;
    iNDex = i;
    ASSERT(pDoc);
}

void TxtPropGenPage::DoDataExchange(CDataExchange* pDX)
{
    int i;

    CPropertyPage::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(TxtPropGenPage)
    DDX_Text(pDX, IDC_TXPRP_NAME, m_name);
    DDV_MaxChars(pDX, m_name, 15);
    DDX_Text(pDX, IDC_TXTPRP_FILE, m_fname);
    DDV_MaxChars(pDX, m_fname, 255);
	//}}AFX_DATA_MAP

    if (pDX->m_bSaveAndValidate)
    {
        pDX->PrepareEditCtrl(IDC_TXPRP_NAME);
        if (!*m_name)
        {
            AfxMessageBox("Texture name must be given.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
        else
        {
            for(i=0; i < pDoc->txtNumb; i++)
            {
                if (iNDex == i)
                    continue;

                if (!pDoc->txtName[i].CompareNoCase(m_name))
                {
                    AfxMessageBox("Texture name must be unique.",MB_OK | MB_ICONEXCLAMATION);
                    pDX->Fail();
                    break;
                }
            }
        }

        pDX->PrepareEditCtrl(IDC_TXTPRP_FILE);
        if (!*m_fname)
        {
            AfxMessageBox("Texture filename must be given.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
        else if (!xf_exist(m_fname))
        {
            AfxMessageBox("Texture file must exist.",MB_OK | MB_ICONEXCLAMATION);
            pDX->Fail();
        }
        else
        {
            XFBitmap bm;

            if (theApp.LoadImage((LPCSTR)m_fname,&bm))
            {
                switch (bm.width)
                {
                    case 16:
                    case 32:
                    case 64:
                    case 128:
                    case 256:
                        break;
                    default:
                        AfxMessageBox("Bitmap file must be 16, 32, 64, 128, or 256 pixels in width.",
                                      MB_OK | MB_ICONEXCLAMATION);
                        pDX->Fail();
                }

                switch (bm.height)
                {
                    case 16:
                    case 32:
                    case 64:
                    case 128:
                    case 256:
                        break;
                    default:
                        AfxMessageBox("Bitmap file must be 16, 32, 64, 128, or 256 pixels in height.",
                                      MB_OK | MB_ICONEXCLAMATION);
                        pDX->Fail();
                }
            }
        }
    }
}

void TxtPropGenPage::OnBrowse() 
{
    CFileDialog dlg(TRUE,
                    NULL, m_fname, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
                    "Bitmap files (*.bmp;*.cel;*.lbm;*.pcx;*.tga)|*.BMP;*.CEL;*.LBM;*.PCX;*.TGA|"
                    "Windows Bitmap files (*.bmp)|*.BMP|"
                    "Autodesk CEL files (*.cel)|*.CEL|"
                    "DPaint/EA LBM files (*.lbm)|*.LBM|"
                    "Zsoft PCX files (*.pcx)|*.PCX|"
                    "Targa files (*.tga)|*.TGA|"
                    "All files (*.*)|*.*||",
                    this);

    dlg.m_ofn.lpstrTitle = "Texture Bitmap File";

    if (dlg.DoModal() == IDOK)
    {
        // Need to check bitmap file for proper size/load support!

        HWND    hWndName = ::GetDlgItem(GetSafeHwnd(),IDC_TXPRP_NAME);
        char    txtName[32];

        ::GetWindowText(hWndName, txtName, sizeof(txtName));

        m_fname = dlg.GetPathName();
        UpdateData(FALSE);

        ::SetWindowText(hWndName, txtName);
    }
}

void TxtPropGenPage::OnView()
{
    if (!UpdateData(TRUE))
        return;

//ÄÄÄ Load Bitmap
    XFBitmap bm;

    if (!theApp.LoadImage((LPCTSTR)m_fname,&bm))
        return;

//ÄÄÄ Create Bitmap
    LPBITMAPINFO bmi = (LPBITMAPINFO) new byte[sizeof(BITMAPINFOHEADER)
                                               + (256*sizeof(WORD))];
    ASSERT(bmi);
    memset(bmi, 0, sizeof(*bmi));
    bmi->bmiHeader.biSize         = sizeof (BITMAPINFOHEADER);
    bmi->bmiHeader.biWidth        = bm.width;
    bmi->bmiHeader.biHeight       = -bm.height;
    bmi->bmiHeader.biPlanes       = 1;
    bmi->bmiHeader.biBitCount     = 8;
    bmi->bmiHeader.biCompression  = BI_RGB;
    bmi->bmiHeader.biClrUsed      = 256;
    bmi->bmiHeader.biClrImportant = 256;
    for(int i=0; i < 256; i++)
        ((WORD*)bmi->bmiColors)[i] = (WORD)i;

    int sizeof_gmap = (((bm.width)+3) & ~0x3) * bm.height;
    BYTE *gmap = new BYTE [sizeof_gmap];
    ASSERT(gmap);

    memset(gmap,(byte)pDoc->palette.get_index((VngoColor24bit)m_color),sizeof_gmap);
    bm.lock();
    ASSERT(bm.data != 0);
    BYTE *dptr=gmap;
    BYTE *sptr=bm.data;

    if (bm.bpp == 1)
    {
        byte mypal[256];

        for(i=0; i < 256; i++)
        {
            mypal[i] = (byte)pDoc->palette.get_index((VngoColor24bit)bm.pal[i]);
        }
        // Force transparency to remain transparent.....
        mypal[255] = 255;

        for(int y=0; y < bm.height; y++)
        {
            for(int x=0; x < bm.width; x++)
            {
                if (mypal[*(sptr)] != 255)
                    *(dptr++) = mypal[*(sptr++)];
                else
                {
                    dptr++;
                    sptr++;
                }
                ASSERT(dptr <= (gmap + ((bm.width+3) & ~0x3)*bm.height));
            }
            int skip = (bm.width & 0x3);
            if (skip)
                dptr += (4-skip);
        }
    }
    else
    {
        VngoColor24bit  clr;

        ASSERT(bm.bpp == 3);
        for(int y=0; y < bm.height; y++)
        {
            for(int x=0; x < bm.width; x++)
            {
                clr.r = *(sptr++);
                clr.g = *(sptr++);
                clr.b = *(sptr++);
                if (clr.r == 255 && clr.g == 0 & clr.b == 255)
                {   // If it is the transparent color skip it.
                    dptr++;
                }
                else
                {
                    *(dptr++) = (byte)pDoc->palette.get_index(clr);
                }
                ASSERT(dptr <= (gmap + ((bm.width+3) & ~0x3)*bm.height));
            }
            int skip = (bm.width & 0x3);
            if (skip)
                dptr += (4-skip);
        }
    }
    bm.unlock();

//ÄÄÄ Create dialog
    TextureViewDlg  dlg;

    dlg.m_width = bm.width;
    dlg.m_height = bm.height;
    dlg.bmi = bmi;
    dlg.gmap = gmap;

    assert(pDoc != NULL);
    dlg.hpal = pDoc->hpal;

//ÄÄÄ Handle interaction
    dlg.DoModal();

//ÄÄÄ Cleanup
    delete bmi;
    delete gmap;
}

void TxtPropGenPage::OnColor() 
{
    ColorSelectPropPage dlga;

    dlga.palette = &pDoc->palette;
    dlga.color = pDoc->palette.get_index(m_color);

    ShadeReviewPropPage dlgb;
    dlgb.palette = dlga.palette;
    dlgb.color = dlga.color;

    dlga.setup(0,&dlgb);

    CPropertySheet sh("Color Select");

    sh.AddPage(&dlga);      // Select Color
    sh.AddPage(&dlgb);      // Review Shade

    if (sh.DoModal() == IDOK)
    {
        VngoColor24bit tclr = dlga.palette->get_RGB(dlga.color);
        m_color = ((dword)tclr.b << 16) | ((dword)tclr.g << 8) | (dword)tclr.r;
    }
}

void TxtPropGenPage::OnCreateNewTexture() 
{
    if (!*m_fname)
    {
        CreateTextureAskDlg dlg;
        
        int res = dlg.DoModal();

        if (res == CREATE_ASK_FILE)
        {
            CFileDialog dlg(TRUE,
                            NULL, m_fname, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
                            "Bitmap files (*.bmp;*.cel;*.lbm;*.pcx;*.tga)|*.BMP;*.CEL;*.LBM;*.PCX;*.TGA|"
                            "Windows Bitmap files (*.bmp)|*.BMP|"
                            "Autodesk CEL files (*.cel)|*.CEL|"
                            "DPaint/EA LBM files (*.lbm)|*.LBM|"
                            "Zsoft PCX files (*.pcx)|*.PCX|"
                            "Targa files (*.tga)|*.TGA|"
                            "All files (*.*)|*.*||",
                            this);
        
            dlg.m_ofn.lpstrTitle = "Texture Bitmap File";
        
            if (dlg.DoModal() == IDOK)
            {
                // Create a CreateTextureDlg instance so we can use its
                // member function check_bitmap_size() on the new filename...
                CreateTextureDlg  tempdlg;
                CString temp;
                
                temp = dlg.GetPathName();
                if (tempdlg.check_bitmap_size((LPCTSTR)temp))
                {
                    // Need to check bitmap file for proper size/load support!

                    HWND    hWndName = ::GetDlgItem(GetSafeHwnd(),IDC_TXPRP_NAME);
                    char    txtName[32];
            
                    ::GetWindowText(hWndName, txtName, sizeof(txtName));

                    m_fname = temp;
                    UpdateData(FALSE);

                    ::SetWindowText(hWndName, txtName);
                }
                else 
                    return;
            }
            else
                return;

        }
        else if (res == CREATE_ASK_COLOR)
        {
            // we want to create a texture from a color!
            CreateTextureFromColorDlg dlg;
        
            dlg.setup(pDoc);
            dlg.hpal = pDoc->hpal;
            dlg.m_color = 0;
            for (int i=0; i<4; i++)
                dlg.colors[i] = 0;
            dlg.m_width = 256;
            dlg.m_height = 256;
        
            dlg.DoModal();     

            HWND    hWndName = ::GetDlgItem(GetSafeHwnd(),IDC_TXPRP_NAME);
            char    txtName[32];
    
            ::GetWindowText(hWndName, txtName, sizeof(txtName));

            m_fname = dlg.m_fname;
            UpdateData(FALSE);
        
            ::SetWindowText(hWndName, txtName);

            return;                
        }
        else if (res == IDCANCEL)
            return;
    }

    //ÄÄÄ Create dialog
    CreateTextureDlg  dlg;
    dlg.setup(pDoc);

    XFBitmap bm;
    if (!theApp.LoadImage((LPCSTR)m_fname,&bm))
        return;

    dlg.m_width = bm.width;
    dlg.m_height = bm.width;
    dlg.dib_fname = m_fname;
   
    for (int i=0; i <4; i++)
        colors[i] = pDoc->palette.get_index((VngoColor24bit)m_color);

    for (i=0;i<4;i++)
        dlg.colors[i] = colors[i];

    assert(pDoc != NULL);
    dlg.hpal = pDoc->hpal;

    //ÄÄÄ Handle interaction
    
    HWND    hWndName = ::GetDlgItem(GetSafeHwnd(),IDC_TXPRP_NAME);
    char    txtName[32];

    ::GetWindowText(hWndName, txtName, sizeof(txtName));

    if (dlg.DoModal()== IDOK)
    {
        for (int i=0;i<4;i++)
            colors[i] = dlg.colors[i];
                
        m_fname = dlg.dib_fname;
        UpdateData(FALSE);
    }
    else
    {
        UpdateData(FALSE);
    }

    ::SetWindowText(hWndName, txtName);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TxtPropSFlagsPage                                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
IMPLEMENT_DYNCREATE(TxtPropSFlagsPage, CPropertyPage)

BEGIN_MESSAGE_MAP(TxtPropSFlagsPage, CPropertyPage)
    //{{AFX_MSG_MAP(TxtPropSFlagsPage)
    ON_BN_CLICKED(IDC_TXTPRP_RESETUSAGE, OnResetUsage)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

TxtPropSFlagsPage::TxtPropSFlagsPage()
    : CPropertyPage(TxtPropSFlagsPage::IDD),
    pDoc(0),
    iNDex(-1),
    m_isnew(0)
{
    //{{AFX_DATA_INIT(TxtPropSFlagsPage)
    m_flipu = FALSE;
    m_flipv = FALSE;
    m_tile = -1;
	m_notile = FALSE;
	m_highonly = FALSE;
	m_app0 = FALSE;
	m_app1 = FALSE;
	m_app2 = FALSE;
	m_app3 = FALSE;
	//}}AFX_DATA_INIT

    m_tile = 0;
}

TxtPropSFlagsPage::~TxtPropSFlagsPage()
{
}

void TxtPropSFlagsPage::setup(TerrEditDoc *pd, int i)
{
    pDoc = pd;
    iNDex = i;
    ASSERT(pDoc);
}

void TxtPropSFlagsPage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(TxtPropSFlagsPage)
    DDX_Control(pDX, IDC_TXTPRP_RESETUSAGE, m_resetCtl);
    DDX_Check(pDX, IDC_TXPRP_FLIPU, m_flipu);
    DDX_Check(pDX, IDC_TXPRP_FLIPV, m_flipv);
    DDX_CBIndex(pDX, IDC_TXPRP_TILE, m_tile);
	DDX_Check(pDX, IDC_TXPROP_NOTILE, m_notile);
	DDX_Check(pDX, IDC_TXPROP_HIGHONLY, m_highonly);
	DDX_Check(pDX, IDC_TXPROP_APP0, m_app0);
	DDX_Check(pDX, IDC_TXPROP_APP1, m_app1);
	DDX_Check(pDX, IDC_TXPROP_APP2, m_app2);
	DDX_Check(pDX, IDC_TXPROP_APP3, m_app3);
	//}}AFX_DATA_MAP

    if (!pDX->m_bSaveAndValidate)
    {
        m_resetCtl.EnableWindow((m_isnew) ? 0 : 1);
    }
}

void TxtPropSFlagsPage::OnResetUsage() 
{
    if (!UpdateData(TRUE))
        return;

    if (MessageBox("This will scan the surface information data and reset\n"
                   "the texture flags to the current settings on this\n"
                   "sheet for any surface point using this texture.\n\n"
                   "Are you sure you wish to proceed?",
                   "Texture Properities",
                   MB_YESNO) != IDYES)
        return;

    assert(pDoc != NULL && pDoc->surfinfo != NULL);

    BOOL changed=FALSE;

    esch_surf_type *surf = pDoc->surfinfo;
    for(long d=0; d < (pDoc->depth >> pDoc->surfshift); d++)
    {
        for( long w=0; w < (pDoc->width >> pDoc->surfshift); w++)
        {
            if (surf->flags & ESCH_SURF_CINDISTXT && surf->cind == iNDex+1)
            {
                if (!changed)
                {
                    pDoc->SetModifiedFlag();
                    changed=TRUE;
                }

                assert(ESCH_SURF_TILE1 == 0x10 && ESCH_SURF_TILE2 == 0x20 && ESCH_SURF_TILE3 == 0x40);

                ushort flags = surf->flags;

                flags &= ~(ESCH_SURF_FLIPU
                           | ESCH_SURF_FLIPV
                           | ESCH_SURF_TILE1
                           | ESCH_SURF_TILE2
                           | ESCH_SURF_TILE3
                           | ESCH_SURF_NOTILE
                           | ESCH_SURF_HIGHONLY
                           | ESCH_SURF_APP0
                           | ESCH_SURF_APP1
                           | ESCH_SURF_APP2
                           | ESCH_SURF_APP3);

                flags |= ((m_flipu) ? ESCH_SURF_FLIPU : 0)
                          | ((m_flipv) ? ESCH_SURF_FLIPV : 0)
                          | ((m_tile << 4) & 0x70)
                          | ((m_notile) ? ESCH_SURF_NOTILE : 0)
                          | ((m_highonly) ? ESCH_SURF_HIGHONLY : 0)
                          | ((m_app0) ? ESCH_SURF_APP0 : 0)
                          | ((m_app1) ? ESCH_SURF_APP1 : 0)
                          | ((m_app2) ? ESCH_SURF_APP2 : 0)
                          | ((m_app3) ? ESCH_SURF_APP3 : 0);

                surf->flags = flags;
            }
            surf++;
        }
    }
}

//°±² eof - eshtdlgt.cpp ²±°
