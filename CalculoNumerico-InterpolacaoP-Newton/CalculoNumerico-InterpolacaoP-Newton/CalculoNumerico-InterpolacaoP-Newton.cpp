// CalculoNumerico-InterpolacaoP-Newton.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
#include <string>

#include <math.h>
#include <algorithm>


const int GRAUPOLINOMIO = 4;

using namespace std;

int main()
{
	//	cout.precision(10);

	float ValorDeX = 0.5,
		arrayX[GRAUPOLINOMIO] = {-2,-1,1,2},
		arrayFX[GRAUPOLINOMIO] = { 0,1,-1,0},
		arrayFxAnterior[GRAUPOLINOMIO] = { 0 },
		resultadoFinal = 0.0;

	//Formando Tabela Triangular
	for (int contador = 1; contador < GRAUPOLINOMIO; contador++)
	{
		int contadorExterno = 0;

		for (int indice_aux = 0; indice_aux < GRAUPOLINOMIO; indice_aux++)
			arrayFxAnterior[indice_aux] = arrayFX[indice_aux];

		for (int indice = contador; indice < GRAUPOLINOMIO; indice++)
		{
			arrayFX[indice] = (arrayFxAnterior[indice] - arrayFxAnterior[indice - 1]) / (arrayX[indice] - arrayX[contadorExterno]);

			contadorExterno++;
		}
	}

	for (int indice = 0; indice < GRAUPOLINOMIO; indice++)
		cout << "Fx(" << indice << ")= " << arrayFX[indice] << endl;

	cout << endl;

	//Esquema prático do resultado final

	resultadoFinal = arrayFX[GRAUPOLINOMIO - 1];

	for (int indice = GRAUPOLINOMIO - 2; indice >= 0; indice--)
	{
		resultadoFinal = (resultadoFinal * (ValorDeX - arrayX[indice]) + arrayFX[indice]);
	}

	cout << "Resultado Final no ponto " << ValorDeX << " igual a: " << resultadoFinal << endl;

	system("PAUSE");
}
