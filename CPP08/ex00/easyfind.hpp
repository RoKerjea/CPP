#pragma once

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator	easyfind(T &tab, int ToFind)
{
	typename T::iterator res = find(tab.begin(), tab.end(), ToFind);
	if (res != tab.end())
		return (res);
	throw std::invalid_argument("not found");
}