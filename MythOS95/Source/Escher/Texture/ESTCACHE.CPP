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
//ùùùùùùùùùùùùùùùùù Microsoft Windows 95/98/NT Version ùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùCopyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbournùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                        http://www.mythos-engine.org/
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Tim Little & Chuck Walbourn
//
// estcache.cpp
//
// Contains the code for the texture cache management routines that are
// static members of EschTexture.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "escher.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define INIT_TCACHE_SIZE 64

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTexture - cache_new                                                  ³
//                                                                          ³
// Creates a new instance of texture in the cache or 0 if not found.        ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
EschTexture *EschTexture::cache_new(const char *n)
{
    if (!EschSysInstance || !EschSysInstance->tcache || !n)
        return 0;

//ÄÄÄ Find texture name in cache
    for(ulong i=0; i < EschSysInstance->tcache_hi; i++)
    {
        if (EschSysInstance->tcache[i].handle
            && !strncmp(EschSysInstance->tcache[i].name,n,ESCH_MAX_NAME))
        {
            EschTexture *t;

            //ÄÄÄ Create new instance based on type
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

            //ÄÄÄ Increment count
            EschSysInstance->tcache[i].count++;

            //ÄÄÄ Return instance
            return t;
        }
    }

    return 0;
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTexture - cache_release                                              ³
//                                                                          ³
// This handles the count decrement for a texture instance created by the   ³
// cache_new function and returns 1.  Returns 0 if not a shared texture.    ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int EschTexture::cache_release(IvoryHandle h)
{
    if (!EschSysInstance || !EschSysInstance->tcache || !h)
        return 0;

//ÄÄÄ Find texture handle in cache
    EschTextureCache *tc = EschSysInstance->tcache;
    for(ulong i=0; i < EschSysInstance->tcache_hi; i++, tc++)
    {
        if (tc->handle == h)
        {
            assertMyth("EschTexture::cache_release count should be non-zero",
                       tc->count > 0);

            //ÄÄÄ Decrement count
            tc->count--;

            if (!tc->count)
            {
                //ÄÄÄ Last reference, so free
                VngoTexture *p = (VngoTexture*)ivory_hlock(tc->handle);
                if (p)
                {
                    for(ushort i=0; i < tc->max; i++, p++)
                    {
                        p->VngoTexture::~VngoTexture();
                    }
                    ivory_hunlock(tc->handle);
                }
                ivory_hfree(&tc->handle);

                if (tc->name)
                {
                    delete [] tc->name;
                    tc->name = 0;
                }
            }
            return 1;
        }
    }

    return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// EschTexture - cache_register                                             ³
//                                                                          ³
// Adds a new texture to the shared texture cache.                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
esch_error_codes EschTexture::cache_register(const char *n, IvoryHandle hnd,
                                             word t, dword f,
                                             ushort w, ushort h, ushort m,
                                             char **name, int inuse)
{
    assertMyth("EschTexture::cache_register needs System",
               EschSysInstance != 0);

//ÄÄÄ Initialize texture cache if needed
    if (!EschSysInstance->tcache)
    {
        EschSysInstance->tcache = new EschTextureCache[INIT_TCACHE_SIZE];
        if (!EschSysInstance->tcache)
            return ESCH_ERR_NOMEMORY;

        EschSysInstance->tcache_hi = 0;
        EschSysInstance->tcache_max = INIT_TCACHE_SIZE;
    }

//ÄÄÄ Find open slot
    for(ulong i=0; i < EschSysInstance->tcache_hi; i++)
    {
        if (!EschSysInstance->tcache[i].handle)
            break;
    }

    if (i >= EschSysInstance->tcache_hi)
    {
        if (EschSysInstance->tcache_hi >= EschSysInstance->tcache_max)
        {
            //ÄÄÄ Must expand
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

//ÄÄÄ Fill slot
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
    tc->name = new char[ESCH_MAX_NAME];
    if (!tc->name)
        return ESCH_ERR_NOMEMORY;

    strncpy(tc->name,n,ESCH_MAX_NAME);

    if (*name)
        *name = tc->name;

    return ESCH_ERR_NONE;
}

//°±² End of module - estcache.cpp ²±°

