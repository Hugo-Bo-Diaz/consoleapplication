#ifndef SCENE_H_
#define SCENE_H_

#define SCENE_WIDTH 80;
#define SCENE_HEIGHT 80;
#include "Input.h"

struct Cursor
{
	Cursor()
	{
		pos.X = 0;
		pos.Y = 0;
		col = WHITE;
	}

	COORD pos;
	color col;
	
	void SetPosition(int x, int y);
	void ResetPosition();
	void SetColor(color c)
	{
		col = c;
	}

};

class Scene
{
public:

	Cursor BackgroundCursor;
	unsigned char scene_blackboard[50][10];
	bool scene_blackboard_required_change[50][10];

	Scene();

	void Update();

	void DrawBlackboard();


};

#endif // !1
