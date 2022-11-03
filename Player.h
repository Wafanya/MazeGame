#pragma once
#include "Libraries.h"

class Maze;
class Player     //клас гравець
{
	Vector2i m_position;
	Vector2i cell;
	char m_direction;  //напр€м "погл€ду" гравц€
	int size = CELL_SIZE - 4.2 * CELL_SIZE / 5;// 3.6
public:
	Player();
	void setPosition(Vector2i position); //зм≥нити позиц≥ю
	int getcell();
	int getX() { return m_position.x; };
	int getY() { return m_position.y; };
	void draw(RenderWindow& win);    //промальовка
	int isCol(Maze a); //чи вр≥завс€ у ст≥нку
	void update(RenderWindow& win, Maze a);  //зм≥нювати м≥сцезнаходженн€ гравц€
};
