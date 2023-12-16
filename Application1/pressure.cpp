// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include"pch.h"
#include<fstream>
#include<vector>
#include<string>
#include<iostream>
#include <stdexcept>

#include "pressure.h"

//Определение функции считывания данных
Pressure Pressure::createFromStream(std::istream& in)
{
	Pressure pressureData;

	std::string DATE;

	in >> DATE;
	
	float heigh = 0;
	int value = 0;

	in >> heigh;
	in >> value;
	
	//Проверка на корректность вводимых значений
	pressureData.CorrectValue(heigh, value);

	pressureData.heigh = heigh;
	pressureData.value = value;

	//Проверка на корректность считываемой даты
	pressureData.Date.CorrectDate(DATE);

	//Запись даты, в случае, если она корректна
	pressureData.Date.readDate(DATE);

	return pressureData;
}


//Определение геттера высоты
float Pressure::getHigh() {
	return heigh;
}
//Определение геттера значения
int Pressure::getValue() {
	return value;
}
//Определение сеттера высоты
void Pressure::setHigh(float val) {
	CorrectValue(val, 1);
	heigh = val;
}
//Определение сеттера значения
void Pressure::setValue(int val) {
	CorrectValue(1, val);
	value = val;
}

//Определение геттера даты
DateStruct Pressure::getDate() {
	return Date;
}
//Определение сеттера даты
void Pressure::setDate(DateStruct date) {
	
	date.Correct(date.getDD(), date.getMM(), date.getYY());

	Date = date;
}

//Определние функции проверки на коррекность вводимых значений
void Pressure::CorrectValue(float h, int v) {
	if (h <= 0) throw std::runtime_error("Неверно введена высота! Проверьте корректность данных!");
	if (v <= 0) throw std::runtime_error("Неверно введено значение давления! Проверьте корректность данных!");
}

//Определение функции чтения данных
void Pressure::print(std::ostream& out)
{
	Date.printDate(out);

	out << " Высота: " << heigh << " Значение:  " << value << "\n";
}

//Определение функции считывания данных из файла
void Pressure::readPressure(std::istream& file, std::vector<Pressure>& pvec) {
	while (!file.eof()) {
		Pressure pressureData = Pressure::createFromStream(file);
		pvec.push_back(pressureData);
	}
}

//Определение функции вывода результата
void Pressure::printPressure(std::vector<Pressure>& pvec, std::ostream &out) {
	for (auto& data : pvec) {
		data.print(out);
	}
}
