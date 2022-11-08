#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <stack>
#include <list>

using namespace sf;
using namespace std;



constexpr unsigned char NFS = 18; // швидк≥сть гравц€ P.S. Need For Speed: Most WAnted 
const int LENGHT = 20; const int WIDTH = 20; //(10,60) (20,15)
const int CELL_SIZE = 25;
const int START_POS = (800 - ((LENGHT - 1) * CELL_SIZE - CELL_SIZE / 5)) / 2;

#include "Player.h"
#include "Maze.h"
