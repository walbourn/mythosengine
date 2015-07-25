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
// estcache.cpp
//
// Contains the code for the texture cache management routines that are
// static members of EschTexture.
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
//                                Equates
//
//���������������������������������������������������������������������������

#define INIT_TCACHE_SIZE 64

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschTexture - cache_new                                                  �
//                                                                          �
// Creates a new instance of texture in the cache or 0 if not found.        �
//���������������������������������������������������������������������������
EschTexture *EschTexture::cache_new(const char *n)
{
    if (!EschSysInstance || !EschSysInstance->tcache || !n)
        return 0;

//��� Find texture name in cache
    for(ulong i=0; i < EschSysInstance->tcache_hi; i++)
    {
        if (EschSysInstance->tcache[i].handle
            && !strncmp(EschSysInstance->tcache[i].name,n,ESCH_MAX_NAME))
        {
            EschTexture *t;

            //��� Create new instance based on type
            switch(EschSysInstance->tcache[i].typ)
            {
                case ESCH_TXTT_STATIC:
                    t = new EschStaticTexture;
                    if (!t)
                        return 0;

                    ((EschStaticTexture*)t)->handle
                                        = EschSysInstance->tcache[i].handle;
                    break;

                case ESCH_TXTT_MFRAME:
                    t = new EschMultiFrameTexture;
                    if (!t)
                        return 0;

                    ((EschMultiFrameTexture*)t)->max
                                        = EschSysInstance->tcache[i].max;
                    ((EschMultiFrameTexture*)t)->set_size
                                            (EschSysInstance->tcache[i].width,
                                             EschSysInstance->tcache[i].height);
                    ((EschMultiFrameTexture*)t)->handle
                                        = EschSysInstance->tcache[i].handle;
                    break;
                default:
                    return 0;
            }

            t->name = EschSysInstance->tcache[i].name;
            t->set_flags(t->flags
                         | ESCH_TXT_SHARED 
                         | EschSysInstance->tcache[i].flags);

            //��� Increment count
            EschSysInstance->tcache[i].count++;

            //��� Return instance
            return t;
        }
    }

    return 0;
}



//�������������������������������������������������������������������������Ŀ
// EschTexture - cache_release                                              �
//                                                                          �
// This handles the count decrement for a texture instance created by the   �
// cache_new function and returns 1.  Returns 0 if not a shared texture.    �
//���������������������������������������������������������������������������
int EschTexture::cache_release(IvoryHandle h)
{
    if (!EschSysInstance || !EschSysInstance->tcache || !h)
        return 0;

//��� Find texture handle in cache
    for(ulong i=0; i < EschSysInstance->tcache_hi; i++)
    {
        if (EschSysInstance->tcache[i].handle == h)
        {
            assertMyth("EschTexture::cache_release count should be non-zero",
                       EschSysInstance->tcache[i].count > 0);

            //��� Decrement count
            EschSysInstance->tcache[i].count--;

            if (!EschSysInstance->tcache[i].count)
            {
                //��� Last reference, so free
                ivory_hfree(&EschSysInstance->tcache[i].handle);
            }
            return 1;
        }
    }

    return 0;
}


//�������������������������������������������������������������������������Ŀ
// EschTexture - cache_register                                             �
//                                                                          �
// Adds a new texture to the shared texture cache.                          �
//���������������������������������������������������������������������������
esch_error_codes EschTexture::cache_register(const char *n, IvoryHandle hnd, 
                                             word t, dword f,
                                             ushort w, ushort h, ushort m,
                                             char **name, int inuse)
{
    assertMyth("EschTexture::cache_register needs System",
               EschSysInstance != 0);

//��� Initialize texture cache if needed
    if (!EschSysInstance->tcache)
    {
        EschSysInstance->tcache = new EschTextureCache[INIT_TCACHE_SIZE];
        if (!EschSysInstance->tcache)
            return ESCH_ERR_NOMEMORY;

        EschSysInstance->tcache_hi = 0;
        EschSysInstance->tcache_max = INIT_TCACHE_SIZE;
    }

//��� Find open slot
    for(ulong i=0; i < EschSysInstance->tcache_hi; i++)
    {
        if (!EschSysInstance->tcache[i].handle)
            break;
    }

    if (i >= EschSysInstance->tcache_hi)
    {
        if (EschSysInstance->tcache_hi >= EschSysInstance->tcache_max)
        {
            //��� Must expand
            EschTextureCache *t
                    = new EschTextureCache[EschSysInstance->tcache_max << 1];
            if (!t)
                return ESCH_ERR_NOMEMORY;
            
            memcpy(t, EschSysInstance->tcache, EschSysInstance->tcache_max
                                               * sizeof(EschTextureCache));
            delete [] EschSysInstance->tcache;
            EschSysInstance->tcache=t;
            EschSysInstance->tcache_max <<= 1;
        }

        EschSysInstance->tcache_hi++;
    }

//��� Fill slot
    assert(i < EschSysInstance->tcache_hi && i < EschSysInstance->tcache_max);

    EschTextureCache *tc = &EschSysInstance->tcache[i];

    tc->handle = hnd;
    tc->count = (inuse) ? 1 : 0;
    tc->flags = f & ~(ESCH_TXT_LOCKED
                      | ESCH_TXT_OWNSDATA
                      | ESCH_TXT_SHARED);
    tc->typ = t;
    tc->max = m;
    tc->width = w;
    tc->height = h;

    strncpy(tc->name,n,ESCH_MAX_NAME);

    if (*name)
        *name = tc->name;

    return ESCH_ERR_NONE;
}

//��� End of module - estcache.cpp ���
