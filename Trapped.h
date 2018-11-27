#ifndef _TRAPPED_H_
#define _TRAPPED_H_

#include "Base_Classes/Controller_Object.h"
#include <list>
#include <string>

#define BASE_HAPPINESS 50;
#define BASE_FRIENDSHIP 50

struct theme
{
	std::string name;
	
};

class Trapped : public Object_Controller
{
public:
	void Draw();

	void PreUpdate();
	void PostUpdate();

	void RecieveString(const char* got);
	void Analyze_segment(const char* str);

	short int happiness = BASE_HAPPINESS;
	short int friendship = BASE_FRIENDSHIP;

	std::list<theme*> themes_talked_about;
	std::list<std::string> badwords;
	std::list<std::string> goodwords;
};


#endif