#include "stdafx.h"
#include "ConsoleApplication.h"

ConsoleApplication* App = NULL;

int main()
{
	App = new ConsoleApplication();
	App->appstate = STARTING;

	App->appstate = RUNNING;

	App->Start();
	while (App->appstate == RUNNING)
	{
		App->Update();
	}

	return 0;
}