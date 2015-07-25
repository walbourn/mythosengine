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
// eshtgrid.cpp
//
// Terrain View support class.
//
// The Grid class handles the surface information overhead window.
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
#include "eshtmfrm.h"
#include "eshtview.h"

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
// TerrEditGrid                                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BEGIN_MESSAGE_MAP(TerrEditGrid, CWnd)
        //{{AFX_MSG_MAP(TerrEditGrid)
        ON_WM_PAINT()
        ON_WM_HSCROLL()
        ON_WM_VSCROLL()
        ON_WM_RBUTTONDOWN()
        ON_WM_MOUSEMOVE()
        ON_WM_SIZE()
        ON_WM_LBUTTONDOWN()
        ON_WM_LBUTTONUP()
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
// TerrEditGrid - Constructor                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
TerrEditGrid::TerrEditGrid() :
    mode(SURFDSP_COLORS),
    bmi(0),
    gmap(0),
    pal(0),
    zoomshift(0),
    xpos(0),
    ypos(0),
    rectactive(FALSE),
    a_method(NONE)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - Destructor                                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
TerrEditGrid::~TerrEditGrid()
{
    release_vport();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Operations °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                            ²²² Protected ²²²                             ³
// TerrEditGrid - setup_vport                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                            ²²² Protected ²²²                             ³
// TerrEditGrid - release_vport                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - SetSurfaceSize                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::SetSurfaceSize(int w, int d)
{
    if (w == width && d == depth)
        return;

    setup_vport(w, d);

    width = w;
    depth = d;

    SetPosition(0,0);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - UpdateSurfaceColors                                       ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::UpdateSurfaceColors()
{
    int             x, y, i;
    esch_surf_type  *sptr;
    byte            *dptr;

//ÄÄÄ Check for valid setup
    if (!width || !depth || !gmap)
        return;

    TerrEditDoc* pDoc = (TerrEditDoc *) ((CView*)GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

    if (!pDoc->surfinfo)
        return;

    if ((width != (pDoc->width >> pDoc->surfshift)) || (depth != (pDoc->depth >> pDoc->surfshift)))
        return;

//ÄÄÄ Ensure shades are up-to-date
    pDoc->LightTerrain();

//ÄÄÄ Create display DIB from terrain data
    VngoShadePal8 *shade=(VngoShadePal8*)pDoc->palette.shd_pal;
    byte black = (byte)pDoc->palette.get_index(VngoColor24bit(0,0,0));

    if (mode == SURFDSP_HGT)
    {
        byte bcolor;
        byte colors[10];

        bcolor = (byte)pDoc->palette.get_index (VngoColor24bit (128, 0, 254));
        colors[0] = (byte)pDoc->palette.get_index (VngoColor24bit (0, 0, 255));
        colors[1] = (byte)pDoc->palette.get_index (VngoColor24bit (0, 100, 255));
        colors[2] = (byte)pDoc->palette.get_index (VngoColor24bit (255, 255, 255));
        colors[3] = (byte)pDoc->palette.get_index (VngoColor24bit (0, 120, 0));
        colors[4] = (byte)pDoc->palette.get_index (VngoColor24bit (0, 185, 0)); 
        colors[5] = (byte)pDoc->palette.get_index (VngoColor24bit (255, 255, 0));
        colors[6] = (byte)pDoc->palette.get_index (VngoColor24bit (254, 185, 0));
        colors[7] = (byte)pDoc->palette.get_index (VngoColor24bit (255, 128, 0));
        colors[8] = (byte)pDoc->palette.get_index (VngoColor24bit (178, 122, 0));
        colors[9] = (byte)pDoc->palette.get_index (VngoColor24bit (107, 68, 0));
        colors[10] = (byte)pDoc->palette.get_index (VngoColor24bit (255, 0,  0));

        //
        // Assign colors to height values
        //

        byte hgts_color[256];
        for(i=0; i < 256; i++)
        {
            hgts_color[i] = bcolor;
            for(int j=10; j >= 0; j--)
            {
                if (pDoc->htable[i] > float(pDoc->color_bands[j]))
                {
                    hgts_color[i] = colors[j];
                    break;
                }
            }
        }

        //
        // Update DIB
        //

        int scanw = width + ((width & 0x3) ? (4-(width & 0x3)) : 0);

        for(y=0, sptr=pDoc->surfinfo, dptr=gmap;
            y < depth; y++)
        {
            dptr = gmap + (scanw * (depth - y - 1)); 

            for(x=0; x < width; x++)
            {
                byte *hptr = pDoc->hfield
                             + ((y << pDoc->surfshift)*(width << pDoc->surfshift))
                             + (x << pDoc->surfshift);

                *(dptr++) = shade->get_shaded_index(hgts_color[*hptr],(sptr++)->shd);
            }
        }
    }
    else if (mode == SURFDSP_APPBITS)
    {
        int scanw = width + ((width & 0x3) ? (4-(width & 0x3)) : 0);

        assert(ESCH_SURF_APP0 == 0x1000
               && ESCH_SURF_APP1 == 0x2000
               && ESCH_SURF_APP2 == 0x4000
               && ESCH_SURF_APP3 == 0x8000);

        VngoPal *pal = &pDoc->palette;
        byte colors[16] =
        { 
            (byte)pal->get_index(VngoColor24bit(64, 64, 64)), // NONE
            (byte)pal->get_index(VngoColor24bit(255,0,  0)),  // A0
            (byte)pal->get_index(VngoColor24bit(0,  255,0)),  // A1
            (byte)pal->get_index(VngoColor24bit(255,255,0)),  // A1,A0
            (byte)pal->get_index(VngoColor24bit(0,  0,  255)),// A2
            (byte)pal->get_index(VngoColor24bit(255,0,  255)),// A2,A0
            (byte)pal->get_index(VngoColor24bit(0,  255,255)),// A2,A1
            (byte)pal->get_index(VngoColor24bit(255,255,128)),// A2,A1,A0
            (byte)pal->get_index(VngoColor24bit(128,128,128)),// A3
            (byte)pal->get_index(VngoColor24bit(128,0,  0)),  // A3,A0
            (byte)pal->get_index(VngoColor24bit(0,  128,0)),  // A3,A1
            (byte)pal->get_index(VngoColor24bit(128,128,0)),  // A3,A1,A0
            (byte)pal->get_index(VngoColor24bit(0,  0,  128)),// A3,A2
            (byte)pal->get_index(VngoColor24bit(128,0,  128)),// A3,A2,A0
            (byte)pal->get_index(VngoColor24bit(0,  128,128)),// A3,A2,A1
            (byte)pal->get_index(VngoColor24bit(255,255,255)),// A3,A2,A1,A0
        };

        for(y=0, sptr=pDoc->surfinfo, dptr=gmap; y < depth; y++)
        {
            dptr = gmap + (scanw * (depth - y - 1)); 

            for(x=0; x < width; x++)
            {
                *(dptr++) = shade->get_shaded_index
                                    (colors[(sptr->flags
                                                 & (ESCH_SURF_APP0
                                                   | ESCH_SURF_APP1
                                                   | ESCH_SURF_APP2
                                                   | ESCH_SURF_APP3)) >> 12],
                                     sptr->shd);
                sptr++;
            }
        }
    }
    else
    {
        int scanw = width + ((width & 0x3) ? (4-(width & 0x3)) : 0);

        for(y=0, sptr=pDoc->surfinfo, dptr=gmap; y < depth; y++)
        {
            dptr = gmap + (scanw * (depth - y - 1)); 

            for(x=0; x < width; x++)
            {
                byte color;

                if ((sptr->flags & ESCH_SURF_CINDISTXT) && sptr->cind)
                {
                    ASSERT((sptr->cind-1) < pDoc->txtNumb);

                    color = pDoc->txtColrIndx[sptr->cind-1];
                }
                else if (mode == SURFDSP_TXTONLY)
                {
                    color = black;
                }
                else
                {    
                    color = sptr->cind;
                }

                if (mode == SURFDSP_SHADED)
                {
                    color = shade->get_shaded_index(color,sptr->shd);
                }

                *(dptr++) = color;
                sptr++;
            }
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - SetZoomLevel                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - SetPosition                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
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

    if (m_hWnd)
        RedrawWindow();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - SetMode                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::SetMode(surfdisp_mode_type m)
{
    if (m == mode)
        return;

    mode = m;

    char *str = "Surface Information Grid - ?";

    switch (m)
    {
        case SURFDSP_COLORS:
            str = "Surface Information Grid - Colors";
            break;
        case SURFDSP_SHADED:
            str = "Surface Information Grid - Shaded Colors";
            break;
        case SURFDSP_HGT:
            str = "Surface Information Grid - Height-based Colors";
            break;
        case SURFDSP_TXTONLY:
            str = "Surface Information Grid - Texture Colors Only";
            break;
        case SURFDSP_APPBITS:
            str = "Surface Information Grid - Application Bits";
            break;
    }

    SetWindowText(str);

    UpdateSurfaceColors();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                             °°° Protected °°°                            ³
// TerrEditGrid::randomize                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::randomize()
{
    long val = (long)chronos_time_now();

    byte b1 = (byte)(val & 0x000000ff);
    byte b2 = (byte)((val & 0x0000ff00) >> 8);
    byte b3 = (byte)((val & 0x00ff0000) >> 16);
    byte b4 = (byte)((val & 0xff000000) >> 24);
    val = (b2 << 24) | (b4 << 16) | (b3 << 8) | (b1);

    flx_srand(val & 0xffff0000, val & 0x0000ffff);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                             °°° Protected °°°                            ³
// TerrEditGrid - assign_by_height                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::assign_by_height(TerrEditDoc* pDoc,
                                    int xspos, int dspos, BOOL &changed)
{
    ASSERT(pDoc && pDoc->hfield && pDoc->htable && pDoc->surfinfo);

//ÄÄÄ Compute surface info pointer
    esch_surf_type *surf = pDoc->surfinfo + ((dspos*width) + xspos);

    if (a_preserve && surf->flags & ESCH_SURF_CINDISTXT)
        return;

//ÄÄÄ Lookup height
    ulong surfshift = pDoc->surfshift;
    float h = pDoc->htable[*(pDoc->hfield
                             + (dspos << surfshift)*(width << surfshift)
                             + (xspos << surfshift))];

//ÄÄÄ Check to see if point fullfills criteria
    if (h >= a_values[0] && h < a_stop)
    {
        if (!changed)
        {
            pDoc->PushUndo();
            changed=TRUE;
        }

        for(ulong i=0; i < a_count-1; i++)
        {
            if (h < a_values[i+1])
                break;
        }

        dword tflags = 0;
        dword color = 0;
        byte cind = 0;

        if (a_istxt[i])
        {
            cind = a_tc[i] + 1;
            tflags = ESCH_SURF_CINDISTXT | pDoc->txtDFlags[a_tc[i]];
        }
        else
        {
            cind = pDoc->colorColrIndx[a_tc[i]];
            color = pDoc->colorColr[a_tc[i]];
            tflags = pDoc->colorDFlags[a_tc[i]];
        }

        assert(ESCH_SURF_TILE1 == 0x10 && ESCH_SURF_TILE2 == 0x20 && ESCH_SURF_TILE3 == 0x40);
        surf->flags &= ~(ESCH_SURF_FLIPU
                         | ESCH_SURF_FLIPV
                         | ESCH_SURF_CINDISTXT
                         | ESCH_SURF_TILE1
                         | ESCH_SURF_TILE2
                         | ESCH_SURF_TILE3
                         | ESCH_SURF_NOTILE
                         | ESCH_SURF_HIGHONLY
                         | ESCH_SURF_APP0
                         | ESCH_SURF_APP1
                         | ESCH_SURF_APP2
                         | ESCH_SURF_APP3);

        surf->flags |= tflags;
        surf->cind = cind;

        if (!(tflags & ESCH_SURF_CINDISTXT))
        {
            dword *colr = pDoc->surfcolr + ((dspos*width) + xspos);
            *colr = color;
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                             °°° Protected °°°                            ³
// TerrEditGrid - assign_by_random_roll                                     ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::assign_by_random_roll(TerrEditDoc* pDoc,
                                         int xspos, int dspos, BOOL &changed)
{
    ASSERT(pDoc && pDoc->hfield && pDoc->htable && pDoc->surfinfo);

//ÄÄÄ Compute surface info pointer
    esch_surf_type *surf = pDoc->surfinfo + ((dspos*width) + xspos);

    if (a_preserve && surf->flags & ESCH_SURF_CINDISTXT)
        return;

//ÄÄÄ Test for elevation cutoff
    if (a_elvcutoff)
    {
        ulong surfshift = pDoc->surfshift;
        float h = pDoc->htable[*(pDoc->hfield
                                 + (dspos << surfshift)
                                   *(width << surfshift)
                                 + (xspos << surfshift))];

        if (h < a_elvlow || h > a_elvhigh)
            return;
    }

//ÄÄÄ Perform roll
    int roll = ((int)flx_rand()) % 100;
    if (roll < 0)
        roll = abs(roll);

    if (roll >= a_values_int[0])
    {
        if (!changed)
        {
            pDoc->PushUndo();
            changed=TRUE;
        }

        for(ulong i=0; i < a_count-1; i++)
        {
            if (roll < a_values_int[i+1])
                break;
        }

        dword tflags = 0;
        dword color = 0;
        byte cind = 0;

        if (a_istxt[i])
        {
            cind = a_tc[i] + 1;
            tflags = ESCH_SURF_CINDISTXT | pDoc->txtDFlags[a_tc[i]];
        }
        else
        {
            cind = pDoc->colorColrIndx[a_tc[i]];
            color = pDoc->colorColr[a_tc[i]];
            tflags = pDoc->colorDFlags[a_tc[i]];
        }

        assert(ESCH_SURF_TILE1 == 0x10 && ESCH_SURF_TILE2 == 0x20 && ESCH_SURF_TILE3 == 0x40);
        surf->flags &= ~(ESCH_SURF_FLIPU
                         | ESCH_SURF_FLIPV
                         | ESCH_SURF_CINDISTXT
                         | ESCH_SURF_TILE1
                         | ESCH_SURF_TILE2
                         | ESCH_SURF_TILE3
                         | ESCH_SURF_NOTILE
                         | ESCH_SURF_HIGHONLY
                         | ESCH_SURF_APP0
                         | ESCH_SURF_APP1
                         | ESCH_SURF_APP2
                         | ESCH_SURF_APP3);

        surf->flags |= tflags;
        surf->cind = cind;

        if (!(tflags & ESCH_SURF_CINDISTXT))
        {
            dword *colr = pDoc->surfcolr + ((dspos*width) + xspos);
            *colr = color;
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                             °°° Protected °°°                            ³
// TerrEditGrid - assign_by_angle                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::assign_by_angle(TerrEditDoc* pDoc,
                                   int xspos, int dspos, BOOL &changed)
{
    ASSERT(pDoc && pDoc->hfield && pDoc->htable && pDoc->surfinfo && pDoc->hsurfnormlflat);

//ÄÄÄ Compute surface info pointer
    esch_surf_type *surf = pDoc->surfinfo + ((dspos*width) + xspos);

    if (a_preserve && surf->flags & ESCH_SURF_CINDISTXT)
        return;

//ÄÄÄ Test for elevation cutoff
    if (a_elvcutoff)
    {
        ulong surfshift = pDoc->surfshift;
        float h = pDoc->htable[*(pDoc->hfield
                                 + (dspos << surfshift)
                                   *(width << surfshift)
                                 + (xspos << surfshift))];

        if (h < a_elvlow || h > a_elvhigh)
            return;
    }

//ÄÄÄ Lookup surface normal
    EschVector *nml = (EschVector*)ivory_hlock(pDoc->hsurfnormlflat);
    if (!nml)
        return;

    nml += (dspos*width) + xspos;

    float dot = *nml DOT EschVector(0,1,0);

//ÄÄÄ Check to see if point fullfills criteria
    if (dot <= a_values[0] && dot > a_stop)
    {
        if (!changed)
        {
            pDoc->PushUndo();
            changed=TRUE;
        }

        for(ulong i=0; i < a_count-1; i++)
        {
            if (dot > a_values[i+1])
                break;
        }

        dword tflags = 0;
        dword color = 0;
        byte cind = 0;

        if (a_istxt[i])
        {
            cind = a_tc[i] + 1;
            tflags = ESCH_SURF_CINDISTXT | pDoc->txtDFlags[a_tc[i]];
        }
        else
        {
            cind = pDoc->colorColrIndx[a_tc[i]];
            color = pDoc->colorColr[a_tc[i]];
            tflags = pDoc->colorDFlags[a_tc[i]];
        }

        assert(ESCH_SURF_TILE1 == 0x10 && ESCH_SURF_TILE2 == 0x20 && ESCH_SURF_TILE3 == 0x40);
        surf->flags &= ~(ESCH_SURF_FLIPU
                         | ESCH_SURF_FLIPV
                         | ESCH_SURF_CINDISTXT
                         | ESCH_SURF_TILE1
                         | ESCH_SURF_TILE2
                         | ESCH_SURF_TILE3
                         | ESCH_SURF_NOTILE
                         | ESCH_SURF_HIGHONLY
                         | ESCH_SURF_APP0
                         | ESCH_SURF_APP1
                         | ESCH_SURF_APP2
                         | ESCH_SURF_APP3);

        surf->flags |= tflags;
        surf->cind = cind;

        if (!(tflags & ESCH_SURF_CINDISTXT))
        {
            dword *colr = pDoc->surfcolr + ((dspos*width) + xspos);
            *colr = color;
        }
    }

    ivory_hunlock(pDoc->hsurfnormlflat);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - AssignByHeight                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::AssignByHeight(ulong count,
                                  ushort *tc, ushort *istxt, float *heights,
                                  float hstop, BOOL area, BOOL preserve)
{
    if (!count)
        return;

//ÄÄ Save values for use by assign
    ASSERT(count <= 8);

    a_count = count;
    a_stop = hstop;
    a_preserve = preserve;
    for(ulong i=0; i < count; i++)
    {
        a_tc[i] = tc[i];
        a_istxt[i] = istxt[i];
        a_values[i] = heights[i];
    }

//ÄÄ If we are doing all, run through all now...
    if (!area)
    {
        BOOL changed=FALSE;

        TerrEditDoc* pDoc = ((TerrEditView *) GetParent())->GetDocument();
        ASSERT_VALID(pDoc);

        for(int dspos = 0; dspos < depth; dspos++)
        {
            for(int xspos = 0; xspos < width; xspos++)
            {
                assign_by_height(pDoc,xspos,dspos,changed);
            }
        }

        //ÄÄÄ If we changed something, update the views
        if (changed)
        {
            pDoc->SetModifiedFlag();
            pDoc->UpdateAllViews(NULL,HINT_UPDATECOLR,NULL);
        }

        a_method=NONE;
    }
//ÄÄ Otherwise, setup for by region...
    else
    {
        a_method = BYHEIGHT;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - AssignByRandomRoll                                        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::AssignByRandomRoll(ulong count,
                                      ushort *tc, ushort *istxt, UINT *chances,
                                      BOOL elvcutoff, float elvlow, float elvhigh,
                                      BOOL area, BOOL preserve)
{
    if (!count)
        return;

//ÄÄ Save values for use by assign
    ASSERT(count <= 8);

    a_count = count;
    a_preserve = preserve;
    a_elvcutoff = elvcutoff;
    a_elvlow = elvlow;
    a_elvhigh = elvhigh;
    for(ulong i=0; i < count; i++)
    {
        a_tc[i] = tc[i];
        a_istxt[i] = istxt[i];
        a_values_int[i] = int(chances[i]);
    }

//ÄÄ If we are doing all, run through all now...
    if (!area)
    {
        BOOL changed=FALSE;

        TerrEditDoc* pDoc = ((TerrEditView *) GetParent())->GetDocument();
        ASSERT_VALID(pDoc);

        randomize();

        for(int dspos = 0; dspos < depth; dspos++)
        {
            for(int xspos = 0; xspos < width; xspos++)
            {
                assign_by_random_roll(pDoc,xspos,dspos,changed);
            }
        }

        //ÄÄÄ If we changed something, update the views
        if (changed)
        {
            pDoc->SetModifiedFlag();
            pDoc->UpdateAllViews(NULL,HINT_UPDATECOLR,NULL);
        }

        a_method=NONE;
    }
//ÄÄ Otherwise, setup for by region...
    else
    {
        a_method = BYRANDOMROLL;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - AssignByAngle                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::AssignByAngle(ulong count,
                                 ushort *tc, ushort *istxt, float *angles,
                                 float astop,
                                 BOOL elvcutoff, float elvlow, float elvhigh,
                                 BOOL area, BOOL preserve)
{
    if (!count)
        return;

//ÄÄ Save values for use by assign
    ASSERT(count <= 8);

    a_count = count;
    a_stop = esch_cos(astop);
    a_preserve = preserve;
    a_elvcutoff = elvcutoff;
    a_elvlow = elvlow;
    a_elvhigh = elvhigh;
    for(ulong i=0; i < count; i++)
    {
        a_tc[i] = tc[i];
        a_istxt[i] = istxt[i];
        a_values[i] = esch_cos(angles[i]);
    }

//ÄÄ If we are doing all, run through all now...
    if (!area)
    {
        BOOL changed=FALSE;

        TerrEditDoc* pDoc = ((TerrEditView *) GetParent())->GetDocument();
        ASSERT_VALID(pDoc);

        for(int dspos = 0; dspos < depth; dspos++)
        {
            for(int xspos = 0; xspos < width; xspos++)
            {
                assign_by_angle(pDoc,xspos,dspos,changed);
            }
        }

        //ÄÄÄ If we changed something, update the views
        if (changed)
        {
            pDoc->SetModifiedFlag();
            pDoc->UpdateAllViews(NULL,HINT_UPDATECOLR,NULL);
        }

        a_method=NONE;
    }
//ÄÄ Otherwise, setup for by region...
    else
    {
        a_method = BYANGLE;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                             °°° Protected °°°                            ³
// TerrEditGrid - assign                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::assign(CRect r)
{
    if (!a_method)
        return;

    BOOL changed=FALSE;

    TerrEditDoc* pDoc = ((TerrEditView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

    if (a_method == ALL)
    {
        TerrEditView *pView = (TerrEditView*)GetParent();
        ASSERT_VALID(pView);

        int i = pView->GetCurrentTextureSel();

        dword tflags = 0;
        dword color = 0;
        byte cind = 0;

        if (i == LB_ERR) 
        {
            i = pView->GetCurrentColorSel();

            if (i == LB_ERR)
            {
                a_method=NONE;
                return;
            }

            cind = pDoc->colorColrIndx[i];
            color = pDoc->colorColr[i];
            tflags = pDoc->colorDFlags[i];
        }
        else
        {
            cind = i + 1;
            tflags = ESCH_SURF_CINDISTXT | pDoc->txtDFlags[i];
        }

        //ÄÄÄ Set each surface point which is touched by the rectangle
        //ÄÄÄ (which is in pixel coords)
        for(int y = r.top; y <= r.bottom; y++)
        {
            int dspos = depth - ((y + ypos) >> zoomshift) - 1;

            for(int x = r.left; x <= r.right; x++)
            {
                int xspos = (x + xpos) >> zoomshift;

                if (xspos >= 0 && xspos < width && dspos >= 0 && dspos < depth)
                {
                    ASSERT(pDoc->surfinfo);

                    if (!changed)
                    {
                        pDoc->PushUndo();
                        changed=TRUE;
                    }

                    esch_surf_type *surf = pDoc->surfinfo + ((dspos*width) + xspos);

                    assert(ESCH_SURF_TILE1 == 0x10 && ESCH_SURF_TILE2 == 0x20 && ESCH_SURF_TILE3 == 0x40);
                    surf->flags &= ~(ESCH_SURF_FLIPU
                                     | ESCH_SURF_FLIPV
                                     | ESCH_SURF_CINDISTXT
                                     | ESCH_SURF_TILE1
                                     | ESCH_SURF_TILE2
                                     | ESCH_SURF_TILE3
                                     | ESCH_SURF_NOTILE
                                     | ESCH_SURF_HIGHONLY
                                     | ESCH_SURF_APP0
                                     | ESCH_SURF_APP1
                                     | ESCH_SURF_APP2
                                     | ESCH_SURF_APP3);
                    surf->flags |= tflags;
                    surf->cind = cind;

                    if (!(tflags & ESCH_SURF_CINDISTXT))
                    {
                        dword *colr = pDoc->surfcolr + ((dspos * width) + xspos);
                        *colr = color;
                    }
                }
            }
        }
    }
    else
    {
        //ÄÄÄ Check each surface point which is touched by the rectangle
        //ÄÄÄ (which is in pixel coords)
        ASSERT(a_count > 0);

        if (a_method == BYRANDOMROLL)
            randomize();

        for(int y = r.top; y <= r.bottom; y++)
        {
            int dspos = depth - ((y + ypos) >> zoomshift) - 1;

            for(int x = r.left; x <= r.right; x++)
            {
                int xspos = (x + xpos) >> zoomshift;

                if (xspos >= 0 && xspos < width && dspos >= 0 && dspos < depth)
                {
                    switch(a_method)
                    {
                        case BYHEIGHT:
                            assign_by_height(pDoc,xspos,dspos,changed);
                            break;
                        case BYRANDOMROLL:
                            assign_by_random_roll(pDoc,xspos,dspos,changed);
                            break;
                        case BYANGLE:
                            assign_by_angle(pDoc,xspos,dspos,changed);
                            break;
                    }
                }
            }
        }
    }

    //ÄÄÄ If we changed something, update the views
    if (changed)
    {
        pDoc->SetModifiedFlag();
        pDoc->UpdateAllViews(NULL,HINT_UPDATECOLR,NULL);
    }

    a_method=NONE;
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Message Handlers °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - OnPaint                                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::OnPaint() 
{
        CPaintDC dc(this); // device context for painting

    if (!depth || !gmap || !bmi)
        return;

    TerrEditDoc* pDoc = (TerrEditDoc*)((CView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

//ÄÄÄ Copy bitmap to window
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - OnHScroll                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - OnVScroll                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
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


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - OnSize                                                    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::OnSize(UINT nType, int cx, int cy) 
{
        CWnd::OnSize(nType, cx, cy);

    SetZoomLevel(zoomshift);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - OnLButtonDown                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::OnLButtonDown(UINT nFlags, CPoint point) 
{
//ÄÄÄ Get position on surface data
    int xspos = (point.x + xpos) >> zoomshift;
    int dspos = (point.y + ypos) >> zoomshift;

    if (xspos >= width || dspos >= depth)
    {
        CWnd::OnLButtonDown(nFlags, point);
        a_method=NONE;
        return;
    }

    dspos = depth - dspos - 1;

    TerrEditDoc* pDoc = ((TerrEditView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

//ÄÄÄ Check modifier keys
    if (nFlags & MK_CONTROL)
    {
        //ÄÄÄ Surface color dialog direct key
        pDoc->UISurfColor(NULL,xspos,dspos);
    }
    else if ((nFlags & MK_SHIFT) || a_method)
    {
        TerrEditView *pView = (TerrEditView*)GetParent();
        ASSERT_VALID(pView);

        //ÄÄÄ Set texture/color shortcut (uses drag rectangle)
        if (!a_method && (nFlags & MK_SHIFT))
        {
            //ÄÄÄ Check that a valid texture is selected first
            if ( (pView->GetCurrentTextureSel() == LB_ERR)
                 && (pView->GetCurrentColorSel() == LB_ERR) )
            {
                MessageBox("Please highlight the texture or "
                           "color definition to apply to the region.",
                           "Assign Error",
                           MB_OK | MB_ICONSTOP);
                return;
            }

            a_method = ALL;
        }

        if (pDoc->width && pDoc->depth)
        {
            rectactive=TRUE;
            SetCapture();

            rect.left = rect.right = point.x;
            rect.top = rect.bottom = point.y;

            SIZE s;
            s.cx = s.cy = 1;

            CDC *pdc = GetDC();
            pdc->DrawDragRect( &rect, s, NULL, s );
            lastrect=rect;
        }
    }
    else
    {
        //ÄÄÄ Standard surface properties dialog
        pDoc->UISurfProperties(NULL,xspos,dspos);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - OnLButtonUp                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::OnLButtonUp(UINT nFlags, CPoint point) 
{
    if (!rectactive)
    {
        CWnd::OnLButtonUp(nFlags, point);
    }
    else
    {
//ÄÄÄ If rectangle was active, take action based on last rectangle set by
//ÄÄÄ MouseMove 
        rectactive=FALSE;
        ReleaseCapture();

        SIZE s;
        s.cx = s.cy = 1;

        CDC *pdc = GetDC();
        pdc->DrawDragRect( &rect, s, NULL, s );

        assign(rect);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - OnRButtonDown                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::OnRButtonDown(UINT nFlags, CPoint point) 
{
    if (rectactive)
    {
        return;
    }

    CRect   rct;
    GetWindowRect (&rct);

    point.x += rct.left;
    point.y += rct.top;

//ÄÄÄ Create menu(s)

    //ÄÄÄ Zoom Submenu
    CMenu   zoomMenu;
    zoomMenu.CreatePopupMenu();

    zoomMenu.AppendMenu(MF_STRING, ID_VIEW_ZOOM_NORM, "Normal Size");
    zoomMenu.AppendMenu(MF_STRING, ID_VIEW_ZOOM_MED, "Medium Size");
    zoomMenu.AppendMenu(MF_STRING, ID_VIEW_ZOOM_LARGE, "Large Size");
    zoomMenu.AppendMenu(MF_STRING, ID_VIEW_ZOOM_XLARGE, "Extra Large Size");
    zoomMenu.AppendMenu(MF_STRING, ID_VIEW_ZOOM_MEGA, "Mega Size");

    //ÄÄÄ Show Submenu
    CMenu   showMenu;
    showMenu.CreatePopupMenu();

    showMenu.AppendMenu(MF_STRING, ID_VIEW_SHOW_COLORS, "Surface Colors");
    showMenu.AppendMenu(MF_STRING, ID_VIEW_SHOW_SHADED, "Shaded Colors");
    showMenu.AppendMenu(MF_STRING, ID_VIEW_SHOW_HGT, "Height-based Colors");
    showMenu.AppendMenu(MF_STRING, ID_VIEW_SHOW_TXTONLY, "Textures Only");
    showMenu.AppendMenu(MF_STRING, ID_VIEW_SHOW_APP, "Application Bits");

    //ÄÄÄ Menu
    CMenu   rMenu;
    rMenu.CreatePopupMenu();
    rMenu.AppendMenu(MF_STRING | MF_POPUP, (unsigned int) zoomMenu.m_hMenu, "Zoom");
    rMenu.AppendMenu(MF_STRING | MF_POPUP, (unsigned int) showMenu.m_hMenu, "Show");
    rMenu.AppendMenu(MF_SEPARATOR);
    rMenu.AppendMenu(MF_STRING, ID_TERR_PROP, "Properties...");

//ÄÄÄ Display and perform action
    ASSERT(AfxGetMainWnd());
    rMenu.TrackPopupMenu( TPM_RIGHTBUTTON | TPM_LEFTALIGN,
                          point.x, point.y,
                          AfxGetMainWnd());
    rMenu.DestroyMenu();
    zoomMenu.DestroyMenu();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditGrid - OnMouseMove                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditGrid::OnMouseMove(UINT nFlags, CPoint point) 
{  
//ÄÄÄ Update status area string
    char str[256];

    int xspos = (point.x + xpos) >> zoomshift;
    int dspos = (point.y + ypos) >> zoomshift;

    if (xspos < 0 || xspos >= width || dspos < 0 || dspos >= depth)
    {
        strcpy(str,"Ready");
    }
    else
    {
        TerrEditDoc* pDoc = ((TerrEditView *) GetParent())->GetDocument();
        ASSERT_VALID(pDoc);

        dspos = depth - dspos - 1;

        float h = pDoc->htable[pDoc->hfield[(dspos << pDoc->surfshift)
                                            * pDoc->width
                                            + (xspos << pDoc->surfshift)]];
        float h2 = pDoc->htable[(xspos+1 < width && dspos+1 < depth)
                                ? pDoc->hfield[((dspos+1) << pDoc->surfshift)
                                               * pDoc->width
                                               + ((xspos+1) << pDoc->surfshift)]
                                : 0];

        float x = (xspos << pDoc->surfshift)*(float)pDoc->scale + (float)pDoc->orgx;
        float z = (dspos << pDoc->surfshift)*(float)pDoc->scale + (float)pDoc->orgz;
        float x2 = ((xspos+1) << pDoc->surfshift)*(float)pDoc->scale + (float)pDoc->orgx;
        float z2 = ((dspos+1) << pDoc->surfshift)*(float)pDoc->scale + (float)pDoc->orgz;

        if (rectactive)
        {
            sprintf(str,"(%3d,%3d) - (%3d,%3d)\t\t"
                        "(X: %8.2f, Z: %8.2f, [H: %8.2f]) "
                        "- (X: %8.2f, Z: %8.2f, [H: %8.2f])",
                        rect.left,rect.top,
                        xspos,dspos,
                        x,z,h,x2,z2,h2);
        }
        else if (a_method)
        {   
            sprintf(str,"Select upper-left (%3d,%3d)\t\t"
                        "(X: %8.2f, Z: %8.2f, [H: %8.2f]) "
                        "- (X: %8.2f, Z: %8.2f, [H: %8.2f])",
                        xspos,dspos,
                        x,z,h,x2,z2,h2);
        }
        else
        {
            sprintf(str,"(%3d,%3d)\t\t"
                        "(X: %8.2f, Z: %8.2f, [H: %8.2f]) "
                        "- (X: %8.2f, Z: %8.2f, [H: %8.2f])",
                        xspos,dspos,
                        x,z,h,x2,z2,h2);
        }
    }

    ((TerrMainFrame *) AfxGetMainWnd())->SetMessageText(str);

//ÄÄÄ Update drag rectangle, if active
    if (rectactive)
    {
        if (point.x >= rect.left)
            rect.right = point.x;

        if (point.y >= rect.top)
            rect.bottom = point.y;

        SIZE s;
        s.cx = s.cy = 1;

        CDC *pdc = GetDC();
        pdc->DrawDragRect( &rect, s, &lastrect, s );
        lastrect=rect;
    }

    CWnd::OnMouseMove(nFlags, point);
}

//°±² eof - eshtgrid.cpp ²±°
