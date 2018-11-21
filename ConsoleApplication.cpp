// ConsoleApplication.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <thread>
#include <time.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Scene.h"
enum state {
	STARTING,
	RUNNING,
	INVALID
};


int main()
{
	Scene scene;
	scene.scene_blackboard[10][10] = 219;

	state appstate = RUNNING;
	int i = 0;
	while (appstate == RUNNING)
	{
		scene.DrawBlackboard();
		i++;
		std::this_thread::sleep_for(std::chrono::milliseconds(33));
		//if (GetKeyState('A'))
		//	printf("a");
		if (_kbhit())
		{
			int a = _getch();
			printf("%d", a);
		}

		if (i > 250)
		{
			appstate = INVALID;
		}
	}
	getchar();
    return 0;
}

