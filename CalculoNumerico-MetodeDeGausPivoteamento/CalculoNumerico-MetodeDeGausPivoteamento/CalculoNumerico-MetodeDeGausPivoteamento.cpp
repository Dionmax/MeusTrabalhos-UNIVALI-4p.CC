// CalculoNumerico-MetodeDeGausPivoteamento.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include <math.h>

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

int main()
{
	double matriz[LINHA][COLUNA],
		pivoTemporario = 0.0,
		divisor = 0.0;

	bool TrocaDeLinhas = false;

	int indiceParaTroca = 0;

	//Valores da Matriz "matriz[][] = ;"
	matriz[0][0] = 4.0;
	matriz[0][1] = 2.0;
	matriz[0][2] = 6.0;
	matriz[0][3] = 6.0;
	matriz[1][0] = 2.0;
	matriz[1][1] = 6.0;
	matriz[1][2] = 8.0;
	matriz[1][3] = 14.0;
	matriz[2][0] = 6.0;
	matriz[2][1] = 8.0;
	matriz[2][2] = 18.0;
	matriz[2][3] = 28.0;
	

	//-------------------//

	printMatriz(matriz);
	cout << endl;

	for (int L = 0; L < LINHA; L++) {

		pivoTemporario = matriz[L][L];

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
	cout << endl;

	system("PAUSE");
	return 0;

}


