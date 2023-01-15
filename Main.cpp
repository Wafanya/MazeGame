#pragma once
#include "Libraries.h"

template <class T>
class MyNumber
{
public:
    // �����������
    MyNumber(void) { }

    // �����, �� ������� �� 2 �����
    void Mult2(T* t) {
        *t = (*t) * 2;
    };

    // �����, �� ������� ������� ����� ��� ������� ���� T
    T MySquare(T number) {
        return (T)(number * number);
    };

    // �����, �� ����� ��� ����� ���� T � ������� ��������� ���� T
    T DivNumbers(T t1, T t2)
    {
        return (T)(t1 / t2);
    };
};



int main()
{
    MyNumber <int> i; // ��'��� i ����� ������ � ����� int
    MyNumber <float> f; // ��'��� f ������ � ����� float

    int d = 8;
    float x = 9.3f;

    // �������� ����� �� 2
    i.Mult2(&d); // d = 16
    f.Mult2(&x); // x = 18.6

    // ������ �������� � �����
    int dd = i.MySquare(9); // dd = 81 - ���� �����
    double z = f.MySquare(1.1); // z = 1.21000... - ����� �����

    // ������ �����
    long int a = i.DivNumbers(5, 2); // t = 2 - ������ ����� �����
    float b = f.DivNumbers(5, 2); // f = 2.5 - ������ ������ �����
    
    Frame mf(10);
	mf.main_cycle();
	return 0;
}
