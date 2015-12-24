#include "Analyser.h"


Analyser::Analyser()
{
}


Analyser::~Analyser()
{
}

void Analyser::addFilter(Filter f)
{
	filters.push_back(f);
}

bool Analyser::checkMessage(Message m)
{
	for (auto f : filters)
	{
		if (!f.checkMessage(m))
			return 0;
	}
	return 1;
}