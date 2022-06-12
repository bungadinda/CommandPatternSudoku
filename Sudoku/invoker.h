#pragma once
#include <iostream>
#include <stack>
#include "command.h"
#include "delete.h"
#include "fill.h"

using namespace std;

class Invoker
{
	stack<Commands*> commands;
public:
	Invoker();
	void pushCommand(Commands*);
	Commands* popCommand();
};
