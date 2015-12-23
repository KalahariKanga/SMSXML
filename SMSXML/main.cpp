#include "rapidxml.hpp"
#include "XMLParser.h"
#include <iostream>
#include <fstream>
#include <string>
#include "MessageLengthAnalyser.h"
#include "LexicalAnalyser.h"

int main(int argc, char* argv[])
{
	std::string fname;
	std::cout << "Filename: ";
	std::cin >> fname;
	
	XMLParser parser;
	LexicalAnalyser la;
	parser.loadFile(fname);
	parser.parseMessages();
	parser.runAnalysis(&la);
	system("pause");
	return 0;
}