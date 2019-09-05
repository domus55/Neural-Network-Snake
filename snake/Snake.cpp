#include "Snake.h"

vector <Snake> Snake::body;

Snake::Snake(int x, int y)
{
	posX = x;
	posY = y;
}

void Snake::Create(int x, int y)
{
	Snake snake(x, y);
	body.push_back(snake);
}

void Snake::MoveBody()
{
	for (int i = body.size() - 1; i > 0; i--)	//nie wykona siê dla pierszego body
	{
		body[i].posX = body[i - 1].posX;
		body[i].posY = body[i - 1].posY;
	}
}

void Snake::MoveHead()	//ma poruszyæ piersze body i ustawiæ kierunek
{
	static char dir = 's';
	static int lifeTime = 0;
	lifeTime++;
	if (lifeTime == 150) 
	{ 
		Create(0, 0);
		NewGame(); 
		lifeTime = 0; 
	}

	static bool firstTime = true;

	if (firstTime)
	{
		NeuralNetwork::Create(14, 8, 8, 3);
		firstTime = false;
	}

	float bodyUp = 0;
	float bodyLeft = 0;
	float bodyRight = 0;

	float bodyUpLeft = 0;
	float bodyUpRight = 0;
	float bodyDownLeft = 0;
	float bodyDownRight = 0;


	float foodUp = 0;
	float foodLeft = 0;
	float foodRight = 0;
	float foodUpLeft = 0;
	float foodUpRight = 0;
	float foodDownLeft = 0;
	float foodDownRight = 0;


	int k = 0;
	bool hit = false;

	//znajdywanie jedzenia

	if (dir == 'w')
	{
		for (int i = 0; i < body[0].posY + 1; i++)	//góra
		{
			if (Board::board[body[0].posX][body[0].posY - i] == 2)
			{
				foodUp = (float)1 / i;
			}
		}

		for (int i = 0; i < Board::width - body[0].posX; i++)	//prawo
		{
			if (Board::board[body[0].posX + i][body[0].posY] == 2)
			{
				foodRight = (float)1 / i;
			}
		}

		for (int i = 0; i < body[0].posX; i++)	//lewo
		{
			if (Board::board[body[0].posX - i][body[0].posY] == 2)
			{
				foodLeft = (float)1 / i;
			}
		}

		k = 0;
		hit = false;

		do
		{
			k++;
			foodUpRight++;

			if (body[0].posX == -1 || body[0].posX + k == Board::width || body[0].posY - k == -1 || body[0].posY == Board::height)
			{
				foodUpRight = 0;
				hit = true;
			}
			else
			if (Board::board[body[0].posX + k][body[0].posY - k] == 2)
			{
				hit = true;
			}

			

		} while (!hit); //góra prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			foodUpLeft++;

			if (body[0].posX - k == -1 || body[0].posX == Board::width || body[0].posY - k == -1 || body[0].posY == Board::height)
			{
				foodUpLeft = 0;
				hit = true;
			}
			else
			if (Board::board[body[0].posX - k][body[0].posY - k] == 2)
			{
				hit = true;
			}

			

		} while (!hit); //góra lewo

		k = 0;
		hit = false;

		do
		{
			k++;
			foodDownRight++;

			if (body[0].posX == -1 || body[0].posX + k == Board::width || body[0].posY == -1 || body[0].posY + k == Board::height)
			{
				foodDownRight = 0;
				hit = true;
			}
			else
			if (Board::board[body[0].posX + k][body[0].posY + k] == 2)
			{
				hit = true;
			}

		} while (!hit); //dó³ prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			foodDownLeft++;

			if (body[0].posX - k == -1 || body[0].posX == Board::width || body[0].posY == -1 || body[0].posY + k == Board::height)
			{
				foodDownLeft = 0;
				hit = true;
			}
			else
			if (Board::board[body[0].posX - k][body[0].posY + k] == 2)
			{
				hit = true;
			}
		} while (!hit); //dó³ lewo
	}
	if (dir == 'a')
	{
		for (int i = 0; i < Board::height - body[0].posY + 1; i++)	//dó³
		{
			if (Board::board[body[0].posX][body[0].posY + i] == 2)
			{
				foodLeft = (float)1 / i;
			}
		}

		for (int i = 0; i < body[0].posY + 1; i++)	//góra
		{
			if (Board::board[body[0].posX][body[0].posY - i] == 2)
			{
				foodRight = (float)1 / i;
			}
		}

		for (int i = 0; i < body[0].posX + 1; i++)	//lewo
		{
			if (Board::board[body[0].posX - i][body[0].posY] == 2)
			{
				foodUp = (float)1 / i;
			}
		}

		k = 0;
		hit = false;

		do
		{
			k++;
			foodDownRight++;

			if (body[0].posX == -1 || body[0].posX + k == Board::width || body[0].posY - k == -1 || body[0].posY == Board::height)
			{
				foodDownRight = 0;
				hit = true;
			}
			else
				if (Board::board[body[0].posX + k][body[0].posY - k] == 2)
				{
					hit = true;
				}



		} while (!hit); //góra prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			foodUpRight++;

			if (body[0].posX - k == -1 || body[0].posX == Board::width || body[0].posY - k == -1 || body[0].posY == Board::height)
			{
				foodUpRight = 0;
				hit = true;
			}
			else
				if (Board::board[body[0].posX - k][body[0].posY - k] == 2)
				{
					hit = true;
				}



		} while (!hit); //góra lewo

		k = 0;
		hit = false;

		do
		{
			k++;
			foodDownLeft++;

			if (body[0].posX == -1 || body[0].posX + k == Board::width || body[0].posY == -1 || body[0].posY + k == Board::height)
			{
				foodDownLeft = 0;
				hit = true;
			}
			else
				if (Board::board[body[0].posX + k][body[0].posY + k] == 2)
				{
					hit = true;
				}

		} while (!hit); //dó³ prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			foodUpLeft++;

			if (body[0].posX - k == -1 || body[0].posX == Board::width || body[0].posY == -1 || body[0].posY + k == Board::height)
			{
				foodUpLeft = 0;
				hit = true;
			}
			else
				if (Board::board[body[0].posX - k][body[0].posY + k] == 2)
				{
					hit = true;
				}
		} while (!hit); //dó³ lewo
	}
	if (dir == 's')
	{
		for (int i = 0; i < Board::height - body[0].posY + 1; i++)	//dó³
		{
			if (Board::board[body[0].posX][body[0].posY + i] == 2)
			{
				foodUp = (float)1 / i;
			}
		}

		for (int i = 0; i < Board::width - body[0].posX; i++)	//prawo
		{
			if (Board::board[body[0].posX + i][body[0].posY] == 2)
			{
				foodLeft = (float)1 / i;
			}
		}

		for (int i = 0; i < body[0].posX; i++)	//lewo
		{
			if (Board::board[body[0].posX - i][body[0].posY] == 2)
			{
				foodRight = (float)1 / i;
			}
		}

		k = 0;
		hit = false;

		do
		{
			k++;
			foodDownLeft++;

			if (body[0].posX == -1 || body[0].posX + k == Board::width || body[0].posY - k == -1 || body[0].posY == Board::height)
			{
				foodDownLeft = 0;
				hit = true;
			}
			else
				if (Board::board[body[0].posX + k][body[0].posY - k] == 2)
				{
					hit = true;
				}



		} while (!hit); //góra prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			foodDownRight++;

			if (body[0].posX - k == -1 || body[0].posX == Board::width || body[0].posY - k == -1 || body[0].posY == Board::height)
			{
				foodDownRight = 0;
				hit = true;
			}
			else
				if (Board::board[body[0].posX - k][body[0].posY - k] == 2)
				{
					hit = true;
				}



		} while (!hit); //góra lewo

		k = 0;
		hit = false;

		do
		{
			k++;
			foodUpLeft++;

			if (body[0].posX == -1 || body[0].posX + k == Board::width || body[0].posY == -1 || body[0].posY + k == Board::height)
			{
				foodUpLeft = 0;
				hit = true;
			}
			else
				if (Board::board[body[0].posX + k][body[0].posY + k] == 2)
				{
					hit = true;
				}

		} while (!hit); //dó³ prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			foodUpRight++;

			if (body[0].posX - k == -1 || body[0].posX == Board::width || body[0].posY == -1 || body[0].posY + k == Board::height)
			{
				foodUpRight = 0;
				hit = true;
			}
			else
				if (Board::board[body[0].posX - k][body[0].posY + k] == 2)
				{
					hit = true;
				}
		} while (!hit); //dó³ lewo
	}
	if (dir == 'd')
	{
		for (int i = 0; i < Board::height - body[0].posY + 1; i++)	//dó³
		{
			if (Board::board[body[0].posX][body[0].posY + i] == 2)
			{
				foodRight = (float)1 / i;
			}
		}

		for (int i = 0; i < body[0].posY + 1; i++)	//góra
		{
			if (Board::board[body[0].posX][body[0].posY - i] == 2)
			{
				foodLeft = (float)1 / i;
			}
		}

		for (int i = 0; i < Board::width - body[0].posX; i++)	//prawo
		{
			if (Board::board[body[0].posX + i][body[0].posY] == 2)
			{
				foodUp = (float)1 / i;
			}
		}

		k = 0;
		hit = false;

		do
		{
			k++;
			foodUpLeft++;

			if (body[0].posX == -1 || body[0].posX + k == Board::width || body[0].posY - k == -1 || body[0].posY == Board::height)
			{
				foodUpLeft = 0;
				hit = true;
			}
			else
				if (Board::board[body[0].posX + k][body[0].posY - k] == 2)
				{
					hit = true;
				}



		} while (!hit); //góra prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			foodDownLeft++;

			if (body[0].posX - k == -1 || body[0].posX == Board::width || body[0].posY - k == -1 || body[0].posY == Board::height)
			{
				foodDownLeft = 0;
				hit = true;
			}
			else
				if (Board::board[body[0].posX - k][body[0].posY - k] == 2)
				{
					hit = true;
				}



		} while (!hit); //góra lewo

		k = 0;
		hit = false;

		do
		{
			k++;
			foodUpRight++;

			if (body[0].posX == -1 || body[0].posX + k == Board::width || body[0].posY == -1 || body[0].posY + k == Board::height)
			{
				foodUpRight = 0;
				hit = true;
			}
			else
				if (Board::board[body[0].posX + k][body[0].posY + k] == 2)
				{
					hit = true;
				}

		} while (!hit); //dó³ prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			foodDownRight++;

			if (body[0].posX - k == -1 || body[0].posX == Board::width || body[0].posY == -1 || body[0].posY + k == Board::height)
			{
				foodDownRight = 0;
				hit = true;
			}
			else
				if (Board::board[body[0].posX - k][body[0].posY + k] == 2)
				{
					hit = true;
				}
		} while (!hit); //dó³ lewo
	}

	//znajdywanie œcian

	if (dir == 'w')
	{
		k = 0;
		hit = false;

		do
		{
			k++;
			bodyUp++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX == body[i].posX)
				{
					if (body[0].posY - k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX == -1 || body[0].posX == Board::width || body[0].posY - k == -1 || body[0].posY - k == Board::height)
			{
				//bodyUp = 0;
				hit = true;
			}

		} while (!hit); //góra

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyRight++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX + k == body[i].posX)
				{
					if (body[0].posY == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX + k == -1 || body[0].posX + k == Board::width || body[0].posY == -1 || body[0].posY == Board::height)
			{
				//bodyRight = 0;
				hit = true;
			}

		} while (!hit); //prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyLeft++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX - k == body[i].posX)
				{
					if (body[0].posY == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX - k == -1 || body[0].posX - k == Board::width || body[0].posY == -1 || body[0].posY == Board::height)
			{
				//bodyLeft = 0;
				hit = true;
			}

		} while (!hit); //lewo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyUpRight++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX + k == body[i].posX)
				{
					if (body[0].posY - k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX == -1 || body[0].posX + k == Board::width || body[0].posY - k == -1 || body[0].posY == Board::height)
			{
				hit = true;
			}

		} while (!hit); //góra prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyUpLeft++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX - k == body[i].posX)
				{
					if (body[0].posY - k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX - k == -1 || body[0].posX == Board::width || body[0].posY - k == -1 || body[0].posY == Board::height)
			{
				hit = true;
			}

		} while (!hit); //góra Lewo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyDownRight++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX + k == body[i].posX)
				{
					if (body[0].posY + k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX == -1 || body[0].posX + k == Board::width || body[0].posY == -1 || body[0].posY + k == Board::height)
			{
				hit = true;
			}

		} while (!hit); //dó³ prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyDownLeft++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX - k == body[i].posX)
				{
					if (body[0].posY + k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX - k == -1 || body[0].posX == Board::width || body[0].posY == -1 || body[0].posY + k == Board::height)
			{
				hit = true;
			}

		} while (!hit); //dó³ Lewo

	}
	if (dir == 'a')
	{
		k = 0;
		hit = false;

		do
		{
			k++;
			bodyRight++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX == body[i].posX)
				{
					if (body[0].posY - k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX == -1 || body[0].posX == Board::width || body[0].posY - k == -1 || body[0].posY - k == Board::height)
			{
				//bodyUp = 0;
				hit = true;
			}

		} while (!hit); //góra

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyUp++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX - k == body[i].posX)
				{
					if (body[0].posY == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX - k == -1 || body[0].posX - k == Board::width || body[0].posY == -1 || body[0].posY == Board::height)
			{
				//bodyLeft = 0;
				hit = true;
			}

		} while (!hit); //lewo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyLeft++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX == body[i].posX)
				{
					if (body[0].posY + k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX == -1 || body[0].posX == Board::width || body[0].posY + k == -1 || body[0].posY + k == Board::height)
			{
				hit = true;
			}

		} while (!hit); //dó³

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyDownRight++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX + k == body[i].posX)
				{
					if (body[0].posY - k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX == -1 || body[0].posX + k == Board::width || body[0].posY - k == -1 || body[0].posY == Board::height)
			{
				hit = true;
			}

		} while (!hit); //góra prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyUpRight++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX - k == body[i].posX)
				{
					if (body[0].posY - k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX - k == -1 || body[0].posX == Board::width || body[0].posY - k == -1 || body[0].posY == Board::height)
			{
				hit = true;
			}

		} while (!hit); //góra Lewo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyDownLeft++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX + k == body[i].posX)
				{
					if (body[0].posY + k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX == -1 || body[0].posX + k == Board::width || body[0].posY == -1 || body[0].posY + k == Board::height)
			{
				hit = true;
			}

		} while (!hit); //dó³ prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyUpLeft++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX - k == body[i].posX)
				{
					if (body[0].posY + k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX - k == -1 || body[0].posX == Board::width || body[0].posY == -1 || body[0].posY + k == Board::height)
			{
				hit = true;
			}

		} while (!hit); //dó³ Lewo
	}
	if (dir == 's')
	{

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyLeft++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX + k == body[i].posX)
				{
					if (body[0].posY == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX + k == -1 || body[0].posX + k == Board::width || body[0].posY == -1 || body[0].posY == Board::height)
			{
				//bodyRight = 0;
				hit = true;
			}

		} while (!hit); //prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyRight++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX - k == body[i].posX)
				{
					if (body[0].posY == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX - k == -1 || body[0].posX - k == Board::width || body[0].posY == -1 || body[0].posY == Board::height)
			{
				//bodyLeft = 0;
				hit = true;
			}

		} while (!hit); //lewo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyUp++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX == body[i].posX)
				{
					if (body[0].posY + k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX == -1 || body[0].posX == Board::width || body[0].posY + k == -1 || body[0].posY + k == Board::height)
			{
				hit = true;
			}

		} while (!hit); //dó³

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyDownLeft++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX + k == body[i].posX)
				{
					if (body[0].posY - k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX == -1 || body[0].posX + k == Board::width || body[0].posY - k == -1 || body[0].posY == Board::height)
			{
				hit = true;
			}

		} while (!hit); //góra prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyDownRight++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX - k == body[i].posX)
				{
					if (body[0].posY - k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX - k == -1 || body[0].posX == Board::width || body[0].posY - k == -1 || body[0].posY == Board::height)
			{
				hit = true;
			}

		} while (!hit); //góra Lewo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyUpLeft++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX + k == body[i].posX)
				{
					if (body[0].posY + k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX == -1 || body[0].posX + k == Board::width || body[0].posY == -1 || body[0].posY + k == Board::height)
			{
				hit = true;
			}

		} while (!hit); //dó³ prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyUpRight++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX - k == body[i].posX)
				{
					if (body[0].posY + k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX - k == -1 || body[0].posX == Board::width || body[0].posY == -1 || body[0].posY + k == Board::height)
			{
				hit = true;
			}

		} while (!hit); //dó³ Lewo
	}
	if (dir == 'd')
	{
		k = 0;
		hit = false;

		do
		{
			k++;
			bodyLeft++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX == body[i].posX)
				{
					if (body[0].posY - k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX == -1 || body[0].posX == Board::width || body[0].posY - k == -1 || body[0].posY - k == Board::height)
			{
				//bodyUp = 0;
				hit = true;
			}

		} while (!hit); //góra

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyUp++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX + k == body[i].posX)
				{
					if (body[0].posY == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX + k == -1 || body[0].posX + k == Board::width || body[0].posY == -1 || body[0].posY == Board::height)
			{
				//bodyRight = 0;
				hit = true;
			}

		} while (!hit); //prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyRight++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX == body[i].posX)
				{
					if (body[0].posY + k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX == -1 || body[0].posX == Board::width || body[0].posY + k == -1 || body[0].posY + k == Board::height)
			{
				hit = true;
			}

		} while (!hit); //dó³

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyUpLeft++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX + k == body[i].posX)
				{
					if (body[0].posY - k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX == -1 || body[0].posX + k == Board::width || body[0].posY - k == -1 || body[0].posY == Board::height)
			{
				hit = true;
			}

		} while (!hit); //góra prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyDownLeft++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX - k == body[i].posX)
				{
					if (body[0].posY - k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX - k == -1 || body[0].posX == Board::width || body[0].posY - k == -1 || body[0].posY == Board::height)
			{
				hit = true;
			}

		} while (!hit); //góra Lewo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyUpRight++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX + k == body[i].posX)
				{
					if (body[0].posY + k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX == -1 || body[0].posX + k == Board::width || body[0].posY == -1 || body[0].posY + k == Board::height)
			{
				hit = true;
			}

		} while (!hit); //dó³ prawo

		k = 0;
		hit = false;

		do
		{
			k++;
			bodyDownRight++;

			for (int i = 1; i < body.size(); i++)
			{
				if (body[0].posX - k == body[i].posX)
				{
					if (body[0].posY + k == body[i].posY)
					{
						hit = true;
					}
				}
			}

			if (body[0].posX - k == -1 || body[0].posX == Board::width || body[0].posY == -1 || body[0].posY + k == Board::height)
			{
				hit = true;
			}

		} while (!hit); //dó³ Lewo
	}

	bodyUp = 1 / bodyUp;
	bodyLeft = 1 / bodyLeft;
	bodyRight = 1 / bodyRight;

	bodyUpLeft = 1 / bodyUpLeft;
	bodyUpRight = 1 / bodyUpRight;
	bodyDownLeft = 1 / bodyDownLeft;
	bodyDownRight = 1 / bodyDownRight;

	if (foodUpLeft != 0) foodUpLeft = 1 / foodUpLeft;
	if (foodUpRight != 0) foodUpRight = 1 / foodUpRight;
	if (foodDownLeft != 0) foodDownLeft = 1 / foodDownLeft;
	if (foodDownRight != 0) foodDownRight = 1 / foodDownRight;
	
	NeuralNetwork::Input(0, bodyUp);
	NeuralNetwork::Input(1, bodyLeft);
	NeuralNetwork::Input(2, bodyRight);

	NeuralNetwork::Input(3, bodyUpRight);
	NeuralNetwork::Input(4, bodyUpLeft);
	NeuralNetwork::Input(5, bodyDownRight);
	NeuralNetwork::Input(6, bodyDownLeft);
						    
	NeuralNetwork::Input(7, foodUp);
	NeuralNetwork::Input(8, foodLeft);
	NeuralNetwork::Input(9, foodRight);

	NeuralNetwork::Input(10, foodUpRight);
	NeuralNetwork::Input(11, foodUpLeft);
	NeuralNetwork::Input(12, foodDownRight);
	NeuralNetwork::Input(13, foodDownLeft);

	float suma[3];

	NeuralNetwork::CalculateOutputs();
	NeuralNetwork::Output(suma);

	float max = -100000;

	for (int i = 0; i < 3; i++)
	{
		if (suma[i] > max) max = suma[i];
	}

	int output = 0;

	for (int i = 0; i < 3; i++)
	{
		if (suma[i] == max)
		{
			output = i;
		}
	}

	if (output == 0 && dir == 'w') dir = 'a';
	else if (output == 0 && dir == 'a') dir = 's';
	else if (output == 0 && dir == 's') dir = 'd';
	else if (output == 0 && dir == 'd') dir = 'w';

	if (output == 2 && dir == 'w') dir = 'd';
	else if (output == 2 && dir == 'a') dir = 'w';
	else if (output == 2 && dir == 's') dir = 'a';
	else if (output == 2 && dir == 'd') dir = 's';

	//cout << "X: " << body[0].posX << endl;
	//cout << "Y: " << body[0].posY << endl << endl;
	//
	//cout << "bodyUp: " << bodyUp << endl;
	//cout << "bodyLeft: " << bodyLeft << endl;
	//cout << "bodyRight: " << bodyRight << endl << endl;
	//
	//cout << "bodyUpRight" << bodyUpRight << endl;
	//cout << "bodyUpLeft" << bodyUpLeft << endl;
	//cout << "bodyDownRight" << bodyDownRight << endl;
	//cout << "bodyDownLeft" << bodyDownLeft << endl;
	//
	//cout << "foodUp: " << foodUp << endl;
	//cout << "foodLeft: " << foodLeft << endl;
	//cout << "foodRight: " << foodRight << endl;
	//
	//cout << "foodUpRight: " << foodUpRight << endl;
	//cout << "foodUpLeft: " << foodUpLeft << endl;
	//cout << "foodDownRight: " << foodDownRight << endl;
	//cout << "foodDownLeft: " << foodDownLeft << endl;
	//
	//dir = _getwch();


	if (dir == 'w') body[0].posY--;
	if (dir == 'a') body[0].posX--;
	if (dir == 's') body[0].posY++;
	if (dir == 'd') body[0].posX++;

	CheckCollision();

	if (Board::board[body[0].posX][body[0].posY] == 2)
	{
		Create(body[body.size() - 1].posX, body[body.size() - 1].posY);
		Create(body[body.size() - 1].posX, body[body.size() - 1].posY);
		Create(body[body.size() - 1].posX, body[body.size() - 1].posY);
		Board::MakeFood();
		lifeTime = 0;
	}
		
}

void Snake::CheckCollision()
{
	for (int i = 1; i < body.size(); i++)
	{
		if (body[0].posX == body[i].posX)
		{
			if (body[0].posY == body[i].posY)
			{
				NewGame();
			}
		}
	}

	if (body[0].posX == -1 || body[0].posX == Board::width || body[0].posY == -1 || body[0].posY == Board::height)
	{
		NewGame();
	}
}

void Snake::NewGame()
{
	NeuralNetwork::Update((body.size() - 3) / (float)(Board::width * Board::height - 3));
	//cout << (body.size() - 3) / (float)(Board::width * Board::height - 3);

	static float srednia = 0;
	static int licznik = 0;
	static int licznik2 = 0;

	licznik2++;

	float buffor = (srednia * licznik) + body.size();
	licznik++;
	srednia = buffor / (float)licznik;
	if (licznik > 5000) licznik = 5000;

	if (licznik2 == 50)
	{
		licznik2 = 0;

		std::cout << "Gen: " << Neuron::gen << "\n";
		std::cout << "Average length: " << srednia << "\n";
	}
	
	
	body.clear();

	static int x = Board::width / 2;
	static int y = Board::height / 2;

	Snake::Create(x, y);
	Snake::Create(x, y-1);
	Snake::Create(x, y-2);
}
