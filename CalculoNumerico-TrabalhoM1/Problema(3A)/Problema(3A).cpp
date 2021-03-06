// Problema(3A).cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

#define Euler 2.71828182845904523536

using namespace std;

int main()
{
	double D = 20.0;
	double Q = 133.0;
	double Xn = 2.5;
	double XAnterior = 0;
	double Fx = 0;
	double DFx = 0;
	double E = 1.0;
	double Error = pow(10, -5);

	for (int K = 0; E > Error; K++)
	{
		//((1.49/E)*D^5*S^3/2)= 5025.91
		Fx = (pow((1.49 / 0.030), 3)*pow(D, 5)*pow(0.0001, 3 / 2))*pow(Xn, 5) - 4 * pow(133, 3)*pow(Xn, 2) - 4 * pow(133, 3) * D * Xn - pow(133, 3)*pow(D, 2);;

		DFx = 5 * (pow((1.49 / 0.030), 3)*pow(D, 5)*pow(0.0001, 3 / 2))*pow(Xn, 4) - 8 * pow(133, 3)*Xn - 4 * pow(133, 3) * 20;

		cout << "K: " << K << "   Xn: " << Xn << "  F'(x):" << DFx << "	F(x):" << Fx << "	E: " << E << endl;
		XAnterior = Xn;

		Xn -= Fx / DFx;

		if (K != 0)
			E = fabs((Xn - XAnterior) / Xn);

	}

	cin.get();
	return 0;
}

