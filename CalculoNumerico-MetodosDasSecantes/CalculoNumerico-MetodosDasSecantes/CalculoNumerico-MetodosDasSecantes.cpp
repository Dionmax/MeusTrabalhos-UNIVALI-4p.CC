// CalculoNumerico-MetodosDasSecantes.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

#define Euler 2.71828182845904523536

using namespace std;

int main()
{
	double Xn = 2.0;
	double XnAnterior = 1.0;
	double Fx;
	double FxAnterior;
	double E = 1.0;
	double Error = pow(10, -3);

	// F(x) = Raiz(x) -5 e^-x

	//Xn+1 = [Xn-1 * F(Xn) - Xn * F(Xn-1)] / [F(Xn) - F(Xn-1)]

	for (int indice = 0; E > Error; indice++)
	{
		FxAnterior = sqrt(XnAnterior) - (5 * pow(Euler, -XnAnterior));

		Fx = sqrt(Xn) - (5 * pow(Euler, -Xn));

		double aux = Xn;

		Xn = ((XnAnterior * Fx) - (Xn * FxAnterior)) / (Fx - FxAnterior);

		XnAnterior = aux;

		if (indice > 1)
			E = fabs((Xn - XnAnterior) / Xn);

		cout << "N: " << indice << "	X:" << Xn << "	X-1: " << XnAnterior << "	FX: " << Fx <<
			"	F(x-1): " << FxAnterior << "	E: " << E << endl;
	}

	cin.get();
	return 0;
}

