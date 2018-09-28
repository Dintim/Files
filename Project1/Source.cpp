#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <Windows.h>


using namespace std;
ifstream in_file("in.txt");
ofstream out_file("out.txt");

int countSymbol(char* arr, char x) {
	int sum = 0;	
	char* context;
	char* p = strtok_s(arr, " ", &context);
	while (p != NULL) {
		if (p[0] == x || p[0] == x + 32 || p[0] == x - 32) sum++;
		p = strtok_s(NULL, " ", &context);
	}
	return sum;
}



int main()
{
	int n;
	cout << "enter number of case: ";
	cin >> n;

	switch (n) {
	case 2:
	{
		//8. Дан текстовый файл. Найти длину самой длинной строки.
		char arr[100];
		int str_lenght = 0, strings = 1, h = 0;

		while (!in_file.eof()) {
			in_file.getline(arr, 100);
			if (strlen(arr)>str_lenght) {
				str_lenght = strlen(arr);
				h = strings;
			}
			strings++;
		}

		cout << "greatest lenght: " << str_lenght << " in " << h << " string" << endl;
	}
	break;

	case 3:
	{
		//9. Дан текстовый файл. Подсчитать количество слов, начинающихся с символа, который задаёт пользователь.
		char arr[100]; int sum = 0; char x;
		cout << "enter character: ";
		cin >> x;
		while (!in_file.eof()) {
			in_file.getline(arr, 100);
			sum += countSymbol(arr, x);
		}
		cout << "count of words begin with searching character: " << sum << endl;
	}
	break;

	case 1:
	{
		//7. Дан текстовый файл. Удалить из него последнюю строку. Результат записать в другой файл.
		char arr[100];
		int sum = 0;
		while (!in_file.eof()) {
			in_file.getline(arr, 100);			
			sum++;
		}
		
		in_file.seekg(0);
		while (!in_file.eof() && sum>1) {
			in_file.getline(arr, 100);
			out_file << arr << endl;
			sum--;
		}
	}
	break;



	}


	system("pause");
	return 0;
}
