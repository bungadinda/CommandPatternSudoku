#include "board.h"

Board::Board()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			gameBoard[i][j] = 0;
		}
	}
}

void Board::generateNumber()
{

}

void Board::printBoard()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (gameBoard[i][j] == 0)
			{
				std::cout << " ";
			}
			else
			{
				std::cout << gameBoard[i][j];
				std::cout << " ";
			}

			if ((j + 1) % 3 == 0)
			{
				if (j != 8)
					std::cout << " | ";
			}
		}
		std::cout << std::endl;

		if ((i + 1) % 3 == 0)
		{
			std::cout << "-----------------------" << std::endl;
		}
	}
}

bool Board::checkRegion()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{

		}
	}

	// correct number
	return true;
}

bool Board::checkRow()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				if (k < 8)
				{
					k = 0;
					if (gameBoard[i][j] == gameBoard[i][k])
					{
						return false;
					}
				}
				else
				{
					if (gameBoard[i][j] == gameBoard[i][k])
					{
						return false;
					}
				}
			}
		}
	}

	// correct number
	return true;
}

bool Board::checkColumn()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				if (k < 8)
				{
					k = 0;
					if (gameBoard[j][i] == gameBoard[k][j])
					{
						return false;
					}
				}
				else
				{
					if (gameBoard[j][i] == gameBoard[k][j])
					{
						return false;
					}
				}
			}
		}
	}

	// correct number
	return true;
}

void Board::fill(int x, int y, int value)
{
	gameBoard[x][y] = value;
}

void Board::Delete(int x, int y)
{
	gameBoard[x][y] = 0;
}