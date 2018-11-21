#ifndef SCENE_H_
#define SCENE_H_

#define SCENE_WIDTH 80;
#define SCENE_HEIGHT 80;

class Scene
{
public:

	unsigned char scene_blackboard[50][10];
	bool scene_blackboard_required_change[50][10];

	Scene();
	void DrawBlackboard();

};

#endif // !1
