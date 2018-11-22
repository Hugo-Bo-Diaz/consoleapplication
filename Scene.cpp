#include "stdafx.h"
#include "Scene.h"
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "ConsoleApplication.h"
#include "Input.h"

Scene::Scene()
{
	for (int i = 0; i < 50 ; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{

			scene_blackboard[i][j] = 'e';
			scene_blackboard_required_change[i][j] = true;

		}
	}
}

void Scene::Update()
{
	if (App->input.GetKeyState('r') == 1)
	{
		App->input.SetColor(RED);
	}

	if (App->input.GetKeyState('w') == 1)
	{
		App->input.SetColor(WHITE);
	}

	if (App->input.GetKeyState('g') == 1)
	{
		App->scene.scene_blackboard[9][10] = 219;
		App->scene.scene_blackboard_required_change[9][10] = true;
	}

	if (App->input.GetKeyState(27) == 1)
	{
		App->appstate = INVALID;
	}
}

void Scene::DrawBlackboard()
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{

			if (scene_blackboard_required_change[j][i])
			{
				BackgroundCursor.SetPosition(j,i);
				std::cout << (unsigned char)scene_blackboard[j][i];
				scene_blackboard_required_change[j][i] = false;
			}
		}
	}
	BackgroundCursor.ResetPosition();
}

void Cursor::SetPosition(int x, int y) {
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(App->input.hConsole, pos);
}

void Cursor::ResetPosition()
{
	COORD normal;
	normal.X = 0;
	normal.Y = 11;
	SetConsoleCursorPosition(App->input.hConsole, normal);
}
