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
	std::cin >> input;
	strcpy_s(playerName, 30, input);

	std::cout << "Please enter your score:";
	//Clear the input buffer, ready for player input
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin >> numberInput;
	playerScore = numberInput;

	add();
}

char Player::getName()
{
	return playerName[30];
}

int Player::getScore()
{
	return playerScore;
}

void Player::save()
{
	std::ofstream ofs("test.txt", std::ofstream::out);

	ofs << dataLength << std::endl;
	for (int i = 0; i < playerData->dataLength; i++)
	{
		ofs << playerData[i].getName() << std::endl;
		ofs << playerData[i].getScore() << std::endl;
	}

	ofs.close();
}

bool Player::load()
{
	std::ifstream ifs("test.txt", std::ifstream::in);


	ifs >> playerName;
	ifs >> playerScore;

	return ifs.operator bool();

	ifs.close();
}

void Player::menu()
{
	char input;
	bool gameEnd = false;


	while (!gameEnd)
	{
		std::cout << std::endl;
		std::cout << "Welcome!" << std::endl;
		std::cout << "[1] Add New Scores" << std::endl;
		std::cout << "[2] Search and Update a Score" << std::endl;
		std::cout << "[3] Save Scores" << std::endl;
		std::cout << "[4] Exit the Program" << std::endl;

		std::cin >> input;
		if (input == '1')
		{
			playerInput();
		}
		else if (input == '2')
		{

		}
		else if (input == '3')
		{
			save();
		}
		else if (input == '4')
		{
			break;
		}
	}
}

void Player::add()
{
	for (int i = 0; i < playerData->dataLength; i++)
	{
		playerData[i] = playerData[i];
		playerData[dataLength] = { playerName, playerScore };
	}

	dataLength++;
}
