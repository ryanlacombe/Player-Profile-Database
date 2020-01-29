#include "pch.h"
#include "Player.h"
#include <cstring>

Player::Player()
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
	std::cin >> input;
	strcpy_s(playerName, 30, input);

	std::cout << "Please enter your score:";
	//Clear the input buffer, ready for player input
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin >> numberInput;
	playerScore = numberInput;
}

void Player::save()
{
	std::ofstream ofs("test.txt", std::ofstream::out);

	ofs << playerName << std::endl;
	ofs << playerScore;

	ofs.close();
}

void Player::load()
{
	std::ifstream ifs("test.txt", std::ifstream::in);

	ifs >> playerName;
	ifs >> playerScore;

	std::cout << playerName << std::endl;
	std::cout << playerScore;
}
