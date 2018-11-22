// ConsoleApplication.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <thread>
#include <time.h>
#include <iostream>
#include <Windows.h>
#include "Scene.h"
#include "Input.h"

enum state {
	STARTING,
	RUNNING,
	INVALID
};


int main()
{
	Input input;
	Scene scene;

	scene.scene_blackboard[10][10] = 219;

	state appstate = RUNNING;
	while (appstate == RUNNING)
	{
		scene.DrawBlackboard();
		input.UpdateKeyboard();
		if (input.GetKeyState('r') == 1)
		{
			input.SetColor(RED);
		}

		if (input.GetKeyState('w') == 1)
		{
			input.SetColor(WHITE);
		}

		if (input.GetKeyState(27) == 1)
		{
			appstate = INVALID;
		}

		//end of loop
		std::this_thread::sleep_for(std::chrono::milliseconds(33));
	}

    return 0;
}

