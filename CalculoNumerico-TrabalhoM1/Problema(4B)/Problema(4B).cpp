// Problema(4B).cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

#define Euler 2.71828182845904523536

using namespace std;

int main()
{
	double Xn = -5;
	double XnAnterior = 1.0;
	double Fx = 0;
	double FxAnterior = 0;
	double E = 1.0;
	double Error = pow(10, -5);

	for (int indice = 0; E > Error; indice++)
	{

		Fx = 37.104740 + 3.15122*Xn - ((2 * pow(Xn, 2)) / 2);

		if (indice > 1)
			E = fabs((Xn - XnAnterior) / Xn);

		cout << "K: " << indice << "	Xn:" << Xn << "	FX': ---- " << "	FX: " << Fx << "	E: " << E << endl;

		double aux = Xn;

		if (indice >= 1)
			Xn = ((XnAnterior * Fx) - (Xn * FxAnterior)) / (Fx - FxAnterior);
		else
			Xn++;

		XnAnterior = aux;

		FxAnterior = Fx;
	}

	cin.get();
    return 0;
}

