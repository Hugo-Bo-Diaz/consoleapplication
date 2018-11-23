#ifndef _CONSOLE_APPLICATION_
#define _CONSOLE_APPLICATION_

#include "Input.h"
#include "Scene.h"

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
};
extern ConsoleApplication* App;

#endif