#include "fill.h"

void Fill::setSave_board(Board save_board)
{
	this->saveBoard = save_board;
}

Board Fill::getSave_board()
{
	return saveBoard;
}

void Fill::undo(int x, int y)
{
	saveBoard.Delete(x, y);
}

void Fill::execute(int x, int y, int value)
{
	saveBoard.fill(x, y, value);
}