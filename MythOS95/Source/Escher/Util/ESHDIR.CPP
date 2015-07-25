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
//ששששששששששCopyrightש(c)ש1994,ש1995שbyשCharybdisשEnterprises,שInc.שששששששששש
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
//                              *** Utilities ***
//
// Created by Tim Little & Chuck Walbourn
//
// eshdir.cpp
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <conio.h>
#include <iostream.h>
#include <stdlib.h>

#include "debug.h"
#include "xfile.hpp"
#include "escher.hpp"
#include "esfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define FLAGS_PAUSE    0x1

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

STATIC void print_help(int full);
STATIC void print_error(XFParseIFF &xp, char *s=0);

STATIC void directory(XFParseIFF &iff);
STATIC void pause(void);

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

STATIC dword   Flags=0;

STATIC ulong   Line=0;
STATIC ulong   Maxline=24;

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// main                                                                     ³
//                                                                          ³
// Entry point for the ESHDIR utility.                                      ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
void main(int argc, char *argv[])
{
    int         i;
    char        *fn;
    XFParseIFF  iff;

//ִִִ Handle no filename for directory...
    if (argc < 2)
    {
        print_help(0);
        return;
    }

//ִִִ Process arguments
    for(i=1, fn=0; i < argc; i++)
    {
        if (*argv[i] == '-' || *argv[i] == '/')
        {
            switch (argv[i][1])
            {
                case 'p':
                case 'P':
                    Flags |= FLAGS_PAUSE;
                    break;
                case '?':
                    print_help(1);
                    return;
                default:
                    cout << "Unknown option " << argv[i] << " ignored\n";
                    break;
            }
        }
        else if (!fn)
        {
            fn=argv[i];
        }
    }

    if (!fn)
    {
        print_help(0);
        return;
    }

//ִִִ Check to see if supplied iff file exists
    if (!xf_exist(fn))
    {
        cout << "±±± " << fn << " does not exist\n";
        return;
    }

//ִִִ Open supplied iff file
    if (iff.open(fn,XF_OPEN_READ))
    {
        print_error(iff,"Failed to open file");
        return;
    }
   
//ִִִ Print outline of file contents
    cout << "°± Escher Directory - (C) 1994, 1995 Charybdis Enterprises, Inc. ±°\n";
    cout << "   File: " << fn << "\n";
    Line=2;
    directory(iff);

//ִִִ Close file
    iff.close();
}


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// print_help                                                               ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
STATIC void print_help(int full)
{
    cout << "°± Escher Directory - (C) 1994, 1995 Charybdis Enterprises, Inc. ±°\n";
    cout << "                      " __DATE__ "\n";
    cout << "   Usage: eshdir [-p] <filename.iff>\n";
    if (full)
    {
        cout << "          -p = Pause between screens.\n";
    }
}

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// print_error                                                              ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ
STATIC void print_error(XFParseIFF &xp, char *s)
{
    cout << "±±± ";
   
    if (s)
    {
        cout << s << ", ";
    }
   
    switch (xp.error())
    {
        case XF_ERR_NOTIFF:
            cout << "not an IFF file error";
            break;
        case XF_ERR_CHUCKNOTFOUND:
            cout << "chunk not found error";
            break;
        case XF_ERR_FORMNOTFOUND:
            cout << "form not found error";
            break;
        case XF_ERR_UNEXPECTEDEOF:
            cout << "unexpected end-of-file error";
            break;
        case XF_ERR_INVALIDFORFORM:
            cout << "invalid operation for FORM error";
            break;
        case XF_ERR_INVALIDFORCHUNK:
            cout << "invalid operation for chunk error";
            break;
        case XF_ERR_INVALIDID:
            cout << "invalid identifier error";
            break;
        case XF_ERR_TRUNCATEDCHUNK:
            cout << "truncated chunk error";
            break;
        case XF_ERR_WRITENOTALLOWED:
            cout << "write not allowed error";
            break;
        case XF_ERR_MAXDEPTHREACHED:
            cout << "maximum supported depth reached error";
            break;
        default:
            cout << "error " << (int)xp.error();
            break;
    }
   
    cout << "\n";
    pause();
}


//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// directory                                                                ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ

#define COLUMN 45
#define MAXCOLUMN  75

STATIC void directory(XFParseIFF &iff)
{
    ulong               i;
    EschFileSceneHDR    sheader;
    EschFileMeshHDR     mheader;
    EschFileMeshEXNT    mextents;
    EschFileMeshMTL     *emtls;
    EschFileMtlMHDR     mtlhdr;
    EschMatrix          mtx;
    EschFileCamera      cdata;
    EschFileLightAmbi   adata;
    EschFileLightPoint  pdata;
    EschFileLightVect   vdata;
    EschFileMeshHIER    ehier;
    EschFileTerrHDR     theader;
    
    memset(&mheader,0,sizeof(EschFileMeshHDR));

//ִִ Loop through current level
    while (iff.next() == XF_ERR_NONE)
    {

        if ((iff.makeid('F','O','R','M') == iff.chunkid)
             && (iff.makeid('E','S','E','N') == iff.formid))
        {
            if (iff.enterform() != XF_ERR_NONE)
            {
                print_error(iff,"Problem entering 'ESEN' FORM");
            }
            else
            {
                cout << "Scene";
                for(i=sizeof("Object")-1; i < MAXCOLUMN; i++)
                    cout << "ֽ";
                cout << "\n";
                pause();

                iff.enterform();

                iff.next();

                if (iff.chunkSize != sizeof(EschFileSceneHDR))
                {
                    print_error(iff,"Scene header chunk not valid, incorrect size");
                }
                else if (iff.read(&sheader))
                {
                    print_error(iff,"Problem reading scene header");
                }
                else
                {  
                    cout << sheader.name << "\n";
                    pause();
                    cout << "       # Cameras: " << sheader.ncameras << "\n";
                    pause();
                    cout << "       # Objects: " << sheader.nobjects << "\n";
                    pause();
                    cout << "       # VLights: " << sheader.nvectorlights << "\n";
                    pause();
                    cout << "       # PLights: " << sheader.npointlights << "\n";
                    pause();
                }

                directory(iff);
                iff.leaveform();

                cout << "\n";
                pause();
            }
            
        }

        if ((iff.makeid('F','O','R','M') == iff.chunkid)
            && (iff.makeid('E','M','S','H') == iff.formid))
        {

            if (iff.enterform() != XF_ERR_NONE)
            {
                print_error(iff,"Problem entering 'EMSH' FORM");
            }
            else
            {
                cout << "Object";
                for(i=sizeof("Object")-1; i < MAXCOLUMN; i++)
                    cout << "ִ";
                cout << "\n";
                pause();

                while (iff.next() == XF_ERR_NONE)
                {

                    if (iff.makeid('H','D','R',' ') == iff.chunkid)
                    {

                        if (iff.chunkSize != sizeof(EschFileMeshHDR))
                        {
                            print_error(iff,"Object header chunk not valid, incorrect size");
                        }
                        else if (iff.read(&mheader))
                        {
                            print_error(iff,"Problem reading object header");
                        }
                        else 
                        {  
                            cout << "³" << mheader.name;
                            cout.flush();
                            printf( "\tFLAGS: %x",mheader.flags);
                            cout << "\tNV: " << mheader.nverts;
                            cout << "\tNF: " << mheader.nfaces << "\n";
                            pause();
                        }
                    }
                    else if (iff.makeid('E','X','N','T') == iff.chunkid)
                    {
                        if (iff.chunkSize != sizeof(EschFileMeshEXNT))
                        {
                            print_error(iff,"Object extents chunk not valid, incorrect size");
                        }
                        else if (iff.read(&mextents))
                        {
                            print_error(iff,"Problem reading object extents");
                        }
                        else
                        {  
                            cout << "³  CEN: "  << (float)mextents.cenx << " "
                                                << (float)mextents.ceny << " "
                                                << (float)mextents.cenz << "\n";
                            pause();
                            cout << "³  RAD: " << (float)mextents.extent_radius << "\n";
                            pause();
                            cout << "³  MIN: " << (float)mextents.minx << " "
                                               << (float)mextents.miny << " "
                                               << (float)mextents.minz << "\n";
                            pause();
                            cout << "³  MAX: " << (float)mextents.maxx << " "
                                               << (float)mextents.maxy << " "
                                               << (float)mextents.maxz << "\n";
                            pause();
                        }
                    }
                    else if (iff.makeid('M','T','R','X') == iff.chunkid)
                    {
                        if (iff.chunkSize != sizeof(EschMatrix))
                        {
                            print_error(iff,"Matrix chunk not valid, incorrect size");
                        }
                        else if (iff.read(&mtx))
                        {
                            print_error(iff,"Problem reading matrix");
                        }
                        else
                        {  
                            cout << "³ MTRX: " << (float)mtx.mtx[ESCH_MTX_A] << " "
                                               << (float)mtx.mtx[ESCH_MTX_B] << " "
                                               << (float)mtx.mtx[ESCH_MTX_C] << "\n";
                            pause();
                            cout << "³       " << (float)mtx.mtx[ESCH_MTX_D] << " "
                                               << (float)mtx.mtx[ESCH_MTX_E] << " "
                                               << (float)mtx.mtx[ESCH_MTX_F] << "\n";
                            pause();
                            cout << "³       " << (float)mtx.mtx[ESCH_MTX_G] << " "
                                               << (float)mtx.mtx[ESCH_MTX_H] << " "
                                               << (float)mtx.mtx[ESCH_MTX_I] << "\n";
                            pause();
                            cout << "³       " << (float)mtx.mtx[ESCH_MTX_J] << " "
                                               << (float)mtx.mtx[ESCH_MTX_K] << " "
                                               << (float)mtx.mtx[ESCH_MTX_L] << "\n";
                            pause();
                        }
                    }
                    else if (iff.makeid('H','I','E','R') == iff.chunkid)
                    {
                        if (iff.chunkSize != sizeof(EschFileMeshHIER))
                        {
                            print_error(iff,"Hierarchy chunk not valid, incorrect size");
                        }
                        else if (iff.read(&ehier))
                        {
                            print_error(iff,"Problem reading hierarchy chunk");
                        }
                        else 
                        {  
                            cout << "³ HIER: " << ehier.parent << "\n";
                            pause();
                        }
                    }
                    else if (iff.makeid('M','T','L',' ') == iff.chunkid)
                    {
                        if (iff.chunkSize != (sizeof(EschFileMeshMTL) * mheader.nmtls))
                        {
                            print_error(iff,"Object materials chunk not valid, incorrect size");
                        }
                        else if (mheader.nmtls)
                        {
                            emtls = new EschFileMeshMTL[mheader.nmtls];

                            if (iff.read(emtls))
                            {
                                print_error(iff,"Problem reading object materials");
                            }
                            else
                            {  
                                cout << "³ MTLS:\n";
                                pause();
                                for(i=0; i < mheader.nmtls; i++)
                                {
                                    char name[ESCH_MAX_NAME+1];
                                    strncpy(name,emtls[i].name,ESCH_MAX_NAME);
                                    name[ESCH_MAX_NAME] = 0;
                                    cout << "³       " << name << "\n";
                                    pause();
                                }
                            }

                            delete [] emtls;
                        }
                    }
                    else if ((iff.makeid('F','O','R','M') == iff.chunkid)
                            && (iff.makeid('E','M','T','L') == iff.formid))
                    {

                        cout << "³ MDATA:\n";
                        pause();

                        iff.enterform();

                        if (iff.seekchunk(iff.makeid('M','H','D','R')))
                        {
                            cout << "³ Can't find header\n";
                            pause();
                        }
                        else if (iff.chunkSize != sizeof(EschFileMtlMHDR))
                        {
                            print_error(iff,"Object materials data header chunk not valid, incorrect size");
                        }
                        else
                        {
                            if (iff.read(&mtlhdr))
                            {
                                print_error(iff,"Problem reading object materials data header");
                            }
                            else
                            {  
                                char name[ESCH_MAX_NAME+1];
                                strncpy(name,mtlhdr.name,ESCH_MAX_NAME);
                                name[ESCH_MAX_NAME] = 0;

                                cout << "³     " << name;
                                cout << " x=" << mtlhdr.xsize << " y=" << mtlhdr.ysize;
                                cout << " nf=" << mtlhdr.nframes << " type=" << mtlhdr.type;
                                cout << " pal=" << mtlhdr.pname << "\n";
                                pause();
                            }
                        }

                        if (iff.seekchunk(iff.makeid('B','O','D','Y')))
                        {
                            cout << "³ Can't find body\n";
                            pause();
                        }
                        else if ((mtlhdr.type==1)
                                 && (iff.chunkSize != (ulong)(mtlhdr.xsize * mtlhdr.ysize)))
                        {
                            print_error(iff,"Object materials data body chunk not valid, incorrect size");
                        }

                        iff.leaveform();
                    }
                }

                cout << "ְ";
                for(i=1; i < MAXCOLUMN; i++)
                    cout << "ִ";
                cout << "\n";
                pause();

                iff.leaveform();
            }
        }
        else if (iff.makeid('E','C','A','M') == iff.chunkid)
        {

            if (iff.chunkSize != sizeof(EschFileCamera))
            {
                print_error(iff,"Camera chunk not valid, incorrect size");
            }
            else if (iff.read(&cdata))
            {
                print_error(iff,"Problem reading camera chunk");
            }
            else
            {
                cout << "Camera";
                for(i=sizeof("Camera")-1; i < MAXCOLUMN; i++)
                    cout << "ִ";
                cout << "\n";
                pause();

                cout << "³" << cdata.name << "\n";
                pause();
                cout << "³   POS: " << (float) cdata.x;
                cout << " " << (float) cdata.y;
                cout << " " << (float) cdata.z << "\n";
                pause();
                cout << "³   DIR: " << (float) cdata.diri;
                cout << " " << (float) cdata.dirj;
                cout << " " << (float) cdata.dirk << "\n";
                pause();
                cout << "³   TOP: " << (float) cdata.topi;
                cout << " " << (float) cdata.topj;
                cout << " " << (float) cdata.topk << "\n";
                pause();
                cout << "³   FOV: " << (float) cdata.fov << "\n";
                pause();

                cout << "ְ";
                for(i=1; i < MAXCOLUMN; i++)
                    cout << "ִ";
                cout << "\n";
                pause();
            }
        }
        else if (iff.makeid('E','A','M','B') == iff.chunkid)
        {

            if (iff.chunkSize != sizeof(EschFileLightAmbi))
            {
                print_error(iff,"Ambient chunk not valid, incorrect size");
            }
            else if (iff.read(&adata))
            {
                print_error(iff,"Problem reading abmient light chunk");
            }
            else
            {
                cout << "Ambient";
                for(i=sizeof("Ambient")-1; i < MAXCOLUMN; i++)
                    cout << "ִ";
                cout << "\n";
                pause();
               
                cout << "³" << adata.name;
                cout.flush();
                printf( "\tFLAGS: %x\n",adata.flags);
                pause();
                cout << "³COLOR: " << (adata.color & 0xff) << " "
                                   << ((adata.color >> 8) & 0xff) << " "
                                   << ((adata.color >> 16) & 0xff) << "\n";
                pause();
               
                cout << "ְ";
                for(i=1; i < MAXCOLUMN; i++)
                    cout << "ִ";
                cout << "\n";
                pause();
            }
        }
        else if (iff.makeid('E','V','E','C') == iff.chunkid)
        {

            if (iff.chunkSize != sizeof(EschFileLightVect))
            {
                print_error(iff,"Vector chunk not valid, incorrect size");
            }
            else if (iff.read(&vdata))
            {
                print_error(iff,"Problem reading vector light chunk");
            }
            else
            {
                cout << "Vector Light";
                for(i=sizeof("Vector Light")-1; i < MAXCOLUMN; i++)
                    cout << "ִ";
                cout << "\n";
                pause();
               
                cout << "³" << vdata.name;
                cout.flush();
                printf( "\tFLAGS: %x\n",vdata.flags);
                pause();
                cout << "³COLOR: " << (vdata.color & 0xff) << " "
                                   << ((vdata.color >> 8) & 0xff) << " "
                                   << ((vdata.color >> 16) & 0xff) << "\n";
                pause();
                cout << "³  DIR: " << (float)vdata.i << " ";
                cout << (float)vdata.j << " ";
                cout << (float)vdata.k << "\n";
                pause();
               
                cout << "ְ";
                for(i=1; i < MAXCOLUMN; i++)
                    cout << "ִ";
                cout << "\n";
                pause();
            }
        }
        else if (iff.makeid('E','P','N','T') == iff.chunkid)
        {

            if (iff.chunkSize != sizeof(EschFileLightPoint))
            {
                print_error(iff,"Point chunk not valid, incorrect size");
            }
            else if (iff.read(&pdata))
            {
                print_error(iff,"Problem reading point light chunk");
            }
            else
            {
                cout << "Point Light";
                for(i=sizeof("Point Light")-1; i < MAXCOLUMN; i++)
                    cout << "ִ";
                cout << "\n";
                pause();
               
                cout << "³" << pdata.name;
                cout.flush();
                printf( "\tFLAGS: %x\n",pdata.flags);
                pause();
                cout << "³COLOR: " << (pdata.color & 0xff) << " "
                                   << ((pdata.color >> 8) & 0xff) << " "
                                   << ((pdata.color >> 16) & 0xff) << "\n";
                pause();
                cout << "³  POS: " << (float)pdata.x << " ";
                cout << (float)pdata.y << " ";
                cout << (float)pdata.z << "\n";
                pause();
               
                cout << "ְ";
                for(i=1; i < MAXCOLUMN; i++)
                    cout << "ִ";
                cout << "\n";
                pause();
            }
        }
        else if ((iff.makeid('F','O','R','M') == iff.chunkid)
                 && (iff.makeid('E','T','E','R') == iff.formid))
        {

            if (iff.enterform() != XF_ERR_NONE)
            {
                print_error(iff,"Problem entering 'ETER' FORM");
            }
            else
            {
                cout << "Terrain";
                for(i=sizeof("Terrain")-1; i < MAXCOLUMN; i++)
                    cout << "ִ";
                cout << "\n";
                pause();

                while (iff.next() == XF_ERR_NONE)
                {

                    if (iff.makeid('H','D','R',' ') == iff.chunkid)
                    {

                        if (iff.chunkSize != sizeof(EschFileTerrHDR))
                        {
                            print_error(iff,"Terrain header chunk not valid, incorrect size");
                        }
                        else if (iff.read(&theader))
                        {
                            print_error(iff,"Problem reading terrain header");
                        }
                        else 
                        {  
                            cout << "³" << theader.name;
                            cout.flush();
                            printf( "\tFLAGS: %x\n",theader.flags);
                            pause();
                            cout << "³  SIZE: " << theader.width << " by "
                                               << theader.depth << endl;
                            pause();
                            cout << "³ SCALE: X:" << (float)theader.wscale;
                            cout << " D:" << (float)theader.dscale;
                            cout << " H:" << (float)theader.hscale << endl;
                            pause();
                            cout << "³ PNAME: " << theader.palname << endl;
                            pause();
                        }
                    }
                    else if (iff.makeid('D','E','S','C') == iff.chunkid)
                    {
                        char    buff[256];

                        if (iff.read(buff))
                        {
                            print_error(iff,"Problem reading terrain description");
                        }
                        else 
                        {
                            cout << "³  DESC: " <<  buff << endl;
                        }
                    }
                    else if (iff.makeid('A','U','T','H') == iff.chunkid)
                    {
                        char    buff[256];

                        if (iff.read(buff))
                        {
                            print_error(iff,"Problem reading terrain author string");
                        }
                        else 
                        {
                            cout << "³  AUTH: " <<  buff << endl;
                        }
                    }
                    else if (iff.makeid('(','C',')',' ') == iff.chunkid)
                    {
                        char    buff[256];

                        if (iff.read(buff))
                        {
                            print_error(iff,"Problem reading terrain copyright notice");
                        }
                        else 
                        {
                            cout << "³   (C): " <<  buff << endl;
                        }
                    }
                    else if (iff.makeid('S','U','R','F') == iff.chunkid)
                    {
                        cout << "³ Contains surface information" << endl;
                    }
                    else if (iff.makeid('N','R','M','L') == iff.chunkid)
                    {
                        cout << "³ Contains normals" << endl;
                    }
                    else if ((iff.makeid('F','O','R','M') == iff.chunkid)
                            && (iff.makeid('E','M','T','L') == iff.formid))
                    {

                        cout << "³ MDATA:\n";
                        pause();

                        iff.enterform();

                        if (iff.seekchunk(iff.makeid('M','H','D','R')))
                        {
                            cout << "³ Can't find header\n";
                            pause();
                        }
                        else if (iff.chunkSize != sizeof(EschFileMtlMHDR))
                        {
                            print_error(iff,"Object materials data header chunk not valid, incorrect size");
                        }
                        else
                        {
                            if (iff.read(&mtlhdr))
                            {
                                print_error(iff,"Problem reading object materials data header");
                            }
                            else
                            {  
                                char name[ESCH_MAX_NAME+1];
                                strncpy(name,mtlhdr.name,ESCH_MAX_NAME);
                                name[ESCH_MAX_NAME] = 0;

                                cout << "³     " << name;
                                cout << " x=" << mtlhdr.xsize << " y=" << mtlhdr.ysize;
                                cout << " nf=" << mtlhdr.nframes << " type=" << mtlhdr.type;
                                cout << " pal=" << mtlhdr.pname << "\n";
                                pause();
                            }
                        }

                        if (iff.seekchunk(iff.makeid('B','O','D','Y')))
                        {
                            cout << "³ Can't find body\n";
                            pause();
                        }
                        else if ((mtlhdr.type==1)
                                 && (iff.chunkSize != (ulong)(mtlhdr.xsize * mtlhdr.ysize)))
                        {
                            print_error(iff,"Object materials data body chunk not valid, incorrect size");
                        }

                        iff.leaveform();
                    }
                }

                cout << "ְ";
                for(i=1; i < MAXCOLUMN; i++)
                    cout << "ִ";
                cout << "\n";
                pause();

                iff.leaveform();
            }
        }
    }

    if (iff.error() != XF_ERR_EOF)
    {
        print_error(iff,"Problem processing file");
    }
}

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ¿
// Pause                                                                    ³
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִÙ

STATIC void pause(void)
{
    if ((Flags & FLAGS_PAUSE) && (++Line >= Maxline))
    {
        cout << "°° More °°\r";
        cout.flush();
        getch();
        Line=1;
    }
}

//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
// _charybdis_assert
// 
// Handler for failed asserts.  If msg is set to non-NULL, then an assertMyth
// was used with a comment.
//ִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִִ
extern "C" void _charybdis_assert(char *msg, char *exp, char *f, unsigned ln)
{
    cout.flush();
    printf("\n\n±±± Assertion Failed ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n"
           "Expr:\t%s\n"
           "File:\t%s\t\tLine %d\n",exp,f,ln);
    if (msg)
    {
        printf("Comment:\n%s\n",msg);
    }

    exit(1);
}

//°±² End of module - eshdir.cpp ²±°

