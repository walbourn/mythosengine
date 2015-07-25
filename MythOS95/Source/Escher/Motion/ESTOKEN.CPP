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
// estoken.cpp
//
// Contains the global list of EschLimbSegment token names.
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

#include "escher.hpp"
#include "estoken.hpp"

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

//°±² End of File - estoken.cpp ²±°

