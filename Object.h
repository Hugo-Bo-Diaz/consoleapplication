#ifndef _OBJECT_H_
#define _OBJECT_H_

class Object
{
public:
	int x=5;
	int y=5;

	virtual void Draw();

	virtual void Update() {};

};

#endif