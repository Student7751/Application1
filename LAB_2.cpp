#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include"date.h"
#include"pressure.h"
using namespace std;

void pressureData(ifstream& file, vector<Pressure>& pvec) {
	while (!file.eof()) {
		Pressure pressureData;

		string DATE;

		file >> DATE;

		pressureData.Date.readDate(DATE);

		file >> pressureData.heigh >> pressureData.value;

		pvec.push_back(pressureData);
	}
}

void print_result(vector<Pressure>& pvec) {
	for (auto& data : pvec) {
		cout << "Дата: " << data.Date.dd << "." << data.Date.mm << "." << data.Date.yy << " Высота: " << data.heigh << " Значение:  " << data.value << "\n";
	}
}

int main()
{
	setlocale(LC_ALL, "RU");

	ifstream file("test.txt");

	vector<Pressure> pvec;

	pressureData(file, pvec);

	print_result(pvec);
}