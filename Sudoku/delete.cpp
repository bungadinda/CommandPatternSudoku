#include "delete.h"

void Delete::setSave_board(Board save_board)
{
	this->saveBoard = save_board;
}

Board Delete::getSave_board()
{
	return saveBoard;
}

void Delete::undo(int x, int y, int value)
{
	saveBoard.fill(x, y, value);
}

void Delete::execute(int x, int y)
{
	saveBoard.Delete(x, y);
}