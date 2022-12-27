#include "Libraries.h"

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

