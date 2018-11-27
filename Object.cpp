#include "stdafx.h"
#include "Base_Classes/Object.h"
#include "Base_Classes/Scene.h"
#include "ConsoleApplication.h"
#include "Modules/Input.h"


void Object::Draw()
{
	if (App->input.GetKeyState('i') == 1)
	{
		y--;
	}
	if (App->input.GetKeyState('k') == 1)
	{
		y++;
	}
	if (App->input.GetKeyState('j') == 1)
	{
		x--;
	}
	if (App->input.GetKeyState('l') == 1)
	{
		x++;
	}
	App->scene.scene_blackboard_new[x][y].character = 219;
	App->scene.scene_blackboard_new[x][y].col = RED;


}
