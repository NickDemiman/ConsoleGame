#include "Level.h"

Level::Level() {
	current_lev = 0;
}

Level::~Level() {

}

void Level::load(int current_lev) {
	std::wifstream level;
	switch (current_lev) {
	case 0: level.open("Levels/Level0.txt");
	}

	std::wstring line;
	if (level.is_open()) {
		while (getline(level, line)) {
			lev_cash.push_back(line);
			std::wcout << line << std::endl;
		}
	}
	//else ThrowMsg("level load error");
	level.close();
}

void Level::update() {
	Console.GotoXY(0, 0);
	for (int i = 0; i < lev_cash.size(); i++) std::wcout << lev_cash[i] << std::endl;
	//CurToOut();
}