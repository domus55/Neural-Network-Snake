#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Snake.h"

using namespace std;

class Board
{
public:
	static vector <vector <int>> board;	//0 - puste | 1 - w¹¿ | 2 - ¿arcie
	static int width;
	static int height;
	static int foodX;
	static int foodY;

	static void Create(int x, int y);
	static void SynchBoard();
	static void Render();
	static void MakeFood();
};

