#ifndef MAIN_
#define MAIN_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include "framework/Framework.h"
#include "examples/MergeSortP.h"
#include "examples/MergeSortS.h"
#include "examples/QuickSortP.h"
#include "examples/QuickSortS.h"

int main(int argc, char* argv[])
{
	if (argc != 2) 
	{
		cout << "Número de parametros incorrecto." << std::endl;
		cout << "Modo de uso: ./main input_values.in" << std::endl;
		exit(-1);
	}
	std::ifstream ifs;
	std::string filename = argv[1];
	ifs.open(filename);
	if (ifs.fail())
	{
		std::cout << "ERROR: Can not open file: " + filename << std::endl;
		exit(-1);
	}
	std::string line;
	std::vector<int> readUnsortedArray;
	int tempReadValue;
	while (!ifs.eof())
	{
		readUnsortedArray.clear();
		getline(ifs, line);
		char sortMethod = line[0];
		line[0] = ' ';
		std::istringstream iss(line);
		while (!iss.eof())
		{
			if (!(iss >> tempReadValue))
			{
				std::cout << "ERROR: Bad syntax at input file." << std::endl;
				exit(-1);
			}
			readUnsortedArray.push_back(tempReadValue);
		}
		Framework *framework = new Framework();
		Problema *problema;
		Solucion *solucion;
		switch (sortMethod)
		{
		case 'q':
			problema = new QuickSortP(readUnsortedArray);
			solucion = new QuickSortS();
			framework->divideyVenceras(problema, solucion);
			std::cout << "Quick Sorted: ";
			solucion->resolver();
			break;

		case 'm':
			problema = new MergeSortP(readUnsortedArray);
			solucion = new MergeSortS();
			framework->divideyVenceras(problema, solucion);
			std::cout << "Merge Sorted: ";
			solucion->resolver();
			break;

		default:
			std::cout << "ERROR: Bad syntax at input file." << std::endl;
			exit(-1);
			break;
		}
	}
};

#endif /* MAIN_ */
