#pragma once
#include "Analyser.h"
#include <iostream>

class MessageLengthAnalyser :
	public Analyser
{
public:
	MessageLengthAnalyser();
	~MessageLengthAnalyser();
	virtual void analyse(std::vector<Message> messages);
};

