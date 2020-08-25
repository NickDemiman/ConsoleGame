#pragma once
#include "resources.h"

class STATS
{
public:
	BOOL hiden;

	STATS();
	~STATS();

	void draw(TConsole);
	void chg_stats(int, int, TConsole);
	void hide(TConsole);

private:
	coordinates pos = { 56,0 };
	int height = 11;
	std::vector<std::wstring> cash;
	std::wstring point;
};