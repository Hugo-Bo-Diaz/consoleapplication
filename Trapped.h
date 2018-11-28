#ifndef _TRAPPED_H_
#define _TRAPPED_H_

#include "Base_Classes/Controller_Object.h"
#include <list>
#include <string>

#define BASE_HAPPINESS 50;
#define BASE_FRIENDSHIP 50

enum wordtype
{
	NOUN,
	VERB,
	ADJECTIVE,
	ADVERB,
	PROPOSITION,
	NOT_VALID_WORD_TYPE
};

enum phrasetype
{
	QUESTION,
	EXCLAMATIVE,
	STATEMENT,
	IMPERATIVE
};

struct interaction
{
	std::string recieved;
	std::string replied;
	int frames_between_last_interaction;
};

struct theme
{
	std::string name;
	
};

class Trapped : public Object_Controller
{
public:

	Trapped();
	
	void Draw();

	void PreUpdate();
	void PostUpdate();

	void RecieveString(const char* got);
	void Analyze_segment(const char* str);

	short int happiness = BASE_HAPPINESS;
	short int friendship = BASE_FRIENDSHIP;

	std::list<theme*> themes_talked_about;

	std::list<interaction*> past_interactions;

	std::list<std::string> verbs;
	std::list<std::string> nouns;
	std::list<std::string> goodwords;
	std::list<std::string> badwords;
	std::list<std::string> adjectives;
	std::list<std::string> prepositions;


};


#endif