#include "Libraries.h"

Player::Player() : Entity()
{
	m_direction = 3;
}
Player::Player(int n): Entity(n)
{
	m_direction = 0;
}
Player::Player(const Player& plyr): m_direction(plyr.m_direction){
	this->start_pos = plyr.start_pos;
	this->m_position = plyr.m_position;
	this->cell = plyr.cell;
}


void Player::draw(RenderWindow& win)
{
	//cout << "Draw for Player" << endl;
	Texture text;
	text.loadFromFile("CATS.png");
	text.setSmooth(true);
	Sprite sprite;
	sprite.setTexture(text);

	if (animation.x >= 4)animation.x -= 4;
	sprite.setTextureRect(IntRect(0, 288 * animation.x, 261, 288));
	sprite.setOrigin(130.5, 144);

	sprite.setScale(cell_size / 500.0, cell_size / 500.0);
	sprite.move(m_position.x, m_position.y);
	win.draw(sprite);
}


void Player::update(RenderWindow& win, const Maze &a)
{
	int SPEED = 1;
	//������ �� �� ����� ��������
	if (Keyboard::isKeyPressed(Keyboard::Left)) { m_direction = 1; animation.y++; }
	if (Keyboard::isKeyPressed(Keyboard::Right)) { m_direction = 2; animation.y++; }
	if (Keyboard::isKeyPressed(Keyboard::Up)) { m_direction = 3; animation.y++; }
	if (Keyboard::isKeyPressed(Keyboard::Down)) { m_direction = 4; animation.y++; }

	for (int s = 0; s <cell_size/6; s++) {
		switch (m_direction)
		{
		case 1://LEFT
		{
			if (isCol(a) == 1) {
				m_position.x = m_position.x; goto z4;
			}
			else { m_position.x -= SPEED; }
			break;
		}
		case 2://RIGHT
		{
			if (isCol(a) == 2) {
				m_position.x = m_position.x; goto z4;
			}
			else { m_position.x += SPEED; }
			break;
		}
		case 3://UP
		{
			if (isCol(a) == 3)
			{
				m_position.y = m_position.y; goto z4;
			}
			else { m_position.y -= SPEED; }
			break;
		}
		case 4://DOWN
		{
			if (isCol(a) == 4)
			{
				m_position.y = m_position.y; goto z4;
			}
			else { m_position.y += SPEED; }
			break;
		}
		}
	}
z4:
	if (animation.y > 6) {
		animation.y = 0;
		animation.x++;
	}
	if (!isWin())
	{
		draw(win);
	}
	m_direction = 0;
}
int Player::isCol(const Maze& a)
{
	Fcell();
	const MazeCell* current = &a.cellsArray[cell.y][cell.x];//"."
	const MazeCell* backddx = &a.cellsArray[cell.y + 1][abs(cell.x - 1)];//"</"
	const MazeCell* nextudx = &a.cellsArray[abs(cell.y - 1)][cell.x + 1];  //"/>" 
	const MazeCell* nextddx = &a.cellsArray[cell.y + 1][cell.x + 1];//"\>
	const MazeCell* backx = &a.cellsArray[cell.y][abs(cell.x - 1)]; //"<"
	const MazeCell* backy = &a.cellsArray[abs(cell.y - 1)][cell.x]; //"^"
	const MazeCell* nextx = &a.cellsArray[cell.y][cell.x + 1];//">"
	const MazeCell* nexty = &a.cellsArray[cell.y + 1][cell.x];//"<"

	int y1 = start_pos + (cell.y + 1) * cell_size - size;
	int y2 = start_pos + cell.y * cell_size + cell_size / 5 + size;
	int x1 = start_pos + (cell.x + 1) * cell_size - cell_size / 5 - size;
	int x2 = start_pos + cell.x * cell_size + size;

	//cout << x2 << ' ' << x1 << ' ' << y2 << ' ' << y1 << ' ' << getX() << ' ' << getY() << ' ' << cell.y << ' ' << cell.x << ' ' << endl;

	if ((current->getWallLeft() or ((backddx->getWallTop() && !nexty->getWallTop() or nexty->getWallLeft() && !current->getWallLeft()) && (m_position.y >= y1 + 1) or (backx->getWallTop() && !current->getWallTop() or backy->getWallLeft() && !current->getWallLeft()) && (m_position.y <= y2 - 1))) && (m_position.x <= x2) && m_direction == 1)return 1;   //����� ������� +2

	if ((nextx->getWallLeft() or (nextddx->getWallTop() && !nextx->getWallLeft() && !nextddx->getWallLeft() && (m_position.y >= y1) or nextx->getWallTop() && !nextx->getWallLeft() && !nextudx->getWallLeft() && (m_position.y <= y2 - 1)) && (m_position.x >= x1 + cell_size / 5) or
		((nextddx->getWallTop() && nextddx->getWallLeft() or !nextx->getWallLeft() && nextddx->getWallLeft()) && (m_position.y >= y1 + 1) or (nextx->getWallTop() && nextudx->getWallLeft() or !nextx->getWallLeft() && nextudx->getWallLeft()) && (m_position.y <= y2 - 1))) && (m_position.x >= x1) && m_direction == 2)return 2;  //������ �������-1

	if ((current->getWallTop() or (nextudx->getWallLeft() && !current->getWallTop() && (m_position.x >= x1 + 1) or nextx->getWallTop() && !current->getWallTop() && (m_position.x >= x1 + cell_size / 5 + 1) or (backy->getWallLeft() && !current->getWallTop() or backx->getWallTop() && !current->getWallTop()) && (m_position.x <= x2 - 1))) && (m_position.y <= y2) && m_direction == 3) return 3;   //������� �������+1

	if ((nexty->getWallTop() or (!nextddx->getWallLeft() && nextddx->getWallTop() && (m_position.x >= x1 + cell_size / 5 + 1) or !nexty->getWallTop() && nextddx->getWallLeft() && (m_position.x >= x1 + 1) or (backddx->getWallTop() or nexty->getWallLeft() && !nexty->getWallTop()) && (m_position.x <= x2 - 1))) && (m_position.y >= y1 - 1) && m_direction == 4)return 4;   //������ �������-1

	return 0;
}
bool Player::isWin() const
{
	if ((m_position.x < start_pos) || (m_position.y<start_pos) || (m_position.x > cell_size / 5 + start_pos + cell_size * (m_n)) || (m_position.y > cell_size / 5 + start_pos + cell_size * (m_n))  )
	{
		 return true;
	}
	else
	{
		return false;
	}
}