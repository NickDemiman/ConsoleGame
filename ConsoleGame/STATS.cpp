#include "STATS.h"

STATS::STATS() {
	std::wifstream file("Interfaces/STATS.txt");
	getline(file, point);
	std::wstring line;
	if (file.is_open()) {
		for (int i = 0; i < height; i++) {
			getline(file, line);
			cash.push_back(line);
		}
	}
	hiden = TRUE;
}

STATS::~STATS() {

}

void STATS::draw(TConsole Console) {
	std::wstring line;
	for (int i = 0; i < height; i++) {
		Console.GotoXY(pos.x, pos.y + i);
		std::wcout << cash[i];
	}
	hiden = FALSE;
}

void STATS::chg_stats(int stat, int value, TConsole Console) {

	int offset_y = 2 + stat;
	int offset_x = 8;
	for (int i = offset_x; i < 20; i += 2) {
		if (value > 0) {
			cash[offset_y][i] = point[0];
			value--;
		}
		else {
			cash[offset_y][i] = L' ';
		}
	}
	Console.GotoXY(pos.x, offset_y);
	std::wcout << cash[offset_y];
}

void STATS::hide(TConsole Console) {
	std::wstring buf;
	buf.resize(cash[0].size(), L' ');
	for (int i = 0; i < height; i++) {
		Console.GotoXY(pos.x, pos.y + i);
		std::wcout << buf;
	}
	hiden = TRUE;
}