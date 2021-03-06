// CalculoNumerico-MetodoDeGaussJocobi.cpp : define o ponto de entrada para o aplicativo do console.
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
const double ERROR = pow(10, -10);

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

int main()
{
	double matriz[LINHA][COLUNA];

	//Valores da Matriz "matriz[][] = ;"
	matriz[0][0] = 10.0;
	matriz[0][1] = 2.0;
	matriz[0][2] = 1.0;
	matriz[0][3] = 7.0;
	matriz[1][0] = 1.0;
	matriz[1][1] = 5.0;
	matriz[1][2] = 1.0;
	matriz[1][3] = -8.0;
	matriz[2][0] = 2.0;
	matriz[2][1] = 3.0;
	matriz[2][2] = 10.0;
	matriz[2][3] = 6.0;
	//-------------------/

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
			cout << "X" << indice << ": " << arrayXAnterior[indice] << endl;
		cout << endl;

	} while (error > ERROR);

	cout << endl;
	cout <<"Error: " << error << endl;

	system("PAUSE");
	return 0;
}

