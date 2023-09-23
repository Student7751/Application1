#pragma once
#include<string>
struct DateStruct {
	int dd, mm, yy;
	void readDate(std::string& dateStr);
	void printDate();
};