#include <iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

struct pressure {
	string date;
	float heigh;
	int value;
};

struct date {
	int mm;
	int dd;
	int yy;
};

int main()
{
	setlocale(LC_ALL, "RU");
	ifstream file("test.txt");
	

	vector<pressure> pvec;

	while (!file.eof()) {
		pressure pressureData;

		file >> pressureData.date >> pressureData.heigh >> pressureData.value;

		pvec.push_back(pressureData);
	}

	for (auto &data : pvec) {
		cout << "Дата: " << data.date << " Высота: " <<  data.heigh << " Значение:  " << data.value << "\n";
	}
}