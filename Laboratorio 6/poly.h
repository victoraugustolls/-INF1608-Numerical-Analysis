
typedef struct sample {
	int n; /* numero de amostras */
	double* x; /* valores x das amostras */
	double* y; /* valores y das amostras */
} Sample;

Sample* Chebyshev(int n, double a, double b, double (*f) (double x));
double* NewtonCompute(Sample *s);
double NewtonEval(Sample *s, double *b, double x);
double ChebyError(int n, double a, double b);