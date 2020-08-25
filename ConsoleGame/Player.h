#pragma once
#include "resources.h"
#include "Interfaces.h"
#include "PlayerGUI.h"
#include "Level.h"

class Player {
	friend class PlayerGUI;
private:
	short int HP;
	short int MP;
	SPECIAL stats;
	wchar_t icon;
	TConsole Console;

public:
	coordinates position;
	Player();
	~Player();

	void move(int, int, Level&, PlayerGUI&);
	void spawn(coordinates, Level&);
};
