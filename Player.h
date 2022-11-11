#pragma once
#include "Libraries.h"

class Maze;

class Player     //клас гравець
{
	Vector2i m_position;
	Vector2i cell;

	int m_n; //к≥льк≥сть кл≥тин у лаб≥ринт≥. маЇ сп≥впадати з к≥льк≥стю в лаб≥ринт≥, очевидно. використовуЇтьс€ дл€ п≥драхуванн€ розм≥р≥в ≥ тд
	int cell_size;
	int start_pos;
	int size;
	int m_direction;  //напр€м "погл€ду" гравц€
public:
	Player();
	Player(int n);
	int getcell();
	int getX() { return m_position.x; };
	int getY() { return m_position.y; };
	void draw(RenderWindow& win);    //промальовка
	int isCol(Maze a, int& z); //чи вр≥завс€ у ст≥нку
	void update(RenderWindow& win, Maze a);  //зм≥нювати м≥сцезнаходженн€ гравц€
};


