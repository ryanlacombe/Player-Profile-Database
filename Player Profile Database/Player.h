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
	char getName();
	int getScore();
	void save();
	bool load();
	void menu();
	void add();

private:
	char playerName[30];
	int playerScore;
	int dataLength = 1;
	Player* playerData = new Player[dataLength];
};

