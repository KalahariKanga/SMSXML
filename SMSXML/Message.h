#pragma once
#include <string>

class Message
{
	std::string body;
	std::string contactName;
	bool from;
	int timecode;
public:
	Message();
	~Message();
};

