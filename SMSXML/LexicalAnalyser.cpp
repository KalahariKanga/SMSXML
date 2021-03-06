#include "LexicalAnalyser.h"
#include <iterator>

LexicalAnalyser::LexicalAnalyser()
{
}


LexicalAnalyser::~LexicalAnalyser()
{
}

std::string LexicalAnalyser::normalise(std::string body)
{
	std::replace(body.begin(), body.end(), '\n', ' ');
	std::replace(body.begin(), body.end(), '\t', ' ');
	std::replace(body.begin(), body.end(), '\r', ' ');

	std::string::size_type start_pos = 0;
	std::string escape = "&#10;";
	while ((start_pos = body.find(escape, start_pos)) != std::string::npos)
	{
		body.replace(start_pos, escape.length(), " ");
		start_pos += 1;
	}

	std::string noPunct;
	noPunct.reserve(body.length());
	std::transform(body.begin(), body.end(), body.begin(), tolower);
	std::copy_if(body.begin(), body.end(), std::back_inserter(noPunct), [](unsigned char c){return !ispunct(c); });
	return noPunct;
}

void LexicalAnalyser::analyse(std::vector<Message> messages)
{
	std::map<std::string, int> wordMap;
	for (auto& m : messages)
	{
		if (!checkMessage(m))
			continue;

		std::stringstream stream;
		std::string word;
		stream << normalise(m.getBody());
		while (std::getline(stream, word, ' '))
		{
			if (wordMap.find(word) != wordMap.end())
				wordMap[word] += 1;
			else
				wordMap[word] = 1;
		}
	}
	std::multimap<int, std::string> flippedMap;
	for (auto& w : wordMap)
	{
		flippedMap.insert(std::make_pair(w.second, w.first));
	}
	for (auto& w : flippedMap)
	{
		std::cout << w.first << ": " << w.second << std::endl;
	}

}