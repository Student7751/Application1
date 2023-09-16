#include <iostream>
using namespace std;

//Функция разибения массива по опоре
int divide(int *arr, int start, int end) {
	
	int element = arr[end];

	int elIndex = start;

	for (int i = start; i < end; i++) {
		if (arr[i] <= element) {
			swap(arr[i], arr[elIndex]);
			elIndex++;
		}
	}

	swap(arr[elIndex], arr[end]);

	return elIndex;
}

//Быстрая сортировка(быстрый алгоритм)
void quickSort(int *arr, int start, int end)
{
	if (start >= end) {
		return;
	}

	int pivot = divide(arr, start, end);

	quickSort(arr, start, pivot - 1);

	quickSort(arr, pivot + 1, end);
}

//Сортировка выбором(медленный алгоритм)
void selectionSort(int* arr, int len) {
	int value = 0;

	for (int i = 0; i < (len - 1); i++) {
		value = i;
		for (int j = i + 1; j < len; j++)
			if (arr[j] < arr[value]) value = j;
		swap(arr[i], arr[value]);
	}
}

//Запись элементов в массив
int* read_array(int len) {
	int* arr = new int[len];
	cout << "Введите элементы массива: ";
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}
	return arr;
}

//Чтение элементов из массива
void print_array(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		cout << *(arr + i) << '\t';
	}
	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "RU");

	int len = 0, position = 0, mode = 0;

	cout << "Введите длину массива: ";
	cin >> len;

	int* ArrA = new int[len];
	ArrA = read_array(len);

	cout << "Ваш массив: ";
	print_array(ArrA, len);

	cout << "Выберите алгоритм работы программы(0 - быстрый, 1 - медленный): ";
	cin >> mode;

	if (mode) selectionSort(ArrA, len);
	else quickSort(ArrA, 0, len - 1);

	cout << "Ваш массив: ";
	print_array(ArrA, len);

	cout << "Введите позицию элемента: ";
	cin >> position;

	if (1 <= position && position <= len) cout << "Элемент, стоящий на позиции " << position << " , если бы данный массив был отсортирован по возрастанию: " << ArrA[position - 1];
	else cout << "Введена неверная позиция, программа завершает работу";
}