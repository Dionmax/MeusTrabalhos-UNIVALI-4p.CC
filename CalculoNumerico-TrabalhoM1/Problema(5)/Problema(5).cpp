// Problema(5).cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

#define PI 3.14159265358979323846
#define Euler 2.71828182845904523536

const int LINHA = 5;
const int COLUNA = 6;

using namespace std;

void printMatriz(double matriz[LINHA][COLUNA]) {
	for (int i = 0; i < LINHA; i++)
	{
		for (int j = 0; j < COLUNA; j++)
		{
			cout << "	" << matriz[i][j] << "	|";
		}
		cout << endl;
	}
}

int main()
{
	double matriz[LINHA][COLUNA];
	double divisor = 0.0;

	//Valores da Matriz "matriz[][] = ;"
	matriz[0][0] = 1.0;
	matriz[0][1] = 0.0;
	matriz[0][2] = 2.0;
	matriz[0][3] = 3.0;
	matriz[0][4] = 2.0;
	matriz[0][5] = 27.0;

	matriz[1][0] = 1.0;
	matriz[1][1] = 1.0;
	matriz[1][2] = 1.0;
	matriz[1][3] = 2.0;
	matriz[1][4] = 1.0;
	matriz[1][5] = 23.0;

	matriz[2][0] = 1.0;
	matriz[2][1] = 2.0;
	matriz[2][2] = 1.0;
	matriz[2][3] = 1.0;
	matriz[2][4] = 2.0;
	matriz[2][5] = 31.0;

	matriz[3][0] = 0.0;
	matriz[3][1] = 1.0;
	matriz[3][2] = 2.0;
	matriz[3][3] = 2.0;
	matriz[3][4] = 3.0;
	matriz[3][5] = 31.0;

	matriz[4][0] = 2.0;
	matriz[4][1] = 1.0;
	matriz[4][2] = 0.0;
	matriz[4][3] = 1.0;
	matriz[4][4] = 1.0;
	matriz[4][5] = 22.0;
	//-------------------//

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

