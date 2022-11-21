#pragma once
#include "Libraries.h"

class Frame
{
private:
	int size;
	static RenderWindow w;
	time_t start;
	time_t cur_it;
	time_t delt;
	fstream lb;
	vector<int> time_res;
	static int counter;
	static int choice;
	const Vector2i m_pos[6] = {Vector2i(50,200), Vector2i(40,300), Vector2i(140, 440), Vector2i(60,500), Vector2i(45,600), Vector2i(420,300)};
	/*const Vector2i o_pos;*/
	const Vector2i t_pos = Vector2i(700, 40);
	//const int win_pos;
public:
	Frame() 
	{
		this->size = 10;
		//this->w(VideoMode(1000, 1000), "Maze");
	}
	Frame(int size)
	{
		this->size = size;
	};
	void menu();
	void info();
	void timer();
	void game_player(Player& player, Maze& a);
	void leadboard();
	void main_cycle();
};

