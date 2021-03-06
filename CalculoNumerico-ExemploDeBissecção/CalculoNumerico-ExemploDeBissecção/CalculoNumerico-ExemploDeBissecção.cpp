// CalculoNumerico-ExemploDeBissecção.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	double A = 0.0;
	double B = 1.0;
	double Xn = 0;
	double Fxn;
	double XnAnterior;
	double Fa;
	double E = 1.0;
	double Error = pow(10, -5);

	for (int i = 0; E > Error; i++) {

		Fa = pow(A, 3) - (9 * A) + 3;

		XnAnterior = Xn;

		Xn = (A + B) / 2;

		Fxn = pow(Xn, 3) - (9 * Xn) + 3;

		if (Fa*Fxn < 0)
			B = Xn;
		else
			A = Xn;

		if (i != 0)
			E = fabs((Xn - XnAnterior) / Xn);

		cout << "i:" << i << "	A:" << A << "	B:" << B << "	X:" << Xn << "	F(a):" << Fa << "	F(X" << i << "):" << Fxn << "	E:" << E << endl << endl;

	}

	cin.get();

	return 0;
}

