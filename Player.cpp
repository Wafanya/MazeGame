#include "Libraries.h"


Player::Player()
{
	//m_position.x = START_POS; m_position.y = START_POS;
	m_position.x = START_POS + CELL_SIZE / 2.5; m_position.y = 12 + START_POS + CELL_SIZE / 2.5;
}

void Player::draw(RenderWindow& win)
{
	CircleShape circ;
	circ.setRadius(size);
	circ.setOrigin(size, size);
	circ.setFillColor(Color::Yellow);
	circ.setPosition(m_position.x, m_position.y);
	win.draw(circ);
}
void Player::setPosition(Vector2i position)
{
	m_position.x = position.x;
	m_position.y = position.y;
}
int Player::getcell()
{
	for (int i = START_POS, j = 0; i < START_POS + CELL_SIZE * (LENGHT); i += CELL_SIZE, j++)
	{
		for (int m = START_POS + 12, k = 0; m < 12 + START_POS + CELL_SIZE * (WIDTH); m += CELL_SIZE, k++)
		{
			if ((i < getX() && getX() < i + CELL_SIZE) && (m < getY() && getY() < m + CELL_SIZE))
			{
				cell.x = j; cell.y = k;
				goto m1;
			}
		}
	}
m1:
	return cell.x, cell.y;
}


void Player::update(RenderWindow& win, Maze a)
{
	int SPEED = 0;
	//задаЇмо д≥ю на кожну стр≥лочку
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_direction = 1;
		SPEED = NFS;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_direction = 2;
		SPEED = NFS;
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		m_direction = 3;
		SPEED = NFS;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		m_direction = 4;
		SPEED = NFS;
	}


	switch (m_direction)
	{
	case 1://LEFT
	{
		if (isCol(a) == 1)
			m_position.x = m_position.x;
		else
			m_position.x -= SPEED;
		break;
	}
	case 2://RIGHT
	{
		if (isCol(a) == 2)
			m_position.x = m_position.x;
		else
			m_position.x += SPEED;
		break;
	}
	case 3://UP
	{
		if (isCol(a) == 3)
			m_position.y = m_position.y;
		else
			m_position.y -= SPEED;
		break;
	}
	case 4://DOWN
	{
		if (isCol(a) == 4)
			m_position.y = m_position.y;
		else
			m_position.y += SPEED;
		break;
	}
	}
	SPEED = 0;
}

int Player::isCol(Maze a)
{
	getcell();
	MazeCell* current = &a.cellsArray[cell.y][cell.x];
	MazeCell* nextx = &a.cellsArray[cell.y][cell.x + 1];
	MazeCell* nexty = &a.cellsArray[cell.y + 1][cell.x];

	if (current->getWallLeft() && (START_POS + cell.x * CELL_SIZE + size + 2 > m_position.x) && m_direction == 1)return 1;   //лева€ граница +1
	if (nextx->getWallLeft() && (START_POS + (cell.x + 1) * CELL_SIZE - CELL_SIZE / 5 - size - 2 < m_position.x) && m_direction == 2)return 2;   //права€ граница-1
	if ((current->getWallTop()) && (m_position.y < START_POS + cell.y * CELL_SIZE + CELL_SIZE / 5 + size + 2) && m_direction == 3) return 3;   //верхн€€ граница+1
	if ((nexty->getWallTop()) && (m_position.y > START_POS + (cell.y + 1) * CELL_SIZE - size - 2) && m_direction == 4)return 4;   //нижн€€ граница-1
	return 0;
}
