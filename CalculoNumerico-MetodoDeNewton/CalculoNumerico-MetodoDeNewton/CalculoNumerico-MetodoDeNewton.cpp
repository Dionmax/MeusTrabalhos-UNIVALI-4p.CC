// CalculoNumerico-MetodoDeNewton.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

#define Euler 2.71828182845904523536

using namespace std;

// F(x) = 4 cos x - e^x
// DF(x) = -4 sin x - e ^ x

int main()
{
	double X = 0.5;
	double XAnterior;
	double Fx;
	double DFx;
	double E = 1.0;
	double Error = pow(10, -20);

	for (int i = 0; E > Error; i++)
	{
		Fx = (4 * cos(X)) - (pow(Euler, X));

		DFx = (-4 * sin(X)) - (pow(Euler, X));

		XAnterior = X;

		X -= Fx / DFx;

		if (i != 0)
			E = fabs((X - XAnterior) / X);

		cout << "X:" << X << "	F(x):" << Fx << "	F'(x):" << DFx << "	Error:" << E << endl;
	}

	cin.get();
	return 0;
}

