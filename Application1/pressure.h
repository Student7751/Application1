#pragma once

#include<fstream>
#include<vector>

#include"date.h"

struct Pressure {
private:
	DateStruct Date;
	float heigh = 0.0;
	int value = 0;
public:

	//Объявление геттеров
	float getHigh();
	int getValue();
	DateStruct getDate();

	//Объявление сеттеров
	void setHigh(float value);
	void setValue(int val);
	void setDate(DateStruct date);

	//Объявление функции чтения из файла
	static Pressure createFromStream(std::istream& in);
	//Объявление функции вывода данных
	void print(std::ostream& out);

	//Объявление функции считывания давления
	void readPressure(std::istream& file, std::vector<Pressure>& pvec);

	//Объявление функции вывода давления
	void printPressure(std::vector<Pressure>& pvec, std::ostream& out);

	//Объявление функции проверки данных на корректность
	void CorrectValue(float heigh, int value);
};
