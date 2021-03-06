// AO2-ProcessamentoParalelo.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

// LINK PDF AUXILIAR: https://www.openmp.org/wp-content/uploads/OpenMP3.1-CCard.pdf

#include "pch.h"
#include <iostream>

#include <omp.h>
#include <windows.h>

using namespace std;

const int TAMANHO_VETOR = 1000;

void exemplo1()
{
	omp_set_num_threads(4);

#pragma omp parallel
	{
		int contador_thread = omp_get_thread_num();

		int quantidade_thread = omp_get_num_threads();

		printf("Hello World! %d %d \n", contador_thread, quantidade_thread);
	}
}

void exemplo2()
{
	int vetor[TAMANHO_VETOR],
		soma = 0;


	for (int indice = 0; indice < TAMANHO_VETOR; indice++)
	{
		vetor[indice] = 1;
	}

#pragma omp parallel for
	for (int indice = 0; indice < TAMANHO_VETOR; indice++)
	{
		soma += vetor[indice];
	}

	printf("Soma : %d", soma);
}

void exemplo2ponto1()
{
	int vetor[TAMANHO_VETOR],
		soma = 0;


	for (int indice = 0; indice < TAMANHO_VETOR; indice++)
	{
		vetor[indice] = 1;
	}

#pragma omp parallel
	{
		int quantidadeThreads = omp_get_num_threads();
		int numeroThreads = omp_get_thread_num();

		int blocoTrabalho = TAMANHO_VETOR / quantidadeThreads;

		int inicio = numeroThreads * blocoTrabalho;
		int fim = inicio + blocoTrabalho;

		for (int indice = inicio; indice < fim; indice++)
			soma += vetor[indice];
	}

	printf("Soma : %d", soma);

	/*

	-> Soluções opcionais

	#pragma omp atomic (Hardware)
	#pragma omp critical (Software)

	Servem para bloquear expressões aritiméticas, para não se sobre escrever.

	*/
}

void exemplo2ponto2()
{
	int vetor[TAMANHO_VETOR],
		soma = 0;


	for (int indice = 0; indice < TAMANHO_VETOR; indice++)
	{
		vetor[indice] = 1;
	}

#pragma omp parallel
	{
		int quantidadeThreads = omp_get_num_threads();
		int numeroThreads = omp_get_thread_num();

		int blocoTrabalho = TAMANHO_VETOR / quantidadeThreads;

		int inicio = numeroThreads * blocoTrabalho;
		int fim = inicio + blocoTrabalho;

		int somaLocal = 0;
		for (int indice = inicio; indice < fim; indice++)
			somaLocal += vetor[indice];

#pragma omp atomic
		soma += somaLocal;
	}

	printf("Soma : %d", soma);

	/*

	-> Soluções opcionais

	#pragma omp atomic (Hardware)
	#pragma omp critical (Software)

	Servem para bloquear expressões aritiméticas, para não se sobre escrever.

	usa-se uma variavel privada, e depois soma o valor dela ao da variavel "global"

	*/
}

void exemplo2ponto3()
{
	int vetor[TAMANHO_VETOR],
		soma = 0;


	for (int indice = 0; indice < TAMANHO_VETOR; indice++)
	{
		vetor[indice] = 1;
	}

	int quantidadeThreads,
		numeroThreads;

#pragma omp parallel private(numeroThreads) shared(quantidadeThreads) num_threads(10)
	{
		quantidadeThreads = omp_get_num_threads();
		numeroThreads = omp_get_thread_num();

		int blocoTrabalho = TAMANHO_VETOR / quantidadeThreads;

		int inicio = numeroThreads * blocoTrabalho;
		int fim = inicio + blocoTrabalho;

		int somaLocal = 0;
		for (int indice = inicio; indice < fim; indice++)
			somaLocal += vetor[indice];

#pragma omp atomic
		soma += somaLocal;
	}

	printf("Soma : %d", soma);

	/*

	-> Soluções opcionais

	#pragma omp atomic (Hardware)
	#pragma omp critical (Software)

	Servem para bloquear expressões aritiméticas, para não se sobre escrever.

	usa-se uma variavel privada, e depois soma o valor dela ao da variavel "global"

	Há a possivilidade de defini qual variavel é privada ou public(compartilhada)

	*/
}

int main()
{
	exemplo2ponto3();
}
