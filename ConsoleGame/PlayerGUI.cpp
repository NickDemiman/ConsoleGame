#include "PlayerGUI.h"

PlayerGUI::PlayerGUI() {
	mphp_points.draw(Console);
	stats.draw(Console);
	Console_out.draw(Console);
	bag.draw(Console);
	Console.GotoXY(0, 0);
}

PlayerGUI::~PlayerGUI() {

}

void PlayerGUI::hide() {
	mphp_points.hide(Console);
	stats.hide(Console);
}