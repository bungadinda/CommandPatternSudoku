#pragma once
#include <iostream>

class Player
{
protected:
	std::string playerName;
	int Score;

public:
	Player();
	void setplayerName(std::string);
	std::string getplayerName();
	void setScore(int);
	int getScore();
};
