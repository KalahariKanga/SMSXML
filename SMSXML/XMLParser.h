#pragma once
#include "rapidxml.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Message.h"
#include "Analyser.h"

class XMLParser
{
	rapidxml::xml_document<> doc;
	std::string parseString;
	std::vector<Message> messages;
public:
	XMLParser();
	~XMLParser();

	void loadFile(std::string filename);
	void parseMessages();
	void runAnalysis(Analyser* analyser);
};

