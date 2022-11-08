#include "Libraries.h"

Player::Player()
{
	//m_position.x = START_POS; m_position.y = START_POS;
	m_position.x = START_POS + CELL_SIZE / 2.5; m_position.y = 7 + START_POS + CELL_SIZE / 2.5;
}

void Player::draw(RenderWindow& win)
{
	CircleShape circ;
	circ.setRadius(size);
	circ.setOrigin(size, size);
	circ.setFillColor(Color::Yellow);
	//circ.setPosition(m_position.x, m_position.y);
	circ.move(m_position.x, m_position.y);
	win.draw(circ);
}

int Player::getcell()
{
	for (int i = START_POS, j = 0; i <= START_POS + CELL_SIZE * (LENGHT); i += CELL_SIZE, j++)
	{
		for (int m = START_POS + 7, k = 0; m <= 7 + START_POS + CELL_SIZE * (WIDTH); m += CELL_SIZE, k++)
		{
			if ((i <= getX() && getX() <= i + CELL_SIZE) && (m <= getY() && getY() <= m + CELL_SIZE))
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
	int SPEED = 1;
	//задаЇмо д≥ю на кожну стр≥лочку
	if (Keyboard::isKeyPressed(Keyboard::Left))m_direction = 1;
	if (Keyboard::isKeyPressed(Keyboard::Right))m_direction = 2;
	if (Keyboard::isKeyPressed(Keyboard::Up))m_direction = 3;
	if (Keyboard::isKeyPressed(Keyboard::Down))m_direction = 4;
	for (int s = 0; s < NFS; s++) {
		switch (m_direction)
		{
		case 1://LEFT
		{
			if (isCol(a, m_direction) == 1) { m_position.x = m_position.x; goto z4; }
			else { m_position.x -= SPEED; }
			break;
		}
		case 2://RIGHT
		{
			if (isCol(a, m_direction) == 2) { m_position.x = m_position.x; goto z4; }
			else { m_position.x += SPEED; }
			break;
		}
		case 3://UP
		{
			if (isCol(a, m_direction) == 3)
			{
				m_position.y = m_position.y; goto z4;
			}
			else { m_position.y -= SPEED; }
			break;
		}
		case 4://DOWN
		{
			if (isCol(a, m_direction) == 4) { m_position.y = m_position.y; goto z4; }
			else { m_position.y += SPEED; }
			break;
		}
		}
		draw(win);
	}
z4:
	draw(win);
	m_direction = 0;
}

int Player::isCol(Maze a, int& z)
{
	getcell();
	MazeCell* current = &a.cellsArray[cell.y][cell.x];//"."
	MazeCell* backddx = &a.cellsArray[cell.y + 1][cell.x - 1];//"</"
	MazeCell* nextudx = &a.cellsArray[cell.y - 1][cell.x + 1];//"/>"
	MazeCell* nextddx = &a.cellsArray[cell.y + 1][cell.x + 1];//"\>"
	MazeCell* backx = &a.cellsArray[cell.y][cell.x - 1];//"<"
	MazeCell* backy = &a.cellsArray[cell.y - 1][cell.x];//"^"
	MazeCell* nextx = &a.cellsArray[cell.y][cell.x + 1];//">"
	MazeCell* nexty = &a.cellsArray[cell.y + 1][cell.x];//"<"

	int y1 = START_POS + (cell.y + 1) * CELL_SIZE - size;
	int y2 = START_POS + cell.y * CELL_SIZE + CELL_SIZE / 5 + size;
	int x1 = START_POS + (cell.x + 1) * CELL_SIZE - CELL_SIZE / 5 - size;
	int x2 = START_POS + cell.x * CELL_SIZE + size;

	//cout << x2 << ' ' << x1 << ' ' << y2 << ' ' << y1 << ' ' << getX() << ' ' << getY() << ' ' << cell.y << ' ' << cell.x << ' '<< endl;

	if ((current->getWallLeft() or ((backddx->getWallTop() && !nexty->getWallTop() or nexty->getWallLeft() && !current->getWallLeft()) && (m_position.y >= y1 + 1) or (backx->getWallTop() && !current->getWallTop() or backy->getWallLeft() && !current->getWallLeft()) && (m_position.y <= y2 - 1))) && (m_position.x <= x2) && m_direction == 1)return 1;   //лева€ граница +2

	if ((nextx->getWallLeft() or (nextddx->getWallTop() && !nextx->getWallLeft() && !nextddx->getWallLeft() && (m_position.y >= y1) or nextx->getWallTop() && !nextx->getWallLeft() && !nextudx->getWallLeft() && (m_position.y <= y2 - 1)) && (m_position.x >= x1 + CELL_SIZE / 5) or
		((nextddx->getWallTop() && nextddx->getWallLeft() or !nextx->getWallLeft() && nextddx->getWallLeft()) && (m_position.y >= y1 + 1) or (nextx->getWallTop() && nextudx->getWallLeft() or !nextx->getWallLeft() && nextudx->getWallLeft()) && (m_position.y <= y2 - 1))) && (m_position.x >= x1) && m_direction == 2)return 2;  //права€ граница-1

	if ((current->getWallTop() or (nextudx->getWallLeft() && !current->getWallTop() && (m_position.x >= x1 + 1) or nextx->getWallTop() && !current->getWallTop() && (m_position.x >= x1 + CELL_SIZE / 5 + 1) or (backy->getWallLeft() && !current->getWallTop() or backx->getWallTop() && !current->getWallTop()) && (m_position.x <= x2 - 1))) && (m_position.y <= y2) && m_direction == 3) return 3;   //верхн€€ граница+1

	if ((nexty->getWallTop() or (!nextddx->getWallLeft() && nextddx->getWallTop() && (m_position.x >= x1 + CELL_SIZE / 5 + 1) or !nexty->getWallTop() && nextddx->getWallLeft() && (m_position.x >= x1 + 1) or (backddx->getWallTop() or nexty->getWallLeft() && !nexty->getWallTop()) && (m_position.x <= x2 - 1))) && (m_position.y >= y1 - 1) && m_direction == 4)return 4;   //нижн€€ граница-1


	return 0;
}
