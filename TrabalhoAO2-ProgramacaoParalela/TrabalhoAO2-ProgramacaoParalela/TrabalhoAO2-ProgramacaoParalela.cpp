// TrabalhoAO2-ProgramacaoParalela.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <time.h>
#include <omp.h>
#include <vector>

using namespace cv;
using namespace std;

const int CORTE = 250;

int main() {

	clock_t Ticks[2];

	Mat imagem = imread("groot.jpg"),
		sub_imagem;

	Rect roi;

	Vec3b cor;

	int imagem_altura = imagem.rows,
		imagem_largura = imagem.cols,
		altura_celulas = imagem_altura / CORTE,
		largura_celulas = imagem_largura / CORTE;

	int identificadorThreads = 0;

	Ticks[0] = clock();

	for (int contador = 0; contador < CORTE; contador++) {
		for (int indice = 0; indice < CORTE; indice++) {

			roi = Rect(contador* largura_celulas, indice* altura_celulas, largura_celulas, altura_celulas);

			sub_imagem = imagem(roi);

			//#pragma omp parallel
			{
				for (int x = 0; x < sub_imagem.rows; x++) {
					//#pragma omp parallel for
					for (int y = 0; y < sub_imagem.cols; y++)
					{
						cor = sub_imagem.at<Vec3b>(x, y);
					}
				}

				for (int x = 0; x < sub_imagem.rows; x++) {
					//#pragma omp parallel for
					for (int y = 0; y < sub_imagem.cols; y++)
					{
						sub_imagem.at<Vec3b>(x, y) = cor;
					}
				}
			}

			sub_imagem.copyTo(imagem(roi));
		}
	}

	Ticks[1] = clock();

	double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

	printf("Tempo gasto: %g ms.", Tempo);
	cout << identificadorThreads << endl;

	imshow("Image", imagem);
	waitKey(50000);

}
