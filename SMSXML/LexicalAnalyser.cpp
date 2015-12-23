#include "LexicalAnalyser.h"


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

	std::transform(body.begin(), body.end(), body.begin(), tolower);
	//std::string alnum;
	std::copy_if(body.begin(), body.end(), body.begin(), [](unsigned char c){return !ispunct(c); });
	//return alnum;
	return body;
}

void LexicalAnalyser::analyse(std::vector<Message> messages)
{
	std::map<std::string, int> wordMap;
	for (auto& m : messages)
	{
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
	for (auto& w : wordMap)
	{
		std::cout << w.first << ": " << w.second << std::endl;
	}
}