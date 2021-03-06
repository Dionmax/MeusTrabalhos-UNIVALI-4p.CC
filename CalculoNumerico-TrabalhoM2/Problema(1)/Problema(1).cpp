// Problema(1).cpp : define o ponto de entrada para o aplicativo do console.

#include "stdafx.h"
#include <iostream>
#include <string>

#include <math.h>

const int LINHA = 10;
const int COLUNA = 11;

using namespace std;

void printMatriz(long double matriz[LINHA][COLUNA]) {
	for (int i = 0; i < LINHA; i++)
	{
		for (int j = 0; j < COLUNA; j++)
		{
			cout << matriz[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	//cout.precision(2);

	long double matriz[LINHA][COLUNA] =
	{ 2,	1,	7,	4, -3, -1,	4,	4,	7,	0,	86,
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

	double divisor = 0.0,
		pivoTemporario = 0.0;

	int indiceParaTroca = 0;
	bool TrocaDeLinhas = false;

	printMatriz(matriz);

	for (int L = 0; L < LINHA; L++) {

		pivoTemporario = abs(matriz[L][L]);

		//COMEÇO DO PIVOTEAMENTO
		for (int numeroLinha = L; numeroLinha < LINHA; numeroLinha++)
			if (pivoTemporario < abs(matriz[numeroLinha][L])) {
				indiceParaTroca = numeroLinha;
				pivoTemporario = abs(matriz[numeroLinha][L]);
				TrocaDeLinhas = true;
			}

		if (TrocaDeLinhas) {

			cout << endl << "---------------------- TROCANDO LINHAS pt1 --------------------- L: " << L << endl;
			printMatriz(matriz);
			cout << endl;

			for (int contador = 0; contador < COLUNA; contador++)
			{
				double aux = matriz[L][contador];
				matriz[L][contador] = matriz[indiceParaTroca][contador];
				matriz[indiceParaTroca][contador] = aux;
			}

			TrocaDeLinhas = false;

			printMatriz(matriz);
			cout << endl;
			cout << "--------------------------------------------------------" << endl;

			//system("PAUSE");
		}

		//Fim de Pivoteamento

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
		//Parte dois -----------
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
	cout << endl;


	for (int i = 0; i < LINHA; i++)
		cout << " X" << i << " = " << matriz[i][COLUNA - 1] << endl;


	cout << endl;
	system("PAUSE");
	return 0;
}

