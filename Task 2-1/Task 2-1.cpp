#include <iostream>
using namespace std;

/**
* \brief перемена местами переменных с использованием 3ей переменной
* \param c - переменная-буфер
*/
void swap1(int a, int b);

/**
* \brief пермена местами переменных без использования 3ей переменной
*
*/
void swap(int a, int b);

/**
* \brief Точка входа в программу.
* \param a - переменная 1
* \param b - переменная 2
* \param f - переменная для выбора алгоритма
* \return Код ошибки (0 - успех).
*/

/**
* \brief выбор заполнения массива
*/
class enum path
{
	Manuall = 1,
	Random = 2
};

int main()
{
	setlocale(LC_ALL, "Russian");

	int a, b, choice;
	cout << "Введите а - ";
	cin >> a;
	cout << "Введите b - ";
	cin >> b;
	cout << "Выберите как хотите заполнить массив:\n1 - ввод с клавиатуры\n2 - заполнение массива случайными числами\nВыбор: ";
	int choice;
	cin >> choice;
	const auto filling = static_cast<path>(choice);
	switch (filling) {
	case path::Random:
	{
		swap(a, b);
	}
	case path::Manuall:
	{
		swap1(a, b);
	}
	default:
		cout << "Некоректный ввод.";
	}
}

void swap1(int a, int b)
{
	int c;
	c = a;
	a = b;
	b = c;
	cout << "Значение а после перестановки - " << a << '\n';
	cout << "Значение b после перестановки - " << b << '\n';
}

void swap(int a, int b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	cout << "Значение а после перестановки - " << a << '\n';
	cout << "Значение b после перестановки - " << b << '\n';
}
