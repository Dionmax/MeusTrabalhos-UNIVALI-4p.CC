// CalculoNumerico-FuncaoExponencial.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
#include <string>

#include <math.h>
#include <algorithm>

const int TAMANHO = 7;

const int LINHA = TAMANHO - 5,
COLUNA = TAMANHO - 4;

using namespace std;

void printMatriz(double matriz[LINHA][COLUNA]) {
	for (int i = 0; i < LINHA; i++)
	{
		for (int j = 0; j < COLUNA; j++)
		{
			cout << matriz[i][j] << "	|	";
			//printf("%i	|", matriz[i][j]);
		}
		cout << endl;
	}
}

int main()
{
	//cout.precision(2);

	double matriz[LINHA][COLUNA] = { 0 };

	double arrayX[TAMANHO] = { 0.2,0.3,0.4,0.5,0.6,0.7,0.8 },
		arrayY[TAMANHO] = { 3.16,2.38,1.75,1.34,1.0,0.74,0.56 },
		pivoTemporario = 0.0,
		divisor = 0.0;

	bool TrocaDeLinhas = false;

	int indiceParaTroca = 0;

	//Definindo matriz para a Reta;

	for (int linha = 0; linha < LINHA; linha++)
		for (int coluna = 0; coluna < COLUNA; coluna++)
			for (int contador = 0; contador < TAMANHO; contador++)
			{
				if (coluna != COLUNA - 1)
					matriz[linha][coluna] += pow(arrayX[contador], linha) * pow(arrayX[contador], coluna);
				else
					matriz[linha][coluna] += log(arrayY[contador]) * pow(arrayX[contador], linha);
			}

	printMatriz(matriz);

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
}
