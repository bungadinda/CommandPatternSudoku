#pragma once
#include <iostream>
#include "board.h"

using namespace std;

class Commands
{
public:
	Commands();
	virtual void undo() = 0;
	virtual void execute() = 0;
};
