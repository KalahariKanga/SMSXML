#pragma once
#include "rapidxml.hpp"
#include <string>

class XMLParser
{
	rapidxml::xml_document<> doc;
	std::string parseString;
public:
	XMLParser();
	~XMLParser();

	void loadFile(std::string filename);
	void parseMessages();
};

