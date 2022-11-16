#include "Libraries.h"

RenderWindow Frame::w(VideoMode(1000, 1000), "Maze");
int Frame::counter = 0;
int Frame::choice = 0;


void Frame::main_cycle()
{
	srand(time(NULL));
	Player player(size);
	Maze a(size);
	w.setFramerateLimit(120);
	while (w.isOpen() or choice!=-1)
	{
		Event event;
		while (w.pollEvent(event))
		{
			if (event.type == Event::Closed)
				w.close();
		}
		w.clear(Color(139, 0, 255));
		if (choice == 0);
		{
			menu();
		}
		if (choice == 1)
		{
			game_player(player, a);
		}
		w.display();
	}
}

void Frame::menu()
{

	Texture pl_pas;
	pl_pas.loadFromFile("Img/Play pas.png");
	if (!pl_pas.loadFromFile("Img/Play pas.png"))
	{
		cout << "error";
	}
	Sprite spr_pla_pas;
	spr_pla_pas.setTexture(pl_pas);
	spr_pla_pas.setPosition(this->m_pos[0].x, this->m_pos[0].y);
	//w.draw(spr_pla_pas);

	Texture pl_act;
	pl_act.loadFromFile("Img/Play act.png");
	if (!pl_act.loadFromFile("Img/Play act.png"))
	{
		cout << "error";
	}
	Sprite spr_pla_act;
	spr_pla_act.setTexture(pl_act);
	spr_pla_act.setPosition(this->m_pos[0].x, this->m_pos[0].y);
	spr_pla_act.setScale(Vector2f(1.03, 1.03));

	Texture bot_pas;
	bot_pas.loadFromFile("Img/BOT pas.png");
	if (!bot_pas.loadFromFile("Img/BOT pas.png"))
	{
		cout << "error";
	}
	Sprite spr_bot_pas;
	spr_bot_pas.setTexture(bot_pas);
	spr_bot_pas.setPosition(this->m_pos[1].x, this->m_pos[1].y);
	//w.draw(spr_bot_pas);


	Texture bot_act;
	bot_act.loadFromFile("Img/BOT act.png");
	if (!bot_act.loadFromFile("Img/BOT act.png"))
	{
		cout << "error";
	}
	Sprite spr_bot_act;
	spr_bot_act.setTexture(bot_act);
	spr_bot_act.setPosition(this->m_pos[1].x, this->m_pos[1].y);
	spr_bot_act.setScale(Vector2f(1.03, 1.03));
	//w.draw(spr_bot_act);


	Texture opt_pas;
	opt_pas.loadFromFile("Img/OPTIONS pas.png");
	if (!opt_pas.loadFromFile("Img/OPTIONS pas.png"))
	{
		cout << "error";
	}
	Sprite spr_opt_pas;
	spr_opt_pas.setTexture(opt_pas);
	spr_opt_pas.setPosition(this->m_pos[2].x, this->m_pos[2].y);
	//w.draw(spr_opt_pas);

	
	Texture opt_act;
	opt_act.loadFromFile("Img/OPTIONS act.png");
	if (!opt_act.loadFromFile("Img/OPTIONS act.png"))
	{
		cout << "error";
	}
	Sprite spr_opt_act;
	spr_opt_act.setTexture(opt_act);
	spr_opt_act.setPosition(this->m_pos[2].x, this->m_pos[2].y);
	spr_opt_act.setScale(Vector2f(1.03, 1.03));
	//w.draw(spr_opt_act);


	Texture exit_pas;
	exit_pas.loadFromFile("Img/EXIT pas.png");
	if (!exit_pas.loadFromFile("Img/EXIT pas.png"))
	{
		cout << "error";
	}
	Sprite spr_exit_pas;
	spr_exit_pas.setTexture(exit_pas);
	spr_exit_pas.setPosition(this->m_pos[3].x, this->m_pos[3].y);
	//w.draw(spr_exit_pas);


	Texture exit_act;
	exit_act.loadFromFile("Img/EXIT act.png");
	if (!exit_act.loadFromFile("Img/EXIT act.png"))
	{
		cout << "error";
	}
	Sprite spr_exit_act;
	spr_exit_act.setTexture(exit_act);
	spr_exit_act.setPosition(this->m_pos[3].x, this->m_pos[3].y);
	spr_exit_act.setScale(Vector2f(1.03, 1.03));
	//w.draw(spr_exit_act);


	Texture logo;
	logo.loadFromFile("Img/HeadMazeee.png");
	if (!logo.loadFromFile("Img/HeadMazeee.png"))
	{
		cout << "error";
	}
	logo.setSmooth(true);
	sf::Sprite spr_logo;
	spr_logo.setTexture(logo);
	spr_logo.setPosition(this->m_pos[4].x, this->m_pos[4].y);
	spr_logo.setScale(Vector2f(1, 1));
	spr_logo.setColor(sf::Color(139, 0, 255));
	
	w.draw(spr_logo);

	w.setKeyRepeatEnabled(false);
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		counter += 1;
		counter %= 4;
	}

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		counter -= 1;
		counter < 0 ? counter += 4 : counter;
		counter %= 4;
	}

	switch (counter)
	{
	case 0: 
		{
		w.draw(spr_pla_act);
		w.draw(spr_bot_pas);
		w.draw(spr_opt_pas);
		w.draw(spr_exit_pas);
		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			choice = 1;
		}
		break;
			/*w.draw(spr_pla_act);
			w.draw(spr_pla_pas);
			w.draw(spr_bot_pas);
			w.draw(spr_bot_act);
			w.draw(spr_opt_pas);
			w.draw(spr_opt_act);
			w.draw(spr_exit_pas);
			w.draw(spr_exit_act);*/
		}
	case 1:
		{
		w.draw(spr_pla_pas);
		w.draw(spr_bot_act);
		w.draw(spr_opt_pas);
		w.draw(spr_exit_pas);
		break;
		}
	case 2:
		{
		w.draw(spr_pla_pas);
		w.draw(spr_bot_pas);
		w.draw(spr_opt_act);
		w.draw(spr_exit_pas);
		break;
		}		
	case 3:
	{
		w.draw(spr_pla_pas);
		w.draw(spr_bot_pas);
		w.draw(spr_opt_pas);
		w.draw(spr_exit_act);
		break;
	}
	default:
		break;
	}
	w.setKeyRepeatEnabled(true);
}


void Frame::game_player(Player& player, Maze& a)
{
	w.clear(Color(0, 0, 200));
	a.draw(w);
	player.update(w, a);
}
