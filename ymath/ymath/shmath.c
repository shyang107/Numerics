//
//  shmath.c
//  shmath
//
//  Created by 楊樹華 on 2015/3/10.
//  Copyright (c) 2015年 楊樹華. All rights reserved.
//

#include "shmath.h"

/**********************************************************************/
//int cmut(double a[], double b[], double c[],
//		 int n, int m, int l, int na, int nb, int, nc){
///*====================================================================*/
///* double a(na, n), b(nb, m), c(nc, l) */
//	double cij;
//	int i, j, k, ik, jb, jc;
//	--a; a -= na; --b; b -= nb; --c; c -= nc;
///*====================================================================*/
//	for (j=1; j<=l; j++) {
//		jb = j+nb;	jc = j+nc;
//		for (i=1; i<=n; i++) {
//			cij = 0.0;
//			for (k=1, ik=i+na; k<=m; k++, ik+=na) {
//				Cij += a[ik]*b[k+jb];
//			}
//			c[i+jc]=cij;
//		}
//	}
//	return 0;
//}

/* matrix utility ************************************************************/
int tempAg(double** a, int n, int m, double (*v)(int, int)){
    // double a[n,m]
    int i, j;
    --a;  a-=n;
    //--------------------------------------------------------------------------
    for (i=1; i<=n; i++) {
        for (j=1; j<=m; j++) {
            a[i][j]= (*v)(i,j);
        }
    }
    return 0;
}
//==============================================================================
int tempA(double a[], int n, int m, double (*v)(int, int)){
    // double a[n*m]
    int i, j;
    --a; a-=n;
    //--------------------------------------------------------------------------
    for (i=1; i<=n; i++) {
        for (j=1; j<=m; j++) {
            a[CMPK(i, j, n)]= (*v)(i,j);
        }
    }
    return 0;
}
//==============================================================================
int printA(double* a, int n, int m, int nn){
	/*-----------------------------------------------------------------------*/
    int i, j, jl, jh, m_width=10;
    --a; a-=nn;	// a(nn,m)
    /*-----------------------------------------------------------------------*/
    for (jl=1; jl<m; jl+=m_width){
        jh=jl+m_width-1; if(jh>m) jh=m;
        printf("\n     ");
        for (j=jl; j<=jh; j++) printf("%6d", j);
        printf("\n");
        for (i=1; i<=n; i++) {
            printf("%5d", i);
            for (j=jl; j<=jh; j++) printf("%6.2lf", a[CMPK(i, j, nn)]);
            printf("\n");
        }
    }
    return 0;
}
/* matrix utility ************************************************************/
