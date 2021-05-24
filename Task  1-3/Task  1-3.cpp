#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Расчет давления pressure 
* \param g - Ускорение свободного падения
* \param mass - Масса
* \param square - Площадь поверхности опоры
* \return Pressure - Давление
*/
double GetPressure(const double massa, const double square);

/* 
* /brief Точка входа в программу
* /return Код ошибки (0-успех)
*/

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите масу объекта - ";
    double massa;
    cin >> massa;
    cout << "Введите площадь - ";
    double square;
    cin >> square;
    double pressure = GetPressure(massa, square);
    cout << "Давление = " << pressure;

    return 0;
}

double GetPressure(const double massa, const double square)
{
    const double g = 9.80665;
    return  (massa * g) / square;
}
