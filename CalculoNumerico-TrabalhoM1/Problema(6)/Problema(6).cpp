// Problema(6).cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

#define PI 3.14159265358979323846
#define Euler 2.71828182845904523536

const int LINHA = 9;
const int COLUNA = 10;

using namespace std;

void printMatriz(double long matriz[LINHA][COLUNA]) {
	for (int i = 0; i < LINHA; i++)
	{
		for (int j = 0; j < COLUNA; j++)
		{
			cout << "" << matriz[i][j] << "	|";
		}
		cout << endl;
	}
}

int main()
{
	double long divisor = 0.0;

	double long matriz[LINHA][COLUNA] =

	{ -4,1,0,1,0,0,0,0,0,0,
	1,-4,1,0,1,0,0,0,0,0,
	0,1,-4,0,0,1,0,0,0,0,
	1,0,0,-4,1,0,1,0,0,0,
	0,1,0,1,-4,1,0,1,0,0,
	0,0,1,0,1,-4,0,0,1,0,
	0,0,0,1,0,0,-4,1,0,-1,
	0,0,0,0,1,0,1,-4,1,-1,
	0,0,0,0,0,1,0,1,-4,-1 };

	printMatriz(matriz);
	cout << endl;

	for (int L = 0; L < LINHA; L++) {

		for (int indice = LINHA - 1; indice > L; indice--)
		{
			divisor = matriz[indice][L] / matriz[L][L];

			for (int percorrerLinha = 0; percorrerLinha < COLUNA; percorrerLinha++) {
				matriz[indice][percorrerLinha] = matriz[indice][percorrerLinha] - (divisor * matriz[L][percorrerLinha]);
			}
			//printMatriz(matriz);
			//cout << endl;
		}
	}

	for (int L = LINHA - 1; L > 0; L--)
	{
		for (int indice = L - 1; indice > -1; indice--)
		{
			divisor = matriz[indice][L] / matriz[L][L];

			for (int percorrerLinha = 0; percorrerLinha < COLUNA; percorrerLinha++) {
				matriz[indice][percorrerLinha] = matriz[indice][percorrerLinha] - (divisor * matriz[L][percorrerLinha]);
			}
			//printMatriz(matriz);
			//cout << endl;
		}
	}

	printMatriz(matriz);

	cout << endl << "Normalizada" << endl;

	for (int L = 0; L < LINHA; L++) {

		divisor = matriz[L][L];

		for (int coluna = 0; coluna < COLUNA; coluna++) {
			matriz[L][coluna] /= divisor;
		}
	}

	printMatriz(matriz);
	cout << endl;

	system("PAUSE");
	return 0;
}

