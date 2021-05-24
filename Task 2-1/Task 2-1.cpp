2-1
#include <iostream>

using namespace std;

/*
* \brief перемена местами переменных с использованием 3ей переменной
* \param c - переменная-буфер
*/
void replacement(int a, int b);

/*
* \brief пермена местами переменных без использования 3ей переменной
* 
*/
void swap(int a, int b);

/*
* \brief Точка входа в программу.
* \param a - переменная 1
* \param b - переменная 2
* \param f - переменная для выбора алгоритма
* \return Код ошибки (0 - успех).
*/
int main()
{
    setlocale(LC_ALL, "Russian");

    int a, b, f;
    cout << "Введите а - ";
    cin >> a;
    cout << "Введите b - ";
    cin >> b;
    cout << "Выберите алгоритм ((1) - с 3 переменными; (2) - без) - ";
    cin >> f;
    if (f == 1) 
    {
        zamena(a, b);
    }
    else 
    {
        swap(a, b);
    }
}

void replacement( int a, int b)
{
    int c;
    c = a;
    a = b;
    b = c;
    cout << "Значение а после перестановки - " << a << '\n';
    cout << "Значение b после перестановки - " << b << '\n';
}

void swap(int *a, int *b)
{
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "Значение а после перестановки - " << a << '\n';
    cout << "Значение b после перестановки - " << b << '\n';
}
