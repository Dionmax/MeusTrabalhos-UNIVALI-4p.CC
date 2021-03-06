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

bool verificacaoCriterioDeSassenField(double matriz[LINHA][COLUNA])
{
	double resultadoFinalLinhas[LINHA] = { 0.0 },
		divisor = abs(matriz[0][0]);

	for (int indice = 1; indice < COLUNA - 1; indice++)
		resultadoFinalLinhas[0] += abs(matriz[0][indice]) / divisor;

	for (int contadorLinha = 1; contadorLinha < LINHA; contadorLinha++)
	{
		divisor = abs(matriz[contadorLinha][contadorLinha]);

		for (int contadorColuna = 0; contadorColuna < COLUNA - 1; contadorColuna++)
		{
			if (contadorColuna != contadorLinha)
			{
				for (; contadorColuna < contadorLinha; contadorColuna++)
					resultadoFinalLinhas[contadorLinha] += (resultadoFinalLinhas[contadorLinha - contadorColuna - 1] * abs(matriz[contadorLinha][contadorColuna])) / divisor;

				if (contadorColuna != contadorLinha)
					resultadoFinalLinhas[contadorLinha] += abs(matriz[contadorLinha][contadorColuna]) / divisor;
			}
		}
	}

	return *max_element(resultadoFinalLinhas, resultadoFinalLinhas + LINHA) < 1.0;
}


int main()
{
	double matriz[LINHA][COLUNA];

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

	double divisor = 0.0,
		arrayXAnterior[LINHA],
		arrayX[LINHA] = { 0.0 },
		arrayDistancia[LINHA],
		error = 0.0;

	//Calculo dos valores inicais
	for (int calculoInicial = 0; calculoInicial < LINHA; calculoInicial++) {
		arrayX[calculoInicial] = matriz[calculoInicial][COLUNA - 1] / matriz[calculoInicial][calculoInicial];
		arrayXAnterior[calculoInicial] = arrayX[calculoInicial];
	}

	do
	{
		for (int linha = 0; linha < LINHA; linha++)
		{
			double acumulador = 0.0;

			divisor = 1.0 / matriz[linha][linha];

			for (int coluna = 0; coluna < COLUNA - 1; coluna++)
			{
				if (coluna != linha)
					acumulador += matriz[linha][coluna] * arrayX[coluna];
			}

			arrayX[linha] = divisor * (matriz[linha][COLUNA - 1] - acumulador);
		}

		//Calculo do erro!
		for (int indice = 0; indice < LINHA; indice++) {
			arrayDistancia[indice] = abs(arrayX[indice] - arrayXAnterior[indice]);
			arrayXAnterior[indice] = abs(arrayX[indice]);
		}

		error = (*max_element(arrayDistancia, arrayDistancia + LINHA)) / (*max_element(arrayXAnterior, arrayXAnterior + LINHA));

		//Printando os valores de X e recupando o valor do X anterior
		for (int indice = 0; indice < LINHA; indice++) {
			arrayXAnterior[indice] = arrayX[indice];
			cout << "X" << indice << ": " << arrayX[indice] << endl;
		}

		cout << endl <<"Error: "<< error << endl << endl;

	} while (error > ERROR);

	system("PAUSE");
	return 0;
}


