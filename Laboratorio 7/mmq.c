#include "mmq.h"
#include "matriz.h"
#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* mmq (int m, int n, double** A, double* b) {

	double * resultV = (double*)malloc(m*sizeof(double));
	double * xB = (double*)malloc(n*sizeof(double));
	double ** resultM = mat_cria(n, n);
	double ** At = mat_cria(n, m);

	mat_transposta(m, n, A, At);

	mat_multv(n, m, At, b, resultV);

	mat_multm(n, m, n, At, A, resultM);

	gauss(n, resultM, resultV, xB);

	return xB;
}

double norma2 (int m, int n, double** A, double* b, double* x) {

	double * resultV = (double*)malloc(m*sizeof(double));
	double * rV = (double*)malloc(m*sizeof(double));
	double somatorio = 0;

	mat_multv(m, n, A, x, resultV);

	for (int i = 0; i < m; i++) {
		rV[i] = b[i] - resultV[i];
	}

	// printf("rV=\n");
	// for (int i = 0; i < m; i++)
	// {
	// 	printf("%g\n", rV[i]);
	// } printf("\n");

	for (int i = 0; i < m; ++i)
	{
		somatorio += pow(rV[i], 2);
	}

	somatorio = sqrt(somatorio);

	// printf("soma = %.16g\n", somatorio);

	return somatorio;
}
