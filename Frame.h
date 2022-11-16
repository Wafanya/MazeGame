#pragma once
#include "Libraries.h"

class Frame
{
private:
	int size;
	static RenderWindow w;
	static int counter;
	static int choice;
	/*static const struct ElemInfo {
		Vector2i m_pos[5];
		Vector2i m_size[5];
		Vector2i o_pos;
		Vector2i p_pos;
		int t_pos;
		int win_pos;
	}ElIn; */
	const Vector2i m_pos[5] = {Vector2i(50,200), Vector2i(40,300), Vector2i(100,400), Vector2i(45,500), Vector2i(420,300)};
	//const Vector2i m_size[5] = {Vector2i(600,200), Vector2i(600,200), Vector2i(100,100), Vector2i(100,100), Vector2i(100,100)};
	/*const Vector2i o_pos;
	const Vector2i p_pos;*/
	//const int t_pos;
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
	void options();
	void pause();
	void timer();
	void game_player(Player& player, Maze& a);
	void win();
	void main_cycle();
	/*RenderWindow& operator= (RenderWindow a(VideoMode vm, const char* s))
	{
		this->w.create(vm, s);
	}*/
};

