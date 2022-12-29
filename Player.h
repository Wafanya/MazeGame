#pragma once
#include "Libraries.h"

class Maze;

class Player : public Entity
{
	Vector2i animation;
	int m_direction;  //напр€м "погл€ду" гравц€

public:
	Player() : Entity() { m_direction = 3; animation.x = 2; animation.y = 4; };
	Player(int n) : Entity(n) { m_direction = 0; animation.x = 0; animation.y = 0; };
	Player(const Player& plyr) : Entity(plyr), m_direction(plyr.m_direction), animation(plyr.animation) {};
	~Player() {};
	operator int() { return m_n; };
	operator Date() { return Date(animation.x, animation.y, m_direction); };
	Player(Date& other) :Entity(other.getDay()), m_direction(other.getMonth()), animation(other.getYear(), other.getYear()) {};

	int getDir() const { return m_direction; };
	Player& setdirection(int x) { m_direction = x % 4; return *this; };
	void Print()
	{
		cout << getX() << ' ' << getY() << "|" << getcellx() << ' ' << getcelly() << "|" << getDir() << "|" << getstartpos() << endl;
	};

	void draw(RenderWindow& win);    //промальовка
	void update(RenderWindow& win, const Maze& a);  //зм≥нювати м≥сцезнаходженн€ гравц€
	int isCol(const Maze& a); //чи вр≥завс€ у ст≥нку
};
