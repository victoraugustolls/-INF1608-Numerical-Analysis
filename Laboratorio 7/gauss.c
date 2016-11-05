#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void gauss (int n, double** A, double* b, double* x){
   
    int i, j, k, p;
    double f, s, aux;
 
    // Eliminação
    for(j = 0; j <= n-2; j++){
 
        // Pivotamento
        p = j; 
        for(k = j+1; k <= n-1; k++){
            if( fabs(A[k][j]) > fabs(A[p][j]) )
                p = k;
        }
 
        // Swap
        for(k = 0; k <= n-1; k++){
            aux = A[j][k];
            A[j][k] = A[p][k];
            A[p][k] = aux;
        }
        aux = b[j];
        b[j] = b[p];
        b[p] = aux;
 
        for(i = j+1; i <= n-1; i++){
            f = A[i][j]/A[j][j];
 
            for(k = j; k <= n-1; k++)
                A[i][k] = A[i][k] - (A[j][k]*f);
            b[i] = b[i] - (b[j]*f);    
        }
    }
 
    // Substituição Regressiva
    for(i = n-1; i >= 0; i--){
        s = 0;
 
        for(j = i+1; j <= n-1; j++)
            s = s + (A[i][j]*x[j]);
        x[i] = (b[i] - s) / A[i][i];
    }
}