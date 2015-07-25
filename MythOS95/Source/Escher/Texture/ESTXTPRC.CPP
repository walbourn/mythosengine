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
//�����������Copyright�(c)�1994-1997�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//��������������������� Microsoft Windows '95 Version �����������������������
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
// estxtprc.cpp
//
// EschProceduralTexture is a standard interface level for developing
// textures which are generated procedurally.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "escher.hpp"

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschProceduralTexture - Destructor                                       �
//���������������������������������������������������������������������������
EschProceduralTexture::~EschProceduralTexture()
{
    release();
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschProceduralTexture - release                                          �
//                                                                          �
// Removes the output buffer from memory.                                   �
//���������������������������������������������������������������������������
void EschProceduralTexture::release()
{
    if (txt.tex)
    {
        delete [] txt.tex;
        txt.tex = 0;
    }

    EschTexture::release();
}


//�������������������������������������������������������������������������Ŀ
// EschProceduralTexture - lock                                             �
//                                                                          �
// Locks the texture, making the 'ptr' member a valid pointer to a Van Gogh �
// texture object.                                                          �
//���������������������������������������������������������������������������
void EschProceduralTexture::lock()
{
    assertMyth("EschProceduralTexture::lock needs a valid work buffer",
               txt.tex != 0);

    if (flags & ESCH_TXT_LOCKED)
        return;

    ptr = &txt;

    flags |= ESCH_TXT_LOCKED;
}


//�������������������������������������������������������������������������Ŀ
// EschProceduralTexture - unlock                                           �
//                                                                          �
// Unlocks the texture, invalidating the 'ptr' member.                      �
//���������������������������������������������������������������������������
void EschProceduralTexture::unlock()
{
    if (flags & ESCH_TXT_LOCKED)
    {
        assertMyth("EschProceduralTexture::unlock expects ptr to be non-zero",
                   ptr);

        flags &= ~ESCH_TXT_LOCKED;

        ptr=0;
    }
}


//�������������������������������������������������������������������������Ŀ
// EschProceduralTexture - animate                                          �
//                                                                          �
// Generates the next frame.                                                �
//���������������������������������������������������������������������������
void EschProceduralTexture::animate()
{
    generate();
}


//�������������������������������������������������������������������������Ŀ
// EschProceduralTexture - init                                             �
//                                                                          �
// Sets up the buffers and performs other initialization for use.           �
//                                                                          �
// The base implementation just allocates the output buffer for generate()  �
// to use.                                                                  �
//���������������������������������������������������������������������������
esch_error_codes EschProceduralTexture::init(ushort w, ushort h,
                                             VngoPal *pal, int dogen)
{
//��� Delete any previous buffer
    if (txt.tex)
        delete [] txt.tex;

//��� Verify valid width and height
    switch (w)
    {
        case 16:
        case 32:
        case 64:
        case 128:
        case 256:
            break;
        default:
            return ESCH_ERR_INVALIDPARMS;
    }

    switch (h)
    {
        case 16:
        case 32:
        case 64:
        case 128:
        case 256:
            break;
        default:
            return ESCH_ERR_INVALIDPARMS;
    }

//��� Initialize output buffer
    txt.width = w;
    txt.height = h;

    txt.tex = new byte[txt.width * txt.height];
    if (!txt.tex)
        return ESCH_ERR_NOMEMORY;

//��� Do generate, if requested
    if (dogen)
        generate();

    return ESCH_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// EschProceduralTexture - generate                                         �
//                                                                          �
// Generates a new buffer.                                                  �
//���������������������������������������������������������������������������
void EschProceduralTexture::generate()
{
}

//��� End of module - estxtprc.cpp ���
