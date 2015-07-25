//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!>''''''<!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!'''''`             ``'!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!''`          .....         `'!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!'`      .      :::::'            `'!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!'     .   '     .::::'                `!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!'      :          `````                   `!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!        .,cchcccccc,,.                       `!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!     .-"?$$$$$$$$$$$$$$c,                      `!!!!!!!!!!!!
//!!!!!!!!!!!!!!    ,ccc$$$$$$$$$$$$$$$$$$$,                     `!!!!!!!!!!!
//!!!!!!!!!!!!!    z$$$$$$$$$$$$$$$$$$$$$$$$;.                    `!!!!!!!!!!
//!!!!!!!!!!!!    <$$$$$$$$$$$$$$$$$$$$$$$$$$:.                    `!!!!!!!!!
//!!!!!!!!!!!     $$$$$$$$$$$$$$$$$$$$$$$$$$$h;:.                   !!!!!!!!!
//!!!!!!!!!!'     $$$$$$$$$$$$$$$$$$$$$$$$$$$$$h;.                   !!!!!!!!
//!!!!!!!!!'     <$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$                   !!!!!!!!
//!!!!!!!!'      `$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$F                   `!!!!!!!
//!!!!!!!!        c$$$$???$$$$$$$P""  """??????"                      !!!!!!!
//!!!!!!!         `"" .,.. "$$$$F    .,zcr                            !!!!!!!
//!!!!!!!         .  dL    .?$$$   .,cc,      .,z$h.                  !!!!!!!
//!!!!!!!!        <. $$c= <$d$$$   <$$$$=-=+"$$$$$$$                  !!!!!!!
//!!!!!!!         d$$$hcccd$$$$$   d$$$hcccd$$$$$$$F                  `!!!!!!
//!!!!!!         ,$$$$$$$$$$$$$$h d$$$$$$$$$$$$$$$$                   `!!!!!!
//!!!!!          `$$$$$$$$$$$$$$$<$$$$$$$$$$$$$$$$'                    !!!!!!
//!!!!!          `$$$$$$$$$$$$$$$$"$$$$$$$$$$$$$P>                     !!!!!!
//!!!!!           ?$$$$$$$$$$$$??$c`$$$$$$$$$$$?>'                     `!!!!!
//!!!!!           `?$$$$$$I7?""    ,$$$$$$$$$?>>'                       !!!!!
//!!!!!.           <<?$$$$$$c.    ,d$$?$$$$$F>>''                       `!!!!
//!!!!!!            <i?$P"??$$r--"?""  ,$$$$h;>''                       `!!!!
//!!!!!!             $$$hccccccccc= cc$$$$$$$>>'                         !!!!
//!!!!!              `?$$$$$$F""""  `"$$$$$>>>''                         `!!!
//!!!!!                "?$$$$$cccccc$$$$??>>>>'                           !!!
//!!!!>                  "$$$$$$$$$$$$$F>>>>''                            `!!
//!!!!!                    "$$$$$$$$???>'''                                !!
//!!!!!>                     `"""""                                        `!
//!!!!!!;                       .                                          `!
//!!!!!!!                       ?h.                                         !
//!!!!!!!!                       $$c,                                       !
//!!!!!!!!>                      ?$$$h.              .,c                    !
//!!!!!!!!!                       $$$$$$$$$hc,.,,cc$$$$$                    !
//!!!!!!!!!                  .,zcc$$$$$$$$$$$$$$$$$$$$$$                    !
//!!!!!!!!!               .z$$$$$$$$$$$$$$$$$$$$$$$$$$$$                    !
//!!!!!!!!!             ,d$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$          .         !
//!!!!!!!!!           ,d$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$         !!         !
// 
//                             D A   V I N C I
//                         3D Graphics Scene Manager
//
//                      Microsoft Windows 95/NT Version
//
//               Copyright (c) 1998 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
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
// davinci.hpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

#ifndef __DAVINCI_HPP
#define __DAVINCI_HPP   1

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
//                                Classes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Prototypes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//°±² End of header - davinci.hpp ²±°

