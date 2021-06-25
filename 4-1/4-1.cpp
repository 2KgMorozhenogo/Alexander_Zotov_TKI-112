
#include <iostream>
#include <string>
#include <ctime>
using namespace std;


/**
* \brief Найти сумму отрицательных элементов, значение которых равно 10.
* \param sum - Переменная для суммы отрицательных элементов массива кратных 10
*/ 
int sum(int* arr, int number);

/**
* \brief Заменить первые k элементов массива на те же элементы в обратном порядке
* \param k - Переменная для выбора кол-ва элементов для переворота массива
* \param j - Переменная для перемены мест элементов в массиве
*/
int swap(int* arr, int number);

/**
* \brief Определить, есть ли пара соседних элементов с произведением, равным заданному числу.
* \param b - Переменная для поиска пар с произведением
*/
int product(int* arr, int number);

/**
* \brief вывод массива
* \return массив
*/
int conclusion(int* arr, int counter);

/**
* \brief вывод перевернутого массива
* \return перевернутый массив
*/
int swap_output(int* arr, int counter, int number);

/**
*  \brief заполнение массива случайными числами
*/
void randomDigits(int* arr, int counter, int number, int UP_BOUND, int LOW_BOUND);

/**
*  \brief заполнение массива с клавиатуры
*/
void UserInput(int* arr, int counter, int number, int UP_BOUND, int LOW_BOUND);

enum path
{
    Manuall = 1,
    Random = 2
};

/**
* \brief Точка входа в программу
* \return Код ошибки(0 - успех)
*/
int main()
{
    int number, choice, counter;
    setlocale(LC_ALL, "Russian");
    cout << "Введите количество элементов массива - ";
    cin >> number;    
    int* arr = new int[number];
    const int UP_BOUND = 1000;
    const int LOW_BOUND = -1000; 
    cout << "Как хотите заполнить массив?" << '\n' << "Введите 1 для заполнения массива с клавиатуры или 2 для заполнения массива случайными числами - ";
    cin >> choice;
    const auto filling = static_cast<path>(choice);
    switch (filling) {
    case path::Random:
    {
        randomDigits(arr, counter, number, UP_BOUND, LOW_BOUND);
    }
    case path::Manuall:
    {
        UserInput(arr, counter, number, UP_BOUND, LOW_BOUND);
    }
    default:
        cout << "Некоректный ввод.";
    }
    cout << "Ваш массив:"; //вывод массива на экран

    for (int counter = 0; counter < number; counter++)
    {
        cout << arr[counter] << " ";
    }

    conclusion(arr, counter);

    sum(arr, number);

    swap(arr, number);

    product(arr, number);

}   

int sum(int* arr, int number)
{
    int sum;
    sum = 0;
    for (int counter = 0; counter < number; counter++)
    {
        if (arr[counter] < 0 and arr[counter] % 10 == 0)
        {
            sum = sum + arr[counter];
        }
    }
    cout << '\n' << "Сумма отрицательных элементов массива кратных 10: " << sum << '\n';
}

int swap(int* arr, int number, int counter)
{
    int quantity, buffer;
    cout << "Введите количество первых элементов, которое заменятся на те же переменные, но в обратном порядке - ";
    cin >> quantity;
    quantity -= 1;
    for (int counter = 0; counter < quantity; counter++) //переворот k элементов массива
    {
        buffer = arr[counter];
        arr[counter] = arr[quantity - counter];
        arr[quantity - counter] = buffer;

    }

    swap_output(arr, quantity, number);
}

int product(int* arr, int number)
{
    int couple;
    cout << '/n' << "Введите число, которое будет значением произведения пар - ";
    cin >> couple;

    for (int counter = 0; counter < number - 1; counter++)
    {
        if (arr[counter] * arr[counter + 1] == couple)
        {
            return couple, arr[counter], arr[counter + 1];
        }
        else
        {
            return 0;
        }
    }

}

int conclusion(int* arr, int counter, int number)
{
    cout << "Ваш массив: ";
    for (counter = 0; counter < number; counter++)
    {
        cout << arr[counter];
    }
}

int swap_output(int* arr, int counter, int number)
{
    cout << "Первернутый массив: ";
    for (counter = 0; counter < number; counter++)
    {
        cout << arr[counter];
    }
}

void randomDigits(int* arr, int counter, int number, int UP_BOUND, int LOW_BOUND)
{
    for (counter  = 0; counter < number; counter++) 
    {
        arr[counter] = rand() % (2 * UP_BOUND + 1) + LOW_BOUND;
    }
}

void UserInput(int* arr, int counter, int number, int UP_BOUND, int LOW_BOUND)
{
    for (counter = 0; counter < number; counter++)
    {
        cin >> arr[counter];
    }
}
