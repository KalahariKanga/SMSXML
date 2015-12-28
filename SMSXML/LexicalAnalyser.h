#pragma once
#include "Analyser.h"


class LexicalAnalyser :
	public Analyser
{
	std::string normalise(std::string body);
public:
	LexicalAnalyser();
	~LexicalAnalyser();
	virtual void analyse(std::vector<Message> messages);
	
};

