#pragma once
#include "Libraries.h"

int main()
{
	//test of index operator
	Maze a(8);
	cout << a[1][2].getWallLeft() << "/" << a[2][2].getWallTop() << endl;

	//test of virtual function
	Entity ent(10);
	Player player(4);
	Entity* ptr;
	ptr = &player;
	ptr->Print();

	cout << "--------------------------------------------------->" << endl;

	int b = 9;
	Player(b).Print();
	Player w;
	cout << int(w) << endl;

	Player c;
	Date(c).print();
	Date f(12, 34, 2024);
	Player(f).Print();

	cout << "--------------------------------------------------->" << endl;

	Date t;
	t--;
	t.print();
	Date p, k;
	k = t + p;
	k.print();
	Date l, m;
	cout << int(l != m) << "   " << int(l == m) << endl;
	Date y(1, 2, 2023);
	cout << int(y < l) << "   " << int(y > l) << endl;
	Date o;
	o = f;
	cout << o << "Enter the date" << endl;
	//cin >> m;
	//cout << m;

	Frame mf(10);
	mf.main_cycle();
	return 0;
}
