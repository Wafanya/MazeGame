#pragma once
#include "Libraries.h"



int main()
{
	Entity q;
	q.Print();
	Entity y(40);
	y.Print();
	Entity v(y);
	v.Print();

	Player c;
	c.Print();
	Player a(10);
	a.Print();
	Player b(a);
	b.Print();

	Date t;
	t.print();
	Date r(12,57,15);
	r.print();
	Date w(t);
	w.print();

	Frame mf(10);
	Frame rf;
	Frame cf(mf);
	mf.print();
	rf.print();
	cf.print();
	Frame::check_m_choice();

	mf.main_cycle();
	return 0;
}
