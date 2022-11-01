#include "Libraries.h"

Player::Player()
{
	m_position.x = START_POS; m_position.y = START_POS+CELL_SIZE/5;
}
void Player::draw(RenderWindow& win)
{
	CircleShape circ(size);
	circ.setFillColor(Color::Yellow);
	circ.setPosition(m_position.x, m_position.y);
	win.draw(circ);
}
void Player::setPosition(Vector2i position, RenderWindow& win)
{
	m_position.x = position.x;
	m_position.y = position.y;
}
void Player::update(RenderWindow& win)
{
	//задаємо дію на кожну стрілочку
	if (1 == Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_direction = 0;
	}
	if (1 == Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_direction = 1;
	}
	if (1 == Keyboard::isKeyPressed(Keyboard::Down))
	{
		m_direction = 2;
	}
	if (1 == Keyboard::isKeyPressed(Keyboard::Up))
	{
		m_direction = 3;
	}
	switch (m_direction)
	{
	case 0:
	{
		if (!m_position.x > 0) //врізався в екран
			m_position.x = 0;
		else
			m_position.x -= SPEED;
		break;
	}
	case 1:
	{
		if (m_position.x > win.getSize().x - 2 * size) //врізався в екран
			m_position.x = win.getSize().x - 2 * size;
		else
			m_position.x += SPEED;
		break;
	}
	case 2:
	{
		if (m_position.y > win.getSize().y - 2 * size) //врізався в екран
			m_position.y = win.getSize().y - 2 * size;
		else
			m_position.y += SPEED;
		break;
	}
	case 3:
	{
		if (!m_position.y > 0) //врізався в екран
			m_position.y = 0;
		else
			m_position.y -= SPEED;
		break;
	}

	} 
}
bool Player::isCol(RenderWindow& win) //тута треба написати функцію чи зіткається гравець зі стінками лабіринту
{
	return 1;
	return 0;
}
