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
//                       *** IPAS Mesh Data Exporter ***
//
// pxp.c
//
//  PXP - 3D Studio Procedural Object Interface
//  Written for Autodesk 3D Studio 3.0 and 4.0
//
//  (C) Copyright 1994 by Autodesk, Inc.
//
//  This program is copyrighted by Autodesk, Inc. and is licensed to you under
//  the following conditions.  You may not distribute or publish the source
//  code of this program in any form.  You may incorporate this code in object
//  form in derivative works provided such derivative works are (i.) are de-
//  signed and intended to work solely with Autodesk, Inc. products, and (ii.)
//  contain Autodesk's copyright notice "(C) Copyright 1994 by Autodesk, Inc."
//
//  AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS.  AUTODESK SPE-
//  CIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF MERCHANTABILITY OR FITNESS FOR
//  A PARTICULAR USE.  AUTODESK, INC.  DOES NOT WARRANT THAT THE OPERATION OF
//  THE PROGRAM WILL BE UNINTERRUPTED OR ERROR FREE.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "pxp.h"

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

char gp_buffer[256]; /* A general purpose character buffer */

static char *state;
static DlgEntry *cdialog;
static int state_size;

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

/* Codes for dialogue box definitions */
#define CFGTITLE 0
#define CFGONOFF 1
#define CFGYESNO 2
#define CFGRADIO 3
#define CFGLFLOAT 4
#define CFGFLOAT 5
#define CFGLINT 6
#define CFGINT 7
#define CFGFILENAME 8
#define CFGSTRING 9
#define CFGSLIDER 10
#define CFGCOLOR 11
#define CFGVAR 12
#define CFGCOLBOX 13

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

/* FindDlgType converts the dialogue field descriptions into the codes used by 3d Studio */
static int FindDlgType(char *s)
{
   if (s[0]=='-') s++; /* skip past the leading dash */
   if (strncmp(s, "TITLE", 5)==0) return(CFGTITLE);
   if (strncmp(s, "ON-OFF", 5)==0) return(CFGONOFF);
   if (strncmp(s, "YES-NO", 5)==0) return(CFGYESNO);
   if (strncmp(s, "RADIO", 5)==0) return(CFGRADIO);
   if (strncmp(s, "LFLOAT", 6)==0) return(CFGLFLOAT);
   if (strncmp(s, "FLOAT", 5)==0) return(CFGFLOAT);
   if (strncmp(s, "LINT", 4)==0) return(CFGLINT);
   if (strncmp(s, "INT", 3)==0) return(CFGINT);
   if (strncmp(s, "SLIDER", 6)==0) return(CFGSLIDER);
   if (strncmp(s, "COLORBOX", 8)==0) return(CFGCOLBOX);
   if (strncmp(s, "COLOR", 5)==0) return(CFGCOLOR);
   if (strncmp(s, "FILENAME", 8)==0) return(CFGFILENAME);
   if (strncmp(s, "STRING", 6)==0) return(CFGSTRING);
   return(0);
}

/* DlgHasVar tests to see if the dialogue field has an associated variable */
static int DlgHasVar(char *s)
{
   if (s[0]=='-') s++;
   if (strncmp(s, "TITLE", 5)==0) return(0); /* Only TITLES don't have variables */
   else return(1);
}

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Data
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

static EXPbuf _far *fexpbuf; /* References 3D Studio's copy of the comunications buffer */

/*-------------------------------------------------*/

/* Local Data */
static EXPbuf localbuf; /* Contains a local copy of the com buffer.  This is done because
                           most 32 bit compilers do not make it easy to use 48 bit
                           pointers.  */

static int dialog_ix, nvar, num_dialog_items; /* Used in dialog processing */
static int version=200; /* Version starts at 2.0 by default */

/* The following three variables are initilized in the customized C initilizer found in
   the toolkit libraries based on information  passed on by 3D Studio */
extern long xpmagic; /* this is the magic number that the IPAS uses to verify its running
                        inside of 3D Studio and that its being called by the right
                        part of 3D Studio. */
extern long xpmainseg; /* The data segment of 3D Studio */
extern long xpbuffer; /* The pointer to the commincations buffer */

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

/* User defined codes used in the main switch statement */
#define U_GET_GFX_INFO1 0x0001
#define U_GET_PXP_INFO1 0x0002
#define U_GET_KXP_INFO1 0x0003
#define U_GET_GFX_INFO2 0x0004
#define U_GET_PXP_INFO2 0x0005
#define U_GET_KXP_INFO2 0x0006
#define U_DIALOG_PREP_INIT 0x100
#define U_DIALOG_PREP_LOOP 0x110
#define U_DIAVAR_PREP_LOOP 0x120
#define U_DIALOG_FINISH    0x130

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

/* This main routine is provided as a useful framework to an IPAS plugin.  */
void main(void)
{
   int type;
   ulong *pl;
   int i, k;
   OVL val;

   /* Check magic number(s) and return if they are not correct.  The correct
      number should either be PXP_MAGIC, or if its a universal PXP, PXP_MAGIC_2 */
   if(xpmagic!=PXP_MAGIC && (!(ClientIsUniversal()) || xpmagic!=PXP_MAGIC_2))
      return;

   /* Copy 3ds comm buffer data to our local buffer */
   FP_SET(fexpbuf, xpbuffer, xpmainseg); /* Construct the far pointer */
   far_to_near(&localbuf, fexpbuf, sizeof(EXPbuf)); /* copy the buffers */

   /* Double-check the buffers version of the magic number */
   if(localbuf.magic!=PXP_MAGIC && (!(ClientIsUniversal()) || localbuf.magic!=PXP_MAGIC_2))
      return;

   /* Since 3D Studio R2.0 did not report version information we have to check a
      magic value to see if there is version information.  The version info is
      always taked onto the end of the communications buffer */
   if(localbuf.ver.magic==VER_MAGIC)
      version=localbuf.ver.version;

   /* Handle user codes used by client process */
   if(localbuf.usercode>0x01FF && localbuf.usercode<0x1000)
      ClientUserCode(&localbuf);
   else /* Else its one of the internal codes used by this main routine or passed to
           it by 3D Studio */
      switch(localbuf.usercode)
      {
      case EXP_UNIVERSAL_CHECK:
         /* 3D Studio sends this token when it wants to if this
            paticular PXP is universal */
         if(ClientIsUniversal())
            localbuf.status=PXP_UNIVERSAL_MAGIC;
         else
            localbuf.status=0;
         break;

      case EXP_STARTUP:         /* Initial startup */
         state = ClientGetState(&state_size);
         if (state_size > 2048) state_size = 2048; /* Truncate oversized state */

         /* If using earlier version just call ClientStartup */
         if(version<300)
         {
            ClientStartup(&localbuf);
            break;
         }

         /* Prepare the direct call interface prior to calling ClientStartup */
         localbuf.opcode=EXP_GFX_INFO;
         localbuf.usercode=U_GET_GFX_INFO1; /* Get the direct call interface structures */
         break;

      case U_GET_GFX_INFO1:
         memcpy(GI, &localbuf.data.ginfo, sizeof(GFXInfo));     /* Hold onto this */
         GC=localbuf.data.ginfo.buf;
         localbuf.opcode=EXP_PXP_INFO; /* Request the PXP direct call info */
         localbuf.usercode=U_GET_PXP_INFO1;
         break;
      case U_GET_PXP_INFO1:
         memcpy(PXP_I, &localbuf.data.pinfo, sizeof(PXPInfo));  /* Hold onto this */
         PC=localbuf.data.pinfo.buf;
         localbuf.opcode=EXP_KXP_INFO;  /* Request the KXP direct call info */
         localbuf.usercode=U_GET_KXP_INFO1;
         break;

      case U_GET_KXP_INFO1:
         memcpy(KI, &localbuf.data.kinfo, sizeof(KXPInfo)); /* Store the info */
         KC=localbuf.data.kinfo.buf;
         localbuf.opcode=EXP_NOCODE; /* Clear the opcode for now */

         /* Now call ClientStartup */
         ClientStartup(&localbuf);
         break;

      case EXP_GET_CONFIG: /* The first thing 3DS does is pass any state information
                              to the PXP */
         /* Get the address and size of the state used by the PXP */
         state = ClientGetState(&state_size);
         if (state_size > 2048) state_size = 2048; /* Truncate state size */

         /* If the size expected doesn't match what 3DS has then do a reset */
         if(localbuf.data.cfig.size!=state_size)
         {
            ClientResetState();
         }
         else   { /* copare the version number of each state */
            long *ver3ds, *verpxp; /* Long pointers to the version */
            ver3ds = (long *)&localbuf.data.cfig.data; /* 3ds's version */
            verpxp = (long *)state; /* The local state version */
            if (*ver3ds != *verpxp) /* If the don't match, then reset the state */
               ClientResetState();
            else  /* They match, so copy 3DS's state to the PXP */
               memcpy(state, &localbuf.data.cfig.data, state_size);
         }

         /* If using an earlier version, skip over to the dialogue stuff */

         if(version<300)
            goto process_dialogue;

         /* Ask 3DS about graphics operations info */
         localbuf.opcode=EXP_GFX_INFO;
         localbuf.usercode=U_GET_GFX_INFO2;
         break;
      case U_GET_GFX_INFO2:
         /* Make a copy of the returned GFX info */
         memcpy(GI, &localbuf.data.ginfo, sizeof(GFXInfo));
         GC=localbuf.data.ginfo.buf;

         /* Next ask for PXP info */
         localbuf.opcode=EXP_PXP_INFO;
         localbuf.usercode=U_GET_PXP_INFO2;
         break;
      case U_GET_PXP_INFO2:
         /* Make a copy of the PXP direct call info */
         memcpy(PXP_I, &localbuf.data.pinfo, sizeof(PXPInfo));
         PC=localbuf.data.pinfo.buf;

         /* Next ask for the KXP info for use in cross module function calls */
         localbuf.opcode=EXP_KXP_INFO;
         localbuf.usercode=U_GET_KXP_INFO2;
         break;
      case U_GET_KXP_INFO2:
         /* Make a copy of the KXP direct call info */
         memcpy(KI, &localbuf.data.kinfo, sizeof(KXPInfo));
         KC=localbuf.data.kinfo.buf;

         localbuf.opcode=EXP_NOCODE; /* Don't ask studio to do anything yet */

         /* process the dialogue info */

         /* If process uses custom dialog handler, go do it */
         if(ClientUsesCustomDialog())
            if(ClientDoCustomDialog())
            {
               /* If the dialog finished successfully */
               localbuf.opcode=EXP_CONFIGURED;
               localbuf.usercode=EXP_TERMINATE;
               localbuf.status=1;

               /* Pass the new state struct values back to 3DS on the way out */
               localbuf.data.cfig.size=state_size;
               memcpy(localbuf.data.cfig.data, state, state_size);
               break;
            } else {
               /* The dialog was not finished successfully */
               localbuf.opcode=localbuf.usercode=EXP_TERMINATE;
               localbuf.status=0;
               break;
            }

   process_dialogue: /* This gets jumped to when the version is less than 3 */

         /* If process has no init dialog, tell 3DS it's OK */
         if(!ClientUsesInitDialog())
         {
            localbuf.opcode=EXP_CONFIGURED;
            localbuf.usercode=EXP_TERMINATE;
            localbuf.status=1;
            localbuf.data.cfig.size=state_size;
            memcpy(localbuf.data.cfig.data, state, state_size);
            break;
         }

         cdialog = ClientDialog(0);

         /* If there are no variables to load up just go do the dialogue */
         if(cdialog->s==NULL)
         {
            localbuf.opcode=EXP_DO_DIALOG;
            localbuf.usercode=0x0130;
            localbuf.status=1;
            break;
         }

         localbuf.opcode=EXP_INIT_DIALOG;
         localbuf.usercode=U_DIALOG_PREP_INIT;
         localbuf.status=1;
         break;

      case U_DIALOG_PREP_INIT:
         dialog_ix=0; /* Initialize dialogue index to 0 */

      case U_DIALOG_PREP_LOOP:

         /* Get a dialogue item */
         cdialog = ClientDialog(dialog_ix);

         /* If the variable is NULL then the loop is finished */
         if(cdialog->s==NULL)
            goto dia_done;

         /* Copy the dialogue string into the buffer */
         strcpy(localbuf.data.string, cdialog->s);

         /* Do a version 3->2 compatibility conversion */
         if (version<300)
         {
            /* 3DS2.0, change COLORBOX's to COLOR */
            int t = FindDlgType(cdialog->s);
            if (t==CFGCOLBOX)
            {
               if (cdialog->s[0]=='-')
               {
                  strcpy(localbuf.data.string, "-COLOR=");
                  strcat(localbuf.data.string, cdialog->s+10);
               }
               else {
                  strcpy(localbuf.data.string, "COLOR=");
                  strcat(localbuf.data.string, cdialog->s+9);
               }
            }
         }

         /* Add entry to dialogue */
         localbuf.opcode=EXP_ADD_DIALOG;
         localbuf.usercode=U_DIALOG_PREP_LOOP;
         localbuf.status=1;
         dialog_ix++;
         break;

         /* The loop exist here when there are no more dialogue strings left */
      dia_done:
         num_dialog_items = dialog_ix;

         /* Initialize for the next loop */
         nvar = 0;
         dialog_ix = 0;

         /* Load the variable values in the dialogue */
      case U_DIAVAR_PREP_LOOP:
         /* Skip any non variable dialogue entries like titles */
         for ( ; dialog_ix<num_dialog_items ; dialog_ix++)
         {
            cdialog = ClientDialog(dialog_ix);
            if (DlgHasVar(cdialog->s)) break;
         }

         /* If skipped past the end (because last dialogue entry was a title) then
            tell 3D Studio to startup the dialog */
         if (dialog_ix>=num_dialog_items)
         {
            localbuf.opcode=EXP_DO_DIALOG;
            localbuf.usercode=U_DIALOG_FINISH;
            localbuf.status=1;
            break;
         }

         /* Get the variable value */
         val.ul = ClientGetStateVar(cdialog->id);

         /* Prepare the variable depending on what type is expected */
         type = FindDlgType(cdialog->s);
         switch(type)
         {
         case CFGLINT: case CFGINT:
            sprintf(localbuf.data.string, "VARIABLE=\"%d\"", val.i);
            nvar++;
            break;
         case CFGONOFF: case CFGYESNO:
         case CFGRADIO: case CFGSLIDER:
            sprintf(localbuf.data.string, "VARIABLE=%d", val.i);
            nvar++;
            break;
         case CFGCOLOR:
         case CFGCOLBOX:
            sprintf(localbuf.data.string, "VARIABLE=%d, %d, %d", val.c.r, val.c.g, val.c.b);
            nvar++;
            break;
         case CFGFLOAT: case CFGLFLOAT:
               {
                  char varstr[256];
                  ClientFormatString(cdialog->id, val.f, varstr);
                  sprintf(localbuf.data.string, "VARIABLE=\"%s\"", varstr);
                  nvar++;
                  break;
               }

         case CFGSTRING: case CFGFILENAME:
            sprintf(localbuf.data.string, "VARIABLE=\"%s\"", val.s);
            nvar++;
            break;
         }

         localbuf.opcode=EXP_ADD_VAR;
         localbuf.usercode=U_DIAVAR_PREP_LOOP;
         localbuf.status=1;
         dialog_ix++;
         break;

      case U_DIALOG_FINISH:
         /* Test to see if the dialog was canceled */
         if(localbuf.status==0) /* Cancelled */
         {
            localbuf.opcode=localbuf.usercode=EXP_TERMINATE;
            localbuf.status=0;
            break;
         }

         /* Get the address of the returned variable buffer */
         pl = (ulong *)&localbuf.data;

         k = 0; /* start the indexing at the first variable */

         for (i=0; ; i++)
         {
            /* Get the next dialogue line and exit if there are no more */
            cdialog = ClientDialog(i);
            if (cdialog->s==NULL) break;

            /* If the dialogue line has a variable then copy it to the state struct */
            if (DlgHasVar(cdialog->s))
            {
               ClientSetStateVar(cdialog->id, &pl[k]);

               /* Since strings take up more than one item in the array, you have to
                  calculate the string size in words (sizeof(long int)) and add it
                  to the array index */
               k+=ClientVarSize(cdialog->id);
            }
         }

         /* done with the dialog session -- send back OK msg */

         localbuf.opcode=EXP_CONFIGURED;
         localbuf.usercode=EXP_TERMINATE;
         localbuf.status=1;

         /* Pass the new state struct values back to 3DS on the way out */
         localbuf.data.cfig.size=state_size;
         memcpy(localbuf.data.cfig.data, state, state_size);
         break;

      case EXP_PUT_CONFIG:
         {
            long *ver3ds, *verpxp; /* Long pointers to the version */

            state = ClientGetState(&state_size);
            if (state_size > 2048) state_size = 2048;

            ver3ds = (long *)&localbuf.data.cfig.data; /* 3ds's version */
            verpxp = (long *)state; /* The local state version */

            /* If the 3ds state is the same size as the local state, and the versions
               match, then copy the 3ds state to the local state */
            if((localbuf.data.cfig.size > 0) &&
               (localbuf.data.cfig.size == state_size) &&
               (*ver3ds == *verpxp))
            {
               memcpy(state, &localbuf.data.cfig.data, state_size);
            } else {
               ClientResetState();
            }
            localbuf.opcode = EXP_CONFIGURED;
            localbuf.status = 1;
            break;
         }

      case EXP_TERMINATE:
         localbuf.opcode=EXP_TERMINATE; /* Terminate! */
         localbuf.status=1;     /* OK status */
         break;

      default:
         printf("ERROR IN PXP.C: %X\n", localbuf.usercode);

         localbuf.opcode=EXP_TERMINATE; /* Terminate! */
         localbuf.status=0;     /* ERROR status */
         break;
      }

   if (localbuf.opcode == EXP_TERMINATE)
      ClientTerminate();

   /* Copy the local buffer back to the 3DS */
   near_to_far(fexpbuf, &localbuf, sizeof(EXPbuf));
   return;
}

int studio_version()
{
   return(version);
}

//°±² End of module - pxp.c ²±°

