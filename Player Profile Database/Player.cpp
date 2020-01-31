#include "pch.h"
#include "Player.h"
#include <cstring>

Player::Player()
{

}

Player::Player(char name[30], int score)
{

}


Player::~Player()
{

}

void Player::playerInput()
{
	char input[30] = "\0";
	int numberInput = 0;

	std::cout << "Please enter your name:";
	//Clear the input buffer, ready for player input
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin >> playerName;
	//strcpy_s(playerName, 30, input);

	std::cout << "Please enter your score:";
	//Clear the input buffer, ready for player input
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin >> numberInput;
	playerScore = numberInput;
}

char* Player::getName()
{
	return playerName;
}

int Player::getScore()
{
	return playerScore;
}
