#include <iostream>

using namespace std;

/**
* \brief Вычисление суммы всех членов последовательности, не меньших заданного числа e.
* \param znam - Знаменатель
* \param chus - Числитель
* \param sum - Сумма
* \return Вычисление суммы всех членов последовательности, не меньших заданного числа e.
*/
void formula();

/* \brief Вычисление суммы первых n членов последовательности(k = 1, 2, 3 ..., n).
*  \param n - Переменная определяющая количество элементов n
*  \return Сумму первых n членов последовательности (k = 1, 2, 3 ..., n).
*/
void summa();

int sum, k, b, i, n, a;


void summa()
{
    int s = 0;
    setlocale(LC_ALL, "Russian");
    cout << "Количество элементов n ";
    cin >> n;

    if (n <= -1)
    {
        for (int i = 1; i >= n; i--) // сумма отрицательных
        {
            s += i;
        }
    }
    else s = (1 + n) * n / 2; // по формуле
    {

    }
    cout << s;
    cout << endl;
}

void formula()
{
    int a, n, k = 0, e, chus = 1, znam = 0, sum = 0;
    cout << "Введите n - ";
    cin >> n;
    cout << "Введите e - ";
    cin >> e;

    for (int h = 1; h <= n; h++) {
        k = 1;
        a = k * h;
        znam += k;
        a += 4;
        for (int i = 1; i <= a; i++) {
            chus *= i;
        }
        sum = chus / znam;
        sum /= (h * h);
        chus = 1;
    }
    cout << sum;
}

int main() {
    summa();
    formula();
}