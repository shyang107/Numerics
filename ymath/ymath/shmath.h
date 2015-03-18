//
//  shmath.h
//  shmath
//
//  Created by 楊樹華 on 2015/3/10.
//  Copyright (c) 2015年 楊樹華. All rights reserved.
//

#ifndef __shmath__shmath__
#define __shmath__shmath__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/* Macro ==================================================================== */
#define MAX(a,b)	((a>b)?a:b)
#define MAX3(a,b,c)	((MAX(a,b)>c)?MAX(a,b):c)
#define MIN(a,b)	((a<b)?a:b)
#define MIN3(a,b,c)	((MIN(a,b)<c)?MIN(a,b):c)

#define SQR(a)		a*a
/* matrix --------------------------------------------------------------------*/
/*    dimension a(n,m)   aij, i=1..n, j=1..m								  */
/*          | a11 a12 a13 a14 a15 |    										  */
/*          | a21 a22 a23 a24 a25 |    										  */
/*    [a] = | a31 a32 a33 a34 a35 |    										  */
/*    		| a41 a42 a43 a44 a45 |    										  */
/*																			  */
/*    for example:                                                    		  */
/*    in 1-d row-major array:                                                 */
/*    a(n*m) = (a11 a12 a13 a14 a15 a21 a22 a23 ... a43 a44 a45);             */
/*																			  */
/*	  in 1-d column-major array:											  */
/*    a(n*m) = (a11 a21 a31 a41 a12 a22 a32 a34 ... a25 a35 a45);             */
/*    ============================================================    		  */
#define RMPK(i,j,columns)	(i*columns+j)			//postion by row-major
#define CMPK(i,j,rows)		(i+j*rows)	 			//postion by column-major
/* Macro ==================================================================== */

/* Subrutine ================================================================ */
int tempAg(double* a[], int n, int m, double (*v)(int, int));
int tempA(double a[], int n, int m, double (*v)(int, int));
int printA(double a[], int n, int m, int nn);

/* Subrutine ================================================================ */


#endif /* defined(__shmath__shmath__) */
