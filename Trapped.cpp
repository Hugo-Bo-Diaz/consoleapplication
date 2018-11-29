#include "stdafx.h"
#include "Trapped.h"
#include <fstream>

Trapped::Trapped()
{

	std::ifstream t;
	t.open("language/verbs.txt");
	while (t) {
		std::string line;
		std::getline(t, line);
		verbs.push_front(line);
	}
	t.close();

	t.open("language/nouns.txt");
	while (t) {
		std::string line;
		std::getline(t, line);
		nouns.push_front(line);
	}
	t.close();

	t.open("language/adjectives.txt");
	while (t) {
		std::string line;
		std::getline(t, line);
		adjectives.push_front(line);
	}
	t.close();

	t.open("language/goodwords.txt");
	while (t) {
		std::string line;
		std::getline(t, line);
		goodwords.push_front(line);
	}
	t.close();

	t.open("language/badwords.txt");
	while (t) {
		std::string line;
		std::getline(t, line);
		badwords.push_front(line);
	}

	t.close();	
	
	t.open("language/prepositions.txt");
	while (t) {
		std::string line;
		std::getline(t, line);
		prepositions.push_front(line);
	}

}

void Trapped::Draw()
{
}

void Trapped::PreUpdate()
{
}

void Trapped::PostUpdate()
{
}

void Trapped::RecieveString(const char * got)
{
	interaction* i = new interaction();

	std::string recieved = got;

	std::list<wordtype*> syntaxis;

	std::string word;
	int length = recieved.length();
	for (int i = 0; i <= length; ++i)
	{
		if (recieved[i] == 32 || i==length)
		{
			Analyze_segment(word.c_str());
			
			wordtype* t = new wordtype();
			t->word = word;
			Getwordtype(word.c_str(),t);
			syntaxis.push_back(t);

			word.clear();
		}
		else
		{
			word += recieved[i];
		}
	}

	Analyze_syntaxis(syntaxis);

	past_interactions.push_back(i);

}

void Trapped::Analyze_segment(const char * str)
{
	std::string word = str;


}

void Trapped::Analyze_syntaxis(std::list<wordtype*>& words)
{
	//words is the array of worlds by type(if a noun can be a noun or a verb is taken into consideration)
	
	//if its a salutation it'll be discarded therefore hi, hey, hello and what's up... are done
	//if its anything else we check for patterns to see if the sentence makes sense, if it does we guess the meaning and keep moving


}

void Trapped::Getwordtype(const char * word, wordtype* tofill)
{
	if (isverb(word))
	{
		tofill->verb = true;
	}
	if (isnoun(word))
	{
		tofill->noun = true;
	}
	if (isgoodword(word))
	{
		tofill->goodword = true;
	}
	if (isbadword(word))
	{
		tofill->badword = true;
	}
	if (ispreposition(word))
	{
		tofill->preposition = true;
	}
	if (isadjective(word))
	{
		tofill->adjective = true;
	}
	
}

bool Trapped::isverb(const char * word)
{
	if (std::find(std::begin(verbs), std::end(verbs), word) != std::end(verbs))
		return true;
	else
		return false;
}

bool Trapped::isnoun(const char * word)
{
	if (std::find(std::begin(nouns), std::end(nouns), word) != std::end(nouns))
		return true;
	else
		return false;
}

bool Trapped::isgoodword(const char * word)
{
	if (std::find(std::begin(goodwords), std::end(goodwords), word) != std::end(goodwords))
		return true;
	else
		return false;
}

bool Trapped::isbadword(const char * word)
{
	if (std::find(std::begin(badwords), std::end(badwords), word) != std::end(badwords))
		return true;
	else
		return false;
}

bool Trapped::isadjective(const char * word)
{
	if (std::find(std::begin(adjectives), std::end(adjectives), word) != std::end(adjectives))
		return true;
	else
		return false;
}

bool Trapped::ispreposition(const char * word)
{
	if (std::find(std::begin(prepositions), std::end(prepositions), word) != std::end(prepositions))
		return true;
	else
		return false;
}
