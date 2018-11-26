#include "stdafx.h"
#include "Input.h"
#include <conio.h>
#include <Windows.h>

Input::Input()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Input::UpdateKeyboard()
{
	for (int i = 0; i < 255; ++i)
	{
		keyboard[i] = 0;
	}
	if (!istyping &&_kbhit())
	{
		keyboard[_getch()] = 1;
	}

	
}

int Input::GetKeyState(int keycode)
{
	return keyboard[keycode];
}

void Input::SetColor(color c, int other_color)
{
	int new_color = 0;
	if (c == OTHER)
	{
		new_color = other_color;
	}
	else
	{
		new_color = (int)c;
	}
	SetConsoleTextAttribute(hConsole,new_color);
}
