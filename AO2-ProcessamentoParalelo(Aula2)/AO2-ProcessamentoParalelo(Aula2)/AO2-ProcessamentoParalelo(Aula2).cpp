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

void exemplo8()
{
#pragma omp parallel
	{
		int identificadorThreads = omp_get_thread_num();

	#pragma omp single // Garantindo que tava tarefa ocupe o mesmo espãço de mémoria
		{

#pragma omp task
			{
				//As threads ociosas buscam as tarefas para ser resolvidas
				//Melhor recomendadas para tarefas dinamicas

#pragma omp task
				{
					//Agendamento de tarefas, que é feito por ordem que são agendas
				}
			}

#pragma omp task
			//pode estar em bloco ou não
		}
	
	}

}

void exemplo7()
{
#pragma omp parallel
	{
		int identificadorThreads = omp_get_thread_num();

#pragma omp task
		{
			//As threads ociosas buscam as tarefas para ser resolvidas
			//Melhor recomendadas para tarefas dinamicas

			#pragma omp task
			{
				//Agendamento de tarefas, que é feito por ordem que são agendas
			}
		}

#pragma omp task
		//pode estar em bloco ou não
	}

}

void exemplo6()
{
#pragma omp parallel
	{
		int identificadorThreads = omp_get_thread_num();

#pragma omp sections
		{
			//Usa diferentes threads para realizar diferentes operações simultaneas
		}

#pragma omp sections
		//pode estar em bloco ou não
	}
}

void exemplo5()
{
	int vetor[TAMANHO],
		quantidade_threads,
		soma = 0;

	for (int indice = 0; indice < TAMANHO; indice++)
		vetor[indice] = 1;

#pragma omp parallel for reduction(+:soma)
	for (int indice = 0; indice < TAMANHO; indice++)
	{
		soma += vetor[indice];
	}

	cout << "Soma: " << soma;
}

void exemplo4()
{
	int vetor[TAMANHO],
		quantidade_threads,
		soma = 0,
		soma_aux;

	for (int indice = 0; indice < TAMANHO; indice++)
		vetor[indice] = 1;

#pragma omp parallel private(soma_aux)
	{
		soma_aux = 0;

		int identificadorThreads = omp_get_thread_num();
		quantidade_threads = omp_get_num_threads();

#pragma omp for
		for (int indice = 0; indice < TAMANHO; indice++)
		{
			soma_aux += vetor[indice];
		}

#pragma omp atomic
		soma += soma_aux;
	}

	cout << "Soma: " << soma;
}

void exemplo3()	//Algoritimo de ordenação
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

#pragma omp parallel for
			for (int contador = indice; contador < TAMANHO; contador++)
			{
#pragma omp critical
				{
					if (vetor[contador] < menor)
					{
						menor = vetor[contador];
						posicao = contador;
					}
				}
			}

			int aux = vetor[indice];
			vetor[posicao] = aux;
			vetor[indice] = menor;
		}
	}

	for (int indice = 0; indice < TAMANHO; indice++)
	{
		printf("Vetor posicao %d valor : %d \n", indice, vetor[indice]);

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

		for (int indice = identificadorThreads; indice < TAMANHO; indice += quantidade_threads)
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
	exemplo5();
}
