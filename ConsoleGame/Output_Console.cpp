#include "Output_Console.h"

Output_Console::Output_Console() {
	std::wifstream file("Interfaces/Cons Output.txt");
	std::wstring line;
	if (file.is_open()) {
		for (int i = 0; i < 9; i++) {
			getline(file, line);
			cash.push_back(line);
		}
	}
}

Output_Console::~Output_Console() {

}

void Output_Console::draw(TConsole Console) {
	std::wstring line;
	for (int i = 0; i < 9; i++) {
		Console.GotoXY(pos.x, pos.y + i);
		std::wcout << cash[i];
	}
}

void Output_Console::out(const char* str, TConsole Console) {
	draw(Console);
	Console.GotoXY(1, 17);
	std::wcout << str;
}

void Output_Console::out(std::wstring str, TConsole Console) {
	draw(Console);
	Console.GotoXY(1, 17);
	std::wcout << str;
}

void Output_Console::out(std::vector<std::wstring> str_vec, TConsole Console) {
	draw(Console);
	int n = str_vec.size();
	for (int i = 0; i < n; i++) {
		Console.GotoXY(1, 17 + i);
		std::wcout << str_vec[i];
	}
}

