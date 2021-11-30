#include <iostream>
using namespace std;

/**
* \brief перемена местами переменных с использованием 3ей переменной
* \param a переменная a
* \param b переменная b
*/
void swap1(int a, int b);

/**
* \brief пермена местами переменных без использования 3ей переменной
* \param a переменная a
* \param b переменная b
*/
void swap(int a, int b);


/**
* \brief выбор заполнения массива
*/
enum class path
{
	SwapWithoutThirdVariable = 1,
	SwapWithThirdVariable = 2
};

/**
* \brief Точка входа в программу.
* \return Код ошибки (0 - успех).
*/
int main()
{
	setlocale(LC_ALL, "Russian");

	int a, b;
	cout << "Введите а - ";
	cin >> a;
	cout << "Введите b - ";
	cin >> b;
	cout << "Какой алгоритм хотите использовать? Введите \n"
		<< static_cast<int>(path::SwapWithoutThirdVariable) << " - для перемены местами переменных без использования третьей переменной,\n"
		<< static_cast<int>(path::SwapWithThirdVariable) << " - для перемены местами переменных с использованием третьей переменной.\n"
		<< "Ваш выбор: ";
	int choice;
	cin >> choice;
	const auto filling = static_cast<path>(choice);
	switch (filling) {
	case path::SwapWithoutThirdVariable:
	{
		swap(a, b);
		break;
	}
	case path::SwapWithThirdVariable:
	{
		swap1(a, b);
		break;
	}
	default:
	{
		cout << "Некоректный ввод.";
		break;
	}
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
