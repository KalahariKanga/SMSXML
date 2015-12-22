#pragma once
#include <string>
#include <chrono>
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

	std::string getBody(){ return body; }
	std::string getContactName(){ return contactName; }
	bool getFrom(){ return from; }
	long getTimecode(){ return timecode; }
};

