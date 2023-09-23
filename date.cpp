#include "date.h"
#include<string>
#include<iostream>

void DateStruct::readDate(std::string& dateStr) {
	dd = stoi(dateStr.substr(0, 2));
	mm = stoi(dateStr.substr(3, 5));
	yy = stoi(dateStr.substr(6, 8));
}

void DateStruct::printDate() {
	std::cout << dd << mm << yy;
}