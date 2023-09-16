#include <iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

struct DateStruct {
	int dd, mm, yy;
};

struct pressure {
	DateStruct Date;
	float heigh;
	int value;
};

void pressureData(ifstream& file, vector<pressure>& pvec) {
	while (!file.eof()) {
		pressure pressureData;

		string dateStr;

		file >> dateStr;

		pressureData.Date.dd = stoi(dateStr.substr(0, 2));
		pressureData.Date.mm = stoi(dateStr.substr(3, 5));
		pressureData.Date.yy = stoi(dateStr.substr(6, 8));


		file >> pressureData.heigh >> pressureData.value;

		pvec.push_back(pressureData);
	}
}

void print_result(vector<pressure>& pvec) {
	for (auto& data : pvec) {
		cout << "Дата: " << data.Date.dd << "." << data.Date.mm << "." << data.Date.yy << " Высота: " << data.heigh << " Значение: " << data.value << "\n";
	}
}

int main()
{
	setlocale(LC_ALL, "RU");

	ifstream file("test.txt");

	vector<pressure> pvec;

	pressureData(file, pvec);

	print_result(pvec);
}