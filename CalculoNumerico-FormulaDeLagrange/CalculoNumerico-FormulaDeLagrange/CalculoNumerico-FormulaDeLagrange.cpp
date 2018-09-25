// CalculoNumerico-FormulaDeLagrange.cpp : define o ponto de entrada para o aplicativo do console.
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
	double matriz[LINHA][COLUNA];

	//Valores da Matriz "matriz[][] = ;"
	matriz[0][0] = 1.0;
	matriz[0][1] = -1.0;
	matriz[0][2] = 1.0;
	matriz[0][3] = 15.0;
	matriz[1][0] = 0.0;
	matriz[1][1] = 4.0;
	matriz[1][2] = 8.0;
	matriz[1][3] = 16.0;
	matriz[2][0] = 0.0;
	matriz[2][1] = 1.0;
	matriz[2][2] = -1.0;
	matriz[2][3] = -7.0;
	//-------------------//

	double divisor = 0.0,
		X = 2.0,
		arrayX[LINHA] = { -1.0,0.0,3.0 },
		arrayFX[LINHA] = { 15.0,8.0,-1.0 },
		arrayDk[LINHA] = { 1.0, 1.0,1.0 },
		Xfinal = 1.0,
		saida = 0.0;

	for (int linha = 0; linha < LINHA; linha++)
	{
		for (int coluna = 0; coluna < COLUNA - 1; coluna++)
		{
			if (coluna != linha)
				arrayDk[linha] *= (arrayX[linha] - arrayX[coluna]);
			else
				arrayDk[linha] *= (X - arrayX[linha]);
		}
		Xfinal *= (X - arrayX[linha]);

		//saida += (arrayFX[linha] / arrayDk[linha]);
	}

	for (int indice = LINHA - 1; indice >= 0; indice--)
		saida += (arrayFX[indice] / arrayDk[indice]);

	cout << "Valor final: " << saida << endl;

	system("PAUSE");
	return 0;
}

