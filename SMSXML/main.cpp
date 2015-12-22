#include "rapidxml.hpp"
#include "XMLParser.h"
#include <iostream>
#include <fstream>
#include <string>
#include "MessageLengthAnalyser.h"

int main(int argc, char* argv[])
{
	std::string fname;
	std::cout << "Filename: ";
	std::cin >> fname;
	
	XMLParser parser;
	MessageLengthAnalyser mla;
	parser.loadFile(fname);
	parser.parseMessages();
	parser.runAnalysis(&mla);
	system("pause");
	return 0;
}