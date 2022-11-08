#pragma once
#include "Libraries.h"

int main()
{
	RenderWindow w(VideoMode(800, 800), "Maze");
	Player player; Maze a;
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
