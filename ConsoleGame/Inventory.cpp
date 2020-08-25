#include "Inventory.h"

Inventory::Inventory() {
	std::wifstream file("Interfaces/Inventory.txt");
	std::wstring line;
	if (file.is_open()) {
		for (int i = 0; i < 5; i++) {
			getline(file, line);
			cash.push_back(line);
		}
	}
}

Inventory::~Inventory() {

}

void Inventory::draw(TConsole Console) {
	std::wstring line;
	for (int i = 0; i < 5; i++) {
		Console.GotoXY(pos.x, pos.y + i);
		std::wcout << cash[i];
	}
}

int Inventory::add_item(wchar_t icon, TConsole Console) {
	for (int i = 0; i < Inv_cash.size(); i++) {
		if (Inv_cash[i].icon == icon) {
			if (Inv_cash[i].count + 1 <= 9) {
				Inv_cash[i].count++;
				int offset = 2 + i * 4;
				cash[2][offset + 2] = Inv_cash[i].count + 48;
				draw(Console);
				return 0;
			}
			else return -1;
		}
	}
	if (cash.size() + 1 <= max_size) {
		Inv_cell buf;
		buf.count = 1;
		buf.icon = icon;
		Inv_cash.push_back(buf);
		int offset = 2 + (Inv_cash.size() - 1) * 4;
		/*Console.GotoXY(pos.x + offset,pos.y+2);
		std::wcout << icon << L'|' << 1;*/
		cash[2][offset] = icon;
		cash[2][offset + 1] = L'|';
		cash[2][offset + 2] = 49;
		draw(Console);
		return 0;
	}
	else return -1;
}
