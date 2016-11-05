#include "mmq.h"
#include "matriz.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static double ** matriz_teste1();
static double * vetor_teste1();
static double ** matriz_teste2();
static double * vetor_teste2();
static double ** matriz_teste3();
static double * vetor_teste3();

int main() {

	int linha, coluna;
	double ** A;
	double *b;
	double *x;
	double n;

	printf("Exercicio 3a\n\n");

	linha = 5;
	coluna = 3;
	A = matriz_teste1();
	b = vetor_teste1();

	x = mmq(linha, coluna, A, b);
	n = norma2(linha, coluna, A, b, x);

	printf("x=\n");
	for (int i = 0; i < coluna; i++) {
		printf("%.16g\n", x[i]);
	} printf("\n");

	printf("norma= %.16g\n\n", n);

	printf("Exercicio 3b\n\n");

	linha = 5;
	coluna = 4;
	A = matriz_teste2();
	b = vetor_teste2();

	x = mmq(linha, coluna, A, b);
	n = norma2(linha, coluna, A, b, x);

	printf("x=\n");
	for (int i = 0; i < coluna; i++) {
		printf("%.16g\n", x[i]);
	} printf("\n");

	printf("norma= %.16g\n\n", n);

	printf("Exercicio 4\n\n");

	linha = 8;
	coluna = 2;
	A = matriz_teste3();
	b = vetor_teste3();

	x = mmq(linha, coluna, A, b);

	x[0] = exp(x[0]);

	printf("A=\n");
	mat_print(linha, coluna, A);

	printf("b=\n");
	for (int i = 0; i < linha; i++) {
		printf("%g\n", b[i]);
	} printf("\n");

	printf("x=\n");
	for (int i = 0; i < coluna; i++) {
		printf("%.16g\n", x[i]);
	} printf("\n");

	n = norma2(linha, coluna, A, b, x);

	printf("norma= %.16g\n\n", n);

	printf("t\tc\n");
	for (double i = 0; i < 16; i+= 0.1) {
		printf("%g\t%.16g\n", i, x[0]*i*exp(x[1]*i));
	}

	return 0;
}

double ** matriz_teste1() {

	double ** A = mat_cria(5, 3);

	A[0][0] = 3;  A[0][1] = -1; A[0][2] = 2;
	A[1][0] = 4;  A[1][1] = 1;  A[1][2] = 0;
	A[2][0] = -3; A[2][1] = 2;  A[2][2] = 1;
	A[3][0] = 1;  A[3][1] = 1;  A[3][2] = 5;
	A[4][0] = -2; A[4][1] = 0;  A[4][2] = 3;

	return A;
}

double * vetor_teste1() {

	double * b = (double*)malloc(5*sizeof(double));

	b[0] = 10; b[1] = 10; b[2] = -5; b[3] = 15; b[4] = 0;

	return b;
}

double ** matriz_teste2() {

	double ** A = mat_cria(5, 4);

	A[0][0] = 4;  A[0][1] = 2;  A[0][2] = 3;  A[0][3] = 0;
	A[1][0] = -2; A[1][1] = 3;  A[1][2] = -1; A[1][3] = 1;
	A[2][0] = 1;  A[2][1] = 3;  A[2][2] = -4; A[2][3] = 2;
	A[3][0] = 1;  A[3][1] = 0;  A[3][2] = 1;  A[3][3] = -1;
	A[4][0] = 3;  A[4][1] = 1;  A[4][2] = 3;  A[4][3] = -2;

	return A;
}

double * vetor_teste2() {

	double * b = (double*)malloc(5*sizeof(double));

	b[0] = 10; b[1] = 0; b[2] = 2; b[3] = 0; b[4] = 5;

	return b;
}

double ** matriz_teste3() {

	double ** A = mat_cria(8, 2);

	A[0][0] = 1; A[0][1] = 1;
	A[1][0] = 1; A[1][1] = 2;
	A[2][0] = 1; A[2][1] = 3;
	A[3][0] = 1; A[3][1] = 4;
	A[4][0] = 1; A[4][1] = 5;
	A[5][0] = 1; A[5][1] = 6;
	A[6][0] = 1; A[6][1] = 7;
	A[7][0] = 1; A[7][1] = 8;

	return A;
}

double * vetor_teste3() {

	double * b = (double*)malloc(8*sizeof(double));

	b[0] = log(8.0) - log(1);
	b[1] = log(12.3) - log(2);
	b[2] = log(15.5) - log(3);
	b[3] = log(16.8) - log(4);
	b[4] = log(17.1) - log(5);
	b[5] = log(15.8) - log(6);
	b[6] = log(15.2) - log(7);
	b[7] = log(14.0) - log(8);

	return b;
}
