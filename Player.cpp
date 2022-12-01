#include "Libraries.h"

Player::Player()
{
	m_n = 6; 
	cell_size = (1000 - 100) / m_n;
	start_pos = (1000 - ((m_n - 1) * cell_size - cell_size / 5)) / 2;
	size = cell_size / 5;

	m_direction = 1;
	m_position.x = start_pos + cell_size / 2.5;
	m_position.y = cell_size / 5 + start_pos + cell_size / 2.5;
}
Player::Player(int n)
{
	m_n = n; 
	cell_size = (1000 - 100) / m_n;
	start_pos = (1000 - ((m_n - 1) * cell_size - cell_size / 5)) / 2;
	size = cell_size / 5;

	//m_direction = 1;
	m_position.x = start_pos + cell_size / 2.5;
	m_position.y = cell_size / 5 + start_pos + cell_size / 2.5;
}
void Player::draw(RenderWindow& win) const
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
	for (int i = start_pos, j = 0; i <= start_pos + cell_size * (m_n); i += cell_size, j++)
	{
		for (int m = start_pos + cell_size/5, k = 0; m <= cell_size/5 + start_pos + cell_size * (m_n); m += cell_size, k++)
		{
			if ((i <= getX() && getX() <= i + cell_size) && (m <= getY() && getY() <= m + cell_size))
			{
				cell.x = j; cell.y = k;
				goto m1;
			}
		}
	}
m1:
	return cell.x, cell.y;
}
void Player::update(RenderWindow& win, const Maze &a)
{
	int SPEED = 1;
	//задаЇмо д≥ю на кожну стр≥лочку
	if (Keyboard::isKeyPressed(Keyboard::Left))m_direction = 1;
	if (Keyboard::isKeyPressed(Keyboard::Right))m_direction = 2;
	if (Keyboard::isKeyPressed(Keyboard::Up))m_direction = 3;
	if (Keyboard::isKeyPressed(Keyboard::Down))m_direction = 4;
	for (int s = 0; s < cell_size; s++) {
		switch (m_direction)
		{
		case 1://LEFT
		{
			if (isCol(a) == 1) {
				m_position.x = m_position.x; goto z4; }
			else { m_position.x -= SPEED; }
			break;
		}
		case 2://RIGHT
		{
			if (isCol(a) == 2) {
				m_position.x = m_position.x; goto z4; }
			else { m_position.x += SPEED; }
			break;
		}
		case 3://UP
		{
			if (isCol(a) == 3)
			{m_position.y = m_position.y; goto z4;}
			else { m_position.y -= SPEED; }
			break;
		}
		case 4://DOWN
		{
			if (isCol(a) == 4) 
			{ m_position.y = m_position.y; goto z4; }
			else { m_position.y += SPEED; }
			break;
		}
		}
			draw(win);
	}
 z4:
	if (!isWin(a))
	{
		draw(win);
	}
	m_direction = 0;
}
int Player::isCol(const Maze &a)
{
	getcell();
	const MazeCell* current = &a.cellsArray[cell.y][cell.x];//"."
	const MazeCell* backddx = &a.cellsArray[cell.y + 1][cell.x - 1];//"</"
	const MazeCell* nextudx = &a.cellsArray[cell.y - 1][cell.x + 1];//"/>"
	const MazeCell* nextddx = &a.cellsArray[cell.y + 1][cell.x + 1];//"\>"
	const MazeCell* backx = &a.cellsArray[cell.y][cell.x - 1];//"<"
	const MazeCell* backy = &a.cellsArray[cell.y - 1][cell.x];//"^"
	const MazeCell* nextx = &a.cellsArray[cell.y][cell.x + 1];//">"
	const MazeCell* nexty = &a.cellsArray[cell.y + 1][cell.x];//"<"

	int y1 = start_pos + (cell.y + 1) * cell_size - size;
	int y2 = start_pos + cell.y * cell_size + cell_size / 5 + size;
	int x1 = start_pos + (cell.x + 1) * cell_size - cell_size / 5 - size;
	int x2 = start_pos + cell.x * cell_size + size;

	//cout << x2 << ' ' << x1 << ' ' << y2 << ' ' << y1 << ' ' << getX() << ' ' << getY() << ' ' << cell.y << ' ' << cell.x << ' '<< endl;

	if ((current->getWallLeft() or ((backddx->getWallTop() && !nexty->getWallTop() or nexty->getWallLeft() && !current->getWallLeft()) && (m_position.y >= y1 + 1) or (backx->getWallTop() && !current->getWallTop() or backy->getWallLeft() && !current->getWallLeft()) && (m_position.y <= y2 - 1))) && (m_position.x <= x2) && m_direction == 1)return 1;   //лева€ граница +2

	if ((nextx->getWallLeft() or (nextddx->getWallTop() && !nextx->getWallLeft() && !nextddx->getWallLeft() && (m_position.y >= y1) or nextx->getWallTop() && !nextx->getWallLeft() && !nextudx->getWallLeft() && (m_position.y <= y2 - 1)) && (m_position.x >= x1 + cell_size / 5) or
		((nextddx->getWallTop() && nextddx->getWallLeft() or !nextx->getWallLeft() && nextddx->getWallLeft()) && (m_position.y >= y1 + 1) or (nextx->getWallTop() && nextudx->getWallLeft() or !nextx->getWallLeft() && nextudx->getWallLeft()) && (m_position.y <= y2 - 1))) && (m_position.x >= x1) && m_direction == 2)return 2;  //права€ граница-1

	if ((current->getWallTop() or (nextudx->getWallLeft() && !current->getWallTop() && (m_position.x >= x1 + 1) or nextx->getWallTop() && !current->getWallTop() && (m_position.x >= x1 + cell_size / 5 + 1) or (backy->getWallLeft() && !current->getWallTop() or backx->getWallTop() && !current->getWallTop()) && (m_position.x <= x2 - 1))) && (m_position.y <= y2) && m_direction == 3) return 3;   //верхн€€ граница+1

	if ((nexty->getWallTop() or (!nextddx->getWallLeft() && nextddx->getWallTop() && (m_position.x >= x1 + cell_size / 5 + 1) or !nexty->getWallTop() && nextddx->getWallLeft() && (m_position.x >= x1 + 1) or (backddx->getWallTop() or nexty->getWallLeft() && !nexty->getWallTop()) && (m_position.x <= x2 - 1))) && (m_position.y >= y1 - 1) && m_direction == 4)return 4;   //нижн€€ граница-1



	return 0;
}
bool Player:: isWin(const Maze &a) const
{
	if ((m_position.x < start_pos) || (m_position.y<start_pos) || (m_position.x > 900) || (m_position.y > 900)  )
	{
		 return true;
	}
	else
	{
		return false;
	}
}