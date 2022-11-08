#pragma once
#include "Libraries.h"


class MazeCell
{
private:
	Vector2i coords;
	bool m_wallTop = true;
	bool m_wallLeft = true;
public:

	bool isVisited = false;
	MazeCell() { coords.x = CELL_SIZE, coords.y = CELL_SIZE; };
	MazeCell(int x, int y) { coords.x = x; coords.y = y; };
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
	MazeCell cellsArray[LENGHT][WIDTH];
	void generate();
public:
	Maze();
	void draw(RenderWindow& win);
	friend int Player::isCol(Maze a, int& z);
};
