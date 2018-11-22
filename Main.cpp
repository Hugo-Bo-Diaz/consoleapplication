#include "stdafx.h"
#include "ConsoleApplication.h"

ConsoleApplication* App = NULL;

int main()
{
	App = new ConsoleApplication();
	App->appstate = STARTING;

	App->appstate = RUNNING;
	App->scene.scene_blackboard[10][10] = 219;

	while (App->appstate == RUNNING)
	{
		App->Update();
	}

	return 0;
}