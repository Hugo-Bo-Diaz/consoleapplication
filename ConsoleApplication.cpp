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
#include "ConsoleApplication.h"

ConsoleApplication::ConsoleApplication()
{
}

void ConsoleApplication::Update()
{
		scene.Update();
		input.UpdateKeyboard();

		scene.DrawBlackboard();

		//end of loop
		std::this_thread::sleep_for(std::chrono::milliseconds(33));
}

