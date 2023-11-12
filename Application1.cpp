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

	std::string error;

	try {
		
		data.readPressure(file, pvec);
	}

	catch (std::runtime_error &errorMessage) {
		error = errorMessage.what();
	}

	data.printPressure(pvec, std::cout);

	std::cout << error;
}
