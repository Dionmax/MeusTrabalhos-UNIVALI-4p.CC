// CalculoNumerico-InterpolacaoPolinomial.cpp : define o ponto de entrada para o aplicativo do console.
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

int main()
{
	double
		matriz[LINHA][COLUNA] = { 0 },
		arrayX[LINHA] = { -1,0,3 },
		arrayFX[LINHA] = { 15 , 8 , -1 },
		divisor = 0.0;

	//Gerando matriz através dos pontos dados;
	for (int linha = 0; linha < LINHA; linha++) {
		for (int coluna = 0; coluna < COLUNA - 1; coluna++)
		{
			matriz[linha][coluna] += 1 * pow(arrayX[linha], coluna);
		}
		matriz[linha][COLUNA - 1] = arrayFX[linha];
	}

	// Reciclando o Pivoteamento 
	for (int L = 0; L < LINHA; L++) {

		//COMEÇO DO PIVOTEAMENTO
		for (int numeroLinha = 0; numeroLinha < LINHA - 1; numeroLinha++)
			if (abs(matriz[L][L]) < abs(matriz[numeroLinha + 1][L]) && L < LINHA - 1) {

				cout << endl << "---------------------- TROCANDO LINHAS pt1 --------------------- L: " << L << endl;
				printMatriz(matriz);
				cout << endl;

				for (int contador = 0; contador < COLUNA; contador++)
				{
					double aux = matriz[L][contador];
					matriz[L][contador] = matriz[L + 1][contador];
					matriz[L + 1][contador] = aux;
				}

				printMatriz(matriz);
				cout << endl;
				cout << "--------------------------------------------------------" << endl;
			}

		//Parte Um --------
		for (int indice = L + 1; indice < LINHA; indice++)
		{
			divisor = matriz[indice][L] / matriz[L][L];

			for (int percorrerLinha = 0; percorrerLinha < COLUNA; percorrerLinha++) {
				matriz[indice][percorrerLinha] = matriz[indice][percorrerLinha] - (divisor * matriz[L][percorrerLinha]);
			}
			printMatriz(matriz);
			cout << endl;
		}
	}


	for (int L = LINHA - 1; L > 0; L--)
	{
		// Parte dois -----------
		for (int indice = 0; indice < L; indice++)
		{
			divisor = matriz[indice][L] / matriz[L][L];

			for (int percorrerLinha = 0; percorrerLinha < COLUNA; percorrerLinha++) {
				matriz[indice][percorrerLinha] = matriz[indice][percorrerLinha] - (divisor * matriz[L][percorrerLinha]);
			}
			printMatriz(matriz);
			cout << endl;
		}
	}


	cout << endl << "Normalizada" << endl;

	for (int L = 0; L < LINHA; L++) {

		divisor = matriz[L][L];

		for (int coluna = 0; coluna < COLUNA; coluna++) {
			matriz[L][coluna] /= divisor;
		}
	}

	printMatriz(matriz);

	//Forma sem estress de montar a formula
	cout << endl;
	cout << "P2(X) = (" << matriz[0][COLUNA - 1] << ") ";
	for (int indice = 1; indice < LINHA; indice++)
		cout << "+ (" << matriz[indice][COLUNA - 1] << ")X^" << indice << " ";

	cout << endl << endl;

	system("PAUSE");
	return 0;
}
