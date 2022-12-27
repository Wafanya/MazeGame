#pragma once
#include "Libraries.h"


class Entity {
protected:
	Vector2i cell;
	int m_n; 
	int cell_size = (1000 - 100) / m_n;
	int start_pos = (1000 - ((m_n - 1) * cell_size - cell_size / 5)) / 2;
	int size = cell_size / 4;
	Vector2i m_position = { start_pos + cell_size / 2.5,cell_size / 5 + start_pos + cell_size / 2.5 };
	
public:
	Entity() :m_n(6) {};
	Entity(int n) : m_n(n) {};
	Entity(const Entity& ent) :m_n(ent.m_n), m_position(ent.m_position), cell(ent.cell){};
	virtual ~Entity() {};

	int getstartpos() const { return start_pos; }
	int getcellx() const { return cell.x; };
	int getcelly() const { return cell.y; };
	Entity& setcell(int x, int y) { cell.x = x; cell.y = y; return *this; };

	int getX() const { return m_position.x; };
	int getY() const { return m_position.y; };
	Entity& setposition(int x, int y) { m_position.x = x; m_position.y = y; return *this; };
	virtual void Print() 
	{
		cout << "Print for Entity" << endl;
		cout << getX() << ' ' << getY() << "|" << getcellx() << ' ' << getcelly() << "|" << getstartpos() << endl;};
	void draw(RenderWindow& win);
	int Fcell();
};