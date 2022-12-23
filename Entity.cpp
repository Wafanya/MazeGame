#include "Libraries.h"


Entity::Entity(): m_n(6)
{
	cell_size = (1000 - 100) / m_n;
	start_pos = (1000 - ((m_n - 1) * cell_size - cell_size / 5)) / 2;
	size = cell_size / 4;
	m_position.x = start_pos + cell_size / 2.5;
	m_position.y = cell_size / 5 + start_pos + cell_size / 2.5;
}

Entity::Entity(int n):m_n(n)
{
	cell_size = (1000 - 100) / m_n;
	start_pos = (1000 - ((m_n - 1) * cell_size - cell_size / 5)) / 2;
	size = cell_size / 4;
	m_position.x = start_pos + cell_size / 2.5;
	m_position.y = cell_size / 5 + start_pos + cell_size / 2.5;
}

Entity::Entity(const Entity& ent):m_n(ent.m_n), m_position(ent.m_position), cell(ent.cell)
{
	cell_size = (1000 - 100) / m_n;
	start_pos = (1000 - ((m_n - 1) * cell_size - cell_size / 5)) / 2;
	size = cell_size / 4;
}

void Entity::draw(RenderWindow& win)
{
	CircleShape circ;
	circ.setRadius(size);
	circ.setOrigin(size, size);
	circ.setFillColor(Color::Cyan);
	circ.move(m_position.x, m_position.y);
	win.draw(circ);
}

int Entity::Fcell()
{
	//cout << getX() << "|" << getY() << endl;
	for (int i = start_pos, j = 0; i <= start_pos + cell_size * (m_n); i += cell_size, j++)
	{
		for (int m = start_pos + cell_size / 5, k = 0; m <= cell_size / 5 + start_pos + cell_size * (m_n); m += cell_size, k++)
		{
			if ((i <= getX() && getX() <= i + cell_size) && (m <= getY() && getY() <= m + cell_size))
			{
				//cout << j <<' '<< k << endl;
				if (j > m_n - 2 or k > m_n - 2) return 0;
				cell.x = j; cell.y = k;
				return 0;
			}
		}
	}
}

