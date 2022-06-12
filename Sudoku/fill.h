#pragma once
#include "command.h"

class Command_Fill : public Commands
{
	Board* board;
	int row, col, num;
public:
	Command_Fill(Board*, int, int, int);
	void execute();
	void undo();
};
