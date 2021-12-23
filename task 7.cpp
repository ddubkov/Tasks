#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

string* separationF(string, string, int&);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str;
	ifstream dm("text.txt");
	int y;
	char bukva;
	string pattern;
	do {

		str = "\0";
		cout << "Чтение из файла - 1, ручной ввод - 2:  "; cin >> y;

		if (y == 1)
		{
			ifstream dm("text.txt");
			if (!dm.is_open())
			{
				cout << "Файл не открылся";
				return 0;
			}

			while (!dm.eof())
			{
				dm.get(bukva);
				str += bukva;
			}

			cout << "Строка из файла: " << str << endl;
			dm.close();
		}
		else if (y == 2)
		{
			string temp_str;
			getline(cin, temp_str);
			temp_str = "\0";

			getline(cin, str);
		}
		else
		{
			cout << "\nДолжно быть 1 или 2";
			return 0;
		}

		//----------------------=====-----=====-----======----=====-----=====-----======----=====-----=====-----======

		int count = 0;

		string* sepka;

		cout << "Введите разделители: "; cin >> pattern;

		sepka = separationF(str, pattern, count);
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		for (int i = 0; i < count + 1; i++)
		{
			cout << sepka[i] << endl;
		}

		cout << "Всего частей: " << count << endl;

		delete[] sepka;

		cout << "\nВведите f, чтобы выполнить ещё раз: "; cin >> bukva;
	} while (bukva = 'f');
}



string* separationF(string buff, string pattern, int& count)  
{
	for (int i = 0; i < buff.size(); i++)
		for (int j = 0; j < pattern.size(); j++)
		{
			if (buff[i] == pattern[j]);
			count++;
		}

	string* temp_stepka = new string[count + 1];
	bool b = false;

	count = 0;
	for (int i = 0; i < buff.size(); i++)
	{

		for (int j = 0; j < pattern.size(); j++)
		{
			if (buff[i] == pattern[j])
			{
				count++;
				i++;
			}
		}



		temp_stepka[count] += buff[i];

	}
	count++;
	return temp_stepka;
}

