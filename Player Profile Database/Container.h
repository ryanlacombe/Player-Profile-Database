#pragma once
#include "Player.h"

class Container
{
public:
	Container();
	~Container();


	void save();
	bool load();
	void menu();
	void add(Player player);

private:

	int dataLength = 0;
	Player* playerData = new Player[dataLength];
};

