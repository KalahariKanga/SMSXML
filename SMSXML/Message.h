#pragma once
#include <string>

class Message
{
	std::string body;
	std::string contactName;
	bool from;
	long timecode;
public:
	Message();
	Message(std::string body, std::string contact, bool from, int timecode);
	~Message();
};

