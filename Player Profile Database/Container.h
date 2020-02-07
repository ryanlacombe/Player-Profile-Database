#pragma once
#include "Player.h"
#include <string.h>

class Container
{
public:
	Container();
	~Container();


	void save();
	bool load();
	void menu();
	void add(Player player);
	void sort();
	void search();

private:

	int dataLength = 0;
	Player* playerData = new Player[dataLength];
};

