#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include"date.h"
#include"pressure.h"

int main()
{
	setlocale(LC_ALL, "RU");

	std::ifstream file("test.txt");

	std::vector<Pressure> pvec;

	Pressure data;

	data.readPressure(file, pvec);

	data.printPressure(pvec, std::cout);
}