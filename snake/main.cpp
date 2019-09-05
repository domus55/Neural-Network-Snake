#include <iostream>
#include <windows.h>
#include "Snake.h"
#include "Board.h"

using namespace std;

bool stopp = true;

void stop();
void fixDrawning();
void hideCursor();

int main()
{
	hideCursor();

	Board::Create(20, 20);
	Board::MakeFood();
	Snake::NewGame();

	std::cout << "Use 'o', and 'p' buttons, to see actual game \n";
	Sleep(1000);
	std::cout << "Click any key";
	_getch();

	system("cls");

	for (;;)
	{
		Snake::MoveBody();
		Snake::MoveHead();
		fixDrawning();
		//system("cls");
		Board::SynchBoard();
		if (stopp) Board::Render();
		stop();
	}

	return 0;
}

void fixDrawning()
{
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = 0;
	dwPos.Y = 0;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}

void hideCursor()
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}

void stop()
{
	static char znak = '0';
	static int licznik = 0;
	licznik++;
	if (licznik % 10000 == 0)
	{
		if (_kbhit())
		{
			znak = _getwch();
			if (znak == 'o' || znak == 'O') system("cls");
		}
	}
	if (znak == 'p' || znak == 'P') stopp = true;
	if (znak == 'o' || znak == 'O') stopp = false;

	if (stopp)
	{
		if (_kbhit()) znak = _getwch();
	}
}