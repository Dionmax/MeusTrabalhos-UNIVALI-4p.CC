// CalculoNumero-MetodoDaFalsaDuracao.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main()
{
	double A = 2.0;
	double B = 3.0;
	double Xn = 0.0;
	double FxA;
	double FxB;
	double FxX;
	double XnAnterior;
	double E = 1.0;
	double Error = pow(10, -5);

	// F(x) = X log (x) - 1 = 0

	for (int i = 0; E > Error; i++)
	{
		FxA = A * log10(A) - 1;
		FxB = B * log10(B) - 1;

		XnAnterior = Xn;

		Xn = (A * FxB - B * FxA) / (FxB - FxA);

		FxX = Xn * log10(Xn) - 1;

		if (FxA*FxX < 0)
			B = Xn;
		else
			A = Xn;

		if (i != 0)
			E = fabs((Xn - XnAnterior) / Xn);

		cout << "i:" << i << "	A:" << A << "	B:" << B <<
			"	X:" << Xn << "	F(a):" << FxA << "	F(b):" << FxB << "	F(X" << i << "):" << FxX << "	E:" << E <<endl;

	}

	cin.get();
	return 0;
}

