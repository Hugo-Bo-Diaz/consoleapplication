#include "stdafx.h"
#include "Input.h"
#include <conio.h>
#include <Windows.h>
#include <algorithm>

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
	if (_kbhit())
	{
		char c = _getch();

		if (c == 13)
		{
			istyping = !istyping;
		}
		else
		{
			if (!istyping)
			{
				keyboard[c] = 1;
			}
			else
			{
				typing += c;
				typing.erase(std::remove(typing.begin(), typing.end(), '\0'), typing.end());
			}
		}
	}

	if (typing.length() > 0)
	{
		printf_s("%s", typing.c_str());
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
