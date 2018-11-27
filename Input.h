#pragma once
#include <string>
#include<windows.h>

enum color
{
HARD_BLUE=0,
HARD_GREEN,
TURQUOISE,
GARNET,
HARD_PURPLE,
GOLD,
SILVER,
WHITEISH,
GREY,
BLUE,
GREEN,
LIGHT_BLUE,
RED,
PURPLE,
YELLOW,
WHITE,
OTHER
};

class Input
{
private:

	int keyboard[255];
	std::string typing="a";

public:

	HANDLE hConsole;

	Input();

	void UpdateKeyboard();

	int GetKeyState(int keycode);

	bool istyping = true;

	void SetColor(color c, int other_color = 0);
};