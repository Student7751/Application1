#include"pch.h"
#include<fstream>
#include<vector>
#include<string>
#include<iostream>
#include <stdexcept>

#include "pressure.h"

Pressure Pressure::createFromStream(std::istream& in)
{
	Pressure pressureData;

	std::string DATE;

	in >> DATE;
	
	float heigh = 0;
	int value = 0;

	in >> heigh;
	in >> value;

	pressureData.CorrectValue(heigh, value);

	pressureData.heigh = heigh;
	pressureData.value = value;

	pressureData.Date.CorrectDate(DATE);

	pressureData.Date.readDate(DATE);

	return pressureData;
}


float Pressure::getHigh() {
	return this->heigh;
}

int Pressure::getValue() {
	return this->value;
}

void Pressure::setHigh(float val) {
	CorrectValue(val, 1);
	this->heigh = val;
}

void Pressure::setValue(int val) {
	CorrectValue(1, val);
	this->value = val;
}


DateStruct Pressure::getDate() {
	return this->Date;
}

void Pressure::setDate(DateStruct date) {
	
	date.Correct(date.getDD(), date.getMM(), date.getYY());

	this->Date = date;
}

void Pressure::CorrectValue(float heigh, int value) {
	if (heigh <= 0) throw std::runtime_error("Неверно введена высота! Проверьте корректность данных!");
	if (value <= 0) throw std::runtime_error("Неверно введено значение давления! Проверьте корректность данных!");
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