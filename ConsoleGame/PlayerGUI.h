#pragma once
#include "resources.h"
#include "Interfaces.h"

class PlayerGUI
{
	friend class Player;
	friend void switch_window(PlayerGUI&, TConsole);
private:
	MH_Points mphp_points;
	STATS stats;
	Inventory bag;
	Equip equip;
	TConsole Console;
	std::vector<std::wstring> GUI_cash;
public:
	Output_Console Console_out;
	PlayerGUI();
	~PlayerGUI();

	void hide();

};