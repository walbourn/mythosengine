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
// Created by Paul Masters
//
// estoken.cpp
//
// Contains the global list of EschLimbSegment token names.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#include "escher.hpp"
#include "estoken.hpp"
#include "esfile.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

#ifdef __WATCOMC__
#pragma off(unreferenced);
#endif

esch_token esch_token_list[ESCH_KEYFRAME_TOKEN_COUNT] =
{
    "NONE",ESCH_KEYFRAME_NONE,
    "FOOTL",(ESCH_KEYFRAME_FOOT|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_LEFT)  ,
    "FOOTR",(ESCH_KEYFRAME_FOOT|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_RIGHT),
    "CALFL",(ESCH_KEYFRAME_SHIN|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_LEFT) ,
    "CALFR",(ESCH_KEYFRAME_SHIN|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_RIGHT),
    "SHINL",(ESCH_KEYFRAME_SHIN|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_LEFT) ,
    "SHINR",(ESCH_KEYFRAME_SHIN|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_RIGHT),
    "THIGHL",(ESCH_KEYFRAME_THIGH|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_LEFT) ,
    "THIGHR",(ESCH_KEYFRAME_THIGH|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_RIGHT),
    "UPLEG-L",(ESCH_KEYFRAME_THIGH|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_RIGHT),
    "UPLEG-R",(ESCH_KEYFRAME_THIGH|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_LEFT) ,
    "LOLEG-L",(ESCH_KEYFRAME_SHIN|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_LEFT) ,
    "LOLEG-R",(ESCH_KEYFRAME_SHIN|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_RIGHT),
    "FOOT-L",(ESCH_KEYFRAME_FOOT|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_LEFT)  ,
    "FOOT-R",(ESCH_KEYFRAME_FOOT|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_RIGHT),
    "ARM-L",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "ARM-R",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "ARM-L1",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "ARM-R1",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "ARMWEAP1",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_WEAP1),
    "ARMWEAP1F",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_WEAP1F),
    "ARMWEAP2",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_WEAP2),
    "ARMWEAP2F",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_WEAP2F),
    "ARMWEAP3",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_WEAP3),
    "ARMWEAP3F",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_WEAP3F),
    "U_ARML",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "U_ARMR",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "F_ARML",(ESCH_KEYFRAME_FOREARM|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "F_ARMR",(ESCH_KEYFRAME_FOREARM|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "UARML",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "UARMR",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "FARML",(ESCH_KEYFRAME_FOREARM|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "FARMR",(ESCH_KEYFRAME_FOREARM|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "UPARML",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "UPARMR",(ESCH_KEYFRAME_UPARM|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "HANDL",(ESCH_KEYFRAME_HAND|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "HANDR",(ESCH_KEYFRAME_HAND|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "BODY",ESCH_KEYFRAME_TORSOM,
    "TORSO",ESCH_KEYFRAME_TORSOM,
    "HEAD",ESCH_KEYFRAME_HEADM,
    "DOME",ESCH_KEYFRAME_DOMEM,
    "WAIST",ESCH_KEYFRAME_WAISTM,
    "HIPL",(ESCH_KEYFRAME_HIP|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_LEFT)  ,
    "HIPR",(ESCH_KEYFRAME_HIP|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_LEG|ESCH_KEYFRAME_RIGHT),
    "SHLDRL",(ESCH_KEYFRAME_SHLDR|ESCH_KEYFRAME_LEADING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_LEFT) ,
    "SHLDRR",(ESCH_KEYFRAME_SHLDR|ESCH_KEYFRAME_TRAILING|ESCH_KEYFRAME_ARM|ESCH_KEYFRAME_RIGHT),
    "MISC",ESCH_KEYFRAME_MISC,
    "ALL",ESCH_KEYFRAME_ALL
};

EschTokenManager::~EschTokenManager()
{
    if (token_list)
    {
        delete [] token_list;
        token_list = 0;
    }
}

esch_error_codes EschTokenManager::load(char *filename)
{
    esch_error_codes    err;
    XFParseIFF          iff;

    if (iff.open (filename, XF_OPEN_READ | XF_OPEN_DENYWRITE))
        return ESCH_ERR_FILEERROR;


    err = ESCH_ERR_NONE;

    for (;;)
    {
        if (iff.next() != XF_ERR_NONE)
        {
            if (!iff.depth)
                return ESCH_ERR_NOTFOUND;
            iff.leaveform();
            continue;
        }

        if (iff.chunkid == iff.makeid('F','O','R','M')
            && iff.formid == iff.makeid ('E','T','O','K'))
        {
            err = load (&iff);

            if (!err
                || err != ESCH_ERR_NOTFOUND)
                break;
        }
    }
    iff.close();
    return err;
}

esch_error_codes EschTokenManager::load(XFParseIFF *iff)
{
    assertMyth ("EschTokenManager::load needs a valid iff pointer", iff);

    if (iff->chunkid != iff->makeid('F','O','R','M')
        && iff->formid == iff->makeid ('E','T','O','K'))
        return ESCH_ERR_NOTFOUND;

    EschFileTokenHeader header;

    iff->enterform();

    if (iff->seekchunk(iff->makeid('H','D','R',' '))
        || iff->chunkSize != sizeof (header))
    {
        iff->leaveform();
        return ESCH_ERR_INVALIDDATA;
    }

    if (iff->read(&header))
    {
        iff->leaveform();
        return ESCH_ERR_FILEERROR;
    }

    if (header.ver == ESCH_TOKEN_VERSION)
    {
        // allocate token_list

        if (token_list)
        {
            delete token_list;
        }

        token_list = new esch_token[header.count];
        if (!token_list)
        {
            iff->leaveform();
            return ESCH_ERR_NOMEMORY;
        }

        token_count = header.count;

        int i=0;
        while (!iff->next())
        {
            EschFileToken   tok;

            if (iff->chunkid == iff->makeid ('K','T','O','K'))
            {
                if (iff->chunkSize != sizeof(tok))
                {
                    iff->leaveform();
                    return ESCH_ERR_INVALIDDATA;
                }

                if (iff->read(&tok))
                {
                    iff->leaveform();
                    return ESCH_ERR_FILEERROR;
                }
            }

            token_list[i].type = tok.type;
            strcpy(token_list[i].name, tok.name);
            i ++;
        }
        iff->leaveform();
    }
    else
    {
        iff->leaveform();
        return ESCH_ERR_INVALIDDATA;
    }


    return ESCH_ERR_NONE;
}

void EschTokenManager::get_token_name (char *_name, esch_limb_type _type)
{
    if (token_list)
    {
        for (int i=0; i< token_count; i++)
        {
            if (_type == token_list[i].type)
            {
                strcpy (_name, token_list[i].name);
                return;
            }
        }
    }
}

esch_limb_type EschTokenManager::get_token_type (char *_name)
{
    if (token_list)
    {
        char str[80];
        strcpy (str, _name);
        str_to_upper(str);

        for (int i=0; i< token_count; i++)
        {
            if (strstr (str, token_list[i].name))
            {
                return token_list[i].type;
            }
        }
    }
    return ESCH_KEYFRAME_NONE;
}

void EschTokenManager::str_to_upper (char *str)
{
    char *ptr = str;
    int i=0;
    while (*ptr != '\0')
    {
        *ptr = toupper(*ptr);
        ptr ++;

        // don't keep going forever...
        i ++;
        if (i > 80)
        {
            return;
        }
    }
}

//°±² End of File - estoken.cpp ²±°

