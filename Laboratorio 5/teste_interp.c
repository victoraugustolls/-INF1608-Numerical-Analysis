#include "interp.h"
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

// static void constroi_matriz(double** A);
// static void constroi_vetor(double* b);
static void constroi_pontos(double* x, double* y);
static void constroi_avalia(double* avalia);

int main(void) {

	int n = 11;

	double* x = (double*)malloc(n*sizeof(double));
	double* y = (double*)malloc(n*sizeof(double));
	double* pontos_avalia = (double*)malloc(n*sizeof(double));

	constroi_pontos(x,y);
	constroi_avalia(pontos_avalia);

	double* resultado = interpola(n,x,y);

	double valor_avalia = 0.0;
	for (int i = 0; i < n; i++) {
		valor_avalia = avalia(n,resultado,pontos_avalia[i]);
		printf("Avalia de %g -> %g\n", pontos_avalia[i], valor_avalia);
	}
	printf("\n");

	//Testa por Lagrange
	double valor_lagrange = 0.0;
	for (int i = 0; i < n; i++) {
		valor_lagrange = lagrange(n,x,y,pontos_avalia[i]);
		printf("Lagrange de %g -> %g\n", pontos_avalia[i], valor_lagrange);
	}
	//

	free(x);
	free(y);
	free(pontos_avalia);

	return 0;
}

// void constroi_matriz(double** A) {
// 	A[0][0] = 1.0;  A[0][1] = 2.0; A[0][2] = -1.0;
// 	A[1][0] = 2.0;  A[1][1] = 1.0; A[1][2] = -2.0;
// 	A[2][0] = -3.0; A[2][1] = 1.0; A[2][2] = 1.0;
// }
//
// void constroi_vetor(double* b) {
// 	b[0] = 3;
// 	b[1] = 3;
// 	b[2] = -6;
// }

void constroi_pontos(double* x, double* y) {
	x[0] = -5; x[1] = -4; x[2] = -3; x[3] = -2; x[4] = -1; x[5] = 0;
	x[6] = 1; x[7] = 2; x[8] = 3; x[9] = 4; x[10] = 5;

	y[0] = 5; y[1] = 5; y[2] = 5; y[3] = 5; y[4] = 5; y[5] = 5;
	y[6] = 5; y[7] = 5; y[8] = 5; y[9] = 5; y[10] = 42;
}

void constroi_avalia(double* avalia) {
	avalia[0] = -1; avalia[1] = -0.8; avalia[2] = -0.6; avalia[3] = -0.4;
	avalia[4] = -0.2; avalia[5] = 0.0; avalia[6] = 0.2; avalia[7] = 0.4;
	avalia[8] = 0.6; avalia[9] = 0.8; avalia[10] = 1;
}
