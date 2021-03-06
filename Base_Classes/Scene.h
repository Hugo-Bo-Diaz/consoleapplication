#ifndef SCENE_H_
#define SCENE_H_

#define SCENE_WIDTH 100
#define SCENE_HEIGHT 20
#include "../Modules/Input.h"
#include <vector>
#include "Object.h"

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

struct pixel
{
	unsigned char character = '.';
	color col = WHITEISH;
	void Set(unsigned char _character, color _col)
	{
		character = _character;
		col = _col;
	}
	bool operator== (pixel p)
	{
		bool ret = true;
		if (this->character != p.character)
		{
			ret = false;
		}
		if (this->col != p.col)
		{
			ret = false;
		}
		return ret;
	}

};

class Scene
{
public:

	Cursor BackgroundCursor;
	pixel scene_blackboard[SCENE_WIDTH][SCENE_HEIGHT];
	pixel scene_blackboard_new[SCENE_WIDTH][SCENE_HEIGHT];

	pixel scene_background[SCENE_WIDTH][SCENE_HEIGHT];

	void PrintPixel(int x, int y, const pixel& p );

	void GenerateBackground();

	Scene();

	void Update();

	void DrawBlackboard();

	Object test;
	std::vector<Object*> objects;

	void AddObject(Object* to_add);

};

#endif // !1
