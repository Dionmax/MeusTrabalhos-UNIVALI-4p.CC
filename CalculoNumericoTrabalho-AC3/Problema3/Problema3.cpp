// Problema3.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
#include <string>

#include <math.h>
#include <algorithm>

using namespace std;

void euler(double x, double y, double h, int contador) {
	while (x <= 4)
	{
		double Fxy = y - x;
		y = y + h * Fxy;
		x = x + h;
		cout << " Valor X: " << x << "	Valor Y: " << y << endl;
		contador++;
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");

	double x = 0;
	double y = 2;
	double h1 = 0.2, h2 = 0.1, h3 = 0.05;
	int contador = 0;

	euler(x, y, h1, contador);
	cout << endl;

	euler(x, y, h2, contador);
	cout << endl;

	euler(x, y, h3, contador);

}
