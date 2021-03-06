// CalculoNumerico-MetodosMinimosQuadrados.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
#include <string>

#include <math.h>
#include <algorithm>

const int TAMANHO = 4; 

using namespace std;

void parabola()
{
	const int LINHA = TAMANHO - 1,
		COLUNA = TAMANHO;

	double matriz[LINHA][COLUNA] = { 0 },
		pivoTemporario = 0.0,
		divisor = 0.0;

	bool TrocaDeLinhas = false;

	int indiceParaTroca = 0;;

	double arrayX[TAMANHO] = { -1,0,1,2 },
		arrayY[TAMANHO] = { 0,-1,0,7 };

	//Definindo matriz para a Reta;

	for (int linha = 0; linha < LINHA; linha++)
		for (int coluna = 0; coluna < COLUNA; coluna++)
			for (int contador = 0; contador < TAMANHO; contador++)
			{
				if (coluna != COLUNA - 1)
					matriz[linha][coluna] += pow(arrayX[contador], linha) * pow(arrayX[contador], coluna);
				else
					matriz[linha][coluna] += arrayY[contador] * pow(arrayX[contador], linha);
			}

	//Imprimindo Matriz
	for (int i = 0; i < LINHA; i++)
	{
		for (int j = 0; j < COLUNA; j++)
		{
			cout << matriz[i][j] << "	|	";
		}
		cout << endl;
	}

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

			for (int contador = 0; contador < COLUNA; contador++)
			{
				double aux = matriz[L][contador];
				matriz[L][contador] = matriz[indiceParaTroca][contador];
				matriz[indiceParaTroca][contador] = aux;
			}

			TrocaDeLinhas = false;

		}

		//Parte Um --------
		for (int indice = L + 1; indice < LINHA; indice++)
		{
			divisor = matriz[indice][L] / matriz[L][L];

			for (int percorrerLinha = 0; percorrerLinha < COLUNA; percorrerLinha++) {
				matriz[indice][percorrerLinha] = matriz[indice][percorrerLinha] - (divisor * matriz[L][percorrerLinha]);
			}
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
		}
	}

	cout << endl << "Normalizada" << endl;

	for (int L = 0; L < LINHA; L++) {

		divisor = matriz[L][L];

		for (int coluna = 0; coluna < COLUNA; coluna++) {
			matriz[L][coluna] /= divisor;
		}
	}

	//Imprimindo Matriz
	for (int i = 0; i < LINHA; i++)
	{
		for (int j = 0; j < COLUNA; j++)
		{
			cout << matriz[i][j] << "	|	";
		}
		cout << endl;
	}

	//Forma sem estress de montar a formula
	cout << endl;
	cout << "Y = (" << matriz[0][COLUNA - 1] << ") ";
	for (int indice = 1; indice < LINHA; indice++)
		cout << "+ (" << matriz[indice][COLUNA - 1] << ")X^" << indice << " ";

	cout << endl;
}

void reta()
{
	const int LINHA = TAMANHO - 2,
		COLUNA = TAMANHO - 1;

	double matriz[LINHA][COLUNA] = { 0 },
		pivoTemporario = 0.0,
		divisor = 0.0;

	bool TrocaDeLinhas = false;

	int indiceParaTroca = 0;;

	double arrayX[TAMANHO] = { -1,0,1,2 },
		arrayY[TAMANHO] = { 0,-1,0,7 };

	//Definindo matriz para a Reta;

	for (int linha = 0; linha < LINHA; linha++)
		for (int coluna = 0; coluna < COLUNA; coluna++)
			for (int contador = 0; contador < TAMANHO; contador++)
			{
				if (coluna != COLUNA - 1)
					matriz[linha][coluna] += pow(arrayX[contador], linha) * pow(arrayX[contador], coluna);
				else
					matriz[linha][coluna] += arrayY[contador] * pow(arrayX[contador], linha);
			}

	//Imprimindo Matriz
	for (int i = 0; i < LINHA; i++)
	{
		for (int j = 0; j < COLUNA; j++)
		{
			cout << matriz[i][j] << "	|	";
		}
		cout << endl;
	}

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

			for (int contador = 0; contador < COLUNA; contador++)
			{
				double aux = matriz[L][contador];
				matriz[L][contador] = matriz[indiceParaTroca][contador];
				matriz[indiceParaTroca][contador] = aux;
			}

			TrocaDeLinhas = false;

		}

		//Parte Um --------
		for (int indice = L + 1; indice < LINHA; indice++)
		{
			divisor = matriz[indice][L] / matriz[L][L];

			for (int percorrerLinha = 0; percorrerLinha < COLUNA; percorrerLinha++) {
				matriz[indice][percorrerLinha] = matriz[indice][percorrerLinha] - (divisor * matriz[L][percorrerLinha]);
			}
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
		}
	}

	cout << endl << "Normalizada" << endl;

	for (int L = 0; L < LINHA; L++) {

		divisor = matriz[L][L];

		for (int coluna = 0; coluna < COLUNA; coluna++) {
			matriz[L][coluna] /= divisor;
		}
	}

	//Imprimindo Matriz
	for (int i = 0; i < LINHA; i++)
	{
		for (int j = 0; j < COLUNA; j++)
		{
			cout << matriz[i][j] << "	|	";
		}
		cout << endl;
	}

	//Forma sem estress de montar a formula
	cout << endl;
	cout << "Y = (" << matriz[0][COLUNA - 1] << ") ";
	for (int indice = 1; indice < LINHA; indice++)
		cout << "+ (" << matriz[indice][COLUNA - 1] << ")X^" << indice << " ";

	cout << endl;
}

int main()
{
	reta();

	cout << endl;
	cout << endl;

	parabola();
}
