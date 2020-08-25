#pragma once
#include "resources.h"

struct item {
	int durability = 100;
	std::vector<std::wstring> cash;
	coordinates pos;
};

class Equip
{
public:
	BOOL hiden;

	Equip();
	~Equip();
	void draw(item, BYTE, TConsole);
	void draw_full(TConsole);
	void hide(TConsole);

private:
	item helmet, left_hand, right_hand, chest, pants;

};