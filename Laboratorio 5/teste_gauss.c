#include "gauss.h"
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

int main (void) {

	int n = 3;
	double** A = mat_cria(3,3);
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
	double x[3];

	gauss(n, A, b, x);

	for (int i = 0; i < 3; i++) {
		printf("%g\n", x[i]);
	}

	return 0;
}
