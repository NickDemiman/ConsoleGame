#pragma once
#include "resources.h"

struct Inv_cell {
	int count;
	wchar_t icon;
};

class Inventory
{
public:
	Inventory();
	~Inventory();

	void draw(TConsole);
	int add_item(wchar_t, TConsole);

private:
	coordinates pos = { 42,11 };
	std::vector<std::wstring> cash;
	std::vector<Inv_cell> Inv_cash;
	int max_size = 8;
};