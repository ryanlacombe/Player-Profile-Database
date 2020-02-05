#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>

class Player
{
public:
	Player();
	Player(char name[30], int score);
	~Player();

	void playerInput();
	char* getName();
	int getScore();
	void setName(char value[30]);
	void setScore(int value);

private:
	char playerName[30];
	int playerScore;
	
};

