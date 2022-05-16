#include "GameManager.h"

GameManager::GameManager()
{
	board = new Board();
	player = new Player();
}

void GameManager::initialize()
{
	board->generateNumber();
	board->printBoard();
}

int GameManager::pause()
{
	int answer;
	std::cout << "Game paused..." << std::endl;
	std::cout << "Please enter:" << std::endl;
	std::cout << "1. Continue\n 2. exit" << std::endl;
	std::cout << "Enter: "; std::cin >> answer;

	return answer;
}

void GameManager::play()
{

}

bool GameManager::quit()
{
	return true;
}

bool GameManager::checkWin()
{
	if (board->checkColumn() == true && board->checkRegion() == true && board->checkRow() == true)
	{
		return true;
	}
	return false;
}

void GameManager::sendToDatabase()
{

}

void GameManager::setBoard(Board* board)
{
	this->board = board;
}

Board* GameManager::getBoard()
{
	return board;
}

void GameManager::setPlayer(Player* player)
{
	this->player = player;
}

Player* GameManager::getPlayer()
{
	return player;
}

void GameManager::undo()
{

}

void GameManager::redo()
{

}

void GameManager::fillCell(int x, int y, int value)
{
	board->fill(x, y, value);
}

void GameManager::Delete(int x, int y)
{
	board->Delete(x, y);
}