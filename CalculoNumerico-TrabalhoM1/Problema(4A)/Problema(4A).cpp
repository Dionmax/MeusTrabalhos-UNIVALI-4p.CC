// Problema(4A).cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

#define Euler 2.71828182845904523536

using namespace std;

int main()
{
	double Xn = 7.5;
	double XAnterior = 0;
	double Fx = 0;
	double DFx = 0;
	double E = 1.0;
	double Error = pow(10, -5);

	for (int K = 0; E > Error; K++)
	{
		Fx = 37.104740 + 3.15122 * Xn - ((2 * pow(Xn, 2)) / 2);

		DFx = 3.15122 - 2 * Xn;

		if (K == 0) {
			cout << "K: " << K << "   Xn: " << Xn << "  F'(x):" << DFx << "	F(x):" << Fx << "	E: " << E << endl;
		}

		XAnterior = Xn;

		Xn -= Fx / DFx;

		if (K != 0)
			E = fabs((Xn - XAnterior) / Xn);

		cout << "K: " << K << "   Xn: " << Xn << "  F'(x):" << DFx << "	F(x):" << Fx << "	E: " << E << endl;
	}

	cin.get();
	return 0;
}

