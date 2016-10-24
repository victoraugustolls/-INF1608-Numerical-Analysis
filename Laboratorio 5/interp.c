#include "interp.h"
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double coeficiente_lagrange(int k, double* px, int n, double x);

void pivotamento (int n, double** A, double** P) {
	double matAux[n][n];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			matAux[i][j] = A[i][j];
		}
	}

	double matAux2[n][n];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			matAux2[i][j] = P[i][j];
		}
	}

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
			P[j][k] = P[pivot][k];
			P[pivot][k] = matAux2[j][k];
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++) {
					matAux[i][j] = A[i][j];
					matAux2[i][j] = P[i][j];
				}
			}
		}
	}
}

double** fatoracao (int n, double** A) {

	double** P = mat_identidade(n);
	double fator;
	pivotamento(n, A, P);

	for (int j = 0; j < n-1; j++) {
		for (int i = j+1; i < n; i++) {
			fator = A[i][j]/A[j][j];
			for (int k = j; k < n; k++) {
				A[i][k] -= A[j][k]*fator;
			}
			A[i][j] = fator;
		}
	}

	return P;
}

double* substituicao (int n, double** A, double** P, double* b) {
	double* x = (double*)malloc(n*sizeof(double));
	double* y = (double*)malloc(n*sizeof(double));
	double* Pb = (double*)malloc(n*sizeof(double));
	mat_multv(n, n, P, b, Pb);

	//Substituicao progressiva
	for (int i = 0; i < n; i++) {
		double s = 0;
		for (int j = 0; j < i; j++) {
			s += A[i][j] * y[j];
		}
		y[i] = Pb[i] - s;
	}
	//

	//Substituicao regressiva
	for (int i = n-1; i >= 0; i--) {
		double s = 0;
		for (int j = n-1; j > i; j--) {
			s += A[i][j] * x[j];
		}
		x[i] = (y[i] - s)/A[i][i];
	}
	//

	free(y);
	free(Pb);
	return x;
}

double* interpola (int n, double* px, double* py) {

	double** X = mat_cria(n,n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			X[i][j] = pow(px[i], j);
		}
	}
	double** fat = fatoracao(n, X);
	double*constantes = substituicao(n, X, fat, py);

	mat_libera(n,X);
	mat_libera(n,fat);

	return constantes;
}

double avalia (int n, double* c, double x) {
	double resultado = c[0];
	for (int i = 1; i < n; i++) {
		resultado += c[i]*pow(x,i);
	}
	return resultado;
}

double lagrange (int n, double* px, double* py, double x) {

	double resultado = 0;

	for (int i = 0; i < n; i++) {
		resultado += py[i]*coeficiente_lagrange(i,px,n,x);
	}

	return resultado;
}

double coeficiente_lagrange(int k, double* px, int n, double x) {

	//Coeficiente de Lagrange
	double numerador = 1.0;
	double denominador = 1.0;
	for (int i = 0; i < n; i++) {
		if (i != k) {
			numerador *= (x - px[i]);
			denominador *= (px[k] - px[i]);
		}
	}
	//
	return numerador/denominador;
}
