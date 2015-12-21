#include "rapidxml.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char* argv[])
{
	std::string fname;
	std::cout << "Filename: ";
	std::cin >> fname;
	
	std::ifstream file(fname);
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string parseString = buffer.str();

	rapidxml::xml_document<> doc;
	doc.parse<0>((char*)parseString.c_str());

	std::cout << doc.first_node()->value();
	system("pause");
	return 0;
}