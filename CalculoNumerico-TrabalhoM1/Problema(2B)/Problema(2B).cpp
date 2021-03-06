// Problema(2B).cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

#define Euler 2.71828182845904523536
#define PI 3.14159265358979323846

using namespace std;

double calculoValorEmGraus(double graus) {
	return graus * PI / 180.0;
}

int main()
{
	double A = 13.0;
	double B = 14.0;
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
		FxA = (sin(A) * cos(A)) / (1.25 - pow(cos(A), 2)) - 0.8391;
		FxB = (sin(B) * cos(B)) / (1.25 - pow(cos(B), 2)) - 0.8391;

		XnAnterior = Xn;

		Xn = (A * FxB - B * FxA) / (FxB - FxA);

		FxX = (sin(Xn) * cos(Xn)) / (1.25 - pow(cos(Xn), 2)) - 0.8391;

		if (FxA*FxX < 0)
			B = Xn;
		else
			A = Xn;

		if (i != 0)
			E = fabs((Xn - XnAnterior) / Xn);

		cout << "i:" << i << "	A:" << A << "	B:" << B <<
			"	X:" << Xn << "	F(a):" << FxA << "	F(b):" << FxB << "	F(X" << i << "):" << FxX << "	E:" << E << endl;

	}

	cin.get();
	return 0;
}

