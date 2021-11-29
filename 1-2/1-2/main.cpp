#include <iostream>
#include <math.h>

using namespace std;

/**
* \brief Расчет расстояния между точками 1 и 2
* \param x1 - Координаты точки 1 по x
* \param y1 - Координаты точки 1 по y
* \param x2 - Координаты точки 2 по x 
* \param y2 - Координаты точки 2 по y
* \return Distance - Расстояние между двумя точками
*/
double GetDistance(const double x1, const double y1, const double x2, const double y2);

int main()
{
	setlocale(LC_ALL, "Russian");
	double x1, y1;
	cout << "Введите х1 и у1" << "\n";
	cin >> x1 >> y1;

	double x2, y2;
	cout << "Введите х2 и у2" << "\n";
	cin >> x2 >> y2;

	double distance = GetDistance(x1, y1, x2, y2);

	cout << distance;
	return 0;
}

double GetDistance(const double x1, const double y1, const double x2, const double y2)
{
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}