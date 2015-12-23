#pragma once
#include "Message.h"
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

class Analyser
{
public:
	Analyser();
	~Analyser();
	virtual void analyse(std::vector<Message> messages) = 0;
	//add filters
};

