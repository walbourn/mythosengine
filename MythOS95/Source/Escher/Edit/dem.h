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
//                        *** Escher Terrain Editor ***
//
// Chuck Walbourn
//
// dem.h
//
// Contains constants and structures for the parsing of VistaPro uncompressed
// DEM files.
//
//ֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽֽ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define HAM_PAL00 0 /* first 16 used as the HAM palette */
#define HAM_PAL01 1 /* may be overridden by user */
#define HAM_PAL02 2
#define HAM_PAL03 3
#define HAM_PAL04 4
#define HAM_PAL05 5
#define HAM_PAL06 6
#define HAM_PAL07 7
#define HAM_PAL08 8
#define HAM_PAL09 9
#define HAM_PAL10 10
#define HAM_PAL11 11
#define HAM_PAL12 12
#define HAM_PAL13 13
#define HAM_PAL14 14
#define HAM_PAL15 15

/* 16-22 not used, reserved for future enhancement */

#define EXPOSURE 23
#define CONTRAST 24
#define SKY_HAZE 25
#define HAZE_COLOR 26

/* 27-31 not used, reserved for future enhancement */

#define WATER_BLUE 32
#define SKY_BLUE 33
#define TREE1 34
#define TREE2 35
#define TREE3 36
#define TREE4 37
#define DIRT1 38
#define DIRT2 39
#define DIRT3 40
#define DIRT4 41
#define SNOW1 42
#define SNOW2 43
#define SNOW3 44
#define SNOW4 45
#define CLIFF_ROCK1 46
#define CLIFF_ROCK2 47
#define CLIFF_ROCK3 48
#define CLIFF_ROCK4 49
#define SAND_YELLOW 50
#define RIVER_WATER1 51
#define RIVER_WATER2 52
#define RIVER_WATER3 53
#define RIVER_WATER4 54
#define RIVER_WATER5 55

/* 56-255 not used, reserved for future enhancement */

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

struct DEM_COLORMAP
{
    unsigned char zero;                 /* unused, set to 0 */
    unsigned char red;                  /* 8 bit red color value */
    unsigned char green;                /* 8 bit green color value */
    unsigned char blue;                 /* 8 bit blue color value */
};

struct DEM_HEADER
{
    char id[32];                        /* null terminated string */
    char name[32];                      /* null terminated string */
    char comment[64];                   /* null terminated string */
    long compression;                   /* 0=not, 1=compressed */
    long header_type;                   /* 0=plain, 1=extended */
    long ex_width;                      /* width for extended (258 otherwise)*/
    long ex_depth;                      /* depth for extended (258 otherwise)*/
    unsigned char reserved[880];        /* pad to 1024 */
    struct DEM_COLORMAP CMAP[256];      /* 256 entry palette */
};

// After the header, the file contains width ny depth shorts, a row at a 
// time, starting with the lower-left.  The data should range from 0 to
// 16000 to keep the VistaPro rendering engine from crashing.

//°±² End of module - dem.h ²±°
