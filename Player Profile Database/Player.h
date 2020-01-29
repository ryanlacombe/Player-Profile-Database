#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>

class Player
{
public:
	Player();
	~Player();

	void playerInput();
	void save();
	void load();

private:
	char playerName[30];
	int playerScore;
};

