#include "Message.h"


Message::Message()
{
}

Message::Message(std::string bodyString, std::string contact, bool from, int timecode)
	: body(bodyString), contactName(contact), from(from), timecode(timecode)
{

}


Message::~Message()
{
}
