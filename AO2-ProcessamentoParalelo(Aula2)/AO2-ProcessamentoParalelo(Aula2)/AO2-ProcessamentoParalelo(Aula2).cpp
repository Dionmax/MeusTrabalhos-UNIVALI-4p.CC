// AO2-ProcessamentoParalelo(Aula2).cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

// LINK PDF AUXILIAR: https://www.openmp.org/wp-content/uploads/OpenMP3.1-CCard.pdf

#include "pch.h"
#include <iostream>

#include <omp.h>
#include <time.h>
#include <cmath>

const int TAMANHO = 10;
const int TAMANHO_MAX = 100;

using namespace std;

void exemplo3()	//Algoritimos de ordenação
{
	int vetor[TAMANHO],
		quantidade_threads;

	srand(time(NULL));

	for (int indice = 0; indice < TAMANHO; indice++)
		vetor[indice] = rand() % TAMANHO_MAX;

	omp_set_num_threads(4);

	#pragma omp parallel 
	{
		int identificadorThreads = omp_get_thread_num();
		quantidade_threads = omp_get_num_threads();

		for (int indice = 0; indice < TAMANHO; indice++)
		{
			int menor = vetor[indice], posicao = indice;

			for (int contador = indice + 1; contador < TAMANHO; contador++)
			{
				if (vetor[contador] < menor)
				{
					menor = vetor[contador];
					posicao = contador;
				}
			}

			int aux = vetor[indice];
			vetor[posicao] = aux;
			vetor[indice] = menor;
		}
	}

	for (int indice = 0; indice < TAMANHO; indice++)
	{
		printf("Vetor posicao %d valor : %d \n", indice,vetor[indice]);

	}
}

void exemplo2()	//Balanceamento de cargas das threads
{
	int vetor[TAMANHO],
		soma = 0,
		quantidade_threads;

	for (int indice = 0; indice < TAMANHO; indice++)
		vetor[indice] = 1;

	omp_set_num_threads(4);

	#pragma omp parallel 
	{
		int identificadorThreads = omp_get_thread_num();
		quantidade_threads = omp_get_num_threads();

		for (int indice = identificadorThreads; indice < TAMANHO; indice+=quantidade_threads)
		{
			soma += vetor[indice];
		}
	}

	printf("Soma: %d", soma);
}

void exemplo1()
{
	omp_set_num_threads(4);

	#pragma omp parallel 
	{
		#pragma omp critical
		{
			//Grupo de operações
		}

		//#pragma omp atomic
		{
			//Unica operação
		}

		#pragma omp single
		{
			//Protege e executa apenas uma thread, depois compartilha a thread
			//Poupa as outras de fazer um processamento redundante.
		}
	}

}

int main()
{
	exemplo3();
}
