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
//שששששששששששCopyrightש(c)ש1994-1997שbyשCharybdisשEnterprises,שInc.שששששששששש
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
// Created by Paul Masters
//
// estoken.hpp
//
// This is used to coordinate the export and load-time patch up process for
// linking the articulation/motion data to objects.
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

#ifndef __ESTOKEN_HPP
#define __ESTOKEN_HPP   1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include "esdefs.h"
#include "xfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define ESCH_KEYFRAME_TOKEN_COUNT 48

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

struct esch_token
{
    char name[ESCH_MAX_NAME];
    esch_limb_type type;
};

class EschTokenManager
{
protected:
    int token_count;
    esch_token *token_list;

public:
    EschTokenManager(){token_count = 0;token_list=0;};
    ~EschTokenManager();
    esch_error_codes load (char *filename);
    esch_error_codes load (XFParseIFF *iff);

    // find type and put matching name in _name
    void get_token_name (char *_name, esch_limb_type _type);

    // find _name and return matching type
    esch_limb_type get_token_type(char *_name);

    void str_to_upper (char *str);
};

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                  Data
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

extern esch_token esch_token_list[ESCH_KEYFRAME_TOKEN_COUNT];

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - estoken.h ²±°

