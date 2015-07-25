//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//            Copyright (c) 1994-1996 by Charybdis Enterprises, Inc.
//                              All Rights Reserved.
//                        Microsoft Windows '95 Version
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
// Created by Chuck Walbourn
//
// xfini.cpp
//
//     XFParseINI
//
//     The internal implementation of the .INI reader is fairly simple -
//
//     Basically, it maintains a buffer with a copy of the current
//     .INI file for fast reading and as the basis of searches for
//     the write operations.  The 'current section' is maintained by
//     keeping a string with the last set name for searching purposes.
//     If the current name is empty, then the file is assumed to be a
//     'single-section' .INI.
//
//     The end of file is indicated by the hitting the end of the file
//     or the beginning of another section.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <string.h>

#include "xfile.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Contructor for the .INI object.                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
XFParseINI::XFParseINI()
{
    buffsize=0;
    buff=0;
    *sectname=0;
    xf=&xfile;
};

XFParseINI::XFParseINI(XFile *f)
{
    buffsize=0;
    buff=0;
    *sectname=0;
    xf=f;
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// Destructor for the .INI object.                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
XFParseINI::~XFParseINI()
{
    end();
    xf->close();
};

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseINI - begin                                                       ³
//                                                                          ³
// Sets up for processing of the .INI file.                                 ³
//                                                                          ³
// Returns 0 if ok, error number otherwise.                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseINI::begin(void)
{
    if (!(xf->status() & (XF_OPEN_READ|XF_OPEN_WRITE)))
    {
        errorn=XF_ERR_NEEDREADORWRITE;
        return errorn;
    }

//ÄÄÄ Load file image ÄÄÄ
    return load();
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseINI - end                                                         ³
//                                                                          ³
// Close the .INI file.                                                     ³
//                                                                          ³
// Returns 0 if ok, error number otherwise.                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseINI::end(void)
{
    xf_error_codes err;

//ÄÄÄ Free memory buffer ÄÄÄ
    if (buff)
    {
        delete [] buff;
        buffsize=0;
        buff=0;
        *sectname=0;
    }

//ÄÄÄ Flush the filehandle ÄÄÄ
    err=xf->flush();
    if (err)
        errorn=err;

    return err;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseINI - section                                                     ³
//                                                                          ³
// Sets the active section name.  If NULL, then the file has no sections,   ³
// with all variables visible.                                              ³
//                                                                          ³
// Returns 0 if ok, error number otherwise.                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseINI::section(const char *name)
{
    if (!name || !*name)
    {
        *sectname = 0;
        return XF_ERR_NONE;
    }

//ÄÄÄ Test length of section name ÄÄÄ
    if ((strlen(name)+3) > XF_MAX_ININAME)
    {
        errorn=XF_ERR_NAME_TOO_LONG;
        return errorn;
    }

//ÄÄÄ Save section name ÄÄÄ
    sectname[0] = '[';
    strcpy(&sectname[1],name);
    sectname[strlen(name)+1] = ']';
    sectname[strlen(name)+2] = 0;

//ÄÄÄ If read only, test for section ÄÄÄ
    if ((xf->status() & (XF_STATUS_READ|XF_STATUS_WRITE)) == XF_STATUS_READ)
    {
        if (!strstr(buff,sectname))
        {
            errorn=XF_ERR_SECTION_NOT_FOUND;
            return errorn;
        }
    }

    return XF_ERR_NONE;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                          °°° Protected °°°                               ³
// XFParseINI - load                                                        ³
//                                                                          ³
// Reloads the current file image into a memory buffer.  Will resize memory ³
// buffer if needed.                                                        ³
//                                                                          ³
// Returns an error code if an error ocurrs.                                ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseINI::load(void)
{
    ulong size;

//ÄÄÄ Get size ÄÄÄ
    size = xf->getsize();
    if (size == -1)
    {
        errorn=xf->error();
        return errorn;
    }

//ÄÄÄ Allocate buffer if too small ÄÄÄ
    if (size > buffsize)
    {
        if (buff)
            delete [] buff;
        buffsize = size;
        buff = new char[buffsize+1];
        if (!buff)
        {
            errorn=XF_ERR_NOMEMORY;
            return errorn;
        }
    }
       
//ÄÄÄ If size is non-zero, load image ÄÄÄ
    xf->seek_set(0);

    if (size && (xf->read(buff,size) != size))
    {
        errorn=xf->error();
        return errorn;

    }

//ÄÄÄ Put a 0 at end for string searches ÄÄÄ
    if (buff && size)
        buff[size] = 0;

    return XF_ERR_NONE;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                          °°° Protected °°°                               ³
// XFParseINI - start                                                       ³
//                                                                          ³
// Gets start location for current section name.  If *sections is non-zero, ³
// then the '[name]' is skipped, so the pointer points just past the name   ³
// of the section.                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
char *XFParseINI::start(void)
{
    char *ptr;

    if (!buff)
    {
        errorn=XF_ERR_SECTION_NOT_FOUND;
        return 0;
    }

    ptr = buff;
    if (*sectname)
    {
        ptr = strstr(ptr,sectname);
        if (!ptr)
        {
            errorn=XF_ERR_SECTION_NOT_FOUND;
            return 0;
        }
        for(; *ptr && *ptr != ']'; ptr++);
    }

    return ptr;
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//                          °°° Protected °°°                               ³
// XFParseINI - find                                                        ³
//                                                                          ³
// Find variable in buffer.  Buffer is assumed to have a 0 at end to        ³
// indicate end of file.  Scanning starts from 'ptr' and ends at end-of-    ³
// file or the first '[ character, indicating beginning of new section      ³
//                                                                          ³
// Returns pointer to buffer line with variable or 0 if not found.          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
char *XFParseINI::find(char *ptr, const char *item)
{
    int     itemlen;

//ÄÄÄ Check for NULL start position ÄÄÄ
    if (!ptr)
        return 0;

//ÄÄÄ Scan buffer ÄÄÄ
    itemlen = strlen(item);
    while (ptr && *ptr)
    {
        switch (*ptr)
        {
                                           // Whitespace
            case ' ':
            case '\t':
            case '\r':
            case '\n':
                ptr++;
                break;
                                           // Comments
            case ';':
                for(; *ptr && *ptr != '\n'; ptr++);
                if (*ptr)
                    ptr++;
                break;
                                           // Section
            case '[':
                ptr=NULL;
                break;

            default:                        // Text line
                if (!strncmp(ptr,item,itemlen))
                    return ptr;
                for(; *ptr && *ptr != '\n'; ptr++);
                break;
        }
    }

    return 0;
}

//°±² End of module - xfini.cpp ²±°

