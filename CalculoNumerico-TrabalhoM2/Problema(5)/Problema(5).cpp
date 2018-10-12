// Problema(5).cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
#include <string>

#include <math.h>
#include <algorithm>


const int GRAUPOLINOMIO = 7;

using namespace std;

int main()
{
	long double ValorDeX = 130.0,
		arrayX[GRAUPOLINOMIO] = { 60, 80, 100, 120, 140, 160, 180 },
		arrayFx[GRAUPOLINOMIO] = { 76, 96 ,112, 138, 151, 170, 192 },
		arrayFxAnterior[GRAUPOLINOMIO] = { 0 },
		resultadoFinal = 0.0;

	//Formando Tabela Triangular
	for (int contador = 1; contador < GRAUPOLINOMIO; contador++)
	{
		int contadorExterno = 0;

		for (int indice_aux = 0; indice_aux < GRAUPOLINOMIO; indice_aux++)
			arrayFxAnterior[indice_aux] = arrayFx[indice_aux];

		for (int indice = contador; indice < GRAUPOLINOMIO; indice++)
		{
			arrayFx[indice] = (arrayFxAnterior[indice] - arrayFxAnterior[indice - 1]) / (arrayX[indice] - arrayX[contadorExterno]);

			contadorExterno++;
		}
	}

	for (int indice = 0; indice < GRAUPOLINOMIO; indice++)
		cout << "valor de F(" << indice << ") = " << arrayFx[indice] << endl;

	cout << endl;

	//Esquema prático do resultado final

	resultadoFinal = arrayFx[GRAUPOLINOMIO - 1];

	int contador_aux = GRAUPOLINOMIO - 1;

	int contador_aux2 = 0;

	for (int indice = GRAUPOLINOMIO - 2; indice >= 0; indice--)
	{
		resultadoFinal += ((resultadoFinal * (ValorDeX - arrayX[indice])) + arrayFx[indice]);
		contador_aux--;
		contador_aux2++;
	}

	cout << "Valor Final no ponto " << ValorDeX << " : " << resultadoFinal << endl;

	cout << endl;

	system("PAUSE");
}
