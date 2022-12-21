#pragma once
#include "Libraries.h"


class MazeCell
{
private:
	Vector2i coords;
	bool m_wallTop = true;
	bool m_wallLeft = true;
	int m_n; 
	int cell_size = (1000 - 100) / m_n;

public:
	bool isVisited = false;
	int dist_f_start;
	MazeCell() : m_n(6) { coords.x = cell_size, coords.y = cell_size; };
	MazeCell(int x, int y, int n): m_n(n) { coords.x = x; coords.y = y; };
	void draw(RenderWindow& win) const;

	int getX() const { return coords.x; };
	int getY() const { return coords.y; };

	void setX(int x) { coords.x = x; };
	void setY(int y) { coords.y = y; };

	
	bool getWallTop() const { return m_wallTop; };
	bool getWallLeft() const { return m_wallLeft; };

	void wallTop(bool f) { m_wallTop = f; };
	void wallLeft(bool f) { m_wallLeft = f; };

};

class Maze
{
private:
	int m_n; //������� ����� � �������.
	int cell_size = (1000 - 100) / m_n;; //����� ������
	int start_pos = (1000 - ((m_n - 1) * cell_size - cell_size / 5)) / 2; //����� �������� 
	vector <vector<MazeCell>> cellsArray;
	void generate();
	void place_finish();
public:
	Maze();
	Maze(int size);
	Maze(const Maze& maze);
	~Maze();
	void draw(RenderWindow& win) const;
	friend int Player::isCol(const Maze &a);
};
