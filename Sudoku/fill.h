#pragma once
#include "command.h"

class Fill : public Command
{
public:
	void setSave_board(Board);
	Board getSave_board();
	void undo(int, int);
	void execute(int, int, int);
};
