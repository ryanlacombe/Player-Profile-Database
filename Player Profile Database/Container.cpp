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

void Container::sort()
{
	int endLength = dataLength - 1;
	int startLength = 0;
	bool sorted = false;

	while (!sorted)
	{
		sorted = true;
		for (int i = startLength; i < endLength; i++)
		{
			int comparedString = strcmp(playerData[i].getName(), playerData[i + 1].getName());
			if (comparedString > 0)
			{
				Player swapData = playerData[i];
				playerData[i] = playerData[i + 1];
				playerData[i + 1] = swapData;
				sorted = false;
			}
		}
		endLength--;

		for (int f = endLength; f > startLength; f--)
		{
			int comparedString2 = strcmp(playerData[f - 1].getName(), playerData[f].getName());
			if (comparedString2 > 0)
			{
				Player swapData2 = playerData[f - 1];
				playerData[f - 1] = playerData[f];
				playerData[f] = swapData2;
				sorted = false;
			}
		}
		startLength++;
	}
}

void Container::search()
{
	char input[30] = "\0";
	int min = 0;
	int max = dataLength - 1;

	std::cout << std::endl;
	std::cout << "Please enter the name of the profile you wish to update: ";
	std::cin >> input;

	while (max >= min)
	{
		int searchData = ((min + max) / 2);

		if (strcmp(playerData[searchData].getName(), input) == 0)
		{
			int updateInput = 0;

			std::cout << "Please enter the new score: ";
			std::cin >> updateInput;
			playerData->setScore(updateInput);
			min = max + 1;
		}
		else if (strcmp(playerData[searchData].getName(), input) < 0)
		{
			min = searchData + 1;
		}
		else if (strcmp(playerData[searchData].getName(), input) > 0)
		{
			max = searchData - 1;
		}
	}
}

