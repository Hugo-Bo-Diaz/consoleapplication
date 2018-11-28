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

	std::string word;
	int length = recieved.length();
	for (int i = 0; i <= length; ++i)
	{
		if (recieved[i] == 32 || i==length)
		{
			Analyze_segment(word.c_str());
			word.clear();
		}
		else
		{
			word += recieved[i];
		}
	}

	past_interactions.push_back(i);

}

void Trapped::Analyze_segment(const char * str)
{
	std::string word = str;


}
