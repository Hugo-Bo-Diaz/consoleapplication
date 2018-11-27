#ifndef _CONTROLLER_OBJECT_H_
#define _CONTROLLER_OBJECT_H_

class Object_Controller
{
public:
	int x = 5;
	int y = 5;

	virtual void Draw() {};

	virtual void PreUpdate() {};
	virtual void PostUpdate() {};
};

#endif