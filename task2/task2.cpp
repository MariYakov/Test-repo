#include <iostream>
#include <string> 
#include <fstream> 

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");

	if (argc < 2)
	{
		cout << "Аргумент не введен" << endl;
		return 0;
	}

	ifstream fin;

	fin.open(argv[1]);

	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		string str;
		char value;

		const int size = 1000;
		int mas[size];
		int sum[size];

		int i = 0;
		int j = 0;
		int k = 0;

		//while (!fin.eof())
		while (getline(fin, str))
		{
			mas[i] = stoi(str);
			i++;
		}


		int n = i ;
		int max = mas[0];
		int min = mas[0];

		//Нахождение max и min
		for (int i = 0; i < n; i++)
		{
			if (max < mas[i])
			{
				max = mas[i];
			}
			if (min > mas[i])
			{
				min = mas[i];
			}
		}

		int minGlob = max * n;

		for (int i = min; i < max+1; i++)
		{
			sum[k] = 0;
			for (int j = 0; j < n; j++)
			{
				sum[k] = sum[k] + abs(i - mas[j]);
			}
			if (k > 0)
			{
				if (minGlob > sum[k])
				{
					minGlob = sum[k];
				}
			}
			else
			{
				minGlob = sum[k];
			}
			k++;
		}
		cout << minGlob << endl;
		fin.close();
	}
	
	return 0;
}