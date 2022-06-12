#pragma once
#include "command.h"

class Command_Delete : public Commands
{
	Board* board;
	int row, col, num;
public:
	Command_Delete(Board*, int, int, int);
	void execute();
	void undo();
};
