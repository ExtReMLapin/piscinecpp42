#pragma once

#include <stdexcept>
#include <algorithm>
#include <iostream>

template < typename T >
int		easyfind( T & x, int i)
{
	typename T::iterator	it = std::find(x.begin(), x.end(), i); // http://www.cplusplus.com/reference/algorithm/find/
	if (it != x.end())
			return *it;
	throw std::logic_error("No occurence found.");
}
