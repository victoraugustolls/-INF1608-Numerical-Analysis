#include "gauss.h"
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

void teste1();
void teste2();

int main (void) {

	teste1();
	teste2();

	return 0;
}

void teste1() {

	int n = 3;
	double** A = mat_cria(n,n);
	A[0][0] = 1.0;
	A[0][1] = 2.0;
	A[0][2] = -1.0;
	A[1][0] = 2.0;
	A[1][1] = 1.0;
	A[1][2] = -2.0;
	A[2][0] = -3.0;
	A[2][1] = 1.0;
	A[2][2] = 1.0;
	double b[3] = {3.0, 3.0, -6.0};
	double* x = (double*)malloc(n*sizeof(double));

	gauss(n, A, b, x);

	printf("Resultado\n");
	for (int i = 0; i < n; i++) {
		printf("x[%d] = %g\n", i, x[i]);
	}
	printf("\n");
}

void teste2() {

	int n = 6;
	double** A = mat_cria(n,n);

	A[0][0] = 3.0;
	A[0][1] = -1.0;
	A[0][2] = 0.0;
	A[0][3] = 0.0;
	A[0][4] = 0.0;
	A[0][5] = 0.5;

	A[1][0] = -1.0;
	A[1][1] = 3.0;
	A[1][2] = -1.0;
	A[1][3] = 0.0;
	A[1][4] = 0.5;
	A[1][5] = 0.0;

	A[2][0] = 0.0;
	A[2][1] = -1.0;
	A[2][2] = 3.0;
	A[2][3] = -1.0;
	A[2][4] = 0.0;
	A[2][5] = 0.0;

	A[3][0] = 0.0;
	A[3][1] = 0.0;
	A[3][2] = -1.0;
	A[3][3] = 3.0;
	A[3][4] = -1.0;
	A[3][5] = 0.0;

	A[4][0] = 0.0;
	A[4][1] = 0.5;
	A[4][2] = 0.0;
	A[4][3] = -1.0;
	A[4][4] = 3.0;
	A[4][5] = -1.0;

	A[5][0] = 0.5;
	A[5][1] = 0.0;
	A[5][2] = 0.0;
	A[5][3] = 0.0;
	A[5][4] = -1.0;
	A[5][5] = 3.0;

	double b[6] = {2.5, 1.5, 1.0, 1.0, 1.5, 2.5};
	double* x = (double*)malloc(n*sizeof(double));

	gauss(n, A, b, x);

	printf("Resultado: \n");
	for (int i = 0; i < n; i++) {
		printf("x[%d] = %g\n", i, x[i]);
	}
}
