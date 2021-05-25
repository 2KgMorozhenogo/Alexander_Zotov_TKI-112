#include <iostream>
#include <cmath>
using namespace std;
/**
* \brief ввод координат точек
* \param xa - координата x точки a
* \param ya - координата y точки a
* \param xb - координата x точки b
* \param yb - координата y точки b
* \param xc - координата x точки c
* \param yc - координата y точки c
*/
void input(double xa, double xb, double xc, double ya, double yb, double yc);

/**
* \brief Проверить лежит ли точки на одной прямой
* \param vector_ab_x - координаты вектора ab по оси x
* \param vector_ab_y - координаты вектора ab по оси y
* \param vector_bc_x - координаты вектора bc по оси x
* \param vector_bc_y - координаты вектора bc по оси y
* \param module_ab - модуль координат вектора ab
* \param module_bc - модуль координат вектора bc
* \scalar - скалярное произведение векторов
*/
void check(double xa, double xb, double xc, double ya, double yb, double yc);

int main(void)
{
    double xa, xb, xc, ya, yb, yc;

    input(xa, xb, xc, ya, yb, yc);

    check(xa, xb, xc, ya, yb, yc);

    return 0;
}

void input(double xa, double xb, double xc, double ya, double yb, double yc) // вводим функцию на ввод переменных
{
    setlocale(LC_ALL, "Russian");



    cout << "Введите координаты точек A, B, C" << endl;

    cout << "xa = ";
    cin >> xa;
    cout << "ya = ";
    cin >> ya;


    cout << "xb = ";
    cin >> xb;
    cout << "yb = ";
    cin >> yb;

    cout << "xc = ";
    cin >> xc;
    cout << "yc = ";
    cin >> yc;
}

void check(double xa, double xb, double xc, double ya, double yb, double yc) //вводим функцию проверяющую лежат ли A, B, C точки на одной прямой
{
    double vector_ab_x, vector_ab_y, vector_bc_x, vector_bc_y, module_ab, module_bc, scalar;

    if ((xa / xb) == (ya / yb))
    {
        if ((xb / xc) == (yb / yc))
        {
            cout << "Точки A, B, C лежат на одной прямой" << endl;
        }
    }
    else
    {
        vector_ab_x = xb - xa;
        vector_ab_y = yb - ya;
        vector_bc_x = xc - xb;
        vector_bc_y = yc - yb;
        scalar = (vector_ab_x * vector_bc_x) + (vector_ab_y * vector_bc_y);
        module_ab = (pow(vector_ab_x, 2) + (pow(vector_ab_y, 2)));
        module_bc = (pow(vector_bc_x, 2) + (pow(vector_bc_y, 2)));

        cout << "Точки A, B, C не лежат на одной прямой. Угол B равен - " << acos(scalar / (module_bc * module_ab)) << endl;
    }
}

