#ifndef SCENE_H_
#define SCENE_H_

#define SCENE_WIDTH 80;
#define SCENE_HEIGHT 80;
#include "Input.h"
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
	unsigned char character = 'e';
	color col = WHITE;
	void PrintSelf();
	void Set(unsigned char _character, color _col)
	{
		character = _character;
		col = _col;
	}
	bool operator= (pixel p)
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
	pixel scene_blackboard[50][10];
	pixel scene_blackboard_new[50][10];

	pixel scene_background[50][10];

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
