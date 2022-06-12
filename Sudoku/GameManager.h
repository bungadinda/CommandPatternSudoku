#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "invoker.h"
#include "board.h"
#include "player.h"
#include "command.h"
#include "fill.h"
#include "delete.h"

class Game_Manager
{
	Player player;
	Board board;
	Invoker undo;
	Invoker redo;
	string saveFile = "saveFile.txt";
public:
	Game_Manager();
	void fillCell(int, int, int);
	void deleteCell(int, int);
	bool checkWin();
	void undoMove();
	void redoMove();
	void quit();
	void play();
	void move();
	void save();
	void load();
};
