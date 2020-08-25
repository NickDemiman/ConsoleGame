#include "MH_Points.h"

MH_Points::MH_Points() {
	std::wifstream file("Interfaces/MP-HP.txt");
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

MH_Points::~MH_Points() {

}

void MH_Points::draw(TConsole Console) {
	std::wstring line;
	for (int i = 0; i < height; i++) {
		Console.GotoXY(pos.x, pos.y + i);
		std::wcout << cash[i];
	}
	hiden = FALSE;
}

void MH_Points::chg_stats(int HP, int MP, TConsole Console) {
	for (int i = 7; i > 0; i--) {
		if (HP > 0) {
			cash[i][7] = point[0];
			cash[i][8] = point[0];
			HP--;
		}
		else {
			cash[i][7] = L' ';
			cash[i][8] = L' ';
		}
		if (MP > 0) {
			cash[i][2] = point[0];
			cash[i][3] = point[0];
			MP--;
		}
		else {
			cash[i][2] = L' ';
			cash[i][3] = L' ';
		}
		Console.GotoXY(pos.x, i);
		std::wcout << cash[i];
	}
}

void MH_Points::hide(TConsole Console) {
	std::wstring buf;
	buf.resize(cash[0].size(), L' ');
	for (int i = 0; i < height; i++) {
		Console.GotoXY(pos.x, pos.y + i);
		std::wcout << buf;
	}
	hiden = TRUE;
}