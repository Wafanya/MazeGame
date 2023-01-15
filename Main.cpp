#pragma once
#include "Libraries.h"

template <class T>
class MyNumber
{
public:
    // конструктор
    MyNumber(void) { }

    // метод, що множить на 2 число
    void Mult2(T* t) {
        *t = (*t) * 2;
    };

    // метод, що повертає квадрат числа для деякого типу T
    T MySquare(T number) {
        return (T)(number * number);
    };

    // метод, що ділить два числа типу T і повертає результат типу T
    T DivNumbers(T t1, T t2)
    {
        return (T)(t1 / t2);
    };
};



int main()
{
    MyNumber <int> i; // об'єкт i класу працює з типом int
    MyNumber <float> f; // об'єкт f працює з типом float

    int d = 8;
    float x = 9.3f;

    // множення числа на 2
    i.Mult2(&d); // d = 16
    f.Mult2(&x); // x = 18.6

    // взяття квадрату з числа
    int dd = i.MySquare(9); // dd = 81 - ціле число
    double z = f.MySquare(1.1); // z = 1.21000... - дійсне число

    // ділення чисел
    long int a = i.DivNumbers(5, 2); // t = 2 - ділення цілих чисел
    float b = f.DivNumbers(5, 2); // f = 2.5 - ділення дійсних чисел
    
    Frame mf(10);
	mf.main_cycle();
	return 0;
}
