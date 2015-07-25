//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//            Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
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
// xfiwrite.cpp
//
// XFParseINI -
//
// Writing includes a number of cases.  The memory-copy of the buffer is
// scanned for the item to see if it needs to be replaced.  If not found,
// then the section is created and the variable is written out.
// The first part of the buffer is written, then the new lines, then
// the second part to replace a buffer.  Comments and whitespace
// are preserved expect on the actual line replaced.  The buffer is
// then reloaded.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <stdio.h>
#include <string.h>

#include <assert.h>

#include "xfile.hpp"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseINI - write                                                       ³
//                                                                          ³
// Writes a variable (overwriting if it already exists in this section).    ³
//                                                                          ³
// Returns 0 if ok, error number otherwise.                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseINI::write(const char *item, const char *value)
{
    int  addcrlf=0;
    xf_error_codes error;
    char *ptr;
    char *prologue;
    char crlf[2] = { '\r', '\n' };
    char equal = '=';

    prologue=0;

//ÄÄÄ Setup start of search  ÄÄÄ
    ptr = start();
    if (!ptr && *sectname)
    {

//ÄÄÄ Section doesn't exist, so this is definetly new:
//                                       append and write section name ÄÄÄ 
        xf->seek_end(0);
        if (xf->write(crlf,2) != 2)
        {
            errorn=xf->error();
            return errorn;
        }
        if (xf->write(sectname,strlen(sectname)) != strlen(sectname))
        {
            errorn=xf->error();
            return errorn;
        }
        if (xf->write(crlf,2) != 2)
        {
            errorn=xf->error();
            return errorn;
        }

    }
    else
    {
//ÄÄÄ Empty current file ÄÄÄ 
        xf->setsize(0);

//ÄÄÄ Scan section for variable already defined  ÄÄÄ
        if ((ptr=find(ptr,item))!=0)
        {

//ÄÄÄ Variable already defined ÄÄÄ
            for(prologue=ptr; *prologue && *prologue != '\n'; prologue++);
            if (*prologue)
                prologue++;

            if (ptr != buff && *ptr)
                ptr--;
        }
        else
        {

//ÄÄÄ Variable not defined in section ÄÄÄ
            ptr = start();
            if (ptr && *sectname)
            {
                addcrlf=1;
                for(prologue=ptr; *prologue && *prologue != '\n'; prologue++);
                if (*prologue)
                    prologue++;
            }
            else
                prologue=ptr;
        }

//ÄÄÄ Write any area previous to variable's location ÄÄÄ
        if (ptr && buff && (ptr != buff))
        {
            if (xf->write(buff,ptr-buff+1) != (ulong)(ptr-buff+1))
            {
                errorn=xf->error();
                return errorn;
            }
        }
    }

//ÄÄÄ Write out ÄÄÄ
    if (addcrlf)
    {
        if (xf->write(crlf,2) != 2)
        {
            errorn=xf->error();
            return errorn;
        }
    }

    if (xf->write(item,strlen(item)) != strlen(item))
    {
        errorn=xf->error();
        return errorn;
    }
    if (xf->write(&equal,1) != 1)
    {
        errorn=xf->error();
        return errorn;
    }
    if (xf->write(value,strlen(value)) != strlen(value))
    {
        errorn=xf->error();
        return errorn;
    }
    if (xf->write(crlf,2) != 2)
    {
        errorn=xf->error();
        return errorn;
    }
    if (prologue && *prologue)
    {
        if (xf->write(prologue,strlen(prologue)) != strlen(prologue))
        {
            errorn=xf->error();
            return errorn;
        }
    }

//ÄÄÄ Reload ÄÄÄ
    error=load();
    if (error)
        return error;

    return XF_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseINI - write                                                       ³
//                                                                          ³
// Writes a block of variables                                              ³
//                                                                          ³
// Returns 0 if ok, error number otherwise.                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseINI::write(const char **item, const char **value)
{
    int i;

    for(i=0; item[i] && *item[i]; i++)
    {
        if (write(item[i],value[i]))
            return errorn;
    }

    return XF_ERR_NONE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// XFParseINI - write                                                       ³
//                                                                          ³
// Writes a variable with an integer value.                                 ³
//                                                                          ³
// Returns 0 if ok, error number otherwise.                                 ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
xf_error_codes XFParseINI::write(const char *item, int value)
{
    char            str[XF_MAX_INIVALUE];

    sprintf(str,"%d",value);

    return write(item,str);
}

//°±² End of module - xfiwrite.cpp ²±°

