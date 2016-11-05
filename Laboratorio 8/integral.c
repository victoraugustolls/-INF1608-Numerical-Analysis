#include "integral.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double derivada (double (*f) (double x), double h, double x) {

	double numerador1 = f(x+h);
	double numerador2 = f(x-h);
	double numerador = numerador1 - numerador2;
	double denominador = 2*h;

	return numerador/denominador;
}

double simpson (double (*f) (double), double a, double b, int n) {

	double h = (b - a)/n;
	double x = a;
	double sum = 0;

	while (x < b) {
		sum += (h/6) * (f(x) + 4*f(x+h/2) + f(x+h));
		x = x + h;
	}

	return sum;
}

double pontomedio (double (*f) (double), double a, double b, int n) {

	double h = (b - a)/n;
	double x = a;
	double sum = 0;

	while (x < b) {
		sum += h*f(x + h/2);
		x = x + h;
	}

	return sum;
}
