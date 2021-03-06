// Problema2(B).cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
#include <string>

#include <math.h>
#include <algorithm>

const double ERROR = pow(10, -5);

using namespace std;

int main()
{
	double alphaMaior = 1.5,
		alphaMenor = 0.5,
		agha = 0,
		error = 0.1,
		FX = 0,
		FXAnterior = 0;

	bool alternador;

	//F(X) = tang(x) + E^x

	for (int contador = 2; error > ERROR; contador += 2) {

		cout << "\nInteracao: " << contador << endl;
		agha = (alphaMaior - alphaMenor) / contador;

		FXAnterior = FX;
		alternador = true;

		for (int indice = 0; indice < contador; indice++)
		{
			if (indice == 0) {
				FX = tan(alphaMenor) + exp(alphaMenor);
			}
			else
			{
				if (alternador) {
					FX += (4 * (tan(((agha * indice) + alphaMenor)) + exp((agha * indice) + alphaMenor)));
					alternador = false;
				}
				else
				{
					FX += (2 * (tan(((agha * indice) + alphaMenor)) + exp((agha * indice) + alphaMenor)));
					alternador = true;
				}
			}

			if (indice == (contador - 1)) {
				FX += tan(alphaMaior) + exp(alphaMaior);
			}
		}

		FX *= (agha / 3);

		cout << "FX: " << FX << endl;

		if (contador != 2) {
			error = (FX - FXAnterior) / FX;
			cout << "Error: " << error << endl;
		}

		cout << endl << endl;
	}
}
