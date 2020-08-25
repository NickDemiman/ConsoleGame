#include "Equip.h"

Equip::Equip() {
	std::wifstream file("Interfaces/Gear.txt");
	std::wstring line;
	getline(file, line);
	helmet.cash.push_back(line);
	helmet.pos = { 44,1 };
	for (int i = 0; i < 3; i++) {
		getline(file, line);
		left_hand.cash.push_back(line);
	}
	left_hand.pos = { 42,2 };
	for (int i = 0; i < 2; i++) {
		getline(file, line);
		chest.cash.push_back(line);
	}
	chest.pos = { 44,2 };
	right_hand.cash = left_hand.cash;
	right_hand.pos = { 48,2 };
	for (int i = 0; i < 3; i++) {
		getline(file, line);
		pants.cash.push_back(line);
	}
	pants.pos = { 44,4 };
	hiden = TRUE;
}

Equip::~Equip() {

}

void Equip::draw(item itm, BYTE Color, TConsole Console) {
	Console.TextColor(Color);
	for (int i = 0; i < itm.cash.size(); i++) {
		Console.GotoXY(itm.pos.x, itm.pos.y + i);
		std::wcout << itm.cash[i];
	}
	Console.TextColor(COLOR_WHITE);
}

void Equip::draw_full(TConsole Console) {
	draw(helmet, 2, Console);
	draw(left_hand, 2, Console);
	draw(right_hand, 2, Console);
	draw(chest, 2, Console);
	draw(pants, 2, Console);
	hiden = FALSE;
}

void Equip::hide(TConsole Console) {
	std::wstring buf;
	buf.resize(7, ' ');
	for (int i = 0; i < 6; i++) {
		Console.GotoXY(left_hand.pos.x, helmet.pos.y + i);
		std::wcout << buf;
	}
	hiden = TRUE;
}