#pragma once
#include "Analyser.h"


class MessageLengthAnalyser :
	public Analyser
{
public:
	MessageLengthAnalyser();
	~MessageLengthAnalyser();
	virtual void analyse(std::vector<Message> messages);
};

