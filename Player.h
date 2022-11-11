#pragma once
#include "Libraries.h"

class Maze;

class Player     //���� �������
{
	Vector2i m_position;
	Vector2i cell;

	int m_n; //������� ����� � �������. �� ��������� � ������� � �������, ��������. ��������������� ��� ����������� ������ � ��
	int cell_size;
	int start_pos;
	int size;
	int m_direction;  //������ "�������" ������
public:
	Player();
	Player(int n);
	int getcell();
	int getX() { return m_position.x; };
	int getY() { return m_position.y; };
	void draw(RenderWindow& win);    //�����������
	int isCol(Maze a, int& z); //�� ������� � �����
	void update(RenderWindow& win, Maze a);  //�������� ��������������� ������
};


