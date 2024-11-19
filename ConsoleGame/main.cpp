#include "resources.h"
#include "Game.h"

void switch_window(PlayerGUI& GUI, TConsole Console) {
	if (((GUI.mphp_points.hiden or GUI.stats.hiden or (not GUI.equip.hiden))) == 0) {
		GUI.mphp_points.hide(Console);
		GUI.stats.hide(Console);
		GUI.equip.draw_full(Console);
	}
	else {
		GUI.equip.hide(Console);
		GUI.mphp_points.draw(Console);
		GUI.stats.draw(Console);
	}

}

int main() {

	Level level;
	TConsole Console;
	Player hero;
	PlayerGUI GUI;
	std::vector<std::wstring> buff;

	level.load(0);
	hero.spawn({ 1, 1 }, level);

	int code;
	char ch;
	Console.GotoXY(1, 1);

	while (true) {
		if (_kbhit())
		{
			code = _getch();
			ch = char(code);

			if (code == 0) {
				code = _getch();
				ch = char(code);
			}

			switch (code) {

			case 99: //key c
				switch_window(GUI, Console);
				break;

			case 72: //arrow up
				hero.move(0, -1, level, GUI);
				break;

			case 80: //arrow down
				hero.move(0, 1, level, GUI);
				break;

			case 75: //arrow left
				hero.move(-1, 0, level, GUI);
				break;

			case 77: //arrow right
				hero.move(1, 0, level, GUI);
				break;

			case 27:
				buff.clear();
				buff.push_back(L" --> wanna exit, r u sure?");
				buff.push_back(L" --> press escape again");
				GUI.Console_out.out(buff, Console);
				code = _getch();
				if (code == 27) goto exit;
				break;
			}
		}
		Sleep(50);
	}

	//system("pause");
exit:
	Sleep(1);
}
