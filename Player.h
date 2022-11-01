#pragma once
#include "Libraries.h"



class Player     //���� �������
{
	Vector2i m_position;
	char m_direction;  //������ "�������" ������
	int size = CELL_SIZE - 3.5 * CELL_SIZE / 5;
public:
	void setPosition(Vector2i position, RenderWindow& win); //������ �������
	Player();
	void draw(RenderWindow& win);    //�����������
	bool isCol(RenderWindow& win); //�� ������� � �����
	void update(RenderWindow& win);  //�������� ��������������� ������

};
