#include "Player.h"

Player::Player() {
	position = { 0,0 };
	HP = 7; MP = 7;
	stats = {
		1, //STR
		1, //PRN
		1, //EDC
		1, //CHR
		1, //INT
		1, //AGL
		1  //LCK
	};
	icon = L'P';
}

Player::~Player() {

}

void Player::move(int x, int y, Level& level, PlayerGUI& GUI) {
	coordinates buf = { position.x + x, position.y + y };
	wchar_t ch = level.lev_cash[buf.y][buf.x];
	if (ch == L':') {
		HP -= 1;
		GUI.Console_out.out("fuck!", Console);
		GUI.mphp_points.chg_stats(HP, MP, Console);
	}
	else if (ch == L' ') {
		level.lev_cash[position.y][position.x] = L' ';
		level.lev_cash[buf.y][buf.x] = icon;
		level.update();
		position = buf;
	}
	else GUI.Console_out.out("there's obstacle!", Console);
}

void Player::spawn(coordinates pos, Level& level) {
	if (pos.y >= 0 and pos.x >= 0) {
		level.lev_cash[pos.y][pos.x] = icon;
	}
	position = pos;
	level.update();
}