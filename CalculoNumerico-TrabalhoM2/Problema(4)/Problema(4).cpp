// Problema(4).cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
#include <string>

#include <math.h>
#include <algorithm>

const int LINHA = 8;

using namespace std;

int main()
{
	long double divisor = 0.0,
		X = 1730.0,
		arrayX[LINHA] = { 500.0 ,1000.0 ,1500.0 ,2000.0 ,2500.0 ,3000.0 ,3500.0 ,4000.0 },
		arrayFX[LINHA] = { 2.74, 5.48, 7.90 , 11.00, 13.93, 16.43, 20.24, 23.52 },
		arrayDk[LINHA] = { 1.0, 1.0,1.0, 1.0,1.0 , 1.0 , 1.0 , 1.0 },
		Xfinal = 1.0,
		saida = 0.0;

	for (int linha = 0; linha < LINHA; linha++)
	{
		for (int coluna = 0; coluna < LINHA; coluna++)
		{
			if (coluna != linha)
				arrayDk[linha] *= (arrayX[linha] - arrayX[coluna]);
			else
				arrayDk[linha] *= (X - arrayX[linha]);
		}

		Xfinal *= (X - arrayX[linha]);
		saida += (arrayFX[linha] / arrayDk[linha]);

		cout << "Saida: " << saida << endl;
		cout << "X: " << Xfinal << endl;
		cout << endl;
	}

	cout << "Valor final no ponto " << X << " : " << saida * Xfinal << endl;

	cout << endl;

	system("PAUSE");
}
