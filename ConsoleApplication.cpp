// ConsoleApplication.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include <stdio.h>
#include <thread>
#include <time.h>

enum state {
	STARTING,
	RUNNING,
	INVALID
};



int main()
{
	state appstate = RUNNING;
	int i = 0;
	while (appstate == RUNNING)
	{
		system("cls");
		printf_s("%d",i);
		i++;
	std::this_thread::sleep_for(std::chrono::milliseconds(33));
	if (i > 250)
	{
		appstate = INVALID;
	}
	}
	getchar();
    return 0;
}

