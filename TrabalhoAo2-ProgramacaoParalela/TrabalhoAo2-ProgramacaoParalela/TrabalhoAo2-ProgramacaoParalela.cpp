// TrabalhoAo2-ProgramacaoParalela.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <time.h>

#include <omp.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	string imageName("C:/Users/dionm/source/repos/MeusTrabalhos-UNIVALI-4p.CC/TrabalhoAo2-ProgramacaoParalela/imagem_processo.jpg");
	if (argc > 1)
	{
		imageName = argv[1];
	}
	Mat image;
	image = imread(imageName.c_str(), IMREAD_COLOR); // Read the file
	if (image.empty())                      // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

}
