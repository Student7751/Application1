#include<fstream>
#include<vector>
#include<string>
#include<iostream>
#include "pressure.h"

Pressure Pressure::createFromStream(std::istream& in)
{
	Pressure pressureData;

	std::string DATE;

	in >> DATE;

	pressureData.Date.readDate(DATE);

	in >> pressureData.heigh >> pressureData.value;

	return pressureData;
}

void Pressure::print(std::ostream& out)
{
	Date.printDate(out);

	out << " Высота: " << heigh << " Значение:  " << value << "\n";
}

void Pressure::readPressure(std::istream& file, std::vector<Pressure>& pvec) {
	while (!file.eof()) {
		Pressure pressureData = Pressure::createFromStream(file);
		pvec.push_back(pressureData);
	}
}

void Pressure::printPressure(std::vector<Pressure>& pvec, std::ostream &out) {
	for (auto& data : pvec) {
		data.print(out);
	}
}