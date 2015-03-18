//
//  main.c
//  shmath
//
//  Created by 楊樹華 on 2015/3/10.
//  Copyright (c) 2015年 楊樹華. All rights reserved.
//

#include <stdio.h>
#include "shmath.h"

double value(int i, int j){
    return (double)(i*10+j);
}

void test_printA(){
    const int n=5, m=5;
        //double a[n][m];
    double a1[n*m];
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            printf("%6.2f", value(i+1, j+1));
        }
        printf("\n");
    }
    printf("\n");
    
    tempA(a1, n, m, value);
    printf("--------------------------------");
    printA(a1, n, m, n);
    printf("--------------------------------");
    printA(a1, 1, n*m, 1);
    
}

void test_printA1(){
    const int n=5, m=5;
	double a[n][m];
    double a1[n*m];
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            a[i][j] = value(i+1, j+1);
            printf("%6.2f", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    tempA(a1, n, m, value);
    printf("--------------------------------");
    printA(a1, n, m, n);
    printf("--------------------------------");
    printA(&a[0][0], 1, n*m, 1);
    
}

int main(int argc, const char * argv[]) {
    test_printA1();
    return 0;
}
