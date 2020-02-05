#include "pch.h"
#include "Player.h"
#include <cstring>

Player::Player()
{
	strcpy_s(playerName, 30, "null");
	playerScore = 0;
}

Player::Player(char name[30], int score)
{
	strcpy_s(playerName, 30, name);
	playerScore = score;
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

void Player::setName(char value[30])
{
	strcpy_s(playerName, 30, value);
}

void Player::setScore(int value)
{
	playerScore = value;
}
