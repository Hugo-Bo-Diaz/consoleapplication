#include "stdafx.h"
#include "Scene.h"
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "../ConsoleApplication.h"
#include "../Modules/Input.h"


Scene::Scene()
{
	for (int i = 0; i < SCENE_WIDTH; ++i)
	{
		for (int j = 0; j < SCENE_HEIGHT; ++j)
		{

			scene_blackboard[i][j].character = '.';
			scene_blackboard_new[i][j].character = '.';
			scene_background[i][j].character = '.';

		}
	}

	AddObject(&test);
}

void Scene::PrintPixel(int x, int y, const pixel & p)
{
	BackgroundCursor.SetPosition(x, y);
	App->input.SetColor(p.col);
	std::cout << (unsigned char)p.character;

}

void Scene::GenerateBackground()
{
	for (int i = 0; i < SCENE_HEIGHT; ++i)
	{
		for (int j = 0; j < SCENE_WIDTH; ++j)
		{

			//BackgroundCursor.SetPosition(j, i);
			PrintPixel(j,i,scene_background[j][i]);
			//std::cout << (unsigned char)scene_background[j][i].character;

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
		App->scene.scene_blackboard_new[9][10].character = 219;
	}



	for (std::vector<Object*>::iterator it = objects.begin(); it != objects.end(); ++it)
	{
		(*it)->Update();
	}
}

void Scene::DrawBlackboard()
{

	for (int i = 0; i < SCENE_HEIGHT; ++i)
	{
		for (int j = 0; j < SCENE_WIDTH; ++j)
		{
			scene_blackboard_new[j][i] = scene_background[j][i];
		}
	}

	for (std::vector<Object*>::iterator it = objects.begin(); it != objects.end();++it)
	{
		(*it)->Draw();
	}

	for (int i = 0; i < SCENE_HEIGHT; ++i)
	{
		for (int j = 0; j < SCENE_WIDTH; ++j)
		{

			if (!(scene_blackboard_new[j][i] == scene_blackboard[j][i]))
			{
				scene_blackboard[j][i] = scene_blackboard_new[j][i];
				PrintPixel(j,i,scene_blackboard[j][i]);
			}
		}
	}
	BackgroundCursor.ResetPosition();
}

void Scene::AddObject(Object * to_add)
{
	objects.push_back(to_add);

}

void Cursor::SetPosition(int x, int y) {
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(App->input.hConsole, pos);
}

void Cursor::ResetPosition()
{
	COORD normal;
	normal.X = App->input.typing.length();
	normal.Y = SCENE_HEIGHT+1;
	SetConsoleCursorPosition(App->input.hConsole, normal);
}