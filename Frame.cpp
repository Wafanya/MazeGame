#include "Libraries.h"

RenderWindow Frame::w(VideoMode(1000, 1000), "Maze");
int Frame::counter = 0;
int Frame::choice = 0;

void Frame::main_cycle()
{
	
s:
	counter = 0;
	srand(time(NULL));
	Player player(size);
	const Maze maze(size);
	w.setFramerateLimit(120);
	while (w.isOpen() and choice!=-1)
	{
		Event event;
		while (w.pollEvent(event))
		{
			if (event.type == Event::Closed)
				w.close();
		}
		w.clear(Color(139, 0, 255));
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			choice = 0;
			main_cycle();
			//goto s;
		}
		if (choice == 0)
		{
			menu();
		}
		if (choice == 1)
		{
			game_player(player, maze);
			cur_it = time(NULL);
			delt = difftime(cur_it, start);
			timer();
			if (player.isWin(maze)) //if WIN
			{
				string s_ti = to_string(delt);
				lb.open("leadboard.txt", ios::in | ios::app | ios::out);
				if (!lb.is_open()) { cout << "File hasn't been opened"; }
				lb << delt << endl;
				lb.close();
				leadboard(); //                                                    рср аюц
				Sleep(2500);
				choice = 0;
				goto s;
			}
		}
		if (choice == 2)
		{
			while(true)
			{
				leadboard();
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					choice = 0;
					break;
				}
			}
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


	Texture lead_pas;
	lead_pas.loadFromFile("Img/Leadboard m pas.png");
	if (!lead_pas.loadFromFile("Img/Leadboard m pas.png"))
	{
		cout << "error";
	}
	Sprite spr_lead_pas;
	spr_lead_pas.setTexture(lead_pas);
	spr_lead_pas.setPosition(this->m_pos[2].x, this->m_pos[2].y);


	Texture lead_act;
	lead_act.loadFromFile("Img/Leadboard m act.png");
	if (!lead_act.loadFromFile("Img/Leadboard m act.png"))
	{
		cout << "error";
	}
	Sprite spr_lead_act;
	spr_lead_act.setTexture(lead_act);
	spr_lead_act.setPosition(this->m_pos[2].x, this->m_pos[2].y);
	spr_lead_act.setScale(Vector2f(1.03, 1.03));



	Texture opt_pas;
	opt_pas.loadFromFile("Img/Info pas.png");
	if (!opt_pas.loadFromFile("Img/Info pas.png"))
	{
		cout << "error";
	}
	Sprite spr_opt_pas;
	spr_opt_pas.setTexture(opt_pas);
	spr_opt_pas.setPosition(this->m_pos[3].x, this->m_pos[3].y);
	//w.draw(spr_opt_pas);

	
	Texture opt_act;
	opt_act.loadFromFile("Img/Info act.png");
	if (!opt_act.loadFromFile("Img/Info act.png"))
	{
		cout << "error";
	}
	Sprite spr_opt_act;
	spr_opt_act.setTexture(opt_act);
	spr_opt_act.setPosition(this->m_pos[3].x, this->m_pos[3].y);
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
	spr_exit_pas.setPosition(this->m_pos[4].x, this->m_pos[4].y);
	//w.draw(spr_exit_pas);


	Texture exit_act;
	exit_act.loadFromFile("Img/EXIT act.png");
	if (!exit_act.loadFromFile("Img/EXIT act.png"))
	{
		cout << "error";
	}
	Sprite spr_exit_act;
	spr_exit_act.setTexture(exit_act);
	spr_exit_act.setPosition(this->m_pos[4].x, this->m_pos[4].y);
	spr_exit_act.setScale(Vector2f(1.03, 1.03));
	//w.draw(spr_exit_act);


	Texture logo;
	logo.loadFromFile("Img/HeadMazeee.png");
	if (!logo.loadFromFile("Img/HeadMazeee.png"))
	{
		cout << "error";
	}
	logo.setSmooth(true);
	Sprite spr_logo;
	spr_logo.setTexture(logo);
	spr_logo.setPosition(this->m_pos[5].x, this->m_pos[5].y);
	spr_logo.setScale(Vector2f(1, 1));
	spr_logo.setColor(Color(139, 0, 255));
	
	w.draw(spr_logo);

	w.setKeyRepeatEnabled(false);
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		counter += 1;
		counter %= 5;
	}

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		counter -= 1;
		counter < 0 ? counter += 5 : counter;
		counter %= 5;
	}

	switch (counter)
	{
	case 0: 
		{
		w.draw(spr_pla_act);
		w.draw(spr_bot_pas);
		w.draw(spr_lead_pas);
		w.draw(spr_opt_pas);
		w.draw(spr_exit_pas);
		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			choice = 1;
			start = time(NULL);
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
		w.draw(spr_lead_pas);
		w.draw(spr_opt_pas);
		w.draw(spr_exit_pas);
		break;
		}
	case 2:
		{
		w.draw(spr_pla_pas);
		w.draw(spr_bot_pas);
		w.draw(spr_lead_act);
		w.draw(spr_opt_pas);
		w.draw(spr_exit_pas);
		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			choice = 2;
		}
		break;
		}
	case 3:
		{
		w.draw(spr_pla_pas);
		w.draw(spr_bot_pas);
		w.draw(spr_lead_pas);
		w.draw(spr_opt_act);
		w.draw(spr_exit_pas);
		break;
		}		
	case 4:
	{
		w.draw(spr_pla_pas);
		w.draw(spr_bot_pas);
		w.draw(spr_lead_pas);
		w.draw(spr_opt_pas);
		w.draw(spr_exit_act);
		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			choice = -1;
		}
		break;
	}
	default:
		break;
	}
	w.setKeyRepeatEnabled(true);
}

void Frame::timer()
{
	Font f_ti;
	f_ti.loadFromFile("Bold/LEMONMILK-BoldItalic.otf");
	if (!f_ti.loadFromFile("Bold/LEMONMILK-BoldItalic.otf"))
	{
		cout << "error in downloading font";
	}
	Text t_ti;
	t_ti.setFont(f_ti);
	string s_ti = to_string(delt);
	t_ti.setString("Time: " + s_ti);
	t_ti.setCharacterSize(40); 
	t_ti.setFillColor(Color(173, 216, 230));
	//text.setStyle(Text::Bold |Text::Underlined);
	t_ti.setPosition(t_pos.x, t_pos.y);
	w.draw(t_ti);
}

void Frame::game_player(Player& player, const Maze& a)
{
	w.clear(Color(139, 0, 255));
	a.draw(w);
	player.update(w, a);
}

void Frame::leadboard()
{
	lb.open("leadboard.txt", ios::in | ios::app | ios::out);
	if (!lb.is_open())
	{
		cout << "file isn't open to read";
	}
	
	string pos;
	
	while (!lb.eof())
	{
		lb >> pos;
		time_res.push_back(stoi(pos));
		//sort(time_res.begin(), time_res.end());
		/*if (time_res.size() > 7) { time_res.pop_back();
		cout << "Sorted \n";
		for (auto x : time_res)
			cout << x << " ";
		}*/
	}
	sort(time_res.begin(), time_res.end());
	while (time_res.size() > 7) { time_res.pop_back(); }
	/*for (auto x : time_res)
		cout << x << " ";*/
	lb.close();

	Font frst_res;
	frst_res.loadFromFile("ARIBL0.ttf");
	if (!frst_res.loadFromFile("ARIBL0.ttf"))
	{
		cout << "error in downloading font";
	}
	Text t_frst_res;
	t_frst_res.setFont(frst_res);
	string cov_frst_res = to_string(time_res[0]);
	t_frst_res.setString("The best result is " + cov_frst_res + " seconds, good job!");
	t_frst_res.setCharacterSize(25);
	t_frst_res.setFillColor(Color(173, 216, 230));
	t_frst_res.setPosition(100, 400);


	Font sec_res;
	sec_res.loadFromFile("ARIBL0.ttf");
	if (!sec_res.loadFromFile("ARIBL0.ttf"))
	{
		cout << "error in downloading font";
	}
	Text t_sec_res;
	t_sec_res.setFont(sec_res);
	string cov_sec_res = to_string(time_res[1]);
	t_sec_res.setString("The second best result is " + cov_sec_res + " seconds");
	t_sec_res.setCharacterSize(25);
	t_sec_res.setFillColor(Color(173, 216, 230));
	t_sec_res.setPosition(100, 450);


	Font third_res;
	third_res.loadFromFile("ARIBL0.ttf");
	if (!third_res.loadFromFile("ARIBL0.ttf"))
	{
		cout << "error in downloading font";
	}
	Text t_third_res;
	t_third_res.setFont(third_res);
	string cov_third_res = to_string(time_res[2]);
	t_third_res.setString("The third best result is " + cov_third_res + " seconds");
	t_third_res.setCharacterSize(25);
	t_third_res.setFillColor(Color(173, 216, 230));
	t_third_res.setPosition(100, 500);

	
	Texture lead;
	lead.loadFromFile("Img/Leadboard.png");
	if (!lead.loadFromFile("Img/Leadboard.png"))
	{
		cout << "error";
	}
	lead.setSmooth(true);
	Sprite spr_lead;
	spr_lead.setTexture(lead);
	spr_lead.setPosition(150, 200);
	spr_lead.setScale(Vector2f(1.1, 1.1));


	w.clear(Color(139, 0, 255));
	w.draw(t_frst_res);
	w.draw(t_sec_res);
	w.draw(t_third_res);
	w.draw(spr_lead);
	w.display();
	//Sleep(5000);
	time_res.clear();
}

void Frame::info()
{
	Font f_ab;
	f_ab.loadFromFile("ARIBL0.ttf");
	if (!f_ab.loadFromFile("ARIBL0.ttf"))
	{
		cout << "error in downloading font";
	}
	Text t_ab;
	t_ab.setFont(f_ab);
	t_ab.setString(" ");
	t_ab.setCharacterSize(25);
	t_ab.setFillColor(Color(173, 216, 230));
	t_ab.setPosition(100, 400);

	Font f_gp;
	f_gp.loadFromFile("ARIBL0.ttf");
	if (!f_gp.loadFromFile("ARIBL0.ttf"))
	{
		cout << "error in downloading font";
	}
	Text t_gp;
	t_gp.setFont(f_gp);
	t_gp.setString(" ");
	t_gp.setCharacterSize(25);
	t_gp.setFillColor(Color(173, 216, 230));
	t_gp.setPosition(100, 400);
}