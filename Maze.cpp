#include "Libraries.h"

Maze::Maze(): m_n(6)
{
	cellsArray.resize(m_n, vector<MazeCell>(m_n));
	for (int y = start_pos; y < start_pos + m_n * cell_size; y += cell_size)
	{
		for (int x = start_pos; x < start_pos + m_n * cell_size; x += cell_size)
		{
			MazeCell a(x, y, m_n);
			cellsArray[(y - start_pos) / cell_size][(x - start_pos) / cell_size] = a;

		}
	}

	for (int i = 0; i < m_n; i++) // видалємо зайві бічні стінки
	{
		cellsArray[i][m_n - 1].wallTop(false);
		cellsArray[i][m_n - 1].isVisited = true;

	}
	for (int j = 0; j < m_n; j++) // видалємо зайві бічні стінки
	{
		cellsArray[m_n - 1][j].wallLeft(false);
		cellsArray[m_n - 1][j].isVisited = true;
	}
	generate();
} 
Maze::Maze(int n): m_n(n)
{
	MazeCell a(start_pos, start_pos, m_n);
	cellsArray.resize(m_n,  vector<MazeCell>(m_n,a));
	
	for (int y = start_pos; y < start_pos + m_n * cell_size; y += cell_size) //заповнюємо вектор
	{
		for (int x = start_pos; x < start_pos + m_n * cell_size; x += cell_size)
		{
			MazeCell a(x, y, m_n);
			cellsArray[(y - start_pos) / cell_size][(x - start_pos) / cell_size] = a;

		}
	}

	for (int i = 0; i < m_n; i++) // видалємо зайві бічні стінки
	{
		cellsArray[i][m_n - 1].wallTop(false);
		cellsArray[i][m_n - 1].isVisited = true;

	}
	for (int j = 0; j < m_n; j++) // видалємо зайві бічні стінки
	{
		cellsArray[m_n - 1][j].wallLeft(false);
		cellsArray[m_n - 1][j].isVisited = true;
	}
	generate();
}
Maze::Maze(const Maze& maze): m_n(maze.m_n)
{
	cellsArray.resize(m_n, vector<MazeCell>(m_n));
	for (int y = start_pos; y < start_pos + m_n * cell_size; y += cell_size) //заповнюємо вектор
	{
		for (int x = start_pos; x < start_pos + m_n * cell_size; x += cell_size)
		{
			cellsArray[(y - start_pos) / cell_size][(x - start_pos) / cell_size] = maze.cellsArray[(y - start_pos) / cell_size][(x - start_pos) / cell_size];
		}
	}

}
Maze::~Maze(){}
void Maze::draw(RenderWindow& win) const
{
	for (int y = 0; y < m_n; y++)
	{
		for (int x = 0; x < m_n; x++)
		{
			cellsArray[y][x].draw(win);
		}
	}
}
void Maze::generate() //генерація лабіринту шляхом видалення стін у сітці
{
	MazeCell* current = &cellsArray[0][0];
	int random;
	current->isVisited = true;
	current->dist_f_start = 0;
	stack <MazeCell*> stack;
	do
	{
		list <MazeCell*> unvisitedNeighbours;
		int x = ((current->getX() - start_pos) / cell_size);
		int y = ((current->getY() - start_pos) / cell_size);
		//cout << "[" << x << "]" << "[" << y << "]" << endl;
		if ((y > 0) && (!cellsArray[y - 1][x].isVisited)) unvisitedNeighbours.push_back(&cellsArray[y - 1][x]); //перевірка чи є невідвідані сусіди
		if ((x > 0) && (!cellsArray[y][x - 1].isVisited)) unvisitedNeighbours.push_back(&cellsArray[y][x - 1]);
		if ((y < m_n - 2) && (!cellsArray[y + 1][x].isVisited)) unvisitedNeighbours.push_back(&cellsArray[y + 1][x]);
		if ((x < m_n - 2) && (!cellsArray[y][x + 1].isVisited)) unvisitedNeighbours.push_back(&cellsArray[y][x + 1]);

		if (unvisitedNeighbours.size() > 0)
		{
			MazeCell* chosen;
			random = rand() % unvisitedNeighbours.size(); //обираємо випадкового невідвіданого сусіда
			list<MazeCell*>::iterator i = unvisitedNeighbours.begin();
			advance(i, random);
			chosen = *i;
			if (current->getX() == chosen->getX()) //зносимо між ними стінку
			{
				if (current->getY() > chosen->getY()) { current->wallTop(false); }
				else { chosen->wallTop(false); }
			}
			else
			{
				if (current->getX() > chosen->getX()) { current->wallLeft(false); }
				else { chosen->wallLeft(false); }

			}

			chosen->isVisited = true; //тепер сусід стає новою клітинкою
			chosen->dist_f_start = stack.size();
			stack.push(chosen);
			current = chosen;
			
		}
		else
		{
			current = stack.top();
			stack.pop();
		}

	} while (stack.size() > 0);
	place_finish();
}
void Maze::place_finish()
{
	MazeCell *furthest = &cellsArray[0][0];
	for (int y = 0; y < m_n; y++)
	{
		if (cellsArray[y][m_n - 2].dist_f_start > furthest->dist_f_start) furthest = &cellsArray[y][m_n - 2];
		if (cellsArray[y][0].dist_f_start > furthest->dist_f_start) furthest = &cellsArray[y][0];
	}
	for (int x = 0; x < m_n; x++)
	{
		if (cellsArray[m_n - 2][x].dist_f_start > furthest->dist_f_start) furthest = &cellsArray[m_n - 2][x];
		if (cellsArray[0][x].dist_f_start > furthest->dist_f_start) furthest = &cellsArray[0][x];
	}

	if (furthest->getX() == start_pos)
		furthest->wallLeft(false);
	else if (furthest->getY() == start_pos)
		furthest->wallTop(false);
	else if (furthest->getX() == (m_n - 2) * cell_size + start_pos)
	{
		
		int i = (furthest->getY() - start_pos) / cell_size;
		int j = (furthest->getX() - start_pos) / cell_size + 1;
		cellsArray[i][j].wallLeft(false);
		
	}
	else if (furthest->getY() == (m_n - 2) * cell_size + start_pos)
	{
		int i = (furthest->getY() - start_pos) / cell_size + 1;
		int j = (furthest->getX() - start_pos) / cell_size;
		cellsArray[i][j].wallTop(false);
		
	}
}
void MazeCell::draw(RenderWindow& win) const
{
	const Vector2f s(cell_size, cell_size / 5);
	RectangleShape rect1;
	rect1.setPosition(getX(), getY());
	rect1.setSize(s);
	rect1.setFillColor(Color::Magenta);
	RectangleShape rect2;
	rect2.setPosition(getX(), getY());
	const Vector2f s1(cell_size * 6 / 5, cell_size / 5);
	rect2.setSize(s1);
	rect2.setFillColor(Color::Magenta);
	rect2.setRotation(90);

	if (getWallTop())
		win.draw(rect1);
	if (getWallLeft())
		win.draw(rect2);
}
