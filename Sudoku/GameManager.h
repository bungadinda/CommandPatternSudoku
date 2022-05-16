#pragma once
#include <string.h>
#include "command.h"
#include "fill.h"
#include "delete.h"
#include "player.h"
#include "board.h"
#include "Invoker.h"

class GameManager
{
protected:
	Board* board;
	Player* player;
	Invoker Undo;
	Invoker Redo;

public:
	GameManager();
	void initialize();
	void play();
	int pause();
	bool quit();
	bool checkWin();
	void sendToDatabase();
	void setBoard(Board*);
	Board* getBoard();
	void setPlayer(Player*);
	Player* getPlayer();
	void undo();
	void redo();
	void fillCell(int, int, int);
	void Delete(int, int);
};
