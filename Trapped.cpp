#include "stdafx.h"
#include "Trapped.h"

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

}

void Trapped::Analyze_segment(const char * str)
{
	std::string word = str;


}
