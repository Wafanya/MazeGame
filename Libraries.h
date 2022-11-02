#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <stack>
#include <list>

using namespace sf;
using namespace std;



constexpr unsigned char NFS = 3; // швидк≥сть гравц€ P.S. Need For Speed: Most WAnted 
const int LENGTH = 10; const int WIDTH = 10;
const int CELL_SIZE = 80;
const int START_POS = (800-((LENGTH-1)*CELL_SIZE-CELL_SIZE/5)) /2;

#include "Player.h"
#include "Maze.h"