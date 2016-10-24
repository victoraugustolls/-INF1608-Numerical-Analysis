#include <stdio.h>
#include <math.h>
#include "poly.h"

static double testeCosseno(double x);
static double arcoCongruo(double arco, int *sinal);

int main(int argc, char const *argv[]) {

	int n = 6;
	double a = 0;
	double b = M_PI/2;

	Sample* s = Chebyshev(n, a, b, testeCosseno);

	//X e Y
	printf("\n\nx=\n");
	for (int i = 0; i < n; i++) {
		printf("%g ", s->x[i]);
	}
	printf("\n\ny=\n");
	for (int i = 0; i < n; i++) {
		printf("%g ", s->y[i]);
	}
	//

	//B
	double *v = NewtonCompute(s);
	printf("\n\nv=\n");
	for (int i = 0; i < n; i++) {
		printf("%g ", v[i]);
	}
	printf("\n");
	//

	double pontos[9] = {-2*M_PI, -M_PI, -M_PI/2, -M_PI/3, 0, M_PI/3, M_PI/2, M_PI, 2*M_PI};
	double resposta = 0;
	double real = 0;
	double erro = 0;
	double arco = 0;
	double max = ChebyError(n, a, b);
	int sinal = 1;

	//Valor
	for (int i = 0; i < 9; i++) {
		arco = arcoCongruo(pontos[i], &sinal);
		resposta = NewtonEval(s, v, arco);
		real = testeCosseno(arco);
		erro = sinal*resposta - sinal*real;
		printf("\nPonto: %g | Congruo: %g\n", pontos[i], arco);
		printf("Eval: %.16g | Real: %.16g\n", sinal*resposta, sinal*real);
		printf("Erro: %.16g | Erro maximo: %.16g\n", erro, max);
		if (fabs(erro) < max) {
			printf("Erro menor do que erro maximo\n");
		} else {
			printf("Erro maior do que erro maximo\n");
		}
	}
	//

	return 0;
}

double testeCosseno(double x) {
	return cos(x);
}

double arcoCongruo(double arco, int *sinal) {
	double newArco = arco;
	if (newArco < 0) {
		newArco = -newArco;
		*sinal = 1;
	}
	if (newArco > M_PI/2 && newArco < M_PI) {
		*sinal = -1;
		newArco = -(newArco - M_PI);
	}
	else if (newArco >= M_PI && newArco < 3*M_PI/2) {
		*sinal = -1;
		newArco = newArco - M_PI;
	}
	else if (newArco >= 3*M_PI/2) {
		newArco = -(newArco - 2*M_PI);
		*sinal = 1;
	}
	return newArco;
}
