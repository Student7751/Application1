#include"pch.h"
#include "date.h"
#include<string>
#include<iostream>
#include <stdexcept>

void DateStruct::readDate(std::string& dateStr) {

	int d = stoi(dateStr.substr(0, 2));
	int m = stoi(dateStr.substr(3, 5));
	int y = stoi(dateStr.substr(6, 8));

    Correct(d, m, y);

    dd = d;
    mm = m;
    yy = y;
}

void DateStruct::printDate(std::ostream& out) {
	out << "Дата: " << dd << '.' << mm << '.' << yy;
}


int DateStruct::getDD() {
    return this->dd;
}

int DateStruct::getMM() {
    return this->mm;
}

int DateStruct::getYY() {
    return this->yy;
}

void DateStruct::setDD(int value) {
    Correct(value, this->mm, this->yy);
    this->dd = value;
}

void DateStruct::setMM(int value) {
    Correct(this->dd, value, this->yy);
    this->mm = value;
}

void DateStruct::setYY(int value) {
    Correct(this->dd, this->mm, value);
    this->yy = value;
}

bool DateStruct::isLeapYear(int year) {
    // Год високосный, если он делится на 4, но не делится на 100,
    // за исключением случаев, когда он делится на 400.
    year += 2000;
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void DateStruct::Correct(int dd, int mm, int yy) {
    if (!isLeapYear(yy)) {
        if (mm == 2 && dd > 28) {
            throw std::runtime_error("День ввёден неверно! Проверьте корректность входных данных");
        }
    }
    if (dd < 0 || dd > 31) throw std::runtime_error("День ввёден неверно! Проверьте корректность входных данных");
    if (mm < 0 || mm > 12) throw std::runtime_error("Месяц ввёден неверно! Проверьте корректность входных данных");
    if (yy < 0 || yy > 99) throw std::runtime_error("Год ввёден неверно! Проверьте корректность входных данных");
}

void DateStruct::CorrectDate(std::string& dateStr) {
    if (dateStr.length() > 8 || dateStr.length() <= 7) throw std::runtime_error("Дата введена неверно! Проверьте корректность входных данных");
    int d = stoi(dateStr.substr(0, 2));
    int m = stoi(dateStr.substr(3, 5));
    int y = stoi(dateStr.substr(6, 8));

    Correct(d, m, y);
}