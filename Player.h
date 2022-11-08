#pragma once
#include "Libraries.h"

class Maze;
class Player     //���� �������
{
	Vector2i m_position;
	Vector2i cell;
	char m_direction;  //������ "�������" ������
	int size = CELL_SIZE - 4.2 * CELL_SIZE / 5;// 3.6
public:
	Player();
	void setPosition(Vector2i position); //������ �������
	int getcell();
	int getX() { return m_position.x; };
	int getY() { return m_position.y; };
	void draw(RenderWindow& win);    //�����������
	int isCol(Maze a); //�� ������� � �����
	void update(RenderWindow& win, Maze a);  //�������� ��������������� ������
};
