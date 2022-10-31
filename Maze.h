#pragma once
#include "Libraries.h"

class MazeCell
{
private:	
	Vector2i coords;
public:
	bool wallTop = true;
	bool wallLeft = true;
	bool isVisited = false;
	MazeCell() { coords.x = CELL_SIZE, coords.y = CELL_SIZE; };
	MazeCell(int x, int y) { coords.x = x; coords.y = y; };
	int getX() { return coords.x; }; int getY() { return coords.y; };
	void draw(RenderWindow& win);
};

class Maze
{
private:	
	MazeCell cellsArray[LENGHT][WIDTH];
	void generate();
public:
	Maze();
	void draw(RenderWindow& win);
};
