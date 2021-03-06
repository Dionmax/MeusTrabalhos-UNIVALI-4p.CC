// Problema(3B).cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

#define Euler 2.71828182845904523536

using namespace std;

int main()
{
	double D = 21.5;
	double Q = 122.3;
	double Xn = 1.0;
	double XnAnterior = 0.0;
	double Fx = 0.0;
	double FxAnterior = 0.0;
	double E = 1.0;
	double Error = pow(10, -5);

	for (int indice = 0; E > Error; indice++)
	{

		Fx = (pow((1.49 / 0.030), 3)*pow(D, 5)*pow(0.0001, 3 / 2))*pow(Xn, 5) - 4 * pow(Q, 3)*pow(Xn, 2) - 4 * pow(Q, 3) * D * Xn - pow(Q, 3)*pow(D, 2);

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

