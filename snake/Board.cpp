#include "Board.h"

vector <vector <int>> Board::board;
int Board::width;
int Board::height;
int Board::foodX;
int Board::foodY;

void Board::Create(int x, int y)
{
	srand(time(NULL));

	width = x;
	height = y;

	board.resize(x);

	for (int i = 0; i < y; i++)
	{
		board[i].resize(y);
	}
}

void Board::SynchBoard()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			board[i][j] = 0;
		}
	}

	board[foodX][foodY] = 2;

	for (int i = 0; i < Snake::body.size(); i++)
	{
		board[Snake::body[i].posX][Snake::body[i].posY] = 1;
	}
}

void Board::Render()
{
	std::cout << char(201);
	for (int i = 0; i < height; i++)
	{
		std::cout << char(205);
		std::cout << char(205);
	}

	std::cout << char(187) <<"\n";

	for (int i = 0; i < height; i++)
	{
		std::cout << char(186);

		for (int j = 0; j < width; j++)
		{
			if (board[j][i] == 1)
			{
				std::cout << char(219) << char(219);
			}
			else
			{
				if (board[j][i] == 2)
				{
					std::cout << "XX";
				}
				else
				{
					std::cout << "  ";
				}
			}
		}

		std::cout << char(186) << "\n";
	}

	std::cout << char(200);
	for (int i = 0; i < height; i++)
	{
		std::cout << char(205);
		std::cout << char(205);
	}

	std::cout << char(188) << "\n";

	std::cout << "Gen: " << Neuron::gen << "\n";
	//Sleep(100);
}

void Board::MakeFood()
{
	bool canPlace;
	int x;
	int y;

	do
	{
		canPlace = true;

		x = rand() % width;
		y = rand() % height;

		for (int i = 0; i < Snake::body.size(); i++)
		{
			if (Snake::body[i].posX == x && Snake::body[i].posY == y) canPlace = false;
			if (x == width/2 && (y == height/2 || y == height / 2 + 1 || y == height / 2 + 2 ||
				y == height / 2 + 3 || y == height / 2 - 1 || y == height / 2 - 2 || y == height / 2 - 3)) canPlace = false;
		}
	} while (canPlace == false);

	//board[x][y] = 2;
	foodX = x;
	foodY = y;
}
