#include "basic.h"
using namespace std;

void switch_window(PlayerGUI& GUI,TConsole Console) {
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