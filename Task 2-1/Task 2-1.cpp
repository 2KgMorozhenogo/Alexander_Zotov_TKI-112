#include <iostream>
Int: a, b


cout << "Выберите алгорит замены переменных";
cout << "1 - Замена через 3 переменную";
cout << "2 - Замена через 2 переменные";
cin >> z;
if z == 1;
    F1;
if z == 2 :
    F2;
else :
    cout » Введите 1 или 2

void F1 (a,b) /*Замена 2 переменных через 3 переменную*/
{
    std::cout << "Enter two values: ";

    if (std::cin >> a >> b)
    {
        std::cout << "The original values: a = " << a << ", b = " << b << std::endl;
        int tmp = a;
        a = b;
        b = tmp;
        std::cout << "After swapping: a = " << a << ", b = " << b << std::endl;
    }
    else
    {
        std::cout << "Unexpected error occured" << std::endl;
    }
}
void F2 (a,b) /*Замена 2 переменных между собой*/
{
    setlocale(LC_ALL, "Russian");
    int a, b;
    cout << "Введите а - ";
    cin >> a;
    cout << "Введите b - ";
    cin >> b;
    swap(a, b);
    cout << "Чему равно а - " << a << '\n';
    cout << "Чему равно b - " << b << '\n';
    return(0);
}