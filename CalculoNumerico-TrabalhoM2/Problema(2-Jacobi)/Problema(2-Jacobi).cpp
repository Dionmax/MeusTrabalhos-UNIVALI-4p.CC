// Problema(2-Jacobi).cpp : define o ponto de entrada para o aplicativo do console.

#include "stdafx.h"
#include <iostream>
#include <string>

#include <math.h>
#include <algorithm>

const int LINHA = 10;
const int COLUNA = 11;
const double ERROR = pow(10, -5);


using namespace std;

bool verificacaoCriteiroDasLinhas(double matriz[LINHA][COLUNA])
{
	double resultadoFinalLinhas[LINHA];

	for (int contadorLinha = 0; contadorLinha < LINHA; contadorLinha++)
	{
		double divisor = abs(matriz[contadorLinha][contadorLinha]),
			alpha = 0.0;

		for (int contadorColuna = 0; contadorColuna < COLUNA - 1; contadorColuna++)
		{
			if (contadorColuna != contadorLinha)
			{
				alpha += abs(matriz[contadorLinha][contadorColuna]);
			}
		}
		resultadoFinalLinhas[contadorLinha] = alpha / divisor;
	}

	return *max_element(resultadoFinalLinhas, resultadoFinalLinhas + LINHA) < 1.0;
}

int main()
{
	//cout.precision(9);

	double matriz[LINHA][COLUNA] = {
		4, -1,	0, -1,	0,	0,	0,	0,	0,	0, -110,
		-1,	4, -1,	0, -1,	0,	0,	0,	0,	0 ,-30,
		0, -1,	4,	0,	0, -1,	0,	0,	0,	0, -40,
		-1,	0,	0,	4, -1,	0,	0,	0,	0,	0, -110,
		0, -1,	0, -1,	4, -1, -1,	0,	0,	0,	0,
		0,	0, -1,	0, -1,	4,	0, -1,	0,	0, -15,
		0,	0,	0,	0, -1,	0,	4, -1,	0,	0, -90,
		0,	0,	0,	0,	0, -1, -1,	4, -1,	0, -25,
		0,	0,	0,	0,	0,	0,	0, -1,	4, -1, -55,
		0,	0,	0,	0,	0,	0	,0,	0, -1,	4, -65
	};


	//Variaveis

	double divisor = 0.0,
		arrayXAnterior[LINHA],
		arrayX[LINHA] = { 0.0 },
		arrayDistancia[LINHA],
		error = 0.0;

	//Calculo dos valores inicais
	for (int calculoInicial = 0; calculoInicial < LINHA; calculoInicial++)
		arrayXAnterior[calculoInicial] = matriz[calculoInicial][COLUNA - 1] / matriz[calculoInicial][calculoInicial];

	do
	{
		for (int linha = 0; linha < LINHA; linha++)
		{
			if (matriz[linha][linha] == 0)
				divisor = 0;
			else
				divisor = 1.0 / matriz[linha][linha];

			for (int coluna = 0; coluna < COLUNA - 1; coluna++)
			{
				if (coluna != linha)
					arrayX[linha] += matriz[linha][coluna] * arrayXAnterior[coluna];
			}

			arrayX[linha] = divisor * (matriz[linha][COLUNA - 1] - arrayX[linha]);
		}

		//Calculo do erro!
		for (int indice = 0; indice < LINHA; indice++) {
			arrayDistancia[indice] = abs(arrayX[indice] - arrayXAnterior[indice]);
			arrayXAnterior[indice] = abs(arrayX[indice]);
		}

		error = abs(*max_element(arrayDistancia, arrayDistancia + LINHA)) / abs(*max_element(arrayXAnterior, arrayXAnterior + LINHA));

		// Salvando X anterior e Zerando o Array do X
		for (int indice = 0; indice < LINHA; indice++) {
			arrayXAnterior[indice] = arrayX[indice];
			arrayX[indice] = 0.0;
		}

		//Escrevendo valores de X no console
		for (int indice = 0; indice < LINHA; indice++)
			cout << " X" << indice << ": " << arrayXAnterior[indice] << endl;
		cout << endl;

	} while (error > ERROR);

	cout << endl;
	cout << "Error: " << error << endl;
	cout << endl;

	system("PAUSE");
	return 0;
}

