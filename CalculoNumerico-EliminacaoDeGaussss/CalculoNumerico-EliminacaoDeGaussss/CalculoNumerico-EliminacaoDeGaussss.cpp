// CalculoNumerico-EliminacaoDeGaussss.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include <math.h>

#define PI 3.14159265358979323846
#define Euler 2.71828182845904523536

const int LINHA = 10;
const int COLUNA = 11;

using namespace std;

double calculoValorEmGraus(double graus) {
	return graus * PI / 180.0;
}

void printMatriz(double matriz[LINHA][COLUNA]) {
	for (int i = 0; i < LINHA; i++)
	{
		for (int j = 0; j < COLUNA; j++)
		{
			cout << matriz[i][j] << "|	";
		}
		cout << endl;
	}
}
int main() {

	cout.precision(6);

	double divisor = 0.0;

	////Valores da Matriz "matriz[][] = ;"
	//matriz[0][0] = 1.0;
	//matriz[0][1] = 0.0;
	//matriz[0][2] = 3.0;
	//matriz[0][3] = 6.0;
	//matriz[1][0] = -3.0;
	//matriz[1][1] = -5.0;
	//matriz[1][2] = 7.0;
	//matriz[1][3] = 7.0;
	//matriz[2][0] = 2.0;
	//matriz[2][1] = 4.0;
	//matriz[2][2] = 0.0;
	//matriz[2][3] = 15.0;
	////-------------------//

	double matriz[LINHA][COLUNA] = {
		2,	1,	7,	4, -3, -1,	4,	4,	7,	0,	86,
		4,	2,	2,	3, -2,	0,	3,	3,	4,	1,	45,
		3,	4,	4,	2,	1, -2,	2,	1,	9, -3,	52.5,
		9,	3,	5,	1,	0,	5,	5, -5, -3,	4,	108,
		2,	0,	7,	0, -5,	7,	1,	0,	1,	6,	66.5,
		1,	9,	8,	0,	3,	9,	9,	0,	0,	5,	90.5,
		4,	1,	9,	0,	4,	3,	7, -4,	1,	3,	139,
		6,	3,	1,	1,	6,	8,	3,	3,	0,	2,	61,
		6,	5,	0, -7,	7, -7,	6,	2, -6,	1,	 -43.5,
		1,	6,	3,	4,	8,	3, -5,	0, -6,	0,	31
	};

	printMatriz(matriz);
	cout << endl;

	for (int L = 0; L < LINHA; L++) {

		for (int indice = LINHA - 1; indice > L; indice--)
		{
			if (matriz[L][L] == 0) {
				cout << "Ocorreu divisao por zero, tente outro metodo." << endl;
				divisor = matriz[indice][L];
				system("PAUSE");
			}
			else
				divisor = matriz[indice][L] / matriz[L][L];

			for (int percorrerLinha = 0; percorrerLinha < COLUNA; percorrerLinha++) {
				matriz[indice][percorrerLinha] = (matriz[indice][percorrerLinha] - (divisor * matriz[L][percorrerLinha]));
			}
			printMatriz(matriz);
			cout << endl;
		}
	}

	for (int L = LINHA - 1; L > 0; L--)
	{
		for (int indice = L - 1; indice > -1; indice--)
		{
			if (matriz[L][L] == 0) {
				cout << "Ocorreu divisao por zero, tente outro metodo." << endl;
				divisor = matriz[indice][L];
				system("PAUSE");
			}
			else
				divisor = matriz[indice][L] / matriz[L][L];

			for (int percorrerLinha = 0; percorrerLinha < COLUNA; percorrerLinha++) {
				matriz[indice][percorrerLinha] = (matriz[indice][percorrerLinha] - (divisor * matriz[L][percorrerLinha]));
			}
			printMatriz(matriz);
			cout << endl;
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

