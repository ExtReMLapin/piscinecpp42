#include "Brain.hpp"

#include <string>	// std::string
#include <iostream>	// std::cout
#include <sstream>

Brain::Brain()
{
}


Brain::~Brain()
{

}

std::string Brain::identify(void) const
{
	std::stringstream adr;
	adr << this;

	return (adr.str());
}

