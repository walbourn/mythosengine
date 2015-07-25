//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//
//                                Assert Header
//
//              Copyright (c) 1994-1996 by Charybdis Enterprises, Inc.
//                            All Rights Reserved.
//
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
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
//ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
//
// Windows assert replacement.
//
//อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ


#ifndef __CHARYBDIS_ASSERT
#define __CHARYBDIS_ASSERT 1

//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ
//
//                                Equates
//
//ฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐฐ

#undef	assert
#undef	assertMyth

#ifdef NDEBUG
#define assert(exp)	((void)0)
#define assertMyth(msg,exp)	((void)0)
#else

#ifdef __cplusplus
extern "C"
#endif
void _charybdis_assert(char *txt, char *exp, char *f, unsigned ln);

#define assert(exp) (void)( (exp) || (_charybdis_assert(0, #exp, __FILE__, __LINE__), 0)  )
#define assertMyth(msg,exp) (void)( (exp) || (_charybdis_assert(msg, #exp, __FILE__, __LINE__), 0)  )

#endif

#endif

//ฐฑฒ End of header - assert.h ฒฑฐ
