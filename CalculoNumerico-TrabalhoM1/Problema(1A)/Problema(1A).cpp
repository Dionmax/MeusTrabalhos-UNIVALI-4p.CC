// Problema(1A).cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

#define Euler 2.71828182845904523536

using namespace std;

int main()
{
	double A = 1.0;
	double B = 2.0;
	double Xn = 0;
	double Fxn;
	double XnAnterior;
	double Fa;
	double E = 1.0;
	double Error = pow(10, -5);

	for (int i = 0; E > Error; i++) {

		Fa = (0.9 - (1 + A + (pow(A, 2) / 2)) * pow(Euler, -A));

		XnAnterior = Xn;

		Xn = (A + B) / 2;

		Fxn = (0.9 - (1 + Xn + (pow(Xn, 2) / 2)) * pow(Euler, -Xn));

		if (Fa*Fxn < 0)
			B = Xn;
		else
			A = Xn;

		if (i != 0)
			E = fabs((Xn - XnAnterior) / Xn);

		cout << "i:" << i << "	A:" << A << "	B:" << B << "	X:" << Xn << "	F(a):" << Fa << "	F(X" << i << "):" << Fxn << "	E:" << E << endl;

	}

	cin.get();
	return 0;
}

