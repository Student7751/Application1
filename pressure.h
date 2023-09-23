#pragma once

#include<fstream>
#include<vector>

#include"date.h"

struct Pressure {
	DateStruct Date;
	float heigh;
	int value;

	static Pressure createFromStream(std::istream& in);
	void print(std::ostream& out);

	void readPressure(std::istream& file, std::vector<Pressure>& pvec);
	void printPressure(std::vector<Pressure>& pvec, std::ostream& out);
};