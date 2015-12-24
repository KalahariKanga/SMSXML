#pragma once
#include "Message.h"
#include "Filter.h"
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

class Analyser
{
protected:
	std::vector<Filter> filters;
public:
	Analyser();
	~Analyser();
	virtual void analyse(std::vector<Message> messages) = 0;
	void addFilter(Filter f);
	bool checkMessage(Message m);
};

