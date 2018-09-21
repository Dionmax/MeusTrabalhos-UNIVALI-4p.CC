// CalculoNumerico-EliminacaoDeGaussSeidal.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include <math.h>
#include <algorithm>

#define PI 3.14159265358979323846
#define Euler 2.71828182845904523536

const int LINHA = 3;
const int COLUNA = 4;

using namespace std;

double calculoValorEmGraus(double graus) {
	return graus * PI / 180.0;
}

void printMatriz(double matriz[LINHA][COLUNA]) {
	for (int i = 0; i < LINHA; i++)
	{
		for (int j = 0; j < COLUNA; j++)
		{
			cout << matriz[i][j] << "	|	";
		}
		cout << endl;
	}
}

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

bool verificacaoCriterioDeSassenField(double matriz[LINHA][COLUNA])
{
	double resultadoFinalLinhas[LINHA] = { 0.0 },
		divisor = abs(matriz[0][0]);

	for (int indice = 1; indice < COLUNA - 1; indice++)
		resultadoFinalLinhas[0] += abs(matriz[0][indice]) / divisor;

	cout << resultadoFinalLinhas[0] << endl;

	for (int contadorLinha = 1; contadorLinha < LINHA; contadorLinha++)
	{
		divisor = abs(matriz[contadorLinha][contadorLinha]);

		for (int contadorColuna = 0; contadorColuna < COLUNA - 1; contadorColuna++)/// Arrumar por aqui
		{
			if (contadorColuna != contadorLinha)
			{
				for (; contadorColuna < contadorLinha; contadorColuna++)
					resultadoFinalLinhas[contadorLinha] += (resultadoFinalLinhas[contadorLinha - contadorColuna - 1] * abs(matriz[contadorLinha][contadorColuna])) / divisor;

				if (contadorColuna != contadorLinha)
					resultadoFinalLinhas[contadorLinha] += abs(matriz[contadorLinha][contadorColuna]) / divisor;
			}
		}

		cout << resultadoFinalLinhas[contadorLinha] << endl;
	}

	return *max_element(resultadoFinalLinhas, resultadoFinalLinhas + LINHA) < 1.0;
}


int main()
{
	double matriz[LINHA][COLUNA];
	double divisor = 0.0;

	//Valores da Matriz "matriz[][] = ;"
	matriz[0][0] = 5.0;
	matriz[0][1] = 1.0;
	matriz[0][2] = 1.0;
	matriz[0][3] = 5.0;
	matriz[1][0] = 3.0;
	matriz[1][1] = 4.0;
	matriz[1][2] = 1.0;
	matriz[1][3] = 6.0;
	matriz[2][0] = 3.0;
	matriz[2][1] = 3.0;
	matriz[2][2] = 6.0;
	matriz[2][3] = 0.0;
	//-------------------//

	verificacaoCriterioDeSassenField(matriz);


	printMatriz(matriz);
	cout << endl;

	system("PAUSE");
	return 0;
}


