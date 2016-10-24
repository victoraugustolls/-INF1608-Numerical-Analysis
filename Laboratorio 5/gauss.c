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
				for (int j = 0; j < n; j++) {
					matAux[i][j] = A[i][j];
				}
			}
			for (int i = 0; i < n; i++) {
				vetAux[i] = b[i];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%g %g %g\n", A[i][0], A[i][1], A[i][2]);
	}
	for (int i = 0; i < n; i++) {
		printf("%g\n", b[i]);
	}
	//

	//GAUSS
	for (int j = 0; j < n-2; j++) {
		//printf("%d\n", j);

		for (int i = 0; i < n-1; i++) {
			double fator = A[i][j] / A[j][j];
			for (int k = j+1; k < n-1; k++) {
				A[i][k] = A[i][k] - A[j][k] * fator;
			}
			b[i] = b[i]-b[j]*fator;
		}

	}
	for (int i = 0; i < n; i++) {
		printf("%g %g %g\n", A[i][0], A[i][1], A[i][2]);
	}

	for (int i = n-1; i < 0; i--) {
		double s = 0;
		for (int j = i+1; j < n-1; j++) {
			s = s + A[i][j] * x[j];
		}
		//printf("%g\n", (b[i]-s)/A[i][i]);
		x[i] = (b[i]-s)/A[i][i];
	}
	
}
