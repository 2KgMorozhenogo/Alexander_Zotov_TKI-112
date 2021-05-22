#include <iostream>
#include <math.h>

using namespace std;
/**
* \brief Функция расчета уравнение A
* \param X - Переменная уравнения
* \param Y - Переменная уравнения
* \param Z - Переменная уравнения
* \return GetA - результат уравнения А
*/
double GetA(const double x, const double y, const double z);
/* * \brief Функция расчета уравнение B
* \param X - Переменная уравнения
* \param Y - Переменная уравнения
* \param Z - Переменная уравнения
* \return GetB - результат уравнения B
*/
double GetB(const double x, const double y, const double z);

int main()
{
	const auto x = 0.61;
	const auto y = 3.4;
	const auto z = 16.5;

	const auto a = GetA(x, y, z);
	const auto b = GetB(x, y, z);

	std::cout << "x = " << x << ", y = " << y << ", z = " << z << '\n';
	std::cout << "a = " << a << ", b = " << b << endl;
	return 0;

}

double GetA(const double x, const double y, const double z)
{
	return (pow(x, 3) * pow(tan((x + y) * (x + y)), 2) + z / sqrt(x + y));
}

double GetB(const double x, const double y, const double z)
{
	return ((y * pow(x, 2) - z) / (exp(z * x) - 1));
}