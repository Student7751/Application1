#include"pch.h"
#include "date.h"
#include<string>
#include<iostream>
#include <stdexcept>

//Определение функции чтения даты
void DateStruct::readDate(std::string& dateStr) {
    if (dateStr[2] == '.' && dateStr[5] == '.') {
        int d = stoi(dateStr.substr(0, 2));
        int m = stoi(dateStr.substr(3, 5));
        int y = stoi(dateStr.substr(6, 8));

        dd = d;
        mm = m;
        yy = y;
    }
    else throw std::runtime_error("Неверный разделитель! Проверьте корректность вводимых данных.");
}

//Определение функции вывода даты
void DateStruct::printDate(std::ostream& out) {
	out << "Дата: " << dd << '.' << mm << '.' << yy;
}

//Определение геттера даты
int DateStruct::getDD() {
    return dd;
}
//Определение геттера месяца
int DateStruct::getMM() {
    return mm;
}
//Определение геттера года
int DateStruct::getYY() {
    return yy;
}
//Определение сеттера даты
void DateStruct::setDD(int value) {
    Correct(value, 12, 12);
    dd = value;
}
//Определение сеттера месяца
void DateStruct::setMM(int value) {
    Correct(12, value, 12);
    mm = value;
}
//Определение сеттера года
void DateStruct::setYY(int value) {
    Correct(12, 12, value);
    yy = value;
}

//Определение функции проверки года на високосность
bool DateStruct::isLeapYear(int year) {
    //Год високосный, если он делится на 4, но не делится на 100,
    //за исключением случаев, когда он делится на 400.
    if (year < 0) throw std::runtime_error("Год не может быть отрицательным!");
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//Определение функции проверки даты на корректность
void DateStruct::Correct(int dd, int mm, int yy) {
    int maxDaysInMonth = 31;
    switch (mm) {
    case 2:
        maxDaysInMonth = isLeapYear(yy) ? 29 : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDaysInMonth = 30;
        break;
    }

    if (dd < 1 || !(dd <= maxDaysInMonth)) throw std::runtime_error("День ввёден неверно! Проверьте корректность входных данных");
    if (mm < 1 || mm > 12) throw std::runtime_error("Месяц ввёден неверно! Проверьте корректность входных данных");
    if (yy < 0 || yy > 99) throw std::runtime_error("Год ввёден неверно! Проверьте корректность входных данных");
}

//Функция проверки считывания даты из строки на корректность
void DateStruct::CorrectDate(std::string& dateStr) {
    if ((dateStr.length() > 8 || dateStr.length() <= 7) || !(dateStr[2] == '.' && dateStr[5] == '.')) throw std::runtime_error("Дата введена неверно! Проверьте корректность входных данных");
    int d = stoi(dateStr.substr(0, 2));
    int m = stoi(dateStr.substr(3, 5));
    int y = stoi(dateStr.substr(6, 8));

    Correct(d, m, y);
}
