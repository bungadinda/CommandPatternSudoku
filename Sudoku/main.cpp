#include "board.h"

int main()
{
	Board* board = new Board();

	board->printBoard();
	if (board->checkColumn() == true && board->checkRegion() == true && board->checkRow() == true)
	{
		std::cout << "finish...." << std::endl;
	}
	else
	{
		std::cout << "lose...." << std::endl;
	}

	return 0;
}