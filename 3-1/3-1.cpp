#include <iostream>
#include <math.h>

using namespace std;

/**
* \brief Функция для расчета y
* \param x Параметр x
* \return Параметр y
*/
double GetY(double x);

/**
* \brief Ввод значения х в программу
* \return Конечное значение
*/
int main()
{
	setlocale(LC_ALL, "Russian");

	double x;
	cout << "Введите значение x = ";
	cin >> x;

	if (x >= 0 && x <= 1)

	{

		for (x; x >= 0 && x <= 1; x += 0.1)

		{
			auto y = GetY(x);

			cout << " y = " << y << "\n";
		}
	}

	else
	{
		auto y = GetY(x);
		cout << " y = " << y << "\n" << "Нет решения, так как х не входит в область определения " << endl;
	}

	return 0;
}

double GetY(double x)
{
	return 3 * x - 4 * log(x) - 5;
}