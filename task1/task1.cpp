#include <iostream>
#include <string> 

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");

	if (argc < 3)
	{
		cout << "Аргументы n и m не введены" << endl;
		return 0;
	}

	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	//cout << n << m << endl;

	if (n < 1 || m < 1)
	{
		cout << "Аргументы n и/или m не могут быть меньше 0" << endl;
		return 0;
	}

	int i = 0;

	int elmas = 1;
	int enmas = 0;

	//const int size = 1000;
	//int mas[size];

	int *mas = new int[m];

	string rez;

	while (enmas != 1)
	{
		for (int i = 0; i < m; i++)
		{
			mas[i] = elmas;
			if (elmas == n)
			{
				elmas = 1;
			} 
			else
			{
				elmas++;
			}			
		}
		elmas = mas[m-1];

		rez = rez + to_string(mas[0]);
		
		enmas = mas[m-1];
	}
	cout << rez << endl;

	return 0;
}