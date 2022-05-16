#include "Invoker.h"

void Invoker::pop()
{
	commanD.pop();
}

void Invoker::push(Command* command)
{
	commanD.push(command);
}