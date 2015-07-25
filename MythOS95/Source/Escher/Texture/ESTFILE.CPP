//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//������������������� Microsoft Windows 95/NT Version �����������������������
//���������������������������������������������������������������������������
//�����������Copyright�(c)�1994-1998�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
//
// Created by Tim Little & Chuck Walbourn
//
// estfile.cpp
//
// Contains the code for the texture file management routines that are
// static members of EschTexture.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "escher.hpp"
#include "esfile.hpp"

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

#define INIT_TFILE_SIZE 4

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschTexture - file_load                                                  �
//                                                                          �
// Loads an instance of the texture from the data file if found in          �
// registered texture files.                                                �
//���������������������������������������������������������������������������
EschTexture *EschTexture::file_load(const char *n, VngoPal *pal, dword ctrlfl)
{
    if (!EschSysInstance || !EschSysInstance->tfile || !n)
        return 0;

//��� Scan through each registered file
    for(ulong i=0; i < EschSysInstance->tfile_hi; i++)
    {
        EschTextureFile *tf = &EschSysInstance->tfile[i];

        if (tf->iff)
        {
            assertMyth("EschTexture::file_load needs valid entry",
                       tf->names != 0 && tf->count > 0);

            //��� Find name in list of textures located within this file
            for(ulong j=0; j < tf->count; j++)
            {
                if (!strncmp(n,&tf->names[j*ESCH_MAX_NAME],ESCH_MAX_NAME))
                {
                    //��� Found, so load texture
                    XFParseIFF *iff = tf->iff;

                    for(;;)
                    {
                        if (iff->next() != XF_ERR_NONE)
                        {
                            if (!iff->depth)
                            {
                                //��� Shouldn't happen, but just in case...
                                iff->topofcontext(0);

                                return 0;
                            }
                            iff->leaveform();
                            continue;
                        }

                        if (iff->chunkid == iff->makeid('F','O','R','M'))
                        {
                            if (iff->formid == iff->makeid('E','M','T','L')
                                || iff->formid == iff->makeid('E','M','T','1'))
                            {
                                if (j > 0)
                                    j--;
                                else
                                {
                                    EschTexture *t = ((ctrlfl & ESCH_TXTLD_MFRAME)
                                                      && iff->formid == iff->makeid('E','M','T','1'))
                                                     ? (EschTexture *) new EschMultiFrameTexture
                                                     : (EschTexture *) new EschStaticTexture;

                                    if (t && t->load(iff, n, ctrlfl, pal))
                                    {
                                        delete t;
                                        t=0;
                                    }

                                    while (iff->depth)
                                        iff->leaveform();

                                    iff->topofcontext(0);

                                    return t;
                                }
                            }

                            // Must scan inside any ESEN Scene forms.
                            else if (iff->formid == iff->makeid('E','S','E','N'))
                            {
                                iff->enterform();
                            }

                            // Must scan inside any EMSH Mesh forms.
                            else if (iff->formid == iff->makeid('E','M','S','H'))
                            {
                                iff->enterform();
                            }

                            // Must scan inside any ETER Terrain forms.
                            else if (iff->formid == iff->makeid('E','T','E','R'))
                            {
                                iff->enterform();
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}


//�������������������������������������������������������������������������Ŀ
// EschTexture - file_register                                              �
//                                                                          �
// Adds a new texture file to the list of shared texture files.             �
//���������������������������������������������������������������������������
esch_error_codes EschTexture::file_register(const char *fname)
{
    assertMyth("EschTexture::file_register needs System",
               EschSysInstance != 0);

//��� Initialize texture file array if needed
    if (!EschSysInstance->tfile)
    {
        EschSysInstance->tfile = new EschTextureFile[INIT_TFILE_SIZE];
        if (!EschSysInstance->tfile)
            return ESCH_ERR_NOMEMORY;

        EschSysInstance->tfile_hi = 0;
        EschSysInstance->tfile_max = INIT_TFILE_SIZE;
    }
    
//��� Find open slot
    for(ulong i=0; i < EschSysInstance->tfile_hi; i++)
    {
        if (!EschSysInstance->tfile[i].iff)
            break;
    }

    if (i >= EschSysInstance->tfile_hi)
    {
        if (EschSysInstance->tfile_hi >= EschSysInstance->tfile_max)
        {
            //��� Must expand
            EschTextureFile *t
                    = new EschTextureFile[EschSysInstance->tfile_max << 1];
            if (!t)
                return ESCH_ERR_NOMEMORY;
            
            memcpy(t, EschSysInstance->tfile, EschSysInstance->tfile_max
                                               * sizeof(EschTextureFile));
            delete [] EschSysInstance->tfile;
            EschSysInstance->tfile=t;
            EschSysInstance->tfile_max <<= 1;
        }

        EschSysInstance->tfile_hi++;
    }

//��� Fill slot
    assert(i < EschSysInstance->tfile_hi && i < EschSysInstance->tfile_max);

    EschTextureFile *tf = &EschSysInstance->tfile[i];

    strncpy(tf->fname, fname, XF_MAX_PATH);
    tf->flags = 0;
    tf->count = 0;

    tf->iff = new XFParseIFF;
    if (!tf->iff)
        return ESCH_ERR_NOMEMORY;

    XFParseIFF *iff = tf->iff;

    //��� Try to open file
    if (iff->open(fname,XF_OPEN_READ | XF_OPEN_DENYWRITE))
    {
        delete tf->iff;
        tf->iff = 0;
        return ESCH_ERR_FILEERROR;
    }

    //��� Count number of EMTL/EMT1 chunks
    for(;;)
    {
        if (iff->next() != XF_ERR_NONE)
        {
            if (!iff->depth)
                break;
            iff->leaveform();
            continue;
        }

        if (iff->chunkid == iff->makeid('F','O','R','M'))
        {
            if (iff->formid == iff->makeid('E','M','T','L')
                || iff->formid == iff->makeid('E','M','T','1'))
            {
                tf->count++;
            }

            // Must scan inside any ESEN Scene forms.
            else if (iff->formid == iff->makeid('E','S','E','N'))
            {
                iff->enterform();
            }

            // Must scan inside any EMSH Mesh forms.
            else if (iff->formid == iff->makeid('E','M','S','H'))
            {
                iff->enterform();
            }

            // Must scan inside any ETER Terrain forms.
            else if (iff->formid == iff->makeid('E','T','E','R'))
            {
                iff->enterform();
            }
        }
    }

    if (!tf->count)
    {
        delete tf->iff;
        tf->iff = 0;
        return ESCH_ERR_NOTFOUND;
    }
    
    iff->topofcontext(0);

    //��� Allocate space for names
    tf->names = new char[ESCH_MAX_NAME*tf->count];
    if (!tf->names)
    {
        delete tf->iff;
        tf->iff = 0;
        return ESCH_ERR_NOMEMORY;
    }

    //��� Read names from EMTL/EMT1 chunks
    esch_error_codes err = ESCH_ERR_NONE;

    for(ulong j=0; j < tf->count;)
    {
        if (iff->next() != XF_ERR_NONE)
        {
            if (!iff->depth)
                break;
            iff->leaveform();
            continue;
        }

        if (iff->chunkid == iff->makeid('F','O','R','M'))
        {
            if (iff->formid == iff->makeid('E','M','T','L')
                || iff->formid == iff->makeid('E','M','T','1'))
            {
                iff->enterform();

                if (iff->seekchunk(iff->makeid('M','H','D','R'))
                    || iff->chunkSize != sizeof(EschFileMtlMHDR))
                {
                    iff->leaveform();
                    err=ESCH_ERR_INVALIDDATA;
                    goto error_exit;
                }

                EschFileMtlMHDR header;
                if (iff->read(&header))
                {
                    iff->leaveform();
                    err=ESCH_ERR_FILEERROR;
                    goto error_exit;
                }

                strncpy(&tf->names[j*ESCH_MAX_NAME],header.name,ESCH_MAX_NAME);

                iff->leaveform();

                j++;
            }

            // Must scan inside any ESEN Scene forms.
            else if (iff->formid == iff->makeid('E','S','E','N'))
            {
                iff->enterform();
            }

            // Must scan inside any EMSH Mesh forms.
            else if (iff->formid == iff->makeid('E','M','S','H'))
            {
                iff->enterform();
            }

            // Must scan inside any ETER Terrain forms.
            else if (iff->formid == iff->makeid('E','T','E','R'))
            {
                iff->enterform();
            }
        }
    }

    if (j < tf->count)
    {
        err=ESCH_ERR_MISSINGDATA;
        goto error_exit;
    }

    iff->topofcontext(0);

    return ESCH_ERR_NONE;

error_exit : ;

    if (tf->iff)
        delete tf->iff;
    tf->iff = 0;

    if (tf->names)
        delete [] tf->names;
    tf->names = 0;

    return err;
}


//�������������������������������������������������������������������������Ŀ
// EschTexture - file_unregister                                            �
//                                                                          �
// Removes a registered texture file from the list of shared texture files. �
// If '0' is passed as the name, all files are unregistered.                �
//���������������������������������������������������������������������������
void EschTexture::file_unregister(const char *fname)
{
    assertMyth("EschTexture::file_unregister needs System",
               EschSysInstance != 0);

    if (!EschSysInstance->tfile)
        return;

//��� Scan through each registered file
    for(ulong i=0; i < EschSysInstance->tfile_hi; i++)
    {
        EschTextureFile *tf = &EschSysInstance->tfile[i];

        if (tf->iff)
        {
            if (!fname || !strncmp(fname,tf->fname,XF_MAX_PATH))
            {
                if (tf->names)
                {
                    delete [] tf->names;
                    tf->names = 0;
                }
                if (tf->iff)
                {
                    delete tf->iff;
                    tf->iff = 0;
                }
                tf->flags = 0;
                tf->count = 0;
                *tf->fname = 0;
            }
        }
    }
}

//��� End of module - estfile.cpp ���
