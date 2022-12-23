#pragma once
#include "Libraries.h"

class Date
{
private:
	int dd; int mm; int yy;
public:
	Date() : dd(21), mm(12), yy(2022) {};
	Date(int d, int m, int y) : dd(d), mm(m), yy(y) {};
	Date(const Date& date): dd(date.dd), mm(date.mm), yy(date.yy) {};
	~Date() {};
	void print();

	Date& setDay(int day) { dd = day; return *this; };
	Date& setMonth(int month) { mm = month; return *this; };
	Date& setYear(int year) { yy = year; return *this; };
	int getDay() { return dd; };
	int getMonth() { return mm; };
	int getYear() { return yy; };
	

};
