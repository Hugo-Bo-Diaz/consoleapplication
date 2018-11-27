#ifndef _CONSOLE_APPLICATION_
#define _CONSOLE_APPLICATION_

#include "Modules/Input.h"
#include "Base_Classes/Scene.h"
#include "Trapped.h"

enum state {
	STARTING,
	RUNNING,
	INVALID
};


class ConsoleApplication
{
public:
	Input input;
	Scene scene;

	state appstate;

	ConsoleApplication();

	void Start();

	void Update();

	Trapped trapped;
	
};
extern ConsoleApplication* App;

#endif