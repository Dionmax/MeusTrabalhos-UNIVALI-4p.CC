// Problema2(A).cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
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
	double alphaMaior = 0.24,
		alphaMenor = 0,
		agha = 0,
		error = 0.1,
		ipsilon = 0,
		ipsilonAnterior = 0,
		FX = 0,
		FXNaoResolvido = 0,
		FXAnterior = 0;

	//Função Intregral sin(raiz(X))

	for (int contador = 1; error > ERROR; contador++) {

		cout << "\nInteracao: " << contador << endl;
		agha = (alphaMaior - alphaMenor) / contador;

		FXAnterior = FX;

		for (int indice = 0; indice < contador; indice++)
		{
			if (indice == 0) {
				FX = sin(sqrt(alphaMenor));
			}

			else {
				FX += (2 * sin(sqrt(indice * agha)));
			}

			if (indice == (contador - 1)) {
				FX += sin(sqrt(alphaMaior));
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