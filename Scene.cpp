#include "stdafx.h"
#include "Scene.h"
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>

Scene::Scene()
{
	for (int i = 0; i < 50 ; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{

			scene_blackboard[i][j] = 'e';

		}
	}
}

void Scene::DrawBlackboard()
{
	system("cls");
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			//printf("ñ");
			//std::wcout << scene_blackboard[j][i];

			std::cout << (unsigned char) 219	;

			//wprintf (L"%c",scene_blackboard[j][i]);

		}
		std::wcout << std::endl;
	}
}
