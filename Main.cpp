#pragma once
#include "Libraries.h"



int main()
{
	//test of index operator
	Maze a(8);
	cout << a[1][2].getWallLeft() << "/" << a[2][2].getWallTop() << endl << endl;

	//test of virtual function
	Entity ent(10);
	Player player(4);
	Entity* ptr;
	ptr = &player;
	ptr->Print();


	Frame mf(10);
	mf.main_cycle();
	return 0;
}
