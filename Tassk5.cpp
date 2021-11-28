#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace std;


int mag(int[], int);

int main()
{
	setlocale(LC_ALL, "rus");

	int n;
	int* arr;
	int p;
	int k = 0;
	int temp;
	do {
		srand(time(0));
		cout << "Введите размер массива: "; 
		cin >> n;                              
		if (n > 0) {

			arr = new int[n];

			for (int i = 0; i < n; i++) {     // Заполнение массива случайными значениями
				arr[i] = 1 + rand() % 100;
			}

			cout << "Массив: ";
			for (int i = 0; i < n; i++) {
				cout << arr[i] << ", ";

			}
			
			mag(arr, n);
			
			delete[] arr;
		}
		else {
			cout << "Размер должен быть больше 0";
		}
		cout << "\nВведите 1, чтобы выполнить ещё раз: ";
		cin >> p;
	} while (p == 1);
}

int mag(int* arr, int n)
{
	int temp;
	int k = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {   // С помощью метода пузырика происходит сортировка элементов массива по возрастанию 
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << "\n-----------------------" << endl;
	cout << "Отсортированный Массив: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";

	}
	cout << "\n-----------------------" << endl;

	for (int i = 0; i < n; i++) {          // Когда элементы массива отсортированы, просходит сравнение двух соседних элементов, если они равны, то переменной k присваивается значение 1
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j] && i != j) {
				k = 1;
				break;
			}
		}
	}
	if (k == 1) {                          // С помощью оператора if определяется, все ли элементы массива различны
		cout << "!Есть одинаковые элементы!" << endl;
	}
	else { cout << "!Все элементы массивы различны!" << endl; }
	return k;
}



