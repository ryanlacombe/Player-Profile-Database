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
	std::ofstream ofs;
	ofs.open("test.txt", std::ios::out | std::ios::trunc);

	ofs.write((char*)&dataLength, sizeof(int));
	for (int i = 0; i < dataLength; i++)
	{
		ofs.write((char*)&playerData[i], sizeof(Player));	
	}

	ofs.close();
}

bool Container::load()
{
	std::ifstream ifs;
	ifs.open("test.txt", std::ios::in);

	char nameData[30];
	int scoreData;

	ifs.read((char*)&dataLength, sizeof(int));

	Player* loadData = new Player[dataLength];
	for (int i = 0; i < dataLength; i++)
	{
		ifs.read((char*)&loadData[i], sizeof(Player));
	}
	playerData = loadData;

	return ifs.operator bool();

	ifs.close();
}

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
			for (int i = 0; i < dataLength; i++)
			{
				std::cout << playerData[i].getName() << std::endl;
				std::cout << playerData[i].getScore() << std::endl;
			}
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

void Container::add(Player player)
{
	Player* middleData = new Player[dataLength + 1];

	for (int i = 0; i < dataLength; i++)
	{
		middleData[i] = playerData[i];
	}
	playerData = middleData;
	playerData[dataLength] = player;
	dataLength++;
}

