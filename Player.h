#pragma once
#include "Libraries.h"

class Maze;

class Player: public Entity
{
	Vector2i animation;
	int m_direction;  //������ "�������" ������

public:
	Player();
	Player(int n);
	Player(const Player& plyr);
	~Player() {};

	int getDir() const { return m_direction; };
	Player& setdirection(int x) {m_direction=x%4; return *this; };

	void Print()
	{cout << getX() << ' ' << getY() << "|" << getcellx() << ' ' << getcelly() << "|" << getDir() << "|"<< getstartpos()<< endl;};

	void draw(RenderWindow& win);    //�����������
	void update(RenderWindow& win, const Maze &a);  //�������� ��������������� ������
	int isCol(const Maze& a); //�� ������� � �����
	bool isWin() const;
};


