#pragma once
#include <iostream>

class Board
{
protected:
	int gameBoard[9][9];

public:
	Board();
	void generateNumber();
	void printBoard();
	bool checkRegion();
	bool checkRow();
	bool checkColumn();
	void fill(int, int, int);
	void Delete(int, int);
};
