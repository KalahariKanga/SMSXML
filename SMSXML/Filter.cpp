#include "Filter.h"


Filter::Filter(std::function<bool(Message)> pred) : predicate(pred)
{
}


Filter::~Filter()
{
}

bool Filter::checkMessage(const Message& m)
{
	return predicate(m);
}
