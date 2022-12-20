#pragma once
#include "Libraries.h"

class Maze;

class Player     
{
	Vector2i m_position;
	Vector2i cell;
	Vector2i animation;

	int m_n; //к≥льк≥сть кл≥тин у лаб≥ринт≥. використовуЇтьс€ дл€ п≥драхуванн€ розм≥р≥в ≥ тд
	int cell_size;
	int start_pos;
	int size;
	int m_direction;  //напр€м "погл€ду" гравц€
public:
	Player();
	Player(int n);
	int getcell();
	int getX() const { return m_position.x; };
	int getY() const { return m_position.y; };
	int getDir() const { return m_direction; };
	void draw(RenderWindow& win);    //промальовка
	int isCol(const Maze &a); //чи вр≥завс€ у ст≥нку
	void update(RenderWindow& win, const Maze &a);  //зм≥нювати м≥сцезнаходженн€ гравц€
	bool isWin(const Maze &a) const;
};


