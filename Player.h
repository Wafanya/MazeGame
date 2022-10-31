#pragma once
#include "Libraries.h"

struct Position				//координати гравц€
{
	unsigned int x; unsigned int y;
};

class Player     //клас гравець
{
	Position m_position;
	char m_direction;  //напр€м "погл€ду" гравц€
	int size = CELL_SIZE - 3.5 * CELL_SIZE / 5;
public:
	void setPosition(Position position, RenderWindow& win); //зм≥нити позиц≥ю
	Player();
	void draw(RenderWindow& win);    //промальовка
	bool isCol(RenderWindow& win); //чи вр≥завс€ у ст≥нку
	void update(RenderWindow& win);  //зм≥нювати м≥сцезнаходженн€ гравц€

};
