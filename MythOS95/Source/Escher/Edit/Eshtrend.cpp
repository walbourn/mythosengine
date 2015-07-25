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
//ùùùùùùùùùùùCopyrightù(c)ù1994-1997ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
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
// eshtrend.cpp
//
// Terrain View support class.
//
// The Render class controls the 3D viewer window for the editor.
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
// TerrEditRender                                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
BEGIN_MESSAGE_MAP(TerrEditRender, CWnd)
	//{{AFX_MSG_MAP(TerrEditRender)
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_SIZE()
	ON_WM_NCRBUTTONDOWN()
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
// TerrEditRender - Constructor                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
TerrEditRender::TerrEditRender() :
    bmi(0),
    gmap(0),
    gvp(0),
    pal(0),
    mode(RNDCTRL_NONE),
    capture(0)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditRender - Destructor                                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
TerrEditRender::~TerrEditRender()
{
    release_vport();
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° Operations °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                            ²²² Protected ²²²                             ³
// TerrEditRender - setup_vport                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditRender::setup_vport(int width, int height)
{
    release_vport();

    if (!width || !height || !pal)
        return;

    width = (((width)+3) & ~0x3);

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

    for(int i=0; i < 256; i++)
    {
        ((WORD *)bmi->bmiColors)[i] = (WORD)i;

    }

    gmap = new BYTE [width * height];
    ASSERT(gmap);

    gvp = new VngoVportDB8(width,height,gmap,NULL,pal,
                           VNGO_ZBUFFER_DEV);
    ASSERT(gvp);

//ÄÄÄ Attach to camera instance
    TerrEditDoc* pDoc = (TerrEditDoc *) ((CView *) GetParent())->GetDocument();
    if (pDoc)
        pDoc->cam.attach(gvp);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                            ²²² Protected ²²²                             ³
// TerrEditRender - release_vport                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
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

        //ÄÄÄ Detach from camera instance
        if (m_hWnd)
        {
            TerrEditDoc* pDoc = (TerrEditDoc *) ((CView *) GetParent())->GetDocument();
            if (pDoc)
                pDoc->cam.attach(0);
        }
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditRender - UpdateRender                                            ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditRender::UpdateRender()
{
    if (!gvp)
        return;

    TerrEditDoc* pDoc = (TerrEditDoc *) ((CView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

//ÄÄÄ Ensure light is correct
    if (!pDoc->lights)
        return;

    pDoc->LightTerrain();

//ÄÄÄ If we are in hover, must reset camera position
    if (mode == RNDCTRL_HOVER)
    {
        EschPoint   pnt;
        pDoc->cam.get_position(&pnt);
        pDoc->cam.set_position(pnt.x,
                               terr.get_height(pnt.x, pnt.z) + pDoc->hover_offset,
                               pnt.z);
    }

//ÄÄÄ Render to DIB
    pDoc->cam.render(&terr,pDoc->lights);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditRender - SetMode                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditRender::SetMode(rnd_ctrl_mode_type m)
{
    mode = m;

    char *str = "Render View - ?";

    TerrEditDoc* pDoc = (TerrEditDoc *) ((CView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

    EnableScrollBarCtrl(SB_VERT,TRUE);
    EnableScrollBarCtrl(SB_HORZ,TRUE);

    switch (m)
    {
        case RNDCTRL_HOVER:
            str = "Render View - Hover";
            SetScrollRange(SB_HORZ,-128,128,FALSE);         // Move X
            SetScrollPos(SB_HORZ,0);
            SetScrollRange(SB_VERT,-128,128,FALSE);         // Move Z
            SetScrollPos(SB_VERT,0);
            break;
        case RNDCTRL_ROTATEXY:
            str = "Render View - Rotate X/Y";
            SetScrollRange(SB_HORZ,-180,180,FALSE);         // Rotate X
            SetScrollPos(SB_HORZ,0);
            SetScrollRange(SB_VERT,-180,180,FALSE);         // Rotate Y
            SetScrollPos(SB_VERT,0);
            break;
        case RNDCTRL_MOVEXY:
            str = "Render View - Move X/Y";
            SetScrollRange(SB_HORZ,-128,128,FALSE);         // Move X
            SetScrollPos(SB_HORZ,0);
            SetScrollRange(SB_VERT,-128,128,FALSE);         // Move Y
            SetScrollPos(SB_VERT,0);
            break;
        case RNDCTRL_ROTMOVEZ:
            str = "Render View - Rotate/Move Z";
            SetScrollRange(SB_VERT,-128,128,FALSE);         // Move Z
            SetScrollPos(SB_VERT,0);
            SetScrollRange(SB_HORZ,-180,180,FALSE);         // Rotate Z
            SetScrollPos(SB_HORZ,0);
            break;
        case RNDCTRL_LIGHTXY:
            str = "Render View - Light X/Y";
            if (pDoc->lights)
            {
                if (pDoc->lights->get_type() == ESCH_LGTT_VECTOR)
                {
                    SetScrollRange(SB_HORZ,-180,180,FALSE);         // Rotate X
                    SetScrollPos(SB_HORZ,0);
                    SetScrollRange(SB_VERT,-180,180,FALSE);         // Rotate Y
                    SetScrollPos(SB_VERT,0);
                }
                else
                {
                    SetScrollRange(SB_HORZ,-32768,+32768,FALSE);    // Move X
                    SetScrollPos(SB_HORZ,0);
                    SetScrollRange(SB_VERT,-32768,+32768,FALSE);    // Move Y
                    SetScrollPos(SB_VERT,0);
                }
            }
            else
            {
                EnableScrollBarCtrl(SB_VERT,FALSE);
                EnableScrollBarCtrl(SB_HORZ,FALSE);
            }
            break;
        case RNDCTRL_LIGHTBRIGHT:
            str = "Render View - Light Intensity";
                                                            // Adjust light brightness
            if (pDoc->lights)
            {
                SetScrollRange(SB_VERT,0,255,FALSE);
                SetScrollPos(SB_VERT,pDoc->lights->get_intensity());
                SetScrollRange(SB_HORZ,0,255,FALSE);
                SetScrollPos(SB_HORZ,pDoc->lights->get_intensity());
            }
            else
            {
                EnableScrollBarCtrl(SB_VERT,FALSE);
                EnableScrollBarCtrl(SB_HORZ,FALSE);
            }
            break;
        default:
            EnableScrollBarCtrl(SB_VERT,FALSE);
            EnableScrollBarCtrl(SB_HORZ,FALSE);
            break;
    }

    SetWindowText(str);
}



//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°° Message Handlers °°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditRender - OnPaint                                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditRender::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

    TerrEditDoc* pDoc = (TerrEditDoc *) ((CView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

//ÄÄÄ Copy bitmap to window

    if (pDoc->hpal)
    {
        SelectPalette(dc.m_hDC,pDoc->hpal,0);
        dc.RealizePalette();
    }
	
    if (bmi && gmap)
    {
        SetDIBitsToDevice(dc.m_hDC, 0, 0,
                          bmi->bmiHeader.biWidth, -bmi->bmiHeader.biHeight,
                          0, 0, 0, -bmi->bmiHeader.biHeight,
                          gmap, bmi, DIB_PAL_COLORS);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditRender - OnHScroll                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditRender::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
    int     t, pos, render=0;
    float   f;
    static  lastpos=0;

    TerrEditDoc* pDoc = (TerrEditDoc*)((CView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

    pos = (int)nPos;

    switch (mode)
    {
        case RNDCTRL_ROTATEXY:                  // Rotate X
            switch (nSBCode)
            {
                case SB_LINELEFT:
                    pDoc->cam.yaw(-1.0f);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    pDoc->cam.yaw(-11.25f);
                    render=1;
                    break;
                case SB_LINERIGHT:
                    pDoc->cam.yaw(1.0f);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    pDoc->cam.yaw(11.25f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    pDoc->cam.yaw(float(pos - lastpos));
                    lastpos=pos;
                    render=2;
                    break;
                case SB_ENDSCROLL:
                    render=1;
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_HOVER:                     // Move X
        case RNDCTRL_MOVEXY:
            switch (nSBCode)
            {
                case SB_LINELEFT:
                    pDoc->cam.move(-pDoc->scale,0.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    pDoc->cam.move(-pDoc->scale * 3.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_LINERIGHT:
                    pDoc->cam.move(pDoc->scale,0.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    pDoc->cam.move(pDoc->scale * 3.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    f = (float)(pos-lastpos) * pDoc->scale;
                    pDoc->cam.move(f,0.0f,0.0f);
                    lastpos=pos;
                    render=2;
                    break;
                case SB_ENDSCROLL:
                    render=1;
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_ROTMOVEZ:                  // Rotate Z
            switch (nSBCode)
            {
                case SB_LINERIGHT:
                    pDoc->cam.roll(-1.0f);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    pDoc->cam.roll(-11.25f);
                    render=1;
                    break;
                case SB_LINELEFT:
                    pDoc->cam.roll(1.0f);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    pDoc->cam.roll(11.25f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    pDoc->cam.roll(float(lastpos - pos));
                    lastpos=pos;
                    render=2;
                    break;
                case SB_ENDSCROLL:
                    render=1;
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_LIGHTXY:                   // Light X
            if (!pDoc->lights)
                break;
            switch (nSBCode)
            {
                case SB_LINELEFT:
                    if (pDoc->lights->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)pDoc->lights)->rotatex(-1.0f);
                    else
                        ((EschPointLight*)pDoc->lights)->translate(-1.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    if (pDoc->lights->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)pDoc->lights)->rotatex(-11.25f);
                    else
                        ((EschPointLight*)pDoc->lights)->translate(-10.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_LINERIGHT:
                    if (pDoc->lights->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)pDoc->lights)->rotatex(1.0f);
                    else
                        ((EschPointLight*)pDoc->lights)->translate(1.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    if (pDoc->lights->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)pDoc->lights)->rotatex(11.25f);
                    else
                        ((EschPointLight*)pDoc->lights)->translate(10.0f,0.0f,0.0f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    if (pDoc->lights->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)pDoc->lights)->rotatex(float(pos - lastpos));
                    else
                    {
                        f = (float)(pos-lastpos) / 10.0f;

                        ((EschPointLight*)pDoc->lights)->translate(f,0.0f,0.0f);
                    }
                    lastpos=pos;
                    render=2;
                    break;
                case SB_ENDSCROLL:
                    render=1;
                    lastpos=0;
                    break;
            }
            if (render)
            {
                pDoc->SetModifiedFlag();
                pDoc->SetLightsModifiedFlag();
            }
            break;
        case RNDCTRL_LIGHTBRIGHT:               // Intensity
            if (!pDoc->lights)
                break;
            t=pDoc->lights->get_intensity();
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
                    render=2;
                    break;
                case SB_ENDSCROLL:
                    render=1;
                    lastpos=0;
                    break;
            }
            if (render)
            {
                pDoc->lights->set_intensity(t);
                pDoc->SetModifiedFlag();
                pDoc->SetLightsModifiedFlag();
            }
            break;
    }

	CWnd::OnHScroll(nSBCode, nPos, pScrollBar);

    if (render)
    {
        if (render == 2)
        {
            UpdateRender();
            RedrawWindow();
        }
        else
            pDoc->UpdateAllViews(NULL, HINT_UPDATELIGHTS, NULL);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditRender - OnVScroll                                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditRender::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
    int     t, pos, render=0;
    float   f;
    static  lastpos=0;

    TerrEditDoc* pDoc = (TerrEditDoc*) ((CView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

    pos = (int)nPos;

    switch (mode)
    {
        case RNDCTRL_ROTATEXY:                  // Rotate Y
            switch (nSBCode)
            {
                case SB_LINEUP:
                    pDoc->cam.pitch(-1.0f);
                    render=1;
                    break;
                case SB_PAGEUP:
                    pDoc->cam.pitch(-11.25f);
                    render=1;
                    break;
                case SB_LINEDOWN:
                    pDoc->cam.pitch(1.0f);
                    render=1;
                    break;
                case SB_PAGEDOWN:
                    pDoc->cam.pitch(11.25f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    pDoc->cam.pitch(float(pos - lastpos));
                    lastpos=pos;
                    render=2;
                    break;
                case SB_ENDSCROLL:
                    render=1;
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_MOVEXY:                    // Move Y
            switch (nSBCode)
            {
                case SB_LINEUP:
                    pDoc->cam.move(0.0f,pDoc->scale,0.0f);
                    render=1;
                    break;
                case SB_PAGEUP:
                    pDoc->cam.move(0.0f,pDoc->scale * 3.0f,0.0f);
                    render=1;
                    break;
                case SB_LINEDOWN:
                    pDoc->cam.move(0.0f,-pDoc->scale,0.0f);
                    render=1;
                    break;
                case SB_PAGEDOWN:
                    pDoc->cam.move(0.0f,-pDoc->scale * 3.0f,0.0f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    f = (float)(lastpos-pos) * pDoc->scale;
                    pDoc->cam.move(0.0f,f,0.0f);
                    lastpos=pos;
                    render=2;
                    break;
                case SB_ENDSCROLL:
                    render=1;
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_HOVER:                     // Move Z
        case RNDCTRL_ROTMOVEZ:
            switch (nSBCode)
            {
                case SB_LINEUP:
                    pDoc->cam.move(0.0f,0.0f,pDoc->scale);
                    render=1;
                    break;
                case SB_PAGEUP:
                    pDoc->cam.move(0.0f,0.0f,pDoc->scale * 3.0f);
                    render=1;
                    break;
                case SB_LINEDOWN:
                    pDoc->cam.move(0.0f,0.0f,-pDoc->scale);
                    render=1;
                    break;
                case SB_PAGEDOWN:
                    pDoc->cam.move(0.0f,0.0f,-pDoc->scale * 3.0f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    f = (float)(lastpos-pos) * pDoc->scale;
                    pDoc->cam.move(0.0f,0.0f,f);
                    lastpos=pos;
                    render=2;
                    break;
                case SB_ENDSCROLL:
                    render=1;
                    lastpos=0;
                    break;
            }
            break;
        case RNDCTRL_LIGHTXY:                   // Light Y
            if (!pDoc->lights)
                break;
            switch (nSBCode)
            {
                case SB_LINELEFT:
                    if (pDoc->lights->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)pDoc->lights)->rotatey(-1.0f);
                    else
                        ((EschPointLight*)pDoc->lights)->translate(0.0f,-1.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGELEFT:
                    if (pDoc->lights->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)pDoc->lights)->rotatey(-11.25f);
                    else
                        ((EschPointLight*)pDoc->lights)->translate(0.0f,-10.0f,0.0f);
                    render=1;
                    break;
                case SB_LINERIGHT:
                    if (pDoc->lights->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)pDoc->lights)->rotatey(1.0f);
                    else
                        ((EschPointLight*)pDoc->lights)->translate(0.0f,1.0f,0.0f);
                    render=1;
                    break;
                case SB_PAGERIGHT:
                    if (pDoc->lights->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)pDoc->lights)->rotatey(11.25f);
                    else
                        ((EschPointLight*)pDoc->lights)->translate(0.0f,10.0f,0.0f);
                    render=1;
                    break;
                case SB_THUMBTRACK:
                    if (pDoc->lights->get_type() == ESCH_LGTT_VECTOR)
                        ((EschVectorLight*)pDoc->lights)->rotatey(float(pos - lastpos));
                    else
                    {
                        f = (float)(pos-lastpos) / 10.0f;
                        ((EschPointLight*)pDoc->lights)->translate(0.0f,f,0.0f);
                    }
                    lastpos=pos;
                    render=2;
                    break;
                case SB_ENDSCROLL:
                    render=1;
                    lastpos=0;
                    break;
            }
            if (render)
            {
                pDoc->SetModifiedFlag();
                pDoc->SetLightsModifiedFlag();
            }
            break;
        case RNDCTRL_LIGHTBRIGHT:               // Intensity
            if (!pDoc->lights)
                break;
            t=pDoc->lights->get_intensity();
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
                    render=2;
                    break;
                case SB_ENDSCROLL:
                    render=1;
                    lastpos=0;
                    break;
            }
            if (render)
            {
                pDoc->lights->set_intensity(t);
                pDoc->SetModifiedFlag();
                pDoc->SetLightsModifiedFlag();
            }
            break;
    }

	CWnd::OnVScroll(nSBCode, nPos, pScrollBar);

    if (render)
    {
        if (render == 2)
        {
            UpdateRender();
            RedrawWindow();
        }
        else
            pDoc->UpdateAllViews(NULL, HINT_UPDATELIGHTS, NULL);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditRender - OnLButtonDown                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditRender::OnLButtonDown(UINT nFlags, CPoint point) 
{
    if (!capture)
    {
        capture=1;
        SetCapture();
        lastx = point.x;
        lasty = point.y;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditRender - OnLButtonUp                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditRender::OnLButtonUp(UINT nFlags, CPoint point) 
{
    if (capture)
    {
        capture=0;
        ReleaseCapture();

        TerrEditDoc* pDoc = (TerrEditDoc*)((CView *) GetParent())->GetDocument();
        ASSERT_VALID(pDoc);

        pDoc->UpdateAllViews(NULL, HINT_UPDATELIGHTS, NULL);
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditRender - OnMouseMove                                             ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditRender::OnMouseMove(UINT nFlags, CPoint point) 
{
    ((TerrMainFrame *) AfxGetMainWnd())->SetMessageText("Ready");

    if (!capture)
        return;

    int dx = point.x - lastx;
    int dy = point.y - lasty;

    if (!dx && !dy)
        return;

    TerrEditDoc* pDoc = (TerrEditDoc*)((CView *) GetParent())->GetDocument();
    ASSERT_VALID(pDoc);

    int             t, render=0;

    switch (mode)
    {
        case RNDCTRL_HOVER:                     // Hover
            pDoc->cam.move((float)-dx, 0.0f, (float)dy);
            render=1;
            break;
        case RNDCTRL_ROTATEXY:                  // Rotate X/Y
            pDoc->cam.yaw((float)-dx);
            pDoc->cam.pitch((float)-dy);
            render=1;
            break;
        case RNDCTRL_MOVEXY:                    // Move X/Y
            pDoc->cam.move((float)-dx, (float)dy, 0.0f);
            render=1;
            break;
        case RNDCTRL_ROTMOVEZ:                  // Move Z/Rotate Z
            if (nFlags & MK_SHIFT)
                pDoc->cam.roll((float)-dx);
            else
                pDoc->cam.move(0.0f, 0.0f, (float)dy);
            render=1;
            break;
        case RNDCTRL_LIGHTXY:                   // Lights X/Y
            if (!pDoc->lights)
                break;
            if (pDoc->lights->get_type() == ESCH_LGTT_VECTOR)
            {
                ((EschVectorLight*)pDoc->lights)->rotatex((float)dx);
                ((EschVectorLight*)pDoc->lights)->rotatey((float)dy);
            }
            else if (nFlags & MK_SHIFT)
            {
                ((EschPointLight*)pDoc->lights)->translate(0.0f, 0.0f, (float)dy);
            }
            else
            {
                ((EschPointLight*)pDoc->lights)->translate((float)dx, (float)-dy, 0.0f);
            }
            render=1;
            pDoc->SetModifiedFlag();
            pDoc->SetLightsModifiedFlag();
            break;
        case RNDCTRL_LIGHTBRIGHT:               // Intensity
            if (!pDoc->lights)
                break;
            t=pDoc->lights->get_intensity();
            t += dx;
            if (t < 0)
                t = 0;
            if (t > 255)
                t = 255;
            pDoc->lights->set_intensity(t);
            SetScrollPos(SB_VERT,t);
            SetScrollPos(SB_HORZ,t);
            render=1;
            pDoc->SetModifiedFlag();
            pDoc->SetLightsModifiedFlag();
            break;
    }
    
    lastx = point.x;
    lasty = point.y;

    if (render)
    {
        UpdateRender();
        RedrawWindow();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditRender - OnRButtonDown                                           ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditRender::OnRButtonDown(UINT nFlags, CPoint point) 
{
    if (capture)
        return;

    CRect   rct;
    GetWindowRect (&rct);

    point.x += rct.left;
    point.y += rct.top;

//ÄÄÄ Create menu(s)

    //ÄÄÄ Render Submenu
    CMenu   modeMenu;
    modeMenu.CreatePopupMenu();

    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_DOTS, "Dots");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_WIREFRAME, "Wireframe");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_SOLID, "Solid");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_FLAT, "Flat");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_SMOOTH, "Smooth");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_SPECULAR, "Specular");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_BACKFACE, "Backface");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_TEXTURES, "Textures");
    modeMenu.AppendMenu(MF_STRING, ID_VIEW_RND_PERSPECTIVE, "Perspective");
        
    //ÄÄÄ Menu
    CMenu   rMenu;
    rMenu.CreatePopupMenu();
    rMenu.AppendMenu(MF_STRING, ID_VIEW_REFRESH, "Refresh");
    rMenu.AppendMenu(MF_STRING | MF_POPUP, (unsigned int) modeMenu.m_hMenu, "Render");
    rMenu.AppendMenu(MF_SEPARATOR);
    rMenu.AppendMenu(MF_STRING, ID_VIEW_HOVER, "Hover");
    rMenu.AppendMenu(MF_STRING, ID_VIEW_ROTXY, "Rotate X/Y");
    rMenu.AppendMenu(MF_STRING, ID_VIEW_MOVEXY, "Move X/Y");
    rMenu.AppendMenu(MF_STRING, ID_VIEW_ROTMOVEZ, "Rotate Z/Move Z");
    rMenu.AppendMenu(MF_STRING, ID_LGT_ADJUSTXY, "Adjust X/Y");
    rMenu.AppendMenu(MF_STRING, ID_LGT_ABRIGHT, "Adjust Intensity");
    rMenu.AppendMenu(MF_SEPARATOR);
    rMenu.AppendMenu(MF_STRING, ID_LGT_PROP, "Light Props...");
    rMenu.AppendMenu(MF_SEPARATOR);
    rMenu.AppendMenu(MF_STRING, ID_VIEW_PROP, "Properties...");

//ÄÄÄ Display and perform action
    ASSERT(AfxGetMainWnd());
    rMenu.TrackPopupMenu( TPM_RIGHTBUTTON | TPM_LEFTALIGN,
                          point.x, point.y,
                          AfxGetMainWnd());
    rMenu.DestroyMenu();
    modeMenu.DestroyMenu();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditRender - OnNcRButtonDown                                         ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditRender::OnNcRButtonDown(UINT nHitTest, CPoint point) 
{
    if (nHitTest & HTCAPTION)
    {
        CMenu   rMenu;

        rMenu.CreatePopupMenu();
        rMenu.AppendMenu(MF_STRING, ID_VIEW_RENDER, "Render View");

        ASSERT(AfxGetMainWnd());
        rMenu.TrackPopupMenu( TPM_RIGHTBUTTON | TPM_LEFTALIGN,
                              point.x, point.y,
                              AfxGetMainWnd());
        rMenu.DestroyMenu();
        return;
    }

	CWnd::OnNcRButtonDown(nHitTest, point);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// TerrEditRender - OnSize                                                  ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void TerrEditRender::OnSize(UINT nType, int cx, int cy) 
{
    setup_vport(cx, cy);
    UpdateRender();

	CWnd::OnSize(nType, cx, cy);
}

//°±² eof - eshtrend.cpp ²±°
