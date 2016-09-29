#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "raiz.h"

#define PRECISAO 1E-15

void testStatus(int status, int teste);
double f(double x);
double questao2(double x);
double questao3(double x);
double questao4(double x);

int main(void) {

	double inicio = -1;
	double fim = 1;
	double raiz = 0;
	double erro = 0;
	int precisao = 20;

	//Questão 1

	printf("Questao 1\n");
	for(int teste = 0; teste < 100; teste++) {

		inicio = -teste-10;
		fim = teste+10;

		printf("\n***** Inicio Teste %d *****\n", teste);
		printf("Inicio: %.16g\n", inicio);
		printf("Fim: %.16g\n", fim);
		raiz = bissecao(0, 10, precisao, f);
		erro = bissecao_erro(precisao);
		printf("Raiz: %.16g\n", raiz);
		printf("Erro: %.16g\n", erro);
		printf("Precisao: %.16g\n", PRECISAO);
		printf("Raiz - Erro: %.16g\n", (raiz-erro));
		if (fabs(raiz-3) < erro + PRECISAO) {
			testStatus(1, teste);
		}
		else {
			testStatus(0,teste);
			exit(1);
		}
		printf("***** Fim Teste %d *****\n", teste);
	}

	printf("\nTodos os testes foram concluidos com sucesso!\n\n");

	//Questão 2

	printf("Questao 2\n");
	inicio = 40;
	fim = 65;
	precisao = 6;
	raiz = bissecao(inicio, fim, precisao, questao2);
	erro = bissecao_erro(precisao);
	printf("Raiz: %.16g\n", raiz);
	printf("Erro: %.16g\n", erro);
	printf("Raiz - Erro: %.16g\n", raiz-erro);

	//Questão 3

	printf("\nQuestao 3\n");
	double ponto_fixo = pontofixo(0, pow(10,-10), questao3);
	printf ("Ponto fixo de cos: %.16g\n", ponto_fixo);

	//Questão 3

	printf("\nQuestao 4\n");
	ponto_fixo = pontofixo(0.5, 0.0005, questao4);
	printf ("Ponto fixo: %.16g\n", ponto_fixo);

	return 0;
}

void testStatus (int status, int teste) {

	if (status == 0) {
		printf("Teste %d Falhou\n\n", teste);
	}
	else {
		printf("Teste %d Funcionou\n", teste);
	}
}

double f(double x) {
	return x-3;
}

double questao2(double x) {
	return (9.8*x/15)*(1-exp(-(15/x)*9)) - 35;
}

double questao3(double x) {
	return cos(x);
}

double questao4(double x) {
	return sqrt(1.8*x+2.5);
}
