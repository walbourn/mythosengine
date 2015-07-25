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
//ùùùùùùùùùùCopyrightù(c)ù1994,ù1995ùbyùCharybdisùEnterprises,ùInc.ùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùAllùRightsùReserved.ùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
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
// Created by Tim Little & Chuck Walbourn
//
//                       *** IPAS Mesh Data Exporter ***
//
// support.c
//
// Contains some support code needed by the exporter (code adopted from
// esmatrix.asm in Escher library)
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <string.h>

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

// 3D Studio uses 4 consecutive 3-element rows in it's float [4][3] matrix
// structure.

#define MTX_A       0
#define MTX_B       1
#define MTX_C       2
#define MTX_D       3
#define MTX_E       4
#define MTX_F       5
#define MTX_G       6
#define MTX_H       7
#define MTX_I       8
#define MTX_J       9
#define MTX_K       10
#define MTX_L       11

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// det_mtx                                                                  ³
//                                                                          ³
// Computes the determinment of a matrix.                                   ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
float det_mtx(float *m)
{
    double  r;

//     [A B C 0]      
// det [D E F 0] =  A |E F 0|  - B |D F 0|  + C |D E 0|   - 0 |D E F|
//     [G H I 0]      |H I 0|      |G I 0|      |G H 0|       |G H I|
//     [J K L 1]      |K L 1|      |J L 1|      |J K 1|       |H K L|
// 
// 
//               =  A(                ) 
//                   ( E|I 0| - F|H 0|)
//                   (  |L 1|    |K 1|)
// 
//                 -B(                )
//                   ( D|I 0| - F|G 0|)
//                   (  |L 1|    |J 1|)
// 
//                 +C(                )
//                   ( D|H 0| - E|G 0|)
//                   (  |K 1|    |J 1|)
// 
//               =  A(EI - FH) - B(DI - FG) + C(DH - EG)

// A |E F 0|
//   |H I 0| = A (EI - FH)
//   |K L 1|

    r = m[MTX_A] * ( m[MTX_E]*m[MTX_I] - m[MTX_F]*m[MTX_H] );

// - B |D F 0| 
//     |G I 0| = - B (DI - FG) 
//     |J L 1|

    r = r - m[MTX_B] * ( m[MTX_D]*m[MTX_I] - m[MTX_F]*m[MTX_G] );

// C |D E 0|
//   |G H 0| = C (DH - EG)
//   |J K 1|

    return (r + m[MTX_C] * ( m[MTX_D]*m[MTX_H] - m[MTX_E]*m[MTX_G] ));
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// inverse_mtx                                                              ³
//                                                                          ³
// Computes the inverse of a 4x3 matrix, returning it in 'inv' and a value  ³
// of 1.  If no inverse exists, 0 is returned.                              ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
int inverse_mtx(float *m, float *inv)
{
    double  det;
    double  iv1, iv2, iv3;
    float   tm[12];

    det = det_mtx(m);

    if (det == 0.0)
        return 0;

    memcpy(tm,m,sizeof(float)*12);

// [A B C 0]      det is A(EI - FH) - B(DI - FG) + C(DH - EG)
// [D E F 0]      
// [G H I 0]
// [J K L 1]      The inverse is :-
//
//
//                [ |E F 0|   |B C 0|   |B C 0|   |B C 0| ]
//                [ |H I 0|  -|H I 0|   |E F 0|  -|E F 0| ]
//                [ |K L 1|   |K L 1|   |K L 1|   |H I 0| ]
//                [                                       ]
//                [ |D F 0|   |A C 0|   |A C 0|   |A C 0| ]
//          1     [-|G I 0|   |G I 0|  -|D F 0|   |D F 0| ]
//        ----- * [ |J L 1|   |J L 1|   |J L 1|   |G I 0| ]
//         det    [                                       ]
//                [ |D E 0|   |A B 0|   |A B 0|   |A B 0| ]
//                [ |G H 0|  -|G H 0|   |D E 0|  -|D E 0| ]
//                [ |J K 1|   |J K 1|   |J K 1|   |G H 0| ]
//                [                                       ]
//                [ |D E F|   |A B C|   |A B C|   |A B C| ]
//                [-|G H I|   |G H I|  -|D E F|   |D E F| ]
//                [ |J K L|   |J K L|   |J K L|   |G H I| ]
//

// <A>
//     1      |E F 0|
//   ----- *  |H I 0| = ( EI - FH ) / det
//    det     |K L 1|    

    inv[MTX_A] = (tm[MTX_E]*tm[MTX_I] - tm[MTX_F]*tm[MTX_H]) / det;

// <D>
//     1      |D F 0|
//   ----- * -|G I 0| = ( FG - DI ) / det
//    det     |J L 1| 

    inv[MTX_D] = (tm[MTX_F]*tm[MTX_G] - tm[MTX_D]*tm[MTX_I]) / det;

// <G>
//     1      |D E 0|
//   ----- *  |G H 0| = ( DH - EG ) / det
//    det     |J K 1|    

    inv[MTX_G] = (tm[MTX_D]*tm[MTX_H] - tm[MTX_E]*tm[MTX_G]) / det;

// <J>
//     1      |D E F|       <IV1>      <IV2>      <IV3>
//   ----- * -|G H I| = ( E(GL-IJ) - D(HL-KI) - F(GK-JH) ) / det
//    det     |J K L|

    iv1 = tm[MTX_G]*tm[MTX_L] - tm[MTX_I]*tm[MTX_J];
    iv2 = tm[MTX_H]*tm[MTX_L] - tm[MTX_K]*tm[MTX_I];
    iv3 = tm[MTX_G]*tm[MTX_K] - tm[MTX_J]*tm[MTX_H];

    inv[MTX_J] = (tm[MTX_E]*iv1 - tm[MTX_D]*iv2 - tm[MTX_F]*iv3) / det;

// <B>
//     1      |B C 0|
//   ----- * -|H I 0| = ( CH - BI ) / det
//    det     |K L 1|   

    inv[MTX_B] = (tm[MTX_C]*tm[MTX_H] - tm[MTX_B]*tm[MTX_I]) / det;

// <E>
//     1      |A C 0|
//   ----- *  |G I 0| = ( AI - CG ) / det
//    det     |J L 1|

    inv[MTX_E] = (tm[MTX_A]*tm[MTX_I] - tm[MTX_C]*tm[MTX_G]) / det;

// <H>          
//     1      |A B 0|
//   ----- * -|G H 0| = ( BG - AH ) / det
//    det     |J K 1|

    inv[MTX_H] = (tm[MTX_B]*tm[MTX_G] - tm[MTX_A]*tm[MTX_H]) / det;

// <K>          
//     1      |A B C|       <IV2>      <IV1>      <IV3>
//   ----- *  |G H I| = ( A(HL-KI) - B(GL-JI) + C(GK-JH) ) / det
//    det     |J K L|

    inv[MTX_K] = (tm[MTX_A]*iv2 - tm[MTX_B]*iv1 + tm[MTX_C]*iv3) / det;

// <C>
//     1      |B C 0|
//   ----- *  |E F 0| = ( BF - CE ) / det
//    det     |K L 1|

    inv[MTX_C] = (tm[MTX_B]*tm[MTX_F] - tm[MTX_C]*tm[MTX_E]) / det;

// <F>
//     1      |A C 0|
//   ----- * -|D F 0| = ( CD - AF ) / det
//    det     |J L 1|

    inv[MTX_F] = (tm[MTX_C]*tm[MTX_D] - tm[MTX_A]*tm[MTX_F]) / det;

// <I>
//     1      |A B 0|
//   ----- *  |D E 0| = ( AE - BD ) / det
//    det     |J K 1|

    inv[MTX_I] = (tm[MTX_A]*tm[MTX_E] - tm[MTX_B]*tm[MTX_D]) / det;

// <L>
//     1      |A B C|
//   ----- * -|D E F| = ( B(DL-JF) - A(EL-KF) - C(DK-JE) ) / det
//    det     |J K L|

    inv[MTX_L] = ( tm[MTX_B]*( tm[MTX_D]*tm[MTX_L] - tm[MTX_J]*tm[MTX_F] )
                   - tm[MTX_A]*( tm[MTX_E]*tm[MTX_L] - tm[MTX_K]*tm[MTX_F] )
                   - tm[MTX_C]*( tm[MTX_D]*tm[MTX_K] - tm[MTX_J]*tm[MTX_E] )
                 ) / det;

    return 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
// concat_mtx                                                               ³
//                                                                          ³
// Concats two matricies by multiplying them.                               ³
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
void concat_mtx(float *ina, float *b, float *res)
{
    float   a[12];

    memcpy(a,ina,sizeof(float)*12);

// [A B C 0]      [a b c 0]    [Aa+Bd+Cg   Ab+Be+Ch   Ac+Bf+Ci   0]
// [D E F 0]      [d e f 0]    [Da+Ed+Fg   Db+Ee+Fh   Dc+Ef+Fi   0]
// [G H I 0]  *   [g h i 0] =  [Ga+Hd+Ig   Gb+He+Ih   Gc+Hf+Ii   0]
// [J K L 1]      [j k l 1]    [Ja+Kd+Lg+j Jb+Ke+Lh+k Jc+Kf+Li+l 1]

// Calculate the new a: Aa+Bd+Cg

    res[MTX_A] = a[MTX_A]*b[MTX_A] + a[MTX_B]*b[MTX_D] + a[MTX_C]*b[MTX_G];

// Calculate the new b: Ab+Be+Ch

    res[MTX_B] = a[MTX_A]*b[MTX_B] + a[MTX_B]*b[MTX_E] + a[MTX_C]*b[MTX_H];

// Calculate the new c: Ac+Bf+Ci

    res[MTX_C] = a[MTX_A]*b[MTX_C] + a[MTX_B]*b[MTX_F] + a[MTX_C]*b[MTX_I];

// Calculate the new d: Da+Ed+Fg

    res[MTX_D] = a[MTX_D]*b[MTX_A] + a[MTX_E]*b[MTX_D] + a[MTX_F]*b[MTX_G];

// Calculate the new e: Db+Ee+Fh

    res[MTX_E] = a[MTX_D]*b[MTX_B] + a[MTX_E]*b[MTX_E] + a[MTX_F]*b[MTX_H];

// Calculate the new f: Dc+Ef+Fi

    res[MTX_F] = a[MTX_D]*b[MTX_C] + a[MTX_E]*b[MTX_F] + a[MTX_F]*b[MTX_I];

// Calculate the new g: Ga+Hd+Ig

    res[MTX_G] = a[MTX_G]*b[MTX_A] + a[MTX_H]*b[MTX_D] + a[MTX_I]*b[MTX_G];

// Calculate the new h: Gb+He+Ih

    res[MTX_H] = a[MTX_G]*b[MTX_B] + a[MTX_H]*b[MTX_E] + a[MTX_I]*b[MTX_H];

// Calculate the new i: Gc+Hf+Ii

    res[MTX_I] = a[MTX_G]*b[MTX_C] + a[MTX_H]*b[MTX_F] + a[MTX_I]*b[MTX_I];

// Calculate the new j: Ja+Kd+Lg+j

    res[MTX_J] = a[MTX_J]*b[MTX_A] + a[MTX_K]*b[MTX_D] + a[MTX_L]*b[MTX_G] + b[MTX_J];

// Calculate the new k: Jb+Ke+Lh+k

    res[MTX_K] = a[MTX_J]*b[MTX_B] + a[MTX_K]*b[MTX_E] + a[MTX_L]*b[MTX_H] + b[MTX_K];

// Calculate the new l: Jc+Kf+Li+l

    res[MTX_L] = a[MTX_J]*b[MTX_C] + a[MTX_K]*b[MTX_F] + a[MTX_L]*b[MTX_I] + b[MTX_L];
}

//°±² End of module - support.c ²±°

