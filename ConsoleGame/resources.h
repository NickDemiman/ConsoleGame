#pragma once
#include "TConsole.h"
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>

struct coordinates {
	int x;
	int y;
};

struct SPECIAL {
	short int STR;
	short int PRN;
	short int EDC;
	short int CHR;
	short int INT;
	short int AGL;
	short int LCK;
};