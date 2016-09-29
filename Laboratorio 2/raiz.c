#include <stdio.h>
#include <math.h>
#include "raiz.h"

#define PRECISAO 1E-15

double bissecao (double a, double b, int p, double (*f) (double x)) {

	double erro = bissecao_erro(p);
	double c = 0;
	double fa, fb, fc;
	double comeco = a;
	double fim = b;
	fa = f(comeco);
	fb = f(fim);
	fc = 0.0;

	while(fabs(fim-comeco)/2.0 > erro) {
		c = (fim+comeco)/2.0;
		fc = f(c);
		if (fabs(fc) < PRECISAO) {
			return c;
		}
		else if (fa*fc < 0) {
			fim = c;
			fb = fc;
		}
		else {
			comeco = c;
			fa = fc;
		}
	}
	return c;
}

double bissecao_erro(int p) {
	return 0.5*pow(10.0, -p);
}

double pontofixo (double x0, double epsilon, double (*g) (double x)) {
	if (fabs(g(x0)-x0) > epsilon) {
		return pontofixo(g(x0), epsilon, g);
	}
	return x0;
}
