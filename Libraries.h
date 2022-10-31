#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <stack>
#include <list>

using namespace sf;
using namespace std;



constexpr unsigned char SPEED = 1; //�������� ������
const int LENGHT = 15; const int WIDTH = 15;
const int CELL_SIZE = 40;
const int START_POS = (800-((LENGHT-1)*CELL_SIZE-CELL_SIZE/5)) /2;

#include "Player.h"
#include "Maze.h"