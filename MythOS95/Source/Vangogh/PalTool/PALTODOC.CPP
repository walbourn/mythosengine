//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                PalTool
//
//                   A Palette extraction/definition tool
//
//              Copyright (c) 1995 by Charybdis Enterprises, Inc.
//                           All Rights Reserved
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
// PalTodoc.cpp
// 	implementation of the CPalToolDoc class
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "stdafx.h"
#include "PalTool.h"
#include "dialog.h"
#include "PalTodoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// setup_hwpal
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void setup_hwpal (VngoPal8 *pal, int type)
{
   VngoColor24bit  pclrs[256];
   int             r,g,b,i;
   Flx16           d6;
   Flx16           d255;

   d255 = 255;
                         
   if (type == 0)
   {
       d6 = d255 / (Flx16)6;

       i=0;
       for (r = 0; r < 6; r++)
       {
           for (g = 0; g < 6; g++)
           {
               for ( b = 0; b < 6; b++,i++)
               {
                   pclrs[i].r = (byte)((long)((Flx16)r * d6));
                   pclrs[i].g = (byte)((long)((Flx16)g * d6));
                   pclrs[i].b = (byte)((long)((Flx16)b * d6));
               }
           }
       }

       for (int j=0;j < 24;j++,i++)
       {
           pclrs[i].r = (byte)((long)(j * 10)+8);
           pclrs[i].g = (byte)((long)(j * 10)+8);
           pclrs[i].b = (byte)((long)(j * 10)+8);
       }

       for (r = 0;r < 5;r++,i++)
       {
           pclrs[i].r = (byte)((long)((Flx16)r * d6)+21);
           pclrs[i].g = (byte)0;
           pclrs[i].b = (byte)0;
       }
       for (g = 0;g < 5;g++,i++)
       {
           pclrs[i].r = (byte)0;
           pclrs[i].g = (byte)((long)((Flx16)g * d6)+21);
           pclrs[i].b = (byte)0;
       }
       for (b = 0;b < 5;b++,i++)
       {
           pclrs[i].r = (byte)0;
           pclrs[i].g = (byte)0;
           pclrs[i].b = (byte)((long)((Flx16)b * d6)+21);
       }


       for (;i<256;i++)
       {
           pclrs[i].r = 0;
           pclrs[i].g = 0;
           pclrs[i].b = 0;
       }
       assert (i <= 256);
       ((VngoPal8 *)pal)->set_hwpal(pclrs,256);
   }
   else if (type == 4)
   {
       i=0;
       for (r=0; r < 256;r+=4)
       {
           pclrs[i].r = (byte)r;
           pclrs[i].g = (byte)0;
           pclrs[i].b = (byte)0;
           ++i;
       }
       for (r=0; r < 256;r+=4)
       {
           pclrs[i].r = (byte)0;
           pclrs[i].g = (byte)r;
           pclrs[i].b = (byte)0;
           ++i;
       }
       for (r=0; r < 256;r+=4)
       {
           pclrs[i].r = (byte)0;
           pclrs[i].g = (byte)0;
           pclrs[i].b = (byte)r;
           ++i;
       }
       for (r=0; r < 256;r+=4)
       {
           pclrs[i].r = (byte)r;
           pclrs[i].g = (byte)r;
           pclrs[i].b = (byte)r;
           ++i;
       }
       for (;i<256;i++)
       {
           pclrs[i].r = 0;
           pclrs[i].g = 0;
           pclrs[i].b = 0;
       }
       assert (i <= 256);
       ((VngoPal8 *)pal)->set_hwpal(pclrs,256);
   }
   else if (type == 2)
   {
       for (r=0;r < 256;r+=4)
       {
           pclrs[(r>>2)].r = (byte)r;
           pclrs[(r>>2)].g = (byte)r;
           pclrs[(r>>2)].b = (byte)r;
           pclrs[(r>>2)+64].r = (byte)(r+1);
           pclrs[(r>>2)+64].g = (byte)r;
           pclrs[(r>>2)+64].b = (byte)r;
           pclrs[(r>>2)+128].r = (byte)r;
           pclrs[(r>>2)+128].g = (byte)(r+1);
           pclrs[(r>>2)+128].b = (byte)r;
           pclrs[(r>>2)+192].r = (byte)r;
           pclrs[(r>>2)+192].g = (byte)r;
           pclrs[(r>>2)+192].b = (byte)(r+1);
       }
       ((VngoPal8 *)pal)->set_hwpal(pclrs,256);
   }
   else if (type == 3)
   {
       for (r=0;r < 8;r++)
       {
           for(g=0;g < 8;g++)
           {
               for(b=0;b < 4;b++)
               {
                   pclrs[(r<<5)+(g<<2)+b].r=(byte)(r<<5);
                   pclrs[(r<<5)+(g<<2)+b].g=(byte)(g<<5);
                   pclrs[(r<<5)+(g<<2)+b].b=(byte)(b<<6);
               }
           }
       }
       ((VngoPal8 *)pal)->set_hwpal(pclrs,256);
   }
   else if (type == 1)
   {
       i=0;
       for (r=0;r < 16;r++)
       {
           pclrs[i].r = (byte)(r << 4);
           pclrs[i].g = 0;
           pclrs[i].b = 0;
           i++;
       }
       for (g=0;g < 16;g++)
       {
           pclrs[i].r = 0;
           pclrs[i].g = (byte)(g << 4);
           pclrs[i].b = 0;
           i++;
       }
       for (b=0;b < 16;b++)
       {
           pclrs[i].r = 0;
           pclrs[i].g = 0;
           pclrs[i].b = (byte)(b << 4);
           i++;
       }
       for (r=0,g=0,b=0;r < 16;r++,g++,b++)
       {
           pclrs[i].r = (byte)(r << 4);
           pclrs[i].g = (byte)(g << 4);
           pclrs[i].b = (byte)(b << 4);
           i++;
       }
       for (r=0,g=0,b=0;r < 16;r++,g++)
       {
           pclrs[i].r = (byte)(r << 4);
           pclrs[i].g = (byte)(g << 4);
           pclrs[i].b = (byte)(b << 4);
           i++;
       }
       for (r=0,g=0,b=0;r < 16;r++,b++)
       {
           pclrs[i].r = (byte)(r << 4);
           pclrs[i].g = (byte)(g << 4);
           pclrs[i].b = (byte)(b << 4);
           i++;
       }
       for (r=0,g=0,b=0;g < 16;g++,b++)
       {
           pclrs[i].r = (byte)(r << 4);
           pclrs[i].g = (byte)(g << 4);
           pclrs[i].b = (byte)(b << 4);
           i++;
       }
       for (r=0,g=0,b=0;b < 16;b++)
       {
           pclrs[i].r = (byte)(r << 4);
           pclrs[i].g = (byte)(g << 4);
           pclrs[i].b = (byte)(b << 4);
           i++;
           if ((b%3))
           {
               r++;
               g++;
           }
       }
       for (r=0,g=0,b=0;g < 16;g++)
       {
           pclrs[i].r = (byte)(r << 4);
           pclrs[i].g = (byte)(g << 4);
           pclrs[i].b = (byte)(b << 4);
           i++;
           if ((g%3))
           {
               r++;
               b++;
           }
       }
       for (r=0,g=0,b=0;r < 16;r++)
       {
           pclrs[i].r = (byte)(r << 4);
           pclrs[i].g = (byte)(g << 4);
           pclrs[i].b = (byte)(b << 4);
           i++;
           if ((r%3))
           {
               b++;
               g++;
           }
       }
       for (r=0,g=0,b=0;b < 16;b++)
       {
           pclrs[i].r = (byte)(r << 4);
           pclrs[i].g = (byte)(g << 4);
           pclrs[i].b = (byte)(b << 4);
           i++;
           if (!(b%3))
           {
               r++;
               g++;
           }
       }
       for (r=0,g=0,b=0;g < 16;g++)
       {
           pclrs[i].r = (byte)(r << 4);
           pclrs[i].g = (byte)(g << 4);
           pclrs[i].b = (byte)(b << 4);
           i++;
           if (!(g%3))
           {
               r++;
               b++;
           }
       }
       for (r=0,g=0,b=0;r < 16;r++)
       {
           pclrs[i].r = (byte)(r << 4);
           pclrs[i].g = (byte)(g << 4);
           pclrs[i].b = (byte)(b << 4);
           i++;
           if (!(r%3))
           {
               b++;
               g++;
           }
       }
       for (r=0,g=0,b=0;b < 16;b++,g++)
       {
           pclrs[i].r = (byte)(r << 4);
           pclrs[i].g = (byte)(g << 4);
           pclrs[i].b = (byte)(b << 4);
           i++;
           if ((b%3))
           {
               r++;
           }
       }
       assert (i <= 256);
       for (r=0,g=0,b=0;g < 16;g++,r++)
       {
           pclrs[i].r = (byte)(r << 4);
           pclrs[i].g = (byte)(g << 4);
           pclrs[i].b = (byte)(b << 4);
           i++;
           if ((g%3))
           {
               b++;
           }
       }
       assert (i <= 256);
       for (r=0,g=0,b=0;r < 16;r++,b++)
       {
           pclrs[i].r = (byte)(r << 4);
           pclrs[i].g = (byte)(g << 4);
           pclrs[i].b = (byte)(b << 4);
           i++;
           if ((r%3))
           {
               g++;
           }
       }
       assert (i <= 256);

       for (;i<256;i++)
       {
           pclrs[i].r = 0;
           pclrs[i].g = 0;
           pclrs[i].b = 0;
       }

       assert (i <= 256);

       ((VngoPal8 *)pal)->set_hwpal(pclrs,256);
   }
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - Message Maps
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
IMPLEMENT_DYNCREATE(CPalToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CPalToolDoc, CDocument)
	//{{AFX_MSG_MAP(CPalToolDoc)
	ON_COMMAND(IDM_FILE_IMPORT, OnFileImport)
	ON_COMMAND(IDM_FILE_EXPORT, OnFileExport)
	//}}AFX_MSG_MAP
	//ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	//ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
END_MESSAGE_MAP()


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
CPalToolDoc::CPalToolDoc():
	base_pal (0),
	curve_mode (LINEAR)
{
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
CPalToolDoc::~CPalToolDoc()
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - OnNewDocument
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL CPalToolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// Create a basic palette
	if (base_pal == 0)
	{
		CProgressDlg	prog;

		prog.m_pbar.SetRange (0, 2);
		prog.m_pbar.SetPos (0);
		prog.SetWindowText ("Computing Initial Palette");
		prog.ShowWindow (SW_SHOW);

		VngoPal8 *tpal = new VngoPal8;
		base_pal = tpal;
		tpal->shd_pal = new VngoShadePal8 (32);
		tpal->shd_pal->mid_point = 192;
		
		setup_hwpal (tpal, 1);
		prog.m_pbar.SetPos (1);

		tpal->convert.init (base_pal, 1);
		prog.m_pbar.SetPos (2);
		calc_shades ();
		prog.ShowWindow (SW_HIDE);

#if 0
		//base_pal->init (0);

		CFile	f ("\\charybds\\mythos95\\paltool\\default.pal", CFile::modeRead);
		CXFile	cf (&f);
		XFParseIFF	iff (&cf);
		iff.begin ();
		
		base_pal->init (0, &iff);
#endif
	}

	return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - Serialize
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::Serialize(CArchive& ar)
{
	CXFile		f (ar.GetFile ());
	XFParseIFF	iff (&f);
	iff.begin ();

	if (ar.IsStoring ())
	{
		// Storing code
		VngoPalIFF8	pal (base_pal);
		pal.save (&iff);
	}
	else
	{
		if (base_pal == 0)
		{
			base_pal = new VngoPal8;
		}

		// Loading code
		if (base_pal->init (0, &iff) != XF_ERR_NONE)
			::MessageBox (NULL, "Unable to read palette", "Error", MB_OK);
	}
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - Diagnostics
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#ifdef _DEBUG
void CPalToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPalToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//±±±±±±±±±±±±±±±±±±±±±±±±±± CPalToolDoc - Commands ±±±±±±±±±±±±±±±±±±±±±±±±±
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - use_color8
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::use_colors8 (VngoColor24bit *colors, int steps, int color_index)
{
    VngoShadePal8 &tp = *(VngoShadePal8 *)base_pal->shd_pal;

	for (int i = 0; i < steps; i++)
	{
	    tp[color_index].shl[i] = (byte)base_pal->get_index (colors[i]);
	}
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - use_colors15
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::use_colors15 (VngoColor24bit *colors, int steps, int color_index)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - use_colors16
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::use_colors16 (VngoColor24bit *colors, int steps, int color_index)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - use_colors24
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::use_colors24 (VngoColor24bit *colors, int steps, int color_index)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - calc_linear_colors
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::calc_linear_colors (VngoColor24bit *colors, int steps,
									  VngoColor24bit color, int break_point)
{
    VngoColorHLS    hlst;
    Flx16           t1;
    Flx16           base,mean,step,step2,max;

    hlst = color;
    mean = hlst.l;
    base = hlst.l * (Flx16)0.2;
   
    t1 = hlst.l - base;
    step = t1 / Flx16 (break_point);

	break_point--;	// Convert to 0 based value

    for (int i = break_point-1; i >= 0; i--)
    {
        hlst.l -= step;
        colors[i] = hlst;
    }

    colors[break_point] = color;

    hlst.l = mean;

    t1 = (Flx16)1 - hlst.l;
    max = t1 * (Flx16) 0.75;
    step = max / Flx16 (steps - break_point);

    for (i = break_point + 1; i < steps; i++)
    {
        hlst.l += step;
        colors[i] = hlst.to_RGB();
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - calc_bez_colors
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::calc_bez_colors (VngoColor24bit *colors, int steps,
							 	   VngoColor24bit color, int break_point)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - calc_quad_colors
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::calc_quad_colors (VngoColor24bit *colors, int steps,
							 		VngoColor24bit color, int break_point)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - calc_shades
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::calc_shades ()
{
	const int shade_count = 32;
	VngoColor24bit	shades[shade_count];

	void (CPalToolDoc:: *calc) (VngoColor24bit *, int, VngoColor24bit, int);

	switch (curve_mode)
	{
	case LINEAR:	calc = calc_linear_colors;
		break;
	case BEZIER:	calc = calc_bez_colors;
		break;
	case QUADRATIC:	calc = calc_quad_colors;
		break;
	}

	for (int i = 0; i < 256; i++)
	{
		(this->*calc) (shades, shade_count, base_pal->get_RGB (i), (shade_env_break()+7) >> 3);
		use_colors8 (shades, shade_count, i);
	}
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - ImportVGPalette
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int CPalToolDoc::ImportVGPalette (LPCSTR filename)
{
    VngoShadePal8   *tpal = (VngoShadePal8 *)base_pal->shd_pal;
	XFParseIFF  iffp;
	int         err=0;

	// Assert that there is memory allocated to load into.
	assert(base_pal != NULL);
	assert(base_pal->shd_pal != NULL);
//    assert(base_pal->hz_pal != NULL);

	err = iffp.open (filename,XF_OPEN_READ);
	if (err)
		return err;

	err = iffp.seekform (iffp.makeid('V','P','A','L'));
	if (err)
		return err;

	err = iffp.enterform();
	if (err)
		return err;

	// ---- Find and read the shade palette.
	err = iffp.seekchunk (iffp.makeid('s','h','d','P'));
	if (err)
		return err;

	// ---- Read the old shade palette format
	err = iffp.read (&(*tpal)[0]);
	if (err)
		return err;


#if 0
	// ---- Find and read the haze palette.
	err = iffp.seekchunk (iffp.makeid ('h','a','z','P'));
	if (err)
		return err;

	err = iffp.read (base_pal->hz_pal);
	if (err)
		return err;
#endif

	// ---- Find and read the hardware palette.
	err = iffp.seekchunk (iffp.makeid('h','w','d','P'));
	if (err)
		return err;

	err = iffp.read (&((VngoPal8 *)base_pal)->hw_pal);
	if (err)
		return err;

	// ---- Find and read the color conversion table.
	err = iffp.seekchunk (iffp.makeid ('c','n','v','t'));
	if (err)
		return err;

	err = iffp.read (&((VngoPal8 *)base_pal)->convert);
	if (err)
		return err;

	// ---- Clean up and close down.
	err = iffp.leaveform();
	if (err)
		return err;

	err = iffp.close();
	if (err)
		return err;

	// Initialize the palette header
	tpal->num_shd_lvl = 32;
	tpal->num_shd_lvl_bits = 5;
	tpal->mid_point = 192;

	// ---- Since no error occured return zero.
	return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - ImportWindowsPalette
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int CPalToolDoc::ImportWindowsPalette (LPCSTR filename)
{
	return 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// CPalToolDoc - OnFileImport
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void CPalToolDoc::OnFileImport() 
{
	// Import the BMP file.
	CFileDialog	fdlg (TRUE, ".pal", NULL, OFN_HIDEREADONLY | OFN_FILEMUSTEXIST,
"Bitmap Files (*.bmp;*.pcx;*.lbm;*.cel)|*.bmp;*.pcx;*.lbm;*.cel|Palette Files (*.pal)|*.pal|All Files (*.*)|*.*||");

	fdlg.m_ofn.lpstrTitle = "Import Picture's Palette";

	if (fdlg.DoModal() == IDOK)
	{
		CString pathname  = fdlg.GetPathName();
		CString extension = fdlg.GetFileExt();

		if (extension.CompareNoCase ("pal") == 0)
		{
			// This is either a windows palette or an old-style Vangogh palette.
			// Let's try the old-style palette first:
			if (ImportVGPalette (pathname) == 0)
			{
				// Successful import
			}
			else if (ImportWindowsPalette (pathname) == 0)
			{
				// Successful import
			}
			else
			{
				MessageBox (NULL, fdlg.GetFileTitle() + " has an unrecongnized format.  Aborting import.",
							"Error", MB_OK | MB_ICONEXCLAMATION);
			}

		}
		else
		{
			// It must be one of our bitmap formats
			XFParseBitmap	*bm;

			if (extension.CompareNoCase ("bmp") == 0)
			{
				bm = new XFParseBMP ();
			}
			else if (extension.CompareNoCase ("pcx") == 0)
			{
				bm = new XFParsePCX ();
			}
			else if (extension.CompareNoCase ("lbm") == 0)
			{
				bm = new XFParseLBM ();
			}
			else if (extension.CompareNoCase ("cel") == 0)
			{
				bm = new XFParseCEL ();
			}
			else
			{
				MessageBox (NULL, "Unable to load file: '" + pathname + "'.  Canceling import.",
							"Error", MB_OK | MB_ICONEXCLAMATION);
				return;
			}

			if (bm->nameread(pathname) != 0 || bm->bm->bpp != 1)
			{
				MessageBox (NULL, "File not supported: '" + pathname + "'.  Canceling import.",
							"Error", MB_OK | MB_ICONEXCLAMATION);
				return;
			}

			CProgressDlg	prog;

			prog.m_pbar.SetRange (0, 2);
			prog.m_pbar.SetPos (0);
			prog.SetWindowText ("Computing Import Palette");
			prog.ShowWindow (SW_SHOW);

			((VngoPal8 *)base_pal)->set_hwpal ((VngoColor24bit *)bm->bm->pal, 256);
			prog.m_pbar.SetPos (1);
			((VngoPal8 *)base_pal)->convert.init (base_pal, 1);
			prog.m_pbar.SetPos (2);
			calc_shades ();

			delete bm;
		}

		// Update our internal values, and redisplay everything
		UpdateAllViews (NULL);
	}
}

void CPalToolDoc::OnFileExport() 
{
	// Export the palette to some "public" format.
	CFileDialog	fdlg (FALSE, ".pal", NULL, OFN_HIDEREADONLY,
						"Windows Palette Files (*.pal)|*.pal||");

	fdlg.m_ofn.lpstrTitle = "Export Palette";

	if (fdlg.DoModal() == IDOK)
	{
		switch (fdlg.m_ofn.nFilterIndex)
		{
		case 0:	// User-specified file extension (assume Windows Palette)
		case 1: // Windows Palette Files
			MessageBox (NULL, "Windows Format export not yet implemented",
						"Note", MB_OK | MB_ICONEXCLAMATION);
			break;

		default:
			MessageBox (NULL, "Invalid Export Format selected",
						"Error", MB_OK | MB_ICONEXCLAMATION);
			break;
		}
	}
}


// eof - paltodoc.cpp
