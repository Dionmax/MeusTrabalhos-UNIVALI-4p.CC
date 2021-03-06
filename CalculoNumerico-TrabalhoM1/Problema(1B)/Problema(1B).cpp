// Problema(1B).cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

#define Euler 2.71828182845904523536

using namespace std;

int main()
{
	double A = 5.0;
	double B = 6.0;
	double Xn = 0.0;
	double FxA;
	double FxB;
	double FxX;
	double XnAnterior;
	double E = 1.0;
	double Error = pow(10, -5);

	// F(x) = (0.1 - (1 + A + (pow(A, 2) / 2)) * pow(Euler, -A));

	for (int i = 0; E > Error; i++)
	{
		FxA = (0.1 - (1 + A + (pow(A, 2) / 2)) * pow(Euler, -A));
		FxB = (0.1 - (1 + B + (pow(B, 2) / 2)) * pow(Euler, -B));

		XnAnterior = Xn;

		Xn = (A * FxB - B * FxA) / (FxB - FxA);

		FxX = (0.1 - (1 + Xn + (pow(Xn, 2) / 2)) * pow(Euler, -Xn));

		if (FxA*FxX < 0)
			B = Xn;
		else
			A = Xn;

		if (i != 0)
			E = fabs((Xn - XnAnterior) / Xn);

		cout << "i:" << i << "	A:" << A << "	B:" << B <<
			"	X(" << i << "):" << Xn << "	F(a):" << FxA << "	F(b):" << FxB << "	F(X" << i << "):" << FxX << "	E:" << E << endl;

	}

	cin.get();
	return 0;
}

