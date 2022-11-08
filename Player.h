#pragma once
#include "Libraries.h"

class Maze;

class Player     //клас гравець
{
	Vector2i m_position;
	Vector2i cell;
	int m_direction;  //напр€м "погл€ду" гравц€
	int size = CELL_SIZE - 4.2 * CELL_SIZE / 5;// 3.6
public:
	Player();
	int getcell();
	int getX() { return m_position.x; };
	int getY() { return m_position.y; };
	void draw(RenderWindow& win);    //промальовка
	int isCol(Maze a, int& z); //чи вр≥завс€ у ст≥нку
	void update(RenderWindow& win, Maze a);  //зм≥нювати м≥сцезнаходженн€ гравц€
};


