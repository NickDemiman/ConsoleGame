#pragma once
#include "resources.h"

extern class Player;

class Level
{
	friend class Player;
private:
	TConsole Console;
	int current_lev;
	std::vector<std::wstring> lev_cash;

public:
	Level();
	~Level();

	void load(int);
	void update();

};
