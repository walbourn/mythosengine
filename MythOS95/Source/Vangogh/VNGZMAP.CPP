//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//        Microsoft Windows 95/98/NT Version                 | / \   .  |
//                                                           |_|_|_._._.|
//                                                           |.-.-.-.-..|
//                                                          %\__________/%
//                                                           %          %
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
// Created by Tim Little
//
// vngzmap.cpp
//
//     The C++ load & save functions for the VngoZMap class.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "debug.h"
#include "portable.h"
#include "ivory.h"
#include "vangogh.hpp"
#include "xfile.hpp"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Structures
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoZMap load()                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

int VngoZMap::load (const char *fn)
{
    XFParseIFF      iffp;
    int             err=0;

    err=iffp.open(fn,XF_OPEN_READ);
    if (err)
        return (err);

    err = load(&iffp);
    if (err)
        return (err);

    err = iffp.close();
    return (err);


}

int VngoZMap::load (XFParseIFF *iffp)
{
    int             err=0;


find_zmap:

    err = iffp->seekform(iffp->makeid('Z','M','A','P'));
    if (err)
        return (err);

    err = iffp->enterform();
    if (err)
        return (err);

    VngoZMap::HDR hdr;
    err = iffp->seekchunk (iffp->makeid ('H','D','R',' '));
    if (err)
        return (err);

    if (sizeof (hdr) != iffp->chunkSize)
        return XF_ERR_CHUCKNOTFOUND;

    err = iffp->read (&hdr);
    if (err)
        return (err);

    if (hdr.ver > 1)   // Current version number is 1.
        return XF_ERR_CHUCKNOTFOUND;

    // Check to see if it is the ZMap we are looking for.
    if (strcmp(name,"Default"))
    {
        if (strcmp(name,hdr.name))
        {
            iffp->leaveform();
            goto    find_zmap;
//            return XF_ERR_CHUCKNOTFOUND;
        }
    }

    // Copy the name of the zmap loaded into the name of the ZMap.
    strncpy (name,hdr.name,16);

    // Allocate the buffer for the data.
    zmap.tex = new byte [hdr.size];
    if (!zmap.tex)
        return XF_ERR_CHUCKNOTFOUND;
    else
        flags |= VNGO_MYMEM_ZMAP;


    color = hdr.color;
    depth = hdr.depth;
    zmap.width = hdr.width;
    zmap.height = hdr.height;

    err = iffp->seekchunk (iffp->makeid ('D','a','t','a'));
    if (err)
        return (err);

    if ((dword)hdr.size != iffp->chunkSize)
        return XF_ERR_CHUCKNOTFOUND;

    err = iffp->read(zmap.tex);
    if (err)
        return (err);

    // ---- Clean up and close down.
    err = iffp->leaveform();
    if (err)
        return (err);

    // ---- Since no error occured return zero.
    return (0);
}

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// VngoZMap save()                                                          ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int VngoZMap::save (const char *fn)
{
    XFParseIFF  iffp;
    int         err=0;

//    assert(zmap.tex != NULL);

    err=iffp.create(fn,0);
    if (err)
        return(err);

    err = save(&iffp);
    if (err)
        return(err);

    err = iffp.close();
    if (err)
        return (err);

    return (err);
}

int VngoZMap::save (XFParseIFF *iffp)
{
    int             err = 0;
    VngoZMap::HDR   hdr;

    assert(zmap.tex != NULL);

    // Fill in the HDR structure to be saved.

    hdr.ver = 1;
    hdr.width = zmap.width;
    hdr.height = zmap.height;
    hdr.size = ((zmap.width + 7) >> 3) * zmap.height;
    hdr.color = color;
    hdr.depth = depth;
    strncpy (hdr.name,name,16);

    err = iffp->newform(iffp->makeid('Z','M','A','P'));
    if (err)
        return (err);

    err = iffp->write(iffp->makeid('H','D','R',' '),&hdr,sizeof(hdr));
    if (err)
        return (err);

    dword id = iffp->makeid('D','a','t','a');
//    printf("hdr.size = %d\n",hdr.size);
    err = iffp->write(id,zmap.tex,hdr.size);

    if (err)
    {
       printf ("Error writing data.  :(\n");
        return (err);
    }

    iffp->leaveform();

    return (err);   // Will be zero if no error occured.
}


//°±² End of module - vngzmap.cpp ²±°
