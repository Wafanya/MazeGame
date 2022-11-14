#pragma once
#include "Libraries.h"


class MazeCell
{
private:
	Vector2i coords;
	bool m_wallTop = true;
	bool m_wallLeft = true;
	int m_n; 
	int cell_size;

public:
	bool isVisited = false;
	int dist_f_start;
	MazeCell() { m_n = 6; cell_size = (1000 - 100) / m_n; coords.x = cell_size, coords.y = cell_size; };
	MazeCell(int x, int y, int n) { m_n = n; cell_size = (1000 - 100) / m_n; coords.x = x; coords.y = y; };
	void draw(RenderWindow& win);

	int getX() { return coords.x; };
	int getY() { return coords.y; };

	void setX(int x) { coords.x = x; };
	void setY(int y) { coords.y = y; };

	void wallTop(bool f) { m_wallTop = f; };
	void wallLeft(bool f) { m_wallLeft = f; };

	bool getWallTop() { return m_wallTop; };
	bool getWallLeft() { return m_wallLeft; };
};

class Maze
{
private:
	int m_n; //кількість клітин у лабіринті.
	int cell_size; //розмір клітини
	int start_pos; //звідки малювати
	MazeCell cellsArray[30][30];
	void generate();
	void place_finish();
public:
	Maze();
	Maze(int size);
	void draw(RenderWindow& win);
	friend int Player::isCol(Maze a, int& z);
};
