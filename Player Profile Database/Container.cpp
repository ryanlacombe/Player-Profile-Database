#include "pch.h"
#include "Container.h"


Container::Container()
{

}


Container::~Container()
{

}

void Container::save()
{
	std::ofstream ofs("test.txt", std::ofstream::out);

	ofs << dataLength << std::endl;
	for (int i = 0; i < dataLength; i++)
	{
		std::cout << playerData[i].getName() << std::endl;
		std::cout << playerData[i].getScore() << std::endl;
		ofs << playerData[i].getName() << std::endl;
		ofs << playerData[i].getScore() << std::endl;
	}

	ofs.close();
}

/*bool Container::load()
{
	std::ifstream ifs("test.txt", std::ifstream::in);


	ifs >> playerName;
	ifs >> playerScore;

	return ifs.operator bool();

	ifs.close();
}*/

void Container::menu()
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
			Player player;
			player.playerInput();
			add(player);
		}
		else if (input == '2')
		{

		}
		else if (input == '3')
		{
			Player player;
			std::cout << player.getName();
			save();
		}
		else if (input == '4')
		{
			break;
		}
	}
}

void Container::add(Player player)
{
	Player* middleData = new Player[dataLength];

	for (int i = 0; i < dataLength; i++)
	{
		middleData[i] = playerData[i];
	}

	playerData[dataLength] = player;
	dataLength++;
}

