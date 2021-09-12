#include <iostream>
#include <ctime>
using namespace std;

/*
* \brief - заполнение массива пользователем
* \return - заполненный массив
*/
int UserInput(int* arr, int size);

/*
* \brief = заполнение массива случайными числами
* \return - заполненный массив
*/
int randomDigits(int* arr, int size);

/*
* \brief - вывод массива
*/
void output(int* arr, int size);

/*
* \brief - вычисление суммы отрицательных элементов кратных 10
* \param total - сумма отрицательных элементов кратных 10
* \param counter - счётчик
* \return - сумма отрицательных элементов кратных 10
*/
int sum(int* arr, int size);

/*
* \brief - переворот первых k элементов массива
* \param quantity - число k
* \param buffer - буфферная переменная
* \param counter - счётчик
* \return - перевёрнутый массив
*/
int swapMyArrayPlease(int* arr, int size);

/*
* \brief - нахождение пары соседних элементов с произведением, равным заданному числу.
* \param couple - заданное число для поиска пар с произведением
* \param counter - счётчик
* \return - массив
*/
int multiplication(int* arr, int size);

enum class path
{
	Manuall = 1,
	Random = 2
};

/*
* \brief Точка входа в программу
* \return Код ошибки(0 - успех)
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество элементов массива - ";
	int size;
	cin >> size;
	int* arr;
	arr = new int[size];

	cout << "Как хотите заполнить массив?" << '\n' << "Введите 1 для заполнения массива с клавиатуры или 2 для заполнения массива случайными числами - ";
	int choice;
	cin >> choice;
	const auto filling = static_cast<path>(choice);
	switch (filling) {
	case path::Random:
	{
		randomDigits(arr, size);
		break;
	}
	case path::Manuall:
	{
		UserInput(arr, size);
		break;
	}
	default:
	{
		cout << "Некоректный ввод.";
		return 0;
	}
	}

	sum(arr, size);
	swapMyArrayPlease(arr, size);
	multiplication(arr, size);

	return 0;
}

int randomDigits(int* arr, int size)
{
	const int UP_BOUND = 1000;
	const int LOW_BOUND = -1000;
	srand(time(NULL));
	int counter = 0;
	while (counter++ < size)
		arr[counter] = rand() % (2 * UP_BOUND + 1) + LOW_BOUND;
	output(arr, size);
	return(arr[size]);
}

int UserInput(int* arr, int size)
{
	int counter = 0;
	while (counter++ < size)
		cin >> arr[counter];
	output(arr, size);
	return(arr[size]);
}

void output(int* arr, int size)
{
	cout << "Ваш массив: ";
	int counter = 0;
	while (counter++ < size)
		cout << arr[counter] << " ";
}

int sum(int* arr, int size)
{
	int total = 0;
	int counter = 0;
	while (counter++ < size)
	{
		if ((arr[counter] < 0) && (arr[counter] % 10 == 0))
			total += arr[counter];
	}
	if (total == 0)
		cout << '\n' << "В массиве нет отрицательных чисел кратных 10.\n";
	else
		cout << '\n' << "Сумма отрицательных элементов массива кратных 10: " << total << ".\n";
	return total;
}

int swapMyArrayPlease(int* arr, int size)
{
	int quantity;
	int buffer;
	int counter = 1;
	cout << "Введите количество первых элементов, которое заменятся на те же переменные, но в обратном порядке: ";
	cin >> quantity;
	for (counter; counter < quantity; counter++, quantity--)
	{
		buffer = arr[counter];
		arr[counter] = arr[quantity];
		arr[quantity] = buffer;
	}
	output(arr, size);
	return arr[counter];
}

int multiplication(int* arr, int size)
{
	cout << "\nВведите число, которое будет значением произведения пар: ";
	int couple;
	cin >> couple;
	int counter = 0;
	int out = 1;
	cout << "Найдены пары: ";
	for (counter; counter < size; counter++)
	{
		if (arr[counter] * arr[counter + 1] == couple)
		{
			cout << "[" << arr[counter] << " " << arr[counter + 1] << "]" << " ";
			out++;
		}
	}
	if (out == 1)
		cout << "пар, произведение которых равно " << couple << ", нет.";
	return arr[size];
}
