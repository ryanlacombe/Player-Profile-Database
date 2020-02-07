#include "pch.h"
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Container.h"

int main()
{
	Container game;
	bool loadSuccess = game.load();

	if (loadSuccess)
	{
		std::cout << "File found and loaded..." << std::endl;		
	}
	else
	{
		std::cout << "No file found. Creating new file..." << std::endl;
		game.save();
	}

	std::cout << "Welcome!" << std::endl;
	
	game.menu();
	
}
