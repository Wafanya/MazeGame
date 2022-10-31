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
		w.clear(Color(30, 50, 100));

		player.draw(w);
		player.update(w);
		a.draw(w);

		w.display();
	}
}