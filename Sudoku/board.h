#pragma once
#include <iostream>
#include <time.h>
#include <list>

using namespace std;
class Board
{
	int board[9][9];

	void fillRegion(int, int);
	bool fillRest();
	bool findEmpty(int&, int&);
	int randomGenerator(int);
public:
	Board();
	void generateNumber();
	bool cekRegion(int, int, int);
	bool cekRow(int, int);
	bool cekColumn(int, int);
	bool isValid(int, int, int);
	void fill(int, int, int);
	void remove(int, int);
	void printBoard();
	int getNum(int, int);
};


