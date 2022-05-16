#include "player.h"

Player::Player()
{
	playerName = " ";
	Score = 0;
}

void Player::setplayerName(std::string Username)
{
	this->playerName = Username;
}

std::string Player::getplayerName()
{
	return playerName;
}

void Player::setScore(int Score)
{
	this->Score = Score;
}

int Player::getScore()
{
	return Score;
}