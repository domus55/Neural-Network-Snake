#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include "Board.h"
#include "NeuralNetwork.h"

using namespace std;

class Snake
{
public:
	static vector <Snake> body;
	int posX, posY;

	Snake(int x, int y);
	static void Create(int x, int y);
	static void MoveBody();
	static void MoveHead();
	static void CheckCollision();
	static void NewGame();
};

