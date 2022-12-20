#pragma once
#include "Libraries.h"

class Maze;

class Player     
{
	Vector2i m_position;
	Vector2i cell;
	Vector2i animation;

	int m_n; //������� ����� � �������. ��������������� ��� ����������� ������ � ��
	int cell_size;
	int start_pos;
	int size;
	int m_direction;  //������ "�������" ������
public:
	Player();
	Player(int n);
	int getcell();
	int getX() const { return m_position.x; };
	int getY() const { return m_position.y; };
	int getDir() const { return m_direction; };
	void draw(RenderWindow& win);    //�����������
	int isCol(const Maze &a); //�� ������� � �����
	void update(RenderWindow& win, const Maze &a);  //�������� ��������������� ������
	bool isWin(const Maze &a) const;
};


