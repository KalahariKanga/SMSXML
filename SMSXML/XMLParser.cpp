#include "XMLParser.h"


XMLParser::XMLParser()
{
}


XMLParser::~XMLParser()
{
}

void XMLParser::loadFile(std::string fname)
{
	std::ifstream file(fname);
	std::stringstream buffer;
	buffer << file.rdbuf();
	parseString = buffer.str();
	doc.parse<0>((char*)parseString.c_str());
}

void XMLParser::parseMessages()
{
	auto sms = doc.first_node()->first_node();
	while (sms->next_sibling() != NULL)
	{
		auto attr = sms->first_attribute();

		std::string attr_name;

		long timecode;
		bool from;
		std::string body;
		std::string contact;

		while (1)
		{
			attr_name = attr->name();

			if (attr_name == "date")
			{
				std::string timecodeString = attr->value();
				timecodeString.erase(timecodeString.end() - 4, timecodeString.end());
				long timecode = stol(timecodeString);
			}
			if (attr_name == "body")
			{
				body = attr->value();
			}
			if (attr_name == "type")
			{
				std::string type = attr->value();
				from = stoi(type) - 1;
			}
			if (attr_name == "contact_name")
			{
				contact = attr->value();
			}
			if (attr->next_attribute() != NULL)
				attr = attr->next_attribute();
			else
				break;
		}
		messages.emplace_back(body, contact, from, timecode);
		sms = sms->next_sibling();
	}
}

void XMLParser::runAnalysis(Analyser* analyser)
{
	analyser->analyse(messages);
}