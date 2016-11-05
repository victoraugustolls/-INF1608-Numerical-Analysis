#include "integral.h"
#include <stdio.h>
#include <math.h>

static double funcao(double x);
static double integral1(double x);
static double integral2(double x);
static double integral3(double x);
static double erroNumerico(double h);
static double erroMinimo();
static void printTabela(double h, double x, double erro);

int main(int argc, char const *argv[]) {


	double h[12];
	double respostas[12];
	double resultado_simpson;
	double resultado_medio;

	for (int i = 0; i < 12; i++) {
		h[i] = pow(10, -(i+1));
	}
	for (int i = 0; i < 12; i++) {
		respostas[i] = derivada(funcao, h[i], 0);
	}
	for (int i = 0; i < 12; i++) {
		printTabela(h[i], respostas[i], erroNumerico(h[i]));
	}

	printf("\n");
	printf("O valor de h que minimiza o erro na tabela e o 10^-5.\n");
	printf("O h teorico que minimiza o erro e %g.\n", erroMinimo());
	printf("Os valores conferem (sao proximos). O valor de h e o valor ");
	printf("testado mais proximo do erro minimo, o que e valido.\n");
	printf("\n");


	printf("Integral 1\n");
	resultado_simpson = simpson(integral1, 0, 4, 16);
	resultado_medio = pontomedio(integral1, 0, 4, 16);
	printf("Simpson: %g | Ponto medio: %g n = 16\n", resultado_simpson, resultado_medio);
	resultado_simpson = simpson(integral1, 0, 4, 32);
	resultado_medio = pontomedio(integral1, 0, 4, 32);
	printf("Simpson: %g | Ponto medio: %g | n = 32\n", resultado_simpson, resultado_medio);

	printf("Integral 2\n");
	resultado_simpson = simpson(integral2, 1, 3, 16);
	resultado_medio = pontomedio(integral2, 1, 3, 16);
	printf("Simpson: %g | Ponto medio: %g n = 16\n", resultado_simpson, resultado_medio);
	resultado_simpson = simpson(integral2, 1, 3, 32);
	resultado_medio = pontomedio(integral2, 1, 3, 32);
	printf("Simpson: %g | Ponto medio: %g | n = 32\n", resultado_simpson, resultado_medio);

	printf("Integral 3\n");
	resultado_simpson = simpson(integral3, 0, M_PI, 16);
	resultado_medio = pontomedio(integral3, 0, M_PI, 16);
	printf("Simpson: %g | Ponto medio: %g n = 16\n", resultado_simpson, resultado_medio);
	resultado_simpson = simpson(integral3, 0, M_PI, 32);
	resultado_medio = pontomedio(integral3, 0, M_PI, 32);
	printf("Simpson: %g | Ponto medio: %g | n = 32\n", resultado_simpson, resultado_medio);

	return 0;
}

double funcao(double x) {

	return cos(x) - 2*sin(x);
}

double integral1(double x) {

	double numerador = x;
	double denominador = sqrt(pow(x,2) + 9);
	return numerador/denominador;
}

double integral2(double x) {

	return pow(x,2) * log(x);
}

double integral3(double x) {

	return pow(x,2) * sin(x);
}

double erroNumerico(double h) {

	return 2*pow(h,2)/6 + pow(2, -52)/h;
}

double erroMinimo() {
	double maq = pow(2, -52);
	return cbrt(3*maq);
}

void printTabela(double h, double x, double erro) {

	printf("h: %g \t f'(0): %.16g \t erro: %.16g\n", h, x, erro);
}
