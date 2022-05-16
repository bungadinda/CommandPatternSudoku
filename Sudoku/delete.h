#pragma once
#include "command.h"

class Delete : public Command
{
public:
	void setSave_board(Board);
	Board getSave_board();
	void undo(int, int, int);
	void execute(int, int);
};
