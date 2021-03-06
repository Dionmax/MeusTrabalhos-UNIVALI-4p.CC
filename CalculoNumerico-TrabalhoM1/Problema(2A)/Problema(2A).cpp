// Problema(2A).cpp : define o ponto de entrada para o aplicativo do console.
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
	double Xn = 0;
	double Fxn;
	double XnAnterior;
	double Fa;
	double E = 1.0;
	double Error = pow(10, -5);

	for (int i = 0; E > Error; i++) {

		//Fa = pow(A, 3) - (9 * A) + 3;
		Fa = (sin(A) * cos(A)) / (1.25 - pow(cos(A), 2)) - 0.8391;

		XnAnterior = Xn;

		Xn = (A + B) / 2;

		//Fxn = pow(Xn, 3) - (9 * Xn) + 3;
		Fxn = (sin(Xn) * cos(Xn)) / (1.25 - pow(cos(Xn), 2)) - 0.8391;

		if (Fa*Fxn < 0)
			B = Xn;
		else
			A = Xn;

		if (i != 0)
			E = fabs((Xn - XnAnterior) / Xn);

		cout << "i:" << i << "	A:" << A << "	B:" << B << "	X:" << Xn <<
			"	F(a):" << Fa << "	F(X" << i << "):" << Fxn << "	E:" << E << endl;

	}

	cout << endl;

	for (int i = 0; i < 20; i++)
	{
		cout << "Indice: " << i << "	Busca do A positivo: " << (sin(i) * cos(i)) / (1.25 - pow(cos(i), 2)) - 0.8391 << endl;
	}

	cin.get();
	return 0;
}

