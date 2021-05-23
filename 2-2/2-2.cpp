#include <iostream>
#include <cmath>

using namespace std;

/**
* \brief Цель
* \param
* \param
* \param
* \return Конечное значение
*/
void input();
void solution();


const int a = 2.5;
double x, y;

void solution()
{
    if (x > a)
    {
        y = (x * (pow(sin(x), 2)));
        std::cout << "Значение y равно - " << y << endl;
    }
    else
    {
        y = (x * (pow(cos(x), 2)));
        std::cout << "Значение y равно - " << y << endl;
    }
}

int main()
{

    setlocale(LC_ALL, "Russian");
    std::cout << "Введите x - ";
    cin >> x;
    solution();
    return 0;
}