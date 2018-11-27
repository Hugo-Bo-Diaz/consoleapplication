#include "stdafx.h"
#include "Input.h"
#include <conio.h>
#include <Windows.h>
#include <algorithm>
#include "../ConsoleApplication.h"

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

		if (c == 27)
		{
			App->appstate = INVALID;
		}

		if (c == 13)
		{
			App->trapped.RecieveString(typing.c_str());
			typing.clear();
			istyping = !istyping;
		}
		else
		{
			if (!istyping)
			{
				keyboard[c] = 1;
			}
			else if (c == 8 && !typing.empty())
			{
				typing.pop_back();
			}
			else
			{
				typing += c;
				typing.erase(std::remove(typing.begin(), typing.end(), '\0'), typing.end());
			}
		}
	}

	printf_s(" ");
	if (typing.length() > 0)
	{
		for (int i = 0; i < typing.length(); ++i)
		{
			printf_s(" ");
		}
		SetColor(WHITEISH);
		App->scene.BackgroundCursor.SetPosition(0, SCENE_HEIGHT + 1);
		printf_s("%s", typing.c_str());
		App->scene.BackgroundCursor.ResetPosition();
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
