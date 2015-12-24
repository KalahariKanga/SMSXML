#pragma once
#include "Message.h"
#include <string>
#include <functional>

class Filter
{
	std::function<bool(Message)> predicate;
public:
	Filter(std::function<bool(Message)> pred);
	~Filter();
	bool checkMessage(const Message& m);
};

