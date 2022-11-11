#pragma once
#include "Libraries.h"

int main()
{
	RenderWindow w(VideoMode(1000, 1000), "Maze");
	int size = 35;
	Player player(size); Maze a(size);
	srand(time(NULL));
	w.setFramerateLimit(120);
	while (w.isOpen())
	{
		Event event;
		while (w.pollEvent(event))
		{
			if (event.type == Event::Closed)
				w.close();
		}
		w.clear(Color(0, 0, 200));
		a.draw(w);
		player.update(w, a);
		w.display();
	}
	return 0;
}
