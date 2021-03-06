// CalculoNumerico-MatodoDosTrapezios.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
#include <string>

#include <math.h>
#include <algorithm>

const double ERROR = pow(10, -2);

using namespace std;

int main()
{
	double alphaMaior = 1.2,
		alphaMenor = 0,
		agha = 0,
		error = 0.1,
		FX = 0,
		FXAnterior = 0;

	//Função Intregral de 1,2 - 0 : Euler ^X * Cos(X)

	for (int contador = 1; error > ERROR; contador++) {

		cout << "\nInteracao: " << contador << endl;
		agha = (alphaMaior - alphaMenor) / contador;

		FXAnterior = FX;

		for (int indice = 0; indice < contador; indice++)
		{
			if (indice == 0) {
				FX = (exp(alphaMenor) * cos(alphaMenor));
			}

			else {
				FX += (2 * (exp(agha* indice) * cos(agha  * indice)));
			}

			if (indice == (contador - 1)) {
				FX += (exp(alphaMaior) * cos(alphaMaior));
			}
		}

		FX *= (agha / 2);

		cout << "FX: " << FX << endl;

		if (contador != 1) {
			error = (FX - FXAnterior) / FX;
			cout << "Error: " << error << endl;
		}

		cout << endl << endl;
	}
}
