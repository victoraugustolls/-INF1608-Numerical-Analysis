#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "poly.h"

static int* calculaBeta(int n);
static double calculaB(int i, int j, Sample *s);
static int factorial(int n);

/************************************/
/* Funcoes de acesso do modulo      */
/************************************/

Sample* Chebyshev(int n, double a, double b, double (*f) (double x)) {

	double inicial = (b-a)/2;
	double final = (b+a)/2;

	Sample* s = NULL;

	s = (Sample *)malloc(sizeof(Sample));

	s->n = n;
	s->x = (double*)malloc(n*sizeof(double));
	s->y = (double*)malloc(n*sizeof(double));

	int* beta = calculaBeta(n);

	for (int i = 0; i < n; i++) {
		s->x[i] = inicial* cos(beta[i]*M_PI/(2*n))+ final;
		s->y[i] = f(s->x[i]);
	}

	return s;
}

double* NewtonCompute(Sample *s) {

	double *v = (double*)malloc(s->n*sizeof(double));

	for (int i = 0; i < s->n; i++) {
		v[i] = calculaB(0, i, s);
	}
	return v;
}

double NewtonEval(Sample *s, double *b, double x) {

	double resposta = 0;
	double x2 = 1;

	for (int i = 0; i < s->n; i++) {
		x2 = 1;
		for (int j = 0; j < i; j++) {
			x2 *= (x-s->x[j]);
		}
		resposta += b[i]*x2;
	}

	return resposta;
}

double ChebyError(int n, double a, double b) {
	
	double numerador = (b-a)/2;
	numerador = pow(numerador, n);

	double denominador = pow(2, n-1);

	return (numerador/(denominador*factorial(n)));
}

/************************************/
/* Funcoes encapsuladas pelo modulo */
/************************************/

int* calculaBeta(int n) {

	int *v = (int *)malloc(n*sizeof(int));
	int i = 0;
	int j = 0;
	
	for (i = 0, j = 0; i <= 2*n-1; i++) {
		if (i%2 == 1) {
			v[j] = i;
			j++;
		}
	}

	printf("\nbeta=\n");
	for (i = 0; i < n; ++i) {
		printf("%d ", v[i]);
	}

	return v;
}

double calculaB(int i, int j, Sample *s) {
	if (i == j) {
		return s->y[i];
	}
	return (calculaB(i+1, j, s) - calculaB(i, j-1, s))/(s->x[j]-s->x[i]);
}

int factorial(int n) {
	if (n == 1) {
		return 1;
	}
	return n * factorial(n - 1);
}
