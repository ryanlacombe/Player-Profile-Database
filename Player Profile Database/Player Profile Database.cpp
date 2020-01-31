#include "pch.h"
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Container.h"

int main()
{
	Container game;
	//bool loadSuccess = game.load();

	/*if (loadSuccess)
	{
		std::cout << "File found and loaded..." << std::endl;		
	}*/
	
		std::cout << "No file found. Creating new file..." << std::endl;
		//game.save();
	
	game.menu();
	
}
