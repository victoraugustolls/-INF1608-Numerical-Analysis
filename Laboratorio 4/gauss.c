#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void gauss (int n, double** A, double* b, double* x) {

	double matAux[n][n];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			matAux[i][j] = A[i][j];
		}
	}
	double vetAux[n];
	for (int i = 0; i < n; i++) {
		vetAux[i] = b[i];
	}

	//PIVOTAMENTO
	for (int j = 0; j < n-1; j++) {
		int pivot = j;
		for (int k = j+1; k <= n-1; k++) {
			if (fabs(A[k][j]) > fabs(A[pivot][j])) {
				pivot = k;
			}
		}
		for (int k = 0; k <= n-1; k++) {
			A[j][k] = A[pivot][k];
			A[pivot][k] = matAux[j][k];
			b[j] = b[pivot];
			b[pivot] = vetAux[j];
			for (int i = 0; i < n; i++){
				for (int l = 0; l < n; l++) {
					matAux[i][l] = A[i][l];
				}
			}
			for (int i = 0; i < n; i++) {
				vetAux[i] = b[i];
			}
		}
	}
	printf("Matriz pivotada:\n");
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			printf("%g ", A[i][j]);
		}
		printf("\n");
	}
	printf("Vetor pivotado:\n");
	for (int i = 0; i < n; i++) {
		printf("b[%d] = %g\n", i, b[i]);
	}
	printf("\n");
	//

	//GAUSS
	for (int j = 0; j < n-1; j++) {
		for (int i = j+1; i < n; i++) {
			double fator = A[i][j] / A[j][j];
			for (int k = j; k < n; k++) {
				A[i][k] -= A[j][k] * fator;
			}
			b[i] -= b[j]*fator;
		}
	}
	printf("Matriz:\n");
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			printf("%g ", A[i][j]);
		}
		printf("\n");
	}
	printf("Vetor:\n");
	for (int i = 0; i < n; i++) {
		printf("b[%d] = %g\n", i, b[i]);
	}
	printf("\n");

	for (int i = n-1; i >= 0; i--) {
		double s = 0;
		for (int j = n-1; j > i; j--) {
			s += A[i][j] * x[j];
		}
		x[i] = (b[i]-s) / A[i][i];
	}
	//

}
