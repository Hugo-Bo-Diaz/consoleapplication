#include "stdafx.h"
#include "Scene.h"
#include <stdlib.h>
#include <iostream>
#include <Windows.h>

Scene::Scene()
{
	for (int i = 0; i < 50 ; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{

			scene_blackboard[i][j] = ' ';

		}
	}
}

void Scene::DrawBlackboard()
{
	system("cls");
	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{

			wprintf(L"%lc",scene_blackboard[i][j]);

		}
		printf_s("\n");
	}
}
