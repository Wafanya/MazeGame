#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <stack>
#include <list>

using namespace sf;
using namespace std;



constexpr unsigned char NFS = 1; // швидк≥сть гравц€ P.S. Need For Speed: Most WAnted 
const int LENGHT = 25; const int WIDTH = 25;
const int CELL_SIZE = 20;
const int START_POS = (800-((LENGHT-1)*CELL_SIZE-CELL_SIZE/5)) /2;

#include "Player.h"
#include "Maze.h"