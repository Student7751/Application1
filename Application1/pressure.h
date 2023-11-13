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

	
	float getHigh();
	int getValue();
	DateStruct getDate();

	void setHigh(float value);
	void setValue(int val);
	void setDate(DateStruct date);

	static Pressure createFromStream(std::istream& in);
	void print(std::ostream& out);

	void readPressure(std::istream& file, std::vector<Pressure>& pvec);

	void printPressure(std::vector<Pressure>& pvec, std::ostream& out);

	void CorrectValue(float heigh, int value);
};