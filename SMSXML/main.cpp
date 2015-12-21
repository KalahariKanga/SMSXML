#include "rapidxml.hpp"
#include "XMLParser.h"
#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char* argv[])
{
	std::string fname;
	std::cout << "Filename: ";
	std::cin >> fname;
	
	XMLParser parser;
	parser.loadFile(fname);
	parser.parseMessages();

	system("pause");
	return 0;
}