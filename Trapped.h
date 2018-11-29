#ifndef _TRAPPED_H_
#define _TRAPPED_H_

#include "Base_Classes/Controller_Object.h"
#include <list>
#include <string>

#define BASE_HAPPINESS 50;
#define BASE_FRIENDSHIP 50

struct wordtype
{
	bool noun=false;
	bool verb = false;
	bool adjective = false;
	bool goodword =false;
	bool preposition = false;
	bool badword = false;
	bool valid = false;

	std::string word;
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

struct topic
{
	std::string name;
	
};

class Trapped : public Object_Controller
{
public:

	Trapped();
	
	bool needssalute = true;

	void Draw();

	void PreUpdate();
	void PostUpdate();

	void RecieveString(const char* got);
	void Analyze_segment(const char* str);
	void Analyze_syntaxis(std::list<wordtype*>& words);

	short int happiness = BASE_HAPPINESS;
	short int friendship = BASE_FRIENDSHIP;

	std::list<topic*> topics_talked_about;

	std::list<interaction*> past_interactions;

	void Getwordtype(const char*, wordtype* tofill);

	std::list<std::string> verbs;
	bool isverb(const char* word);
	std::list<std::string> nouns;
	bool isnoun(const char* word);
	std::list<std::string> goodwords;
	bool isgoodword(const char* word);
	std::list<std::string> badwords;
	bool isbadword(const char* word);
	std::list<std::string> adjectives;
	bool isadjective(const char* word);
	std::list<std::string> prepositions;
	bool ispreposition(const char* word);

};


#endif