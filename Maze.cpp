#include "Libraries.h"

Maze::Maze()
{
	int x; int y; 
	for (y = START_POS; y < START_POS+ WIDTH*CELL_SIZE; y+=CELL_SIZE)
	{
		for (x = START_POS; x < START_POS+LENGTH*CELL_SIZE; x+=CELL_SIZE)
		{
			MazeCell a(x, y);
			cellsArray[(y - START_POS) / CELL_SIZE][(x - START_POS) / CELL_SIZE] = a;
			
		}
	}

	for (int i = 0; i < WIDTH; i++) // видалємо зайві бічні стінки
	{
		cellsArray[i][LENGTH - 1].wallTop(false);
		cellsArray[i][LENGTH - 1].isVisited = true;

	}
	for (int j = 0; j < LENGTH; j++) // видалємо зайві бічні стінки
	{
		cellsArray[WIDTH - 1][j].wallLeft(false);
		cellsArray[WIDTH - 1][j].isVisited = true;
	}
	generate();
}
void Maze::draw(RenderWindow& win)
{
	for (int y = 0; y < LENGTH; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			cellsArray[y][x].draw(win);
		}
	}
}
void Maze::generate() //генерація лабіринту шляхом видалення стін у сітці
{
	MazeCell* current = &cellsArray[0][0]; int random; 
	current->isVisited = true;
	stack <MazeCell*> stack;
	do
	{
		list <MazeCell*> unvisitedNeighbours;
		int x = ((current->getX() - START_POS) / CELL_SIZE); 
		int y = ((current->getY() - START_POS) / CELL_SIZE); 
		cout << "[" << x << "]" << "[" << y << "]" << endl;
		if ((y > 0) && (!cellsArray[y - 1][x].isVisited)) unvisitedNeighbours.push_back(&cellsArray[y - 1][x]); //перевірка чи є невідвідані сусіди
		if ((x > 0) && (!cellsArray[y][x - 1].isVisited)) unvisitedNeighbours.push_back(&cellsArray[y][x - 1]);
		if ((y < WIDTH - 2) && (!cellsArray[y + 1][x].isVisited)) unvisitedNeighbours.push_back(&cellsArray[y + 1][x]);
		if ((x < LENGTH - 2) && (!cellsArray[y][x + 1].isVisited)) unvisitedNeighbours.push_back(&cellsArray[y][x + 1]);

		if (unvisitedNeighbours.size()>0)
		{
			MazeCell* chosen;
			random = rand() % unvisitedNeighbours.size(); //обираємо випадкового невідвіданого сусіда
			list<MazeCell*>::iterator i = unvisitedNeighbours.begin();
			advance(i, random);
			chosen = *i;
			if (current->getX() == chosen->getX()) //зносимо між ними стінку
			{
				if (current->getY() > chosen->getY()) { current->wallTop(false); }
				else { chosen->wallTop(false);}
			}
			else
			{
				if (current->getX() > chosen->getX()) { current->wallLeft(false);  }
				else { chosen->wallLeft(false);  }
				
			}

			chosen->isVisited = true; //тепер сусід стає новою клітинкою
			stack.push(chosen);
			current = chosen;
			//current->setX(chosen->getX()); 
			//current->setY(chosen->getY());
		}
		else
		{
			current = stack.top();
			stack.pop();
		}

	} while (stack.size() > 0);
}


void MazeCell::draw(RenderWindow& win)
{
	const Vector2f s(CELL_SIZE, CELL_SIZE/5);
	RectangleShape rect1;
	rect1.setPosition(getX(), getY());
	rect1.setSize(s);
	rect1.setFillColor(Color::Magenta);
	RectangleShape rect2;
	rect2.setPosition(getX(), getY());
	const Vector2f s1(CELL_SIZE+ CELL_SIZE/5, CELL_SIZE/5);
	rect2.setSize(s1);
	rect2.setFillColor(Color::Magenta);
	rect2.setRotation(90);

	
	if (getWallTop())
		win.draw(rect1);
	if (getWallLeft())
		win.draw(rect2);
}

