#include "span.hpp"

#include <exception>
#include <numeric> 
#include <iostream>


Span::Span(unsigned int size) 

{
	_db.reserve(size);// reserve Request a change in capacity (public member function )
}

Span::Span(int size) 
{
	size = std::max(0, size);

	_db.reserve(size);// reserve Request a change in capacity (public member function )
}



void Span::addNumber(int i)
{
	if (this->_db.size() == this->_db.capacity())
		throw std::overflow_error("max size reached");
	this->_db.push_back(i);
}

Span::Span()
{

}


Span::~Span()
{

}

Span &	Span::operator=( Span const & rhs )
{

	this->_db = rhs._db;
	return *this;
}

Span::Span(Span const &source)
{
	*this = source; 
}
 
void Span::fillRandom()
{
	while (this->_db.size() != this->_db.capacity())
		this->_db.push_back(std::rand());

}


int	Span::shortestSpan()
{

	if (this->_db.size() < 2)
		throw std::overflow_error("cannot get it");

	std::vector<int> 	cpy = _db;

    std::sort(cpy.begin(), cpy.end()); // on trie
	std::adjacent_difference(cpy.begin(), cpy.end(), cpy.begin() - 1);
	cpy.pop_back();
    return (cpy[std::distance(cpy.begin(), std::min_element(cpy.begin(), cpy.end()))]);
}

int	Span::longestSpan()
{
	if (this->_db.size() < 2)
		throw std::overflow_error("cannot get it");
	std::vector<int> 	cpy = _db;
    std::sort(cpy.begin(), cpy.end()); // on trie
	return (cpy.back() - cpy.front());
}
