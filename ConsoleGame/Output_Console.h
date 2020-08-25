#pragma once
#include "resources.h"

class Output_Console
{
public:
	Output_Console();
	~Output_Console();

	void draw(TConsole);
	void out(const char*, TConsole);
	void out(std::wstring, TConsole);
	void out(std::vector<std::wstring>, TConsole);

private:
	coordinates pos = { 0,16 };
	std::vector<std::wstring> cash;
};