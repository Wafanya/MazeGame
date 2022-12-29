#pragma once
#include "Libraries.h"


class Date
{
private:
	int dd; int mm; int yy;
public:
	Date() : dd(1), mm(1), yy(2023) {};
	Date(int d, int m, int y) : dd(d), mm(m), yy(y) {};
	Date(const Date& date) : dd(date.dd), mm(date.mm), yy(date.yy) {};
	~Date() {};
	void print();

	Date& setDay(int day) { dd = day; return *this; };
	Date& setMonth(int month) { mm = month; return *this; };
	Date& setYear(int year) { yy = year; return *this; };
	int getDay() { return dd; };
	int getMonth() { return mm; };
	int getYear() { return yy; };
	Date operator++();
	Date operator++(int i);
	Date operator--();
	Date operator--(int i);
	Date operator+(const Date& other);
	bool operator != (const Date& other);
	bool operator == (const Date& other);
	bool operator > (const Date& other);
	bool operator < (const Date& other);
	Date operator = (Date other);
	friend std::ostream& operator<< (std::ostream& out, const Date& obj);
	friend std::istream& operator>> (std::istream& in, Date& obj);
};
