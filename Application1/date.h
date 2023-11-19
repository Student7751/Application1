#pragma once
#include<string>
struct DateStruct {
private:
	int dd = 0, mm = 0, yy = 0;

public:

	//Объявление геттеров
	int getDD();
	int getMM();
	int getYY();
	//Объявление сеттеров
	void setDD(int value);
	void setMM(int value);
	void setYY(int value);

	//Объявление функции чтения даты
	void readDate(std::string& dateStr);
	//Объявление функции вывода даты
	void printDate(std::ostream& out);
	//Объявление функции проверки корректности даты из строки
	void CorrectDate(std::string& dateStr);
	//Объявление функции определения года на високосноть
	bool isLeapYear(int year);
	//Объявление функции проверки даты на корректность
	void Correct(int dd, int mm, int yy);
};
