#include <iostream>
#include <string>
#include <random>
#include <sstream>

using namespace std;

/**
* \brief Заполнение массива случайными числами
* \array Массив
* \size Размер массива
* \param min Минимально возможное число
* \param max Максимально возможное число
**/
void randomizeArray(int* array, const size_t size, const int min, const int max);

/**
* \brief Ввод массива с клавиатуры
* \param array Массив
* \param size Размер массива
**/
void manualInput(int* array, const size_t size);

/**
* \brief Конвертация массива строку вида {element_1, element_2, ... ,element_n}
* \param array Массив
* \param size Размер массива
* \param message Сообщение, которое будет выведено перед массивом
**/
string arrayToString(int* array, const size_t size, const string& message = "");

/**
* \brief Определяет чётное ли число
* \param number Число, которое необходимо проверить
* \return True если чётное
**/
bool isEven(const int number);

/**
* \brief Определяет делится ли число на делитель
* \param number Число, которое необходимо проверить
* \param divider Делитель
* \return True если делится без остатка
**/
bool isDivisible(const int number, const int divider);

/**
* \brief Считает сумму отрицательных элементов, значения которых кратно 10
* \param arr Массив
* \param size Размер массива
* \return Сумма элементов
**/
int calcSum(int* arr, const size_t size);

/**
* \brief Замена первых k элементов массива на те же элементы в обратном порядке.
* \param arr Массив
* \param size Размер массива
* \param index первые k элементы (нумерация начинается с нуля)
**/
void replaceElements(int* arr, const size_t size, const size_t index);

/**
* \brief Определяет, есть ли пара соседних элементов с произведением, равным заданному числу.
* \param arr Массив
* \param size Размер массива
* \param number Заданное число
* \return True если существует
**/
bool pairExist(int* arr, const size_t size, const int number);


/**
* \brief Выбор заполнеия массива
**/
enum class FillType
{
    randomize = 1,
    manual = 2
};

int main()
{
    setlocale(LC_ALL, "Russian");
    const int MIN = -1000, MAX = 1000;

    cout << "Please input array length: ";
    size_t size;
    cin >> size;

    int* arr = new int[size];

    cout << "Choose an option:\n" << static_cast<int>(FillType::randomize)<< ") Generate array\n" 
        << static_cast<int>(FillType::manual) << ") Manual input\n" 
        << static_cast<int>(FillType::randomize) <<" or " << static_cast<int>(FillType::manual) << ": ";
    int choice;
    cin >> choice;

    const auto fillType = static_cast<FillType>(choice);

    switch (fillType)
    {
    case FillType::randomize:
    {
        randomizeArray(arr, size, MIN, MAX);
        cout << arrayToString(arr, size, "Your array = ") << "\n";
        break;
    }
    case FillType::manual:
    {
        manualInput(arr, size);
        break;
    }
    default:
        break;
    }

    cout << "Сумма отрицательных элементов, значения которых кратно 10" << calcSum(arr, size) << "\n";

    cout << "Задайте число: ";
    int num;
    cin >> num;
    if (pairExist(arr, size, num))
        cout << "Пара существует\n";
    else
        cout << "Пары не существует\n";

    cout << "Сколько первых элементов заменить? ";
    size_t k;
    cin >> k;
    replaceElements(arr, size, --k);
    cout << "Замена первых " << k << " элементов массива на те же элементы в обратном порядке: " << arrayToString(arr, size) << "\n";

    if (arr != nullptr)
    { 
        delete[] arr;
        arr = nullptr;
    }

}

void randomizeArray(int* array, const size_t size, const int min, const int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    const uniform_int_distribution<> uniformIntDistribution(min, max);

    for (size_t i = 0; i < size; ++i)
        array[i] = uniformIntDistribution(gen);

}

void manualInput(int* array, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << "array[" << i << "] = ";
        cin >> array[i];
    }
}

string arrayToString(int* array, const size_t size, const string& message)
{
    std::stringstream buffer;
    buffer << message << "{" << array[0];

    for (size_t i = 1; i < size; ++i)
    {
        buffer << ", " << array[i];
    }

    buffer << "}";

    return buffer.str();
}

bool isEven(const int number)
{
    return number % 2 == 0;
}

bool isDivisible(const int number, const int divider)
{
    return number % divider == 0;
}

int calcSum(int* arr, const size_t size)
{
    int sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < 0 && isDivisible(arr[i], 10))
            sum += arr[i];
    }

    return sum;
}

void replaceElements(int* arr, const size_t size, const size_t index)
{
    if (index >= size)
        throw out_of_range("Индекс не может быть больше размера массива");

    for (size_t i = 0; i <= index / 2; i++)
        swap(arr[i], arr[index - i]);

}

bool pairExist(int* arr, const size_t size, const int number)
{
    for (size_t i = 0; i < size - 1; i++)
        if (arr[i] * arr[i + 1] == number)
            return true;

    return false;
}
