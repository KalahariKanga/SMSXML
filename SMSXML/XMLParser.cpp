#include "XMLParser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
		std::cout << sms->first_attribute("body")->value();
		sms = sms->next_sibling();
	}
}