#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

double** mat_cria (int m, int n)
{
	double** lines = (double**) malloc(m*sizeof(double*));
	for(int i=0;i<m;i++)
	{
		lines[i] = (double*) malloc(n*sizeof(double));
	}
	return lines;
}

void mat_libera (int m, double** A)
{
	for(int i=0;i<m;i++)
	{
		free(A[i]);
	}
	free(A);
}

void mat_transposta (int m, int n, double** A, double** T)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			T[j][i] = A[i][j];
		}
	}
}

void mat_multv (int m, int n, double** A, double* v, double* w)
{
	for(int i=0; i<m; i++)
	{
		w[i] = 0.0;
		for(int j=0; j<n; j++)
		{
			w[i] += A[i][j]*v[j];
		}
	}
}

void mat_multm (int m, int n, int q, double** A, double** B, double** C)
{
	for(int i=0; i<m; i++)
	{
		for(int k=0; k<q; k++)
		{
			C[i][k] = 0.0;
			for(int j=0; j<n; j++)
			{
				C[i][k] += A[i][j]*B[j][k];
			}
		}
	}
}

double** mat_identidade(int n) {

	double** A = mat_cria(n,n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = (i == j)? 1 : 0;
		}
	}
	return A;
}

void mat_print(int linha, int coluna, double** A) {

	for (int i = 0; i < linha; i++) {
		for (int j = 0; j < coluna; j++) {
			printf("%g    ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
