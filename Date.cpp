#include "Libraries.h"

void Date::print()
{
	cout << dd << "/" << mm << "/" << yy << endl;
}

Date Date::operator++()
{
	if ((mm == 4 or mm == 6 or mm == 9 or mm == 11) and dd == 30)
	{
		dd = 0;
		mm++;
	}
	if (dd == 31) { mm++; dd = 1; }
	if (mm == 13)
	{
		mm = 1;
		yy++;
	}
	if (mm == 2)
	{
		if ((yy % 4 == 0 and dd == 29) or (yy % 4 != 0 and dd == 28))
		{
			mm++;
			dd = 0;
		}
	}
	dd++;
	return *this;
}

Date Date::operator++(int i)
{
	if ((mm == 4 or mm == 6 or mm == 9 or mm == 11) and dd == 30)
	{
		dd = 0;
		mm++;
	}
	if (dd == 31) { mm++; dd = 0; }
	if (mm == 13)
	{
		mm = 1;
		yy++;
	}
	if (mm == 2)
	{
		if ((yy % 4 == 0 and dd == 29) or (yy % 4 != 0 and dd == 28))
		{
			mm++;
			dd = 0;
		}
	}
	dd++;
	return *this;
}

Date Date::operator--()
{
	if ((mm == 5 or mm == 7 or mm == 10 or mm == 12) and dd == 1)
	{
		dd = 31;
		mm--;
	}
	else
	{
		if (yy % 4 == 0 and mm == 3 and dd == 1)
		{
			dd = 30;
			mm = 2;
		}
		if (yy % 4 != 0 and mm == 3 and dd == 1)
		{
			dd = 29;
			mm = 2;
		}
	}
	if (mm == 1 and dd == 1)
	{
		mm = 12;
		yy--;
		dd = 32;
	}
	if (dd == 1)
	{
		mm--;
		dd = 32;
	}
	dd--;
	return *this;
}

Date Date::operator--(int i)
{
	if ((mm == 5 or mm == 7 or mm == 10 or mm == 12) and dd == 1)
	{
		dd = 31;
		mm--;
	}
	else
	{
		if (yy % 4 == 0 and mm == 3 and dd == 1)
		{
			dd = 30;
			mm = 2;
		}
		if (yy % 4 != 0 and mm == 3 and dd == 1)
		{
			dd = 29;
			mm = 2;
		}
	}
	if (mm == 1 and dd == 1)
	{
		mm = 12;
		yy--;
		dd = 32;
	}
	if (dd == 1)
	{
		mm--;
		dd = 32;
	}
	dd--;
	return *this;
}

Date Date::operator+(const Date& other)
{
	Date temp;
	temp.dd = this->dd + other.dd;
	temp.mm = this->mm + other.mm;
	temp.yy = this->yy + other.yy;
	return temp;
}

bool Date::operator!=(const Date& other)
{
	return !(this->dd == other.dd && this->dd == other.dd && this->dd == other.dd);
}

bool Date::operator==(const Date& other)
{
	return (this->dd == other.dd && this->dd == other.dd && this->dd == other.dd);
}

bool Date::operator>(const Date& other)
{
	if (this->yy > other.yy) { return true; }
	else
	{
		if (this->yy == other.yy)
		{
			if (this->mm > other.mm)
			{
				return true;
			}
			else
			{
				if (this->mm == other.mm)
				{
					return (this->dd > other.dd);
				}
			}
		}
	}
	return false;
}

bool Date::operator<(const Date& other)
{
	if (this->yy < other.yy) { return true; }
	else
	{
		if (this->yy == other.yy)
		{
			if (this->mm < other.mm)
			{
				return true;
			}
			else
			{
				if (this->mm == other.mm)
				{
					return (this->dd < other.dd);
				}
			}
		}
	}
	return false;
}

Date Date::operator=(Date other)
{
	this->dd = other.dd;
	this->mm = other.mm;
	this->yy = other.yy;
	return Date();
}


ostream& operator<<(std::ostream& out, const Date& obj)
{
	out << "Date: " << obj.dd << "/" << obj.mm << "/" << obj.yy << endl;
	return out;
}

std::istream& operator>>(std::istream& in, Date& obj)
{
	in >> obj.dd;
	in >> obj.mm;
	in >> obj.yy;
	return in;
}
