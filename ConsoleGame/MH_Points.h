#include "resources.h"

class MH_Points
{
public:
	BOOL hiden;
	MH_Points();
	~MH_Points();

	void draw(TConsole);
	void chg_stats(int, int, TConsole);
	void hide(TConsole);

private:
	coordinates pos = { 42,0 };
	int height = 11;
	std::vector<std::wstring> cash;
	std::wstring point;
};
