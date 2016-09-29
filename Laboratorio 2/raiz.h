#ifndef _RAIZ_H
#define _RAIZ_H

double bissecao (double a, double b, int p, double (*f)(double x));
double bissecao_erro(int p);
double pontofixo (double x0, double epsilon, double (*g) (double x));

#endif
