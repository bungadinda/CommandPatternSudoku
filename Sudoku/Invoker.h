#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include "command.h"
#include "fill.h"
#include "delete.h"

class Invoker
{
protected:
	std::stack<Command*> commanD;

public:
	void pop();
	void push(Command*);
};
