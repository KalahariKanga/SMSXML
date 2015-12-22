#include "MessageLengthAnalyser.h"


MessageLengthAnalyser::MessageLengthAnalyser()
{
}


MessageLengthAnalyser::~MessageLengthAnalyser()
{
}

void MessageLengthAnalyser::analyse(std::vector<Message> messages)
{
	std::map<int, int> lengthDensity;
	for (auto& m : messages)
	{
		int length = m.getBody().length();
		if (lengthDensity.find(length) != lengthDensity.end())
			lengthDensity[length] += 1;
		else
			lengthDensity[length] = 0;
	}
	for (auto& l : lengthDensity)
	{
		std::cout << l.first << ": " << l.second << "\n";
	}
}