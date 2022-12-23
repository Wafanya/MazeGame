#pragma once
#include "Libraries.h"


class Entity {
protected:
	Vector2i m_position;
	Vector2i cell;

	int m_n; //кількість клітин у лабіринті. використовується для підрахування розмірів і тд
	int cell_size;
	int start_pos;
	int size;
public:
	Entity();
	Entity(int n);
	Entity(const Entity& ent);
	~Entity() {};

	int getstartpos() { return start_pos; }

	int getcellx() { return cell.x; };
	int getcelly() { return cell.y; };
	Entity& setcell(int x, int y) { cell.x = x; cell.y = y; return *this; };

	int getX() const { return m_position.x; };
	int getY() const { return m_position.y; };
	Entity& setpositoin(int x, int y) { m_position.x = x; m_position.y = y; return *this; };
	void Print()
	{cout << getX() << ' ' << getY() << "|" << getcellx() << ' ' << getcelly() << "|" << getstartpos() << endl;};

	void draw(RenderWindow& win);
	int Fcell();
};