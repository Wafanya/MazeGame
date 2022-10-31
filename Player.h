#pragma once
#include "Libraries.h"

struct Position				//���������� ������
{
	unsigned int x; unsigned int y;
};

class Player     //���� �������
{
	Position m_position;
	char m_direction;  //������ "�������" ������
	int size = CELL_SIZE - 3.5 * CELL_SIZE / 5;
public:
	void setPosition(Position position, RenderWindow& win); //������ �������
	Player();
	void draw(RenderWindow& win);    //�����������
	bool isCol(RenderWindow& win); //�� ������� � �����
	void update(RenderWindow& win);  //�������� ��������������� ������

};
